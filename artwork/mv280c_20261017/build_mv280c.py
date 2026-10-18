"""MV-280C（s1xlv.mv280c）资源与单位文件生成（2026-10-17）。

以原版 MV-280C VER.F（UnitID 377）的精灵描述符、动作脚本与音效为基础，只替换三张图集中的两张：
- 车体图集 future_jeep_out.obm → mv280c_out.obm：只改调色板。车体页共 15 个调色板索引，按《合金弹头6》MV-280C 素材表
  IDLE 第 1 格与 VER.F 待机第 1 帧（车体页矩形 0）逐像素对应（不透明区域完全一致）求出每个索引的颜色。
- 子弹与枪口火光图集 bullet_mv-280c_out.obm → mv280c_bullet_out.obm：
  · 火光矩形 51–54 与素材表 FIRING 行 4 格逐像素同形，按素材表的橙红黄配色等位替换；
  · 子弹矩形 55、56 改为加特林机枪兵（UnitID 48，gatling_out.obm 矩形 100、101）子弹的像素与颜色
    （同为 8×8、锚点 (4,4)，不透明区域相同），子弹另分调色板索引（原子弹索引与火光共用）。
- 爆炸图集 geep_2_out.obm 不变，单位文件直接引用原版资源。
- 头像：VER.F 头像（unit_icon_02 的 (235,141,46,46)，锚点 (-5,1)）按车体同一配色换色，写入社区合并图集
  community_content/unit_icon_02.obm 的空位 (1430,768)。
素材表颜色为 5 位色左移 3 位（c<<3）；游戏调色板为 (c<<3)|(c>>2)，写入时换算（同一颜色在两种展开下数值不同）。
矩形坐标取自 libAppMain.so 1.46.0 的 VER.F 精灵描述符；对应关系在运行时逐像素复核，不一致即中止。

运行：windows_runtime/python.exe artwork/mv280c_20261017/build_mv280c.py（输出写入 community_content/ 与本目录 out/）。
"""
from collections import Counter, defaultdict
from pathlib import Path
import hashlib
import json
import os
import struct
import sys

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[1]
RUNTIME = Path(sys.executable).resolve().parent
for _name in ('.', 'native', 'angle', 'DLLs'):
    if os.name == 'nt' and (RUNTIME / _name).is_dir():
        os.add_dll_directory(str(RUNTIME / _name))
from PIL import Image  # noqa: E402

ASSETS = REPO / 'game_data/assets/com.snkplaymore.android003'
CONTENT = REPO / 'community_content'
OUT = HERE / 'out'
SHEET = HERE / 'source' / 'MS6_MV-280C.png'   # The Spriters Resource，Division 6（A Japanese Soldier）整理

KEY = 's1xlv.mv280c'
BODY, BULLET, EXPLOSION, ICON_ATLAS = 'mv280c_out.obm', 'mv280c_bullet_out.obm', 'geep_2_out.obm', 'unit_icon_02.obm'
SHEET_BG = {(16, 216, 128, 255), (0, 255, 163, 255)}
IDLE = ((0, 0, 70, 46), (10, 33))                       # 车体页矩形 0 ↔ 素材表 IDLE 第 1 格中的位置
FLASH = [((0, 0, 30, 24), (21, 494)), ((30, 0, 34, 14), (58, 496)),
         ((0, 24, 37, 27), (103, 492)), ((37, 14, 38, 16), (145, 497))]   # 子弹页矩形 51–54 ↔ FIRING 行 4 格
BULLETS = [((0, 51), (184, 86)), ((8, 51), (184, 95))]  # 子弹页矩形 55、56 ↔ gatling_out.obm 矩形 100、101
BULLET_SIZE = 8
VERF_ICON, ICON_AT, ICON_ANCHOR = (235, 141, 46, 46), (1430, 768), [-5, 1]

