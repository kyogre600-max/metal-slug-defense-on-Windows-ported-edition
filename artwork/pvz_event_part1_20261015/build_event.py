"""PVZ EVENT（本体 EVENT，游戏内名称 PVZ EVENT）：生成 community_content/events/pvz_part1.json、左屏封面、小关缩略图与俘虏页立绘。

第一、二大关（2026-10-15 用户设定）：
- 两个大关各 4 个小关；地点为美国东部（第一大关）与美国中部（第二大关），活动地图使用通用 EVENT 世界地图。
- 敌军等级：第一大关 5 / 10 / 15 / 20，第二大关 30 / 40 / 40 / 40。
- 强度系数（关卡强化，每级生命与攻击 +20%）：第一大关无；第二大关 0% / 40% / 60% / 100%。
- 敌军构成：1-1 普通；1-2 加路障；1-3 加铁桶；1-4 加读报；2-1 去掉普通、加橄榄球；2-2 去掉路障、加冰车；
  2-3 加巨人；2-4 只有读报、橄榄球、冰车、巨人。
- 战场：猫咪大战争的场地，第一大关白天草地（场景 116），第二大关黄昏（场景 117）；配乐为 Watery Graves Remix。
- 奖励：解救人质。第一大关各关人质 1 / 1 / 2 / 2，全部救出解锁小鬼僵尸；第二大关 3 / 3 / 5 / 7，全部救出解锁读报僵尸。
第三至五大关（2026-10-15 用户设定，直接加在本 EVENT 上）：
- 每大关 4 个小关，敌军全部 Lv40；战场为猫咪大战争的第三张场地（场景 118）；第三、四大关配乐沿用 Watery Graves，
  第五大关为用户提供的 Zombotany Remix。地点：第三大关加拿大东部（游戏内只写“加拿大”）、第四大关英国、第五大关阿拉斯加。
- 强度系数：第三大关 60% / 60% / 60% / 80%，第四大关 80% / 80% / 100% / 100%，第五大关 100% / 120% / 140% / 160%。
- 敌军构成与开战时已在场上的单位（“开门”）：
  3-1 普通、路障、铁桶、读报、橄榄球、冰车；3-2 读报、铁桶、橄榄球、倭瓜（开门 2 读报）；3-3 读报、橄榄球、冰车、倭瓜、机枪
  （开门 1 冰车）；3-4 橄榄球、倭瓜、机枪、辣椒（开门 2 机枪）；4-1 橄榄球、倭瓜、机枪、辣椒（开门 1 机枪 1 橄榄球）；
  4-2 机枪、辣椒、橄榄球、气球（开门 1 机枪 1 橄榄球）；4-3 机枪、辣椒、橄榄球、气球、小丑（开门 3 机枪）；4-4 机枪、辣椒、
  橄榄球、气球、小丑、巨人（开门 2 巨人）；5-1 辣椒、机枪、气球、巨人、小丑（开门 3 机枪）；5-2 冰车、机枪、气球、巨人、小丑
  （开门 2 冰车）；5-3 冰车、小丑、气球、巨人、橄榄球（开门 2 冰车）；5-4 冰车、小丑、巨人、橄榄球、机枪、辣椒（开门 4 辣椒）。
- 人质：第三大关 4 / 4 / 6 / 7（解锁倭瓜僵尸），第四大关 6 / 6 / 7 / 7（解锁辣椒僵尸），第五大关 7 / 7 / 8 / 8（解锁小丑僵尸）。
- 地图区域图标改为数字 1–5（原为 Boss 图标“!”）；俘虏页写入奖励单位名称（同原版“就能使用「…」！”），立绘为对应僵尸的待机帧；
  活动地图 BGM 用原版最新活动（合作活动）地图的 BGM 156。
出兵节奏参照猫咪大战争 PART1（historical_events/data/battle_cats_2015.json）：出兵表 1080 帧（36 秒）循环；我方前线
接近敌方据点时追加新登场的僵尸；大关最后一关的据点生命较高，据点生命降低时追加大波。道具放置表沿用该活动。
代理提出、未经用户指定的数值：各关出兵表与触发、据点生命、体力与 MSP（第二大关 30 / 5000，第三至五大关 40 / 6000、
50 / 8000、60 / 10000）、难度标签、开门单位的位置（敌方据点前 120 起每只间隔 60）。
用法：windows_runtime/python.exe artwork/pvz_event_part1_20261015/build_event.py
"""
from pathlib import Path
import json
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
import portable_launcher  # noqa: E402,F401  （随包 PIL 的 DLL 目录）
sys.path.insert(0, str(ROOT / 'windows_runtime' / 'packages'))
from PIL import Image  # noqa: E402

