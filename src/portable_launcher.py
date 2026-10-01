"""Bootstrap the local Python/ANGLE bundle before importing game dependencies."""
from pathlib import Path
import os
import sys

ROOT = Path(__file__).resolve().parent
RUNTIME = Path(sys.executable).resolve().parent
DLL_DIRECTORIES = []
for name in ('.', 'native', 'angle'):
    folder = RUNTIME / name
    if folder.is_dir():
        DLL_DIRECTORIES.append(os.add_dll_directory(str(folder)))
sys.path.insert(0, str(ROOT))

if __name__ == '__main__':
    import runpy
    sys.argv[0] = str(ROOT / 'player.py')
    runpy.run_path(sys.argv[0], run_name='__main__')
