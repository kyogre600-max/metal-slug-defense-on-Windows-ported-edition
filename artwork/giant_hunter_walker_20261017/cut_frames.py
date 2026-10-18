"""巨型 Hunter Walker（MS6）素材表切帧与对齐（2026-10-17）。

来源：source/MS6_Giant_Hunter_Walker.png（The Spriters Resource，Division 6 / A Japanese Soldier 整理，2383×3865）。
素材表每个动作分身体、腿、合成三行；本脚本取合成行与卵、爆炸、坠地等效果行，被击败另取身体、腿、紫色液体与肉块三行
（见 DEATH_LAYER_ROWS）。帧与帧紧密排布、没有固定格子，对齐规则：
- 本体各帧：纵向以帧底（脚底）为地面；横向与待机第 1 帧对准，搜索范围 ±SEARCH 像素：行走以壳顶（帧顶部 TOP_ROWS 行的
  轮廓）对准（脚在移动）；待机、张嘴、吐卵、闭嘴、恢复行走与被击败以脚部（帧底部 FOOT_ROWS 行的轮廓）对准（嘴朝上张开时壳顶
  轮廓会变，脚不动）；被击败第 1 帧以脚部对准待机，之后逐帧以壳顶对准前一帧。单位原点 x 取待机第 1 帧的包围盒中心。
- 卵与效果帧：带浅绿底框的行以底框为格子（同一格内位置即原生对齐）；无底框的行以包围盒底边中点为锚点。
输出 frames/<动作>_<序号>.png（透明底，裁到内容）与 frames.json（每帧锚点：图内脚底点 / 中心点）。
"""
from pathlib import Path
import json
import os
import sys

HERE = Path(__file__).resolve().parent
RUNTIME = Path(sys.executable).resolve().parent
for _name in ('.', 'native', 'angle', 'DLLs'):
    if os.name == 'nt' and (RUNTIME / _name).is_dir():
        os.add_dll_directory(str(RUNTIME / _name))
from PIL import Image, ImageChops  # noqa: E402

SHEET = HERE / 'source' / 'MS6_Giant_Hunter_Walker.png'
OUT = HERE / 'frames'
BG = {(16, 216, 128, 255), (0, 255, 163, 255)}
BOX = (0, 255, 163, 255)
TOP_ROWS, FOOT_ROWS, SEARCH = 40, 24, 30
ALIGN_BY_TOP = {'walk'}
CHAIN_BY_TOP = {'death'}
CHAIN_SKIP = {('death', 11): 9}
# 2026-10-17 R2：被击败行第 5 帧起紫色爆裂的粒子落到脚底以下，按包围盒底边贴地会把本体抬高（最多 8 像素，战场中 16）；
# 素材表同一行各帧的脚底在同一基线上，这些行改以第 1 帧的底边为地面。
SHEET_BASELINE = {'death'}

