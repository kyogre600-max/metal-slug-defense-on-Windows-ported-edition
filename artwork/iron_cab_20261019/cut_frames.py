"""IRON CAB（MSA）素材表切帧与对齐（2026-10-19）。

来源：source/MSA_Iron_Cab.png（《Metal Slug Attack》单位 IRON CAB，Midian-P 提取、Patchworks 整理，1976×966）。
素材表每帧由洋红边框围成格子，格内为透明底；本脚本按格子切出内容，并计算锚点。用户决定按 MSA 素材原尺寸 1:1 使用。
素材朝左（激光炮口与前进方向为 −x），与基准僵尸（青年）相同，不翻转。

单位原点：行走各帧的车体中心（车体格 BODY——素材表第 1 格，x=4——在组装帧中按颜色逐像素比对定位，宽 127，中心 63）与地面（组装帧底边，
素材表中 8 帧底边同为第 372 行）。组装行走帧由“左侧一对腿（在车体之后）→ 车体 → 右侧一对腿（在最上层）”叠成：
右侧腿帧（高 129 的一组）在组装帧中逐像素完全一致，可单独重画在激光炮之上。
- 发射管：发射管静止帧在行走第 1 帧中按颜色定位；6 个闪光帧按透明度轮廓与静止帧对准。
- 激光炮：炮管各帧按颜色与静止帧对准（锚点为炮管静止帧中的吊杆顶端）；光球各帧以内容中心为锚点，放在蓄力满时
  （炮管 + 大光球帧）光球的中心；光束各帧以格子中线为锚点（右端对齐光球中心向左排开）。
- 原版爆炸：导弹爆炸取共用效果 402 动画 2（28 帧，吉利塔炮弹命中），损毁大爆炸取动画 4（28 帧，基寇卡损毁），
  碎片取动画 11、12（各 8 帧），锚点为原生效果原点。

运行（需要 numpy 与 scipy）：E:\\anaconda3\\python.exe -I artwork/iron_cab_20261019/cut_frames.py
输出 frames/<名称>_<序号>.png（透明底，裁到内容）与 frames.json（每帧锚点 ax、ay：原点在图内的位置）。
"""
from pathlib import Path
import json
import sys

import numpy as np
from PIL import Image
from scipy import ndimage

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[1]
SHEET = HERE / 'source' / 'MSA_Iron_Cab.png'
OUT = HERE / 'frames'
NATIVE = HERE / 'source' / 'native'
GROUND = 372                 # 组装行走帧的底边（素材表行号，不含）
BODY_W = 127                 # 车体格（素材表第 1 格 BODY）内容宽，中心 63


def cells(img):
    """洋红边框围成的格子：[(格左, 格上, 内容图)]，按格上、格左排序。"""
    a = np.array(img)
    mag = (a[:, :, 0] == 255) & (a[:, :, 1] == 0) & (a[:, :, 2] == 255)
    lab, _ = ndimage.label(~mag)
    out = []
    for i, s in enumerate(ndimage.find_objects(lab)):
        y0, y1, x0, x1 = s[0].start, s[0].stop, s[1].start, s[1].stop
        if y0 == 0 or x0 == 0 or y1 == a.shape[0] or x1 == a.shape[1]:
            continue                      # 素材表外的绿底
        sub = a[s].copy()
        inside = lab[s] == i + 1
        green = (sub[:, :, 0] == 0) & (sub[:, :, 1] == 255) & (sub[:, :, 2] == 0)
        keep = inside & (sub[:, :, 3] > 0) & ~green
        if not keep.any():
            continue
        sub[~keep] = 0
        ys, xs = np.nonzero(keep)
        box = (xs.min(), ys.min(), xs.max() + 1, ys.max() + 1)
        out.append((x0, y0, box, Image.fromarray(sub).crop(box)))
    return sorted(out, key=lambda c: (c[1], c[0]))


def colors(img):
    a = np.array(img).astype(np.int64)
    key = (a[:, :, 0] << 16) | (a[:, :, 1] << 8) | a[:, :, 2]
    return np.where(a[:, :, 3] > 0, key, -1)


def match(big, small, xs, ys):
    """small 放在 big 的 (dx, dy) 处时颜色相同的像素数最多的位置。"""
    B, S = colors(big), colors(small)
    h, w = S.shape
    pad = np.full((B.shape[0] + 2 * h, B.shape[1] + 2 * w), -2, np.int64)
    pad[h:h + B.shape[0], w:w + B.shape[1]] = B
    m = S >= 0
    best = None
    for dy in ys:
        for dx in xs:
            reg = pad[dy + h:dy + 2 * h, dx + w:dx + 2 * w]
            score = int(((reg == S) & m).sum())
            if best is None or score > best[0]:
                best = (score, dx, dy)
    return best[1], best[2], best[0] / int(m.sum())


