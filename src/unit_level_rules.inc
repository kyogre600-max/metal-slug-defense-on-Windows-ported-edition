// beta 玩家升级限制同时依据普通世界主线进度和对应军队核库存。
static constexpr uint32_t WORLD_H=0x1ffe9000u,WORLD_MAGIC=0x57474c31u;
static uint32_t world_level_cap(Context& c,uint32_t app){
 if(rd<uint32_t>(c,WORLD_H)!=WORLD_MAGIC)return 40u;
 for(uint32_t world=0;world<2u;world++){
  uint32_t bits=rd<uint32_t>(c,WORLD_H+4u+world*8u),count=rd<uint32_t>(c,WORLD_H+8u+world*8u);
  if(!count)return world?20u:10u;
  for(uint32_t i=0;i<count;i++){
   uint32_t bit=rd<uint32_t>(c,bits+i*4u);
   if(!(rd<uint32_t>(c,app+0x5140u+(bit/32u)*4u)&(1u<<(bit%32u))))return world?20u:10u;
  }
 }
 return 40u;
}
static uint32_t player_level_address(uint32_t app,uint32_t uid){
 return app+(uid<300u?0x3e28u:0x86a8u)+uid*2u;
}
static uint32_t player_cap_address(uint32_t app,uint32_t uid){
 return app+(uid<300u?0x68ccu:0x8edcu)+uid*2u;
}
static int32_t player_saved_level(Context& c,uint32_t app,uint32_t uid){
 uint32_t entry=record(c,uid);
 return entry?rd<int32_t>(c,entry+24u):rd<int16_t>(c,player_level_address(app,uid));
}
static bool player_has_faction_core(Context& c,uint32_t app,uint32_t uid){
 // BattleInfo's database includes the registered unit rows and their factions.
 uint32_t info=rd<uint32_t>(c,0x101cfa94u)+0x101cfa84u+4u;
 uint32_t db=rd<uint32_t>(c,info),rows=rd<uint32_t>(c,db+4u);
 if(uid>=rd<uint32_t>(c,db+8u))return false;
 int32_t faction=rd<int32_t>(c,rows+uid*0x390u+0x378u);
 if(faction<0||faction>5)return false;
 uint32_t shops=rd<uint32_t>(c,0x101655d8u)+0x101655ceu+0x19cu;
 uint32_t item=rd<uint32_t>(c,shops+(289u+uint32_t(faction))*32u+4u);
 return rd<int16_t>(c,app+0x3decu+item*2u)>0;
}
static uint32_t player_level_cap(Context& c,uint32_t app,uint32_t uid){
 // 已有高等级保存值继续保留；世界上限用于约束后续升级。
 uint32_t core_cap=player_has_faction_core(c,app,uid)?40u:35u;
 return std::min(world_level_cap(c,app),core_cap);
}
static uint32_t reconcile_player_cap(Context& c,uint32_t app,uint32_t uid){
 uint32_t cap=player_level_cap(c,app,uid),entry=record(c,uid);
 if(entry){
  if(rd<uint32_t>(c,entry+28u)!=cap){wr<uint32_t>(c,entry+28u,cap);dirty(c);}
 }else if(player_saved_level(c,app,uid)>=0){
  wr<int16_t>(c,player_cap_address(app,uid),int16_t(cap));
 }
 return cap;
}
static bool limit_player_increment(Context& c){
 if(!active(c)||!real_unit(c,c.r[1])||int32_t(c.r[2])<=0)return false;
 int32_t current=player_saved_level(c,c.r[0],c.r[1]);
 int32_t limit=int32_t(player_level_cap(c,c.r[0],c.r[1]))-1;
 if(current>=limit){ret(c,uint32_t(current));return true;}
 c.r[2]=uint32_t(std::min(int32_t(c.r[2]),limit-current));return false;
}
extern "C" __declspec(dllexport) uint32_t msd_player_level_rules_version(){return 1u;}
extern "C" __declspec(dllexport) uint32_t msd_world_level_rules_version(){return 1u;}
static Block old_world_upgrade;
static void world_upgrade(Context& c){
 if(active(c)&&rd<uint32_t>(c,WORLD_H)==WORLD_MAGIC){
  uint32_t limit=world_level_cap(c,c.r[4]);
  // 世界条件尚未满足时，保留原生单位页面并结束本次选择。
  if(limit<35u&&int32_t(c.r[7])>=int32_t(limit)-1){c.pc=0x101ed2d1u;return;}
 }
 old_world_upgrade(c);
}
extern "C" __declspec(dllexport) void msd_enable_world_level_rules(){
 static bool installed=false;if(installed)return;installed=true;
 old_world_upgrade=find_block(0x101ed29fu);register_block(0x101ed29fu,world_upgrade);
}
