"""原生标题字体：从原生整词逐字母裁切原生 RGBA 像素，建立字形库、测量字距，并按原生整词重排对照。

字形切分（每个原生词）：
  - 填充像素：不透明且非纯黑（max(RGB) > 12）；轮廓像素：黑色（max(RGB) <= 12）且 alpha > 0。
  - 按含填充像素的列切成连续列段，一段一个字母；填充相连的字母对（如 TO、LA、PT）用 CUTS 指定切分列
    （x < cut 的填充属于左字母）。i 的点与竖笔同列，归入同一字母。
  - 轮廓像素归属与之欧氏距离最近的填充像素所属字母（距离上限 2.9），每个原生像素只归一个字母，
    因此用本词自身字形与本词字距重排时应与原图逐像素一致（自重排检查）。
度量：每个字形记录填充左右列 fl、fr（相对字形图左上角），字距 gap = 右字母 fl − 左字母 fr − 1（两填充之间的列数）。
排字：按字距放置字形；两字形在同一像素重叠时，填充像素优先，两个轮廓像素取较大 alpha。

用法：
  native_font.py extract  解码目录   → glyphs/<size>/、glyphs.json、segmentation_<size>.png
  native_font.py verify   解码目录   → verify_report.json、verify_<size>.png
"""
from pathlib import Path
import sys
import json
import collections
import itertools

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
import portable_launcher  # noqa: F401,E402
from PIL import Image, ImageDraw  # noqa: E402

# (图集, 字号=填充行数, 填充首行 y0, 列范围 x0..x1, 文字)。文字中的空格表示两词之间不参与字距统计的断开。
WORDS = [
    ('menu', 16, 485, 0, 131, 'CUSTOMIZE'),
    ('menu', 16, 485, 133, 256, 'LANGUAGE'),
    ('menu', 16, 485, 258, 343, 'OPTION'),
    ('menu', 16, 485, 344, 410, 'MENU'),
    ('menu', 16, 485, 412, 475, 'SHOP'),
    ('login_bonus', 16, 1, 0, 67, 'LOGIN'),
    ('login_bonus', 16, 1, 74, 152, 'BONUS'),
    ('login_bonus', 16, 228, 270, 372, 'PRESENT'),
    ('login_bonus', 16, 478, 68, 259, 'COLLABORATION'),
    ('medal_shop', 16, 69, 305, 383, 'MEDAL'),
    ('medal_shop', 16, 69, 388, 450, 'SHOP'),
    ('menu_mission', 16, 206, 228, 321, 'MISSION'),
    ('pause_menu', 16, 331, 114, 189, 'PAUSE'),
    ('pause_menu', 16, 331, 195, 260, 'MENU'),
    ('prisoner_list', 16, 202, 0, 52, 'POW'),
    ('prisoner_list', 16, 202, 57, 106, 'LIST'),
    ('profile', 16, 197, 0, 56, 'Wi-Fi'),
    ('profile', 16, 197, 61, 152, 'VERSUS'),
    ('profile', 16, 216, 0, 92, 'PROFILE'),
    ('shop', 16, 278, 391, 453, 'SHOP'),
    ('shop', 16, 321, 446, 505, 'BASE'),
    ('shop', 16, 343, 322, 390, 'ITEMS'),
    ('shop', 16, 477, 0, 131, 'CUSTOMIZE'),
    ('stageselect_01', 16, 212, 0, 75, 'STAGE'),
    ('stageselect_01', 16, 212, 81, 166, 'SELECT'),
    ('stageselect_01', 16, 231, 0, 63, 'AREA'),
    ('stageselect_01', 16, 231, 68, 154, 'SELECT'),
    ('unit', 16, 232, 340, 402, 'DECK'),
    ('shop', 12, 180, 434, 480, 'UNIT'),
    ('shop', 12, 304, 241, 279, 'MSP'),
    ('shop', 12, 455, 125, 170, 'ITEM'),
    ('icon_mov', 12, 104, 126, 177, 'VIDEO'),
    ('icon_mov', 12, 119, 126, 151, 'AD'),
    ('shop', 8, 308, 312, 344, 'NEXT'),
    ('shop', 8, 308, 351, 385, 'BACK'),
]
# 填充相连字母对的切分列：(图集, y0, x0) → [cut, ...]
CUTS = {('menu', 485, 133): [147], ('menu', 485, 258): [289], ('login_bonus', 478, 68): [128, 190, 221],
        ('profile', 197, 0): [22], ('stageselect_01', 212, 81): [150], ('stageselect_01', 231, 68): [110], ('icon_mov', 104, 126): [139]}

