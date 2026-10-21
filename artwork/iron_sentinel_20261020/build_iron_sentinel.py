"""IRON SENTINEL（s1xlv.iron_sentinel）资源与单位文件生成（2026-10-20）。

《合金弹头6》第 2 关首领，素材取自《Metal Slug Attack》单位 Iron Sentinel（source/MSA_Iron_Sentinel.png，无损），
由 cut_frames.py 切帧，geometry.py 定位部件并水平化（RotSprite 旋转 atan(1/2)，见 rotsprite.py）、按 MSA 素材 1:1 使用
（用户 2026-10-20：保持 720 世界单位大小、水平放置）。调研见 docs/ms6/IRON_SENTINEL_RESEARCH_2026-10-20.md。

动作依据 MSA 录像（Lindermann 动作浏览影片 2Jss8QCG2dA 7:40–8:02；1 对 1 实战 fdcqqIWDZzk 7:43–7:54）：
- 第一形态普通攻击：车身侧面 6 个舱口依次打开，小火箭竖直升空，之后落在前方（MSA Long Range Attack）。
- 第一形态特殊攻击：主炮连射 8 发大型导弹，两座侧炮升起抛射炮弹（MSA Special Attack）。
- 第一形态生命耗尽时形态转换（MSA FORM CHANGE）：连续爆炸，主炮炸飞，换为第二形态。
- 第二形态普通攻击：发射臂竖起巨型导弹，导弹升空后自画面上方竖直落下，炸成一排火柱。
用户决定不做 MSA 的屏障（属性减伤）与硬直免疫（MSD 没有这些属性）。

实现（未新增 C++ 行为）：基准为原版僵尸（青年）UnitID 313（BattleAction_ZombieBrain），第二形态用行为库 hp_stage_animations
（生命低于最大生命 1/6 进入第 1 档，经状态 80 播放槽 28 的形态转换；第 1 档动作槽为原生槽号 + 16）与 stage_knockback_animation。
所有伤害为单位自身帧上的攻击框（同 IRON CAB 的激光），在弹体落地的 tick 以 op4 开启 2 tick；弹体按世界方向绘制在单位帧中
（随队伍镜像），爆炸与火柱为 op12 效果。原生 ZombieBrain 弹体的命中 / 落地固定播放槽 21 / 22，而槽 22 是第 1 档的待机动作，
本单位不使用 op22 弹体。

数值（用户 2026-10-20）：AP 800；生命 44000（第二形态为最后 1/6）；近战 / 远程 / 绝招按 MSA Lv50 信息页（Near 17599、Far 7207、
Special 86881，生命 872428）以生命比例 44000/872428 缩小：远程每次 6 枚火箭共 366（MSA 折算 363）、第二形态巨型导弹 888
（Near 折算 888，MSA 动作浏览器中没有近战动作）、绝招 14 发每发 313 共 4382（折算 4382）。
第二形态的普通与绝招伤害以狂暴倍率 888/61 换算（hp_stage_animations.rage_damage_multiplier）。

运行：E:\\anaconda3\\python.exe -I artwork/iron_sentinel_20261020/build_iron_sentinel.py [--preview]
（--preview 只生成 out/preview_*.png 与报告；否则写入 community_content/：图集、描述符、单位文件、头像、音效与 content.json）。
"""
from pathlib import Path
import hashlib
import json
import math
import sys

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[1]
sys.path.insert(0, str(HERE))
sys.path.insert(0, str(REPO / 'artwork' / 'pvz_zombies_20261012'))

import numpy as np  # noqa: E402
from PIL import Image  # noqa: E402

import geometry as G  # noqa: E402

# build_pvz_zombies 在导入时把随包 Python 的 Pillow 路径加入 sys.path（anaconda 下不需要），这里只取其纯函数。
_PVZ = REPO / 'artwork' / 'pvz_zombies_20261012' / 'build_pvz_zombies.py'
_src = _PVZ.read_text(encoding='utf-8')
_src = _src.replace("sys.path.insert(0, str(RT / 'packages'))", "").replace("os.add_dll_directory(str(RT / 'native'))", "")
pvz = type(sys)('pvzb')
pvz.__dict__['__file__'] = str(_PVZ)
exec(compile(_src, str(_PVZ), 'exec'), pvz.__dict__)
F, op, loop, Sheet, shelf_pack, indexed_obm = pvz.F, pvz.op, pvz.loop, pvz.Sheet, pvz.shelf_pack, pvz.indexed_obm

CONTENT = REPO / 'community_content'
OUT = HERE / 'out'
KEY = 's1xlv.iron_sentinel'
TEXTURES = ['iron_sentinel_0.obm', 'iron_sentinel_1.obm']      # 第 0 页本体（旋转后的部件），第 1 页弹体与效果
DESCRIPTOR = 'iron_sentinel_descriptor.json'
ICON_ATLAS = 'unit_icon_02.obm'
ICON_AT, ICON_SIZE, ICON_ANCHOR = (1650, 768), 40, [-5, -5]
ICON_CROP = (3, 3)              # MSA 出兵栏头像（主炮特写，46×46）1:1 裁 40×40 的左上角

WORLD = 2                       # 战场中 1 精灵像素 = 2 世界单位
RANGE = 680                     # 开始攻击的距离（世界单位，自本体前缘；MSA Far / Special Distance 680）
FRONT = 165                     # 受击框半宽（精灵像素）：射程与落点自本体前缘算起
HIT_H = 163                     # 受击框上沿（初版 175，本体下移 12 像素后同步下移）
HIT_RECT = [-FRONT, -HIT_H, 2 * FRONT, HIT_H, 0]
WALK_HOLD = 2                   # 行走每帧 tick（履带 6 帧一循环）
TOP = 300                       # 弹体飞出画面的高度（地面以上精灵像素）

# 音效：火箭与主炮导弹发射沿用原版 SoundID 208（B4_MISSL，IRON CAB R5 起的导弹发射音效）；爆炸为 IRON CAB 已登记的
# s1xlv.ironcab_bomb（MS6 第 1 关 Boss SE_BS1_BOMB）；巨型导弹发射与火柱取 MS6 第 2 关音效库（MS6_OST_ST02.osb）的
# SE_BS2_MISSILE（2.66 秒）与 SE_BS2_CONFLICT（2.95 秒），按名称选用，未经录像比对；大爆炸为原版 253（基寇卡损毁）。
SOUND_SOURCE = Path(r'F:\egg\MS6\MS6-sounds-wav\OSB_MS6_OST_ST02')
SOUNDS = {'launch': 'SE_BS2_MISSILE', 'blast': 'SE_BS2_CONFLICT'}
SND = {name: f's1xlv.isentinel_{name}' for name in SOUNDS}
BOMB = 's1xlv.ironcab_bomb'
MISSILE_SE = 208
BIG_BLAST_SE = 253

# 共用效果（op12 编号 ≥ 0xff00 时取原生共用效果 UnitID 402 的动画，不占本单位图集；IRON CAB R9 起使用）
FX_HIT = 0xff02                 # 小爆炸（吉利塔炮弹命中）
FX_BLAST = 0xff04               # 中爆炸（基寇卡损毁）
FX_BIG = 0xff17                 # 大型单位爆炸（白闪后火球与黑烟）

