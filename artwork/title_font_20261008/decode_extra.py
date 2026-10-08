"""解码 scan_obm.py 记录的失败图集（4 位与 16 位格式）。用法：decode_extra.py 输出目录"""
import sys
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(HERE))
import portable_launcher  # noqa: F401,E402
from obm_extra import parse_extra  # noqa: E402

OUT = Path(sys.argv[1])
for n in json.load(open(HERE / 'decode_failures.json')):
    parse_extra((ROOT / 'game_data/assets/com.snkplaymore.android003' / n).read_bytes()).save(OUT / (Path(n).stem + '.png'))
    print('ok', n)
