"""巨型 Hunter Walker（s1xlv.giant_hunter_walker）资源与单位文件生成（2026-10-17）。

素材：source/MS6_Giant_Hunter_Walker.png（《合金弹头6》，The Spriters Resource，Division 6 / A Japanese Soldier 整理），
由 cut_frames.py 切帧并计算锚点（frames/、frames.json）。复用 PvZ 生成脚本的 Sheet、finish 与动作片段工具。

基准为原版僵尸（青年）UnitID 313（BattleAction_ZombieBrain：状态 10/20/40/50/70/80/100·110/120 依次使用槽
6/7/9/10/11/12/13/15；槽 0–2 为菜单用的待机、行走与攻击）。该动作类按脚本 op22[弹体槽, 命中槽, x, y] 发射弹体；
弹体（BulletAction_ZombieBrain）的轨迹由弹体槽的 op7 决定（僵尸（青年）的弹体速度相关状态词 25/26/32/33 为 0），
命中目标后进入状态 60 播放槽 21、落地后进入状态 61 播放槽 22，播放完毕即消失。素材朝左（前方为 −x，眼睛在左侧）。

用户设定（2026-10-17）：再出击 2400 tick（R6 改为 1350 tick，即 45 秒）；绝招冷却 2000 tick，出场后第一次为其 2/3（1333 tick）；不召唤、不留尸体墙，
死亡倒下后消失。R3（同日）：射程改为 MSA 的数值（普攻 700、绝招 800），普攻吐 5 颗卵、绝招 10 颗，每颗卵 Lv40 1000，
AP 650（R6 改为 400），Lv40 生命 30000（R1/R2 为 3 颗与 5 颗、落点 200–350 与 200–450、AP 500、生命 24000、每颗 800）。
其余数值为暂定（见 PROVISIONAL）。

运行：windows_runtime/python.exe artwork/giant_hunter_walker_20261017/build_giant_hunter_walker.py
（写入 community_content/ 与本目录 out/；头像写入 community_content/unit_icon_02.obm 的空位；音效从 source/sounds/
复制为 community_content/ghw_*.msdf 并登记在 content.json 的 sounds，见 SOUNDS）。
"""
from pathlib import Path
import hashlib
import json
import shutil
import struct
import sys

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[1]
sys.path.insert(0, str(REPO / 'artwork' / 'pvz_zombies_20261012'))
import build_pvz_zombies as pvz  # noqa: E402
from build_pvz_zombies import F, op, loop, once  # noqa: E402
from PIL import Image  # noqa: E402

CONTENT = REPO / 'community_content'
FRAMES = HERE / 'frames'
OUT = HERE / 'out'
DATA = json.loads((HERE / 'frames.json').read_text(encoding='utf-8'))

