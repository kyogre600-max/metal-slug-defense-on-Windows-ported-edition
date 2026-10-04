"""依据原版普通世界主线通关位登记玩家升级条件。"""
import struct
HEADER=0x1ffe9000
MAGIC=0x57474c31

class WorldLevelRules:
    def __init__(self,p):
        self.p=p;self.stages=[]
        if not hasattr(p.uc.lib,'msd_world_level_rules_version') or p.uc.lib.msd_world_level_rules_version()!=1:
            raise RuntimeError('世界等级限制需要匹配的游戏核心')
        # 此初始化先于 Event 表替换，依据原版普通世界资源枚举主线。
        for world in (0,1):
            stages=[]
            for area in range(p.call('_Z10GetAreaNumi9WorldType',world,0)):
                if p.call('_Z11GetAreaBossii9WorldType',world,area,0)!=0xffffffff:continue
                for stage in range(p.call('_Z11GetStageNumii9WorldType',world,area,0)):
                    if not p.call('_Z12GetStageDataiii9WorldType',world,area,stage,0):raise RuntimeError('主线关卡描述符缺失')
                    bit=p.call('_ZN7AppMain24GetStageDataSavePointNumEiii9WorldType',p.app_instance(),world,area,stage,0)
                    if not 0<=bit<240:raise RuntimeError('主线通关索引超出原生保存范围')
                    stages.append((world,area,stage,bit))
            if not stages:raise RuntimeError('世界主线列表为空')
            data=struct.pack('<'+'I'*len(stages),*[s[3] for s in stages]);pointer=p.alloc(len(data));p.write(pointer,data)
            p.put(HEADER+4+world*8,pointer);p.put(HEADER+8+world*8,len(stages));self.stages.append(stages)
        p.put(HEADER,MAGIC)
        p.uc.lib.msd_enable_world_level_rules()
        p.log('BETA_WORLD_LEVEL_RULES',*[len(stages) for stages in self.stages])
