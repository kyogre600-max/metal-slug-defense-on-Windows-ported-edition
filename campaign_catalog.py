"""世界、区域、战场与敌军配置的版本化内容契约。"""
from pathlib import Path
import json,hashlib,re,struct,math

def stable_key(value):
    if not isinstance(value,str) or not re.fullmatch(r'[a-zA-Z0-9_.-]{1,120}',value):
        raise ValueError('内容键仅允许字母、数字、下划线、点和连字符')
    return value

def integer(value,low,high):
    if type(value) is not int or not low<=value<=high:raise ValueError('整数配置超出范围')
    return value

class Catalog:
    def __init__(self,root,units):
        self.root=Path(root);self.path=self.root/'catalog.json'
        self.raw=json.loads(self.path.read_text(encoding='utf-8')) if self.path.exists() else {'schema':1,'assets':{},'scenes':[],'music':[],'worlds':[]}
        if self.raw.get('schema')!=1:raise ValueError('未知世界目录版本')
        self.units={u['key']:u['id'] for u in units};self.assets={};self.keys=set(self.units)
        for name,digest in self.raw.get('assets',{}).items():
            if Path(name).name!=name or '\\' in name or name in ('.','..'):raise ValueError('资源要求独立文件名')
            if Path(name).suffix not in ('.obm','.msdf'):raise ValueError('运行资源要求 .obm 或 .msdf 文件')
            raw=(self.root/name).read_bytes()
            if hashlib.sha256(raw).hexdigest()!=digest:raise ValueError('资源校验值不一致：'+name)
            if len(raw)>64*1024*1024:raise ValueError('单个资源超过 64 MiB')
            self.assets[name]=raw
        if sum(map(len,self.assets.values()))>512*1024*1024:raise ValueError('目录资源合计超过 512 MiB')
        self.scenes=self.index('scenes');self.music=self.index('music');self.worlds=self.index('worlds')
        if len(self.scenes)>4096:raise ValueError('当前场景容量为 4096')
        for scene in self.scenes.values():
            integer(scene.get('base_id',0),0,137)
            if scene.get('texture') not in self.assets or not scene['texture'].endswith('.obm'):raise ValueError('场景缺少已登记 OBM')
            raw=self.assets[scene['texture']]
            if len(raw)<8 or raw[:2]!=b'OI':raise ValueError('无效场景图集')
            w,h=struct.unpack_from('<HH',raw,4);kind,bits=raw[2:4]
            if kind==1 and bits==4:expected=72+(w*h+1)//2
            elif kind in (1,4) and bits==8:expected=8+(1024 if kind==1 else 512)+w*h
            elif kind in (0,1) and bits in (24,32):expected=8+w*h*(3 if kind==0 else 4)
            else:raise ValueError('无效 OBM 格式')
            if not 0<w<=8192 or not 0<h<=8192 or len(raw)!=expected:raise ValueError('场景图集尺寸或字节数不符合约定')
            if w&(w-1) or h&(h-1):raise ValueError('场景运行图集要求二的整数次幂画布；PNG 导入工具可补充透明边缘')
            if 'graphics' in scene:
                if scene.get('base_id',0)!=0:raise ValueError('自定义图块使用基础场景 0')
                graphics=scene['graphics'];rects=graphics['rects']
                if not 0<len(rects)<=4096:raise ValueError('图块数量超出范围')
                for rect in rects:
                    if len(rect)!=8:raise ValueError('图块要求八个 int16 字段')
                    for v in rect:integer(v,-32768,32767)
                    x,y,rw,rh=rect[:4]
                    if min(x,y)<0 or min(rw,rh)<=0 or x+rw>w or y+rh>h:raise ValueError('图块超出图集边界')
                for name in ('back','front'):
                    layers=graphics.get(name,[])
                    if len(layers)>64:raise ValueError('场景图层数量超出范围')
                    for frames in layers:
                        if not 0<len(frames)<=1024:raise ValueError('场景动画帧数超出范围')
                        for v in frames:integer(v,0,len(rects)-1)
            if any(name in scene for name in ('terrain','bases')) and 'bounds' not in scene:raise ValueError('地形与基地位置配置需要战场边界')
            if 'bounds' in scene:
                left,right=scene['bounds'];integer(left,0,10000);integer(right,left+100,20000)
                points=scene.get('terrain',[[0,0],[2*(right-left),0]])
                if len(points)<2 or points[0][0]!=0 or points[-1][0]!=2*(right-left):raise ValueError('地形需覆盖完整战场宽度')
                last=-1
                for x,y in points:
                    integer(x,last+1,40000);integer(y,-1000,1000);last=x
                bases=scene.get('bases',[min(68,(right-left)//4),right-left-47])
                if len(bases)!=2:raise ValueError('战场需要两端基地位置')
                for x in bases:integer(x,0,right-left)
                if bases[0]>=bases[1]:raise ValueError('基地位置顺序无效')
        for music in self.music.values():
            if music.get('file') not in self.assets or not music['file'].endswith('.msdf') or not self.assets[music['file']].startswith(b'OggS'):
                raise ValueError('音乐要求包含 Vorbis 数据的 .msdf 文件')
            integer(music.get('base_sound_id',100),1,1030)
            start,end=music.get('loop_start',0),music.get('loop_end',0)
            if any(type(v) not in (int,float) or not math.isfinite(v) or v<0 for v in (start,end)) or end and end<=start:
                raise ValueError('音乐循环时间范围无效')
        self.stages={};self.locations={};self.areas={}
        for world in self.worlds.values():
            self.title(world)
            for area in world.get('areas',[]):
                self.identity(area);self.title(area)
                self.areas[area['key']]=area
                for stage in area.get('stages',[]):
                    self.identity(stage);self.title(stage)
                    if stage.get('scene') not in self.scenes and not isinstance(stage.get('scene'),int):raise ValueError('未登记战场')
                    if isinstance(stage.get('scene'),int):integer(stage['scene'],0,137)
                    music=stage.get('music',100)
                    if type(music) is int:integer(music,1,1030)
                    elif music not in self.music:raise ValueError('未登记音乐')
                    integer(stage.get('template',1011),1,999999)
                    if type(stage.get('enemy_specials',True)) is not bool:raise ValueError('敌军绝招选项要求布尔值')
                    for name,default,low,high in [('stamina',0,0,1000),('reward_msp',0,0,999999),('enemy_base_hp',10000,1,100000000),('strength_steps',0,0,100)]:
                        integer(stage.get(name,default),low,high)
                    enemies=stage.get('enemies',[])
                    if not 0<len(enemies)<=32:raise ValueError('敌军名单要求 1–32 个条目')
                    for enemy in enemies:
                        self.unit_id(enemy['unit']);integer(enemy.get('level',40),1,200)
                    previous=-1
                    for wave in stage.get('waves',[]):
                        integer(wave['tick'],previous+1,32766);previous=wave['tick']
                        integer(wave['enemy'],0,len(enemies)-1)
                    if len(stage.get('waves',[]))>8192:raise ValueError('出击波次超过 8192')
                    rewards=stage.get('reward_units',[])
                    for unit in rewards:self.unit_id(unit)
                    self.stages[stage['key']]=stage;self.locations[stage['key']]=(world['key'],area['key'])
        if len(self.stages)>100000:raise ValueError('当前目录容量为 100000 条关卡')
        for item in [*self.worlds.values(),*(a for w in self.worlds.values() for a in w.get('areas',[])),*self.stages.values()]:
            for key in item.get('requires',[]):
                if key not in self.stages:raise ValueError('解锁条件引用未登记关卡')
        # 解锁图的环会导致无法取得初始通关条件。
        from collections import deque
        effective={}
        for key,s in self.stages.items():
            world_key,area_key=self.locations[key];world=self.worlds[world_key]
            area=self.areas[area_key]
            effective[key]=[*world.get('requires',[]),*area.get('requires',[]),*s.get('requires',[])]
        pending={key:len(reqs) for key,reqs in effective.items()};followers={key:[] for key in self.stages}
        for key,reqs in effective.items():
            for req in reqs:followers[req].append(key)
        queue=deque(key for key,count in pending.items() if not count);visited=0
        while queue:
            key=queue.popleft();visited+=1
            for follower in followers[key]:
                pending[follower]-=1
                if not pending[follower]:queue.append(follower)
        if visited!=len(self.stages):raise ValueError('解锁条件存在循环')
        self.fingerprint=hashlib.sha256(json.dumps(self.raw,sort_keys=True,separators=(',',':'),ensure_ascii=False).encode()).hexdigest()
    def identity(self,row):
        key=stable_key(row['key'])
        if key in self.keys:raise ValueError('内容键重复：'+key)
        self.keys.add(key)
    def index(self,name):
        result={}
        for row in self.raw.get(name,[]):self.identity(row);result[row['key']]=row
        return result
    def title(self,row):
        if not isinstance(row.get('title'),str) or not row['title'] or '\0' in row['title']:raise ValueError('标题应为有效文本')
    def unit_id(self,key):
        if type(key) is int:return integer(key,1,399)
        if key not in self.units:raise ValueError('未登记社区单位：'+str(key))
        return self.units[key]

def merge_scenes(content):
    catalog=Catalog(content.root.parent/'campaign_content',content.units)
    content.campaign_catalog=catalog
    for name in catalog.assets:
        if name in content.p.asset_cache.safe_names:raise ValueError('新增场景或音乐与原生资源文件名冲突：'+name)
    scenes=content.manifest.setdefault('stages',[])
    for scene in catalog.scenes.values():
        row=dict(scene);row['id']=138+len(scenes);row.setdefault('base_id',0);scenes.append(row)
    for name,raw in catalog.assets.items():
        if not name.endswith('.obm'):continue
        if name in content.assets and content.assets[name]!=raw:raise ValueError('社区资源与场景资源文件名冲突')
        content.assets[name]=raw;content.asset_dimensions[name]=struct.unpack_from('<HH',raw,4)
