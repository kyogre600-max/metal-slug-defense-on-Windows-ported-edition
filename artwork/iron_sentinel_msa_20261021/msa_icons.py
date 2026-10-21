"""IRON SENTINEL 与 IRON CAB 的头像改用 MSA 7.13.0 头像图集的原格（2026-10-21，AGENTS 第 188 节）。

MSA 的 unit_icon_02.obme（AES 6 + Brotli，2048×2048 RGBA，msa_decode.py images 解出）中两者的头像格为透明底的剪影：
IRON SENTINEL (295,644) 46×46、IRON CAB (480,647) 42×46。格的左列与底行各有 40 像素不透明，即选单位格内框（40×40）
位于格的左下，画面向上与向右越出内框 6 像素，与原生 46 高头像（ConvUnitIcon 中 18 项为 46×46、锚点 −5,1）相同。
此前两者为 1:1 裁出的 40×40（锚点 −5,−5），恰好填满内框，看起来被框住。

本脚本把两格原样复制到 source/（来源记录），写入 community_content/unit_icon_02.obm（先清除该单位原头像矩形，确认
不与其他单位的头像矩形重叠），并改写 IRON CAB 单位文件的 icon（IRON SENTINEL 的 icon 由 build_iron_sentinel_msa.py 写入）。
运行：E:\\anaconda3\\python.exe -I artwork/iron_sentinel_msa_20261021/msa_icons.py
"""
from pathlib import Path
import json
import struct

from PIL import Image

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[1]
CONTENT = REPO / 'community_content'
MSA_ICONS = Path(r'F:\egg\research\metal_slug_attack\decoded\unit_icons\unit_icon_02.obme.png')
ANCHOR = [-5, 1]
SHARED = {'s1xlv.iron_sentinel_form2': 's1xlv.iron_sentinel'}   # 内部单位与本体共用头像矩形
ICONS = {   # 稳定键：(MSA 头像格 x, y, 宽, 高), 合并图集中的位置, 来源副本
    's1xlv.iron_sentinel': ((295, 644, 46, 46), (1650, 768), 'msa_icon_iron_sentinel_295_644.png'),
    's1xlv.iron_cab': ((480, 647, 42, 46), (1600, 768), 'msa_icon_iron_cab_480_647.png'),
}


def save_json(path, data):
    path.write_bytes((json.dumps(data, ensure_ascii=False, indent=2) + '\n').replace('\n', '\r\n').encode('utf-8'))


def main():
    raw = bytearray((CONTENT / 'unit_icon_02.obm').read_bytes())
    assert raw[:4] == b'OI\x01\x20'
    w, h = struct.unpack_from('<HH', raw, 4)
    units = {json.loads(f.read_text(encoding='utf-8'))['key']: f for f in (CONTENT / 'units').glob('*.json')}
    rects = {k: json.loads(f.read_text(encoding='utf-8'))['icon'] for k, f in units.items()}
    source = Image.open(MSA_ICONS).convert('RGBA')
    report = {}
    for key, ((sx, sy, iw, ih), (ax, ay), name) in ICONS.items():
        for other, icon in rects.items():
            if other in ICONS or SHARED.get(other) in ICONS or 'atlas' in icon or icon['page'] != 1:
                continue
            x, y, ow, oh = icon['rect']
            assert x + ow <= ax or x >= ax + iw or y + oh <= ay or y >= ay + ih, (key, other)
        cell = source.crop((sx, sy, sx + iw, sy + ih))
        cell.save(HERE / 'source' / name)
        ox, oy, ow, oh = rects[key]['rect']
        for j in range(oh):
            for i in range(ow):
                at = 8 + ((oy + j) * w + ox + i) * 4
                raw[at:at + 4] = bytes(4)
        for j in range(ih):
            for i in range(iw):
                at = 8 + ((ay + j) * w + ax + i) * 4
                raw[at:at + 4] = bytes(cell.getpixel((i, j)))
        report[key] = {'msa_cell': [sx, sy, iw, ih], 'rect': [ax, ay, iw, ih], 'anchor': ANCHOR, 'previous': rects[key]['rect']}
    (CONTENT / 'unit_icon_02.obm').write_bytes(bytes(raw))
    cab = json.loads(units['s1xlv.iron_cab'].read_text(encoding='utf-8'))
    cab['icon'] = {'page': 1, 'rect': report['s1xlv.iron_cab']['rect'], 'anchor': ANCHOR}
    save_json(units['s1xlv.iron_cab'], cab)
    print(json.dumps(report, ensure_ascii=False))


if __name__ == '__main__':
    main()
