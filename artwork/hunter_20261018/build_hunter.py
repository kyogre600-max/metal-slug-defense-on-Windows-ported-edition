"""Hunter（s1xlv.hunter，《合金弹头6》第 2 关的原住民猎人）资源与单位文件生成（2026-10-18）。

素材：source/MS6_Hunter.png（The Spriters Resource，The Mad Soldier 整理），由 cut_frames.py 切帧并计算锚点（frames/、frames.json）；
炸药爆炸取原版叛军步兵（UnitID 2）槽 16 的手榴弹爆炸 8 帧（source/grenade/）。复用 PvZ 生成脚本的 Sheet、finish 与动作片段工具。

基准为原版原住民（鸟）NATIVE(BIRD)，UnitID 221（BattleAction_NativeBird：状态 10/20/30/40/50/70/80/100·110·120
依次使用槽 6/7/8/9/10/30/11/12；死亡动作播完后消失）。普通攻击 op22 以槽 26 为弹体（原生 BulletAction_NativeBird：高抛，
最高点在战场 y 110 附近，落点为普通攻击目的距离）；特殊攻击的 5 颗由行为 lob_blast 按射程等距分布（弹体槽 40–44）。
素材朝左（前方为 −x，同原住民（鸟））。

用户设定（2026-10-18）：Lv40 生命 4000、AP 80、射程 400、每颗炸药 Lv40 840；炸药可以炸到空中单位；爆炸范围为叛军步兵
手榴弹的 125%（暂定）；落地后引信燃烧一会儿再爆炸，碰到敌人立即爆炸；特殊攻击同时投出 5 颗，在射程 400 内平均分布
（按射程计算，射程改变时落点随之改变），同日改为与原住民（鸟）的连投相同的间隔逐颗投出（每颗间隔 16 tick），
由近至远；死亡区分普通、爆炸、火焰击杀（同小兵）；爆炸图像用手榴弹的，爆炸声先用 B4_EXP2；
再出击时间为原住民（鸟）的 160%，移速慢 10%，特殊攻击冷却为原住民（鸟）的 125%。其余数值为暂定（见 PROVISIONAL）。

运行：windows_runtime/python.exe artwork/hunter_20261018/build_hunter.py
（写入 community_content/ 与本目录 out/；头像写入 community_content/unit_icon_02.obm 的空位；死亡音效从 source/sounds/
复制为 community_content/hunter_*.msdf 并登记在 content.json 的 sounds）。
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

KEY = 's1xlv.hunter'
TEXTURE, DESCRIPTOR = 'hunter.obm', 'hunter_descriptor.json'
ICON_ATLAS = 'unit_icon_02.obm'
# 头像：同原住民（鸟）等原版小兵的全身头像（面朝右）。待机第 1 帧水平翻转、不缩放，底边放在选单位格内框底边（格内 y 45），
# 横向居中（43 像素宽，两侧各越过边框 1–2 像素，同原版部分头像）。
ICON_AT, ICON_CLEAR = (1550, 768), 46

# 音效（MS6 第 2 关音效库 MS6_OST_ST02.osb 的原住民语音，manatools 转出的 WAV，source/sounds/ 为其 Ogg Vorbis；
# 由 MS6 视频 https://www.youtube.com/watch?v=UWAYQW8mMks 6:38–7:25 的频谱峰指纹比对推定，见
# verification/hunter_prep_20261018/README.md）。音量与游戏内小兵死亡语音相当（100 ms 响度 9774–13737，B4_DET4M 16014、
# B4_DET2M 12477），不加增益。
SOUND_SOURCE = HERE / 'source' / 'sounds'
# R4（2026-10-18）：语音按用户的分配：NDEATH 普通死亡、SDEATH 爆炸死亡、SURPRISE 火焰死亡（各两个版本，见 death_by_attribute
# 的 *_variant_animation），CHEER1 投炸药、CHEER2 砍刀（取代原先借用的 B4_HATK2 喊声）。
SOUNDS = {          # 名称 → MS6 原名；音效键为 s1xlv.hunter_<名称>，文件为 community_content/hunter_<名称>.msdf
    'death1': 'SE_MIN_NDEATH1',      # 普通击杀
    'death2': 'SE_MIN_NDEATH2',      # 普通击杀（另一版本）
    'blast1': 'SE_MIN_SDEATH1',      # 爆炸击杀（血花）
    'blast2': 'SE_MIN_SDEATH2',      # 爆炸击杀（另一版本）
    'fire1': 'SE_MIN_SURPRISE1',     # 火焰击杀
    'fire2': 'SE_MIN_SURPRISE2',     # 火焰击杀（另一版本）
    'throw': 'SE_MIN_CHEER1',        # 投炸药（普通攻击与特殊攻击的每一颗）
    'melee': 'SE_MIN_CHEER2',        # 砍刀
}
SND = {name: f's1xlv.hunter_{name}' for name in SOUNDS}
KNIFE = 207          # 挥刀 B4_KNIFE（原住民 112 的近战同用）
BLAST = 202          # 爆炸 B4_EXP2（叛军步兵手榴弹；用户指定先试用）
FIRE_HIT = 283       # 火焰击杀的燃烧声 fire_hit_s（叛军步兵火焰死亡同用）

# 槽位
S_DYN, S_WAIT, S_BLAST, S_FUSE = 26, 30, 32, 33
S_SPREAD, SPREAD = 40, 5          # 特殊攻击的 5 颗炸药：弹体槽 40–44（lob_blast.special_spread_*）
S_DEATH_BLAST, S_DEATH_FIRE = 14, 16
# 三种死亡的另一版本（只换语音；death_by_attribute 的 *_variant_animation，死亡时横坐标取整为奇数时播放）
S_DEATH_NORMAL_ALT, S_DEATH_BLAST_ALT, S_DEATH_FIRE_ALT = 45, 46, 47
SCRIPT_COUNT = 48
RELEASE = (-20, -20)              # 投出点（素材像素，相对单位原点，前方为 −x）：投掷第 11 帧前伸的手
# 攻击框：1 飞行中的炸药，2 砍刀（同原住民（鸟）的近战框），3 落地爆炸（手榴弹 (-18,-34,38,38) 的 125%，绕原点放大），
# 4 空中碰到敌人时的爆炸（框与爆炸图像下移 BLAST_DROP，以碰撞点为中心）。第 5 个值同原住民（鸟）的攻击框（7）。
BLAST_DROP = 16
DYN_RECT = [-9, -9, 18, 18, 7]
MELEE_RECT = [-44, -51, 49, 58, 7]
BLAST_RECT = [-23, -43, 48, 48, 7]
BLAST_AIR_RECT = [-23, -43 + BLAST_DROP, 48, 48, 7]
HIT_RECT = [-12, -38, 24, 38, 0]  # 本体受击框（待机第 1 帧除砍刀外的身体）
FUSE_TICKS = 1                    # 落地炸药每帧停留：燃烧 17 帧 + 闪烁 6 帧，约 23 tick（0.77 秒，暂定）
# R2（2026-10-18，用户实机反馈：奔跑时身体看起来错位，绝招就绪标记与光柱以单位原点为中心）：cut_frames.py 以上身对齐奔跑与待机，
# 奔跑时身体前倾、腿伸在前面，各帧身体（除刀刃与描边外的像素）重心平均在原点前方 8.9 素材像素（待机 −0.2，原住民（鸟）的待机与
# 行走为 0）；奔跑整组后移 RUN_DX，帧间相对位置不变。
RUN_DX = 9
# R2：待机 4 帧往返播放（1 2 3 4 3 2 1 2 …，同原住民（鸟）待机的往返），此前为 1 2 3 4 1 2 3 4，第 4 帧跳回第 1 帧不自然。
IDLE_ORDER = (0, 1, 2, 3, 2, 1)
# R4（2026-10-18，用户要求按普通原住民（UnitID 112）的帧率播放）：每帧停留取原住民（112）同一阶段的平均每帧时长（四舍五入，至少 1 tick）。
# 原住民（112）：待机 5/3/5/3（平均 4，与此前相同，不改）；行走 12 帧各 1 tick；砍刀（槽 8）举刀 6 帧 7 tick、带攻击框 4 帧 6 tick、
# 收刀 4 帧 6 tick；投掷（槽 9）举起 6 帧各 2 tick、投出后 7 帧 9 tick；普通死亡（槽 13）倒下 3 帧各 1 tick；火焰死亡（槽 14）各 2 tick。
# 特殊攻击每颗的间隔（16 tick，用户指定同原住民（鸟））、受击滑行（时序与位移同原住民（鸟））与爆炸死亡（112 无对应动作）不变。
RUN_HOLD = 1
MELEE_HOLDS = ((1, 1), (2, 2), (2, 2, 2, 2))          # 举刀 2 帧、挥砍 2 帧（攻击框开 4 tick，同此前）、收刀 4 帧：共 14 tick（此前 20）
NORMAL_THROW_HOLDS = [2] * 6 + [1] * 5               # 举起点燃 6 帧（同此前，投出时刻不变）、投出后 5 帧：共 17 tick（此前 23）
FALL_HOLD = 1
# 动作缩短的 tick 加到攻击后的等待中，攻击间隔保持不变：投炸药后等待（状态词 27）20 → 26；砍刀后等待（状态词 20）0 → 7
# （等待 n 时原生在状态 10 停留 n−1 帧，0 时不进入等待；实测投炸药 24+19 → 18+25 帧，砍刀 21+0 → 15+6 帧）。
THROW_WAIT, MELEE_WAIT = 26, 7

AP = 80
HP_MULTIPLIER = [4, 3]            # 原住民（鸟）Lv40 3000 → 4000（用户设定）
KNOCKBACK_THRESHOLD = [4, 3]      # 随生命倍率（AGENTS 第 6.1 节）：20 → 27
PRODUCTION = [8, 5]               # 再出击 300 → 480 tick（用户设定：+60%）
MOVE_SPEED = [6, 5]               # 3.7 → 4.44（用户设定：原住民（鸟）的 120%；R5 起，此前为慢 10%）
SPECIAL_COOLDOWN = [5, 4]         # 绝招冷却 160 / 80 → 200 / 100 tick（用户设定：125%）
RANGE = 400                       # 射程 400（用户设定）：开火距离（词 7）、普通与特殊攻击的弹体目的距离（词 26、33）
BOMB = [280, 420, 560, 700, 840, 980]   # 每颗炸药 Lv1/10/20/30/40/50（原住民（鸟）火把 260…910 × 14/13；Lv40 840 为用户设定）

PROVISIONAL = {   # 用户未指定、暂定的数值（待确认）
    'shop_price': 100,
    'fuse_ticks': 23,
}

TEXT = {
    'EN': ('HUNTER', 'STAND. ATK : Dynamite     SPEC. ATK : Dynamite x5\n'
                     'A hunter of the swamp tribe, armed with a machete.\nHis lit dynamite blows up on contact or when the fuse burns out.'),
    'JP': ('ハンター', '通常攻撃：ダイナマイト   特殊攻撃：ダイナマイト5連投\n山刀を持つ沼地の部族の狩人。\n'
                    '火の付いたダイナマイトは敵に触れるか、導火線が燃え尽きると爆発する。'),
    'KR': ('헌터', '일반 공격: 다이너마이트   특수 공격: 다이너마이트 5연투\n마체테를 든 늪지 부족의 사냥꾼.\n'
                 '불붙은 다이너마이트는 적에게 닿거나 도화선이 다 타면 폭발한다.'),
    'ES': ('CAZADOR', 'ATQ. ESTÁND.: Dinamita     ATQ. ESPEC.: Dinamita x5\n'
                      'Cazador de la tribu del pantano, armado con un machete.\n'
                      'Su dinamita estalla al tocar al enemigo o al consumirse la mecha.'),
    'PT': ('CAÇADOR', 'ATQ. PADR.: Dinamite     ATQ. ESPEC.: Dinamite x5\n'
                      'Caçador da tribo do pântano, armado com um facão.\n'
                      'Sua dinamite explode ao tocar o inimigo ou quando o pavio acaba.'),
    'RU': ('ОХОТНИК', 'СТАНД. АТАК: Динамит     СПЕЦ. АТАК: Динамит x5\n'
                      'Охотник болотного племени с мачете.\nЕго динамит взрывается от удара о врага или когда догорит фитиль.'),
    'FR': ('CHASSEUR', 'ATT. STAND : Dynamite     ATT. SPÉ : Dynamite x5\n'
                       'Chasseur de la tribu des marais, armé d\'une machette.\n'
                       'Sa dynamite explose au contact ou quand la mèche est consumée.'),
    'DE': ('JÄGER', 'STAND. ATK : Dynamit     SPEC. ATK : Dynamit x5\n'
                    'Ein Jäger des Sumpfstammes mit einer Machete.\nSein Dynamit explodiert bei Kontakt oder wenn die Lunte abbrennt.'),
    'IT': ('CACCIATORE', 'ATC STAND.: Dinamite     ATC SPEC.: Dinamite x5\n'
                         'Cacciatore della tribù della palude, armato di machete.\n'
                         'La sua dinamite esplode al contatto o quando la miccia si consuma.'),
    'ZT': ('獵人', '普通攻擊：炸藥     特殊攻擊：炸藥五連投\n手持砍刀的沼澤部落獵人。\n點燃的炸藥碰到敵人或引信燒完時爆炸。'),
    'ZS': ('猎人', '普通攻击：炸药     特殊攻击：炸药五连投\n手持砍刀的沼泽部落猎人。\n点燃的炸药碰到敌人或引信烧完时爆炸。'),
}


def fr(sheet, name, i, dx=0, dy=0):
    f = DATA[name][i]
    return sheet.f(FRAMES / f['file'], f['ax'], f['ay'], dx, dy)


def frames(sheet, name, indices=None, dx=0, dy=0):
    return [fr(sheet, name, i, dx, dy) for i in (indices if indices is not None else range(len(DATA[name])))]


def blink(frame, times=3):
    return [c for _ in range(times) for c in F(-1, 2) + F(frame, 2)] + F(-1, 1)


def melee_script(sheet):
    """砍刀：举刀（第 8、7 帧）→ 挥砍（第 1、2 帧带刀光，攻击框 2）→ 收刀（第 3–6 帧，刀垂在前方，接回待机）。
    R2：去掉收尾的第 11、12 帧（下蹲后起身，身体重心比其余各帧靠后 6–12 素材像素，回到待机时向前跳）。
    R4：去掉借用的喊声 B4_HATK2，改为 MS6 原住民语音 CHEER2（用户指定），挥刀声保留。"""
    s = frames(sheet, 'slash')
    up, hit, down = MELEE_HOLDS
    out = [op(3, 1)] + F(s[7], up[0]) + F(s[6], up[1])
    out += [op(4, 2), op(23, SND['melee']), op(23, KNIFE)] + F(s[0], hit[0]) + F(s[1], hit[1]) + [op(4, -1)]
    for i, w in zip((2, 3, 4, 5), down):
        out += F(s[i], w)
    return out + [op(21)]


def throw_script(sheet, shots, indices, holds):
    """投炸药：举刀、点燃（火花）→ 第 11 帧前伸投出（shots 为 op22 的弹体槽；空列表为菜单演示）→ 收势。"""
    t = frames(sheet, 'throw')
    out = [op(3, 1)]
    for i, w in zip(indices, holds):
        if i == 10:
            out += [op(22, slot, 1, *RELEASE) for slot in shots] + ([op(23, SND['throw'])] if shots else [])
        out += F(t[i], w)
    return out + [op(21)]


NORMAL_THROW = ([4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16], NORMAL_THROW_HOLDS)
# 特殊攻击：同原住民（鸟）槽 10 的连投节奏（每颗一轮 16 tick，第 6 tick 投出：F78 w4、F80 w2、投出、F82 w2、F84 w4、F82 w2、
# F80 w2），5 颗由近至远（弹体槽 40–44，落点为射程的 1/5…5/5）。每轮：举起点燃的炸药（第 9、10 帧）→ 前伸投出（第 11 帧）→
# 收回（第 12–14 帧）；第一轮前先点燃（第 7、8 帧）。
SPECIAL_CYCLE = ((8, 4), (9, 2), (10, 2), (11, 4), (12, 2), (13, 2))


def special_script(sheet):
    t = frames(sheet, 'throw')
    out = [op(3, 1)] + F(t[6], 2) + F(t[7], 2)
    for k in range(SPREAD):
        for i, w in SPECIAL_CYCLE:
            if i == 10:
                out += [op(22, S_SPREAD + k, 1, *RELEASE), op(23, SND['throw'])]
            out += F(t[i], w)
    for i in (14, 15, 16):
        out += F(t[i], 2)
    return out + [op(21)]


def knockback_script(sheet):
    """受击滑行（同原住民（鸟）槽 11 的时序与位移）：后仰第 2、3、4 帧。"""
    r = frames(sheet, 'recoil')
    return ([op(4, -1), op(7, 300, 0, -10, 0)] + F(r[1], 2) + F(r[2], 2) + F(r[3], 10) + F(r[2], 2)
            + [op(16)] + F(r[1], 2) + [op(21)])


def death_normal(sheet, voice):
    f = frames(sheet, 'fall')
    return once(f + [f[-1]], [FALL_HOLD] * len(f) + [20], first=[op(4, -1), op(23, SND[voice])], tail=blink(f[-1]))


def death_blast(sheet, voice):
    b = frames(sheet, 'blood')
    return once(b, [2] * len(b), first=[op(4, -1), op(23, SND[voice])], tail=F(-1, 1))


def death_fire(sheet, voice):
    burn, ash = frames(sheet, 'burn'), frames(sheet, 'ash')
    seq = burn + burn + ash + [ash[-1]]
    return once(seq, [2] * (len(seq) - 1) + [20], first=[op(4, -1), op(23, FIRE_HIT), op(23, SND[voice])],
                tail=blink(ash[-1]))


def dynamite_flight(sheet):
    return loop(frames(sheet, 'dyn_fly'), [1] * len(DATA['dyn_fly']), first=[op(4, 1)])


def blast(sheet, rect, dy):
    """手榴弹爆炸（叛军步兵槽 16 的时序：攻击框开 4 tick，共 8 tick）。"""
    g = frames(sheet, 'grenade', dy=dy)
    return [op(4, rect), op(23, BLAST)] + F(g[0], 1) + F(g[1], 1) + F(g[2], 1) + F(g[3], 1) + [op(4, -1)] + \
        F(g[4], 1) + F(g[5], 1) + F(g[6], 1) + F(g[7], 1) + F(-1, 1) + [op(21)]


def fuse_script(sheet):
    """落地：引信燃烧（17 帧）→ 闪烁（6 帧）→ 爆炸。"""
    out = [op(4, -1)]
    for f in frames(sheet, 'dyn_lie'):
        out += F(f, FUSE_TICKS)
    return out + blast(sheet, 3, 0)


def build():
    sheet = pvz.Sheet()
    idle, run = frames(sheet, 'idle'), frames(sheet, 'run', dx=RUN_DX)
    idle_seq = [idle[i] for i in IDLE_ORDER]
    sheet.scripts[0] = sheet.scripts[6] = sheet.scripts[S_WAIT] = loop(idle_seq, [4] * len(idle_seq), first=[op(3, 1)])
    sheet.scripts[1] = sheet.scripts[7] = loop(run, [RUN_HOLD] * len(run), first=[op(3, 1)])
    sheet.scripts[2] = throw_script(sheet, [], *NORMAL_THROW)
    sheet.scripts[8] = melee_script(sheet)
    sheet.scripts[9] = throw_script(sheet, [S_DYN], *NORMAL_THROW)
    sheet.scripts[10] = special_script(sheet)
    sheet.scripts[11] = knockback_script(sheet)
    sheet.scripts[12] = death_normal(sheet, 'death1')
    sheet.scripts[S_DEATH_NORMAL_ALT] = death_normal(sheet, 'death2')
    fall = frames(sheet, 'fall')
    sheet.scripts[13] = F(fall[-1], 20) + blink(fall[-1]) + [op(21)]   # 原生着地后的槽（死亡中被抛起才会用到）
    sheet.scripts[S_DEATH_BLAST] = death_blast(sheet, 'blast1')
    sheet.scripts[S_DEATH_BLAST_ALT] = death_blast(sheet, 'blast2')
    sheet.scripts[S_DEATH_FIRE] = death_fire(sheet, 'fire1')
    sheet.scripts[S_DEATH_FIRE_ALT] = death_fire(sheet, 'fire2')
    sheet.scripts[S_DYN] = dynamite_flight(sheet)
    for i in range(SPREAD):
        sheet.scripts[S_SPREAD + i] = dynamite_flight(sheet)
    sheet.scripts[S_BLAST] = blast(sheet, 4, BLAST_DROP)
    sheet.scripts[S_FUSE] = fuse_script(sheet)
    return pvz.finish(sheet, SCRIPT_COUNT, HIT_RECT, [DYN_RECT, MELEE_RECT, BLAST_RECT, BLAST_AIR_RECT])


def icon_image():
    f = DATA['idle'][0]
    return Image.open(FRAMES / f['file']).convert('RGBA').transpose(Image.FLIP_LEFT_RIGHT)


def icon_atlas():
    """头像写入社区合并图集（RGBA32）的空位；目标区域须为空或为本单位先前写入。"""
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
    img = icon_image()
    for j in range(ICON_CLEAR):
        for i in range(ICON_CLEAR):
            at = 8 + ((ICON_AT[1] + j) * w + ICON_AT[0] + i) * 4
            raw[at:at + 4] = bytes(img.getpixel((i, j)) if i < img.width and j < img.height else (0, 0, 0, 0))
    # 格内位置：横向居中（50 宽的格），底边在 45
    anchor = [-((50 - img.width) // 2), -(45 - img.height)]
    return bytes(raw), img, {'page': 1, 'rect': [*ICON_AT, img.width, img.height], 'anchor': anchor}


def unit_file(animations, icon):
    status = {'7': RANGE, '26': RANGE, '33': RANGE, '22': BOMB, '29': BOMB, '20': MELEE_WAIT, '27': THROW_WAIT}
    return {
        'key': KEY, 'base_id': 221, 'faction': 4, 'identity': 'Native',
        'shop_price': PROVISIONAL['shop_price'], 'available_from_start': True, 'ap': AP,
        'hp_multiplier': HP_MULTIPLIER, 'knockback_threshold_multiplier': KNOCKBACK_THRESHOLD,
        'production_reference_id': 221, 'production_interval_multiplier': PRODUCTION,
        'move_speed_multiplier': MOVE_SPEED, 'special_cooldown_multiplier': SPECIAL_COOLDOWN,
        'damage_multiplier': [1, 1], 'special_damage_multiplier': [1, 1], 'knockback_distance_multiplier': [1, 1],
        # 状态词 7 开火距离、26/33 普通与特殊攻击的弹体目的距离（特殊攻击按 lob_blast 在 33 内等距分布）、22/29 每颗炸药伤害、20/27 砍刀与投炸药后的等待（R4）；
        # 攻击属性：砍刀 0（普通击杀），炸药 2（爆炸击杀）
        'status_word_values': status,
        'attack_attributes': {'melee': 0, 'normal': 2, 'special': 2},
        'behaviors': [
            {'name': 'lob_blast', 'version': 1,
             'params': {'blast_animation': S_BLAST, 'fuse_animation': S_FUSE,
                        'special_spread_first': S_SPREAD, 'special_spread_count': SPREAD}},
            {'name': 'death_by_attribute', 'version': 1,
             'params': {'explosion_animation': S_DEATH_BLAST, 'fire_animation': S_DEATH_FIRE,
                        'normal_variant_animation': S_DEATH_NORMAL_ALT, 'explosion_variant_animation': S_DEATH_BLAST_ALT,
                        'fire_variant_animation': S_DEATH_FIRE_ALT}},
        ],
        'icon': icon,
        'textures': [TEXTURE], 'sprite_descriptor': DESCRIPTOR, 'animations': animations,
        'localization': {code: {'name': n, 'description': d} for code, (n, d) in TEXT.items()},
        'tags': ['ms6'],
    }


def main():
    OUT.mkdir(exist_ok=True)
    obm, desc, animations, page = build()
    icon_raw, icon_img, icon = icon_atlas()
    files = {TEXTURE: obm, ICON_ATLAS: icon_raw}
    index = json.loads((CONTENT / 'content.json').read_text(encoding='utf-8'))
    if KEY not in index['unit_ids']:
        index['unit_ids'][KEY] = max(index['unit_ids'].values()) + 1
    for name, raw in files.items():
        (CONTENT / name).write_bytes(raw)
        if index['assets'].get(name, '') is not None:     # unit_icon_02.obm 登记为 null（不做摘要核对）
            index['assets'][name] = hashlib.blake2b(raw, digest_size=32).hexdigest()
    sounds = [e for e in index.get('sounds', []) if not e['key'].startswith('s1xlv.hunter_')]
    for old in CONTENT.glob('hunter_*.msdf'):        # 不再使用的音效文件（R4 起 hunter_blood 改为 hunter_blast1/2）
        if old.stem[len('hunter_'):] not in SOUNDS:
            old.unlink()
    for name, source in SOUNDS.items():
        target = f'hunter_{name}.msdf'
        shutil.copyfile(SOUND_SOURCE / f'{source}.ogg', CONTENT / target)
        sounds.append({'key': SND[name], 'file': target, 'type': 'se'})
    index['sounds'] = sounds
    pvz.save_json(CONTENT / DESCRIPTOR, desc)
    pvz.save_json(CONTENT / 'units' / 'hunter.json', unit_file(animations, icon))
    pvz.save_json(CONTENT / 'content.json', index)
    page.save(OUT / 'hunter_atlas.png')
    icon_img.resize((icon_img.width * 8, icon_img.height * 8), Image.NEAREST).save(OUT / 'icon_8x.png')
    report = {'unit_id': index['unit_ids'][KEY], 'atlas': list(page.size), 'rects': len(desc['rects']),
              'frame_words': len(desc['frames']), 'icon': icon}
    (OUT / 'build_report.json').write_text(json.dumps(report, ensure_ascii=False, indent=2), encoding='utf-8')
    print(json.dumps(report))


if __name__ == '__main__':
    main()
