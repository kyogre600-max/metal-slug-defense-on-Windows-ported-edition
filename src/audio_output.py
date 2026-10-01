"""Small, bounded WinMM PCM sink; no codec, ARM, or third-party dependencies.

The caller owns scheduling: call poll() regularly and retry submit() after False.
queued_seconds conservatively includes each whole outstanding block. A completed
buffer means Windows returned it; it does not prove speakers were audible.

WinMM lifetime rules (Microsoft):
https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-waveoutprepareheader
https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-waveoutwrite
https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-waveoutunprepareheader
https://learn.microsoft.com/windows/win32/api/mmeapi/nf-mmeapi-waveoutreset
https://learn.microsoft.com/windows/win32/api/mmeapi/ns-mmeapi-wavehdr
https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex
"""

from __future__ import annotations

from array import array
import ctypes
from dataclasses import dataclass
import math
import os
import sys
import threading
import warnings


UINT = ctypes.c_uint32
DWORD = ctypes.c_uint32
WORD = ctypes.c_uint16
DWORD_PTR = ctypes.c_size_t
HWAVEOUT = ctypes.c_void_p
MMSYSERR_NOERROR = 0
MMSYSERR_NODRIVER = 6
WAVERR_STILLPLAYING = 33
WAVE_MAPPER = 0xFFFFFFFF
WAVE_FORMAT_PCM = 1
WHDR_DONE = 0x00000001
WHDR_PREPARED = 0x00000002
CALLBACK_NULL = 0


class WAVEFORMATEX(ctypes.Structure):
    # Windows multimedia headers use packed WAVEFORMATEX (18 bytes).
    _pack_ = 1
    _fields_ = [
        ("wFormatTag", WORD), ("nChannels", WORD),
        ("nSamplesPerSec", DWORD), ("nAvgBytesPerSec", DWORD),
        ("nBlockAlign", WORD), ("wBitsPerSample", WORD), ("cbSize", WORD),
    ]


class WAVEHDR(ctypes.Structure):
    pass


WAVEHDR._fields_ = [
    ("lpData", ctypes.c_void_p), ("dwBufferLength", DWORD),
    ("dwBytesRecorded", DWORD), ("dwUser", DWORD_PTR),
    ("dwFlags", DWORD), ("dwLoops", DWORD),
    ("lpNext", ctypes.POINTER(WAVEHDR)), ("reserved", DWORD_PTR),
]


_ERROR_NAMES = {
    1: "MMSYSERR_ERROR", 2: "MMSYSERR_BADDEVICEID",
    3: "MMSYSERR_NOTENABLED", 4: "MMSYSERR_ALLOCATED",
    5: "MMSYSERR_INVALHANDLE", 6: "MMSYSERR_NODRIVER",
    7: "MMSYSERR_NOMEM", 8: "MMSYSERR_NOTSUPPORTED",
    9: "MMSYSERR_BADERRNUM", 10: "MMSYSERR_INVALFLAG",
    11: "MMSYSERR_INVALPARAM", 12: "MMSYSERR_HANDLEBUSY",
    20: "MMSYSERR_NODRIVERCB", 32: "WAVERR_BADFORMAT",
    33: "WAVERR_STILLPLAYING", 34: "WAVERR_UNPREPARED",
    35: "WAVERR_SYNC",
}


class WaveOutError(RuntimeError):
    """An actual WinMM failure, including the operation and MMRESULT code."""

    def __init__(self, operation: str, code: int, detail: str = ""):
        self.operation = operation
        self.code = int(code)
        self.error_name = _ERROR_NAMES.get(self.code, "MMRESULT_UNKNOWN")
        suffix = f": {detail}" if detail else ""
        super().__init__(f"{operation} failed: {self.error_name} ({code}){suffix}")


