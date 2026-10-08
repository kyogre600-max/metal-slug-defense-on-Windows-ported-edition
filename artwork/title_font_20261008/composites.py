"""缺失字母的原生笔画拼接。每个拼接字形由若干原生字形实例的像素按操作序列组合，
所有像素值均直接取自原生字形（同一行号取同一行号，保持逐行渐变一致）；仅 X 的左下腿为原生右下腿的水平镜像（已在 notes 标明）。

操作（坐标为字形图坐标，行 0–1 为空行，行 2 为上轮廓，与原生字形一致）：
  base(gid)                       以原生字形为底
  erase(x0, y0, x1, y1)           清除矩形（含端点）
  rows(gid, y0, y1, x0, x1, dx)   把源字形 y0..y1、x0..x1 的像素复制到同行、列偏移 dx（源透明像素也写入，即覆盖）
  over(gid, y0, y1, x0, x1, dx)   同上，但只写源非透明像素；目标为填充而源为轮廓时保留目标
  px(gid, sx, sy, dx, dy)         复制单个像素（取原生轮廓/暗边值）
  mirror(gid, y0, y1, x0, x1, axis)  水平镜像复制：源列 x 写到 axis - x
用法：composites.py → glyphs/composite/*.png、composites.json、composites_6x.png
"""
from pathlib import Path
import sys
import json

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
from native_font import load_db, is_fill, CORE_MIN, Image, ImageDraw  # noqa: E402

V16 = '16/V_profile_197_61_0'
T16 = '16/T_login_bonus_228_270_6'
U16 = '16/U_menu_485_344_3'          # MENU 词尾 U（右侧为词边轮廓）
O16 = '16/O_menu_485_258_0'          # OPTION 词首 O
R16 = '16/R_login_bonus_228_270_1'
K16 = '16/K_unit_232_340_3'          # DECK 词尾 K
E12 = '12/E_icon_mov_104_126_3'      # VIDEO 的 E（左轮廓完整）
I12_UNIT = '12/I_shop_180_434_2'     # UNIT 的 I：右暗边
I12_ITEM = '12/I_shop_455_125_0'     # ITEM 词首 I：右侧外轮廓
O12 = '12/O_icon_mov_104_126_4'      # VIDEO 词尾 O（右侧为词边轮廓）
S12 = '12/S_shop_304_241_1'          # MSP 的 S：右上收笔末行暗化

RECIPES = {
    '16/Y': {
        'notes': 'V 行 0–11（上半两臂）+ T 第 12–19 行竖笔（同行号）；第 12 行两臂下方写入 T 第 7 行横笔下轮廓的原生轮廓像素（仅黑色轮廓移行，填充颜色不移行）。',
        'ops': [('base', V16), ('erase', 0, 12, 18, 19),
                ('rows', T16, 12, 19, 4, 13, 0),          # T 第 12–19 行竖笔（同行号）
                ('rows', T16, 7, 7, 1, 5, 0, 5),          # 接合行：T 第 7 行横笔下轮廓（仅轮廓像素）移到第 12 行，两臂下方
                ('rows', T16, 7, 7, 12, 16, 0, 5)],
    },
    '16/J': {
        'notes': 'U（MENU 词尾）去掉左竖笔第 2–12 行，左竖笔下段保留为钩；钩顶第 12 行写入 U 第 2 行左竖笔上方的原生上轮廓。',
        'ops': [('base', U16), ('erase', 0, 2, 7, 12),
                ('rows', U16, 2, 2, 1, 7, 0, 10)],        # 第 2 行轮廓复制到第 12 行（行偏移 10，仅轮廓像素）
    },
    '16/Q': {
        'notes': 'O（OPTION 词首）+ R（PRESENT）右下腿第 14–19 行（同行号），右移 3 列作为尾巴；填充优先。',
        'ops': [('base', O16), ('over', R16, 14, 19, 9, 17, 3)],
    },
    '16/X': {
        'notes': 'V 行 0–11（上半两臂）+ K（DECK 词尾）右下腿第 12–19 行（右移 1 列）+ 同一右下腿的水平镜像作为左下腿（镜像为位置变换，像素值为原生）。',
        'ops': [('base', V16), ('erase', 0, 12, 18, 19),
                ('over', K16, 12, 19, 8, 18, 1),
                ('mirror', K16, 12, 19, 8, 18, 18)],
    },
    '12/L': {
        'notes': 'E（VIDEO）第 0–1、11–15 行（底横及其上轮廓）；第 2–10 行为竖笔：E 的左轮廓与竖笔填充 0–3 列、UNIT 的 I 右暗边、ITEM 词首 I 的右侧外轮廓；顶角取 ITEM 的 I 上轮廓角点。',
        'ops': [('base', E12), ('erase', 4, 2, 10, 10),
                ('rows', I12_UNIT, 3, 10, 4, 4, 0),       # 右暗边（第 3–10 行）
                ('rows', I12_ITEM, 3, 10, 6, 6, -1),      # 右外轮廓 → 第 5 列
                ('px', I12_ITEM, 5, 2, 4, 2),             # 顶部右角点
                ('px', I12_ITEM, 6, 2, 5, 2)],
    },
    '12/C': {
        'notes': 'O（VIDEO 词尾）右笔第 7–10 行打开；第 7、10 行写入 O 内孔上轮廓的原生值作为两端收笔轮廓，右角点取 O 外轮廓值；上收笔末行（第 6 行）取 S 第 6 行右上收笔暗化像素（同行号）。',
        'ops': [('base', O12), ('erase', 8, 7, 13, 10),
                ('rows', S12, 6, 6, 6, 9, 2),
                ('px', O12, 6, 6, 8, 7), ('px', O12, 6, 6, 9, 7), ('px', O12, 6, 6, 10, 7), ('px', O12, 6, 6, 11, 7),
                ('px', O12, 12, 2, 12, 7),
                ('px', O12, 6, 6, 8, 10), ('px', O12, 6, 6, 9, 10), ('px', O12, 6, 6, 10, 10), ('px', O12, 6, 6, 11, 10),
                ('px', O12, 12, 2, 12, 10)],
    },
}