EVENTS = ROOT / 'community_content' / 'events'
HERE = Path(__file__).resolve().parent
COVER = 'pvz_part1_cover.png'
ASSETS = ROOT / 'game_data' / 'assets' / 'com.snkplaymore.android003'
FRAMES = ROOT / 'artwork' / 'pvz_zombies_20261012' / 'source'
KEY = 's1xlv.pvz_part1'
WATERY = 's1xlv.bgm_pvz_watery_graves'
ZOMBOTANY = 's1xlv.bgm_pvz_zombotany'
MAP_MUSIC = 156          # 原版最新活动（合作活动，WorldType 4）与 Survival 类活动的活动地图 BGM（SC_EventMSDStageLoop 0x1f8f38）
LOOP = 1080

NORMAL, CONE, BUCKET, NEWSPAPER = 's1xlv.pvz_zombie', 's1xlv.pvz_cone', 's1xlv.pvz_bucket', 's1xlv.pvz_newspaper'
FOOTBALL, ZOMBONI, GARGANTUAR, IMP = 's1xlv.pvz_football', 's1xlv.pvz_zomboni', 's1xlv.pvz_gargantuar', 's1xlv.pvz_imp'
JACK, BALLOON, GATLING = 's1xlv.pvz_jack', 's1xlv.pvz_balloon', 's1xlv.pvz_gatling'
JALAPENO, SQUASH = 's1xlv.pvz_jalapeno', 's1xlv.pvz_squash'

# 猫咪大战争各关相同的道具与俘虏放置表（x、离地高度、权重），道具等级 15。
CAT_ITEMS = [(411, 24, 2), (562, 80, 2), (791, 4, 2), (426, 182, 2), (640, 207, 2), (716, 122, 2)]
# 小关标记偏移（区域放大画面中相对画面中心），沿用一周年活动 4 关区域的排列。
MARKERS = [(-338, -55), (-132, -2), (75, -97), (240, 36)]
# 开门单位：场景 116–118 的敌方据点在 x=1300（SceneInfo 右边界 650 × 2），第一只在据点前 120，其后每只再前 60。
OPENING_X = [1180, 1120, 1060, 1000]


def stage(area, slot, *, level, roster, waves, triggers=(), placed=(), base_hp, prisoners, strength=0, difficulty=0):
    key = f'{KEY}.{area["id"]}.s{slot + 1}'
    # 开门单位不在出兵名单中时追加到敌军名单末尾，只供开战放置使用（出兵表与触发不引用）。
    roster = list(roster) + [unit for unit in dict.fromkeys(placed) if unit not in roster]
    index = {unit: i for i, unit in enumerate(roster)}
    entry = {
        'key': key, 'marker': list(MARKERS[slot]), 'thumbnail': area['thumbnail'],
        'template': 1011, 'scene': area['scene'], 'music': area['music'],
        'stamina': area['stamina'], 'reward_msp': area['msp'], 'enemy_base_hp': base_hp, 'strength_steps': strength,
        'enemies': [{'unit': unit, 'level': level} for unit in roster],
        'waves': [{'tick': tick, 'enemy': index[unit]} for tick, unit in waves],
        'loop': LOOP, 'difficulty': difficulty,
        'triggers': [dict(when=when, value=value, spawn=index[unit]) for when, value, unit in triggers],
        'prisoners': prisoners,
        'items': [{'x': x, 'y': y, 'weight': w} for x, y, w in CAT_ITEMS], 'item_level': 15, 'prisoner_chance': 100,
    }
    if placed:
        entry['placed'] = [{'enemy': index[unit], 'x': x} for unit, x in zip(placed, OPENING_X)]
    return entry


