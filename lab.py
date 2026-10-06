"""LAB 战斗入口原型：绕过 Wi-Fi 菜单直接建立 1v1（GameMode 1）战斗，敌方由玩家手动控制。

原型范围（2026-10-06）：
- F7：在非战斗界面启动 LAB 战斗（NPC 对手信息由原生 MakeNPCInfo 生成，可用 lab_config.json 覆盖敌方牌组；
  敌方单位经 BattleController::entryUnit 以完整 UnitID 写入，原版 0–399 与社区单位均可用）。
- Q–P：敌方 1–10 号槽位出兵；[ 敌方 AP 升级；] 敌方弹头车；\\ 敌方全体绝招。
- F8：完全控制模式开/关（宿主层方案 B：据点满级、AP 每帧补满、出兵冷却每帧清零）。
- F5：退出 LAB 战斗并返回菜单（联机模式下原生暂停/脱离不可用，正式版并入 LAB 战斗菜单）。
- F4：敌方 AI 自动出兵 开/关；F3：我方 AI 自动出兵 开/关。自动绝招为独立开关（战斗中菜单，钩子版本 ≥ 4）。
- Esc：战斗中菜单（lab_menu.py，打开期间暂停战斗）：完全控制、四个 AI 开关、重新开始、退出、继续。
- 存档隔离（T9）：LAB 期间原生存档写入改写到内存，离开时还原内存中的主存档映像。
- 战斗结束或进入结算场景时直接返回主菜单，不进入 Wi-Fi 结算。

所有原生调用均为已核实的导出符号；运行记录写入 lab_probe.jsonl 与 lab_player.log。
"""
from pathlib import Path
import collections
import os
import struct
import json
import time

CONFIG_NAME = 'lab_config.json'
DEFAULT_CONFIG = {
    'schema': 1,
    'stage_id': 1011,          # 原生联机地图表首项（0x8fd730+48 起：1011,1021,1022,...）
    'enemy_deck': None,        # None=原生 NPC 牌组；或至多 10 项 [单位, 等级(1-40)]，单位为 UnitID 或社区单位 key，null=空槽
    'player_deck': None,       # None=存档牌组与存档等级（BattleStartSetUnit）；格式同 enemy_deck
    'player_base_level': 0,    # 开战时的据点等级 0–10（10=MAX）；完全控制开启时为 MAX
    'enemy_base_level': 0,
    'player_hp_boost': 0,      # 优势设定：原生关卡强化级数（生命/攻击各 ×(1+0.2×级数)），0–10
    'player_atk_boost': 0,
    'enemy_hp_boost': 0,
    'enemy_atk_boost': 0,
    'full_control': True,
    'enemy_ai': False,             # 敌方 AI 自动出兵（含弹头车）
    'player_ai': False,            # 我方 AI 自动出兵（含弹头车）
    'enemy_auto_special': False,   # 敌方自动释放绝招
    'player_auto_special': False,  # 我方自动释放绝招
    'player_support': 0,           # 支援（弹头车按钮效果）：见 SUPPORT_OPTIONS
    'enemy_support': 0,
}
# 支援选项（与 src/lab_hooks.cpp apply_support 编号一致；新增选项在两处同时扩展）。
SUPPORT_OPTIONS = ('弹头车出击', '除据点外全员 HP 回满', '全员绝招立即可用')
PLAYER_FAMILY = ('BattleControllerPlayerBase', 'BattleControllerPlayer', 'BattleControllerNetPlayer',
                 'BattleControllerNetMultiPlayer', 'BattleControllerNetRaidPlayer')
ENEMY_DECK = 0xC081           # app 偏移：10×2 字节（UID 低 8 位 | UID 高 2 位 + 等级<<2）
APP_ONLINE = 0xC030           # 1=联机分支
APP_ONLINE_KIND = 0xC034      # 0=1v1
APP_NPC = 0xC061              # 字节，1=NPC 对手（GetPlayerInfo 调 MakeNPCInfo）
APP_MENU_MODE = 0xC63C
SCENE_BATTLE = 100
LAB_HEADER = 0x1ffeb000        # 与 src/lab_hooks.cpp 共用；0x1ffea000/0x1ffec000/0x1ffed000/0x1ffee000 已被占用
LAB_MAGIC = 0x4c414231         # "LAB1"
LAB_FLAG_ENEMY_GAUGE = 1
LAB_FLAG_ENEMY_TOUCH = 2         # 点击敌方单位释放绝招（lab_hooks 版本 ≥ 2）
LAB_FLAG_SPLIT_BAR = 4           # 底栏左右分栏：我方 AP/弹头车/3 格 | 敌方 3 格/弹头车/AP（版本 ≥ 3）
LAB_FLAG_AUTO_SPLIT = 16         # AI 自动出兵与自动绝招分开控制（版本 ≥ 4）
LAB_AUTO_DISABLE = 0x30          # 头部偏移：位 0/1 我方 出兵/绝招 关闭，位 2/3 敌方 出兵/绝招 关闭
LAB_FLAG_SUPPORT = 32            # 支援：弹头车按钮可换为其他效果（版本 ≥ 5）
LAB_SUPPORT = 0x34               # 头部偏移：低字节我方、次字节敌方的支援选项
LAB_SUPPORT_COUNT = 0x38         # 头部偏移：非弹头车支援的发动计数（原生累加）
LAB_ENEMY_GFX_READY = 0x3c       # 头部偏移：敌方出兵格图集已就绪
LAB_ENEMY_GFX = 0x40             # 头部偏移：敌方 operator+188…+220（9 字）
LAB_ENEMY_PANEL_READY = 0x6c     # 头部偏移：敌方出兵栏状态已初始化
LAB_ENEMY_PANEL = 0x70           # 头部偏移：敌方 operator+24/32/96/100/104/112/116（7 字，+12 为滚动值）
AURA_STRING = 0x103011c3       # BattleEffectRenderer 构造函数引用的 "aura.obm"（.rodata 0x3011c3）
RESULT_SCENES = (110, 120)
SAVE_RAM = 0x3d08              # app 偏移：主存档映像（与 event_trial.EventTrial.transaction 相同）
SAVE_RAM_SIZE = 0x5ab0
STAGE_TABLE = 0x108fd730 + 48
PRESET_DIR = 'lab_presets'
SWITCHES = ('full_control', 'enemy_ai', 'player_ai', 'enemy_auto_special', 'player_auto_special',
            'player_support', 'enemy_support')
