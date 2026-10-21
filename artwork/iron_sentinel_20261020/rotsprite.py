"""斜置素材的水平化（2026-10-20）：RotSprite 旋转，按全局坐标逐层进行。

MSA 素材按 MS6 第 2 关的 2:1 下坡绘制（履带着地线斜率 1/2，约 26.57°，右端较低），MSA 在运行时把单位图像转成水平。
本模块把素材坐标（第一形态整车帧 ff_walk_00 的格子坐标，记为 G）中的图层旋转到水平坐标 R：
  x' = x cosθ + y sinθ，y' = −x sinθ + y cosθ（y 向下，画面上为逆时针，右端抬起），θ = atan(1/2)。

RotSprite：图层先放大 8 倍（三次 2×；R4 起用 MMPX，R1–R3 为 Scale2x），R 中每个像素取其中心反算到 G 后在 8 倍图中最近的像素（不插值、不产生新颜色）。
所有图层使用同一映射（同一原点、同一像素网格），分别旋转后按整数偏移叠合即对齐；部件只在边缘 1 像素内与整帧旋转的结果可能不同。
"""
import math

import numpy as np

THETA = math.atan2(1, 2)
COS, SIN = math.cos(THETA), math.sin(THETA)


def scale2x(a):
    h, w = a.shape[:2]
    p = np.pad(a, ((1, 1), (1, 1), (0, 0)), mode='edge')
    e, b, d, f, hh = p[1:-1, 1:-1], p[:-2, 1:-1], p[1:-1, :-2], p[1:-1, 2:], p[2:, 1:-1]

    def eq(u, v):
        return np.all(u == v, axis=-1)
    c = ~eq(b, hh) & ~eq(d, f)
    o = np.empty((h * 2, w * 2, a.shape[2]), a.dtype)
    o[0::2, 0::2] = np.where((c & eq(d, b))[..., None], d, e)
    o[0::2, 1::2] = np.where((c & eq(b, f))[..., None], f, e)
    o[1::2, 0::2] = np.where((c & eq(d, hh))[..., None], d, e)
    o[1::2, 1::2] = np.where((c & eq(hh, f))[..., None], f, e)
    return o


UPSCALER = 'mmpx'                # R4（用户 2026-10-20：水平化后锯齿明显）：Scale2x → MMPX（见下文）；R1–R3 为 'scale2x'


def upscale8(a):
    f = mmpx if UPSCALER == 'mmpx' else scale2x
    return f(f(f(a)))


def forward(x, y):
    return x * COS + y * SIN, -x * SIN + y * COS


def rotate(img, ox, oy, theta=THETA):
    """img：RGBA 数组（透明像素 alpha 为 0），左上角在 G 的 (ox, oy)。返回 (R 中的图块 RGBA 数组, 左上角 X, Y)；全透明时返回 None。
    theta 为画面上逆时针的角度（弧度）；缺省为素材水平化的 atan(1/2)，其他角度用于导弹等弹体的朝向。"""
    cos, sin = math.cos(theta), math.sin(theta)
    a = np.ascontiguousarray(img)
    a = np.where(a[..., 3:4] > 0, a, 0).astype(np.uint8)
    h, w = a.shape[:2]
    big = upscale8(np.pad(a, ((1, 1), (1, 1), (0, 0))))     # 外圈留 1 像素透明，边缘不被复制
    corners = [((ox + dx) * cos + (oy + dy) * sin, -(ox + dx) * sin + (oy + dy) * cos)
               for dx in (-1, w + 1) for dy in (-1, h + 1)]
    x0 = math.floor(min(c[0] for c in corners)); x1 = math.ceil(max(c[0] for c in corners))
    y0 = math.floor(min(c[1] for c in corners)); y1 = math.ceil(max(c[1] for c in corners))
    ys, xs = np.mgrid[y0:y1, x0:x1]
    X, Y = xs + 0.5, ys + 0.5
    gx = X * cos - Y * sin - ox + 1           # 反算到图层（含外圈 1 像素）
    gy = X * sin + Y * cos - oy + 1
    sx = np.floor(gx * 8).astype(np.int64)
    sy = np.floor(gy * 8).astype(np.int64)
    H8, W8 = big.shape[:2]
    ok = (sx >= 0) & (sx < W8) & (sy >= 0) & (sy < H8)
    out = np.zeros(X.shape + (4,), np.uint8)
    out[ok] = big[sy[ok], sx[ok]]
    alpha = out[..., 3] > 0
    if not alpha.any():
        return None
    r, c = np.nonzero(alpha)
    tile = out[r.min():r.max() + 1, c.min():c.max() + 1]
    return tile, x0 + int(c.min()), y0 + int(r.min())