EAST = {'id': 'us_east', 'scene': 116, 'stamina': 20, 'msp': 3000, 'thumbnail': 'pvz_part1_day.png', 'music': WATERY}
CENTRAL = {'id': 'us_central', 'scene': 117, 'stamina': 30, 'msp': 5000, 'thumbnail': 'pvz_part1_dusk.png', 'music': WATERY}
CANADA = {'id': 'canada', 'scene': 118, 'stamina': 40, 'msp': 6000, 'thumbnail': 'pvz_part1_field3.png', 'music': WATERY}
UK = {'id': 'uk', 'scene': 118, 'stamina': 50, 'msp': 8000, 'thumbnail': 'pvz_part1_field3.png', 'music': WATERY}
ALASKA = {'id': 'alaska', 'scene': 118, 'stamina': 60, 'msp': 10000, 'thumbnail': 'pvz_part1_field3.png', 'music': ZOMBOTANY}

# 触发：('front', n, 单位) 我方最前单位与敌方据点距离小于 n 时出兵一次；('base_hp', n, 单位) 敌方据点生命低于 n% 时出兵一次。
# 同一时刻追加多只时阈值依次相差 20 或 1，使其分帧出现、不重叠。
EAST_STAGES = [
    stage(EAST, 0, level=5, roster=[NORMAL], base_hp=3000, prisoners=1,
          waves=[(150, NORMAL), (500, NORMAL), (850, NORMAL)],
          triggers=[('front', 500, NORMAL), ('front', 480, NORMAL)]),
    stage(EAST, 1, level=10, roster=[NORMAL, CONE], base_hp=5000, prisoners=1,
          waves=[(120, NORMAL), (330, CONE), (520, NORMAL), (760, CONE), (950, NORMAL)],
          triggers=[('front', 500, CONE), ('front', 480, NORMAL)]),
    stage(EAST, 2, level=15, difficulty=1, roster=[NORMAL, CONE, BUCKET], base_hp=8000, prisoners=2,
          waves=[(120, NORMAL), (300, CONE), (500, BUCKET), (700, NORMAL), (900, CONE)],
          triggers=[('front', 500, BUCKET), ('front', 480, CONE)]),
    stage(EAST, 3, level=20, difficulty=2, roster=[NORMAL, CONE, BUCKET, NEWSPAPER], base_hp=30000, prisoners=2,
          waves=[(100, NORMAL), (280, CONE), (460, NEWSPAPER), (640, NORMAL), (820, BUCKET), (1000, NORMAL)],
          triggers=[('front', 600, NEWSPAPER), ('front', 580, NEWSPAPER),
                    ('base_hp', 30, NORMAL), ('base_hp', 29, NORMAL), ('base_hp', 28, NORMAL),
                    ('base_hp', 27, CONE), ('base_hp', 26, CONE), ('base_hp', 25, BUCKET)]),
]
CENTRAL_STAGES = [
    stage(CENTRAL, 0, level=30, difficulty=2, roster=[CONE, BUCKET, NEWSPAPER, FOOTBALL], base_hp=12500, prisoners=3,
          waves=[(120, CONE), (330, BUCKET), (540, CONE), (750, NEWSPAPER), (960, FOOTBALL)],
          triggers=[('front', 500, FOOTBALL), ('front', 480, FOOTBALL)]),
    stage(CENTRAL, 1, level=40, difficulty=3, strength=2, roster=[BUCKET, NEWSPAPER, FOOTBALL, ZOMBONI], base_hp=15000, prisoners=3,
          waves=[(120, BUCKET), (330, NEWSPAPER), (540, FOOTBALL), (750, BUCKET), (960, ZOMBONI)],
          triggers=[('front', 600, ZOMBONI), ('front', 580, FOOTBALL)]),
    stage(CENTRAL, 2, level=40, difficulty=4, strength=3, roster=[BUCKET, NEWSPAPER, FOOTBALL, ZOMBONI, GARGANTUAR], base_hp=17500,
          prisoners=5,
          waves=[(120, BUCKET), (360, FOOTBALL), (600, NEWSPAPER), (840, ZOMBONI)],
          triggers=[('front', 600, GARGANTUAR), ('base_hp', 50, GARGANTUAR)]),
    stage(CENTRAL, 3, level=40, difficulty=5, strength=5, roster=[NEWSPAPER, FOOTBALL, ZOMBONI, GARGANTUAR], base_hp=50000, prisoners=7,
          waves=[(100, NEWSPAPER), (300, FOOTBALL), (500, NEWSPAPER), (700, FOOTBALL), (900, ZOMBONI)],
          placed=[GARGANTUAR],
          triggers=[('front', 650, GARGANTUAR), ('base_hp', 50, GARGANTUAR), ('base_hp', 49, ZOMBONI),
                    ('base_hp', 20, FOOTBALL), ('base_hp', 19, FOOTBALL), ('base_hp', 18, FOOTBALL),
                    ('base_hp', 17, NEWSPAPER), ('base_hp', 16, NEWSPAPER)]),
]
# 第三至五大关：敌军全部 Lv40；强度系数 60% 为 3 级（每级 +20%），依此类推。
# 开门单位（2026-10-16 用户修订）：3-1 无、3-2 普通、3-3 路障、3-4 铁桶；4-1 无、4-2 铁桶、4-3 读报、4-4 橄榄球；
# 5-1 橄榄球、5-2 机枪豌豆、5-3 辣椒 4 只、5-4 巨人。
CANADA_STAGES = [
    stage(CANADA, 0, level=40, difficulty=3, strength=3, roster=[NORMAL, CONE, BUCKET, NEWSPAPER, FOOTBALL, ZOMBONI],
          base_hp=20000, prisoners=4,
          waves=[(100, NORMAL), (250, CONE), (400, BUCKET), (550, NEWSPAPER), (700, NORMAL), (850, FOOTBALL), (1000, CONE)],
          triggers=[('front', 600, ZOMBONI), ('front', 580, FOOTBALL), ('base_hp', 50, ZOMBONI)]),
    stage(CANADA, 1, level=40, difficulty=3, strength=3, roster=[NEWSPAPER, BUCKET, FOOTBALL, SQUASH],
          base_hp=22500, prisoners=4, placed=[NORMAL],
          waves=[(120, BUCKET), (330, SQUASH), (540, NEWSPAPER), (750, FOOTBALL), (960, SQUASH)],
          triggers=[('front', 600, SQUASH), ('front', 580, FOOTBALL), ('base_hp', 50, NEWSPAPER), ('base_hp', 49, NEWSPAPER)]),
    stage(CANADA, 2, level=40, difficulty=4, strength=3, roster=[NEWSPAPER, FOOTBALL, ZOMBONI, SQUASH, GATLING],
          base_hp=25000, prisoners=6, placed=[CONE],
          waves=[(120, NEWSPAPER), (300, GATLING), (480, SQUASH), (660, FOOTBALL), (840, NEWSPAPER), (1000, GATLING)],
          triggers=[('front', 600, ZOMBONI), ('front', 580, SQUASH), ('base_hp', 50, GATLING), ('base_hp', 49, FOOTBALL)]),
    stage(CANADA, 3, level=40, difficulty=4, strength=4, roster=[FOOTBALL, SQUASH, GATLING, JALAPENO],
          base_hp=60000, prisoners=7, placed=[BUCKET],
          waves=[(100, FOOTBALL), (300, SQUASH), (500, GATLING), (700, FOOTBALL), (900, JALAPENO)],
          triggers=[('front', 650, JALAPENO), ('front', 630, SQUASH), ('base_hp', 50, GATLING), ('base_hp', 49, GATLING),
                    ('base_hp', 20, FOOTBALL), ('base_hp', 19, FOOTBALL), ('base_hp', 18, FOOTBALL), ('base_hp', 17, JALAPENO)]),
]
UK_STAGES = [
    stage(UK, 0, level=40, difficulty=4, strength=4, roster=[FOOTBALL, SQUASH, GATLING, JALAPENO],
          base_hp=30000, prisoners=6,
          waves=[(120, FOOTBALL), (330, SQUASH), (540, GATLING), (750, FOOTBALL), (960, JALAPENO)],
          triggers=[('front', 600, JALAPENO), ('front', 580, GATLING), ('base_hp', 50, SQUASH)]),
    stage(UK, 1, level=40, difficulty=4, strength=4, roster=[GATLING, JALAPENO, FOOTBALL, BALLOON],
          base_hp=32500, prisoners=6, placed=[BUCKET],
          waves=[(120, BALLOON), (330, FOOTBALL), (540, GATLING), (750, BALLOON), (960, JALAPENO)],
          triggers=[('front', 600, JALAPENO), ('front', 580, BALLOON), ('base_hp', 50, GATLING), ('base_hp', 49, FOOTBALL)]),
    stage(UK, 2, level=40, difficulty=5, strength=5, roster=[GATLING, JALAPENO, FOOTBALL, BALLOON, JACK],
          base_hp=35000, prisoners=7, placed=[NEWSPAPER],
          waves=[(120, JACK), (330, FOOTBALL), (540, BALLOON), (750, JACK), (960, JALAPENO)],
          triggers=[('front', 600, JACK), ('front', 580, JALAPENO), ('base_hp', 50, GATLING), ('base_hp', 49, BALLOON)]),
    stage(UK, 3, level=40, difficulty=5, strength=5, roster=[GATLING, JALAPENO, FOOTBALL, BALLOON, JACK, GARGANTUAR],
          base_hp=70000, prisoners=7, placed=[FOOTBALL],
          waves=[(100, GATLING), (300, FOOTBALL), (500, BALLOON), (700, JACK), (900, JALAPENO)],
          triggers=[('front', 650, GARGANTUAR), ('base_hp', 50, GARGANTUAR), ('base_hp', 49, JACK),
                    ('base_hp', 20, FOOTBALL), ('base_hp', 19, FOOTBALL), ('base_hp', 18, BALLOON), ('base_hp', 17, JALAPENO)]),
]
ALASKA_STAGES = [
    stage(ALASKA, 0, level=40, difficulty=5, strength=5, roster=[JALAPENO, GATLING, BALLOON, GARGANTUAR, JACK],
          base_hp=40000, prisoners=7, placed=[FOOTBALL],
          waves=[(120, JACK), (330, BALLOON), (540, GATLING), (750, JACK), (960, JALAPENO)],
          triggers=[('front', 600, GARGANTUAR), ('front', 580, JALAPENO), ('base_hp', 50, GARGANTUAR)]),
    stage(ALASKA, 1, level=40, difficulty=5, strength=6, roster=[ZOMBONI, GATLING, BALLOON, GARGANTUAR, JACK],
          base_hp=45000, prisoners=7, placed=[GATLING],
          waves=[(120, GATLING), (330, BALLOON), (540, JACK), (750, GATLING), (960, ZOMBONI)],
          triggers=[('front', 600, GARGANTUAR), ('front', 580, JACK), ('base_hp', 50, GARGANTUAR), ('base_hp', 49, ZOMBONI)]),
    stage(ALASKA, 2, level=40, difficulty=5, strength=7, roster=[ZOMBONI, JACK, BALLOON, GARGANTUAR, FOOTBALL],
          base_hp=50000, prisoners=8, placed=[JALAPENO, JALAPENO, JALAPENO, JALAPENO],
          waves=[(120, FOOTBALL), (330, JACK), (540, BALLOON), (750, FOOTBALL), (960, ZOMBONI)],
          triggers=[('front', 600, GARGANTUAR), ('front', 580, JACK), ('base_hp', 50, GARGANTUAR), ('base_hp', 49, FOOTBALL)]),
    stage(ALASKA, 3, level=40, difficulty=5, strength=8, roster=[ZOMBONI, JACK, GARGANTUAR, FOOTBALL, GATLING, JALAPENO],
          base_hp=100000, prisoners=8, placed=[GARGANTUAR],
          waves=[(100, FOOTBALL), (300, GATLING), (500, JACK), (700, ZOMBONI), (900, JALAPENO)],
          triggers=[('front', 650, GARGANTUAR), ('base_hp', 50, GARGANTUAR), ('base_hp', 49, ZOMBONI),
                    ('base_hp', 20, FOOTBALL), ('base_hp', 19, JACK), ('base_hp', 18, GATLING), ('base_hp', 17, JALAPENO)]),
]


