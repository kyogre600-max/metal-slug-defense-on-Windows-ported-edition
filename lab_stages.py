"""LAB 地图目录：原生世界 / 区域 / 小关、对应的战斗 StageID 与原生缩略图。

数据全部在运行时读取原生表，与原生关卡选择、关卡信息窗及战斗使用同一来源：
- 区域表：GetAreaNum / GetAreaData（WorldType 0）以 0x902384 为基址，tbb 分派到 +0xcc，即每世界一行
  0x44 字节（+0 区域数，+4 起 16 个区域指针），世界 w 位于第 w+3 行。区域 +0 名称序号、+0xc 区域缩略图号、
  +0x12 小关数、+0x14 起 5 个小关指针；小关 +8 BGM、+0xc 缩略图图块号（GetStageBgmID / GetStageThumbnail）。
- 战斗 StageID：SC_BattleStart 的关卡模式按 (世界+1)×1000 + (区域+1)×10 + (小关+1) 计算，
  BattleInfo::getMissionInfo(StageID) 取 Mission 记录（+4 战场）。BattleScene::setupResourceAll 在 Mission BGM
  为 0 时按同一 StageID 拆回世界/区域/小关并调用 GetStageBgmID，地图与音乐随 StageID 一致。
- 联机模式（GameMode 1）的敌方为 BattleControllerNetPlayer，不读取 Mission 的敌军波次；捕虏与 UnitID 363
  只在游戏类型 1/7 生成（LAB 为 2），所以开放的关卡不带敌方默认配兵。
- 缩略图：LoadThumbnailImage 以区域缩略图号查 0x31d420 的 (ImageDataInfo 序号, 第二张/-1)，按语言取
  ImageDataInfo（GOT 0x93681c）得到文件名，分别载入菜单图像 0、1；GT_InfoWindowDraw 以 drawPict 的转换表 28
  绘制 GetStageThumbnail 的图块（转换项 x,y,w,h,锚点,标志,页；页选第一或第二张图）。
世界只开放 WorldType 0 中有区域的世界：0–2 为地图 1–3，9–11 为里地图 1–3（其余行为空）。
"""
import struct

G = 0x10000000
AREA_TABLE = G + 0x902384
THUMB_PAIRS = G + 0x31d420
THUMB_IMAGES_GOT = G + 0x93681c
PICT_OFFSETS_GOT, PICT_CONV_GOT, PICT_PATTERN_GOT = G + 0x93675c, G + 0x936750, G + 0x936758
THUMB_CONV = 28
AREA_NAMES = G + 0x946b8c          # strAreaNameTbl：11 种语言，每种 57 个名称
WORLDS = (0, 1, 2, 9, 10, 11)


def stage_id(world, area, stage):
    return (world + 1) * 1000 + (area + 1) * 10 + stage + 1


class StageCatalog:
    def __init__(self, p):
        self.p = p
        self.language = p.word(p.app_instance() + 0x3d64)   # 区域名与缩略图表按此语言读取
        self.worlds = None            # [(world, [stage 记录…])]
        self.by_id = {}

    def valid(self, address):
        return G <= address < 0x1ffff000

    def s32(self, value):
        return value - (1 << 32) if value & 0x80000000 else value

    def short(self, address):
        return struct.unpack('<h', self.p.read(address, 2))[0]

    def load(self):
        if self.worlds is not None:
            return self.worlds
        p = self.p
        language = self.language
        images = p.word(p.word(THUMB_IMAGES_GOT) + 4 * language)
        offsets = p.word(p.word(PICT_OFFSETS_GOT) + 4 * THUMB_CONV)
        conv = p.word(p.word(PICT_CONV_GOT) + 4 * THUMB_CONV)
        pattern = p.word(p.word(PICT_PATTERN_GOT) + 4 * THUMB_CONV)
        names = p.word(AREA_NAMES + 4 * language) if 0 <= language < 11 else 0
        info = p.call('_ZN10BattleInfo11getInstanceEv')

        def image_name(index):
            if index < 0:
                return None
            return p.read(p.word(images + 12 * index), 64).split(bytes(1))[0].decode('ascii', 'replace')

        def parts(pict):
            result = []
            address = pattern + 2 * self.short(offsets + 2 * pict)
            while len(result) < 8:
                index = self.short(address)
                if index == -1:
                    break
                x, y, w, h, ox, oy, _, page = struct.unpack('<8h', p.read(conv + 16 * index, 16))
                result.append((page, (x, y, w, h), (ox, oy)))
                address += 2
            return result

        worlds = []
        for world in WORLDS:
            row = AREA_TABLE + (world + 3) * 0x44
            count = self.s32(p.word(row))
            if not 0 < count <= 16:
                continue
            stages = []
            for area in range(count):
                record = p.word(row + 4 + 4 * area)
                if not self.valid(record):
                    continue
                name_index = self.s32(p.word(record))
                name = ''
                if self.valid(names) and 0 <= name_index < 57 and self.valid(p.word(names + 4 * name_index)):
                    name = p.read(p.word(names + 4 * name_index), 96).split(bytes(1))[0].decode('utf-8', 'replace')
                thumb = struct.unpack('<b', p.read(record + 0xc, 1))[0]
                files = (None, None)
                if thumb >= 0:
                    files = (image_name(self.s32(p.word(THUMB_PAIRS + 8 * thumb))),
                             image_name(self.s32(p.word(THUMB_PAIRS + 8 * thumb + 4))))
                for stage in range(max(0, min(self.short(record + 0x12), 5))):
                    data = p.word(record + 0x14 + 4 * stage)
                    sid = stage_id(world, area, stage)
                    if not self.valid(data) or not p.call('_ZN10BattleInfo14getMissionInfoEi', info, sid):
                        continue
                    pict = self.s32(p.word(data + 0xc))
                    entry = {'id': sid, 'world': world, 'area': area, 'stage': stage, 'area_name': name,
                             'bgm': self.s32(p.word(data + 8)), 'files': files,
                             'parts': parts(pict) if pict >= 0 else []}
                    stages.append(entry)
                    self.by_id[sid] = entry
            if stages:
                worlds.append((world, stages))
        self.worlds = worlds
        return worlds

    def locate(self, sid):
        """(世界序号, 小关序号)；未知 StageID 取第一个世界的第一关。"""
        for wi, (_, stages) in enumerate(self.load()):
            for si, entry in enumerate(stages):
                if entry['id'] == sid:
                    return wi, si
        return 0, 0

    def thumbnail(self, skin, entry):
        """按原生转换项合成缩略图（RGBA，原尺寸）；图块页 0/1 对应区域的第一、第二张缩略图。"""
        from PIL import Image
        pieces = []
        for page, (x, y, w, h), (ox, oy) in entry['parts']:
            name = entry['files'][page] if page < len(entry['files']) else None
            if not name or w <= 0 or h <= 0:
                continue
            pieces.append((skin.atlas(name).crop((x, y, x + w, y + h)), -ox, -oy))
        if not pieces:
            return None
        left = min(dx for _, dx, _ in pieces)
        top = min(dy for _, _, dy in pieces)
        width = max(dx + im.width for im, dx, _ in pieces) - left
        height = max(dy + im.height for im, _, dy in pieces) - top
        out = Image.new('RGBA', (width, height))
        for im, dx, dy in pieces:
            out.alpha_composite(im.convert('RGBA'), (dx - left, dy - top))
        return out
