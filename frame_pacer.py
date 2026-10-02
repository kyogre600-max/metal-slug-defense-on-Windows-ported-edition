"""Thirty-Hz monotonic presentation scheduling with a Windows deadline timer."""
import ctypes as C
import time

class FramePacer:
    def __init__(self,hz=30):
        self.period=1.0/hz;self.deadline=time.perf_counter();self.timer=None
        self.kernel=C.WinDLL('kernel32',use_last_error=True)
        create=self.kernel.CreateWaitableTimerExW
        create.argtypes=[C.c_void_p,C.c_wchar_p,C.c_uint32,C.c_uint32];create.restype=C.c_void_p
        self.timer=create(None,None,2,0x1f0003)
        if self.timer:
            self.kernel.SetWaitableTimer.argtypes=[C.c_void_p,C.POINTER(C.c_int64),C.c_int32,C.c_void_p,C.c_void_p,C.c_int]
            self.kernel.WaitForSingleObject.argtypes=[C.c_void_p,C.c_uint32]
            self.kernel.CloseHandle.argtypes=[C.c_void_p]
        else:
            self.winmm=C.WinDLL('winmm');self.winmm.timeBeginPeriod(1)

    def wait(self):
        self.deadline+=self.period;now=time.perf_counter()
        if now-self.deadline>=self.period:self.deadline=now
        delay=self.deadline-now
        if delay<=0:return
        if self.timer:
            due=C.c_int64(-max(1,int(delay*10_000_000)))
            if self.kernel.SetWaitableTimer(self.timer,C.byref(due),0,None,None,False):
                self.kernel.WaitForSingleObject(self.timer,100);return
        time.sleep(delay)

    def close(self):
        if self.timer:self.kernel.CloseHandle(self.timer);self.timer=None
        elif hasattr(self,'winmm'):self.winmm.timeEndPeriod(1)

