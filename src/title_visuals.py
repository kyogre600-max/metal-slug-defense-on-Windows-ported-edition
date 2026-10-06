"""标题图集适配：保留用户 PNG 的原始尺寸、RGBA 及透明背景。"""
from pathlib import Path
import json
import struct

LOGO_FILE = 'LOGO_IN_GAME.png'
LOGO_SIZE = (282, 247)
ATLAS_SIZE = (512, 1024)
LOGO_XY = (0, 512)
NATIVE_IMAGE_ID = 34
NATIVE_CONV_ADDRESS = 0x10308460
NATIVE_PAT_ADDRESS = 0x10308970
NATIVE_OFF_ADDRESS = 0x10308ac8
NATIVE_RECT_COUNT = 81
NATIVE_PATTERN_WORDS = 172
NATIVE_OFFSET_COUNT = 42
NATIVE_LOGO_PATTERN = 8
NATIVE_LOGO_OFFSET = 104
NATIVE_LOGO_RECT = (0, 204, 282, 227, -143, -21, 0, 0)
NATIVE_TAP_RECT = (116, 483, 111, 23, -229, -262, 0, 0)


class TitleVisuals:
    """在首次 title01 读取时创建图集及原生转换表，沿用既有任务与动作。"""

    def __init__(self, probe, folder):
        self.p = probe
        self.folder = Path(folder)
        self.atlas = None
        self.metadata = None
        self.tables = None
        self.loaded = False

    def read_asset(self, path, mode, asset_folder):
        path = Path(path)
        if path.parent != Path(asset_folder) or path.name != 'title01.obm':
            return None
        if not mode.startswith('r') or any(flag in mode for flag in 'wa+'):
            return None
        if not self.loaded:
            self.loaded = True
            if not (self.folder / LOGO_FILE).is_file():
                self.p.log('TITLE_VISUALS_DEFAULT', str(self.folder / LOGO_FILE))
                return None
            self._load(path)
        if self.atlas is not None:
            self._install_tables()
        return self.atlas

    def _load(self, path):
        from PIL import Image
        source = self.folder / LOGO_FILE
        with Image.open(source) as original:
            if original.format != 'PNG' or original.mode != 'RGBA' or original.size != LOGO_SIZE:
                raise ValueError('标题 PNG 必须保持用户提供的 282×247 RGBA 尺寸和格式')
            logo = original.tobytes()
        raw = path.read_bytes()
        if raw[:8] != b'OI\x01\x20' + struct.pack('<HH', 512, 512) or len(raw) != 8 + 512 * 512 * 4:
            raise ValueError('标题原生图集格式或尺寸发生变化')
        pixels = bytearray(ATLAS_SIZE[0] * ATLAS_SIZE[1] * 4)
        pixels[:len(raw) - 8] = raw[8:]
        tap_x, tap_y, tap_w, tap_h = NATIVE_TAP_RECT[:4]
        for y in range(tap_y, tap_y + tap_h):
            start = (y * ATLAS_SIZE[0] + tap_x) * 4 + 3
            for x in range(tap_w):
                pixels[start + x * 4] = 0
        width, height = LOGO_SIZE
        for y in range(height):
            start = ((LOGO_XY[1] + y) * ATLAS_SIZE[0] + LOGO_XY[0]) * 4
            pixels[start:start + width * 4] = logo[y * width * 4:(y + 1) * width * 4]
        self.atlas = b'OI\x01\x20' + struct.pack('<HH', *ATLAS_SIZE) + bytes(pixels)
        self.metadata = dict(source=str(source), source_size=list(LOGO_SIZE),
            atlas_size=list(ATLAS_SIZE), foreground_xy=list(LOGO_XY),
            source_png_preserved=True, source_resampling=False,
            source_rgba_pixels_preserved=True, source_rgb_pixels_preserved=True,
            source_alpha_preserved=True,
            logo_rectangle_layers=1,
            native_anchor=[-143, -21], native_title_actions_preserved=True,
            tap_screen_alpha_hidden=True, tap_screen_geometry_preserved=True)
        self.p.log('TITLE_VISUALS_LOADED', json.dumps(self.metadata, ensure_ascii=False))

    def _install_tables(self):
        p = self.p
        names = ('m_pMenuTblConv', 'm_pMenuTblPat', 'm_pMenuTblOff')
        slots = tuple(p.symbols[name] + NATIVE_IMAGE_ID * 4 for name in names)
        if self.tables is not None and tuple(p.word(slot) for slot in slots) == self.tables:
            return
        if self.tables is None:
            if tuple(p.word(slot) for slot in slots) != (
                    NATIVE_CONV_ADDRESS, NATIVE_PAT_ADDRESS, NATIVE_OFF_ADDRESS):
                raise RuntimeError('标题原生转换表映射与核验版本不符')
            conv = bytearray(p.read(NATIVE_CONV_ADDRESS, NATIVE_RECT_COUNT * 16))
            if struct.unpack_from('<8h', conv) != NATIVE_LOGO_RECT or struct.unpack_from('<8h', conv, 16) != NATIVE_TAP_RECT:
                raise RuntimeError('标题原生 LOGO 与 TAP SCREEN 矩形发生变化')
            anchor = NATIVE_LOGO_RECT[4:]
            struct.pack_into('<8h', conv, 0, *LOGO_XY, *LOGO_SIZE, *anchor)
            address = p.alloc(len(conv))
            p.write(address, bytes(conv))
            self.tables = (address, NATIVE_PAT_ADDRESS, NATIVE_OFF_ADDRESS)
        p.put(slots[0], self.tables[0])
        p.log('TITLE_VISUALS_TABLES', *map(hex, self.tables))