# 合成行：(名称, y0, y1, [帧的 x 范围])；x 范围取自逐行扫描（帧间空隙约 14 像素）。被击败行的第 11 帧含右侧两块碎片。
BODY_ROWS = {
    'walk': (268, 394, [(10, 119), (133, 244), (258, 373), (387, 513), (527, 660), (674, 809), (823, 949), (963, 1088),
                        (1102, 1227), (1241, 1366), (1380, 1531), (1545, 1679), (1693, 1822), (1836, 1963), (1977, 2091),
                        (2105, 2215)]),
    'idle': (661, 787, [(10, 120), (134, 244), (258, 368), (382, 492), (506, 616), (630, 740), (754, 864), (878, 988)]),
    'open': (1051, 1176, [(10, 120), (134, 246), (260, 374), (388, 502), (516, 630), (644, 758)]),
    'fire': (1641, 1795, [(10, 124), (138, 252), (266, 380), (394, 508), (522, 636), (650, 764), (778, 892), (906, 1020),
                          (1034, 1148), (1162, 1278), (1292, 1410), (1424, 1542), (1556, 1674), (1688, 1804), (1818, 1932)]),
    'close': (2387, 2512, [(11, 125), (139, 253), (267, 381), (395, 509), (523, 635), (649, 759)]),
    'back': (2784, 2909, [(10, 120), (134, 244), (258, 367)]),
    'death': (3313, 3444, [(10, 142), (156, 297), (311, 468), (482, 650), (664, 838), (852, 1040), (1054, 1242),
                           (1266, 1472), (1475, 1694), (1708, 1914), (1928, 2191), (2205, 2373)]),
}
# 被击败的分层（2026-10-18 R5）：被击败区段除合成行外另有三行——身体（壳与靠近镜头一侧的腿）、另一侧的腿、
# 紫色液体与肉块（带底框，11 格，第 11 格只剩落在地上的肉块）。合成行 = 三者按 壳 < 液体与肉块 < 腿 的次序叠成。
# DEATH_LAYER_AT 为各层裁切（包围盒）在合成帧裁切中的左上角位置，以 anaconda 按“颜色相同的像素数”做二维互相关求得
# （腿的全部像素与合成帧相同；见 verification/giant_hunter_walker_20261017/death_layers/）。
# 合成行第 12 帧（残骸）与第 10 帧爆裂后的身体为同一姿势（残骸 6786 个像素全部出现在第 10 帧中），可直接接在爆裂之后。
DEATH_LAYER_ROWS = {
    'shell': (2949, 3065, [(10, 115), (129, 240), (254, 380), (394, 527), (541, 684), (698, 844), (858, 1008),
                           (1022, 1168), (1182, 1332), (1346, 1500)]),
    'legs': (3080, 3156, [(10, 131), (145, 275), (289, 438), (452, 611), (625, 788), (802, 969), (983, 1151),
                          (1165, 1333), (1347, 1515), (1529, 1697)]),
    'fx': (3171, 3298, [(10, 220), (224, 434), (438, 648), (652, 862), (866, 1076), (1080, 1290), (1294, 1504),
                        (1508, 1718), (1722, 1932), (1936, 2146), (2150, 2360)]),
}
DEATH_LAYER_AT = [   # 合成帧 0–9：{层: (dx, dy)}
    {'shell': (0, 0), 'legs': (11, 46), 'fx': (13, 36)},
    {'shell': (2, 0), 'legs': (11, 48), 'fx': (0, 35)},
    {'shell': (7, 0), 'legs': (8, 51), 'fx': (0, 23)},
    {'shell': (14, 0), 'legs': (9, 54), 'fx': (0, 11)},
    {'shell': (15, 0), 'legs': (10, 61), 'fx': (0, 9)},
    {'shell': (21, 3), 'legs': (15, 67), 'fx': (0, 0)},
    {'shell': (19, 7), 'legs': (14, 71), 'fx': (0, 0)},
    {'shell': (32, 11), 'legs': (25, 75), 'fx': (0, 0)},
    {'shell': (42, 14), 'legs': (37, 76), 'fx': (15, 0)},
    {'shell': (26, 16), 'legs': (23, 77), 'fx': (0, 0)},
]


def is_purple(p):
    """液体与肉块行中紫色液体的 5 种颜色色相 279–300（B > G）；肉块的 7 种颜色色相 0–50（B ≤ G）。"""
    return p[3] and p[2] > p[1]


# 效果行：(名称, y0, y1, 是否有底框)
EFFECT_ROWS = {
    'emerge': (1832, 1886, False),     # 卵从嘴里冒出（绿色光团）
    'descend': (1922, 1944, False),    # 卵下降（旋翼）
    'explode': (1981, 2014, True),     # 卵在空中爆炸
    'wing_a': (2025, 2039, True),      # 爆炸时飞出的两片翅膀
    'wing_b': (2050, 2064, True),
    'crash': (2101, 2124, True),       # 卵撞地坠毁
}


def load():
    return Image.open(SHEET).convert('RGBA')


def transparent(img):
    out = Image.new('RGBA', img.size, (0, 0, 0, 0))
    out.putdata([(0, 0, 0, 0) if p in BG else p for p in img.getdata()])
    return out


def mask(img):
    return img.getchannel('A').point(lambda a: 255 if a else 0)


def top_mask(img, rows):
    box = img.getbbox()
    return mask(img.crop((box[0], box[1], box[2], min(box[3], box[1] + rows)))), box


def foot_mask(img, rows):
    box = img.getbbox()
    return mask(img.crop((box[0], max(box[1], box[3] - rows), box[2], box[3]))), box