KEY = 's1xlv.giant_hunter_walker'
TEXTURE, DESCRIPTOR = 'giant_hunter_walker.obm', 'giant_hunter_walker_descriptor.json'
ICON_ATLAS = 'unit_icon_02.obm'
# 头像（R6，2026-10-18）：同 MSA 出兵栏的取景。MSA 头像（https://www.youtube.com/watch?v=ixG0urjAp20 ，226 秒）与
# 水平翻转的待机第 1 帧按 1:1 比对，最佳位置为翻转帧的 (61,34) 起 40×40（与窗口大小 32–60 像素的其他组合比较），
# 恰为选单位格内框大小，放在格内 (5,5)（锚点 −5,−5）。R1–R5 为待机帧整体缩小的占位（46×46），写入前清除该区域。
ICON_AT, ICON_SIZE, ICON_ANCHOR = (1490, 768), 40, [-5, -5]
ICON_CROP = (61, 34)          # 翻转后的待机第 1 帧中的裁切起点
ICON_CLEAR = 46               # R1–R5 占位头像占用的区域（46×46）
# 音效（2026-10-17 R4）：取自《合金弹头6》第 5 关音效库（MS6_OST_ST05.osb，manatools 转出的 WAV，source/sounds/ 为其 Ogg Vorbis）。
# MSD 的 OgA/OgB/OgE/OgF/Oguro 音效与 MS6 的 OGA/OGB/OGE/OGF/OGR 逐一相同（Hunter Walker、Crab Tank 等），OGC 与 FALLBOMB
# 未被 MSD 使用，为巨型 Hunter Walker 及其卵弹的音效；吐卵音（OGC_LAUNCHER）经 MSA 视频比对确认在每次吐卵时出现。
# 音量与 MSD 收录的同源音效相同（不加增益）。
# R5（2026-10-18）：用户指出卵缓降时不应有声音、落地（接触单位）时才有声音，并提供 MSA 单位动作浏览影片
# （https://www.youtube.com/watch?v=mU-oiFX-oqM ，19:40–20:00）。该段卵缓降期间（约 1187.5–1189 秒）只有背景音乐；
# 卵逐颗落地的 1195.5–1198.6 秒中，MS6 小型 Hunter Walker 的眼珠爆开声 SE_OGA_EYE 按频谱峰指纹出现 11 次（R4 的 OGR_EXP
# 与旋翼声 FALLBOMB 未出现）。该音效即原版 HUNTER WALKER（194）已使用的 OgA_Burst（SoundID 347），直接引用原版音效。
SOUND_SOURCE = HERE / 'source' / 'sounds'
SOUNDS = {          # 名称 → MS6 原名；音效键为 s1xlv.ghw_<名称>，文件为 community_content/ghw_<名称>.msdf
    'launcher': 'SE_OGC_LAUNCHER',       # 吐出一颗卵
    'death': 'SE_OGC_DEATH',             # 被击败
}
SND = {name: f's1xlv.ghw_{name}' for name in SOUNDS}
EGG_LAND = 347                           # 卵命中爆开 / 落地坠毁：原版 OgA_Burst（= MS6 SE_OGA_EYE）
# 被击败（R5）：身体（壳与一侧的腿）、紫色液体、肉块、另一侧的腿分层叠成（cut_frames.py 的 DEATH_LAYER_*）。爆裂 10 帧
# 各 3 tick 后紫色液体结束，接残骸（与爆裂第 10 帧同一姿势）与落在地上的肉块，停留 CORPSE_HOLD tick 后闪烁消失。
CORPSE_HOLD = 45

