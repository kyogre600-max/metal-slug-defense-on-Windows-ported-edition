"""生成字体图集、度量文件与标题（预览用，尚未放入游戏）。

  - font_atlas_<size>.png：每个字号一行，每字母取代表实例（原生同字母实例的 medoid；缺失字母取拼接字形）。
  - font_metrics.json：图集矩形、填充左右列 fl/fr、来源（原生词与图集坐标或拼接配方）、各字号字距表与默认字距、全部原生变体。
  - titles/<NAME>_<size>.png：标题原尺寸 RGBA；titles_preview_6x.png：放大预览（拼接字母下方标记）。
VERSUS 在 profile.obm 中有原生整词（Wi-Fi VERSUS），16 行版本直接输出原生整词像素；另附排字版本供对照。
排字：按上下文选原生实例（左右邻字相同优先，其次词首/词尾与词内类别相同），字距取原生同字母对众数，否则取该字号正字距众数。
"""
from pathlib import Path
import sys
import json

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
from native_font import (load_db, choose, gap_table, render, word_reference, contexts,  # noqa: E402
                         Image, ImageDraw)

TITLES = {16: ['VERSUS', 'LOCAL', 'LAN', 'ONLINE'], 12: ['LOCAL', 'LAN', 'ONLINE', 'VERSUS']}
CHARS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'


def typeset(db, imgs, text, size):
    gaps, default, _ = gap_table(db, size)
    seq, used = [], []
    for i, ch in enumerate(text):
        lc = text[i - 1] if i else None
        rc = text[i + 1] if i + 1 < len(text) else None
        g = choose(db, imgs, ch, size, left=lc, right=rc)
        if g is None:
            raise KeyError(f'{size} 行字号缺少字母 {ch}')
        seq.append((ch, imgs[g], db['glyphs'][g]))
        used.append(g)
    img, pos = render(seq, lambda a, b: gaps.get(a + b, default), size)
    gap_src = ['native_pair' if (a + b) in gaps else 'default' for a, b in zip(text, text[1:])]
    return img, used, pos, gap_src


def main():
    db, imgs = load_db(with_composites=True)
    ctx = contexts(db)
    metrics = {'note': '坐标单位为像素；字形图第 0–1 行为空行，第 2 行为上轮廓，第 3 行起为填充（16/12/8 行）。',
               'sizes': {}}
    for size in (16, 12, 8):
        gaps, default, dist = gap_table(db, size)
        chars = [c for c in CHARS + '-i' if choose(db, imgs, c, size)]
        cells = []
        x = 1
        for c in chars:
            g = choose(db, imgs, c, size)
            m = db['glyphs'][g]
            cells.append((c, g, x))
            x += imgs[g].width + 2
        H = max(imgs[g].height for _, g, _ in cells)
        atlas = Image.new('RGBA', (x, H), (0, 0, 0, 0))
        glyph_meta = {}
        for c, g, gx in cells:
            atlas.alpha_composite(imgs[g], (gx, 0))
            m = db['glyphs'][g]
            variants = sorted(k for k, v in db['glyphs'].items() if v['ch'] == c and v['size'] == size)
            glyph_meta[c] = {'rect': [gx, 0, imgs[g].width, imgs[g].height], 'fl': m['fl'], 'fr': m['fr'],
                             'source': g, 'composite': bool(m.get('composite')),
                             'source_word': m.get('word'), 'context': ctx.get(g),
                             'notes': m.get('notes'), 'variants': variants}
        atlas.save(HERE / f'font_atlas_{size}.png')
        Z = 6
        big = Image.new('RGBA', (atlas.width * Z, atlas.height * Z + 16), (60, 120, 60, 255))
        big.alpha_composite(atlas.resize((atlas.width * Z, atlas.height * Z), Image.NEAREST), (0, 16))
        d = ImageDraw.Draw(big)
        for c, g, gx in cells:
            d.text((gx * Z + 4, 2), c + ('*' if db['glyphs'][g].get('composite') else ''), fill=(255, 255, 0, 255))
        big.save(HERE / f'font_atlas_{size}_6x.png')
        missing = [c for c in CHARS if c not in chars]
        metrics['sizes'][str(size)] = {'fill_rows': size, 'atlas': f'font_atlas_{size}.png', 'glyphs': glyph_meta,
                                       'missing': missing, 'default_gap': default,
                                       'gap_distribution': dict(sorted(dist.items())), 'pair_gaps': dict(sorted(gaps.items()))}
        print(size, 'chars', ''.join(chars), 'missing', ''.join(missing), 'default gap', default, dict(dist))
    json.dump(metrics, open(HERE / 'font_metrics.json', 'w', encoding='utf-8'), indent=1, ensure_ascii=False)

    out = HERE / 'titles'
    out.mkdir(exist_ok=True)
    rows = []
    report = {}
    vw = next(w for w in db['words'] if w['text'] == 'VERSUS')
    native_versus = word_reference(db, imgs, vw)
    native_versus.save(out / 'VERSUS_16_native.png')
    rows.append(('VERSUS 16-row: native word pixels (profile.obm "Wi-Fi VERSUS")', native_versus, []))
    report['VERSUS_16_native'] = {'source': vw['key'], 'glyphs': vw['glyphs']}
    for size, names in TITLES.items():
        for name in names:
            try:
                img, used, pos, gap_src = typeset(db, imgs, name, size)
            except KeyError as e:
                print('跳过', name, size, e)
                report[f'{name}_{size}'] = {'skipped': str(e)}
                continue
            fn = f'{name}_{size}' + ('_typeset' if name == 'VERSUS' and size == 16 else '')
            img.save(out / (fn + '.png'))
            marks = [(p + db['glyphs'][g]['fl'], p + db['glyphs'][g]['fr']) for g, p in zip(used, pos)
                     if db['glyphs'][g].get('composite')]
            label = f'{name} {size}-row: typeset from native glyphs' + (' (comparison only)' if fn.endswith('_typeset') else '') + ('   red bar = stitched letter' if marks else '')
            rows.append((label, img, marks))
            report[fn] = {'glyphs': used, 'contexts': [ctx.get(g) for g in used], 'gaps_from': gap_src,
                          'composite_letters': [db['glyphs'][g]['ch'] for g in used if db['glyphs'][g].get('composite')]}
    json.dump(report, open(out / 'titles_report.json', 'w', encoding='utf-8'), indent=1, ensure_ascii=False)
    Z = 6
    W = max(r[1].width for r in rows) * Z + 20
    H = sum(r[1].height * Z + 30 for r in rows)
    sh = Image.new('RGBA', (W, H), (52, 44, 36, 255))
    d = ImageDraw.Draw(sh)
    y = 0
    for label, img, marks in rows:
        d.text((4, y + 2), label, fill=(255, 255, 255, 255))
        y += 16
        sh.alpha_composite(img.resize((img.width * Z, img.height * Z), Image.NEAREST), (10, y))
        for a, b in marks:
            d.rectangle([10 + a * Z, y + img.height * Z + 2, 10 + (b + 1) * Z, y + img.height * Z + 6], fill=(255, 80, 80, 255))
        y += img.height * Z + 14
    sh.save(HERE / 'titles_preview_6x.png')


if __name__ == '__main__':
    main()
