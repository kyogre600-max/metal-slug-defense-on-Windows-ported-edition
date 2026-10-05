"""生成三款单位的独立像素素材；保持原生图集坐标、透明度及帧锚点。"""
from pathlib import Path
import json
import os
import sys
from collections import Counter, defaultdict

ROOT = Path(__file__).resolve().parent
REPO = ROOT.parents[1]
RUNTIME = REPO / "windows_runtime"
DLL_HANDLE = os.add_dll_directory(str(RUNTIME / "native"))
sys.path.insert(0, str(RUNTIME / "packages"))
from PIL import Image, ImageChops, ImageDraw, ImageFont

SOURCE = ROOT / "source"
DEST = ROOT / "sprites"
PREVIEW = ROOT / "previews"
DESCRIPTORS = json.loads((SOURCE / "native/native_descriptors.json").read_text(encoding="utf-8"))
BASE_RAMP = [(16, 16, 8), (74, 57, 16), (106, 90, 49), (148, 123, 74), (213, 197, 139), (255, 255, 238)]
SDB_RAMP = [(16, 16, 8), (72, 56, 16), (104, 88, 48), (144, 120, 72), (208, 192, 136), (248, 248, 232)]
FEATURE_BASE = [(82, 24, 0), (123, 49, 8), (172, 98, 0)]
FEATURE_RAMPS = {
    "white_mummy": [(80, 24, 72), (120, 48, 96), (168, 96, 152)],
    "green_mummy": [(80, 24, 0), (120, 48, 8), (168, 96, 0)],
}
FONT = ImageFont.truetype("C:/Windows/Fonts/msyh.ttc", 19)
SMALL = ImageFont.truetype("C:/Windows/Fonts/msyh.ttc", 14)


