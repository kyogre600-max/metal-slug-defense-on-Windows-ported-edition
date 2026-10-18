"""Hunter（《合金弹头6》）素材表切帧与对齐（2026-10-18）。

来源：source/MS6_Hunter.png（The Spriters Resource，The Mad Soldier 整理，1000×1503，背景 (86,177,222)）。
同一行各帧的脚底在同一基线上（各帧包围盒底边相同），纵向锚点取该行基线；横向锚点按轮廓对齐：
- 各动作第 1 帧以脚部（帧底 FOOT_ROWS 行的轮廓）对准待机第 1 帧；之后各帧按 ALIGN 的方式对准前一帧
  （foot：脚部轮廓；full：整帧轮廓；torso：上身一段轮廓）。待机第 1 帧的原点取脚部像素的平均横坐标。
- 分帧：多数行以连通区域分帧（像素数 ≥ MAJOR 的区域为一帧，零散的小区域归入横向最近的一帧，刀尖越过相邻帧的列时也能分开）；
  血花、火焰与炸药的行以列空隙分帧（宽度 ≤ THIN 的零散列段并入相邻帧）。
- 炸药飞行帧以描边色 (16,16,8) 像素的重心为锚点（旋转中心）；落地的炸药以该行基线为地面，横向以右缘对准第 1 帧（锚点为第 1 帧的描边重心）。
另从原版叛军步兵（UnitID 2）槽 16 取手榴弹爆炸 8 帧（source/grenade/，锚点为原生弹体原点），供炸药爆炸使用。
输出 frames/<动作>_<序号>.png 与 frames.json（每帧 file、ax、ay、size）。
运行：E:/anaconda3/python.exe -I cut_frames.py（需 numpy、scipy；手榴弹帧需 KT-21 研究工具读取 original.apk）。
"""
from pathlib import Path
import json
import sys
import numpy as np
from PIL import Image
from scipy import ndimage

HERE = Path(__file__).resolve().parent
SHEET = HERE / 'source' / 'MS6_Hunter.png'
OUT = HERE / 'frames'
GRENADE = HERE / 'source' / 'grenade'
BG = (86, 177, 222)
OUTLINE = (16, 16, 8)
MAJOR, THIN, FOOT_ROWS, TORSO, SEARCH = 60, 8, 6, (8, 26), 24

# 名称：(y0, y1, 分帧方式, 对齐方式, 取用的帧序号或 None)
ROWS = {
    'idle': (2, 41, 'comp', 'foot', None),
    'run': (98, 152, 'comp', 'torso', range(12)),
    'taunt': (233, 280, 'comp', 'foot', range(4)),
    'slash': (295, 349, 'comp', 'foot', None),
    'throw': (355, 411, 'comp', 'foot', None),
    'fall': (489, 532, 'comp', 'full', None),
    'recoil': (657, 700, 'comp', 'full', range(6)),
    'blood': (595, 647, 'gap', 'full', None),
    'burn': (714, 779, 'gap', 'full', None),
    'ash': (793, 858, 'gap', 'full', None),
}
DYNAMITE = {'fly': (1342, 1370), 'lie': (1378, 1397)}


def load():
    a = np.array(Image.open(SHEET).convert('RGBA'))
    fg = ~np.all(a[:, :, :3] == BG, axis=2)
    a[~fg] = 0
    return a, fg


def comp_frames(fg, y0, y1):
    lab, n = ndimage.label(fg[y0:y1], structure=np.ones((3, 3)))
    sizes = ndimage.sum(np.ones_like(lab), lab, range(1, n + 1))
    objs = ndimage.find_objects(lab)
    major = sorted((i + 1 for i in range(n) if sizes[i] >= MAJOR), key=lambda k: objs[k - 1][1].start)
    groups = {k: [k] for k in major}
    for i in range(n):
        k = i + 1
        if k in groups:
            continue
        cx = (objs[i][1].start + objs[i][1].stop) / 2
        best = min(major, key=lambda m: max(objs[m - 1][1].start - cx, cx - objs[m - 1][1].stop, 0))
        groups[best].append(k)
    return [np.isin(lab, groups[k]) for k in major]


def gap_frames(fg, y0, y1):
    cols = fg[y0:y1].any(axis=0)
    segs, x = [], 0
    while x < len(cols):
        if cols[x]:
            s = x
            while x < len(cols) and cols[x]:
                x += 1
            segs.append([s, x])
        x += 1
    merged = []
    for s in segs:
        if merged and s[0] - merged[-1][1] < 2:
            merged[-1][1] = s[1]
        else:
            merged.append(s)
    out = [m for m in merged if m[1] - m[0] > THIN]
    for m in merged:
        if m[1] - m[0] <= THIN:
            near = min(out, key=lambda o: min(abs(m[0] - o[1]), abs(o[0] - m[1])))
            near[0], near[1] = min(near[0], m[0]), max(near[1], m[1])
    masks = []
    for s, e in sorted(out):
        mk = np.zeros_like(fg[y0:y1])
        mk[:, s:e] = fg[y0:y1, s:e]
        masks.append(mk)
    return masks


def bbox(mask):
    ys, xs = np.nonzero(mask)
    return xs.min(), ys.min(), xs.max() + 1, ys.max() + 1


def best_shift(ref, cur):
    """ref、cur 为同高的布尔轮廓（各自的局部坐标）；返回 dx，使 cur 右移 dx 后与 ref 不一致的像素最少。"""
    h = ref.shape[0]
    w = max(ref.shape[1], cur.shape[1]) + 2 * SEARCH + 2
    a = np.zeros((h, w), bool)
    a[:, SEARCH:SEARCH + ref.shape[1]] = ref
    best = None
    for dx in range(-SEARCH, SEARCH + 1):
        b = np.zeros((h, w), bool)
        x = SEARCH + dx
        if x < 0 or x + cur.shape[1] > w:
            continue
        b[:, x:x + cur.shape[1]] = cur
        score = int((a ^ b).sum())
        if best is None or score < best[0]:
            best = (score, dx)
    return best[1]