SLOT_FIRE = 19                  # 效果脚本：巨型导弹的火柱
SLOT_SMOKE = 20                 # 效果脚本：烟团
SCRIPT_COUNT = 32

STATS = {
    'ap': 800, 'shop_price': 450, 'upgrade_cost_base': 650,
    'hp_multiplier': [220, 17],                     # 僵尸（青年）Lv40 3400 → 44000
    'knockback_threshold_multiplier': [220, 17],    # 随生命（AGENTS 第 6.1 节）：30 → 388
    'production_interval_multiplier': [40, 13],     # 650 → 2000 tick（暂定）
    'damage_multiplier': [61, 600],                 # 普通攻击每发 Lv40 61（600 × 61/600）
    'special_damage_multiplier': [3079, 600],       # 词 29：600 → 3079，再乘 61/600 为 313
    'move_speed_multiplier': [5, 8],                # 2.4 → 1.5（暂定）
}
RAGE_DAMAGE = [888, 61]         # 第二形态：61 → 888（巨型导弹），313 → 4556（绝招）
STAGE_THRESHOLD = [1, 6]        # 生命低于最大生命 1/6 时为第二形态（MSA：复活为最大生命的 20%，44000 = 第一形态 36667 + 第二形态 7333）

TEXT = {
    'EN': ('IRON SENTINEL', 'STAND. ATK : Missile salvo     SPEC. ATK : Big missile barrage\n'
                            'A giant missile tank built with the Mars People. Gen. Morden himself is aboard.\n'
                            'When first destroyed it changes into its second form and launches giant missiles.'),
    'JP': ('アイアンセンチネル', '通常攻撃：ミサイル斉射   特殊攻撃：大型ミサイル連射\nマーズピープルの協力で造られた超巨大ミサイル戦車。モーデン元帥が自ら搭乗する。\n'
                          '一度破壊されると第二形態となり、巨大ミサイルを発射する。'),
    'KR': ('아이언 센티넬', '일반 공격: 미사일 일제 사격   특수 공격: 대형 미사일 연사\n마즈 피플의 협력으로 만든 초거대 미사일 전차. 모덴 원수가 직접 탑승한다.\n'
                      '한 번 파괴되면 제2형태가 되어 거대 미사일을 발사한다.'),
    'ES': ('IRON SENTINEL', 'ATQ. ESTÁND.: Salva de misiles  ATQ. ESPEC.: Ráfaga de misiles grandes\n'
                            'Tanque lanzamisiles gigante construido con los Mars People. Lo pilota el propio Gen. Morden.\n'
                            'Al ser destruido por primera vez pasa a su segunda forma y lanza misiles gigantes.'),
    'PT': ('IRON SENTINEL', 'ATQ. PADR.: Salva de mísseis   ATQ. ESPEC.: Rajada de mísseis grandes\n'
                            'Tanque lança-mísseis gigante feito com os Mars People. O próprio Gen. Morden está a bordo.\n'
                            'Ao ser destruído pela primeira vez muda para a segunda forma e lança mísseis gigantes.'),
    'RU': ('АЙРОН СЕНТИНЕЛ', 'СТАНД. АТАК: Ракетный залп   СПЕЦ. АТАК: Залп больших ракет\n'
                             'Гигантский ракетный танк, построенный с помощью марсиан. Им управляет сам генерал Морден.\n'
                             'После первого уничтожения переходит во вторую форму и запускает гигантские ракеты.'),
    'FR': ('IRON SENTINEL', 'ATT. STAND : Salve de missiles   ATT. SPÉ : Salve de gros missiles\n'
                            'Char lance-missiles géant construit avec les Mars People. Le Gén. Morden est à bord.\n'
                            'Détruit une première fois, il passe à sa seconde forme et lance des missiles géants.'),
    'DE': ('IRON SENTINEL', 'STAND. ATK : Raketensalve   SPEC. ATK : Große Raketensalve\n'
                            'Riesiger Raketenpanzer, gebaut mit den Mars People. General Morden selbst ist an Bord.\n'
                            'Nach der ersten Zerstörung wechselt er in die zweite Form und feuert Riesenraketen ab.'),
    'IT': ('IRON SENTINEL', 'ATC STAND.: Salva di missili  ATC SPEC.: Raffica di grandi missili\n'
                            'Carro lanciamissili gigante costruito con i Mars People. A bordo c’è il Gen. Morden.\n'
                            'Distrutto una prima volta passa alla seconda forma e lancia missili giganti.'),
    'ZT': ('鋼鐵哨兵', '普通攻擊：飛彈齊射     特殊攻擊：大型飛彈連射\n與火星人合作打造的超巨型飛彈戰車，由摩登元帥親自搭乘。\n'
                   '第一次被擊毀後轉為第二形態，發射巨型飛彈。'),
    'ZS': ('钢铁哨兵', '普通攻击：导弹齐射     特殊攻击：大型导弹连射\n与火星人合作打造的超巨型导弹战车，由摩登元帅亲自搭乘。\n'
                   '第一次被击毁后转为第二形态，发射巨型导弹。'),
}


# ---------------------------------------------------------------- 帧与姿势
class Sheet2(Sheet):
    """两页图集：derived/fx/ 中的图块放第 1 页，其余放第 0 页。"""
    pass


def page_of(path):
    return 1 if Path(path).parent.name == 'fx' else 0


HATCHES = None


def first_base(k=0, dx=0, cannon=('cannon_idle', 0), hatch=None, cannon_shift=(0, 0)):
    """第一形态姿势的部件：车体（ff_bare k）< 舱口 < 主炮。hatch：{舱口序号: (组, 帧)}；cannon_shift：主炮整体的平移（后坐）。"""
    parts = [G.body('ff_bare', k, *G.g_full('ff_bare', k))]
    for i, (grp, f) in sorted((hatch or {}).items()):
        parts.append(G.body(grp, f, *G.hatch_pos(HATCHES[i], grp, f)))
    if cannon:
        parts.append(shifted(G.body(cannon[0], cannon[1], *G.cannon_pos(*cannon)), *cannon_shift))
    if dx:
        parts = [(p[0], p[1], p[2], p[3] + dx, p[4]) for p in parts]
    return parts


ARM = {'a': 'sf_walk_a', 'b': 'sf_walk_b', 'c': 'sf_walk_c'}


def second_base(arm='a', k=0, missile=None, dx=0):
    """第二形态姿势：整车帧（发射臂折叠 a / 半竖 b / 竖起 c）< 巨型导弹（missile_turn 帧）。"""
    grp = ARM[arm]
    parts = [G.body(grp, k, *G.g_full(grp, k))]
    if missile is not None:
        parts.append(G.body('missile_turn', missile, *G.missile_pos(missile)))
    if dx:
        parts = [(p[0], p[1], p[2], p[3] + dx, p[4]) for p in parts]
    return parts


def bbox_of(part):
    path, ax, ay, dx, dy = part
    w, h = Image.open(path).size
    return dx - ax, dy - ay, dx - ax + w, dy - ay + h


def opaque_points(part):
    path, ax, ay, dx, dy = part
    a = np.asarray(Image.open(path).convert('RGBA'))[..., 3] > 0
    ys, xs = np.nonzero(a)
    return xs + dx - ax, ys + dy - ay


