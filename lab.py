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
import json
import time

CONFIG_NAME = 'lab_config.json'
DEFAULT_CONFIG = {
    'schema': 1,
    'stage_id': 1011,          # 原生联机地图表首项（0x8fd730+48 起：1011,1021,1022,...）
    'enemy_deck': None,        # None=原生 NPC 牌组；或至多 10 项 [单位, 等级(1-40)]，单位为 UnitID 或社区单位 key，null=空槽
    'full_control': True,
    'enemy_ai': False,             # 敌方 AI 自动出兵（含弹头车）
    'player_ai': False,            # 我方 AI 自动出兵（含弹头车）
    'enemy_auto_special': False,   # 敌方自动释放绝招
    'player_auto_special': False,  # 我方自动释放绝招
}
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
LAB_ENEMY_GFX_READY = 0x3c       # 头部偏移：敌方出兵格图集已就绪
LAB_ENEMY_GFX = 0x40             # 头部偏移：敌方 operator+188…+220（9 字）
LAB_ENEMY_PANEL_READY = 0x6c     # 头部偏移：敌方出兵栏状态已初始化
LAB_ENEMY_PANEL = 0x70           # 头部偏移：敌方 operator+24/32/96/100/104/112/116（7 字，+12 为滚动值）
AURA_STRING = 0x103011c3       # BattleEffectRenderer 构造函数引用的 "aura.obm"（.rodata 0x3011c3）
RESULT_SCENES = (110, 120)
SAVE_RAM = 0x3d08              # app 偏移：主存档映像（与 event_trial.EventTrial.transaction 相同）
SAVE_RAM_SIZE = 0x5ab0
PB = '_ZN26BattleControllerPlayerBase'



