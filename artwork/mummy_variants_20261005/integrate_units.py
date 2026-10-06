"""生成木乃伊变种的原生资源与增量注册记录，保留既有单位及图标像素。"""
from pathlib import Path
import copy
import json
import os
import struct
import sys

ART = Path(__file__).resolve().parent
REPO = ART.parents[1]
RUNTIME = REPO / 'windows_runtime'
DLLS = [os.add_dll_directory(str(RUNTIME / name)) for name in ('.', 'native')]
sys.path[:0] = [str(RUNTIME / 'packages'), r'F:\egg\research\metal_slug_defense\content_work\kt21_feasibility_20261005\design_verification_r1\tools']
from PIL import Image
import elfmem as native
from obm_tool import parse

CONTENT = REPO / 'community_content'
NATIVE_ASSETS = REPO / 'game_data/assets/com.snkplaymore.android003'
DESCS = json.loads((ART / 'source/native/native_descriptors.json').read_text(encoding='utf-8'))
KEYS = ('s1xlv.white_mummy', 's1xlv.green_mummy', 's1xlv.mummy_generator_mk2', 's1xlv.mummy_generator_mk2_box')


def save_json(path, data):
    path.write_bytes((json.dumps(data, ensure_ascii=False, indent=2) + '\n').replace('\n', '\r\n').encode('utf-8'))


def indexed_obm(image):
    rgba = image.convert('RGBA')
    colors = list(dict.fromkeys(rgba.getdata()))
    assert len(colors) <= 256
    lut = {color: index for index, color in enumerate(colors)}
    raw = b'OI\x01\x08' + struct.pack('<HH', *image.size)
    return raw + b''.join(bytes(c) for c in colors).ljust(1024, b'\0') + bytes(lut[c] for c in rgba.getdata())


def command(opcode, *values):
    return {'opcode': opcode, 'values': list(values)}


def green_emission_anchor():
    # 普通喷气的逻辑对象位于单位原点；图像靠近口部的边缘由原生矩形锚点确定。
    gas_id=DESCS['Mummy']['scripts']['21']['timeline'][0]['rects'][0]
    bug_id=DESCS['BungeeMummy']['scripts']['31']['timeline'][0]['rects'][0]
    _,_,gw,gh,gax,gay,_,_=DESCS['Mummy']['rects'][gas_id]
    _,_,_,bh,_,bay,_,_=DESCS['BungeeMummy']['rects'][bug_id]
    return gw-gax, -gay+(gh-bh)//2+bay


def normal_attack(green):
    commands = copy.deepcopy(DESCS['Mummy']['scripts']['8']['commands'])
    result = []
    for cmd in commands:
        if cmd['opcode'] == 22:
            anchor=green_emission_anchor() if green else (-8,-32)
            result += [command(22, slot, 2 if green else 0, *anchor) for slot in (range(31, 36) if green else (22,))]
        else:
            result.append(cmd)
    return result


def special_attack(green):
    original = copy.deepcopy(DESCS['Mummy']['scripts']['10']['commands'])
    point = next(i for i, cmd in enumerate(original) if cmd['opcode'] == 22)
    prefix, suffix = original[:point], original[point + 1:]
    result = []
    for burst in range(3):
        result += copy.deepcopy(prefix)
        anchor=green_emission_anchor() if green else (-8,-32)
        result += [command(22, slot, 2 if green else 0, *anchor) for slot in (range(42, 47) if green else (22,))]
        if burst < 2:
            result += [command(23, 845)]
            if green:
                result += [command(0, 58), command(1, 1)]
            else:
                # 收嘴及双臂复位沿原生帧顺序压缩为11 tick，保持20 tick的发射间隔。
                for frame in range(58, 100, 4):
                    result += [command(0, frame), command(1, 1)]
        else:
            result += suffix
    return result


def green_descriptor():
    mummy, bugs = DESCS['Mummy'], DESCS['BungeeMummy']
    offset = len(mummy['rects'])
    frames = list(bugs['frames'])
    pos = 0
    while pos < len(frames):
        count = frames[pos]
        for index in range(pos + 1, pos + 1 + count):
            frames[index] += offset
        pos += count + 1
    rects = copy.deepcopy(bugs['rects'])
    for rect in rects:
        rect[7] = 2
        # 图集锚点表示从矩形边缘到原点的距离，水平镜像采用 width-anchor。
        rect[4] = rect[2]-rect[4]
        rect[6] ^= 1
    return {'rects': mummy['rects'] + rects, 'frames': mummy['frames'] + frames, 'script_count': 49,
            'hit_bounds': [[0, 0, 0, 0, 0], [-18, -46, 31, 46, 0], [-4, -18, 30, 36, 0], [-35, -151, 65, 199, 0]],
            'attack_bounds': [[0, 0, 0, 0, 0], [-3, -26, 31, 54, 7], [-4, -18, 14, 18, 7]]}


