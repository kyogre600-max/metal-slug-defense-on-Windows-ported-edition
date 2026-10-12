"""单位浏览与单位菜单的动效（2026-10-12，开工说明 D52）：按原生动作表与按下白光重现原版界面的过渡。

依据（原始 APK 1.46.0 静态反汇编与运行中读取的动作表，verification/u1_motion_20261012/）：
- 按下白光：GT_MenuPanel、GT_CustomWindow、GT_MenuShopWindow 的按钮在按住时 +0xd8 每帧 +64（上限 255），松开或移出后
  每帧 −64；绘制为同一按钮的“亮版”图像（如列表按钮 ConvMenuParts 110 → 111、红色按钮 97 → 98）以该值为透明度叠在原图上。
  原生弹窗按钮（GT_PopupOKDraw 等）按住时直接画亮版，不渐变；底栏按钮为青色框与三灯（不变）。
- 弹窗开合：任务动作表 14 的动作 0（打开）与 1（关闭），ActionSub2D 逐帧设定缩放与透明度：打开 5 帧，纵向 5%→10%→20%→50%
  →100%、透明度 51→255，全开后才显示窗口内容；关闭 5 帧，纵向 50%→2%、横向 100%→400%、透明度 204→51。窗口下方压暗。
- 列表面板进出：主菜单子页切换时面板任务的动作 5（进入，自右侧偏移 120→60→−6→−2→0，透明度 76→153→255，各行相隔 2 帧）
  与动作 4（离开，偏移 2→4→8→16→32，透明度 255→25）。偏移为原生坐标，画布为其 1280/1137.78 倍。
- 横向滑入：动作表 2 的动作 48/49（偏移 1136→512→256→…→4→0，每帧减半），用于翻页时卡片整体平移。
"""
import ctypes as C

W, H = 1280, 720
NATIVE_TO_CANVAS = 1280 / 1137.78
LIGHT_STEP = 64
DIM = 140                                    # 弹窗下方压暗（UnitBrowser.shaded）
# (横向倍率, 纵向倍率, 透明度)：原生缩放字为 4096 分之一，2.0（8192）为原尺寸
POPUP_OPEN = ((1.0, 409 / 8192, 51), (1.0, 819 / 8192, 102), (1.0, 1638 / 8192, 153), (1.0, 4096 / 8192, 204),
              (1.0, 1.0, 255))
POPUP_CLOSE = ((1.0, 4096 / 8192, 204), (9830 / 8192, 2048 / 8192, 153), (12288 / 8192, 655 / 8192, 102),
               (16384 / 8192, 409 / 8192, 76), (32768 / 8192, 163 / 8192, 51))
PANEL_IN = ((120, 76), (60, 153), (-6, 255), (-2, 255), (0, 255))
PANEL_OUT = ((2, 255), (4, 229), (8, 153), (16, 76), (32, 25))
PANEL_STAGGER = 2
SLIDE = (512, 256, 128, 64, 32, 16, 8, 4, 0)  # 动作 48/49 去掉首帧（整页在画面外，与上一帧相同）
SLIDE_SPAN = 1136


VERTEX = (b'attribute vec2 pos; uniform vec4 area; varying vec2 uv; void main(){'
          b'gl_Position=vec4(pos,0.0,1.0);vec2 t=(pos+1.0)*0.5;'
          b'uv=vec2(area.x+t.x*area.z,area.y+(1.0-t.y)*area.w);}')
FRAGMENT = (b'precision mediump float; varying vec2 uv; uniform sampler2D tex; uniform float alpha;'
            b'void main(){vec4 c=texture2D(tex,uv);gl_FragColor=vec4(c.rgb,c.a*alpha);}')