# ---------------------------------------------------------------- 时间轴
class Timeline:
    """逐 tick 的帧（部件列表）与事件；最后转为脚本（每 tick 一条 op0 + op1 1，相同帧合并等待）。"""

    def __init__(self, length):
        self.length = length
        self.parts = [[] for _ in range(length)]
        self.back = [[] for _ in range(length)]      # 画在本体之后的部件
        self.base = [None] * length
        self.events = [[] for _ in range(length)]

    def put(self, t, part):
        if 0 <= t < self.length:
            self.parts[t].append(part)

    def put_back(self, t, part):
        if 0 <= t < self.length:
            self.back[t].append(part)

    def event(self, t, *cmds):
        self.events[t].extend(cmds)

    def script(self, sheet, first=(), tail=()):
        out = list(first)
        prev, wait = None, 0
        for t in range(self.length):
            parts = self.back[t] + (self.base[t] or []) + self.parts[t]
            key = sheet.frame(parts) if parts else -1
            if self.events[t] or key != prev:
                if prev is not None:
                    out += F(prev, wait)
                out += self.events[t]
                prev, wait = key, 1
            else:
                wait += 1
        out += F(prev, wait)
        return out + list(tail) + [op(21)]


ATTACKS = [[0, 0, 0, 0, 0]]         # attack_bounds（第 0 项为空）


def attack_box(x0, x1, height=80):
    """单位坐标 x0 < x1 之间、地面以上 height 的攻击框，返回编号。"""
    rect = [int(x0), -height, int(x1 - x0), height, 7]
    if rect not in ATTACKS:
        ATTACKS.append(rect)
    return ATTACKS.index(rect)


def land_x(distance):
    """自本体前缘 distance 世界单位处的单位坐标 x。"""
    return -FRONT - distance / WORLD


def impact(tl, t, x, half, damage=True, fx_code=FX_HIT, sound=None, height=80):
    """t 时在 x 处爆炸：op12 共用效果；damage 时开启攻击框 2 tick。"""
    cmds = [op(12, fx_code, 0, int(round(x)), 0)]
    if sound:
        cmds.append(op(23, sound))
    tl.event(t, *cmds)
    if damage:
        tl.event(t, op(4, attack_box(x - half, x + half, height)))
        tl.event(t + 2, op(4, -1))


def schedule_impacts(times, gap=3):
    """把落地 tick 调整为互相至少相隔 gap（攻击框开 2 tick，同一时间只有一个攻击框）。"""
    out, last = [], -99
    for t in sorted(times):
        t = max(t, last + gap)
        out.append(t)
        last = t
    return out


# ---------------------------------------------------------------- 弹体朝向与定位（R4）
# 弹体按“航向”绘制：航向为单位坐标中头部所指的数学角度（x 向右、y 向上，度）。素材中火箭头部朝上、导弹头部朝右；
# fx_tile 先以 RotSprite 逆时针旋转 a 再左右翻转，翻转后的航向为 90 − a（火箭）或 180 − a（导弹）。
# 弹体以头部定位：路径上的点为头部位置；头部取图块中沿航向最远的不透明像素。航向 5° 一档，车体倾角（63.43° / 153.43°）取精确值。
H_ROCKET_UP = 90 - math.degrees(G.rotsprite.THETA)        # 63.43°：舱内火箭（顶端偏后）
H_BARREL = 180 - math.degrees(G.rotsprite.THETA)          # 153.43°：主炮炮管（向前上方）
_NOSE = {}


def heading_angle(group, h):
    base = 90.0 if group == 'rocket' else 180.0
    a = base - h
    th = math.degrees(G.rotsprite.THETA)
    if abs(a - th) < 2.5:
        return G.rotsprite.THETA
    return math.radians(round(a / 5) * 5)


def nosed(group, k, h, x, y):
    """弹体 (group, k) 以航向 h 绘制，头部位于单位坐标 (x, y)。"""
    a = heading_angle(group, h)
    path, w, ht = G.fx_tile(group, k, a)
    if path not in _NOSE:
        base = 90.0 if group == 'rocket' else 180.0
        hh = math.radians(base - math.degrees(a))
        d = (math.cos(hh), -math.sin(hh))
        al = np.asarray(Image.open(path).convert('RGBA'))[..., 3] > 0
        ys, xs = np.nonzero(al)
        proj = xs * d[0] + ys * d[1]
        m = proj >= proj.max() - 1.5
        _NOSE[path] = (float(xs[m].mean()) + 0.5, float(ys[m].mean()) + 0.5)
    nx, ny = _NOSE[path]
    return (path, 0, 0, int(round(x - nx)), int(round(y - ny)))


def part_nose(part, h):
    """部件中沿航向 h 最远处（头部）的单位坐标。"""
    xs, ys = opaque_points(part)
    d = (math.cos(math.radians(h)), -math.sin(math.radians(h)))
    proj = xs * d[0] + ys * d[1]
    m = proj >= proj.max() - 1.5
    return float(xs[m].mean()) + 0.5, float(ys[m].mean()) + 0.5


def step(x, y, h, v):
    return x + v * math.cos(math.radians(h)), y - v * math.sin(math.radians(h))


def turn_and_dive(h0, h1, v, radius):
    """自原点以航向 h0 起，以半径 radius 逆时针转到 h1，再沿 h1 直线下落到 y = 0 所需的相对路径由调用方平移；
    这里返回转弯段的相对点列 [(dx, dy, h)]。"""
    out, x, y, h = [], 0.0, 0.0, h0
    while h < h1 - 1e-6:
        h = min(h1, h + math.degrees(v / radius))
        x, y = step(x, y, h, v)
        out.append((x, y, h))
    return out


# ---------------------------------------------------------------- 第一形态：普通攻击（舱口火箭）
HATCH_ORDER = [2, 5, 0, 3, 1, 4]                     # 发射次序（舱口由后到前编号 0–5）
# 落点（R4，用户 2026-10-20：落点太近，像打到自己）：先远后近，等距分布在本体前缘以外 680–240（R2–R3 为 680–60，近处一枚落在车头履带前）。
NEAR_DIST = 240
ROCKET_DIST = [round(RANGE - (RANGE - NEAR_DIST) * j / 5) for j in range(6)]
ROCKET_HALF = 33                                     # 每枚火箭的攻击框半宽（精灵像素，66 = 132 世界单位）
ROCKET_START, ROCKET_STEP = 6, 7
# 轨迹（R4，按用户提供的 MSA 单位动作影片 BV19W4y1J7Wz P10 12:50–12:57）：火箭沿舱内的倾斜角度（顶端偏后 26.57°）直线加速升起，
# 在车顶上方逆时针转弯到水平、朝前方平飞，到目标上方前再转弯，以同一倾角（头朝下偏前）落向目标（R3 为升起后直接从画面上方斜落）。
# 舱口第 17 帧中的火箭即 rocket 16；升起段用随车体旋转的同一帧，转弯与平飞用按航向旋转的帧（rocket 15、16 交替）。
ROCKET_FLY = (15, 16)
ROCKET_V0, ROCKET_A, ROCKET_VMAX = 6.0, 1.5, 22.0    # 沿航向的初速、加速度、最大速度（精灵像素/tick）
ROCKET_TURN_Y = -175                                 # 头部升到此高度开始转弯（单位坐标）
ROCKET_R = 40                                        # 转弯半径
ROCKET_DIVE_V = 20.0
H_DIVE = H_ROCKET_UP + 180                           # 243.43°：落下时头朝下偏前


