"""IRON SENTINEL（MSA）素材表切帧（2026-10-20）。

来源：source/MSA_Iron_Sentinel.png（《Metal Slug Attack》单位 Iron Sentinel，Midian-P 提取、Division 6 提供放置参考、
Patchworks 整理，3698×2717，无损 PNG）。每帧由边框围成格子，格内为透明底。边框颜色为洋红 (255,0,255) / (255,1,255)，
侧炮两组另用蓝 (0,51,255)、红 (255,4,4)；素材表背景为绿 (0,255,0)。

本脚本只按格子切出内容并记录素材表坐标（格子与内容外框），不移动、不改色；部件之间的相对位置由 build 脚本按颜色逐像素比对求出。
素材为 MSA 的斜置图（车体沿下坡方向倾斜约 20°，朝右）；水平化与翻转在 build 脚本中进行。

运行（需要 numpy 与 scipy）：E:\\anaconda3\\python.exe -I artwork/iron_sentinel_20261020/cut_frames.py
输出 frames/<名称>_<序号>.png（透明底，裁到内容）与 frames.json（每帧 file、cell [x,y,w,h]、box [x,y,w,h]，均为素材表坐标）。
另从 MS6 素材表（source/MS6_Iron_Sentinel.png，Division 6 整理）切出排气烟 13 帧（EXHAUST FUMES 一行，两根排气管各一团，R3b 用于待机），
颜色按 5 位分量换算为 MSA 素材的取值（c & ~7 | c >> 5，MSA 以位复制扩展、MS6 以 ×8 扩展），记为组 fumes（box 为 MS6 素材表坐标）。
R4 另切出 MS6 素材表 CANNON 一节的炮口火光与烟（16 格，每格 110×64，同一格内配准相同），记为组 muzzle，整格保存（不裁切）。
"""
from pathlib import Path
import json

import numpy as np
from PIL import Image
from scipy import ndimage

HERE = Path(__file__).resolve().parent
SHEET = HERE / 'source' / 'MSA_Iron_Sentinel.png'
MS6_SHEET = HERE / 'source' / 'MS6_Iron_Sentinel.png'
MS6_BG = (60, 199, 182)
FUMES_ROWS = (757, 810)          # MS6 素材表 EXHAUST FUMES 一行（标签在其上方）
MUZZLE_CELLS = [(x, y) for y in (288, 356) for x in range(0, 912, 114)]    # 炮口火光与烟的格子左上角（110×64）
OUT = HERE / 'frames'
BORDERS = ((255, 0, 255), (255, 1, 255), (0, 51, 255), (255, 4, 4))
GREEN = (0, 255, 0)