def _load_winmm():
    if os.name != "nt":
        raise OSError("WinMM PCM output requires Windows")
    api = ctypes.WinDLL("winmm.dll")
    signatures = {
        "waveOutGetNumDevs": ([], UINT),
        "waveOutOpen": ([ctypes.POINTER(HWAVEOUT), UINT,
                         ctypes.POINTER(WAVEFORMATEX), DWORD_PTR, DWORD_PTR,
                         DWORD], UINT),
        "waveOutPrepareHeader": ([HWAVEOUT, ctypes.POINTER(WAVEHDR), UINT], UINT),
        "waveOutWrite": ([HWAVEOUT, ctypes.POINTER(WAVEHDR), UINT], UINT),
        "waveOutUnprepareHeader": ([HWAVEOUT, ctypes.POINTER(WAVEHDR), UINT], UINT),
        "waveOutPause": ([HWAVEOUT], UINT),
        "waveOutRestart": ([HWAVEOUT], UINT),
        "waveOutReset": ([HWAVEOUT], UINT),
        "waveOutClose": ([HWAVEOUT], UINT),
        "waveOutGetErrorTextW": ([UINT, ctypes.c_wchar_p, UINT], UINT),
    }
    for name, (args, result) in signatures.items():
        function = getattr(api, name)
        function.argtypes = args
        function.restype = result
    return api


@dataclass
class _Buffer:
    data: object
    header: WAVEHDR
    size: int
    submitted: bool = False
    cancelled: bool = False


# A device which refuses reset/close may still hold native pointers. Keep their
# storage alive rather than freeing memory beneath the driver during finalization.
_FAILED_CLOSE_KEEPALIVE: dict[int, "WaveOut"] = {}


