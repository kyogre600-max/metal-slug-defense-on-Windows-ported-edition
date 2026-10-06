"""LAB 界面共用部分：原生素材、文字表（随游戏语言）、按钮按下反馈、原生菜单音效与 BGM、宿主闸门动画。

语言取 app+0x3d64（与原生一致：1 日语，9 繁体中文，10 简体中文，其余显示英语）。
菜单音效经 AppMain::Sound_RequestPlayMenuSE：13 为原生按钮确定音（159 处调用），8 为关闭/返回，
MISSION 菜单 BGM 为 135（SC_MissionMenuInit2 → Sound_RequestPlayBGMEx2）。
"""
import os
from pathlib import Path

W, H = 1280, 720
LANGUAGE_OFFSET = 0x3d64
SE_DECIDE, SE_CLOSE = 13, 8
BGM_MISSION, BGM_STAGE = 135, 103
WHITE, GOLD, GRAY, DARK = (240, 240, 240, 255), (255, 214, 90, 255), (165, 165, 165, 255), (40, 30, 20, 255)
BLUE, RED = (150, 210, 255, 255), (255, 150, 140, 255)

# 原生素材矩形（图集, (x, y, w, h)），按不透明像素的连通区域量得。
HEADER = ('menuparts.obm', (0, 0, 568, 67))                    # 金属标题栏
PANEL = ('popup.obm', (0, 0, 300, 150))                        # 弹窗底板
BOARD = ('pause_window.obm', (15, 58, 290, 212))               # 暂停窗口米色面板（不含烙印标题）
BRICK = ('pause_menu.obm', (0, 0, 512, 320))                   # 暂停背景砖墙
BUTTONS = {'normal': ('menuparts.obm', (191, 144, 190, 23)),   # 棕
           'light': ('menuparts.obm', (191, 120, 190, 23)),    # 米色
           'on': ('menuparts.obm', (191, 168, 90, 23)),        # 绿
           'off': ('menuparts.obm', (282, 168, 90, 23))}       # 红
ICON_BUTTONS = {'ok': ('menuparts.obm', (813, 170, 60, 48)), 'back': ('menuparts.obm', (935, 170, 60, 48))}
TAB_ON, TAB_OFF = ('menuparts.obm', (0, 120, 190, 33)), ('menuparts.obm', (0, 154, 190, 33))
ROW_STYLES = {None: TAB_OFF, 'player': TAB_OFF, 'enemy': ('menuparts.obm', (0, 222, 190, 33))}
CELLS = {'player': ('unit.obm', (362, 151, 50, 50)), 'enemy': ('unit.obm', (428, 125, 50, 50)),
         'empty': ('unit.obm', (439, 188, 50, 50))}
ICON_PAGES = {0: 'unit_icon_01.obm', 1: 'unit_icon_02.obm'}

