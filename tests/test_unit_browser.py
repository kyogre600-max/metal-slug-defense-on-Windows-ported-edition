"""单位浏览组件与目录操作结果的独立检查（不启动原生核心）：设定文件的校验与往返、结果对象的货币变化。"""
from pathlib import Path
import json
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
import portable_launcher  # noqa: E402,F401  （登记运行时 DLL 目录）
import unit_browser  # noqa: E402
import unit_catalog  # noqa: E402


class FakeProbe:
    def __init__(self, folder):
        self.saves = Path(folder)
        self.logs = []

    def log(self, *values):
        self.logs.append(values)


class UnitBrowserStateTests(unittest.TestCase):
    def browser(self, folder):
        return unit_browser.UnitBrowser(FakeProbe(folder), None, ROOT)

    def test_defaults_without_file(self):
        with tempfile.TemporaryDirectory() as temp:
            b = self.browser(temp)
            b.load_state()
            self.assertEqual(b.state['favorites'], [])
            self.assertEqual(b.state['custom'], unit_browser.default_settings('custom'))
            self.assertNotIn('display', b.state['shop'])

    def test_roundtrip(self):
        with tempfile.TemporaryDirectory() as temp:
            b = self.browser(temp)
            b.load_state()
            b.state['favorites'] = ['original.16', 's1xlv.kt21']
            b.state['custom'].update(sort='hp', descending=True, factions=[0, 4], sources=['body'], text='MAR', page=3,
                                     favorites_only=True)
            b.save_state()
            again = self.browser(temp)
            again.load_state()
            self.assertEqual(again.state['favorites'], ['original.16', 's1xlv.kt21'])
            self.assertEqual(again.state['custom'], b.state['custom'])
            self.assertFalse((Path(temp) / (unit_browser.STATE_NAME + '.tmp')).exists())

    def test_invalid_values_fall_back(self):
        with tempfile.TemporaryDirectory() as temp:
            data = {'favorites': ['ok', 3, None], 'custom': {'sort': 'price', 'descending': 'yes', 'factions': [0, 9],
                                                             'sources': ['x'], 'text': 'x' * 41, 'page': -1,
                                                             'display': 'ap'},
                    'shop': {'sort': 'price', 'display': 'ap', 'page': 2}}
            (Path(temp) / unit_browser.STATE_NAME).write_text(json.dumps(data), encoding='utf-8')
            b = self.browser(temp)
            b.load_state()
            self.assertEqual(b.state['favorites'], ['ok'])
            # 强化模式没有价格排序；越界的阵营、来源、文字与页码都不采用；旧版设定中的 display 忽略
            self.assertEqual(b.state['custom'], unit_browser.default_settings('custom'))
            self.assertEqual((b.state['shop']['sort'], b.state['shop']['page']), ('price', 2))
            self.assertNotIn('display', b.state['shop'])

    def test_corrupt_file(self):
        with tempfile.TemporaryDirectory() as temp:
            (Path(temp) / unit_browser.STATE_NAME).write_text('{not json', encoding='utf-8')
            b = self.browser(temp)
            b.load_state()
            self.assertEqual(b.state['shop'], unit_browser.default_settings('shop'))

    def test_layout_constants(self):
        # 已确认样张的 3×3 布局（D15、D19）：卡片 364×126，行距与列距在区域内均分，BUY 位于卡片右下（D35）
        self.assertEqual((unit_browser.CARD_W, unit_browser.CARD_H, unit_browser.GAP_Y), (364, 126, 27))
        x, y, w, h = unit_browser.BUY_RECT
        self.assertEqual((w, h), (104, 46))
        self.assertLessEqual(x + w, unit_browser.CARD_W - unit_browser.CARD_EDGES[2] * unit_browser.CARD_SCALE)


class ResultTests(unittest.TestCase):
    def test_currency_delta(self):
        r = unit_catalog.result('upgrade', 'k', True, None, {'medal': 10, 'msp': 5000}, {'medal': 10, 'msp': 2720},
                                levels=1)
        self.assertEqual(r['currency'], {'medal': 0, 'msp': -2280})
        self.assertEqual(r['wallet'], {'medal': 10, 'msp': 2720})
        self.assertTrue(r['ok'])
        self.assertEqual(r['levels'], 1)

    def test_failure_without_after(self):
        r = unit_catalog.result('purchase', 'k', False, 'medal_short', {'medal': 3, 'msp': 0}, need=7)
        self.assertEqual(r['currency'], {'medal': 0, 'msp': 0})
        self.assertEqual((r['reason'], r['need']), ('medal_short', 7))


if __name__ == '__main__':
    unittest.main()
