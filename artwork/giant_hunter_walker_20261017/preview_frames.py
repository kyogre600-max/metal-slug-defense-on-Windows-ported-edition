"""切帧结果预览：每个动作一行，各帧按锚点放在同一位置（竖线为单位原点，横线为地面），2 倍最近邻。"""
from pathlib import Path
import json, os, sys
HERE = Path(__file__).resolve().parent
RUNTIME = Path(sys.executable).resolve().parent
for _n in ('.', 'native', 'angle', 'DLLs'):
    if os.name == 'nt' and (RUNTIME / _n).is_dir():
        os.add_dll_directory(str(RUNTIME / _n))
from PIL import Image, ImageDraw
data = json.loads((HERE / 'frames.json').read_text(encoding='utf-8'))
names = sys.argv[1].split(',') if len(sys.argv) > 1 else list(data)
CW, CH, AX, AY = 190, 170, 95, 150
rows = [n for n in names if n in data]
cols = max(len(data[n]) for n in rows)
sheet = Image.new('RGBA', (CW * cols, CH * len(rows)), (40, 44, 52, 255))
d = ImageDraw.Draw(sheet)
for r, name in enumerate(rows):
    for c, f in enumerate(data[name]):
        img = Image.open(HERE / 'frames' / f['file'])
        ox, oy = c * CW + AX - f['ax'], r * CH + AY - f['ay']
        sheet.alpha_composite(img, (ox, oy))
        d.line([(c * CW + AX, r * CH + 10), (c * CW + AX, r * CH + AY)], fill=(255, 80, 80, 160))
        d.line([(c * CW + 10, r * CH + AY), (c * CW + CW - 10, r * CH + AY)], fill=(80, 200, 255, 160))
out = HERE / 'out'
out.mkdir(exist_ok=True)
sheet = sheet.resize((sheet.width * 2 // 3, sheet.height * 2 // 3), Image.NEAREST)
sheet.save(out / ('preview_' + '_'.join(rows) + '.png'))
print(sheet.size)