class Lab:
    def __init__(self, p, root):
        self.p = p
        self.root = Path(root)
        self.commands = collections.deque()
        self.config = self.load_config()
        self.active = False
        self.saved_flags = None
        self.started_frame = 0
        self.applied = False
        self.full_control = bool(self.config['full_control'])
        self.enemy_ai = bool(self.config['enemy_ai'])
        self.player_ai = bool(self.config['player_ai'])
        self.enemy_auto_special = bool(self.config['enemy_auto_special'])
        self.player_auto_special = bool(self.config['player_auto_special'])
        from lab_menu import LabMenu
        self.menu = LabMenu(self)
        self.restart_at = None
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
        path = self.root / CONFIG_NAME
        if not path.is_file():
            path.write_text(json.dumps(DEFAULT_CONFIG, ensure_ascii=False, indent=2), encoding='utf-8')
            return dict(DEFAULT_CONFIG)
        data = json.loads(path.read_text(encoding='utf-8'))
        config = dict(DEFAULT_CONFIG)
        config.update({k: v for k, v in data.items() if k in DEFAULT_CONFIG})
        deck = config['enemy_deck']
        if deck is not None and (not isinstance(deck, list) or len(deck) > 10):
            raise ValueError('lab_config.json: enemy_deck 须为至多 10 项的列表')
        return config

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
        if scene == SCENE_BATTLE or self.active:
            self.feedback('战斗中无法启动 LAB', False)
            return
        self.config = self.load_config()
        # 先完成全部校验与查表，确认无误后才改动原生场景状态。
        configured = None
        if self.config['enemy_deck'] is not None:
            configured = self.resolve_deck(self.config['enemy_deck'])
            for entry in configured:
                if entry is not None and entry[0] >= 400:
                    self.stand_in(entry[0])
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
        p.call('_ZN7AppMain18BattleStartSetUnitEv', app)
        p.call('_ZN7AppMain25BattleStartSetStatusEnemyEv', app)
        # 取代 BattleStartSetUnitEnemy（0x1e8966）：与原生相同按槽位顺序调用 entryUnit，空槽传 -1，
        # 但 UnitID 不经 10 位编码，社区单位可直接写入。
        main = p.word(app + 0xc220)
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
        self.record('start', from_scene=scene, stage_id=stage, native_npc_deck=native_deck,
                    enemy_deck=[None if e is None else [e[0], e[1] + 1] for e in deck],
                    saved_flags=self.saved_flags, config=self.config)
        self.feedback(f'战斗开始 · 地图 {stage}')

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

    def leave(self, reason):
        p = self.p
        app = self.app()
        scene = p.word(app + 0x22bc)
        self.record('leave', reason=reason, scene=scene)
        self.menu.set_open(False)
        try:
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
        p.call('_ZN7AppMain11ChangeExeSTEi', app, 31)
        self.active = False
        self.feedback('已返回菜单')

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
                self.feedback(f'{command} 失败：{error}', False)
        if not self.active:
            if self.restart_at is not None and self.p.frame >= self.restart_at:
                self.restart_at = None
                self.start()
            return
        self.menu.draw()
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
            if not self.valid(main) or (not paused and (scene != SCENE_BATTLE or self.idle_frames >= 60)):
                self.leave(f'battle_finished_scene_{scene}')
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
            self.record('applied', mine=self.describe(mine), enemy=self.describe(enemy))
        if self.full_control:
            for controller in (mine, enemy):
                level = p.call(PB + '14getKyotenLevelEv', controller)
                maximum = p.call(PB + '8getMaxAPEi', controller, level)
                ap = p.call(PB + '5getAPEv', controller)
                if maximum > ap:
                    p.call(PB + '6plusAPEi', controller, maximum - ap)
                p.call(PB + '24clearCreateUnitWaitTimerEv', controller)

    def publish_enemy(self, enemy):
        """头部：+4 功能位，+8 敌方队伍，+16 敌方控制器，+20 敌方成员（controller+924，与 onGameScreenTouchEnded 的 r9 相同）。"""
        p = self.p
        p.put(LAB_HEADER + 4, self.header_flags())
        p.put(LAB_HEADER + 8, p.word(enemy + 0x38c))
        p.put(LAB_HEADER + 16, enemy)
        p.put(LAB_HEADER + 20, p.word(enemy + 924))

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
        self.record('enemy_graphics', operator=hex(operator), fields=[hex(v) for v in built])

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
        elif kind == 'restart':
            self.menu.set_open(False)
            self.leave('menu_restart')
            self.restart_at = self.p.frame + 45   # 返回菜单场景稳定后重新进入
        elif kind == 'exit':
            self.menu.set_open(False)
            self.leave('menu_exit')
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
        if kind == 'exit':
            if self.active:
                self.leave('user_exit')
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
            self.feedback('完全控制 ' + ('开' if self.full_control else '关'))
            return
        if kind in ('toggle_enemy_ai', 'toggle_player_ai'):
            if kind == 'toggle_enemy_ai':
                self.enemy_ai = not self.enemy_ai
            else:
                self.player_ai = not self.player_ai
            mine, enemy, _ = self.controllers()
            if self.active and mine and enemy:
                self.apply_ai(mine, enemy)
            self.feedback(f'敌方 AI {"开" if self.enemy_ai else "关"} · 我方 AI {"开" if self.player_ai else "关"}')
            return
        if not self.active:
            return
        mine, enemy, _ = self.controllers()
        if not enemy:
            self.feedback('未找到敌方控制器', False)
            return
        p = self.p
        if kind == 'enemy_unit':
            self.enemy_slot(enemy, command[1])
        elif kind == 'enemy_ap':
            if p.call(PB + '15isKyotenLevelupEv', enemy):
                p.call(p.word(p.word(enemy) + 0xa8), enemy)
                self.feedback('敌方 AP 升级')
            else:
                self.feedback('敌方 AP 无法升级', False)
        elif kind == 'enemy_slug':
            if p.call(PB + '16isUseMetasuraHouEv', enemy):
                p.call(p.word(p.word(enemy) + 0xa0), enemy)
                self.feedback('敌方弹头车出击')
            else:
                self.feedback('敌方弹头车未就绪', False)
        elif kind == 'enemy_special':
            from battle_controls import team_units
            ready = [u for u in team_units(p, enemy)
                     if not p.read(u + 0x3d4, 1)[0] and p.call('_ZNK10BattleUnit10isSpAttackEv', u)]
            for unit in ready:
                p.call(p.word(p.word(enemy) + 0x98), enemy, int.from_bytes(p.read(unit + 0x62, 2), 'little'))
            self.feedback(f'敌方绝招 {len(ready)} 个' if ready else '敌方无绝招就绪单位', bool(ready))

    def enemy_slot(self, enemy, slot):
        p = self.p
        key = 'QWERTYUIOP'[slot]
        main, _ = self.battle()
        if not main or not p.call('_ZN10BattleMain15isBattlePlayingEv', main):
            self.feedback(f'{key} 战斗未进行', False)
            return
        info = p.call('_ZNK16BattleController11getUnitInfoEi', enemy, slot)
        if not info:
            self.feedback(f'{key} 空槽位', False)
            return
        if p.call('_ZNK16BattleController15isUnitCountOverEv', enemy):
            self.feedback(f'{key} 已达到单位数量上限', False)
            return
        if not p.call(PB + '12isUnitCreateEi', enemy, slot):
            self.feedback(f'{key} 当前无法生产（AP {p.call(PB + "5getAPEv", enemy)} / {p.word(info)}）', False)
            return
        created = p.call(p.word(p.word(enemy) + 0x94), enemy, slot)
        self.record('enemy_unit', slot=slot + 1, unit_id=p.word(info + 0x10), created=bool(created))
        self.reveal_slot(True, slot)
        self.feedback(f'{key} 敌方出击' if created else f'{key} 原生拒绝', bool(created))
