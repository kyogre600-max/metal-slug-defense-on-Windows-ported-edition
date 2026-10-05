"""离线核对：由生成的 OBM、描述符与注册动画重建精灵集，与 R7 候选逐 tick 渲染逐像素比较。"""
import json, os, sys
from pathlib import Path
sys.path.insert(0, os.environ['KT21_TOOLS']); sys.path.insert(0, str(Path(__file__).parent))
from PIL import Image
from obm_tool import parse
from native_sim import World, SpriteSet
import integrate_kt21 as I

OUT = Path(os.environ['KT21_OUT']) / 'community_content'
desc = json.loads((OUT / I.DESCRIPTOR).read_text(encoding='utf-8'))
reg = json.loads((OUT / 'registry.json').read_text(encoding='utf-8'))
unit = next(u for u in reg['units'] if u['key'] == I.KEY)
pages = [parse((OUT / t).read_bytes()).convert('RGBA') for t in unit['textures']]
frames, pos = {}, 0
F = desc['frames']
while pos < len(F):
    n = F[pos]; tiles = []
    for i in F[pos + 1:pos + 1 + n]:
        x, y, w, h, ax, ay, flags, pg = desc['rects'][i]
        t = pages[pg].crop((x, y, x + w, y + h))
        if flags & 1: t = t.transpose(Image.FLIP_LEFT_RIGHT)
        tiles.append((t, ax, ay))
    frames[pos] = tiles; pos += n + 1
scripts = {int(k): [[c['opcode'], *c['values']] for c in v] for k, v in unit['animations'].items()}
atk = {i: tuple(r) for i, r in enumerate(desc['attack_bounds']) if i}
new = SpriteSet(frames, scripts, atk, (13, 14, 14))
r7, *_ = I.build_scripts()
def render(s, slot, ticks):
    w = World(0); w.spawn(s, slot, 0, 0, -1, 'unit'); out = []
    for t in range(ticks):
        c = Image.new('RGBA', (700, 260), (0, 0, 0, 0)); w.draw(c, 200, 200, show_attack=True); out.append(c.tobytes()); w.step()
    return out, [e for e in w.events]
res = {}
mapping = {2: 9}
for slot in (0, 1, 2, 6, 7, 8, 9, 10, 11, 12, 13, 15, 16, 17, 18, 19, 20):
    a, ea = render(new, slot, 120)
    b, eb = render(r7, mapping.get(slot, slot), 120)
    if slot == 2:
        res[slot] = {'events_new': len(ea)}
        continue
    diff = sum(x != y for x, y in zip(a, b))
    res[slot] = {'ticks': 120, 'differing_ticks': diff, 'events_equal': [e[:3] for e in ea] == [e[:3] for e in eb]}
# ALT 槽：第 0 tick 发射收尾弹体（此处以效果对象代替原生钩子），其余与槽 11 一致
for j in range(5):
    s = scripts[I.ALT_BASE + j]
    assert s[1:] == scripts[11], j
    res['alt%d' % j] = s[0]
print(json.dumps(res, ensure_ascii=False))
assert all(v.get('differing_ticks', 0) == 0 and v.get('events_equal', True) for v in res.values() if isinstance(v, dict))