def unit_names(key):
    unit = json.loads((ROOT / 'community_content' / 'units' / (key.split('.', 1)[1] + '.json')).read_text(encoding='utf-8'))
    return {code: text['name'] for code, text in unit['localization'].items()}


# 俘虏页说明（原版俘虏奖励的写法，取自猫咪大战争俘虏 67 的 11 种语言原文；第二行写入奖励单位名称）。
# 单位名称缺少的语言（法、意、俄、德）不写，由加载器以英语补全。
INFO1 = {'EN': 'If all prisoners of war are freed,', 'JP': '捕虜がすべて解放されれば', 'KR': '포로를 모두 해방하면,',
         'ES': 'Si liberas a todos los prisioneros de guerra...', 'PT': 'Se todos os prisioneiros forem libertados,',
         'ZS': '只要解放所有俘虏', 'ZT': '只要解放所有俘虜'}
INFO2 = {'EN': '{} will be available!', 'JP': '「{}」が使用可能！', 'KR': '{} 사용 가능!', 'ES': '¡{} estará disponible!',
         'PT': '{} se tornará disponível!', 'ZS': '就能使用「{}」！', 'ZT': '就能使用「{}」！'}

# 俘虏页立绘：奖励僵尸的待机（中立）动作第 1 帧（与游戏中的待机动作相同的帧；小鬼没有待机行，游戏中取行走第 7、8 帧交替），
# 5 种僵尸统一按最近邻 7 倍放大（保持游戏中的相对大小；倭瓜最高 58 像素 → 406），水平翻转为面向右（与我方单位相同），
# 保存为 pvz_part1_portrait_<名称>.png。
PORTRAIT_FRAMES = {IMP: 'garg/imp_walk_06.png', NEWSPAPER: 'newspaper/idle_00.png', SQUASH: 'squash/idle_00.png',
                   JALAPENO: 'jalapeno/idle_00.png', JACK: 'jack/idle_00.png'}
