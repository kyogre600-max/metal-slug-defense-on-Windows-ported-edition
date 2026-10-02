"""Compile generated C++ to a Windows x64 DLL with existing local MinGW."""
from pathlib import Path
import subprocess,concurrent.futures,json,time,hashlib
ROOT=Path(__file__).resolve().parent
COMPILER=Path(r'C:\Program Files\mingw64\bin\g++.exe')
def main():
    out=ROOT/'build';out.mkdir(exist_ok=True)
    sources=[ROOT/'aot_runtime.cpp',ROOT/'native_imports.cpp',ROOT/'native_audio.cpp',*sorted((ROOT/'generated').glob('*.cpp'))]
    started=time.perf_counter()
    def compile_one(src):
        obj=out/(src.stem+'.o');log=out/(src.stem+'.log')
        dependencies=[src,ROOT/'aot_runtime.h']
        if src.parent==ROOT:dependencies.append(ROOT/'native_imports.h')
        if src.name=='native_audio.cpp':dependencies.append(ROOT/'third_party/stb_vorbis.c')
        if obj.exists() and obj.stat().st_mtime>max(p.stat().st_mtime for p in dependencies):return obj
        command=[str(COMPILER),'-std=c++17','-O2','-Wa,-mbig-obj','-fno-strict-aliasing','-ffp-contract=off','-fno-exceptions','-fno-rtti','-c',str(src),'-o',str(obj)]
        result=subprocess.run(command,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
        log.write_text(result.stdout,encoding='utf-8')
        if result.returncode:
            obj.unlink(missing_ok=True)
            raise RuntimeError(str(log)+'\n'+result.stdout[:1800])
        print('compiled',src.name,flush=True);return obj
    with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:objects=list(pool.map(compile_one,sources))
    command=[str(COMPILER),'-shared','-static-libgcc','-static-libstdc++','-o',str(out/'msd_aot.dll'),*[str(p) for p in objects]]
    subprocess.run(command,check=True)
    result={'compiler':str(COMPILER),'target':'Windows x64 PE DLL','seconds':time.perf_counter()-started,'sha256':hashlib.sha256((out/'msd_aot.dll').read_bytes()).hexdigest(),'bytes':(out/'msd_aot.dll').stat().st_size,'objects':len(objects)}
    (out/'build_result.json').write_text(json.dumps(result,indent=2))
    (ROOT/'core_runtime.json').write_text(json.dumps({'library':'msd_aot.dll','sha256':result['sha256']},indent=2),encoding='utf-8')
    print(json.dumps(result))
if __name__=='__main__':main()
