"""IRON SENTINEL 的部件定位、水平化与单位坐标（2026-10-20）。

坐标：
- G：第一形态整车帧 ff_walk_00 的内容外框坐标（素材斜置，朝右）。各整车帧与部件在 G 中的位置由 locate.py 按颜色逐像素比对求出，
  或按同组格子的对齐方式（MSA 素材表同一组帧的格子按某个角对齐）换算。
- R：G 经 rotsprite 旋转 atan(1/2) 后的水平坐标。
- U：单位坐标（精灵像素，原点为车体中心与地面，朝左，前方为 −x），由 R 平移并左右翻转得到；与基准僵尸（青年）的素材朝向相同。

本体部件（车体、主炮、舱口、侧炮、发射臂、巨型导弹、残骸）在 G 中定位后逐层旋转；弹体与效果（火箭、导弹、炮弹、火柱、烟雾）
按世界方向绘制，不旋转，只翻转。
"""
from pathlib import Path
import hashlib
import json
import math

import numpy as np
from PIL import Image

import locate as L
import rotsprite

HERE = Path(__file__).resolve().parent
FRAMES = HERE / 'frames'
DERIVED = HERE / 'derived'
D = L.DATA

DROP = 18                       # 履带底边在原点以下的像素（同 IRON CAB 的做法，素材脚底略低于行走线）；
                                # 初版 6，用户 2026-10-20 看实机截图认为悬空，要求再向下 12 像素


def img(group, k):
    return np.asarray(Image.open(FRAMES / D[group][k]['file']).convert('RGBA'))


def cell_corner(group, k, mode):
    """格子的某个角相对内容外框左上角的偏移（mode：lt / rt / lb / rb）。"""
    cx, cy, cw, ch = D[group][k]['cell']
    bx, by = D[group][k]['box'][:2]
    x = cx if mode[0] == 'l' else cx + cw
    y = cy if mode[1] == 't' else cy + ch
    return x - bx, y - by


_FOUND = {}


def find(target, ti, group, k):
    key = (target, ti, group, k)
    if key not in _FOUND:
        _FOUND[key] = L.find(L.load(target, ti), L.load(group, k))
    return _FOUND[key]


def g_full(group, k):
    """整车帧（与 ff_walk_00 同一画面）的内容外框在 G 中的位置。"""
    dx, dy, r = find('ff_walk', 0, group, k)
    assert r > 0.5, (group, k, r)
    return dx, dy


# ---------------------------------------------------------------- 部件在 G 中的位置
# 舱口：6 个舱口位置为闭合舱门 hatch_small 0 在 ff_walk_00 中的位置；舱口三组帧（hatch_small、hatch、hatch_rocket）的格子按右下角对齐
# （组装参考 guide_open 中 hatch 与 hatch_rocket 的位置核对）。按 x 由后到前排列。
HATCH_REG = 'rb'


def hatch_slots():
    T = L.load('ff_walk', 0).copy()
    P = L.load('hatch_small', 0)
    out = []
    for _ in range(6):
        dx, dy, r = L.find(T, P)
        assert r > 0.99, r
        out.append((dx, dy))
        h, w = P.shape
        T[dy:dy + h, dx:dx + w] = -3
    out.sort()
    ox, oy = cell_corner('hatch_small', 0, HATCH_REG)
    return [(x + ox, y + oy) for x, y in out]          # 各舱口格子右下角（G）


def hatch_pos(slot_corner, group, k):
    ox, oy = cell_corner(group, k, HATCH_REG)
    return slot_corner[0] - ox, slot_corner[1] - oy


def cannon_pos(group, k):
    """主炮：待机帧在 ff_walk_00 中定位；射击后坐帧按与待机第 0 帧的比对（炮座不动）定位。"""
    x0, y0, r = find('ff_walk', 0, 'cannon_idle', 0)
    assert r > 0.99
    if group == 'cannon_idle' and k == 0:
        return x0, y0
    dx, dy, r = find('cannon_idle', 0, group, k)
    return x0 + dx, y0 + dy


# 巨型导弹：MS6 素材表 REFERENCES 第 2 幅（发射中的第二形态）中，导弹（missile_turn 18）与第二形态整车帧（sf_walk_c 0）的相对位置
# 由颜色比对求出（MS6 颜色按 5 位分量换算为 MSA 的取值后一致）：导弹外框左上角在整车帧外框的 (198, −44)。
# missile_turn 各帧的格子按左下角对齐（导弹绕尾部转动，叠合后尾部重合）。
MISSILE_ON_ARM = (198, -44)
MISSILE_REG = 'lb'


def missile_pos(k):
    cx, cy = g_full('sf_walk_c', 0)
    bx, by = cx + MISSILE_ON_ARM[0], cy + MISSILE_ON_ARM[1]
    ox, oy = cell_corner('missile_turn', 18, MISSILE_REG)
    corner = bx + ox, by + oy
    ox, oy = cell_corner('missile_turn', k, MISSILE_REG)
    return corner[0] - ox, corner[1] - oy


