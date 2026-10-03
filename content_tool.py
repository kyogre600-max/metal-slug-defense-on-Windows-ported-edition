"""扩展资源导入、内容核验与联机内容指纹工具。"""
from pathlib import Path
import sys,argparse,json,hashlib,shutil
ROOT=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT));import portable_launcher
from campaign_catalog import Catalog
from content_assets import import_png

def main():
    parser=argparse.ArgumentParser(description=__doc__);commands=parser.add_subparsers(dest='command',required=True)
    validate=commands.add_parser('validate');validate.add_argument('--catalog',type=Path,default=ROOT/'campaign_content')
    png=commands.add_parser('import-png');png.add_argument('source',type=Path);png.add_argument('destination',type=Path)
    music=commands.add_parser('import-music');music.add_argument('source',type=Path);music.add_argument('destination',type=Path)
    sample=commands.add_parser('install-example');sample.add_argument('--destination',type=Path,default=ROOT/'campaign_content/catalog.json')
    args=parser.parse_args()
    if args.command=='import-png':print(json.dumps(import_png(args.source,args.destination),ensure_ascii=False,indent=2));return
    if args.command=='install-example':
        if args.destination.exists() and json.loads(args.destination.read_text(encoding='utf-8')).get('worlds'):raise ValueError('目标已包含世界配置')
        args.destination.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(ROOT/'campaign_content/catalog.example.json',args.destination);return
    if args.command=='import-music':
        if args.destination.suffix.lower()!='.msdf':raise ValueError('音乐输出扩展名应为 .msdf')
        raw=args.source.read_bytes()
        if not raw.startswith(b'OggS') or len(raw)>64*1024*1024:raise ValueError('音乐输入要求 Ogg Vorbis')
        import ctypes as C,static_cpu
        lib=static_cpu.Uc().lib;fn=lib.msd_vorbis_decode;fn.argtypes=[C.c_void_p,C.c_int32,C.POINTER(C.c_int32),C.POINTER(C.c_int32),C.POINTER(C.c_void_p)];fn.restype=C.c_int32
        channels=C.c_int32();rate=C.c_int32();pcm=C.c_void_p();frames=fn(raw,len(raw),C.byref(channels),C.byref(rate),C.byref(pcm))
        if frames<1:raise ValueError('音乐完整解码核验失败')
        free=lib.msd_vorbis_free;free.argtypes=[C.c_void_p];free(pcm)
        args.destination.parent.mkdir(parents=True,exist_ok=True);args.destination.write_bytes(raw)
        print(json.dumps({'file':args.destination.name,'sha256':hashlib.sha256(raw).hexdigest(),'channels':channels.value,'rate':rate.value,'frames':frames}));return
    units=json.loads((ROOT/'community_content/registry.json').read_text(encoding='utf-8'))
    catalog=Catalog(args.catalog,units['units'])
    from online_session import fingerprint
    print(json.dumps({'worlds':len(catalog.worlds),'stages':len(catalog.stages),'scenes':len(catalog.scenes),'music':len(catalog.music),'online_content_hash':fingerprint(units,catalog)},indent=2))
if __name__=='__main__':main()