def shifted(part, ox, oy):
    path, ax, ay, dx, dy = part
    return (path, ax, ay, dx + int(round(ox)), dy + int(round(oy)))


def hatch_rocket_part(i, k):
    """舱口 i 的舱内火箭位置上的 rocket k（随车体旋转）。"""
    gx, gy = G.hatch_pos(HATCHES[i], 'hatch_rocket', 17)
    dx, dy, r = G.find('hatch_rocket', 17, 'rocket', 16)
    assert r > 0.99, r
    return G.body('rocket', k, gx + dx, gy + dy)


def rocket_flight(i, tx):
    """舱口 i 的火箭飞到目标 x = tx 的逐 tick 部件：[(部件, 是否画在本体之后)]，最后一项为落地前一 tick。"""
    out = []
    # 升起：随车体旋转的舱内火箭帧沿轴线平移
    dist, v, n = 0.0, ROCKET_V0, 0
    ux, uy = math.cos(math.radians(H_ROCKET_UP)), -math.sin(math.radians(H_ROCKET_UP))
    nose0 = part_nose(hatch_rocket_part(i, 16), H_ROCKET_UP)
    while True:
        y = nose0[1] + uy * dist
        if y <= ROCKET_TURN_Y:
            break
        out.append((shifted(hatch_rocket_part(i, 15 + n % 4), ux * dist, uy * dist), False))
        dist += v
        v = min(ROCKET_VMAX, v + ROCKET_A)
        n += 1
    x, y, h = nose0[0] + ux * dist, nose0[1] + uy * dist, H_ROCKET_UP
    # 转弯到水平（朝前）
    while h < 180 - 1e-6:
        h = min(180.0, h + math.degrees(v / ROCKET_R))
        x, y = step(x, y, h, v)
        v = min(ROCKET_VMAX, v + ROCKET_A)
        out.append((nosed('rocket', ROCKET_FLY[len(out) % 2], h, x, y), False))
    # 第二次转弯与落下的相对路径
    tail = [(dx, dy, hh) for dx, dy, hh in turn_and_dive(180.0, H_DIVE, ROCKET_DIVE_V, ROCKET_R)]
    ex, ey = tail[-1][0], tail[-1][1]
    k = -(y + ey) / math.sin(math.radians(H_DIVE - 180))            # 沿 H_DIVE 直线下落的路程
    dive_dx = -k * math.cos(math.radians(H_DIVE - 180))
    cruise = (x + ex + dive_dx) - tx                                   # 平飞的水平路程（向前为负方向）
    steps = max(1, math.ceil(cruise / v))
    for s in range(steps):
        x -= cruise / steps
        out.append((nosed('rocket', ROCKET_FLY[len(out) % 2], 180.0, x, y), False))
    for dx, dy, hh in tail:
        out.append((nosed('rocket', ROCKET_FLY[len(out) % 2], hh, x + dx, y + dy), True))
    x, y = x + ex, y + ey
    steps = max(1, math.ceil(k / ROCKET_DIVE_V))
    for s in range(1, steps + 1):
        px = x + dive_dx * s / steps
        py = y + (-y) * s / steps
        if s < steps:
            out.append((nosed('rocket', ROCKET_FLY[len(out) % 2], H_DIVE, px, py), True))
    return out


def normal_attack_first(sheet, damage=True):
    length = ROCKET_START + ROCKET_STEP * 5 + 120
    tl = Timeline(length)
    hatch_state = [dict() for _ in range(length)]
    impacts = []
    for j, i in enumerate(HATCH_ORDER):
        s = ROCKET_START + ROCKET_STEP * j
        seq = [('hatch_small', f) for f in range(1, 7)] + [('hatch_rocket', f) for f in range(18)] \
            + [('hatch', 0)] * 4 + [('hatch_small', f) for f in range(6, 0, -1)]
        for n, st in enumerate(seq):
            if s + n < length:
                hatch_state[s + n][i] = st
        launch = s + 24
        if j % 3 == 0:
            tl.event(launch, op(23, MISSILE_SE))
        x = land_x(ROCKET_DIST[j])
        flight = rocket_flight(i, x)
        for n, (part, behind) in enumerate(flight):
            (tl.put_back if behind else tl.put)(launch + n, part)
        impacts.append((launch + len(flight), x))
    times = schedule_impacts([t for t, _ in impacts])
    for idx, (t, (_, x)) in enumerate(zip(times, sorted(impacts))):
        impact(tl, t, x, ROCKET_HALF, damage=damage, sound=BOMB if idx % 2 == 0 else None)
    end = max(times) + 4
    tl.length = min(tl.length, end)
    for t in range(tl.length):
        tl.base[t] = first_base(0, hatch=hatch_state[t])
    tl.parts, tl.back, tl.events, tl.base = tl.parts[:tl.length], tl.back[:tl.length], tl.events[:tl.length], tl.base[:tl.length]
    tl.event(0, op(3, 1))
    return tl.script(sheet, tail=[op(4, -1)])


# ---------------------------------------------------------------- 第一形态：特殊攻击（主炮导弹）
# R4（用户 2026-10-20：导弹未对准炮管、动画生硬；后坐力大，应是主炮整体被往后下方推，而非固定在原地；参照 MSA 影片 12:59.5–13:03）：
# - 炮管方向：素材中炮管为水平（G 坐标中炮管上下轮廓的中线在第 25–48 行之间、沿 x 不变），水平化后仰角恰为 26.57°；
#   R3 以炮口一带的轮廓拟合得 42°（混入了炮口环与较粗的炮身），导弹偏离炮管。
# - 后坐：开火时主炮（炮座与炮管）整体沿炮管轴线向后下方推出 RECOIL_PUSH 像素后逐 tick 复位，炮管同时缩入 RECOIL_BARREL 帧；
#   R1–R3 为炮座不动、炮管 8 帧逐渐缩入后一次弹回。
# - 炮口火光与烟：MS6 素材表 CANNON 一节的 16 帧（白色火光 → 拉长的火焰 → 黑烟团向前飘散），在 G 坐标中与炮管同向绘制
#   并随车体旋转，火光起点对准炮口；MSA 影片中每发导弹都有同样的火光与烟团。火光留在开火时的位置，不随炮身后坐移动。
# - 导弹：自炮口沿炮管方向射出（头部起点在炮口前 30 像素，前 3 tick 画在本体之后，像从炮管中钻出），以 8 像素/tick 沿三次
#   贝塞尔曲线飞行：先沿炮管方向，升到炮口以上约 40 像素后转为水平朝前，最后落向目标（MSA：导弹沿炮管射出后转为水平飞行）。
CANNON_SHOTS = [12 + 10 * j for j in range(8)]
CANNON_DIST = [round(RANGE - (RANGE - NEAR_DIST) * j / 7) for j in range(8)]   # 680 … 240（R4；R1–R3 为 680 … 109）
CANNON_SPEED = 8.0
CANNON_FRAMES = (4, 5)
RECOIL_PUSH = [5, 8, 8, 7, 5, 4, 3, 2, 1, 0]
RECOIL_BARREL = [1, 3, 3, 2, 2, 1, 1, 0, 0, None]   # cannon_fire 帧号，None 为待机帧
MUZZLE_ANCHOR = (11.5, 40.5)                          # MS6 炮口火光第 0 帧中炮口的位置（格内坐标）
MUZZLE_HOLDS = [1, 1, 1] + [2] * 13
NOSE_START = 30
CRUISE_ABOVE = 40
SPECIAL_HALF = 30