FILL_MIN = 13
CORE_MIN = 121  # 切分列段只用较亮的填充核心（暗化抗锯齿边缘按距离归属）
MAX_LAYER = 4


def is_fill(p):
    return p[3] == 255 and max(p[:3]) >= FILL_MIN


def word_key(w):
    return f'{w[0]}@{w[2]}:{w[3]}'


def segment(dec, w):
    """返回 (crop 原点, [每字母 {'pix': {(x,y): rgba}, 'fill': set}], 未归属轮廓数)。坐标为图集绝对坐标。"""
    name, n, y0, x0, x1, text = w
    im = Image.open(dec / (name + '.png')).convert('RGBA')
    px = im.load()
    ya, yb = max(0, y0 - 3), min(im.height, y0 + n + 3)
    xa, xb = max(0, x0 - 3), min(im.width, x1 + 4)
    fill = {(x, y) for x in range(x0, x1 + 1) for y in range(y0 - 1, y0 + n + 1) if px[x, y][3] == 255 and max(px[x, y][:3]) >= CORE_MIN}
    # 填充核心按 4 连通分量分组；列范围重叠达较窄者一半的分量合并（i 的点、字母内部分离部分）
    comps, seen = [], set()
    for p0 in sorted(fill):
        if p0 in seen:
            continue
        stack, comp = [p0], set()
        seen.add(p0)
        while stack:
            x, y = stack.pop()
            comp.add((x, y))
            for q in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
                if q in fill and q not in seen:
                    seen.add(q)
                    stack.append(q)
        comps.append(comp)
    for cut in CUTS.get((name, y0, x0), []):
        for c in comps:
            xs = [x for x, _ in c]
            if min(xs) < cut <= max(xs):
                comps.remove(c)
                comps += [{p for p in c if p[0] < cut}, {p for p in c if p[0] >= cut}]
                break
    comps = [c for c in comps if len(c) >= 2]
    merged = True
    while merged:
        merged = False
        for c1, c2 in itertools.combinations(comps, 2):
            a0, a1 = min(x for x, _ in c1), max(x for x, _ in c1)
            b0, b1 = min(x for x, _ in c2), max(x for x, _ in c2)
            ov = min(a1, b1) - max(a0, b0) + 1
            if ov > 0 and ov * 2 >= min(a1 - a0, b1 - b0) + 1:
                comps.remove(c1)
                comps.remove(c2)
                comps.append(c1 | c2)
                merged = True
                break
    comps.sort(key=lambda c: min(x for x, _ in c))
    letters = [c for c in text]
    if len(comps) != len(letters):
        print('切分失败', f'{word_key(w)} {text}: {len(comps)} 个填充分量 '
                         f'{[(min(x for x, _ in c), max(x for x, _ in c), len(c)) for c in comps]}，字母 {len(letters)} 个')
        return None, (0, 0)
    lab = {p: i for i, c in enumerate(comps) for p in c}
    glyphs = [{'ch': ch, 'pix': {}, 'fill': set()} for ch in letters]
    for p, i in lab.items():
        glyphs[i]['pix'][p] = px[p]
        glyphs[i]['fill'].add(p)
    # 其余非透明像素（暗化填充边缘、黑色轮廓、淡轮廓）：对每个字母分别做 8 连通广度优先，得到经非透明像素到该字母
    # 填充核心的步数 d。非黑像素归最近的字母（并列取欧氏距离最近的核心）；黑色轮廓像素归所有 d <= max(2, 最小 d)
    # 的字母——相邻两字母共用的 1 列轮廓因此同时保存在两个字形中，排字时两份相同像素取较大 alpha，原词重排不受影响。
    dist = []
    for i, c in enumerate(comps):
        d = {q: 0 for q in c}
        frontier = list(c)
        for layer in range(1, MAX_LAYER + 1):
            nxt = []
            for (x, y) in frontier:
                for dx in (-1, 0, 1):
                    for dy in (-1, 0, 1):
                        q = (x + dx, y + dy)
                        if q in d or q in lab or not (xa <= q[0] < xb and ya <= q[1] < yb) or px[q][3] == 0:
                            continue
                        d[q] = layer
                        nxt.append(q)
            frontier = nxt
        dist.append(d)
    owner = {}
    cand_px = set().union(*[set(d) for d in dist]) - set(lab)
    fills = [set(c) for c in comps]
    for q in sorted(cand_px):                  # 先归属非黑像素（暗化填充边缘）
        if max(px[q][:3]) <= 12:
            continue
        ds = {i: d[q] for i, d in enumerate(dist) if q in d}
        m = min(ds.values())
        i = min((i for i, v in ds.items() if v == m),
                key=lambda i: min((cx - q[0]) ** 2 + (cy - q[1]) ** 2 for cx, cy in comps[i]))
        owner[q] = [i]
        fills[i].add(q)
    for q in sorted(cand_px):                  # 再归属黑色轮廓：须距该字母自身填充不超过 1.5 px
        if max(px[q][:3]) > 12:
            continue
        ds = {i: d[q] for i, d in enumerate(dist) if q in d}
        m = min(ds.values())
        near = {i: min((fx - q[0]) ** 2 + (fy - q[1]) ** 2 for fx, fy in fills[i]) for i in ds}
        ls = [i for i, v in ds.items() if v <= max(2, m) and near[i] <= 2.25]
        owner[q] = ls or [min(ds, key=lambda i: (ds[i], near[i]))]
    for q, ls in owner.items():
        for i in ls:
            glyphs[i]['pix'][q] = px[q]
    shared = sum(1 for ls in owner.values() if len(ls) > 1)
    orphan = sum(1 for x in range(xa + 1, xb - 1) for y in range(ya, yb)
                 if px[x, y][3] and (x, y) not in owner and (x, y) not in lab and x0 <= x <= x1 and y0 - 2 <= y <= y0 + n + 1)
    return glyphs, (orphan, shared)


