"""正式版各启动入口共用的 LAB 输入、原生核心与存档隔离适配器。"""
from pathlib import Path
import io
import sys

ROOT = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT))
try:
    # 先登记便携运行时 DLL 目录，再导入 ctypes 与窗口宿主。
    import portable_launcher
    import player
    import glfw
    import ctypes
except BaseException:
    # pythonw 无控制台：导入阶段的异常也写入错误记录，避免“双击无反应”。
    import traceback
    (ROOT / 'lab_launcher_error.log').write_text(traceback.format_exc(), encoding='utf-8')
    raise

PROFILE = 'lab_test_save'
# 含 LAB 钩子的核心由正式版配置统一加载；独立入口和验证保留显式指定核心接口。
LAB_CORE = ROOT / 'src' / 'build' / 'MSD_Core_LAB_r16_20261007.dll'
KEYS = {glfw.KEY_F7: ('prep',), glfw.KEY_F5: ('exit',), glfw.KEY_F8: ('toggle_full',),
        glfw.KEY_F4: ('toggle_enemy_ai',), glfw.KEY_F3: ('toggle_player_ai',),
        glfw.KEY_LEFT_BRACKET: ('enemy_ap',), glfw.KEY_RIGHT_BRACKET: ('enemy_slug',),
        glfw.KEY_BACKSLASH: ('enemy_special',)}
KEYS.update({key: ('enemy_unit', slot) for slot, key in enumerate(
    (glfw.KEY_Q, glfw.KEY_W, glfw.KEY_E, glfw.KEY_R, glfw.KEY_T,
     glfw.KEY_Y, glfw.KEY_U, glfw.KEY_I, glfw.KEY_O, glfw.KEY_P))})
BLOCKED_MODS = glfw.MOD_SHIFT | glfw.MOD_CONTROL | glfw.MOD_ALT | glfw.MOD_SUPER


def safe_profile(path):
    profile = (ROOT / path).resolve()
    if not profile.is_relative_to(ROOT):
        raise ValueError('存档目录必须位于仓库内')
    if any(part.lower().startswith('play_save') for part in profile.relative_to(ROOT).parts):
        raise ValueError('拒绝使用 play_save* 目录，请使用独立存档副本')
    return profile


class VirtualFile(io.BytesIO):
    """LAB 隔离期间的存档写入目标：关闭时把内容记入 lab.virtual_files，不落盘。"""

    def __init__(self, lab, key, initial, append=False):
        super().__init__(initial)
        self.lab, self.key = lab, key
        if append:
            self.seek(0, io.SEEK_END)

    def close(self):
        if not self.closed:
            self.lab.virtual_files[self.key] = self.getvalue()
        super().close()


def install_core(path):
    """以指定 DLL 替代根目录配置的核心，ABI 检查与原 static_cpu.Uc 相同。"""
    import ctypes
    import probe
    import static_cpu

    class LabUc(static_cpu.Uc):
        def __init__(self, *args):
            self.ctx = static_cpu.Context()
            self.callbacks = {}
            self.library_path = path
            self.lib = ctypes.CDLL(str(path))
            self.lib.msd_context_size.restype = ctypes.c_uint32
            if self.lib.msd_context_size() != ctypes.sizeof(static_cpu.Context):
                raise RuntimeError('AOT context ABI mismatch')
            self.lib.msd_runtime_kind.restype = ctypes.c_uint32
            if self.lib.msd_runtime_kind() != 0x414f5431:
                raise RuntimeError('Unexpected AOT backend')
            self.lib.msd_run.argtypes = [ctypes.POINTER(static_cpu.Context), ctypes.c_uint32]
            self.lib.msd_run.restype = ctypes.c_uint32

    probe.Uc = LabUc


