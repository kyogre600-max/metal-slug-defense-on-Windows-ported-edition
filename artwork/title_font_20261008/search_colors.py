"""第二遍搜索（补漏）：以三种字号的原生填充渐变色（容差 TOL）在全部解码图集中查找像素，
按“同一行带内各行颜色对应渐变的同一行”聚类，报告图集、行带起点、字号与列范围。
渐变参考：16 行取 menu.png E 竖笔 x=121；12 行取 shop.png MSP 的 M 竖笔 x=244；8 行取 shop.png NEXT（x=302，行 308–315）。
用法：search_colors.py 解码目录"""
from pathlib import Path
import sys
import json
import collections

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
import portable_launcher  # noqa: F401,E402
from PIL import Image  # noqa: E402

TOL = 6


def profile(name, x, y0, n, dec):
    p = Image.open(dec / (name + '.png')).convert('RGBA').load()
    return [p[x, y][:3] for y in range(y0, y0 + n)]


def near(c, d):
    return all(abs(a - b) <= TOL for a, b in zip(c, d))


if __name__ == '__main__':
    DEC = Path(sys.argv[1])
    profiles = {16: profile('menu', 121, 485, 16, DEC), 12: profile('shop', 244, 304, 12, DEC)}
    p8 = Image.open(DEC / 'shop.png').convert('RGBA').load()
    profiles[8] = [max((p8[x, y][:3] for x in range(296, 330) if p8[x, y][3] == 255), key=sum) for y in range(308, 316)]
    report = {}
    for png in sorted(DEC.glob('*.png')):
        im = Image.open(png).convert('RGBA')
        colors = im.getcolors(1 << 24)
        cand = {}
        for size, prof in profiles.items():
            m = {c[:3] for _, c in colors if c[3] == 255 and any(near(c[:3], q) for q in prof)}
            if len(m) >= len(prof) // 2:
                cand[size] = prof
        if not cand:
            continue
        w, h = im.size
        px = im.load()
        for size, prof in cand.items():
            # 每个可能的行带起点 y0：统计行 y0+i 上与 prof[i] 相近的像素数
            rowmatch = []
            for y in range(h):
                row = [px[x, y] for x in range(w)]
                rowmatch.append([sum(1 for c in row if c[3] == 255 and near(c[:3], q)) for q in prof])
            for y0 in range(h - size + 1):
                score = sum(1 for i in range(size) if rowmatch[y0 + i][i] >= 3)
                if score >= size - 1 and sum(rowmatch[y0 + i][i] for i in range(size)) >= 12 * size:
                    xs = [x for x in range(w) if any(px[x, y0 + i][3] == 255 and near(px[x, y0 + i][:3], prof[i]) for i in range(size))]
                    report.setdefault(png.stem, []).append([size, y0, xs[0], xs[-1], len(xs)])
        if png.stem in report:
            print(png.stem, report[png.stem])
    json.dump({'profiles': {k: v for k, v in profiles.items()}, 'hits': report}, open(HERE / 'search_colors_hits.json', 'w'), indent=1)
