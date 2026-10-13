// Additive native hooks; original game blocks remain the fallback for stock IDs.
#include "aot_runtime.h"
#include "netplay.h"
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
static uint32_t pack_record(Context& c){return active(c)?head(c,96):0u;}
static uint32_t pack_shop(Context& c,uint32_t sid){uint32_t p=pack_record(c);return p&&rd<uint16_t>(c,p)==sid?p:0u;}
static uint32_t pack_id(Context& c,uint32_t id){uint32_t p=pack_record(c);return p&&rd<uint32_t>(c,p+4u)==id?p:0u;}
static uint32_t pack_member(Context& c,uint32_t p,uint32_t index){
 return index<rd<uint32_t>(c,p+32u)?rd<uint32_t>(c,rd<uint32_t>(c,p+36u)+index*4u):0xffffffffu;
}
static bool pack_owned(Context& c,uint32_t p){
 for(uint32_t i=0;i<rd<uint32_t>(c,p+32u);++i){uint32_t r=record(c,pack_member(c,p,i));if(!r||rd<int32_t>(c,r+24u)<0)return false;}
 return true;
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
// 已拥有单位紧凑列表的字节数（头部 +40 为单位个数，宿主取 8 的倍数，保持栈 8 字节对齐）。
// CreateUnitListCustum 与 InitDeckPanels 的栈上暂存表及列表清零、复制按此长度。
static uint32_t list_bytes(Context& c){return head(c,40)*4u;}
// BattleSpriteFactory::releaseUnusedResourcesAll 的栈上“使用中”标记表（每个图片索引 1 字节，清零长度为 images(c)）。
// 原覆盖块的帧固定为 516 字节（按 64 个社区单位）；帧长取不小于 images(c) 且 ≡4 mod 8（加 36 字节保存寄存器后 8 字节对齐）。
static uint32_t used_bytes(Context& c){return std::max(516u,(images(c)+3u)/8u*8u+4u);}
// 有理数参数在原生等级插值完成后应用；既有单位的默认倍率为一。
static uint32_t combat_profile(Context& c,uint32_t uid){
 // 原版单位（模组覆盖补丁，M3b）：头部 +148 为 400 个指针的表，被补丁修改的 UnitID 指向 48 字节倍率组，其余为 0。
 if(uid<400u){
  uint32_t table=active(c)&&head(c,80)==1u?head(c,148u):0u;
  return table?rd<uint32_t>(c,table+uid*4u):0u;
 }
 if(!record(c,uid)||head(c,80)!=1u||!head(c,76))return 0u;
 return head(c,76)+(uid-U)*48u;
}
extern "C" __declspec(dllexport) uint32_t msd_community_stock_profile_version(){return 1u;}
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
 // 近距、普攻、绝招伤害分别为状态偏移 0x3c/0x58/0x74（词 15/22/29）；0x34（词 13）为被击毁时给予敌方的 AP，保持原值。
 for(uint32_t off:{0x3cu,0x58u,0x74u})scale_integer(c,out+off,p+8u);
 uint32_t a=rd<uint32_t>(c,p+16u),b=rd<uint32_t>(c,p+20u);
 if(a!=b&&b)wr<float>(c,out+0x14u,rd<float>(c,out+0x14u)*float(a)/float(b));
 // 近距、远距攻击判定与三类弹体的目的距离分别缩放。
 // 近距弹体目的距离为 0x4c（词 19）；0x40（词 16）为近距击退力，保持原值。
 for(uint32_t off:{0x18u,0x1cu,0x4cu,0x68u,0x84u})scale_integer(c,out+off,p+24u);
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
HOOK(maxlevel,0x1016533bu, /* 原生世界开放数量与菜单数据共同决定免费基础上限。 */)
HOOK(getlevel,0x10167af1u, uint32_t p=record(c,c.r[1]);if(p){ret(c,rd<uint32_t>(c,p+0x8cu)?0xffffffffu:rd<uint32_t>(c,p+24));return;}if(active(c)&&c.r[1]>=400u){ret(c,0xffffffffu);return;})
HOOK(setlevel,0x10167b5bu, uint32_t p=record(c,c.r[1]);if(p){wr<uint32_t>(c,p+24,uint32_t(std::max(-1,std::min(39,int32_t(c.r[2])))));dirty(c);ret(c,0);return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(addlevel,0x10167b0fu, if(limit_player_increment(c))return;uint32_t p=record(c,c.r[1]);if(p){int v=std::max(-1,std::min(39,int32_t(rd<uint32_t>(c,p+24))+int32_t(c.r[2])));wr<uint32_t>(c,p+24,uint32_t(v));dirty(c);ret(c,uint32_t(v));return;}if(active(c)&&c.r[1]>=400u){ret(c,0xffffffffu);return;})
HOOK(getopen,0x10167ccbu, if(active(c)&&real_unit(c,c.r[1])){ret(c,reconcile_player_cap(c,c.r[0],c.r[1]));return;}if(active(c)&&c.r[1]>=400u){ret(c,40u);return;})
HOOK(isopen,0x10167cf3u, if(active(c)&&real_unit(c,c.r[1])){ret(c,reconcile_player_cap(c,c.r[0],c.r[1])<=39u);return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(setopen,0x10167d69u, if(active(c)&&real_unit(c,c.r[1]))c.r[2]=uint32_t(std::max(0,std::min(40,int32_t(c.r[2]))));uint32_t p=record(c,c.r[1]);if(p){wr<uint32_t>(c,p+28,c.r[2]);dirty(c);ret(c,0);return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(addopen,0x10167d1du, uint32_t p=record(c,c.r[1]);if(p){int32_t cap=std::max(0,std::min(40,int32_t(rd<uint32_t>(c,p+28u))+int32_t(c.r[2])));wr<uint32_t>(c,p+28u,uint32_t(cap));dirty(c);ret(c,uint32_t(cap));return;}if(active(c)&&c.r[1]>=400u){ret(c,40u);return;})
HOOK(gettime,0x10167bafu, uint32_t p=record(c,c.r[1]);if(p){ret(c,rd<uint32_t>(c,p+32));return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(settime,0x10167bcfu, uint32_t p=record(c,c.r[1]);if(p){wr<uint32_t>(c,p+32,c.r[2]);dirty(c);ret(c,0);return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(getdecktime,0x10167c0du, uint32_t p=record(c,c.r[1]);if(p){ret(c,rd<uint32_t>(c,p+0x88u));return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(setdecktime,0x10167c2bu, uint32_t p=record(c,c.r[1]);if(p){wr<uint32_t>(c,p+0x88u,c.r[2]);dirty(c);ret(c,0);return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
// 获得时间（GetUnitGetTimeSaveData / SetUnitGetTimeSaveData，0x167b74 / 0x167b90）：原生对 UnitID ≥ 300 读写
// app+0x857c+4·uid，无上界（U1 开工说明附录 A.11）。社区单位改用头部 +160 的逐槽表（宿主随社区进度保存）。
static uint32_t get_time_slot(Context& c,uint32_t uid){uint32_t t=head(c,160);return t&&record(c,uid)?t+(uid-U)*4u:0u;}
HOOK(getgettime,0x10167b75u, uint32_t p=get_time_slot(c,c.r[1]);if(p){ret(c,rd<uint32_t>(c,p));return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(setgettime,0x10167b91u, uint32_t p=get_time_slot(c,c.r[1]);if(p){wr<uint32_t>(c,p,c.r[2]);dirty(c);ret(c,0);return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
extern "C" __declspec(dllexport) uint32_t msd_community_get_time_version(){return 1u;}
// 原生单位商店勋章不足（PopupResultMenuShopBuyYes：0x20b686 起以 strShop 8 格式化“还差 %d 个 [deco0]\n是否前往购买画面”，
// 0x20b69a 起以 SetPopupYesNo 询问，“是”转勋章商店）。头部 +164 非零时（新单位界面的组合包页面，开工说明 D45）只保留第一行，
// 改走同函数模式 6 的 SetPopupOK 路径（0x20b66c：r4 为 AppMain、r5 为文字缓冲），不询问是否前往商店。
HOOK(shop_short_ok,0x1020b69bu, if(active(c)&&head(c,164u)){
 for(uint32_t i=0,s=c.r[5];i<512u;++i){uint8_t ch=rd<uint8_t>(c,s+i);if(!ch)break;
  if(ch=='\n'){uint32_t e=i;while(e&&rd<uint8_t>(c,s+e-1u)==' ')--e;wr<uint8_t>(c,s+e,0);break;}}
 c.pc=0x1020b66du;return;})
extern "C" __declspec(dllexport) uint32_t msd_community_shop_short_ok_version(){return 1u;}
HOOK(getnew,0x10167c67u, uint32_t p=record(c,c.r[1]);if(p){ret(c,rd<uint32_t>(c,p+36));return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(addnew,0x10167c7bu, uint32_t p=record(c,c.r[1]);if(p){wr<uint32_t>(c,p+36,1u);dirty(c);ret(c,0);return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(delnew,0x10167ca3u, uint32_t p=record(c,c.r[1]);if(p){wr<uint32_t>(c,p+36,0u);dirty(c);ret(c,0);return;}if(active(c)&&c.r[1]>=400u){ret(c,0u);return;})
HOOK(shopdata,0x101655c9u, uint32_t p=pack_shop(c,c.r[0]);if(p){ret(c,p);return;}p=shop(c,c.r[0]);if(p){ret(c,rd<uint32_t>(c,p+16));return;})
HOOK(shopprice,0x101656c5u, uint32_t p=pack_shop(c,c.r[0]);if(p){ret(c,uint32_t(rd<int16_t>(c,p+16u)));return;}p=shop(c,c.r[0]);if(p){ret(c,rd<uint32_t>(c,p+44));return;})
HOOK(shopmax,0x10165709u, if(shop(c,c.r[0])||pack_shop(c,c.r[0])){ret(c,1u);return;})
HOOK(shopstock,0x10165749u, uint32_t p=pack_shop(c,c.r[0]);if(p){ret(c,pack_owned(c,p));return;}p=shop(c,c.r[0]);if(p){ret(c,rd<uint32_t>(c,p+0x8cu)||int32_t(rd<uint32_t>(c,p+24))>=0?1u:0u);return;})
HOOK(soldout,0x10165835u, uint32_t p=pack_shop(c,c.r[0]);if(p){ret(c,pack_owned(c,p));return;}p=shop(c,c.r[0]);if(p){ret(c,rd<uint32_t>(c,p+0x8cu)||int32_t(rd<uint32_t>(c,p+24))>=0);return;})
HOOK(shopdisplay,0x1016595fu, if(shop(c,c.r[0])||pack_shop(c,c.r[0])){ret(c,0u);return;})
HOOK(shopdiscount,0x1016596bu, uint32_t p=pack_shop(c,c.r[0]);if(p){ret(c,uint32_t(rd<int16_t>(c,p+24u)));return;}if(shop(c,c.r[0])){ret(c,0u);return;})
HOOK(discount,0x1020b459u, if(record(c,c.r[1])){ret(c,0u);return;})
HOOK(shopavailable,0x102093f5u, if(pack_shop(c,c.r[1])){ret(c,rd<uint32_t>(c,c.r[0]+0xb890u)==2u);return;}uint32_t p=shop(c,c.r[1]);if(p){ret(c,!rd<uint32_t>(c,p+0x8cu)&&rd<uint32_t>(c,c.r[0]+0xb890u)==2u&&shop_unlocked(c,p,c.r[0]));return;})
HOOK(shopenable,0x10167d8du, if(pack_shop(c,c.r[1])){ret(c,1u);return;}uint32_t p=shop(c,c.r[1]);if(p){ret(c,!rd<uint32_t>(c,p+0x8cu)&&shop_unlocked(c,p,c.r[0]));return;})
HOOK(setshopenable,0x10167da1u, if(shop(c,c.r[1])||pack_shop(c,c.r[1])){ret(c,0u);return;})
HOOK(getshopnew,0x10167dc9u, if(pack_shop(c,c.r[1])){ret(c,0u);return;}uint32_t p=shop(c,c.r[1]);if(p){ret(c,rd<uint32_t>(c,p+40));return;})
HOOK(addshopnew,0x10167dddu, if(pack_shop(c,c.r[1])){ret(c,0u);return;}uint32_t p=shop(c,c.r[1]);if(p){wr<uint32_t>(c,p+40,1u);dirty(c);ret(c,0);return;})
HOOK(delshopnew,0x10167e05u, if(pack_shop(c,c.r[1])){ret(c,0u);return;}uint32_t p=shop(c,c.r[1]);if(p){wr<uint32_t>(c,p+40,0u);dirty(c);ret(c,0);return;})
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
HOOK(pack_unit,0x101654b5u, uint32_t p=pack_id(c,c.r[0]);if(p){ret(c,pack_member(c,p,c.r[1]));return;})
static const int32_t pack_positions[7]={-50,0,50,-65,-25,15,55};
HOOK(pack_x,0x101654d1u, if(pack_id(c,c.r[0])){ret(c,c.r[1]<7u?uint32_t(pack_positions[c.r[1]]):0u);return;})
HOOK(pack_y,0x101654edu, if(pack_id(c,c.r[0])){ret(c,c.r[1]<3u?uint32_t(-30):0u);return;})
HOOK(pack_name,0x1016551du, uint32_t p=pack_id(c,c.r[0]);if(p){ret(c,rd<uint32_t>(c,p+40u+std::min(c.r[1],10u)*4u));return;})
HOOK(pack_info,0x10165509u, uint32_t p=pack_id(c,c.r[0]);if(p){ret(c,rd<uint32_t>(c,p+84u+std::min(c.r[1],10u)*4u));return;})
extern "C" __declspec(dllexport) uint32_t msd_community_unit_pack_version(){return 1u;}
// ---------- 生命分档单位（行为库 v3：hp_stage_animations 等，首批为 PVZ 僵尸；基准为原版 UnitID 313 BattleAction_ZombieBrain）----------
// 头部 +168：逐槽 ZSpec 指针表（0 为无，无此类单位时整表为 0）。ZSpec 为 28 个 32 位字（community_content.py zombie_spec）：
//  0 标记（1 生命分档 2 无击退 4 防具受击音效 8 击毙音效 16 投出子单位 32 被投出的飞行单位 64 前方最近敌人 128 分档受击动作）；1 分档数 n（≤6）；
//  2..7 / 8..13 第 k 档阈值的分子 / 分母（生命 < 最大生命×分子/分母 时至少为第 k 档）；14 带过渡动作的档位位图；
//  15 狂暴档（0 为无）；16/17 狂暴移速倍率；18/19 狂暴伤害倍率；20/21 防具受击音效 SoundID；22 防具在第几档前存在；
//  23 击毙音效；24 投出子单位的档位；25 投出时刻（过渡动作的精灵帧计数）；26/27 被投出单位的起点前移与高度（世界坐标）。
// 第 k 档的动作槽为原生槽号 + 16k（只对槽 0–2、6、7、9–12、14；槽 14 为分档受击动作，原生 ZombieBrain 不使用）。逐实例状态只保存在客体对象中：当前动作号（+0xc4）、
// 状态副本序号（+0x300，狂暴为 1）与子对象指针（+0xfc，已投出），回滚快照随客体内存保存。
bool msd_guest_call(Context& c,uint32_t fn,uint32_t a0,uint32_t a1,uint32_t a2,uint32_t a3,uint32_t* result);
static constexpr uint32_t Z_STAGE_SLOTS=0x5ec7u;
static constexpr uint32_t Z_RESERVE_STATE=0x101dda28u,Z_PLAY_SE=0x101de1acu,Z_SUMMON_CHILD=0x101af74bu;
static const uint8_t Z_LEN[24]={2,2,2,2,2,1,3,5,2,2,3,5,5,2,3,1,1,2,2,3,3,1,5,2};
static uint32_t zspec(Context& c,uint32_t obj){
 if(!active(c)||!head(c,168u)||!obj||rd<uint32_t>(c,obj)!=head(c,84u))return 0u;
 uint32_t uid=rd<uint32_t>(c,obj+0x128u);if(!record(c,uid))return 0u;
 return rd<uint32_t>(c,head(c,168u)+(uid-U)*4u);
}
static uint32_t zw(Context& c,uint32_t s,uint32_t i){return rd<uint32_t>(c,s+i*4u);}
static int32_t z_stage_of_anim(Context& c,uint32_t s,int32_t anim){
 if(anim<0)return -1;uint32_t k=uint32_t(anim)/16u,slot=uint32_t(anim)%16u;
 if(k>zw(c,s,1)||!((Z_STAGE_SLOTS>>slot)&1u))return -1;return int32_t(k);
}
static uint32_t z_stage_of_hp(Context& c,uint32_t s,uint32_t obj){
 int64_t hp=int32_t(rd<uint32_t>(c,obj+0x308u)),mx=int32_t(rd<uint32_t>(c,obj+0x304u));uint32_t n=std::min(zw(c,s,1),6u),k=0u;
 for(uint32_t i=0;i<n;++i)if(hp*int64_t(zw(c,s,8u+i))<int64_t(zw(c,s,2u+i))*mx)k=i+1u;
 return k;
}
static uint32_t z_next_transition(Context& c,uint32_t s,uint32_t d){
 uint32_t n=std::min(zw(c,s,1),6u),m=zw(c,s,14);for(uint32_t k=d+1u;k<=n;++k)if((m>>k)&1u)return k;return n+1u;
}
// 动作请求的目标档位：不越过下一个带过渡动作的档位（过渡动作经状态 80 播放，槽 12 只由过渡请求）。
static uint32_t z_target(Context& c,uint32_t s,uint32_t obj,uint32_t slot){
 int32_t d=z_stage_of_anim(c,s,int32_t(rd<uint32_t>(c,obj+0xc4u)));if(d<0)d=0;
 uint32_t hp=z_stage_of_hp(c,s,obj),t=z_next_transition(c,s,uint32_t(d));
 if(slot==12u)return hp>=t?t:uint32_t(d);
 return std::min(hp,t-1u);
}
// 同一动作换到另一档：保留脚本位置与等待计数，显示帧取新脚本在该位置之前最后一条 op0（各档同一动作的命令结构相同）。
static void z_swap(Context& c,uint32_t obj,uint32_t anim,uint32_t target){
 uint32_t next=anim%16u+16u*target,sprite=rd<uint32_t>(c,obj+0x5cu);if(!sprite)return;
 uint32_t st=rd<uint32_t>(c,sprite+0x58u),desc=rd<uint32_t>(c,sprite+0x40u);if(!st||!desc)return;
 if(rd<uint32_t>(c,st+0xcu)!=anim||next>=rd<uint32_t>(c,desc+0x1cu))return;
 uint32_t script=rd<uint32_t>(c,rd<uint32_t>(c,desc+0x18u)+next*4u),index=rd<uint32_t>(c,st+0x10u),pos=0u;int32_t frame=-2;
 while(pos<index){uint32_t op=rd<uint32_t>(c,script+pos*4u);if(op>23u)return;if(op==0u)frame=int32_t(rd<uint32_t>(c,script+pos*4u+4u));pos+=Z_LEN[op];}
 if(pos!=index)return;
 wr<uint32_t>(c,st+0xcu,next);if(frame!=-2)wr<uint32_t>(c,st+8u,uint32_t(frame));wr<uint32_t>(c,obj+0xc4u,next);
}
// 狂暴：状态副本 1 复制副本 0，移速（词 5，浮点）与普攻、绝招伤害（词 22、29）按倍率缩放，切换序号（不改特殊攻击计量）。
static void z_apply_rage(Context& c,uint32_t s,uint32_t obj){
 for(uint32_t i=0;i<0xecu;i+=4u)wr<uint32_t>(c,obj+0x214u+i,rd<uint32_t>(c,obj+0x128u+i));
 uint32_t a=zw(c,s,16),b=zw(c,s,17);
 if(a&&b)wr<float>(c,obj+0x214u+0x14u,rd<float>(c,obj+0x214u+0x14u)*float(a)/float(b));
 a=zw(c,s,18);b=zw(c,s,19);
 if(a&&b)for(uint32_t w:{22u,29u}){int64_t v=int32_t(rd<uint32_t>(c,obj+0x214u+w*4u));wr<uint32_t>(c,obj+0x214u+w*4u,uint32_t(int32_t(v*a/b)));}
 wr<uint32_t>(c,obj+0x300u,1u);
}
// BattleAction_ZombieBrain::update 入口（r1 对象、r2 状态）：生命越过档位时，带过渡的档位预约状态 80，其余就地换档。
static void z_update(Context& c){
 uint32_t obj=c.r[1],state=c.r[2],s=zspec(c,obj);if(!s||!(zw(c,s,0)&1u))return;
 if(state>=100u||int32_t(rd<uint32_t>(c,obj+0x308u))<=0)return;
 int32_t anim=int32_t(rd<uint32_t>(c,obj+0xc4u)),d=z_stage_of_anim(c,s,anim);if(d<0)return;
 uint32_t rage=zw(c,s,15);
 if(rage&&uint32_t(d)>=rage&&!rd<uint32_t>(c,obj+0x300u))z_apply_rage(c,s,obj);
 if(state==80u)return;
 uint32_t hp=z_stage_of_hp(c,s,obj),t=z_next_transition(c,s,uint32_t(d));
 if(hp>=t){msd_guest_call(c,Z_RESERVE_STATE,obj,80u,0u,0u,nullptr);return;}
 uint32_t target=std::min(hp,t-1u);
 if(target!=uint32_t(d))z_swap(c,obj,uint32_t(anim),target);
}
// 分档受击动作（行为库 v5：stage_knockback_animation，标记 128）：ZombieBrain 只在进入状态 80 的第一帧请求槽 12
// （0x1017caaa）；此时没有待播的过渡（生命未越过下一个带过渡的档位）即为原生击退（BattleUnitDefault::damageAction
// 预约），改为当前档的槽 14 + 16d，过渡动作不因受击重播。没有此标记时槽 12 照旧。
static uint32_t z_remap(Context& c,uint32_t s,uint32_t obj,uint32_t slot){
 if(slot==12u&&(zw(c,s,0)&128u)){
  int32_t d=z_stage_of_anim(c,s,int32_t(rd<uint32_t>(c,obj+0xc4u)));if(d<0)d=0;
  if(z_stage_of_hp(c,s,obj)<z_next_transition(c,s,uint32_t(d)))return 14u+16u*uint32_t(d);
 }
 return slot+16u*z_target(c,s,obj,slot);
}
HOOK(zombie_stage_update,0x1017ca15u, z_update(c);)
// 雪地步兵类（基准 182，BattleAction_ZakoSnow::update 入口 0x1018805c，参数与 ZombieBrain::update 相同：r1 对象、r2 状态）：
// 2026-10-13 冰车。宿主只允许不带过渡与狂暴的分档（behaviors.py），此处只会就地换档。
HOOK(zombie_stage_update_snow,0x1018805du, z_update(c);)
HOOK(zombie_stage_remap,0x101de017u,
 uint32_t slot=c.r[1];
 if(slot<16u&&slot!=14u&&((Z_STAGE_SLOTS>>slot)&1u)){uint32_t s=zspec(c,c.r[0]);if(s&&(zw(c,s,0)&1u))c.r[1]=z_remap(c,s,c.r[0],slot);}
 )
// ZombieBrain 状态 80 的尾块（0x1017cac4：mov r0,r6; mov r1,r4; movs r2,#0 后出栈并尾调用 actionMove）。
// 投出子单位的档位过渡到达投出时刻且尚未投出时，按同一出栈改为尾调用 ParaTrooper::summonZakoBazooka(r1=对象)：
// 原生在对象位置以本单位等级生成固定 UnitID 45（落地映射改为登记的子单位）并记入 +0xfc。该帧不调用 actionMove(…,0)。
static bool z_throw(Context& c){
 uint32_t obj=c.r[4],s=zspec(c,obj);if(!s||!(zw(c,s,0)&16u))return false;
 if(rd<uint32_t>(c,obj+0xc4u)!=12u+16u*zw(c,s,24)||rd<uint32_t>(c,obj+0xfcu))return false;
 uint32_t sprite=rd<uint32_t>(c,obj+0x5cu);if(!sprite||rd<uint32_t>(c,sprite+0x3cu)<zw(c,s,25))return false;
 uint32_t sp=c.r[13];c.r[0]=c.r[6];c.r[1]=obj;
 c.r[4]=rd<uint32_t>(c,sp);c.r[5]=rd<uint32_t>(c,sp+4u);c.r[6]=rd<uint32_t>(c,sp+8u);c.r[14]=rd<uint32_t>(c,sp+12u);c.r[13]=sp+16u;
 c.pc=Z_SUMMON_CHILD;return true;
}
static Block old_zombie_throw;static void zombie_throw(Context& c){if(z_throw(c))return;old_zombie_throw(c);}
// 被投出的飞行单位（基准 160 BattleAction_ParaTrooper）首帧：原生把高度固定为 75（空降起点），改为从投出者手中出发，
// 并与原生空中单位一样不阻挡、不被选为目标。
// 0x101af7da 为非浏览模式的高度写入块，跳到 0x101af802 继续原生首帧流程。
static bool z_flight_start(Context& c){
 uint32_t obj=c.r[4],s=zspec(c,obj);if(!s||!(zw(c,s,0)&32u))return false;
 int32_t forward=int32_t(zw(c,s,26)),height=int32_t(zw(c,s,27));
 float x=rd<float>(c,obj+0x8cu)+float(rd<uint32_t>(c,obj+0x78u)==0x5au?forward:-forward),y=rd<float>(c,obj+0x90u)-float(height);
 wr<float>(c,obj+0x8cu,x);wr<float>(c,obj+0x94u,x);wr<float>(c,obj+0x90u,y);wr<float>(c,obj+0x98u,y);
 // 飞行段不阻挡、不受伤、穿越前线（身体状态 +0x6c：2 Guard、8 DontToche、0x10 AreaThrough、0x40 NoTarget，同原生空中单位）。
 wr<uint32_t>(c,obj+0x6cu,rd<uint32_t>(c,obj+0x6cu)|0x5au);
 c.pc=0x101af803u;return true;
}
static Block old_zombie_flight_start;static void zombie_flight_start(Context& c){if(z_flight_start(c))return;old_zombie_flight_start(c);}
// BattleUnitDefault::damageAction：0x1016f484 为受击后仍存活的分支（随后检查击退计量），0x1016f4a2 播放受击效果，
// 0x1016f44c 为生命归零的分支（栈 +8 为攻击方）。
static void z_armor_hit(Context& c){
 uint32_t obj=c.r[4],s=zspec(c,obj);
 if(!s||!(zw(c,s,0)&4u)||z_stage_of_hp(c,s,obj)>=zw(c,s,22))return;
 // 两个音效按当前生命的第 6 位交替（受击伤害多为 8 的倍数，低位不变）。
 uint32_t sid=zw(c,s,20u+((rd<uint32_t>(c,obj+0x308u)>>6)&1u));if(!sid)sid=zw(c,s,20);
 if(sid)msd_guest_call(c,Z_PLAY_SE,obj,sid,0u,0u,nullptr);
}
static void z_kill_sound(Context& c){
 uint32_t attacker=rd<uint32_t>(c,c.r[13]+8u),s=zspec(c,attacker);
 if(s&&(zw(c,s,0)&8u)&&zw(c,s,23))msd_guest_call(c,Z_PLAY_SE,attacker,zw(c,s,23),0u,0u,nullptr);
}
HOOK(zombie_no_knockback,0x1016f485u, uint32_t s=zspec(c,c.r[4]);if(s&&(zw(c,s,0)&2u)){c.pc=0x1016f4a3u;return;})
HOOK(zombie_armor_hit,0x1016f4a3u, z_armor_hit(c);)
HOOK(zombie_kill_sound,0x1016f44du, z_kill_sound(c);)
static bool z_throws(Context& c,uint32_t obj){uint32_t s=zspec(c,obj);return s&&(zw(c,s,0)&16u);}
// 前方最近敌人（行为库 v4：front_nearest_target，ZSpec 标记 64）。原生 setHeadPositionUnit 每帧按横坐标为两队各取最前单位
// （管理器 +0x30/+0x34 含 NoTarget，+0x38/+0x3c 不含；+0x30/+0x38 为队伍 0 的，+0x34/+0x3c 为队伍 1 的），
// getNearEnemyDistance、unitControlTypeNoukin 的阻挡判定与 isUnitMovePossible 的移动限制只看对方最前单位。单位落到对方最前单位之后
// （被投出的小鬼）时，距离为负，原生一直攻击而攻击框内没有敌人；与其重叠的对方单位也不能越过它移动，双方停在原地互相攻击不到。
// 本单位或对方最前单位带此标记、且对方最前单位的中心在本单位中心之后时，改取本单位前方（中心不在其后）的对方单位中前缘最近者：
// 资格同原生（存活，UnitID 0x8b/0x101/0x10c/0x10d 不检查；+0x64；身体状态非 Invisible 1、DontToche 8，攻击目标另排除 NoTarget 0x40），
// 前缘相同时取 +0xf0、再取 +0x60 较大者。前方没有对方单位时按原生的“无对方单位”处理。其余情形保持原生。
static constexpr uint32_t Z_AHEAD=64u;
static bool z_ahead(Context& c,uint32_t obj){uint32_t s=zspec(c,obj);return s&&(zw(c,s,0)&Z_AHEAD);}
// BattleObject::getWidthSize：精灵 +8（整数）乘 +0x28（浮点）后截断。
static int32_t z_width(Context& c,uint32_t obj){
 uint32_t sp=rd<uint32_t>(c,obj+0x5cu);
 return int32_t(float(int32_t(rd<uint32_t>(c,sp+8u)))*rd<float>(c,sp+0x28u));
}
static bool z_candidate(Context& c,uint32_t e,uint32_t excluded){
 if(!rd<uint8_t>(c,e+0x64u)||(rd<uint32_t>(c,e+0x6cu)&excluded))return false;
 uint32_t vt=rd<uint32_t>(c,e),uid=0u,alive=0u;
 msd_guest_call(c,rd<uint32_t>(c,vt+0x4cu),e,0u,0u,0u,&uid);
 if(uid==0x8bu||uid==0x101u||uid==0x10cu||uid==0x10du)return true;
 msd_guest_call(c,rd<uint32_t>(c,vt+0x5cu),e,0u,0u,0u,&alive);
 return alive!=0u;
}
// 单位 u（队伍 team）前方的对方单位中前缘最近者（对方队伍链表：队伍 0 的对方为 +0x1c，队伍 1 的对方为 +0x18，环形）。
static uint32_t z_nearest_ahead(Context& c,uint32_t manager,uint32_t u,uint32_t team,uint32_t excluded){
 uint32_t head=rd<uint32_t>(c,manager+(team?0x18u:0x1cu));if(!head)return 0u;
 float ux=rd<float>(c,u+0x8cu);uint32_t best=0u,bf=0u,bi=0u,e=head;int32_t bk=0;
 for(uint32_t n=0;n<8192u;++n){
  float ex=rd<float>(c,e+0x8cu);
  if((team?ex<=ux:ex>=ux)&&z_candidate(c,e,excluded)){
   float w=float(z_width(c,e));int32_t k=int32_t(team?ex+w:ex-w);
   uint32_t f=rd<uint32_t>(c,e+0xf0u),i=rd<uint16_t>(c,e+0x60u);
   if(!best||(team?k>bk:k<bk)||(k==bk&&(int32_t(f)>int32_t(bf)||(f==bf&&i>bi)))){best=e;bk=k;bf=f;bi=i;}
  }
  uint32_t next=rd<uint32_t>(c,e+0x124u);if(!next)break;e=next-0x11cu;if(e==head)break;
 }
 return best;
}
static bool z_front_behind(Context& c,uint32_t u,uint32_t f,uint32_t team){
 if(!f)return false;
 float ux=rd<float>(c,u+0x8cu),fx=rd<float>(c,f+0x8cu);
 if(team?!(fx>ux):!(fx<ux))return false;
 return z_ahead(c,u)||z_ahead(c,f);
}
// getNearEnemyDistance 入口（r0 管理器、r1 单位、r2 非 0 时扣除双方宽度）；计算次序同原生，结果截断为整数。
static bool z_distance(Context& c){
 uint32_t m=c.r[0],u=c.r[1],team=rd<uint32_t>(c,u+0x70u);
 if(!z_front_behind(c,u,rd<uint32_t>(c,m+(team?0x38u:0x3cu)),team))return false;
 uint32_t e=z_nearest_ahead(c,m,u,team,0x49u);
 if(!e){ret(c,0x7fffffffu);return true;}
 float ux=rd<float>(c,u+0x8cu),ex=rd<float>(c,e+0x8cu),d;
 if(c.r[2]){float wu=float(z_width(c,u)),we=float(z_width(c,e));d=team?((ux-wu)-we)-ex:((ex-we)-wu)-ux;}
 else d=team?ux-ex:ex-ux;
 ret(c,uint32_t(int32_t(d)));return true;
}
static Block old_zombie_ahead_distance;static void zombie_ahead_distance(Context& c){if(z_distance(c))return;old_zombie_ahead_distance(c);}
// unitControlTypeNoukin 的阻挡判定：0x1df780（队伍 0）与 0x1df7ea（队伍 1）入口处 r0 为管理器、r4 单位、
// r5 对方最前单位（含 NoTarget）、r7 队伍；r5 为 0 时原生按无对方单位前进至战场边界。
static void z_block_target(Context& c){
 uint32_t u=c.r[4],team=c.r[7];
 if(z_front_behind(c,u,c.r[5],team))c.r[5]=z_nearest_ahead(c,c.r[0],u,team,0x09u);
}
HOOK(zombie_ahead_block_p1,0x101df781u, z_block_target(c);)
HOOK(zombie_ahead_block_p2,0x101df7ebu, z_block_target(c);)
// BattleObjectManager::isUnitMovePossible（advanceFrame 移动后检查）：向前移动时不得越过对方最前单位（含 NoTarget）的后缘。
// 0x1df1fa（向右）与 0x1df23a（向左）入口处 r0 为管理器、r3 队伍、r4 单位、r5 对方最前单位；r5 为 0 时只受战场边界限制。
static void z_move_target(Context& c){
 uint32_t u=c.r[4],team=c.r[3];
 if(team<=1u&&z_front_behind(c,u,c.r[5],team))c.r[5]=z_nearest_ahead(c,c.r[0],u,team,0x09u);
}
HOOK(zombie_ahead_move_right,0x101df1fbu, z_move_target(c);)
HOOK(zombie_ahead_move_left,0x101df23bu, z_move_target(c);)
// 已登记的钩子数：首批 7 个全部找到时版本 1，另含前方最近敌人的 5 个时版本 2；宿主据此确认核心支持。
static uint32_t zombie_hooks=0u;
// 3：分档受击动作（标记 128，钩子数同 2）。4：另含雪地步兵类的分档入口（2026-10-13 冰车，共 13 个钩子）。
extern "C" __declspec(dllexport) uint32_t msd_community_zombie_version(){return zombie_hooks==13u?4u:zombie_hooks==12u?3u:zombie_hooks==7u?1u:0u;}
// 伞兵落地时，原生动作固定生成 UnitID 45；社区映射保留其正规军身份。投出子单位的生命分档单位同样经此映射（落地映射表登记子单位）。
HOOK(paratrooper_landing,0x101de225u, uint32_t uid=rd<uint32_t>(c,c.r[0]+0x128u);uint32_t p=record(c,uid);if(p&&(rd<uint32_t>(c,p+4u)==160u||z_throws(c,c.r[0]))&&c.r[1]==45u&&head(c,100)){uint32_t target=rd<uint32_t>(c,head(c,100)+(uid-U)*4u);if(target)c.r[1]=target;})
extern "C" __declspec(dllexport) uint32_t msd_community_paratrooper_landing_version(){return 1u;}
// 属性面板显示实际作战单位；其他调用保留购买与拥有状态的原生标识。
HOOK(menu_display_id,0x101652fdu, if(record(c,c.r[0])&&c.r[14]==0x101ecd31u&&head(c,104)){ret(c,rd<uint32_t>(c,head(c,104)+(c.r[0]-U)*4u));return;})
extern "C" __declspec(dllexport) uint32_t msd_community_display_status_version(){return 1u;}
// 地面木乃伊与虫群共享原生动画编号；本体击退恢复使用登记的独立槽。
HOOK(mummy_recovery,0x101de017u,
 if(active(c)&&c.r[1]==26u&&rd<uint32_t>(c,c.r[0])==head(c,84)&&head(c,108)){
  uint32_t uid=rd<uint32_t>(c,c.r[0]+0x128u);
  if(record(c,uid))c.r[1]=rd<uint32_t>(c,head(c,108)+(uid-U)*4u);
 })
// 修筑单位的浏览模式沿用原版初始化位置与完成箱体选择流程。
HOOK(mummy_viewer_setup,0x1020a665u,
 uint32_t p=record(c,c.r[4]);
 if(p&&rd<uint32_t>(c,p+4u)==77u&&head(c,104)&&rd<uint32_t>(c,head(c,104)+(c.r[4]-U)*4u)!=c.r[4]){
  wr<uint32_t>(c,c.r[5]+176u,300u);wr<uint32_t>(c,c.r[5]+180u,400u);
  c.pc=0x1020a9a7u;return;
 })
HOOK(mummy_viewer_child,0x1020a571u,
 uint32_t p=record(c,c.r[0]);if(p&&rd<uint32_t>(c,p+4u)==77u)c.r[0]=77u;
 )
HOOK(mummy_viewer_update,0x1020b0edu,
 uint32_t p=record(c,c.r[0]);if(p&&rd<uint32_t>(c,p+4u)==77u){
  uint32_t object=c.r[4];uint32_t state=rd<uint32_t>(c,object+0x7cu);
  if((state==10u||state==20u)&&rd<float>(c,object+0x8cu)<320.0f){
   wr<uint32_t>(c,object+0x80u,20u);wr<uint32_t>(c,object+0x84u,20u);
  }
  c.r[0]=77u;
 }
 )
HOOK(mummy_viewer_initial_state,0x1020ab2du,
 uint32_t object=rd<uint32_t>(c,c.r[7]+24u);
 if(object){uint32_t p=record(c,rd<uint32_t>(c,object+0x128u));
  if(p&&rd<uint32_t>(c,p+4u)==77u){wr<uint32_t>(c,object+0x80u,20u);wr<uint32_t>(c,object+0x84u,20u);}
 }
 )
extern "C" __declspec(dllexport) uint32_t msd_community_mummy_variant_version(){return 1u;}
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
// 自定义音效（M6）：头部 +152 为 1032 项的 SoundID → 24 字节音效记录指针表（宿主只为原生表中不存在的 SoundID 写入），
// +156 为登记数。原生音效缓存与引用计数数组（app+0x9b30、app+0xab54）按 SoundID 0..1031 定址，扩展 ID 位于该范围内。
HOOK(extension_music,0x101c6625u,
 if(c.r[1]==1031u&&rd<uint32_t>(c,0x1ffec000u)==0x45585431u){
  uint32_t bank=rd<uint32_t>(c,0x1ffec004u);if(bank){ret(c,bank);return;}
 }
 if(active(c)&&head(c,152)&&c.r[1]<1032u){
  uint32_t entry=rd<uint32_t>(c,head(c,152)+c.r[1]*4u);if(entry){ret(c,entry);return;}
 })
extern "C" __declspec(dllexport) uint32_t msd_community_sound_version(){return 1u;}
HOOK(extension_mission,0x101d09fdu,
 if(rd<uint32_t>(c,0x1ffec000u)==0x45585431u&&c.r[1]>=1000000u){
  uint32_t base=rd<uint32_t>(c,0x1ffec00cu);uint32_t count=rd<uint32_t>(c,0x1ffec010u);
  uint32_t i=c.r[1]-1000000u;
  if(i<count&&rd<uint32_t>(c,base+i*120u)==c.r[1]){ret(c,base+i*120u);return;}
  ret(c,0u);return;
 })
extern "C" __declspec(dllexport) uint32_t msd_content_interface_version(){return 1u;}
// KT-21 喷火受击收尾与单次击退限制（第 112 字节头字段：每单位 8 词）。
// 词 0 标记（1 启用收尾，2 启用击退限制）；词 1 喷火在槽 10 内的起点 tick，词 2 喷火时长；词 3 收尾受击槽起点；词 4..7 收尾弹体动画。
static uint32_t flame_entry(Context& c,uint32_t uid){
 if(!record(c,uid)||!head(c,112))return 0u;
 uint32_t e=head(c,112)+(uid-U)*32u;return rd<uint32_t>(c,e)?e:0u;
}
struct FlameMark{uint32_t target,target_id,owner,count;};
static FlameMark flame_marks[1024];static uint32_t flame_mark_count=0;
struct FlameOwner{uint32_t owner,count;};
static FlameOwner flame_owners[128];static uint32_t flame_owner_count=0;
void msd_flame_netplay_state(StateIO& io){         // 联机回滚：喷火击退记录属于战斗状态（netplay.h）
 io.field(flame_marks);io.field(flame_mark_count);io.field(flame_owners);io.field(flame_owner_count);
}
static uint32_t flame_owner_key(Context& c,uint32_t object){return uint32_t(rd<uint16_t>(c,object+0x62u))|((rd<uint32_t>(c,object+0x70u)&0xffu)<<16);}
static void flame_owner_store(uint32_t owner,uint32_t count){
 for(uint32_t i=0;i<flame_owner_count;++i)if(flame_owners[i].owner==owner){flame_owners[i].count=count;return;}
 if(flame_owner_count<128u)flame_owners[flame_owner_count++]={owner,count};
}
static bool flame_owner_count_of(uint32_t owner,uint32_t& count){
 for(uint32_t i=0;i<flame_owner_count;++i)if(flame_owners[i].owner==owner){count=flame_owners[i].count;return true;}
 return false;
}
// 原生 setAnimationID：喷火阶段转入受击动画 11 时，按已执行的喷火 tick 选择含收尾的受击槽。
static void flame_interrupt_select(Context& c){
 if(active(c)&&c.r[1]==11u&&rd<uint32_t>(c,c.r[0])==head(c,84)){
  uint32_t object=c.r[0],e=flame_entry(c,rd<uint32_t>(c,object+0x128u));
  if(e&&rd<uint32_t>(c,object+0x7cu)==80u&&rd<uint32_t>(c,object+0xc4u)==10u){
   uint32_t frames=rd<uint32_t>(c,rd<uint32_t>(c,object+0x5cu)+0x3cu);
   int32_t k=int32_t(frames)-1-int32_t(rd<uint32_t>(c,e+4u));
   int32_t span=int32_t(rd<uint32_t>(c,e+8u));
   if(k>=1&&k<span){uint32_t variant=k<=4?0u:k<=8?1u:k<=12?2u:k<span-5?3u:4u;c.r[1]=rd<uint32_t>(c,e+12u)+variant;}
  }
 }
}
HOOK(kt21_flame_interrupt,0x101de017u, flame_interrupt_select(c);)
// addBulletImpl：受击收尾槽发射的弹体改用登记的收尾动画、绝招参数组，命中与落地不切换动画（贯穿，动画结束后消失）。
static void flame_ending_bullet(Context& c){
 uint32_t owner=c.r[1];
 if(active(c)&&rd<uint32_t>(c,owner)==head(c,84)){
  uint32_t e=flame_entry(c,rd<uint32_t>(c,owner+0x128u));
  if(e){uint32_t animation=rd<uint32_t>(c,owner+0xc4u),base=rd<uint32_t>(c,e+12u);
   if(animation>=base&&animation<base+4u){
    uint32_t sp=c.r[13];
    wr<uint32_t>(c,sp+8u,50u);wr<uint32_t>(c,sp+0xcu,rd<uint32_t>(c,e+16u+(animation-base)*4u));
    wr<uint32_t>(c,sp+0x10u,0xfffffffeu);wr<uint32_t>(c,sp+0x14u,0xfffffffeu);
    flame_owner_store(flame_owner_key(c,owner),rd<uint32_t>(c,owner+0x324u));
   }
  }
 }
}
HOOK(kt21_flame_ending_bullet,0x1017d7fdu, flame_ending_bullet(c);)
// BattleUnit::damage 击退计量扣除处：同一次绝招的喷火对同一目标最多造成一次击退。
static void flame_knockback_limit(Context& c){
 if(active(c)){
  uint32_t attacker=c.r[5],target=c.r[4],vt=rd<uint32_t>(c,attacker);
  uint32_t e=flame_entry(c,rd<uint32_t>(c,attacker+0x128u));
  if(e&&(rd<uint32_t>(c,e)&2u)){
   uint32_t owner=flame_owner_key(c,attacker),count=0u;bool flame=false;
   if(vt==head(c,84)&&rd<uint32_t>(c,attacker+0x7cu)==50u){count=rd<uint32_t>(c,attacker+0x324u);flame_owner_store(owner,count);flame=true;}
   else if(vt==head(c,88)){
    uint32_t animation=rd<uint32_t>(c,attacker+0xc4u);
    for(uint32_t i=0;i<4u;++i)if(animation==rd<uint32_t>(c,e+16u+i*4u))flame=flame_owner_count_of(owner,count);
   }
   if(flame){
    uint32_t sp=c.r[13],target_id=flame_owner_key(c,target);bool seen=false;
    for(uint32_t i=0;i<flame_mark_count&&!seen;++i){const FlameMark& m=flame_marks[i];seen=m.target==target&&m.target_id==target_id&&m.owner==owner&&m.count==count;}
    int32_t gauge=int32_t(rd<uint32_t>(c,target+0x310u));
    // 已被本次绝招击退的目标：计量为正时不扣除；计量非正（原生每次受击均击退的单位）时保持计量为 1。
    if(seen)wr<int32_t>(c,sp+0x48u,gauge>0?0:gauge-1);
    else if(gauge-int32_t(rd<uint32_t>(c,sp+0x48u))<=0){
     if(flame_mark_count>=1024u)flame_mark_count=0u;
     flame_marks[flame_mark_count++]={target,target_id,owner,count};
    }
   }
  }
 }
}
HOOK(kt21_flame_knockback_limit,0x101e0b5du, flame_knockback_limit(c);)
// BattleObjectManager::initialize：战斗开始时清除上述记录。
HOOK(kt21_flame_battle_reset,0x101e019du, flame_mark_count=0u;flame_owner_count=0u;)
extern "C" __declspec(dllexport) uint32_t msd_community_flame_interrupt_version(){return 1u;}
// 地面绝招沿用 HeavyB 状态 50 的更新：动画与攻击等待后，每帧调用 actionMove(object,0)。
// 该流程保留脚本水平速度，并按原生规则处理坡地高度、阶差阻挡与下落。
HOOK(ground_special_update,0x10192571u,
 if(active(c)&&c.r[2]==50u&&head(c,116u)){
  uint32_t object=c.r[1];uint32_t uid=rd<uint32_t>(c,object+0x128u);
  if(record(c,uid)&&rd<uint32_t>(c,object)==head(c,84u)&&
     (rd<uint32_t>(c,head(c,116u)+(uid-U)*4u)&1u)){
   c.pc=0x1017a0adu;return;
  }
 }
)
extern "C" __declspec(dllexport) uint32_t msd_community_ground_special_version(){return 1u;}
// 多页单位图标（M1b）：页 0/1 为原版 unit_icon_01/02（菜单图像 33/34），页 2 起为社区图标页。
// 头部 +120 为页表、+124 为页数、+128 为扩展 ConvUnitIcon 地址；每页 16 字节：+0 文件名、+4 菜单纹理 Image*（宿主创建与释放）、
// +8 保留、+12 标记（位 0 菜单请求）。头部 +132 为战斗面板共用的页 ImageDesc，+136 为其中当前载入的页号（无为 0xffffffff）。
static uint32_t icon_page_entry(Context& c,int32_t page){
 if(!active(c)||page<2||uint32_t(page-2)>=head(c,124u)||!head(c,120u))return 0u;
 return head(c,120u)+uint32_t(page-2)*16u;
}
// GraphicsOpt::drawConv(Image**,…,const C_CONV*,…)：任务绘制共用的单矩形入口，按矩形 +0xe 的页号取 images[page]。
// 各场景把 unit_icon_01/02 载入不同的菜单图像槽（主菜单 33/34、编队 25/26），故以矩形本身判定：
// 矩形位于扩展 ConvUnitIcon（头部 +128）的社区段且页号 ≥2 时，把基址改到页表，使 images[page] 取得该页纹理。
// 纹理尚未创建时登记请求并跳过本次绘制，宿主在下一帧前创建。
static void icon_page_draw(Context& c){
 uint32_t conv=rd<uint32_t>(c,c.r[13]),table=head(c,128u);
 if(!active(c)||!table||conv<table+340u*16u||conv>=table+(340u+head(c,4u))*16u)return;
 int32_t page=rd<int16_t>(c,conv+14u);
 uint32_t e=icon_page_entry(c,page);
 if(!e)return;
 if(rd<uint32_t>(c,e+4u)){c.r[1]=e+4u-uint32_t(page)*4u;return;}
 wr<uint32_t>(c,e+12u,rd<uint32_t>(c,e+12u)|1u);
 c.pc=c.r[14];
}
static Block old_icon_page_draw_hook;
static void icon_page_draw_hook(Context& c){
 icon_page_draw(c);
 if(c.pc==c.r[14])return;
 old_icon_page_draw_hook(c);
}
// BattlePlayerOperator::createGrahics 的出兵格头像循环（块 0x101dacbc）：源图为 unit_icon_02 的 ImageDesc（fp）。
// 页号 ≥2 的社区单位改用共用的页 ImageDesc（头部 +132），+136 记录其中当前载入的页号。所需页未载入时调用
// ImageDesc::readFileFromOBM（其内部 create 先释放上一页像素，同一时刻只占一页内存）并返回循环头 0x101dacaa
// 重新取同一格（循环头只依赖被调用者保存的寄存器）。页图集在加载时已校验存在与格式。宿主在下一帧释放该 ImageDesc。
static bool battle_icon_source(Context& c,uint32_t rect){
 int32_t page=rd<int16_t>(c,rect+14u);
 uint32_t e=icon_page_entry(c,page),desc=head(c,132u);if(!e||!desc)return false;
 if(head(c,136u)==uint32_t(page)){if(rd<uint32_t>(c,desc))c.r[11]=desc;return false;}
 wr<uint32_t>(c,H+136u,uint32_t(page));
 c.r[0]=desc;c.r[1]=rd<uint32_t>(c,e);c.r[14]=0x101dacabu;c.pc=0x101c3badu;
 return true;
}
extern "C" __declspec(dllexport) uint32_t msd_community_icon_pages_version(){return 1u;}
// 保留强化武器（行为 retained_special_weapon）：返回 UnitID 对应的角色类（原版十类角色为其自身 UnitID）；
// 社区单位在逐单位行为标记（头部 +116）位 1 置位时取其基准 UnitID（行为库限定为这十类）；其他单位返回 0。
uint32_t msd_retained_class(Context& c,uint32_t uid){
 switch(uid){
  case 16u:case 17u:case 18u:case 19u:case 96u:case 97u:case 98u:case 99u:case 344u:case 362u:return uid;
  default:break;
 }
 uint32_t p=record(c,uid);
 if(p&&head(c,116u)&&(rd<uint32_t>(c,head(c,116u)+(uid-U)*4u)&2u))return rd<uint32_t>(c,p+4u);
 return 0u;
}
// 诊断计数：保留武器参数组替换次数，头部 +140 社区单位、+144 原版角色（只计数，不影响行为）。
void msd_retained_count(Context& c,uint32_t uid){
 if(!active(c))return;
 uint32_t field=H+(uid>=U?140u:144u);wr<uint32_t>(c,field,rd<uint32_t>(c,field)+1u);
}
extern "C" __declspec(dllexport) uint32_t msd_community_retained_weapon_version(){return 1u;}
// 行为库清单（模组 M2）：behavior_library.json 原文，由构建脚本生成 behavior_manifest.inc 嵌入。
#include "behavior_manifest.inc"
extern "C" __declspec(dllexport) const char* msd_behavior_manifest(){return BEHAVIOR_MANIFEST;}
// Generated block overrides and registration are emitted by the build script.
#include "community_blocks.inc"
