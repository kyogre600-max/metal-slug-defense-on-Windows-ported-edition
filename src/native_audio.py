"""Preserve CMediaSound ownership while replacing full Vorbis computation."""
import ctypes as C
import os
import time
import hashlib
import threading
from collections import OrderedDict
from static_cpu import Context

class AudioCache:
    def __init__(self,p):
        self.lib=p.uc.lib;self.root=p.asset_cache.root
        self.lock=threading.Lock();self.stop=threading.Event();self.data=OrderedDict()
        self.size=0;self.limit=128*1024*1024;self.hits=0;self.misses=0
        self.fn=self.lib.msd_vorbis_decode
        self.fn.argtypes=[C.c_void_p,C.c_int32,C.POINTER(C.c_int32),C.POINTER(C.c_int32),C.POINTER(C.c_void_p)]
        self.fn.restype=C.c_int32
        self.free=self.lib.msd_vorbis_free;self.free.argtypes=[C.c_void_p];self.free.restype=None
        self.thread=threading.Thread(target=self.preload,name='MSD audio prefetch',daemon=True)
        self.thread.start()

    def obtain(self,raw):
        key=hashlib.sha256(raw).digest()
        with self.lock:
            item=self.data.get(key)
            if item is not None:self.data.move_to_end(key);self.hits+=1;return item
        channels=C.c_int32();rate=C.c_int32();output=C.c_void_p()
        frames=self.fn(raw,len(raw),C.byref(channels),C.byref(rate),C.byref(output))
        if frames<1:return frames
        try:item=(frames,channels.value,rate.value,C.string_at(output.value,frames*channels.value*2))
        finally:self.free(output)
        with self.lock:
            self.misses+=1
            if key not in self.data and len(item[3])<=self.limit:
                while self.data and self.size+len(item[3])>self.limit:
                    _,old=self.data.popitem(last=False);self.size-=len(old[3])
                self.data[key]=item;self.size+=len(item[3])
        return item

    def preload(self):
        common={f'bgm{i:02}.msdf' for i in range(1,9)}|{'bgm_ms7_select.msdf','bgm_b_1_1.msdf'}
        try:
            paths=sorted(self.root.glob('*.msdf'),key=lambda q:q.name not in common)
            for path in paths:
                if self.stop.is_set():break
                if path.name.startswith('bgm') and path.name not in common:continue
                self.obtain(path.read_bytes())
        except OSError:pass

    def close(self):
        self.stop.set();self.thread.join(timeout=1)

def bind(p):
    if os.environ.get('MSD_NATIVE_AUDIO','1')=='0' or not hasattr(p.uc.lib,'msd_bind_decoder'):return
    fn=p.uc.lib.msd_bind_decoder;fn.argtypes=[C.POINTER(Context),C.c_uint32,C.c_uint32];fn.restype=None
    fn(C.byref(p.uc.ctx),p.thunk('windows_vorbis_plus'),p.thunk('windows_vorbis_sync'))
    p.native_audio_cache=AudioCache(p)
    p.log('NATIVE_AUDIO_ENABLED','Windows x64 stb_vorbis')

def decode(p,name,a):
    started=time.perf_counter()
    item=p.native_audio_cache.obtain(p.read(a[0],a[1]))
    if isinstance(item,int):return item
    frames,channels,rate,data=item;pcm=p.alloc(len(data));p.write(pcm,data)
    p.put(a[2],channels);p.put(a[3],rate)
    if name=='windows_vorbis_plus':
        # The original worker publishes progress, releases its input and flag,
        # then clears CMediaSound's flag pointer. PCM has independent ownership.
        p.put(a[7],pcm);flag=p.word(a[4]);p.put(a[5],frames)
        p.free(flag);p.put(a[4],0);p.free(a[0])
    else:p.put(a[4],pcm)
    p.log('NATIVE_AUDIO_DECODE',channels,rate,frames,round((time.perf_counter()-started)*1000,3),'ms')
    return frames