def glyph_record(g, top):
    xs = [x for x, _ in g['pix']]
    gx0, gx1 = min(xs), max(xs)
    fx = [x for x, _ in g['fill']]
    h = max(y for _, y in g['pix']) - top + 1
    img = Image.new('RGBA', (gx1 - gx0 + 1, max(h, 1)), (0, 0, 0, 0))
    for (x, y), p in g['pix'].items():
        img.putpixel((x - gx0, y - top), p)
    return img, {'fl': min(fx) - gx0, 'fr': max(fx) - gx0, 'abs_x': gx0}


def render(seq, gaps_for, n):
    """seq：[(ch, Image, meta)]；gaps_for(a, b) → 字距。返回 (Image, 每字母放置 x)。"""
    H = n + 6
    pos = []
    x_fill = 3
    for k, (ch, img, m) in enumerate(seq):
        if k:
            prev = seq[k - 1]
            x_fill = pos[-1] + prev[2]['fr'] + 1 + gaps_for(prev[0], ch)
            pos.append(x_fill - m['fl'])
        else:
            pos.append(x_fill - m['fl'])
    W = max(p + s[1].width for p, s in zip(pos, seq)) + 3
    shift = -min(0, min(pos))
    canvas = {}
    for p, (ch, img, m) in zip(pos, seq):
        src = img.load()
        for x in range(img.width):
            for y in range(img.height):
                c = src[x, y]
                if c[3] == 0:
                    continue
                k = (x + p + shift, y)
                if k in canvas:
                    o = canvas[k]
                    if is_fill(o) and not is_fill(c):
                        continue
                    if not is_fill(o) and not is_fill(c):
                        c = c if c[3] >= o[3] else o
                canvas[k] = c
    out = Image.new('RGBA', (W + shift, H), (0, 0, 0, 0))
    for k, c in canvas.items():
        out.putpixel(k, c)
    return out, [p + shift for p in pos]