def muzzle_g():
    """炮口在 G 中的位置：主炮待机帧外框右缘、炮管中线（外框第 37 行）。"""
    gx, gy = G.cannon_pos('cannon_idle', 0)
    return gx + 125.0, gy + 37.0


def muzzle_point():
    return G.g_to_u(*muzzle_g())


def barrel_direction():
    h = math.radians(H_BARREL)
    return np.array([math.cos(h), -math.sin(h)])


def cubic_path(p0, p1, p2, p3, speed):
    def at(t):
        a, b, c, d = (1 - t) ** 3, 3 * t * (1 - t) ** 2, 3 * t * t * (1 - t), t ** 3
        return (a * p0[0] + b * p1[0] + c * p2[0] + d * p3[0], a * p0[1] + b * p1[1] + c * p2[1] + d * p3[1])
    fine = [at(i / 600) for i in range(601)]
    lengths = [0.0]
    for (x0, y0), (x1, y1) in zip(fine, fine[1:]):
        lengths.append(lengths[-1] + math.hypot(x1 - x0, y1 - y0))
    total = lengths[-1]
    n = max(1, math.ceil(total / speed))
    out, k = [], 0
    for s in range(1, n + 1):
        target = total * s / n
        while k < 599 and lengths[k + 1] < target:
            k += 1
        (x0, y0), (x1, y1) = fine[k], fine[k + 1]
        out.append((x1, y1, math.degrees(math.atan2(-(y1 - y0), x1 - x0)) % 360))
    return out


def muzzle_parts(k):
    mgx, mgy = muzzle_g()
    return G.body_array(f'muzzle_{k}', G.img('muzzle', k), mgx - MUZZLE_ANCHOR[0], mgy - MUZZLE_ANCHOR[1])


def special_first(sheet, damage=True):
    length = 220
    tl = Timeline(length)
    cannon = [(('cannon_idle', 0), 0.0)] * length
    impacts = []
    mx, my = muzzle_point()
    d = barrel_direction()
    for j, t0 in enumerate(CANNON_SHOTS):
        for n, (push, fr) in enumerate(zip(RECOIL_PUSH, RECOIL_BARREL)):
            cannon[t0 + n] = (('cannon_fire', fr) if fr is not None else ('cannon_idle', 0), push)
        tl.event(t0, op(23, MISSILE_SE))
        t = t0
        for k, hold in enumerate(MUZZLE_HOLDS):
            for _ in range(hold):
                tl.put(t, muzzle_parts(k))
                t += 1
        tx = land_x(CANNON_DIST[j])
        p0 = (mx + d[0] * NOSE_START, my + d[1] * NOSE_START)
        p1 = (p0[0] + d[0] * 90, p0[1] + d[1] * 90)
        p2 = (tx + 70, p0[1] - CRUISE_ABOVE)
        path = [(p0[0], p0[1], H_BARREL)] + cubic_path(p0, p1, p2, (tx, 0.0), CANNON_SPEED)
        for n, (x, y, h) in enumerate(path[:-1]):
            part = nosed('cannon_missile', CANNON_FRAMES[n % 2], h, x, y)
            (tl.put_back if n < 3 else tl.put)(t0 + n, part)
        impacts.append((t0 + len(path) - 1, tx))
    times = schedule_impacts([t for t, _ in impacts])
    for idx, (t, (_, x)) in enumerate(zip(times, sorted(impacts))):
        impact(tl, t, x, SPECIAL_HALF, damage=damage, sound=BOMB if idx % 2 == 0 else None)
    end = max(max(times) + 4, CANNON_SHOTS[-1] + len(RECOIL_PUSH), CANNON_SHOTS[-1] + sum(MUZZLE_HOLDS))
    tl.length = end
    back = (math.cos(math.radians(H_BARREL + 180)), -math.sin(math.radians(H_BARREL + 180)))
    for t in range(end):
        (grp, fr), push = cannon[t]
        tl.base[t] = first_base(0, cannon=(grp, fr), cannon_shift=(back[0] * push, back[1] * push))
    tl.parts, tl.back, tl.events, tl.base = tl.parts[:end], tl.back[:end], tl.events[:end], tl.base[:end]
    tl.event(0, op(3, 1))
    return tl.script(sheet, tail=[op(4, -1)])


# ---------------------------------------------------------------- 第二形态：巨型导弹
# 落点与范围：火柱攻击框覆盖本体前缘以外 0–640 世界单位（LAB 初测落点 422、半宽 220 时，前缘以外 200 以内靠近的敌人打不到）
GIANT_DIST = 320
GIANT_HALF = 160                                         # 火柱攻击框半宽（精灵像素，320 世界单位）
FIRE_OFFSETS = [(-140, 0), (-100, 2), (-60, 1), (-20, 3), (20, 0), (60, 2), (100, 1), (140, 3)]   # 8 道火柱（x 偏移，出现的 tick）


def missile_tail_top(k=18):
    part = G.body('missile_turn', k, *G.missile_pos(k))
    xs, ys = opaque_points(part)
    return xs, ys


