"""Additive stage and Mission adapters retaining stock terrain and objectives.

Additional world types require a separate carousel and progress adapter.
"""
import struct

MAX_STAGES=4096
MAX_MISSIONS=5
STAGE_ID_BASE=138
MISSION_INDEX_BASE=195
MISSION_ID_BASE=20196

def validate(manifest,assets):
 """Validate additive identities and save bounds before changing native tables."""
 if manifest.get('worlds'):raise ValueError('Additional worlds require a world selector and save adapter')
 lists={name:manifest.get(name,[]) for name in ('stages','missions','campaign_choices')}
 if any(not isinstance(value,list) for value in lists.values()):raise ValueError('Map registries must be lists')
 stages=lists['stages'];missions=lists['missions'];campaign=lists['campaign_choices']
 if len(stages)>MAX_STAGES or len(missions)>MAX_MISSIONS:raise ValueError('Stage/Mission registry capacity exceeded')
 if len(campaign)>1:raise ValueError('This campaign adapter accepts one reserved marker')
 keys={u['key'] for u in manifest['units']}
 def identity(row):
  key=row.get('key')
  if not isinstance(key,str) or not key or '\0' in key or key in keys:raise ValueError('Invalid or duplicate map content key')
  keys.add(key)
  if 'available_from_start' in row and type(row['available_from_start']) is not bool:raise ValueError('Map availability must be boolean')
 def integer(row,key,low,high):
  value=row.get(key)
  if type(value) is not int or not low<=value<=high:raise ValueError('Invalid map integer: '+key)
  return value
 stage_ids=set()
 for i,s in enumerate(stages):
  identity(s)
  if integer(s,'id',STAGE_ID_BASE,STAGE_ID_BASE+MAX_STAGES-1)!=STAGE_ID_BASE+i:raise ValueError('Stage IDs must be contiguous')
  integer(s,'base_id',0,STAGE_ID_BASE-1)
  if s.get('texture') not in assets:raise ValueError('Unregistered stage texture')
  stage_ids.add(s['id'])
 for c in campaign:
  identity(c)
  if any(type(c.get(k)) is not int for k in ('world','area','slot','id')) or (c['world'],c['area'],c['slot'],c['id'])!=(0,0,4,1015):raise ValueError('Campaign topology needs an explicit area adapter')
  if c.get('stage_id') not in stage_ids:raise ValueError('Unregistered campaign stage')
  integer(c,'reward_msp',0,2147483647);integer(c,'stamina_cost',0,2147483647)
  position=c.get('position')
  if not isinstance(position,list) or len(position)!=2 or any(type(v) is not int or not -32768<=v<=32767 for v in position):raise ValueError('Invalid campaign marker position')
  if 'base_mission_id' in c:integer(c,'base_mission_id',1,2147483647)
 for i,m in enumerate(missions):
  identity(m)
  if integer(m,'index',MISSION_INDEX_BASE,MISSION_INDEX_BASE+MAX_MISSIONS-1)!=MISSION_INDEX_BASE+i or integer(m,'id',MISSION_ID_BASE,MISSION_ID_BASE+MAX_MISSIONS-1)!=MISSION_ID_BASE+i:raise ValueError('Mission identities must be contiguous')
  integer(m,'base_index',0,MISSION_INDEX_BASE-1)
  if m.get('stage_id') not in stage_ids:raise ValueError('Unregistered Mission stage')
  integer(m,'reward_medals',0,2147483647);integer(m,'reward_msp',0,2147483647)

