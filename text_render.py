"""Local Windows font selection shared by JNI measurements and rasterization."""
from pathlib import Path
import os
from functools import lru_cache
from PIL import ImageFont

FONT_DIR = Path(os.environ['SystemRoot']) / 'Fonts'
# These installed font files were checked against all exported JP/KR/ZT text.
LANGUAGE_FONTS = {1: ('msgothic.ttc', 'msjh.ttc', 'msyh.ttc', 'arial.ttf'),
                  2: ('malgun.ttf',),
                  9: ('msjh.ttc', 'msyh.ttc', 'mingliu.ttc', 'arial.ttf'),
                  10: ('msyh.ttc', 'msjh.ttc', 'mingliu.ttc', 'arial.ttf')}
KOREAN_FALLBACK = frozenset('\u2010\u30fb')

class FontLayout:
    def __init__(self, primary, fallback=None):
        self.primary, self.fallback = primary, fallback
        metrics = [font.getmetrics() for font in (primary, fallback) if font is not None]
        self.metrics = max(v[0] for v in metrics), max(v[1] for v in metrics)

    def getmetrics(self):
        return self.metrics

    def runs(self, text):
        if self.fallback is None:
            return [(self.primary, text)]
        runs = []
        for character in text:
            font = self.fallback if character in KOREAN_FALLBACK else self.primary
            if runs and runs[-1][0] is font:
                runs[-1] = font, runs[-1][1] + character
            else:
                runs.append((font, character))
        return runs

    @lru_cache(maxsize=2048)
    def getlength(self, text):
        return sum(font.getlength(run) for font, run in self.runs(text))

    def draw(self, draw, position, text, **kwargs):
        x, y = position
        for font, run in self.runs(text):
            draw.text((x, y), run, font=font, anchor='ls', **kwargs)
            x += font.getlength(run)

def font_for(probe, size, language):
    selection_key=language,int(size)
    selected=getattr(probe,'font_selection',None)
    if selected is None:probe.font_selection=selected={}
    if selection_key in selected:return selected[selection_key]
    names = LANGUAGE_FONTS.get(language, ('arial.ttf',))
    primary_path = next((FONT_DIR / name for name in names if (FONT_DIR / name).is_file()), None)
    if primary_path is None:
        raise RuntimeError('Required Windows font is unavailable: ' + ', '.join(names))
    fallback_path = None
    if language == 2 and primary_path.name.lower() == 'malgun.ttf':
        fallback_path = next((FONT_DIR / name for name in ('msjh.ttc', 'msyh.ttc', 'msgothic.ttc')
                              if (FONT_DIR / name).is_file()), None)
    key = language, str(primary_path), str(fallback_path), int(size)
    if not hasattr(probe, 'fonts'):
        probe.fonts = {}
    if key not in probe.fonts:
        primary = ImageFont.truetype(str(primary_path), size, index=0)
        fallback = ImageFont.truetype(str(fallback_path), size, index=0) if fallback_path else None
        probe.fonts[key] = FontLayout(primary, fallback)
        probe.log('FONT_SELECTED', language, size, primary_path.name,
                  fallback_path.name if fallback_path else None)
    selected[selection_key]=probe.fonts[key]
    return selected[selection_key]