# 名称：(素材表区域 x0, y0, x1, y1（格子左上角落在其中）, 格子最小宽, 最小高)。区域按素材表标签划分（第 2 节，
# docs/ms6/IRON_SENTINEL_RESEARCH_2026-10-20.md）；同一区域内按行（格上 12 像素一档）、再按格左排序。
GROUPS = {
    'body': ((0, 80, 820, 245), 200, 100),               # 车体 279×152 ×2、车底板 237×152
    'body_parts': ((800, 95, 1550, 245), 90, 40),        # 排气管、顶板等小部件
    'tread_a': ((1550, 40, 2560, 140), 150, 80),         # 履带 160×92 ×6
    'tread_b': ((1550, 140, 2560, 245), 150, 80),        # 履带 168×94 ×6
    'destroyed': ((2580, 10, 3380, 245), 150, 200),      # 损毁车体
    'destroyed_part': ((3550, 60, 3698, 200), 100, 100),
    'icon': ((3370, 185, 3440, 245), 40, 40),
    'ff_hull': ((0, 250, 2200, 460), 190, 90),           # 第一形态部件：车体（无履带）、顶板
    'ff_bare': ((0, 460, 2200, 720), 350, 250),          # 车体 + 履带（无主炮）6 帧
    'ff_walk': ((0, 720, 2200, 1000), 350, 250),         # 第一形态整车（含主炮）6 帧
    'guide': ((2340, 900, 2740, 1130), 380, 200),        # 组装参考：完整第一形态
    'guide_open': ((2340, 1120, 2720, 1400), 350, 250),  # 组装参考：侧面舱口全开、侧炮位置标记
    'guide_mark': ((2400, 1160, 2640, 1250), 40, 60),    # 侧炮 1、2 的位置标记
    'guide_red': ((2680, 1270, 3100, 1400), 380, 200),   # 整体偏红的整车（推测为受击闪色参考）
    'sf_arm_a': ((1170, 1000, 2350, 1200), 280, 190),    # 第二形态部件：发射臂各阶段
    'sf_arm_b': ((0, 1185, 1170, 1400), 280, 190),
    'sf_arm_c': ((1170, 1205, 2350, 1400), 280, 170),
    'sf_walk_a': ((0, 1398, 2200, 1670), 350, 250),      # 第二形态整车 6 帧 ×3 行
    'sf_walk_b': ((0, 1670, 2200, 1935), 350, 250),
    'sf_walk_c': ((0, 1935, 2200, 2200), 350, 230),
    'cannon_idle': ((2340, 1405, 2620, 1495), 120, 70),  # 主炮
    'cannon_fire': ((2340, 1495, 3290, 1580), 100, 70),
    'shell': ((3280, 1555, 3480, 1580), 80, 15),
    'cannon_missile': ((2340, 1580, 3698, 1625), 80, 25),
    'hatch_small': ((2340, 1630, 2580, 1675), 20, 30),
    'hatch': ((2340, 1675, 2970, 1715), 30, 35),         # 侧面舱口（火箭）
    'hatch_rocket': ((2340, 1715, 2970, 1800), 30, 70),
    'rocket': ((2970, 1725, 3400, 1800), 10, 60),        # 小火箭飞行
    'dome': ((2340, 1805, 2680, 1850), 20, 30),          # 圆顶小炮塔：升起（暗→亮）
    'dome_b': ((2680, 1800, 2980, 1850), 28, 35),        # 炮管转向（第 0 帧与升起后的姿势相同）
    'dome_c': ((2975, 1815, 3170, 1850), 30, 25),        # 炮管朝前、后坐
    'bomb': ((3165, 1830, 3260, 1850), 8, 8),            # 橙色小弹
    'side1_a': ((2350, 1850, 3560, 1930), 30, 70),       # 侧炮 1（蓝框）2 行
    'side1_b': ((2350, 1930, 3560, 2015), 30, 70),
    'side2_a': ((2350, 2015, 3560, 2100), 30, 70),       # 侧炮 2（红框）2 行
    'side2_b': ((2350, 2100, 3560, 2190), 30, 70),
    'fc_cannon': ((0, 2200, 265, 2290), 60, 70),         # 形态转换：主炮碎块
    'fc_plate': ((265, 2215, 1280, 2290), 100, 50),      # 顶板碎片
    'fc_flat': ((1280, 2215, 2400, 2290), 100, 50),      # 平板碎片
    'fc_arm': ((2410, 2195, 3250, 2290), 15, 70),        # 发射臂部件
    'silo_arm': ((0, 2315, 760, 2420), 100, 85),         # 发射臂抬起
    'missile_turn': ((750, 2295, 2210, 2420), 10, 100),  # 巨型导弹由平放转为竖直
    'silo_loaded': ((0, 2500, 230, 2605), 100, 85),      # 装弹的发射臂
    'flame_small': ((230, 2545, 510, 2605), 25, 45),
    'missile_tilt': ((505, 2430, 615, 2605), 90, 150),
    'flame_a': ((610, 2490, 880, 2605), 40, 100),
    'missile_up': ((880, 2415, 930, 2605), 35, 170),
    'flame_b': ((925, 2485, 1172, 2605), 30, 100),
    'missile_break': ((1170, 2430, 1900, 2605), 40, 150),
    'blast': ((1900, 2435, 3298, 2605), 20, 150),
    'smoke_a': ((0, 2605, 780, 2717), 140, 85),
    'smoke_b': ((780, 2605, 1340, 2717), 110, 70),
    'smoke_c': ((1340, 2605, 2140, 2717), 140, 85),
    'smoke_d': ((2140, 2605, 3698, 2717), 80, 75),
}
EXCLUDED = ('飞行战舰与粉色小型飞行器（x≈2800–3698，y≈700–1135）不属于本单位，不切出')


def cells(a):
    """边框与绿底之外的连通区域即格子：[(格左, 格上, 格宽, 格高, 内容 RGBA)]。"""
    def iscol(c):
        return (a[..., 0] == c[0]) & (a[..., 1] == c[1]) & (a[..., 2] == c[2]) & (a[..., 3] == 255)
    border = np.zeros(a.shape[:2], bool)
    for c in BORDERS:
        border |= iscol(c)
    green = iscol(GREEN)
    lab, _ = ndimage.label(~border & ~green)
    out = []
    for i, s in enumerate(ndimage.find_objects(lab)):
        y0, y1, x0, x1 = s[0].start, s[0].stop, s[1].start, s[1].stop
        sub = a[s].copy()
        keep = (lab[s] == i + 1) & (sub[..., 3] > 0)
        if not keep.any():
            continue
        sub[~keep] = 0
        out.append((x0, y0, x1 - x0, y1 - y0, sub))
    return out


