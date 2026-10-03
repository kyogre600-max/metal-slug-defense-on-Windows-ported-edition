"""分页内容面板，图像与命中区域使用统一逻辑坐标。"""
from pathlib import Path
import os

class Panel:
    def __init__(self,p):self.p=p;self.renderer=None;self.boxes=[];self.image=None;self.key=None
    def draw(self,title,rows,footer=(),rect=(0,0,1280,720),key=None):
        from PIL import Image,ImageDraw,ImageFont
        from trial_overlay import SurfaceOverlay
        if self.renderer is None:self.renderer=SurfaceOverlay(self.p.graphics)
        lw,lh=self.p.graphics.logical_size;sx,sy=lw/1280,lh/720
        cache=(title,tuple((label,command) for label,command in rows),tuple(footer),rect,key,lw,lh)
        if self.key!=cache:
            self.key=cache;self.boxes=[]
            image=Image.new('RGBA',(rect[2],rect[3]),(20,30,34,255));d=ImageDraw.Draw(image)
            font=ImageFont.truetype(str(Path(os.environ['SystemRoot'])/'Fonts/msjh.ttc'),26)
            if title:d.text((25,16),title,font=font,fill='#eed9a1')
            def button(x,y,w,h,label,command):
                d.rectangle((x,y,x+w,y+h),fill='#344846',outline='#a3b4a9',width=2)
                d.text((x+14,y+12),label,font=font,fill='white')
                if command:self.boxes.append((((rect[0]+x)*sx,(rect[1]+y)*sy,w*sx,h*sy),command))
            for i,(label,command) in enumerate(rows):
                row,col=divmod(i,2)
                button(25+col*630,80+row*102,600,88,label,command)
            for i,(label,command) in enumerate(footer):button(25+i*300,rect[3]-85,min(280,rect[2]-50),65,label,command)
            self.image=image
        self.renderer.draw_image(self.image,cache,(round(rect[0]*sx),round(rect[1]*sy),round(rect[2]*sx),round(rect[3]*sy)))
    def hit(self,x,y):
        for (bx,by,w,h),command in self.boxes:
            if bx<=x<bx+w and by<=y<by+h:return command
    def close(self):
        if self.renderer:self.renderer.close()