PORTRAIT_SCALE = 7


def portrait(unit):
    frame = Image.open(FRAMES / PORTRAIT_FRAMES[unit]).convert('RGBA')
    frame = frame.crop(frame.getbbox())
    scale = PORTRAIT_SCALE
    art = frame.resize((frame.width * scale, frame.height * scale), Image.NEAREST).transpose(Image.FLIP_LEFT_RIGHT)
    name = f'pvz_part1_portrait_{unit.split("_", 1)[1]}.png'
    art.save(EVENTS / name)
    return name, scale


def reward(unit):
    names = unit_names(unit)
    return {'unit': unit, 'portrait_image': f'pvz_part1_portrait_{unit.split("_", 1)[1]}.png', 'names': names,
            'info1': dict(INFO1), 'info2': {code: text.format(names[code]) for code, text in INFO2.items()}}


def area(key, position, names, unit, stages):
    return {'key': f'{KEY}.{key}', 'position': position, 'names': names, 'reward': reward(unit), 'stages': stages}


EVENT = {
    'schema': 1, 'key': KEY, 'mode': 'rescue',
    # 2026-10-15 用户指定细则：发行商 S1XLV、发行日期 2026-10-14（细则只列发行商与日期，同历史活动）；名称改为“PVZ EVENT”
    # （取消 PART1，只写英语时各语言都显示该名称），左屏封面为用户绘制的 360×240 图（source/pvz_event_cover.png）。
    'names': {'EN': 'PVZ EVENT'},
    'image': COVER,
    'publisher': 'S1XLV', 'date': '2026-10-14', 'order': 0,
    'map_music': MAP_MUSIC,
    'areas': [
        area(EAST['id'], [1159, 280],
             {'EN': 'EASTERN USA', 'ZT': '美國・東部', 'ZS': '美国・东部', 'JP': 'アメリカ・東部', 'ES': 'ESTE DE EE. UU.',
              'PT': 'LESTE DOS EUA', 'KR': '미국 동부', 'FR': 'EST DES ÉTATS-UNIS', 'IT': 'STATI UNITI ORIENTALI', 'RU': 'ВОСТОК США'},
             IMP, EAST_STAGES),
        area(CENTRAL['id'], [1068, 277],
             {'EN': 'CENTRAL USA', 'ZT': '美國・中部', 'ZS': '美国・中部', 'JP': 'アメリカ・中部', 'ES': 'CENTRO DE EE. UU.',
              'PT': 'CENTRO DOS EUA', 'KR': '미국 중부', 'FR': 'CENTRE DES ÉTATS-UNIS', 'IT': 'STATI UNITI CENTRALI', 'RU': 'ЦЕНТР США'},
             NEWSPAPER, CENTRAL_STAGES),
        # 坐标按地图截图换算（两个美国区域图标：横向每地图像素 0.7345 画面像素）：加拿大东部（魁北克一带，游戏内只写“加拿大”）、
        # 英国（大不列颠岛）、阿拉斯加。
        area(CANADA['id'], [1196, 157],
             {'EN': 'CANADA', 'ZT': '加拿大', 'ZS': '加拿大', 'JP': 'カナダ', 'ES': 'CANADÁ', 'PT': 'CANADÁ', 'KR': '캐나다',
              'FR': 'CANADA', 'IT': 'CANADA', 'RU': 'КАНАДА'},
             SQUASH, CANADA_STAGES),
        area(UK['id'], [92, 205],
             {'EN': 'UNITED KINGDOM', 'ZT': '英國', 'ZS': '英国', 'JP': 'イギリス', 'ES': 'REINO UNIDO', 'PT': 'REINO UNIDO',
              'KR': '영국', 'FR': 'ROYAUME-UNI', 'IT': 'REGNO UNITO', 'RU': 'ВЕЛИКОБРИТАНИЯ'},
             JALAPENO, UK_STAGES),
        area(ALASKA['id'], [870, 137],
             {'EN': 'ALASKA', 'ZT': '阿拉斯加', 'ZS': '阿拉斯加', 'JP': 'アラスカ', 'ES': 'ALASKA', 'PT': 'ALASCA', 'KR': '알래스카',
              'FR': 'ALASKA', 'IT': 'ALASKA', 'RU': 'АЛЯСКА'},
             JACK, ALASKA_STAGES),
    ],
}


