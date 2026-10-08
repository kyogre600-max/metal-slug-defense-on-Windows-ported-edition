"""拼接方法对照：用与 12 行 L 相同的方法，在 16 行字号以原生 E + 原生 I 拼出 L，与原生 16 行 L 的各实例逐像素比较；
并给出原生 L 实例彼此之间的差异作为基线（原生同字母本身存在边缘变体）。输出 method_check.json、method_check_8x.png。"""
from pathlib import Path
import sys
import json
import itertools

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
from native_font import load_db, instance_diff, aligned, diff, Image  # noqa: E402
from composites import build  # noqa: E402

E16 = '16/E_medal_shop_69_305_1'
I16 = '16/I_shop_343_322_0'
RECIPE = {'ops': [('base', E16), ('erase', 5, 2, 13, 13),
                  ('rows', I16, 3, 13, 5, 5, 0),     # I 的右暗边
                  ('rows', I16, 3, 13, 6, 6, 0),     # I 的右外轮廓
                  ('px', I16, 5, 2, 5, 2), ('px', I16, 6, 2, 6, 2)]}


def main():
    db, imgs = load_db()
    img, m = build(RECIPE, imgs)
    m['ch'] = 'L'
    natives = sorted(g for g, v in db['glyphs'].items() if v['ch'] == 'L' and v['size'] == 16)
    res = {}
    for g in natives:
        W = max(m['w'], db['glyphs'][g]['w']) + 16
        res[g] = diff(aligned(img, m, W), aligned(imgs[g], db['glyphs'][g], W))
    base = [instance_diff(db, imgs, a, b) for a, b in itertools.combinations(natives, 2)]
    base_bad = sorted(d[1] for d in base)
    out = {'recipe': [list(o) for o in RECIPE['ops']],
           'stitched_vs_native': {g: {'pixels': d[0], 'diff_px': d[1], 'max_channel_diff': d[2]} for g, d in res.items()},
           'stitched_best_diff_px': min(d[1] for d in res.values()),
           'native_pairwise_diff_px': {'min': base_bad[0], 'median': base_bad[len(base_bad) // 2], 'max': base_bad[-1],
                                       'pairs': len(base_bad)}}
    json.dump(out, open(HERE / 'method_check.json', 'w', encoding='utf-8'), indent=1)
    best = min(res, key=lambda g: res[g][1])
    W = max(m['w'], db['glyphs'][best]['w']) + 16
    a, b = aligned(img, m, W), aligned(imgs[best], db['glyphs'][best], W)
    dm = Image.new('RGBA', a.size, (0, 0, 0, 0))
    pa, pb = a.load(), b.load()
    for x in range(a.width):
        for y in range(a.height):
            if pa[x, y] != pb[x, y]:
                dm.putpixel((x, y), (255, 0, 0, 255))
    Z = 8
    sh = Image.new('RGBA', (a.width * 3 * Z + 40, a.height * Z), (60, 120, 60, 255))
    for i, im in enumerate((a, b, dm)):
        sh.alpha_composite(im.resize((im.width * Z, im.height * Z), Image.NEAREST), (i * (a.width * Z + 20), 0))
    sh.save(HERE / 'method_check_8x.png')
    print(json.dumps({k: v for k, v in out.items() if k != 'recipe'}, indent=1))


if __name__ == '__main__':
    main()