TEXTS = {
 'EN': ('WHITE MUMMY', 'GREEN MUMMY', 'Poison Bomb', 'Poison Bomb Combo', 'Scarab Bomb', 'Scarab Bomb Combo', 'A white variant of the Mummy. Attacks with poison bombs.', 'A green variant of the Mummy. Appears to be a special variant of the Hunged Mummy.'),
 'JP': ('白いミイラ', '緑のミイラ', '魔薬爆弾', '魔薬爆弾連撃', '虫爆弾', '虫爆弾連撃', 'ミイラの白色変種。魔薬爆弾で攻撃する。', 'ミイラの緑色変種。吊り下げミイラの特殊な変種と思われる。'),
 'KR': ('흰 미라', '초록 미라', '마약 폭탄', '마약 폭탄 연타', '벌레 폭탄', '벌레 폭탄 연타', '미라의 흰색 변종. 마약 폭탄으로 공격한다.', '미라의 초록색 변종. 매달린 미라의 특수한 변종으로 보인다.'),
 'ES': ('MOMIA BLANCA', 'MOMIA VERDE', 'Bomba de veneno', 'Ráfaga de veneno', 'Bomba escarabajo', 'Ráfaga de escarabajos', 'Variante blanca de la momia. Ataca con bombas de veneno.', 'Variante verde de la momia. Parece una variante especial de la momia colgante.'),
 'PT': ('MÚMIA BRANCA', 'MÚMIA VERDE', 'Bomba de veneno', 'Rajada de veneno', 'Bomba de escaravelhos', 'Rajada de escaravelhos', 'Variante branca da múmia. Ataca com bombas de veneno.', 'Variante verde da múmia. Parece uma variante especial da múmia suspensa.'),
 'RU': ('БЕЛАЯ МУМИЯ', 'ЗЕЛЁНАЯ МУМИЯ', 'Ядовитая бомба', 'Серия ядовитых бомб', 'Бомба со скарабеями', 'Серия бомб со скарабеями', 'Белая разновидность мумии. Атакует ядовитыми бомбами.', 'Зелёная разновидность мумии. Вероятно, особая разновидность висящей мумии.'),
 'FR': ('MOMIE BLANCHE', 'MOMIE VERTE', 'Bombe de poison', 'Salve de poison', 'Bombe de scarabées', 'Salve de scarabées', 'Variante blanche de la momie. Attaque avec des bombes de poison.', 'Variante verte de la momie. Semble être une variante spéciale de la momie suspendue.'),
 'DE': ('WEISSE MUMIE', 'GRÜNE MUMIE', 'Giftbombe', 'Giftbombenserie', 'Skarabäusbombe', 'Skarabäusbombenserie', 'Weiße Variante der Mumie. Greift mit Giftbomben an.', 'Grüne Variante der Mumie. Vermutlich eine besondere Variante der hängenden Mumie.'),
 'IT': ('MUMMIA BIANCA', 'MUMMIA VERDE', 'Bomba velenosa', 'Raffica velenosa', 'Bomba di scarabei', 'Raffica di scarabei', 'Variante bianca della mummia. Attacca con bombe velenose.', 'Variante verde della mummia. Sembra una variante speciale della mummia appesa.'),
 'ZT': ('白木乃伊', '綠木乃伊', '魔藥炸彈', '魔藥炸彈連擊', '蟲蟲炸彈', '蟲蟲炸彈連擊', '木乃伊的白色變種。使用魔藥炸彈進行攻擊。', '木乃伊的綠色變種。似乎是垂降木乃伊的特殊變體。'),
 'ZS': ('白木乃伊', '绿木乃伊', '魔药炸弹', '魔药炸弹连击', '虫虫炸弹', '虫虫炸弹连击', '木乃伊的白色变种。使用魔药炸弹进行攻击。', '木乃伊的绿色变种。似乎是垂降木乃伊的特殊变体。'),
}