def band(local, mode):
    h = local.shape[0]
    if mode == 'foot':
        return local[max(0, h - FOOT_ROWS):]
    if mode == 'torso':
        return local[TORSO[0]:TORSO[1]]
    return local


def align_pair(ref_local, ref_ax, cur_local, mode):
    """两帧底边对齐（同一基线）；返回 cur 的横向锚点（局部坐标）。"""
    h = max(ref_local.shape[0], cur_local.shape[0])

    def pad(m):
        return np.vstack([np.zeros((h - m.shape[0], m.shape[1]), bool), m]) if mode != 'torso' else m
    r, c = band(pad(ref_local), mode), band(pad(cur_local), mode)
    if mode == 'torso':      # 上身一段取各自的顶部起算
        n = min(r.shape[0], c.shape[0])
        r, c = r[:n], c[:n]
    return ref_ax - best_shift(r, c)


def save(img, name, i):
    path = OUT / f'{name}_{i:02d}.png'
    Image.fromarray(img).save(path)
    return path.name


def main():
    OUT.mkdir(exist_ok=True)
    for old in OUT.glob('*.png'):
        old.unlink()
    a, fg = load()
    data = {}
    idle_ref = None
    for name, (y0, y1, split, mode, pick) in ROWS.items():
        masks = comp_frames(fg, y0, y1) if split == 'comp' else gap_frames(fg, y0, y1)
        if pick is not None:
            masks = [masks[i] for i in pick]
        baseline = max(bbox(m)[3] for m in masks)        # 行基线（局部，开区间）
        frames, prev = [], None
        for i, m in enumerate(masks):
            x0, top, x1, bottom = bbox(m)
            local = m[top:bottom, x0:x1]
            img = np.zeros((bottom - top, x1 - x0, 4), np.uint8)
            region = a[y0 + top:y0 + bottom, x0:x1]
            img[local] = region[local]
            ay = baseline - top
            if idle_ref is None:
                foot = local[-FOOT_ROWS:]
                ax = int(round(np.nonzero(foot)[1].mean()))
                idle_ref = (local, ax)
            elif prev is None:
                ax = align_pair(idle_ref[0], idle_ref[1], local, 'foot')
            else:
                ax = align_pair(prev[0], prev[1], local, mode)
            prev = (local, ax)
            frames.append({'file': save(img, name, i), 'ax': int(ax), 'ay': int(ay), 'size': [int(x1 - x0), int(bottom - top)]})
        data[name] = frames
    # 炸药
    for name, (y0, y1) in DYNAMITE.items():
        masks = gap_frames(fg, y0, y1) if name == 'fly' else comp_frames(fg, y0, y1)
        baseline = max(bbox(m)[3] for m in masks)
        frames, prev = [], None
        for i, m in enumerate(masks):
            x0, top, x1, bottom = bbox(m)
            local = m[top:bottom, x0:x1]
            img = np.zeros((bottom - top, x1 - x0, 4), np.uint8)
            region = a[y0 + top:y0 + bottom, x0:x1]
            img[local] = region[local]
            outline = np.all(region[:, :, :3] == OUTLINE, axis=2) & local
            ys, xs = np.nonzero(outline)
            if name == 'fly':
                ax, ay = int(round(xs.mean())), int(round(ys.mean()))
            else:
                # 落地的炸药不动：引信火花在左上端，最后几帧整根变白、变黑闪烁（无描边色），以右下端（包围盒右缘）对齐第 1 帧
                ay = baseline - top
                if prev is None:
                    ax = int(round(xs.mean()))
                    prev = (x1 - x0) - ax
                else:
                    ax = (x1 - x0) - prev
            frames.append({'file': save(img, 'dyn_' + name, i), 'ax': int(ax), 'ay': int(ay), 'size': [int(x1 - x0), int(bottom - top)]})
        data['dyn_' + name] = frames
    data['grenade'] = grenade_frames()
    (HERE / 'frames.json').write_text(json.dumps(data, ensure_ascii=False, indent=1), encoding='utf-8')
    print({k: len(v) for k, v in data.items()})


def grenade_frames():
    """原版叛军步兵（UnitID 2）槽 16 的手榴弹爆炸 8 帧：首次运行时从 original.apk 与原版图集合成到 source/grenade/，
    之后只读该目录。锚点为原生弹体原点在图像中的位置。"""
    index = GRENADE / 'grenade.json'
    if not index.exists():
        GRENADE.mkdir(parents=True, exist_ok=True)
        sys.path.insert(0, str(HERE.parents[1] / 'verification' / 'hunter_prep_20261018'))
        import common
        frames = []
        for i, off in enumerate(common.script_frames(2, 16)):
            d, names, rects, fr = common.unit(2)
            tiles = []
            for ri in common.frame_rects(2, off):
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
            im.save(GRENADE / f'grenade_{i:02d}.png')
            frames.append({'file': f'grenade_{i:02d}.png', 'ax': -min(xs), 'ay': -min(ys), 'size': list(im.size), 'native_frame': off})
        index.write_text(json.dumps(frames, indent=1), encoding='utf-8')
    out = []
    for f in json.loads(index.read_text(encoding='utf-8')):
        img = np.array(Image.open(GRENADE / f['file']).convert('RGBA'))
        out.append({'file': save(img, 'grenade', len(out)), 'ax': f['ax'], 'ay': f['ay'], 'size': f['size']})
    return out


if __name__ == '__main__':
    main()
