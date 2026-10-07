"""Build icon-bearing Windows launchers with the installed MinGW toolchain."""
from pathlib import Path
import argparse
import ctypes
import json
import shutil
import subprocess


SOURCE = Path(__file__).resolve().parent
PROJECT = SOURCE.parent
TOOLCHAIN = Path(r'C:\Program Files\mingw64\bin')
ENTRYPOINTS = {
    'MSD WINDOWS S1XLV.exe': 'portable_launcher.py',
    'Start_MSD_All_Units_Level1.exe': 'all_units_level1_launcher.py',
    'Start_MSD_All_Unlocked_Max_Level.exe': 'all_unlocked_max_level_launcher.py',
    'Start_LAB.exe': 'lab_launcher.py',
    'Start_MSD_Max_Level.exe': 'max_level_launcher.py',
}


def build(destination, entry_root):
    destination, entry_root = Path(destination).resolve(), Path(entry_root).resolve()
    destination.mkdir(parents=True, exist_ok=True)
    temporary = SOURCE / 'build/app_launchers'
    temporary.mkdir(parents=True, exist_ok=True)
    resource = temporary / 'branding.o'
    binary = temporary / 'application_launcher.exe'
    gcc = str(TOOLCHAIN / 'gcc.exe')
    short_path = ctypes.create_unicode_buffer(32768)
    if ctypes.windll.kernel32.GetShortPathNameW(gcc, short_path, len(short_path)):
        gcc = short_path.value
    commands = [
        [str(TOOLCHAIN / 'windres.exe'), '--preprocessor=' + gcc,
         '--preprocessor-arg=-E', '--preprocessor-arg=-xc', '--preprocessor-arg=-DRC_INVOKED',
         '-i', 'branding.rc', '-o', str(resource)],
        [str(TOOLCHAIN / 'g++.exe'), '-std=c++17', '-O2', '-s', '-municode', '-mwindows',
         '-static-libgcc', '-static-libstdc++', 'launcher.cpp', str(resource), '-o', str(binary)],
    ]
    for command in commands:
        subprocess.run(command, cwd=SOURCE, check=True)
    outputs = []
    for name, entry in ENTRYPOINTS.items():
        if (entry_root / entry).is_file():
            target = destination / name
            shutil.copyfile(binary, target)
            outputs.append({'file': str(target), 'python_entry': entry,
                            'bytes': target.stat().st_size})
    version = json.loads((PROJECT / 'branding.json').read_text(encoding='utf-8'))['display_version']
    return {'version': version, 'outputs': outputs, 'commands': commands}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output-dir', type=Path, default=PROJECT)
    parser.add_argument('--entry-root', type=Path, default=PROJECT)
    args = parser.parse_args()
    print(json.dumps(build(args.output_dir, args.entry_root), ensure_ascii=False, indent=2))
