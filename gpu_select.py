"""Query Windows DXGI adapters without changing system graphics settings."""
import ctypes as C
import uuid
class Description(C.Structure):
    _fields_=[('name',C.c_wchar*128),('vendor',C.c_uint32),('device',C.c_uint32),
              ('subsystem',C.c_uint32),('revision',C.c_uint32),('dedicated_video',C.c_size_t),
              ('dedicated_system',C.c_size_t),('shared_system',C.c_size_t),
              ('luid_low',C.c_uint32),('luid_high',C.c_int32),('flags',C.c_uint32)]
def method(obj,index,ret,*args):
    table=C.cast(obj,C.POINTER(C.POINTER(C.c_void_p))).contents
    return C.WINFUNCTYPE(ret,C.c_void_p,*args)(table[index])
def adapters():
    dxgi=C.WinDLL('dxgi');create=dxgi.CreateDXGIFactory1
    create.argtypes=[C.c_void_p,C.POINTER(C.c_void_p)];create.restype=C.c_long
    guid=(C.c_ubyte*16).from_buffer_copy(uuid.UUID('770aae78-f26f-4dba-a829-253c83d1b387').bytes_le)
    factory=C.c_void_p();hr=create(guid,C.byref(factory))
    if hr<0:raise OSError(f'CreateDXGIFactory1: 0x{hr&0xffffffff:08x}')
    result=[]
    try:
        enum=method(factory,12,C.c_long,C.c_uint32,C.POINTER(C.c_void_p))
        for index in range(32):
            adapter=C.c_void_p();hr=enum(factory,index,C.byref(adapter))
            if hr<0:break
            try:
                desc=Description();hr=method(adapter,10,C.c_long,C.POINTER(Description))(adapter,C.byref(desc))
                if hr>=0:result.append({n:getattr(desc,n) for n,_ in Description._fields_})
            finally:method(adapter,2,C.c_ulong)(adapter)
    finally:method(factory,2,C.c_ulong)(factory)
    return result
def initialize_display(egl,log):
    """Prefer the hardware adapter with most dedicated VRAM, then EGL default."""
    P,I,U=C.c_void_p,C.c_int,C.c_uint
    egl.eglQueryString.argtypes=[P,I];egl.eglQueryString.restype=C.c_char_p
    egl.eglGetProcAddress.argtypes=[C.c_char_p];egl.eglGetProcAddress.restype=P
    egl.eglGetDisplay.argtypes=[P];egl.eglGetDisplay.restype=P
    egl.eglInitialize.argtypes=[P,C.POINTER(I),C.POINTER(I)];egl.eglInitialize.restype=U
    candidates=[]
    try:
        extensions=egl.eglQueryString(None,0x3055) or b''
        proc=egl.eglGetProcAddress(b'eglGetPlatformDisplayEXT')
        modern=b'EGL_ANGLE_platform_angle_device_id' in extensions
        legacy=b'EGL_ANGLE_platform_angle_d3d_luid' in extensions
        if proc and (modern or legacy):
            get_display=C.WINFUNCTYPE(P,U,P,C.POINTER(I))(proc)
            available=sorted((a for a in adapters() if not a['flags']&2),key=lambda a:a['dedicated_video'],reverse=True)
            for a in available:
                high,low=(0x34d6,0x34d7) if modern else (0x34a0,0x34a1)
                attrs=(I*7)(0x3203,0x3208,high,a['luid_high'],low,a['luid_low'],0x3038)
                display=get_display(0x3202,None,attrs)
                if display:candidates.append((a['name'],display))
    except (OSError,ValueError) as error:log('GPU_SELECTION_FALLBACK',str(error))
    candidates.append(('EGL default adapter',egl.eglGetDisplay(None)))
    for name,display in candidates:
        major,minor=I(),I()
        if display and egl.eglInitialize(display,C.byref(major),C.byref(minor)):
            log('GPU_REQUESTED',name);return display
    raise RuntimeError('No available ANGLE graphics adapter could initialize')
if __name__=='__main__':
    import json
    print(json.dumps(adapters(),indent=2))