class Layer:
    """一张纹理：整幅或其中一块（src，图像像素）画到画布矩形（dst），可带整体透明度与裁切矩形（画布坐标）。
    着色器程序与顶点缓冲由所属 Layers 共用；绘制前后保存并恢复原生 GLES 状态（与 SurfaceOverlay 相同）。"""

    def __init__(self, owner):
        self.owner, self.g, self.f = owner, owner.g, owner.f
        self.texture = C.c_uint()
        self.f('glGenTextures', 'ip')(1, C.byref(self.texture))
        self.cached = None
        self.size = (1, 1)

    def integer(self, parameter, count=1):
        values = (C.c_int * count)()
        self.f('glGetIntegerv', 'up')(parameter, C.cast(values, C.c_void_p))
        return tuple(values) if count > 1 else values[0]

    def attribute(self, parameter):
        value = C.c_int()
        self.f('glGetVertexAttribiv', 'uup')(0, parameter, C.byref(value))
        return value.value

    def draw(self, image, key, dst, src=None, alpha=1.0, clip=None):
        """image 为 None 时使用已上传的纹理（key 须与上传时相同）。"""
        f, g, owner = self.f, self.g, self.owner
        lh = g.logical_size[1]
        program = self.integer(0x8B8D); viewport = self.integer(0x0BA2, 4); scissor = self.integer(0x0C10, 4)
        array_buffer = self.integer(0x8894); active = self.integer(0x84E0); unpack = self.integer(0x0CF5)
        mask = self.integer(0x0C23, 4)
        blend = tuple(self.integer(n) for n in (0x80C9, 0x80C8, 0x80CB, 0x80CA, 0x8009, 0x883D))
        flags = {n: f('glIsEnabled', 'u', C.c_ubyte)(n) for n in (0x0BE2, 0x0B71, 0x0B90, 0x0B44, 0x0C11)}
        attrib = {n: self.attribute(n) for n in (0x8622, 0x8623, 0x8624, 0x8625, 0x886A, 0x889F)}
        pointer = C.c_void_p(); f('glGetVertexAttribPointerv', 'uup')(0, 0x8645, C.byref(pointer))
        f('glActiveTexture', 'u')(0x84C0); texture = self.integer(0x8069)
        try:
            f('glBindTexture', 'uu')(0x0DE1, self.texture.value)
            if self.cached != key:
                pixels = C.create_string_buffer(image.tobytes())
                f('glPixelStorei', 'ui')(0x0CF5, 4)
                f('glTexImage2D', 'uiiiiiuup')(0x0DE1, 0, 0x1908, *image.size, 0, 0x1908, 0x1401, C.cast(pixels, C.c_void_p))
                for param, val in ((0x2801, 0x2600), (0x2800, 0x2600), (0x2802, 0x812F), (0x2803, 0x812F)):
                    f('glTexParameteri', 'uui')(0x0DE1, param, val)
                self.cached, self.size = key, image.size
            f('glBindBuffer', 'uu')(0x8892, owner.buffer.value)
            f('glEnableVertexAttribArray', 'u')(0)
            f('glVertexAttribPointer', 'uiubip')(0, 2, 0x1406, 0, 0, None)
            f('glUseProgram', 'u')(owner.program); f('glUniform1i', 'ii')(owner.sampler, 0)
            tw, th = self.size
            sx, sy, sw, sh = src if src is not None else (0, 0, tw, th)
            f('glUniform4f', 'iffff')(owner.u_area, sx / tw, sy / th, sw / tw, sh / th)
            f('glUniform1f', 'if')(owner.u_alpha, max(0.0, min(1.0, alpha)))
            x, y, w, h = dst
            f('glViewport', 'iiii')(*g.surface_rect((round(x), lh - round(y) - round(h), round(w), round(h))))
            f('glColorMask', 'bbbb')(1, 1, 1, 1); f('glEnable', 'u')(0x0BE2)
            f('glBlendEquation', 'u')(0x8006); f('glBlendFunc', 'uu')(0x0302, 0x0303)
            for flag in (0x0B71, 0x0B90, 0x0B44, 0x0C11):
                f('glDisable', 'u')(flag)
            if clip is not None:
                cx, cy, cw, ch = clip
                f('glEnable', 'u')(0x0C11)
                f('glScissor', 'iiii')(*g.surface_rect((cx, lh - cy - ch, cw, ch)))
            f('glDrawArrays', 'uii')(0x0005, 0, 4)
        finally:
            f('glBindBuffer', 'uu')(0x8892, attrib[0x889F])
            f('glVertexAttribPointer', 'uiubip')(0, attrib[0x8623], attrib[0x8625], attrib[0x886A], attrib[0x8624], pointer)
            f('glEnableVertexAttribArray' if attrib[0x8622] else 'glDisableVertexAttribArray', 'u')(0)
            f('glBindBuffer', 'uu')(0x8892, array_buffer); f('glUseProgram', 'u')(program)
            f('glBindTexture', 'uu')(0x0DE1, texture); f('glActiveTexture', 'u')(active)
            f('glPixelStorei', 'ui')(0x0CF5, unpack); f('glViewport', 'iiii')(*viewport)
            f('glScissor', 'iiii')(*scissor)
            f('glColorMask', 'bbbb')(*mask); f('glBlendFuncSeparate', 'uuuu')(*blend[:4])
            f('glBlendEquationSeparate', 'uu')(*blend[4:])
            for flag, enabled in flags.items():
                f('glEnable' if enabled else 'glDisable', 'u')(flag)

    def upload(self, image, key):
        """只上传纹理（不绘制）：空闲帧预先上传之后过渡要用的画面。"""
        f = self.f
        active = self.integer(0x84E0); unpack = self.integer(0x0CF5)
        f('glActiveTexture', 'u')(0x84C0); texture = self.integer(0x8069)
        try:
            f('glBindTexture', 'uu')(0x0DE1, self.texture.value)
            pixels = C.create_string_buffer(image.tobytes())
            f('glPixelStorei', 'ui')(0x0CF5, 4)
            f('glTexImage2D', 'uiiiiiuup')(0x0DE1, 0, 0x1908, *image.size, 0, 0x1908, 0x1401, C.cast(pixels, C.c_void_p))
            for param, val in ((0x2801, 0x2600), (0x2800, 0x2600), (0x2802, 0x812F), (0x2803, 0x812F)):
                f('glTexParameteri', 'uui')(0x0DE1, param, val)
            self.cached, self.size = key, image.size
        finally:
            f('glBindTexture', 'uu')(0x0DE1, texture); f('glActiveTexture', 'u')(active)
            f('glPixelStorei', 'ui')(0x0CF5, unpack)

    def close(self):
        self.f('glDeleteTextures', 'ip')(1, C.byref(self.texture))


