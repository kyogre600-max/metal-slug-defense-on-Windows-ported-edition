"""LAB 前置核查（只读）：记录战斗中双方控制器的类型、AUTO 状态、AP 与槽位。

用法（在正式版仓库根目录）：
    windows_runtime\\python.exe -B -I -S lab_probe_launcher.py [--profile verification/lab_probe] [--windowed]

- 默认使用独立存档 verification/lab_probe（首次启动由全兵种 Lv1 种子初始化），
  拒绝 play_save* 及仓库外的目录，不读写个人存档。
- 只调用原生只读查询函数（getAP / getAutoPlay / getUnitInfo 等），不改内存、不出兵。
- 进入任意战斗后每 30 帧采样一次，内容变化时追加一行到仓库根目录 lab_probe.jsonl。
  请分别进入一场普通关卡和一场 Wi-Fi NPC 对战，各停留 10 秒以上。
"""
from pathlib import Path
import argparse
import json
import sys
import time

ROOT = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT))
import all_units_level1_launcher as base_launcher
import player

OUTPUT = ROOT / 'lab_probe.jsonl'
SAMPLE_EVERY = 30
PLAYER_FAMILY = ('BattleControllerPlayerBase', 'BattleControllerPlayer', 'BattleControllerNetPlayer',
                 'BattleControllerNetMultiPlayer', 'BattleControllerNetRaidPlayer')


def safe_profile(path):
    profile = (ROOT / path).resolve()
    if not profile.is_relative_to(ROOT):
        raise ValueError('存档目录必须位于仓库内')
    if any(part.lower().startswith('play_save') for part in profile.relative_to(ROOT).parts):
        raise ValueError('拒绝使用 play_save* 目录，请使用独立存档')
    return profile


class LabProbe:
    def __init__(self, p):
        self.p = p
        self.last = None
        self.classes = {}
        for name, address in p.symbols.items():
            if name.startswith('_ZTV') and 'BattleController' in name:
                body = name[4:]
                digits = ''
                while body and body[0].isdigit():
                    digits += body[0]
                    body = body[1:]
                self.classes[address + 8] = body[:int(digits)] if digits else body
        p.log('LAB_PROBE_READY', len(self.classes))

    def valid(self, address):
        return 0x10000000 <= address < 0x1ffff000

    def controller(self, address):
        p = self.p
        vtable = p.word(address)
        cls = self.classes.get(vtable, hex(vtable))
        info = {'address': hex(address), 'class': cls,
                'team': p.word(address + 0x38c), 'member': p.word(address + 0x39c)}
        if cls in PLAYER_FAMILY:
            info['ap'] = p.call('_ZN26BattleControllerPlayerBase5getAPEv', address)
            info['auto_play'] = p.call('_ZN26BattleControllerPlayerBase11getAutoPlayEv', address)
            info['kyoten_level'] = p.call('_ZN26BattleControllerPlayerBase14getKyotenLevelEv', address)
            slots = []
            for slot in range(10):
                unit = p.call('_ZNK16BattleController11getUnitInfoEi', address, slot)
                if not unit:
                    slots.append(None)
                    continue
                cooldown = p.word(unit + 0x18)
                slots.append({'unit_id': p.word(unit + 0x10), 'cost': p.word(unit),
                              'enabled': p.read(unit + 0xc, 1)[0],
                              'cooldown': cooldown - (1 << 32) if cooldown & 0x80000000 else cooldown})
            info['slots'] = slots
        return info

    def sample(self):
        p = self.p
        app = p.app_instance()
        if not app or p.word(app + 0x22bc) != 100:
            return
        main = p.word(app + 0xc220)
        if not main or not p.word(main + 8):
            return
        scene = p.call('_ZN10BattleMain12getMainSceneEv', main)
        if not scene:
            return
        record = {'frame': p.frame,
                  'app': {'npc_flag_c061': p.read(app + 0xc061, 1)[0], 'c63c': p.word(app + 0xc63c),
                          'c06c': p.word(app + 0xc06c)},
                  'playing': bool(p.call('_ZN10BattleMain15isBattlePlayingEv', main)),
                  'game_mode': p.word(scene + 0x24)}
        operator = p.word(scene + 0x3c)
        record['operator_controller'] = hex(p.word(operator + 0x18)) if self.valid(operator) else None
        controllers = []
        for index in range(8):
            address = p.word(scene + 0x40 + index * 4)
            if self.valid(address) and p.word(address) in self.classes:
                entry = self.controller(address)
                entry['scene_index'] = index
                controllers.append(entry)
        record['controllers'] = controllers
        key = json.dumps({k: v for k, v in record.items() if k != 'frame'}, sort_keys=True,
                         default=str)
        # AP 每帧变化；只在结构或 AUTO/槽位变化时完整记录，AP 变化每 10 秒记录一次。
        structural = json.dumps([{k: v for k, v in c.items() if k != 'ap'} for c in controllers]
                                + [record['game_mode'], record['app'], record['playing']], sort_keys=True)
        now = time.monotonic()
        if structural == getattr(self, 'last_structural', None) and now - getattr(self, 'last_time', 0) < 10:
            return
        self.last_structural, self.last_time = structural, now
        with OUTPUT.open('a', encoding='utf-8') as stream:
            stream.write(json.dumps(record, ensure_ascii=False) + '\n')
        p.log('LAB_PROBE_SAMPLE', record['game_mode'], [c['class'] for c in controllers])


def install():
    probe_class = player.Probe

    class ProbedProbe(probe_class):
        def step_frame(self):
            super().step_frame()
            if not hasattr(self, 'lab_probe'):
                self.lab_probe = LabProbe(self)
            if self.frame % SAMPLE_EVERY == 0:
                try:
                    self.lab_probe.sample()
                except Exception as error:  # 核查失败不影响游戏运行
                    self.log('LAB_PROBE_ERROR', type(error).__name__, str(error))

    player.Probe = ProbedProbe


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='LAB 前置只读核查')
    parser.add_argument('--profile', default='verification/lab_probe')
    parser.add_argument('--windowed', action='store_true')
    args = parser.parse_args()
    profile = safe_profile(args.profile)
    install()
    session = base_launcher.create_player(False, guest_root=profile,
                                          fullscreen=False if args.windowed else None)
    player.TITLE = 'MSD WINDOWS S1XLV · LAB 核查（只读）'
    session.status_file = ROOT / 'lab_probe_status.json'
    session.log_name = 'lab_probe_player.log'
    sys.exit(session.run())