LANGS = {1: 'JP', 9: 'ZT', 10: 'ZS'}
TEXT = {
    'prep_title': ('LAB · 準備', 'LAB · 准备', 'LAB · 準備', 'LAB · SETUP'),
    'start': ('開始戰鬥 →', '开始战斗 →', 'バトル開始 →', 'START →'),
    'player_deck': ('我方牌組', '我方牌组', '自軍デッキ', 'YOUR DECK'),
    'enemy_deck': ('敵方牌組', '敌方牌组', '敵軍デッキ', 'ENEMY DECK'),
    'all_level': ('全部等級', '全部等级', '全レベル', 'ALL LV'),
    'apply': ('套用', '应用', '適用', 'APPLY'),
    'random': ('隨機', '随机', 'ランダム', 'RANDOM'),
    'clear': ('清空', '清空', 'クリア', 'CLEAR'),
    'empty': ('空', '空', '空き', 'EMPTY'),
    'battle_settings': ('戰鬥設定', '战斗设定', 'バトル設定', 'BATTLE'),
    'player_base': ('我方據點等級', '我方据点等级', '自軍拠点レベル', 'YOUR BASE LV'),
    'enemy_base': ('敵方據點等級', '敌方据点等级', '敵軍拠点レベル', 'ENEMY BASE LV'),
    'max_full': ('MAX（完全控制）', 'MAX（完全控制）', 'MAX（フルコントロール）', 'MAX (FULL CONTROL)'),
    'map': ('地圖', '地图', 'マップ', 'MAP'),
    'control': ('控制', '控制', '操作', 'CONTROL'),
    'full_control': ('完全控制（無冷卻・AP 無限）', '完全控制（无冷却 · AP 无限）', 'フルコントロール（CTなし・AP無限）',
                     'FULL CONTROL (NO CD · ∞ AP)'),
    'player_ai': ('我方 AI 自動出兵', '我方 AI 自动出兵', '自軍 AI 自動出撃', 'YOUR AI DEPLOY'),
    'player_auto_special': ('我方自動施放絕招', '我方自动释放绝招', '自軍 必殺技自動', 'YOUR AUTO SPECIAL'),
    'enemy_ai': ('敵方 AI 自動出兵', '敌方 AI 自动出兵', '敵軍 AI 自動出撃', 'ENEMY AI DEPLOY'),
    'enemy_auto_special': ('敵方自動施放絕招', '敌方自动释放绝招', '敵軍 必殺技自動', 'ENEMY AUTO SPECIAL'),
    'on': ('開', '开', 'ON', 'ON'), 'off': ('關', '关', 'OFF', 'OFF'),
    'advantage': ('優勢設定', '优势设定', '優位設定', 'ADVANTAGE'),
    'adv_hp': ('生命', '生命', 'HP', 'HP'), 'adv_atk': ('攻擊', '攻击', '攻撃', 'ATK'),
    'adv_player': ('我方', '我方', '自軍', 'YOU'), 'adv_enemy': ('敵方', '敌方', '敵軍', 'ENEMY'),
    'presets': ('預設與履歷', '预设与履历', 'プリセット・履歴', 'PRESETS'),
    'preset': ('預設 {}', '预设 {}', 'プリセット {}', 'PRESET {}'),
    'save': ('儲存', '保存', '保存', 'SAVE'), 'load': ('讀取', '读取', '読込', 'LOAD'),
    'history': ('戰鬥履歷', '战斗履历', '戦闘履歴', 'HISTORY'),
    'saved': ('已儲存至預設 {}', '已保存到预设 {}', 'プリセット {} に保存しました', 'Saved to preset {}'),
    'loaded': ('已讀取預設 {}', '已读取预设 {}', 'プリセット {} を読み込みました', 'Loaded preset {}'),
    'preset_empty': ('預設 {} 為空', '预设 {} 为空', 'プリセット {} は空です', 'Preset {} is empty'),
    'hint': ('點擊格子選擇單位・± 調整等級（Lv1–40，僅用於本場，不寫入存檔）・Esc 關閉',
             '点击格子选择单位 · ± 调整等级（Lv1–40，只用于本场，不写存档）· Esc 关闭',
             'マスをクリックでユニット選択・± でレベル調整（Lv1–40、この戦闘のみ・セーブには書き込みません）・Esc で閉じる',
             'Click a slot to pick a unit · ± level (Lv1–40, this battle only, not saved) · Esc to close'),
    'picker_title': ('選擇單位・{}第 {} 格', '选择单位 · {}第 {} 格', 'ユニット選択・{} {} 番', 'SELECT UNIT · {} SLOT {}'),
    'set_empty': ('設為空槽', '设为空槽', '空きにする', 'SET EMPTY'),
    'tab_all': ('全部', '全部', 'すべて', 'ALL'), 'tab_community': ('社群', '社区', 'コミュニティ', 'COMMUNITY'),
    'f0': ('正規軍', '正规军', '正規軍', 'REGULAR'), 'f1': ('叛軍', '叛军', '反乱軍', 'REBEL'),
    'f2': ('普特曼軍', '普特曼军', 'プトレマイック軍', 'PTOLEMAIC'), 'f3': ('火星人', '火星人', 'マーズピープル', 'MARS'),
    'f4': ('其他', '其他', 'その他', 'OTHER'), 'f5': ('聯動', '联动', 'コラボ', 'COLLAB'),
    'community_mark': ('社群', '社区', 'COM', 'COM'),
    'prev': ('上一頁', '上一页', '前へ', 'PREV'), 'next': ('下一頁', '下一页', '次へ', 'NEXT'),
    'page': ('{} / {}（共 {} 個）', '{} / {}（共 {} 个）', '{} / {}（全 {} 体）', '{} / {} ({} units)'),
    'history_title': ('戰鬥履歷（最近 12 場）', '战斗履历（最近 12 场）', '戦闘履歴（直近 12 戦）', 'HISTORY (LAST 12)'),
    'no_history': ('尚無紀錄', '暂无记录', '記録なし', 'No records'),
    'win_player': ('我方勝', '我方胜', '自軍勝利', 'YOU WIN'), 'win_enemy': ('敵方勝', '敌方胜', '敵軍勝利', 'ENEMY WINS'),
    'aborted': ('中止', '中止', '中断', 'ABORTED'),
    'history_row': ('{}   {}   {:.0f} 秒   地圖 {}', '{}   {}   {:.0f} 秒   地图 {}', '{}   {}   {:.0f} 秒   マップ {}',
                    '{}   {}   {:.0f}s   MAP {}'),
    'side_player': ('我方', '我方', '自軍', 'YOUR'), 'side_enemy': ('敵方', '敌方', '敵軍', 'ENEMY'),
    'menu_title': ('LAB 選單', 'LAB 菜单', 'LAB メニュー', 'LAB MENU'),
    'menu_paused': ('戰鬥已暫停', '战斗已暂停', 'バトル一時停止中', 'PAUSED'),
    'restart': ('重新開始', '重新开始', 'リスタート', 'RESTART'),
    'exit_lab': ('返回準備畫面', '返回准备界面', '準備画面へ戻る', 'BACK TO SETUP'),
    'resume': ('繼續', '继续', '続ける', 'RESUME'),
    'fb_busy': ('戰鬥中無法啟動 LAB', '战斗中无法启动 LAB', 'バトル中は LAB を開始できません', 'Cannot start LAB during a battle'),
    'fb_start': ('戰鬥開始・地圖 {}', '战斗开始 · 地图 {}', 'バトル開始・マップ {}', 'Battle start · map {}'),
    'fb_back': ('已返回準備畫面', '已返回准备界面', '準備画面に戻りました', 'Back to setup'),
    'fb_back_menu': ('已返回選單', '已返回菜单', 'メニューに戻りました', 'Back to menu'),
    'fb_failed': ('{} 失敗：{}', '{} 失败：{}', '{} 失敗：{}', '{} failed: {}'),
    'fb_support': ('支援發動', '支援发动', '支援発動', 'Support activated'),
    'fb_full': ('完全控制 {}', '完全控制 {}', 'フルコントロール {}', 'Full control {}'),
    'fb_ai': ('敵方 AI {}・我方 AI {}', '敌方 AI {} · 我方 AI {}', '敵軍 AI {}・自軍 AI {}', 'Enemy AI {} · your AI {}'),
    'fb_no_enemy': ('找不到敵方控制器', '未找到敌方控制器', '敵軍コントローラーが見つかりません', 'Enemy controller not found'),
    'fb_enemy_ap': ('敵方 AP 升級', '敌方 AP 升级', '敵軍 AP レベルアップ', 'Enemy AP level up'),
    'fb_enemy_ap_no': ('敵方 AP 無法升級', '敌方 AP 无法升级', '敵軍 AP はレベルアップできません', 'Enemy AP cannot level up'),
    'fb_enemy_slug': ('敵方合金彈頭出擊', '敌方弹头车出击', '敵軍メタルスラッグ出撃', 'Enemy Metal Slug attack'),
    'fb_enemy_slug_no': ('敵方合金彈頭尚未就緒', '敌方弹头车未就绪', '敵軍メタルスラッグ未準備', 'Enemy Metal Slug not ready'),
    'fb_enemy_special': ('敵方絕招 {} 個', '敌方绝招 {} 个', '敵軍必殺技 {} 体', 'Enemy specials: {}'),
    'fb_enemy_special_none': ('敵方沒有可施放絕招的單位', '敌方无绝招就绪单位', '必殺技が使える敵軍ユニットはいません',
                              'No enemy special ready'),
    'fb_not_playing': ('{} 戰鬥未進行', '{} 战斗未进行', '{} バトル中ではありません', '{} battle not running'),
    'fb_empty_slot': ('{} 空槽位', '{} 空槽位', '{} 空きスロット', '{} empty slot'),
    'fb_unit_limit': ('{} 已達單位數量上限', '{} 已达到单位数量上限', '{} ユニット数の上限です', '{} unit limit reached'),
    'fb_cannot': ('{} 目前無法生產（AP {} / {}）', '{} 当前无法生产（AP {} / {}）', '{} 出撃できません（AP {} / {}）',
                  '{} cannot deploy (AP {} / {})'),
    'fb_deployed': ('{} 敵方出擊', '{} 敌方出击', '{} 敵軍出撃', '{} enemy deployed'),
    'fb_rejected': ('{} 原生拒絕', '{} 原生拒绝', '{} 出撃不可', '{} rejected'),
    'menu_hint': ('點擊或 ↑/↓ + Enter 選擇・Esc 繼續', '点击或 ↑/↓ + Enter 选择 · Esc 继续',
                  'クリック または ↑/↓ + Enter・Esc で続ける', 'Click or ↑/↓ + Enter · Esc to resume'),
}