# 残骸：destroyed 0 / 2 与第二形态整车帧前端（车头标志一带）比对，外框左上角在 sf_walk_a 0 外框的 (79, −28) / (3, −28)。
WRECK_OFFSET = {0: (79, -28), 2: (3, -28)}


def wreck_pos(k):
    ax, ay = g_full('sf_walk_a', 0)
    return ax + WRECK_OFFSET[k][0], ay + WRECK_OFFSET[k][1]


# ---------------------------------------------------------------- 旋转、原点与单位坐标
ROT = DERIVED / 'rot'
FX = DERIVED / 'fx'
_ROT_CACHE = {}


def rotated(group, k, gx, gy):
    """部件旋转到 R：返回 (图块数组, X, Y)。"""
    key = (group, k, gx, gy)
    if key not in _ROT_CACHE:
        _ROT_CACHE[key] = rotsprite.rotate(img(group, k), gx, gy)
    return _ROT_CACHE[key]


_ORIGIN = []


def origin():
    """R 中的单位原点 (OX, OY)：第一形态车体帧 ff_bare 0 旋转后，履带着地处（多数履带列的最低像素所在行）以上 DROP 行，
    横向为履带前后两端的中点。"""
    if not _ORIGIN:
        tile, X, Y = rotated('ff_bare', 0, *g_full('ff_bare', 0))
        a = tile[..., 3] > 0
        bottoms = np.array([np.nonzero(a[:, c])[0].max() if a[:, c].any() else -1 for c in range(a.shape[1])])
        ground = int(np.percentile(bottoms[bottoms >= 0], 90))
        cols = np.nonzero(bottoms >= ground - 3)[0]
        _ORIGIN.extend([X + (cols.min() + cols.max() + 1) / 2, Y + ground + 1 - DROP])
        _ORIGIN[0] = round(_ORIGIN[0])
    return _ORIGIN


def save_tile(arr, folder):
    folder.mkdir(parents=True, exist_ok=True)
    digest = hashlib.blake2b(arr.tobytes() + str(arr.shape).encode(), digest_size=10).hexdigest()
    path = folder / f'{digest}.png'
    if not path.exists():
        Image.fromarray(arr).save(path)
    return path


def body_array(name, arr, gx, gy):
    """自定义图层（G 中的数组，左上角在 (gx, gy)，可为小数）旋转、翻转后的部件元组；name 只用于缓存。"""
    key = ('array', name, gx, gy)
    if key not in _ROT_CACHE:
        _ROT_CACHE[key] = rotsprite.rotate(arr, gx, gy)
    return _part(_ROT_CACHE[key])


def body(group, k, gx, gy):
    """本体部件：旋转、翻转后作为 Sheet 的部件元组 (路径, 锚点 x, 锚点 y, dx, dy)（锚点为图块左上角）。"""
    return _part(rotated(group, k, gx, gy))


def _part(res):
    tile, X, Y = res
    OX, OY = origin()
    flipped = np.ascontiguousarray(tile[:, ::-1])
    path = save_tile(flipped, ROT)
    left = OX - (X + tile.shape[1])
    top = Y - OY
    return (path, 0, 0, int(left), int(top))


def to_u(xr, yr):
    OX, OY = origin()
    return OX - xr, yr - OY


def g_to_u(gx, gy):
    return to_u(*rotsprite.forward(gx, gy))


def part_bbox_u(group, k, gx, gy):
    """部件旋转后在 U 中的外框 (left, top, right, bottom)。"""
    path, _, _, left, top = body(group, k, gx, gy)
    w, h = Image.open(path).size
    return left, top, left + w, top + h


_FX_CACHE = {}


def fx_tile(group, k, angle=0.0, flip_v=False):
    """弹体与效果帧：按世界方向绘制，可旋转 angle（画面上逆时针，弧度，素材朝右时），之后左右翻转；返回 (路径, 宽, 高)。"""
    key = (group, k, round(angle, 4), flip_v)
    if key not in _FX_CACHE:
        a = img(group, k)
        if flip_v:
            a = a[::-1]
        if angle:
            a = rotsprite.rotate(a, 0, 0, angle)[0]
        a = np.ascontiguousarray(a[:, ::-1])
        path = save_tile(a, FX)
        _FX_CACHE[key] = (path, a.shape[1], a.shape[0])
    return _FX_CACHE[key]


def fx(group, k, x, y, anchor=(0.5, 0.5), angle=0.0, flip_v=False):
    """效果帧放在 U 的 (x, y)：anchor 为图块内的相对位置（0–1）。"""
    path, w, h = fx_tile(group, k, angle, flip_v)
    return (path, 0, 0, int(round(x - anchor[0] * w)), int(round(y - anchor[1] * h)))


def save_json(path, data):
    path.write_text(json.dumps(data, ensure_ascii=False, indent=1) + '\n', encoding='utf-8')