def shift_score(ref, cur, dx):
    """ref、cur 为同高的轮廓（L）；cur 右移 dx 后与 ref 不一致的像素数。"""
    w = max(ref.width, cur.width + abs(dx)) + 2 * SEARCH
    a = Image.new('L', (w, ref.height)); a.paste(ref, (SEARCH, 0))
    b = Image.new('L', (w, ref.height)); b.paste(cur, (SEARCH + dx, 0))
    return sum(ImageChops.difference(a, b).histogram()[255:])


def body_frames(sheet):
    frames, report = {}, {}
    raw = {name: [transparent(sheet.crop((x0, y0, x1, y1))) for x0, x1 in xs] for name, (y0, y1, xs) in BODY_ROWS.items()}
    ref_img = raw['idle'][0]
    ref_box = ref_img.getbbox()
    origin_x = (ref_box[0] + ref_box[2]) / 2          # 单位原点：待机第 1 帧包围盒中心（图内 x）
    def match(ref, cur, by_top):
        """cur 右移 dx 后与 ref 的同名部位重合；返回 (dx, 不一致像素数)。"""
        (a, _), (b, _) = ((top_mask(ref, TOP_ROWS), top_mask(cur, TOP_ROWS)) if by_top
                          else (foot_mask(ref, FOOT_ROWS), foot_mask(cur, FOOT_ROWS)))
        rows = min(a.height, b.height)
        a = a.crop((0, 0, a.width, rows)) if by_top else a.crop((0, a.height - rows, a.width, a.height))
        b = b.crop((0, 0, b.width, rows)) if by_top else b.crop((0, b.height - rows, b.width, b.height))
        best = min(range(-SEARCH, SEARCH + 1), key=lambda dx: (shift_score(a, b, dx), abs(dx)))
        return best, shift_score(a, b, best)

    ref_anchor = origin_x - ref_box[0]                 # 待机第 1 帧的锚点（裁切后图内 x）
    for name, imgs in raw.items():
        frames[name] = []
        prev, history = None, []
        for i, img in enumerate(imgs):
            box = img.getbbox()
            if name in CHAIN_BY_TOP and prev is not None:
                # 被击败：紫色爆裂与收拢的腿干扰脚部对齐，第 2 帧起按壳顶对准前一帧，逐帧累积；
                # 暗色剪影帧（第 11 帧）轮廓与前后帧差异过大，残骸帧（第 12 帧）改为对准第 10 帧
                ref = history[CHAIN_SKIP[(name, i)]] if (name, i) in CHAIN_SKIP else prev
                best, miss = match(ref[0], img, True)
                anchor = ref[1] - best
            else:
                best, miss = match(ref_img, img, name in ALIGN_BY_TOP)
                anchor = ref_anchor - best             # cur 中与参考帧原点对应的位置（裁切后图内 x）
            prev = (img, anchor)
            history.append(prev)
            crop = img.crop(box)
            path = OUT / f'{name}_{i:02d}.png'
            crop.save(path)
            ground = imgs[0].getbbox()[3] if name in SHEET_BASELINE else box[3]
            frames[name].append({'file': path.name, 'ax': round(anchor), 'ay': ground - box[1], 'size': list(crop.size)})
            report.setdefault(name, []).append({'dx': best, 'mismatch': miss})
    return frames, report


def split(img, keep):
    """img 中只保留 keep(p) 为真的像素；返回 (裁切后的图, 包围盒左上角) 或 None。"""
    out = Image.new('RGBA', img.size, (0, 0, 0, 0))
    out.putdata([p if keep(p) else (0, 0, 0, 0) for p in img.getdata()])
    box = out.getbbox()
    return (out.crop(box), box[:2]) if box else None


