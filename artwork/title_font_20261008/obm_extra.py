"""obm_tool.parse 未覆盖的 OI 格式：4 位调色板（kind 1 RGBA8888 调色板 / kind 4 RGB5A1 调色板）与 kind 4 16 位直接色。"""
import struct
from PIL import Image


def _rgb5a1(v):
    return (((v >> 11) & 31) * 255 // 31, ((v >> 6) & 31) * 255 // 31, ((v >> 1) & 31) * 255 // 31, (v & 1) * 255)


def parse_extra(raw, low_first=True):
    kind, bits = raw[2], raw[3]
    w, h = struct.unpack_from('<HH', raw, 4)
    if bits == 4:
        if kind == 1:
            pal = [tuple(raw[8 + i * 4:12 + i * 4]) for i in range(16)]
            off = 72
        else:
            pal = [_rgb5a1(v) for v in struct.unpack_from('<16H', raw, 8)]
            off = 40
        idx = bytearray()
        for b in raw[off:off + w * h // 2]:
            idx += bytes((b & 15, b >> 4)) if low_first else bytes((b >> 4, b & 15))
        im = Image.new('RGBA', (w, h))
        im.putdata([pal[i] for i in idx])
        return im
    if kind == 4 and bits == 24:   # 16 位 RGB5A1 直接色
        im = Image.new('RGBA', (w, h))
        im.putdata([_rgb5a1(v) for v in struct.unpack_from('<%dH' % (w * h), raw, 8)])
        return im
    raise ValueError(('unknown OI format', kind, bits))