def giant_attack(sheet, damage=True, special=False):
    tl = Timeline(100)
    base = [None] * 100
    # 发射臂：a 导轨约 45°、带托架；b 导轨竖直、带托架；c 导轨竖直、托架打开（发射位置，MS6 REFERENCES 第 2 幅）。
    # 巨型导弹沿 45° 导轨伸出（missile_turn 0–13），随导轨竖起转到竖直（14–18），在 c 上点火发射。
    seq = [('a', None)] * 6 + [('a', m) for m in range(14)] \
        + [('b', m) for m in (14, 14, 15, 15, 16, 16, 17, 17)] + [('c', 18)] * 2
    t = 0
    for arm, m in seq:
        base[t] = (arm, m)
        t += 1
    ignite = t
    xs, ys = missile_tail_top(18)
    tail_x, tail_y = float(xs[ys >= ys.max() - 3].mean()), float(ys.max())
    top_x, top_y = float(xs[ys <= ys.min() + 3].mean()), float(ys.min())
    for n in range(12):                                   # 点火：导弹底部的小火焰循环
        base[t] = ('c', 18)
        tl.put(t, G.fx('flame_small', n % 8, tail_x, tail_y - 4, anchor=(0.5, 0.15)))
        t += 1
    tl.event(ignite, op(23, SND['launch']))
    launch = t
    tl.event(launch, op(12, SLOT_SMOKE, 0, int(tail_x), int(tail_y)))
    # 发射：导弹（竖直素材 missile_up）自发射臂上的位置向上加速飞出，尾焰 flame_b，发射口闪光 flame_a
    mpath = G.fx_tile('missile_up', 0)
    mh = mpath[2]
    y, v, n = tail_y, 2.0, 0
    while y - mh > -TOP - 40:
        base[t] = ('c', None)
        tl.put(t, G.fx('missile_up', 0, tail_x, y, anchor=(0.5, 1.0)))
        tl.put(t, G.fx('flame_b', n % 4, tail_x, y - 6, anchor=(0.5, 0.0)))
        if n < 4:
            tl.put(t, G.fx('flame_a', n, tail_x, tail_y, anchor=(0.5, 0.35)))
        y -= v
        v += 2.5
        n += 1
        t += 1
    for arm, hold in (('c', 8), ('b', 4), ('a', 2)):
        for _ in range(hold):
            base[t] = (arm, None)
            t += 1
    fall_start = launch + n + 6
    x = land_x(GIANT_DIST)
    fall_v = 24
    fall_ticks = math.ceil((TOP + 40) / fall_v)
    for m in range(fall_ticks):
        yy = -TOP - 40 + fall_v * (m + 1)
        tl.put(fall_start + m, G.fx('missile_up', 0, x, min(yy, 0), anchor=(0.5, 1.0), flip_v=True))
    hit = fall_start + fall_ticks
    tl.event(hit, op(23, SND['blast']))
    for dx, dt in FIRE_OFFSETS:
        tl.event(hit + dt, op(12, SLOT_FIRE, 0, int(round(x + dx)), 0))
    tl.event(hit, op(12, FX_BIG, 0, int(round(x)), -20))
    if damage:
        tl.event(hit, op(4, attack_box(x - GIANT_HALF, x + GIANT_HALF, 120)))
        tl.event(hit + 2, op(4, -1))
    end = max(t, hit + 4)
    tl.length = end
    for k in range(end):
        arm, m = base[k] if k < len(base) and base[k] else ('a', None)
        tl.base[k] = second_base(arm, 0, m)
    tl.parts, tl.events, tl.base = tl.parts[:end], tl.events[:end], tl.base[:end]
    tl.event(0, op(3, 1))
    return tl.script(sheet, tail=[op(4, -1)])


# ---------------------------------------------------------------- 形态转换、受击、被击败
DEBRIS = [('fc_cannon', 3, (40, -150), (3.5, -9.0)), ('fc_flat', 9, (-20, -120), (-2.5, -10.0)),
          ('fc_plate', 9, (90, -125), (4.5, -8.0)), ('fc_flat', 9, (-80, -110), (-4.0, -7.5))]
DEBRIS_G = 0.7