LOCALIZATION = {
    'EN': ('MV-280C', 'STAND. ATK : Machine gun     SPEC. ATK : Machine gun burst\n'
                      "A 4WD machine gun vehicle used by the Morden's Army.\n"
                      'The original model of the MV-280C VER.F. Its visibility is bad.'),
    'JP': ('MV-280C', '通常攻撃：マシンガン   特殊攻撃：マシンガン連射\nモーデン軍の機銃搭載４輪駆動車。\n'
                      '未来MV-280Cの原型で、やはり視界が悪い。'),
    'KR': ('MV-280C', '일반 공격: 머신건      특수 공격: 머신건 연사\n모덴군의 기관총 탑재 사륜구동 차량.\n'
                      '미래 MV-280C의 원형으로, 역시 시야가 좋지 않다.'),
    'ES': ('MV-280C', 'ATQ. ESTÁND.: Ametralladora ATQ. ESPEC.: Explosión ametralladora\n'
                      'Vehículo 4x4 con ametralladora de la Armada de Morden.\n'
                      'Modelo original del VER.F MV-280C. Tiene mala visibilidad.'),
    'PT': ('MV-280C', 'ATQ. PADR.: Metralhadora     ATQ. ESPEC.: Rajada Metralhadora\n'
                      'Veículo 4x4 com metralhadora do Exército de Morden.\n'
                      'Modelo original do MV-280C VER.F. Sua visibilidade é ruim.'),
    'RU': ('Эм-Ви-280Си', 'СТАНД. АТАК: Пулемет СПЕЦ. АТАК: Пулеметная очередь\n'
                          'Полноприводная машина Армии Мордена с пулеметом.\n'
                          'Прототип Эм-Ви-280Си ВЕР.Эф. Видимость плохая.'),
    'FR': ('MV-280C', 'ATT. STAND :  Mitrailleuse    ATT. SPÉ : Salve de mitrailleuse\n'
                      "Véhicule 4x4 armé d'une mitrailleuse de l'armée de Morden.\n"
                      "Modèle d'origine du MV-280C du futur. Mauvaise visibilité."),
    'DE': ('MV-280C', 'STAND. ATK : Maschinengewehr   SPEC. ATK : MG-Salve\n'
                      'Ein Allradfahrzeug der Morden-Armee mit Maschinengewehr.\n'
                      'Urmodell des MV-280C VER.F. Die Sicht ist schlecht.'),
    'IT': ('MV-280C', 'ATC STAND.: Mitragliatrice  ATC SPEC.: Raffica di mitragliatrice\n'
                      "Veicolo 4x4 con mitragliatrice dell'Armata di Morden.\n"
                      'Modello originale del MV-280C VER.F. Ha una pessima visuale.'),
    'ZT': ('MV-280C', '普通攻擊：機關槍     特殊攻擊：機關槍連射\n莫丁軍配備機關槍的４輪驅動車。\n未來MV-280C的原型，視野一樣差。'),
    'ZS': ('MV-280C', '普通攻击：机关枪     特殊攻击：机关枪连射\n莫丁军配备机关枪的４轮驱动车。\n未来MV-280C的原型，视野一样差。'),
}

# 用户设定（2026-10-17）：AP 90；再出击同原版重装 B 型（UnitID 117）；生命为 VER.F 的 1/3，击退门槛随生命；
# 移速与攻击方式同 VER.F；子弹伤害为 VER.F 的一半；勋章 120；强化费用基数 320；开局即可购买。
UNIT = {
    'key': KEY,
    'base_id': 377,
    'faction': 1,
    'identity': 'Rebel Army',
    'shop_price': 120,
    # 2026-10-17 用户决定开局即可购买（原为引用 MenuShopID 9，即世界 1 最终区域通关时授予的上架位；种子生成的
    # 全解锁存档只写入通关记录、未经原生结算，没有该位，单位因此被锁）。
    'available_from_start': True,
    'ap': 90,
    'upgrade_cost_base': 320,           # 同原版重装 B 型（数据行 +0x354）
    'hp_multiplier': [1, 3],
    'knockback_threshold_multiplier': [1, 3],
    'special_damage_multiplier': [1, 1],
    'damage_multiplier': [1, 2],
    'move_speed_multiplier': [1, 1],
    'production_reference_id': 117,
    'production_interval_multiplier': [1, 1],
    'attack_range_multiplier': [1, 1],
    'knockback_distance_multiplier': [1, 1],
    'ballistic_range_multiplier': [1, 1],
    # 特殊攻击每发的命中目标数（状态词 31）：VER.F 为 999（穿透），用户要求不穿透，与普通攻击（状态词 24）同为 1。
    # 发数由动作脚本决定，沿用 VER.F：普通攻击槽 9 发射 6 发、特殊攻击槽 10 发射 18 发。
    'status_word_values': {'31': 1},
    'textures': [BODY, BULLET, EXPLOSION],
    'icon': {'page': 1, 'rect': [*ICON_AT, VERF_ICON[2], VERF_ICON[3]], 'anchor': ICON_ANCHOR},
    'animations': {},
    'localization': {lang: {'name': name, 'description': text} for lang, (name, text) in LOCALIZATION.items()},
}


def expand(v):
    """素材表的 c<<3 展开为游戏调色板的 (c<<3)|(c>>2)。"""
    return v | (v >> 5)