class Layers:
    """按名称复用的纹理层（每层一张纹理）；着色器程序与顶点缓冲只建立一次，由各层共用，界面关闭时释放。"""

    def __init__(self, graphics):
        self.g, self.f = graphics, graphics.function
        self.layers = {}
        self.program = None

    def setup(self):
        f = self.f
        program = f('glCreateProgram', '', C.c_uint)()
        shaders = []
        try:
            for kind, source in ((0x8B31, VERTEX), (0x8B30, FRAGMENT)):
                shader = f('glCreateShader', 'u', C.c_uint)(kind)
                shaders.append(shader)
                strings = (C.c_char_p * 1)(source)
                f('glShaderSource', 'uipp')(shader, 1, C.cast(strings, C.c_void_p), None)
                f('glCompileShader', 'u')(shader)
                status = C.c_int()
                f('glGetShaderiv', 'uup')(shader, 0x8B81, C.byref(status))
                if not status.value:
                    raise RuntimeError('UI motion shader compilation failed')
                f('glAttachShader', 'uu')(program, shader)
            f('glBindAttribLocation', 'uup')(program, 0, C.c_char_p(b'pos'))
            f('glLinkProgram', 'u')(program)
            status = C.c_int()
            f('glGetProgramiv', 'uup')(program, 0x8B82, C.byref(status))
            if not status.value:
                raise RuntimeError('UI motion shader link failed')
        except Exception:
            f('glDeleteProgram', 'u')(program)
            raise
        finally:
            for shader in shaders:
                f('glDeleteShader', 'u')(shader)
        uniform = lambda name: f('glGetUniformLocation', 'up', C.c_int)(program, C.c_char_p(name))
        self.sampler, self.u_area, self.u_alpha = uniform(b'tex'), uniform(b'area'), uniform(b'alpha')
        self.buffer = C.c_uint()
        f('glGenBuffers', 'ip')(1, C.byref(self.buffer))
        previous = (C.c_int * 1)()
        f('glGetIntegerv', 'up')(0x8894, C.cast(previous, C.c_void_p))
        f('glBindBuffer', 'uu')(0x8892, self.buffer.value)
        vertices = (C.c_float * 8)(-1, -1, 1, -1, -1, 1, 1, 1)
        f('glBufferData', 'uipu')(0x8892, C.sizeof(vertices), C.cast(vertices, C.c_void_p), 0x88E4)
        f('glBindBuffer', 'uu')(0x8892, previous[0])
        self.program = program

    def layer(self, name):
        if self.program is None:
            self.setup()
        layer = self.layers.get(name)
        if layer is None:
            layer = self.layers[name] = Layer(self)
        return layer

    def cached(self, name):
        layer = self.layers.get(name)
        return layer.cached if layer is not None else None

    def upload(self, name, image, key):
        self.layer(name).upload(image, key)

    def draw(self, name, image, key, dst, src=None, alpha=1.0, clip=None):
        layer = self.layer(name)
        if layer.cached != key and image is None:
            return
        layer.draw(image if layer.cached != key else None, key, dst, src, alpha, clip)

    def drop(self, predicate):
        """释放名称满足 predicate 的层（按下白光结束后释放其纹理）。"""
        for name in [n for n in self.layers if predicate(n)]:
            self.layers.pop(name).close()

    def close(self):
        for layer in self.layers.values():
            layer.close()
        self.layers.clear()
        if self.program is not None:
            self.f('glDeleteBuffers', 'ip')(1, C.byref(self.buffer))
            self.f('glDeleteProgram', 'u')(self.program)
            self.program = None