def lang(p):
    app = p.app_instance()
    return LANGS.get(p.word(app + LANGUAGE_OFFSET) if app else 0, 'EN')


def T(p, key, *args):
    """界面文字（繁体 / 简体 / 日语 / 英语）。"""
    index = ('ZT', 'ZS', 'JP', 'EN').index(lang(p))
    text = TEXT[key][index]
    return text.format(*args) if args else text


def play_se(p, sound):
    try:
        p.call('_ZN7AppMain23Sound_RequestPlayMenuSEE7SoundID', p.app_instance(), sound)
    except Exception as error:
        p.log('LAB_SE_ERROR', sound, type(error).__name__, str(error))


def current_bgm(p):
    """当前播放的 BGM 编号：Sound_RequestPlayBGM（0x1c677c）写入请求 app+38656+208，
    Sound_PlayBGM（0x1c7364）开始播放时移到 app+38656+212 并清空请求。尚有未处理的请求时取请求值。"""
    app = p.app_instance()
    if not app:
        return 0
    return p.word(app + 38656 + 208) or p.word(app + 38656 + 212)


def play_bgm(p, sound):
    try:
        p.call('_ZN7AppMain23Sound_RequestPlayBGMEx2E7SoundIDi', p.app_instance(), sound, 0)
    except Exception as error:
        p.log('LAB_BGM_ERROR', sound, type(error).__name__, str(error))


