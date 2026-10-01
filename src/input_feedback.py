"""Brief in-game keyboard feedback with GLES state restored after drawing."""
import ctypes as C
import os
from pathlib import Path
from PIL import Image, ImageDraw, ImageFont


class FeedbackOverlay:
    def __init__(self, graphics):
        self.g = graphics
        self.f = graphics.function
        self.program = self.f('glCreateProgram', '', C.c_uint)()
        shaders = []
        try:
            for kind, source in (
                (0x8B31, b'attribute vec2 pos; varying vec2 uv; void main(){'
                           b'gl_Position=vec4(pos,0.0,1.0);uv=(pos+1.0)*0.5;}'),
                (0x8B30, b'precision mediump float; varying vec2 uv; uniform sampler2D tex;'
                           b'void main(){gl_FragColor=texture2D(tex,vec2(uv.x,1.0-uv.y));}'),
            ):
                shader = self.f('glCreateShader', 'u', C.c_uint)(kind)
                shaders.append(shader)
                strings = (C.c_char_p * 1)(source)
                self.f('glShaderSource', 'uipp')(shader, 1, C.cast(strings, C.c_void_p), None)
                self.f('glCompileShader', 'u')(shader)
                status = C.c_int()
                self.f('glGetShaderiv', 'uup')(shader, 0x8B81, C.byref(status))
                if not status.value:raise RuntimeError('Keyboard feedback shader compilation failed')
                self.f('glAttachShader', 'uu')(self.program, shader)
            self.f('glBindAttribLocation', 'uup')(self.program, 0, C.c_char_p(b'pos'))
            self.f('glLinkProgram', 'u')(self.program)
            status = C.c_int()
            self.f('glGetProgramiv', 'uup')(self.program, 0x8B82, C.byref(status))
            if not status.value:raise RuntimeError('Keyboard feedback shader link failed')
        except Exception:
            self.f('glDeleteProgram', 'u')(self.program)
            raise
        finally:
            for shader in shaders:self.f('glDeleteShader', 'u')(shader)
        self.sampler = self.f('glGetUniformLocation', 'up', C.c_int)(self.program, C.c_char_p(b'tex'))
        self.texture, self.buffer = C.c_uint(), C.c_uint()
        self.f('glGenTextures', 'ip')(1, C.byref(self.texture))
        self.f('glGenBuffers', 'ip')(1, C.byref(self.buffer))
        fonts = Path(os.environ['SystemRoot']) / 'Fonts'
        font = next((fonts/n for n in ('msjh.ttc', 'msyh.ttc', 'msgothic.ttc') if (fonts/n).is_file()), None)
        if font is None:raise RuntimeError('CJK font required for keyboard feedback')
        self.font = ImageFont.truetype(str(font), 20)
        self.cached = None
        self.buffer_initialized = False

    def integer(self, parameter, count=1):
        values = (C.c_int * count)()
        self.f('glGetIntegerv', 'up')(parameter, C.cast(values, C.c_void_p))
        return tuple(values) if count > 1 else values[0]

    def attribute(self, parameter):
        value = C.c_int()
        self.f('glGetVertexAttribiv', 'uup')(0, parameter, C.byref(value))
        return value.value

    def draw(self, feedback):
        # Snapshot all state changed below, including the attribute's own VBO.
        program = self.integer(0x8B8D)
        viewport = self.integer(0x0BA2, 4)
        array_buffer = self.integer(0x8894)
        active = self.integer(0x84E0)
        unpack = self.integer(0x0CF5)
        color_mask = self.integer(0x0C23, 4)
        blend = tuple(self.integer(n) for n in (0x80C9, 0x80C8, 0x80CB, 0x80CA, 0x8009, 0x883D))
        flags = {n: self.f('glIsEnabled', 'u', C.c_ubyte)(n) for n in (0x0BE2, 0x0B71, 0x0B90, 0x0B44, 0x0C11)}
        attrib = {n: self.attribute(n) for n in (0x8622, 0x8623, 0x8624, 0x8625, 0x886A, 0x889F)}
        pointer = C.c_void_p()
        self.f('glGetVertexAttribPointerv', 'uup')(0, 0x8645, C.byref(pointer))
        self.f('glActiveTexture', 'u')(0x84C0)
        texture = self.integer(0x8069)
        try:
            self.f('glBindTexture', 'uu')(0x0DE1, self.texture.value)
            key = feedback['text'], feedback['success']
            if key != self.cached:
                width = min(900, max(160, round(self.font.getlength(key[0])) + 24))
                image = Image.new('RGBA', (width, 38), (12, 18, 22, 225))
                draw = ImageDraw.Draw(image)
                draw.text((12, 19), key[0], font=self.font, anchor='lm',
                          fill=(135, 255, 175, 255) if key[1] else (255, 214, 120, 255))
                pixels = C.create_string_buffer(image.tobytes())
                self.f('glPixelStorei', 'ui')(0x0CF5, 4)
                self.f('glTexImage2D', 'uiiiiiuup')(0x0DE1, 0, 0x1908, width, 38, 0,
                                                0x1908, 0x1401, C.cast(pixels, C.c_void_p))
                for parameter, value in ((0x2801, 0x2601), (0x2800, 0x2601), (0x2802, 0x812F), (0x2803, 0x812F)):
                    self.f('glTexParameteri', 'uui')(0x0DE1, parameter, value)
                self.cached, self.size = key, (width, 38)
            self.f('glBindBuffer', 'uu')(0x8892, self.buffer.value)
            if not self.buffer_initialized:
                vertices = (C.c_float * 8)(-1, -1, 1, -1, -1, 1, 1, 1)
                self.f('glBufferData', 'uipu')(0x8892, C.sizeof(vertices), C.cast(vertices, C.c_void_p), 0x88E4)
                self.buffer_initialized = True
            self.f('glEnableVertexAttribArray', 'u')(0)
            self.f('glVertexAttribPointer', 'uiubip')(0, 2, 0x1406, 0, 0, None)
            self.f('glUseProgram', 'u')(self.program)
            self.f('glUniform1i', 'ii')(self.sampler, 0)
            self.f('glViewport', 'iiii')(*self.g.surface_rect((12, self.g.logical_size[1]-76-38, *self.size)))
            self.f('glColorMask', 'bbbb')(1, 1, 1, 1)
            self.f('glEnable', 'u')(0x0BE2)
            self.f('glBlendEquation', 'u')(0x8006)
            self.f('glBlendFunc', 'uu')(0x0302, 0x0303)
            for flag in (0x0B71, 0x0B90, 0x0B44, 0x0C11):self.f('glDisable', 'u')(flag)
            self.f('glDrawArrays', 'uii')(0x0005, 0, 4)
        finally:
            self.f('glBindBuffer', 'uu')(0x8892, attrib[0x889F])
            self.f('glVertexAttribPointer', 'uiubip')(0, attrib[0x8623], attrib[0x8625],
                                                   attrib[0x886A], attrib[0x8624], pointer)
            self.f('glEnableVertexAttribArray' if attrib[0x8622] else 'glDisableVertexAttribArray', 'u')(0)
            self.f('glBindBuffer', 'uu')(0x8892, array_buffer)
            self.f('glUseProgram', 'u')(program)
            self.f('glBindTexture', 'uu')(0x0DE1, texture)
            self.f('glActiveTexture', 'u')(active)
            self.f('glPixelStorei', 'ui')(0x0CF5, unpack)
            self.f('glViewport', 'iiii')(*viewport)
            self.f('glColorMask', 'bbbb')(*color_mask)
            self.f('glBlendFuncSeparate', 'uuuu')(*blend[:4])
            self.f('glBlendEquationSeparate', 'uu')(*blend[4:])
            for flag, enabled in flags.items():self.f('glEnable' if enabled else 'glDisable', 'u')(flag)

    def close(self):
        self.f('glDeleteTextures', 'ip')(1, C.byref(self.texture))
        self.f('glDeleteBuffers', 'ip')(1, C.byref(self.buffer))
        self.f('glDeleteProgram', 'u')(self.program)
