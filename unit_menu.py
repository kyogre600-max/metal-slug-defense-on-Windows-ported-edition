"""单位菜单（U1b，开工说明第 3.2–3.5 节与已确认样张 u1_unit_menu / u1_lv_up_states / u1_status / u1_action）。

点进单位后的页面：左为名称槽与 STATUS、LV UP、ACTION 三个原生列表按钮，中为原生动作浏览画框（单位待机动作，
unit_viewer），下为等级进度条、等级 / 上限、MAX 与 AP（D28）；左右箭头切换到浏览大菜单同一筛选结果的上一个、下一个单位；
画框右上为收藏切换（D13）。

面板（模态，底下页面压暗）：
- LV UP（D2、D29）：+1 / +10 / 升满三列，按钮旁为 MSP 合计；目标超出当前上限的列为红色按钮加锁；到上限且可购买开放阶段时
  三列均加锁，按下打开“解除 Lv 上限限制”窗口（D37，与原生窗口构成相同，勋章与 MSP 两种付款）；到上限且为世界进度或
  军队核心限制、或已到 Lv40 时三列均为原生“無法強化”。下方为 HP 与三种攻击伤害（可升级时为“当前 → 选中列”）。
- STATUS（D10、D39）：三栏公开参数；不显示攻击属性。
- ACTION（D11、D14、D40）：待机、近距离、远距离、特殊攻击（单位没有的类别不显示），下方为原生单位说明。

强化、开放阶段交易经 unit_catalog（按原生事务顺序组合原生存档函数，附录 A.1、A.3），音效同原生（A.10）。

商店（U1c，样张 u1_shop_unit_menu / u1_shop_buy）：左侧按钮为 STATUS、BUY、ACTION（D9）；画框左上为勋章售价，说明条为
带锁的空进度条与 AP（D31）。购买确认（D32）与原生商店购买弹窗构成相同：标题为单位名称，正文为勋章图标加原生字串
strShop 5 第二行；成功播放 805 与 9 并显示原生 strShop 7，勋章不足为 strShop 8 第一行（不询问是否前往商店），
已拥有为 strShop 12。浏览大菜单卡片上的 BUY（D35）以 open_buy 把确认窗口直接画在浏览大菜单之上。
LV UP 与开放阶段的 MSP、勋章不足同样只提示原生 strShop 9 / 8 第一行（含不足数量），不询问是否前往商店。
"""
import math
import re
import time

from lab_ui import W, H, play_se
from unit_browser import (CARD_SCALE, MAX, RED, TAB_OFF, TAB_ON, POPUP, DLG_RED, DLG_BROWN, ARROW, FAVORITE_STAR,
                          scaled, star_polygon)
from unit_viewer import UnitViewer

TITLED = ('shop.obm', (0, 71, 206, 128))           # 强化卡片：顶部名称槽 + 棕色底板
CAPTION = ('popup_2.obm', (1, 193, 306, 36))       # 动作浏览下方的棕色说明条
SLATE = ('shop.obm', (447, 0, 62, 62))             # 深色小底板（四角铆钉）
GRAYBTN = ('shop.obm', (133, 475, 84, 23))         # 原生“無法強化”按钮
LEVEL_UP = ('shop.obm', (113, 331, 72, 13))        # “LEVEL UP”字样
LOCK_ICON = ('shop.obm', (461, 194, 32, 33))       # 原生强化按钮上的锁
MSP_ICON = ('menuparts.obm', (982, 1, 29, 23))
CYAN = (209, 251, 255, 255)                        # 原生弹窗边框色
WHITE, GRAY, YELLOW, DARK = (255, 255, 255, 255), (205, 205, 200, 255), (245, 225, 90, 255), (40, 30, 20, 255)
GREEN, SHORT = (120, 255, 140, 255), (255, 90, 70, 255)
# 原生弹窗按钮字样（实测原生购买弹窗，verification/u1c_20261012/driver_font_probe.py）：原生以游戏语言的字体按 24 号、白色、
# 无描边光栅化（strEtc 0 / 1），再按 1.125 倍（原生 960 基准到 1280 画布）绘制；文字按前进宽度居中后左移 5、上移 3 像素。
LABEL_SIZE, LABEL_SCALE, LABEL_SHIFT = 24, 1.125, (-5, -3)

SE_UPGRADE, SE_BEEP, SE_THANKS, SE_BUY = 2, 18, 805, 9   # 附录 A.10