def read_indexed(raw):
    """8 位索引 OI 图集：类型 1 为 RGBA8888 调色板，类型 4 为 RGBA5551 调色板（5 位色按 (c<<3)|(c>>2) 展开）。"""
    assert raw[:2] == b'OI' and raw[3] == 8 and raw[2] in (1, 4), 'expected an 8-bit indexed OI atlas'
    w, h = struct.unpack_from('<HH', raw, 4)
    size = 1024 if raw[2] == 1 else 512
    assert len(raw) == 8 + size + w * h
    if raw[2] == 1:
        palette = [tuple(raw[8 + i * 4:12 + i * 4]) for i in range(256)]
    else:
        five = lambda c: (c << 3) | (c >> 2)
        palette = [(five((v >> 11) & 31), five((v >> 6) & 31), five((v >> 1) & 31), (v & 1) * 255)
                   for v in struct.unpack_from('<256H', raw, 8)]
    return w, h, palette, bytearray(raw[8 + size:])


def write_indexed(w, h, palette, body):
    return b'OI\x01\x08' + struct.pack('<HH', w, h) + b''.join(bytes(c) for c in palette) + bytes(body)


def read_rgba32(raw):
    assert raw[:4] == b'OI\x01\x20', 'expected a 32-bit OI atlas'
    w, h = struct.unpack_from('<HH', raw, 4)
    assert len(raw) == 8 + w * h * 4
    return w, h, bytearray(raw[8:])


def vote(page, sheet, rect, at):
    """逐像素比较图集矩形与素材表位置：返回（不透明区域不一致的像素数，索引 → 素材表颜色计数）。"""
    w, _, palette, body = page
    (x0, y0, rw, rh), (sx, sy) = rect, at
    mismatch, votes = 0, defaultdict(Counter)
    for j in range(rh):
        for i in range(rw):
            index = body[(y0 + j) * w + x0 + i]
            colour = sheet[sx + i, sy + j]
            if (palette[index][3] != 0) != (colour not in SHEET_BG):
                mismatch += 1
            elif palette[index][3]:
                votes[index][colour[:3]] += 1
    return mismatch, votes


def recolour(palette, votes, exact):
    new = list(palette)
    mapping = {}
    for index, counts in sorted(votes.items()):
        rgb, n = counts.most_common(1)[0]
        assert (len(counts) == 1) if exact else n * 20 >= sum(counts.values()) * 19, (index, counts)
        new[index] = (*(expand(v) for v in rgb), palette[index][3])
        mapping[palette[index][:3]] = new[index][:3]
    return new, mapping


def body_atlas(sheet, report):
    page = read_indexed((ASSETS / 'future_jeep_out.obm').read_bytes())
    w, h, palette, body = page
    mismatch, votes = vote(page, sheet, *IDLE)
    assert mismatch == 0, mismatch
    used = {i for i in body if palette[i][3]}
    assert used == set(votes), (used, set(votes))
    new, mapping = recolour(palette, votes, exact=True)
    report['body'] = {'indices': len(used), 'idle_frame_mismatch': mismatch,
                      'palette': {str(i): [list(palette[i][:3]), list(new[i][:3])] for i in sorted(used)}}
    return write_indexed(w, h, new, body), mapping, (w, h, new, body)


def bullet_atlas(sheet, report):
    page = read_indexed((ASSETS / 'bullet_mv-280c_out.obm').read_bytes())
    w, h, palette, body = page
    votes, mismatches = defaultdict(Counter), []
    for rect, at in FLASH:
        mismatch, part = vote(page, sheet, rect, at)
        assert mismatch <= 1, (rect, mismatch)
        mismatches.append(mismatch)
        for index, counts in part.items():
            votes[index].update(counts)
    new, _ = recolour(palette, votes, exact=False)
    gatling = read_indexed((ASSETS / 'gatling_out.obm').read_bytes())
    gw, _, gpalette, gbody = gatling
    used = {i for i in body if palette[i][3]}
    free = [i for i in range(255, 0, -1) if i not in used]
    slots = {}
    for (bx, by), (gx, gy) in BULLETS:
        for j in range(BULLET_SIZE):
            for i in range(BULLET_SIZE):
                pos = (by + j) * w + bx + i
                colour = gpalette[gbody[(gy + j) * gw + gx + i]]
                assert (palette[body[pos]][3] != 0) == (colour[3] != 0), ((bx, by), i, j)
                if colour[3]:
                    if colour not in slots:
                        slots[colour] = free.pop(0)
                        new[slots[colour]] = colour
                    body[pos] = slots[colour]
    for (x0, y0, rw, rh), _ in FLASH + [((bx, by, BULLET_SIZE, BULLET_SIZE), None) for (bx, by), _ in BULLETS]:
        for j in range(rh):
            for i in range(rw):
                r, g, b, a = new[body[(y0 + j) * w + x0 + i]]
                assert not a or not (b > r + 16 and b > g), 'blue pixel left at %d,%d' % (x0 + i, y0 + j)
    report['bullet'] = {'flash_mismatch': mismatches,
                        'flash_palette': {str(i): [list(palette[i][:3]), list(new[i][:3])] for i in sorted(votes)},
                        'bullet_slots': {str(v): list(k) for k, v in slots.items()}}
    return write_indexed(w, h, new, body), (w, h, new, body)