def localizations(green=False, box=False):
    result = {}
    labels = {'EN': ('STAND. ATK : ', 'SPEC. ATK : '), 'ZT': ('普通攻擊：', '特殊攻擊：'), 'ZS': ('普通攻击：', '特殊攻击：'), 'JP': ('通常攻撃：', '特殊攻撃：'), 'KR': ('일반 공격: ', '특수 공격: ')}
    for code, values in TEXTS.items():
        normal, special = labels.get(code, labels['EN'])
        if box:
            name = native.string(native.word(native.SYMS['strMenuUnitName' + code][0] + 77 * 4))
            desc = native.string(native.word(native.SYMS['strMenuUnitInfo' + code][0] + 77 * 4))
            original = native.string(native.word(native.SYMS['strMenuUnitName' + code][0] + 61 * 4))
            if code == 'ZS':
                name, desc = '木乃伊召唤箱', '普通攻击：‐     特殊攻击：‐\n「白木乃伊」会从召唤箱里出现。'
            else:
                desc = desc.replace(original, values[0]).replace(original.title(), values[0].title())
                if code in ('DE',) and 'MUMMY' in desc:
                    desc = desc.replace('MUMMY', values[0])
            result[code] = {'name': name + ' MKII', 'description': desc}
        else:
            index = 1 if green else 0
            result[code] = {'name': values[index], 'description': normal + values[4 if green else 2] + '     ' + special + values[5 if green else 3] + '\n' + values[7 if green else 6]}
    return result


