"""Register frequently used, stateless imports in the Windows native core."""
import ctypes as C
import os
from static_cpu import Context

COMMON={'sin':1,'cos':2,'sinf':3,'cosf':4,'memset':5,'memcpy':6,'memmove':7,
        **{name:8 for name in ('pthread_mutex_init','pthread_mutex_lock','pthread_mutex_unlock',
                              'pthread_mutex_destroy','pthread_attr_init','pthread_attr_setdetachstate',
                              'pthread_attr_destroy','pthread_setname_np','pthread_detach','pthread_key_delete')}}
GRAPHICS={'glEnable':32,'glDisable':33,'glActiveTexture':34,'glUseProgram':35,
          'glEnableVertexAttribArray':36,'glDisableVertexAttribArray':37,'glFrontFace':38,
          'glBindTexture':39,'glBlendFunc':40,'glHint':41,'glBindBuffer':42,'glDepthMask':43,
          'glDrawArrays':44,'glDrawElements':45,'glVertexAttribPointer':46,
          'glUniform4fv':47,'glUniform3fv':48,'glUniformMatrix4fv':49,'glUniform1i':50,
          'glUniform1f':51,'glUniform4f':52,'glBlendColor':53,'glTexParameterf':54,
          'glGetUniformLocation':55,'glGetAttribLocation':55}

def bind(p, graphics=None):
    if os.environ.get('MSD_NATIVE_IMPORTS','1')=='0':return
    if not hasattr(p.uc.lib,'msd_bind_import'):return
    fn=p.uc.lib.msd_bind_import
    fn.argtypes=[C.POINTER(Context),C.c_uint32,C.c_uint32,C.c_void_p];fn.restype=C.c_uint32
    mapping=COMMON if graphics is None else GRAPHICS
    count=0
    for name,kind in mapping.items():
        address=p.thunks.get(name)
        if address is None:continue
        function=C.cast(getattr(graphics.gl,name),C.c_void_p) if graphics else None
        if not fn(C.byref(p.uc.ctx),address,kind,function):raise RuntimeError('Native import binding failed: '+name)
        count+=1
    p.log('NATIVE_IMPORTS', 'graphics' if graphics else 'common', count)

def release(p):
    if hasattr(p.uc.lib,'msd_release_imports'):
        fn=p.uc.lib.msd_release_imports;fn.argtypes=[C.POINTER(Context)];fn.restype=None
        fn(C.byref(p.uc.ctx))
