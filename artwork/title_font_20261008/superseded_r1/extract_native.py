"""从原生 menu.obm 标题行（CUSTOMIZE LANGUAGE OPTION MENU SHOP）提取各字母的填充区域（二值），供字体设计与渲染校验。"""
from pathlib import Path
import json
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
import portable_launcher  # noqa: F401,E402  设置 DLL 目录（PIL）
from PIL import Image  # noqa: E402

SOURCE = Path(r'F:\egg\MSD_封面素材\UI图标_20261007\完整图集\menu.png')   # menu.obm 的无损 PNG 导出
Y0, Y1 = 484, 502          # 标题行：484 与 501 为上下轮廓，485–500 为 16 行填充
TEXT = 'CUSTOMIZELANGUAGEOPTIONMENUSHOP'


def load():
    return Image.open(SOURCE).convert('RGBA')


def fill_mask(im):
    """填充像素：不透明且非近黑（含左侧暗边列）。返回 {(x,y)}，y 相对填充首行 485。"""
    pts = set()
    for y in range(Y0 + 1, Y1 - 1):
        for x in range(0, 480):
            r, g, b, a = im.getpixel((x, y))
            if a == 255 and max(r, g, b) > 60:
                pts.add((x, y - (Y0 + 1)))
    return pts


# 每个字母的列范围（填充亮度 >120 的连续列，±1 列包含左侧暗边）。TO、LA、PT 三组填充相连，按轮廓分隔列切分。
RANGES = [(1, 15), (18, 32), (34, 46), (46, 62, True), (63, 78, True), (79, 96), (98, 102), (105, 117), (119, 130),
          (133, 146, True), (147, 162, True), (163, 177), (179, 193), (195, 209), (211, 226), (228, 241), (244, 255),
          (259, 274), (275, 288, True), (289, 304, True), (305, 309), (311, 326), (328, 342), (346, 362), (365, 376),
          (379, 392), (395, 409), (414, 426), (428, 442), (444, 459), (461, 473)]


def letters():
    im = load()
    pts = fill_mask(im)
    assert len(RANGES) == len(TEXT)
    out = {}
    for ch, rng in zip(TEXT, RANGES):
        lo, hi = (rng[0], rng[1]) if len(rng) == 3 else (rng[0] - 1, rng[1] + 1)
        comp = {(x, y) for x, y in pts if lo <= x <= hi}
        x0 = min(x for x, _ in comp)
        x1 = max(x for x, _ in comp)
        rows = [''.join('#' if (x, y) in comp else '.' for x in range(x0, x1 + 1)) for y in range(16)]
        out.setdefault(ch, {'rows': rows, 'x': [x0, x1]})
    return im, out


if __name__ == '__main__':
    _, glyphs = letters()
    for ch, g in glyphs.items():
        print(ch, g['x'], len(g['rows'][0]))
        print('\n'.join(g['rows']))
    (Path(__file__).parent / 'native_masks.json').write_text(json.dumps(glyphs, indent=1), encoding='utf-8')