def main():
    registry = json.loads((CONTENT / 'registry.json').read_text(encoding='utf-8'))
    existing = [unit for unit in registry['units'] if unit['key'] not in KEYS]
    assert len(existing) == 15, '新增单位编号需与现行注册顺序共同核查。'
    files = {}
    for color in ('white', 'green'):
        files[color + '_mummy_out.obm'] = indexed_obm(Image.open(ART / f'sprites/{color}_mummy_atlas_0.png'))
    files['mummy_variant_effects.obm'] = indexed_obm(Image.open(ART / 'sprites/white_mummy_atlas_1.png'))
    files['mummy_variant_bugs.obm'] = (NATIVE_ASSETS / 'hungedmummy_out.obm').read_bytes()
    files['mummy_generator_mk2.obm'] = indexed_obm(Image.open(ART / 'sprites/mummy_generator_mk2_atlas.png'))
    files['mummy_generator_builder.obm'] = (NATIVE_ASSETS / 'donou.obm').read_bytes()
    icon_source = REPO / 'verification/mummy_variants_20261005/before/community_content/unit_icon_02.obm'
    icon = parse(icon_source.read_bytes()).convert('RGBA')
    icons = []
    palettes=json.loads((ART/'palette_maps.json').read_text(encoding='utf-8'))
    for i,color in enumerate(('white_mummy','green_mummy','mummy_generator_mk2')):
        # 原生图标独立于本体图集；保留其姿态、裁切、透明度、尺寸及显示偏移。
        reference=48 if i<2 else 49
        x,y,w,h,ax,ay,_,_=struct.unpack('<8h',native.read(native.SYMS['ConvUnitIcon'][0]+reference*16,16))
        tile=icon.crop((x,y,x+w,y+h))
        entries=palettes[color]+(palettes['white_mummy'] if i==2 else [])
        mapping={}
        for original in {p[:3] for p in tile.getdata() if p[3]}:
            # 图标与索引图集的 RGB5 展开采用不同舍入；逐色限定两级以内的编码差异。
            matches=[tuple(p['target']) for p in entries if max(abs(a-b) for a,b in zip(original,p['original']))<=2]
            assert len(set(matches))<=1,(color,original,matches)
            if matches:mapping[original]=matches[0]
        tile.putdata([mapping.get(p[:3],p[:3])+(p[3],) if p[3] else p for p in tile.getdata()])
        anchor=[ax,ay]
        assert tile.width <= 72 and tile.height <= 72
        ix, iy = 1110 + i * 80, 768
        assert icon.crop((ix,iy,ix+72,iy+72)).getbbox() is None, '新增图标区域含有既有像素。'
        icon.paste(tile, (ix,iy))
        icons.append({'page':1,'index':355+i,'rect':[ix,iy,w,h],'anchor':anchor})
    files['unit_icon_02.obm'] = b'OI\x01\x20' + struct.pack('<HH', *icon.size) + icon.tobytes()
    for name, raw in files.items():
        (CONTENT / name).write_bytes(raw)
        registry['assets'][name] = None
    save_json(CONTENT / 'green_mummy_descriptor.json', green_descriptor())
    units = []
    for index, base in enumerate((61,61,77,64)):
        unit = {'key':KEYS[index], 'id':1039+index, 'base_id':base, 'faction':4, 'identity':'Independent Army',
                'shop_price':(100,100,160,160)[index], 'available_from_start':False, 'shop_unlock_reference_id':80,
                'ap':(80,90,220,220)[index], 'hp_multiplier':([5,2],[7,4],[1,1],[20,9])[index],
                'knockback_threshold_multiplier':([5,2],[7,4],[1,1],[20,9])[index],
                'production_reference_id':51, 'production_interval_multiplier':([1,1],[9,10],[2,1],[2,1])[index],
                'special_damage_multiplier':[1,1], 'damage_multiplier':([1,2],[67,200],[1,1],[1,1])[index],
                'move_speed_multiplier':([19,20],[11,10],[1,1],[1,1])[index], 'attack_wait_multiplier':[1,1],
                'attack_range_multiplier':[1,1], 'knockback_distance_multiplier':[1,1], 'ballistic_range_multiplier':[1,1],
                'icon':copy.deepcopy(icons[min(index,2)]), 'animations':{}, 'localization':localizations(index==1,index>=2)}
        unit['icon']['index']=355+index
        if index<2:
            unit.update(textures=[('white' if index==0 else 'green')+'_mummy_out.obm','mummy_variant_effects.obm'],
                        normal_attack_range_from_projectile=True,
                        attack_range_categories={'normal':4 if index==0 else 3,'special':4},
                        animations={'8':normal_attack(index==1),'10':special_attack(index==1)},
                        attack_parameter_references={'normal':{'unit_id':61 if index==0 else 157,'group':'special'},'special':{'unit_id':61 if index==0 else 157,'group':'special'}},
                        normal_projectile_distance_multiplier=[6,5] if index==0 else [1,1],
                        special_projectile_distance_multiplier=[6,5] if index==0 else [2,1])
            if index==1:
                unit.update(sprite_descriptor='green_mummy_descriptor.json',shot_action_reference_id=157,recovery_animation=47)
                unit['textures'].append('mummy_variant_bugs.obm')
                for slot in range(23,42):
                    commands=copy.deepcopy(DESCS['BungeeMummy']['scripts'][str(slot)]['commands'])
                    for cmd in commands:
                        if cmd['opcode']==0 and cmd['values'][0]>=0:cmd['values'][0]+=len(DESCS['Mummy']['frames'])
                        # 地面与垂降木乃伊的图集朝向相反；虫群采用地面木乃伊的局部坐标。
                        if cmd['opcode']==7:
                            cmd['values'][0]*=-1
                            cmd['values'][2]*=-1
                        if cmd['opcode'] in (10,11,12):cmd['values'][2]*=-1
                    unit['animations'][str(slot)]=commands
                for slot in range(31,36):
                    commands=copy.deepcopy(unit['animations'][str(slot)])
                    for cmd in commands:
                        if cmd['opcode']==7:
                            cmd['values'][0]*=2
                            cmd['values'][2]*=2
                    unit['animations'][str(slot+11)]=commands
                # 虫群原生状态机使用槽 23..26；本体恢复及死亡效果采用独立槽。
                unit['animations']['47']=copy.deepcopy(DESCS['Mummy']['scripts']['26']['commands'])
                unit['animations']['48']=copy.deepcopy(DESCS['Mummy']['scripts']['24']['commands'])
                for slot in (13,14):
                    commands=copy.deepcopy(DESCS['Mummy']['scripts'][str(slot)]['commands'])
                    for cmd in commands:
                        if cmd['opcode'] in (10,11,12) and cmd['values'][0]==24:cmd['values'][0]=48
                    unit['animations'][str(slot)]=commands
        elif index==2:
            unit.update(textures=['mummy_generator_builder.obm'],child_unit_key=KEYS[3],preview_unit_key=KEYS[3],construction_time_multiplier=[1,1])
        else:
            unit.update(textures=['mummy_generator_mk2.obm'],menu_reference_id=77,internal_only=True,summoned_unit_key=KEYS[0],summon_interval_multiplier=[5,4],summon_interval_additional_multiplier=[3,1])
        units.append(unit)
    registry['units']=existing+units
    save_json(CONTENT / 'registry.json', registry)
    (REPO / 'src/community_content.py').write_bytes((REPO / 'community_content.py').read_bytes())
    print('已生成 3 个可选单位、1 个内部箱体、6 个独立 OBM 及新增图标。')


if __name__ == '__main__':
    main()