def build(recipe, imgs):
    canvas = {}
    for op in recipe['ops']:
        kind = op[0]
        if kind == 'base':
            im = imgs[op[1]]
            p = im.load()
            canvas = {(x, y): p[x, y] for x in range(im.width) for y in range(im.height) if p[x, y][3]}
        elif kind == 'erase':
            _, x0, y0, x1, y1 = op
            for k in [k for k in canvas if x0 <= k[0] <= x1 and y0 <= k[1] <= y1]:
                del canvas[k]
        elif kind in ('rows', 'over'):
            gid, y0, y1, x0, x1, dx = op[1:7]
            dy = op[7] if len(op) > 7 else 0
            p = imgs[gid].load()
            W, H = imgs[gid].size
            for y in range(y0, y1 + 1):
                for x in range(x0, min(x1, W - 1) + 1):
                    c = p[x, y] if y < H else (0, 0, 0, 0)
                    k = (x + dx, y + dy)
                    if kind == 'rows' and dy:          # 行偏移复制仅用于轮廓（黑色）像素
                        if c[3] and max(c[:3]) <= 12:
                            canvas[k] = c
                        continue
                    if kind == 'rows':
                        if c[3]:
                            canvas[k] = c
                        else:
                            canvas.pop(k, None)
                    elif c[3]:
                        if k in canvas and is_fill(canvas[k]) and not is_fill(c):
                            continue
                        canvas[k] = c
        elif kind == 'px':
            gid, sx, sy, dx, dy = op[1:]
            canvas[(dx, dy)] = imgs[gid].load()[sx, sy]
        elif kind == 'mirror':
            gid, y0, y1, x0, x1, axis = op[1:]
            p = imgs[gid].load()
            W, H = imgs[gid].size
            for y in range(y0, min(y1, H - 1) + 1):
                for x in range(x0, min(x1, W - 1) + 1):
                    c = p[x, y]
                    k = (axis - x, y)
                    if c[3] and k[0] >= 0:
                        if k in canvas and is_fill(canvas[k]) and not is_fill(c):
                            continue
                        canvas[k] = c
    x_min = min(x for x, _ in canvas)
    W = max(x for x, _ in canvas) - x_min + 1
    H = max(y for _, y in canvas) + 1
    img = Image.new('RGBA', (W, H), (0, 0, 0, 0))
    for (x, y), c in canvas.items():
        img.putpixel((x - x_min, y), c)
    core = [x - x_min for (x, y), c in canvas.items() if c[3] == 255 and max(c[:3]) >= CORE_MIN]
    return img, {'fl': min(core), 'fr': max(core), 'w': W, 'h': H}


def main():
    db, imgs = load_db()
    out = HERE / 'glyphs' / 'composite'
    out.mkdir(parents=True, exist_ok=True)
    meta = {}
    tiles = []
    for key, r in RECIPES.items():
        size, ch = key.split('/')
        img, m = build(r, imgs)
        gid = f'composite/{size}_{ch}'
        img.save(HERE / 'glyphs' / (gid + '.png'))
        m.update(ch=ch, id=gid, size=int(size), word=None, index=0, abs_x=0, joined_left=False, joined_right=False,
                 composite=True, notes=r['notes'], sources=sorted({op[1] for op in r['ops'] if isinstance(op[1], str)}))
        meta[gid] = m
        tiles.append((key, img, [imgs[s] for s in m['sources']]))
    json.dump(meta, open(HERE / 'composites.json', 'w', encoding='utf-8'), indent=1, ensure_ascii=False)
    Z = 8
    rows = []
    for key, img, srcs in tiles:
        ims = srcs + [img]
        W = sum(i.width + 3 for i in ims) * Z
        H = max(i.height for i in ims) * Z + 14
        t = Image.new('RGBA', (W, H), (60, 120, 60, 255))
        d = ImageDraw.Draw(t)
        d.text((2, 0), key + '  = ' + ' + '.join(s.split('/')[-1] for s in []) + '  (sources ... → result, right)', fill=(255, 255, 255, 255))
        x = 0
        for i in ims:
            t.alpha_composite(i.resize((i.width * Z, i.height * Z), Image.NEAREST), (x, 14))
            x += (i.width + 3) * Z
        rows.append(t)
    W = max(t.width for t in rows)
    sh = Image.new('RGBA', (W, sum(t.height + 6 for t in rows)), (30, 30, 30, 255))
    y = 0
    for t in rows:
        sh.alpha_composite(t, (0, y))
        y += t.height + 6
    sh.save(HERE / 'composites_6x.png')
    print({k: (v['fl'], v['fr'], v['w']) for k, v in meta.items()})


if __name__ == '__main__':
    main()
