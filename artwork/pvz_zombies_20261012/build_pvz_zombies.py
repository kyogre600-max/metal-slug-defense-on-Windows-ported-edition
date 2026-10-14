"""PVZ 僵尸（首批 7 种可选单位与 1 个内部飞行单位）的资源与单位文件生成：OBM 图集、精灵描述符、动作脚本、头像页、
单位文件、音效（MSDF）与 content.json 登记。

素材：用户提供的 DS 版 Plants vs. Zombies 素材表（F:\\egg\\PVZ），已由研究目录
content_work/pvz_event_feasibility_20261012/gif_sim 切帧并计算脚底锚点（anims.json、garg_jpg/anims.json）。
本脚本首次运行时把用到的帧复制到 source/（之后只读 source/），音效从 F:\\egg\\PVZ\\*.ogg 复制为 community_content/pvz_*.msdf。

行为（行为库 v3）：基准为原版僵尸（青年）UnitID 313（BattleAction_ZombieBrain：状态 10/20/30·40/50/70/80/100·110/120
依次使用槽 6/7/9/10/11/12/13/15）。第 k 个生命档使用槽 原生槽号 + 16k；带过渡的档位在槽 12+16k 播放过渡动作。
素材朝左（与僵尸（青年）相同，前方为 −x），原生按队伍翻转。

运行：python build_pvz_zombies.py（需要 windows_runtime 中的 Pillow；写入 community_content/ 与本目录 out/）。
"""
from pathlib import Path
import hashlib
import json
import os
import shutil
import struct
import sys

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[1]
RT = REPO / 'windows_runtime'
sys.path.insert(0, str(RT / 'packages'))
os.add_dll_directory(str(RT / 'native'))
from PIL import Image  # noqa: E402

RESEARCH = Path(os.environ.get('PVZ_RESEARCH', r'F:\egg\research\metal_slug_defense\content_work\pvz_event_feasibility_20261012\gif_sim'))
SOUND_SOURCE = Path(os.environ.get('PVZ_SOUNDS', r'F:\egg\PVZ'))
SOURCE = HERE / 'source'
CONTENT = REPO / 'community_content'
OUT = HERE / 'out'
ICON_ATLAS = 'pvz_icons.obm'

# ---------------------------------------------------------------- 原生约定
STRIDE = 16
LENGTHS = (2, 2, 2, 2, 2, 1, 3, 5, 2, 2, 3, 5, 5, 2, 3, 1, 1, 2, 2, 3, 3, 1, 5, 2)
# 效果脚本的位移（op7 单位为 0.01/tick）。素材像素与 op7 的比例在验证时校准（EFFECT_SCALE）。
EFFECT_SCALE = 1.0


def F(frame, wait):
    return [{'opcode': 0, 'values': [frame]}, {'opcode': 1, 'values': [wait]}]


def op(code, *values):
    return {'opcode': code, 'values': list(values)}


# ---------------------------------------------------------------- 素材读取
def anims():
    main = json.loads((RESEARCH / 'anims.json').read_text(encoding='utf-8'))
    # 巨人：2026-10-15 起使用用户重新制作的素材表（garg_user/cut.py 切帧，锚点与交接表配准；结构同 garg_jpg/anims.json）
    garg = json.loads((RESEARCH / 'garg_user' / 'anims.json').read_text(encoding='utf-8'))
    return main, garg


def copy_sources(main, garg):
    """把用到的帧复制到 source/（保持子目录）。研究目录可用时以它为准：缺少或内容不同的帧重新复制
    （2026-10-13 巨人帧重新清理后同名文件内容改变）。"""
    SOURCE.mkdir(exist_ok=True)

    def put(src, dst):
        if not src.exists():
            return
        if not dst.exists() or dst.read_bytes() != src.read_bytes():
            dst.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(src, dst)

    for key in ('zombie', 'cone', 'bucket', 'football', 'newspaper', 'zomboni'):
        for frames in main[key].values():
            for f in frames:
                put(RESEARCH / 'frames' / f['file'], SOURCE / f['file'])
    for name in ('imp_walk', 'imp_eat', 'imp_death', 'imp_fly'):
        for f in main['garg'][name]:
            put(RESEARCH / 'frames' / f['file'], SOURCE / f['file'])
    # 巨人帧：2026-10-15 起为用户拼接的素材表（此前为 garg_parts/fit.py 的分件配准结果，用户判定不可用）。
    for seq in garg['anims'].values():
        for f in seq['frames']:
            put(RESEARCH / 'garg_user' / 'frames' / f['file'], SOURCE / 'gargantuar' / f['file'])
    for f in garg['imp_charred']:
        put(RESEARCH / 'garg_user' / 'frames' / f['file'], SOURCE / 'gargantuar' / f['file'])


def seq(main, key, name):
    return [(SOURCE / f['file'], int(f['ax'] + 0.5), int(f['ay'])) for f in main[key][name]]


def garg_seq(garg, name):
    return [(SOURCE / 'gargantuar' / f['file'], int(f['ax']), int(f['ay'])) for f in garg['anims'][name]['frames']]


# ---------------------------------------------------------------- 待机（中立）动作（2026-10-13：待机不再只是一张图）
# 素材表的待机行：普通 5 帧、断臂 4 帧、路障 / 铁桶 5 帧、读报 6 帧、橄榄球 4 帧（只有满血档）。其余档位与没有待机行的
# 单位（读报狂暴、小鬼、巨人）按下面两种方式由已有帧组成；生成的帧写在 source/derived/，结果记在 IDLE_REPORT。
IDLE_HOLD = 4
DERIVED = SOURCE / 'derived'
IDLE_REPORT = {}


def anchored(path, ax, ay):
    """{(x−ax, y−ay): RGBA}，只含不透明像素。"""
    img = Image.open(path).convert('RGBA')
    px = img.load()
    return {(x - ax, y - ay): px[x, y] for y in range(img.height) for x in range(img.width) if px[x, y][3]}


def save_anchored(pixels, path):
    xs = [p[0] for p in pixels]; ys = [p[1] for p in pixels]
    x0, y0 = min(xs), min(ys)
    img = Image.new('RGBA', (max(xs) - x0 + 1, max(ys) - y0 + 1), (0, 0, 0, 0))
    for (x, y), c in pixels.items():
        img.putpixel((x - x0, y - y0), c)
    path.parent.mkdir(parents=True, exist_ok=True)
    img.save(path)
    return (path, -x0, -y0)


def frame_diff(a, b):
    return sum(1 for p in set(a) | set(b) if a.get(p) != b.get(p))


