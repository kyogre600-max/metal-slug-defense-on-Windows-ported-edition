"""Event selection through the original scrollable Mission menu tasks."""
import struct
from event_native_map import HEADER

class NativeEventSelector:
    def __init__(self,trial):
        self.t=trial;self.p=trial.p;self.active=False
        p=self.p;template=p.read(p.call('_ZN10BattleInfo16getExMissionInfoEi',trial.info,0),112)
        rows=[]
        for i,e in enumerate(trial.catalog):
            row=bytearray(template);struct.pack_into('<II',row,0,20001+i,0);rows.append(bytes(row))
        self.rows=trial.blob(b''.join(rows))

    def open(self,immediate=False):
        if not immediate:return self.t.transition(lambda:self.open(True))
        t=self.t;p=self.p;app=t.app or p.app_instance();t.app=app
        if t.active_battle:raise RuntimeError('Cannot select another Event during battle')
        t.native_map.disable();t.overlay=None;p.put(HEADER+8,0);t.native_shop_active=False
        p.put(HEADER,0x45565431);p.put(HEADER+124,1);p.put(HEADER+128,self.rows)
        p.put(HEADER+132,len(t.catalog));p.put(HEADER+136,0);self.active=True
        p.call('_ZN7AppMain12SceneEndFuncEi',app,p.word(app+0x22bc))
        p.put(app+0xc46c,0);p.put(app+0xc604,0);p.put(app+0xc608,0)
        p.call('_ZN7AppMain19SC_MissionMenuInit2Ev',app)
        p.call('_ZN7AppMain17OpenMissionWindowEv',app)
        self.labels_ready=False

    def set_labels(self):
        t=self.t;p=self.p;app=t.app
        # TexString receives each label with the same task-local string index
        # used by the original Mission renderer.
        tex=p.word(app+0x3238);font=p.word(app+0x60)
        for i,e in enumerate(t.catalog):
            task=p.word(app+0x337c+i*4)
            if task:
                label={'sleeping_gigantic_weapon_2015':'SLEEPING GIANT'}.get(e['event_key'],
                      e['event_key'].replace('_2015','').replace('_2016_current','').replace('_2016','').replace('_',' ').upper())
                p.call('_ZN9TexString13setStringCharEPKcPiP4Fontb',tex,p.cstr(label),task+0x1f8,font,0)
        p.put(app+0xc604,0)
        p.call('_ZN19TouchManagerScrollY10setScrollYEi',p.word(app+0x88),0)
        self.labels_ready=True
        p.log('HISTORICAL_NATIVE_EVENT_SELECTOR',len(t.catalog))

    def disable(self):
        self.p.put(HEADER+124,0);self.active=False

    def update(self):
        if not self.active:return
        if not self.labels_ready and self.p.word(self.t.app+0x22dc)==6:self.set_labels()
        chosen=self.p.word(HEADER+136)
        if chosen:
            self.p.put(HEADER+136,0);self.disable()
            self.t.select(self.t.catalog[chosen-1]['event_key'],True)

    def back(self):
        self.t.leave()
