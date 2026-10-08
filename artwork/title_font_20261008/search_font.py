"""在全部解码图集中搜索标题字体特征：竖向连续填充列，上下各有黑色轮廓，填充为银蓝色逐行渐变
（顶部近白、下部 3/4 处最暗且 B>R、底部回亮）。按图集与行带汇总候选，输出 search_hits.json。
用法：search_font.py 解码目录"""
from pathlib import Path
import sys
import json
import collections

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
import portable_launcher  # noqa: F401,E402
from PIL import Image  # noqa: E402



def is_black(p):
    return p[3] > 0x40 and max(p[:3]) < 40


def column_runs(px, w, h, x):
    y = 0
    while y < h:
        p = px[x, y]
        if p[3] == 255 and max(p[:3]) > 60:
            y0 = y
            while y < h and px[x, y][3] == 255 and max(px[x, y][:3]) > 60:
                y += 1
            yield y0, y
        else:
            y += 1


def gradient_ok(col):
    n = len(col)
    if n < 9 or n > 26:
        return False
    top = col[0]
    if min(top[:3]) < 0xe0:
        return False
    lum = [sum(c[:3]) for c in col]
    k = min(range(n), key=lambda i: lum[i])
    if not (0.55 * n <= k <= 0.95 * n) or k == n - 1:
        return False
    dark = col[k]
    if not (dark[2] >= dark[0] + 10 and lum[k] < lum[0] - 120):
        return False
    if lum[-1] <= lum[k] + 20:
        return False
    # 自顶至最暗处单调不增（容差 6）
    return all(lum[i + 1] <= lum[i] + 6 for i in range(k))


if __name__ == '__main__':
    DEC = Path(sys.argv[1])
    hits = collections.defaultdict(lambda: collections.Counter())
    for png in sorted(DEC.glob('*.png')):
        im = Image.open(png).convert('RGBA')
        w, h = im.size
        px = im.load()
        for x in range(w):
            for y0, y1 in column_runs(px, w, h, x):
                if y0 == 0 or y1 >= h:
                    continue
                if not (is_black(px[x, y0 - 1]) and is_black(px[x, y1])):
                    continue
                col = [px[x, y] for y in range(y0, y1)]
                if gradient_ok(col):
                    hits[png.stem][(y0, y1 - y0)] += 1
    out = {}
    for name, c in hits.items():
        bands = [[y0, n, cnt] for (y0, n), cnt in sorted(c.items()) if cnt >= 3]
        if bands:
            out[name] = bands
    json.dump(out, open(HERE / 'search_hits.json', 'w'), indent=1)
    for name, b in sorted(out.items(), key=lambda kv: -sum(x[2] for x in kv[1])):
        print(name, sum(x[2] for x in b), b[:12])