def mask_match(ref, cur, xs, ys):
    """透明度轮廓对准：cur 放在 ref 的 (dx, dy) 处时轮廓不一致的像素最少。"""
    A = np.array(ref)[:, :, 3] > 0
    C = np.array(cur)[:, :, 3] > 0
    H, W = max(A.shape[0], C.shape[0]) + 80, max(A.shape[1], C.shape[1]) + 80
    best = None
    for dy in ys:
        for dx in xs:
            a = np.zeros((H, W), bool); a[40:40 + A.shape[0], 40:40 + A.shape[1]] = A
            c = np.zeros((H, W), bool); c[40 + dy:40 + dy + C.shape[0], 40 + dx:40 + dx + C.shape[1]] = C
            diff = int((a ^ c).sum())
            if best is None or diff < best[0]:
                best = (diff, dx, dy)
    return best[1], best[2]


def native_frames(uid, slot):
    """原生描述符的动画帧（合成到透明底），锚点为原生原点在图内的位置。"""
    sys.path.insert(0, str(REPO / 'verification' / 'hunter_prep_20261018'))
    import common
    out = []
    for off in common.script_frames(uid, slot):
        d, names, rects, fr = common.unit(uid)
        tiles = []
        for ri in common.frame_rects(uid, off):
            x, y, w, h, ax, ay, flags, pg = rects[ri]
            t = common.atlas(names[pg]).crop((x, y, x + w, y + h))
            if flags & 1:
                t = t.transpose(Image.FLIP_LEFT_RIGHT)
            tiles.append((t, ax, ay))
        xs = [-ax for t, ax, ay in tiles] + [-ax + t.width for t, ax, ay in tiles]
        ys = [-ay for t, ax, ay in tiles] + [-ay + t.height for t, ax, ay in tiles]
        im = Image.new('RGBA', (max(xs) - min(xs), max(ys) - min(ys)))
        for t, ax, ay in tiles:
            im.alpha_composite(t, (-ax - min(xs), -ay - min(ys)))
        out.append((im, -min(xs), -min(ys)))
    return out