def fonts():
    from PIL import ImageFont
    folder = Path(os.environ['SystemRoot']) / 'Fonts'
    path = next((folder / n for n in ('msjhbd.ttc', 'msjh.ttc', 'msyhbd.ttc', 'msyh.ttc', 'msgothic.ttc')
                 if (folder / n).is_file()), None)
    cache = {}

    def font(size):
        # 按字号缓存；字体文件只在首次使用该字号时载入。
        if size not in cache:
            cache[size] = ImageFont.truetype(str(path), size)
        return cache[size]
    return font


class Canvas:
    """一次绘制用的画布：文字自动缩小、按钮（含按下状态）与点击区域登记。"""

    def __init__(self, image, skin, font, pressed):
        from PIL import ImageDraw
        self.image, self.skin, self.font, self.pressed = image, skin, font, pressed
        self.draw = ImageDraw.Draw(image)
        self.hitboxes = []

    def fit_size(self, value, size, width, minimum=10):
        """超出宽度时先缩小字号（不低于 minimum），仍超出时以“…”截断。"""
        while size > minimum and self.font(size).getlength(value) > width:
            size -= 1
        return size

    def text(self, xy, value, size=16, fill=WHITE, anchor='la', stroke=2, width=None):
        if width is not None:
            size = self.fit_size(value, size, width)
            font = self.font(size)
            if font.getlength(value) > width:
                while value and font.getlength(value + '…') > width:
                    value = value[:-1]
                value += '…'
        self.draw.text(xy, value, font=self.font(size), fill=fill, anchor=anchor,
                       stroke_width=stroke, stroke_fill=(0, 0, 0, 255))

    def paste(self, part, xy):
        self.image.alpha_composite(part, (int(xy[0]), int(xy[1])))

    def is_pressed(self, command):
        return self.pressed is not None and self.pressed == command

    def button(self, rect, label, command, size=16, style='normal'):
        """原生 menuparts 按钮；按下时下移 2 像素并压暗，抬起时播放原生确定音（由调用方处理）。"""
        x, y, w, h = rect
        down = self.is_pressed(command)
        part = self.skin.nine(BUTTONS[style], w, h, 6)
        if down:
            part = self.skin.darken(part)
        oy = 2 if down else 0
        self.paste(part, (x, y + oy))
        light = style == 'light'
        self.text((x + w / 2, y + h / 2 + oy), label, size, DARK if light else WHITE, 'mm', 0 if light else 2, w - 8)
        self.hitboxes.append((rect, command))

    def icon_button(self, rect, part_name, command):
        x, y, w, h = rect
        part = self.skin.scaled(ICON_BUTTONS[part_name], w, h)
        down = self.is_pressed(command)
        self.paste(self.skin.darken(part) if down else part, (x, y + (2 if down else 0)))
        self.hitboxes.append((rect, command))

    def panel(self, rect, title=None):
        x, y, w, h = rect
        self.paste(self.skin.nine(PANEL, w, h, 10), (x, y))
        if title:
            self.text((x + 14, y + 20), title, 18, GOLD, 'lm', 2, w - 28)

    def header(self, title):
        self.paste(self.skin.nine(HEADER, W, 67, 26), (0, 0))
        self.text((28, 35), title, 26, GOLD, 'lm', 3, 700)