def idle_cycle(frames):
    """待机行若首尾差别与相邻帧相当则循环播放，否则往返播放（0…n−1…1）。"""
    if len(frames) < 3:
        return frames
    px = [anchored(*f) for f in frames]
    steps = sorted(frame_diff(px[i], px[i + 1]) for i in range(len(px) - 1))
    if frame_diff(px[-1], px[0]) <= 1.5 * steps[len(steps) // 2]:
        return frames
    return frames + frames[-2:0:-1]


def patched_idle(base_walk, stage_walk, base_idle, tag, search=6):
    """受损档的待机：两档行走帧的差异（防具凹痕、头盔裂缝、报纸破口等）贴到满血档待机帧上。
    取满血档行走帧在差异区（外扩 2 px）的像素作模板，在待机帧中找颜色完全相同最多的平移（±search px），
    把受损档行走帧在差异区内的像素（含透明）按该平移写入。行走帧取与待机首帧吻合度最高的一帧。"""
    walks = [(anchored(*b), anchored(*s)) for b, s in zip(base_walk, stage_walk)]
    idles = [anchored(*f) for f in base_idle]

    def prepare(w0, ws):
        diff = {p for p in set(w0) | set(ws) if w0.get(p) != ws.get(p)}
        ctx = {(x + dx, y + dy) for x, y in diff for dx in range(-2, 3) for dy in range(-2, 3)}
        return diff, {p: w0[p] for p in ctx if p in w0}

    def match(template, idle):
        best = (-1, (0, 0))
        for ox in range(-search, search + 1):
            for oy in range(-search, search + 1):
                n = sum(1 for (x, y), c in template.items() if idle.get((x + ox, y + oy)) == c)
                if n > best[0]:
                    best = (n, (ox, oy))
        return best

    prepared = [prepare(w0, ws) for w0, ws in walks]
    scores = [(match(t, idles[0])[0] / max(1, len(t)), j) for j, (d, t) in enumerate(prepared) if d]
    j = max(scores)[1]
    diff, template = prepared[j]
    w_stage = walks[j][1]
    out, ratios = [], []
    for i, idle in enumerate(idles):
        n, (ox, oy) = match(template, idle)
        ratios.append(round(n / max(1, len(template)), 3))
        px = dict(idle)
        for x, y in diff:
            c = w_stage.get((x, y))
            if c is None:
                px.pop((x + ox, y + oy), None)
            else:
                px[(x + ox, y + oy)] = c
        out.append(save_anchored(px, DERIVED / f'{tag}_{i:02d}.png'))
    IDLE_REPORT[tag] = {'method': 'patched', 'walk_frame': j, 'diff_pixels': len(diff), 'match': ratios}
    return out


def sway_idle(walk, tag):
    """没有待机行的单位：取行走循环中差别最小的相邻两帧交替（每帧 6 tick），作为站立时的轻微晃动。"""
    px = [anchored(*f) for f in walk]
    n = len(px)
    d, a = min((frame_diff(px[i], px[(i + 1) % n]), i) for i in range(n))
    b = (a + 1) % n
    IDLE_REPORT[tag] = {'method': 'sway', 'frames': [a, b], 'diff_pixels': d}
    return [walk[a], walk[b]]


def breath_idle(frame, tag, cut=0.55):
    """巨人：行走相邻帧差别过大（电线杆换边），改用站立帧与“腰部以上下移 1 px”的副本交替，作为呼吸起伏。
    cut 为自头顶起的高度比例（以上的像素整体下移 1 行）。"""
    px = anchored(*frame)
    top = min(y for _, y in px); bottom = max(y for _, y in px)
    y_cut = top + int((bottom - top) * cut)
    low = {p: c for p, c in px.items() if p[1] >= y_cut}
    for (x, y), c in px.items():
        if y < y_cut:
            low[(x, y + 1)] = c
    IDLE_REPORT[tag] = {'method': 'breath', 'cut_row': y_cut, 'pixels': len(px)}
    return [frame, save_anchored(low, DERIVED / f'{tag}_01.png')]


# ---------------------------------------------------------------- 图集与描述符
class Sheet:
    """一个单位的图块、帧条目与脚本。"""

    def __init__(self):
        self.tiles, self.tile_index = [], {}
        self.rects, self.rect_index = [], {}
        self.frames, self.frame_index = [], {}
        self.scripts = {}

    def tile(self, path):
        key = str(path)
        if key not in self.tile_index:
            img = Image.open(path).convert('RGBA')
            box = img.getbbox()
            self.tile_index[key] = len(self.tiles)
            self.tiles.append((img.crop(box), box))
        return self.tile_index[key]

    def frame(self, parts):
        """parts：[(路径, 锚点 x, 锚点 y, 偏移 dx, dy)]；返回帧条目起点。锚点为图像内的脚底点，偏移为相对单位原点。"""
        rects = []
        for path, ax, ay, dx, dy in parts:
            t = self.tile(path)
            _, box = self.tiles[t]
            key = (t, ax - box[0] - dx, ay - box[1] - dy)
            if key not in self.rect_index:
                self.rect_index[key] = len(self.rects)
                self.rects.append(key)
            rects.append(self.rect_index[key])
        key = tuple(rects)
        if key not in self.frame_index:
            self.frame_index[key] = len(self.frames)
            self.frames.append(key)
        return key

    def f(self, path, ax, ay, dx=0, dy=0):
        return self.frame([(path, ax, ay, dx, dy)])


def indexed_obm(image):
    rgba = image.convert('RGBA')
    colors = list(dict.fromkeys(rgba.getdata()))
    assert len(colors) <= 256, len(colors)
    lut = {color: index for index, color in enumerate(colors)}
    raw = b'OI\x01\x08' + struct.pack('<HH', *image.size)
    return raw + b''.join(bytes(c) for c in colors).ljust(1024, b'\0') + bytes(lut[c] for c in rgba.getdata())


def shelf_pack(tiles, pad=1, sizes=((256, 256), (512, 256), (512, 512), (1024, 512), (1024, 1024), (2048, 1024))):
    order = sorted(range(len(tiles)), key=lambda i: (-tiles[i].height, -tiles[i].width))
    for W, H in sizes:
        x = y = shelf = 0
        pos, ok = {}, True
        for i in order:
            w, h = tiles[i].width + pad, tiles[i].height + pad
            if x + w > W:
                x, y, shelf = 0, y + shelf, 0
            if w > W or y + h > H:
                ok = False
                break
            pos[i] = (x, y)
            x += w
            shelf = max(shelf, h)
        if ok:
            page = Image.new('RGBA', (W, H), (0, 0, 0, 0))
            for i, (px, py) in pos.items():
                page.paste(tiles[i], (px, py))
            return page, pos
    raise ValueError('atlas overflow')


def finish(sheet, script_count, hit, attacks):
    """装箱并返回 (OBM 字节, 描述符, 动作脚本)。帧条目以 [数量, 矩形...] 写出，脚本中的帧键换为条目起点。"""
    page, pos = shelf_pack([img for img, _ in sheet.tiles])
    rects = []
    for t, ax, ay in sheet.rects:
        img, _ = sheet.tiles[t]
        x, y = pos[t]
        rects.append([x, y, img.width, img.height, ax, ay, 0, 0])
    starts, words = {}, []
    for key in sheet.frames:
        starts[key] = len(words)
        words += [len(key)] + list(key)
    animations = {}
    for slot, commands in sorted(sheet.scripts.items()):
        out = []
        for cmd in commands:
            if cmd['opcode'] == 0 and isinstance(cmd['values'][0], tuple):
                cmd = op(0, starts[cmd['values'][0]])
            out.append(cmd)
        animations[str(slot)] = out
    for slot in range(script_count):
        animations.setdefault(str(slot), [op(0, -1), op(1, 1), op(21)])
    desc = {'rects': rects, 'frames': words, 'script_count': script_count,
            'hit_bounds': [[0, 0, 0, 0, 0], hit, [0, 0, 0, 0, 0]],
            'attack_bounds': [[0, 0, 0, 0, 0]] + attacks}
    return indexed_obm(page), desc, animations, page


# ---------------------------------------------------------------- 动作片段
# 2026-10-13 用户调整（UNITS 中的 hp / move / dmg 为第一版设计值，写入单位文件时乘以下列比例）：
# - 生命：保持第一版的比例关系（路障 / 铁桶为普通的 2 / 4 倍，读报为报纸 4 倍 + 本体 2 倍，橄榄球为铁桶的 2.5 倍，
#   巨人为橄榄球的 2 倍，小鬼为普通的 1.5 倍），以橄榄球 Lv40 15000 为基准整体换算：× 15/34（普通 Lv40 1500）。
#   击退门槛同倍率（AGENTS 第 6.1 节；僵尸另有 no_knockback）。
# - 移速：全部降低 33%（×67/100），行走动作每帧停留按同一比例延长（整数 tick 交替），脚步与位移保持一致。
# - 伤害：除巨人外 ×5（每口 60 → 300，橄榄球 180 → 900）；读报狂暴后伤害不再提高，只提高移速。
# - 绝招：除巨人外取消（同原版无绝招单位：词 35/36 冷却为 0，BattleUnit::isSpAttack 恒为否；词 29 伤害为 0）；
#   巨人绝招冷却 ×5/2，再出击时间 ×2（800 → 1600 tick）。
HP_SCALE = (15, 34)
MOVE_SCALE = (67, 100)
# 同日再调：普通、路障、铁桶与读报（正常状态）移速再 ×67/100（共 ×4489/10000）；读报狂暴后的速度保持 4.02
# （狂暴倍率按两档移速之比换算为 250/67），行走动画节奏按各自移速换算。
MOVE_SCALE_SLOW = (4489, 10000)
# 修订四：橄榄球移速再 ×4/5（共 ×67/125，4.824 → 3.859），奔跑动画节奏同比放慢。
# 修订六：除橄榄球外移速再 ×6/5（读报狂暴后的速度仍为 4.02，见 unit_file 的狂暴倍率换算），行走动画节奏同比加快。
# 普通、路障、铁桶与读报为 MOVE_SCALE_SLOW × 6/5 = 13467/25000，加载器的有理数倍率要求分子分母不超过 10000，
# 取 7/13（相差 0.04%，Lv40 1.292）；7/13 时读报的狂暴倍率为 871/280，狂暴后恰为 4.02。巨人与小鬼为 MOVE_SCALE × 6/5。
# 2026-10-15 巨人移速再 ×4/5（用户指定，201/250 × 4/5 = 402/625，Lv40 1.544 → 1.235），行走动画节奏同比放慢；小鬼不变。
MOVE_SCALE_BY_KIND = {'zombie': (7, 13), 'cone': (7, 13), 'bucket': (7, 13), 'newspaper': (7, 13),
                      'football': (67, 125), 'gargantuar': (402, 625), 'imp': (201, 250)}
DMG_SCALE = {'gargantuar': (1, 1)}
DMG_SCALE_DEFAULT = (5, 1)
# 2026-10-13 修订四（用户指定，UNITS 中已改为对应的第一版设计值）：读报总生命 6000、本体同普通僵尸 1500（报纸 4500），
# AP 175（用户实测后由 200 改定，与 PvZ 原作的价格次序一致），狂暴后每口 450（正常 300）；橄榄球生命 9000、移速 −20%、每口 300、AP 225；小鬼每口 200；巨人生命 15000、
# 锤击 3000、重锤 6000。除巨人外恢复击退：Lv40 击退门槛橄榄球 80、其余 60（用户指定，不随生命倍率联动，AGENTS 第 6.1 节；
# 僵尸（青年）的门槛各等级均为 30，倍率为 [8,3] 与 [2,1]），受击滑行约 16 像素（基 · 寇卡 MK.III：64 × 1/4）；巨人保持无击退。
KNOCKBACK_THRESHOLD = {'football': [8, 3], 'gargantuar': None}   # None：同生命倍率（巨人带 no_knockback，不使用）
KNOCKBACK_THRESHOLD_DEFAULT = [2, 1]
# 2026-10-13 修订五（用户指定）：再出击时间橄榄球、读报 −33%（×67/100），其余僵尸 −20%（×4/5），作用于 UNITS 的
# interval（2026-10-12 指定值，巨人含 ×2）；加载器在等级锚点向上取整：普通 64、路障 80、铁桶 96、读报 134、
# 橄榄球 168（167.5）、巨人 1280、小鬼 48 tick。
INTERVAL_SCALE = {'football': (67, 100), 'newspaper': (67, 100)}
INTERVAL_SCALE_DEFAULT = (4, 5)
# 2026-10-13 修订六（用户指定）：生命按“本体 + 防具”给出，本体（同普通僵尸）3000、路障 1500、铁桶 4500、报纸 4500、
# 橄榄球头盔 9000，Lv40 总生命普通 3000、路障 4500、铁桶 7500、读报 7500、橄榄球 12000（UNITS 的 hp 为 1500 的倍数）；
# 生命分档按“防具失去 1/3、2/3、防具脱落、本体失去一半”重算。击退门槛保持修订四的用户指定值（橄榄球 80、其余 60）。
# 巨人与小鬼的生命不变（用户未指定）。
# 2026-10-13 修订七（用户选定平衡方案 C，verification/pvz_zombies_20261012/BALANCE_PROPOSAL_2026-10-13.md）：
# 本体（同普通僵尸）7500，Lv40 普通 7500、路障 11250（防具 3750）、铁桶 15000（防具 7500）、读报 15000（报纸 7500）、
# 橄榄球 18000（头盔 10500）、小鬼 4500，巨人不变；分档仍按“防具失去 1/3、2/3、防具脱落、本体失去一半”。
# 击退门槛保持用户指定值（橄榄球 80、其余 60），不随生命放大。


def scaled(ratio, scale):
    from fractions import Fraction
    f = Fraction(*ratio) * Fraction(*scale)
    return [f.numerator, f.denominator]


def slow_holds(count, hold, scale=MOVE_SCALE):
    """行走每帧停留 hold tick 按移速比例 scale 的倒数延长：累计取整，例如 ×67/100 时 3 → 4、5、4、5…，1 → 1、2、1、2…。"""
    k = hold * scale[1] / scale[0]
    return [round((i + 1) * k) - round(i * k) for i in range(count)]


def loop(frames, holds, first=()):
    """循环动作：[op3[1]] + 帧 + op5。"""
    out = list(first)
    for fr, w in zip(frames, holds):
        out += F(fr, w)
    return out + [op(5)]


def once(frames, holds, first=(), events=None, tail=None):
    """播放一次：events 为 {帧序号: [命令]}（在该帧之前插入），tail 为结尾前插入的命令，最后 op21。"""
    out = list(first)
    for i, (fr, w) in enumerate(zip(frames, holds)):
        out += (events or {}).get(i, [])
        out += F(fr, w)
    out += (events or {}).get(len(frames), [])
    return out + list(tail or []) + [op(21)]


def bite(frames, hold, bites, sound_pairs, rect=1):
    """啃咬一次循环：咬合帧前 op4[rect] 与音效，下一帧前 op4[-1]。"""
    events = {}
    for n, i in enumerate(bites):
        chomp, splat = sound_pairs[n % len(sound_pairs)]
        events.setdefault(i, []).extend([op(4, rect), op(23, chomp), op(23, splat)])
        events.setdefault(i + 1, []).append(op(4, -1))
    return once(frames, [hold] * len(frames), first=[op(3, 1)], events=events)


def multi_bite(frames, hold, bites, sound_pairs, count, rect=1):
    """绝招：连续啃咬 count 口（逐帧重复啃咬循环，凑满 count 次咬合判定后播完当前循环，不再判定）。"""
    seq_frames, events, n, i = [], {}, 0, 0
    while True:
        for k, fr in enumerate(frames):
            if k in bites and n < count:
                chomp, splat = sound_pairs[n % len(sound_pairs)]
                events.setdefault(len(seq_frames), []).extend([op(4, rect), op(23, chomp), op(23, splat)])
                events.setdefault(len(seq_frames) + 1, []).append(op(4, -1))
                n += 1
            seq_frames.append(fr)
        if n >= count:
            break
    return once(seq_frames, [hold] * len(seq_frames), first=[op(3, 1)], events=events)


def debris(sheet, path, ax, ay, vx, vy, g, fall_ticks, rest=36):
    """掉落物效果脚本：以 op7 抛出，fall_ticks 后停住，静置后闪烁消失。"""
    fr = sheet.f(path, ax, ay)
    out = [op(7, int(vx * EFFECT_SCALE), int(vy * EFFECT_SCALE), 0, int(g * EFFECT_SCALE))]
    out += F(fr, fall_ticks)
    out += [op(7, 0, 0, 0, 0)] + F(fr, rest)
    for _ in range(4):
        out += F(-1, 2) + F(fr, 2)
    return out + F(-1, 1) + [op(21)]


def throw_ticks(height, vy, g):
    """自高度 height（像素，向上为正）以竖直速度 vy、重力 g（0.01/tick）落回地面所需的 tick。"""
    y, v, t = -height * 100.0, float(vy), 0
    while t < 400:
        t += 1
        y += v
        v += g
        if y >= 0:
            return t
    return t


# ---------------------------------------------------------------- 各单位
S = 's1xlv.'
SND = {name: S + 'pvz_' + name for name in (
    'chomp', 'chomp2', 'splat', 'splat2', 'splat3', 'gulp', 'plastichit', 'plastichit2', 'shieldhit', 'shieldhit2',
    'newspaper_rip', 'newspaper_rarrgh', 'newspaper_rarrgh2', 'lowgroan', 'lowgroan2', 'gargantuar_thump',
    'imp', 'imp2', 'explosion')}
# 冰车的爆炸音效：用户提供（2026-10-13，C:\\Users\\26839\\Downloads\\explosion.ogg，复制到 source/sounds/）
SOUND_FILES = {'explosion': SOURCE / 'sounds' / 'explosion.ogg'}
BITE_SOUNDS = [(SND['chomp'], SND['splat']), (SND['chomp2'], SND['splat2'])]
SPECIAL_BITES = 3        # 绝招连咬次数（暂定）
SPECIAL_BITE_SOUNDS = [(SND['chomp2'], SND['splat3']), (SND['chomp'], SND['splat2'])]
# 啃咬音效增益（2026-10-13 用户要求与原版近战音效同响度）：原版近战音效（B4_KNIFE、B4_PUNCH、b_punch、m_slash、
# locust_bite、B4TKNIFE、KOF95_HIT）100 ms 短时最大均方根 × 音量字的中位数为 13248；PvZ 每次咬合同时播放的
# chomp + splat 组合在增益 4.31（msd_pcm_gain，超过满幅 60% 以 tanh 压缩）下平均为 13257，单独播放的 gulp 为 2.35。
SOUND_GAIN = {'chomp': 4.31, 'chomp2': 4.31, 'splat': 4.31, 'splat2': 4.31, 'splat3': 4.31, 'gulp': 2.35}
# 音效类型（缺省 se；vo 走原生语音通道，与音效分开）。2026-10-15 曾把巨人倒地音效 gargantudeath（3.1 秒）设为 vo，
# 以免混战中被啃咬、受击等音效取代；同日用户决定去掉该音效、改在倒地帧播放锤击落地音效，gargantudeath 不再登记。
SOUND_TYPE = {}


# 受击（击退，2026-10-13 修订四）：与僵尸（青年）槽 12 相同的减速滑行（op7 初速、每 tick 减速），KNOCKBACK_SLIDE tick 后停下，
# 滑行时行走帧倒放，之后站立 KNOCKBACK_RECOVER tick。素材与僵尸（青年）同样朝左，op7 正值为后退。
# 距离以基 · 寇卡 MK.III（UnitID 1028，受击滑行倍率 1/4）为准：同一 LAB 条件下直接预约状态 80，实测世界坐标后退
# MK.III 30.2、僵尸（青年）61.6（其 op7 速度和 27.5，世界坐标约为 op7 速度和 × 2.25）。初速 2.42、每 tick 减 0.24 时
# 速度和 13.4，约 30.2（初稿 3.0 / 0.3 实测 37.3）。
KNOCKBACK_MOVE = (242, -24)
KNOCKBACK_SLIDE = 10
KNOCKBACK_RECOVER = 10


def knockback_script(walk_fr, idle_fr):
    back = walk_fr[::-1]
    out = [op(4, -1), op(3, 1), op(7, KNOCKBACK_MOVE[0], 0, KNOCKBACK_MOVE[1], 0)]
    t = i = 0
    while t < KNOCKBACK_SLIDE:
        out += F(back[i % len(back)], 2)
        t += 2
        i += 1
    return out + [op(7, 0, 0, 0, 0), op(16)] + F(idle_fr[0], KNOCKBACK_RECOVER) + [op(21)]


def biter_block(sheet, block, idle, walk, walk_hold, eat, eat_hold, bites, transition=None, demo=True, idle_hold=IDLE_HOLD,
                move_scale=MOVE_SCALE):
    """一个生命档的槽 0–2、6、7、9–12、14。idle/walk/eat 为帧序列 [(路径, ax, ay)]；idle 为待机（中立）动作。
    槽 14 为该档的受击动作（行为 stage_knockback_animation）；没有过渡的档位槽 12 同为受击动作（不分档的小鬼经槽 12 受击）。"""
    base = STRIDE * block
    walk_fr = [sheet.f(*w) for w in walk]
    eat_fr = [sheet.f(*e) for e in eat]
    idle_fr = [sheet.f(*i) for i in idle]
    idle_hold = [idle_hold] * len(idle_fr) if len(idle_fr) > 1 else [8]
    sheet.scripts[base + 0] = loop(idle_fr, idle_hold)
    sheet.scripts[base + 1] = loop(walk_fr, slow_holds(len(walk_fr), walk_hold, move_scale))
    sheet.scripts[base + 2] = once(eat_fr * 2, [eat_hold] * (2 * len(eat_fr)))
    sheet.scripts[base + 6] = loop(idle_fr, idle_hold, first=[op(3, 1)])
    sheet.scripts[base + 7] = loop(walk_fr, slow_holds(len(walk_fr), walk_hold, move_scale), first=[op(3, 1)])
    sheet.scripts[base + 9] = bite(eat_fr, eat_hold, bites, BITE_SOUNDS)
    # 绝招：连续啃咬 SPECIAL_BITES 口，每口为普通啃咬的 2 倍（单位文件 special_damage_multiplier [2,1]，2026-10-12 用户要求）
    sheet.scripts[base + 10] = multi_bite(eat_fr, eat_hold, bites, SPECIAL_BITE_SOUNDS, SPECIAL_BITES)
    sheet.scripts[base + 11] = loop(eat_fr[:1], [1], first=[op(3, 1)])
    knock = knockback_script(walk_fr, idle_fr)
    sheet.scripts[base + 12] = transition if transition is not None else knock
    sheet.scripts[base + 14] = knock


def death_slots(sheet, frames, holds, first=(), linger=12, events=None):
    """死亡（槽 13、15；状态 100/110 用 13，120 用 15；槽 14 为受击动作，槽 16 属于第 1 档）：倒地帧、末帧停留后闪烁消失。
    events 同 once（{帧序号: [命令]}，在该帧之前插入）。"""
    fr = [sheet.f(*x) for x in frames]
    body = once(fr + [fr[-1]], list(holds) + [linger], first=first, events=events,
                tail=[c for _ in range(3) for c in F(-1, 2) + F(fr[-1], 2)] + F(-1, 1))
    for slot in (13, 15):
        sheet.scripts[slot] = body


# 火焰击杀（状态 120，槽 15；2026-10-13 用户要求）：普通僵尸素材表右上角的两帧焦黑剪影（睁眼、闭眼）交替，形成眨眼，
# 随后直接消失（DS 版没有灰烬落下的动画）。用于巨人、冰车、小鬼以外的僵尸；剪影为普通僵尸体形。
CHARRED_BLINK = [(0, 12), (1, 3), (0, 12), (1, 3), (0, 12)]


def charred_script(sheet, main):
    fr = [sheet.f(*x) for x in seq(main, 'zombie', 'charred')]
    return once([fr[i] for i, _ in CHARRED_BLINK], [h for _, h in CHARRED_BLINK], tail=F(-1, 1))


def charred_blink(sheet, frames):
    """巨人与小鬼的火焰击杀（槽 15）：用户素材表中的焦黑剪影（睁眼、闭眼，2026-10-15 补充闭眼帧），眨眼节奏同普通僵尸。"""
    fr = [sheet.f(*x) for x in frames]
    return once([fr[i] for i, _ in CHARRED_BLINK], [h for _, h in CHARRED_BLINK], tail=F(-1, 1))


def transition_script(sheet, frame_seq, holds, events):
    fr = [sheet.f(*x) for x in frame_seq]
    return once(fr, holds, first=[op(3, 1)], events=events)


def build_zombie_family(main, kind):
    """普通 / 路障 / 铁桶：armor 档（3 档外观）→ 普通 → 断臂。"""
    sheet = Sheet()
    z = lambda name: seq(main, 'zombie', name)
    head = z('head')[0]
    arm = z('arm')[0]
    # 效果槽（放在各档之后）：头、手臂、防具
    blocks = {'zombie': 2, 'cone': 5, 'bucket': 5}[kind]
    e_head, e_arm, e_armor = STRIDE * blocks, STRIDE * blocks + 1, STRIDE * blocks + 2
    sheet.scripts[e_head] = debris(sheet, *head, vx=50, vy=-180, g=30, fall_ticks=throw_ticks(44, -180, 30))
    sheet.scripts[e_arm] = debris(sheet, *arm, vx=-40, vy=-100, g=30, fall_ticks=throw_ticks(34, -100, 30))
    stages = []
    if kind != 'zombie':
        # 掉落的防具用素材表右上角三帧中最右边（损坏最重）的一帧（2026-10-13 用户要求；此前用最左边的完整版）
        drop = seq(main, kind, 'armor_drop')[-1]
        sheet.scripts[e_armor] = debris(sheet, *drop, vx=80, vy=-220, g=30, fall_ticks=throw_ticks(46, -220, 30))
        base_walk, base_idle = seq(main, kind, 'walk'), seq(main, kind, 'idle')
        for block, suffix in enumerate(('', '_d1', '_d2')):
            walk = seq(main, kind, 'walk' + suffix)
            eat = seq(main, kind, 'eat' + suffix)
            idle = idle_cycle(base_idle) if not suffix else idle_cycle(
                patched_idle(base_walk, walk, base_idle, f'{kind}_idle{suffix}'))
            biter_block(sheet, block, idle, walk, 3, eat, 3, (3,), move_scale=MOVE_SCALE_BY_KIND[kind])
        stages = [3]
    normal_block = len(stages) and 3 or 0
    # 普通（防具掉落的过渡：防具飞出）
    trans = None
    if kind != 'zombie':
        trans = transition_script(sheet, z('walk')[:1], [2], {0: [op(12, e_armor, 0, -2, -46)]})
    biter_block(sheet, normal_block, idle_cycle(z('idle')), z('walk'), 3, z('eat'), 3, (3,), transition=trans,
                move_scale=MOVE_SCALE_BY_KIND[kind])
    # 断臂
    arm_trans = transition_script(sheet, z('walk_armless')[:1], [2], {0: [op(12, e_arm, 0, 6, -34)]})
    biter_block(sheet, normal_block + 1, idle_cycle(z('idle_armless')), z('walk_armless'), 3, z('eat_armless'), 3, (3,),
                transition=arm_trans, move_scale=MOVE_SCALE_BY_KIND[kind])
    death_slots(sheet, z('death'), [3] * 9, first=[op(12, e_head, 0, -2, -44)])
    sheet.scripts[15] = charred_script(sheet, main)
    n_stage_blocks = normal_block + 2
    script_count = STRIDE * n_stage_blocks + 3
    hit = [-9, -48, 18, 48, 0]
    return sheet, script_count, hit, [bite_rect(hit)]


def build_football(main):
    sheet = Sheet()
    blocks = 4
    e_head, e_helmet = STRIDE * blocks, STRIDE * blocks + 1
    head = seq(main, 'zombie', 'head')[0]
    helmet = seq(main, 'football', 'helmet')[0]
    sheet.scripts[e_head] = debris(sheet, *head, vx=50, vy=-180, g=30, fall_ticks=throw_ticks(44, -180, 30))
    sheet.scripts[e_helmet] = debris(sheet, *helmet, vx=100, vy=-240, g=30, fall_ticks=throw_ticks(44, -240, 30))
    base_run, base_idle = seq(main, 'football', 'run'), seq(main, 'football', 'idle')
    for block, suffix in enumerate(('', '_d1', '_d2', '_nohelmet')):
        run = seq(main, 'football', 'run' + suffix)
        eat = seq(main, 'football', 'eat' + suffix)
        trans = None
        if suffix == '_nohelmet':
            trans = transition_script(sheet, run[:1], [2], {0: [op(12, e_helmet, 0, -2, -44)]})
        idle = idle_cycle(base_idle) if not suffix else idle_cycle(
            patched_idle(base_run, run, base_idle, f'football_idle{suffix}'))
        biter_block(sheet, block, idle, run, 1, eat, 2, (2,), transition=trans, move_scale=MOVE_SCALE_BY_KIND['football'])
    death_slots(sheet, seq(main, 'football', 'death'), [3] * 7)
    sheet.scripts[15] = charred_script(sheet, main)
    hit = [-10, -48, 20, 48, 0]
    return sheet, STRIDE * blocks + 2, hit, [bite_rect(hit)]


def build_newspaper(main):
    sheet = Sheet()
    blocks = 4
    e_head, e_paper = STRIDE * blocks, STRIDE * blocks + 1
    n = lambda name: seq(main, 'newspaper', name)
    sheet.scripts[e_head] = debris(sheet, *n('head')[0], vx=50, vy=-180, g=30, fall_ticks=throw_ticks(44, -180, 30))
    sheet.scripts[e_paper] = debris(sheet, *n('paper')[0], vx=-50, vy=-150, g=25, fall_ticks=throw_ticks(30, -150, 25))
    for block, suffix in enumerate(('', '_d1', '_d2')):
        walk = n('walk' + suffix)
        idle = idle_cycle(n('idle')) if not suffix else idle_cycle(
            patched_idle(n('walk'), walk, n('idle'), f'newspaper_idle{suffix}'))
        biter_block(sheet, block, idle, walk, 3, n('eat' + suffix), 4, (3,), move_scale=MOVE_SCALE_BY_KIND['newspaper'])
    # 愣住（报纸被打掉）：修订四依用户要求时长减半，45 → 23 tick（三帧 6/12/27 → 3/6/14，怒吼音效仍在第三帧开始时）
    confused = transition_script(sheet, n('confused'), [3, 6, 14],
                                 {0: [op(12, e_paper, 0, -4, -30), op(23, SND['newspaper_rip'])],
                                  2: [op(23, SND['newspaper_rarrgh'])]})
    rage_walk = n('walk_rage')
    biter_block(sheet, 3, sway_idle(rage_walk, 'newspaper_idle_rage'), rage_walk, 1, n('eat_rage'), 1, (2, 5),
                transition=confused, idle_hold=6)
    death_slots(sheet, n('death'), [3] * 7, first=[op(12, e_head, 0, -2, -44)])
    sheet.scripts[15] = charred_script(sheet, main)
    hit = [-10, -48, 20, 48, 0]
    return sheet, STRIDE * blocks + 2, hit, [bite_rect(hit)]


def build_imp(main, garg):
    sheet = Sheet()
    g = lambda name: seq(main, 'garg', name)
    walk, eat = g('imp_walk'), g('imp_eat')
    biter_block(sheet, 0, sway_idle(walk, 'imp_idle'), walk, 1, eat, 3, (3, 7), idle_hold=6,
                move_scale=MOVE_SCALE_BY_KIND['imp'])
    death_slots(sheet, g('imp_death'), [3] * 6)
    sheet.scripts[15] = charred_blink(sheet, [(SOURCE / 'gargantuar' / c['file'], int(c['ax']), int(c['ay']))
                                              for c in garg['imp_charred']])
    hit = [-7, -34, 14, 34, 0]
    return sheet, STRIDE, hit, [bite_rect(hit)]


def build_imp_flight(main, imp_sheet_tiles=None):
    """被投出的小鬼（基准 160 ParaTrooper，内部单位）：槽 8 飞行（op7 抛物线，帧展开不循环），槽 25 落地（空）。"""
    sheet = Sheet()
    fly = [sheet.f(*x) for x in seq(main, 'garg', 'imp_fly')]
    vx, vy, g, height = IMP_FLIGHT
    ticks = throw_ticks(height / 2.0, vy, g) + 30
    script = [op(3, 1), op(7, vx, vy, 0, g)]
    t = 0
    while t < ticks:
        script += F(fly[(t // 3) % len(fly)], 3)
        t += 3
    sheet.scripts[8] = script + [op(21)]
    sheet.scripts[25] = [op(0, -1), op(1, 2), op(21)]
    blank = [op(0, -1), op(1, 1), op(5)]
    for slot in range(34):
        if slot not in (8, 25):
            sheet.scripts[slot] = list(blank) if slot not in (13, 14, 15, 16, 17) else [op(0, -1), op(1, 1), op(21)]
    return sheet, 34, [-6, -30, 12, 30, 0], [[0, 0, 0, 0, 0]]


# 小鬼投出：op7 速度与重力（0.01/tick，验证时校准），起点高度与前移（世界坐标，行为 thrown_flight）。
IMP_FLIGHT = (420, -520, 40, 114)


def build_gargantuar(garg):
    sheet = Sheet()
    gs = lambda name: garg_seq(garg, name)
    impact = sum([3, 4, 4, 8, 2])
    for block, suffix in enumerate(('_imp', '_noimp')):
        walk = [sheet.f(*x) for x in gs('walk' + suffix)]
        smash = [sheet.f(*x) for x in gs('smash' + suffix)]
        # 待机（2026-10-15 用户指定）：素材表新增的两帧站立姿势交替（与行走第 9、10 号帧相同），取代此前的“呼吸”合成帧
        idle = [sheet.f(*x) for x in gs('idle' + suffix)]
        base = STRIDE * block
        sheet.scripts[base + 0] = loop(idle, [8] * len(idle))
        sheet.scripts[base + 1] = loop(walk, slow_holds(len(walk), 3, MOVE_SCALE_BY_KIND['gargantuar']))
        sheet.scripts[base + 2] = once(smash, [3, 4, 4, 8, 2, 12])
        sheet.scripts[base + 6] = loop(idle, [8] * len(idle), first=[op(3, 1)])
        sheet.scripts[base + 7] = loop(walk, slow_holds(len(walk), 3, MOVE_SCALE_BY_KIND['gargantuar']), first=[op(3, 1)])
        groan = SND['lowgroan'] if block == 0 else SND['lowgroan2']
        sheet.scripts[base + 9] = once(smash, [3, 4, 4, 8, 2, 12], first=[op(3, 1), op(23, groan)],
                                       events={5: [op(4, 1), op(23, SND['gargantuar_thump'])]},
                                       tail=[op(4, -1)])
        # 特殊攻击：后摆延长 12 tick、击地停留延长 8 tick，范围更大
        sheet.scripts[base + 10] = once(smash, [3, 4, 4, 20, 2, 20], first=[op(3, 1), op(23, groan)],
                                        events={5: [op(4, 2), op(23, SND['gargantuar_thump'])]},
                                        tail=[op(4, -1)])
        sheet.scripts[base + 11] = loop(walk[:1], [1], first=[op(3, 1)])
        sheet.scripts[base + 12] = once(walk[:1], [1], first=[op(3, 1)])
    throw = [sheet.f(*x) for x in gs('throw')]
    sheet.scripts[STRIDE + 12] = once(throw, [4, 5, 6, 3, 10], first=[op(3, 1)], events={4: [op(23, SND['imp'])]})
    death = gs('death')
    # 2026-10-15 用户要求：去掉开头的倒地音效（gargantudeath），在身体砸到地面的第 7 帧（s47，第 24 tick）播放锤击落地音效
    death_slots(sheet, death, [4, 4, 4, 4, 4, 4, 30], linger=20, events={6: [op(23, SND['gargantuar_thump'])]})
    sheet.scripts[15] = charred_blink(sheet, gs('charred'))
    del impact
    # 锤击框：普通锤击从受击框前缘向前覆盖 SMASH_RANGE + REACH_MARGIN（原 74 只比开锤距离多 4 像素）；重锤范围更大
    hit = [-18, -78, 36, 78, 0]
    smash = abs(hit[0]) + SMASH_RANGE + REACH_MARGIN
    return sheet, STRIDE * 2, hit, [[-smash, -44, smash, 44, 7], [-124, -54, 124, 54, 7]]


# ---------------------------------------------------------------- 冰车（2026-10-13 用户提出）
# 基准为原版雪地步兵 UnitID 182（BattleAction_ZakoSnow，推雪球的小兵）：出击即不被击退（changeStateNockbackGuard），
# 状态 10/20/30/40/50 都用槽 7 并持续前进（被前方单位挡住时停下），槽 7 开头的 op4 攻击框常驻，每帧对框内全部敌人
# （含据点）造成近距伤害（词 15）；状态 100/110 用槽 13（110 另加原生爆炸效果），120 用槽 15，播完后移除；状态 70 用槽 11 与 20。
# 该描述符以 +x 为前方（原版图块带水平翻转标记），PvZ 素材朝左，因此帧先水平翻转（锚点 x 改为 宽 − x）。
# 外观 5 档：完好、受损 1–4（素材第 1–4、7 行）；各档的行驶脚本展开为 60 帧（12 与 10 帧的公倍数），
# 命令结构相同，生命越档时就地换档（核心钩取 ZakoSnow::update 入口，同 ZombieBrain 的分档处理）。
# 被击毁（槽 13）：受损版翻覆的前 6 帧，随后车身消失，烟雾 9 帧与零件 4 帧在同一画面中同时开始播放，并播放爆炸音效；
# 零件第 5 格在素材中为空，零件播完 4 帧后消失，烟雾继续散开。被火焰击毁（槽 15）：冰车自带的焦黑剪影 5 帧（睁眼与闭眼交替）。
ZOMBONI_STAGES = ('drive', 'drive_d1', 'drive_d2', 'drive_d3', 'drive_d4')
ZOMBONI_CYCLE = 60
ZOMBONI_HOLD = 2
# 攻击框（碾压）：2026-10-14 用户认为碾压过强，要求按冰车 sprite 的范围设计（原为用户指定的宽 80、高 59，自锚点向前）。
# 原版雪地步兵的攻击框 (0,-54,62,59) 即其雪球图像的范围（雪球 x 4–66、y −48–0）；冰车同理取各档行驶帧不透明范围的并集，
# 在 build_zomboni 中计算（现为 x −30–29、y −54–8，即 [-30,-54,59,62]），类型 7 同雪球。
ZOMBONI_MIRROR = DERIVED / 'zomboni'
# 帧格底边比车轮低 4 像素（僵尸帧为 0–1 像素）。2026-10-13 用户两次反馈冰车位置太高：先上移锚点 4（车轮与锚点平齐），
# 用户再要求下压至少 8 像素，共上移 12（车轮低于锚点 8 个素材像素，屏幕上约 18 像素）。
# 冰车各帧（行驶、翻覆、烟雾、零件、焦黑）出自同一素材表、同以帧格底边为锚点，统一上移以保持相对位置。
ZOMBONI_GROUND = 12


def zomboni_seq(main, name):
    """冰车帧（水平翻转）：[(路径, ax, ay)]。翻转后的帧写在 source/derived/zomboni/。"""
    ZOMBONI_MIRROR.mkdir(parents=True, exist_ok=True)
    out = []
    for f in main['zomboni'][name]:
        src = SOURCE / f['file']
        img = Image.open(src).convert('RGBA')
        dst = ZOMBONI_MIRROR / src.name
        flipped = img.transpose(Image.FLIP_LEFT_RIGHT)
        if not dst.exists() or Image.open(dst).convert('RGBA').tobytes() != flipped.tobytes():
            flipped.save(dst)
        out.append((dst, int(round(img.width - f['ax'])), int(f['ay']) - ZOMBONI_GROUND))
    return out


def build_zomboni(main):
    sheet = Sheet()
    zs = lambda name: zomboni_seq(main, name)
    holds = [ZOMBONI_HOLD] * ZOMBONI_CYCLE
    first_crush = None
    extent = None     # 各档行驶帧不透明范围的并集（相对锚点），作为碾压攻击框
    for block, name in enumerate(ZOMBONI_STAGES):
        for path, ax, ay in zs(name):
            x0, y0, x1, y1 = Image.open(path).getbbox()
            box = (x0 - ax, y0 - ay, x1 - ax, y1 - ay)
            extent = box if extent is None else (min(extent[0], box[0]), min(extent[1], box[1]),
                                                 max(extent[2], box[2]), max(extent[3], box[3]))
        fr = [sheet.f(*x) for x in zs(name)]
        cyc = [fr[i % len(fr)] for i in range(ZOMBONI_CYCLE)]
        base = STRIDE * block
        # 战斗中只请求槽 7 与 11（状态 70 的首个动作）：这两槽展开为 60 帧，各档命令结构相同，可就地换档；
        # 其余槽（浏览与原生不请求的槽）用该档原长度的循环。
        crush = loop(cyc, holds, first=[op(3, 1), op(4, 1)])
        first_crush = first_crush or crush
        short = [ZOMBONI_HOLD] * len(fr)
        for slot in (0, 1, 2):
            sheet.scripts[base + slot] = loop(fr, short)
        sheet.scripts[base + 6] = loop(fr, short, first=[op(3, 1)])
        for slot in (9, 10, 12, 14):
            sheet.scripts[base + slot] = loop(fr, short, first=[op(3, 1), op(4, 1)])
        for slot in (7, 11):
            sheet.scripts[base + slot] = crush
    sheet.scripts[20] = first_crush          # 状态 70 的后续动作（原生请求槽 20，不分档）
    wreck = zs('wreck_d')
    smoke, parts = zs('smoke'), zs('debris')[:4]
    tilt = [sheet.f(*x) for x in wreck[:6]]
    boom = [sheet.frame([smoke[i] + (0, 0)] + ([parts[i] + (0, 0)] if i < len(parts) else [])) for i in range(len(smoke))]
    sheet.scripts[13] = once(tilt + boom, [2] * len(tilt) + [3] * len(boom), first=[op(4, -1), op(3, 1)],
                             events={len(tilt): [op(23, SND['explosion'])]}, tail=F(-1, 1))
    charred = [sheet.f(*x) for x in zs('charred')[:5]]
    sheet.scripts[15] = once(charred, [12, 4, 12, 4, 12], first=[op(4, -1), op(3, 1), op(23, SND['explosion'])],
                             tail=F(-1, 1))
    # 受击框：完好行驶帧的不透明范围（相对锚点），四边各收 2 像素
    path, ax, ay = zs('drive')[0]
    x0, y0, x1, y1 = Image.open(path).getbbox()
    hit = [x0 - ax + 2, y0 - ay + 2, x1 - x0 - 4, ay - y0 - 2, 0]
    attack = [extent[0], extent[1], extent[2] - extent[0], extent[3] - extent[1], 7]
    return sheet, STRIDE * len(ZOMBONI_STAGES), hit, [attack]


# ---------------------------------------------------------------- 头像（朝右，限于选单位格内框）
# 选单位格 unit.obm (362,151) 50×50：四边各 5 像素为边框，内框为格内坐标 x、y 5–44。原版头像的下沿均止于内框底行
# （337 个中 300 个下沿为 45），超出内框的部分不绘制。PvZ 单位的图像比原版高，按脚点放在格内后裁去内框以外的部分。
ICON_INNER = (5, 5, 45, 45)
# 单位 → (帧, 脚点在格内的坐标)。普通、路障、铁桶、读报为同一行走帧（序号 0）、同一脚点，只有头饰与报纸不同；
# 脚点 y=58 时路障顶端在内框之上 2 行，四者的小腿以下被下边框挡住。
ICON_FRAME = 0
ICON_LAYOUT = {
    'zombie': (('zombie', 'walk'), (23, 58)),
    'cone': (('cone', 'walk'), (23, 58)),
    'bucket': (('bucket', 'walk'), (23, 58)),
    'newspaper': (('newspaper', 'walk'), (23, 58)),
    'football': (('football', 'run'), (22, 58)),
    'imp': (('garg', 'imp_walk'), (24, 45)),          # 小鬼全身，站在内框底行（与原版头像相同）
    'gargantuar': (('gargantuar', 'walk_imp'), (16, 80)),   # 头部与背上的小鬼
    'zomboni': (('zomboni', 'drive'), (31, 74)),            # 驾驶员的头与冰车前部（车身下部被下边框挡住）
}


def icon_of(path, ax, ay, foot):
    """帧按脚点放入 50×50 格（朝右），裁去内框以外的部分；返回 (图像, 格内左上角)。"""
    img = Image.open(path).convert('RGBA').transpose(Image.FLIP_LEFT_RIGHT)
    layer = Image.new('RGBA', (50, 50), (0, 0, 0, 0))
    layer.paste(img, (foot[0] - (img.width - ax), foot[1] - ay), img)
    inner = layer.crop(ICON_INNER)
    box = inner.getbbox()
    return inner.crop(box), (ICON_INNER[0] + box[0], ICON_INNER[1] + box[1])


def build_icons(main, garg):
    icons = {}
    for key, ((unit, anim), foot) in ICON_LAYOUT.items():
        frame = garg_seq(garg, anim)[ICON_FRAME] if unit == 'gargantuar' else seq(main, unit, anim)[ICON_FRAME]
        icons[key] = icon_of(*frame, foot)
    order = ('zombie', 'cone', 'bucket', 'newspaper', 'football', 'gargantuar', 'imp', 'zomboni')
    width = sum(icons[k][0].width + 2 for k in order)
    page = Image.new('RGBA', (256 if width <= 256 else 512, 64), (0, 0, 0, 0))   # 加入冰车后为 512 宽，已有头像位置不变
    rects = {}
    x = 0
    for key in order:
        img, (cx, cy) = icons[key]
        assert x + img.width <= page.width, key
        page.paste(img, (x, 0))
        rects[key] = ([x, 0, img.width, img.height], [-cx, -cy])
        x += img.width + 2
    return page, rects


# ---------------------------------------------------------------- 文字（简中、繁中、日、英、西、葡、韩；其余语言由加载器以英语补全）
TEXT = {
    'zombie': {
        'ZS': ('普通僵尸', '普通攻击：啃咬     特殊攻击：啃咬\n最常见的僵尸。\n生命低于一半时会掉下一条手臂。'),
        'ZT': ('普通殭屍', '普通攻擊：啃咬     特殊攻擊：啃咬\n最常見的殭屍。\n生命低於一半時會掉下一條手臂。'),
        'JP': ('ゾンビ', '通常攻撃：かみつき     特殊攻撃：かみつき\nごく普通のゾンビ。\n体力が半分を切ると腕が取れる。'),
        'EN': ('ZOMBIE', 'Normal attack: Bite     Special attack: Bite\nYour regular, garden-variety zombie.\nLoses an arm below half HP.'),
        'ES': ('ZOMBI', 'Ataque normal: Mordisco     Ataque especial: Mordisco\nUn zombi común y corriente.\nPierde un brazo con menos de la mitad de vida.'),
        'PT': ('ZUMBI', 'Ataque normal: Mordida     Ataque especial: Mordida\nUm zumbi comum.\nPerde um braço abaixo de metade da vida.'),
        'KR': ('좀비', '일반 공격：물기     특수 공격：물기\n흔히 볼 수 있는 평범한 좀비.\n체력이 절반 아래가 되면 팔이 떨어진다.'),
    },
    'cone': {
        'ZS': ('路障僵尸', '普通攻击：啃咬     特殊攻击：啃咬\n头戴路障的僵尸。\n路障被打掉后与普通僵尸相同。'),
        'ZT': ('路障殭屍', '普通攻擊：啃咬     特殊攻擊：啃咬\n頭戴路障的殭屍。\n路障被打掉後與普通殭屍相同。'),
        'JP': ('コーンヘッドゾンビ', '通常攻撃：かみつき     特殊攻撃：かみつき\nコーンをかぶったゾンビ。\nコーンが外れると普通のゾンビと同じになる。'),
        'EN': ('CONEHEAD ZOMBIE', 'Normal attack: Bite     Special attack: Bite\nA zombie wearing a traffic cone.\nSame as a regular zombie once the cone is knocked off.'),
        'ES': ('ZOMBI CON CONO', 'Ataque normal: Mordisco     Ataque especial: Mordisco\nUn zombi con un cono en la cabeza.\nSin el cono es igual a un zombi común.'),
        'PT': ('ZUMBI CONE', 'Ataque normal: Mordida     Ataque especial: Mordida\nUm zumbi com um cone na cabeça.\nSem o cone é igual a um zumbi comum.'),
        'KR': ('라바콘 좀비', '일반 공격：물기     특수 공격：물기\n라바콘을 쓴 좀비.\n라바콘이 떨어지면 평범한 좀비와 같다.'),
    },
    'bucket': {
        'ZS': ('铁桶僵尸', '普通攻击：啃咬     特殊攻击：啃咬\n头戴铁桶的僵尸，非常耐打。\n铁桶被打掉后与普通僵尸相同。'),
        'ZT': ('鐵桶殭屍', '普通攻擊：啃咬     特殊攻擊：啃咬\n頭戴鐵桶的殭屍，非常耐打。\n鐵桶被打掉後與普通殭屍相同。'),
        'JP': ('バケツヘッドゾンビ', '通常攻撃：かみつき     特殊攻撃：かみつき\nバケツをかぶったタフなゾンビ。\nバケツが外れると普通のゾンビと同じになる。'),
        'EN': ('BUCKETHEAD ZOMBIE', 'Normal attack: Bite     Special attack: Bite\nA zombie wearing a metal bucket. Very tough.\nSame as a regular zombie once the bucket is knocked off.'),
        'ES': ('ZOMBI CUBO', 'Ataque normal: Mordisco     Ataque especial: Mordisco\nUn zombi con un cubo de metal. Muy resistente.\nSin el cubo es igual a un zombi común.'),
        'PT': ('ZUMBI BALDE', 'Ataque normal: Mordida     Ataque especial: Mordida\nUm zumbi com um balde de metal. Muito resistente.\nSem o balde é igual a um zumbi comum.'),
        'KR': ('양동이 좀비', '일반 공격：물기     특수 공격：물기\n철 양동이를 쓴 튼튼한 좀비.\n양동이가 떨어지면 평범한 좀비와 같다.'),
    },
    'newspaper': {
        'ZS': ('读报僵尸', '普通攻击：啃咬     特殊攻击：啃咬\n一边走一边读报纸的僵尸。\n报纸被打掉后会愣住，随后狂暴。'),
        'ZT': ('讀報殭屍', '普通攻擊：啃咬     特殊攻擊：啃咬\n邊走邊讀報紙的殭屍。\n報紙被打掉後會愣住，隨後狂暴。'),
        'JP': ('新聞ゾンビ', '通常攻撃：かみつき     特殊攻撃：かみつき\n新聞を読みながら歩くゾンビ。\n新聞を破られると一瞬止まり、その後激怒する。'),
        'EN': ('NEWSPAPER ZOMBIE', 'Normal attack: Bite     Special attack: Bite\nReads the paper while walking.\nStunned when the paper is destroyed, then goes into a rage.'),
        'ES': ('ZOMBI LECTOR', 'Ataque normal: Mordisco     Ataque especial: Mordisco\nLee el periódico mientras camina.\nSi le destruyen el periódico se aturde y luego se enfurece.'),
        'PT': ('ZUMBI JORNAL', 'Ataque normal: Mordida     Ataque especial: Mordida\nLê o jornal enquanto anda.\nFica atordoado quando o jornal é destruído e depois se enfurece.'),
        'KR': ('신문 좀비', '일반 공격：물기     특수 공격：물기\n신문을 읽으며 걷는 좀비.\n신문이 찢어지면 잠시 멈췄다가 분노한다.'),
    },
    'football': {
        'ZS': ('橄榄球僵尸', '普通攻击：啃咬     特殊攻击：啃咬\n身穿橄榄球护具的僵尸。\n移动非常快，头盔十分坚固。'),
        'ZT': ('橄欖球殭屍', '普通攻擊：啃咬     特殊攻擊：啃咬\n身穿橄欖球護具的殭屍。\n移動非常快，頭盔十分堅固。'),
        'JP': ('アメフトゾンビ', '通常攻撃：かみつき     特殊攻撃：かみつき\nアメフトの防具を着たゾンビ。\n動きがとても速く、ヘルメットは非常に頑丈。'),
        'EN': ('FOOTBALL ZOMBIE', 'Normal attack: Bite     Special attack: Bite\nA zombie in football gear.\nVery fast, with a very sturdy helmet.'),
        'ES': ('ZOMBI FUTBOLISTA', 'Ataque normal: Mordisco     Ataque especial: Mordisco\nUn zombi con equipo de fútbol americano.\nMuy rápido y con un casco muy resistente.'),
        'PT': ('ZUMBI JOGADOR', 'Ataque normal: Mordida     Ataque especial: Mordida\nUm zumbi com equipamento de futebol americano.\nMuito rápido e com um capacete muito resistente.'),
        'KR': ('미식축구 좀비', '일반 공격：물기     특수 공격：물기\n미식축구 보호구를 입은 좀비.\n매우 빠르고 헬멧이 아주 단단하다.'),
    },
    'gargantuar': {
        'ZS': ('巨人僵尸', '普通攻击：锤击     特殊攻击：重锤\n扛着电线杆的巨大僵尸。\n生命低于一半时会把背上的小鬼扔出去。'),
        'ZT': ('巨人殭屍', '普通攻擊：錘擊     特殊攻擊：重錘\n扛著電線桿的巨大殭屍。\n生命低於一半時會把背上的小鬼扔出去。'),
        'JP': ('ガルガンチュア', '通常攻撃：たたきつけ     特殊攻撃：強烈なたたきつけ\n電柱をかついだ巨大なゾンビ。\n体力が半分を切ると背中のインプを投げる。'),
        'EN': ('GARGANTUAR', 'Normal attack: Smash     Special attack: Heavy smash\nA giant zombie wielding a telephone pole.\nThrows the imp on its back below half HP.'),
        'ES': ('GARGANTÚA', 'Ataque normal: Golpe     Ataque especial: Golpe pesado\nUn zombi gigante armado con un poste.\nLanza al diablillo de su espalda con menos de la mitad de vida.'),
        'PT': ('GIGANTE', 'Ataque normal: Pancada     Ataque especial: Pancada pesada\nUm zumbi gigante armado com um poste.\nArremessa o diabinho das costas abaixo de metade da vida.'),
        'KR': ('거대 좀비', '일반 공격：내려치기     특수 공격：강하게 내려치기\n전봇대를 든 거대한 좀비.\n체력이 절반 아래가 되면 등에 업은 꼬마 좀비를 던진다.'),
    },
    'imp': {
        'ZS': ('小鬼僵尸', '普通攻击：啃咬     特殊攻击：啃咬\n个子小、动作快的僵尸。\n常被巨人僵尸扔到敌阵之中。'),
        'ZT': ('小鬼殭屍', '普通攻擊：啃咬     特殊攻擊：啃咬\n個子小、動作快的殭屍。\n常被巨人殭屍扔到敵陣之中。'),
        'JP': ('インプ', '通常攻撃：かみつき     特殊攻撃：かみつき\n小さくてすばやいゾンビ。\nよくガルガンチュアに投げ込まれる。'),
        'EN': ('IMP', 'Normal attack: Bite     Special attack: Bite\nA small and quick zombie.\nOften thrown into enemy lines by a Gargantuar.'),
        'ES': ('DIABLILLO', 'Ataque normal: Mordisco     Ataque especial: Mordisco\nUn zombi pequeño y rápido.\nA menudo un Gargantúa lo lanza entre las filas enemigas.'),
        'PT': ('DIABINHO', 'Ataque normal: Mordida     Ataque especial: Mordida\nUm zumbi pequeno e rápido.\nMuitas vezes é arremessado pelo Gigante no meio do inimigo.'),
        'KR': ('꼬마 좀비', '일반 공격：물기     특수 공격：물기\n작고 재빠른 좀비.\n거대 좀비가 적진에 자주 던져 넣는다.'),
    },
}
TEXT['zomboni'] = {
    'ZS': ('冰车僵尸', '普通攻击：碾压     特殊攻击：-\n驾驶冰车的僵尸，碾压前方的所有敌人。\n不会被击退，被击毁时冰车会爆炸。'),
    'ZT': ('冰車殭屍', '普通攻擊：碾壓     特殊攻擊：-\n駕駛冰車的殭屍，碾壓前方的所有敵人。\n不會被擊退，被擊毀時冰車會爆炸。'),
    'JP': ('ゾンボーニ', '通常攻撃：ひき潰し     特殊攻撃：-\n製氷車を運転するゾンビ。前方の敵をまとめてひき潰す。\nノックバックせず、倒されると製氷車が爆発する。'),
    'EN': ('ZOMBONI', 'Normal attack: Crush     Special attack: -\nDrives an ice resurfacer, crushing all enemies ahead.\nNever knocked back; explodes when destroyed.'),
    'ES': ('ZOMBONI', 'Ataque normal: Aplastar     Ataque especial: -\nConduce una pulidora de hielo y aplasta a todos los enemigos delante.\nNo retrocede al recibir golpes; explota al ser destruido.'),
    'PT': ('ZOMBONI', 'Ataque normal: Esmagar     Ataque especial: -\nDirige uma máquina de gelo e esmaga todos os inimigos à frente.\nNão recua ao ser atingido; explode ao ser destruído.'),
    'KR': ('좀보니', '일반 공격：깔아뭉개기     특수 공격：-\n제빙차를 몰며 앞에 있는 적을 모두 깔아뭉갠다.\n밀려나지 않으며, 파괴되면 제빙차가 폭발한다.'),
}
TEXT['imp_flight'] = TEXT['imp']


# ---------------------------------------------------------------- 数值（Lv40 为用户给出的第一版数值；其他等级按僵尸（青年）曲线）
# 生命以僵尸（青年）Lv40 3400 为基准倍率；伤害以其普攻 600 为基准（每口 60 = 1/10）。
# AP 由用户给出或取 PvZ 一代 brain cost；再出击时间与勋章价格为用户 2026-10-12 指定值。
UNITS = {
    # 稳定键后缀: (AP, 生命倍率, 伤害倍率, 绝招伤害追加, 移速倍率, 再出击 tick, 勋章, 档位, 过渡, 狂暴档)
    'zombie': dict(ap=50, hp=[5, 1], dmg=[1, 10], move=[1, 1], interval=80, price=20,
                   thresholds=[[1, 2]], transitions=[1]),
    'cone': dict(ap=75, hp=[15, 2], dmg=[1, 10], move=[1, 1], interval=100, price=30,
                 thresholds=[[8, 9], [7, 9], [2, 3], [1, 3]], transitions=[0, 0, 1, 1],
                 armor=([SND['plastichit'], SND['plastichit2']], 3)),
    'bucket': dict(ap=125, hp=[10, 1], dmg=[1, 10], move=[1, 1], interval=120, price=40,
                   thresholds=[[5, 6], [2, 3], [1, 2], [1, 4]], transitions=[0, 0, 1, 1],
                   armor=([SND['shieldhit'], SND['shieldhit2']], 3)),
    # 读报：本体 7500 + 报纸 7500（修订七），报纸受损两档在报纸失去 1/3、2/3 时，狂暴在只剩本体（1/2）时；
    # 狂暴后移速 4.02、伤害 ×3/2（300 → 450）。
    'newspaper': dict(ap=175, hp=[10, 1], dmg=[1, 10], move=[1, 1], interval=200, price=90,
                      thresholds=[[5, 6], [2, 3], [1, 2]], transitions=[0, 0, 1], rage=(3, [5, 2]), rage_damage=[3, 2]),
    # 橄榄球：本体 7500 + 头盔 10500（修订七；头盔受损两档在头盔失去 1/3、2/3 时，掉头盔在 5/12 时）；
    # 移速 ×4/5 写在 MOVE_SCALE_BY_KIND。
    'football': dict(ap=225, hp=[12, 1], dmg=[1, 10], move=[3, 1], interval=250, price=130,
                     thresholds=[[29, 36], [11, 18], [5, 12]], transitions=[0, 0, 1],
                     armor=([SND['plastichit'], SND['plastichit2']], 3)),
    # 巨人（2026-10-15 用户指定，重新启用）：生命 Lv40 30000（UNITS 的 hp 经 HP_SCALE 换算为 [150,17]，僵尸（青年）3400 ×
    # 150/17）、每锤 2100（普攻 600 × 7/2）、取消绝招、AP 350、再出击时间为冰车（210 tick）的 2.5 倍 525 tick
    # （650 × 21/26，各等级相同）。勋章价格与移速保持。同日再修订：再出击时间延长 50%，650 × 63/52 = 787.5 向上取整 788 tick；
    # 生命 Lv40 30000 → 20000（hp [20,1] → [40,3]，经 HP_SCALE 为 [100,17]，3400 × 100/17），移速见 MOVE_SCALE_BY_KIND。
    'gargantuar': dict(ap=350, hp=[40, 3], dmg=[7, 2], move=[4, 5], interval_ratio=[63, 52], price=250,
                       thresholds=[[1, 2]], transitions=[1], throw=1),
    'imp': dict(ap=50, hp=[3, 1], dmg=[1, 15], move=[11, 5], interval=60, price=30),
}
ORDER = ['zombie', 'cone', 'bucket', 'newspaper', 'football', 'gargantuar', 'imp', 'imp_flight', 'zomboni']
BITE_RANGE = 24          # 状态词 7：开始啃咬的距离（验证时校准）
# 巨人开始锤击的距离。2026-10-15 用户认为锤击范围过大，要求缩小到原来的 2/3：锤击框伸出自身受击框前缘的长度
# SMASH_RANGE + REACH_MARGIN 由 60 改为 40（开锤距离 52 → 32，锤击框 x 由 −78 改为 −58），纵向不变。
SMASH_RANGE = 32
# 攻击判定框（2026-10-13 修订）：原生在双方受击框前缘的间距小于状态词 7 时停下攻击
# （BattleObjectManager::getNearEnemyDistance = 中心距 − 双方 getWidthSize；getWidthSize 为首个 op3 受击框 |x|，
# BattleSprite::setObjectSize）。攻击框须从本身受击框前缘向前覆盖这段距离再加余量，否则停在远处的目标
# （如受击框小于外观的远程坦克）咬不到。纵向覆盖到地面，矮小目标同样命中。
REACH_MARGIN = 8


def bite_rect(hit):
    """啃咬攻击框：从受击框前缘向前 BITE_RANGE + REACH_MARGIN，纵向自受击框顶下 8 像素至地面。"""
    x0 = -(abs(hit[0]) + BITE_RANGE + REACH_MARGIN)
    y0 = hit[1] + 8
    return [x0, y0, -x0, -y0, 7]
THROW_RELEASE_TICK = 18  # 投掷动作第 5 帧（4+5+6+3）


def unit_file(kind, icon, texture, descriptor, animations):
    key = S + 'pvz_' + kind
    text = {code: {'name': n, 'description': no_special(d)} for code, (n, d) in TEXT[kind].items()}
    if kind == 'imp_flight':
        return {
            'key': key, 'base_id': 160, 'faction': 3, 'identity': 'Zombie', 'shop_price': 10,
            'available_from_start': True, 'ap': 50, 'hp_multiplier': [100, 1],
            'knockback_threshold_multiplier': [100, 1], 'production_reference_id': 160,
            'production_interval_multiplier': [1, 1], 'special_damage_multiplier': [1, 1],
            'icon': icon, 'textures': [texture], 'sprite_descriptor': descriptor, 'animations': animations,
            'localization': text, 'menu_reference_id': 159, 'internal_only': True,
            'behaviors': [{'name': 'para_drop_transform', 'version': 1, 'params': {'landing_unit': S + 'pvz_imp'}},
                          {'name': 'thrown_flight', 'version': 1,
                           'params': {'forward': 56, 'height': IMP_FLIGHT[3]}}],
        }
    v = UNITS[kind]
    smash = kind == 'gargantuar'
    targets = 999 if smash else 1
    words = {'7': SMASH_RANGE if smash else BITE_RANGE, '24': targets, '31': targets, '27': 1, '34': 1}
    words.update({'29': 0, '35': 0, '36': 0})         # 无绝招：伤害与两个冷却为 0（同原版无绝招单位；巨人 2026-10-15 起同样取消）
    # 被投出的小鬼落到对方前线之后时，攻击距离与阻挡改以前方最近的对方单位计算（2026-10-13 修订三，避免无限啃食）
    behaviors = [{'name': 'front_nearest_target', 'version': 1, 'params': {}}]
    if smash:
        behaviors.insert(0, {'name': 'no_knockback', 'version': 1, 'params': {}})   # 巨人无击退（修订四保持）
    elif 'thresholds' in v:
        # 受击时播放该档的槽 14，不重播过渡（2026-10-13 修订四恢复击退）
        behaviors.append({'name': 'stage_knockback_animation', 'version': 1, 'params': {}})
    if 'thresholds' in v:
        params = {'thresholds': v['thresholds'], 'transitions': v['transitions']}
        if 'rage' in v:
            # 狂暴提高移速；修订四起伤害 ×3/2（每口 300 → 450）
            # 狂暴倍率作用于已换算的移速；按两档移速比例换算，使狂暴后的速度保持只 ×MOVE_SCALE 时的值（4.02）
            kind_scale = MOVE_SCALE_BY_KIND.get(kind, MOVE_SCALE)
            rage = scaled(v['rage'][1], (kind_scale[1] * MOVE_SCALE[0], kind_scale[0] * MOVE_SCALE[1]))
            params.update(rage_stage=v['rage'][0], rage_speed_multiplier=rage)
            if 'rage_damage' in v:
                params['rage_damage_multiplier'] = v['rage_damage']
        behaviors.insert(0, {'name': 'hp_stage_animations', 'version': 1, 'params': params})
    if 'armor' in v:
        behaviors.append({'name': 'armor_hit_sound', 'version': 1, 'params': {'sounds': v['armor'][0], 'until_stage': v['armor'][1]}})
    if not smash:
        behaviors.append({'name': 'kill_sound', 'version': 1, 'params': {'sound': SND['gulp']}})
    if 'throw' in v:
        behaviors.append({'name': 'throw_child_on_stage', 'version': 1,
                          'params': {'unit': S + 'pvz_imp_flight', 'stage': v['throw'], 'release_tick': THROW_RELEASE_TICK}})
    hp = scaled(v['hp'], HP_SCALE)
    threshold = KNOCKBACK_THRESHOLD.get(kind, KNOCKBACK_THRESHOLD_DEFAULT) or hp
    unit = {
        'key': key, 'base_id': 313, 'faction': 3, 'identity': 'Zombie',
        'shop_price': v['price'], 'available_from_start': True, 'ap': v['ap'],
        'hp_multiplier': hp, 'knockback_threshold_multiplier': threshold,
        'production_reference_id': 313,
        'production_interval_multiplier': v.get('interval_ratio') or reduce_ratio(
            v['interval'] * INTERVAL_SCALE.get(kind, INTERVAL_SCALE_DEFAULT)[0], 650 * INTERVAL_SCALE.get(kind, INTERVAL_SCALE_DEFAULT)[1]),
        'damage_multiplier': scaled(v['dmg'], DMG_SCALE.get(kind, DMG_SCALE_DEFAULT)),
        'special_damage_multiplier': v.get('special', [1, 1]),    # 加载器必需字段；无绝招单位词 29 已为 0
        'move_speed_multiplier': scaled(v['move'], MOVE_SCALE_BY_KIND.get(kind, MOVE_SCALE)), 'knockback_distance_multiplier': [1, 1],
        'status_word_values': words,
        'icon': icon, 'textures': [texture], 'sprite_descriptor': descriptor, 'animations': animations,
        'localization': text, 'tags': ['pvz'], 'behaviors': behaviors,
    }
    return unit


# 冰车（2026-10-13 用户指定）：生命 Lv40 15000（雪地步兵 3600 × 25/6；2026-10-14 用户认为过强，由 24000 即 × 20/3 下调）、移速为橄榄球的 2/3（2.6 × 1608/1625 = 2.5728，
# 两者实测每 tick 位移均等于移速值）、AP 250、勋章 250、再出击时间为橄榄球的 5/4（2026-10-13 实测后修订，
# 原为基寇卡原版 750 tick；橄榄球 650 × 67/260 = 167.5 → 168 tick，冰车 650 × 67/208 = 209.375 → 210 tick）、
# 碾压每秒 1200（词 15 Lv40 每帧 6 × 20/3 = 40；2026-10-15 用户要求减半，原为 40/3、每秒 2400）、攻击框为车体图像范围（见 build_zomboni）。击退门槛按第 6.1 节随生命倍率；
# 雪地步兵的动作类出击即不被击退，门槛实际不使用。受击时播放金属音效（用户 2026-10-12：shieldhit 用于铁桶与冰车）。
ZOMBONI = dict(ap=250, price=250, hp=[25, 6], dmg=[20, 3], move=[1608, 1625],
               thresholds=[[4, 5], [3, 5], [2, 5], [1, 5]], armor=([SND['shieldhit'], SND['shieldhit2']], 5))


def unit_file_zomboni(icon, texture, descriptor, animations):
    v = ZOMBONI
    return {
        'key': S + 'pvz_zomboni', 'base_id': 182, 'faction': 3, 'identity': 'Zombie',
        'shop_price': v['price'], 'available_from_start': True, 'ap': v['ap'],
        'hp_multiplier': v['hp'], 'knockback_threshold_multiplier': v['hp'],
        'production_reference_id': 313,
        'production_interval_multiplier': reduce_ratio(UNITS['football']['interval'] * INTERVAL_SCALE['football'][0] * 5,
                                                       650 * INTERVAL_SCALE['football'][1] * 4),
        'damage_multiplier': v['dmg'], 'special_damage_multiplier': [1, 1],
        'move_speed_multiplier': v['move'], 'knockback_distance_multiplier': [1, 1],
        'icon': icon, 'textures': [texture], 'sprite_descriptor': descriptor, 'animations': animations,
        'localization': {code: {'name': n, 'description': d} for code, (n, d) in TEXT['zomboni'].items()},
        'tags': ['pvz'],
        'behaviors': [
            {'name': 'hp_stage_animations', 'version': 1,
             'params': {'thresholds': v['thresholds'], 'transitions': [0] * len(v['thresholds'])}},
            {'name': 'armor_hit_sound', 'version': 1, 'params': {'sounds': v['armor'][0], 'until_stage': v['armor'][1]}},
            # 2026-10-15：以爆炸属性击毁时不生成原生雪地步兵的血色效果 0xff01（状态 110 按 100 处理）
            {'name': 'no_death_splash', 'version': 1, 'params': {}},
        ],
    }


def no_special(desc):
    """说明首行的特殊攻击写为“-”（原版无绝招单位的写法，如 SCIENTIST (ZOMBIE)：SPEC. ATK : -）。"""
    first, rest = desc.split('\n', 1)
    normal, special = first.split('     ')
    sep = '：' if '：' in special else ':'
    return normal + '     ' + special.split(sep, 1)[0] + sep + ('-' if sep == '：' else ' -') + '\n' + rest


def reduce_ratio(a, b):
    from math import gcd
    g = gcd(a, b)
    return [a // g, b // g]


def save_json(path, data):
    path.write_bytes((json.dumps(data, ensure_ascii=False, indent=2) + '\n').replace('\n', '\r\n').encode('utf-8'))


def main():
    main_anims, garg = anims()
    copy_sources(main_anims, garg)
    OUT.mkdir(exist_ok=True)
    builders = {
        'zombie': lambda: build_zombie_family(main_anims, 'zombie'),
        'cone': lambda: build_zombie_family(main_anims, 'cone'),
        'bucket': lambda: build_zombie_family(main_anims, 'bucket'),
        'newspaper': lambda: build_newspaper(main_anims),
        'football': lambda: build_football(main_anims),
        'gargantuar': lambda: build_gargantuar(garg),
        'imp': lambda: build_imp(main_anims, garg),
        'imp_flight': lambda: build_imp_flight(main_anims),
        'zomboni': lambda: build_zomboni(main_anims),
    }
    icon_page, icon_rects = build_icons(main_anims, garg)
    files, report = {}, {}
    # 头像页与原版 unit_icon_02 相同采用 RGBA32（战斗出兵格在 CPU 端按 32 位像素合成头像）。
    files[ICON_ATLAS] = b'OI ' + struct.pack('<HH', *icon_page.size) + icon_page.convert('RGBA').tobytes()
    icon_page.save(OUT / 'pvz_icons.png')
    index = json.loads((CONTENT / 'content.json').read_text(encoding='utf-8'))
    next_id = max(index['unit_ids'].values()) + 1
    for kind in ORDER:
        sheet, count, hit, attacks = builders[kind]()
        if kind != 'imp_flight':
            # 槽 8（僵尸（青年）的动作类不使用）：只由 C++ 行为播放的音效（防具受击、击毙）。原生开战预载
            # BattleSpriteFactory::readSounds 逐个脚本扫描到 op5/op21 为止，对其中 op23 调用 loadSound；该槽不会被播放。
            spec = ZOMBONI if kind == 'zomboni' else UNITS[kind]
            behavior_sounds = list(spec.get('armor', ([], 0))[0]) + ([SND['gulp']] if kind not in ('gargantuar', 'zomboni') else [])
            if behavior_sounds:
                sheet.scripts[8] = [op(23, k) for k in behavior_sounds] + [op(21)]
        obm, desc, animations, page = finish(sheet, count, hit, attacks)
        texture, descriptor = f'pvz_{kind}.obm', f'pvz_{kind}_descriptor.json'
        files[texture] = obm
        save_json(CONTENT / descriptor, desc)
        page.save(OUT / f'pvz_{kind}_atlas.png')
        icon_kind = 'imp' if kind == 'imp_flight' else kind
        rect, anchor = icon_rects[icon_kind]
        icon = {'atlas': ICON_ATLAS, 'rect': rect, 'anchor': anchor}
        unit = (unit_file_zomboni if kind == 'zomboni' else lambda *a: unit_file(kind, *a))(icon, texture, descriptor, animations)
        save_json(CONTENT / 'units' / f'pvz_{kind}.json', unit)
        key = unit['key']
        if key not in index['unit_ids']:
            index['unit_ids'][key] = next_id
            next_id += 1
        report[kind] = {'atlas': list(page.size), 'tiles': len(sheet.tiles), 'rects': len(desc['rects']),
                        'frame_words': len(desc['frames']), 'scripts': count}
    for name, raw in files.items():
        (CONTENT / name).write_bytes(raw)
        index['assets'][name] = hashlib.blake2b(raw, digest_size=32).hexdigest()
    sounds = [e for e in index.get('sounds', []) if not e['key'].startswith(S + 'pvz_')]
    for name, key in SND.items():
        target = f'pvz_{name}.msdf'
        shutil.copyfile(SOUND_FILES.get(name, SOUND_SOURCE / f'{name}.ogg'), CONTENT / target)
        entry = {'key': key, 'file': target, 'type': SOUND_TYPE.get(name, 'se')}
        if name in SOUND_GAIN:
            entry['gain'] = SOUND_GAIN[name]
        sounds.append(entry)
    index['sounds'] = sounds
    save_json(CONTENT / 'content.json', index)
    report['idle'] = IDLE_REPORT
    (OUT / 'build_report.json').write_text(json.dumps(report, ensure_ascii=False, indent=2), encoding='utf-8')
    print(json.dumps(report, ensure_ascii=False))


if __name__ == '__main__':
    main()