def thumbnail(obm, name):
    """战场图集的背景部分（天空、草地、地面）等比缩到高 56 后取中央 128 宽。"""
    sys.path.insert(0, r'F:\egg\research\metal_slug_defense\content_work\kt21_feasibility_20261005\design_verification_r1\tools')
    from obm_tool import parse
    atlas = parse((ASSETS / obm).read_bytes()).convert('RGBA')
    box = atlas.getbbox()
    art = atlas.crop(box)
    width = round(art.width * 56 / art.height)
    art = art.resize((width, 56), Image.LANCZOS)
    left = (width - 128) // 2
    art.crop((left, 0, left + 128, 56)).save(EVENTS / name)


def main():
    EVENTS.mkdir(parents=True, exist_ok=True)
    (EVENTS / COVER).write_bytes((HERE / 'source' / 'pvz_event_cover.png').read_bytes())
    thumbnail('stage_neko00.obm', EAST['thumbnail'])
    thumbnail('stage_neko01.obm', CENTRAL['thumbnail'])
    thumbnail('stage_neko02.obm', CANADA['thumbnail'])
    scales = {unit: portrait(unit)[1] for unit in PORTRAIT_FRAMES}
    (EVENTS / 'pvz_part1.json').write_text(json.dumps(EVENT, ensure_ascii=False, indent=2) + '\n', encoding='utf-8', newline='\n')
    print(json.dumps({'stages': sum(len(a['stages']) for a in EVENT['areas']),
                      'prisoners': [[s['prisoners'] for s in a['stages']] for a in EVENT['areas']],
                      'portrait_scale': scales}))


if __name__ == '__main__':
    main()