def extract(dec):
    db = {'words': [], 'glyphs': {}}
    sheets = collections.defaultdict(list)
    for w in WORDS:
        name, n, y0, x0, x1, text = w
        glyphs, orphan = segment(dec, w)
        if glyphs is None:
            continue
        top = y0 - 3
        recs = []
        for k, g in enumerate(glyphs):
            img, m = glyph_record(g, top)
            gid = f'{n}/{g["ch"] if g["ch"].isupper() else "lower_" + g["ch"] if g["ch"].isalpha() else "U%04X" % ord(g["ch"])}_{name}_{y0}_{x0}_{k}'
            out = HERE / 'glyphs' / (gid + '.png')
            out.parent.mkdir(parents=True, exist_ok=True)
            img.save(out)
            m.update(ch=g['ch'], id=gid, size=n, word=word_key(w), index=k, w=img.width, h=img.height,
                     joined_left=False, joined_right=False)
            recs.append(m)
        for a, b in zip(recs, recs[1:]):
            gap = (b['abs_x'] + b['fl']) - (a['abs_x'] + a['fr']) - 1
            a['gap_right'] = gap
            if gap <= 0:
                a['joined_right'] = b['joined_left'] = True
        for m in recs:
            db['glyphs'][m['id']] = m
        db['words'].append({'key': word_key(w), 'atlas': name, 'size': n, 'y0': y0, 'x0': x0, 'x1': x1, 'text': text,
                            'glyphs': [m['id'] for m in recs], 'unassigned_px': orphan[0], 'shared_outline_px': orphan[1]})
        sheets[n].append((w, glyphs))
        print(word_key(w), text, 'gaps', [m.get('gap_right') for m in recs[:-1]], 'orphan', orphan)
    json.dump(db, open(HERE / 'glyphs.json', 'w', encoding='utf-8'), indent=1, ensure_ascii=False)
    pal = [(230, 60, 60), (60, 160, 230), (240, 200, 40), (90, 200, 90), (200, 90, 220), (240, 140, 40)]
    for n, items in sheets.items():
        rows = []
        for w, glyphs in items:
            name, _, y0, x0, x1, text = w
            ox, oy = x0 - 3, y0 - 3
            W, H = x1 - x0 + 7, n + 6
            a = Image.new('RGBA', (W, H), (60, 60, 60, 255))
            b = Image.new('RGBA', (W, H), (255, 255, 255, 255))
            for k, g in enumerate(glyphs):
                for (x, y), p in g['pix'].items():
                    a.alpha_composite(Image.new('RGBA', (1, 1), p), (x - ox, y - oy))
                    b.putpixel((x - ox, y - oy), pal[k % len(pal)] + (255,) if (x, y) in g['fill'] else
                               tuple(int(c * 0.45) for c in pal[k % len(pal)]) + (255,))
            rows.append((word_key(w) + ' ' + text, a, b))
        S = 4
        W = max(r[1].width for r in rows) * S * 2 + 16
        H = sum(r[1].height * S + 14 for r in rows)
        sh = Image.new('RGBA', (W, H), (255, 255, 255, 255))
        d = ImageDraw.Draw(sh)
        y = 0
        for t, a, b in rows:
            d.text((2, y), t, fill=(0, 0, 0, 255))
            y += 12
            sh.paste(a.resize((a.width * S, a.height * S), Image.NEAREST), (0, y))
            sh.paste(b.resize((b.width * S, b.height * S), Image.NEAREST), (a.width * S + 16, y))
            y += a.height * S + 2
        sh.save(HERE / f'segmentation_{n}.png')