def install():
    probe_class = player.Probe
    player_class = player.Player
    if getattr(probe_class, 'lab_runtime_installed', False) and getattr(player_class, 'lab_runtime_installed', False):
        return

    class LabProbe(probe_class):
        lab_runtime_installed = True

        def initialize(self):
            super().initialize()
            from lab import Lab
            self.lab = Lab(self, ROOT)
            enable = getattr(self.uc.lib, 'msd_enable_lab_hooks', None)
            if enable is None:
                self.lab.native_hooks = 0
                self.log('LAB_NATIVE_HOOKS_UNAVAILABLE', str(self.uc.library_path))
            else:
                enable()
                version = self.uc.lib.msd_lab_hooks_version
                version.restype = ctypes.c_uint32
                self.lab.native_hooks = version()
                self.log('LAB_NATIVE_HOOKS', self.lab.native_hooks, str(self.uc.library_path))
            from lab_menu_entry import LabMenuEntry
            self.menu_entry = LabMenuEntry(self, self.lab, ROOT)

        def filecall(self, name, a):
            # 敌方红色绝招光圈：LAB 以替换文件名 aurR.obm 构造第二个 BattleEffectRenderer，
            # 此处返回由 aura.obm 调色板换色得到的内存数据（贴图结构与原图一致）。
            if name == 'fopen':
                requested = self.string(a[0])
                if requested.replace('\\', '/').rsplit('/', 1)[-1] == 'aurR.obm':
                    handle = self.alloc(16)
                    self.handles[handle] = io.BytesIO(self.lab.red_aura_bytes())
                    self.log('LAB_RED_AURA_OPEN', requested)
                    return handle
                lab = getattr(self, 'lab', None)
                if lab is not None and lab.sandbox:
                    handle = self.sandbox_open(lab, requested, self.string(a[1]))
                    if handle is not None:
                        return handle
            return super().filecall(name, a)

        def sandbox_open(self, lab, requested, mode):
            """LAB 存档隔离（T9）：存档目录内的写入改写到 lab.virtual_files；已写过的文件读回虚拟内容。"""
            path = self.path(requested)
            if not path.is_relative_to(self.guest_root):
                return None
            key = str(path)
            writing = any(k in mode for k in 'wa+')
            if writing:
                initial = b''
                if not mode.startswith('w'):
                    initial = lab.virtual_files.get(key, path.read_bytes() if path.is_file() else b'')
                stream = VirtualFile(lab, key, initial, append=mode.startswith('a'))
                lab.virtual_write_count += 1
                self.log('LAB_SANDBOX_WRITE', key, mode)
            elif key in lab.virtual_files:
                stream = io.BytesIO(lab.virtual_files[key])
            else:
                return None
            handle = self.alloc(16)
            self.handles[handle] = stream
            return handle

        def touch_event(self, action, x, y):
            lab = getattr(self, 'lab', None)
            if lab is not None and (lab.menu.touch(action, x, y) or lab.prep.touch(action, x, y)):
                return
            entry = getattr(self, 'menu_entry', None)
            if entry is not None and entry.touch(action, x, y):
                return
            super().touch_event(action, x, y)

        def back(self):
            lab = getattr(self, 'lab', None)
            if lab is not None and lab.back():
                return True
            return super().back()

        def close(self):
            lab = getattr(self, 'lab', None)
            if lab is not None and lab.sandbox:
                lab.abort()
            entry = getattr(self, 'menu_entry', None)
            if entry is not None:
                entry.close()
            return super().close()

        def activate_unit_slot(self, slot):
            result = super().activate_unit_slot(slot)
            lab = getattr(self, 'lab', None)
            if lab is not None:
                lab.reveal_slot(False, slot)
            return result

        def step_frame(self):
            entry = getattr(self, 'menu_entry', None)
            if entry is not None:
                entry.prepare_frame()
            super().step_frame()
            lab = getattr(self, 'lab', None)
            if lab is None:
                return
            try:
                lab.update()
                if entry is not None:
                    entry.draw()
            except Exception as error:
                import traceback
                self.log('LAB_UPDATE_ERROR', type(error).__name__, str(error), traceback.format_exc())
                try:
                    lab.abort()
                except Exception:
                    pass
                lab.feedback(f'内部错误：{type(error).__name__}，详见 {Path(self.logfile.name).name}', False)

    class LabPlayer(player_class):
        lab_runtime_installed = True

        def key(self, window, key, scan, action, mods):
            lab = getattr(self.probe, 'lab', None) if self.probe else None
            if lab is not None and self.ready and action == glfw.PRESS and not mods & BLOCKED_MODS:
                # 战斗中菜单（T6）：Esc 打开/关闭；打开期间 ↑/↓/Enter 操作菜单，其余游戏按键不送入战斗。
                if key == glfw.KEY_ESCAPE and lab.active:
                    lab.commands.append(('menu',))
                    return
                if lab.prep.open:
                    # 准备界面（T8）：Esc 返回/关闭，F7 关闭；其余游戏按键不送入菜单场景。
                    if key == glfw.KEY_ESCAPE:
                        # 按键回调在窗口线程：只入队，由游戏线程执行（原生调用不得跨线程）。
                        lab.commands.append(('prep_key', 'escape'))
                    elif key == glfw.KEY_F7:
                        lab.commands.append(('prep',))
                    if key not in (glfw.KEY_F11, glfw.KEY_F12, glfw.KEY_F9):
                        return
                if lab.menu.open:
                    menu_keys = {glfw.KEY_UP: ('menu_move', -1), glfw.KEY_DOWN: ('menu_move', 1),
                                 glfw.KEY_ENTER: ('menu_select',), glfw.KEY_KP_ENTER: ('menu_select',)}
                    if key in menu_keys:
                        lab.commands.append(menu_keys[key])
                    if key not in (glfw.KEY_F11, glfw.KEY_F12, glfw.KEY_F9):
                        return
            command = KEYS.get(key)
            if command and action == glfw.PRESS and not mods & BLOCKED_MODS:
                lab = getattr(self.probe, 'lab', None) if self.probe else None
                if lab is not None and self.ready:
                    lab.commands.append(command)
                return
            super().key(window, key, scan, action, mods)

    if not getattr(probe_class, 'lab_runtime_installed', False):
        player.Probe = LabProbe
    if not getattr(player_class, 'lab_runtime_installed', False):
        player.Player = LabPlayer


def install_platform():
    import local_platform
    original = local_platform.handle_java_call
    if getattr(original, 'lab_runtime_installed', False):
        return

    def handle_java_call(p, method, arg):
        lab = getattr(p, 'lab', None)
        if lab is not None and lab.active and method[1] in (
                'sendDataTCP', 'sendDataUDP', 'startQuickGame', 'cancelRoom', 'setRoomVariant'):
            if not hasattr(p, 'lab_network_counts'):
                p.lab_network_counts = {}
            p.lab_network_counts[method[1]] = p.lab_network_counts.get(method[1], 0) + 1
            if p.lab_network_counts[method[1]] == 1:
                p.log('LAB_NETWORK_CALL_OMITTED', method[1])
            return True, 0
        return original(p, method, arg)

    handle_java_call.lab_runtime_installed = True
    local_platform.handle_java_call = handle_java_call


