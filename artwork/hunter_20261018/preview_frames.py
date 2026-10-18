"""frames.json 预览：每个动作一行，各帧按锚点放在同一原点（红色十字），3 倍放大（研究用）。"""
from pathlib import Path
import json, sys
from PIL import Image, ImageDraw
HERE = Path(__file__).resolve().parent
data = json.loads((HERE / 'frames.json').read_text(encoding='utf-8'))
names = sys.argv[1].split(',') if len(sys.argv) > 1 else list(data)
CW, CH, OX, OY, K = 90, 80, 50, 70, 3
rows = []
for name in names:
    fr = data[name]
    row = Image.new('RGBA', (CW * len(fr), CH), (60, 70, 80, 255))
    d = ImageDraw.Draw(row)
    for i, f in enumerate(fr):
        im = Image.open(HERE / 'frames' / f['file']).convert('RGBA')
        ox = i * CW + OX
        oy = OY if not name.startswith('dyn_fly') else 40
        row.alpha_composite(im, (ox - f['ax'], oy - f['ay']))
        d.line((ox - 3, oy, ox + 3, oy), fill=(255, 0, 0, 255)); d.line((ox, oy - 3, ox, oy + 3), fill=(255, 0, 0, 255))
        d.line((i * CW, 0, i * CW, CH), fill=(30, 30, 30, 255))
    rows.append((name, row))
W = max(r.width for _, r in rows); H = sum(r.height + 4 for _, r in rows)
out = Image.new('RGBA', (W, H), (20, 20, 20, 255)); y = 0
for _, r in rows:
    out.paste(r, (0, y)); y += r.height + 4
out = out.resize((out.width * K, out.height * K), Image.NEAREST)
out.save(HERE / 'out_preview.png'); print(out.size)
