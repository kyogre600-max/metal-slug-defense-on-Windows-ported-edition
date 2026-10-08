"""统计全部 OBM 的 OI 头格式，并解码可解码者为 PNG（输出到 decoded/）。"""
from pathlib import Path
import sys, struct, collections, json
HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
sys.path.insert(0, str(ROOT))
import portable_launcher  # noqa
sys.path.insert(0, r'F:\egg\research\metal_slug_defense\windows_native\modding_feasibility_20261002')
from obm_tool import parse
SRC = ROOT / 'game_data/assets/com.snkplaymore.android003'
OUT = Path(sys.argv[1]) if len(sys.argv) > 1 else HERE / 'decoded'
OUT.mkdir(exist_ok=True)
kinds = collections.Counter(); fail = {}
for p in sorted(SRC.glob('*.obm')):
    raw = p.read_bytes()
    k = (raw[:2], raw[2], raw[3]); kinds[str(k)] += 1
    try:
        im = parse(raw)
        im.convert('RGBA').save(OUT / (p.stem + '.png'))
    except Exception as e:
        fail[p.name] = [raw[:2].hex(), raw[2], raw[3], struct.unpack_from('<HH', raw, 4) if len(raw) > 8 else None, len(raw), str(e)[:80]]
print(kinds)
print(len(fail))
json.dump(fail, open(HERE / 'decode_failures.json', 'w'), indent=1)