# 卵（2026-10-17 R2，参照 MSA 的攻击：张嘴后卵带绿色尾光竖直喷出画面，再带旋翼从落点正上方缓缓降下）：
# 上升段（emerge 帧）→ 画面外横移到落点上方（空白帧）→ 缓降段（descend 帧，左右轻摆，带攻击框 1）。
# op7 单位为 0.01 精灵像素/tick；y 相对单位原点（地面），向上为负。战场中 1 精灵像素 = 2 世界单位（LAB 实测：
# op7 速度与 op22 偏移在世界坐标中为 2 倍）；状态词 7 等原生射程与 getNearEnemyDistance 为世界单位。
WORLD = 2
# R7（2026-10-18）：用户反馈脚与卵的落点看起来悬在地面之上。本体各帧（含被击败）下移 BODY_DROP 精灵像素，
# 卵的缓降、爆开与坠地帧下移 EGG_DROP（卵的攻击框随之下移，判定与画面一致）。战场中 1 精灵像素在 1280×720 画面上
# 约 2.25 像素、在 2560×1440 全屏上约 4.5 像素；用户在全屏截图上量得约 16 像素，取 4（约 18 像素），卵取 2。
# R8（2026-10-18）：用户实机确认本体 4 不变，卵再下移 2 精灵像素（共 4）。
BODY_DROP, EGG_DROP = 4, 4
BODY_PARTS = {'idle', 'walk', 'open', 'fire', 'close', 'back', 'death', 'death_shell', 'death_gore', 'death_purple', 'death_legs'}
EGG_PARTS = {'descend', 'explode', 'wing_a', 'wing_b', 'crash'}
MOUTH = (0, -96 + BODY_DROP)    # 发射点（精灵像素，相对单位原点，前方为 −x；随本体下移）
TOP = 200                       # 横移与开始缓降的高度（精灵像素，地面以上 400 世界单位；地面 y=338 的战场画面上沿在地面以上约 338）
RISE_VY = 9.0                   # 上升速度（精灵像素/tick；约 12 tick 出画面，与 6 帧冒出动画同长）
TRAVEL_TICKS = 8                # 画面外横移的 tick 数
FALL_VY = 2.5                   # 缓降速度（精灵像素/tick；400 世界单位约 80 tick，画面内约 68 tick）
SWAY = (0.5, 8)                 # 缓降时左右摆动：0.5 精灵像素/tick，每 8 tick 换向（幅度约 ±2 精灵像素）
FRONT = 42                      # 本体受击框半宽（精灵像素）：落点距离与原生射程相同，从本体前缘算起
# R3：射程同 MSA（普攻 700、绝招 800）；卵的落点在射程内等距分布（暂定），最远一颗落在射程处
NORMAL_RANGE, SPECIAL_RANGE = 700, 800
NORMAL_DIST = tuple(NORMAL_RANGE * (i + 1) // 5 for i in range(5))      # 普攻 5 颗：140 / 280 / 420 / 560 / 700（世界单位，距本体前缘）
SPECIAL_DIST = tuple(SPECIAL_RANGE * (i + 1) // 10 for i in range(10))  # 绝招 10 颗：80 / 160 / … / 800
EGG_SLOTS = [17, 18, 19, 20, 23, 24, 25] + list(range(26, 40))          # 卵的脚本槽（槽 21、22 为爆开与坠地）
EGG_RECT = [-9, -18 + EGG_DROP, 18, 18, 7]     # 卵的攻击框（攻击框 1，相对卵的锚点：底边中点；随画面下移 EGG_DROP）
HIT_RECT = [-42, -116 + BODY_DROP, 84, 116 - BODY_DROP, 0]   # 本体受击框（受击框 1；上沿随本体下移，下沿仍为地面）

DAMAGE_MULTIPLIER = [5, 3]          # 每颗卵 Lv40 1000（僵尸（青年）普攻与绝招 600 × 5/3；用户设定）
SPECIAL_DAMAGE_MULTIPLIER = [2, 1]  # R9：绝招每颗卵 Lv40 2000（再 ×2，普攻仍 1000；用户设定）
KNOCKBACK_THRESHOLD = [20, 3]       # R9：击退门槛（抗击退）200（僵尸（青年）30 × 20/3；用户指定，不随生命联动）
AP, HP_MULTIPLIER = 400, [150, 17]  # Lv40 生命 30000（僵尸（青年）3400 × 150/17；用户设定）；AP 400（R6，原 650）
PRODUCTION = [27, 13]               # 再出击 45 秒 = 1350 tick（僵尸（青年）650 × 27/13；R6，原 2400 tick）

PROVISIONAL = {   # 用户未指定、暂定的数值（待确认）
    'move_speed_multiplier': [2, 3],      # 1.6（僵尸（青年）2.4 × 2/3）
    'targets': 1,                         # 每颗卵命中 1 个目标后在空中爆开（状态词 24/31）
    'shop_price': 300,
    'upgrade_cost_base': 500,             # 同原版 HUNTER WALKER（194）
}

TEXT = {
    'EN': ('GIANT HUNTER WALKER', 'STAND. ATK : Flying egg bombs     SPEC. ATK : Flying egg barrage\n'
                                  'A Hunter Walker that grew enormous to survive.\nThe eggs it spits drift down onto its enemies.'),
    'JP': ('ジャイアントHUNTER WALKER', '通常攻撃：飛行卵弾   特殊攻撃：飛行卵弾連射\n生き残るために巨大化したHUNTER WALKER。\n'
                                   '吐き出した卵は空から敵に降り注ぐ。'),
    'KR': ('자이언트 헌터 워커', '일반 공격: 비행 알 폭탄   특수 공격: 비행 알 폭탄 연사\n살아남기 위해 거대해진 헌터 워커.\n'
                          '토해낸 알이 하늘에서 적에게 떨어진다.'),
    'ES': ('CAZADOR CAMINANTE GIGANTE', 'ATQ. ESTÁND.: Huevos voladores  ATQ. ESPEC.: Ráfaga de huevos\n'
                                        'Un cazador caminante que creció enormemente para sobrevivir.\n'
                                        'Los huevos que escupe caen sobre sus enemigos.'),
    'PT': ('CAMINHANTE CAÇADOR GIGANTE', 'ATQ. PADR.: Ovos voadores     ATQ. ESPEC.: Rajada de ovos\n'
                                         'Um caminhante caçador que cresceu muito para sobreviver.\n'
                                         'Os ovos que cospe caem sobre os inimigos.'),
    'RU': ('ГИГАНТСКИЙ ПЕШИЙ ОХОТНИК', 'СТАНД. АТАК: Летучие яйца СПЕЦ. АТАК: Залп летучих яиц\n'
                                       'Пеший охотник, ставший огромным, чтобы выжить.\nЕго яйца медленно падают на врагов.'),
    'FR': ('CHASSEUR MARCHEUR GÉANT', "ATT. STAND : Œufs volants    ATT. SPÉ : Salve d'œufs\n"
                                      'Un chasseur marcheur devenu gigantesque pour survivre.\n'
                                      'Ses œufs volants retombent sur ses ennemis.'),
    'DE': ('RIESEN-HUNTER WALKER', 'STAND. ATK : Flugeier   SPEC. ATK : Flugeier-Salve\n'
                                   'Ein Hunter Walker, der zum Überleben riesig wurde.\nSeine Eier sinken auf die Feinde herab.'),
    'IT': ('CACCIATORE GIGANTE', 'ATC STAND.: Uova volanti  ATC SPEC.: Raffica di uova\n'
                                 'Un cacciatore diventato gigantesco per sopravvivere.\nLe uova che sputa ricadono sui nemici.'),
    'ZT': ('巨型HUNTER WALKER', '普通攻擊：飛行卵彈     特殊攻擊：飛行卵彈連射\n為了生存而巨大化的HUNTER WALKER。\n'
                               '吐出的飛行卵會從空中落到敵人身上。'),
    'ZS': ('巨型HUNTER WALKER', '普通攻击：飞行卵弹     特殊攻击：飞行卵弹连射\n为了生存而巨大化的HUNTER WALKER。\n'
                               '吐出的飞行卵会从空中落到敌人身上。'),
}


def drop(name):
    return BODY_DROP if name in BODY_PARTS else EGG_DROP if name in EGG_PARTS else 0


def fr(sheet, name, i, dx=0, dy=0):
    f = DATA[name][i]
    return sheet.f(FRAMES / f['file'], f['ax'], f['ay'], dx, dy + drop(name))


def frames(sheet, name, indices=None):
    return [fr(sheet, name, i) for i in (indices if indices is not None else range(len(DATA[name])))]


def egg_script(sheet, distance):
    """一颗卵：竖直上升出画面 → 画面外横移到距本体前缘 distance 处的正上方 → 带旋翼缓降（左右轻摆，带攻击框 1，无音效）。
    命中目标进入状态 60（槽 21 爆开），落地进入状态 61（槽 22 坠毁）。"""
    emerge, descend = frames(sheet, 'emerge'), frames(sheet, 'descend')
    rise = round((TOP + MOUTH[1]) / RISE_VY)          # MOUTH[1] 为负
    out = [op(7, 0, round(-RISE_VY * 100), 0, 0)]
    for t in range(0, rise, 2):
        out += F(emerge[(t // 2) % len(emerge)], min(2, rise - t))
    vx = -(FRONT + distance / WORLD - MOUTH[0]) / TRAVEL_TICKS
    out += [op(7, round(vx * 100), 0, 0, 0)] + F(-1, TRAVEL_TICKS)
    speed, period = SWAY
    fall = TOP / FALL_VY
    out += [op(4, 1)]
    t = i = 0
    while t < fall + 30:                 # 正常情况在此之前落地（状态 61）
        half = period // 2
        if t == 0 or (t >= half and (t - half) % period == 0):
            # 先摆半个周期（自中心起），之后每个周期换向：横向位移在 ±speed×half 之间往返，平均为零
            direction = 1 if t < half or (t - half) // period % 2 == 1 else -1
            out += [op(7, round(direction * speed * 100), round(FALL_VY * 100), 0, 0)]
        out += F(descend[i % len(descend)], 2)
        t, i = t + 2, i + 1
    return out + [op(4, -1)] + F(-1, 1) + [op(21)]


def explode_script(sheet):
    """命中目标（状态 60，槽 21）：爆开，两片翅膀向左右飞出后下落。"""
    out = [op(4, -1), op(23, EGG_LAND)]
    for i in range(len(DATA['wing_a'])):
        parts = []
        if i < len(DATA['explode']):
            f = DATA['explode'][i]
            parts.append((FRAMES / f['file'], f['ax'], f['ay'], 0, EGG_DROP))
        for name, sign in (('wing_a', -1), ('wing_b', 1)):
            f = DATA[name][i]
            parts.append((FRAMES / f['file'], f['ax'], f['ay'], sign * 3 * i, round(-5 * i + 0.6 * i * i) + EGG_DROP))
        out += F(sheet.frame(parts), 2)
    return out + F(-1, 1) + [op(21)]


def crash_script(sheet):
    """落地（状态 61，槽 22）：坠毁溅开。素材格子底边与残渣最下沿相差 gap 像素，下移 gap 贴地。"""
    gap = min(f['ay'] - f['size'][1] for f in DATA['crash'])
    out = [op(4, -1), op(23, EGG_LAND)]
    for i in range(len(DATA['crash'])):
        out += F(fr(sheet, 'crash', i, 0, gap), 2)
    return out + F(-1, 1) + [op(21)]


def death_script(sheet):
    """被击败（状态 100/110/120，槽 13、15）：每帧按 壳 < 肉块 < 紫色液体 < 另一侧的腿 叠成（肉块与紫色液体在素材表
    同一行、互不重叠）。爆裂 10 帧后紫色液体结束；残骸（素材表合成行第 12 帧）与地上的肉块（液体行第 11 格）停留，
    再闪烁消失。残骸已含两侧的腿，其上再叠一次第 10 帧的腿，使肉块与腿的前后次序与爆裂各帧相同。"""
    def part(name, k):
        f = DATA[name][k]
        return f and (FRAMES / f['file'], f['ax'], f['ay'], 0, BODY_DROP)

    burst = [sheet.frame([p for p in (part('death_shell', k), part('death_gore', k), part('death_purple', k),
                                      part('death_legs', k)) if p]) for k in range(10)]
    corpse = sheet.frame([part('death', 11), part('death_gore', 10), part('death_legs', 9)])
    blink = [c for _ in range(3) for c in F(-1, 2) + F(corpse, 2)] + F(-1, 1)
    return once(burst + [corpse], [3] * len(burst) + [CORPSE_HOLD],
                first=[op(4, -1), op(23, SND['death'])], tail=blink)


def attack_script(sheet, fire_seq, shots, show_eggs=True):
    """张嘴 → 吐卵（嘴部绿焰）→ 闭嘴 → 恢复行走姿势；shots 为 {fire_seq 序号: 弹体槽}。"""
    fire = frames(sheet, 'fire')
    out = [op(3, 1)]
    for f in frames(sheet, 'open'):
        out += F(f, 2)
    for k, index in enumerate(fire_seq):
        if show_eggs and k in shots:
            out += [op(22, shots[k], 0, MOUTH[0], MOUTH[1]), op(23, SND['launcher'])]
        out += F(fire[index], 2)
    for f in frames(sheet, 'close') + frames(sheet, 'back'):
        out += F(f, 2)
    return out + [op(21)]


def build():
    sheet = pvz.Sheet()
    idle, walk = frames(sheet, 'idle'), frames(sheet, 'walk')
    sheet.scripts[0] = sheet.scripts[6] = sheet.scripts[11] = loop(idle, [4] * len(idle), first=[op(3, 1)])
    sheet.scripts[1] = sheet.scripts[7] = loop(walk, [3] * len(walk), first=[op(3, 1)])
    distances = sorted(set(NORMAL_DIST) | set(SPECIAL_DIST))
    egg_slots = dict(zip(distances, EGG_SLOTS))
    normal_seq = list(range(15))
    special_seq = list(range(10)) + list(range(15))
    # 吐卵时刻：普攻 15 帧吐 5 颗（每 3 帧一颗），绝招 25 帧吐 10 颗（每 2.5 帧一颗）
    normal_shots = {1 + 3 * i: egg_slots[d] for i, d in enumerate(NORMAL_DIST)}
    special_shots = {int(1 + 2.5 * i + 0.5): egg_slots[d] for i, d in enumerate(SPECIAL_DIST)}
    assert len(special_shots) == len(SPECIAL_DIST) and max(special_shots) < len(special_seq)
    for distance, slot in egg_slots.items():
        sheet.scripts[slot] = egg_script(sheet, distance)
    sheet.scripts[9] = attack_script(sheet, normal_seq, normal_shots)
    sheet.scripts[10] = attack_script(sheet, special_seq, special_shots)
    sheet.scripts[2] = attack_script(sheet, normal_seq, normal_shots, show_eggs=False)
    sheet.scripts[12] = pvz.knockback_script(walk, idle)
    sheet.scripts[13] = sheet.scripts[15] = death_script(sheet)
    sheet.scripts[21] = explode_script(sheet)
    sheet.scripts[22] = crash_script(sheet)
    return pvz.finish(sheet, max(EGG_SLOTS[:len(distances)]) + 1, HIT_RECT, [EGG_RECT])


def icon_image():
    """待机第 1 帧水平翻转（眼睛朝右，同 MSA 与原版 HUNTER WALKER 头像）后按 ICON_CROP 1:1 裁切 ICON_SIZE 见方，
    不缩放；裁切范围内的透明像素保持透明。"""
    src = Image.open(FRAMES / DATA['idle'][0]['file']).convert('RGBA').transpose(Image.FLIP_LEFT_RIGHT)
    x, y = ICON_CROP
    assert x + ICON_SIZE <= src.width and y + ICON_SIZE <= src.height
    return src.crop((x, y, x + ICON_SIZE, y + ICON_SIZE))


def icon_atlas():
    """头像（icon_image）写入社区合并图集（RGBA32）的空位；目标区域须为空或为本单位先前写入。"""
    raw = bytearray((CONTENT / ICON_ATLAS).read_bytes())
    assert raw[:4] == b'OI\x01\x20'
    w, h = struct.unpack_from('<HH', raw, 4)
    for unit_file in (CONTENT / 'units').glob('*.json'):
        unit = json.loads(unit_file.read_text(encoding='utf-8'))
        if unit['key'] == KEY or 'atlas' in unit['icon']:
            continue
        x, y, iw, ih = unit['icon']['rect']
        assert (x + iw <= ICON_AT[0] or x >= ICON_AT[0] + ICON_CLEAR or y + ih <= ICON_AT[1]
                or y >= ICON_AT[1] + ICON_CLEAR), unit['key']
    crop = icon_image()
    for j in range(ICON_CLEAR):
        for i in range(ICON_CLEAR):
            at = 8 + ((ICON_AT[1] + j) * w + ICON_AT[0] + i) * 4
            raw[at:at + 4] = bytes(crop.getpixel((i, j)) if i < ICON_SIZE and j < ICON_SIZE else (0, 0, 0, 0))
    return bytes(raw), crop


def unit_file(animations):
    return {
        'key': KEY, 'base_id': 313, 'faction': 3, 'identity': 'Invader',
        'shop_price': PROVISIONAL['shop_price'], 'available_from_start': True, 'ap': AP,
        'upgrade_cost_base': PROVISIONAL['upgrade_cost_base'],
        'hp_multiplier': HP_MULTIPLIER,                   # 僵尸（青年）Lv40 3400 → 30000
        'knockback_threshold_multiplier': KNOCKBACK_THRESHOLD,  # R9 用户指定 200（此前随生命为 265）
        'production_reference_id': 313, 'production_interval_multiplier': PRODUCTION,   # 650 → 1350 tick
        'damage_multiplier': DAMAGE_MULTIPLIER, 'special_damage_multiplier': SPECIAL_DAMAGE_MULTIPLIER,
        'move_speed_multiplier': PROVISIONAL['move_speed_multiplier'], 'knockback_distance_multiplier': [1, 1],
        # 状态词 7 开始吐卵的距离；24/31 每颗卵命中目标数；35/36 绝招冷却（之后 / 出场后第一次）
        'status_word_values': {'7': NORMAL_RANGE, '24': PROVISIONAL['targets'], '31': PROVISIONAL['targets'],
                               '35': 2000, '36': 1333},
        'icon': {'page': 1, 'rect': [*ICON_AT, ICON_SIZE, ICON_SIZE], 'anchor': ICON_ANCHOR},
        'textures': [TEXTURE], 'sprite_descriptor': DESCRIPTOR, 'animations': animations,
        'localization': {code: {'name': n, 'description': d} for code, (n, d) in TEXT.items()},
        'tags': ['ms6'],
    }


def main():
    OUT.mkdir(exist_ok=True)
    obm, desc, animations, page = build()
    icon_raw, icon = icon_atlas()
    files = {TEXTURE: obm, ICON_ATLAS: icon_raw}
    index = json.loads((CONTENT / 'content.json').read_text(encoding='utf-8'))
    if KEY not in index['unit_ids']:
        index['unit_ids'][KEY] = max(index['unit_ids'].values()) + 1
    for name, raw in files.items():
        (CONTENT / name).write_bytes(raw)
        if index['assets'].get(name, '') is not None:     # unit_icon_02.obm 登记为 null（不做摘要核对）
            index['assets'][name] = hashlib.blake2b(raw, digest_size=32).hexdigest()
    sounds = [e for e in index.get('sounds', []) if not e['key'].startswith('s1xlv.ghw_')]
    for e in index.get('sounds', []):           # 已不使用的本单位音效文件（R5 去掉旋翼声与 OGR_EXP）
        if e['key'].startswith('s1xlv.ghw_') and e['key'] not in SND.values():
            (CONTENT / e['file']).unlink(missing_ok=True)
    for name, source in SOUNDS.items():
        target = f'ghw_{name}.msdf'
        shutil.copyfile(SOUND_SOURCE / f'{source}.ogg', CONTENT / target)
        sounds.append({'key': SND[name], 'file': target, 'type': 'se'})
    index['sounds'] = sounds
    pvz.save_json(CONTENT / DESCRIPTOR, desc)
    pvz.save_json(CONTENT / 'units' / 'giant_hunter_walker.json', unit_file(animations))
    pvz.save_json(CONTENT / 'content.json', index)
    page.save(OUT / 'giant_hunter_walker_atlas.png')
    icon.resize((ICON_SIZE * 8, ICON_SIZE * 8), Image.NEAREST).save(OUT / 'icon_8x.png')
    report = {'unit_id': index['unit_ids'][KEY], 'atlas': list(page.size), 'rects': len(desc['rects']),
              'frame_words': len(desc['frames']), 'scripts': len(desc.get('scripts', [])) or None}
    (OUT / 'build_report.json').write_text(json.dumps(report, ensure_ascii=False, indent=2), encoding='utf-8')
    print(json.dumps(report))


if __name__ == '__main__':
    main()