# ---------------------------------------------------------------- 分镜
class Motion:
    """一段过渡：images 为本段用到的图像（名称 → PIL 图像），frames 为逐帧绘制操作
    （层名, 目标矩形, 源矩形或 None, 透明度, 裁切矩形或 None）。interruptible 为真时期间仍接受输入（翻页）。
    keys 为可选的“层名 → 纹理键”：给出时与其他过渡或空闲帧预先上传的同名同键纹理共用，否则为本段专用。"""
    serial = 0

    def __init__(self, kind, images, frames, interruptible=False, keys=None):
        Motion.serial += 1
        self.kind, self.images, self.frames = kind, images, frames
        self.keys = keys or {}
        self.interruptible = interruptible
        self.index = 0
        self.tag = ('motion', Motion.serial)

    @property
    def done(self):
        return self.index >= len(self.frames)

    def draw(self, layers):
        """画当前一帧并前进；返回是否已画完全部帧。"""
        if self.done:
            return True
        for name, dst, src, alpha, clip in self.frames[self.index]:
            image = self.images[name]
            layers.draw(name, image, self.keys.get(name, (self.tag, name)), dst, src, alpha, clip)
        self.index += 1
        return self.done


def full(name, alpha=1.0):
    return (name, (0, 0, W, H), None, alpha, None)


def scaled_rect(rect, sx, sy):
    x, y, w, h = rect
    cx, cy = x + w / 2, y + h / 2
    return (cx - w * sx / 2, cy - h * sy / 2, w * sx, h * sy)


def popup_open(rect, under, frame, dim_ramp):
    """打开弹窗（动作表 14 动作 0）：under 为窗口下方的画面（未压暗）；压暗为叠一层黑色（'black'），dim_ramp 为真时
    随透明度渐入，否则保持（换窗口时）；frame 为空窗口（只有框与底色）的图像层名。"""
    out = []
    for sx, sy, a in POPUP_OPEN:
        ops = [full(under), full('black', DIM / 255 * (a / 255 if dim_ramp else 1.0))]
        ops.append((frame, scaled_rect(rect, sx, sy), None, a / 255, None))
        out.append(ops)
    return out


def popup_close(rect, under, frame):
    """关闭弹窗（动作 1）：内容先消失，空窗口纵向收起、横向展开并淡出；压暗保持到最后一帧之后。"""
    return [[full(under), full('black', DIM / 255), (frame, scaled_rect(rect, sx, sy), None, a / 255, None)]
            for sx, sy, a in POPUP_CLOSE]