def load_db(with_composites=False):
    db = json.load(open(HERE / 'glyphs.json', encoding='utf-8'))
    if with_composites and (HERE / 'composites.json').exists():
        db['glyphs'].update(json.load(open(HERE / 'composites.json', encoding='utf-8')))
    imgs = {gid: Image.open(HERE / 'glyphs' / (gid + '.png')).convert('RGBA') for gid in db['glyphs']}
    return db, imgs


def gap_table(db, size, exclude_word=None):
    pairs = collections.defaultdict(list)
    allg = collections.Counter()
    for w in db['words']:
        if w['size'] != size or w['key'] == exclude_word:
            continue
        gs = [db['glyphs'][g] for g in w['glyphs']]
        for a, b in zip(gs, gs[1:]):
            pairs[a['ch'] + b['ch']].append(a['gap_right'])
            if a['gap_right'] > 0:
                allg[a['gap_right']] += 1
    default = allg.most_common(1)[0][0] if allg else 2
    return {k: collections.Counter(v).most_common(1)[0][0] for k, v in pairs.items()}, default, allg


def diff(a, b):
    W, H = max(a.width, b.width), max(a.height, b.height)
    pa, pb = a.load(), b.load()
    tot = bad = 0
    maxd = 0
    for x in range(W):
        for y in range(H):
            ca = pa[x, y] if x < a.width and y < a.height else (0, 0, 0, 0)
            cb = pb[x, y] if x < b.width and y < b.height else (0, 0, 0, 0)
            if ca[3] == 0 and cb[3] == 0:
                continue
            tot += 1
            d = max(abs(i - j) for i, j in zip(ca, cb)) if (ca[3] and cb[3]) else 255
            maxd = max(maxd, d)
            if d:
                bad += 1
    return tot, bad, maxd


def aligned(img, m, W=None):
    """把字形放到以填充左列为 x=3 的画布上，便于逐像素比较。"""
    out = Image.new('RGBA', (W or img.width + 8, img.height), (0, 0, 0, 0))
    out.paste(img, (3 - m['fl'] + 4, 0))
    return out


def instance_diff(db, imgs, a, b):
    ma, mb = db['glyphs'][a], db['glyphs'][b]
    W = max(ma['w'], mb['w']) + 16
    return diff(aligned(imgs[a], ma, W), aligned(imgs[b], mb, W))


def contexts(db):
    """每个原生字形的左右邻字（词首/词尾记为 None）。"""
    ctx = {}
    for w in db['words']:
        gs = w['glyphs']
        for i, g in enumerate(gs):
            ctx[g] = (db['glyphs'][gs[i - 1]]['ch'] if i else None, db['glyphs'][gs[i + 1]]['ch'] if i + 1 < len(gs) else None)
    return ctx


_CTX = {}


def choose(db, imgs, ch, size, exclude_word=None, left=False, right=False):
    """同字号同字母的原生实例中取代表。left/right 为期望的左右邻字（None 表示词首/词尾，False 表示不限）。
    评分：邻字相同 2 分，同为词边或同为词内 1 分（左右各计）；同分者取与其余实例差异像素总和最小者（medoid）。"""
    ctx = _CTX.setdefault(id(db), contexts(db))
    cands = [g for g, m in db['glyphs'].items() if m['ch'] == ch and m['size'] == size and (exclude_word is None or m['word'] != exclude_word)]
    if not cands:
        return None

    def side(want, have):
        if want is False:
            return 0
        if want == have:
            return 2
        return 1 if (want is None) == (have is None) else 0
    score = {g: side(left, ctx.get(g, (None, None))[0]) + side(right, ctx.get(g, (None, None))[1]) for g in cands}
    top = max(score.values())
    pool = [g for g in cands if score[g] == top]
    return min(pool, key=lambda g: (sum(instance_diff(db, imgs, g, h)[1] for h in cands if h != g), g))