def main():
    OUT.mkdir(exist_ok=True)
    for old in OUT.glob('*.png'):
        old.unlink()
    sheet = Image.open(SHEET).convert('RGBA')
    allc = cells(sheet)
    by = {(x0, y0): (box, img) for x0, y0, box, img in allc}
    row = lambda y, lo=0, hi=10 ** 6: [(x0, by[(x0, y0)]) for x0, y0, box, img in allc if y0 == y and lo <= x0 <= hi]
    data, meta = {}, {}

    def save(name, img, ax, ay, extra=None):
        data.setdefault(name, [])
        k = len(data[name])
        f = f'{name}_{k:02d}.png'
        img.save(OUT / f)
        entry = {'file': f, 'ax': int(ax), 'ay': int(ay), 'size': list(img.size)}
        entry.update(extra or {})
        data[name].append(entry)
        return entry

    body = by[(4, 36)][1]            # 第 1 格 BODY（完好车体）；第 2 格 (142, 26) 为 DESTROYED（损毁车体）
    walk = row(164)
    legs = row(16)
    assert len(walk) == 8 and len(legs) == 8
    origins = []
    for i, (x0, (box, img)) in enumerate(walk):
        bx, by_, score = match(img, body, range(-5, 50), range(-3, 6))
        top = 164 + box[1]                                 # 内容顶边（素材表行号）
        assert top + img.height == GROUND or top + img.height == GROUND - 1, (i, top + img.height)
        ax, ay = bx + BODY_W // 2, GROUND - top
        origins.append((ax, ay))
        save('walk', img, ax, ay, {'body': [int(bx), int(by_)], 'body_match': round(score, 3)})
        lx, ly, lscore = match(img, legs[i][1][1], range(40, 100), range(70, 90))
        assert lscore == 1.0, (i, lscore)
        save('legs', legs[i][1][1], ax - lx, ay - ly, {'match': lscore})

    # 发射管：静止帧在行走第 1 帧中定位；闪光帧按轮廓与静止帧对准（锚点为单位原点在图内的位置，以行走第 1 帧为准）
    w0img, (w0x, w0y) = walk[0][1][1], origins[0]
    idle_box, launcher = by[(4, 411)]
    lx, ly, lscore = match(w0img, launcher, range(0, 120), range(0, 60))
    meta['launcher_match'] = round(lscore, 3)
    save('launcher', launcher, w0x - lx, w0y - ly, {'match': round(lscore, 3)})
    # 闪光帧的格子比静止帧大（含发射管下方的车体）：颜色未变的帧直接在行走第 1 帧中定位，
    # 变亮的帧按轮廓与最近一个已定位的帧对准
    flashes = [img for x0, (box, img) in row(392)]
    placed = {}
    for k, img in enumerate(flashes):
        fx, fy, fscore = match(w0img, img, range(0, 120), range(0, 60))
        if fscore > 0.6:
            placed[k] = (fx, fy)
    for k, img in enumerate(flashes):
        if k not in placed:
            ref = min(placed, key=lambda j: abs(j - k))
            dx, dy = mask_match(flashes[ref], img, range(-8, 9), range(-8, 9))
            placed[k] = (placed[ref][0] + dx, placed[ref][1] + dy)
        save('launcher', img, w0x - placed[k][0], w0y - placed[k][1])
    meta['launcher_flash_color_matched'] = sorted(k for k in placed)

    # 导弹：竖直（头朝下，下落）两帧与水平（头朝左）两帧；锚点为弹头尖端
    for x0 in (492, 519):
        box, img = by[(x0, 401)]
        save('missile_down', img, img.width // 2, img.height)
        save('missile_up', img.transpose(Image.FLIP_TOP_BOTTOM), img.width // 2, 0)
    for x0 in (548, 611):
        box, img = by[(x0, 428)]
        save('missile_side', img, 0, img.height // 2)
    for x0, (box, img) in row(420):
        save('smoke', img, img.width // 2, img.height // 2)

    # 激光炮：静止帧锚点为吊杆顶端（吊杆为第 0 行的不透明像素）
    cannon_box, cannon = by[(4, 479)]
    top_row = np.nonzero(np.array(cannon)[0, :, 3] > 0)[0]
    pole = (int(top_row.min() + top_row.max()) // 2, 0)
    left_col = np.nonzero(np.array(cannon)[:, :, 3].max(axis=0) > 0)[0].min()
    rows_at_left = np.nonzero(np.array(cannon)[:, left_col, 3] > 0)[0]
    muzzle = (int(left_col), int(rows_at_left.mean()))
    meta['cannon_pole'], meta['cannon_muzzle'] = pole, muzzle
    save('cannon', cannon, pole[0], pole[1])
    cannon_frames = [('charge', (77, 471)), ('full', (936, 471)), ('full', (1033, 471))]
    cannon_frames += [('fire', (x0, 474)) for x0, _ in row(474)]
    orb_center = None
    for name, key in cannon_frames:
        box, img = by[key]
        dx, dy, score = match(img, cannon, range(-10, 60), range(-12, 14))
        # img 中炮管静止帧位于 (dx, dy)：吊杆顶端在 img 中为 (dx + pole_x, dy)
        e = save('cannon', img, dx + pole[0], dy + pole[1], {'part': name, 'match': round(score, 3)})
        if key == (1033, 471):
            a = np.array(img).astype(int)
            cyan = (a[:, :, 3] > 0) & (a[:, :, 2] > a[:, :, 0] + 60) & (a[:, :, 1] > a[:, :, 0] + 30)
            ys, xs = np.nonzero(cyan)
            orb_center = (float(xs.mean()) - e['ax'], float(ys.mean()) - e['ay'])   # 相对吊杆顶端
    meta['orb_center'] = [round(v, 1) for v in orb_center]
    for x0, (box, img) in row(471, 150, 900):
        save('orb', img, img.width // 2, img.height // 2)
    for x0, (box, img) in row(471, 1130, 1300):
        save('orb_big', img, img.width // 2, img.height // 2)

    # 光束：格子中线为锚点纵坐标，右端为锚点横坐标（向左排开）
    for x0, (box, img) in row(565):
        save('beam', img, img.width, 582 - (565 + box[1]))
    for x0, (box, img) in row(562):
        save('beam_spark', img, img.width, 580 - (562 + box[1]))

    # 损毁车体（素材表第 2 格 DESTROYED）：底边中点
    dbox, destroyed = by[(142, 26)]
    save('destroyed', destroyed, destroyed.width // 2, destroyed.height)
    # 头像：MSA 出兵栏头像（44×48 格，内容 42×46）1:1 裁 40×40（含顶部两盏灯）
    ibox, icon = by[(1369, 325)]
    save('icon', icon.crop((1, 2, 41, 42)), 0, 0)

    # 原版爆炸的前两帧为单色暗褐圆盘 (32,24,0)；原版单位（如基寇卡炮弹命中）在本移植版中同样画成暗色圆盘，保持原样
    for name, (uid, slot) in {'boom': (402, 2), 'blast': (402, 4), 'debris_a': (402, 11), 'debris_b': (402, 12)}.items():
        for img, ax, ay in native_frames(uid, slot):
            save(name, img, ax, ay, {'native': [uid, slot]})

    data['meta'] = meta
    (HERE / 'frames.json').write_text(json.dumps(data, ensure_ascii=False, indent=1), encoding='utf-8')
    print({k: len(v) for k, v in data.items() if k != 'meta'}, meta)


if __name__ == '__main__':
    main()