def panel_slots(rects):
    """面板区域可写 (x, y, w, h) 或 ((x, y, w, h), 次序)；同一次序的区域同时进入（例如与中间一行同时进入的翻页箭头）。"""
    out = []
    for i, item in enumerate(rects):
        out.append(item if len(item) == 2 else (item, i))
    return out


def panels_out(background, layer, rects):
    """列表面板离开（动作 4）：各面板同时向右移动并淡出。"""
    out = []
    for dx, a in PANEL_OUT:
        ops = [full(background)]
        for rect, _ in panel_slots(rects):
            x, y, w, h = rect
            ops.append((layer, (x + dx * NATIVE_TO_CANVAS, y, w, h), rect, a / 255, None))
        out.append(ops)
    return out


def panels_in(background, layer, rects):
    """列表面板进入（动作 5）：自右侧滑入并淡入，依次相隔 PANEL_STAGGER 帧。"""
    out = []
    slots = panel_slots(rects)
    for t in range(len(PANEL_IN) + PANEL_STAGGER * max(slot for _, slot in slots)):
        ops = [full(background)]
        for rect, slot in slots:
            k = t - PANEL_STAGGER * slot
            if k < 0:
                continue
            dx, a = PANEL_IN[min(k, len(PANEL_IN) - 1)]
            x, y, w, h = rect
            ops.append((layer, (x + dx * NATIVE_TO_CANVAS, y, w, h), rect, a / 255, None))
        out.append(ops)
    return out


def slide(background, old, new, area, direction, top=None):
    """翻页（动作 48/49 的减半偏移）：新页自 direction 一侧滑入，旧页同时滑出；各图像为裁到 area 的图像，只画在 area 之内，
    top（可选）为平移时留在原处、压在卡片之上的一层。"""
    x, y, w, h = area
    out = []
    for offset in SLIDE:
        dx = direction * w * offset / SLIDE_SPAN
        ops = [(background, area, None, 1.0, None),
               (old, (x + dx - direction * w, y, w, h), None, 1.0, area),
               (new, (x + dx, y, w, h), None, 1.0, area)]
        if top is not None:
            ops.append((top, area, None, 1.0, None))
        out.append(ops)
    return out


# ---------------------------------------------------------------- 按下白光
def color_map(base, lit):
    """同一按钮的原图与亮版（尺寸相同）逐像素配对，得到“原图颜色 → 亮版颜色”（取最常见的对应）。"""
    from collections import Counter
    pairs = {}
    for p, q in zip(base.getdata(), lit.getdata()):
        if p[3] and p != q:
            pairs.setdefault(p, Counter())[q] += 1
    return {p: c.most_common(1)[0][0] for p, c in pairs.items()}


def lighten(image, amount=0.5):
    """图标类按钮的亮版：图标本身的像素向白色移动至多 amount，按亮度加权（深色描边基本不变），透明度不变。"""
    from PIL import Image
    image = image.convert('RGBA')
    white = Image.new('RGBA', image.size, (255, 255, 255, 255))
    blended = Image.blend(image, white, amount)
    weight = image.convert('L').point(lambda v: min(255, v * 2))
    out = Image.composite(blended, image, weight)
    out.putalpha(image.getchannel('A'))
    return out


def relight(image, mapping):
    """按颜色对照表把画面中按钮底色换为亮版（文字等其他颜色不变）。"""
    out = image.copy()
    out.putdata([mapping.get(p, p) for p in image.getdata()])
    return out


class Lights:
    """按下白光：每个命令一个 0–255 的值，按住且指针在区域内时每帧 +64、否则 −64（instant 的为 255 / 0），
    以亮版图像按该值为透明度画在原图之上。"""

    def __init__(self):
        self.values = {}            # 命令 → [值, 区域, 即时]

    def update(self, pressed, rect, inside, instant):
        if pressed is not None and rect is not None and pressed not in self.values:
            self.values[pressed] = [0, rect, instant]
        for command, entry in list(self.values.items()):
            on = command == pressed and inside
            if entry[2]:
                entry[0] = 255 if on else 0
            else:
                entry[0] = min(255, entry[0] + LIGHT_STEP) if on else max(0, entry[0] - LIGHT_STEP)
            if entry[0] == 0 and not on:
                del self.values[command]

    def clear(self):
        self.values.clear()
