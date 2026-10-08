"""宿主受理的原生底栏按钮的按压保持（核心 LAB 钩子 17，src/lab_hooks.cpp cockpit_push）。

原生 GT_CockpitButton 每帧经 PushPanel 依触点重算按压字段；宿主拦截触点时，登记的任务跳过
PushPanel，保持原生青色框与三灯（+0x174=1），且不产生原生选择。登记随场景切换自动解除，
避免任务释放后地址被其他按钮复用。
"""
HOLD_HEADER = 0x1ffef040
HOLD_MAGIC = 0x444c4f48
SLOTS = 4


class CockpitHold:
    def __init__(self, probe):
        self.p = probe
        self.tasks = {}                 # task -> 登记时的场景
        self.enabled = False

    def available(self):
        lab = getattr(self.p, 'lab', None)
        return bool(lab and getattr(lab, 'native_hooks', 0) >= 17)

    def write(self):
        p = self.p
        tasks = list(self.tasks)[:SLOTS]
        for i in range(SLOTS):
            p.put(HOLD_HEADER + 4 + i * 4, tasks[i] if i < len(tasks) else 0)
        p.put(HOLD_HEADER, HOLD_MAGIC if tasks else 0)

    def hold(self, task):
        if not task:
            return
        app = self.p.app_instance()
        self.tasks[task] = self.p.word(app + 0x22bc)
        self.p.put(task + 0x174, 1)
        if self.available():
            self.write()

    def release(self, task):
        if task in self.tasks:
            del self.tasks[task]
            self.p.put(task + 0x174, 0)
            if self.available():
                self.write()

    def tick(self):
        """场景改变后解除全部登记（任务已由场景结束流程释放）。"""
        if not self.tasks:
            return
        scene = self.p.word(self.p.app_instance() + 0x22bc)
        stale = [task for task, held in self.tasks.items() if held != scene]
        if stale:
            for task in stale:
                del self.tasks[task]
            if self.available():
                self.write()


def instance(probe):
    hold = getattr(probe, 'cockpit_hold', None)
    if hold is None:
        hold = probe.cockpit_hold = CockpitHold(probe)
    return hold
