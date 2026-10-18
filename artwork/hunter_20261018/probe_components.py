"""Hunter 素材表：按连通区域分帧的探查（研究用）。"""
from pathlib import Path
import numpy as np
from PIL import Image
from scipy import ndimage
SRC = Path(__file__).resolve().parent / 'source' / 'MS6_Hunter.png'
a = np.array(Image.open(SRC).convert('RGBA'))
fg = ~np.all(a[:, :, :3] == (86, 177, 222), axis=2)
ROWS = {'00': (2, 41), '02': (98, 152), '03': (160, 222), '04': (233, 280), '05': (295, 349), '06': (355, 411),
        '07': (421, 473), '08': (489, 532), '09': (546, 585), '10': (595, 647), '11': (657, 700), '12': (714, 779),
        '13': (793, 858), '28': (1342, 1370), '29': (1378, 1397)}
for name, (y0, y1) in ROWS.items():
    lab, n = ndimage.label(fg[y0:y1], structure=np.ones((3, 3)))
    objs = ndimage.find_objects(lab)
    sizes = ndimage.sum(np.ones_like(lab), lab, range(1, n + 1))
    big = [(o[1].start, o[1].stop, o[0].stop + y0, int(s)) for o, s in zip(objs, sizes) if s >= 60]
    big.sort()
    print(name, len(big), 'small', sum(1 for s in sizes if s < 60), ' '.join(f'{x0}-{x1}/b{b}' for x0, x1, b, s in big))