# ---------------------------------------------------------------- MMPX（R4）
# McGuire & Gagiu, "MMPX Style-Preserving Pixel Art Magnification"（JCGT 2021）的 2× 规则：1:1 斜线、交叉、三角尖与 2:1 斜线，
# 只复制原有颜色。Scale2x 只把 1:1 的阶梯连成斜线，本素材的边缘多为 2:1 阶梯（MS6 第 2 关的下坡斜率），旋转为水平后留下锯齿；
# MMPX 的 2:1 规则先把这类阶梯连成直线。透明像素视为最亮的颜色（深色轮廓在拐角处向外补一格，与原规则对浅色背景的处理相同）。
def mmpx(a):
    a = np.ascontiguousarray(a)
    h, w = a.shape[:2]
    k = (a[..., 0].astype(np.uint32) | (a[..., 1].astype(np.uint32) << 8) | (a[..., 2].astype(np.uint32) << 16)
         | (a[..., 3].astype(np.uint32) << 24))
    k = np.where(a[..., 3] > 0, k, 0).astype(np.uint32)
    lu = np.where(a[..., 3] > 0, a[..., :3].astype(np.int32).sum(-1), 1000)
    P = 3
    kp = np.pad(k, P)
    lp = np.pad(lu, P, constant_values=1000)

    def s(dx, dy):
        return kp[P + dy:P + dy + h, P + dx:P + dx + w]

    def ls(dx, dy):
        return lp[P + dy:P + dy + h, P + dx:P + dx + w]
    A, B, C = s(-1, -1), s(0, -1), s(1, -1)
    D, E, F = s(-1, 0), s(0, 0), s(1, 0)
    G, H, I = s(-1, 1), s(0, 1), s(1, 1)
    Pp, S, Q, R = s(0, -2), s(0, 2), s(-2, 0), s(2, 0)
    Bl, Dl, El, Fl, Hl = ls(0, -1), ls(-1, 0), ls(0, 0), ls(1, 0), ls(0, 1)
    J, K, L, M = E.copy(), E.copy(), E.copy(), E.copy()

    def any3(b, x, y, z):
        return (b == x) | (b == y) | (b == z)

    def all2(b, x, y):
        return (b == x) & (b == y)

    def all3(b, x, y, z):
        return (b == x) & (b == y) & (b == z)

    def all4(b, x, y, z, u):
        return (b == x) & (b == y) & (b == z) & (b == u)

    def none2(b, x, y):
        return (b != x) & (b != y)

    def none4(b, x, y, z, u):
        return (b != x) & (b != y) & (b != z) & (b != u)
    # 1:1 斜线
    c = (D == B) & (D != H) & (D != F) & ((El >= Dl) | (E == A)) & any3(E, A, C, G) & ((El < Dl) | (A != D) | (E != Pp) | (E != Q))
    J = np.where(c, D, J)
    c = (B == F) & (B != D) & (B != H) & ((El >= Bl) | (E == C)) & any3(E, A, C, I) & ((El < Bl) | (C != B) | (E != Pp) | (E != R))
    K = np.where(c, B, K)
    c = (H == D) & (H != F) & (H != B) & ((El >= Hl) | (E == G)) & any3(E, A, G, I) & ((El < Hl) | (G != H) | (E != S) | (E != Q))
    L = np.where(c, H, L)
    c = (F == H) & (F != B) & (F != D) & ((El >= Fl) | (E == I)) & any3(E, C, G, I) & ((El < Fl) | (I != H) | (E != R) | (E != S))
    M = np.where(c, F, M)
    # 交叉
    c = (E != F) & all4(E, C, I, D, Q) & all2(F, B, H) & (F != s(3, 0))
    K, M = np.where(c, F, K), np.where(c, F, M)
    c = (E != D) & all4(E, A, G, F, R) & all2(D, B, H) & (D != s(-3, 0))
    J, L = np.where(c, D, J), np.where(c, D, L)
    c = (E != H) & all4(E, G, I, B, Pp) & all2(H, D, F) & (H != s(0, 3))
    L, M = np.where(c, H, L), np.where(c, H, M)
    c = (E != B) & all4(E, A, C, H, S) & all2(B, D, F) & (B != s(0, -3))
    J, K = np.where(c, B, J), np.where(c, B, K)
    # 三角尖
    c = (Bl < El) & all4(E, G, H, I, S) & none4(E, A, D, C, F)
    J, K = np.where(c, B, J), np.where(c, B, K)
    c = (Hl < El) & all4(E, A, B, C, Pp) & none4(E, D, G, I, F)
    L, M = np.where(c, H, L), np.where(c, H, M)
    c = (Fl < El) & all4(E, A, D, G, Q) & none4(E, B, C, I, H)
    K, M = np.where(c, F, K), np.where(c, F, M)
    c = (Dl < El) & all4(E, C, F, I, R) & none4(E, B, A, G, H)
    J, L = np.where(c, D, J), np.where(c, D, L)
    # 2:1 斜线
    hb = H != B
    c1 = hb & (H != A) & (H != E) & (H != C)
    c = c1 & all3(H, G, F, R) & none2(H, D, s(2, -1))
    L, M = np.where(c, H, L), np.where(c, H, M)
    c = c1 & all3(H, I, D, Q) & none2(H, F, s(-2, -1))
    L, M = np.where(c, H, L), np.where(c, H, M)
    c2 = hb & (B != I) & (B != G) & (B != E)
    c = c2 & all3(B, A, F, R) & none2(B, D, s(2, 1))
    J, K = np.where(c, B, J), np.where(c, B, K)
    c = c2 & all3(B, C, D, Q) & none2(B, F, s(-2, 1))
    J, K = np.where(c, B, J), np.where(c, B, K)
    fd = F != D
    c3 = fd & (D != I) & (D != E) & (D != C)
    c = c3 & all3(D, A, H, S) & none2(D, B, s(1, 2))
    J, L = np.where(c, D, J), np.where(c, D, L)
    c = c3 & all3(D, G, B, Pp) & none2(D, H, s(1, -2))
    J, L = np.where(c, D, J), np.where(c, D, L)
    c4 = fd & (F != E) & (F != A) & (F != G)
    c = c4 & all3(F, C, H, S) & none2(F, B, s(-1, 2))
    K, M = np.where(c, F, K), np.where(c, F, M)
    c = c4 & all3(F, I, B, Pp) & none2(F, H, s(-1, -2))
    K, M = np.where(c, F, K), np.where(c, F, M)
    out = np.empty((2 * h, 2 * w), np.uint32)
    out[0::2, 0::2], out[0::2, 1::2], out[1::2, 0::2], out[1::2, 1::2] = J, K, L, M
    o = np.empty((2 * h, 2 * w, 4), np.uint8)
    for ch in range(4):
        o[..., ch] = (out >> (8 * ch)) & 0xff
    return o
