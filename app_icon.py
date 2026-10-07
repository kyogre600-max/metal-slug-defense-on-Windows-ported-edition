"""Windows application identity and DPI-scaled window icon ownership."""
from pathlib import Path
import ctypes
import sys

APP_USER_MODEL_ID = 'MSD.Windows.S1XLV'
WM_SETICON = 0x0080
IMAGE_ICON = 1
LR_LOADFROMFILE = 0x0010


def set_app_user_model_id():
    if sys.platform != 'win32':
        return False
    try:
        shell32 = ctypes.WinDLL('shell32', use_last_error=True)
        shell32.SetCurrentProcessExplicitAppUserModelID.argtypes = [ctypes.c_wchar_p]
        shell32.SetCurrentProcessExplicitAppUserModelID.restype = ctypes.c_long
        return shell32.SetCurrentProcessExplicitAppUserModelID(APP_USER_MODEL_ID) == 0
    except (OSError, AttributeError):
        return False


class WindowIcon:
    """Retain file-loaded HICONs until the window releases their references."""

    def __init__(self, hwnd, root):
        self.hwnd = hwnd
        self.path = Path(root) / 'custom_content/app_icon.ico'
        self.error = None
        self.sizes = None
        self.handles = []
        self.previous = {}
        self.user32 = None
        try:
            self.user32 = ctypes.WinDLL('user32', use_last_error=True)
        except OSError as error:
            self.error = str(error)
            return
        self.user32.LoadImageW.argtypes = [ctypes.c_void_p, ctypes.c_wchar_p,
                                         ctypes.c_uint, ctypes.c_int,
                                         ctypes.c_int, ctypes.c_uint]
        self.user32.LoadImageW.restype = ctypes.c_void_p
        self.user32.SendMessageW.argtypes = [ctypes.c_void_p, ctypes.c_uint,
                                           ctypes.c_size_t, ctypes.c_ssize_t]
        self.user32.SendMessageW.restype = ctypes.c_ssize_t
        self.user32.DestroyIcon.argtypes = [ctypes.c_void_p]
        self.user32.DestroyIcon.restype = ctypes.c_int
        self.user32.GetSystemMetrics.argtypes = [ctypes.c_int]
        self.user32.GetSystemMetrics.restype = ctypes.c_int
        self.get_dpi = getattr(self.user32, 'GetDpiForWindow', None)
        self.get_metric_for_dpi = getattr(self.user32, 'GetSystemMetricsForDpi', None)
        if self.get_dpi:
            self.get_dpi.argtypes = [ctypes.c_void_p]
            self.get_dpi.restype = ctypes.c_uint
        if self.get_metric_for_dpi:
            self.get_metric_for_dpi.argtypes = [ctypes.c_int, ctypes.c_uint]
            self.get_metric_for_dpi.restype = ctypes.c_int
        self.refresh()

    def refresh(self):
        if not self.hwnd or self.user32 is None:
            return False
        if not self.path.is_file():
            self.error = 'Application icon file is unavailable: ' + str(self.path)
            return False
        dpi = (self.get_dpi(self.hwnd) if self.get_dpi else 96) or 96

        def metric(index, default):
            value = (self.get_metric_for_dpi(index, dpi) if self.get_metric_for_dpi
                     else self.user32.GetSystemMetrics(index))
            return value or max(1, (default * dpi + 48) // 96)

        sizes = ((metric(49, 16), metric(50, 16)),
                 (metric(11, 32), metric(12, 32)))
        if sizes == self.sizes:
            return True
        handles = []
        for width, height in sizes:
            handle = self.user32.LoadImageW(None, str(self.path), IMAGE_ICON,
                                            width, height, LR_LOADFROMFILE)
            if not handle:
                self.error = str(ctypes.WinError(ctypes.get_last_error()))
                for loaded in handles:
                    self.user32.DestroyIcon(loaded)
                return False
            handles.append(handle)
        for slot, handle in enumerate(handles):
            previous = self.user32.SendMessageW(self.hwnd, WM_SETICON, slot, handle)
            if slot not in self.previous:
                self.previous[slot] = previous
        for handle in self.handles:
            self.user32.DestroyIcon(handle)
        self.handles = handles
        self.sizes = sizes
        self.error = None
        return True

    def close(self):
        for slot, previous in self.previous.items():
            self.user32.SendMessageW(self.hwnd, WM_SETICON, slot, previous)
        for handle in self.handles:
            self.user32.DestroyIcon(handle)
        self.handles = []
        self.previous = {}
        self.hwnd = None