def icon_atlas(mapping, report):
    raw = (CONTENT / ICON_ATLAS).read_bytes()
    w, h, pixels = read_rgba32(raw)
    x0, y0, iw, ih = VERF_ICON
    tx, ty = ICON_AT
    unmatched = Counter()
    for j in range(ih):
        for i in range(iw):
            src = (y0 + j) * w + x0 + i
            dst = (ty + j) * w + tx + i
            r, g, b, a = pixels[src * 4:src * 4 + 4]
            if a and (r, g, b) not in mapping:
                unmatched[(r, g, b)] += 1
            rgb = mapping.get((r, g, b), (r, g, b)) if a else (0, 0, 0)
            pixels[dst * 4:dst * 4 + 4] = bytes((*rgb, a))
    assert not unmatched, unmatched
    report['icon'] = {'source_rect': list(VERF_ICON), 'target': list(ICON_AT)}
    return raw[:8] + bytes(pixels)


def check_icon_slot():
    """目标区域必须为空（或为本脚本先前写入的结果），避免覆盖其他头像。"""
    w, _, pixels = read_rgba32((CONTENT / ICON_ATLAS).read_bytes())
    for unit_file in (CONTENT / 'units').glob('*.json'):
        unit = json.loads(unit_file.read_text(encoding='utf-8'))
        if unit['key'] == KEY or 'atlas' in unit['icon']:
            continue
        x, y, iw, ih = unit['icon']['rect']
        assert x + iw <= ICON_AT[0] or x >= ICON_AT[0] + VERF_ICON[2] or y + ih <= ICON_AT[1] or y >= ICON_AT[1] + VERF_ICON[3], unit['key']
    return w, pixels


def save_json(path, data):
    path.write_bytes((json.dumps(data, ensure_ascii=False, indent=2) + '\n').replace('\n', '\r\n').encode('utf-8'))


def preview(page, path, scale):
    w, h, palette, body = page
    image = Image.new('RGBA', (w, h))
    image.putdata([palette[i] for i in body])
    canvas = Image.new('RGBA', (w, h), (60, 60, 60, 255))
    canvas.alpha_composite(image)
    canvas.resize((w * scale, h * scale), Image.NEAREST).save(path)


def main():
    OUT.mkdir(exist_ok=True)
    sheet = Image.open(SHEET).convert('RGBA').load()
    report = {}
    check_icon_slot()
    body_raw, mapping, body_page = body_atlas(sheet, report)
    bullet_raw, bullet_page = bullet_atlas(sheet, report)
    icon_raw = icon_atlas(mapping, report)
    files = {BODY: body_raw, BULLET: bullet_raw, ICON_ATLAS: icon_raw}
    index = json.loads((CONTENT / 'content.json').read_text(encoding='utf-8'))
    if KEY not in index['unit_ids']:
        index['unit_ids'][KEY] = max(index['unit_ids'].values()) + 1
    for name, raw in files.items():
        (CONTENT / name).write_bytes(raw)
        if index['assets'].get(name, '') is not None:   # 已登记为 null 的资源（unit_icon_02.obm）保持不做摘要核对
            index['assets'][name] = hashlib.blake2b(raw, digest_size=32).hexdigest()
    save_json(CONTENT / 'units' / 'mv280c.json', UNIT)
    save_json(CONTENT / 'content.json', index)
    preview(body_page, OUT / 'mv280c_out.png', 2)
    preview(bullet_page, OUT / 'mv280c_bullet_out.png', 6)
    w, h, pixels = read_rgba32(icon_raw)
    icon = Image.frombytes('RGBA', (w, h), bytes(pixels)).crop((*ICON_AT, ICON_AT[0] + VERF_ICON[2], ICON_AT[1] + VERF_ICON[3]))
    icon.resize((icon.width * 8, icon.height * 8), Image.NEAREST).save(OUT / 'mv280c_icon_8x.png')
    report['unit_id'] = index['unit_ids'][KEY]
    (OUT / 'build_report.json').write_text(json.dumps(report, ensure_ascii=False, indent=2), encoding='utf-8')
    print(json.dumps({'unit_id': report['unit_id'], 'body_indices': report['body']['indices'],
                      'flash_mismatch': report['bullet']['flash_mismatch']}))


if __name__ == '__main__':
    main()
