"""独立 LAB 存档启动入口；通用运行适配器见 lab_runtime.py。"""
from pathlib import Path
import argparse
import sys

ROOT = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT))
import all_units_level1_launcher as base_launcher
import player
from lab_runtime import (LAB_CORE, PROFILE, KEYS, BLOCKED_MODS, VirtualFile,
                         safe_profile, install_core, install, install_platform)

if __name__ == '__main__':
    try:
        (ROOT / 'lab_launcher_error.log').unlink(missing_ok=True)
        parser = argparse.ArgumentParser(description='MSD WINDOWS S1XLV：LAB 原型')
        parser.add_argument('--profile', default=PROFILE)
        parser.add_argument('--windowed', action='store_true')
        args = parser.parse_args()
        profile = safe_profile(args.profile)
        if LAB_CORE.is_file():
            install_core(LAB_CORE)
        install()
        install_platform()
        session = base_launcher.create_player(False, guest_root=profile,
                                              fullscreen=False if args.windowed else None)
        player.TITLE = 'MSD WINDOWS S1XLV · LAB 原型'
        session.status_file = ROOT / 'lab_status.json'
        session.log_name = 'lab_player.log'
        sys.exit(session.run())
    except Exception:
        import ctypes
        import traceback
        error = traceback.format_exc()
        path = ROOT / 'lab_launcher_error.log'
        path.write_text(error, encoding='utf-8')
        ctypes.windll.user32.MessageBoxW(None, 'LAB 原型启动失败。错误记录：\n' + str(path),
                                        'MSD WINDOWS S1XLV', 0x10)
        sys.exit(1)
