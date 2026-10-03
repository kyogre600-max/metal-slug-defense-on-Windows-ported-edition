"""Historical map metadata with bounded markers and isolated Event results."""
import json,struct
HEADER=0x1ffed000
class NativeEventMap:
    def __init__(self,trial):
        self.t=trial;self.p=trial.p;self.tables={};self.active=False
        p=self.p
        manifest=json.loads((trial.root/'historical_events/native_maps.json').read_text(encoding='utf-8'));self.manifest=manifest
        for key,data in manifest['events'].items():
            records=[];indices=[];world_indices=[];names=[];worlds=[];by_index={}
            title=key.replace('_2015','').replace('_2016_current','').replace('_2016','').replace('_',' ').upper()
            for world in range(data['world_count']):
                area_ptrs=[]
                for area in (a for a in data['areas'] if a['world']==world):
                    a=area['area'];items=area['markers'];raw=bytearray.fromhex(area['raw_hex'])
                    if not 0<len(items)<=5:raise ValueError('Invalid Event marker count')
                    for slot in range(5):
                        pointer=0
                        if slot<len(items):
                            marker=items[slot];index=marker['index'];s=trial.data[key]['stages'][index]
                            virtual=(world+1)*1000+(a+1)*10+slot+1
                            menu=bytearray(p.read(trial.tables[key]['missions']+index*120,120));struct.pack_into('<I',menu,0,virtual)
                            marker_raw=bytes.fromhex(marker['raw_hex'])
                            if len(marker_raw)!=24 or marker['preview_frame']>32:raise ValueError('Invalid Event marker')
                            pointer=trial.blob(marker_raw)
                            maximum=marker['pow_max'] if area['prisoner_id']>=0 else 0
                            records.append(struct.pack('<16I',virtual,s['id'],trial.blob(bytes(menu)),0,0,a,slot,index,world,marker['bgm_id'],maximum,0,*([0]*4)))
                            indices.append((a,slot,index));world_indices.append((world,a,slot,index));by_index[index]=marker
                            names.append(trial.blob((f'{title} / {world+1}-{a+1}').encode()+b'\0'))
                        struct.pack_into('<I',raw,20+slot*4,pointer)
                    area_ptrs.append(trial.blob(bytes(raw)))
                if len(area_ptrs)>16:raise ValueError('Event world exceeds original area capacity')
                worlds.append(struct.pack('<3I',trial.blob(struct.pack('<'+'I'*len(area_ptrs),*area_ptrs)),len(area_ptrs),0))
            prisoners=[]
            for pid,reward in data['prisoners'].items():
                text_arrays=[]
                for field in ('names','info1','info2'):
                    text_arrays.append(trial.blob(struct.pack('<11I',*[trial.blob(text.encode('utf-8')+b'\0') for text in reward[field]])))
                prisoners.append(struct.pack('<5I',int(pid),trial.blob(bytes.fromhex(reward['raw_hex'])),*text_arrays))
            self.tables[key]={'worlds':trial.blob(b''.join(worlds)),'world_count':len(worlds),
                              'area_count':len(data['areas']),'records':trial.blob(b''.join(records)),
                              'count':len(records),'indices':indices,'world_indices':world_indices,'by_index':by_index,
                              'names':trial.blob(struct.pack('<'+'I'*len(names),*names)),
                              'prisoners':trial.blob(b''.join(prisoners)),'prisoner_count':len(prisoners)}
        table=p.symbols['MenuImageDataTbl'];locale=p.word(p.app_instance()+0x3d64)
        self.cat_descriptor=p.word(table+locale*4)+64*12
        self.cat_draw_task=trial.blob(b'\0'*(3*0x228))
    def enable(self):
        t=self.t;p=self.p;table=self.tables[t.selected];state=t.state();self.active=True
        p.put(HEADER+80,0);p.put(HEADER+36,t.app);bonuses=[]
        for world_type in (0,1):
            for world in range(3):
                for area in range(p.call('_Z10GetAreaNumi9WorldType',world,world_type)):
                    rate=p.call('_Z19GetAreaPrisonerRateii9WorldType',world,area,world_type)
                    bonuses.append(struct.pack('<4I',world,area,world_type,rate))
        p.put(HEADER+140,t.blob(b''.join(bonuses)));p.put(HEADER+144,len(bonuses))
        for i,(_,_,index) in enumerate(table['indices']):
            saved=state['stages'].get(t.data[t.selected]['stages'][index]['local_stage_key'],{})
            p.put(table['records']+i*64+12,int(saved.get('wins',0)>0));p.put(table['records']+i*64+16,saved.get('best_time',0))
            maximum=p.word(table['records']+i*64+40)
            p.put(table['records']+i*64+44,min(maximum,max(0,saved.get('captures',0))))
        for off,value in ((80,1),(88,table['area_count']),(92,table['records']),(96,table['count']),(100,table['names']),
                          (108,int(t.data[t.selected]['controller'] in ('legacy_survival','current_cooperation'))),(112,0),
                          (148,table['world_count']),(152,table['worlds']),(156,int(t.selected=='battle_cats_2015')),(164,0),
                          (168,table['prisoners']),(172,table['prisoner_count']),(176,int(self.has_prisoners(0))),
                          (180,0),(184,int(t.data[t.selected]['controller']=='parts')),(196,self.cat_draw_task)):
            p.put(HEADER+off,value)
    def has_prisoners(self,world):
        return any(a['world']==world and a['prisoner_id']>=0 and any(m['pow_max'] for m in a['markers'])
                   for a in self.manifest['events'][self.t.selected]['areas'])
    def disable(self):
        self.p.put(HEADER+80,0);self.p.put(HEADER+164,0);self.active=False
    def open(self,immediate=False):
        t=self.t
        if not immediate:return t.transition(lambda:self.open(True))
        p=self.p;app=t.app;self.enable();t.overlay=None
        p.call('_ZN7AppMain12SceneEndFuncEi',app,p.word(app+0x22bc))
        if t.selected=='battle_cats_2015':p.call('_ZN7AppMain15createMenuImageEiPK13ImageDataInfo',app,65,self.cat_descriptor)
        for off in (0xb1ec,0xb1f0,0xb1f4):p.put(app+off,0)
        p.put(app+0xc030,0);p.put(app+0xc034,0);p.call('_ZN7AppMain11ChangeExeSTEi',app,31)
        p.log('HISTORICAL_NATIVE_MAP',t.selected,self.tables[t.selected]['area_count'])
    def update(self):
        t=self.t;p=self.p;app=t.app;pending=p.word(HEADER+112)
        if self.active and not t.active_battle:
            p.put(HEADER+176,int(self.has_prisoners(p.word(app+0xb1ec))))
            if p.word(HEADER+180):
                p.put(HEADER+180,0);p.call('_ZN7AppMain12SceneEndFuncEi',app,p.word(app+0x22bc))
                p.call('_ZN7AppMain11ChangeExeSTEi',app,32)
        if pending:
            p.put(HEADER+112,0);index=pending-1;s=t.data[t.selected]['stages'][index]
            t.active_battle={'index':index,'stage':s,'key':t.selected,'native_map':True}
            p.call('_ZN7AppMain10Sound_LoadE7SoundID',app,self.tables[t.selected]['by_index'][index]['bgm_id'])
            p.call('_ZN7AppMain20Sound_RequestPlayBGME7SoundIDi',app,self.tables[t.selected]['by_index'][index]['bgm_id'],0)
            legacy=bool(p.word(HEADER+108));p.put(app+0xc8c8,5 if legacy else 3);p.put(app+0xc63c,3 if legacy else 1)
            if legacy:
                ex=p.call('_ZN10BattleInfo17getExSurvivalInfoEi',t.info,s['id']);p.put(app+0xb9a4,p.word(ex+8))
            p.log('HISTORICAL_NATIVE_MAP_BATTLE',t.selected,s['id'])
    def save_result(self,record,won,time):
        t=self.t;p=self.p;table=self.tables[t.selected];saved=t.state()['stages'][record['stage']['local_stage_key']]
        if won:saved['best_time']=min(saved.get('best_time') or time,time)
        for i,(world,a,slot,index) in enumerate(table['world_indices']):
            if index==record['index']:
                p.put(table['records']+i*64+12,int(saved['wins']>0));p.put(table['records']+i*64+16,saved.get('best_time',0))
                maximum=p.word(table['records']+i*64+40)
                saved['captures']=min(maximum,max(0,saved.get('captures',0)))
                p.put(table['records']+i*64+44,saved['captures'])
                return p.call('_Z12GetStageRankiii9WorldType',world,a,slot,0)
        raise ValueError('Historical stage absent from native map')
    def back(self,immediate=False):
        t=self.t
        if not immediate:return t.transition(lambda:self.back(True))
        p=self.p;self.disable();p.call('_ZN7AppMain12SceneEndFuncEi',t.app,p.word(t.app+0x22bc))
        p.put(t.app+0xc63c,4);p.put(t.app+0xc8c8,6);p.call('_ZN7AppMain23SC_WiFiMenuInit_TagTeamEv',t.app)
