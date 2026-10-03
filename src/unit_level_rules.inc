// Player progression: level 35 is available independently of world progress.
// A corresponding faction core enables level 40 for native and registered units.
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
 // Existing levels above 35 retain their progress when loading older profiles.
 return player_saved_level(c,app,uid)>=35||player_has_faction_core(c,app,uid)?40u:35u;
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
extern "C" __declspec(dllexport) uint32_t msd_player_level_rules_version(){return 1u;}
