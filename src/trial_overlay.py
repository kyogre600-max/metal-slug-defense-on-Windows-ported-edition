"""Render cached Event panels while preserving native GLES state."""
import ctypes as C
from input_feedback import FeedbackOverlay
class SurfaceOverlay(FeedbackOverlay):
    def draw_image(self,image,key,rect):
        f=self.f
        program=self.integer(0x8B8D);viewport=self.integer(0x0BA2,4)
        array_buffer=self.integer(0x8894);active=self.integer(0x84E0);unpack=self.integer(0x0CF5)
        mask=self.integer(0x0C23,4)
        blend=tuple(self.integer(n) for n in (0x80C9,0x80C8,0x80CB,0x80CA,0x8009,0x883D))
        flags={n:f('glIsEnabled','u',C.c_ubyte)(n) for n in (0x0BE2,0x0B71,0x0B90,0x0B44,0x0C11)}
        attrib={n:self.attribute(n) for n in (0x8622,0x8623,0x8624,0x8625,0x886A,0x889F)}
        pointer=C.c_void_p();f('glGetVertexAttribPointerv','uup')(0,0x8645,C.byref(pointer))
        f('glActiveTexture','u')(0x84C0);texture=self.integer(0x8069)
        try:
            f('glBindTexture','uu')(0x0DE1,self.texture.value)
            if self.cached!=key:
                pixels=C.create_string_buffer(image.tobytes())
                f('glPixelStorei','ui')(0x0CF5,4)
                f('glTexImage2D','uiiiiiuup')(0x0DE1,0,0x1908,*image.size,0,0x1908,0x1401,C.cast(pixels,C.c_void_p))
                for param,val in ((0x2801,0x2600),(0x2800,0x2600),(0x2802,0x812F),(0x2803,0x812F)):
                    f('glTexParameteri','uui')(0x0DE1,param,val)
                self.cached=key
            f('glBindBuffer','uu')(0x8892,self.buffer.value)
            if not self.buffer_initialized:
                vertices=(C.c_float*8)(-1,-1,1,-1,-1,1,1,1)
                f('glBufferData','uipu')(0x8892,C.sizeof(vertices),C.cast(vertices,C.c_void_p),0x88E4)
                self.buffer_initialized=True
            f('glEnableVertexAttribArray','u')(0)
            f('glVertexAttribPointer','uiubip')(0,2,0x1406,0,0,None)
            f('glUseProgram','u')(self.program);f('glUniform1i','ii')(self.sampler,0)
            x,y,w,h=rect
            f('glViewport','iiii')(*self.g.surface_rect((x,self.g.logical_size[1]-y-h,w,h)))
            f('glColorMask','bbbb')(1,1,1,1);f('glEnable','u')(0x0BE2)
            f('glBlendEquation','u')(0x8006);f('glBlendFunc','uu')(0x0302,0x0303)
            for flag in (0x0B71,0x0B90,0x0B44,0x0C11):f('glDisable','u')(flag)
            f('glDrawArrays','uii')(0x0005,0,4)
        finally:
            f('glBindBuffer','uu')(0x8892,attrib[0x889F])
            f('glVertexAttribPointer','uiubip')(0,attrib[0x8623],attrib[0x8625],attrib[0x886A],attrib[0x8624],pointer)
            f('glEnableVertexAttribArray' if attrib[0x8622] else 'glDisableVertexAttribArray','u')(0)
            f('glBindBuffer','uu')(0x8892,array_buffer);f('glUseProgram','u')(program)
            f('glBindTexture','uu')(0x0DE1,texture);f('glActiveTexture','u')(active)
            f('glPixelStorei','ui')(0x0CF5,unpack);f('glViewport','iiii')(*viewport)
            f('glColorMask','bbbb')(*mask);f('glBlendFuncSeparate','uuuu')(*blend[:4])
            f('glBlendEquationSeparate','uu')(*blend[4:])
            for flag,enabled in flags.items():f('glEnable' if enabled else 'glDisable','u')(flag)
