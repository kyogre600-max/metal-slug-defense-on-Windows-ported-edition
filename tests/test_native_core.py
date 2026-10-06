"""发布前检查：build/ 中的原生核心须导出 Python 宿主引用的全部 msd_* 接口。

此前 KT-21 已提交火焰中断适配器源码与注册表，但 build/MSD_Core.dll 仍为旧构建，
玩家下载 ZIP 后启动即报 "Native core lacks the flame interruption adapter"。
本检查只读取 PE 导出表，不加载 DLL，可在任意平台运行。
"""
from pathlib import Path
import json,re,struct,unittest
ROOT=Path(__file__).resolve().parents[1]
SYMBOL=re.compile(r"""(?:\blib\.|['"])(msd_[A-Za-z0-9_]+)""")

def pe_exports(path):
    d=Path(path).read_bytes()
    pe=struct.unpack_from('<I',d,0x3c)[0]
    if d[pe:pe+4]!=b'PE\0\0':raise ValueError('not a PE file')
    machine,nsec=struct.unpack_from('<HH',d,pe+4);optsize=struct.unpack_from('<H',d,pe+20)[0];opt=pe+24
    if struct.unpack_from('<H',d,opt)[0]!=0x20b:raise ValueError('not a PE32+ (x64) image')
    rva,size=struct.unpack_from('<II',d,opt+112)
    secs=[struct.unpack_from('<IIII',d,pe+24+optsize+40*i+8) for i in range(nsec)]
    def off(r):
        for vsize,va,rawsize,raw in secs:
            if va<=r<va+max(vsize,rawsize):return r-va+raw
        raise ValueError('RVA outside sections')
    if not rva:return machine,set()
    e=off(rva);count=struct.unpack_from('<I',d,e+24)[0];names=off(struct.unpack_from('<I',d,e+32)[0])
    out=set()
    for i in range(count):
        p=off(struct.unpack_from('<I',d,names+4*i)[0]);out.add(d[p:d.index(b'\0',p)].decode())
    return machine,out

def required_symbols():
    found=set()
    for py in ROOT.glob('*.py'):found.update(SYMBOL.findall(py.read_text(encoding='utf-8')))
    return found

class NativeCoreRelease(unittest.TestCase):
    def test_active_core_exports_host_interfaces(self):
        name=json.loads((ROOT/'core_runtime.json').read_text(encoding='utf-8'))['library']
        dll=ROOT/'build'/name
        self.assertTrue(dll.is_file(),f'{dll} 不存在；src/build/ 不会随仓库发布')
        machine,exports=pe_exports(dll)
        self.assertEqual(machine,0x8664,'核心必须为 Windows x64')
        missing=sorted(required_symbols()-exports)
        self.assertFalse(missing,f'{dll.name} 缺少导出 {missing}；请用 src/build.py 重新构建并复制到 build/{name}')

if __name__=='__main__':unittest.main()