def word_reference(db, imgs, w):
    gs = [db['glyphs'][g] for g in w['glyphs']]
    ox = gs[0]['abs_x'] + gs[0]['fl'] - 3
    W = max(m['abs_x'] + m['w'] for m in gs) - ox + 3
    H = max(m['h'] for m in gs)
    out = Image.new('RGBA', (W, H), (0, 0, 0, 0))
    for g in w['glyphs']:     # 原生像素直接写回（共用轮廓在两个字形中为同一原生值）
        src, gx = imgs[g].load(), db['glyphs'][g]['abs_x'] - ox
        for x in range(imgs[g].width):
            for y in range(imgs[g].height):
                if src[x, y][3]:
                    out.putpixel((x + gx, y), src[x, y])
    return out


def typeset(db, imgs, text, size, gaps=None, default=None, pick=None):
    """以原生字形排字；pick(ch) → 字形 id。字距：原生同字母对的众数，否则该字号默认值（正字距众数）。"""
    if gaps is None:
        gaps, default, _ = gap_table(db, size)
    seq = []
    for i, ch in enumerate(text):
        lc = text[i - 1] if i else None
        rc = text[i + 1] if i + 1 < len(text) else None
        gid = pick(ch, lc, rc) if pick else choose(db, imgs, ch, size, left=lc, right=rc)
        seq.append((ch, imgs[gid], db['glyphs'][gid]))
    return render(seq, lambda a, b: gaps.get(a + b, default), size)[0]