def form_change(sheet):
    """第一形态生命耗尽（状态 80，槽 28）：抖动并接连爆炸 → 大爆炸中主炮与顶板炸飞，换为第二形态 → 烟散。"""
    length = 64
    tl = Timeline(length)
    pops = [(-60, -120), (30, -140), (-100, -90), (80, -100), (0, -160), (-30, -80), (110, -130), (-140, -110)]
    for n in range(10):
        x, y = pops[n % len(pops)]
        tl.event(3 * n, op(12, FX_HIT, 0, x, y))
        if n % 3 == 0:
            tl.event(3 * n, op(23, BOMB))
    tl.event(12, op(12, FX_BLAST, 0, -40, -100))
    tl.event(22, op(12, FX_BLAST, 0, 60, -110))
    swap = 30
    tl.event(swap, op(23, BIG_BLAST_SE), op(12, FX_BIG, 0, 20, -150), op(12, FX_BIG, 0, -80, -90), op(12, FX_BIG, 0, 90, -80))
    tl.event(swap + 6, op(12, SLOT_SMOKE, 0, 10, -130), op(12, SLOT_SMOKE, 0, -90, -100))
    for grp, count, (x0, y0), (vx, vy) in DEBRIS:              # 主炮与顶板在换为第二形态的同一 tick 炸飞，落地即消失
        x, y, v = x0, y0, vy
        for n in range(length - swap - 2):
            if y > 0:
                break
            tl.put(swap + 2 + n, G.fx(grp, (n // 2) % count, x, y, anchor=(0.5, 0.5)))
            x += vx
            y += v
            v += DEBRIS_G
    for t in range(length):
        if t < swap + 2:
            tl.base[t] = first_base(0, dx=(1 if t % 2 else -1) if t < swap else 0)
        else:
            tl.base[t] = second_base('a', 0)
    tl.event(0, op(4, -1), op(3, 1))
    return tl.script(sheet)


def knockback(sheet, walk_parts, stand_parts):
    out = [op(4, -1), op(3, 1), op(7, 160, 0, -16, 0)]
    for i in range(5):
        out += F(sheet.frame(walk_parts[(-i) % len(walk_parts)]), 2)
    return out + [op(7, 0, 0, 0, 0), op(16)] + F(sheet.frame(stand_parts), 10) + [op(21)]


def death(sheet):
    """第二形态生命耗尽（槽 13、15）：抖动并接连小爆炸 → 大爆炸中换为残骸 → 冒烟 → 残骸炸开后消失（同 IRON CAB R9 的收尾）。"""
    length = 110
    tl = Timeline(length)
    pops = [(-50, -110), (40, -130), (-110, -80), (90, -90), (0, -150), (-150, -60), (130, -110)]
    for n in range(10):
        x, y = pops[n % len(pops)]
        tl.event(3 * n, op(12, FX_HIT, 0, x, y))
        if n % 3 == 0:
            tl.event(3 * n, op(23, BOMB))
    swap = 30
    tl.event(swap, op(23, BIG_BLAST_SE), op(12, FX_BIG, 0, 0, -120), op(12, FX_BIG, 0, -100, -70), op(12, FX_BIG, 0, 100, -60))
    tl.event(swap + 8, op(12, SLOT_SMOKE, 0, -20, -90))
    final = swap + 30
    tl.event(final, op(23, BIG_BLAST_SE), op(12, FX_BIG, 0, -40, -40), op(12, FX_BIG, 0, 60, -30), op(12, FX_BIG, 0, -140, -20))
    wreck = [G.body('destroyed', 2, *G.wreck_pos(2))]
    for t in range(length):
        if t < swap + 2:
            tl.base[t] = second_base('a', 0, dx=(1 if t % 2 else -1) if t < swap else 0)
        elif t < final + 2:
            tl.base[t] = wreck
        else:
            tl.base[t] = None
    tl.event(0, op(4, -1))
    return tl.script(sheet)


# ---------------------------------------------------------------- 效果脚本
def fire_column(sheet):
    out = []
    for k in range(len(G.D['blast'])):
        out += F(sheet.frame([G.fx('blast', k, 0, 0, anchor=(0.5, 1.0))]), 2 if k < 20 else 1)
    return out + F(-1, 1) + [op(21)]


def smoke_puff(sheet):
    out = [op(7, 0, -40, 0, 0)]
    for k in range(len(G.D['smoke_c'])):
        out += F(sheet.frame([G.fx('smoke_c', k, 0, 0, anchor=(0.5, 0.5))]), 3)
    return out + F(-1, 1) + [op(21)]


# ---------------------------------------------------------------- 待机的排气烟（R3b）
# 用户 2026-10-20：中立状态不要完全静止一帧。MSA 素材的待机只有一帧（主炮待机第 2 帧与第 1 帧只差零散像素的明暗，交替会显得闪烁），
# 改用 MS6 素材表的排气烟（13 帧）：两根排气管口各冒一团烟，由小变大再散开。烟团按世界方向绘制（只左右翻转，不随车体旋转；
# 翻转后两团烟的相对位置与两个管口一致），每帧以烟团像素的重心对准两管口中点的外侧，并逐 tick 向后上方漂移。
# R4（用户 2026-10-20：遮挡关系错误）：烟团画在本体之后，排气管口盖在烟团之上（R3b 画在本体之前）。
FUME_HOLD = 3
FUME_GAP = 21                   # 两次冒烟之间不冒烟的 tick
FUME_OUT = (7.0, 0.0)           # 第一帧重心相对两管口中点的偏移（管口朝后，+x 为后方；两团烟分居上下管口两侧）
FUME_DRIFT = (0.25, -0.5)       # 每 tick 漂移


def pipe_tips(parts):
    """两根排气管口：黄铜色像素中，车体后上方按高度分为上下两根，各取最靠后（x 最大）处。"""
    pts = []
    for path, ax, ay, dx, dy in parts:
        a = np.asarray(Image.open(path).convert('RGBA')).astype(int)
        m = (a[..., 3] > 0) & (a[..., 0] > a[..., 2] + 30) & (a[..., 1] > a[..., 2] + 10) & (a[..., 0] > 90)
        ys, xs = np.nonzero(m)
        pts += list(zip(xs + dx - ax, ys + dy - ay))
    pts = np.array([p for p in pts if p[1] < -100 and p[0] > 60])
    out = []
    for lo, hi in ((-140, -122), (-122, -105)):
        sel = pts[(pts[:, 1] >= lo) & (pts[:, 1] < hi)]
        x = sel[:, 0].max()
        out.append((float(x), float(sel[sel[:, 0] >= x - 1][:, 1].mean())))
    return out


def fume_part(k, x, y):
    path, w, h = G.fx_tile('fumes', k)
    a = np.asarray(Image.open(path).convert('RGBA'))[..., 3] > 0
    ys, xs = np.nonzero(a)
    return (path, 0, 0, int(round(x - xs.mean())), int(round(y - ys.mean())))


def idle_loop(sheet, base):
    (x0, y0), (x1, y1) = pipe_tips(base)
    mx, my = (x0 + x1) / 2 + FUME_OUT[0], (y0 + y1) / 2 + FUME_OUT[1]
    frames, holds, t = [], [], 0
    for k in range(len(G.D['fumes'])):
        part = fume_part(k, mx + FUME_DRIFT[0] * t, my + FUME_DRIFT[1] * t)
        frames.append(sheet.frame([part] + base))          # R4：烟团画在本体之后（排气管口在烟团之前）
        holds.append(FUME_HOLD)
        t += FUME_HOLD
    frames.append(sheet.frame(base))
    holds.append(FUME_GAP)
    return loop(frames, holds, first=[op(3, 1)])


# ---------------------------------------------------------------- 组装
def build():
    global HATCHES
    HATCHES = G.hatch_slots()
    del ATTACKS[1:]
    sheet = Sheet2()
    walk1 = [first_base(k) for k in range(6)]
    stand1 = first_base(0)
    walk2 = [second_base('a', k) for k in range(6)]
    stand2 = second_base('a', 0)
    w1 = [sheet.frame(p) for p in walk1]
    w2 = [sheet.frame(p) for p in walk2]
    s1, s2 = sheet.frame(stand1), sheet.frame(stand2)
    sc = sheet.scripts
    sc[0] = sc[6] = sc[11] = idle_loop(sheet, stand1)
    sc[1] = sc[7] = loop(w1, [WALK_HOLD] * 6, first=[op(3, 1)])
    sc[16] = sc[22] = sc[27] = idle_loop(sheet, stand2)
    sc[17] = sc[23] = loop(w2, [WALK_HOLD] * 6, first=[op(3, 1)])
    sc[9] = normal_attack_first(sheet)
    sc[2] = normal_attack_first(sheet, damage=False)
    sc[10] = special_first(sheet)
    sc[25] = giant_attack(sheet)
    sc[18] = giant_attack(sheet, damage=False)
    sc[26] = giant_attack(sheet, special=True)
    sc[12] = sc[14] = knockback(sheet, walk1, stand1)
    sc[30] = knockback(sheet, walk2, stand2)
    sc[28] = form_change(sheet)
    sc[13] = sc[15] = death(sheet)
    sc[SLOT_FIRE] = fire_column(sheet)
    sc[SLOT_SMOKE] = smoke_puff(sheet)
    return sheet


def finish(sheet):
    """两页装箱；返回 (OBM 字节列表, 描述符, 动作脚本, 页图像列表)。"""
    pages_tiles = {0: [], 1: []}
    index = {}
    for t, (img, _) in enumerate(sheet.tiles):
        path = [k for k, v in sheet.tile_index.items() if v == t][0]
        p = page_of(path)
        index[t] = (p, len(pages_tiles[p]))
        pages_tiles[p].append(img)
    packed = {p: shelf_pack(tiles) for p, tiles in pages_tiles.items()}
    rects = []
    for t, ax, ay in sheet.rects:
        p, i = index[t]
        img = pages_tiles[p][i]
        x, y = packed[p][1][i]
        rects.append([x, y, img.width, img.height, ax, ay, 0, p])
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
    for slot in range(SCRIPT_COUNT):
        animations.setdefault(str(slot), [op(0, -1), op(1, 1), op(21)])
    desc = {'rects': rects, 'frames': words, 'script_count': SCRIPT_COUNT,
            'hit_bounds': [[0, 0, 0, 0, 0], HIT_RECT, [0, 0, 0, 0, 0]],
            'attack_bounds': [list(r) for r in ATTACKS]}
    images = [packed[p][0] for p in (0, 1)]
    return [indexed_obm(im) for im in images], desc, animations, images


def render(sheet, key, origin=(420, 330), size=(1200, 400)):
    img = Image.new('RGBA', size, (52, 56, 66, 255))
    for r in key:
        t, ax, ay = sheet.rects[r]
        tile, _ = sheet.tiles[t]
        img.alpha_composite(tile, (origin[0] - ax, origin[1] - ay))
    return img


def preview(sheet, slots, path, step=4, cols=3, size=(1000, 420), origin=(600, 360)):
    from PIL import ImageDraw
    picks = []
    for slot in slots:
        t = 0
        for cmd in sheet.scripts[slot]:
            if cmd['opcode'] == 0:
                cur = cmd['values'][0]
            if cmd['opcode'] == 1:
                for _ in range(cmd['values'][0]):
                    if t % step == 0 and isinstance(cur, tuple):
                        picks.append((slot, t, cur))
                    t += 1
    W, H = size
    rows = math.ceil(len(picks) / cols)
    out = Image.new('RGB', (W * cols // 2, H * rows // 2), (30, 30, 30))
    for n, (slot, t, key) in enumerate(picks):
        im = render(sheet, key, origin, size)
        d = ImageDraw.Draw(im)
        d.line([(0, origin[1]), (W, origin[1])], fill=(80, 200, 255, 120))
        d.line([(origin[0], 0), (origin[0], H)], fill=(255, 80, 80, 120))
        x0 = origin[0] - FRONT
        d.line([(x0, origin[1] - 4), (x0, origin[1] + 4)], fill=(255, 255, 0))
        d.line([(x0 - RANGE // WORLD, origin[1] - 8), (x0 - RANGE // WORLD, origin[1] + 8)], fill=(255, 255, 0))
        d.text((6, 4), f'slot {slot} t {t}', fill=(255, 255, 255))
        out.paste(im.convert('RGB').resize((W // 2, H // 2), Image.BOX), ((n % cols) * W // 2, (n // cols) * H // 2))
    out.save(path)
    return len(picks)


def icon_atlas():
    raw = bytearray((CONTENT / ICON_ATLAS).read_bytes())
    assert raw[:4] == b'OI\x01\x20'
    w, h = map(int, np.frombuffer(bytes(raw[4:8]), '<u2'))
    for unit_file_ in (CONTENT / 'units').glob('*.json'):
        unit = json.loads(unit_file_.read_text(encoding='utf-8'))
        if unit['key'] == KEY or 'atlas' in unit['icon']:
            continue
        x, y, iw, ih = unit['icon']['rect']
        assert (x + iw <= ICON_AT[0] or x >= ICON_AT[0] + ICON_SIZE or y + ih <= ICON_AT[1]
                or y >= ICON_AT[1] + ICON_SIZE), unit['key']
    src = Image.open(G.FRAMES / G.D['icon'][0]['file']).convert('RGBA')
    icon = src.crop((ICON_CROP[0], ICON_CROP[1], ICON_CROP[0] + ICON_SIZE, ICON_CROP[1] + ICON_SIZE))
    for j in range(ICON_SIZE):
        for i in range(ICON_SIZE):
            at = 8 + ((ICON_AT[1] + j) * w + ICON_AT[0] + i) * 4
            raw[at:at + 4] = bytes(icon.getpixel((i, j)))
    return bytes(raw), icon


def unit_file(animations):
    return {
        'key': KEY, 'base_id': 313, 'faction': 1, 'identity': 'Rebel Army',
        'shop_price': STATS['shop_price'], 'available_from_start': True, 'ap': STATS['ap'],
        'upgrade_cost_base': STATS['upgrade_cost_base'],
        'hp_multiplier': STATS['hp_multiplier'],
        'knockback_threshold_multiplier': STATS['knockback_threshold_multiplier'],
        'production_reference_id': 313, 'production_interval_multiplier': STATS['production_interval_multiplier'],
        'damage_multiplier': STATS['damage_multiplier'], 'special_damage_multiplier': STATS['special_damage_multiplier'],
        'move_speed_multiplier': STATS['move_speed_multiplier'], 'knockback_distance_multiplier': [1, 1],
        # 状态词 7 开始攻击的距离；24 / 31 普通 / 特殊攻击每个攻击框的命中目标数（爆炸范围内全部）；35 / 36 绝招冷却（之后 / 出场后第一次）
        'status_word_values': {'7': RANGE, '24': 99, '31': 99, '35': 2100, '36': 1400},
        # 小地图标记：按原版大型单位标记与图像尺寸（世界单位）的比例（宽约 1/25、高约 1/21.5）
        'minimap_marker': [31, 20],
        'icon': {'page': 1, 'rect': [*ICON_AT, ICON_SIZE, ICON_SIZE], 'anchor': ICON_ANCHOR},
        'textures': TEXTURES, 'sprite_descriptor': DESCRIPTOR, 'animations': animations,
        'behaviors': [
            {'name': 'hp_stage_animations', 'version': 1,
             'params': {'thresholds': [STAGE_THRESHOLD], 'transitions': [1], 'rage_stage': 1,
                        'rage_speed_multiplier': [1, 1], 'rage_damage_multiplier': RAGE_DAMAGE}},
            {'name': 'stage_knockback_animation', 'version': 1, 'params': {}},
        ],
        'localization': {code: {'name': n, 'description': d} for code, (n, d) in TEXT.items()},
        'tags': ['ms6', 'msa'],
    }


def encode_ogg(wav, target):
    import soundfile as sf
    data, rate = sf.read(str(wav), always_2d=True)
    with sf.SoundFile(str(target), 'w', samplerate=rate, channels=data.shape[1], format='OGG', subtype='VORBIS') as f:
        for i in range(0, len(data), 4096):          # 分块写入（libsndfile 一次写入大量帧会中止，第 2 节 PvZ 配乐的做法）
            f.write(data[i:i + 4096])


def main():
    OUT.mkdir(exist_ok=True)
    sheet = build()
    obms, desc, animations, images = finish(sheet)
    n1 = preview(sheet, [9], OUT / 'preview_normal.png', step=3)
    n2 = preview(sheet, [10], OUT / 'preview_special.png', step=4)
    n3 = preview(sheet, [25], OUT / 'preview_giant.png', step=3)
    n4 = preview(sheet, [28, 13], OUT / 'preview_change_death.png', step=4)
    n5 = preview(sheet, [7, 23, 14, 30], OUT / 'preview_walk.png', step=2, cols=4)
    report = {'pages': [list(im.size) for im in images], 'rects': len(desc['rects']), 'frame_words': len(desc['frames']),
              'colors': [len(set(im.getdata())) for im in images], 'attack_boxes': len(ATTACKS) - 1,
              'hatches': HATCHES, 'origin_R': G.origin(), 'script_lengths': {
                  s: sum(c['values'][0] for c in sheet.scripts[s] if c['opcode'] == 1) for s in sorted(sheet.scripts)}}
    for n, im in enumerate(images):
        im.save(OUT / f'atlas_{n}.png')
    if '--preview' in sys.argv:
        print(json.dumps(report, ensure_ascii=False))
        return
    icon_raw, icon = icon_atlas()
    files = {TEXTURES[0]: obms[0], TEXTURES[1]: obms[1], ICON_ATLAS: icon_raw}
    index = json.loads((CONTENT / 'content.json').read_text(encoding='utf-8'))
    if KEY not in index['unit_ids']:
        index['unit_ids'][KEY] = max(index['unit_ids'].values()) + 1
    for name, raw in files.items():
        (CONTENT / name).write_bytes(raw)
        if index['assets'].get(name, '') is not None:     # unit_icon_02.obm 登记为 null（不做摘要核对）
            index['assets'][name] = hashlib.blake2b(raw, digest_size=32).hexdigest()
    sounds = [e for e in index.get('sounds', []) if not e['key'].startswith('s1xlv.isentinel_')]
    for name, source in SOUNDS.items():
        target = f'isentinel_{name}.msdf'
        encode_ogg(SOUND_SOURCE / f'{source}.wav', CONTENT / target)
        sounds.append({'key': SND[name], 'file': target, 'type': 'se'})
    index['sounds'] = sounds
    pvz.save_json(CONTENT / DESCRIPTOR, desc)
    pvz.save_json(CONTENT / 'units' / 'iron_sentinel.json', unit_file(animations))
    pvz.save_json(CONTENT / 'content.json', index)
    icon.resize((ICON_SIZE * 8, ICON_SIZE * 8), Image.NEAREST).save(OUT / 'icon_8x.png')
    report['unit_id'] = index['unit_ids'][KEY]
    (OUT / 'build_report.json').write_text(json.dumps(report, ensure_ascii=False, indent=2), encoding='utf-8')
    print(json.dumps(report, ensure_ascii=False))


if __name__ == '__main__':
    main()
