// Additive native hooks; original game blocks remain the fallback for stock IDs.
#include "aot_runtime.h"
static constexpr uint32_t H=0x1ffee000u,MAGIC=0x434f4d32u,R=0x90u,U=1024u;
static uint32_t head(Context& c,uint32_t o){return rd<uint32_t>(c,H+o);}
static bool active(Context& c){return head(c,0)==MAGIC;}
static uint32_t record(Context& c,uint32_t uid){
 if(!active(c)||uid<U||uid>=head(c,12))return 0;
 return head(c,8)+(uid-U)*R;
}
static bool real_unit(Context& c,uint32_t uid){return uid<400u||record(c,uid)!=0;}
static uint32_t shop(Context& c,uint32_t sid){
 if(!active(c)||sid<512u||sid>=512u+head(c,4))return 0;
 return head(c,8)+(sid-512u)*R;
}
static void ret(Context& c,uint32_t v){c.r[0]=v;c.pc=c.r[14];}
static void dirty(Context& c){wr<uint32_t>(c,H+24,1u);}
static uint32_t total(Context& c){return active(c)?head(c,12):400u;}
static uint32_t images(Context& c){return active(c)?head(c,16):423u;}
static uint32_t stage_graphics(Context& c,uint32_t id,uint32_t original){
 if(!active(c)||id<138u||id>=138u+head(c,68))return original;
 return rd<uint32_t>(c,head(c,64)+(id-138u)*8u+4u);
}
static void extend_menu_icons(Context& c){
 // Menu initialization rebuilds these arrays when changing scenes.
 // Bind the additive action maps immediately before native menu drawing.
 if(!active(c)||!rd<uint32_t>(c,0x109600d4u+80u))return;
 wr<uint32_t>(c,0x1095fe9cu+80u,head(c,56));
 wr<uint32_t>(c,0x1095ffb8u+80u,head(c,60));
}
static uint32_t array_address(Context& c,uint32_t a,bool deck){
 if(!active(c))return a;uint32_t base=head(c,28)+(deck?0xb9d4u:0xb240u);
 if(a>=base&&a<base+head(c,40)*4u)return head(c,deck?36:32)+a-base;
 return a;
}
static uint32_t array_base(Context& c,uint32_t a,bool deck){
 if(active(c)&&a==head(c,28)+(deck?0xb9d4u:0xb240u))return head(c,deck?36:32);
 return a;
}
static uint32_t image_base(Context& c,uint32_t a){return active(c)&&a==0x10922f28u?head(c,20):a;}
// 有理数参数在原生等级插值完成后应用；既有单位的默认倍率为一。
static uint32_t combat_profile(Context& c,uint32_t uid){
 if(!record(c,uid)||head(c,80)!=1u||!head(c,76))return 0u;
 return head(c,76)+(uid-U)*48u;
}
static bool shop_unlocked(Context& c,uint32_t entry,uint32_t app){
 uint32_t table=head(c,92);if(!table)return true;
 uint32_t index=(entry-head(c,8))/R,reference=rd<uint32_t>(c,table+index*4u);
 if(reference==0xffffffffu)return true;
 if(reference>=512u)return false;
 return (rd<uint32_t>(c,app+0x4f20u+(reference/32u)*4u)&(1u<<(reference%32u)))!=0u;
}
static void scale_integer(Context& c,uint32_t address,uint32_t pair){
 uint32_t a=rd<uint32_t>(c,pair),b=rd<uint32_t>(c,pair+4u);if(a==b||!b)return;
 int64_t value=int64_t(rd<int32_t>(c,address))*a/b;
 wr<int32_t>(c,address,int32_t(std::max<int64_t>(INT32_MIN,std::min<int64_t>(INT32_MAX,value))));
}
static void apply_combat_status(Context& c,uint32_t out){
 uint32_t p=combat_profile(c,rd<uint32_t>(c,out));if(!p)return;
 scale_integer(c,out+0xcu,p);
 for(uint32_t off:{0x34u,0x58u,0x74u})scale_integer(c,out+off,p+8u);
 uint32_t a=rd<uint32_t>(c,p+16u),b=rd<uint32_t>(c,p+20u);
 if(a!=b&&b)wr<float>(c,out+0x14u,rd<float>(c,out+0x14u)*float(a)/float(b));
 // 近距、远距攻击判定与三类弹体的目的距离分别缩放。
 for(uint32_t off:{0x18u,0x1cu,0x40u,0x68u,0x84u})scale_integer(c,out+off,p+24u);
}
#define HOOK(NAME,PC,BODY) static Block old_##NAME;static void NAME(Context& c){BODY old_##NAME(c);}
// 抛物线弹体保持垂直轨迹，水平位移按射程倍率缩放。
// 受击滑行仅调整进入受击状态的载具水平位移。
static void scale_vehicle_motion(Context& c){
 uint32_t object=c.r[0],p=combat_profile(c,rd<uint32_t>(c,object+0x128u));if(!p)return;
 uint32_t type=rd<uint32_t>(c,object),pair=0u;
 if(type==head(c,84)&&rd<uint32_t>(c,object+0x7cu)==80u)pair=p+32u;
 else if(type==head(c,88))pair=p+40u;
 if(!pair)return;
 uint32_t a=rd<uint32_t>(c,pair),b=rd<uint32_t>(c,pair+4u);if(a==b||!b)return;
 for(uint32_t index:{1u,2u}){float x;std::memcpy(&x,&c.r[index],4);x=x*float(a)/float(b);std::memcpy(&c.r[index],&x,4);}
}
#include "unit_level_rules.inc"
HOOK(vehicle_motion,0x101dde11u, scale_vehicle_motion(c);)
HOOK(unitdata,0x101652a9u, uint32_t p=record(c,c.r[0]);if(p){ret(c,rd<uint32_t>(c,p+12));return;})
HOOK(unitname,0x101652d5u, uint32_t p=record(c,c.r[0]);if(p){ret(c,rd<uint32_t>(c,p+0x30u+std::min(c.r[1],10u)*4u));return;})
HOOK(unitinfo,0x101652e9u, uint32_t p=record(c,c.r[0]);if(p){ret(c,rd<uint32_t>(c,p+0x5cu+std::min(c.r[1],10u)*4u));return;})
HOOK(maxlevel,0x1016533bu, if(active(c)&&real_unit(c,c.r[0])){ret(c,player_level_cap(c,head(c,28),c.r[0]));return;})
HOOK(getlevel,0x10167af1u, uint32_t p=record(c,c.r[1]);if(p){ret(c,rd<uint32_t>(c,p+24));return;}if(active(c)&&c.r[1]>=400u){ret(c,0xffffffffu);return;})
HOOK(setlevel,0x10167b5bu, uint32_t p=record(c,c.r[1]);if(p){wr<uint32_t>(c,p+24,uint32_t(std::max(-1,std::min(39,int32_t(c.r[2])))));dirty(c);ret(c,0);return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(addlevel,0x10167b0fu, uint32_t p=record(c,c.r[1]);if(p){int v=std::max(-1,std::min(39,int32_t(rd<uint32_t>(c,p+24))+int32_t(c.r[2])));wr<uint32_t>(c,p+24,uint32_t(v));dirty(c);ret(c,uint32_t(v));return;}if(active(c)&&c.r[1]>=400u){ret(c,0xffffffffu);return;})
HOOK(getopen,0x10167ccbu, if(active(c)&&real_unit(c,c.r[1])){ret(c,reconcile_player_cap(c,c.r[0],c.r[1]));return;}if(active(c)&&c.r[1]>=400u){ret(c,40u);return;})
HOOK(isopen,0x10167cf3u, if(active(c)){ret(c,0u);return;})
HOOK(setopen,0x10167d69u, if(active(c)&&real_unit(c,c.r[1]))c.r[2]=player_level_cap(c,c.r[0],c.r[1]);uint32_t p=record(c,c.r[1]);if(p){wr<uint32_t>(c,p+28,c.r[2]);dirty(c);ret(c,0);return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(addopen,0x10167d1du, if(active(c)&&real_unit(c,c.r[1])){ret(c,reconcile_player_cap(c,c.r[0],c.r[1]));return;}if(active(c)&&c.r[1]>=400u){ret(c,40u);return;})
HOOK(gettime,0x10167bafu, uint32_t p=record(c,c.r[1]);if(p){ret(c,rd<uint32_t>(c,p+32));return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(settime,0x10167bcfu, uint32_t p=record(c,c.r[1]);if(p){wr<uint32_t>(c,p+32,c.r[2]);dirty(c);ret(c,0);return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(getdecktime,0x10167c0du, uint32_t p=record(c,c.r[1]);if(p){ret(c,rd<uint32_t>(c,p+0x88u));return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(setdecktime,0x10167c2bu, uint32_t p=record(c,c.r[1]);if(p){wr<uint32_t>(c,p+0x88u,c.r[2]);dirty(c);ret(c,0);return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(getnew,0x10167c67u, uint32_t p=record(c,c.r[1]);if(p){ret(c,rd<uint32_t>(c,p+36));return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(addnew,0x10167c7bu, uint32_t p=record(c,c.r[1]);if(p){wr<uint32_t>(c,p+36,1u);dirty(c);ret(c,0);return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(delnew,0x10167ca3u, uint32_t p=record(c,c.r[1]);if(p){wr<uint32_t>(c,p+36,0u);dirty(c);ret(c,0);return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(shopdata,0x101655c9u, uint32_t p=shop(c,c.r[0]);if(p){ret(c,rd<uint32_t>(c,p+16));return;})
HOOK(shopprice,0x101656c5u, uint32_t p=shop(c,c.r[0]);if(p){ret(c,rd<uint32_t>(c,p+44));return;})
HOOK(shopmax,0x10165709u, if(shop(c,c.r[0])){ret(c,1u);return;})
HOOK(shopstock,0x10165749u, uint32_t p=shop(c,c.r[0]);if(p){ret(c,int32_t(rd<uint32_t>(c,p+24))>=0?1u:0u);return;})
HOOK(soldout,0x10165835u, uint32_t p=shop(c,c.r[0]);if(p){ret(c,int32_t(rd<uint32_t>(c,p+24))>=0);return;})
HOOK(shopdisplay,0x1016595fu, if(shop(c,c.r[0])){ret(c,0u);return;})
HOOK(shopdiscount,0x1016596bu, if(shop(c,c.r[0])){ret(c,0u);return;})
HOOK(discount,0x1020b459u, if(record(c,c.r[1])){ret(c,0u);return;})
HOOK(shopavailable,0x102093f5u, uint32_t p=shop(c,c.r[1]);if(p){ret(c,rd<uint32_t>(c,c.r[0]+0xb890u)==2u&&shop_unlocked(c,p,c.r[0]));return;})
HOOK(shopenable,0x10167d8du, uint32_t p=shop(c,c.r[1]);if(p){ret(c,shop_unlocked(c,p,c.r[0]));return;})
HOOK(setshopenable,0x10167da1u, if(shop(c,c.r[1])){ret(c,0u);return;})
HOOK(getshopnew,0x10167dc9u, uint32_t p=shop(c,c.r[1]);if(p){ret(c,rd<uint32_t>(c,p+40));return;})
HOOK(addshopnew,0x10167dddu, uint32_t p=shop(c,c.r[1]);if(p){wr<uint32_t>(c,p+40,1u);dirty(c);ret(c,0);return;})
HOOK(delshopnew,0x10167e05u, uint32_t p=shop(c,c.r[1]);if(p){wr<uint32_t>(c,p+40,0u);dirty(c);ret(c,0);return;})
HOOK(convertunit,0x101dc929u, uint32_t p=record(c,c.r[0]);if(p){ret(c,rd<uint32_t>(c,p+20));return;})
// Auxiliary sprites have image/sound resources and no BattleInfo unit row.
// Stop child traversal after preloading their resources, at the common path.
HOOK(aux_preload_status,0x101c945du, if(active(c)&&!real_unit(c,c.r[5])){c.pc=0x101c9483u;return;})
HOOK(image_index_boundary,0x101dcb09u, if(active(c)&&c.r[1]>=images(c)){ret(c,0u);return;})
HOOK(image_create_boundary,0x101dcbc5u, if(active(c)&&c.r[1]>=images(c)){ret(c,0u);return;})
HOOK(sound_read_boundary,0x101dcc65u, if(active(c)&&c.r[1]>=images(c)){ret(c,0u);return;})
HOOK(sound_release_boundary,0x101dccd9u, if(active(c)&&c.r[1]>=images(c)){ret(c,0u);return;})
HOOK(resource_uid_boundary,0x101dcba9u, if(active(c)&&c.r[1]>=423u&&!record(c,c.r[1])){ret(c,0u);return;})
HOOK(sound_uid_boundary,0x101dccc1u, if(active(c)&&c.r[1]>=423u&&!record(c,c.r[1])){ret(c,0u);return;})
HOOK(release_uid_boundary,0x101dcd31u, if(active(c)&&c.r[1]>=423u&&!record(c,c.r[1])){ret(c,0u);return;})
// Namespace gaps are excluded before table interpolation; empty statuses
// retain a -1 child sentinel and cannot become an accidental real unit.
HOOK(status_boundary,0x101cfbcdu, if(active(c)&&!real_unit(c,c.r[1])){uint32_t out=c.r[3];for(uint32_t i=0;i<0xecu;i+=4u)wr<uint32_t>(c,out+i,0u);wr<uint32_t>(c,out,c.r[1]);wr<uint32_t>(c,out+0xa0u,0xffffffffu);ret(c,0u);return;})
extern "C" __declspec(dllexport) uint32_t msd_community_unit_id_base(){return U;}
extern "C" __declspec(dllexport) uint32_t msd_community_combat_profile_version(){return 1u;}
extern "C" __declspec(dllexport) uint32_t msd_community_shop_gate_version(){return 1u;}
HOOK(create_params_boundary,0x101cfa99u, if(active(c)&&!real_unit(c,c.r[1])){for(uint32_t i=0;i<0x1cu;i+=4u)wr<uint32_t>(c,c.r[3]+i,0u);ret(c,0u);return;})
HOOK(real_unit_factory_boundary,0x101d1421u, if(active(c)&&!real_unit(c,c.r[2])){ret(c,0u);return;})
// 敌军名单沿用原生等级与标志计算，社区身份由运行注册表确认。
HOOK(enemy_roster,0x101c9d07u,
 uint32_t row=rd<uint32_t>(c,c.r[3]+68u)+c.r[6]*c.r[5];
 uint32_t uid=rd<uint32_t>(c,row+4u);
 if(record(c,uid)){
  c.r[0]=c.r[4];c.r[3]=row;c.r[5]=add(c,c.r[5],1u,0u,true);
  c.r[1]=uid;c.r[2]=rd<uint32_t>(c,row+8u);c.r[3]=1u;nz(c,1u);
  c.r[2]=add(c,c.r[2],~1u,1u,true);c.r[14]=0x101c9d23u;c.pc=0x101c9b91u;return;
 })
HOOK(enemy_unit_enable,0x101c98fbu, if(record(c,c.r[1])){ret(c,1u);return;})
HOOK(enemy_special_policy,0x101c9da3u,
 uint32_t mission=rd<uint32_t>(c,c.r[4]+0x3acu);
 if(rd<uint32_t>(c,0x1ffec000u)==0x45585431u&&mission&&rd<uint32_t>(c,mission)>=1000000u)
  c.r[3]=rd<uint32_t>(c,0x1ffec014u)?1u:0u;
 )
// 独立音乐复用已核验的空闲音频槽，保持原生缓存边界。
HOOK(extension_music,0x101c6625u,
 if(c.r[1]==1031u&&rd<uint32_t>(c,0x1ffec000u)==0x45585431u){
  uint32_t bank=rd<uint32_t>(c,0x1ffec004u);if(bank){ret(c,bank);return;}
 })
HOOK(extension_mission,0x101d09fdu,
 if(rd<uint32_t>(c,0x1ffec000u)==0x45585431u&&c.r[1]>=1000000u){
  uint32_t base=rd<uint32_t>(c,0x1ffec00cu);uint32_t count=rd<uint32_t>(c,0x1ffec010u);
  uint32_t i=c.r[1]-1000000u;
  if(i<count&&rd<uint32_t>(c,base+i*120u)==c.r[1]){ret(c,base+i*120u);return;}
  ret(c,0u);return;
 })
extern "C" __declspec(dllexport) uint32_t msd_content_interface_version(){return 1u;}
// Generated block overrides and registration are emitted by the build script.
#include "community_blocks.inc"