def death_layers(sheet, death):
    """被击败的三层：death_shell_k、death_legs_k（k = 0–9）、death_purple_k（0–9）、death_gore_k（0–10）。
    锚点由合成帧 k 的锚点与该层在合成帧中的位置换算；第 11 格的肉块按第 10 格（k = 9）的格子位置放置。
    同时以各层重新叠成合成帧，与素材表合成行逐像素比较（结果写入 cut_report.json）。"""
    frames = {'death_shell': [], 'death_legs': [], 'death_purple': [], 'death_gore': []}
    report = []
    comp_y0, comp_y1, comp_xs = BODY_ROWS['death']
    cells = []
    for name, (y0, y1, xs) in DEATH_LAYER_ROWS.items():
        cells.append([])
        for x0, x1 in xs:
            img = transparent(sheet.crop((x0, y0, x1, y1)))
            box = img.getbbox()
            cells[-1].append((img.crop(box), box[:2]))
    shells, legs, fxs = cells

    def save(kind, k, img, ax, ay):
        path = OUT / f'{kind}_{k:02d}.png'
        img.save(path)
        frames[kind].append({'file': path.name, 'ax': round(ax), 'ay': round(ay), 'size': list(img.size)})

    cell_world = None
    for k, at in enumerate(DEATH_LAYER_AT):
        comp = transparent(sheet.crop((comp_xs[k][0], comp_y0, comp_xs[k][1], comp_y1)))
        comp = comp.crop(comp.getbbox())
        ax, ay = death[k]['ax'], death[k]['ay']
        rebuilt = Image.new('RGBA', comp.size, (0, 0, 0, 0))
        dx, dy = at['shell']
        save('death_shell', k, shells[k][0], ax - dx, ay - dy)
        rebuilt.alpha_composite(shells[k][0], (dx, dy))
        dx, dy = at['fx']
        fx = fxs[k][0]
        for kind, keep in (('death_gore', lambda p: p[3] and not is_purple(p)), ('death_purple', is_purple)):
            part = split(fx, keep)
            if part is None:
                frames[kind].append(None)
                continue
            img, (bx, by) = part
            save(kind, k, img, ax - dx - bx, ay - dy - by)
            rebuilt.alpha_composite(img, (dx + bx, dy + by))
        cell_world = (dx - fxs[k][1][0] - ax, dy - fxs[k][1][1] - ay)   # 格子左上角相对单位原点
        dx, dy = at['legs']
        save('death_legs', k, legs[k][0], ax - dx, ay - dy)
        rebuilt.alpha_composite(legs[k][0], (dx, dy))
        diff = sum(1 for a, b in zip(rebuilt.getdata(), comp.getdata()) if a != b and (a[3] or b[3]))
        report.append({'frame': k, 'pixels': sum(1 for p in comp.getdata() if p[3]), 'differ': diff})
    fx, (bx, by) = fxs[10]
    assert split(fx, is_purple) is None
    img, (gx, gy) = split(fx, lambda p: p[3])
    save('death_gore', 10, img, -(cell_world[0] + bx + gx), -(cell_world[1] + by + gy))
    return frames, report


def effect_frames(sheet):
    frames = {}
    for name, (y0, y1, boxed) in EFFECT_ROWS.items():
        band = sheet.crop((0, y0, sheet.width, y1))
        px = band.load()
        if boxed:
            cols = [any(px[x, y] == BOX for y in range(band.height)) for x in range(band.width)]
        else:
            cols = [any(px[x, y] not in BG for y in range(band.height)) for x in range(band.width)]
        cells, x = [], 0
        while x < band.width:
            if cols[x]:
                s = x
                while x < band.width and (cols[x] or (not boxed and any(cols[x + 1:x + 4]))):
                    x += 1
                cells.append((s, x))
            x += 1
        frames[name] = []
        for i, (x0, x1) in enumerate(cells):
            cell = transparent(band.crop((x0, 0, x1, band.height)))
            box = cell.getbbox()
            if box is None:
                continue
            if boxed:
                # 底框格子：锚点为格子中心（爆炸、翅膀）或格子底边中点（坠地）
                ax, ay = (x1 - x0) / 2, (band.height if name == 'crash' else band.height / 2)
            else:
                ax, ay = (box[0] + box[2]) / 2, box[3]
            crop = cell.crop(box)
            path = OUT / f'{name}_{i:02d}.png'
            crop.save(path)
            frames[name].append({'file': path.name, 'ax': round(ax - box[0]), 'ay': round(ay - box[1]), 'size': list(crop.size)})
    return frames


def main():
    OUT.mkdir(exist_ok=True)
    sheet = load()
    body, report = body_frames(sheet)
    layers, report['death_layers'] = death_layers(sheet, body['death'])
    effects = effect_frames(sheet)
    data = {**body, **layers, **effects}
    (HERE / 'frames.json').write_text(json.dumps(data, indent=1), encoding='utf-8')
    (HERE / 'cut_report.json').write_text(json.dumps(report, indent=1), encoding='utf-8')
    print({k: len(v) for k, v in data.items()})


if __name__ == '__main__':
    main()
