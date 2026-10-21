"""部件定位（2026-10-20）：求部件帧在目标帧中的位置（素材表无损，按颜色逐像素比对）。

先按颜色投票（部件与目标中同色像素的位置差计票，只用两者中都不太常见的颜色），取票数最高的若干候选，
再逐个统计重合的同色像素，返回重合最多的偏移。偏移为“部件内容外框左上角相对目标内容外框左上角”的像素差。
"""
from pathlib import Path
import json

import numpy as np
from PIL import Image

HERE = Path(__file__).resolve().parent
FRAMES = HERE / 'frames'
DATA = json.loads((HERE / 'frames.json').read_text(encoding='utf-8'))


def keys(img):
    a = np.asarray(img.convert('RGBA')).astype(np.int64)
    k = (a[..., 0] << 16) | (a[..., 1] << 8) | a[..., 2]
    return np.where(a[..., 3] > 0, k, -1)


def load(name, i):
    return keys(Image.open(FRAMES / DATA[name][i]['file']))


def overlap(T, P, dx, dy):
    """P 放在 T 的 (dx, dy) 处时同色像素数与 P 的不透明像素数。"""
    H, W = T.shape
    h, w = P.shape
    x0, y0 = max(dx, 0), max(dy, 0)
    x1, y1 = min(dx + w, W), min(dy + h, H)
    m = P >= 0
    if x1 <= x0 or y1 <= y0:
        return 0, int(m.sum())
    t = T[y0:y1, x0:x1]
    p = P[y0 - dy:y1 - dy, x0 - dx:x1 - dx]
    return int(((t == p) & (p >= 0)).sum()), int(m.sum())


def find(T, P, top=12, max_color_px=4000):
    """返回 (dx, dy, 重合比例)；比例以 P 的不透明像素计。"""
    H, W = T.shape
    h, w = P.shape
    tv, tc = np.unique(T[T >= 0], return_counts=True)
    pv, pc = np.unique(P[P >= 0], return_counts=True)
    tcount = dict(zip(tv.tolist(), tc.tolist()))
    votes = np.zeros((H + h, W + w), np.int32)        # 偏移 (dx, dy) 存在 [dy + h, dx + w]
    for color, n in zip(pv.tolist(), pc.tolist()):
        m = tcount.get(color, 0)
        if not m or n * m > max_color_px * 60:
            continue
        py, px = np.nonzero(P == color)
        ty, tx = np.nonzero(T == color)
        dy = (ty[None, :] - py[:, None]).ravel() + h
        dx = (tx[None, :] - px[:, None]).ravel() + w
        np.add.at(votes, (dy, dx), 1)
    flat = np.argsort(votes.ravel())[::-1][:top]
    best = None
    for f in flat:
        dy, dx = divmod(int(f), W + w)
        dy -= h
        dx -= w
        s, n = overlap(T, P, dx, dy)
        if best is None or s > best[0]:
            best = (s, dx, dy, n)
    return best[1], best[2], round(best[0] / best[3], 4)


def find_frames(target, ti, part, pi):
    """部件帧在目标帧中的位置，换算为目标格子坐标（内容外框左上角相对格子左上角）。"""
    dx, dy, ratio = find(load(target, ti), load(part, pi))
    tb, tc = DATA[target][ti]['box'], DATA[target][ti]['cell']
    return dx + tb[0] - tc[0], dy + tb[1] - tc[1], ratio
