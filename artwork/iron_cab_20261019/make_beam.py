"""IRON CAB 激光光束（R7，2026-10-19，用户要求）：MSA 素材的光束只是一根平直的色带，从光球中心盖在激光炮帧的光球上，
光球上下露出的部分与光束的边缘形成台阶，颜色也与光球的环不连续。本模块为发射时的炮帧画出与光球相接的光束：

1. 炮帧 4、5 的光球是同心环（帧 4：外圈青蓝 4 级 → 浅青 → 白芯，半径 16；帧 5：亮青 → 浅青 → 白 → 浅青芯，半径 12），
   中心与半径由最外环颜色的范围求出。光束的色带取同一光球中心列的环（外 → 内），按光束半高压缩，每一环至少 1 像素。
2. 光球保留原像素；光球左侧原有的锥形喷口（圆外的发光像素）去掉。光束自光球中心向左，与光球重叠处每个像素取较深的环
   （按环的位置，而不是亮度），光束的环因此穿过光球的外圈并入光球；光束与光球外缘之间按平滑并集补出圆角（最外环颜色）。
3. 合成后的炮帧（含光球与光束开头一段，到光球左缘再左 8 像素为止）与光束的直段（64 像素宽，可平铺）分别输出到
   derived/beam/，锚点与炮帧相同（吊杆顶端）。帧 6（发射结束，炮口只剩一条细线）的细光束用帧 6 线条的颜色。

颜色全部取自 MSA 素材表（光球与线条原有的颜色），不缩放、不新增颜色。
"""
from pathlib import Path
import json
import math

from PIL import Image

HERE = Path(__file__).resolve().parent
OUT = HERE / 'derived' / 'beam'
FILLET = 4.0                    # 光束与光球之间圆角的平滑并集参数（像素）
SPLIT = 8                       # 合成炮帧在光球左缘以左再保留的像素（其后为可平铺的直段）
RING = {4: (33, 165, 189), 5: (74, 255, 255)}      # 求光球中心与半径用的最外环颜色
THIN = {2: [(0, 206, 247), (0, 255, 255), (206, 255, 255)],   # 帧 6 用的细光束（半高 → 上半色带，外 → 中）
        1: [(0, 255, 255), (206, 255, 255)],
        0: [(206, 255, 255)]}


def glow(p):
    """发光像素：青蓝色（蓝明显高于红）或近白色（与 fix_cannon.glow 相同）。"""
    r, g, b = p[:3]
    return p[3] > 0 and (b >= r + 40 or (r >= 230 and g >= 230 and b >= 230))


def orb(img, ax, k):
    """光球中心 (cx, cy)（相对吊杆）与半径 R：最外环颜色像素的外接范围。"""
    pts = [(x - ax, y) for y in range(img.height) for x in range(img.width)
           if img.getpixel((x, y))[3] and img.getpixel((x, y))[:3] == RING[k]]
    xs = [p[0] for p in pts]
    ys = [p[1] for p in pts]
    assert max(xs) - min(xs) == max(ys) - min(ys), (k, xs, ys)
    return (min(xs) + max(xs)) // 2, (min(ys) + max(ys)) // 2, (max(ys) - min(ys)) // 2


def runs_of(img, ax, ay, cx, cy, R):
    """光球中心列上半（外 → 中）的环：[(颜色, 像素数)]。"""
    out = []
    for y in range(cy - R, cy + 1):
        c = img.getpixel((cx + ax, y - ay))[:3]
        if out and out[-1][0] == c:
            out[-1][1] += 1
        else:
            out.append([c, 1])
    return out


def allocate(runs, n):
    """把环按比例压缩到 n 像素（每环至少 1 像素；n 小于环数时去掉外环），返回各像素的环序号（外 → 中）。"""
    if n < len(runs):
        return list(range(len(runs) - n, len(runs)))
    total = sum(c for _, c in runs)
    raw = [c * n / total for _, c in runs]
    cnt = [max(1, int(r)) for r in raw]
    while sum(cnt) > n:
        i = max(range(len(cnt)), key=lambda j: (cnt[j] - raw[j], cnt[j]))
        cnt[i] -= 1
    while sum(cnt) < n:
        i = max(range(len(cnt)), key=lambda j: raw[j] - cnt[j])
        cnt[i] += 1
    out = []
    for i, m in enumerate(cnt):
        out += [i] * m
    return out


def smax(a, b, k):
    h = max(k - abs(a - b), 0) / k
    return max(a, b) + h * h * k / 4