PB = '_ZN26BattleControllerPlayerBase'
# BattleObjectManager::createUnit（0x1df344）以 manager+72+(队伍×2+成员)×8 的两个浮点数调用
# BattleObjectFactory::createUnitObject → createUnitStatus（0.2 常量所在函数）；里世界关卡把关卡强化级数写入敌方的这一对值。
ADVANTAGE_BASE = 72


def T(p, key, *args):
    from lab_ui import T as text
    return text(p, key, *args)



class Lab:
    def __init__(self, p, root):
        self.p = p
        self.root = Path(root)
        # 设定与预设目录：默认仓库根目录；验证脚本以 MSD_LAB_CONFIG_DIR 指向独立目录，不改动玩家的 lab_config.json。
        self.config_dir = Path(os.environ.get('MSD_LAB_CONFIG_DIR', root))
        self.commands = collections.deque()
        self.config = self.load_config()
        self.active = False
        self.saved_flags = None
        self.started_frame = 0
        self.applied = False
        self.apply_switches()
        self.support_count = 0
        self.player_units = self.enemy_units = []
        self.cooldown_seen = {}
        from lab_menu import LabMenu
        from lab_prep import LabPrep
        self.menu = LabMenu(self)
        self.prep = LabPrep(self)
        self.restart_at = None
        self.finishing = None             # 战斗结束：原生闸门合拢后离开（原因, 是否回到准备界面, 是否重新开始）
        self.release_shutter_on_battle = False
        self.classes = {}
        for name, address in p.symbols.items():
            if name.startswith('_ZTV') and 'BattleController' in name:
                body = name[4:]
                digits = ''
                while body and body[0].isdigit():
                    digits += body[0]
                    body = body[1:]
                self.classes[address + 8] = body[:int(digits)] if digits else body
        self.last_sample = 0.0
        self.native_hooks = 0
        self.red_renderer = None
        self.red_aura = None
        self.sandbox = False
        self.save_snapshot = None
        self.virtual_files = {}
        self.virtual_write_count = 0
        p.log('LAB_READY', json.dumps(self.config, ensure_ascii=False))

    # ---------- 配置与记录 ----------
    def load_config(self):
        path = self.config_dir / CONFIG_NAME
        if not path.is_file():
            path.write_text(json.dumps(DEFAULT_CONFIG, ensure_ascii=False, indent=2), encoding='utf-8')
            return dict(DEFAULT_CONFIG)
        data = json.loads(path.read_text(encoding='utf-8'))
        config = dict(DEFAULT_CONFIG)
        config.update({k: v for k, v in data.items() if k in DEFAULT_CONFIG})
        for key in ('enemy_deck', 'player_deck'):
            deck = config[key]
            if deck is not None and (not isinstance(deck, list) or len(deck) > 10):
                raise ValueError(f'lab_config.json: {key} 须为至多 10 项的列表')
        return config

    def save_config(self):
        for name in SWITCHES:
            self.config[name] = getattr(self, name)
        (self.config_dir / CONFIG_NAME).write_text(json.dumps(self.config, ensure_ascii=False, indent=2), encoding='utf-8')

    # ---------- 预设与履历（lab_presets/） ----------
    def preset_path(self, name):
        folder = self.config_dir / PRESET_DIR
        folder.mkdir(exist_ok=True)
        return folder / f'preset_{name}.json'

    def save_preset(self, name):
        self.save_config()
        self.preset_path(name).write_text(json.dumps(self.config, ensure_ascii=False, indent=2), encoding='utf-8')

    def load_preset(self, name):
        path = self.preset_path(name)
        if not path.is_file():
            return False
        data = json.loads(path.read_text(encoding='utf-8'))
        self.config.update({k: v for k, v in data.items() if k in DEFAULT_CONFIG})
        self.apply_switches()
        self.save_config()
        return True

    def apply_switches(self):
        for name in SWITCHES:
            value = self.config[name]
            setattr(self, name, int(value) % len(SUPPORT_OPTIONS) if name.endswith('_support') else bool(value))
        # 支援接口（原生钩子与 SUPPORT_OPTIONS）保留；界面暂只开放弹头车出击，其余选项不生效。
        self.player_support = self.enemy_support = 0

    def read_history(self):
        path = self.config_dir / PRESET_DIR / 'history.jsonl'
        if not path.is_file():
            return []
        entries = []
        for line in path.read_text(encoding='utf-8').splitlines()[-200:]:
            try:
                entries.append(json.loads(line))
            except ValueError:
                pass
        return entries

    def write_history(self, reason):
        mine, enemy, _ = self.controllers()
        alive = {}
        for side, controller in (('player', mine), ('enemy', enemy)):
            base = self.p.call('_ZNK16BattleController11getBaseUnitEv', controller) if controller else 0
            alive[side] = bool(self.valid(base) and struct.unpack('<f', self.p.read(base + 776, 4))[0] > 0)
        winner = 'player' if alive['player'] and not alive['enemy'] else (
            'enemy' if alive['enemy'] and not alive['player'] else None)
        entry = {'time': time.strftime('%m-%d %H:%M'), 'reason': reason, 'winner': winner,
                 'seconds': (self.p.frame - self.started_frame) / 30, 'stage_id': self.config['stage_id'],
                 'player_units': [e[0] if e else 0 for e in self.player_units],
                 'enemy_units': [e[0] if e else 0 for e in self.enemy_units]}
        with self.preset_path('A').parent.joinpath('history.jsonl').open('a', encoding='utf-8') as stream:
            stream.write(json.dumps(entry, ensure_ascii=False) + '\n')

    def community_uid(self, key):
        community = getattr(self.p, 'community', None)
        for unit in (community.units if community is not None else []):
            if unit['key'] == key:
                return unit['id']
        return None

    def stage_list(self):
        """原生联机地图表（0x108fd730+48 起，以 4 位数 StageID 连续存放）。"""
        stages = []
        for index in range(64):
            value = self.p.word(STAGE_TABLE + 4 * index)
            if not 1000 <= value < 2000:
                break
            stages.append(value)
        return stages or [1011]

    def resolve_deck(self, deck):
        """把配置项解析为 10 个 (UnitID, 存档等级) 或 None；单位可写 UnitID 或社区单位 key。"""
        community = getattr(self.p, 'community', None)
        units = community.units if community is not None else []
        by_key = {u['key']: u['id'] for u in units}
        # 内部子单位（internal_only，如伞兵/迫击炮子单位、生成器箱体）不可直接编入牌组。
        known = set(range(400)) | {u['id'] for u in units if not u.get('internal_only')}
        result = []
        for index in range(10):
            entry = deck[index] if index < len(deck) else None
            if entry is None:
                result.append(None)
                continue
            unit, level = entry
            uid = by_key.get(unit) if isinstance(unit, str) else int(unit)
            if uid is None or uid not in known:
                raise ValueError(f'enemy_deck 第 {index + 1} 项：未知单位 {unit!r}')
            if not 1 <= int(level) <= 40:
                raise ValueError(f'enemy_deck 第 {index + 1} 项：等级 {level} 超出 1–40')
            result.append((uid, int(level) - 1))
        return result

    def affiliation(self, uid):
        return self.p.call('_ZN7AppMain18GetUnitAffiliationE6UnitID', self.app(), uid)

    def stand_in(self, uid):
        """取与 uid 同阵营、编号 < 400 的原版单位，仅供原生阵营一致性判断使用。"""
        if not hasattr(self, 'stand_ins'):
            self.stand_ins = {}
            for candidate in range(1, 400):
                self.stand_ins.setdefault(self.affiliation(candidate), candidate)
        faction = self.affiliation(uid)
        if faction not in self.stand_ins:
            raise ValueError(f'UnitID {uid} 的阵营 {faction} 无原版对应单位')
        return self.stand_ins[faction]

    def feedback(self, text, success=True):
        self.p.unit_feedback = {'text': 'LAB · ' + text, 'until': time.perf_counter() + 2.5,
                                'success': success, 'visible': True}
        self.p.log('LAB_FEEDBACK', text)

    def record(self, kind, **values):
        values.update(kind=kind, frame=self.p.frame)
        with (self.root / 'lab_probe.jsonl').open('a', encoding='utf-8') as stream:
            stream.write(json.dumps(values, ensure_ascii=False, default=str) + '\n')

    # ---------- 原生对象 ----------
    def app(self):
        return self.p.app_instance()

    def valid(self, address):
        return 0x10000000 <= address < 0x1ffff000

    def battle(self):
        p = self.p
        app = self.app()
        if not app or p.word(app + 0x22bc) != SCENE_BATTLE:
            return None, None
        main = p.word(app + 0xc220)
        if not main or not p.word(main + 8):
            return None, None
        scene = p.call('_ZN10BattleMain12getMainSceneEv', main)
        return main, scene

    def controllers(self):
        """返回 (我方控制器, 敌方控制器, 场景信息)。"""
        p = self.p
        main, scene = self.battle()
        if not scene:
            return None, None, None
        from battle_controls import player_controller
        mine = player_controller(p, main)
        team = p.word(mine + 0x38c) if mine else None
        enemy = None
        found = []
        for index in range(8):
            address = p.word(scene + 0x40 + index * 4)
            if not self.valid(address):
                continue
            cls = self.classes.get(p.word(address))
            if cls is None:
                continue
            found.append((index, cls, hex(address), p.word(address + 0x38c)))
            if cls in PLAYER_FAMILY and address != mine and p.word(address + 0x38c) != team:
                enemy = address
        return mine, enemy, {'game_mode': p.word(scene + 0x24), 'controllers': found}

    # ---------- 启动与离开 ----------
    def start(self):
        p = self.p
        app = self.app()
        scene = p.word(app + 0x22bc)
        if scene in (99, SCENE_BATTLE) or self.active:
            self.feedback(T(self.p, 'fb_busy'), False)
            return
        self.config = self.load_config()
        self.config.update({name: getattr(self, name) for name in SWITCHES})
        # 先完成全部校验与查表，确认无误后才改动原生场景状态。
        configured = None
        if self.config['enemy_deck'] is not None:
            configured = self.resolve_deck(self.config['enemy_deck'])
            for entry in configured:
                if entry is not None and entry[0] >= 400:
                    self.stand_in(entry[0])
        player_deck = None
        if self.config['player_deck'] is not None:
            player_deck = self.resolve_deck(self.config['player_deck'])
        self.prep.set_open(False)
        self.saved_flags = {name: p.word(app + offset) for name, offset in
                            (('online', APP_ONLINE), ('kind', APP_ONLINE_KIND), ('menu', APP_MENU_MODE))}
        self.saved_flags['npc'] = p.read(app + APP_NPC, 1)[0]
        self.enter_sandbox()
        p.call('_ZN7AppMain12SceneEndFuncEi', app, scene)
        p.put(app + APP_ONLINE, 1)
        p.put(app + APP_ONLINE_KIND, 0)
        p.write(app + APP_NPC, b'\x01')
        p.put(app + APP_MENU_MODE, 4)
        p.call('_ZN7AppMain13GetPlayerInfoEv', app)
        native_deck = self.read_enemy_deck()
        if configured is not None:
            deck = configured
        else:
            deck = [None if entry is None else (entry[0], entry[1] - 1) for entry in native_deck]
        # 原生对手数据区只容 10 位 UID：UID ≥ 400 的单位以同阵营原版单位代写，
        # 仅用于 BattleStartSetStatusEnemy 的全同阵营判断；实际单位随后以完整 UID 写入。
        self.write_enemy_deck([None if e is None else (e[0] if e[0] < 400 else self.stand_in(e[0]), e[1])
                               for e in deck])
        stage = int(self.config['stage_id'])
        p.call('_ZN7AppMain22BattleInit_OnlinerModeEi12BattleTeamID', app, stage, 0)
        p.call('_ZN7AppMain20BattleStartSetStatusEiii9WorldType', app, 0, 0, 0, 0)
        main = p.word(app + 0xc220)
        if player_deck is None:
            p.call('_ZN7AppMain18BattleStartSetUnitEv', app)
            player_deck = [None] * 10
            for slot in range(10):
                uid = p.call('_ZN7AppMain19GetDeckUnitSaveDataEii', app, slot, 0xffffffff)
                if uid not in (0, 0xffffffff) and not uid & 0x80000000:
                    player_deck[slot] = (uid, p.call('_ZN7AppMain20GetUnitLevelSaveDataE6UnitID', app, uid))
        else:
            # 取代 BattleStartSetUnit：与原生相同按槽位顺序调用 entryUnit，等级取准备界面设定，不读存档。
            mine = p.call('_ZN10BattleMain19getPlayerControllerEv', main)
            for entry in player_deck:
                uid, level = (0xffffffff, 0) if entry is None else entry
                p.call('_ZN16BattleController9entryUnitE6UnitIDib', mine, uid, level, 0)
        p.call('_ZN7AppMain25BattleStartSetStatusEnemyEv', app)
        # 取代 BattleStartSetUnitEnemy（0x1e8966）：与原生相同按槽位顺序调用 entryUnit，空槽传 -1，
        # 但 UnitID 不经 10 位编码，社区单位可直接写入。
        enemy = p.call('_ZN10BattleMain18getEnemyControllerEv', main)
        for entry in deck:
            uid, level = (0xffffffff, 0) if entry is None else entry
            p.call('_ZN16BattleController9entryUnitE6UnitIDib', enemy, uid, level, 0)
        p.call('_ZN7AppMain26SetContinueStageIDSaveDataEi', app, 0)
        # 战斗对象已按联机 1v1（GameMode 1）建立；应用层联机标记随即清除，
        # 使 AppMain::BattleConnectionCheck 与战斗循环不再检查 CGameCenter 连接状态（无对端时会弹出“通讯中断”）。
        p.put(app + APP_ONLINE, 0)
        self.write_header(True)
        p.call('_ZN7AppMain11ChangeExeSTEi', app, 99)
        self.active = True
        self.applied = False
        self.seen_playing = False
        self.network_wait_done = False
        self.idle_frames = 0
        self.last_scene = None
        self.started_frame = p.frame
        self.player_units, self.enemy_units = list(player_deck), list(deck)
        self.cooldown_seen = {}
        self.record('start', from_scene=scene, stage_id=stage, native_npc_deck=native_deck,
                    enemy_deck=[None if e is None else [e[0], e[1] + 1] for e in deck],
                    player_deck=[None if e is None else [e[0], e[1] + 1] for e in player_deck],
                    saved_flags=self.saved_flags, config=self.config)
        self.feedback(T(p, 'fb_start', stage))

    # ---------- 存档隔离（T9） ----------
    def enter_sandbox(self):
        """LAB 期间不改动玩家存档：
        1. 快照内存中的主存档映像（app+0x3d08，0x5ab0 字节，与 EventTrial.transaction 相同），离开时还原，
           战斗中原生对体力、续关、奖励等存档字段的改动不会被之后的正常保存带出；
        2. 原生对存档目录的写入改写到内存中的虚拟文件（lab_launcher.LabProbe.filecall），
           同一文件的读回（原生保存后的校验）由虚拟文件提供，磁盘上的存档文件不被打开写入。"""
        p = self.p
        self.save_snapshot = p.read(self.app() + SAVE_RAM, SAVE_RAM_SIZE)
        self.virtual_files = {}
        self.sandbox = True
        self.record('sandbox_enter')

    def leave_sandbox(self):
        p = self.p
        if self.save_snapshot is not None:
            restored = p.read(self.app() + SAVE_RAM, SAVE_RAM_SIZE) != self.save_snapshot
            p.write(self.app() + SAVE_RAM, self.save_snapshot)
            self.record('sandbox_leave', ram_restored=restored,
                        virtual_writes=sorted(self.virtual_files), write_count=self.virtual_write_count)
        self.save_snapshot = None
        self.virtual_files = {}
        self.virtual_write_count = 0
        self.sandbox = False

    def abort(self):
        """宿主异常时的回退：还原存档映像、关闭隔离并清零共享头。"""
        self.active = False
        try:
            if self.sandbox:
                self.leave_sandbox()
        finally:
            self.write_header(False)

    def read_enemy_deck(self):
        p = self.p
        app = self.app()
        deck = []
        for slot in range(10):
            low, high = p.read(app + ENEMY_DECK + slot * 2, 2)
            uid = low | ((high & 3) << 8)
            deck.append(None if uid & 0x200 else [uid, (high >> 2) + 1])
        return deck

    def write_enemy_deck(self, deck):
        p = self.p
        app = self.app()
        for slot in range(10):
            entry = deck[slot] if slot < len(deck) else None
            if entry is None:
                raw = bytes((0xff, 0x03))   # UID 位 9 置位 → 原生视为空槽
            else:
                uid, level = int(entry[0]), int(entry[1])
                raw = bytes((uid & 0xff, ((uid >> 8) & 3) | ((level & 0x3f) << 2)))
            p.write(app + ENEMY_DECK + slot * 2, raw)

    def leave(self, reason, reopen_prep=True):
        p = self.p
        app = self.app()
        scene = p.word(app + 0x22bc)
        self.record('leave', reason=reason, scene=scene)
        self.menu.set_open(False, animate=False)
        try:
            self.write_history(reason)
        except Exception as error:
            p.log('LAB_HISTORY_ERROR', type(error).__name__, str(error))
        try:
            self.release_enemy_graphics()
            # 原生战斗结束先经 SC_BattleEnd（0x1ea098）再进结算，结算后 SC_BattleEndLoop 才 BattleEnd_ClearBattleMain。
            # LAB 不进结算，SceneEndFunc 也无战斗场景分支，此处按原生顺序补做 SC_BattleEnd 的清理：
            # 菜单任务与 2D 任务（SC_BattleInit 每场新建的菜单图片等）、2D 绘制请求、BGM 与音效请求屏蔽位。
            # 缺少这一步时每场战斗的这些对象不释放，客机内存逐场减少，之后的战斗中音效载入失败。
            p.call('_ZN7AppMain13ClearMenuTaskEv', app)
            p.call('_ZN13CTaskSystem2D9AllDeleteEii', app + 0x3830, 0, 4)
            p.call('_ZN7AppMain14RequestClear2DEv', app)
            p.call('_ZN7AppMain13Sound_StopBGMEv', app)
            p.call('_ZN7AppMain22Sound_InitRequestBlockEv', app)
            p.call('_ZN7AppMain25BattleEnd_ClearBattleMainEv', app)
        except Exception as error:
            p.log('LAB_CLEAR_ERROR', type(error).__name__, str(error))
        if self.saved_flags:
            p.put(app + APP_ONLINE, self.saved_flags['online'])
            p.put(app + APP_ONLINE_KIND, self.saved_flags['kind'])
            p.put(app + APP_MENU_MODE, self.saved_flags['menu'])
            p.write(app + APP_NPC, bytes((self.saved_flags['npc'],)))
        self.leave_sandbox()
        self.write_header(False)
        p.call('_ZN7AppMain12SceneEndFuncEi', app, scene)
        # 27 为原生主菜单初始化，28 为其稳态；31 属于关卡地图初始化。
        p.call('_ZN7AppMain11ChangeExeSTEi', app, 27)
        self.active = False
        self.finishing = None
        if reopen_prep:
            self.prep.show(from_closed=True)   # 原生闸门已合拢：宿主闸门接手并在准备界面上打开（T8）
        self.feedback(T(p, 'fb_back') if reopen_prep else T(p, 'fb_back_menu'))

    def finish(self, reason, reopen_prep=True, restart=False):
        """结束 LAB 战斗：先以原生 SetShutterClose 合拢闸门（与原生战斗结束相同的画面），合拢后离开战斗。"""
        if self.finishing is not None:
            return
        self.menu.set_open(False)
        p = self.p
        try:
            p.call('_ZN7AppMain15SetShutterCloseEv', self.app())
            self.finishing = (reason, reopen_prep, restart, p.frame)
        except Exception as error:
            p.log('LAB_SHUTTER_ERROR', type(error).__name__, str(error))
            self.leave(reason, reopen_prep)
            if restart:
                self.restart_at = p.frame + 45

    def poll_finish(self):
        reason, reopen_prep, restart, since = self.finishing
        p = self.p
        closed = p.call('_ZN7AppMain14IsShutterCloseEv', self.app()) if p.frame - since > 2 else 0
        if closed or p.frame - since > 90:
            self.leave(reason, reopen_prep and not restart)
            if restart:
                self.restart_at = p.frame + 10

    # ---------- 每帧 ----------
    def update(self):
        while self.commands:
            command = self.commands.popleft()
            try:
                self.execute(command)
            except Exception as error:
                self.p.log('LAB_COMMAND_ERROR', command, type(error).__name__, str(error))
                if self.sandbox and not self.active:
                    self.leave_sandbox()   # 启动中途失败：还原存档映像并关闭隔离
                self.feedback(T(self.p, 'fb_failed', command, error), False)
        if self.release_shutter_on_battle and self.p.word(self.app() + 0x22bc) in (99, SCENE_BATTLE):
            self.release_shutter_on_battle = False
            self.prep.shutter.release()          # SC_BattleInit 的 SetShutterOpen 接管（原生开闸）
        if not self.active:
            if self.restart_at is not None and self.p.frame >= self.restart_at:
                self.restart_at = None
                self.start()
            self.prep.draw()
            return
        self.menu.draw()
        self.prep.draw()
        if self.finishing is not None:
            self.poll_finish()
            return
        p = self.p
        app = self.app()
        scene = p.word(app + 0x22bc)
        if scene != self.last_scene:
            self.record('scene', scene=scene, previous=self.last_scene)
            self.last_scene = scene
        main = p.word(app + 0xc220)
        if not self.network_wait_done and self.valid(main):
            self.finish_network_wait(main)
        playing = bool(self.valid(main) and p.word(main + 8) and
                       p.call('_ZN10BattleMain15isBattlePlayingEv', main))
        if playing:
            self.seen_playing = True
            self.idle_frames = 0
        elif self.seen_playing:
            master = p.call('_ZN16BattleGameMaster11getInstanceEv')
            paused = p.read(master + 0x1c, 1)[0] if master else 0
            # 战斗停止且非暂停：离开战斗场景、战斗对象销毁或停止满 2 秒，视为结束并直接返回菜单。
            if not paused:
                self.idle_frames += 1
            if not self.valid(main):
                self.leave(f'battle_finished_scene_{scene}')
                return
            if not paused and (scene != SCENE_BATTLE or self.idle_frames >= 75):
                # 原生 MISSION COMPLETE / FAILED 演出结束后合拢闸门，再回到准备界面。
                self.finish(f'battle_finished_scene_{scene}')
                return
        elif scene in RESULT_SCENES and p.frame - self.started_frame > 5:
            # 尚未开战即出现弹窗（110/120）：记录后退出，避免停在无对端的联机流程中。
            self.leave(f'popup_before_battle_scene_{scene}')
            return
        mine, enemy, info = self.controllers()
        now = time.monotonic()
        if now - self.last_sample > (2 if p.frame - self.started_frame < 900 else 15):
            self.last_sample = now
            self.record('sample', scene=scene, info=info, playing=playing,
                        mine=self.describe(mine), enemy=self.describe(enemy))
        if not (mine and enemy):
            return
        # 原生钩子所需的敌方信息在开场（MISSION START）前即写入，底栏分栏从开场画面起生效。
        self.publish_enemy(enemy)
        self.apply_advantage(mine, enemy)
        if self.native_hooks >= 3 and not p.word(LAB_HEADER + LAB_ENEMY_GFX_READY):
            self.build_enemy_graphics(enemy)
        if not playing:
            return
        self.fix_units(mine, enemy)
        if not self.applied:
            self.applied = True
            self.apply_ai(mine, enemy)
            if self.full_control:
                for controller in (mine, enemy):
                    p.call(PB + '20actionKyotenLevelMaxEv', controller)
            else:
                self.apply_base_levels(mine, enemy)
            self.record('applied', mine=self.describe(mine), enemy=self.describe(enemy))
        if self.full_control:
            for controller in (mine, enemy):
                level = p.call(PB + '14getKyotenLevelEv', controller)
                maximum = p.call(PB + '8getMaxAPEi', controller, level)
                ap = p.call(PB + '5getAPEv', controller)
                if maximum > ap:
                    p.call(PB + '6plusAPEi', controller, maximum - ap)
                if not self.recent_create(controller):
                    p.call(PB + '24clearCreateUnitWaitTimerEv', controller)

    def publish_enemy(self, enemy):
        """头部：+4 功能位，+8 敌方队伍，+16 敌方控制器，+20 敌方成员（controller+924，与 onGameScreenTouchEnded 的 r9 相同）。"""
        p = self.p
        p.put(LAB_HEADER + 4, self.header_flags())
        p.put(LAB_HEADER + 8, p.word(enemy + 0x38c))
        p.put(LAB_HEADER + 16, enemy)
        p.put(LAB_HEADER + 20, p.word(enemy + 924))
        p.put(LAB_HEADER + LAB_SUPPORT, self.player_support | (self.enemy_support << 8))
        count = p.word(LAB_HEADER + LAB_SUPPORT_COUNT)
        if count != self.support_count:
            self.support_count = count
            self.feedback(T(p, 'fb_support'))

    def apply_advantage(self, mine, enemy):
        """优势设定：写入双方的原生强化级数（每帧覆盖，作用于此后生成的单位）。"""
        import struct
        p = self.p
        manager = p.call('_ZN19BattleObjectManager11getInstanceEv')
        if not self.valid(manager):
            return
        for controller, side in ((mine, 'player'), (enemy, 'enemy')):
            index = p.word(controller + 0x38c) * 2 + p.word(controller + 924)
            if not 0 <= index < 8:
                continue
            hp = float(int(self.config.get(side + '_hp_boost', 0)))
            atk = float(int(self.config.get(side + '_atk_boost', 0)))
            p.write(manager + ADVANTAGE_BASE + index * 8, struct.pack('<ff', hp, atk))

    def build_enemy_graphics(self, enemy):
        """底栏分栏的敌方出兵格图集。BattlePlayerOperator::createGrahics 以 operator+24 的控制器生成
        出兵格头像、成本数字等合成图（operator+188…+220，只新建不释放旧对象）；这里临时换入敌方控制器调用一次，
        把结果交给原生钩子（头部 +0x40 起 9 字，+0x3c 置 1），随后还原我方的值。"""
        p = self.p
        _, scene = self.battle()
        operator = p.word(scene + 0x3c)
        if not self.valid(operator):
            return
        offsets = [188 + 4 * i for i in range(9)]
        mine = [p.word(operator + o) for o in offsets]
        controller = p.word(operator + 24)
        p.put(operator + 24, enemy)
        try:
            p.call('_ZN20BattlePlayerOperator13createGrahicsEv', operator)
            built = [p.word(operator + o) for o in offsets]
        finally:
            p.put(operator + 24, controller)
            for o, value in zip(offsets, mine):
                p.put(operator + o, value)
        for i, value in enumerate(built):
            p.put(LAB_HEADER + LAB_ENEMY_GFX + 4 * i, value)
        p.put(LAB_HEADER + LAB_ENEMY_GFX_READY, 1)
        # 只记录本次新建的对象（与我方相同的字段是共用对象，由 operator 析构释放），离开战斗时释放。
        self.enemy_gfx_owned = {o: b for o, b, m in zip(offsets, built, mine) if b and b != m}
        self.record('enemy_graphics', operator=hex(operator), fields=[hex(v) for v in built])

    def release_enemy_graphics(self):
        """按 ~BattlePlayerOperator（0x1d6668）对 operator+188…+220 的释放方式释放敌方出兵格对象：
        +188/+192/+196/+216 虚析构（vtable[1]），+200 delete[]，+204/+220 BattleSprite::release，
        +208 BattleCoinAnimator 析构后 delete；+212 原生不释放。须在 BattleEnd_ClearBattleMain 之前调用。"""
        p = self.p
        owned, self.enemy_gfx_owned = getattr(self, 'enemy_gfx_owned', {}), {}
        p.put(LAB_HEADER + LAB_ENEMY_GFX_READY, 0)
        for offset, obj in owned.items():
            if offset in (188, 192, 196, 216):
                p.call(p.word(p.word(obj) + 4), obj)
            elif offset == 200:
                p.call('_ZdaPv', obj)
            elif offset in (204, 220):
                p.call('_ZN12BattleSprite7releaseEv', obj)
            elif offset == 208:
                p.call('_ZN18BattleCoinAnimatorD2Ev', obj)
                p.call('_ZdlPv', obj)
        if owned:
            self.record('enemy_graphics_released', fields={o: hex(v) for o, v in owned.items()})

    def finish_network_wait(self, main):
        """联机战斗开场的 BattleSceneNetworkWait（场景类型 6）等待对端同步；LAB 无对端，
        找到该场景对象后调用其原生 finish()（与同步完成时相同，置 +21 完成标记）。"""
        p = self.p
        vtable = p.symbols['_ZTV22BattleSceneNetworkWait'] + 8
        candidates = []
        for index in range(25):
            word = p.word(main + index * 4)
            if not self.valid(word):
                continue
            candidates.append(word)
            for inner in range(16):
                deeper = p.word(word + inner * 4)
                if self.valid(deeper):
                    candidates.append(deeper)
        for address in candidates:
            if p.word(address) == vtable:
                if not p.read(address + 21, 1)[0]:
                    p.call('_ZN22BattleSceneNetworkWait6finishEv', address)
                    self.record('network_wait_finished', address=hex(address))
                # 原生各结束分支均在完成前调用 CloseContentsWindow 关闭“同步中”窗口（0x1d6280/0x1d6284）。
                p.call('_ZN7AppMain19CloseContentsWindowEv', self.app())
                self.network_wait_done = True
                return

    def write_header(self, active):
        p = self.p
        p.put(LAB_HEADER + LAB_ENEMY_GFX_READY, 0)
        p.put(LAB_HEADER + LAB_ENEMY_PANEL_READY, 0)
        p.put(LAB_HEADER + LAB_SUPPORT_COUNT, 0)
        self.support_count = 0
        if not active:
            for offset in range(0, 32, 4):
                p.put(LAB_HEADER + offset, 0)
            return
        p.put(LAB_HEADER + 4, self.header_flags())
        p.put(LAB_HEADER + 12, 0)
        p.put(LAB_HEADER, LAB_MAGIC)

    def header_flags(self):
        flags = LAB_FLAG_ENEMY_GAUGE if self.native_hooks >= 1 else 0
        if self.native_hooks >= 2:
            flags |= LAB_FLAG_ENEMY_TOUCH
        if self.native_hooks >= 3:
            flags |= LAB_FLAG_SPLIT_BAR
        if self.native_hooks >= 4:
            flags |= LAB_FLAG_AUTO_SPLIT
        if self.native_hooks >= 5:
            flags |= LAB_FLAG_SUPPORT
        return flags

    def reveal_slot(self, enemy, slot):
        """分栏每侧只显示 3 格：按键出兵的槽位不在可见范围时，把该侧滚动到能看见它。"""
        if self.native_hooks < 3 or not self.active:
            return
        p = self.p
        _, scene = self.battle()
        if not scene:
            return
        operator = p.word(scene + 0x3c)
        import struct
        pitch = round(struct.unpack('<f', p.read(operator + 108, 4))[0])
        if pitch <= 0:
            return
        address = LAB_HEADER + LAB_ENEMY_PANEL + 12 if enemy else operator + 100
        if enemy and not p.word(LAB_HEADER + LAB_ENEMY_PANEL_READY):
            return
        scroll = p.word(address)
        scroll = scroll - (1 << 32) if scroll & 0x80000000 else scroll
        first = max(0, round(scroll / pitch))
        if first <= slot <= first + 2:
            return
        first = slot if slot < first else slot - 2
        p.put(address, max(0, min(first, 7)) * pitch)

    def red_aura_bytes(self):
        """aura.obm（OI 04 04，256×256，16 色 RGB5_A1 调色板 + 4bpp）调色板换色：
        各色 R←max(R,G,B)，G、B←min(R,G,B)；洋红透明键保持不变。亮蓝/青 → 亮红，白芯保持白色。"""
        if self.red_aura is None:
            import struct
            import probe
            raw = bytearray((Path(probe.RESOURCE_ROOT) / probe.PKG / 'aura.obm').read_bytes())
            if raw[:4] != b'OI\x04\x04' or len(raw) != 8 + 32 + 128 * 256:
                raise ValueError('aura.obm 格式与预期不符')
            for index in range(16):
                value = struct.unpack_from('<H', raw, 8 + index * 2)[0]
                r, g, b, a = (value >> 11) & 31, (value >> 6) & 31, (value >> 1) & 31, value & 1
                if (r, g, b) != (31, 0, 31):
                    hi, lo = max(r, g, b), min(r, g, b)
                    value = (hi << 11) | (lo << 6) | (lo << 1) | a
                struct.pack_into('<H', raw, 8 + index * 2, value)
            self.red_aura = bytes(raw)
        return self.red_aura

    def ensure_red_renderer(self):
        """构造第二个 BattleEffectRenderer（12 字节），其图像以 aurR.obm 载入（由宿主返回红色版本）。
        仅在构造期间把 .rodata 中的 "aura.obm" 改为 "aurR.obm"，随即还原。整个会话复用同一对象。"""
        if self.red_renderer is not None:
            return self.red_renderer
        p = self.p
        if p.read(AURA_STRING, 9) != b'aura.obm\x00':
            self.red_renderer = 0
            self.record('red_aura_unavailable', reason='string_mismatch')
            return 0
        renderer = p.call('_Znwj', 12)
        p.write(AURA_STRING, b'aurR.obm\x00')
        try:
            p.call('_ZN20BattleEffectRendererC1Ev', renderer)
        finally:
            p.write(AURA_STRING, b'aura.obm\x00')
        self.red_renderer = renderer if self.valid(p.word(renderer + 4)) else 0
        self.record('red_aura_renderer', address=hex(renderer), image=hex(p.word(renderer + 4)))
        return self.red_renderer

    def team_list(self, team):
        p = self.p
        manager = p.call('_ZN19BattleObjectManager11getInstanceEv')
        unit = p.call('_ZN19BattleObjectManager15getTeamUnitListE12BattleTeamID18BattleTeamMemberID', manager, team, 0)
        units = []
        seen = set()
        while unit and unit not in seen and self.valid(unit) and len(seen) < 4096:
            seen.add(unit)
            units.append(unit)
            link = p.word(unit + 0x120)
            unit = link - 0x11c if link else 0
        return manager, units

    def fix_units(self, mine, enemy):
        """联机模式的本地修正（每帧）：
        1. BattleScene::setupResourceAll 在 GameMode 1 中把本方据点 +981 置 1（据点 HP 由对端同步，本地不扣血，
           BattleUnit::damage 0x1e0aa8 据此跳过扣血）。LAB 无对端，双方单位与据点 +981 一律清零，伤害本地结算、两边对称。
        2. BattleObjectManager::createUnit（0x1df418）只为本地玩家队伍设置绝招特效渲染器（+972/+976）；
           为敌方单位补设同一渲染器（类型 1），使敌方也显示绝招可释放光圈。"""
        p = self.p
        enemy_team = p.word(enemy + 0x38c)
        cleared = 0
        red = self.ensure_red_renderer()
        for team in (0, 1):
            manager, units = self.team_list(team)
            renderer = p.word(manager + 64)
            if red and renderer:
                # 原渲染器的动画帧（+8，浮点）由原生逐帧推进；红色渲染器同步该帧号。
                p.put(red + 8, p.word(renderer + 8))
            enemy_renderer = red or renderer
            for unit in units:
                if p.read(unit + 981, 1)[0]:
                    p.write(unit + 981, b'\x00')
                    cleared += 1
                if team == enemy_team and enemy_renderer and p.word(unit + 972) != enemy_renderer:
                    p.call('_ZN10BattleUnit17setEffectRendererEP20BattleEffectRendererNS_18SpAttackEffectTypeE',
                           unit, enemy_renderer, 1)
        for controller in (mine, enemy):
            base = p.call('_ZNK16BattleController11getBaseUnitEv', controller)
            if self.valid(base) and p.read(base + 981, 1)[0]:
                p.write(base + 981, b'\x00')
                cleared += 1
        if cleared and not getattr(self, 'reported_invulnerable', False):
            self.reported_invulnerable = True
            self.record('cleared_remote_hp_lock', count=cleared)

    def recent_create(self, controller, frames=8):
        """完全控制每帧清零出兵冷却；刚出兵的槽位保留冷却显示若干帧（格子变红的原生出兵反馈），之后再清零。"""
        p = self.p
        seen = self.cooldown_seen.setdefault(controller, {})
        recent = False
        for slot in range(10):
            info = p.call('_ZNK16BattleController11getUnitInfoEi', controller, slot)
            cooldown = p.word(info + 0x18) if info else 0
            if info and cooldown and not cooldown & 0x80000000:
                first = seen.setdefault(slot, p.frame)
                recent = recent or p.frame - first < frames
            else:
                seen.pop(slot, None)
        return recent

    def apply_base_levels(self, mine, enemy):
        """准备界面设定的据点初始等级：以原生 actionKyotenLevelup 逐级提升（同时更新 AP 上限、回复量与升级成本，
        并触发原生升级事件），随后还原升级扣除的 AP。"""
        p = self.p
        for controller, key in ((mine, 'player_base_level'), (enemy, 'enemy_base_level')):
            target = max(0, min(10, int(self.config.get(key, 0))))
            ap = p.word(controller + 1028)
            while p.call(PB + '14getKyotenLevelEv', controller) < target:
                before = p.call(PB + '14getKyotenLevelEv', controller)
                p.call(PB + '19actionKyotenLevelupEv', controller)
                if p.call(PB + '14getKyotenLevelEv', controller) == before:
                    break
            p.put(controller + 1028, ap)

    def apply_ai(self, mine, enemy):
        """原生 AUTO 同时负责出兵（含弹头车）与绝招；任一开关开启即启动该方 AUTO，
        关闭的部分由原生钩子跳过（头部 +0x30，版本 ≥ 4）。旧核心下两项随“自动出兵”一起开关。"""
        p = self.p
        split = self.native_hooks >= 4
        disable = 0
        for shift, controller, deploy, special in ((0, mine, self.player_ai, self.player_auto_special),
                                                   (2, enemy, self.enemy_ai, self.enemy_auto_special)):
            enabled = (deploy or special) if split else deploy
            p.call(PB + ('13startAutoPlayEv' if enabled else '13resetAutoPlayEv'), controller)
            disable |= ((0 if deploy else 1) | (0 if special else 2)) << shift
        p.put(LAB_HEADER + LAB_AUTO_DISABLE, disable if split else 0)

    def menu_command(self, command):
        """战斗中菜单（lab_menu.LabMenu）的选择结果。"""
        kind = command[0]
        if kind == 'toggle':
            name = command[1]
            setattr(self, name, not getattr(self, name))
            if name == 'full_control':
                if self.full_control:
                    self.applied = False       # 重新执行据点满级
            else:
                mine, enemy, _ = self.controllers()
                if self.active and mine and enemy:
                    self.apply_ai(mine, enemy)
            self.record('menu_toggle', name=name, value=getattr(self, name))
        elif kind == 'cycle':
            name = command[1]
            setattr(self, name, (getattr(self, name) + 1) % len(SUPPORT_OPTIONS))
            self.record('menu_cycle', name=name, value=getattr(self, name))
        elif kind == 'restart':
            self.finish('menu_restart', restart=True)   # 合拢闸门 → 离开 → 重新开始（原生开场闸门打开）
        elif kind == 'exit':
            self.finish('menu_exit')
        elif kind == 'close':
            self.menu.set_open(False)

    def describe(self, controller):
        if not controller:
            return None
        p = self.p
        slots = []
        for slot in range(10):
            unit = p.call('_ZNK16BattleController11getUnitInfoEi', controller, slot)
            if not unit:
                slots.append(None)
                continue
            cooldown = p.word(unit + 0x18)
            slots.append([p.word(unit + 0x10), p.word(unit),
                          cooldown - (1 << 32) if cooldown & 0x80000000 else cooldown])
        return {'address': hex(controller), 'class': self.classes.get(p.word(controller)),
                'team': p.word(controller + 0x38c), 'ap': p.call(PB + '5getAPEv', controller),
                'auto': p.call(PB + '11getAutoPlayEv', controller),
                'kyoten_level': p.call(PB + '14getKyotenLevelEv', controller), 'slots': slots}

    # ---------- 指令 ----------
    def execute(self, command):
        kind = command[0]
        if kind == 'start':
            self.start()
            return
        if kind == 'prep_key':
            if self.prep.open:
                self.prep.key(command[1])
            return
        if kind == 'prep':
            if not self.active and not self.prep.busy():
                if self.prep.open:
                    self.prep.hide()
                elif self.p.word(self.app() + 0x22bc) in (99, SCENE_BATTLE):
                    self.feedback(T(self.p, 'fb_busy'), False)
                else:
                    self.prep.show()
            return
        if kind == 'exit':
            if self.active:
                self.finish('user_exit')
            return
        if kind == 'menu':
            if self.active:
                self.menu.set_open(not self.menu.open)
            return
        if kind == 'menu_move':
            if self.menu.open:
                self.menu.move(command[1])
            return
        if kind == 'menu_select':
            if self.menu.open:
                self.menu.activate()
            return
        if kind == 'toggle_full':
            self.full_control = not self.full_control
            if self.full_control and self.active:
                self.applied = False
            self.feedback(T(self.p, 'fb_full', T(self.p, 'on' if self.full_control else 'off')))
            return
        if kind in ('toggle_enemy_ai', 'toggle_player_ai'):
            if kind == 'toggle_enemy_ai':
                self.enemy_ai = not self.enemy_ai
            else:
                self.player_ai = not self.player_ai
            mine, enemy, _ = self.controllers()
            if self.active and mine and enemy:
                self.apply_ai(mine, enemy)
            self.feedback(T(self.p, 'fb_ai', T(self.p, 'on' if self.enemy_ai else 'off'),
                            T(self.p, 'on' if self.player_ai else 'off')))
            return
        if not self.active:
            return
        mine, enemy, _ = self.controllers()
        if not enemy:
            self.feedback(T(self.p, 'fb_no_enemy'), False)
            return
        p = self.p
        if kind == 'enemy_unit':
            self.enemy_slot(enemy, command[1])
        elif kind == 'enemy_ap':
            if p.call(PB + '15isKyotenLevelupEv', enemy):
                p.call(p.word(p.word(enemy) + 0xa8), enemy)
                self.feedback(T(p, 'fb_enemy_ap'))
            else:
                self.feedback(T(p, 'fb_enemy_ap_no'), False)
        elif kind == 'enemy_slug':
            if p.call(PB + '16isUseMetasuraHouEv', enemy):
                p.call(p.word(p.word(enemy) + 0xa0), enemy)
                if not (self.native_hooks >= 5 and self.enemy_support):
                    self.feedback(T(p, 'fb_enemy_slug'))   # 支援效果由 publish_enemy 依原生计数提示
            else:
                self.feedback(T(p, 'fb_enemy_slug_no'), False)
        elif kind == 'enemy_special':
            from battle_controls import team_units
            ready = [u for u in team_units(p, enemy)
                     if not p.read(u + 0x3d4, 1)[0] and p.call('_ZNK10BattleUnit10isSpAttackEv', u)]
            for unit in ready:
                p.call(p.word(p.word(enemy) + 0x98), enemy, int.from_bytes(p.read(unit + 0x62, 2), 'little'))
            self.feedback(T(p, 'fb_enemy_special', len(ready)) if ready else T(p, 'fb_enemy_special_none'), bool(ready))

    def back(self):
        """在游戏线程处理 LAB 返回请求，过渡期间消费输入以保持单一导航流程。"""
        if self.finishing is not None or self.prep.busy():
            return True
        if self.prep.open:
            self.prep.key('escape')
            return True
        if self.active:
            self.menu.set_open(not self.menu.open)
            return True
        return False

    def enemy_slot(self, enemy, slot):
        p = self.p
        key = 'QWERTYUIOP'[slot]
        main, _ = self.battle()
        if not main or not p.call('_ZN10BattleMain15isBattlePlayingEv', main):
            self.feedback(T(p, 'fb_not_playing', key), False)
            return
        info = p.call('_ZNK16BattleController11getUnitInfoEi', enemy, slot)
        if not info:
            self.feedback(T(p, 'fb_empty_slot', key), False)
            return
        if p.call('_ZNK16BattleController15isUnitCountOverEv', enemy):
            self.feedback(T(p, 'fb_unit_limit', key), False)
            return
        if not p.call(PB + '12isUnitCreateEi', enemy, slot):
            self.feedback(T(p, 'fb_cannot', key, p.call(PB + '5getAPEv', enemy), p.word(info)), False)
            return
        created = p.call(p.word(p.word(enemy) + 0x94), enemy, slot)
        if created:
            # 与我方按键出兵（probe.activate_unit_slot）相同的原生出兵音效。
            p.call('_ZN17FrameworkInstance6playSEENS_9SoundTypeE7SoundIDi', 0, 8, 0)
        self.record('enemy_unit', slot=slot + 1, unit_id=p.word(info + 0x10), created=bool(created))
        self.reveal_slot(True, slot)
        self.feedback(T(p, 'fb_deployed' if created else 'fb_rejected', key), bool(created))
