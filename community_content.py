"""Register additive native content and persist its progress per save profile."""
from pathlib import Path
import json,struct,hashlib,io,os

HEADER=0x1ffee000
RECORD_SIZE=0x90
MAX_UNITS=64
UNIT_ID_BASE=1024
ORIGINAL_UNITS=400
LANGUAGES=frozenset(('EN','JP','KR','ES','PT','RU','FR','DE','IT','ZT','ZS'))
COMMAND_LENGTHS=(2,2,2,2,2,1,3,5,2,2,3,5,5,2,3,1,1,2,2,3,3,1,5,2)

def ratio(value):
    """解析整数或精确有理数倍率，保持既有注册表的整数格式。"""
    if isinstance(value,int) and not isinstance(value,bool):value=(value,1)
    if not isinstance(value,(list,tuple)) or len(value)!=2:raise ValueError('Invalid rational unit multiplier')
    a,b=value
    if any(not isinstance(v,int) or isinstance(v,bool) or not 0<v<=10000 for v in (a,b)) or a>100*b:raise ValueError('Invalid rational unit multiplier')
    return a,b

class CommunityContent:
    def __init__(self,p,root=None):
        self.p=p
        self.root=Path(root or Path(__file__).resolve().parent/'community_content')
        self.manifest=json.loads((self.root/'registry.json').read_text(encoding='utf-8'))
        if self.manifest.get('schema')!=2:raise ValueError('Unsupported community content schema')
        if self.manifest.get('unit_id_base')!=UNIT_ID_BASE:raise ValueError('Unsafe community unit namespace')
        self.units=self.manifest['units']
        if not 0<len(self.units)<=MAX_UNITS:raise ValueError('Community unit capacity exceeded')
        keys=set()
        for i,u in enumerate(self.units):
            if not isinstance(u['key'],str) or not u['key'] or '\0' in u['key']:raise ValueError('Invalid stable unit key')
            if u['id']!=UNIT_ID_BASE+i or u['key'] in keys:raise ValueError('Unstable or duplicate community unit identity')
            if not 0<u['base_id']<400:raise ValueError('Invalid original unit reference')
            if not u.get('available_from_start') and (not isinstance(u.get('shop_unlock_reference_id'),int) or not 0<=u['shop_unlock_reference_id']<512):raise ValueError('Invalid original shop unlock reference')
            if set(u['localization'])!=LANGUAGES:raise ValueError('All eleven unit localizations are required')
            if not 0<u['shop_price']<=32767 or not 0<u['ap']<=100000:raise ValueError('Unit price/AP outside supported range')
            if u['icon']['index']!=340+i:raise ValueError('Non-contiguous community icon identity')
            if u['icon']['page']!=1:raise ValueError('Community icons must use unit_icon_02')
            ratio(u['hp_multiplier'])
            if not isinstance(u['production_reference_id'],int) or not 0<u['production_reference_id']<400:raise ValueError('Invalid production reference unit')
            if u['faction'] not in range(5):raise ValueError('Invalid native faction filter')
            rect=u['icon']['rect'];anchor=u['icon']['anchor']
            if len(rect)!=4 or len(anchor)!=2 or any(not isinstance(v,int) or not -32768<=v<=32767 for v in [*rect,*anchor]):raise ValueError('Invalid icon geometry')
            if rect[0]<0 or rect[1]<0 or rect[2]<=0 or rect[3]<=0:raise ValueError('Invalid icon rectangle')
            for key in ('production_interval_multiplier','special_damage_multiplier','attack_wait_multiplier',
                        'damage_multiplier','move_speed_multiplier','attack_range_multiplier',
                        'knockback_distance_multiplier','ballistic_range_multiplier'):
                ratio(u.get(key,[1,1]))
            for text in u['localization'].values():
                if not isinstance(text['name'],str) or not isinstance(text['description'],str) or not text['name'] or not text['description'] or '\0' in text['name']+text['description']:raise ValueError('Invalid unit text')
            for commands in u['animations'].values():
                if not 0<len(commands)<=10000:raise ValueError('Animation command capacity exceeded')
                for cmd in commands:
                    opcode=cmd['opcode'];values=cmd['values']
                    if not isinstance(opcode,int) or not 0<=opcode<len(COMMAND_LENGTHS) or len(values)!=COMMAND_LENGTHS[opcode]-1:raise ValueError('Invalid animation command arity')
                    if any(not isinstance(v,int) or not -2147483648<=v<=2147483647 for v in values):raise ValueError('Invalid animation command value')
            keys.add(u['key'])
        self.assets={};self.asset_dimensions={}
        for name,digest in self.manifest['assets'].items():
            if Path(name).name!=name or not name.lower().endswith('.obm'):raise ValueError('Invalid content asset name')
            raw=(self.root/name).read_bytes()
            if hashlib.sha256(raw).hexdigest()!=digest:raise ValueError('Content asset checksum mismatch: '+name)
            if len(raw)<8 or raw[:2]!=b'OI':raise ValueError('Unsupported content texture header: '+name)
            width,height=struct.unpack_from('<HH',raw,4);kind,bits=raw[2:4]
            if kind==1 and bits==4:expected=8+64+(width*height+1)//2
            elif kind in (1,4) and bits==8:expected=8+(1024 if kind==1 else 512)+width*height
            elif kind in (0,1) and bits in (24,32):expected=8+width*height*(3 if kind==0 else 4)
            else:raise ValueError('Unsupported content texture format: '+name)
            if not 0<width<=8192 or not 0<height<=8192 or len(raw)!=expected:raise ValueError('Invalid content texture dimensions or byte count: '+name)
            self.asset_dimensions[name]=(width,height)
            self.assets[name]=raw
        for u in self.units:
            for name in u.get('textures',[u.get('texture')]):
                if name not in self.assets:raise ValueError('Unregistered unit texture')
            if 'unit_icon_02.obm' not in self.assets:raise ValueError('Missing community icon atlas')
            width,height=self.asset_dimensions['unit_icon_02.obm'];x,y,w,h=u['icon']['rect']
            if x+w>width or y+h>height:raise ValueError('Icon rectangle outside its atlas')
        from campaign_catalog import merge_scenes
        merge_scenes(self)
        import community_maps
        community_maps.validate(self.manifest,self.assets)
        self.overridden_assets=set()
        self.path=p.saves/'community_progress.json'
        self.progress=json.loads(self.path.read_text(encoding='utf-8')) if self.path.exists() else {'schema':1,'units':{}}
        if self.progress.get('schema')!=1:raise ValueError('Unsupported community progress schema')
        self.legacy_ids={}
        for i,u in enumerate(self.units):
            saved=self.progress['units'].get(u['key'],{})
            previous=saved.get('id',u['id'])
            if previous!=u['id']:
                if previous!=400+i:raise ValueError('Unsupported legacy unit identity')
                self.legacy_ids[previous]=u['id']
        self.deck_migration_done=not self.legacy_ids
        self.original_filecall=p.filecall
        def filecall(name,args):
            leaf=Path(p.string(args[0])).name if name=='fopen' else None
            if leaf in self.assets and p.string(args[1]).startswith('r'):
                self.overridden_assets.add(leaf)
                handle=p.alloc(16);p.handles[handle]=io.BytesIO(self.assets[leaf]);return handle
            return self.original_filecall(name,args)
        p.filecall=filecall
        self.original_host=p.host
        def host(a,size=1):
            # memset operates on the list's full allocation during rebuilding.
            if hasattr(self,'app') and a==self.app+0xb240:a=self.custom_list
            elif hasattr(self,'app') and a==self.app+0xb9d4:a=self.deck_list
            return self.original_host(a,size)
        p.host=host
        if not hasattr(p.uc.lib,'msd_community_unit_id_base') or p.uc.lib.msd_community_unit_id_base()!=UNIT_ID_BASE:raise RuntimeError('Native core lacks the separated community unit namespace')
        extended=any(isinstance(u['hp_multiplier'],list) or any(key in u for key in
            ('damage_multiplier','move_speed_multiplier','attack_range_multiplier','knockback_distance_multiplier','ballistic_range_multiplier')) for u in self.units)
        if extended and (not hasattr(p.uc.lib,'msd_community_combat_profile_version') or p.uc.lib.msd_community_combat_profile_version()!=1):raise RuntimeError('Native core lacks rational combat profiles')
        if any(not u['available_from_start'] for u in self.units) and (not hasattr(p.uc.lib,'msd_community_shop_gate_version') or p.uc.lib.msd_community_shop_gate_version()!=1):raise RuntimeError('Native core lacks original-shop unlock references')
        p.uc.lib.msd_enable_community_content()
        self.ready=False

    def alloc(self,raw):
        p=self.p;a=p.alloc(len(raw));p.write(a,bytes(raw));return a

    def replace_global(self,old,new):
        p=self.p;hits=[]
        # Global data and GOT references use relocated pointers, not code bytes.
        for section in p.elf.iter_sections():
            if section.name not in ('.got','.data','.data.rel.ro','.data.rel.ro.local','.bss'):continue
            start=0x10000000+section['sh_addr'];raw=p.read(start,section['sh_size'])
            for off in range(0,len(raw)-3,4):
                if struct.unpack_from('<I',raw,off)[0]==old:p.put(start+off,new);hits.append(start+off)
        if not hits:raise RuntimeError('Unresolved native global: '+hex(old))
        return hits

    def install(self):
        p=self.p;n=len(self.units);info=p.call('_ZN10BattleInfo11getInstanceEv');db=p.word(info)
        if p.word(db+8)!=400:raise RuntimeError('Unexpected original unit table size')
        base=p.word(db+4);original=p.read(base,400*0x390);rows=bytearray(original)+bytearray((UNIT_ID_BASE-400)*0x390)
        self.original_rows=hashlib.sha256(original).hexdigest()
        table=0x10922f28;original_images=p.read(table,423*8);images=bytearray(original_images)
        actions_global=0x109373f4;actions=p.word(actions_global);action_rows=bytearray(p.read(actions,400*4))+bytearray((UNIT_ID_BASE-400)*4)
        menu=(p.word(0x101652d0)+0x101652b4+0x818)&0xffffffff
        shopbase=(p.word(0x101655d8)+0x101655ce+0x19c)&0xffffffff
        language_table=p.symbols['strMenuUnitInfoTbl']
        language_order={p.word(language_table+i*4):i for i in range(11)}
        records=bytearray(n*RECORD_SIZE)
        for i,u in enumerate(self.units):
            uid=u['id'];bid=u['base_id'];row=bytearray(original[bid*0x390:(bid+1)*0x390])
            struct.pack_into('<I',row,0,uid)
            for off in (4,0xa8,0x12c,0x1b0,0x234,0x2b8):struct.pack_into('<i',row,off,u['ap'])
            # 有理数生命值在原生等级插值完成后缩放，避免中间等级的重复取整。
            if isinstance(u['hp_multiplier'],int):
                for off in (12,0xb0,0x134,0x1b8,0x23c,0x2c0):struct.pack_into('<i',row,off,struct.unpack_from('<i',row,off)[0]*u['hp_multiplier'])
            a,b=u['production_interval_multiplier'];ref=u['production_reference_id']
            for off in (8,0xac,0x130,0x1b4,0x238,0x2bc):
                v=struct.unpack_from('<i',original,ref*0x390+off)[0];struct.pack_into('<i',row,off,(v*a+b-1)//b)
            a,b=u['special_damage_multiplier']
            for off in (0x74,0xfc,0x180,0x204,0x288,0x30c):struct.pack_into('<i',row,off,struct.unpack_from('<i',row,off)[0]*a//b)
            # Native status IDs 24/31 map to status words 27/34.
            # These six anchors match getUnitStatus's level interpolation.
            # Production time and the special-readiness timer remain separate.
            a,b=u.get('attack_wait_multiplier',[1,1])
            for off in (0x6c,0xf8,0x17c,0x200,0x284,0x308,
                        0x88,0x110,0x194,0x218,0x29c,0x320):
                value=struct.unpack_from('<i',row,off)[0]
                struct.pack_into('<i',row,off,(value*a+b-1)//b)
            struct.pack_into('<i',row,0x378,u['faction']);rows+=row
            action_rows+=p.read(actions+bid*4,4)
            descriptor=p.word(table+bid*8);header=bytearray(p.read(descriptor,32))
            textures=u.get('textures',[u.get('texture')]);image_count=p.word(descriptor)
            if not 1<=image_count<=16 or len(textures)!=image_count:raise ValueError('Texture bindings must match the base unit atlas count')
            struct.pack_into('<I',header,4,self.alloc(struct.pack('<'+'I'*image_count,*[p.cstr(t) for t in textures])))
            count=p.word(descriptor+28);scripts=list(struct.unpack('<'+'I'*count,p.read(p.word(descriptor+24),count*4)))
            for key,commands in u['animations'].items():
                if not 0<=int(key)<count:raise ValueError('Animation index outside base unit descriptor')
                values=[v for cmd in commands for v in [cmd['opcode'],*cmd['values']]]
                scripts[int(key)]=self.alloc(struct.pack('<'+'i'*len(values),*values))
            struct.pack_into('<I',header,24,self.alloc(struct.pack('<'+'I'*count,*scripts)))
            images+=struct.pack('<II',self.alloc(header),p.word(table+bid*8+4))
            menurow=next(p.read(menu+j*20,20) for j in range(320) if p.word(menu+j*20)==bid)
            menurow=bytearray(menurow);struct.pack_into('<II',menurow,0,uid,uid)
            struct.pack_into('<h',menurow,8,u['faction']);struct.pack_into('<h',menurow,10,u['icon']['index'])
            shoprow=bytearray(p.read(shopbase+23*32,32));struct.pack_into('<H',shoprow,0,512+i)
            struct.pack_into('<I',shoprow,4,uid);struct.pack_into('<h',shoprow,16,u['shop_price'])
            data=self.progress['units'].get(u['key'],{})
            level=int(data.get('level',-1));opened=int(data.get('level_open',40))
            if not -1<=level<=39 or not 0<=opened<=40:raise ValueError('Invalid community unit progress')
            values=(uid,bid,512+i,self.alloc(menurow),self.alloc(shoprow),423+i,level&0xffffffff,opened,int(data.get('custom_time',0)),int(data.get('new',0)),int(data.get('shop_new',0)),u['shop_price'])
            struct.pack_into('<12I',records,i*RECORD_SIZE,*values)
            struct.pack_into('<I',records,i*RECORD_SIZE+0x88,int(data.get('deck_time',0)))
            for code,text in u['localization'].items():
                lang=language_order[p.symbols['strMenuUnitInfo'+code]]
                for offset,field in ((0x30,'name'),(0x5c,'description')):struct.pack_into('<I',records,i*RECORD_SIZE+offset+lang*4,p.cstr(text[field]))
        self.records=self.alloc(records);p.put(db+4,self.alloc(rows));p.put(db+8,UNIT_ID_BASE+n)
        p.put(actions_global,self.alloc(action_rows));imageptr=self.alloc(images)
        factory=p.call('_ZN19BattleSpriteFactory11getInstanceEv');cache=p.word(factory+0xe108)
        p.put(factory+0xe108,self.alloc(p.read(cache,423*4)+bytes(n*4)))
        # Stock UI sprites remain independent; custom IDs need additional cells.
        # Custom uses fifty visible panels; Deck uses ten slots. Main-menu and
        # shop preview caches are indexed by UID and require sparse allocation.
        for name in ('m_MainMenuObject','m_MenuShopBattleObject'):
            if name not in p.symbols:raise RuntimeError('Missing native UID preview cache: '+name)
            old=p.symbols[name]
            size=next(s['st_size'] for s in p.elf.get_section_by_name('.dynsym').iter_symbols() if s.name==name)
            if size!=ORIGINAL_UNITS*4:raise RuntimeError('Unexpected native UI pointer array size: '+name)
            self.replace_global(old,self.alloc(p.read(old,size)+bytes((UNIT_ID_BASE+n)*4-size)))
        # Append icon rectangles; keep all 340 original entries unchanged.
        conv=p.symbols['ConvUnitIcon'];rects=bytearray(p.read(conv,340*16))
        battle_icons=bytearray()
        for u in self.units:
            ic=u['icon'];rect=struct.pack('<8h',*ic['rect'],*ic['anchor'],0,ic['page']);rects+=rect;battle_icons+=rect
        self.icon_references=self.replace_global(conv,self.alloc(rects))
        p.log('COMMUNITY_ICON_REFERENCES',[(hex(a),p.read(a-8,24).hex()) for a in self.icon_references])
        # Each menu picture also has an action-offset map and a terminated
        # rectangle script. Extending rectangles alone leaves ID 340 blank.
        offsets=bytearray(p.read(0x10305fcc,340*2));icon_scripts=bytearray(p.read(0x10305a7c,340*4))
        for i in range(n):
            offsets+=struct.pack('<H',(340+i)*2)
            icon_scripts+=struct.pack('<hh',340+i,-1)
        self.icon_offsets=self.alloc(offsets);self.icon_scripts=self.alloc(icon_scripts)
        # Obtain the native unit-shop list's PC-relative root.
        # The add-PC at 0x20bb9c uses the literal at 0x20bee4.
        catalog_base=(p.word(0x1020bee4)+0x1020bba0)&0xffffffff
        self.catalog_source=catalog_base
        catalog=p.read(catalog_base+0x74,259*4)
        self.shop_catalog=self.alloc(catalog+struct.pack('<'+'I'*n,*range(512,512+n)))
        self.app=p.app_instance();self.custom_list=self.alloc(bytes(512*4));self.deck_list=self.alloc(bytes(512*4))
        import community_maps
        stage_pointer,stage_count,mission_count=community_maps.install(self,info,db)
        fields=(0x434f4d32,n,self.records,UNIT_ID_BASE+n,423+n,imageptr,0,self.app,self.custom_list,self.deck_list,512,self.shop_catalog,259+n,self.alloc(battle_icons),self.icon_offsets,self.icon_scripts,stage_pointer,stage_count,mission_count)
        profiles=bytearray()
        for u in self.units:
            values=[ratio(u['hp_multiplier']) if isinstance(u['hp_multiplier'],list) else (1,1)]
            values.extend(ratio(u.get(key,[1,1])) for key in ('damage_multiplier','move_speed_multiplier',
                'attack_range_multiplier','knockback_distance_multiplier','ballistic_range_multiplier'))
            profiles+=struct.pack('<12I',*(v for pair in values for v in pair))
        unlocks=struct.pack('<'+'I'*n,*(0xffffffff if u['available_from_start'] else u['shop_unlock_reference_id'] for u in self.units))
        fields+= (self.alloc(profiles),1,p.symbols['_ZTV10BattleUnit']+8,p.symbols['_ZTV12BattleBullet']+8,self.alloc(unlocks))
        p.write(HEADER,struct.pack('<24I',*fields));self.ready=True
        self.map_initial_choices_applied=not (self.manifest.get('missions') or self.manifest.get('campaign_choices'))
        assert p.read(p.word(db+4),400*0x390)==original
        p.log('COMMUNITY_REGISTERED',n,'unit IDs',[u['id'] for u in self.units])

    def flush(self):
        p=self.p
        if self.ready and not self.deck_migration_done and p.word(self.app+0x22bc)==28:
            self.migrate_legacy_decks()
        if self.ready and not self.map_initial_choices_applied and p.word(self.app+0x22bc)==28:
            import community_maps
            community_maps.enable_initial_choices(self);self.map_initial_choices_applied=True
        if not self.ready or not p.word(HEADER+24):return
        for i,u in enumerate(self.units):
            values=struct.unpack('<5I',p.read(self.records+i*RECORD_SIZE+24,20))
            self.progress['units'][u['key']]={'id':u['id'],'level':struct.unpack('<i',struct.pack('<I',values[0]))[0],
             'level_open':values[1],'custom_time':values[2],'new':values[3],'shop_new':values[4],
             'deck_time':p.word(self.records+i*RECORD_SIZE+0x88)}
        temporary=self.path.with_suffix('.json.tmp')
        with temporary.open('w',encoding='utf-8') as stream:
            json.dump(self.progress,stream,ensure_ascii=False,indent=2);stream.flush();os.fsync(stream.fileno())
        os.replace(temporary,self.path);p.put(HEADER+24,0)

    def migrate_legacy_decks(self):
        # Migrate only in-memory loaded decks; ordinary game saves persist them.
        # The original test.dat and sidecar are never rewritten by an installer.
        p=self.p;changed=[]
        for deck in range(3):
            for slot in range(10):
                old=p.call('_ZN7AppMain19GetDeckUnitSaveDataEii',self.app,slot,deck)
                if old in self.legacy_ids:
                    new=self.legacy_ids[old]
                    p.call('_ZN7AppMain19SetDeckUnitSaveDataEi6UnitIDi',self.app,slot,new,deck)
                    changed.append({'deck':deck,'slot':slot,'old':old,'new':new})
        self.deck_migration_done=True
        p.put(HEADER+24,1)
        p.log('COMMUNITY_LEGACY_DECK_MIGRATION',changed)
