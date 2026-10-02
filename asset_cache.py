"""Bounded read-only asset cache; save I/O always retains its original path."""
from collections import OrderedDict
import io
import threading
import os


class AssetCache:
    def __init__(self, root, limit=128*1024*1024):
        self.root=root.resolve();self.limit=limit;self.size=0
        with os.scandir(self.root) as entries:
            self.safe_names={e.name for e in entries if e.is_file(follow_symlinks=False) and not e.is_symlink()}
        self.files=OrderedDict();self.lock=threading.Lock();self.stop=threading.Event()
        self.thread=threading.Thread(target=self.preload,name='MSD asset prefetch',daemon=True)
        self.thread.start()

    def put(self,path,data):
        if len(data)>self.limit:return
        with self.lock:
            old=self.files.pop(path,None)
            if old is not None:self.size-=len(old)
            while self.files and self.size+len(data)>self.limit:
                _,old=self.files.popitem(last=False);self.size-=len(old)
            self.files[path]=data;self.size+=len(data)

    def preload(self):
        try:
            # Music and common interface textures have priority. Remaining
            # textures enter the cache on demand without preloading the army.
            paths=sorted(self.root.glob('*.msdf'))
            names={p.name for p in self.root.glob('menu*.obm')}
            for pattern in ('stage*.obm','prisoner*.obm','popup*.obm','icon*.obm','point_bar.obm','battle*.obm'):
                names.update(p.name for p in self.root.glob(pattern))
            paths+=[self.root/name for name in sorted(names)]
            for path in paths:
                if self.stop.is_set():break
                if path.name not in self.safe_names:continue
                self.put(path,path.read_bytes())
        except OSError:pass

    def open(self,path):
        with self.lock:
            data=self.files.get(path)
            if data is not None:self.files.move_to_end(path)
        if data is None:
            data=path.read_bytes();self.put(path,data)
        return io.BytesIO(data)

    def close(self):
        self.stop.set();self.thread.join(timeout=1)