class WaveOut:
    """Signed 16-bit little-endian PCM sink for mono/stereo Windows output.

    submit returns False only for queue backpressure. Other failures raise.
    set_volume affects future submissions; already queued PCM is immutable.
    clear/reset discard queued audio and preserve the requested paused state.
    close is idempotent; if a native call fails, storage is retained and close
    can be retried. Methods are serialized by a lock, with no callback thread.
    """

    def __init__(self, sample_rate: int = 44100, channels: int = 2,
                 bits: int = 16, *, max_buffers: int = 8,
                 max_buffer_seconds: float = 0.25, volume: float = 1.0):
        if sample_rate not in (16000, 22050, 44100, 48000):
            raise ValueError("sample_rate must be 16000, 22050, 44100, or 48000")
        if channels not in (1, 2) or bits != 16:
            raise ValueError("only mono/stereo signed 16-bit PCM is supported")
        if (isinstance(max_buffers, bool) or not isinstance(max_buffers, int)
                or not 1 <= max_buffers <= 256):
            raise ValueError("max_buffers must be an integer from 1 to 256")
        if (not math.isfinite(max_buffer_seconds)
                or not 0 < max_buffer_seconds <= 10):
            raise ValueError("max_buffer_seconds must be finite and in (0, 10]")
        if not math.isfinite(volume) or not 0 <= volume <= 1:
            raise ValueError("volume must be finite and in [0, 1]")
        self.sample_rate = int(sample_rate)
        self.channels = int(channels)
        self.bits = int(bits)
        self.block_align = self.channels * 2
        self.bytes_per_second = self.sample_rate * self.block_align
        self.max_buffers = max_buffers
        self.max_buffer_bytes = int(max_buffer_seconds * self.sample_rate) * self.block_align
        if self.max_buffer_bytes < self.block_align:
            raise ValueError("max_buffer_seconds is shorter than one PCM frame")
        self._volume = float(volume)
        self._lock = threading.RLock()
        self._buffers: list[_Buffer] = []
        self._handle = HWAVEOUT()
        self._closed = True
        self._paused = False
        self._metrics = dict(submitted_buffers=0, submitted_bytes=0,
                             completed_buffers=0, completed_bytes=0,
                             discarded_buffers=0, discarded_bytes=0,
                             queue_full_count=0, peak_queued_buffers=0,
                             peak_queued_bytes=0, clear_count=0,
                             errors=0, last_error=None)
        self._api = _load_winmm()
        self.device_count = int(self._api.waveOutGetNumDevs())
        if not self.device_count:
            raise self._error("waveOutGetNumDevs", MMSYSERR_NODRIVER,
                              "No waveform audio output device is available")
        self._format = WAVEFORMATEX(
            WAVE_FORMAT_PCM, self.channels, self.sample_rate,
            self.bytes_per_second, self.block_align, self.bits, 0,
        )
        self._check("waveOutOpen", self._api.waveOutOpen(
            ctypes.byref(self._handle), WAVE_MAPPER, ctypes.byref(self._format),
            0, 0, CALLBACK_NULL,
        ))
        self._closed = False

    def _error(self, operation: str, code: int, detail: str = "") -> WaveOutError:
        if not detail:
            message = ctypes.create_unicode_buffer(256)
            try:
                if self._api.waveOutGetErrorTextW(code, message, len(message)) == 0:
                    detail = message.value
            except (AttributeError, OSError):
                pass
        error = WaveOutError(operation, code, detail)
        self._metrics["errors"] += 1
        self._metrics["last_error"] = str(error)
        return error

    def _check(self, operation: str, result: int):
        if result != MMSYSERR_NOERROR:
            raise self._error(operation, int(result))

    def _require_open(self):
        if self._closed:
            raise RuntimeError("WaveOut is closed")

    def _queued_bytes(self) -> int:
        return sum(block.size for block in self._buffers
                   if block.submitted and not block.cancelled)

    @property
    def queued_seconds(self) -> float:
        with self._lock:
            return self._queued_bytes() / self.bytes_per_second

    @property
    def volume(self) -> float:
        with self._lock:
            return self._volume

    def set_volume(self, volume: float):
        if not math.isfinite(volume) or not 0 <= volume <= 1:
            raise ValueError("volume must be finite and in [0, 1]")
        with self._lock:
            self._volume = float(volume)

    def _gain(self, pcm: bytes) -> bytes:
        if self._volume == 1.0:
            return pcm
        if self._volume == 0.0:
            return bytes(len(pcm))
        samples = array("h")
        samples.frombytes(pcm)
        if sys.byteorder != "little":
            samples.byteswap()
        gain = self._volume
        for index, sample in enumerate(samples):
            samples[index] = round(sample * gain)
        if sys.byteorder != "little":
            samples.byteswap()
        return samples.tobytes()

    def submit(self, pcm: bytes | bytearray | memoryview) -> bool:
        """Copy one aligned PCM block; return False if all slots are occupied."""
        if not isinstance(pcm, (bytes, bytearray, memoryview)):
            raise TypeError("pcm must be bytes, bytearray, or memoryview")
        size = pcm.nbytes if isinstance(pcm, memoryview) else len(pcm)
        if size % self.block_align:
            raise ValueError(f"PCM byte length must be a multiple of {self.block_align}")
        if size > self.max_buffer_bytes:
            raise ValueError(f"PCM block exceeds {self.max_buffer_bytes} byte limit")
        with self._lock:
            self._require_open()
            self.poll()
            if not size:
                return True
            if len(self._buffers) >= self.max_buffers:
                self._metrics["queue_full_count"] += 1
                return False
            content = self._gain(bytes(pcm))
            data = ctypes.create_string_buffer(content, size)
            header = WAVEHDR()
            header.lpData = ctypes.addressof(data)
            header.dwBufferLength = size
            block = _Buffer(data, header, size)
            self._check("waveOutPrepareHeader", self._api.waveOutPrepareHeader(
                self._handle, ctypes.byref(header), ctypes.sizeof(WAVEHDR)))
            # Retain the allocation before passing a prepared header to Write.
            self._buffers.append(block)
            result = self._api.waveOutWrite(
                self._handle, ctypes.byref(header), ctypes.sizeof(WAVEHDR))
            if result != MMSYSERR_NOERROR:
                error = self._error("waveOutWrite", int(result))
                try:
                    self._release(block)
                except WaveOutError as cleanup_error:
                    error.add_note(str(cleanup_error))
                raise error
            block.submitted = True
            self._metrics["submitted_buffers"] += 1
            self._metrics["submitted_bytes"] += size
            self._metrics["peak_queued_buffers"] = max(
                self._metrics["peak_queued_buffers"], len(self._buffers))
            self._metrics["peak_queued_bytes"] = max(
                self._metrics["peak_queued_bytes"], self._queued_bytes())
            return True

    def _release(self, block: _Buffer):
        # On STILLPLAYING or any other failure retain BOTH header and PCM bytes.
        self._check("waveOutUnprepareHeader", self._api.waveOutUnprepareHeader(
            self._handle, ctypes.byref(block.header), ctypes.sizeof(WAVEHDR)))
        self._buffers.remove(block)
        if block.submitted:
            kind = "discarded" if block.cancelled else "completed"
            self._metrics[f"{kind}_buffers"] += 1
            self._metrics[f"{kind}_bytes"] += block.size

    def poll(self) -> int:
        """Release returned headers; return the number of allocations reclaimed."""
        with self._lock:
            if self._closed:
                return 0
            released = 0
            for block in list(self._buffers):
                if not block.submitted or block.header.dwFlags & WHDR_DONE:
                    self._release(block)
                    released += 1
            return released

    def pause(self, paused: bool = True):
        with self._lock:
            self._require_open()
            operation = "waveOutPause" if paused else "waveOutRestart"
            self._check(operation, getattr(self._api, operation)(self._handle))
            self._paused = bool(paused)

    def clear(self):
        """Discard outstanding audio; keep pause state and leave the device open."""
        with self._lock:
            self._require_open()
            already_done = {id(block) for block in self._buffers
                            if block.header.dwFlags & WHDR_DONE}
            self._check("waveOutReset", self._api.waveOutReset(self._handle))
            self._metrics["clear_count"] += 1
            # Reset returns all pending buffers, including buffers never played.
            for block in self._buffers:
                if id(block) not in already_done:
                    block.cancelled = True
            for block in list(self._buffers):
                self._release(block)
            if self._paused:
                self._check("waveOutPause", self._api.waveOutPause(self._handle))

    reset = clear

    def close(self):
        """Reset, unprepare every header, then close. Safe to call repeatedly."""
        with self._lock:
            if self._closed:
                return
            self.clear()
            self._check("waveOutClose", self._api.waveOutClose(self._handle))
            self._closed = True
            self._paused = False
            self._handle = HWAVEOUT()
            _FAILED_CLOSE_KEEPALIVE.pop(id(self), None)

    def stats(self) -> dict:
        with self._lock:
            return {
                "backend": "winmm-waveout", "sample_rate": self.sample_rate,
                "channels": self.channels, "bits": self.bits,
                "device_count": self.device_count, "closed": self._closed,
                "paused": self._paused, "volume": self._volume,
                "max_buffers": self.max_buffers,
                "max_buffer_bytes": self.max_buffer_bytes,
                "outstanding_buffers": len(self._buffers),
                "queued_bytes": self._queued_bytes(),
                "queued_seconds": self.queued_seconds,
                **self._metrics,
            }

    def __enter__(self):
        self._require_open()
        return self

    def __exit__(self, exc_type, exc_value, traceback):
        try:
            self.close()
        except Exception as cleanup_error:
            if exc_value is None:
                raise
            exc_value.add_note(f"WaveOut cleanup also failed: {cleanup_error}")
        return False

    def __del__(self):
        if getattr(self, "_closed", True):
            return
        try:
            self.close()
        except Exception as error:
            _FAILED_CLOSE_KEEPALIVE[id(self)] = self
            warnings.warn(f"WaveOut native buffers retained after cleanup failure: {error}",
                          ResourceWarning)