MENU_PANEL = (40, 128, 372, 420)
FRAME = (492, 128, 676, 328)
FOOT = (FRAME[0] + FRAME[2] // 2, FRAME[1] + FRAME[3] - 70)
CAPTION_BOX = (492, 466, 676, 82)
LV_PANEL = (200, 155, 880, 410)
BIG_PANEL = (60, 108, 1160, 488)
LIMIT_PANEL = (303, 127, 672, 430)                 # 与原生“解除 Lv 上限限制”窗口相同（300×192 原生弹窗 2.25 倍）
CONFIRM_PANEL = (303, 150, 673, 380)
MESSAGE_PANEL = (303, 213, 673, 260)
BUY_PANEL = (303, 173, 673, 337)                   # 原生商店购买弹窗（300×150 原生弹窗 2.25 倍，D32）
DECO = {0: (6, 2), 2: (7, 1.5)}                    # 原生字串中的 [deco0] 勋章、[deco2] MSP：ConvMenuParts 序号与倍率
ACTION_ORDER = ('neutral', 'near', 'normal', 'special')
FLASH_FRAMES = 10
DESC_LINES, DESC_LINE_H = 3, 30                    # ACTION 说明条可见行数与行距；超出时显示滚动条（滚轮、拖动、↑↓）
SCROLL_W = 14

# 原生字串（序号）：strShop 22–25 动作类别；strCustomize 1“無法強化”、21/22 單體 / 範圍、28 解除 Lv 上限限制、
# 30 是否要解除 Lv 上限限制？；strEtc 0 CANCEL、1 OK。
NATIVE = {
    'neutral': ('_Z13GetStringShopii', 22), 'near': ('_Z13GetStringShopii', 23),
    'normal': ('_Z13GetStringShopii', 24), 'special': ('_Z13GetStringShopii', 25),
    'na': ('_Z18GetStringCustomizeii', 1), 'single': ('_Z18GetStringCustomizeii', 21),
    'spread': ('_Z18GetStringCustomizeii', 22), 'limit_title': ('_Z18GetStringCustomizeii', 28),
    'limit_body': ('_Z18GetStringCustomizeii', 30), 'cancel': ('_Z12GetStringEtcii', 0), 'ok': ('_Z12GetStringEtcii', 1),
    # strShop 5“%s\n[deco0]: Buy for %d?”、7“Thank you for your purchase.”、8 / 9 勋章 / MSP 不足（第一行为不足数量，
    # 第二行询问是否前往商店，本界面不使用）、12“Already at capacity.”
    'buy_line': ('_Z13GetStringShopii', 5), 'thanks': ('_Z13GetStringShopii', 7),
    'medal_need': ('_Z13GetStringShopii', 8), 'msp_need': ('_Z13GetStringShopii', 9),
    'capacity': ('_Z13GetStringShopii', 12),
}
# 宿主文字（繁中、简中、日、英、西、葡、韩，D4）
TEXT = {
    'favorite': ('收藏', '收藏', 'お気に入り', 'FAVORITE', 'FAVORITO', 'FAVORITO', '즐겨찾기'),
    'redeploy': ('再出擊', '再出击', '再出撃', 'REDEPLOY', 'REDESPLIEGUE', 'REIMPLANTAR', '재출격'),
    'knockback_res': ('抗擊退', '抗击退', 'ノックバック耐性', 'KNOCKBACK RES.', 'RES. EMPUJE', 'RES. EMPURRÃO', '넉백 저항'),
    'move': ('移動速度', '移动速度', '移動速度', 'MOVE', 'MOVIMIENTO', 'MOVIMENTO', '이동 속도'),
    'reward': ('擊破獎勵', '击破奖励', '撃破報酬', 'KILL REWARD', 'RECOMPENSA', 'RECOMPENSA', '격파 보상'),
    'damage': ('傷害', '伤害', 'ダメージ', 'DAMAGE', 'DAÑO', 'DANO', '피해'),
    'force': ('擊退力', '击退力', 'ノックバック力', 'KNOCKBACK', 'EMPUJE', 'EMPURRÃO', '넉백'),
    'range': ('射程', '射程', '射程', 'RANGE', 'ALCANCE', 'ALCANCE', '사거리'),
    'interval': ('攻擊間隔', '攻击间隔', '攻撃間隔', 'INTERVAL', 'INTERVALO', 'INTERVALO', '공격 간격'),
    'target': ('目標', '目标', '対象', 'TARGET', 'OBJETIVO', 'ALVO', '대상'),
    'cooldown_first': ('首次冷卻', '首次冷却', '初回クールダウン', 'COOLDOWN (1ST)', 'ENFRIAMIENTO (1.º)', 'RECARGA (1ª)',
                       '첫 쿨다운'),
    'cooldown': ('冷卻', '冷却', 'クールダウン', 'COOLDOWN', 'ENFRIAMIENTO', 'RECARGA', '쿨다운'),
    'msp_short': ('MSP 不足', 'MSP 不足', 'MSP が足りません', 'NOT ENOUGH MSP', 'MSP INSUFICIENTE', 'MSP INSUFICIENTE',
                  'MSP 부족'),
    'medal_short': ('勳章不足', '勋章不足', '勲章が足りません', 'NOT ENOUGH MEDALS', 'MEDALLAS INSUFICIENTES',
                    'MEDALHAS INSUFICIENTES', '훈장 부족'),
    'unavailable': ('無法購買', '无法购买', '購入できません', 'UNAVAILABLE', 'NO DISPONIBLE', 'INDISPONÍVEL', '구입 불가'),
}
SOURCE_TEXT = {'original': ('原版', '原版', 'オリジナル', 'ORIGINAL', 'ORIGINAL', 'ORIGINAL', '오리지널'),
               'body': ('S1XLV', 'S1XLV', 'S1XLV', 'S1XLV', 'S1XLV', 'S1XLV', 'S1XLV')}


def inside(rect, x, y):
    return rect[0] <= x < rect[0] + rect[2] and rect[1] <= y < rect[1] + rect[3]


def seconds(ticks):
    """原生 30 tick 为 1 秒；不足 1 秒保留两位小数。"""
    value = max(0, ticks) / 30
    return f'{value:.2f} s' if value < 1 else f'{value:.1f} s'


class UnitMenu:
    def __init__(self, browser):
        self.b = browser
        self.p = browser.p
        self.key = None
        self.panel = None               # None / 'lvup' / 'limit' / 'confirm' / 'buy' / 'message' / 'status' / 'action'
        self.under = None               # 'message' 关闭后回到的面板
        self.message = None
        self.after_message = None       # 'message' 关闭后：None 回到 under，'dismiss' 关闭购买确认，'close' 回到浏览大菜单
        self.standalone = False         # 购买确认直接画在浏览大菜单之上（卡片 BUY，D35）
        self.selected = 0               # LV UP 选中列
        self.action = 'neutral'
        self.flash = 0
        self.viewer = UnitViewer(self.p)
        self.base = None                # 面板打开期间压暗后的底层
        self.native_strings = {}
        self.labels = {}
        self.desc_scroll = 0            # ACTION 说明条首行
        self.desc_count = 0
        self.desc_track = None          # (轨道 y, 轨道高, 滑块高)，由 compose_action 记录
        self.desc_drag = None

    # ---------- 开关 ----------
    @property
    def active(self):
        return self.key is not None

    def open(self, key):
        self.key = key
        self.panel = None
        self.base = None
        self.selected = 0
        self.flash = 0
        self.standalone = False
        self.after_message = None
        self.show_unit()

    def open_buy(self, key):
        """浏览大菜单卡片上的 BUY（D35）：购买确认直接画在浏览大菜单之上，不进入单位菜单页面、不演示动作。"""
        self.key = key
        self.flash = 0
        self.standalone = True
        self.after_message = None
        self.base = self.b.shaded(self.b.rendered) if self.b.rendered is not None else None
        self.panel = 'buy'

    def close(self):
        self.viewer.clear()
        self.desc_drag = None
        self.key = None
        self.panel = None
        self.base = None
        self.standalone = False
        self.after_message = None

    def show_unit(self):
        self.desc_scroll = 0
        entry = self.entry()
        try:
            self.viewer.play(entry['uid'], 'neutral', entry['key'])
        except Exception as error:
            self.p.log('UNIT_MENU_VIEWER_ERROR', type(error).__name__, str(error))
            self.viewer.uid = None

    def entry(self):
        return self.b.catalog().entry(self.key)

    def info(self):
        return self.b.catalog().level_cap(self.key)

    def stats(self, level):
        return self.b.catalog().stats(self.entry()['uid'], level)

    def shop(self):
        return self.b.mode == 'shop'

    def price(self):
        """勋章售价（与原生购买相同：GetMenuShopPrice 按单位折扣率计算）。"""
        entry = self.entry()
        return self.b.catalog().shop_price(entry['shop_id'], entry['uid']) if entry['shop_id'] is not None else 0

    # ---------- 文字 ----------
    def lang_index(self):
        from unit_browser import LANG_INDEX
        return LANG_INDEX.get(self.b.language(), 3)

    def tr(self, key):
        if key in NATIVE:
            return self.native(key)
        if key in TEXT:
            return TEXT[key][self.lang_index()]
        return self.b.tr(key)

    def native(self, key):
        from unit_browser import NATIVE_LANGUAGES
        language = self.b.language()
        cache = (key, language)
        if cache not in self.native_strings:
            symbol, index = NATIVE[key]
            value = ''
            for lang in ((language,) if language in NATIVE_LANGUAGES and language != 8 else ()) + ((9,) if language == 8 else ()) + (0,):
                try:
                    value = self.p.string(self.p.call(symbol, index, lang)).strip()
                except Exception:
                    value = ''
                if value:
                    break
            self.native_strings[cache] = value.lstrip(':：').strip()
        return self.native_strings[cache]

    def text(self, img, xy, value, size, fill=WHITE, anchor='lm', stroke=2, width=None):
        self.b.text(img, xy, value, size, fill, anchor, stroke, width)

    def rich_text(self, img, cx, cy, text, size, width, fill=WHITE):
        """一行原生字串，居中于 (cx, cy)：[deco0] / [deco2] 画成原生勋章 / MSP 图标（ConvMenuParts 6 / 7），超宽时缩小字号。"""
        art = self.b.art
        parts = re.split(r'\[deco(\d)\]', text)
        while True:
            font = self.b.font(size)
            total = 0.0
            for i, piece in enumerate(parts):
                if i % 2:
                    index, k = DECO.get(int(piece), DECO[0])
                    total += art.conv_scaled(index, k)[0].width + 6
                else:
                    total += font.getlength(piece)
            if total <= width or size <= 14:
                break
            size -= 1
        x = cx - total / 2
        for i, piece in enumerate(parts):
            if i % 2:
                index, k = DECO.get(int(piece), DECO[0])
                sprite = art.conv_scaled(index, k)[0]
                img.alpha_composite(sprite, (round(x), round(cy - sprite.height / 2)))
                x += sprite.width + 6
            elif piece:
                self.text(img, (x, cy), piece, size, fill, 'lm', 0)
                x += font.getlength(piece)

    def button_label(self, img, rect, label):
        """原生弹窗按钮字样：与原生相同的字体（text_render.font_for，按游戏语言）、字号、颜色与缩放（LABEL_*）。"""
        from PIL import Image, ImageDraw
        key = (self.b.language(), label)
        cached = self.labels.get(key)
        if cached is None:
            font = self.b.font(LABEL_SIZE)
            asc, desc = font.getmetrics()
            advance = font.getlength(label)
            raster = Image.new('RGBA', (max(1, math.ceil(advance)) + 4, asc + desc))
            font.draw(ImageDraw.Draw(raster), (2, asc), label, fill=WHITE)
            k = LABEL_SCALE
            cached = (raster.resize((round(raster.width * k), round(raster.height * k)), Image.BILINEAR), advance * k, 2 * k)
            self.labels[key] = cached
        layer, advance, margin = cached
        x, y, w, h = rect
        img.alpha_composite(layer, (round(x + (w - advance) / 2 - margin + LABEL_SHIFT[0]),
                                    round(y + (h - layer.height) / 2 + LABEL_SHIFT[1])))

    # ---------- 合成 ----------
    def compose(self):
        """当前页面图像与点击区域。"""
        b, art = self.b, self.b.art
        if self.panel is not None and self.base is not None:
            img = self.base.copy()
            return img, self.compose_panel(img)
        img, boxes = b.chrome(['back'])
        boxes += self.compose_menu(img)
        if self.panel is not None:
            self.base = b.shaded(img)
            img = self.base.copy()
            boxes = self.compose_panel(img)
        return img, boxes

    def compose_menu(self, img):
        from PIL import Image, ImageDraw
        b, art = self.b, self.b.art
        entry = self.entry()
        info = self.info()
        level, cap = info['level'] or 1, info['cap']
        boxes = []
        px, py, pw, ph = MENU_PANEL
        img.alpha_composite(art.slice(TITLED, pw, ph, (28, 30, 28, 12), 2), (px, py))
        logo = art.logo(entry['faction'])
        nx = px + 64
        if logo is not None:
            img.alpha_composite(logo, (nx, py + 15))
            nx += logo.width + 12
        self.text(img, (nx, py + 30), entry['name'], 28, anchor='lm', width=px + pw - 40 - nx)
        shop = self.shop()
        buttons = (('status', 'STATUS'), ('buy', 'BUY') if shop else ('lvup', 'LV UP'), ('action', 'ACTION'))
        for i, (name, label) in enumerate(buttons):
            rect = (px + 36, py + 104 + i * 96, pw - 72, 64)
            img.alpha_composite(art.slice(TAB_OFF, rect[2], rect[3], (8, 8, 8, 8), 2), rect[:2])
            self.text(img, (rect[0] + rect[2] / 2, rect[1] + rect[3] / 2), label, 28, anchor='mm')
            boxes.append((rect, ('open', name)))
        sx, sy, sw, sh = FRAME
        img.alpha_composite(art.slice(POPUP, sw, sh, (6, 6, 6, 6), 2), (sx, sy))
        if shop:
            # 商店（D31）：画框左上为勋章售价（原生勋章图标、冒号与银色数字），不设收藏切换（样张 u1_shop_unit_menu）。
            b.conv_paste(img, 6, sx + 26, sy + 30, 2)
            b.conv_paste(img, 8, sx + 70, sy + 30, 2)
            b.number(img, sx + 86, sy + 30, self.price(), 0, 2, 18, lead=False)
        else:
            favorite = self.key in b.favorites()
            d = ImageDraw.Draw(img)
            if favorite:
                d.polygon(star_polygon(sx + sw - 34, sy + 32, 13), fill=FAVORITE_STAR, outline=(60, 30, 0, 255), width=2)
            else:
                d.polygon(star_polygon(sx + sw - 34, sy + 32, 13), outline=YELLOW, width=2)
            self.text(img, (sx + sw - 54, sy + 32), self.tr('favorite'), 18, YELLOW, 'rm')
            boxes.append(((sx + sw - 220, sy + 10, 210, 46), ('favorite',)))
        cx, cy, cw, ch = CAPTION_BOX
        img.alpha_composite(art.slice(CAPTION, cw, ch, (6, 6, 10, 12), 2), (cx, cy))
        self.text(img, (cx + 28, cy + ch // 2 - 2), 'Lv', 24, anchor='lm')
        if shop:
            # 尚未拥有：空进度条，中间叠原生锁（shop.obm 32×33，1.25 倍）
            g = art.gauge(0, cap, 300)
            gx, gy = cx + 66, cy + ch // 2 - g.height // 2
            img.alpha_composite(g, (gx, gy))
            lock = scaled(art.part(LOCK_ICON), 1.25)
            img.alpha_composite(lock, (gx + (g.width - lock.width) // 2, gy + (g.height - lock.height) // 2))
        else:
            g = art.gauge(level, cap, 250)
            img.alpha_composite(g, (cx + 66, cy + ch // 2 - g.height // 2))
            lx = cx + 330
            b.level_label(img, lx, cy + ch // 2 - 2, level, cap)
            if level >= cap:
                mx = scaled(art.part(MAX), 2)
                img.alpha_composite(mx, (lx + 18 * (len(str(level)) + len(str(cap))) + 34,
                                         cy + ch // 2 - mx.height // 2 - 1))
        ap = self.stats(level)['ap']
        self.text(img, (cx + cw - 140, cy + ch // 2 - 2), 'AP', 24, anchor='lm')
        b.number(img, cx + cw - 100, cy + ch // 2 - 13, ap, 0, 2, 18, lead=False)
        if len(b.all_items) > 1:
            arrow = scaled(art.part(ARROW), 3)
            mid = sy + sh // 2 - arrow.height // 2
            left = (sx - arrow.width - 14, mid, arrow.width, arrow.height)
            right = (sx + sw + 14, mid, arrow.width, arrow.height)
            img.alpha_composite(arrow.transpose(Image.Transpose.FLIP_LEFT_RIGHT), left[:2])
            img.alpha_composite(arrow, right[:2])
            boxes.append(((left[0] - 12, left[1] - 12, left[2] + 24, left[3] + 24), ('nav', -1)))
            boxes.append(((right[0] - 12, right[1] - 12, right[2] + 24, right[3] + 24), ('nav', 1)))
        return boxes

    def compose_panel(self, img):
        return {'lvup': self.compose_lvup, 'limit': self.compose_limit, 'confirm': self.compose_confirm,
                'buy': self.compose_buy, 'message': self.compose_message, 'status': self.compose_status,
                'action': self.compose_action}[self.panel](img)

    def popup(self, img, rect):
        x, y, w, h = rect
        img.alpha_composite(self.b.art.slice(POPUP, w, h, (6, 6, 6, 6), 2), (x, y))

    def unit_cell(self, img, x, y, flash=0.0):
        from PIL import Image
        art = self.b.art
        cell = art.cell()
        img.alpha_composite(cell, (x, y))
        icon = art.icon(self.entry()['uid'])
        if icon is not None:
            sprite, (ax, ay) = icon
            pos = (x + round(-ax * CARD_SCALE), y + round(-ay * CARD_SCALE))
            img.alpha_composite(sprite, pos)
            if flash > 0:
                # 原生强化效果：单位图像白色闪光并淡出（附录 A.1、A.10）
                white = Image.new('RGBA', sprite.size, (255, 255, 255, 0))
                white.putalpha(sprite.getchannel('A').point(lambda a: round(a * flash)))
                img.alpha_composite(white, pos)

    # —— LV UP ——
    def columns(self):
        """三列：(标签, 目标等级, 层级数, 状态)；状态为 ok / lock / na。"""
        info = self.info()
        level, cap = info['level'] or 1, info['cap']
        if level >= cap:
            state = 'lock' if info['next'] == 'open_stage' else 'na'
            return [(label, None, steps, state) for label, steps in (('+1', 1), ('+10', 10), ('MAX', 'max'))], info
        rows = []
        for label, steps in (('+1', 1), ('+10', 10), ('MAX', 'max')):
            target = cap if steps == 'max' else level + steps
            rows.append((label, target, steps, 'ok' if target <= cap else 'lock'))
        return rows, info

    def compose_lvup(self, img):
        from PIL import Image, ImageDraw
        b, art = self.b, self.b.art
        x, y, w, h = LV_PANEL
        self.popup(img, LV_PANEL)
        boxes = [((x, y, w, h), ('panel',))]
        lu = scaled(art.part(LEVEL_UP), 2)
        img.alpha_composite(lu, (x + (w - lu.width) // 2, y + 18))
        self.unit_cell(img, x + 40, y + 60, self.flash / FLASH_FRAMES)
        self.text(img, (x + 164, y + 78), self.entry()['name'], 26, anchor='lm', width=560)
        rows, info = self.columns()
        level, cap = info['level'] or 1, info['cap']
        if self.selected >= len(rows) or rows[self.selected][3] != 'ok':
            self.selected = next((i for i, r in enumerate(rows) if r[3] == 'ok'), 0)
        preview = rows[self.selected][1] if rows[self.selected][3] == 'ok' else None
        g = art.gauge(level, cap, 420)
        if preview:
            gp = art.gauge(preview, cap, 420).copy()
            inner = 420 - 20
            fw = (lambda lv: inner if lv >= cap else round(inner * lv / cap / 2) * 2)
            a, c = 10 + fw(level), 10 + fw(preview)
            gp.paste(g.crop((0, 0, a, g.height)), (0, 0))
            if c > a:
                gp.alpha_composite(Image.new('RGBA', (c - a, g.height - 12), (255, 255, 255, 120)), (a, 6))
            g = gp
        img.alpha_composite(g, (x + 164, y + 108))
        b.level_label(img, x + 604, y + 120, level, cap)
        if level >= cap:
            img.alpha_composite(scaled(art.part(MAX), 2), (x + 744, y + 108))
        colw = 250
        ox = x + (w - colw * 3) // 2
        red = scaled(art.part(RED), 2.25)
        gray = scaled(art.part(GRAYBTN), 2.25)
        lock = scaled(art.part(LOCK_ICON), 2.25)
        bw = red.width
        wallet = b.catalog().wallet()
        d = ImageDraw.Draw(img)
        costs = {}
        for i, (label, target, steps, state) in enumerate(rows):
            cx = ox + i * colw
            bx, by = cx + (colw - bw) // 2, y + 218
            if state == 'na':
                img.alpha_composite(gray, (bx, by))
                self.text(img, (bx + bw / 2, by + gray.height / 2), self.tr('na'), 24, (150, 150, 150, 255), 'mm',
                          width=bw - 16)
                boxes.append(((bx, by, bw, gray.height), ('lv_na', i)))
                continue
            img.alpha_composite(red, (bx, by))
            if state == 'lock':
                img.alpha_composite(lock, (bx + (bw - lock.width) // 2, by + red.height // 2 - lock.height // 2))
                boxes.append(((bx, by, bw, red.height), ('lv_lock', i)))
                continue
            self.text(img, (cx + colw // 2 - 34, y + 196), 'Lv', 22, anchor='rm')
            b.number(img, cx + colw // 2 - 26, y + 185, target, 0, 2, 18, lead=False)
            self.text(img, (bx + bw / 2, by + red.height / 2), label, 28, anchor='mm')
            cost = b.catalog().upgrade_cost(self.key, level, target)
            costs[i] = cost
            icon = scaled(art.part(MSP_ICON), 1.25)
            img.alpha_composite(icon, (cx + 40, y + 282))
            if cost > wallet['msp']:
                self.text(img, (cx + 40 + icon.width + 8, y + 282 + icon.height / 2), f'{cost:,}', 24, SHORT, 'lm')
            else:
                b.number(img, cx + 40 + icon.width + 8, y + 282 + (icon.height - 22) // 2, cost, 0, 2, 18, lead=False)
            if i == self.selected:
                d.rectangle([cx + 10, y + 176, cx + colw - 10, y + 318], outline=CYAN, width=2)
            boxes.append(((cx + 10, y + 176, colw - 20, 142), ('lv_col', i)))
            boxes.append(((bx, by, bw, red.height), ('lv_up', i)))
        self.costs = costs
        # 数值：可升级时为“当前 → 选中列”；加锁或 N/A 时只显示当前数值
        now = self.stats(level)
        after = self.stats(preview) if preview else None
        rows_stat = [('HP', 'hp', None), (self.tr('near'), 'near', 'damage'), (self.tr('normal'), 'normal', 'damage'),
                     (self.tr('special'), 'special', 'damage')]
        for i, (label, group, field) in enumerate(rows_stat):
            sx = x + 60 + (i % 2) * 400
            sy = y + 346 + (i // 2) * 34
            value = (lambda s: s['hp'] if group == 'hp' else s['attacks'][group]['damage'])
            present = group == 'hp' or now['attacks'][group]['present']
            self.text(img, (sx, sy), label, 22, GRAY, 'lm', width=170)
            self.text(img, (sx + 230, sy), str(value(now)) if present else '-', 22, WHITE, 'rm')
            if after is not None and present:
                self.text(img, (sx + 250, sy), '→', 22, GRAY, 'lm')
                self.text(img, (sx + 340, sy), str(value(after)), 22, GREEN, 'rm')
        return boxes

    # —— 解除 Lv 上限限制（D37）——
    def compose_limit(self, img):
        b, art = self.b, self.b.art
        x, y, w, h = LIMIT_PANEL
        self.popup(img, LIMIT_PANEL)
        boxes = [((x, y, w, h), ('panel',))]
        info = self.info()
        prices = info.get('prices') or {'medal': 0, 'msp': 0}
        self.text(img, (x + w / 2, y + 81), self.tr('limit_title'), 24, YELLOW, 'mm', 0, w - 60)
        self.text(img, (x + w / 2, y + 156), self.tr('limit_body'), 24, WHITE, 'mm', 0, w - 60)
        rows = ((x + 67, 'medal', 6), (x + 386, 'msp', 7))
        for bx, pay, icon in rows:
            k = 2
            sprite, ax, ay = art.conv_scaled(icon, k)
            iy = y + 250
            b.conv_paste(img, icon, bx + 4 + ax * k, iy - sprite.height // 2 + ay * k, k)
            cx = bx + 4 + sprite.width + 16
            b.conv_paste(img, 8, cx, iy - 11, k)
            b.number(img, cx + 24, iy - 11, prices[pay], 0, k, 18, lead=False)
            ok = scaled(art.part(DLG_RED), 2.25)
            rect = (bx, y + 288, ok.width, ok.height)
            img.alpha_composite(ok, rect[:2])
            self.button_label(img, rect, self.tr('ok'))
            boxes.append((rect, ('limit_pay', pay)))
        return boxes

    def compose_confirm(self, img):
        b, art = self.b, self.b.art
        x, y, w, h = CONFIRM_PANEL
        self.popup(img, CONFIRM_PANEL)
        boxes = [((x, y, w, h), ('panel',))]
        price = (self.info().get('prices') or {}).get('medal', 0)
        self.text(img, (x + w / 2, y + 60), self.tr('limit_title'), 24, YELLOW, 'mm', 0, w - 60)
        k = 2
        sprite, ax, ay = art.conv_scaled(6, k)
        digits = len(str(price)) * 18
        total = sprite.width + 16 + 24 + digits
        ix = x + (w - total) // 2
        iy = y + 130
        b.conv_paste(img, 6, ix + ax * k, iy - sprite.height // 2 + ay * k, k)
        b.conv_paste(img, 8, ix + sprite.width + 16, iy - 11, k)
        b.number(img, ix + sprite.width + 40, iy - 11, price, 0, k, 18, lead=False)
        self.text(img, (x + w / 2, y + 196), self.tr('limit_body'), 24, WHITE, 'mm', 0, w - 60)
        for bx, src, label, command in ((x + 69, DLG_BROWN, self.tr('cancel'), ('confirm_cancel',)),
                                        (x + 404, DLG_RED, self.tr('ok'), ('confirm_ok',))):
            button = scaled(art.part(src), 2.25)
            rect = (bx, y + 280, button.width, button.height)
            img.alpha_composite(button, rect[:2])
            self.button_label(img, rect, label)
            boxes.append((rect, command))
        return boxes

    # —— 购买确认（D32）——
    def buy_line(self):
        """原生 strShop 5 第二行（“[deco0]: Buy for %d?”，各语言均有译文），%d 为售价。"""
        raw = self.tr('buy_line')
        line = raw.split('\n')[-1].strip() if raw else ''
        if '%d' not in line:
            line = '[deco0]: %d'
        return line.replace('%d', str(self.price()))

    def compose_buy(self, img):
        art = self.b.art
        x, y, w, h = BUY_PANEL
        self.popup(img, BUY_PANEL)
        boxes = [((x, y, w, h), ('panel',))]
        self.text(img, (x + w / 2, y + 88), self.entry()['name'], 28, WHITE, 'mm', 0, w - 60)
        self.rich_text(img, x + w / 2, y + 146, self.buy_line(), 28, w - 60)
        # 按钮位置与原生购买弹窗相同（实测 CANCEL 371–573、OK 704–906、上沿 412）
        for bx, src, label, command in ((x + 68, DLG_BROWN, self.tr('cancel'), ('buy_cancel',)),
                                        (x + 401, DLG_RED, self.tr('ok'), ('buy_ok',))):
            button = scaled(art.part(src), 2.25)
            rect = (bx, y + 239, button.width, button.height)
            img.alpha_composite(button, rect[:2])
            self.button_label(img, rect, label)
            boxes.append((rect, command))
        return boxes

    def compose_message(self, img):
        art = self.b.art
        x, y, w, h = MESSAGE_PANEL
        self.popup(img, MESSAGE_PANEL)
        boxes = [((x, y, w, h), ('panel',))]
        self.rich_text(img, x + w / 2, y + 90, self.message or '', 26, w - 60)
        ok = scaled(art.part(DLG_RED), 2.25)
        rect = (x + (w - ok.width) // 2, y + 160, ok.width, ok.height)
        img.alpha_composite(ok, rect[:2])
        self.button_label(img, rect, self.tr('ok'))
        boxes.append((rect, ('message_ok',)))
        return boxes

    # —— STATUS ——
    def column(self, img, rect, sections):
        art = self.b.art
        x, y, w, h = rect
        img.alpha_composite(art.slice(SLATE, w, h, (10, 10, 10, 10), 2), (x, y))
        cy = y + 30
        for title, rows in sections:
            self.text(img, (x + w / 2, cy), f'[{title}]', 22, YELLOW, 'mm', 2, w - 30)
            cy += 36
            for label, value in rows:
                self.text(img, (x + 26, cy), label, 21, GRAY, 'lm', 2, w * 0.55)
                self.text(img, (x + w - 26, cy), value, 21, WHITE, 'rm', 2, w * 0.4)
                cy += 30
            cy += 10

    def compose_status(self, img):
        b, art = self.b, self.b.art
        x, y, w, h = BIG_PANEL
        self.popup(img, BIG_PANEL)
        boxes = [((x, y, w, h), ('panel',))]
        entry = self.entry()
        info = self.info()
        level = info['level'] or 1
        s = self.stats(level)
        logo = art.logo(entry['faction'])
        nx = x + 26
        if logo is not None:
            img.alpha_composite(logo, (nx, y + 16))
            nx += logo.width + 12
        self.text(img, (nx, y + 31), entry['name'], 28, anchor='lm', width=640)
        source = entry['source']
        label = SOURCE_TEXT[source][self.lang_index()] if source in SOURCE_TEXT else source
        self.text(img, (x + w - 28, y + 31), label, 20, GRAY, 'rm')
        threshold = s['knockback_threshold']
        # 商店中尚未拥有：数值为购买后的 Lv1
        lv = f'{level} / {info["cap"]}' if info['level'] is not None else '1'
        basic = [('LV', lv), ('AP', str(s['ap'])), ('HP', str(s['hp'])),
                 (self.tr('redeploy'), seconds(s['production_interval'])),
                 (self.tr('knockback_res'), '-' if threshold <= 0 else f'{threshold:g}'),
                 (self.tr('move'), f'{s["move_speed"]:.2f}'), (self.tr('reward'), f'{s["ap_reward"]} AP')]
        a = s['attacks']

        def target(group):
            return self.tr('single') if a[group].get('targets', 1) <= 1 else self.tr('spread')

        near = [(self.tr('damage'), str(a['near']['damage'])), (self.tr('force'), f'{a["near"]["knockback_force"]:.1f}'),
                (self.tr('range'), str(a['near']['range']) if a['near']['range'] > 0 else '-'),
                (self.tr('target'), target('near'))]
        normal = [(self.tr('damage'), str(a['normal']['damage'])),
                  (self.tr('force'), f'{a["normal"]["knockback_force"]:.1f}'),
                  (self.tr('range'), str(a['normal']['range']) if a['normal']['range'] > 0 else '-'),
                  (self.tr('interval'), seconds(a['normal']['wait'])),
                  (self.tr('target'), target('normal'))]
        special = [(self.tr('damage'), str(a['special']['damage'])),
                   (self.tr('force'), f'{a["special"]["knockback_force"]:.1f}'),
                   (self.tr('range'), str(a['special']['distance']) if a['special']['distance'] > 0 else '-'),
                   (self.tr('interval'), seconds(a['special'].get('interval', 0))),
                   (self.tr('cooldown_first'), seconds(a['special']['first_cooldown'])),
                   (self.tr('cooldown'), seconds(a['special']['wait'])), (self.tr('target'), target('special'))]
        middle = []
        if a['near']['present']:
            middle.append((self.tr('near'), near))
        if a['normal']['present']:
            middle.append((self.tr('normal'), normal))
        if not middle:
            middle.append((self.tr('normal'), [(self.tr('damage'), '-')]))
        cw = (w - 26 * 2 - 16 * 2) // 3
        top, ch = y + 60, h - 80
        self.column(img, (x + 26, top, cw, ch), [('STATUS', basic)])
        self.column(img, (x + 26 + cw + 16, top, cw, ch), middle)
        self.column(img, (x + 26 + (cw + 16) * 2, top, cw, ch),
                    [(self.tr('special'), special if a['special']['present'] else [(self.tr('damage'), '-')])])
        return boxes

    # —— ACTION ——
    def categories(self):
        a = self.stats(self.info()['level'] or 1)['attacks']
        return [name for name in ACTION_ORDER if name == 'neutral' or a[name]['present']]

    def compose_action(self, img):
        b, art = self.b, self.b.art
        x, y, w, h = BIG_PANEL
        self.popup(img, BIG_PANEL)
        boxes = [((x, y, w, h), ('panel',))]
        for i, name in enumerate(self.categories()):
            rect = (x + 26, y + 26 + i * 72, 260, 60)
            on = name == self.action
            img.alpha_composite(art.slice(TAB_ON if on else TAB_OFF, rect[2], rect[3], (8, 8, 8, 8), 2), rect[:2])
            self.text(img, (rect[0] + rect[2] / 2, rect[1] + rect[3] / 2), self.tr(name), 22,
                      DARK if on else WHITE, 'mm', 0 if on else 2, rect[2] - 24)
            boxes.append((rect, ('act', name)))
        by = y + h - 152
        bx, bw, bh = x + 26, w - 52, 132
        img.alpha_composite(art.slice(CAPTION, bw, bh, (6, 6, 10, 12), 2), (bx, by))
        text_w = bw - 60
        lines = self.description(text_w)
        if len(lines) > DESC_LINES:
            text_w -= SCROLL_W + 16                      # 为滚动条留出位置后重新折行
            lines = self.description(text_w)
        self.desc_count = len(lines)
        top = self.desc_scroll = max(0, min(self.desc_scroll, len(lines) - DESC_LINES))
        for i, line in enumerate(lines[top:top + DESC_LINES]):
            self.text(img, (bx + 30, by + 30 + i * DESC_LINE_H), line, 21, WHITE, 'lm', 2, text_w)
        self.desc_track = None
        if len(lines) > DESC_LINES:
            boxes += self.desc_scrollbar(img, bx, by, bw, top, len(lines))
        return boxes

    def desc_scrollbar(self, img, bx, by, bw, top, count):
        """说明条右侧的滚动条：深色轨道与金属色滑块（颜色取自说明条与选单位格边框）；拖动滑块或轨道、
        在文字上拖动均可滚动。说明条内框为 y+12 至 y+108（CAPTION 切片 2 倍）。"""
        from PIL import ImageDraw
        tx, ty, th = bx + bw - 44, by + 16, 88
        thumb = max(24, round(th * DESC_LINES / count))
        sy = ty + round((th - thumb) * top / (count - DESC_LINES))
        d = ImageDraw.Draw(img)
        d.rounded_rectangle([tx, ty, tx + SCROLL_W - 1, ty + th - 1], 6, fill=(30, 19, 12, 255), outline=(12, 7, 4, 255))
        d.rounded_rectangle([tx, sy, tx + SCROLL_W - 1, sy + thumb - 1], 6, fill=(172, 164, 144, 255),
                            outline=(46, 36, 26, 255), width=2)
        d.line([tx + 3, sy + 4, tx + 3, sy + thumb - 5], fill=(226, 220, 202, 255))
        d.line([tx + SCROLL_W - 4, sy + 4, tx + SCROLL_W - 4, sy + thumb - 5], fill=(108, 100, 86, 255))
        mid = sy + thumb // 2
        for k in (-4, 0, 4):
            d.line([tx + 4, mid + k, tx + SCROLL_W - 5, mid + k], fill=(92, 84, 70, 255))
        self.desc_track = (ty, th, thumb)
        return [((bx + 12, by + 12, tx - bx - 20, 96), ('desc_text',)),
                ((tx - 10, ty - 6, SCROLL_W + 20, th + 12), ('desc_bar',))]

    # —— 说明条滚动 ——
    def set_desc(self, value):
        value = max(0, min(int(value), self.desc_count - DESC_LINES))
        if value != self.desc_scroll:
            self.desc_scroll = value
            self.b.revision += 1

    def scroll_desc(self, delta):
        self.set_desc(self.desc_scroll + delta)

    def desc_press(self, kind, y):
        self.desc_drag = (kind, y, self.desc_scroll)
        if kind == 'desc_bar':
            self.desc_bar_to(y)

    def desc_move(self, y):
        if self.desc_drag is None:
            return
        kind, y0, start = self.desc_drag
        if kind == 'desc_bar':
            self.desc_bar_to(y)
        else:
            self.set_desc(start - round((y - y0) / DESC_LINE_H))

    def desc_release(self):
        self.desc_drag = None

    def desc_bar_to(self, y):
        """滑块中心跟随指针。"""
        if self.desc_track is None:
            return
        ty, th, thumb = self.desc_track
        span = max(1, th - thumb)
        self.set_desc(round((y - ty - thumb / 2) / span * (self.desc_count - DESC_LINES)))

    def description(self, width):
        """原生单位说明（GetMenuUnitInfo），按宽度折行。"""
        uid = self.entry()['uid']
        raw = self.b.catalog().text('_Z15GetMenuUnitInfo6UnitIDi', uid) or ''
        font = self.b.font(21)
        out = []
        for paragraph in raw.replace('\r', '').split('\n'):
            line = ''
            for ch in paragraph:
                if font.getlength(line + ch) > width and line:
                    cut = line.rfind(' ')
                    if cut > len(line) // 2 and ' ' in paragraph:
                        out.append(line[:cut])
                        line = line[cut + 1:] + ch
                    else:
                        out.append(line)
                        line = ch
                else:
                    line += ch
            out.append(line)
        return [line for line in out if line.strip()] or ['']

    # ---------- 动作演示（宿主界面之上） ----------
    def viewer_frame(self):
        if self.panel is None:
            x, y, w, h = FRAME
            return (x + 6, y + 6, w - 12, h - 12), FOOT
        if self.panel == 'action':
            x, y, w, h = BIG_PANEL
            frame = (x + 300, y + 8, w - 310, h - 152 - 16)
            return frame, (frame[0] + frame[2] // 2, frame[1] + frame[3] - 70)
        return None, None

    def draw_live(self):
        """每帧：推进并绘制动作演示（单位菜单画框或 ACTION 预览）；强化闪光期间重画面板。"""
        if self.flash > 0:
            self.flash -= 1
            self.b.revision += 1
        frame, foot = self.viewer_frame()
        if frame is None or self.viewer.uid is None:
            return
        try:
            if self.viewer.prepare():
                # 首次演示该单位或动作：测量图像范围（写入画面的测量区域），随后重画界面覆盖
                self.b.repaint()
            self.viewer.update()
            self.viewer.draw(foot, frame)
        except Exception as error:
            self.p.log('UNIT_MENU_VIEWER_ERROR', type(error).__name__, str(error))
            self.viewer.uid = None

    # ---------- 命令 ----------
    def set_panel(self, panel):
        self.panel = panel
        self.desc_drag = None
        self.b.revision += 1
        if panel is None:
            self.base = None

    def say(self, key):
        self.say_text(self.tr(key))

    def say_text(self, text, after=None):
        self.under = self.panel
        self.message = text
        self.after_message = after
        self.set_panel('message')

    def short_text(self, pay, need):
        """余额不足：原生 strShop 8（勋章）/ 9（MSP）的第一行（“You need "%d" more [deco0].”），不使用询问是否前往
        商店的第二行（用户决定 2026-10-12）。"""
        raw = self.tr('medal_need' if pay == 'medal' else 'msp_need')
        line = raw.split('\n')[0].strip() if raw else ''
        if '%d' not in line:
            return self.tr(pay + '_short')
        return line.replace('%d', str(max(0, int(need))))

    def dismiss(self):
        """关闭购买确认或其结果提示：卡片 BUY 打开的回到浏览大菜单，单位菜单中的回到单位菜单。"""
        if self.standalone:
            self.close()
            self.b.revision += 1
        else:
            self.set_panel(None)

    def message_done(self):
        after, self.after_message = self.after_message, None
        if after == 'close':
            self.close()
            self.b.revision += 1
        elif after == 'dismiss':
            self.dismiss()
        else:
            self.set_panel(self.under)

    def command(self, name, *args):
        b = self.b
        if name == 'open':
            panel = args[0]
            if panel == 'action':
                self.action = 'neutral'
                self.desc_scroll = 0
                self.select_action('neutral')
            self.set_panel(panel)
            return
        if name == 'nav':
            items = [e['key'] for e in b.all_items]
            if self.key in items and len(items) > 1:
                self.key = items[(items.index(self.key) + args[0]) % len(items)]
                b.revision += 1
                self.show_unit()
            return
        if name == 'favorite':
            b.toggle_favorite(self.key)
            return
        if name == 'lv_col':
            self.selected = args[0]
            b.revision += 1
            return
        if name == 'lv_up':
            self.selected = args[0]
            self.upgrade(args[0])
            return
        if name == 'lv_lock':
            if self.info()['next'] == 'open_stage':
                self.set_panel('limit')
            else:
                play_se(self.p, SE_BEEP)
            return
        if name == 'lv_na':
            play_se(self.p, SE_BEEP)
            return
        if name == 'limit_pay':
            if args[0] == 'medal':
                self.set_panel('confirm')            # 原生：勋章付款先经 YesNo 确认（strCustomize 29/28）
            else:
                self.open_stage('msp')
            return
        if name == 'confirm_ok':
            self.open_stage('medal')
            return
        if name == 'confirm_cancel':
            self.set_panel('limit')
            return
        if name == 'message_ok':
            self.message_done()
            return
        if name == 'buy_ok':
            self.purchase()
            return
        if name == 'buy_cancel':
            self.dismiss()
            return
        if name == 'act':
            self.select_action(args[0])
            b.revision += 1
            return
        if name == 'close':
            self.back()

    def select_action(self, action):
        self.action = action
        try:
            self.viewer.play(self.entry()['uid'], action, self.entry()['key'])
        except Exception as error:
            self.p.log('UNIT_MENU_VIEWER_ERROR', type(error).__name__, str(error))
            self.viewer.uid = None

    def upgrade(self, column):
        rows, info = self.columns()
        label, target, steps, state = rows[column]
        if state != 'ok':
            return
        result = self.b.catalog().upgrade(self.key, steps)
        self.p.log('UNIT_MENU_UPGRADE', self.key, steps, result.get('ok'), result.get('reason'), result.get('level_after'),
                   result.get('cost'))
        if result['ok']:
            play_se(self.p, SE_UPGRADE)
            self.flash = FLASH_FRAMES
            self.after_change()
        elif result['reason'] == 'msp_short':
            play_se(self.p, SE_BEEP)
            self.say_text(self.short_text('msp', result.get('need', 0)))
        else:
            play_se(self.p, SE_BEEP)
        self.b.revision += 1

    def purchase(self):
        """购买（unit_catalog.purchase，原生 PopupResultMenuShopBuyYes 的顺序，附录 A.4）。结果提示关闭后：成功时回到
        浏览大菜单（单位已拥有，从商店列表消失，D30），失败时关闭购买确认。"""
        result = self.b.catalog().purchase(self.key)
        self.p.log('UNIT_MENU_PURCHASE', self.key, result.get('ok'), result.get('reason'), result.get('price'))
        if result['ok']:
            play_se(self.p, SE_THANKS)
            play_se(self.p, SE_BUY)
            self.b.data_changed()
            self.say_text(self.tr('thanks'), 'close')
            return
        play_se(self.p, SE_BEEP)
        reason = result['reason']
        if reason == 'medal_short':
            text = self.short_text('medal', result.get('need', 0))
        elif reason in ('owned', 'sold_out'):
            text = self.tr('capacity')
        else:
            text = self.tr('unavailable')
        self.say_text(text, 'dismiss')

    def open_stage(self, pay):
        result = self.b.catalog().open_stage(self.key, pay)
        self.p.log('UNIT_MENU_OPEN_STAGE', self.key, pay, result.get('ok'), result.get('reason'))
        if result['ok']:
            if pay == 'medal':
                play_se(self.p, SE_THANKS)
                play_se(self.p, SE_BUY)
            else:
                play_se(self.p, SE_UPGRADE)
            self.after_change()
            self.set_panel('lvup')
        else:
            play_se(self.p, SE_BEEP)
            if result['reason'] in ('medal_short', 'msp_short'):
                self.panel = 'limit'
                self.say_text(self.short_text(pay, result.get('need', 0)))
            else:
                self.set_panel('lvup')

    def after_change(self):
        """强化或开放阶段之后：重画底层（等级、进度条、货币），浏览大菜单的卡片随之更新。"""
        self.base = None
        self.b.data_changed()

    def back(self):
        """Esc / BACK：关闭面板（窗口回到上一层），否则回到浏览大菜单。"""
        if self.panel == 'message':
            self.message_done()
        elif self.panel == 'buy':
            self.dismiss()
        elif self.panel in ('limit',):
            self.set_panel('lvup')
        elif self.panel == 'confirm':
            self.set_panel('limit')
        elif self.panel is not None:
            if self.panel == 'action':
                self.select_action('neutral')
            self.set_panel(None)
        else:
            self.close()
            self.b.revision += 1
        return True

    def outside(self):
        """模态面板外点击：与原生弹窗相同，视为取消。"""
        self.back()