def verify(dec):
    db, imgs = load_db()
    report = {'instances': {}, 'words': []}
    # 1. 同字母不同实例的差异
    by = collections.defaultdict(list)
    for g, m in db['glyphs'].items():
        by[(m['size'], m['ch'])].append(g)
    for (size, ch), gs in sorted(by.items()):
        pairs = [(a, b, instance_diff(db, imgs, a, b)) for a, b in itertools.combinations(gs, 2)]
        report['instances'][f'{size}/{ch}'] = {
            'count': len(gs), 'identical_pairs': sum(1 for *_, d in pairs if d[1] == 0), 'pairs': len(pairs),
            'pair_diffs': [[db['glyphs'][a]['word'], db['glyphs'][b]['word'], d[0], d[1], d[2]] for a, b, d in pairs]}
    # 2. 整词重排：A 自重排（本词字形 + 本词字距）；B 交叉重排（其他词的字形 medoid + 其他词统计字距）
    sheets = collections.defaultdict(list)
    for w in db['words']:
        size = w['size']
        ref = word_reference(db, imgs, w)
        own = dict(zip(w['text'], w['glyphs']))
        mine = [db['glyphs'][g] for g in w['glyphs']]
        own_gaps = {}
        for a, b in zip(mine, mine[1:]):
            own_gaps[a['ch'] + b['ch']] = a['gap_right']
        seq = [(m['ch'], imgs[m['id']], m) for m in mine]
        it = iter(mine)
        gl = [m['gap_right'] for m in mine[:-1]]
        k = [0]

        def own_gap(a, b, k=k, gl=gl):
            v = gl[k[0]]
            k[0] += 1
            return v
        self_img = render(seq, own_gap, size)[0]
        gaps, default, _ = gap_table(db, size, exclude_word=w['key'])
        src = {}

        def pick(ch, lc=False, rc=False, w=w, src=src):
            g = choose(db, imgs, ch, size, exclude_word=w['key'], left=lc, right=rc)
            src[ch] = 'other' if g else 'own'
            return g or own[ch]
        cross = typeset(db, imgs, w['text'], size, gaps, default, pick)
        d_self = diff(ref, self_img)
        d_cross = diff(ref, cross)
        # 上限参考：每个字母取其他词中与本词该字母差异最小的实例（存在逐像素相同的复用实例时为 0），字距同上
        it_best = iter(mine)

        def pick_best(ch, lc=None, rc=None, w=w, it=it_best):
            m = next(it)
            cands = [g for g, mm in db['glyphs'].items() if mm['ch'] == ch and mm['size'] == size and mm['word'] != w['key']]
            if not cands:
                return m['id']
            return min(cands, key=lambda g: instance_diff(db, imgs, m['id'], g)[1])
        d_best = diff(ref, typeset(db, imgs, w['text'], size, gaps, default, pick_best))
        # 交叉重排逐字母：把每个字母单独放在原生位置比较（排除字距影响）
        per = []
        for i, m in enumerate(mine):
            g = pick(m['ch'], w['text'][i - 1] if i else None, w['text'][i + 1] if i + 1 < len(w['text']) else None)
            mm = db['glyphs'][g]
            W = max(m['w'], mm['w']) + 16
            per.append([m['ch'], src[m['ch']], *diff(aligned(imgs[m['id']], m, W), aligned(imgs[g], mm, W))[1:]])
        gap_used = [gaps.get(a['ch'] + b['ch'], default) for a, b in zip(mine, mine[1:])]
        rec = {'word': w['key'], 'text': w['text'], 'size': size,
               'self': {'pixels': d_self[0], 'diff_px': d_self[1], 'max_channel_diff': d_self[2]},
               'cross': {'pixels': d_cross[0], 'diff_px': d_cross[1], 'max_channel_diff': d_cross[2],
                         'width_native': ref.width, 'width_rebuilt': cross.width,
                         'native_gaps': gl,
                         'best_variant_diff_px': d_best[1], 'rebuilt_gaps': gap_used, 'per_letter_diff_px': per}}
        report['words'].append(rec)
        sheets[size].append((w, ref, cross))
        print(w['key'], w['text'], 'self', d_self[1], '/', d_self[0], '| cross', d_cross[1], '/', d_cross[0], '| best', d_best[1],
              'gaps', gl, gap_used, 'letters', [(c, s[0], b) for c, s, b, _ in per])
    json.dump(report, open(HERE / 'verify_report.json', 'w', encoding='utf-8'), indent=1, ensure_ascii=False)
    for size, items in sheets.items():
        S = 4
        rows = []
        for w, ref, cross in items:
            W = max(ref.width, cross.width)
            dm = Image.new('RGBA', (W, ref.height), (0, 0, 0, 0))
            pa, pb = ref.load(), cross.load()
            for x in range(W):
                for y in range(ref.height):
                    ca = pa[x, y] if x < ref.width else (0, 0, 0, 0)
                    cb = pb[x, y] if x < cross.width and y < cross.height else (0, 0, 0, 0)
                    if ca != cb and (ca[3] or cb[3]):
                        dm.putpixel((x, y), (255, 0, 0, 255))
                    elif ca[3]:
                        dm.putpixel((x, y), (200, 200, 200, 255))
            rows.append((w['key'] + ' ' + w['text'], [ref, cross, dm]))
        W = max(sum(i.width for i in r[1]) for r in rows) * S + 40
        H = sum(r[1][0].height * S + 14 for r in rows)
        sh = Image.new('RGBA', (W, H), (60, 90, 60, 255))
        d = ImageDraw.Draw(sh)
        y = 0
        for t, ims in rows:
            d.text((2, y), t + '   native | rebuilt (glyphs from other words) | diff (red)', fill=(255, 255, 255, 255))
            y += 12
            x = 0
            for i in ims:
                sh.alpha_composite(i.resize((i.width * S, i.height * S), Image.NEAREST), (x, y))
                x += i.width * S + 20
            y += ims[0].height * S + 2
        sh.save(HERE / f'verify_{size}.png')


if __name__ == '__main__':
    cmd, dec = sys.argv[1], Path(sys.argv[2])
    if cmd == 'extract':
        extract(dec)
    elif cmd == 'verify':
        verify(dec)
