"""Generate Windows icon resources while retaining the supplied PNG artwork."""
from pathlib import Path
import argparse
import json
import shutil
import struct
from io import BytesIO

from PIL import Image


ICON_SIZES = (16, 20, 24, 30, 32, 36, 40, 48, 60, 64, 72, 80, 96, 128, 192, 256)
PROJECT = Path(__file__).resolve().parent.parent


def build(source, destination):
    source, destination = Path(source), Path(destination)
    with Image.open(source) as original:
        original.load()
        if original.format != 'PNG' or original.size != (512, 512):
            raise ValueError('The application icon source must be a 512 by 512 PNG')
        artwork = original.convert('RGBA')
    destination.mkdir(parents=True, exist_ok=True)
    images = {}
    payloads = []
    for size in ICON_SIZES:
        picture = artwork.resize((size, size), Image.Resampling.LANCZOS)
        images[size] = picture
        stream = BytesIO()
        picture.save(stream, format='PNG')
        payloads.append(stream.getvalue())
    offset = 6 + 16 * len(ICON_SIZES)
    directory = []
    for size, payload in zip(ICON_SIZES, payloads):
        dimension = size if size < 256 else 0
        directory.append(struct.pack('<BBBBHHII', dimension, dimension, 0, 0,
                                     1, 32, len(payload), offset))
        offset += len(payload)
    icon = struct.pack('<HHH', 0, 1, len(ICON_SIZES)) + b''.join(directory) + b''.join(payloads)
    icon_path = destination / 'app_icon.ico'
    icon_path.write_bytes(icon)
    images[192].save(destination / 'app_icon_192.png')
    with Image.open(icon_path) as check:
        assert check.ico.sizes() == {(n, n) for n in ICON_SIZES}
        for size in ICON_SIZES:
            decoded = check.ico.getimage((size, size)).convert('RGBA')
            assert decoded.tobytes() == images[size].tobytes(), size
    with Image.open(destination / 'app_icon_192.png') as check:
        check.load()
        assert check.size == (192, 192)
        assert check.convert('RGBA').tobytes() == images[192].tobytes()
    if destination.resolve() == (PROJECT / 'custom_content').resolve():
        mirror = PROJECT / 'src/custom_content'
        mirror.mkdir(parents=True, exist_ok=True)
        for name in ('LOGOAPP.png', 'LOGOAPP2.png', 'app_icon.ico', 'app_icon_192.png'):
            path = destination / name
            if path.is_file():
                shutil.copyfile(path, mirror / name)
                assert path.read_bytes() == (mirror / name).read_bytes()
    return {'source': str(source.resolve()), 'source_size': [512, 512],
            'icon': str(icon_path.resolve()), 'sizes_px': list(ICON_SIZES),
            'color_mode': 'RGBA', 'resampling': 'LANCZOS',
            'composition_preserved': True, 'transparent_background_preserved': True,
            'icon_decode_and_192_png_verified': True}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--source', type=Path, default=PROJECT / 'custom_content/LOGOAPP2.png')
    parser.add_argument('--destination', type=Path, default=PROJECT / 'custom_content')
    args = parser.parse_args()
    print(json.dumps(build(args.source, args.destination), ensure_ascii=False, indent=2))