def ms6_fumes():
    """MS6 素材表的排气烟：该行内不透明且非背景色的像素按列间隙（≥4 列）分帧。"""
    a = np.array(Image.open(MS6_SHEET).convert('RGBA'))
    y0, y1 = FUMES_ROWS
    reg = a[y0:y1].copy()
    fg = (reg[..., 3] > 0) & ~np.all(reg[..., :3] == MS6_BG, axis=-1)
    reg[~fg] = 0
    rgb = reg[..., :3].astype(np.int32)
    reg[..., :3] = ((rgb & ~7) | (rgb >> 5)).astype(np.uint8)
    cols = np.nonzero(fg.any(axis=0))[0]
    groups, start = [], cols[0]
    for c0, c1 in zip(cols, cols[1:]):
        if c1 - c0 > 3:
            groups.append((start, c0))
            start = c1
    groups.append((start, cols[-1]))
    out = []
    for n, (g0, g1) in enumerate(groups):
        sub = reg[:, g0:g1 + 1]
        ys, xs = np.nonzero(sub[..., 3])
        bx, by, bx1, by1 = xs.min(), ys.min(), xs.max() + 1, ys.max() + 1
        file = f'fumes_{n:02d}.png'
        Image.fromarray(sub[by:by1, bx:bx1]).save(OUT / file)
        out.append({'file': file, 'box': [int(g0 + bx), int(y0 + by), int(bx1 - bx), int(by1 - by)], 'sheet': 'MS6'})
    return out


def ms6_muzzle():
    """MS6 素材表的炮口火光与烟：格内非背景色像素，整格保存（各帧配准一致）。"""
    a = np.array(Image.open(MS6_SHEET).convert('RGBA'))
    out = []
    for n, (x, y) in enumerate(MUZZLE_CELLS):
        cell = a[y:y + 64, x:x + 110].copy()
        fg = (cell[..., 3] > 0) & ~np.all(cell[..., :3] == MS6_BG, axis=-1)
        cell[~fg] = 0
        rgb = cell[..., :3].astype(np.int32)
        cell[..., :3] = ((rgb & ~7) | (rgb >> 5)).astype(np.uint8)
        file = f'muzzle_{n:02d}.png'
        Image.fromarray(cell).save(OUT / file)
        out.append({'file': file, 'box': [x, y, 110, 64], 'cell': [x, y, 110, 64], 'sheet': 'MS6'})
    return out


def main():
    a = np.array(Image.open(SHEET).convert('RGBA'))
    OUT.mkdir(exist_ok=True)
    for old in OUT.glob('*.png'):
        old.unlink()
    found = {name: [] for name in GROUPS}
    for x, y, w, h, sub in cells(a):
        for name, ((gx0, gy0, gx1, gy1), mw, mh) in GROUPS.items():
            if gx0 <= x < gx1 and gy0 <= y < gy1 and w >= mw and h >= mh:
                found[name].append((x, y, w, h, sub))
                break
    data = {}
    for name, items in found.items():
        items.sort(key=lambda t: (t[1] // 12, t[0]))
        data[name] = []
        for n, (x, y, w, h, sub) in enumerate(items):
            ys, xs = np.nonzero(sub[..., 3])
            bx, by, bx1, by1 = xs.min(), ys.min(), xs.max() + 1, ys.max() + 1
            file = f'{name}_{n:02d}.png'
            Image.fromarray(sub[by:by1, bx:bx1]).save(OUT / file)
            data[name].append({'file': file, 'cell': [int(x), int(y), int(w), int(h)],
                               'box': [int(x + bx), int(y + by), int(bx1 - bx), int(by1 - by)]})
    data['fumes'] = ms6_fumes()
    data['muzzle'] = ms6_muzzle()
    data['meta'] = {'source': SHEET.name, 'excluded': EXCLUDED, 'fumes_source': MS6_SHEET.name}
    (HERE / 'frames.json').write_text(json.dumps(data, ensure_ascii=False, indent=1), encoding='utf-8')
    print({k: len(v) for k, v in data.items() if k != 'meta'})


if __name__ == '__main__':
    main()
