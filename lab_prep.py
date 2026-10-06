"""LAB 准备界面（T8）：宿主自绘的独立全屏界面（砖墙背景、MISSION BGM），F7 经闸门进入，
开始战斗时经闸门进入战斗，战斗结束或退出后经原生闸门回到本界面。

内容：我方/敌方牌组（各 10 格，点格子选单位，±调整等级，一括等级、随机编队、清空）、双方据点初始等级、
地图、完全控制与四个 AI 开关、优势设定（原生关卡强化级数，生命/攻击各 +20%/级）、预设 A/B/C（lab_presets/）
与战斗履历（lab_presets/history.jsonl）。全部设定保存到 lab_config.json；战斗使用的牌组与等级直接交给
BattleController::entryUnit，不写存档。界面文字随游戏语言（lab_ui.TEXT）。
"""
import random

from lab_ui import (W, H, WHITE, GOLD, GRAY, DARK, BLUE, RED, BRICK, CELLS, TAB_ON, TAB_OFF, ROW_STYLES,
                    SE_DECIDE, SE_CLOSE, BGM_MISSION, BGM_STAGE, T, current_bgm, Canvas, Skin, Shutter, fonts, play_se, play_bgm)

HEADER_H = 67
CELL, CELL_GAP = 100, 10                          # 编组格（unit.obm 50×50 原图 2 倍）
DECK_X = (W - (10 * CELL + 9 * CELL_GAP)) // 2
PICK_CELL, PICK_PITCH, PICK_COLS, PICK_ROWS = 75, 100, 12, 4
PICK_X = (W - PICK_COLS * PICK_PITCH) // 2 + (PICK_PITCH - PICK_CELL) // 2
FALLBACK_LANGUAGE = 3
ADVANTAGE_MAX = 10                                # 原生强化级数：每级生命/攻击 +20%
# GetUnitAffiliation：0 正规军 1 叛军 2 普特曼军 3 火星人与僵尸 4 其他 5 联动（依各阵营成员核对）
TABS = (('tab_all', None), ('tab_community', 'community'), ('f0', 0), ('f1', 1), ('f2', 2),
        ('f3', 3), ('f4', 4), ('f5', 5))
BACK_COMMANDS = ('close', 'back')


