"""LAB 战斗中菜单（T6）：宿主层自绘面板，打开期间暂停战斗。

GameMode 1 中原生暂停页不可用；打开菜单时置 BattleGameMaster+0x1c（暂停标记，战斗模拟随之停止，
原生不显示暂停界面），关闭时还原。面板以 trial_overlay.SurfaceOverlay 绘制（与 EventTrial 相同），
鼠标点击行或 ↑/↓ + Enter 选择，Esc 打开/关闭。
"""
import os
from pathlib import Path

PANEL_W, PANEL_H = 520, 470
ROW_H, ROW_TOP = 44, 70


class LabMenu:
    def __init__(self, lab):
        self.lab = lab
        self.open = False
        self.selected = 0
        self.paused_by_menu = False
        self.overlay = None
        self.font = self.small = None
        self.rect = None
        self.revision = 0

    # ---------- 行 ----------
    def rows(self):
        lab = self.lab
        on = lambda value: '开' if value else '关'
        return [
            ('完全控制（无冷却 · AP 无限）', on(lab.full_control), ('toggle', 'full_control')),
            ('我方 AI 自动出兵', on(lab.player_ai), ('toggle', 'player_ai')),
            ('我方自动释放绝招', on(lab.player_auto_special), ('toggle', 'player_auto_special')),
            ('敌方 AI 自动出兵', on(lab.enemy_ai), ('toggle', 'enemy_ai')),
            ('敌方自动释放绝招', on(lab.enemy_auto_special), ('toggle', 'enemy_auto_special')),
            ('重新开始', '', ('restart',)),
            ('退出 LAB（返回菜单）', '', ('exit',)),
            ('继续', '', ('close',)),
        ]

    # ---------- 打开与关闭 ----------
    def set_open(self, value):
        p = self.lab.p
        master = p.call('_ZN16BattleGameMaster11getInstanceEv')
        if value and not self.open:
            self.open = True
            self.selected = 0
            if master and not p.read(master + 0x1c, 1)[0]:
                p.write(master + 0x1c, b'\x01')
                self.paused_by_menu = True
        elif not value and self.open:
            self.open = False
            if self.paused_by_menu and master:
                p.write(master + 0x1c, b'\x00')
            self.paused_by_menu = False
        self.revision += 1

    # ---------- 输入 ----------
    def move(self, step):
        self.selected = (self.selected + step) % len(self.rows())
        self.revision += 1

    def activate(self, index=None):
        index = self.selected if index is None else index
        self.lab.menu_command(self.rows()[index][2])
        self.revision += 1

    def touch(self, action, x, y):
        """返回 True 表示触点已由菜单处理（菜单打开期间一律拦截）。"""
        if not self.open:
            return False
        if action == 3 and self.rect:
            left, top = self.rect[:2]
            for index in range(len(self.rows())):
                y0 = top + ROW_TOP + index * ROW_H
                if left + 20 <= x < left + PANEL_W - 20 and y0 <= y < y0 + ROW_H - 4:
                    self.selected = index
                    self.activate(index)
                    break
        return True

    # ---------- 绘制 ----------
    def draw(self):
        if not self.open:
            return
        from PIL import Image, ImageDraw, ImageFont
        graphics = self.lab.p.graphics
        if self.overlay is None:
            from trial_overlay import SurfaceOverlay
            self.overlay = SurfaceOverlay(graphics)
            fonts = Path(os.environ['SystemRoot']) / 'Fonts'
            font = next((fonts / n for n in ('msyh.ttc', 'msjh.ttc', 'msgothic.ttc') if (fonts / n).is_file()), None)
            self.font = ImageFont.truetype(str(font), 22)
            self.small = ImageFont.truetype(str(font), 16)
        rows = self.rows()
        key = ('lab_menu', self.revision, tuple(r[1] for r in rows), self.selected)
        width, height = graphics.logical_size
        self.rect = ((width - PANEL_W) // 2, (height - PANEL_H) // 2, PANEL_W, PANEL_H)
        image = None
        if self.overlay.cached != key:
            image = Image.new('RGBA', (PANEL_W, PANEL_H), (0, 0, 0, 0))
            draw = ImageDraw.Draw(image)
            draw.rounded_rectangle((0, 0, PANEL_W - 1, PANEL_H - 1), 14, fill=(14, 20, 24, 236),
                                   outline=(200, 170, 90, 255), width=3)
            draw.text((PANEL_W // 2, 34), 'LAB · 战斗菜单（战斗已暂停）', font=self.font, anchor='mm',
                      fill=(240, 220, 150, 255))
            for index, (label, state, _) in enumerate(rows):
                y0 = ROW_TOP + index * ROW_H
                if index == self.selected:
                    draw.rounded_rectangle((20, y0, PANEL_W - 21, y0 + ROW_H - 6), 8, fill=(60, 80, 70, 255))
                draw.text((40, y0 + (ROW_H - 6) // 2), label, font=self.font, anchor='lm', fill=(235, 235, 235, 255))
                if state:
                    color = (130, 255, 160, 255) if state == '开' else (255, 150, 120, 255)
                    draw.text((PANEL_W - 44, y0 + (ROW_H - 6) // 2), state, font=self.font, anchor='rm', fill=color)
            draw.text((PANEL_W // 2, PANEL_H - 18), '点击或 ↑/↓ + Enter 选择 · Esc 继续', font=self.small,
                      anchor='mm', fill=(170, 170, 170, 255))
        self.overlay.draw_image(image, key, self.rect)

    def close_resources(self):
        if self.overlay is not None:
            self.overlay.close()
            self.overlay = None
