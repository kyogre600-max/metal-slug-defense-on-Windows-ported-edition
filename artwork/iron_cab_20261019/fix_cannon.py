"""IRON CAB 激光炮帧修正（R3，2026-10-19，用户实机反馈）：MSA 素材的激光炮后端为一块平涂的暗色矩形（RGB 49,49,24），
没有收尾的形状；炮管外沿也没有本体那样的黑色描边，叠在本体上显得发虚。本模块由 frames/cannon_00–11.png 生成修正后的帧：

1. 后端：清除炮管尾部（相对吊杆 x > 13、第 42–62 行）平涂的暗色块与炮管末端，在相对吊杆 x 14–20、第 43–62 行画一个圆形的
   端盖（DRUM，颜色全部取自 MSA 素材表：高光、中间色、暗部与描边）。第 11 帧的炮身比其他帧右移 2 像素，端盖随之右移。
2. 描边：在不透明的炮体像素外侧加 1 像素描边（RGB 8,0,0，素材表的描边色）；蓄力光球、光束等发光像素（青蓝色或近白色）
   不加描边。画布左、右、下各扩 1 像素，锚点 x 随之 +1。

修正结果写入 derived/cannon/（cannon_XX.png 与 cannon.json，记录锚点与来源）。素材像素不缩放，未改动的像素与原帧相同。
"""
from pathlib import Path
import json

from PIL import Image

HERE = Path(__file__).resolve().parent
FRAMES = HERE / 'frames'
OUT = HERE / 'derived' / 'cannon'

C = {'K': (16, 16, 8), 'D': (49, 49, 24), 'G': (49, 57, 41), 'M': (90, 99, 82), 'L': (140, 148, 132),
     'H': (189, 198, 181), 'N': (8, 0, 0)}
BLOCK = (49, 49, 24)            # 原素材后端平涂块的颜色
OUTLINE = C['N']
# 端盖：第 43–62 行（20 行），相对吊杆 x 14–20（7 列）；'.' 为透明
DRUM = [
    '.KKKK..',
    'KGGGGK.',
    'GGMMGGK',
    'GMMMMGK',
    'GMMMMGK',
    'GMLLMGK',
    'MLLLMGD',
    'MLHLLGD',
    'MLLLMGD',
    'GMLMMGD',
    'GMMMGGD',
    'GMMMGDD',
    'DGGGGDD',
    'DGGGGDD',
    'DDGGDDK',
    'DDDDDDK',
    'KDDDDKK',
    'KDDDDK.',
    'KKDDKK.',
    '.KKKK..',
]
DRUM_X, DRUM_Y = 14, 43
BARREL_END = 16                 # 炮管（第 50–61 行）保留到相对吊杆 x 13 为止，其后由端盖接上
SHIFT = {11: 2}                 # 炮身相对吊杆右移的帧


def glow(rgb):
    """蓄力光球、光束等发光像素：青蓝色（蓝明显高于红）或近白色。炮体为橄榄灰，蓝不高于红。"""
    r, g, b = rgb
    return b >= r + 40 or (r >= 230 and g >= 230 and b >= 230)


def fix_rear(img, ax, shift=0):
    img = img.copy()
    px = img.load()
    for y in range(42, 63):
        for x in range(img.width - 1, -1, -1):
            p = px[x, y]
            rel = x - ax - shift
            if rel <= 13:
                break
            if not p[3]:
                continue
            if (50 <= y <= 61 and rel > BARREL_END - 3) or p[:3] == BLOCK or (43 <= y <= 62 and rel >= DRUM_X):
                px[x, y] = (0, 0, 0, 0)
                continue
            break
    for r, line in enumerate(DRUM):
        for c, ch in enumerate(line):
            x = ax + shift + DRUM_X + c
            if ch != '.' and 0 <= x < img.width:
                px[x, DRUM_Y + r] = C[ch] + (255,)
    return img


def outline(img, ax):
    w, h = img.size
    out = Image.new('RGBA', (w + 2, h + 1), (0, 0, 0, 0))
    out.alpha_composite(img, (1, 0))
    src = out.copy().load()
    o = out.load()

    def solid(x, y):
        if not (0 <= x < w + 2 and 0 <= y < h + 1):
            return False
        p = src[x, y]
        return p[3] > 0 and not glow(p[:3])

    for y in range(h + 1):
        for x in range(w + 2):
            if not src[x, y][3] and any(solid(x + dx, y + dy) for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1))):
                o[x, y] = OUTLINE + (255,)
    return out, ax + 1


def build(frames_json):
    """生成修正后的帧，返回与 frames.json 中 cannon 同格式的列表（文件名相对 derived/cannon/）。"""
    OUT.mkdir(parents=True, exist_ok=True)
    result = []
    for i, f in enumerate(frames_json['cannon']):
        img = Image.open(FRAMES / f['file']).convert('RGBA')
        img = fix_rear(img, f['ax'], SHIFT.get(i, 0))
        img, ax = outline(img, f['ax'])
        name = f'cannon_{i:02d}.png'
        img.save(OUT / name)
        result.append({'file': name, 'ax': ax, 'ay': f['ay'], 'size': list(img.size), 'source': f'frames/{f["file"]}'})
    (OUT / 'cannon.json').write_text(json.dumps({'note': __doc__.strip().splitlines()[0], 'frames': result},
                                                ensure_ascii=False, indent=2), encoding='utf-8')
    return result


if __name__ == '__main__':
    print(json.dumps(build(json.loads((HERE / 'frames.json').read_text(encoding='utf-8'))), indent=1))