class LabPrep:
    def __init__(self, lab):
        self.lab = lab
        self.open = False
        self.page = 'main'               # main / picker / history
        self.picker = None               # (side, slot)
        self.tab = 0
        self.picker_page = 0
        self.level_all = {'player': 40, 'enemy': 40}
        self.revision = 0
        self.overlay = None
        self.font = None
        self.skin = Skin(lab)
        self.shutter = Shutter(lab)
        self.hitboxes = []
        self.units = None
        self.pressed = None
        self.pressed_rect = None
        self.return_bgm = None
        self.press_overlay = None
        self.message = ''

    # ---------- 数据 ----------
    def unit_list(self):
        """全部可选单位：原版 1–399 与社区可选单位。原生名称带括号或为“-”的条目是内部子单位
        （投放体、箱体、弹头车攻击等，如“(沙包)”“(伞兵)”），与社区 internal_only 一样排除。
        名称取 GetMenuUnitName(uid, 游戏语言)。(uid, 名称, 阵营, 是否社区)"""
        if self.units is None:
            p, app = self.lab.p, self.lab.app()
            current = p.word(app + 0x3d64)
            def name(uid):
                for language in (current, FALLBACK_LANGUAGE):
                    try:
                        text = p.string(p.call('_Z15GetMenuUnitName6UnitIDi', uid, language))
                    except Exception:
                        text = ''
                    if text and text != '-':
                        return text
                return f'UID {uid}'
            units = []
            for uid in range(1, 400):
                label = name(uid)
                if label.startswith('(') or label == '-':
                    continue
                units.append((uid, label, p.call('_ZN7AppMain18GetUnitAffiliationE6UnitID', app, uid), False))
            community = getattr(p, 'community', None)
            for entry in (community.units if community is not None else []):
                if not entry.get('internal_only'):
                    uid = entry['id']
                    units.append((uid, name(uid), p.call('_ZN7AppMain18GetUnitAffiliationE6UnitID', app, uid), True))
            self.units = units
        return self.units

    def random_pool(self):
        """随机编队的候选：可选单位中具有原生头像的单位（无头像的空单位，如 UID 256、259、265，不进入候选）。"""
        return [u[0] for u in self.unit_list() if self.skin.icon(u[0], 1) is not None]

    def names(self):
        return {uid: name for uid, name, _, _ in self.unit_list()}

    def deck(self, side):
        lab = self.lab
        key = side + '_deck'
        deck = lab.config.get(key)
        if deck is None:
            deck = self.default_deck(side)
            lab.config[key] = deck
        deck = list(deck) + [None] * (10 - len(deck))
        return deck[:10]

    def default_deck(self, side):
        """我方：当前原生牌组；敌方：沿用我方牌组。等级默认 Lv40。"""
        lab = self.lab
        p, app = lab.p, lab.app()
        deck = []
        for slot in range(10):
            uid = p.call('_ZN7AppMain19GetDeckUnitSaveDataEii', app, slot, 0xffffffff)
            deck.append(None if uid in (0, 0xffffffff) or uid & 0x80000000 else [uid, 40])
        return deck

    def resolved(self, side):
        """[(UnitID, 存档等级 0–39) 或 None] × 10，供 Lab.start 使用。"""
        return self.lab.resolve_deck(self.deck(side))

    def uid(self, unit):
        return unit if isinstance(unit, int) else self.lab.community_uid(unit)

    def set_deck(self, side, deck):
        self.lab.config[side + '_deck'] = deck
        self.changed()

    def changed(self):
        self.lab.save_config()
        self.revision += 1

    # ---------- 打开与关闭（闸门） ----------
    def show(self, from_closed=False):
        """显示准备界面并播放 MISSION BGM。from_closed：画面已被闸门遮住（原生战斗结束闸门），直接开闸。"""
        if not from_closed:
            # F7 从当前界面进入：记下该界面正在播放的 BGM，返回时恢复（战斗结束回到准备界面时沿用先前记录）。
            self.return_bgm = current_bgm(self.lab.p)
        def reveal():
            self.open, self.page, self.pressed = True, 'main', None
            self.revision += 1
            play_bgm(self.lab.p, BGM_MISSION)
            self.shutter.open()
        if from_closed:
            reveal()                     # 原生闸门已合拢：直接以原生开闸任务打开
        else:
            self.shutter.close(reveal)

    def hide(self):
        """返回进入 LAB 前的界面：闸门合拢后关闭准备界面，恢复进入前的 BGM，再开闸。"""
        def leave():
            self.open = False
            play_bgm(self.lab.p, self.return_bgm or BGM_STAGE)
            self.shutter.open()
        self.shutter.close(leave)

    def set_open(self, value):
        """无动画的开关（启动战斗、测试脚本使用）。"""
        self.open = bool(value)
        self.page, self.pressed = 'main', None
        self.revision += 1

    def busy(self):
        return self.shutter.state != 'open'

    # ---------- 指令 ----------
    def command(self, name, *args):
        lab = self.lab
        if name == 'start':
            try:
                self.resolved('player')
                self.resolved('enemy')
            except ValueError as error:
                self.message = str(error)
                self.revision += 1
                return
            def begin():
                self.set_open(False)
                lab.commands.append(('start',))
                lab.release_shutter_on_battle = True   # 场景进入战斗初始化后交给 SC_BattleInit 的原生开闸
            self.shutter.close(begin)
        elif name == 'close':
            self.hide()
        elif name == 'slot':
            side, slot = args
            self.page, self.picker, self.picker_page = 'picker', (side, slot), 0
        elif name == 'level':
            side, slot, step = args
            deck = self.deck(side)
            if deck[slot] is not None:
                deck[slot] = [deck[slot][0], max(1, min(40, int(deck[slot][1]) + step))]
                self.set_deck(side, deck)
        elif name == 'level_all':
            side, step = args
            self.level_all[side] = max(1, min(40, self.level_all[side] + step))
        elif name == 'apply_all':
            side = args[0]
            self.set_deck(side, [None if e is None else [e[0], self.level_all[side]] for e in self.deck(side)])
        elif name == 'random':
            side = args[0]
            pool = self.random_pool()
            self.set_deck(side, [[uid, self.level_all[side]] for uid in random.sample(pool, min(10, len(pool)))])
        elif name == 'clear':
            self.set_deck(args[0], [None] * 10)
        elif name == 'base':
            side, step = args
            key = side + '_base_level'
            lab.config[key] = max(0, min(10, int(lab.config.get(key, 0)) + step))
            self.changed()
        elif name == 'advantage':
            key, step = args
            lab.config[key] = max(0, min(ADVANTAGE_MAX, int(lab.config.get(key, 0)) + step))
            self.changed()
        elif name == 'stage':
            stages = lab.stage_list()
            index = stages.index(lab.config['stage_id']) if lab.config['stage_id'] in stages else 0
            lab.config['stage_id'] = stages[(index + args[0]) % len(stages)]
            self.changed()
        elif name == 'toggle':
            setattr(lab, args[0], not getattr(lab, args[0]))
            lab.config[args[0]] = getattr(lab, args[0])
            self.changed()
        elif name == 'pick':
            side, slot = self.picker
            uid = args[0]
            deck = self.deck(side)
            if uid is None:
                deck[slot] = None
            else:
                # 同一牌组不能重复编入（原生 entryUnit 会略过重复单位）：已在其他格时两格互换。
                old = deck[slot]
                for other, entry in enumerate(deck):
                    if other != slot and entry is not None and self.uid(entry[0]) == uid:
                        deck[other] = old
                deck[slot] = [uid, old[1] if old else self.level_all[side]]
            self.set_deck(side, deck)
            self.page = 'main'
        elif name == 'tab':
            self.tab, self.picker_page = args[0], 0
        elif name == 'picker_page':
            self.picker_page = max(0, self.picker_page + args[0])
        elif name == 'back':
            self.page = 'main'
        elif name == 'history':
            self.page = 'history'
        elif name == 'preset_save':
            lab.save_preset(args[0])
            self.message = T(lab.p, 'saved', args[0])
        elif name == 'preset_load':
            self.message = T(lab.p, 'loaded' if lab.load_preset(args[0]) else 'preset_empty', args[0])
        self.revision += 1

    def key(self, name):
        if name == 'escape' and not self.busy():
            play_se(self.lab.p, SE_CLOSE)
            if self.page != 'main':
                self.page = 'main'
                self.revision += 1
            else:
                self.hide()

    def touch(self, action, x, y):
        """按下：按钮显示按下状态；在同一按钮上抬起：播放原生确定（返回类为关闭）音效并执行。"""
        if not self.open and self.shutter.state == 'open':
            return False
        if self.busy():
            return True
        hit = rect = None
        for box, command in reversed(self.hitboxes):
            left, top, w, h = box
            if left <= x < left + w and top <= y < top + h:
                hit, rect = command, box
                break
        if action == 1:
            # 按下反馈只叠加该按钮区域的压暗小图（draw 中绘制），不重绘整个界面。
            self.pressed, self.pressed_rect = hit, rect
        elif action == 3:
            pressed, self.pressed = self.pressed, None
            if hit is not None and hit == pressed:
                play_se(self.lab.p, SE_CLOSE if hit[0] in BACK_COMMANDS else SE_DECIDE)
                self.command(*hit)
        return True

    # ---------- 绘制 ----------
    def draw(self):
        """每帧调用：准备界面（打开时）在下，宿主闸门在上。"""
        if self.open:
            if self.overlay is None:
                from trial_overlay import SurfaceOverlay
                self.overlay = SurfaceOverlay(self.lab.p.graphics)
                self.font = fonts()
            key = ('lab_prep', self.revision)
            image = None
            if self.overlay.cached != key:
                image = self.skin.tiled(BRICK, W, H).copy()
                self.c = Canvas(image, self.skin, self.font, None)
                {'main': self.draw_main, 'picker': self.draw_picker, 'history': self.draw_history}[self.page]()
                self.hitboxes = self.c.hitboxes
                self.rendered = image
            self.overlay.draw_image(image, key, (0, 0, W, H))
            if self.pressed is not None and self.pressed_rect and getattr(self, 'rendered', None) is not None:
                if self.press_overlay is None:
                    from trial_overlay import SurfaceOverlay
                    self.press_overlay = SurfaceOverlay(self.lab.p.graphics)
                x, y, w, h = self.pressed_rect
                press_key = ('lab_prep_press', self.revision, self.pressed_rect)
                part = None
                if self.press_overlay.cached != press_key:
                    part = self.skin.darken(self.rendered.crop((x, y, x + w, y + h)), cache=False)
                self.press_overlay.draw_image(part, press_key, (x, y + 2, w, h))
        self.shutter.update_and_draw(self.skin)

    def cell(self, rect, uid, side, label=None):
        """原生编组格（unit.obm 绿/红/空格 50×50）+ 原生单位头像（与格子同倍率）。"""
        c = self.c
        x, y, size = rect
        style = 'empty' if uid is None else ('player' if side == 'player' else 'enemy')
        part = self.skin.scaled(CELLS[style], size, size)
        down = c.is_pressed(('slot', side, label and int(label) - 1)) if label else False
        c.paste(self.skin.darken(part) if down else part, (x, y))
        if uid is not None:
            icon = self.skin.icon(uid, size / 50)
            if icon is not None:
                c.paste(icon, (x + (size - icon.width) // 2, y + (size - icon.height) // 2))
        if label is not None:
            c.text((x + 6, y + 3), label, 14, WHITE)

    def draw_main(self):
        lab, c, p = self.lab, self.c, self.lab.p
        names = self.names()
        c.header(T(p, 'prep_title'))
        c.icon_button((W - 190, 4, 75, 60), 'ok', ('start',))
        c.icon_button((W - 100, 4, 75, 60), 'back', ('close',))
        c.text((W - 200, 35), T(p, 'start'), 18, GOLD, 'rm', 2, 260)
        for row, side in enumerate(('player', 'enemy')):
            top = HEADER_H + 10 + row * 158
            c.text((DECK_X, top + 13), T(p, side + '_deck'), 18, BLUE if side == 'player' else RED, 'lm', 2, 150)
            x = DECK_X + 160
            c.text((x, top + 13), T(p, 'all_level'), 14, WHITE, 'lm', 2, 80)
            c.button((x + 84, top, 28, 26), '-', ('level_all', side, -1))
            c.text((x + 146, top + 13), f'Lv{self.level_all[side]}', 16, WHITE, 'mm')
            c.button((x + 180, top, 28, 26), '+', ('level_all', side, 1))
            c.button((x + 218, top, 80, 26), T(p, 'apply'), ('apply_all', side), 14, 'light')
            c.button((DECK_X + 10 * CELL + 9 * CELL_GAP - 186, top, 90, 26), T(p, 'random'), ('random', side), 14)
            c.button((DECK_X + 10 * CELL + 9 * CELL_GAP - 90, top, 90, 26), T(p, 'clear'), ('clear', side), 14, 'off')
            for slot, entry in enumerate(self.deck(side)):
                x, y = DECK_X + slot * (CELL + CELL_GAP), top + 32
                uid = None if entry is None else self.uid(entry[0])
                self.cell((x, y, CELL), uid, side, str(slot + 1))
                c.hitboxes.append(((x, y, CELL, CELL), ('slot', side, slot)))
                if entry is None:
                    c.text((x + CELL // 2, y + CELL // 2), T(p, 'empty'), 18, GRAY, 'mm', 2, CELL - 10)
                    continue
                c.text((x + CELL // 2, y + CELL - 11), names.get(uid, str(uid)), 13, WHITE, 'mm', 2, CELL - 8)
                c.button((x, y + CELL + 4, 28, 24), '-', ('level', side, slot, -1))
                c.text((x + CELL // 2, y + CELL + 16), f'Lv{entry[1]}', 16, GOLD, 'mm', 2, CELL - 58)
                c.button((x + CELL - 28, y + CELL + 4, 28, 24), '+', ('level', side, slot, 1))
        # 下方四块面板：等宽间隔，左右边距与牌组对齐。
        top, height = HEADER_H + 334, H - HEADER_H - 334 - 34
        left, right = DECK_X, DECK_X + 10 * CELL + 9 * CELL_GAP
        widths = (270, 330, 250)
        gap = 10
        last = right - left - sum(widths) - 3 * gap
        xs = [left]
        for w in widths:
            xs.append(xs[-1] + w + gap)
        boxes = list(zip(xs, list(widths) + [last]))
        self.draw_settings(boxes[0], top, height)
        self.draw_control(boxes[1], top, height)
        self.draw_advantage(boxes[2], top, height)
        self.draw_presets(boxes[3], top, height)
        c.text((W // 2, H - 17), T(p, 'hint'), 12, GRAY, 'mm', 1, W - 40)

    def stepper(self, x, y, w, value, minus, plus):
        c = self.c
        c.button((x, y, 30, 28), '<', minus)
        c.text((x + w / 2, y + 14), value, 15, GOLD, 'mm', 2, w - 68)
        c.button((x + w - 30, y, 30, 28), '>', plus)

    def draw_settings(self, box, top, height):
        lab, c, p = self.lab, self.c, self.lab.p
        x, w = box
        c.panel((x, top, w, height), T(p, 'battle_settings'))
        rows = []
        for side in ('player', 'enemy'):
            value = int(lab.config.get(side + '_base_level', 0))
            shown = T(p, 'max_full') if lab.full_control else ('MAX' if value >= 10 else f'Lv{value}')
            rows.append((T(p, side + '_base'), shown, ('base', side, -1), ('base', side, 1)))
        rows.append((T(p, 'map'), str(lab.config['stage_id']), ('stage', -1), ('stage', 1)))
        for index, (title, value, minus, plus) in enumerate(rows):
            y = top + 44 + index * 68
            c.text((x + 14, y + 10), title, 15, WHITE, 'lm', 2, w - 28)
            self.stepper(x + 14, y + 26, w - 28, value, minus, plus)

    def draw_control(self, box, top, height):
        lab, c, p = self.lab, self.c, self.lab.p
        x, w = box
        c.panel((x, top, w, height), T(p, 'control'))
        for index, attr in enumerate(('full_control', 'player_ai', 'player_auto_special', 'enemy_ai',
                                      'enemy_auto_special')):
            y = top + 44 + index * 40
            on = getattr(lab, attr)
            c.text((x + 14, y + 15), T(p, attr), 15, WHITE, 'lm', 2, w - 110)
            c.button((x + w - 86, y, 72, 30), T(p, 'on' if on else 'off'), ('toggle', attr), 16, 'on' if on else 'off')

    def draw_advantage(self, box, top, height):
        """优势设定：原生关卡强化级数（BattleObjectManager+72 起每队两个浮点数，生命/攻击各 ×(1+0.2×级数)）。"""
        lab, c, p = self.lab, self.c, self.lab.p
        x, w = box
        c.panel((x, top, w, height), T(p, 'advantage'))
        y = top + 44
        for side in ('player', 'enemy'):
            c.text((x + 14, y + 10), T(p, 'adv_' + side), 15, BLUE if side == 'player' else RED, 'lm', 2, w - 28)
            y += 24
            for stat in ('hp', 'atk'):
                key = f'{side}_{stat}_boost'
                steps = int(lab.config.get(key, 0))
                c.text((x + 14, y + 14), T(p, 'adv_' + stat), 15, WHITE, 'lm', 2, 54)
                self.stepper(x + 70, y, w - 84, f'+{steps * 20}%', ('advantage', key, -1), ('advantage', key, 1))
                y += 34
            y += 4

    def draw_presets(self, box, top, height):
        c, p = self.c, self.lab.p
        x, w = box
        c.panel((x, top, w, height), T(p, 'presets'))
        bw = (w - 28 - 70 - 8) // 2
        for index, name in enumerate('ABC'):
            y = top + 44 + index * 40
            c.text((x + 14, y + 15), T(p, 'preset', name), 15, WHITE, 'lm', 2, 66)
            c.button((x + 84, y, bw, 30), T(p, 'save'), ('preset_save', name), 14)
            c.button((x + 84 + bw + 8, y, bw, 30), T(p, 'load'), ('preset_load', name), 14, 'light')
        c.button((x + 14, top + 44 + 3 * 40, w - 28, 30), T(p, 'history'), ('history',), 15)
        if self.message:
            c.text((x + w / 2, top + 44 + 4 * 40 + 16), self.message, 14, GOLD, 'mm', 2, w - 28)

    def filtered(self):
        tab = TABS[self.tab][1]
        units = self.unit_list()
        if tab == 'community':
            return [u for u in units if u[3]]
        if tab is None:
            return units
        return [u for u in units if u[2] == tab]

    def draw_picker(self):
        c, p = self.c, self.lab.p
        side, slot = self.picker
        c.header(T(p, 'picker_title', T(p, 'side_' + side), slot + 1))
        c.icon_button((W - 100, 4, 75, 60), 'back', ('back',))
        c.button((W - 260, 18, 140, 32), T(p, 'set_empty'), ('pick', None), 16, 'light')
        tab_w = (W - 48 - 7 * 8) // 8
        for index, (label, _) in enumerate(TABS):
            x = 24 + index * (tab_w + 8)
            down = c.is_pressed(('tab', index))
            part = self.skin.nine(TAB_ON if index == self.tab else TAB_OFF, tab_w, 33, 6)
            c.paste(self.skin.darken(part) if down else part, (x, 76 + (2 if down else 0)))
            active = index == self.tab
            c.text((x + tab_w / 2, 93 + (2 if down else 0)), T(p, label), 16, DARK if active else WHITE, 'mm',
                   0 if active else 2, tab_w - 10)
            c.hitboxes.append(((x, 76, tab_w, 33), ('tab', index)))
        units = self.filtered()
        per_page = PICK_COLS * PICK_ROWS
        pages = max(1, (len(units) + per_page - 1) // per_page)
        self.picker_page = min(self.picker_page, pages - 1)
        for index, (uid, name, faction, community) in enumerate(units[self.picker_page * per_page:][:per_page]):
            col, row = index % PICK_COLS, index // PICK_COLS
            x, y = PICK_X + col * PICK_PITCH, 122 + row * (PICK_CELL + 32)
            self.cell((x, y, PICK_CELL), uid, side)
            if c.is_pressed(('pick', uid)):
                c.paste(self.skin.darken(self.skin.scaled(CELLS['player' if side == 'player' else 'enemy'],
                                                          PICK_CELL, PICK_CELL)), (x, y))
                icon = self.skin.icon(uid, PICK_CELL / 50)
                if icon is not None:
                    c.paste(icon, (x + (PICK_CELL - icon.width) // 2, y + (PICK_CELL - icon.height) // 2))
            if community:
                c.text((x + PICK_CELL - 4, y + 3), T(p, 'community_mark'), 12, GOLD, 'ra', 2)
            c.text((x + PICK_CELL / 2, y + PICK_CELL + 13), name, 13, WHITE, 'mm', 2, PICK_PITCH - 6)
            c.hitboxes.append(((x, y, PICK_CELL, PICK_CELL + 26), ('pick', uid)))
        c.button((24, H - 54, 140, 38), T(p, 'prev'), ('picker_page', -1), 16)
        c.text((W / 2, H - 35), T(p, 'page', self.picker_page + 1, pages, len(units)), 16, WHITE, 'mm', 2, 600)
        c.button((W - 164, H - 54, 140, 38), T(p, 'next'), ('picker_page', 1), 16)

    def draw_history(self):
        c, p = self.c, self.lab.p
        c.header(T(p, 'history_title'))
        c.icon_button((W - 100, 4, 75, 60), 'back', ('back',))
        entries = self.lab.read_history()[-12:][::-1]
        if not entries:
            c.text((W / 2, H / 2), T(p, 'no_history'), 20, GRAY, 'mm')
        for index, entry in enumerate(entries):
            y = HEADER_H + 12 + index * 52
            winner = entry.get('winner')
            c.paste(self.skin.nine(ROW_STYLES.get(winner, ROW_STYLES[None]), W - 48, 48, 8), (24, y))
            result = T(p, {'player': 'win_player', 'enemy': 'win_enemy'}.get(winner, 'aborted'))
            c.text((40, y + 24), T(p, 'history_row', entry.get('time', ''), result, entry.get('seconds', 0),
                                   entry.get('stage_id')), 16, WHITE, 'lm', 2, 380)
            for side_index, key in enumerate(('player_units', 'enemy_units')):
                for i, uid in enumerate([u for u in entry.get(key, []) if u][:10]):
                    icon = self.skin.icon(uid, 36 / 50)
                    if icon is not None:
                        c.paste(icon, (430 + side_index * 410 + i * 38 + (36 - icon.width) // 2,
                                       y + 6 + (36 - icon.height) // 2))

    def close_resources(self):
        for overlay in (self.overlay, self.press_overlay):
            if overlay is not None:
                overlay.close()
        self.overlay = self.press_overlay = None
        self.shutter.close_resources()