def write_json(path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(value, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


def transparent_reference(box):
    """原始 MSX 图集采用纯色背景；仅清除该背景颜色。"""
    image = Image.open(SOURCE / "sdb_Mummy.gif").convert("RGBA").crop(box)
    image.putdata([(0, 0, 0, 0) if p[:3] == (64, 32, 80) else p for p in image.getdata()])
    return image.crop(image.getbbox())


def ramp_of(image):
    colors = {p[:3] for p in image.getdata() if p[3]}
    return sorted(colors, key=lambda c: sum(c))


def canonical_bytes(image):
    image = image.convert("RGBA")
    image.putdata([p if p[3] else (0, 0, 0, 0) for p in image.getdata()])
    return image.tobytes()


def body_signature(image, ramp):
    """使用六级本体色的逐像素分布识别参考中的相同姿态。"""
    lut = {color: i + 1 for i, color in enumerate(ramp)}
    mask = Image.new("L", image.size)
    mask.putdata([lut.get(p[:3], 0) if p[3] else 0 for p in image.getdata()])
    box = mask.getbbox()
    if box is None:
        return None, None
    cropped = mask.crop(box)
    return (cropped.size, cropped.tobytes()), box


def verify_feature_reference(desc, native, key, body_ramp):
    """在原始动作参考中匹配本体姿态，独立核对眼睛与舌头颜色。"""
    signatures = defaultdict(list)
    for rid, rect in enumerate(desc["rects"]):
        x, y, w, h, ax, ay, flags, page = rect
        if page != 0:
            continue
        tile = native.crop((x, y, x + w, y + h))
        if flags & 1:
            tile = tile.transpose(Image.Transpose.FLIP_LEFT_RIGHT)
        signature, box = body_signature(tile, BASE_RAMP)
        if signature:
            signatures[signature].append((rid, tile, box))
    filename = "WhiteMummy.gif" if key == "white_mummy" else "0035.gif"
    counts = defaultdict(Counter)
    matches = []
    sample = None
    with Image.open(SOURCE / filename) as reference:
        for index in range(reference.n_frames):
            reference.seek(index)
            image = reference.convert("RGBA")
            if key == "green_mummy":
                # 该参考所有不透明颜色比原始八步级颜色高 2；统一至 SDB 待机参考编码。
                image.putdata([tuple(max(0, c - 2) for c in p[:3]) + (p[3],) if p[3] else p for p in image.getdata()])
            signature, ref_box = body_signature(image, body_ramp)
            if signature not in signatures:
                continue
            rid, tile, native_box = signatures[signature][0]
            ox, oy = ref_box[0] - native_box[0], ref_box[1] - native_box[1]
            patch = image.crop((ox, oy, ox + tile.width, oy + tile.height))
            matches.append({"reference_frame": index, "native_rect_id": rid})
            for original, target in zip(tile.getdata(), patch.getdata()):
                if original[3] and target[3] and original[:3] in FEATURE_BASE:
                    counts[original[:3]][target[:3]] += 1
            if rid == 29 and sample is None:
                sample = patch
    expected = dict(zip(FEATURE_BASE, FEATURE_RAMPS[key]))
    for original, target in expected.items():
        assert set(counts[original]) == {target}, (key, original, counts[original])
    assert sample is not None
    return {
        "reference_file": f"source/{filename}",
        "reference_rgb_offset_removed": 2 if key == "green_mummy" else 0,
        "matched_poses": matches,
        "feature_colors": [{"native": list(a), "reference": list(b), "matched_pixels": counts[a][b]} for a, b in expected.items()],
    }, sample


def feature_comparison(samples, desc):
    """展示同一原生姿态的参考、修订前与修订后像素。"""
    revision = SOURCE / "revisions/before_eye_tongue_r1"
    canvas = Image.new("RGB", (960, 700), (38, 45, 53))
    draw = ImageDraw.Draw(canvas)
    draw.text((18, 12), "眼睛与舌头配色核查 · 对应原生矩形 29 · 最近邻放大", font=FONT, fill=(242, 238, 220))
    for i, label in enumerate(["原始动作参考（编码已统一）", "修订前图集", "修订后图集"]):
        draw.text((18 + i * 320, 48), label, font=FONT, fill=(242, 238, 220))
    x, y, w, h, ax, ay, flags, page = desc["rects"][29]
    for row, key in enumerate(["white_mummy", "green_mummy"]):
        tiles = [samples[key]]
        for path in [revision / f"{key}_atlas_0.png", DEST / f"{key}_atlas_0.png"]:
            atlas = Image.open(path).convert("RGBA")
            tile = atlas.crop((x, y, x + w, y + h))
            if flags & 1:
                tile = tile.transpose(Image.Transpose.FLIP_LEFT_RIGHT)
            tiles.append(tile)
        for col, tile in enumerate(tiles):
            enlarged = tile.resize((tile.width * 6, tile.height * 6), Image.Resampling.NEAREST)
            canvas.paste(enlarged, (30 + col * 320, 100 + row * 300), enlarged)
        draw.text((200, 190 + row * 300), "白木乃伊" if row == 0 else "绿木乃伊", font=SMALL, fill=(170, 187, 195))
    canvas.save(PREVIEW / "eye_tongue_comparison_r1.png")


def rect_mask(desc, scripts, page, size):
    mask = Image.new("L", size)
    draw = ImageDraw.Draw(mask)
    for script in scripts:
        for frame in desc["scripts"][str(script)]["timeline"]:
            for rid in frame["rects"]:
                x, y, w, h, ax, ay, flags, pg = desc["rects"][rid]
                if pg == page:
                    draw.rectangle((x, y, x + w - 1, y + h - 1), fill=255)
    return mask


def recolor_indexed(image, mapping, mask=None):
    """新增调色板条目并局部更换索引，避免共享颜色导致其他效果变化。"""
    assert image.mode == "P"
    out = image.copy()
    palette = list(image.getpalette("RGB"))
    palette += [0] * (768 - len(palette))
    alpha = image.info.get("transparency", bytes([255] * 256))
    if isinstance(alpha, int):
        alpha = bytes(0 if i == alpha else 255 for i in range(256))
    alpha = list(bytes(alpha) + bytes([255] * (256 - len(alpha))))
    used = set(image.tobytes())
    free = iter(i for i in range(256) if i not in used)
    lut = {}
    for old_index in sorted(used):
        color = tuple(palette[old_index * 3:old_index * 3 + 3])
        if alpha[old_index] == 0 or color not in mapping:
            continue
        replacement = tuple(mapping[color])
        candidates = [i for i in used if tuple(palette[i * 3:i * 3 + 3]) == replacement and alpha[i] == alpha[old_index]]
        new_index = candidates[0] if candidates else next(free)
        palette[new_index * 3:new_index * 3 + 3] = replacement
        alpha[new_index] = alpha[old_index]
        lut[old_index] = new_index
    mask_data = mask.tobytes() if mask else bytes([255]) * (image.width * image.height)
    out.putdata([lut.get(index, index) if selected else index for index, selected in zip(image.tobytes(), mask_data)])
    out.putpalette(palette)
    out.info["transparency"] = bytes(alpha)
    return out


def draw_frame(desc, atlases, ids, size=(160, 112), anchor=(80, 96), face_right=False):
    canvas = Image.new("RGBA", size)
    for rid in ids:
        x, y, w, h, ax, ay, flags, page = desc["rects"][rid]
        tile = atlases[page].convert("RGBA").crop((x, y, x + w, y + h))
        if flags & 1:
            tile = tile.transpose(Image.Transpose.FLIP_LEFT_RIGHT)
        if face_right:
            tile = tile.transpose(Image.Transpose.FLIP_LEFT_RIGHT)
            ax = w - ax
        assert 0 <= anchor[0] - ax and anchor[0] - ax + w <= size[0], (rid, "水平画布边界")
        assert 0 <= anchor[1] - ay and anchor[1] - ay + h <= size[1], (rid, "垂直画布边界")
        canvas.alpha_composite(tile, (anchor[0] - ax, anchor[1] - ay))
    return canvas


def sequence(desc, atlases, slot, size=(160, 112), anchor=(80, 96)):
    """仅绘制动作本体；弹体、附属对象与战斗逻辑分别保留描述记录。"""
    script = desc["scripts"][str(slot)]
    frames = []
    timeline = script["timeline"]
    for i, frame in enumerate(timeline):
        end = timeline[i + 1]["tick"] if i + 1 < len(timeline) else script["duration_ticks"]
        for tick in range(frame["tick"], end):
            frames.append(draw_frame(desc, atlases, frame["rects"], size, anchor, True))
    return frames


def save_gif(frames, path, label):
    assert frames
    rendered = []
    for frame in frames:
        canvas = Image.new("RGBA", (frame.width + 24, frame.height + 34), (38, 45, 53, 255))
        draw = ImageDraw.Draw(canvas)
        draw.line((0, frame.height + 16, canvas.width, frame.height + 16), fill=(100, 108, 106), width=1)
        canvas.alpha_composite(frame, (12, 17))
        canvas = canvas.resize((canvas.width * 3, canvas.height * 3), Image.Resampling.NEAREST).convert("RGB")
        ImageDraw.Draw(canvas).text((12, 7), label, font=FONT, fill=(242, 238, 220))
        rendered.append(canvas)
    rendered[0].save(path, save_all=True, append_images=rendered[1:], duration=[(30, 30, 40)[i % 3] for i in range(len(rendered))], loop=0, disposal=1)


def ordered_sheet(desc, atlases, path, cell=(160, 112), anchor=(80, 96)):
    frames = desc["frames"]
    offsets, off = [], 0
    while off < len(frames):
        count = frames[off]
        ids = frames[off + 1:off + count + 1]
        offsets.append((off, ids))
        off += 1 + count
    assert off == len(frames)
    columns = 8
    sheet = Image.new("RGBA", (columns * cell[0], ((len(offsets) + columns - 1) // columns) * cell[1]))
    records = []
    for i, (offset, ids) in enumerate(offsets):
        x, y = i % columns * cell[0], i // columns * cell[1]
        sheet.alpha_composite(draw_frame(desc, atlases, ids, cell, anchor), (x, y))
        records.append({"native_frame_offset": offset, "rect_ids": ids, "sheet_rect": [x, y, *cell], "anchor": list(anchor)})
    sheet.save(path)
    return records


def contact_rows(desc, atlases, slots, path, size=(160, 112), anchor=(80, 96)):
    width = 8 * size[0]
    rows = sum((len(desc["scripts"][str(slot)]["timeline"]) + 7) // 8 for label, slot in slots)
    height = rows * (size[1] + 20) + len(slots) * 30
    sheet = Image.new("RGB", (width, height), (38, 45, 53))
    draw = ImageDraw.Draw(sheet)
    cy = 0
    for label, slot in slots:
        timeline = desc["scripts"][str(slot)]["timeline"]
        draw.text((8, cy + 3), f"{label}   原生动作 {slot}   {len(timeline)} 个帧条目", font=FONT, fill=(242, 238, 220))
        cy += 30
        for i, row in enumerate(timeline):
            x, y = i % 8 * size[0], cy + i // 8 * (size[1] + 20)
            frame = draw_frame(desc, atlases, row["rects"], size, anchor)
            sheet.paste(frame, (x, y), frame)
            draw.text((x + 5, y + size[1]), f"{i:02d}  tick {row['tick']}", font=SMALL, fill=(151, 167, 176))
        cy += ((len(timeline) + 7) // 8) * (size[1] + 20)
    sheet.save(path)


def main():
    DEST.mkdir(exist_ok=True)
    PREVIEW.mkdir(exist_ok=True)
    evidence = {"date": "2026-10-05", "stage": "standalone_artwork", "checks": {}, "units": {}, "sha256_performed": False, "runtime_files_modified": False}
    normal = transparent_reference((5, 70, 43, 125))
    white = transparent_reference((391, 70, 433, 125))
    green = transparent_reference((350, 70, 391, 125))
    refs = {"white_mummy": ("白木乃伊", white), "green_mummy": ("绿木乃伊", green)}
    desc = DESCRIPTORS["Mummy"]
    native = [Image.open(SOURCE / "native" / n.replace(".obm", ".png")) for n in desc["images"]]
    first = desc["rects"][0]
    native_pose = native[0].convert("RGBA").crop((first[0], first[1], first[0] + first[2], first[1] + first[3]))
    native_pose.putdata([(*dict(zip(BASE_RAMP, SDB_RAMP))[p[:3]], 255) if p[3] else (0, 0, 0, 0) for p in native_pose.getdata()])
    assert canonical_bytes(native_pose) == canonical_bytes(normal), "MSX 参考姿态与原生待机首帧存在像素差异"
    evidence["checks"]["native_idle_matches_msx_source_pixels"] = True
    body_slots = list(range(21)) + [24, 25, 26]
    palettes = {}
    feature_audit = {"date": "2026-10-05", "scope": "眼睛与舌头颜色", "units": {}, "sha256_performed": False}
    feature_samples = {}
    for key, (label, reference) in refs.items():
        ramp = ramp_of(reference)
        assert len(ramp) == 6
        mapping = dict(zip(BASE_RAMP, ramp))
        feature_evidence, sample = verify_feature_reference(desc, native[0].convert("RGBA"), key, ramp)
        feature_audit["units"][key] = feature_evidence
        feature_samples[key] = sample
        mapping.update(dict(zip(FEATURE_BASE, FEATURE_RAMPS[key])))
        comparison = normal.copy()
        comparison.putdata([(*dict(zip(SDB_RAMP, ramp))[p[:3]], 255) if p[3] else (0, 0, 0, 0) for p in comparison.getdata()])
        assert canonical_bytes(comparison) == canonical_bytes(reference)
        reference.save(SOURCE / f"{key}_msx_reference.png")
        paths, atlases, changes = [], [], []
        for page, image in enumerate(native):
            body = rect_mask(desc, body_slots, page, image.size)
            effects = rect_mask(desc, [21, 22, 23], page, image.size)
            body = ImageChops.subtract(body, effects)
            colored = recolor_indexed(image, mapping, body)
            assert colored.convert("RGBA").getchannel("A").tobytes() == image.convert("RGBA").getchannel("A").tobytes()
            original_effects = Image.composite(image.convert("RGBA"), Image.new("RGBA", image.size), effects)
            result_effects = Image.composite(colored.convert("RGBA"), Image.new("RGBA", image.size), effects)
            assert original_effects.tobytes() == result_effects.tobytes()
            path = DEST / f"{key}_atlas_{page}.png"
            colored.save(path)
            paths.append(str(path.relative_to(ROOT)))
            atlases.append(colored)
            changes.append(sum(a != b for a, b in zip(image.tobytes(), colored.tobytes())))
        saved = Image.open(DEST / f"{key}_atlas_0.png").convert("RGBA")
        x, y, w, h, ax, ay, flags, page = desc["rects"][29]
        saved_pose = saved.crop((x, y, x + w, y + h))
        if flags & 1:
            saved_pose = saved_pose.transpose(Image.Transpose.FLIP_LEFT_RIGHT)
        assert canonical_bytes(saved_pose) == canonical_bytes(sample)
        before = Image.open(SOURCE / "revisions/before_eye_tongue_r1" / f"{key}_atlas_0.png").convert("RGBA")
        differences = Counter((a[:3], b[:3]) for a, b in zip(before.getdata(), saved.getdata()) if a != b)
        expected_features = dict(zip(FEATURE_BASE, FEATURE_RAMPS[key]))
        assert all(expected_features[a] == b for a, b in differences)
        assert before.getchannel("A").tobytes() == saved.getchannel("A").tobytes()
        feature_evidence.update({"exported_rect29_matches_reference_rgba": True, "only_three_feature_colors_changed": True, "changed_pixels": sum(differences.values())})
        records = ordered_sheet(desc, atlases, DEST / f"{key}_frames.png")
        write_json(DEST / f"{key}_frames.json", {"cells": records, "descriptor": desc, "native_origin": "左向；锚点遵循原生矩形", "purpose": "独立美术交接；尚未登记为游戏单位"})
        palettes[key] = [{"original": list(a), "target": list(b)} for a, b in mapping.items()]
        contact_rows(desc, atlases, [("待机", 6), ("移动", 7), ("吐出动作", 10 if key == "white_mummy" else 8), ("受击", 12), ("消散", 13), ("碎裂", 15), ("出场", 25)], PREVIEW / f"{key}_actions.png")
        save_gif(sequence(desc, atlases, 6) * 3 + sequence(desc, atlases, 7) + sequence(desc, atlases, 10 if key == "white_mummy" else 8), PREVIEW / f"{key}_body.gif", f"{label} · 待机／移动／吐出动作")
        evidence["units"][key] = {"atlas_paths": paths, "atlas_dimensions": [list(p.size) for p in atlases], "native_rect_count": len(desc["rects"]), "native_script_count": len(desc["scripts"]), "ordered_frame_count": len(records), "changed_pixels_per_atlas": changes, "reference_pose_pixel_match": True, "alpha_preserved": True, "projectile_effects_preserved": True}

    # 箱体采用原始参考的十级红褐色；蓝色铭牌及闪烁色沿用本地图集。
    brown_reference = Image.open(SOURCE / "Coffin.png").convert("RGBA")
    red_reference = Image.open(SOURCE / "Coffin.gif").convert("RGBA")
    brown = [(40, 0, 0), (64, 32, 0), (80, 48, 8), (104, 64, 24), (120, 72, 32), (144, 88, 24), (160, 104, 40), (184, 136, 64), (224, 184, 104), (232, 224, 160)]
    red = [(40, 0, 0), (88, 8, 0), (104, 24, 8), (120, 48, 24), (144, 48, 32), (160, 72, 24), (184, 80, 40), (208, 112, 64), (248, 160, 104), (248, 200, 160)]
    assert set(brown) <= {p[:3] for p in brown_reference.getdata() if p[3]}
    assert set(red) <= {p[:3] for p in red_reference.getdata() if p[3]}
    expanded = [tuple((min(v // 8, 31) * 255 // 31) for v in c) for c in brown]
    mapping = dict(zip(expanded, red))
    # 侧面内壁的额外暗色引用原始红褐色参考的深阴影，独立记录映射依据。
    mapping[(41, 24, 0)] = (88, 8, 0)
    gate_desc = DESCRIPTORS["MummyGate"]
    gate_native = Image.open(SOURCE / "native/gate_out.png")
    gate = recolor_indexed(gate_native, mapping)
    gate.save(DEST / "mummy_generator_mk2_atlas.png")
    assert gate.convert("RGBA").getchannel("A").tobytes() == gate_native.convert("RGBA").getchannel("A").tobytes()
    palettes["mummy_generator_mk2"] = [{"original": list(a), "target": list(b), "source": "Coffin.gif"} for a, b in mapping.items()]
    gate_records = ordered_sheet(gate_desc, [gate], DEST / "mummy_generator_mk2_frames.png", (160, 144), (80, 112))
    write_json(DEST / "mummy_generator_mk2_frames.json", {"cells": gate_records, "descriptor": gate_desc, "purpose": "箱体、门扇与碎块独立帧；附属门扇需依原生脚本组合"})
    contact_rows(gate_desc, [gate], [("箱体", 15), ("箱体闪烁", 16), ("门扇", 6), ("门扇受击", 11), ("损毁", 13), ("碎块", 21)], PREVIEW / "mummy_generator_mk2_actions.png", (160, 144), (80, 112))
    gate_frame = draw_frame(gate_desc, [gate], gate_desc["scripts"]["15"]["timeline"][0]["rects"] + gate_desc["scripts"]["6"]["timeline"][0]["rects"], (160, 144), (80, 112))
    gate_frame.save(PREVIEW / "mummy_generator_mk2_closed.png")
    gate_open = draw_frame(gate_desc, [gate], gate_desc["scripts"]["15"]["timeline"][0]["rects"], (160, 144), (80, 112))
    gate_open.save(PREVIEW / "mummy_generator_mk2_open.png")
    # 仅作配色展示；门扇开合与修筑时序保留后续原生适配任务。
    evidence["units"]["mummy_generator_mk2"] = {"atlas_paths": ["sprites/mummy_generator_mk2_atlas.png"], "atlas_dimensions": [[256, 256]], "native_rect_count": len(gate_desc["rects"]), "native_script_count": len(gate_desc["scripts"]), "ordered_frame_count": len(gate_records), "alpha_preserved": True, "palette_reference": "source/Coffin.gif", "mission4_palette_confirmation": "2026-10-05 用户明确确认采用该红褐色"}

    # 原始弹体与虫体逐图块导出，保持角色改色与投射物素材独立。
    effect_manifest = {}
    for label, dname, slots in [("rolling_ball", "Mummy", [22, 23]), ("insects", "BungeeMummy", [31, 32, 33, 34, 35])]:
        d = DESCRIPTORS[dname]
        pages = [Image.open(SOURCE / "native" / n.replace(".obm", ".png")) for n in d["images"]]
        ids = sorted({rid for slot in slots for frame in d["scripts"][str(slot)]["timeline"] for rid in frame["rects"]})
        maximum = max(max(d["rects"][rid][2:4]) for rid in ids)
        cell = ((maximum + 31) // 32) * 32
        image = Image.new("RGBA", (cell * 8, cell * ((len(ids) + 7) // 8)))
        records = []
        for i, rid in enumerate(ids):
            x, y, w, h, ax, ay, flags, pg = d["rects"][rid]
            tile = pages[pg].convert("RGBA").crop((x, y, x + w, y + h))
            if flags & 1:
                tile = tile.transpose(Image.Transpose.FLIP_LEFT_RIGHT)
            assert w <= cell and h <= cell
            cx, cy = i % 8 * cell + (cell - w) // 2, i // 8 * cell + (cell - h) // 2
            image.alpha_composite(tile, (cx, cy))
            records.append({"native_rect_id": rid, "native_rect": d["rects"][rid], "sheet_rect": [cx, cy, w, h], "anchor": [ax, ay]})
        image.save(DEST / f"{label}.png")
        effect_manifest[label] = {"rectangles": records, "native_scripts": {str(slot): d["scripts"][str(slot)] for slot in slots}, "native_images": d["images"]}
    write_json(DEST / "effects.json", effect_manifest)
    write_json(ROOT / "palette_maps.json", palettes)
    write_json(ROOT / "eye_tongue_verification_r1.json", feature_audit)
    feature_comparison(feature_samples, desc)

    # 汇总预览采用整数倍最近邻缩放，展示三款素材及其原始配色参考。
    summary = Image.new("RGB", (1000, 500), (38, 45, 53))
    draw = ImageDraw.Draw(summary)
    draw.text((26, 18), "白木乃伊／绿木乃伊／木乃伊召唤箱 MKII · 独立美术阶段", font=FONT, fill=(242, 238, 220))
    for i, (key, (label, ref)) in enumerate(refs.items()):
        draw.text((30 + i * 245, 70), label, font=FONT, fill=(242, 238, 220))
        ref_big = ref.resize((ref.width * 5, ref.height * 5), Image.Resampling.NEAREST)
        summary.paste(ref_big, (48 + i * 245, 110), ref_big)
        draw.text((30 + i * 245, 356), "MSX 六级原始调色板", font=SMALL, fill=(170, 187, 195))
        for j, color in enumerate(ramp_of(ref)):
            draw.rectangle((30 + i * 245 + j * 28, 388, 55 + i * 245 + j * 28, 414), fill=color)
    crop = gate_frame.crop(gate_frame.getbbox())
    big_gate = crop.resize((crop.width * 4, crop.height * 4), Image.Resampling.NEAREST)
    summary.paste(big_gate, (570, 93), big_gate)
    draw.text((570, 61), "木乃伊召唤箱 MKII", font=FONT, fill=(242, 238, 220))
    draw.text((570, 465), "第四关红褐色参考 · 用户已确认", font=SMALL, fill=(170, 187, 195))
    summary.save(PREVIEW / "three_units_overview.png")

    gif_results = []
    for path in sorted(PREVIEW.glob("*.gif")):
        decoded, total = 0, 0
        with Image.open(path) as image:
            for i in range(image.n_frames):
                image.seek(i)
                image.convert("RGBA").load()
                total += image.info.get("duration", 0)
                decoded += 1
        gif_results.append({"path": str(path.relative_to(ROOT)), "decoded_frames": decoded, "duration_ms": total})
    evidence["checks"]["gif_full_decode"] = gif_results
    atlas_results = []
    for path in sorted(DEST.glob("*atlas*.png")):
        with Image.open(path) as image:
            image.load()
            colors = image.getcolors(maxcolors=256)
            assert image.mode == "P" and colors is not None
            atlas_results.append({"path": str(path.relative_to(ROOT)), "mode": image.mode, "used_palette_indices": len(colors)})
    evidence["checks"]["indexed_palette_limit"] = atlas_results
    evidence["checks"]["all_ordered_frame_rectangles_within_canvas"] = True
    evidence["checks"]["eyes_tongue_reference_match"] = "eye_tongue_verification_r1.json"
    evidence["checks"]["mummy_ordered_sheet_cell"] = {"size": [160, 112], "anchor": [80, 96], "native_relative_bounds": [-68, -63, 70, 15]}
    write_json(ROOT / "artwork_verification.json", evidence)
    print(json.dumps(evidence, ensure_ascii=False, indent=1))


if __name__ == "__main__":
    main()