def merged(frame, k, hb):
    """炮帧 k（derived/cannon 的修正帧，dict：file、ax、ay）加半高 hb 的光束开头。返回 (图, ax, ay, 直段左起 x)。"""
    src = Image.open(HERE / 'derived' / 'cannon' / frame['file']).convert('RGBA')
    ax, ay = frame['ax'], frame['ay']
    cx, cy, R = orb(src, ax, k)
    runs = runs_of(src, ax, ay, cx, cy, R)
    colors = [c for c, _ in runs]
    lv_o = []
    for i, (_, n) in enumerate(runs):
        lv_o += [i] * n                                 # 径向深度 0..R → 环序号
    lv_b = allocate(runs, hb + 1)                       # 光束上半：自外缘起的像素 → 环序号
    split = cx - R - SPLIT                              # 合成帧保留 x ≥ split（相对吊杆）
    ext = max(0, -(split + ax))                         # 画布向左扩到 split
    img = Image.new('RGBA', (src.width + ext, src.height), (0, 0, 0, 0))
    img.alpha_composite(src, (ext, 0))
    ax2 = ax + ext
    px = img.load()
    for y in range(img.height):
        uy = y - ay
        dy = abs(uy - cy)
        for x in range(img.width):
            ux = x - ax2
            if ux > cx:
                continue
            if ux < split:
                if px[x, y][3] and glow(px[x, y]):
                    px[x, y] = (0, 0, 0, 0)            # 直段由平铺图块画出
                continue
            do = R + 0.5 - math.hypot(ux - cx, uy - cy)
            db = hb + 0.5 - dy
            p = px[x, y]
            orig = p[3] > 0 and glow(p)
            if orig and do < 0:                         # 光球圆外原有的锥形喷口
                px[x, y] = (0, 0, 0, 0)
                orig = False
            if smax(do, db, FILLET) <= 0:
                continue
            lo = lv_o[min(int(do), R)] if do > 0 else -1
            lb = lv_b[min(int(db), hb)] if db > 0 else -1
            if lo < 0 and lb < 0:
                lb = 0                                  # 圆角：最外环
            if lb > lo:
                px[x, y] = colors[lb] + (255,)
            elif lo >= 0 and not orig and not (p[3] and not glow(p)):
                px[x, y] = colors[lo] + (255,)          # 原光球此处无像素（只在边缘出现）时按径向补齐
    bbox = img.getbbox()
    img = img.crop((bbox[0], 0, img.width, img.height))
    return img, ax2 - bbox[0], ay, split, [colors[i] for i in lv_b]


def body(top, name):
    """可平铺的直段：上半色带 top（外 → 中）镜像成整列，64 像素宽；锚点在右缘、中线。"""
    col = top + top[-2::-1]
    img = Image.new('RGBA', (64, len(col)), (0, 0, 0, 0))
    for x in range(64):
        for j, c in enumerate(col):
            img.putpixel((x, j), tuple(c) + (255,))
    img.save(OUT / name)
    return {'file': name, 'ax': 64, 'ay': len(col) // 2}


def build(cannon_frames, states):
    """states：[(炮帧序号, 光束半高)]，炮帧 4、5 带光球；返回 {(k, hb): {'frame': …, 'body': …, 'split': x}}，
    以及帧 6 的细光束 {('thin', hb): {'body': …}}。"""
    OUT.mkdir(parents=True, exist_ok=True)
    result, record = {}, {}
    for k, hb in states:
        img, ax, ay, split, top = merged(cannon_frames[k], k, hb)
        name = f'cannon{k:02d}_beam{2 * hb + 1}.png'
        img.save(OUT / name)
        frame = {'file': name, 'ax': ax, 'ay': ay}
        result[(k, hb)] = {'frame': frame, 'body': body(top, f'body{k:02d}_{2 * hb + 1}.png'), 'split': split}
        record[f'{k}_{hb}'] = {**result[(k, hb)], 'source': f'derived/cannon/{cannon_frames[k]["file"]}'}
    for hb, top in THIN.items():
        result[('thin', hb)] = {'body': body(top, f'body_thin_{2 * hb + 1}.png')}
        record[f'thin_{hb}'] = result[('thin', hb)]
    (OUT / 'beam.json').write_text(json.dumps({'note': __doc__.strip().splitlines()[0], 'states': record},
                                              ensure_ascii=False, indent=2), encoding='utf-8')
    return result
