"""预览工具：把某个动作槽在指定 tick 的帧按整数倍放大并排（核对部件对齐）。"""
import sys
from PIL import Image, ImageDraw
sys.path.insert(0, str(__import__('pathlib').Path(__file__).resolve().parent))
import build_iron_sentinel as B


def frame_at(sheet, slot, tick):
    t = 0
    cur = None
    for cmd in sheet.scripts[slot]:
        if cmd['opcode'] == 0:
            cur = cmd['values'][0]
        if cmd['opcode'] == 1:
            if t + cmd['values'][0] > tick:
                return cur
            t += cmd['values'][0]
    return cur


def main(out, slot, ticks, box=(-260, -330, 260, 20), scale=2, cols=3):
    sheet = B.build()
    x0, y0, x1, y1 = box
    W, H = (x1 - x0) * scale, (y1 - y0) * scale
    rows = (len(ticks) + cols - 1) // cols
    canvas = Image.new('RGB', (W * cols, H * rows), (20, 20, 20))
    for n, t in enumerate(ticks):
        key = frame_at(sheet, slot, t)
        im = Image.new('RGBA', (x1 - x0, y1 - y0), (52, 56, 66, 255))
        if isinstance(key, tuple):
            for r in key:
                tid, ax, ay = sheet.rects[r]
                tile, _ = sheet.tiles[tid]
                im.alpha_composite(tile, (-x0 - ax, -y0 - ay)) if True else None
        d = ImageDraw.Draw(im)
        d.line([(0, -y0), (x1 - x0, -y0)], fill=(80, 200, 255, 120))
        d.text((3, 3), f'{slot}:{t}', fill=(255, 255, 0))
        canvas.paste(im.convert('RGB').resize((W, H), Image.NEAREST), ((n % cols) * W, (n // cols) * H))
    canvas.save(out)


if __name__ == '__main__':
    slot = int(sys.argv[2])
    ticks = [int(v) for v in sys.argv[3].split(',')]
    box = tuple(int(v) for v in sys.argv[4].split(',')) if len(sys.argv) > 4 else (-260, -330, 260, 20)
    scale = int(sys.argv[5]) if len(sys.argv) > 5 else 2
    cols = int(sys.argv[6]) if len(sys.argv) > 6 else 3
    main(sys.argv[1], slot, ticks, box, scale, cols)