class Skin:
    """原生素材（OI 01 20，32 位 RGBA）的加载、九宫格缩放与单位头像。"""

    def __init__(self, lab):
        self.lab = lab
        self.atlases, self.cache, self.icons = {}, {}, None

    def atlas(self, name):
        if name not in self.atlases:
            import struct
            import probe
            from PIL import Image
            community = Path(self.lab.root) / 'community_content' / name
            path = community if community.is_file() else Path(probe.RESOURCE_ROOT) / probe.PKG / name
            raw = path.read_bytes()
            if raw[:4] != b'OI\x01\x20':
                raise ValueError(f'{name}：不是 32 位 RGBA 图集')
            w, h = struct.unpack_from('<HH', raw, 4)
            self.atlases[name] = Image.frombytes('RGBA', (w, h), raw[8:8 + w * h * 4])
        return self.atlases[name]

    def crop(self, part):
        name, (x, y, w, h) = part
        return self.atlas(name).crop((x, y, x + w, y + h))

    def scaled(self, part, w, h):
        from PIL import Image
        key = ('scaled', part, int(w), int(h))
        if key not in self.cache:
            self.cache[key] = self.crop(part).resize((int(w), int(h)), Image.NEAREST)
        return self.cache[key]

    def darken(self, image, cache=True):
        """压暗（按下状态）。cache 只用于长期保存在 self.cache 中的素材图（以对象 id 为键）。"""
        key = ('dark', id(image))
        if cache and key in self.cache:
            return self.cache[key]
        from PIL import ImageEnhance
        rgb = ImageEnhance.Brightness(image).enhance(0.7)
        rgb.putalpha(image.split()[3])
        if cache:
            self.cache[key] = rgb
        return rgb

    def nine(self, part, w, h, corner):
        """九宫格缩放：四角保持原像素，边与中心以最近邻拉伸。"""
        from PIL import Image
        w, h = int(w), int(h)
        key = ('nine', part, w, h, corner)
        if key in self.cache:
            return self.cache[key]
        src = self.crop(part)
        sw, sh = src.size
        c = min(corner, sw // 2 - 1, sh // 2 - 1, w // 2, h // 2)
        out = Image.new('RGBA', (w, h))
        for sx0, sx1, dx0, dx1 in ((0, c, 0, c), (c, sw - c, c, w - c), (sw - c, sw, w - c, w)):
            for sy0, sy1, dy0, dy1 in ((0, c, 0, c), (c, sh - c, c, h - c), (sh - c, sh, h - c, h)):
                if dx1 > dx0 and dy1 > dy0:
                    out.alpha_composite(src.crop((sx0, sy0, sx1, sy1)).resize((dx1 - dx0, dy1 - dy0), Image.NEAREST),
                                        (dx0, dy0))
        self.cache[key] = out
        return out

    def tiled(self, part, w, h, scale=2, dim=0.55):
        """砖墙等背景按整数倍放大后平铺，并压暗。"""
        from PIL import Image, ImageEnhance
        key = ('tiled', part, w, h, scale, dim)
        if key not in self.cache:
            tile = self.crop(part)
            tile = tile.resize((tile.width * scale, tile.height * scale), Image.NEAREST)
            out = Image.new('RGBA', (w, h), (0, 0, 0, 255))
            for y in range(0, h, tile.height):
                for x in range(0, w, tile.width):
                    out.alpha_composite(tile, (x, y))
            out = ImageEnhance.Brightness(out).enhance(dim)
            self.cache[key] = out
        return self.cache[key]

    def icon_rects(self):
        """UnitID → (图集, 矩形)。原版：菜单表（320 行 × 20 字节，+10 头像序号）→ ConvUnitIcon（16 字节：
        x,y,w,h,锚点 x,y,0,页）；社区单位：注册表 icon.rect（页 1）。"""
        if self.icons is None:
            import struct
            p = self.lab.p
            menu = (p.word(0x101652d0) + 0x101652b4 + 0x818) & 0xffffffff
            conv = p.symbols['ConvUnitIcon']
            icons = {}
            for row in range(320):
                uid = p.word(menu + row * 20)
                index = struct.unpack('<h', p.read(menu + row * 20 + 10, 2))[0]
                if uid and 0 <= index < 340:
                    x, y, w, h, _, _, _, page = struct.unpack('<8h', p.read(conv + index * 16, 16))
                    if w > 0 and h > 0:
                        icons[uid] = (ICON_PAGES.get(page, ICON_PAGES[1]), (x, y, w, h))
            community = getattr(p, 'community', None)
            for unit in (community.units if community is not None else []):
                icon = unit.get('icon')
                if icon:
                    icons[unit['id']] = (ICON_PAGES[icon.get('page', 1)], tuple(icon['rect']))
            self.icons = icons
        return self.icons

    def icon(self, uid, scale):
        """单位头像按与编组格相同的倍率最近邻缩放（原生头像按 50×50 格设计）。"""
        from PIL import Image
        entry = self.icon_rects().get(uid)
        if entry is None:
            return None
        key = ('icon', uid, round(scale, 3))
        if key not in self.cache:
            name, rect = entry
            src = self.atlas(name).crop((rect[0], rect[1], rect[0] + rect[2], rect[1] + rect[3]))
            if src.getbbox() is None:
                self.cache[key] = None
            else:
                self.cache[key] = src.resize((max(1, int(src.width * scale)), max(1, int(src.height * scale))),
                                             Image.NEAREST)
        return self.cache[key]


class Shutter:
    """原生闸门（与 AppMain::SetShutterClose / SetShutterOpen 相同的任务，0x2137b8 / 0x213804）：
    ShutterActionDataInit → CTaskSystem2D::AllDelete(app+0x3830, 5) → 清空 app+0x3820 的 4 个任务槽 →
    createMenuTask(app, app+0x3820, 动作表, 4)；不调用其末尾的 ChangeNT（17/18），场景状态保持不变。
    LAB 每帧调用 CTaskSystem2D::Caller(app+0x3830, 5) 推进任务（GT_Shutter 经 ActionSub2D 按动作表移动并播放
    原生闸门音效），随后 GraphicsOpt::drawStack(app+124) 立即提交，使闸门画在宿主界面之上。
    结束以 IsShutterActionEnd 判定；开闸结束后删除任务。"""

    def __init__(self, lab):
        self.lab = lab
        self.state = 'open'          # open / closing / closed / opening
        self.on_closed = None

    def tables(self):
        p = self.lab.p
        close = p.word((0x102137ea & ~3) + 24) + 0x102137f0          # SetShutterClose 的 pc 相对动作表
        opened = p.word((0x10213836 & ~3) + 28) + 0x1021383c + 224   # SetShutterOpen：同表 +224
        return close, opened

    def create(self, table):
        p = self.lab.p
        app = p.app_instance()
        p.write(app + 0xc200 + 28, bytes((0,)))
        p.call('_Z21ShutterActionDataInitv')
        p.call('_ZN13CTaskSystem2D9AllDeleteEi', app + 0x3830, 5)
        for i in range(4):
            p.put(app + 0x3820 + 4 * i, 0)
        p.call('_ZN7AppMain14createMenuTaskEPP17GENERAL_TASK_BASEPNS_10_MENU_TASKEi', app, app + 0x3820, table, 4)

    def delete(self):
        p = self.lab.p
        app = p.app_instance()
        p.call('_ZN13CTaskSystem2D9AllDeleteEi', app + 0x3830, 5)
        for i in range(4):
            p.put(app + 0x3820 + 4 * i, 0)
        p.write(app + 0xc200 + 28, bytes((1,)))
        # 与原生 SC_ShutterOpen 完成步骤一致：解除闭合标记，恢复普通界面的输入判定。
        p.write(app + 0xc200 + 29, bytes((0,)))

    def close(self, on_closed=None):
        self.create(self.tables()[0])
        self.state, self.on_closed = 'closing', on_closed

    def open(self):
        """从合拢状态开闸（原生战斗结束闸门合拢后，或宿主关闸后）。"""
        self.create(self.tables()[1])
        self.state = 'opening'

    def release(self):
        """原生场景（SC_BattleInit 的 SetShutterOpen）接管闸门：LAB 停止推进，任务交由原生处理。"""
        self.state, self.on_closed = 'open', None

    def set_closed(self):
        pass

    def update_and_draw(self, skin=None):
        if self.state == 'open':
            return
        p = self.lab.p
        app = p.app_instance()
        p.call('_ZN13CTaskSystem2D6CallerEi', app + 0x3830, 5)
        p.call('_ZN11GraphicsOpt9drawStackEv', p.word(app + 124))
        if self.state not in ('closing', 'opening'):
            return
        # 原生 SC_ShutterOpen 或后继场景初始化可先释放任务并清空四个槽。
        # IsShutterActionEnd 对空槽返回 0；已释放的任务需按完成处理，避免准备界面永久阻断返回输入。
        released = not any(p.word(app + 0x3820 + 4 * i) for i in range(4))
        ended = released or p.call('_ZN7AppMain18IsShutterActionEndEv', app)
        if ended:
            if released:
                self.lab.record('shutter_native_release', state=self.state)
            if self.state == 'closing':
                self.state = 'closed'
                callback, self.on_closed = self.on_closed, None
                if callback:
                    callback()
            else:
                self.delete()
                self.state = 'open'

    def close_resources(self):
        pass
