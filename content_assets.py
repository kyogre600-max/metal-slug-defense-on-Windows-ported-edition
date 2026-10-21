"""像素素材的无损导入与运行格式核验。"""
from pathlib import Path
import struct
from content_digest import blake2

def decode_obm(raw):
    if len(raw)<8 or raw[:4]!=b'OI\x01\x08':
        raise ValueError('规范场景图集要求 OI、RGBA 调色板和 8 位索引')
    w,h=struct.unpack_from('<HH',raw,4)
    if not 0<w<=8192 or not 0<h<=8192 or len(raw)!=1032+w*h:
        raise ValueError('图集尺寸或字节数不符合约定')
    palette=[raw[8+i*4:12+i*4] for i in range(256)]
    return (w,h),b''.join(palette[i] for i in raw[1032:])

def import_png(source,destination):
    from PIL import Image
    source=Path(source);destination=Path(destination)
    if destination.suffix.lower()!='.obm':raise ValueError('输出扩展名应为 .obm')
    with source.open('rb') as stream:header=stream.read(29)
    if len(header)<29 or header[:8]!=b'\x89PNG\r\n\x1a\n' or header[12:16]!=b'IHDR' or header[24]>8:
        raise ValueError('PNG 通道位深要求不超过 8 位')
    with Image.open(source) as image:
        if image.format!='PNG' or getattr(image,'n_frames',1)!=1:
            raise ValueError('输入要求单帧 PNG')
        if image.mode not in ('1','P','RGB','RGBA','L','LA'):
            raise ValueError('输入要求 8 位 RGB、RGBA、灰度或调色板 PNG')
        w,h=image.size
        if not 0<w<=8192 or not 0<h<=8192:raise ValueError('输入尺寸超出范围')
        pixels=image.convert('RGBA').tobytes()
    # 原生透明图集保留索引零，避免首个不透明颜色被解释为透明色。
    palette={b'\0\0\0\0':0};indices=bytearray()
    for i in range(0,len(pixels),4):
        color=pixels[i:i+4]
        if color not in palette:
            if len(palette)==256:raise ValueError('RGBA 颜色超过 256 种；需要显式完成调色板整理')
            palette[color]=len(palette)
        indices.append(palette[color])
    # 原生场景纹理使用重复采样，画布采用二的整数次幂以满足 GLES2 完整性条件。
    tw=1<<(w-1).bit_length();th=1<<(h-1).bit_length()
    padded=b''.join(indices[y*w:(y+1)*w]+b'\0'*(tw-w) for y in range(h))+b'\0'*(tw*(th-h))
    raw=b'OI\x01\x08'+struct.pack('<HH',tw,th)+b''.join(palette)+b'\0'*((256-len(palette))*4)+padded
    if len(raw)>64*1024*1024:raise ValueError('运行图集超过 64 MiB')
    size,decoded=decode_obm(raw)
    restored=b''.join(decoded[y*tw*4:(y*tw+w)*4] for y in range(h))
    if size!=(tw,th) or restored!=pixels:raise RuntimeError('图集像素往返核验失败')
    destination.parent.mkdir(parents=True,exist_ok=True)
    temp=destination.with_suffix('.obm.tmp');temp.write_bytes(raw);temp.replace(destination)
    return {'file':destination.name,'blake2b':blake2(raw),'size':[tw,th],'source_size':[w,h],'colors':len(palette)}


# 图像源场景图集（2026-10-19，MS6 关卡移植 S0）：场景的 texture 可登记无损 PNG / WebP。
# 启动时只读取尺寸与摘要；原生打开对应 OBM 时再解码为直接 RGBA（OI kind 1、32 位，原生 OGLTexture / ImageDesc 均支持），
# 画布补透明边缘到二的整数次幂。仓库与内存中只保存压缩后的源文件，最近一次解码结果保留以免同一次载入重复解码。
IMAGE_TEXTURE_SUFFIXES=('.png','.webp')

def pow2(n):
    return 1<<(n-1).bit_length()

class ImageTexture:
    """一个图像源；runtime_name 为原生场景记录使用的 OBM 文件名。"""
    _last=(None,None)
    def __init__(self,path):
        from PIL import Image
        self.path=Path(path);self.file_size=self.path.stat().st_size
        with Image.open(self.path) as image:
            if image.format not in ('PNG','WEBP') or getattr(image,'n_frames',1)!=1:raise ValueError('场景图像源要求单帧 PNG 或 WebP：'+self.path.name)
            if image.format=='WEBP' and image.info.get('lossless') is False:raise ValueError('WebP 场景图像源要求无损编码：'+self.path.name)
            self.source_size=image.size
        w,h=self.source_size
        if not 0<w<=8192 or not 0<h<=8192:raise ValueError('场景图像源尺寸超出范围：'+self.path.name)
        self.size=(pow2(w),pow2(h))
        self.runtime_name=self.path.name+'.obm'
    def __len__(self):return self.file_size
    def obm(self):
        key=(str(self.path),self.path.stat().st_mtime_ns)
        if ImageTexture._last[0]==key:return ImageTexture._last[1]
        from PIL import Image
        with Image.open(self.path) as image:rgba=image.convert('RGBA')
        if rgba.size!=self.source_size:raise ValueError('场景图像源在运行中被修改：'+self.path.name)
        tw,th=self.size
        if (tw,th)!=rgba.size:
            canvas=Image.new('RGBA',(tw,th),(0,0,0,0));canvas.paste(rgba,(0,0));rgba=canvas
        raw=b'OI\x01\x20'+struct.pack('<HH',tw,th)+rgba.tobytes()
        ImageTexture._last=(key,raw)
        return raw