def install(content,info,db):
 p=content.p;manifest=content.manifest;alloc=content.alloc
 validate(manifest,content.assets)
 if manifest.get('worlds'):raise ValueError('Additional worlds require a world selector and save adapter')
 stages=manifest.get('stages',[]);missions=manifest.get('missions',[]);campaign=manifest.get('campaign_choices',[])
 if len(stages)>MAX_STAGES or len(missions)>5:raise ValueError('Stage/Mission registry capacity exceeded')
 records=bytearray();stage_count=p.word(db+0x10)
 if stage_count!=138:raise RuntimeError('Unexpected original stage count')
 ctor_global=(p.word(0x101e1c10)+0x101e1bd8)&0xffffffff
 ctor=p.word(ctor_global);ctors=bytearray(p.read(ctor,138*4))
 base=p.word(db+0xc);old=p.read(base,138*0x1c);rows=bytearray(old)
 graphics=(p.word(0x101e1c14)+0x101e1bf8)&0xffffffff
 for i,s in enumerate(stages):
  if s['id']!=138+i or not 0<=s['base_id']<138 or s['texture'] not in content.assets:raise ValueError('Invalid stage registry entry')
  bid=s['base_id'];row=bytearray(old[bid*0x1c:(bid+1)*0x1c])
  struct.pack_into('<II',row,0,s['id'],p.cstr(s['texture']))
  if 'bounds' in s:
   left,right=s['bounds'];points=s.get('terrain',[[0,0],[2*(right-left),0]])
   struct.pack_into('<iii',row,8,left,right,alloc(b''.join(struct.pack('<ii',*point) for point in points)))
   bases=s.get('bases',[min(68,(right-left)//4),right-left-47])
   struct.pack_into('<ii',row,20,*bases)
  rows+=row
  ctors+=p.read(ctor+bid*4,4)
  if 'graphics' in s:
   g=s['graphics']
   rects=alloc(b''.join(struct.pack('<8h',*rect) for rect in g['rects']))
   layer_ptrs=[]
   for name in ('back','front'):
    layers=[alloc(struct.pack('<'+'I'*(len(frames)+1),len(frames),*frames)) for frames in g.get(name,[])]
    layer_ptrs.append(alloc(struct.pack('<'+'I'*(len(layers)+1),*layers,0)))
   graphic=alloc(struct.pack('<3I',*layer_ptrs,rects))
  else:graphic=alloc(p.read(graphics+bid*12,12))
  records+=struct.pack('<II',s['id'],graphic)
 if stages:
  p.put(db+0xc,alloc(rows));p.put(db+0x10,138+len(stages));p.put(ctor_global,alloc(ctors))
  assert p.read(p.word(db+0xc),len(old))==old
 # A first campaign adapter exercises the original area's reserved fifth
 # marker. Larger regions/worlds fail validation until explicitly adapted.
 groups=p.word(db+0x14)
 if len(campaign)>1:raise ValueError('This campaign adapter accepts one reserved marker')
 for c in campaign:
  if (c['world'],c['area'],c['slot'])!=(0,0,4) or c['id']!=1015:raise ValueError('Campaign topology needs an explicit area adapter')
  if c['stage_id'] not in [s['id'] for s in stages]:raise ValueError('Unregistered campaign stage')
  area=p.call('_Z11GetAreaDataii9WorldType',0,0,0)
  if struct.unpack('<H',p.read(area+0x12,2))[0]!=4 or p.word(area+0x24):raise ValueError('Campaign marker conflicts with original content')
  base=p.word(groups);count=p.word(groups+4);old=p.read(base,count*0x78)
  source=p.call('_ZN10BattleInfo14getMissionInfoEi',info,c.get('base_mission_id',1011))
  if not source:raise ValueError('Campaign mission template does not exist')
  row=bytearray(p.read(source,0x78))
  struct.pack_into('<II',row,0,1015,c['stage_id']);struct.pack_into('<I',row,0x18,c['reward_msp']);struct.pack_into('<I',row,0x20,c['stamina_cost'])
  p.put(groups,alloc(old+row));p.put(groups+4,count+1)
  marker=bytearray(p.read(p.call('_Z12GetStageDataiii9WorldType',0,0,0,0),24))
  struct.pack_into('<ii',marker,0,*c['position']);p.put(area+0x24,alloc(marker));p.write(area+0x12,struct.pack('<H',5))
  assert p.read(p.word(groups),len(old))==old
 if p.word(db+0x1c)!=195:raise RuntimeError('Unexpected original Mission count')
 exbase=p.word(db+0x18);oldex=p.read(exbase,195*0x70);exrows=bytearray(oldex)
 group=groups+6*8;normalbase=p.word(group);normalcount=p.word(group+4);oldnormal=p.read(normalbase,normalcount*0x78);normalrows=bytearray(oldnormal)
 for i,m in enumerate(missions):
  if m['index']!=195+i or m['id']!=20196+i or not 0<=m['base_index']<195:raise ValueError('Invalid Mission registry identity')
  if m['stage_id'] not in [s['id'] for s in stages]:raise ValueError('Unregistered Mission stage')
  row=bytearray(oldex[m['base_index']*0x70:(m['base_index']+1)*0x70])
  # +4 is the deck limit, +12 the timer. Preserve both cloned objectives.
  # First-clear rewards occupy three (type, quantity) pairs at +0x10.
  struct.pack_into('<I',row,0,m['id'])
  struct.pack_into('<6I',row,0x10,2 if m['reward_medals'] else 0,m['reward_medals'],0,0,0,0);exrows+=row
  source=p.call('_ZN10BattleInfo14getMissionInfoEi',info,20001+m['base_index'])
  row=bytearray(p.read(source,0x78));struct.pack_into('<II',row,0,m['id'],m['stage_id']);struct.pack_into('<I',row,0x18,m['reward_msp']);normalrows+=row
 if missions:
  p.put(db+0x18,alloc(exrows));p.put(db+0x1c,195+len(missions));p.put(group,alloc(normalrows));p.put(group+4,normalcount+len(missions))
  assert p.read(p.word(db+0x18),len(oldex))==oldex
  assert p.read(p.word(group),len(oldnormal))==oldnormal
 return alloc(records),len(stages),195+len(missions)

def enable_initial_choices(content):
 """Apply unlocks after the original profile has been read, on the first menu."""
 p=content.p;app=p.app_instance()
 for c in content.manifest.get('campaign_choices',[]):
  if c.get('available_from_start'):p.call('_ZN7AppMain22AddStageEnableSaveDataEiii9WorldType',app,c['area'],0,c['slot'],c['world'])
 for m in content.manifest.get('missions',[]):
  if m.get('available_from_start'):p.call('_ZN7AppMain24AddMissionEnableSaveDataEi',app,m['index'])
