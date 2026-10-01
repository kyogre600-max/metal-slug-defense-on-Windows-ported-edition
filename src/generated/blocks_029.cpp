#include "../aot_runtime.h"
static void b_101b966e(Context& c){
{if(c.r[7] != 0){c.pc=(270243450u|1u);return;}}
c.pc=270243441u;}
static void b_101b9670(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[7];c.r[2]=v;}
{c.r[14]=270243451u;c.pc=(270393366u|1u);return;}
c.pc=270243451u;}
static void b_101b967a(Context& c){
{c.r[14]=270243455u;c.pc=(270408416u|1u);return;}
c.pc=270243455u;}
static void b_101b967e(Context& c){
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[1]=sbits(c,15);}
{c.r[14]=270243473u;c.pc=(270408818u|1u);return;}
c.pc=270243473u;}
static void b_101b9690(Context& c){
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[3]=sbits(c,15);}
{uint32_t v=add(c,c.r[0],~(280u),1,false);c.r[0]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[0]),1,true);}
{if(cond(c,11)){c.pc=(270243536u|1u);return;}}
c.pc=270243493u;}
static void b_101b96a4(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=5u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],28u,0,false);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270243505u;c.pc=c.r[3];return;}
c.pc=270243505u;}
static void b_101b96b0(Context& c){
{setfs(c,15,5.0);}
{uint32_t a=(c.r[13]+0u+28u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+48u);c.r[3]=rd<uint32_t>(c,a+0u);}
{setfs(c,15,(fs(c,14))*(fs(c,15)));}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{if(c.r[3] != 0){c.pc=(270243530u|1u);return;}}
c.pc=270243525u;}
static void b_101b96c4(Context& c){
{uint32_t v=1073741824u;c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);c.r[1]=rd<uint32_t>(c,a+0u);}
{c.pc=(270243980u|1u);return;}
c.pc=270243537u;}
static void b_101b96ca(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);c.r[1]=rd<uint32_t>(c,a+0u);}
{c.pc=(270243980u|1u);return;}
c.pc=270243537u;}
static void b_101b96d0(Context& c){
{uint32_t v=2u;nz(c,v);c.r[3]=v;}
{c.pc=(270243826u|1u);return;}
c.pc=270243541u;}
static void b_101b96d4(Context& c){
{uint32_t v=add(c,c.r[3],~(2u),1,true);}
{if(cond(c,2)){c.pc=(270243562u|1u);return;}}
c.pc=270243545u;}
static void b_101b96d8(Context& c){
{uint32_t v=5u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=280u;c.r[3]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[4]+0u+48u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270244510u|1u);return;}
c.pc=270243563u;}
static void b_101b96ea(Context& c){
{uint32_t v=add(c,c.r[3],~(5u),1,true);}
{if(cond(c,2)){c.pc=(270243650u|1u);return;}}
c.pc=270243567u;}
static void b_101b96ee(Context& c){
{uint32_t v=add(c,c.r[6],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270244492u|1u);return;}}
c.pc=270243573u;}
static void b_101b96f4(Context& c){
{uint32_t v=add(c,c.r[6],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270244492u|1u);return;}}
c.pc=270243579u;}
static void b_101b96fa(Context& c){
{uint32_t v=add(c,c.r[6],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270244492u|1u);return;}}
c.pc=270243585u;}
static void b_101b9700(Context& c){
{uint32_t v=add(c,c.r[6],~(80u),1,true);}
{if(cond(c,1)){c.pc=(270245292u|1u);return;}}
c.pc=270243591u;}
static void b_101b9706(Context& c){
{uint32_t v=add(c,c.r[6],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270244516u|1u);return;}}
c.pc=270243597u;}
static void b_101b970c(Context& c){
{uint32_t v=add(c,c.r[6],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270244080u|1u);return;}}
c.pc=270243603u;}
static void b_101b9712(Context& c){
{uint32_t a=(c.r[4]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{uint32_t v=add(c,c.r[3],4294967295u,0,false);c.r[2]=v;}
{uint32_t a=(c.r[4]+0u+40u);wr<uint32_t>(c,a+0u,c.r[2]);}
{if(cond(c,11)){c.pc=(270243650u|1u);return;}}
c.pc=270243615u;}
static void b_101b971e(Context& c){
{uint32_t v=add(c,c.r[6],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270244052u|1u);return;}}
c.pc=270243621u;}
static void b_101b9724(Context& c){
{uint32_t v=add(c,c.r[6],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270244052u|1u);return;}}
c.pc=270243627u;}
static void b_101b972a(Context& c){
{c.r[14]=270243631u;c.pc=(270394904u|1u);return;}
c.pc=270243631u;}
static void b_101b972e(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[3])^(1u);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],12u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[0]+shift(c,c.r[3],2,1,false)+0u);c.r[9]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[9],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270245164u|1u);return;}}
c.pc=270243651u;}
static void b_101b9742(Context& c){
{uint32_t v=add(c,c.r[6],~(51u),1,true);}
{if(cond(c,1)){c.pc=(270243942u|1u);return;}}
c.pc=270243657u;}
static void b_101b9748(Context& c){
{if(cond(c,13)){c.pc=(270243690u|1u);return;}}
c.pc=270243659u;}
static void b_101b974a(Context& c){
{uint32_t v=add(c,c.r[6],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270244052u|1u);return;}}
c.pc=270243665u;}
static void b_101b9750(Context& c){
{if(cond(c,13)){c.pc=(270243676u|1u);return;}}
c.pc=270243667u;}
static void b_101b9752(Context& c){
{uint32_t v=add(c,c.r[6],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270243726u|1u);return;}}
c.pc=270243671u;}
static void b_101b9756(Context& c){
{uint32_t v=add(c,c.r[6],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270243846u|1u);return;}}
c.pc=270243675u;}
static void b_101b975a(Context& c){
{c.pc=(270245292u|1u);return;}
c.pc=270243677u;}
static void b_101b975c(Context& c){
{uint32_t v=add(c,c.r[6],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270244052u|1u);return;}}
c.pc=270243683u;}
static void b_101b9762(Context& c){
{uint32_t v=add(c,c.r[6],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270244080u|1u);return;}}
c.pc=270243689u;}
static void b_101b9768(Context& c){
{c.pc=(270245292u|1u);return;}
c.pc=270243691u;}
static void b_101b976a(Context& c){
{uint32_t v=add(c,c.r[6],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270244492u|1u);return;}}
c.pc=270243697u;}
static void b_101b9770(Context& c){
{if(cond(c,13)){c.pc=(270243712u|1u);return;}}
c.pc=270243699u;}
static void b_101b9772(Context& c){
{uint32_t v=add(c,c.r[6],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270244448u|1u);return;}}
c.pc=270243705u;}
static void b_101b9778(Context& c){
{uint32_t v=add(c,c.r[6],~(100u),1,true);}
{if(cond(c,2)){c.pc=(270245292u|1u);return;}}
c.pc=270243711u;}
static void b_101b977e(Context& c){
{c.pc=(270244492u|1u);return;}
c.pc=270243713u;}
static void b_101b9780(Context& c){
{uint32_t v=add(c,c.r[6],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270244492u|1u);return;}}
c.pc=270243719u;}
static void b_101b9786(Context& c){
{uint32_t v=add(c,c.r[6],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270244516u|1u);return;}}
c.pc=270243725u;}
static void b_101b978c(Context& c){
{c.pc=(270245292u|1u);return;}
c.pc=270243727u;}
static void b_101b978e(Context& c){
{c.r[14]=270243731u;c.pc=(270394904u|1u);return;}
c.pc=270243731u;}
static void b_101b9792(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[3])^(1u);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],14u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[0]+shift(c,c.r[3],2,1,false)+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{if(c.r[3] == 0){c.pc=(270243830u|1u);return;}}
c.pc=270243745u;}
static void b_101b97a0(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{uint32_t a=((270243754u&~3u)+0u+712u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[3]+0u+148u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[2],~(90u),1,true);}
{if(cond(c,2)){c.pc=(270243782u|1u);return;}}
c.pc=270243763u;}
static void b_101b97b2(Context& c){
{setfs(c,14,(fs(c,13))-(fs(c,14)));}
{fcmp(c,fs(c,14),fs(c,15));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,14)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{c.pc=(270243800u|1u);return;}
c.pc=270243783u;}
static void b_101b97c6(Context& c){
{setfs(c,14,(fs(c,13))+(fs(c,14)));}
{fcmp(c,fs(c,14),fs(c,15));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,6)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,5)){uint32_t v=1u;c.r[3]=v;}}
{if(c.r[3] == 0){c.pc=(270243830u|1u);return;}}
c.pc=270243803u;}
static void b_101b97d8(Context& c){
{if(c.r[3] == 0){c.pc=(270243830u|1u);return;}}
c.pc=270243803u;}
static void b_101b97da(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270243815u;c.pc=(270393366u|1u);return;}
c.pc=270243815u;}
static void b_101b97e6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=51u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[14]=270243825u;c.pc=(270391848u|1u);return;}
c.pc=270243825u;}
static void b_101b97f0(Context& c){
{uint32_t v=3u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270245292u|1u);return;}
c.pc=270243831u;}
static void b_101b97f2(Context& c){
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270245292u|1u);return;}
c.pc=270243831u;}
static void b_101b97f6(Context& c){
{if(c.r[7] != 0){c.pc=(270243918u|1u);return;}}
c.pc=270243833u;}
static void b_101b97f8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[7];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270243845u;c.pc=(270393366u|1u);return;}
c.pc=270243845u;}
static void b_101b9804(Context& c){
{c.pc=(270243918u|1u);return;}
c.pc=270243847u;}
static void b_101b9806(Context& c){
{if(c.r[7] != 0){c.pc=(270243872u|1u);return;}}
c.pc=270243849u;}
static void b_101b9808(Context& c){
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[2];c.r[3]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{c.r[14]=270243861u;c.pc=(270393366u|1u);return;}
c.pc=270243861u;}
static void b_101b9814(Context& c){
{uint32_t a=(c.r[4]+0u+52u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(5u),1,true);}
{}
{if(cond(c,1)){uint32_t v=280u;c.r[3]=v;}}
{if(cond(c,1)){uint32_t a=(c.r[4]+0u+48u);wr<uint32_t>(c,a+0u,c.r[3]);}}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=5u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],28u,0,false);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270243885u;c.pc=c.r[3];return;}
c.pc=270243885u;}
static void b_101b9820(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=5u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],28u,0,false);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270243885u;c.pc=c.r[3];return;}
c.pc=270243885u;}
static void b_101b982c(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(270u),1,true);}
{if(cond(c,2)){c.pc=(270243904u|1u);return;}}
c.pc=270243893u;}
static void b_101b9834(Context& c){
{uint32_t a=(c.r[13]+0u+28u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,-(fs(c,15)));}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270243919u;c.pc=(270392848u|1u);return;}
c.pc=270243919u;}
static void b_101b9840(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270243919u;c.pc=(270392848u|1u);return;}
c.pc=270243919u;}
static void b_101b984e(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270243932u|1u);return;}}
c.pc=270243925u;}
static void b_101b9854(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270243933u;c.pc=(270243160u|1u);return;}
c.pc=270243933u;}
static void b_101b985c(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270243941u;c.pc=(270242448u|1u);return;}
c.pc=270243941u;}
static void b_101b9864(Context& c){
{c.pc=(270245292u|1u);return;}
c.pc=270243943u;}
static void b_101b9866(Context& c){
{uint32_t a=(c.r[4]+0u+52u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(3u),1,true);}
{if(cond(c,2)){c.pc=(270244042u|1u);return;}}
c.pc=270243949u;}
static void b_101b986c(Context& c){
{if(c.r[7] != 0){c.pc=(270243992u|1u);return;}}
c.pc=270243951u;}
static void b_101b986e(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=5u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],28u,0,false);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270243963u;c.pc=c.r[3];return;}
c.pc=270243963u;}
static void b_101b987a(Context& c){
{setfs(c,14,5.0);}
{uint32_t a=(c.r[13]+0u+28u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=c.r[4];c.r[0]=v;}
{setfs(c,14,-float((fs(c,14))*(fs(c,15))));}
{c.r[1]=sbits(c,14);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270243991u;c.pc=(270392910u|1u);return;}
c.pc=270243991u;}
static void b_101b988c(Context& c){
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270243991u;c.pc=(270392910u|1u);return;}
c.pc=270243991u;}
static void b_101b9896(Context& c){
{c.pc=(270245292u|1u);return;}
c.pc=270243993u;}
static void b_101b9898(Context& c){
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=((270244000u&~3u)+0u+468u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{fcmp(c,fs(c,14),fs(c,15));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,6)){c.pc=(270245292u|1u);return;}}
c.pc=270244013u;}
static void b_101b98ac(Context& c){
{c.r[14]=270244017u;c.pc=(270394904u|1u);return;}
c.pc=270244017u;}
static void b_101b98b0(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270244025u;c.pc=(270398272u|1u);return;}
c.pc=270244025u;}
static void b_101b98b8(Context& c){
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+140u);c.r[1]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270244039u;c.pc=(270393014u|1u);return;}
c.pc=270244039u;}
static void b_101b98c6(Context& c){
{uint32_t v=4u;nz(c,v);c.r[3]=v;}
{c.pc=(270243826u|1u);return;}
c.pc=270244043u;}
static void b_101b98ca(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270244508u|1u);return;}
c.pc=270244053u;}
static void b_101b98d4(Context& c){
{if(c.r[7] != 0){c.pc=(270244060u|1u);return;}}
c.pc=270244055u;}
static void b_101b98d6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{c.pc=(270244454u|1u);return;}
c.pc=270244061u;}
static void b_101b98dc(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270243932u|1u);return;}}
c.pc=270244069u;}
static void b_101b98e4(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.r[14]=270244079u;c.pc=(269980032u|1u);return;}
c.pc=270244079u;}
static void b_101b98ee(Context& c){
{c.pc=(270243932u|1u);return;}
c.pc=270244081u;}
static void b_101b98f0(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270244124u|1u);return;}}
c.pc=270244087u;}
static void b_101b98f6(Context& c){
{if(c.r[7] != 0){c.pc=(270244102u|1u);return;}}
c.pc=270244089u;}
static void b_101b98f8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[7];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270244101u;c.pc=(270393366u|1u);return;}
c.pc=270244101u;}
static void b_101b9904(Context& c){
{c.pc=(270244422u|1u);return;}
c.pc=270244103u;}
static void b_101b9906(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270244422u|1u);return;}}
c.pc=270244113u;}
static void b_101b9910(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=50u;nz(c,v);c.r[2]=v;}
{c.r[14]=270244123u;c.pc=(269980032u|1u);return;}
c.pc=270244123u;}
static void b_101b991a(Context& c){
{c.pc=(270244422u|1u);return;}
c.pc=270244125u;}
static void b_101b991c(Context& c){
{uint32_t v=add(c,c.r[7],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270244330u|1u);return;}}
c.pc=270244129u;}
static void b_101b9920(Context& c){
{c.r[14]=270244133u;c.pc=(270394904u|1u);return;}
c.pc=270244133u;}
static void b_101b9924(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[8];c.r[2]=v;}
{uint32_t v=(c.r[1])^(1u);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[6]=v;}
{c.r[14]=270244147u;c.pc=(270398272u|1u);return;}
c.pc=270244147u;}
static void b_101b9932(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=5u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],28u,0,false);c.r[2]=v;}
{uint32_t v=(c.r[3])^(1u);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],12u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[6]+shift(c,c.r[3],2,1,false)+0u);c.r[6]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270244173u;c.pc=c.r[3];return;}
c.pc=270244173u;}
static void b_101b994c(Context& c){
{setfs(c,15,5.0);}
{uint32_t a=(c.r[13]+0u+28u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{setfs(c,15,(fs(c,14))*(fs(c,15)));}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{if(c.r[7] == 0){c.pc=(270244236u|1u);return;}}
c.pc=270244191u;}
static void b_101b995e(Context& c){
{if(c.r[6] == 0){c.pc=(270244236u|1u);return;}}
c.pc=270244193u;}
static void b_101b9960(Context& c){
{uint32_t a=(c.r[7]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[6]+0u+140u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{setfs(c,14,(fs(c,14))-(fs(c,15)));}
{setsbits(c,14,cvti(fs(c,14),true));}
{c.r[3]=sbits(c,14);}
{uint32_t v=shift(c,c.r[3],1u,3,true);nz(c,v);c.r[3]=v;}
{setsbits(c,14,c.r[3]);}
{setfs(c,14,int32_t(sbits(c,14)));}
{setfs(c,15,(fs(c,14))+(fs(c,15)));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t a=(c.r[4]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.pc=(270244252u|1u);return;}
c.pc=270244237u;}
static void b_101b998c(Context& c){
{c.r[14]=270244241u;c.pc=(270408416u|1u);return;}
c.pc=270244241u;}
static void b_101b9990(Context& c){
{c.r[14]=270244245u;c.pc=(270408736u|1u);return;}
c.pc=270244245u;}
static void b_101b9994(Context& c){
{uint32_t v=add(c,c.r[0],shift(c,c.r[0],31,2,false),0,false);c.r[0]=v;}
{uint32_t v=shift(c,c.r[0],1u,3,true);nz(c,v);c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+20u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[4]+0u+20u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,14,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+24u);wr<uint32_t>(c,a+0u,c.r[3]);}
{fcmp(c,fs(c,14),fs(c,15));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,6)){c.pc=(270244296u|1u);return;}}
c.pc=270244279u;}
static void b_101b999c(Context& c){
{uint32_t a=(c.r[4]+0u+20u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,14,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+24u);wr<uint32_t>(c,a+0u,c.r[3]);}
{fcmp(c,fs(c,14),fs(c,15));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,6)){c.pc=(270244296u|1u);return;}}
c.pc=270244279u;}
static void b_101b99b6(Context& c){
{uint32_t a=(c.r[13]+0u+28u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,-(fs(c,15)));}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+24u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);c.r[1]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270244311u;c.pc=(270392848u|1u);return;}
c.pc=270244311u;}
static void b_101b99c8(Context& c){
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);c.r[1]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270244311u;c.pc=(270392848u|1u);return;}
c.pc=270244311u;}
static void b_101b99d6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270244319u;c.pc=(269976968u|1u);return;}
c.pc=270244319u;}
static void b_101b99de(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270244327u;c.pc=(269976986u|1u);return;}
c.pc=270244327u;}
static void b_101b99e6(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.pc=(270244402u|1u);return;}
c.pc=270244331u;}
static void b_101b99ea(Context& c){
{uint32_t a=(c.r[4]+0u+16u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270244406u|1u);return;}}
c.pc=270244337u;}
static void b_101b99f0(Context& c){
{uint32_t a=(c.r[4]+0u+20u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{setfs(c,14,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+24u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{fcmp(c,fs(c,14),fs(c,15));}
{if(cond(c,11)){c.pc=(270244370u|1u);return;}}
c.pc=270244359u;}
static void b_101b9a06(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,14)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{c.pc=(270244380u|1u);return;}
c.pc=270244371u;}
static void b_101b9a12(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,6)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,5)){uint32_t v=1u;c.r[3]=v;}}
{if(c.r[3] == 0){c.pc=(270244422u|1u);return;}}
c.pc=270244383u;}
static void b_101b9a1c(Context& c){
{if(c.r[3] == 0){c.pc=(270244422u|1u);return;}}
c.pc=270244383u;}
static void b_101b9a1e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270244389u;c.pc=(270393272u|1u);return;}
c.pc=270244389u;}
static void b_101b9a24(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270244401u;c.pc=(270393366u|1u);return;}
c.pc=270244401u;}
static void b_101b9a30(Context& c){
{uint32_t v=2u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+16u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270244422u|1u);return;}
c.pc=270244407u;}
static void b_101b9a32(Context& c){
{uint32_t a=(c.r[4]+0u+16u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270244422u|1u);return;}
c.pc=270244407u;}
static void b_101b9a36(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270244422u|1u);return;}}
c.pc=270244413u;}
static void b_101b9a3c(Context& c){
{uint32_t a=(c.r[4]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(9u),1,true);}
{if(cond(c,1)){c.pc=(270245276u|1u);return;}}
c.pc=270244423u;}
static void b_101b9a46(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270244431u;c.pc=(270242448u|1u);return;}
c.pc=270244431u;}
static void b_101b9a4e(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270245292u|1u);return;}}
c.pc=270244439u;}
static void b_101b9a56(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270244447u;c.pc=(270243160u|1u);return;}
c.pc=270244447u;}
static void b_101b9a5e(Context& c){
{c.pc=(270245292u|1u);return;}
c.pc=270244449u;}
static void b_101b9a60(Context& c){
{if(c.r[7] != 0){c.pc=(270244472u|1u);return;}}
c.pc=270244451u;}
static void b_101b9a62(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[7];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270244463u;c.pc=(270393366u|1u);return;}
c.pc=270244463u;}
static void b_101b9a66(Context& c){
{uint32_t v=c.r[7];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270244463u;c.pc=(270393366u|1u);return;}
c.pc=270244463u;}
static void b_101b9a6e(Context& c){
{c.pc=(270243932u|1u);return;}
c.pc=270244465u;}
static void b_101b9a78(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270243932u|1u);return;}}
c.pc=270244483u;}
static void b_101b9a82(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.r[14]=270244491u;c.pc=(270391848u|1u);return;}
c.pc=270244491u;}
static void b_101b9a8a(Context& c){
{c.pc=(270243932u|1u);return;}
c.pc=270244493u;}
static void b_101b9a8c(Context& c){
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270244505u;c.pc=(270393366u|1u);return;}
c.pc=270244505u;}
static void b_101b9a98(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=140u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270244515u;c.pc=(270391848u|1u);return;}
c.pc=270244515u;}
static void b_101b9a9c(Context& c){
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270244515u;c.pc=(270391848u|1u);return;}
c.pc=270244515u;}
static void b_101b9a9e(Context& c){
{c.r[14]=270244515u;c.pc=(270391848u|1u);return;}
c.pc=270244515u;}
static void b_101b9aa2(Context& c){
{c.pc=(270245292u|1u);return;}
c.pc=270244517u;}
static void b_101b9aa4(Context& c){
{c.r[14]=270244521u;c.pc=(270408416u|1u);return;}
c.pc=270244521u;}
static void b_101b9aa8(Context& c){
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[1]=sbits(c,15);}
{c.r[14]=270244539u;c.pc=(270408818u|1u);return;}
c.pc=270244539u;}
static void b_101b9aba(Context& c){
{setsbits(c,16,c.r[0]);}
{if(c.r[7] != 0){c.pc=(270244576u|1u);return;}}
c.pc=270244545u;}
static void b_101b9ac0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270244551u;c.pc=(270393272u|1u);return;}
c.pc=270244551u;}
static void b_101b9ac6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1073741824u;c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270244567u;c.pc=(270392910u|1u);return;}
c.pc=270244567u;}
static void b_101b9ad6(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270244575u;c.pc=(270242656u|1u);return;}
c.pc=270244575u;}
static void b_101b9ade(Context& c){
{c.pc=(270244670u|1u);return;}
c.pc=270244577u;}
static void b_101b9ae0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+152u);setsbits(c,17,rd<uint32_t>(c,a+0u));}
{c.r[14]=270244587u;c.pc=(270392138u|1u);return;}
c.pc=270244587u;}
static void b_101b9aea(Context& c){
{uint32_t v=3u;nz(c,v);c.r[1]=v;}
{c.r[14]=270244593u;c.pc=(270697408u|1u);return;}
c.pc=270244593u;}
static void b_101b9af0(Context& c){
{setfs(c,16,int32_t(sbits(c,16)));}
{setsbits(c,14,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{setfs(c,17,(fs(c,15))+(fs(c,17)));}
{fcmp(c,fs(c,16),fs(c,17));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,6)){c.pc=(270244670u|1u);return;}}
c.pc=270244619u;}
static void b_101b9b0a(Context& c){
{uint32_t v=65284u;c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[2];c.r[3]=v;}
{c.r[14]=270244645u;c.pc=(270015700u|1u);return;}
c.pc=270244645u;}
static void b_101b9b24(Context& c){
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270244657u;c.pc=(270393366u|1u);return;}
c.pc=270244657u;}
static void b_101b9b30(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270244665u;c.pc=(270242656u|1u);return;}
c.pc=270244665u;}
static void b_101b9b38(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270244671u;c.pc=(270391404u|1u);return;}
c.pc=270244671u;}
static void b_101b9b3e(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=25u;nz(c,v);c.r[1]=v;}
{c.r[14]=270244679u;c.pc=(270697604u|1u);return;}
c.pc=270244679u;}
static void b_101b9b46(Context& c){
{uint32_t v=add(c,c.r[1],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270245148u|1u);return;}}
c.pc=270244685u;}
static void b_101b9b4c(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270244691u;c.pc=(270082278u|1u);return;}
c.pc=270244691u;}
static void b_101b9b52(Context& c){
{uint32_t v=c.r[0];c.r[8]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270244699u;c.pc=(270082278u|1u);return;}
c.pc=270244699u;}
static void b_101b9b5a(Context& c){
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270244707u;c.pc=(270392138u|1u);return;}
c.pc=270244707u;}
static void b_101b9b62(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=c.r[8];c.r[0]=v;}
{c.r[14]=270244717u;c.pc=(270697604u|1u);return;}
c.pc=270244717u;}
static void b_101b9b6c(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=65283u;c.r[8]=v;}
{uint32_t v=1u;nz(c,v);c.r[7]=v;}
{uint32_t v=add(c,c.r[1],~(130u),1,false);c.r[9]=v;}
{uint32_t v=c.r[6];c.r[1]=v;}
{c.r[14]=270244735u;c.pc=(270697604u|1u);return;}
c.pc=270244735u;}
static void b_101b9b7e(Context& c){
{uint32_t v=4294967295u;c.r[6]=v;}
{uint32_t v=c.r[9];c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[7]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270244757u;c.pc=(270015700u|1u);return;}
c.pc=270244757u;}
static void b_101b9b94(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270244763u;c.pc=(270082278u|1u);return;}
c.pc=270244763u;}
static void b_101b9b9a(Context& c){
{uint32_t v=c.r[0];c.r[10]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270244771u;c.pc=(270082278u|1u);return;}
c.pc=270244771u;}
static void b_101b9ba2(Context& c){
{uint32_t v=c.r[0];c.r[11]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270244779u;c.pc=(270392138u|1u);return;}
c.pc=270244779u;}
static void b_101b9baa(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[9]=v;}
{uint32_t v=c.r[10];c.r[0]=v;}
{c.r[14]=270244789u;c.pc=(270697604u|1u);return;}
c.pc=270244789u;}
static void b_101b9bb4(Context& c){
{uint32_t v=c.r[11];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(80u),1,false);c.r[10]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{c.r[14]=270244801u;c.pc=(270697604u|1u);return;}
c.pc=270244801u;}
static void b_101b9bc0(Context& c){
{uint32_t v=65284u;c.r[9]=v;}
{uint32_t v=c.r[10];c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[1];c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270244825u;c.pc=(270015700u|1u);return;}
c.pc=270244825u;}
static void b_101b9bd8(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270244831u;c.pc=(270082278u|1u);return;}
c.pc=270244831u;}
static void b_101b9bde(Context& c){
{uint32_t v=c.r[0];c.r[10]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270244839u;c.pc=(270082278u|1u);return;}
c.pc=270244839u;}
static void b_101b9be6(Context& c){
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270244849u;c.pc=(270392138u|1u);return;}
c.pc=270244849u;}
static void b_101b9bf0(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[11]=v;}
{uint32_t v=c.r[10];c.r[0]=v;}
{c.r[14]=270244859u;c.pc=(270697604u|1u);return;}
c.pc=270244859u;}
static void b_101b9bfa(Context& c){
{uint32_t a=(c.r[13]+0u+20u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(40u),1,false);c.r[10]=v;}
{uint32_t v=c.r[11];c.r[1]=v;}
{c.r[14]=270244873u;c.pc=(270697604u|1u);return;}
c.pc=270244873u;}
static void b_101b9c08(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[7]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[10];c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270244891u;c.pc=(270015700u|1u);return;}
c.pc=270244891u;}
static void b_101b9c1a(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270244897u;c.pc=(270082278u|1u);return;}
c.pc=270244897u;}
static void b_101b9c20(Context& c){
{uint32_t v=c.r[0];c.r[10]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270244905u;c.pc=(270082278u|1u);return;}
c.pc=270244905u;}
static void b_101b9c28(Context& c){
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270244915u;c.pc=(270392138u|1u);return;}
c.pc=270244915u;}
static void b_101b9c32(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[11]=v;}
{uint32_t v=c.r[10];c.r[0]=v;}
{c.r[14]=270244925u;c.pc=(270697604u|1u);return;}
c.pc=270244925u;}
static void b_101b9c3c(Context& c){
{uint32_t a=(c.r[13]+0u+20u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[10]=v;}
{uint32_t v=c.r[11];c.r[1]=v;}
{c.r[14]=270244937u;c.pc=(270697604u|1u);return;}
c.pc=270244937u;}
static void b_101b9c48(Context& c){
{uint32_t v=c.r[10];c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[7]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[1];c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270244955u;c.pc=(270015700u|1u);return;}
c.pc=270244955u;}
static void b_101b9c5a(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270244961u;c.pc=(270082278u|1u);return;}
c.pc=270244961u;}
static void b_101b9c60(Context& c){
{uint32_t v=c.r[0];c.r[10]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270244969u;c.pc=(270082278u|1u);return;}
c.pc=270244969u;}
static void b_101b9c68(Context& c){
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270244979u;c.pc=(270392138u|1u);return;}
c.pc=270244979u;}
static void b_101b9c72(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[11]=v;}
{uint32_t v=c.r[10];c.r[0]=v;}
{c.r[14]=270244989u;c.pc=(270697604u|1u);return;}
c.pc=270244989u;}
static void b_101b9c7c(Context& c){
{uint32_t a=(c.r[13]+0u+20u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],80u,0,false);c.r[10]=v;}
{uint32_t v=c.r[11];c.r[1]=v;}
{c.r[14]=270245003u;c.pc=(270697604u|1u);return;}
c.pc=270245003u;}
static void b_101b9c8a(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[7]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[10];c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270245021u;c.pc=(270015700u|1u);return;}
c.pc=270245021u;}
static void b_101b9c9c(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270245027u;c.pc=(270082278u|1u);return;}
c.pc=270245027u;}
static void b_101b9ca2(Context& c){
{uint32_t v=c.r[0];c.r[10]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270245035u;c.pc=(270082278u|1u);return;}
c.pc=270245035u;}
static void b_101b9caa(Context& c){
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270245045u;c.pc=(270392138u|1u);return;}
c.pc=270245045u;}
static void b_101b9cb4(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[11]=v;}
{uint32_t v=c.r[10];c.r[0]=v;}
{c.r[14]=270245055u;c.pc=(270697604u|1u);return;}
c.pc=270245055u;}
static void b_101b9cbe(Context& c){
{uint32_t a=(c.r[13]+0u+20u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],30u,0,false);c.r[10]=v;}
{uint32_t v=c.r[11];c.r[1]=v;}
{c.r[14]=270245069u;c.pc=(270697604u|1u);return;}
c.pc=270245069u;}
static void b_101b9ccc(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[7]);wr<uint32_t>(c,a+4u,c.r[9]);}
{uint32_t v=c.r[10];c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270245087u;c.pc=(270015700u|1u);return;}
c.pc=270245087u;}
static void b_101b9cde(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270245093u;c.pc=(270082278u|1u);return;}
c.pc=270245093u;}
static void b_101b9ce4(Context& c){
{uint32_t v=c.r[0];c.r[9]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270245101u;c.pc=(270082278u|1u);return;}
c.pc=270245101u;}
static void b_101b9cec(Context& c){
{uint32_t v=c.r[0];c.r[11]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270245109u;c.pc=(270392138u|1u);return;}
c.pc=270245109u;}
static void b_101b9cf4(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[10]=v;}
{uint32_t v=c.r[9];c.r[0]=v;}
{c.r[14]=270245119u;c.pc=(270697604u|1u);return;}
c.pc=270245119u;}
static void b_101b9cfe(Context& c){
{uint32_t v=c.r[11];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],130u,0,false);c.r[9]=v;}
{uint32_t v=c.r[10];c.r[1]=v;}
{c.r[14]=270245131u;c.pc=(270697604u|1u);return;}
c.pc=270245131u;}
static void b_101b9d0a(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[7]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[9];c.r[2]=v;}
{uint32_t v=c.r[1];c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270245149u;c.pc=(270015700u|1u);return;}
c.pc=270245149u;}
static void b_101b9d1c(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270245157u;c.pc=(270242552u|1u);return;}
c.pc=270245157u;}
static void b_101b9d24(Context& c){
{c.pc=(270245292u|1u);return;}
c.pc=270245159u;}
static void b_101b9d26(Context& c){
{uint32_t v=3u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270243412u|1u);return;}
c.pc=270245165u;}
static void b_101b9d2c(Context& c){
{uint32_t v=add(c,c.r[13],32u,0,false);c.r[2]=v;}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[2]+0u+4294967292u);uint32_t wb=a;wr<uint32_t>(c,a+0u,c.r[3]);c.r[2]=wb;}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270245183u;c.pc=c.r[3];return;}
c.pc=270245183u;}
static void b_101b9d3e(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+28u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(270u),1,true);}
{uint32_t a=(c.r[9]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,13,int32_t(sbits(c,13)));}
{if(cond(c,2)){c.pc=(270245226u|1u);return;}}
c.pc=270245207u;}
static void b_101b9d56(Context& c){
{setfs(c,14,(fs(c,14))-(fs(c,13)));}
{fcmp(c,fs(c,15),fs(c,14));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,14)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{c.pc=(270245244u|1u);return;}
c.pc=270245227u;}
static void b_101b9d6a(Context& c){
{setfs(c,14,(fs(c,13))+(fs(c,14)));}
{fcmp(c,fs(c,15),fs(c,14));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,6)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,5)){uint32_t v=1u;c.r[3]=v;}}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270243650u|1u);return;}}
c.pc=270245251u;}
static void b_101b9d7c(Context& c){
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270243650u|1u);return;}}
c.pc=270245251u;}
static void b_101b9d82(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=30u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[14]=270245261u;c.pc=(270391848u|1u);return;}
c.pc=270245261u;}
static void b_101b9d8c(Context& c){
{uint32_t v=c.r[4];c.r[2]=v;}
{uint32_t a=(c.r[2]+0u+0u);uint32_t wb=c.r[2]+40u;c.r[3]=rd<uint32_t>(c,a+0u);c.r[2]=wb;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=17u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270245275u;c.pc=c.r[3];return;}
c.pc=270245275u;}
static void b_101b9d9a(Context& c){
{c.pc=(270245292u|1u);return;}
c.pc=270245277u;}
static void b_101b9d9c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=51u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[8];c.r[2]=v;}
{c.r[14]=270245287u;c.pc=(270391848u|1u);return;}
c.pc=270245287u;}
static void b_101b9da6(Context& c){
{uint32_t v=3u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270244422u|1u);return;}
c.pc=270245293u;}
static void b_101b9dac(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.r[13]=a+8u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);uint32_t newpc=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;c.pc=newpc;return;}
c.pc=270245303u;}
static void b_101b9db8(Context& c){
{uint32_t a=(c.r[1]+0u+252u);c.r[3]=rd<uint32_t>(c,a+0u);}
{if(c.r[3] == 0){c.pc=(270245344u|1u);return;}}
c.pc=270245311u;}
static void b_101b9dbe(Context& c){
{uint32_t a=(c.r[1]+0u+36u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,14,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[1]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t a=((270245326u&~3u)+0u+24u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[3]+0u+152u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[3]+0u+144u);wr<uint32_t>(c,a+0u,c.r[2]);}
{setfs(c,15,(fs(c,14))+(fs(c,15)));}
{uint32_t a=(c.r[3]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[3]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.pc=c.r[14];return;}
c.pc=270245347u;}
static void b_101b9de0(Context& c){
{c.pc=c.r[14];return;}
c.pc=270245347u;}
static void b_101b9de8(Context& c){
{uint32_t a=c.r[13]-36u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[11]);wr<uint32_t>(c,a+32u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-24u;wr<uint64_t>(c,a+0u,c.d[8]);wr<uint64_t>(c,a+8u,c.d[9]);wr<uint64_t>(c,a+16u,c.d[10]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[4]=v;}
{uint32_t a=((270245366u&~3u)+0u+468u);setsbits(c,18,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[13],~(36u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[5]=v;}
{c.r[14]=270245377u;c.pc=(270392110u|1u);return;}
c.pc=270245377u;}
static void b_101b9e00(Context& c){
{uint32_t v=0u;nz(c,v);c.r[6]=v;}
{uint32_t v=4294967295u;c.r[7]=v;}
{uint32_t v=65284u;c.r[8]=v;}
{setfs(c,21,-16.0);}
{uint32_t a=((270245394u&~3u)+0u+444u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{setfs(c,17,-10.0);}
{setfs(c,20,16.0);}
{uint32_t v=c.r[0];c.r[10]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270245411u;c.pc=(270392138u|1u);return;}
c.pc=270245411u;}
static void b_101b9e22(Context& c){
{uint32_t v=c.r[10];c.r[2]=v;}
{uint32_t v=c.r[6];c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{setfs(c,19,-8.0);}
{uint32_t v=c.r[0];c.r[11]=v;}
{uint32_t v=shift(c,c.r[0],1u,3,false);c.r[9]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270245439u;c.pc=(270015700u|1u);return;}
c.pc=270245439u;}
static void b_101b9e3e(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=5u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270245457u;c.pc=(270015700u|1u);return;}
c.pc=270245457u;}
static void b_101b9e50(Context& c){
{uint32_t v=add(c,0u,~(c.r[10]),1,false);c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270245477u;c.pc=(270015700u|1u);return;}
c.pc=270245477u;}
static void b_101b9e64(Context& c){
{uint32_t v=shift(c,c.r[10],1u,3,false);c.r[12]=v;}
{uint32_t v=add(c,0u,~(c.r[9]),1,false);c.r[10]=v;}
{uint32_t v=add(c,c.r[12],10u,0,false);c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[10];c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[12]);}
{c.r[14]=270245509u;c.pc=(270015700u|1u);return;}
c.pc=270245509u;}
static void b_101b9e84(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[12]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[10];c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=~(9u);c.r[2]=v;}
{uint32_t v=add(c,c.r[2],~(c.r[12]),1,false);c.r[2]=v;}
{uint32_t v=shift(c,c.r[11],2u,3,false);c.r[6]=v;}
{c.r[14]=270245541u;c.pc=(270015700u|1u);return;}
c.pc=270245541u;}
static void b_101b9ea4(Context& c){
{uint32_t a=(c.r[5]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=8u;c.r[11]=v;}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,2)){uint32_t v=c.r[7];c.r[10]=v;}}
{if(cond(c,1)){uint32_t v=1u;c.r[10]=v;}}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270245563u;c.pc=(270082278u|1u);return;}
c.pc=270245563u;}
static void b_101b9eb4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270245563u;c.pc=(270082278u|1u);return;}
c.pc=270245563u;}
static void b_101b9eba(Context& c){
{uint32_t v=c.r[0];c.r[8]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270245571u;c.pc=(270082278u|1u);return;}
c.pc=270245571u;}
static void b_101b9ec2(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[8];c.r[0]=v;}
{c.r[14]=270245581u;c.pc=(270697604u|1u);return;}
c.pc=270245581u;}
static void b_101b9ecc(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=0u;c.r[8]=v;}
{uint32_t v=1u;nz(c,v);c.r[7]=v;}
{uint32_t v=add(c,c.r[1],~(130u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270245603u;c.pc=(270697604u|1u);return;}
c.pc=270245603u;}
static void b_101b9ee2(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,21));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=shift(c,c.r[1],1u,1,true);nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);c.r[3]=v;}
{c.r[14]=270245639u;c.pc=(270091396u|1u);return;}
c.pc=270245639u;}
static void b_101b9f06(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270245645u;c.pc=(270082278u|1u);return;}
c.pc=270245645u;}
static void b_101b9f0c(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270245655u;c.pc=(270082278u|1u);return;}
c.pc=270245655u;}
static void b_101b9f16(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270245669u;c.pc=(270697604u|1u);return;}
c.pc=270245669u;}
static void b_101b9f24(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],30u,0,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270245687u;c.pc=(270697604u|1u);return;}
c.pc=270245687u;}
static void b_101b9f36(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,20));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=shift(c,c.r[1],(c.r[7]&255u),1,false);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);c.r[3]=v;}
{c.r[14]=270245725u;c.pc=(270082284u|1u);return;}
c.pc=270245725u;}
static void b_101b9f5c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270245731u;c.pc=(270082278u|1u);return;}
c.pc=270245731u;}
static void b_101b9f62(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270245741u;c.pc=(270082278u|1u);return;}
c.pc=270245741u;}
static void b_101b9f6c(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270245755u;c.pc=(270697604u|1u);return;}
c.pc=270245755u;}
static void b_101b9f7a(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(50u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270245773u;c.pc=(270697604u|1u);return;}
c.pc=270245773u;}
static void b_101b9f8c(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,19));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=shift(c,c.r[1],(c.r[7]&255u),1,false);c.r[3]=v;}
{uint32_t v=1090519040u;c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270245813u;c.pc=(270082284u|1u);return;}
c.pc=270245813u;}
static void b_101b9fb4(Context& c){
{uint32_t v=add(c,c.r[11],~(1u),1,true);c.r[11]=v;}
{if(cond(c,2)){c.pc=(270245556u|1u);return;}}
c.pc=270245821u;}
static void b_101b9fbc(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.d[10]=rd<uint64_t>(c,a+16u);c.r[13]=a+24u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);uint32_t newpc=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;c.pc=newpc;return;}
c.pc=270245831u;}
static void b_101b9fd0(Context& c){
{uint32_t a=c.r[13]-40u;wr<uint32_t>(c,a+0u,c.r[0]);wr<uint32_t>(c,a+4u,c.r[1]);wr<uint32_t>(c,a+8u,c.r[2]);wr<uint32_t>(c,a+12u,c.r[3]);wr<uint32_t>(c,a+16u,c.r[4]);wr<uint32_t>(c,a+20u,c.r[5]);wr<uint32_t>(c,a+24u,c.r[6]);wr<uint32_t>(c,a+28u,c.r[7]);wr<uint32_t>(c,a+32u,c.r[8]);wr<uint32_t>(c,a+36u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[3];c.r[5]=v;}
{uint32_t a=(c.r[1]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[2];c.r[6]=v;}
{if(c.r[3] != 0){c.pc=(270245860u|1u);return;}}
c.pc=270245857u;}
static void b_101b9fe0(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[6],~(80u),1,true);}
{if(cond(c,1)){c.pc=(270246082u|1u);return;}}
c.pc=270245865u;}
static void b_101b9fe4(Context& c){
{uint32_t v=add(c,c.r[6],~(80u),1,true);}
{if(cond(c,1)){c.pc=(270246082u|1u);return;}}
c.pc=270245865u;}
static void b_101b9fe8(Context& c){
{if(cond(c,13)){c.pc=(270245898u|1u);return;}}
c.pc=270245867u;}
static void b_101b9fea(Context& c){
{uint32_t v=add(c,c.r[6],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270245982u|1u);return;}}
c.pc=270245871u;}
static void b_101b9fee(Context& c){
{if(cond(c,13)){c.pc=(270245882u|1u);return;}}
c.pc=270245873u;}
static void b_101b9ff0(Context& c){
{uint32_t v=add(c,c.r[6],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270245942u|1u);return;}}
c.pc=270245877u;}
static void b_101b9ff4(Context& c){
{uint32_t v=add(c,c.r[6],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270245954u|1u);return;}}
c.pc=270245881u;}
static void b_101b9ff8(Context& c){
{c.pc=(270246534u|1u);return;}
c.pc=270245883u;}
static void b_101b9ffa(Context& c){
{uint32_t v=add(c,c.r[6],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270246022u|1u);return;}}
c.pc=270245887u;}
static void b_101b9ffe(Context& c){
{uint32_t v=add(c,c.r[6],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270246126u|1u);return;}}
c.pc=270245891u;}
static void b_101ba002(Context& c){
{uint32_t v=add(c,c.r[6],~(40u),1,true);}
{if(cond(c,2)){c.pc=(270246534u|1u);return;}}
c.pc=270245897u;}
static void b_101ba008(Context& c){
{c.pc=(270246002u|1u);return;}
c.pc=270245899u;}
static void b_101ba00a(Context& c){
{uint32_t v=add(c,c.r[6],~(121u),1,true);}
{if(cond(c,1)){c.pc=(270246208u|1u);return;}}
c.pc=270245905u;}
static void b_101ba010(Context& c){
{if(cond(c,13)){c.pc=(270245922u|1u);return;}}
c.pc=270245907u;}
static void b_101ba012(Context& c){
{uint32_t v=add(c,c.r[6],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270246150u|1u);return;}}
c.pc=270245911u;}
static void b_101ba016(Context& c){
{uint32_t v=add(c,c.r[6],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270246150u|1u);return;}}
c.pc=270245915u;}
static void b_101ba01a(Context& c){
{uint32_t v=add(c,c.r[6],~(100u),1,true);}
{if(cond(c,2)){c.pc=(270246534u|1u);return;}}
c.pc=270245921u;}
static void b_101ba020(Context& c){
{c.pc=(270246150u|1u);return;}
c.pc=270245923u;}
static void b_101ba022(Context& c){
{uint32_t v=add(c,c.r[6],~(123u),1,true);}
{if(cond(c,1)){c.pc=(270246372u|1u);return;}}
c.pc=270245929u;}
static void b_101ba028(Context& c){
{if(cond(c,12)){c.pc=(270246324u|1u);return;}}
c.pc=270245933u;}
static void b_101ba02c(Context& c){
{uint32_t v=add(c,c.r[6],~(140u),1,true);}
{if(cond(c,2)){c.pc=(270246534u|1u);return;}}
c.pc=270245939u;}
static void b_101ba032(Context& c){
{uint32_t v=0u;nz(c,v);c.r[5]=v;}
{c.pc=(270246490u|1u);return;}
c.pc=270245943u;}
static void b_101ba036(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270246534u|1u);return;}}
c.pc=270245949u;}
static void b_101ba03c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270245988u|1u);return;}
c.pc=270245955u;}
static void b_101ba042(Context& c){
{if(c.r[5] != 0){c.pc=(270245974u|1u);return;}}
c.pc=270245957u;}
static void b_101ba044(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270245969u;c.pc=(270393366u|1u);return;}
c.pc=270245969u;}
static void b_101ba050(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270245982u&~3u)+0u+560u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270246116u|1u);return;}
c.pc=270245983u;}
static void b_101ba056(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270245982u&~3u)+0u+560u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270246116u|1u);return;}
c.pc=270245983u;}
static void b_101ba05e(Context& c){
{if(c.r[5] != 0){c.pc=(270246010u|1u);return;}}
c.pc=270245985u;}
static void b_101ba060(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270393366u|1u);return;}
c.pc=270246003u;}
static void b_101ba064(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270393366u|1u);return;}
c.pc=270246003u;}
static void b_101ba072(Context& c){
{if(c.r[5] != 0){c.pc=(270246010u|1u);return;}}
c.pc=270246005u;}
static void b_101ba074(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{c.pc=(270245988u|1u);return;}
c.pc=270246011u;}
static void b_101ba07a(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270246534u|1u);return;}}
c.pc=270246021u;}
static void b_101ba084(Context& c){
{c.pc=(270246066u|1u);return;}
c.pc=270246023u;}
static void b_101ba086(Context& c){
{if(c.r[5] != 0){c.pc=(270246050u|1u);return;}}
c.pc=270246025u;}
static void b_101ba088(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270246037u;c.pc=(270393366u|1u);return;}
c.pc=270246037u;}
static void b_101ba094(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(269975948u|1u);return;}
c.pc=270246051u;}
static void b_101ba0a2(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[1]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[1],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270246534u|1u);return;}}
c.pc=270246061u;}
static void b_101ba0ac(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270246067u;c.pc=(269975948u|1u);return;}
c.pc=270246067u;}
static void b_101ba0b2(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(269980032u|1u);return;}
c.pc=270246083u;}
static void b_101ba0c2(Context& c){
{if(c.r[5] != 0){c.pc=(270246098u|1u);return;}}
c.pc=270246085u;}
static void b_101ba0c4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270246097u;c.pc=(270393366u|1u);return;}
c.pc=270246097u;}
static void b_101ba0d0(Context& c){
{c.pc=(270246110u|1u);return;}
c.pc=270246099u;}
static void b_101ba0d2(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270246110u|1u);return;}}
c.pc=270246105u;}
static void b_101ba0d8(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(269978432u|1u);return;}
c.pc=270246127u;}
static void b_101ba0de(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(269978432u|1u);return;}
c.pc=270246127u;}
static void b_101ba0e4(Context& c){
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(269978432u|1u);return;}
c.pc=270246127u;}
static void b_101ba0ee(Context& c){
{if(c.r[5] != 0){c.pc=(270246134u|1u);return;}}
c.pc=270246129u;}
static void b_101ba0f0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270245988u|1u);return;}
c.pc=270246135u;}
static void b_101ba0f6(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270246534u|1u);return;}}
c.pc=270246145u;}
static void b_101ba100(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270246186u|1u);return;}
c.pc=270246151u;}
static void b_101ba106(Context& c){
{if(c.r[5] != 0){c.pc=(270246196u|1u);return;}}
c.pc=270246153u;}
static void b_101ba108(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270246165u;c.pc=(270393366u|1u);return;}
c.pc=270246165u;}
static void b_101ba114(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270246173u;c.pc=(270245352u|1u);return;}
c.pc=270246173u;}
static void b_101ba11c(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270246534u|1u);return;}}
c.pc=270246181u;}
static void b_101ba124(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=121u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270391848u|1u);return;}
c.pc=270246197u;}
static void b_101ba12a(Context& c){
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270391848u|1u);return;}
c.pc=270246197u;}
static void b_101ba134(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270246534u|1u);return;}}
c.pc=270246207u;}
static void b_101ba13e(Context& c){
{c.pc=(270246514u|1u);return;}
c.pc=270246209u;}
static void b_101ba140(Context& c){
{if(c.r[5] != 0){c.pc=(270246310u|1u);return;}}
c.pc=270246211u;}
static void b_101ba142(Context& c){
{uint32_t v=59u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270246223u;c.pc=(270393366u|1u);return;}
c.pc=270246223u;}
static void b_101ba14e(Context& c){
{uint32_t v=62u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t a=((270246232u&~3u)+0u+312u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=add(c,c.r[3],270246240u,0,false);c.r[3]=v;}
{uint32_t a=(c.r[3]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270246249u;c.pc=(270077468u|1u);return;}
c.pc=270246249u;}
static void b_101ba168(Context& c){
{if(c.r[0] == 0){c.pc=(270246254u|1u);return;}}
c.pc=270246251u;}
static void b_101ba16a(Context& c){
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[0]);}
{c.r[14]=270246259u;c.pc=(270408416u|1u);return;}
c.pc=270246259u;}
static void b_101ba16e(Context& c){
{c.r[14]=270246259u;c.pc=(270408416u|1u);return;}
c.pc=270246259u;}
static void b_101ba172(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(270u),1,true);}
{if(cond(c,2)){c.pc=(270246288u|1u);return;}}
c.pc=270246267u;}
static void b_101ba17a(Context& c){
{c.r[14]=270246271u;c.pc=(270408736u|1u);return;}
c.pc=270246271u;}
static void b_101ba17e(Context& c){
{setsbits(c,15,c.r[0]);}
{setfs(c,14,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,(fs(c,14))-(fs(c,15)));}
{c.pc=(270246292u|1u);return;}
c.pc=270246289u;}
static void b_101ba190(Context& c){
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=122u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270246311u;c.pc=(270391848u|1u);return;}
c.pc=270246311u;}
static void b_101ba194(Context& c){
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=122u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270246311u;c.pc=(270391848u|1u);return;}
c.pc=270246311u;}
static void b_101ba1a0(Context& c){
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270246311u;c.pc=(270391848u|1u);return;}
c.pc=270246311u;}
static void b_101ba1a6(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270245304u|1u);return;}
c.pc=270246325u;}
static void b_101ba1b4(Context& c){
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,13)){c.pc=(270246366u|1u);return;}}
c.pc=270246331u;}
static void b_101ba1ba(Context& c){
{uint32_t v=0u;nz(c,v);c.r[5]=v;}
{uint32_t v=c.r[5];c.r[8]=v;}
{uint32_t v=add(c,c.r[4],c.r[5],0,true);c.r[6]=v;}
{uint32_t a=(c.r[6]+0u+252u);c.r[0]=rd<uint32_t>(c,a+0u);}
{if(c.r[0] == 0){c.pc=(270246350u|1u);return;}}
c.pc=270246343u;}
static void b_101ba1be(Context& c){
{uint32_t v=add(c,c.r[4],c.r[5],0,true);c.r[6]=v;}
{uint32_t a=(c.r[6]+0u+252u);c.r[0]=rd<uint32_t>(c,a+0u);}
{if(c.r[0] == 0){c.pc=(270246350u|1u);return;}}
c.pc=270246343u;}
static void b_101ba1c6(Context& c){
{c.r[14]=270246347u;c.pc=(270391404u|1u);return;}
c.pc=270246347u;}
static void b_101ba1ca(Context& c){
{uint32_t a=(c.r[6]+0u+252u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=add(c,c.r[5],4u,0,true);c.r[5]=v;}
{uint32_t v=add(c,c.r[5],~(20u),1,true);}
{if(cond(c,2)){c.pc=(270246334u|1u);return;}}
c.pc=270246357u;}
static void b_101ba1ce(Context& c){
{uint32_t v=add(c,c.r[5],4u,0,true);c.r[5]=v;}
{uint32_t v=add(c,c.r[5],~(20u),1,true);}
{if(cond(c,2)){c.pc=(270246334u|1u);return;}}
c.pc=270246357u;}
static void b_101ba1d4(Context& c){
{uint32_t v=176u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=123u;nz(c,v);c.r[1]=v;}
{c.pc=(270246304u|1u);return;}
c.pc=270246367u;}
static void b_101ba1de(Context& c){
{uint32_t v=add(c,c.r[3],~(10u),1,true);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270246310u|1u);return;}
c.pc=270246373u;}
static void b_101ba1e4(Context& c){
{if(c.r[5] != 0){c.pc=(270246388u|1u);return;}}
c.pc=270246375u;}
static void b_101ba1e6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=55u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270246387u;c.pc=(270393366u|1u);return;}
c.pc=270246387u;}
static void b_101ba1f2(Context& c){
{c.pc=(270246310u|1u);return;}
c.pc=270246389u;}
static void b_101ba1f4(Context& c){
{uint32_t v=add(c,c.r[5],~(36u),1,true);}
{if(cond(c,2)){c.pc=(270246430u|1u);return;}}
c.pc=270246393u;}
static void b_101ba1f8(Context& c){
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=58u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[2]);wr<uint32_t>(c,a+4u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t a=((270246406u&~3u)+0u+144u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=add(c,c.r[3],270246410u,0,false);c.r[3]=v;}
{uint32_t a=(c.r[3]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[2];c.r[3]=v;}
{c.r[14]=270246419u;c.pc=(270077468u|1u);return;}
c.pc=270246419u;}
static void b_101ba212(Context& c){
{if(c.r[0] == 0){c.pc=(270246424u|1u);return;}}
c.pc=270246421u;}
static void b_101ba214(Context& c){
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+16u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270246310u|1u);return;}
c.pc=270246431u;}
static void b_101ba218(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+16u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270246310u|1u);return;}
c.pc=270246431u;}
static void b_101ba21e(Context& c){
{uint32_t a=(c.r[4]+0u+16u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270246310u|1u);return;}}
c.pc=270246437u;}
static void b_101ba224(Context& c){
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],10u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270246447u;c.pc=(270408416u|1u);return;}
c.pc=270246447u;}
static void b_101ba22e(Context& c){
{c.r[14]=270246451u;c.pc=(270408736u|1u);return;}
c.pc=270246451u;}
static void b_101ba232(Context& c){
{setsbits(c,15,c.r[0]);}
{setfs(c,14,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+36u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,(fs(c,13))+(fs(c,15)));}
{fcmp(c,fs(c,14),fs(c,15));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,9)){c.pc=(270246310u|1u);return;}}
c.pc=270246485u;}
static void b_101ba254(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=140u;nz(c,v);c.r[1]=v;}
{c.pc=(270246304u|1u);return;}
c.pc=270246491u;}
static void b_101ba25a(Context& c){
{uint32_t v=add(c,c.r[4],c.r[5],0,true);c.r[3]=v;}
{uint32_t a=(c.r[3]+0u+252u);c.r[0]=rd<uint32_t>(c,a+0u);}
{if(c.r[0] == 0){c.pc=(270246502u|1u);return;}}
c.pc=270246499u;}
static void b_101ba262(Context& c){
{c.r[14]=270246503u;c.pc=(270391404u|1u);return;}
c.pc=270246503u;}
static void b_101ba266(Context& c){
{uint32_t v=add(c,c.r[5],4u,0,true);c.r[5]=v;}
{uint32_t v=add(c,c.r[5],~(20u),1,true);}
{if(cond(c,2)){c.pc=(270246490u|1u);return;}}
c.pc=270246509u;}
static void b_101ba26c(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270246523u;c.pc=(270245352u|1u);return;}
c.pc=270246523u;}
static void b_101ba272(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270246523u;c.pc=(270245352u|1u);return;}
c.pc=270246523u;}
static void b_101ba27a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270391404u|1u);return;}
c.pc=270246535u;}
static void b_101ba286(Context& c){
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270246541u;}
static void b_101ba298(Context& c){
{uint32_t a=c.r[13]-36u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[11]);wr<uint32_t>(c,a+32u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-24u;wr<uint64_t>(c,a+0u,c.d[8]);wr<uint64_t>(c,a+8u,c.d[9]);wr<uint64_t>(c,a+16u,c.d[10]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[4]=v;}
{uint32_t a=((270246566u&~3u)+0u+468u);setsbits(c,18,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[13],~(36u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[5]=v;}
{c.r[14]=270246577u;c.pc=(270392110u|1u);return;}
c.pc=270246577u;}
static void b_101ba2b0(Context& c){
{uint32_t v=0u;nz(c,v);c.r[6]=v;}
{uint32_t v=4294967295u;c.r[7]=v;}
{uint32_t v=65284u;c.r[8]=v;}
{setfs(c,21,-16.0);}
{uint32_t a=((270246594u&~3u)+0u+444u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{setfs(c,17,-10.0);}
{setfs(c,20,16.0);}
{uint32_t v=c.r[0];c.r[10]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270246611u;c.pc=(270392138u|1u);return;}
c.pc=270246611u;}
static void b_101ba2d2(Context& c){
{uint32_t v=c.r[10];c.r[2]=v;}
{uint32_t v=c.r[6];c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{setfs(c,19,-8.0);}
{uint32_t v=c.r[0];c.r[11]=v;}
{uint32_t v=shift(c,c.r[0],1u,3,false);c.r[9]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270246639u;c.pc=(270015700u|1u);return;}
c.pc=270246639u;}
static void b_101ba2ee(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=5u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270246657u;c.pc=(270015700u|1u);return;}
c.pc=270246657u;}
static void b_101ba300(Context& c){
{uint32_t v=add(c,0u,~(c.r[10]),1,false);c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270246677u;c.pc=(270015700u|1u);return;}
c.pc=270246677u;}
static void b_101ba314(Context& c){
{uint32_t v=shift(c,c.r[10],1u,3,false);c.r[12]=v;}
{uint32_t v=add(c,0u,~(c.r[9]),1,false);c.r[10]=v;}
{uint32_t v=add(c,c.r[12],10u,0,false);c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[10];c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[12]);}
{c.r[14]=270246709u;c.pc=(270015700u|1u);return;}
c.pc=270246709u;}
static void b_101ba334(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[12]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[10];c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=~(9u);c.r[2]=v;}
{uint32_t v=add(c,c.r[2],~(c.r[12]),1,false);c.r[2]=v;}
{uint32_t v=shift(c,c.r[11],2u,3,false);c.r[6]=v;}
{c.r[14]=270246741u;c.pc=(270015700u|1u);return;}
c.pc=270246741u;}
static void b_101ba354(Context& c){
{uint32_t a=(c.r[5]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=8u;c.r[11]=v;}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,2)){uint32_t v=c.r[7];c.r[10]=v;}}
{if(cond(c,1)){uint32_t v=1u;c.r[10]=v;}}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270246763u;c.pc=(270082278u|1u);return;}
c.pc=270246763u;}
static void b_101ba364(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270246763u;c.pc=(270082278u|1u);return;}
c.pc=270246763u;}
static void b_101ba36a(Context& c){
{uint32_t v=c.r[0];c.r[8]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270246771u;c.pc=(270082278u|1u);return;}
c.pc=270246771u;}
static void b_101ba372(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[8];c.r[0]=v;}
{c.r[14]=270246781u;c.pc=(270697604u|1u);return;}
c.pc=270246781u;}
static void b_101ba37c(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=0u;c.r[8]=v;}
{uint32_t v=1u;nz(c,v);c.r[7]=v;}
{uint32_t v=add(c,c.r[1],~(130u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270246803u;c.pc=(270697604u|1u);return;}
c.pc=270246803u;}
static void b_101ba392(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,21));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=shift(c,c.r[1],1u,1,true);nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);c.r[3]=v;}
{c.r[14]=270246839u;c.pc=(270091396u|1u);return;}
c.pc=270246839u;}
static void b_101ba3b6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270246845u;c.pc=(270082278u|1u);return;}
c.pc=270246845u;}
static void b_101ba3bc(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270246855u;c.pc=(270082278u|1u);return;}
c.pc=270246855u;}
static void b_101ba3c6(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270246869u;c.pc=(270697604u|1u);return;}
c.pc=270246869u;}
static void b_101ba3d4(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],30u,0,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270246887u;c.pc=(270697604u|1u);return;}
c.pc=270246887u;}
static void b_101ba3e6(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,20));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=shift(c,c.r[1],(c.r[7]&255u),1,false);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);c.r[3]=v;}
{c.r[14]=270246925u;c.pc=(270082284u|1u);return;}
c.pc=270246925u;}
static void b_101ba40c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270246931u;c.pc=(270082278u|1u);return;}
c.pc=270246931u;}
static void b_101ba412(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270246941u;c.pc=(270082278u|1u);return;}
c.pc=270246941u;}
static void b_101ba41c(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270246955u;c.pc=(270697604u|1u);return;}
c.pc=270246955u;}
static void b_101ba42a(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(50u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270246973u;c.pc=(270697604u|1u);return;}
c.pc=270246973u;}
static void b_101ba43c(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,19));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=shift(c,c.r[1],(c.r[7]&255u),1,false);c.r[3]=v;}
{uint32_t v=1090519040u;c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270247013u;c.pc=(270082284u|1u);return;}
c.pc=270247013u;}
static void b_101ba464(Context& c){
{uint32_t v=add(c,c.r[11],~(1u),1,true);c.r[11]=v;}
{if(cond(c,2)){c.pc=(270246756u|1u);return;}}
c.pc=270247021u;}
static void b_101ba46c(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.d[10]=rd<uint64_t>(c,a+16u);c.r[13]=a+24u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);uint32_t newpc=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;c.pc=newpc;return;}
c.pc=270247031u;}
static void b_101ba480(Context& c){
{uint32_t v=add(c,c.r[2],~(70u),1,true);}
{uint32_t a=c.r[13]-16u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[2];c.r[5]=v;}
{if(cond(c,1)){c.pc=(270247276u|1u);return;}}
c.pc=270247053u;}
static void b_101ba48c(Context& c){
{if(cond(c,13)){c.pc=(270247080u|1u);return;}}
c.pc=270247055u;}
static void b_101ba48e(Context& c){
{uint32_t v=add(c,c.r[2],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270247144u|1u);return;}}
c.pc=270247059u;}
static void b_101ba492(Context& c){
{if(cond(c,13)){c.pc=(270247070u|1u);return;}}
c.pc=270247061u;}
static void b_101ba494(Context& c){
{uint32_t v=add(c,c.r[2],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270247106u|1u);return;}}
c.pc=270247065u;}
static void b_101ba498(Context& c){
{uint32_t v=add(c,c.r[2],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270247116u|1u);return;}}
c.pc=270247069u;}
static void b_101ba49c(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270247071u;}
static void b_101ba49e(Context& c){
{uint32_t v=add(c,c.r[2],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270247162u|1u);return;}}
c.pc=270247075u;}
static void b_101ba4a2(Context& c){
{uint32_t v=add(c,c.r[2],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270247180u|1u);return;}}
c.pc=270247079u;}
static void b_101ba4a6(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270247081u;}
static void b_101ba4a8(Context& c){
{uint32_t v=add(c,c.r[2],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270247302u|1u);return;}}
c.pc=270247085u;}
static void b_101ba4ac(Context& c){
{if(cond(c,13)){c.pc=(270247096u|1u);return;}}
c.pc=270247087u;}
static void b_101ba4ae(Context& c){
{uint32_t v=add(c,c.r[2],~(80u),1,true);}
{if(cond(c,1)){c.pc=(270247234u|1u);return;}}
c.pc=270247091u;}
static void b_101ba4b2(Context& c){
{uint32_t v=add(c,c.r[2],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270247302u|1u);return;}}
c.pc=270247095u;}
static void b_101ba4b6(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270247097u;}
static void b_101ba4b8(Context& c){
{uint32_t v=add(c,c.r[2],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270247302u|1u);return;}}
c.pc=270247101u;}
static void b_101ba4bc(Context& c){
{uint32_t v=add(c,c.r[2],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270247342u|1u);return;}}
c.pc=270247105u;}
static void b_101ba4c0(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270247107u;}
static void b_101ba4c2(Context& c){
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270247352u|1u);return;}}
c.pc=270247111u;}
static void b_101ba4c6(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270247150u|1u);return;}
c.pc=270247117u;}
static void b_101ba4cc(Context& c){
{if(c.r[3] != 0){c.pc=(270247136u|1u);return;}}
c.pc=270247119u;}
static void b_101ba4ce(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270247131u;c.pc=(270393366u|1u);return;}
c.pc=270247131u;}
static void b_101ba4da(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270247144u&~3u)+0u+212u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270247268u|1u);return;}
c.pc=270247145u;}
static void b_101ba4e0(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270247144u&~3u)+0u+212u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270247268u|1u);return;}
c.pc=270247145u;}
static void b_101ba4e8(Context& c){
{if(c.r[3] != 0){c.pc=(270247170u|1u);return;}}
c.pc=270247147u;}
static void b_101ba4ea(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270393366u|1u);return;}
c.pc=270247163u;}
static void b_101ba4ee(Context& c){
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270393366u|1u);return;}
c.pc=270247163u;}
static void b_101ba4fa(Context& c){
{if(c.r[3] != 0){c.pc=(270247170u|1u);return;}}
c.pc=270247165u;}
static void b_101ba4fc(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{c.pc=(270247150u|1u);return;}
c.pc=270247171u;}
static void b_101ba502(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270247352u|1u);return;}}
c.pc=270247179u;}
static void b_101ba50a(Context& c){
{c.pc=(270247226u|1u);return;}
c.pc=270247181u;}
static void b_101ba50c(Context& c){
{if(c.r[3] != 0){c.pc=(270247206u|1u);return;}}
c.pc=270247183u;}
static void b_101ba50e(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270247195u;c.pc=(270393366u|1u);return;}
c.pc=270247195u;}
static void b_101ba51a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(269975948u|1u);return;}
c.pc=270247207u;}
static void b_101ba526(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[1]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[1],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270247352u|1u);return;}}
c.pc=270247215u;}
static void b_101ba52e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270247221u;c.pc=(269975948u|1u);return;}
c.pc=270247221u;}
static void b_101ba534(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(269980032u|1u);return;}
c.pc=270247235u;}
static void b_101ba53a(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(269980032u|1u);return;}
c.pc=270247235u;}
static void b_101ba542(Context& c){
{if(c.r[3] != 0){c.pc=(270247250u|1u);return;}}
c.pc=270247237u;}
static void b_101ba544(Context& c){
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{c.r[14]=270247249u;c.pc=(270393366u|1u);return;}
c.pc=270247249u;}
static void b_101ba550(Context& c){
{c.pc=(270247262u|1u);return;}
c.pc=270247251u;}
static void b_101ba552(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270247262u|1u);return;}}
c.pc=270247257u;}
static void b_101ba558(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(269978432u|1u);return;}
c.pc=270247277u;}
static void b_101ba55e(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(269978432u|1u);return;}
c.pc=270247277u;}
static void b_101ba564(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(269978432u|1u);return;}
c.pc=270247277u;}
static void b_101ba56c(Context& c){
{if(c.r[3] != 0){c.pc=(270247284u|1u);return;}}
c.pc=270247279u;}
static void b_101ba56e(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270247150u|1u);return;}
c.pc=270247285u;}
static void b_101ba574(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{if(c.r[2] != 0){c.pc=(270247352u|1u);return;}}
c.pc=270247291u;}
static void b_101ba57a(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270391848u|1u);return;}
c.pc=270247303u;}
static void b_101ba586(Context& c){
{if(c.r[3] != 0){c.pc=(270247328u|1u);return;}}
c.pc=270247305u;}
static void b_101ba588(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270247317u;c.pc=(270393366u|1u);return;}
c.pc=270247317u;}
static void b_101ba594(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270246552u|1u);return;}
c.pc=270247329u;}
static void b_101ba5a0(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270247352u|1u);return;}}
c.pc=270247335u;}
static void b_101ba5a6(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270247343u;c.pc=(270246552u|1u);return;}
c.pc=270247343u;}
static void b_101ba5ae(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270391404u|1u);return;}
c.pc=270247353u;}
static void b_101ba5b8(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270247355u;}
static void b_101ba5c0(Context& c){
{uint32_t a=c.r[13]-12u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[14]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(20u),1,false);c.r[13]=v;}
{uint32_t a=(c.r[1]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[5]=v;}
{uint32_t a=(c.r[1]+0u+28u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270247383u;c.pc=c.r[3];return;}
c.pc=270247383u;}
static void b_101ba5d6(Context& c){
{uint32_t a=(c.r[4]+0u+277u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=330u;c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[13]+0u+12u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270247405u;c.pc=(270393892u|1u);return;}
c.pc=270247405u;}
static void b_101ba5ec(Context& c){
{if(c.r[0] == 0){c.pc=(270247414u|1u);return;}}
c.pc=270247407u;}
static void b_101ba5ee(Context& c){
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[0]+0u+32u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270247423u;c.pc=(269975098u|1u);return;}
c.pc=270247423u;}
static void b_101ba5f6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270247423u;c.pc=(269975098u|1u);return;}
c.pc=270247423u;}
static void b_101ba5fe(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270247431u;c.pc=(269975106u|1u);return;}
c.pc=270247431u;}
static void b_101ba606(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270247439u;c.pc=(269976968u|1u);return;}
c.pc=270247439u;}
static void b_101ba60e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270247447u;c.pc=(269976986u|1u);return;}
c.pc=270247447u;}
static void b_101ba616(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270247455u;c.pc=(269975400u|1u);return;}
c.pc=270247455u;}
static void b_101ba61e(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=2u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270247465u;c.pc=c.r[3];return;}
c.pc=270247465u;}
static void b_101ba628(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);uint32_t newpc=rd<uint32_t>(c,a+8u);c.r[13]=a+12u;c.pc=newpc;return;}
c.pc=270247469u;}
static void b_101ba62c(Context& c){
{uint32_t a=c.r[13]-36u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[11]);wr<uint32_t>(c,a+32u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-24u;wr<uint64_t>(c,a+0u,c.d[8]);wr<uint64_t>(c,a+8u,c.d[9]);wr<uint64_t>(c,a+16u,c.d[10]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[4]=v;}
{uint32_t a=((270247482u&~3u)+0u+468u);setsbits(c,18,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[13],~(36u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[5]=v;}
{c.r[14]=270247493u;c.pc=(270392110u|1u);return;}
c.pc=270247493u;}
static void b_101ba644(Context& c){
{uint32_t v=0u;nz(c,v);c.r[6]=v;}
{uint32_t v=4294967295u;c.r[7]=v;}
{uint32_t v=65284u;c.r[8]=v;}
{setfs(c,21,-16.0);}
{uint32_t a=((270247510u&~3u)+0u+444u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{setfs(c,17,-10.0);}
{setfs(c,20,16.0);}
{uint32_t v=c.r[0];c.r[10]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270247527u;c.pc=(270392138u|1u);return;}
c.pc=270247527u;}
static void b_101ba666(Context& c){
{uint32_t v=c.r[10];c.r[2]=v;}
{uint32_t v=c.r[6];c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{setfs(c,19,-8.0);}
{uint32_t v=c.r[0];c.r[11]=v;}
{uint32_t v=shift(c,c.r[0],1u,3,false);c.r[9]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270247555u;c.pc=(270015700u|1u);return;}
c.pc=270247555u;}
static void b_101ba682(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=5u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270247573u;c.pc=(270015700u|1u);return;}
c.pc=270247573u;}
static void b_101ba694(Context& c){
{uint32_t v=add(c,0u,~(c.r[10]),1,false);c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270247593u;c.pc=(270015700u|1u);return;}
c.pc=270247593u;}
static void b_101ba6a8(Context& c){
{uint32_t v=shift(c,c.r[10],1u,3,false);c.r[12]=v;}
{uint32_t v=add(c,0u,~(c.r[9]),1,false);c.r[10]=v;}
{uint32_t v=add(c,c.r[12],10u,0,false);c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[10];c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[12]);}
{c.r[14]=270247625u;c.pc=(270015700u|1u);return;}
c.pc=270247625u;}
static void b_101ba6c8(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[12]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[10];c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=~(9u);c.r[2]=v;}
{uint32_t v=add(c,c.r[2],~(c.r[12]),1,false);c.r[2]=v;}
{uint32_t v=shift(c,c.r[11],2u,3,false);c.r[6]=v;}
{c.r[14]=270247657u;c.pc=(270015700u|1u);return;}
c.pc=270247657u;}
static void b_101ba6e8(Context& c){
{uint32_t a=(c.r[5]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=8u;c.r[11]=v;}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,2)){uint32_t v=c.r[7];c.r[10]=v;}}
{if(cond(c,1)){uint32_t v=1u;c.r[10]=v;}}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270247679u;c.pc=(270082278u|1u);return;}
c.pc=270247679u;}
static void b_101ba6f8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270247679u;c.pc=(270082278u|1u);return;}
c.pc=270247679u;}
static void b_101ba6fe(Context& c){
{uint32_t v=c.r[0];c.r[8]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270247687u;c.pc=(270082278u|1u);return;}
c.pc=270247687u;}
static void b_101ba706(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[8];c.r[0]=v;}
{c.r[14]=270247697u;c.pc=(270697604u|1u);return;}
c.pc=270247697u;}
static void b_101ba710(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=0u;c.r[8]=v;}
{uint32_t v=1u;nz(c,v);c.r[7]=v;}
{uint32_t v=add(c,c.r[1],~(130u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270247719u;c.pc=(270697604u|1u);return;}
c.pc=270247719u;}
static void b_101ba726(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,21));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=shift(c,c.r[1],1u,1,true);nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);c.r[3]=v;}
{c.r[14]=270247755u;c.pc=(270091396u|1u);return;}
c.pc=270247755u;}
static void b_101ba74a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270247761u;c.pc=(270082278u|1u);return;}
c.pc=270247761u;}
static void b_101ba750(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270247771u;c.pc=(270082278u|1u);return;}
c.pc=270247771u;}
static void b_101ba75a(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270247785u;c.pc=(270697604u|1u);return;}
c.pc=270247785u;}
static void b_101ba768(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],30u,0,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270247803u;c.pc=(270697604u|1u);return;}
c.pc=270247803u;}
static void b_101ba77a(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,20));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=shift(c,c.r[1],(c.r[7]&255u),1,false);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);c.r[3]=v;}
{c.r[14]=270247841u;c.pc=(270082284u|1u);return;}
c.pc=270247841u;}
static void b_101ba7a0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270247847u;c.pc=(270082278u|1u);return;}
c.pc=270247847u;}
static void b_101ba7a6(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270247857u;c.pc=(270082278u|1u);return;}
c.pc=270247857u;}
static void b_101ba7b0(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270247871u;c.pc=(270697604u|1u);return;}
c.pc=270247871u;}
static void b_101ba7be(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(50u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270247889u;c.pc=(270697604u|1u);return;}
c.pc=270247889u;}
static void b_101ba7d0(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,19));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=shift(c,c.r[1],(c.r[7]&255u),1,false);c.r[3]=v;}
{uint32_t v=1090519040u;c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270247929u;c.pc=(270082284u|1u);return;}
c.pc=270247929u;}
static void b_101ba7f8(Context& c){
{uint32_t v=add(c,c.r[11],~(1u),1,true);c.r[11]=v;}
{if(cond(c,2)){c.pc=(270247672u|1u);return;}}
c.pc=270247937u;}
static void b_101ba800(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.d[10]=rd<uint64_t>(c,a+16u);c.r[13]=a+24u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);uint32_t newpc=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;c.pc=newpc;return;}
c.pc=270247947u;}
static void b_101ba814(Context& c){
{uint32_t a=c.r[13]-32u;wr<uint32_t>(c,a+0u,c.r[0]);wr<uint32_t>(c,a+4u,c.r[1]);wr<uint32_t>(c,a+8u,c.r[2]);wr<uint32_t>(c,a+12u,c.r[4]);wr<uint32_t>(c,a+16u,c.r[5]);wr<uint32_t>(c,a+20u,c.r[6]);wr<uint32_t>(c,a+24u,c.r[7]);wr<uint32_t>(c,a+28u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[2];c.r[6]=v;}
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t a=(c.r[1]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{if(c.r[3] != 0){c.pc=(270247978u|1u);return;}}
c.pc=270247971u;}
static void b_101ba822(Context& c){
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270247977u;c.pc=(270247360u|1u);return;}
c.pc=270247977u;}
static void b_101ba828(Context& c){
{uint32_t a=(c.r[13]+0u+4u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270248136u|1u);return;}}
c.pc=270247985u;}
static void b_101ba82a(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270248136u|1u);return;}}
c.pc=270247985u;}
static void b_101ba830(Context& c){
{uint32_t a=(c.r[4]+0u+252u);c.r[5]=rd<uint32_t>(c,a+0u);}
{if(c.r[5] == 0){c.pc=(270248006u|1u);return;}}
c.pc=270247991u;}
static void b_101ba836(Context& c){
{uint32_t a=(c.r[5]+0u+100u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270248444u|1u);return;}}
c.pc=270248001u;}
static void b_101ba840(Context& c){
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270248444u|1u);return;}
c.pc=270248007u;}
static void b_101ba846(Context& c){
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270248017u;c.pc=(269975098u|1u);return;}
c.pc=270248017u;}
static void b_101ba850(Context& c){
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270248025u;c.pc=(269975106u|1u);return;}
c.pc=270248025u;}
static void b_101ba858(Context& c){
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270248033u;c.pc=(269976968u|1u);return;}
c.pc=270248033u;}
static void b_101ba860(Context& c){
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270248041u;c.pc=(269976986u|1u);return;}
c.pc=270248041u;}
static void b_101ba868(Context& c){
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270248049u;c.pc=(269975400u|1u);return;}
c.pc=270248049u;}
static void b_101ba870(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[1]);}
{c.r[14]=270248063u;c.pc=(270391848u|1u);return;}
c.pc=270248063u;}
static void b_101ba87e(Context& c){
{c.r[14]=270248067u;c.pc=(270408416u|1u);return;}
c.pc=270248067u;}
static void b_101ba882(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270248075u;c.pc=(270392110u|1u);return;}
c.pc=270248075u;}
static void b_101ba88a(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(270u),1,true);}
{uint32_t v=shift(c,c.r[0],1u,3,false);c.r[0]=v;}
{uint32_t v=add(c,0u,~(c.r[0]),1,false);c.r[0]=v;}
{if(cond(c,2)){c.pc=(270248108u|1u);return;}}
c.pc=270248091u;}
static void b_101ba89a(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270248097u;c.pc=(270408736u|1u);return;}
c.pc=270248097u;}
static void b_101ba8a0(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270248105u;c.pc=(270392110u|1u);return;}
c.pc=270248105u;}
static void b_101ba8a8(Context& c){
{uint32_t v=add(c,c.r[5],shift(c,c.r[0],1,3,false),0,false);c.r[0]=v;}
{setsbits(c,14,c.r[0]);}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[3]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270248135u;c.pc=c.r[3];return;}
c.pc=270248135u;}
static void b_101ba8ac(Context& c){
{setsbits(c,14,c.r[0]);}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[3]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270248135u;c.pc=c.r[3];return;}
c.pc=270248135u;}
static void b_101ba8c6(Context& c){
{c.pc=(270248444u|1u);return;}
c.pc=270248137u;}
static void b_101ba8c8(Context& c){
{uint32_t v=add(c,c.r[6],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270248364u|1u);return;}}
c.pc=270248141u;}
static void b_101ba8cc(Context& c){
{if(cond(c,13)){c.pc=(270248168u|1u);return;}}
c.pc=270248143u;}
static void b_101ba8ce(Context& c){
{uint32_t v=add(c,c.r[6],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270248230u|1u);return;}}
c.pc=270248147u;}
static void b_101ba8d2(Context& c){
{if(cond(c,13)){c.pc=(270248158u|1u);return;}}
c.pc=270248149u;}
static void b_101ba8d4(Context& c){
{uint32_t v=add(c,c.r[6],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270248194u|1u);return;}}
c.pc=270248153u;}
static void b_101ba8d8(Context& c){
{uint32_t v=add(c,c.r[6],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270248204u|1u);return;}}
c.pc=270248157u;}
static void b_101ba8dc(Context& c){
{c.pc=(270248444u|1u);return;}
c.pc=270248159u;}
static void b_101ba8de(Context& c){
{uint32_t v=add(c,c.r[6],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270248248u|1u);return;}}
c.pc=270248163u;}
static void b_101ba8e2(Context& c){
{uint32_t v=add(c,c.r[6],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270248266u|1u);return;}}
c.pc=270248167u;}
static void b_101ba8e6(Context& c){
{c.pc=(270248444u|1u);return;}
c.pc=270248169u;}
static void b_101ba8e8(Context& c){
{uint32_t v=add(c,c.r[6],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270248392u|1u);return;}}
c.pc=270248173u;}
static void b_101ba8ec(Context& c){
{if(cond(c,13)){c.pc=(270248184u|1u);return;}}
c.pc=270248175u;}
static void b_101ba8ee(Context& c){
{uint32_t v=add(c,c.r[6],~(80u),1,true);}
{if(cond(c,1)){c.pc=(270248322u|1u);return;}}
c.pc=270248179u;}
static void b_101ba8f2(Context& c){
{uint32_t v=add(c,c.r[6],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270248392u|1u);return;}}
c.pc=270248183u;}
static void b_101ba8f6(Context& c){
{c.pc=(270248444u|1u);return;}
c.pc=270248185u;}
static void b_101ba8f8(Context& c){
{uint32_t v=add(c,c.r[6],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270248392u|1u);return;}}
c.pc=270248189u;}
static void b_101ba8fc(Context& c){
{uint32_t v=add(c,c.r[6],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270248432u|1u);return;}}
c.pc=270248193u;}
static void b_101ba900(Context& c){
{c.pc=(270248444u|1u);return;}
c.pc=270248195u;}
static void b_101ba902(Context& c){
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270248444u|1u);return;}}
c.pc=270248199u;}
static void b_101ba906(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270248236u|1u);return;}
c.pc=270248205u;}
static void b_101ba90c(Context& c){
{if(c.r[2] != 0){c.pc=(270248222u|1u);return;}}
c.pc=270248207u;}
static void b_101ba90e(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{c.r[14]=270248217u;c.pc=(270393366u|1u);return;}
c.pc=270248217u;}
static void b_101ba918(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270248230u&~3u)+0u+220u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270248354u|1u);return;}
c.pc=270248231u;}
static void b_101ba91e(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270248230u&~3u)+0u+220u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270248354u|1u);return;}
c.pc=270248231u;}
static void b_101ba926(Context& c){
{if(c.r[2] != 0){c.pc=(270248256u|1u);return;}}
c.pc=270248233u;}
static void b_101ba928(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270393366u|1u);return;}
c.pc=270248249u;}
static void b_101ba92c(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270393366u|1u);return;}
c.pc=270248249u;}
static void b_101ba938(Context& c){
{if(c.r[2] != 0){c.pc=(270248256u|1u);return;}}
c.pc=270248251u;}
static void b_101ba93a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{c.pc=(270248236u|1u);return;}
c.pc=270248257u;}
static void b_101ba940(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270248444u|1u);return;}}
c.pc=270248265u;}
static void b_101ba948(Context& c){
{c.pc=(270248306u|1u);return;}
c.pc=270248267u;}
static void b_101ba94a(Context& c){
{if(c.r[2] != 0){c.pc=(270248292u|1u);return;}}
c.pc=270248269u;}
static void b_101ba94c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270248279u;c.pc=(270393366u|1u);return;}
c.pc=270248279u;}
static void b_101ba956(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(269975948u|1u);return;}
c.pc=270248293u;}
static void b_101ba964(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[1]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[1],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270248444u|1u);return;}}
c.pc=270248301u;}
static void b_101ba96c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270248307u;c.pc=(269975948u|1u);return;}
c.pc=270248307u;}
static void b_101ba972(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(269980032u|1u);return;}
c.pc=270248323u;}
static void b_101ba982(Context& c){
{if(c.r[2] != 0){c.pc=(270248336u|1u);return;}}
c.pc=270248325u;}
static void b_101ba984(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270248335u;c.pc=(270393366u|1u);return;}
c.pc=270248335u;}
static void b_101ba98e(Context& c){
{c.pc=(270248348u|1u);return;}
c.pc=270248337u;}
static void b_101ba990(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270248348u|1u);return;}}
c.pc=270248343u;}
static void b_101ba996(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(269978432u|1u);return;}
c.pc=270248365u;}
static void b_101ba99c(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(269978432u|1u);return;}
c.pc=270248365u;}
static void b_101ba9a2(Context& c){
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(269978432u|1u);return;}
c.pc=270248365u;}
static void b_101ba9ac(Context& c){
{if(c.r[2] != 0){c.pc=(270248372u|1u);return;}}
c.pc=270248367u;}
static void b_101ba9ae(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270248236u|1u);return;}
c.pc=270248373u;}
static void b_101ba9b4(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{if(c.r[2] != 0){c.pc=(270248444u|1u);return;}}
c.pc=270248379u;}
static void b_101ba9ba(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270391848u|1u);return;}
c.pc=270248393u;}
static void b_101ba9c8(Context& c){
{if(c.r[2] != 0){c.pc=(270248418u|1u);return;}}
c.pc=270248395u;}
static void b_101ba9ca(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270248405u;c.pc=(270393366u|1u);return;}
c.pc=270248405u;}
static void b_101ba9d4(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270247468u|1u);return;}
c.pc=270248419u;}
static void b_101ba9e2(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270248444u|1u);return;}}
c.pc=270248425u;}
static void b_101ba9e8(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270248433u;c.pc=(270247468u|1u);return;}
c.pc=270248433u;}
static void b_101ba9f0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270391404u|1u);return;}
c.pc=270248445u;}
static void b_101ba9fc(Context& c){
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);uint32_t newpc=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;c.pc=newpc;return;}
c.pc=270248449u;}
static void b_101baa04(Context& c){
{uint32_t a=c.r[13]-36u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[11]);wr<uint32_t>(c,a+32u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-16u;wr<uint64_t>(c,a+0u,c.d[8]);wr<uint64_t>(c,a+8u,c.d[9]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(36u),1,false);c.r[13]=v;}
{uint32_t a=((270248466u&~3u)+0u+508u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{uint32_t v=0u;nz(c,v);c.r[5]=v;}
{uint32_t v=c.r[1];c.r[6]=v;}
{uint32_t v=65303u;c.r[8]=v;}
{uint32_t v=4294967295u;c.r[7]=v;}
{uint32_t v=c.r[0];c.r[4]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=~(9u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{setfs(c,19,-16.0);}
{c.r[14]=270248501u;c.pc=(270015700u|1u);return;}
c.pc=270248501u;}
static void b_101baa34(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t v=100u;nz(c,v);c.r[2]=v;}
{uint32_t v=~(9u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=((270248520u&~3u)+0u+460u);c.r[11]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270248525u;c.pc=(270015700u|1u);return;}
c.pc=270248525u;}
static void b_101baa4c(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t v=~(99u);c.r[2]=v;}
{uint32_t v=~(9u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;c.r[9]=v;}
{c.r[14]=270248551u;c.pc=(270015700u|1u);return;}
c.pc=270248551u;}
static void b_101baa66(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=~(29u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{setfs(c,18,16.0);}
{c.r[14]=270248575u;c.pc=(270015700u|1u);return;}
c.pc=270248575u;}
static void b_101baa7e(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=~(59u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1107296256u;c.r[10]=v;}
{c.r[14]=270248599u;c.pc=(270015700u|1u);return;}
c.pc=270248599u;}
static void b_101baa96(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=~(29u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270248619u;c.pc=(270015700u|1u);return;}
c.pc=270248619u;}
static void b_101baaaa(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{setfs(c,17,-8.0);}
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=~(59u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270248643u;c.pc=(270015700u|1u);return;}
c.pc=270248643u;}
static void b_101baac2(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=~(149u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270248663u;c.pc=(270015700u|1u);return;}
c.pc=270248663u;}
static void b_101baad6(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=~(179u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270248683u;c.pc=(270015700u|1u);return;}
c.pc=270248683u;}
static void b_101baaea(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t a=((270248690u&~3u)+0u+288u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270248701u;c.pc=(270015700u|1u);return;}
c.pc=270248701u;}
static void b_101baafc(Context& c){
{uint32_t a=(c.r[6]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,2)){uint32_t v=c.r[7];c.r[8]=v;}}
{if(cond(c,1)){uint32_t v=1u;c.r[8]=v;}}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270248719u;c.pc=(270082278u|1u);return;}
c.pc=270248719u;}
static void b_101bab08(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270248719u;c.pc=(270082278u|1u);return;}
c.pc=270248719u;}
static void b_101bab0e(Context& c){
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270248727u;c.pc=(270082278u|1u);return;}
c.pc=270248727u;}
static void b_101bab16(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[7];c.r[0]=v;}
{c.r[14]=270248737u;c.pc=(270697604u|1u);return;}
c.pc=270248737u;}
static void b_101bab20(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[7]=v;}
{uint32_t v=1u;nz(c,v);c.r[5]=v;}
{uint32_t v=add(c,c.r[1],~(130u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[8])*(c.r[1]);c.r[2]=v;}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270248757u;c.pc=(270697604u|1u);return;}
c.pc=270248757u;}
static void b_101bab34(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,19));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t v=add(c,c.r[1],~(30u),1,false);c.r[3]=v;}
{uint32_t v=c.r[6];c.r[1]=v;}
{c.r[14]=270248791u;c.pc=(270091396u|1u);return;}
c.pc=270248791u;}
static void b_101bab56(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270248797u;c.pc=(270082278u|1u);return;}
c.pc=270248797u;}
static void b_101bab5c(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270248807u;c.pc=(270082278u|1u);return;}
c.pc=270248807u;}
static void b_101bab66(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270248821u;c.pc=(270697604u|1u);return;}
c.pc=270248821u;}
static void b_101bab74(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],30u,0,true);c.r[1]=v;}
{uint32_t v=(c.r[8])*(c.r[1]);c.r[2]=v;}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270248839u;c.pc=(270697604u|1u);return;}
c.pc=270248839u;}
static void b_101bab86(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t v=add(c,c.r[1],~(130u),1,false);c.r[3]=v;}
{uint32_t v=c.r[6];c.r[1]=v;}
{c.r[14]=270248873u;c.pc=(270082284u|1u);return;}
c.pc=270248873u;}
static void b_101baba8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270248879u;c.pc=(270082278u|1u);return;}
c.pc=270248879u;}
static void b_101babae(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270248889u;c.pc=(270082278u|1u);return;}
c.pc=270248889u;}
static void b_101babb8(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270248903u;c.pc=(270697604u|1u);return;}
c.pc=270248903u;}
static void b_101babc6(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(50u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[8])*(c.r[1]);c.r[2]=v;}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270248921u;c.pc=(270697604u|1u);return;}
c.pc=270248921u;}
static void b_101babd8(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[1],~(230u),1,false);c.r[3]=v;}
{uint32_t v=1090519040u;c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=c.r[6];c.r[1]=v;}
{c.r[14]=270248957u;c.pc=(270082284u|1u);return;}
c.pc=270248957u;}
static void b_101babfc(Context& c){
{uint32_t v=add(c,c.r[9],~(1u),1,true);c.r[9]=v;}
{if(cond(c,2)){c.pc=(270248712u|1u);return;}}
c.pc=270248963u;}
static void b_101bac02(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);uint32_t newpc=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;c.pc=newpc;return;}
c.pc=270248973u;}
static void b_101bac18(Context& c){
{uint32_t a=c.r[13]-32u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[8]=v;}
{uint32_t a=(c.r[1]+0u+28u);c.r[9]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[2];c.r[6]=v;}
{uint32_t v=c.r[3];c.r[5]=v;}
{uint32_t v=add(c,c.r[9],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270249108u|1u);return;}}
c.pc=270249007u;}
static void b_101bac2e(Context& c){
{uint32_t v=1u;nz(c,v);c.r[7]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t a=(c.r[1]+0u+28u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270249019u;c.pc=(269975768u|1u);return;}
c.pc=270249019u;}
static void b_101bac3a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270249027u;c.pc=(269975414u|1u);return;}
c.pc=270249027u;}
static void b_101bac42(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270249035u;c.pc=(269975422u|1u);return;}
c.pc=270249035u;}
static void b_101bac4a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270249043u;c.pc=(269975962u|1u);return;}
c.pc=270249043u;}
static void b_101bac52(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270249051u;c.pc=(269976968u|1u);return;}
c.pc=270249051u;}
static void b_101bac5a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270249059u;c.pc=(269976986u|1u);return;}
c.pc=270249059u;}
static void b_101bac62(Context& c){
{uint32_t v=c.r[7];c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270249067u;c.pc=(269975400u|1u);return;}
c.pc=270249067u;}
static void b_101bac6a(Context& c){
{c.r[14]=270249071u;c.pc=(270408416u|1u);return;}
c.pc=270249071u;}
static void b_101bac6e(Context& c){
{c.r[14]=270249075u;c.pc=(270408736u|1u);return;}
c.pc=270249075u;}
static void b_101bac72(Context& c){
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t v=~(29u);c.r[2]=v;}
{uint32_t v=add(c,c.r[0],shift(c,c.r[0],31,2,false),0,false);c.r[0]=v;}
{uint32_t v=shift(c,c.r[0],(c.r[7]&255u),3,true);nz(c,v);c.r[0]=v;}
{setsbits(c,14,c.r[0]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.r[14]=270249109u;c.pc=(270392166u|1u);return;}
c.pc=270249109u;}
static void b_101bac94(Context& c){
{uint32_t v=add(c,c.r[6],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270249318u|1u);return;}}
c.pc=270249113u;}
static void b_101bac98(Context& c){
{if(cond(c,13)){c.pc=(270249140u|1u);return;}}
c.pc=270249115u;}
static void b_101bac9a(Context& c){
{uint32_t v=add(c,c.r[6],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270249170u|1u);return;}}
c.pc=270249119u;}
static void b_101bac9e(Context& c){
{if(cond(c,13)){c.pc=(270249128u|1u);return;}}
c.pc=270249121u;}
static void b_101baca0(Context& c){
{uint32_t v=add(c,c.r[6],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270249170u|1u);return;}}
c.pc=270249125u;}
static void b_101baca4(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270249129u;}
static void b_101baca8(Context& c){
{uint32_t v=add(c,c.r[6],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270249292u|1u);return;}}
c.pc=270249133u;}
static void b_101bacac(Context& c){
{uint32_t v=add(c,c.r[6],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270249300u|1u);return;}}
c.pc=270249137u;}
static void b_101bacb0(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270249141u;}
static void b_101bacb4(Context& c){
{uint32_t v=add(c,c.r[6],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270249366u|1u);return;}}
c.pc=270249145u;}
static void b_101bacb8(Context& c){
{if(cond(c,13)){c.pc=(270249158u|1u);return;}}
c.pc=270249147u;}
static void b_101bacba(Context& c){
{uint32_t v=add(c,c.r[6],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270249346u|1u);return;}}
c.pc=270249151u;}
static void b_101bacbe(Context& c){
{uint32_t v=add(c,c.r[6],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270249366u|1u);return;}}
c.pc=270249155u;}
static void b_101bacc2(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270249159u;}
static void b_101bacc6(Context& c){
{uint32_t v=add(c,c.r[6],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270249366u|1u);return;}}
c.pc=270249163u;}
static void b_101bacca(Context& c){
{uint32_t v=add(c,c.r[6],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270249402u|1u);return;}}
c.pc=270249167u;}
static void b_101bacce(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270249171u;}
static void b_101bacd2(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270249418u|1u);return;}}
c.pc=270249175u;}
static void b_101bacd6(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270249187u;c.pc=(270393366u|1u);return;}
c.pc=270249187u;}
static void b_101bace2(Context& c){
{uint32_t v=c.r[8];c.r[0]=v;}
{c.r[14]=270249193u;c.pc=(270082278u|1u);return;}
c.pc=270249193u;}
static void b_101bace8(Context& c){
{uint32_t v=30u;nz(c,v);c.r[1]=v;}
{c.r[14]=270249199u;c.pc=(270697604u|1u);return;}
c.pc=270249199u;}
static void b_101bacee(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=3u;nz(c,v);c.r[1]=v;}
{c.r[14]=270249207u;c.pc=(270697604u|1u);return;}
c.pc=270249207u;}
static void b_101bacf6(Context& c){
{uint32_t v=add(c,c.r[1],~(1u),1,true);}
{if(cond(c,1)){c.pc=(270249240u|1u);return;}}
c.pc=270249211u;}
static void b_101bacfa(Context& c){
{uint32_t v=add(c,c.r[1],~(2u),1,true);}
{if(cond(c,1)){c.pc=(270249270u|1u);return;}}
c.pc=270249215u;}
static void b_101bacfe(Context& c){
{uint32_t v=add(c,c.r[1],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270249418u|1u);return;}}
c.pc=270249219u;}
static void b_101bad02(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270249225u;c.pc=(269977496u|1u);return;}
c.pc=270249225u;}
static void b_101bad08(Context& c){
{if(c.r[0] == 0){c.pc=(270249234u|1u);return;}}
c.pc=270249227u;}
static void b_101bad0a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270249235u;c.pc=(269976986u|1u);return;}
c.pc=270249235u;}
static void b_101bad12(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=30u;nz(c,v);c.r[1]=v;}
{c.pc=(270249260u|1u);return;}
c.pc=270249241u;}
static void b_101bad18(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270249247u;c.pc=(269976978u|1u);return;}
c.pc=270249247u;}
static void b_101bad1e(Context& c){
{if(c.r[0] == 0){c.pc=(270249256u|1u);return;}}
c.pc=270249249u;}
static void b_101bad20(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270249257u;c.pc=(269976968u|1u);return;}
c.pc=270249257u;}
static void b_101bad28(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=40u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(270391848u|1u);return;}
c.pc=270249271u;}
static void b_101bad2c(Context& c){
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(270391848u|1u);return;}
c.pc=270249271u;}
static void b_101bad2e(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(270391848u|1u);return;}
c.pc=270249271u;}
static void b_101bad36(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270249277u;c.pc=(269975408u|1u);return;}
c.pc=270249277u;}
static void b_101bad3c(Context& c){
{if(c.r[0] == 0){c.pc=(270249286u|1u);return;}}
c.pc=270249279u;}
static void b_101bad3e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270249287u;c.pc=(269975400u|1u);return;}
c.pc=270249287u;}
static void b_101bad46(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=50u;nz(c,v);c.r[1]=v;}
{c.pc=(270249260u|1u);return;}
c.pc=270249293u;}
static void b_101bad4c(Context& c){
{if(c.r[5] != 0){c.pc=(270249326u|1u);return;}}
c.pc=270249295u;}
static void b_101bad4e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{c.pc=(270249306u|1u);return;}
c.pc=270249301u;}
static void b_101bad54(Context& c){
{if(c.r[5] != 0){c.pc=(270249326u|1u);return;}}
c.pc=270249303u;}
static void b_101bad56(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(270393366u|1u);return;}
c.pc=270249319u;}
static void b_101bad5a(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(270393366u|1u);return;}
c.pc=270249319u;}
static void b_101bad66(Context& c){
{if(c.r[5] != 0){c.pc=(270249326u|1u);return;}}
c.pc=270249321u;}
static void b_101bad68(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270249306u|1u);return;}
c.pc=270249327u;}
static void b_101bad6e(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270249418u|1u);return;}}
c.pc=270249333u;}
static void b_101bad74(Context& c){
{uint32_t v=c.r[8];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(269980032u|1u);return;}
c.pc=270249347u;}
static void b_101bad82(Context& c){
{if(c.r[5] != 0){c.pc=(270249354u|1u);return;}}
c.pc=270249349u;}
static void b_101bad84(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270249306u|1u);return;}
c.pc=270249355u;}
static void b_101bad8a(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{if(c.r[2] != 0){c.pc=(270249418u|1u);return;}}
c.pc=270249361u;}
static void b_101bad90(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270249262u|1u);return;}
c.pc=270249367u;}
static void b_101bad96(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=236u;nz(c,v);c.r[1]=v;}
{c.r[14]=270249375u;c.pc=(270393772u|1u);return;}
c.pc=270249375u;}
static void b_101bad9e(Context& c){
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270249387u;c.pc=(270393366u|1u);return;}
c.pc=270249387u;}
static void b_101badaa(Context& c){
{uint32_t v=c.r[8];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270249395u;c.pc=(270248452u|1u);return;}
c.pc=270249395u;}
static void b_101badb2(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=140u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.pc=(270249262u|1u);return;}
c.pc=270249403u;}
static void b_101badba(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270249418u|1u);return;}}
c.pc=270249409u;}
static void b_101badc0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(270391404u|1u);return;}
c.pc=270249419u;}
static void b_101badca(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270249423u;}
static void b_101badce(Context& c){
{uint32_t a=c.r[13]-36u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[11]);wr<uint32_t>(c,a+32u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-16u;wr<uint64_t>(c,a+0u,c.d[8]);wr<uint64_t>(c,a+8u,c.d[9]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(100u),1,false);c.r[13]=v;}
{uint32_t v=c.r[2];c.r[4]=v;}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+68u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[1];c.r[5]=v;}
{uint32_t a=(c.r[13]+0u+72u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=40u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+76u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[0];c.r[8]=v;}
{uint32_t a=(c.r[13]+0u+80u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+88u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[13],84u,0,false);c.r[6]=v;}
{uint32_t a=(c.r[13]+0u+92u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+0u+88u);c.r[10]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+84u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=add(c,c.r[13],68u,0,false);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270249475u;c.pc=c.r[3];return;}
c.pc=270249475u;}
static void b_101bae02(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=41u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],72u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270249487u;c.pc=c.r[3];return;}
c.pc=270249487u;}
static void b_101bae0e(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=42u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],76u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270249499u;c.pc=c.r[3];return;}
c.pc=270249499u;}
static void b_101bae1a(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=43u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],80u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270249511u;c.pc=c.r[3];return;}
c.pc=270249511u;}
static void b_101bae26(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=45u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270249523u;c.pc=c.r[3];return;}
c.pc=270249523u;}
static void b_101bae32(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=47u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],92u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270249535u;c.pc=c.r[3];return;}
c.pc=270249535u;}
static void b_101bae3e(Context& c){
{uint32_t a=(c.r[5]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=29u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],88u,0,false);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270249547u;c.pc=c.r[3];return;}
c.pc=270249547u;}
static void b_101bae4a(Context& c){
{uint32_t a=(c.r[13]+0u+84u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{fcmp(c,fs(c,15),0);}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,9)){c.pc=(270249572u|1u);return;}}
c.pc=270249561u;}
static void b_101bae58(Context& c){
{uint32_t a=(c.r[5]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=28u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270249573u;c.pc=c.r[3];return;}
c.pc=270249573u;}
static void b_101bae64(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[5]+0u+140u);setsbits(c,18,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{c.r[14]=270249587u;c.pc=(270392110u|1u);return;}
c.pc=270249587u;}
static void b_101bae72(Context& c){
{uint32_t a=(c.r[13]+0u+88u);c.r[6]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[5]+0u+144u);setsbits(c,17,rd<uint32_t>(c,a+0u));}
{setsbits(c,16,cvti(fs(c,16),true));}
{setsbits(c,18,cvti(fs(c,18),true));}
{uint32_t v=add(c,c.r[6],c.r[0],0,false);c.r[6]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270249609u;c.pc=(270392138u|1u);return;}
c.pc=270249609u;}
static void b_101bae88(Context& c){
{setfs(c,15,int32_t(sbits(c,16)));}
{uint32_t v=shift(c,c.r[0],1u,3,true);nz(c,v);c.r[0]=v;}
{setsbits(c,13,c.r[0]);}
{setfs(c,14,int32_t(sbits(c,13)));}
{setfs(c,17,(fs(c,17))-(fs(c,14)));}
{fcmp(c,fs(c,15),fs(c,17));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,14)){c.pc=(270249664u|1u);return;}}
c.pc=270249637u;}
static void b_101baea4(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[5]+0u+144u);setsbits(c,17,rd<uint32_t>(c,a+0u));}
{c.r[14]=270249647u;c.pc=(270392138u|1u);return;}
c.pc=270249647u;}
static void b_101baeae(Context& c){
{uint32_t v=shift(c,c.r[0],1u,3,true);nz(c,v);c.r[0]=v;}
{setsbits(c,15,c.r[0]);}
{setfs(c,16,int32_t(sbits(c,15)));}
{setfs(c,16,(fs(c,17))-(fs(c,16)));}
{setsbits(c,16,cvti(fs(c,16),true));}
{uint32_t a=(c.r[5]+0u+240u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[5]+0u+120u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[3]+0u+76u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+60u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t a=(c.r[13]+0u+56u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270249683u;c.pc=c.r[3];return;}
c.pc=270249683u;}
static void b_101baec0(Context& c){
{uint32_t a=(c.r[5]+0u+240u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[5]+0u+120u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[3]+0u+76u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+60u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t a=(c.r[13]+0u+56u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270249683u;c.pc=c.r[3];return;}
c.pc=270249683u;}
static void b_101baed2(Context& c){
{uint32_t a=(c.r[4]+0u+340u);c.r[7]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[0];c.r[11]=v;}
{c.r[14]=270249693u;c.pc=(270394904u|1u);return;}
c.pc=270249693u;}
static void b_101baedc(Context& c){
{uint32_t a=(c.r[13]+0u+56u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[5]+0u+98u);c.r[3]=rd<uint16_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+60u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[13]+0u+68u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t a=(c.r[13]+0u+80u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[13]+0u+72u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t a=(c.r[13]+0u+92u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[13]+0u+76u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+36u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[13]+0u+40u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t a=(c.r[13]+0u+24u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[13]+0u+84u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+44u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t a=(c.r[13]+0u+32u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=c.r[11];c.r[2]=v;}
{uint32_t a=(c.r[5]+0u+116u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+48u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t a=(c.r[5]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[0];c.r[9]=v;}
{c.r[14]=270249757u;c.pc=(270395744u|1u);return;}
c.pc=270249757u;}
static void b_101baf1c(Context& c){
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270250076u|1u);return;}}
c.pc=270249765u;}
static void b_101baf24(Context& c){
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270249771u;c.pc=(270389454u|1u);return;}
c.pc=270249771u;}
static void b_101baf2a(Context& c){
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[2];c.r[3]=v;}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270249783u;c.pc=(270393366u|1u);return;}
c.pc=270249783u;}
static void b_101baf36(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[6]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[6]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[13]+0u+88u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,13)){c.pc=(270249802u|1u);return;}}
c.pc=270249797u;}
static void b_101baf44(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{c.r[14]=270249803u;c.pc=(270389436u|1u);return;}
c.pc=270249803u;}
static void b_101baf4a(Context& c){
{uint32_t a=(c.r[4]+0u+336u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] == 0){c.pc=(270249818u|1u);return;}}
c.pc=270249809u;}
static void b_101baf50(Context& c){
{uint32_t v=c.r[8];c.r[0]=v;}
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+84u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270249819u;c.pc=(269997700u|1u);return;}
c.pc=270249819u;}
static void b_101baf5a(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+76u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270249827u;c.pc=c.r[3];return;}
c.pc=270249827u;}
static void b_101baf62(Context& c){
{uint32_t v=401u;c.r[3]=v;}
{uint32_t v=add(c,c.r[0],~(c.r[3]),1,true);}
{if(cond(c,2)){c.pc=(270250076u|1u);return;}}
c.pc=270249835u;}
static void b_101baf6a(Context& c){
{uint32_t a=(c.r[5]+0u+112u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[6]+0u+140u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[5]+0u+120u);c.r[5]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[3])^(1u);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],14u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[9]+shift(c,c.r[3],2,1,false)+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[5],~(270u),1,true);c.r[3]=v;}
{uint32_t v=add(c,0u,~(c.r[3]),1,true);c.r[5]=v;}
{uint32_t v=add(c,c.r[5],c.r[3],c.c,true);c.r[5]=v;}
{uint32_t a=(c.r[13]+0u+88u);c.r[3]=rd<uint32_t>(c,a+0u);}
{if(c.r[5] == 0){c.pc=(270249876u|1u);return;}}
c.pc=270249865u;}
static void b_101baf88(Context& c){
{uint32_t v=add(c,0u,~(c.r[3]),1,true);c.r[1]=v;}
{setsbits(c,16,c.r[1]);}
{setfs(c,16,int32_t(sbits(c,16)));}
{c.pc=(270249884u|1u);return;}
c.pc=270249877u;}
static void b_101baf94(Context& c){
{setsbits(c,13,c.r[3]);}
{setfs(c,16,int32_t(sbits(c,13)));}
{setfs(c,16,(fs(c,16))+(fs(c,14)));}
{setsbits(c,16,cvti(fs(c,16),true));}
{if(c.r[2] == 0){c.pc=(270249922u|1u);return;}}
c.pc=270249895u;}
static void b_101baf9c(Context& c){
{setfs(c,16,(fs(c,16))+(fs(c,14)));}
{setsbits(c,16,cvti(fs(c,16),true));}
{if(c.r[2] == 0){c.pc=(270249922u|1u);return;}}
c.pc=270249895u;}
static void b_101bafa6(Context& c){
{uint32_t a=(c.r[2]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,14,(fs(c,15))-(fs(c,14)));}
{setfs(c,14,std::fabs(fs(c,14)));}
{setsbits(c,14,cvti(fs(c,14),true));}
{c.r[1]=sbits(c,14);}
{uint32_t v=add(c,c.r[1],~(c.r[3]),1,true);}
{}
{if(cond(c,12)){setsbits(c,16,cvti(fs(c,15),true));}}
{c.r[14]=270249927u;c.pc=(270408416u|1u);return;}
c.pc=270249927u;}
static void b_101bafc2(Context& c){
{c.r[14]=270249927u;c.pc=(270408416u|1u);return;}
c.pc=270249927u;}
static void b_101bafc6(Context& c){
{c.r[1]=sbits(c,16);}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[14]=270249937u;c.pc=(270408818u|1u);return;}
c.pc=270249937u;}
static void b_101bafd0(Context& c){
{uint32_t a=(c.r[6]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,16,int32_t(sbits(c,16)));}
{setfs(c,16,(fs(c,16))-(fs(c,15)));}
{uint32_t a=(c.r[6]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,17,std::fabs(fs(c,16)));}
{setsbits(c,13,c.r[0]);}
{setfs(c,18,int32_t(sbits(c,13)));}
{setfs(c,18,(fs(c,18))-(fs(c,15)));}
{uint32_t a=(c.r[13]+0u+84u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,14,std::fabs(fs(c,18)));}
{fcmp(c,fs(c,17),fs(c,14));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,14)){c.pc=(270250028u|1u);return;}}
c.pc=270249987u;}
static void b_101bb002(Context& c){
{if(c.r[5] == 0){c.pc=(270249992u|1u);return;}}
c.pc=270249989u;}
static void b_101bb004(Context& c){
{setfs(c,15,-(fs(c,15)));}
{c.r[1]=sbits(c,15);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{setfs(c,17,(fs(c,18))/(fs(c,17)));}
{c.r[14]=270250013u;c.pc=(270392848u|1u);return;}
c.pc=270250013u;}
static void b_101bb008(Context& c){
{c.r[1]=sbits(c,15);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{setfs(c,17,(fs(c,18))/(fs(c,17)));}
{c.r[14]=270250013u;c.pc=(270392848u|1u);return;}
c.pc=270250013u;}
static void b_101bb01c(Context& c){
{uint32_t a=(c.r[13]+0u+84u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=c.r[6];c.r[0]=v;}
{setfs(c,15,(fs(c,17))*(fs(c,15)));}
{c.r[1]=sbits(c,15);}
{c.pc=(270250056u|1u);return;}
c.pc=270250029u;}
static void b_101bb02c(Context& c){
{setfs(c,14,(fs(c,16))/(fs(c,14)));}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{setfs(c,15,(fs(c,14))*(fs(c,15)));}
{c.r[1]=sbits(c,15);}
{c.r[14]=270250053u;c.pc=(270392848u|1u);return;}
c.pc=270250053u;}
static void b_101bb044(Context& c){
{uint32_t a=(c.r[13]+0u+84u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270250067u;c.pc=(270392910u|1u);return;}
c.pc=270250067u;}
static void b_101bb048(Context& c){
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270250067u;c.pc=(270392910u|1u);return;}
c.pc=270250067u;}
static void b_101bb052(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[14]=270250077u;c.pc=(270391848u|1u);return;}
c.pc=270250077u;}
static void b_101bb05c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270250083u;c.pc=(270391404u|1u);return;}
c.pc=270250083u;}
static void b_101bb062(Context& c){
{uint32_t v=add(c,c.r[13],100u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);uint32_t newpc=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;c.pc=newpc;return;}
c.pc=270250093u;}
static void b_101bb06c(Context& c){
{uint32_t a=c.r[13]-32u;wr<uint32_t>(c,a+0u,c.r[0]);wr<uint32_t>(c,a+4u,c.r[1]);wr<uint32_t>(c,a+8u,c.r[4]);wr<uint32_t>(c,a+12u,c.r[5]);wr<uint32_t>(c,a+16u,c.r[6]);wr<uint32_t>(c,a+20u,c.r[7]);wr<uint32_t>(c,a+24u,c.r[8]);wr<uint32_t>(c,a+28u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[3];c.r[8]=v;}
{uint32_t a=(c.r[1]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[2];c.r[4]=v;}
{uint32_t v=add(c,c.r[13],8u,0,false);c.r[2]=v;}
{uint32_t v=0u;nz(c,v);c.r[6]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[1];c.r[5]=v;}
{uint32_t a=(c.r[2]+0u+4294967288u);uint32_t wb=a;wr<uint32_t>(c,a+0u,c.r[6]);c.r[2]=wb;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=2u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[13];c.r[2]=v;}
{c.r[14]=270250125u;c.pc=c.r[3];return;}
c.pc=270250125u;}
static void b_101bb08c(Context& c){
{uint32_t a=(c.r[13]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);}
{if(cond(c,14)){c.pc=(270250198u|1u);return;}}
c.pc=270250131u;}
static void b_101bb092(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270250137u;c.pc=(269975114u|1u);return;}
c.pc=270250137u;}
static void b_101bb098(Context& c){
{if(c.r[0] == 0){c.pc=(270250198u|1u);return;}}
c.pc=270250139u;}
static void b_101bb09a(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+116u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270250147u;c.pc=c.r[3];return;}
c.pc=270250147u;}
static void b_101bb0a2(Context& c){
{uint32_t v=add(c,c.r[0],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270250198u|1u);return;}}
c.pc=270250151u;}
static void b_101bb0a6(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],8u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=47u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[2]+0u+4294967292u);uint32_t wb=a;wr<uint32_t>(c,a+0u,c.r[6]);c.r[2]=wb;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270250167u;c.pc=c.r[3];return;}
c.pc=270250167u;}
static void b_101bb0b6(Context& c){
{uint32_t a=(c.r[4]+0u+124u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270250180u|1u);return;}}
c.pc=270250173u;}
static void b_101bb0bc(Context& c){
{uint32_t v=add(c,c.r[3],~(200u),1,true);c.r[6]=v;}
{}
{if(cond(c,2)){uint32_t v=1u;c.r[6]=v;}}
{uint32_t a=(c.r[13]+0u+4u);c.r[3]=rd<uint32_t>(c,a+0u);}
{if(c.r[3] == 0){c.pc=(270250210u|1u);return;}}
c.pc=270250185u;}
static void b_101bb0c4(Context& c){
{uint32_t a=(c.r[13]+0u+4u);c.r[3]=rd<uint32_t>(c,a+0u);}
{if(c.r[3] == 0){c.pc=(270250210u|1u);return;}}
c.pc=270250185u;}
static void b_101bb0c8(Context& c){
{if(c.r[6] == 0){c.pc=(270250210u|1u);return;}}
c.pc=270250187u;}
static void b_101bb0ca(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[4];c.r[2]=v;}
{c.r[14]=270250197u;c.pc=(270249422u|1u);return;}
c.pc=270250197u;}
static void b_101bb0d4(Context& c){
{c.pc=(270250210u|1u);return;}
c.pc=270250199u;}
static void b_101bb0d6(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[4];c.r[2]=v;}
{uint32_t v=c.r[8];c.r[3]=v;}
{c.r[14]=270250211u;c.pc=(269939764u|1u);return;}
c.pc=270250211u;}
static void b_101bb0e2(Context& c){
{uint32_t v=add(c,c.r[13],8u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270250217u;}
static void b_101bb0e8(Context& c){
{uint32_t a=c.r[13]-12u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+252u);c.r[5]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],~(20u),1,false);c.r[13]=v;}
{if(c.r[5] != 0){c.pc=(270250286u|1u);return;}}
c.pc=270250229u;}
static void b_101bb0f4(Context& c){
{uint32_t a=(c.r[1]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],8u,0,false);c.r[2]=v;}
{uint32_t v=38u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270250241u;c.pc=c.r[3];return;}
c.pc=270250241u;}
static void b_101bb100(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=39u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270250253u;c.pc=c.r[3];return;}
c.pc=270250253u;}
static void b_101bb10c(Context& c){
{uint32_t a=(c.r[4]+0u+277u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+12u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270250273u;c.pc=(270393892u|1u);return;}
c.pc=270250273u;}
static void b_101bb120(Context& c){
{if(c.r[0] == 0){c.pc=(270250286u|1u);return;}}
c.pc=270250275u;}
static void b_101bb122(Context& c){
{uint32_t a=(c.r[4]+0u+240u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[0]+0u+240u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);uint32_t newpc=rd<uint32_t>(c,a+8u);c.r[13]=a+12u;c.pc=newpc;return;}
c.pc=270250291u;}
static void b_101bb12e(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);uint32_t newpc=rd<uint32_t>(c,a+8u);c.r[13]=a+12u;c.pc=newpc;return;}
c.pc=270250291u;}
static void b_101bb134(Context& c){
{uint32_t a=c.r[13]-32u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[3];c.r[9]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[2];c.r[5]=v;}
{c.r[14]=270250309u;c.pc=(270326600u|1u);return;}
c.pc=270250309u;}
static void b_101bb144(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[10]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],18432u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(5u),1,true);c.r[3]=v;}
{uint32_t v=add(c,0u,~(c.r[3]),1,true);c.r[8]=v;}
{uint32_t v=add(c,c.r[8],c.r[3],c.c,true);c.r[8]=v;}
{uint32_t v=add(c,c.r[10],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270250404u|1u);return;}}
c.pc=270250335u;}
static void b_101bb15e(Context& c){
{uint32_t v=1u;nz(c,v);c.r[6]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270250347u;c.pc=(269975106u|1u);return;}
c.pc=270250347u;}
static void b_101bb16a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[6];c.r[1]=v;}
{c.r[14]=270250355u;c.pc=(269975948u|1u);return;}
c.pc=270250355u;}
static void b_101bb172(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[6];c.r[1]=v;}
{c.r[14]=270250363u;c.pc=(269975400u|1u);return;}
c.pc=270250363u;}
static void b_101bb17a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[6];c.r[1]=v;}
{c.r[14]=270250371u;c.pc=(269975962u|1u);return;}
c.pc=270250371u;}
static void b_101bb182(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[10];c.r[1]=v;}
{uint32_t v=175u;nz(c,v);c.r[2]=v;}
{c.r[14]=270250381u;c.pc=(270393746u|1u);return;}
c.pc=270250381u;}
static void b_101bb18c(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270250404u|1u);return;}}
c.pc=270250387u;}
static void b_101bb192(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270250395u;c.pc=(270250216u|1u);return;}
c.pc=270250395u;}
static void b_101bb19a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270250401u;c.pc=(270391404u|1u);return;}
c.pc=270250401u;}
static void b_101bb1a0(Context& c){
{uint32_t v=4u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[5],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270250506u|1u);return;}}
c.pc=270250409u;}
static void b_101bb1a4(Context& c){
{uint32_t v=add(c,c.r[5],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270250506u|1u);return;}}
c.pc=270250409u;}
static void b_101bb1a8(Context& c){
{if(cond(c,13)){c.pc=(270250432u|1u);return;}}
c.pc=270250411u;}
static void b_101bb1aa(Context& c){
{uint32_t v=add(c,c.r[5],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270250456u|1u);return;}}
c.pc=270250415u;}
static void b_101bb1ae(Context& c){
{if(cond(c,13)){c.pc=(270250424u|1u);return;}}
c.pc=270250417u;}
static void b_101bb1b0(Context& c){
{uint32_t v=add(c,c.r[5],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270250456u|1u);return;}}
c.pc=270250421u;}
static void b_101bb1b4(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270250425u;}
static void b_101bb1b8(Context& c){
{uint32_t v=add(c,c.r[5],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270250506u|1u);return;}}
c.pc=270250429u;}
static void b_101bb1bc(Context& c){
{uint32_t v=add(c,c.r[5],~(40u),1,true);}
{c.pc=(270250452u|1u);return;}
c.pc=270250433u;}
static void b_101bb1c0(Context& c){
{uint32_t v=add(c,c.r[5],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270250506u|1u);return;}}
c.pc=270250437u;}
static void b_101bb1c4(Context& c){
{if(cond(c,13)){c.pc=(270250446u|1u);return;}}
c.pc=270250439u;}
static void b_101bb1c6(Context& c){
{uint32_t v=add(c,c.r[5],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270250456u|1u);return;}}
c.pc=270250443u;}
static void b_101bb1ca(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270250447u;}
static void b_101bb1ce(Context& c){
{uint32_t v=add(c,c.r[5],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270250506u|1u);return;}}
c.pc=270250451u;}
static void b_101bb1d2(Context& c){
{uint32_t v=add(c,c.r[5],~(120u),1,true);}
{if(cond(c,2)){c.pc=(270250524u|1u);return;}}
c.pc=270250455u;}
static void b_101bb1d4(Context& c){
{if(cond(c,2)){c.pc=(270250524u|1u);return;}}
c.pc=270250455u;}
static void b_101bb1d6(Context& c){
{c.pc=(270250506u|1u);return;}
c.pc=270250457u;}
static void b_101bb1d8(Context& c){
{uint32_t v=add(c,c.r[9],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270250474u|1u);return;}}
c.pc=270250463u;}
static void b_101bb1de(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=26u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[9];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270250475u;c.pc=(270393366u|1u);return;}
c.pc=270250475u;}
static void b_101bb1ea(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270250524u|1u);return;}}
c.pc=270250481u;}
static void b_101bb1f0(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{}
{if(cond(c,1)){uint32_t a=((270250502u&~3u)+0u+28u);c.r[1]=rd<uint32_t>(c,a+0u);}}
{if(cond(c,2)){uint32_t a=((270250504u&~3u)+0u+28u);c.r[1]=rd<uint32_t>(c,a+0u);}}
{c.pc=(270392848u|1u);return;}
c.pc=270250507u;}
static void b_101bb20a(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270250515u;c.pc=(270250216u|1u);return;}
c.pc=270250515u;}
static void b_101bb212(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270250521u;c.pc=(270391404u|1u);return;}
c.pc=270250521u;}
static void b_101bb218(Context& c){
{uint32_t v=4u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270250529u;}
static void b_101bb21c(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270250529u;}
static void b_101bb228(Context& c){
{uint32_t a=c.r[13]-8u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270250558u|1u);return;}}
c.pc=270250547u;}
static void b_101bb232(Context& c){
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[1]+0u+60u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=~(49u);c.r[2]=v;}
{uint32_t a=(c.r[1]+0u+32u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.pc=(270250570u|1u);return;}
c.pc=270250559u;}
static void b_101bb23e(Context& c){
{uint32_t v=add(c,c.r[3],~(10u),1,true);}
{if(cond(c,2)){c.pc=(270250572u|1u);return;}}
c.pc=270250563u;}
static void b_101bb242(Context& c){
{uint32_t v=50u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270250578u&~3u)+0u+60u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{c.r[14]=270250621u;c.pc=(270393746u|1u);return;}
c.pc=270250621u;}
static void b_101bb24a(Context& c){
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270250578u&~3u)+0u+60u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{c.r[14]=270250621u;c.pc=(270393746u|1u);return;}
c.pc=270250621u;}
static void b_101bb24c(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270250578u&~3u)+0u+60u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{c.r[14]=270250621u;c.pc=(270393746u|1u);return;}
c.pc=270250621u;}
static void b_101bb27c(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(17u),1,true);}
{}
{if(cond(c,14)){uint32_t v=add(c,c.r[3],1u,0,false);c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270250635u;}
static void b_101bb290(Context& c){
{uint32_t a=c.r[13]-20u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[3];c.r[5]=v;}
{uint32_t a=(c.r[1]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],~(20u),1,false);c.r[13]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[2];c.r[6]=v;}
{if(c.r[3] != 0){c.pc=(270250734u|1u);return;}}
c.pc=270250657u;}
static void b_101bb2a0(Context& c){
{uint32_t v=1u;nz(c,v);c.r[5]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t a=(c.r[1]+0u+28u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270250669u;c.pc=(269976986u|1u);return;}
c.pc=270250669u;}
static void b_101bb2ac(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270250677u;c.pc=(269976968u|1u);return;}
c.pc=270250677u;}
static void b_101bb2b4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270250685u;c.pc=(269975400u|1u);return;}
c.pc=270250685u;}
static void b_101bb2bc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270250693u;c.pc=(269975414u|1u);return;}
c.pc=270250693u;}
static void b_101bb2c4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270250701u;c.pc=(269975768u|1u);return;}
c.pc=270250701u;}
static void b_101bb2cc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270250709u;c.pc=(269975948u|1u);return;}
c.pc=270250709u;}
static void b_101bb2d4(Context& c){
{uint32_t a=((270250712u&~3u)+0u+348u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=71u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270391848u|1u);return;}
c.pc=270250735u;}
static void b_101bb2ee(Context& c){
{uint32_t v=add(c,c.r[2],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270250920u|1u);return;}}
c.pc=270250739u;}
static void b_101bb2f2(Context& c){
{if(cond(c,13)){c.pc=(270250766u|1u);return;}}
c.pc=270250741u;}
static void b_101bb2f4(Context& c){
{uint32_t v=add(c,c.r[2],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270250866u|1u);return;}}
c.pc=270250745u;}
static void b_101bb2f8(Context& c){
{if(cond(c,13)){c.pc=(270250756u|1u);return;}}
c.pc=270250747u;}
static void b_101bb2fa(Context& c){
{uint32_t v=add(c,c.r[2],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270250832u|1u);return;}}
c.pc=270250751u;}
static void b_101bb2fe(Context& c){
{uint32_t v=add(c,c.r[2],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270250832u|1u);return;}}
c.pc=270250755u;}
static void b_101bb302(Context& c){
{c.pc=(270251056u|1u);return;}
c.pc=270250757u;}
static void b_101bb304(Context& c){
{uint32_t v=add(c,c.r[2],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270250866u|1u);return;}}
c.pc=270250761u;}
static void b_101bb308(Context& c){
{uint32_t v=add(c,c.r[2],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270250890u|1u);return;}}
c.pc=270250765u;}
static void b_101bb30c(Context& c){
{c.pc=(270251056u|1u);return;}
c.pc=270250767u;}
static void b_101bb30e(Context& c){
{uint32_t v=add(c,c.r[2],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270250946u|1u);return;}}
c.pc=270250771u;}
static void b_101bb312(Context& c){
{if(cond(c,13)){c.pc=(270250782u|1u);return;}}
c.pc=270250773u;}
static void b_101bb314(Context& c){
{uint32_t v=add(c,c.r[2],~(71u),1,true);}
{if(cond(c,1)){c.pc=(270250792u|1u);return;}}
c.pc=270250777u;}
static void b_101bb318(Context& c){
{uint32_t v=add(c,c.r[2],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270250946u|1u);return;}}
c.pc=270250781u;}
static void b_101bb31c(Context& c){
{c.pc=(270251056u|1u);return;}
c.pc=270250783u;}
static void b_101bb31e(Context& c){
{uint32_t v=add(c,c.r[2],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270250946u|1u);return;}}
c.pc=270250787u;}
static void b_101bb322(Context& c){
{uint32_t v=add(c,c.r[2],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270251038u|1u);return;}}
c.pc=270250791u;}
static void b_101bb326(Context& c){
{c.pc=(270251056u|1u);return;}
c.pc=270250793u;}
static void b_101bb328(Context& c){
{if(c.r[5] != 0){c.pc=(270250800u|1u);return;}}
c.pc=270250795u;}
static void b_101bb32a(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270250984u|1u);return;}
c.pc=270250801u;}
static void b_101bb330(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[5]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270251056u|1u);return;}}
c.pc=270250809u;}
static void b_101bb338(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270250817u;c.pc=(269976968u|1u);return;}
c.pc=270250817u;}
static void b_101bb340(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270250825u;c.pc=(269975400u|1u);return;}
c.pc=270250825u;}
static void b_101bb348(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270251056u|1u);return;}
c.pc=270250833u;}
static void b_101bb350(Context& c){
{if(c.r[5] != 0){c.pc=(270250852u|1u);return;}}
c.pc=270250835u;}
static void b_101bb352(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270250847u;c.pc=(270393366u|1u);return;}
c.pc=270250847u;}
static void b_101bb35e(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270250536u|1u);return;}
c.pc=270250867u;}
static void b_101bb364(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270250536u|1u);return;}
c.pc=270250867u;}
static void b_101bb372(Context& c){
{if(c.r[5] != 0){c.pc=(270250874u|1u);return;}}
c.pc=270250869u;}
static void b_101bb374(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{c.pc=(270250896u|1u);return;}
c.pc=270250875u;}
static void b_101bb37a(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270250852u|1u);return;}}
c.pc=270250883u;}
static void b_101bb382(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.pc=(270250914u|1u);return;}
c.pc=270250891u;}
static void b_101bb38a(Context& c){
{if(c.r[5] != 0){c.pc=(270250906u|1u);return;}}
c.pc=270250893u;}
static void b_101bb38c(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270250905u;c.pc=(270393366u|1u);return;}
c.pc=270250905u;}
static void b_101bb390(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270250905u;c.pc=(270393366u|1u);return;}
c.pc=270250905u;}
static void b_101bb398(Context& c){
{c.pc=(270250852u|1u);return;}
c.pc=270250907u;}
static void b_101bb39a(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270250852u|1u);return;}}
c.pc=270250915u;}
static void b_101bb3a2(Context& c){
{c.r[14]=270250919u;c.pc=(269980032u|1u);return;}
c.pc=270250919u;}
static void b_101bb3a6(Context& c){
{c.pc=(270250852u|1u);return;}
c.pc=270250921u;}
static void b_101bb3a8(Context& c){
{if(c.r[5] != 0){c.pc=(270250928u|1u);return;}}
c.pc=270250923u;}
static void b_101bb3aa(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270250896u|1u);return;}
c.pc=270250929u;}
static void b_101bb3b0(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270250852u|1u);return;}}
c.pc=270250937u;}
static void b_101bb3b8(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.r[14]=270250945u;c.pc=(270391848u|1u);return;}
c.pc=270250945u;}
static void b_101bb3c0(Context& c){
{c.pc=(270250852u|1u);return;}
c.pc=270250947u;}
static void b_101bb3c2(Context& c){
{if(c.r[5] != 0){c.pc=(270250998u|1u);return;}}
c.pc=270250949u;}
static void b_101bb3c4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270250955u;c.pc=(270392138u|1u);return;}
c.pc=270250955u;}
static void b_101bb3ca(Context& c){
{uint32_t v=65284u;c.r[2]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=4294967295u;c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[7];c.r[0]=v;}
{c.r[14]=270250981u;c.pc=(270015700u|1u);return;}
c.pc=270250981u;}
static void b_101bb3e4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270393366u|1u);return;}
c.pc=270250999u;}
static void b_101bb3e8(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270393366u|1u);return;}
c.pc=270250999u;}
static void b_101bb3f6(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[5]=rd<uint8_t>(c,a+0u);}
{if(c.r[5] != 0){c.pc=(270251056u|1u);return;}}
c.pc=270251005u;}
static void b_101bb3fc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270251011u;c.pc=(270392138u|1u);return;}
c.pc=270251011u;}
static void b_101bb402(Context& c){
{uint32_t v=65284u;c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=4294967295u;c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[7];c.r[0]=v;}
{c.r[14]=270251037u;c.pc=(270015700u|1u);return;}
c.pc=270251037u;}
static void b_101bb41c(Context& c){
{c.pc=(270251044u|1u);return;}
c.pc=270251039u;}
static void b_101bb41e(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270251056u|1u);return;}}
c.pc=270251045u;}
static void b_101bb424(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270391404u|1u);return;}
c.pc=270251057u;}
static void b_101bb430(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);uint32_t newpc=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;c.pc=newpc;return;}
c.pc=270251061u;}
static void b_101bb438(Context& c){
{uint32_t a=c.r[13]-16u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-8u;wr<uint64_t>(c,a+0u,c.d[8]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=add(c,c.r[13],~(16u),1,false);c.r[13]=v;}
{c.r[14]=270251079u;c.pc=(270394904u|1u);return;}
c.pc=270251079u;}
static void b_101bb446(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+116u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270251087u;c.pc=(269978260u|1u);return;}
c.pc=270251087u;}
static void b_101bb44e(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{if(c.r[0] != 0){c.pc=(270251190u|1u);return;}}
c.pc=270251091u;}
static void b_101bb452(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270251103u;c.pc=c.r[3];return;}
c.pc=270251103u;}
static void b_101bb45e(Context& c){
{uint32_t a=(c.r[4]+0u+277u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=343u;c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+12u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270251125u;c.pc=(270393892u|1u);return;}
c.pc=270251125u;}
static void b_101bb474(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{if(c.r[0] == 0){c.pc=(270251190u|1u);return;}}
c.pc=270251129u;}
static void b_101bb478(Context& c){
{uint32_t a=(c.r[4]+0u+240u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[0]+0u+240u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+140u);c.r[6]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{c.r[14]=270251151u;c.pc=(270392138u|1u);return;}
c.pc=270251151u;}
static void b_101bb48e(Context& c){
{uint32_t a=((270251154u&~3u)+0u+48u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,(fs(c,16))+(fs(c,15)));}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[5]+0u+148u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[5]+0u+140u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[5]+0u+56u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,13,c.r[0]);}
{setfs(c,14,int32_t(sbits(c,13)));}
{setfs(c,15,(fs(c,15))+(fs(c,14)));}
{uint32_t a=(c.r[5]+0u+152u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[5]+0u+144u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.r[13]=a+8u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270251199u;}
static void b_101bb4b6(Context& c){
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.r[13]=a+8u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270251199u;}
static void b_101bb4c4(Context& c){
{uint32_t a=c.r[13]-36u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[11]);wr<uint32_t>(c,a+32u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-24u;wr<uint64_t>(c,a+0u,c.d[8]);wr<uint64_t>(c,a+8u,c.d[9]);wr<uint64_t>(c,a+16u,c.d[10]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[4]=v;}
{uint32_t a=((270251218u&~3u)+0u+488u);setsbits(c,18,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[13],~(36u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[5]=v;}
{c.r[14]=270251229u;c.pc=(270392138u|1u);return;}
c.pc=270251229u;}
static void b_101bb4dc(Context& c){
{uint32_t v=1u;c.r[8]=v;}
{uint32_t v=4294967295u;c.r[6]=v;}
{uint32_t v=65284u;c.r[7]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=~(129u);c.r[2]=v;}
{uint32_t v=130u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{setfs(c,21,-16.0);}
{uint32_t v=8u;c.r[11]=v;}
{uint32_t a=((270251268u&~3u)+0u+440u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{setfs(c,17,-10.0);}
{setfs(c,20,16.0);}
{uint32_t v=c.r[0];c.r[9]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270251285u;c.pc=(270015700u|1u);return;}
c.pc=270251285u;}
static void b_101bb514(Context& c){
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=~(79u);c.r[2]=v;}
{uint32_t v=90u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{setfs(c,19,-8.0);}
{c.r[14]=270251311u;c.pc=(270015700u|1u);return;}
c.pc=270251311u;}
static void b_101bb52e(Context& c){
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=~(39u);c.r[2]=v;}
{uint32_t v=240u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{c.r[14]=270251333u;c.pc=(270015700u|1u);return;}
c.pc=270251333u;}
static void b_101bb544(Context& c){
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=~(69u);c.r[2]=v;}
{uint32_t v=170u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270251355u;c.pc=(270015700u|1u);return;}
c.pc=270251355u;}
static void b_101bb55a(Context& c){
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=180u;nz(c,v);c.r[2]=v;}
{uint32_t v=170u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270251375u;c.pc=(270015700u|1u);return;}
c.pc=270251375u;}
static void b_101bb56e(Context& c){
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=30u;nz(c,v);c.r[2]=v;}
{uint32_t v=180u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270251395u;c.pc=(270015700u|1u);return;}
c.pc=270251395u;}
static void b_101bb582(Context& c){
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=150u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=130u;nz(c,v);c.r[2]=v;}
{c.r[14]=270251415u;c.pc=(270015700u|1u);return;}
c.pc=270251415u;}
static void b_101bb596(Context& c){
{uint32_t a=(c.r[5]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,2)){uint32_t v=c.r[6];c.r[10]=v;}}
{if(cond(c,1)){uint32_t v=c.r[8];c.r[10]=v;}}
{uint32_t v=shift(c,c.r[9],(c.r[8]&255u),3,false);c.r[6]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270251435u;c.pc=(270082278u|1u);return;}
c.pc=270251435u;}
static void b_101bb5a4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270251435u;c.pc=(270082278u|1u);return;}
c.pc=270251435u;}
static void b_101bb5aa(Context& c){
{uint32_t v=c.r[0];c.r[8]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270251443u;c.pc=(270082278u|1u);return;}
c.pc=270251443u;}
static void b_101bb5b2(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[8];c.r[0]=v;}
{c.r[14]=270251453u;c.pc=(270697604u|1u);return;}
c.pc=270251453u;}
static void b_101bb5bc(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=0u;c.r[8]=v;}
{uint32_t v=1u;nz(c,v);c.r[7]=v;}
{uint32_t v=add(c,c.r[1],~(130u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270251475u;c.pc=(270697604u|1u);return;}
c.pc=270251475u;}
static void b_101bb5d2(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,21));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=shift(c,c.r[1],1u,1,true);nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);c.r[3]=v;}
{c.r[14]=270251511u;c.pc=(270091396u|1u);return;}
c.pc=270251511u;}
static void b_101bb5f6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270251517u;c.pc=(270082278u|1u);return;}
c.pc=270251517u;}
static void b_101bb5fc(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270251527u;c.pc=(270082278u|1u);return;}
c.pc=270251527u;}
static void b_101bb606(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270251541u;c.pc=(270697604u|1u);return;}
c.pc=270251541u;}
static void b_101bb614(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],30u,0,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270251559u;c.pc=(270697604u|1u);return;}
c.pc=270251559u;}
static void b_101bb626(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,20));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=shift(c,c.r[1],(c.r[7]&255u),1,false);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);c.r[3]=v;}
{c.r[14]=270251597u;c.pc=(270082284u|1u);return;}
c.pc=270251597u;}
static void b_101bb64c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270251603u;c.pc=(270082278u|1u);return;}
c.pc=270251603u;}
static void b_101bb652(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270251613u;c.pc=(270082278u|1u);return;}
c.pc=270251613u;}
static void b_101bb65c(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270251627u;c.pc=(270697604u|1u);return;}
c.pc=270251627u;}
static void b_101bb66a(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(50u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270251645u;c.pc=(270697604u|1u);return;}
c.pc=270251645u;}
static void b_101bb67c(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,19));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=shift(c,c.r[1],(c.r[7]&255u),1,false);c.r[3]=v;}
{uint32_t v=1090519040u;c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270251685u;c.pc=(270082284u|1u);return;}
c.pc=270251685u;}
static void b_101bb6a4(Context& c){
{uint32_t v=add(c,c.r[11],~(1u),1,true);c.r[11]=v;}
{if(cond(c,2)){c.pc=(270251428u|1u);return;}}
c.pc=270251693u;}
static void b_101bb6ac(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.d[10]=rd<uint64_t>(c,a+16u);c.r[13]=a+24u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);uint32_t newpc=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;c.pc=newpc;return;}
c.pc=270251703u;}
static void b_101bb6c0(Context& c){
{uint32_t a=c.r[13]-8u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270251734u|1u);return;}}
c.pc=270251723u;}
static void b_101bb6ca(Context& c){
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[1]+0u+60u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=~(49u);c.r[2]=v;}
{uint32_t a=(c.r[1]+0u+32u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.pc=(270251746u|1u);return;}
c.pc=270251735u;}
static void b_101bb6d6(Context& c){
{uint32_t v=add(c,c.r[3],~(10u),1,true);}
{if(cond(c,2)){c.pc=(270251748u|1u);return;}}
c.pc=270251739u;}
static void b_101bb6da(Context& c){
{uint32_t v=50u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270251754u&~3u)+0u+60u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{c.r[14]=270251797u;c.pc=(270393746u|1u);return;}
c.pc=270251797u;}
static void b_101bb6e2(Context& c){
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270251754u&~3u)+0u+60u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{c.r[14]=270251797u;c.pc=(270393746u|1u);return;}
c.pc=270251797u;}
static void b_101bb6e4(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270251754u&~3u)+0u+60u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{c.r[14]=270251797u;c.pc=(270393746u|1u);return;}
c.pc=270251797u;}
static void b_101bb714(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(17u),1,true);}
{}
{if(cond(c,14)){uint32_t v=add(c,c.r[3],1u,0,false);c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270251811u;}
static void b_101bb728(Context& c){
{uint32_t a=(c.r[1]+0u+252u);c.r[3]=rd<uint32_t>(c,a+0u);}
{if(c.r[3] == 0){c.pc=(270251834u|1u);return;}}
c.pc=270251823u;}
static void b_101bb72e(Context& c){
{uint32_t a=(c.r[1]+0u+140u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[3]+0u+148u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[3]+0u+140u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.pc=c.r[14];return;}
c.pc=270251837u;}
static void b_101bb73a(Context& c){
{c.pc=c.r[14];return;}
c.pc=270251837u;}
static void b_101bb73c(Context& c){
{uint32_t a=c.r[13]-24u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[3];c.r[5]=v;}
{uint32_t a=(c.r[1]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],~(24u),1,false);c.r[13]=v;}
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{if(c.r[3] != 0){c.pc=(270251936u|1u);return;}}
c.pc=270251853u;}
static void b_101bb74c(Context& c){
{uint32_t v=1u;nz(c,v);c.r[5]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t a=(c.r[1]+0u+28u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270251865u;c.pc=(269975422u|1u);return;}
c.pc=270251865u;}
static void b_101bb758(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270251873u;c.pc=(269975414u|1u);return;}
c.pc=270251873u;}
static void b_101bb760(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270251881u;c.pc=(269975768u|1u);return;}
c.pc=270251881u;}
static void b_101bb768(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270251889u;c.pc=(269975724u|1u);return;}
c.pc=270251889u;}
static void b_101bb770(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270251897u;c.pc=(269976986u|1u);return;}
c.pc=270251897u;}
static void b_101bb778(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270251905u;c.pc=(269976968u|1u);return;}
c.pc=270251905u;}
static void b_101bb780(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270251913u;c.pc=(269975400u|1u);return;}
c.pc=270251913u;}
static void b_101bb788(Context& c){
{uint32_t v=1115684864u;c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=81u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270251935u;c.pc=(270391848u|1u);return;}
c.pc=270251935u;}
static void b_101bb79e(Context& c){
{c.pc=(270252596u|1u);return;}
c.pc=270251937u;}
static void b_101bb7a0(Context& c){
{uint32_t v=add(c,c.r[2],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270252046u|1u);return;}}
c.pc=270251941u;}
static void b_101bb7a4(Context& c){
{if(cond(c,13)){c.pc=(270251970u|1u);return;}}
c.pc=270251943u;}
static void b_101bb7a6(Context& c){
{uint32_t v=add(c,c.r[2],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270252134u|1u);return;}}
c.pc=270251947u;}
static void b_101bb7aa(Context& c){
{if(cond(c,13)){c.pc=(270251958u|1u);return;}}
c.pc=270251949u;}
static void b_101bb7ac(Context& c){
{uint32_t v=add(c,c.r[2],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270252046u|1u);return;}}
c.pc=270251953u;}
static void b_101bb7b0(Context& c){
{uint32_t v=add(c,c.r[2],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270252058u|1u);return;}}
c.pc=270251957u;}
static void b_101bb7b4(Context& c){
{c.pc=(270252514u|1u);return;}
c.pc=270251959u;}
static void b_101bb7b6(Context& c){
{uint32_t v=add(c,c.r[2],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270252134u|1u);return;}}
c.pc=270251963u;}
static void b_101bb7ba(Context& c){
{uint32_t v=add(c,c.r[2],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270252242u|1u);return;}}
c.pc=270251969u;}
static void b_101bb7c0(Context& c){
{c.pc=(270252514u|1u);return;}
c.pc=270251971u;}
static void b_101bb7c2(Context& c){
{uint32_t v=add(c,c.r[2],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270252322u|1u);return;}}
c.pc=270251977u;}
static void b_101bb7c8(Context& c){
{if(cond(c,13)){c.pc=(270251990u|1u);return;}}
c.pc=270251979u;}
static void b_101bb7ca(Context& c){
{uint32_t v=add(c,c.r[2],~(80u),1,true);}
{if(cond(c,1)){c.pc=(270252296u|1u);return;}}
c.pc=270251985u;}
static void b_101bb7d0(Context& c){
{uint32_t v=add(c,c.r[2],~(81u),1,true);}
{if(cond(c,1)){c.pc=(270252010u|1u);return;}}
c.pc=270251989u;}
static void b_101bb7d4(Context& c){
{c.pc=(270252514u|1u);return;}
c.pc=270251991u;}
static void b_101bb7d6(Context& c){
{uint32_t v=add(c,c.r[2],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270252322u|1u);return;}}
c.pc=270251997u;}
static void b_101bb7dc(Context& c){
{uint32_t v=add(c,c.r[2],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270252508u|1u);return;}}
c.pc=270252003u;}
static void b_101bb7e2(Context& c){
{uint32_t v=add(c,c.r[2],~(110u),1,true);}
{if(cond(c,2)){c.pc=(270252514u|1u);return;}}
c.pc=270252009u;}
static void b_101bb7e8(Context& c){
{c.pc=(270252322u|1u);return;}
c.pc=270252011u;}
static void b_101bb7ea(Context& c){
{if(c.r[5] != 0){c.pc=(270252018u|1u);return;}}
c.pc=270252013u;}
static void b_101bb7ec(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{c.pc=(270252302u|1u);return;}
c.pc=270252019u;}
static void b_101bb7f2(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[5]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270252514u|1u);return;}}
c.pc=270252029u;}
static void b_101bb7fc(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270252037u;c.pc=(269975400u|1u);return;}
c.pc=270252037u;}
static void b_101bb804(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270252045u;c.pc=(269976968u|1u);return;}
c.pc=270252045u;}
static void b_101bb80c(Context& c){
{c.pc=(270252314u|1u);return;}
c.pc=270252047u;}
static void b_101bb80e(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270252514u|1u);return;}}
c.pc=270252053u;}
static void b_101bb814(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270252302u|1u);return;}
c.pc=270252059u;}
static void b_101bb81a(Context& c){
{if(c.r[5] != 0){c.pc=(270252124u|1u);return;}}
c.pc=270252061u;}
static void b_101bb81c(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270252073u;c.pc=(270393366u|1u);return;}
c.pc=270252073u;}
static void b_101bb828(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=5u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270252091u;c.pc=c.r[3];return;}
c.pc=270252091u;}
static void b_101bb83a(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(270u),1,true);}
{if(cond(c,2)){c.pc=(270252110u|1u);return;}}
c.pc=270252099u;}
static void b_101bb842(Context& c){
{uint32_t a=(c.r[13]+0u+20u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,-(fs(c,15)));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+20u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270252125u;c.pc=(270392848u|1u);return;}
c.pc=270252125u;}
static void b_101bb84e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+20u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270252125u;c.pc=(270392848u|1u);return;}
c.pc=270252125u;}
static void b_101bb85c(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270252133u;c.pc=(270251712u|1u);return;}
c.pc=270252133u;}
static void b_101bb864(Context& c){
{c.pc=(270252514u|1u);return;}
c.pc=270252135u;}
static void b_101bb866(Context& c){
{if(c.r[5] != 0){c.pc=(270252206u|1u);return;}}
c.pc=270252137u;}
static void b_101bb868(Context& c){
{c.r[14]=270252141u;c.pc=(270394904u|1u);return;}
c.pc=270252141u;}
static void b_101bb86c(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=343u;c.r[8]=v;}
{c.r[14]=270252153u;c.pc=(270398232u|1u);return;}
c.pc=270252153u;}
static void b_101bb878(Context& c){
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t a=(c.r[5]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+92u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270252165u;c.pc=c.r[3];return;}
c.pc=270252165u;}
static void b_101bb87c(Context& c){
{uint32_t a=(c.r[5]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+92u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270252165u;c.pc=c.r[3];return;}
c.pc=270252165u;}
static void b_101bb884(Context& c){
{if(c.r[0] != 0){c.pc=(270252178u|1u);return;}}
c.pc=270252167u;}
static void b_101bb886(Context& c){
{uint32_t a=(c.r[5]+0u+292u);c.r[5]=rd<uint32_t>(c,a+0u);}
{if(c.r[5] == 0){c.pc=(270252196u|1u);return;}}
c.pc=270252173u;}
static void b_101bb88c(Context& c){
{uint32_t v=add(c,c.r[5],~(284u),1,false);c.r[5]=v;}
{c.pc=(270252196u|1u);return;}
c.pc=270252179u;}
static void b_101bb892(Context& c){
{uint32_t a=(c.r[5]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+76u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270252187u;c.pc=c.r[3];return;}
c.pc=270252187u;}
static void b_101bb89a(Context& c){
{uint32_t v=add(c,c.r[0],~(c.r[8]),1,true);}
{if(cond(c,2)){c.pc=(270252166u|1u);return;}}
c.pc=270252191u;}
static void b_101bb89e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{c.pc=(270252524u|1u);return;}
c.pc=270252197u;}
static void b_101bb8a4(Context& c){
{uint32_t v=add(c,c.r[5],~(c.r[7]),1,true);}
{if(cond(c,2)){c.pc=(270252156u|1u);return;}}
c.pc=270252201u;}
static void b_101bb8a8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{c.pc=(270252524u|1u);return;}
c.pc=270252207u;}
static void b_101bb8ae(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270252220u|1u);return;}}
c.pc=270252213u;}
static void b_101bb8b4(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270252221u;c.pc=(269980032u|1u);return;}
c.pc=270252221u;}
static void b_101bb8bc(Context& c){
{uint32_t v=add(c,c.r[5],~(28u),1,true);}
{if(cond(c,1)){c.pc=(270252230u|1u);return;}}
c.pc=270252225u;}
static void b_101bb8c0(Context& c){
{uint32_t v=add(c,c.r[5],~(72u),1,true);}
{if(cond(c,2)){c.pc=(270252514u|1u);return;}}
c.pc=270252231u;}
static void b_101bb8c6(Context& c){
{uint32_t a=(c.r[4]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(8u),1,true);}
{if(cond(c,2)){c.pc=(270252514u|1u);return;}}
c.pc=270252241u;}
static void b_101bb8d0(Context& c){
{c.pc=(270252534u|1u);return;}
c.pc=270252243u;}
static void b_101bb8d2(Context& c){
{if(c.r[5] != 0){c.pc=(270252266u|1u);return;}}
c.pc=270252245u;}
static void b_101bb8d4(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t a=(c.r[1]+0u+16u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=30u;nz(c,v);c.r[2]=v;}
{uint32_t a=((270252256u&~3u)+0u+348u);c.r[1]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270252259u;c.pc=(270393090u|1u);return;}
c.pc=270252259u;}
static void b_101bb8e2(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270252265u;c.pc=(270393220u|1u);return;}
c.pc=270252265u;}
static void b_101bb8e8(Context& c){
{c.pc=(270252514u|1u);return;}
c.pc=270252267u;}
static void b_101bb8ea(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{c.r[14]=270252273u;c.pc=(269975064u|1u);return;}
c.pc=270252273u;}
static void b_101bb8f0(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270252544u|1u);return;}}
c.pc=270252279u;}
static void b_101bb8f6(Context& c){
{uint32_t a=(c.r[4]+0u+16u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270252544u|1u);return;}}
c.pc=270252287u;}
static void b_101bb8fe(Context& c){
{uint32_t v=2u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+16u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270252524u|1u);return;}
c.pc=270252297u;}
static void b_101bb908(Context& c){
{if(c.r[5] != 0){c.pc=(270252306u|1u);return;}}
c.pc=270252299u;}
static void b_101bb90a(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.pc=(270252526u|1u);return;}
c.pc=270252307u;}
static void b_101bb90e(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{c.pc=(270252526u|1u);return;}
c.pc=270252307u;}
static void b_101bb912(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270252514u|1u);return;}}
c.pc=270252315u;}
static void b_101bb91a(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270252514u|1u);return;}
c.pc=270252323u;}
static void b_101bb922(Context& c){
{if(c.r[5] != 0){c.pc=(270252338u|1u);return;}}
c.pc=270252325u;}
static void b_101bb924(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270252337u;c.pc=(270393366u|1u);return;}
c.pc=270252337u;}
static void b_101bb930(Context& c){
{c.pc=(270252396u|1u);return;}
c.pc=270252339u;}
static void b_101bb932(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[5]=rd<uint8_t>(c,a+0u);}
{if(c.r[5] != 0){c.pc=(270252396u|1u);return;}}
c.pc=270252345u;}
static void b_101bb938(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270252353u;c.pc=(270251204u|1u);return;}
c.pc=270252353u;}
static void b_101bb940(Context& c){
{uint32_t v=31u;nz(c,v);c.r[7]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[3]);wr<uint32_t>(c,a+4u,c.r[7]);}
{uint32_t a=((270252364u&~3u)+0u+244u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=add(c,c.r[3],270252372u,0,false);c.r[3]=v;}
{uint32_t a=(c.r[3]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270252381u;c.pc=(270077468u|1u);return;}
c.pc=270252381u;}
static void b_101bb95c(Context& c){
{if(c.r[0] == 0){c.pc=(270252390u|1u);return;}}
c.pc=270252383u;}
static void b_101bb95e(Context& c){
{c.r[14]=270252387u;c.pc=(270391404u|1u);return;}
c.pc=270252387u;}
static void b_101bb962(Context& c){
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270252397u;c.pc=(270391404u|1u);return;}
c.pc=270252397u;}
static void b_101bb966(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270252397u;c.pc=(270391404u|1u);return;}
c.pc=270252397u;}
static void b_101bb96c(Context& c){
{uint32_t a=(c.r[4]+0u+16u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+16u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,13)){c.pc=(270252514u|1u);return;}}
c.pc=270252407u;}
static void b_101bb976(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{c.r[14]=270252413u;c.pc=(270082278u|1u);return;}
c.pc=270252413u;}
static void b_101bb97c(Context& c){
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.r[14]=270252419u;c.pc=(270697604u|1u);return;}
c.pc=270252419u;}
static void b_101bb982(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],3u,0,true);c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+16u);wr<uint32_t>(c,a+0u,c.r[1]);}
{c.r[14]=270252429u;c.pc=(270082278u|1u);return;}
c.pc=270252429u;}
static void b_101bb98c(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270252437u;c.pc=(270392110u|1u);return;}
c.pc=270252437u;}
static void b_101bb994(Context& c){
{uint32_t v=c.r[0];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270252445u;c.pc=(270697604u|1u);return;}
c.pc=270252445u;}
static void b_101bb99c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[5]=v;}
{c.r[14]=270252453u;c.pc=(270392110u|1u);return;}
c.pc=270252453u;}
static void b_101bb9a4(Context& c){
{uint32_t v=add(c,c.r[5],~(shift(c,c.r[0],1,3,false)),1,false);c.r[5]=v;}
{uint32_t v=c.r[6];c.r[0]=v;}
{c.r[14]=270252463u;c.pc=(270082278u|1u);return;}
c.pc=270252463u;}
static void b_101bb9ae(Context& c){
{uint32_t v=shift(c,c.r[5],1u,1,true);nz(c,v);c.r[5]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270252473u;c.pc=(270392138u|1u);return;}
c.pc=270252473u;}
static void b_101bb9b8(Context& c){
{uint32_t v=c.r[0];c.r[1]=v;}
{uint32_t v=c.r[7];c.r[0]=v;}
{c.r[14]=270252481u;c.pc=(270697604u|1u);return;}
c.pc=270252481u;}
static void b_101bb9c0(Context& c){
{uint32_t v=0u;nz(c,v);c.r[0]=v;}
{uint32_t v=4294967295u;c.r[2]=v;}
{uint32_t v=c.r[1];c.r[3]=v;}
{uint32_t v=65302u;c.r[1]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[0]);wr<uint32_t>(c,a+4u,c.r[1]);wr<uint32_t>(c,a+8u,c.r[2]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270252507u;c.pc=(270015700u|1u);return;}
c.pc=270252507u;}
static void b_101bb9da(Context& c){
{c.pc=(270252514u|1u);return;}
c.pc=270252509u;}
static void b_101bb9dc(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{c.r[14]=270252515u;c.pc=(270391404u|1u);return;}
c.pc=270252515u;}
static void b_101bb9e2(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270252523u;c.pc=(270251816u|1u);return;}
c.pc=270252523u;}
static void b_101bb9ea(Context& c){
{c.pc=(270252596u|1u);return;}
c.pc=270252525u;}
static void b_101bb9ec(Context& c){
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270252533u;c.pc=(270393366u|1u);return;}
c.pc=270252533u;}
static void b_101bb9ee(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270252533u;c.pc=(270393366u|1u);return;}
c.pc=270252533u;}
static void b_101bb9f4(Context& c){
{c.pc=(270252514u|1u);return;}
c.pc=270252535u;}
static void b_101bb9f6(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270252543u;c.pc=(270251064u|1u);return;}
c.pc=270252543u;}
static void b_101bb9fe(Context& c){
{c.pc=(270252514u|1u);return;}
c.pc=270252545u;}
static void b_101bba00(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270252574u|1u);return;}}
c.pc=270252551u;}
static void b_101bba06(Context& c){
{uint32_t a=(c.r[4]+0u+16u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(2u),1,true);}
{if(cond(c,2)){c.pc=(270252574u|1u);return;}}
c.pc=270252557u;}
static void b_101bba0c(Context& c){
{uint32_t v=3u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+16u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=1115684864u;c.r[1]=v;}
{uint32_t v=30u;nz(c,v);c.r[2]=v;}
{c.r[14]=270252573u;c.pc=(270393090u|1u);return;}
c.pc=270252573u;}
static void b_101bba1c(Context& c){
{c.pc=(270252514u|1u);return;}
c.pc=270252575u;}
static void b_101bba1e(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270252514u|1u);return;}}
c.pc=270252579u;}
static void b_101bba22(Context& c){
{uint32_t a=(c.r[4]+0u+16u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(3u),1,true);}
{if(cond(c,2)){c.pc=(270252514u|1u);return;}}
c.pc=270252585u;}
static void b_101bba28(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=50u;nz(c,v);c.r[2]=v;}
{c.r[14]=270252595u;c.pc=(269980032u|1u);return;}
c.pc=270252595u;}
static void b_101bba32(Context& c){
{c.pc=(270252514u|1u);return;}
c.pc=270252597u;}
static void b_101bba34(Context& c){
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270252603u;}
static void b_101bba44(Context& c){
{if(c.r[1] != 0){c.pc=(270252624u|1u);return;}}
c.pc=270252615u;}
static void b_101bba46(Context& c){
{uint32_t v=add(c,c.r[2],~(99u),1,true);}
{}
{if(cond(c,14)){uint32_t v=2u;c.r[0]=v;}}
{if(cond(c,13)){uint32_t v=0u;c.r[0]=v;}}
{c.pc=c.r[14];return;}
c.pc=270252625u;}
static void b_101bba50(Context& c){
{uint32_t v=add(c,c.r[1],~(2u),1,true);}
{if(cond(c,2)){c.pc=(270252638u|1u);return;}}
c.pc=270252629u;}
static void b_101bba54(Context& c){
{uint32_t v=add(c,c.r[2],~(179u),1,true);}
{}
{if(cond(c,13)){uint32_t v=0u;c.r[0]=v;}}
{if(cond(c,14)){uint32_t v=1u;c.r[0]=v;}}
{c.pc=c.r[14];return;}
c.pc=270252639u;}
static void b_101bba5e(Context& c){
{uint32_t v=add(c,c.r[2],~(126u),1,true);}
{}
{if(cond(c,14)){uint32_t v=2u;c.r[0]=v;}}
{if(cond(c,13)){uint32_t v=0u;c.r[0]=v;}}
{c.pc=c.r[14];return;}
c.pc=270252649u;}
static void b_101bba68(Context& c){
{uint32_t a=c.r[13]-28u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-8u;wr<uint64_t>(c,a+0u,c.d[8]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(28u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[3];c.r[6]=v;}
{uint32_t v=c.r[0];c.r[8]=v;}
{uint32_t v=c.r[2];c.r[5]=v;}
{c.r[14]=270252671u;c.pc=(270326600u|1u);return;}
c.pc=270252671u;}
static void b_101bba7e(Context& c){
{uint32_t v=add(c,c.r[0],18432u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(5u),1,true);c.r[3]=v;}
{uint32_t v=add(c,0u,~(c.r[3]),1,true);c.r[9]=v;}
{uint32_t v=add(c,c.r[9],c.r[3],c.c,true);c.r[9]=v;}
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270252822u|1u);return;}}
c.pc=270252693u;}
static void b_101bba94(Context& c){
{uint32_t v=1u;nz(c,v);c.r[7]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[7]);}
{c.r[14]=270252705u;c.pc=(269975962u|1u);return;}
c.pc=270252705u;}
static void b_101bbaa0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270252713u;c.pc=(269975422u|1u);return;}
c.pc=270252713u;}
static void b_101bbaa8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270252721u;c.pc=(269975768u|1u);return;}
c.pc=270252721u;}
static void b_101bbab0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270252729u;c.pc=(269975414u|1u);return;}
c.pc=270252729u;}
static void b_101bbab8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270252737u;c.pc=(269975400u|1u);return;}
c.pc=270252737u;}
static void b_101bbac0(Context& c){
{uint32_t v=add(c,c.r[9],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270252822u|1u);return;}}
c.pc=270252743u;}
static void b_101bbac6(Context& c){
{uint32_t a=(c.r[4]+0u+56u);c.r[3]=rd<uint32_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270252822u|1u);return;}}
c.pc=270252747u;}
static void b_101bbaca(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{if(cond(c,2)){c.pc=(270252772u|1u);return;}}
c.pc=270252753u;}
static void b_101bbad0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270252759u;c.pc=(270392110u|1u);return;}
c.pc=270252759u;}
static void b_101bbad6(Context& c){
{uint32_t v=add(c,0u,~(c.r[0]),1,true);c.r[0]=v;}
{uint32_t v=shift(c,c.r[0],(c.r[7]&255u),1,true);nz(c,v);c.r[0]=v;}
{setsbits(c,13,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,13)));}
{c.pc=(270252788u|1u);return;}
c.pc=270252773u;}
static void b_101bbae4(Context& c){
{c.r[14]=270252777u;c.pc=(270408416u|1u);return;}
c.pc=270252777u;}
static void b_101bbae8(Context& c){
{c.r[14]=270252781u;c.pc=(270408736u|1u);return;}
c.pc=270252781u;}
static void b_101bbaec(Context& c){
{setsbits(c,14,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=((270252792u&~3u)+0u+760u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[5],~(40u),1,true);}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,c.r[3]);}
{if(cond(c,1)){c.pc=(270252814u|1u);return;}}
c.pc=270252811u;}
static void b_101bbaf4(Context& c){
{uint32_t a=((270252792u&~3u)+0u+760u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[5],~(40u),1,true);}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,c.r[3]);}
{if(cond(c,1)){c.pc=(270252814u|1u);return;}}
c.pc=270252811u;}
static void b_101bbb0a(Context& c){
{uint32_t v=add(c,c.r[5],~(30u),1,true);}
{if(cond(c,2)){c.pc=(270252822u|1u);return;}}
c.pc=270252815u;}
static void b_101bbb0e(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270253540u|1u);return;}
c.pc=270252823u;}
static void b_101bbb16(Context& c){
{uint32_t v=add(c,c.r[5],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270253450u|1u);return;}}
c.pc=270252829u;}
static void b_101bbb1c(Context& c){
{if(cond(c,13)){c.pc=(270252856u|1u);return;}}
c.pc=270252831u;}
static void b_101bbb1e(Context& c){
{uint32_t v=add(c,c.r[5],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270252886u|1u);return;}}
c.pc=270252835u;}
static void b_101bbb22(Context& c){
{if(cond(c,13)){c.pc=(270252842u|1u);return;}}
c.pc=270252837u;}
static void b_101bbb24(Context& c){
{uint32_t v=add(c,c.r[5],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270252886u|1u);return;}}
c.pc=270252841u;}
static void b_101bbb28(Context& c){
{c.pc=(270253540u|1u);return;}
c.pc=270252843u;}
static void b_101bbb2a(Context& c){
{uint32_t v=add(c,c.r[5],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270253364u|1u);return;}}
c.pc=270252849u;}
static void b_101bbb30(Context& c){
{uint32_t v=add(c,c.r[5],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270253364u|1u);return;}}
c.pc=270252855u;}
static void b_101bbb36(Context& c){
{c.pc=(270253540u|1u);return;}
c.pc=270252857u;}
static void b_101bbb38(Context& c){
{uint32_t v=add(c,c.r[5],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270253472u|1u);return;}}
c.pc=270252863u;}
static void b_101bbb3e(Context& c){
{if(cond(c,13)){c.pc=(270252872u|1u);return;}}
c.pc=270252865u;}
static void b_101bbb40(Context& c){
{uint32_t v=add(c,c.r[5],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270253472u|1u);return;}}
c.pc=270252871u;}
static void b_101bbb46(Context& c){
{c.pc=(270253540u|1u);return;}
c.pc=270252873u;}
static void b_101bbb48(Context& c){
{uint32_t v=add(c,c.r[5],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270253472u|1u);return;}}
c.pc=270252879u;}
static void b_101bbb4e(Context& c){
{uint32_t v=add(c,c.r[5],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270253520u|1u);return;}}
c.pc=270252885u;}
static void b_101bbb54(Context& c){
{c.pc=(270253540u|1u);return;}
c.pc=270252887u;}
static void b_101bbb56(Context& c){
{if(c.r[6] != 0){c.pc=(270252900u|1u);return;}}
c.pc=270252889u;}
static void b_101bbb58(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270252901u;c.pc=(270393366u|1u);return;}
c.pc=270252901u;}
static void b_101bbb64(Context& c){
{uint32_t v=add(c,c.r[9],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270253540u|1u);return;}}
c.pc=270252909u;}
static void b_101bbb6c(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,14)){c.pc=(270252920u|1u);return;}}
c.pc=270252915u;}
static void b_101bbb72(Context& c){
{uint32_t v=add(c,c.r[3],~(1u),1,true);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270253540u|1u);return;}
c.pc=270252921u;}
static void b_101bbb78(Context& c){
{c.r[14]=270252925u;c.pc=(270394904u|1u);return;}
c.pc=270252925u;}
static void b_101bbb7c(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],12u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[0]+shift(c,c.r[3],2,1,false)+0u);c.r[6]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[6],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270253540u|1u);return;}}
c.pc=270252939u;}
static void b_101bbb8a(Context& c){
{uint32_t v=c.r[8];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270252947u;c.pc=(270081006u|1u);return;}
c.pc=270252947u;}
static void b_101bbb92(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270252955u;c.pc=(269974782u|1u);return;}
c.pc=270252955u;}
static void b_101bbb9a(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270253132u|1u);return;}}
c.pc=270252959u;}
static void b_101bbb9e(Context& c){
{uint32_t a=(c.r[4]+0u+20u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(2u),1,true);}
{if(cond(c,2)){c.pc=(270252978u|1u);return;}}
c.pc=270252965u;}
static void b_101bbba4(Context& c){
{uint32_t v=add(c,c.r[5],~(31u),1,true);}
{if(cond(c,13)){c.pc=(270252978u|1u);return;}}
c.pc=270252969u;}
static void b_101bbba8(Context& c){
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270252977u;c.pc=(270393220u|1u);return;}
c.pc=270252977u;}
static void b_101bbbb0(Context& c){
{c.pc=(270253540u|1u);return;}
c.pc=270252979u;}
static void b_101bbbb2(Context& c){
{uint32_t v=add(c,c.r[5],~(128u),1,false);c.r[3]=v;}
{uint32_t a=(c.r[6]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t a=((270252990u&~3u)+0u+568u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,17,rd<uint32_t>(c,a+0u));}
{setsbits(c,13,c.r[3]);}
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[2]=v;}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{setfs(c,13,int32_t(sbits(c,13)));}
{uint32_t a=(c.r[2]+0u+4294967292u);uint32_t wb=a;wr<uint32_t>(c,a+0u,c.r[3]);c.r[2]=wb;}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=5u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{setsbits(c,15,cvti(fs(c,15),true));}
{setfs(c,16,int32_t(sbits(c,15)));}
{c.r[14]=270253033u;c.pc=c.r[3];return;}
c.pc=270253033u;}
static void b_101bbbe8(Context& c){
{uint32_t a=(c.r[13]+0u+20u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{setfs(c,17,(fs(c,17))-(fs(c,16)));}
{fcmp(c,fs(c,14),0);}
{setfs(c,17,std::fabs(fs(c,17)));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,10)){c.pc=(270253540u|1u);return;}}
c.pc=270253057u;}
static void b_101bbc00(Context& c){
{uint32_t a=((270253060u&~3u)+0u+500u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[3])&(c.r[5]);nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,11)){c.pc=(270253072u|1u);return;}}
c.pc=270253065u;}
static void b_101bbc08(Context& c){
{uint32_t v=add(c,c.r[3],~(1u),1,true);c.r[3]=v;}
{uint32_t v=(c.r[3])|(~(3u));c.r[3]=v;}
{uint32_t v=add(c,c.r[3],1u,0,true);c.r[3]=v;}
{setsbits(c,13,c.r[3]);}
{setfs(c,15,int32_t(sbits(c,13)));}
{setfs(c,14,(fs(c,15))+(fs(c,14)));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,14));}
{setfs(c,14,(fs(c,17))/(fs(c,14)));}
{setfs(c,15,(fs(c,14))+(fs(c,15)));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[6]=sbits(c,15);}
{uint32_t v=add(c,c.r[6],~(2u),1,true);}
{if(cond(c,14)){c.pc=(270253132u|1u);return;}}
c.pc=270253109u;}
static void b_101bbc10(Context& c){
{setsbits(c,13,c.r[3]);}
{setfs(c,15,int32_t(sbits(c,13)));}
{setfs(c,14,(fs(c,15))+(fs(c,14)));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,14));}
{setfs(c,14,(fs(c,17))/(fs(c,14)));}
{setfs(c,15,(fs(c,14))+(fs(c,15)));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[6]=sbits(c,15);}
{uint32_t v=add(c,c.r[6],~(2u),1,true);}
{if(cond(c,14)){c.pc=(270253132u|1u);return;}}
c.pc=270253109u;}
static void b_101bbc34(Context& c){
{uint32_t a=(c.r[4]+0u+20u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=c.r[8];c.r[0]=v;}
{c.r[14]=270253119u;c.pc=(270252612u|1u);return;}
c.pc=270253119u;}
static void b_101bbc3e(Context& c){
{c.r[1]=sbits(c,16);}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t a=(c.r[4]+0u+20u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270253133u;c.pc=(270393014u|1u);return;}
c.pc=270253133u;}
static void b_101bbc4c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270253139u;c.pc=(269975064u|1u);return;}
c.pc=270253139u;}
static void b_101bbc52(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270253540u|1u);return;}}
c.pc=270253145u;}
static void b_101bbc58(Context& c){
{uint32_t a=(c.r[4]+0u+20u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(2u),1,true);}
{if(cond(c,2)){c.pc=(270253164u|1u);return;}}
c.pc=270253151u;}
static void b_101bbc5e(Context& c){
{uint32_t v=add(c,c.r[5],~(31u),1,true);}
{if(cond(c,13)){c.pc=(270253164u|1u);return;}}
c.pc=270253155u;}
static void b_101bbc62(Context& c){
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270253163u;c.pc=(270393246u|1u);return;}
c.pc=270253163u;}
static void b_101bbc6a(Context& c){
{c.pc=(270253540u|1u);return;}
c.pc=270253165u;}
static void b_101bbc6c(Context& c){
{c.r[14]=270253169u;c.pc=(270408416u|1u);return;}
c.pc=270253169u;}
static void b_101bbc70(Context& c){
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[1]=sbits(c,15);}
{c.r[14]=270253187u;c.pc=(270408818u|1u);return;}
c.pc=270253187u;}
static void b_101bbc82(Context& c){
{uint32_t v=420u;c.r[1]=v;}
{c.r[14]=270253195u;c.pc=(269745118u|1u);return;}
c.pc=270253195u;}
static void b_101bbc8a(Context& c){
{setsbits(c,14,c.r[5]);}
{uint32_t a=((270253202u&~3u)+0u+364u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,17,rd<uint32_t>(c,a+0u));}
{setfs(c,13,int32_t(sbits(c,14)));}
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[2]=v;}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t v=5u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[2]+0u+4294967292u);uint32_t wb=a;wr<uint32_t>(c,a+0u,c.r[3]);c.r[2]=wb;}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{setfs(c,13,(fs(c,13))*(fs(c,15)));}
{uint32_t v=add(c,c.r[0],~(80u),1,true);c.r[0]=v;}
{setsbits(c,15,c.r[0]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{setfs(c,14,int32_t(sbits(c,15)));}
{uint32_t a=((270253244u&~3u)+0u+324u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{setsbits(c,15,cvti(fs(c,15),true));}
{setfs(c,16,int32_t(sbits(c,15)));}
{c.r[14]=270253259u;c.pc=c.r[3];return;}
c.pc=270253259u;}
static void b_101bbcca(Context& c){
{uint32_t a=(c.r[13]+0u+20u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{setfs(c,17,(fs(c,17))-(fs(c,16)));}
{fcmp(c,fs(c,14),0);}
{setfs(c,17,std::fabs(fs(c,17)));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,10)){c.pc=(270253540u|1u);return;}}
c.pc=270253283u;}
static void b_101bbce2(Context& c){
{uint32_t a=((270253286u&~3u)+0u+276u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[3])&(c.r[5]);nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,11)){c.pc=(270253298u|1u);return;}}
c.pc=270253291u;}
static void b_101bbcea(Context& c){
{uint32_t v=add(c,c.r[3],~(1u),1,true);c.r[3]=v;}
{uint32_t v=(c.r[3])|(~(3u));c.r[3]=v;}
{uint32_t v=add(c,c.r[3],1u,0,true);c.r[3]=v;}
{setsbits(c,13,c.r[3]);}
{setfs(c,15,int32_t(sbits(c,13)));}
{setfs(c,14,(fs(c,15))+(fs(c,14)));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,14));}
{setfs(c,14,(fs(c,17))/(fs(c,14)));}
{setfs(c,15,(fs(c,14))+(fs(c,15)));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[6]=sbits(c,15);}
{uint32_t v=add(c,c.r[6],~(2u),1,true);}
{if(cond(c,14)){c.pc=(270253540u|1u);return;}}
c.pc=270253335u;}
static void b_101bbcf2(Context& c){
{setsbits(c,13,c.r[3]);}
{setfs(c,15,int32_t(sbits(c,13)));}
{setfs(c,14,(fs(c,15))+(fs(c,14)));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,14));}
{setfs(c,14,(fs(c,17))/(fs(c,14)));}
{setfs(c,15,(fs(c,14))+(fs(c,15)));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[6]=sbits(c,15);}
{uint32_t v=add(c,c.r[6],~(2u),1,true);}
{if(cond(c,14)){c.pc=(270253540u|1u);return;}}
c.pc=270253335u;}
static void b_101bbd16(Context& c){
{uint32_t a=(c.r[4]+0u+20u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=c.r[8];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(1u),1,true);c.r[1]=v;}
{c.r[14]=270253347u;c.pc=(270252612u|1u);return;}
c.pc=270253347u;}
static void b_101bbd22(Context& c){
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[1]=sbits(c,16);}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t a=(c.r[4]+0u+20u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270253363u;c.pc=(270393090u|1u);return;}
c.pc=270253363u;}
static void b_101bbd32(Context& c){
{c.pc=(270253540u|1u);return;}
c.pc=270253365u;}
static void b_101bbd34(Context& c){
{if(c.r[6] != 0){c.pc=(270253394u|1u);return;}}
c.pc=270253367u;}
static void b_101bbd36(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270253373u;c.pc=(269974782u|1u);return;}
c.pc=270253373u;}
static void b_101bbd3c(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270253528u|1u);return;}}
c.pc=270253377u;}
static void b_101bbd40(Context& c){
{uint32_t v=add(c,c.r[9],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270253528u|1u);return;}}
c.pc=270253383u;}
static void b_101bbd46(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=20u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[14]=270253393u;c.pc=(270391848u|1u);return;}
c.pc=270253393u;}
static void b_101bbd50(Context& c){
{c.pc=(270253540u|1u);return;}
c.pc=270253395u;}
static void b_101bbd52(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270253540u|1u);return;}}
c.pc=270253403u;}
static void b_101bbd5a(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],1u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[3],~(5u),1,true);}
{if(cond(c,14)){c.pc=(270253438u|1u);return;}}
c.pc=270253413u;}
static void b_101bbd64(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270253423u;c.pc=(270393366u|1u);return;}
c.pc=270253423u;}
static void b_101bbd6e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[14]=270253433u;c.pc=(270391848u|1u);return;}
c.pc=270253433u;}
static void b_101bbd78(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270253540u|1u);return;}
c.pc=270253439u;}
static void b_101bbd7e(Context& c){
{uint32_t v=c.r[8];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270253449u;c.pc=(269980032u|1u);return;}
c.pc=270253449u;}
static void b_101bbd88(Context& c){
{c.pc=(270253540u|1u);return;}
c.pc=270253451u;}
static void b_101bbd8a(Context& c){
{if(c.r[6] != 0){c.pc=(270253540u|1u);return;}}
c.pc=270253453u;}
static void b_101bbd8c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270253465u;c.pc=(270393366u|1u);return;}
c.pc=270253465u;}
static void b_101bbd98(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270253471u;c.pc=(270393272u|1u);return;}
c.pc=270253471u;}
static void b_101bbd9e(Context& c){
{c.pc=(270253540u|1u);return;}
c.pc=270253473u;}
static void b_101bbda0(Context& c){
{if(c.r[6] != 0){c.pc=(270253482u|1u);return;}}
c.pc=270253475u;}
static void b_101bbda2(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.pc=(270253534u|1u);return;}
c.pc=270253483u;}
static void b_101bbdaa(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[5]=rd<uint8_t>(c,a+0u);}
{if(c.r[5] != 0){c.pc=(270253540u|1u);return;}}
c.pc=270253489u;}
static void b_101bbdb0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270253495u;c.pc=(270392138u|1u);return;}
c.pc=270253495u;}
static void b_101bbdb6(Context& c){
{uint32_t v=65282u;c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=4294967295u;c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=shift(c,c.r[0],1u,3,true);nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[8];c.r[0]=v;}
{c.r[14]=270253521u;c.pc=(270015700u|1u);return;}
c.pc=270253521u;}
static void b_101bbdd0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270253527u;c.pc=(270391404u|1u);return;}
c.pc=270253527u;}
static void b_101bbdd6(Context& c){
{c.pc=(270253540u|1u);return;}
c.pc=270253529u;}
static void b_101bbdd8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270253541u;c.pc=(270393366u|1u);return;}
c.pc=270253541u;}
static void b_101bbdde(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270253541u;c.pc=(270393366u|1u);return;}
c.pc=270253541u;}
static void b_101bbde4(Context& c){
{uint32_t v=add(c,c.r[13],28u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.r[13]=a+8u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);uint32_t newpc=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;c.pc=newpc;return;}
c.pc=270253551u;}
static void b_101bbe04(Context& c){
{uint32_t a=c.r[13]-16u;wr<uint32_t>(c,a+0u,c.r[3]);wr<uint32_t>(c,a+4u,c.r[4]);wr<uint32_t>(c,a+8u,c.r[5]);wr<uint32_t>(c,a+12u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+98u);c.r[5]=rd<uint16_t>(c,a+0u);}
{c.r[14]=270253585u;c.pc=(270394904u|1u);return;}
c.pc=270253585u;}
static void b_101bbe10(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270253593u;c.pc=(270398260u|1u);return;}
c.pc=270253593u;}
static void b_101bbe18(Context& c){
{uint32_t v=c.r[0];c.r[3]=v;}
{if(c.r[0] == 0){c.pc=(270253636u|1u);return;}}
c.pc=270253597u;}
static void b_101bbe1c(Context& c){
{uint32_t a=(c.r[0]+0u+292u);c.r[0]=rd<uint32_t>(c,a+0u);}
{if(c.r[0] == 0){c.pc=(270253606u|1u);return;}}
c.pc=270253603u;}
static void b_101bbe22(Context& c){
{uint32_t v=add(c,c.r[0],~(284u),1,false);c.r[0]=v;}
{uint32_t v=add(c,c.r[0],~(c.r[3]),1,true);}
{if(cond(c,1)){c.pc=(270253636u|1u);return;}}
c.pc=270253611u;}
static void b_101bbe26(Context& c){
{uint32_t v=add(c,c.r[0],~(c.r[3]),1,true);}
{if(cond(c,1)){c.pc=(270253636u|1u);return;}}
c.pc=270253611u;}
static void b_101bbe2a(Context& c){
{uint32_t a=(c.r[0]+0u+98u);c.r[2]=rd<uint16_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(c.r[5]),1,true);}
{if(cond(c,2)){c.pc=(270253626u|1u);return;}}
c.pc=270253619u;}
static void b_101bbe32(Context& c){
{uint32_t a=c.r[13];c.r[3]=rd<uint32_t>(c,a+0u);c.r[4]=rd<uint32_t>(c,a+4u);c.r[5]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270391404u|1u);return;}
c.pc=270253627u;}
static void b_101bbe3a(Context& c){
{uint32_t a=(c.r[0]+0u+292u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270253602u|1u);return;}}
c.pc=270253635u;}
static void b_101bbe42(Context& c){
{c.pc=(270253610u|1u);return;}
c.pc=270253637u;}
static void b_101bbe44(Context& c){
{uint32_t a=c.r[13];c.r[3]=rd<uint32_t>(c,a+0u);c.r[4]=rd<uint32_t>(c,a+4u);c.r[5]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270253639u;}
static void b_101bbe48(Context& c){
{uint32_t v=add(c,c.r[2],~(70u),1,true);}
{uint32_t a=c.r[13]-16u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[2];c.r[5]=v;}
{if(cond(c,1)){c.pc=(270253848u|1u);return;}}
c.pc=270253653u;}
static void b_101bbe54(Context& c){
{if(cond(c,13)){c.pc=(270253680u|1u);return;}}
c.pc=270253655u;}
static void b_101bbe56(Context& c){
{uint32_t v=add(c,c.r[2],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270253750u|1u);return;}}
c.pc=270253659u;}
static void b_101bbe5a(Context& c){
{if(cond(c,13)){c.pc=(270253670u|1u);return;}}
c.pc=270253661u;}
static void b_101bbe5c(Context& c){
{uint32_t v=add(c,c.r[2],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270253706u|1u);return;}}
c.pc=270253665u;}
static void b_101bbe60(Context& c){
{uint32_t v=add(c,c.r[2],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270253716u|1u);return;}}
c.pc=270253669u;}
static void b_101bbe64(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270253671u;}
static void b_101bbe66(Context& c){
{uint32_t v=add(c,c.r[2],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270253768u|1u);return;}}
c.pc=270253675u;}
static void b_101bbe6a(Context& c){
{uint32_t v=add(c,c.r[2],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270253776u|1u);return;}}
c.pc=270253679u;}
static void b_101bbe6e(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270253681u;}
static void b_101bbe70(Context& c){
{uint32_t v=add(c,c.r[2],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270253892u|1u);return;}}
c.pc=270253685u;}
static void b_101bbe74(Context& c){
{if(cond(c,13)){c.pc=(270253696u|1u);return;}}
c.pc=270253687u;}
static void b_101bbe76(Context& c){
{uint32_t v=add(c,c.r[2],~(80u),1,true);}
{if(cond(c,1)){c.pc=(270253800u|1u);return;}}
c.pc=270253691u;}
static void b_101bbe7a(Context& c){
{uint32_t v=add(c,c.r[2],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270253892u|1u);return;}}
c.pc=270253695u;}
static void b_101bbe7e(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270253697u;}
static void b_101bbe80(Context& c){
{uint32_t v=add(c,c.r[2],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270253892u|1u);return;}}
c.pc=270253701u;}
static void b_101bbe84(Context& c){
{uint32_t v=add(c,c.r[2],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270253942u|1u);return;}}
c.pc=270253705u;}
static void b_101bbe88(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270253707u;}
static void b_101bbe8a(Context& c){
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270253958u|1u);return;}}
c.pc=270253711u;}
static void b_101bbe8e(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270253756u|1u);return;}
c.pc=270253717u;}
static void b_101bbe94(Context& c){
{if(c.r[3] != 0){c.pc=(270253736u|1u);return;}}
c.pc=270253719u;}
static void b_101bbe96(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270253731u;c.pc=(270393366u|1u);return;}
c.pc=270253731u;}
static void b_101bbea2(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270253744u&~3u)+0u+216u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(269978432u|1u);return;}
c.pc=270253751u;}
static void b_101bbea8(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270253744u&~3u)+0u+216u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(269978432u|1u);return;}
c.pc=270253751u;}
static void b_101bbeb6(Context& c){
{if(c.r[3] != 0){c.pc=(270253784u|1u);return;}}
c.pc=270253753u;}
static void b_101bbeb8(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270393366u|1u);return;}
c.pc=270253769u;}
static void b_101bbebc(Context& c){
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270393366u|1u);return;}
c.pc=270253769u;}
static void b_101bbebe(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270393366u|1u);return;}
c.pc=270253769u;}
static void b_101bbec8(Context& c){
{if(c.r[3] != 0){c.pc=(270253784u|1u);return;}}
c.pc=270253771u;}
static void b_101bbeca(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{c.pc=(270253756u|1u);return;}
c.pc=270253777u;}
static void b_101bbed0(Context& c){
{if(c.r[3] != 0){c.pc=(270253784u|1u);return;}}
c.pc=270253779u;}
static void b_101bbed2(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270253756u|1u);return;}
c.pc=270253785u;}
static void b_101bbed8(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270253958u|1u);return;}}
c.pc=270253793u;}
static void b_101bbee0(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(269980032u|1u);return;}
c.pc=270253801u;}
static void b_101bbee8(Context& c){
{if(c.r[3] != 0){c.pc=(270253824u|1u);return;}}
c.pc=270253803u;}
static void b_101bbeea(Context& c){
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{c.r[14]=270253815u;c.pc=(270393366u|1u);return;}
c.pc=270253815u;}
static void b_101bbef6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270253823u;c.pc=(269975768u|1u);return;}
c.pc=270253823u;}
static void b_101bbefe(Context& c){
{c.pc=(270253862u|1u);return;}
c.pc=270253825u;}
static void b_101bbf00(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[1]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[1],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270253958u|1u);return;}}
c.pc=270253833u;}
static void b_101bbf08(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(269975768u|1u);return;}
c.pc=270253849u;}
static void b_101bbf18(Context& c){
{if(c.r[3] != 0){c.pc=(270253874u|1u);return;}}
c.pc=270253851u;}
static void b_101bbf1a(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270253863u;c.pc=(270393366u|1u);return;}
c.pc=270253863u;}
static void b_101bbf1e(Context& c){
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270253863u;c.pc=(270393366u|1u);return;}
c.pc=270253863u;}
static void b_101bbf26(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270253572u|1u);return;}
c.pc=270253875u;}
static void b_101bbf32(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{if(c.r[2] != 0){c.pc=(270253958u|1u);return;}}
c.pc=270253881u;}
static void b_101bbf38(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270391848u|1u);return;}
c.pc=270253893u;}
static void b_101bbf44(Context& c){
{if(c.r[3] != 0){c.pc=(270253906u|1u);return;}}
c.pc=270253895u;}
static void b_101bbf46(Context& c){
{uint32_t v=add(c,c.r[5],~(120u),1,true);}
{uint32_t v=c.r[4];c.r[0]=v;}
{}
{if(cond(c,1)){uint32_t v=17u;c.r[1]=v;}}
{if(cond(c,2)){uint32_t v=13u;c.r[1]=v;}}
{c.pc=(270253854u|1u);return;}
c.pc=270253907u;}
static void b_101bbf52(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270253915u;c.pc=(270118736u|1u);return;}
c.pc=270253915u;}
static void b_101bbf5a(Context& c){
{if(c.r[0] == 0){c.pc=(270253958u|1u);return;}}
c.pc=270253917u;}
static void b_101bbf5c(Context& c){
{uint32_t v=140u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270253927u;c.pc=(270391848u|1u);return;}
c.pc=270253927u;}
static void b_101bbf66(Context& c){
{uint32_t v=add(c,c.r[5],~(120u),1,true);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;c.r[2]=v;}
{}
{if(cond(c,1)){uint32_t v=18u;c.r[1]=v;}}
{if(cond(c,2)){uint32_t v=14u;c.r[1]=v;}}
{c.pc=(270253758u|1u);return;}
c.pc=270253943u;}
static void b_101bbf76(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270253958u|1u);return;}}
c.pc=270253949u;}
static void b_101bbf7c(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270391404u|1u);return;}
c.pc=270253959u;}
static void b_101bbf86(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270253961u;}
static void b_101bbf8c(Context& c){
{uint32_t a=c.r[13]-12u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+252u);c.r[5]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],~(20u),1,false);c.r[13]=v;}
{if(c.r[5] != 0){c.pc=(270254034u|1u);return;}}
c.pc=270253977u;}
static void b_101bbf98(Context& c){
{uint32_t a=(c.r[1]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],8u,0,false);c.r[2]=v;}
{uint32_t v=38u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270253989u;c.pc=c.r[3];return;}
c.pc=270253989u;}
static void b_101bbfa4(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270254001u;c.pc=c.r[3];return;}
c.pc=270254001u;}
static void b_101bbfb0(Context& c){
{uint32_t a=(c.r[4]+0u+277u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+12u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270254021u;c.pc=(270393892u|1u);return;}
c.pc=270254021u;}
static void b_101bbfc4(Context& c){
{if(c.r[0] == 0){c.pc=(270254034u|1u);return;}}
c.pc=270254023u;}
static void b_101bbfc6(Context& c){
{uint32_t a=(c.r[4]+0u+240u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[0]+0u+240u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);uint32_t newpc=rd<uint32_t>(c,a+8u);c.r[13]=a+12u;c.pc=newpc;return;}
c.pc=270254039u;}
static void b_101bbfd2(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);uint32_t newpc=rd<uint32_t>(c,a+8u);c.r[13]=a+12u;c.pc=newpc;return;}
c.pc=270254039u;}
static void b_101bbfd8(Context& c){
{uint32_t a=c.r[13]-24u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[2];c.r[6]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[3];c.r[5]=v;}
{uint32_t v=c.r[0];c.r[8]=v;}
{c.r[14]=270254057u;c.pc=(270326600u|1u);return;}
c.pc=270254057u;}
static void b_101bbfe8(Context& c){
{uint32_t v=add(c,c.r[0],18432u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+40u);c.r[7]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[7],~(5u),1,true);c.r[3]=v;}
{uint32_t v=add(c,0u,~(c.r[3]),1,true);c.r[7]=v;}
{uint32_t v=add(c,c.r[7],c.r[3],c.c,true);c.r[7]=v;}
{c.r[14]=270254073u;c.pc=(270394904u|1u);return;}
c.pc=270254073u;}
static void b_101bbff8(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270254081u;c.pc=(270398272u|1u);return;}
c.pc=270254081u;}
static void b_101bc000(Context& c){
{uint32_t v=add(c,c.r[6],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270254408u|1u);return;}}
c.pc=270254087u;}
static void b_101bc006(Context& c){
{if(cond(c,13)){c.pc=(270254118u|1u);return;}}
c.pc=270254089u;}
static void b_101bc008(Context& c){
{uint32_t v=add(c,c.r[6],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270254322u|1u);return;}}
c.pc=270254093u;}
static void b_101bc00c(Context& c){
{if(cond(c,13)){c.pc=(270254106u|1u);return;}}
c.pc=270254095u;}
static void b_101bc00e(Context& c){
{uint32_t v=add(c,c.r[6],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270254248u|1u);return;}}
c.pc=270254099u;}
static void b_101bc012(Context& c){
{uint32_t v=add(c,c.r[6],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270254248u|1u);return;}}
c.pc=270254103u;}
static void b_101bc016(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270254107u;}
static void b_101bc01a(Context& c){
{uint32_t v=add(c,c.r[6],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270254322u|1u);return;}}
c.pc=270254111u;}
static void b_101bc01e(Context& c){
{uint32_t v=add(c,c.r[6],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270254322u|1u);return;}}
c.pc=270254115u;}
static void b_101bc022(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270254119u;}
static void b_101bc026(Context& c){
{uint32_t v=add(c,c.r[6],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270254378u|1u);return;}}
c.pc=270254123u;}
static void b_101bc02a(Context& c){
{if(cond(c,13)){c.pc=(270254136u|1u);return;}}
c.pc=270254125u;}
static void b_101bc02c(Context& c){
{uint32_t v=add(c,c.r[6],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270254378u|1u);return;}}
c.pc=270254129u;}
static void b_101bc030(Context& c){
{uint32_t v=add(c,c.r[6],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270254378u|1u);return;}}
c.pc=270254133u;}
static void b_101bc034(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270254137u;}
static void b_101bc038(Context& c){
{uint32_t v=add(c,c.r[6],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270254538u|1u);return;}}
c.pc=270254143u;}
static void b_101bc03e(Context& c){
{uint32_t v=add(c,c.r[6],~(141u),1,true);}
{if(cond(c,2)){c.pc=(270254628u|1u);return;}}
c.pc=270254149u;}
static void b_101bc044(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270254628u|1u);return;}}
c.pc=270254155u;}
static void b_101bc04a(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+76u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270254163u;c.pc=c.r[3];return;}
c.pc=270254163u;}
static void b_101bc052(Context& c){
{uint32_t v=~(344u);c.r[12]=v;}
{uint32_t v=add(c,c.r[0],c.r[12],0,false);c.r[0]=v;}
{uint32_t v=add(c,c.r[0],~(11u),1,true);}
{if(cond(c,9)){c.pc=(270254184u|1u);return;}}
c.pc=270254173u;}
static void b_101bc05c(Context& c){
{uint32_t a=((270254176u&~3u)+0u+456u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],270254178u,0,false);c.r[3]=v;}
{uint32_t v=add(c,c.r[0],c.r[3],0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+140u);c.r[1]=uint32_t(rd<int8_t>(c,a+0u));}
{c.pc=(270254186u|1u);return;}
c.pc=270254185u;}
static void b_101bc068(Context& c){
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270254197u;c.pc=(270393366u|1u);return;}
c.pc=270254197u;}
static void b_101bc06a(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270254197u;c.pc=(270393366u|1u);return;}
c.pc=270254197u;}
static void b_101bc074(Context& c){
{setfs(c,15,10.0);}
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,1)){setfs(c,15,(fs(c,14))-(fs(c,15)));}}
{if(cond(c,2)){setfs(c,15,(fs(c,14))+(fs(c,15)));}}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=add(c,c.r[7],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270254628u|1u);return;}}
c.pc=270254233u;}
static void b_101bc098(Context& c){
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270254249u;}
static void b_101bc0a8(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270254628u|1u);return;}}
c.pc=270254255u;}
static void b_101bc0ae(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+76u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270254263u;c.pc=c.r[3];return;}
c.pc=270254263u;}
static void b_101bc0b6(Context& c){
{uint32_t v=~(344u);c.r[14]=v;}
{uint32_t v=add(c,c.r[0],c.r[14],0,false);c.r[0]=v;}
{uint32_t v=add(c,c.r[0],~(11u),1,true);}
{if(cond(c,9)){c.pc=(270254284u|1u);return;}}
c.pc=270254273u;}
static void b_101bc0c0(Context& c){
{uint32_t a=((270254276u&~3u)+0u+360u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],270254278u,0,false);c.r[3]=v;}
{uint32_t v=add(c,c.r[0],c.r[3],0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+152u);c.r[1]=uint32_t(rd<int8_t>(c,a+0u));}
{c.pc=(270254286u|1u);return;}
c.pc=270254285u;}
static void b_101bc0cc(Context& c){
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270254297u;c.pc=(270393366u|1u);return;}
c.pc=270254297u;}
static void b_101bc0ce(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270254297u;c.pc=(270393366u|1u);return;}
c.pc=270254297u;}
static void b_101bc0d8(Context& c){
{uint32_t v=add(c,c.r[7],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270254628u|1u);return;}}
c.pc=270254303u;}
static void b_101bc0de(Context& c){
{uint32_t a=(c.r[4]+0u+32u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270254323u;}
static void b_101bc0f2(Context& c){
{if(c.r[5] != 0){c.pc=(270254388u|1u);return;}}
c.pc=270254325u;}
static void b_101bc0f4(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=~(344u);c.r[7]=v;}
{uint32_t a=(c.r[3]+0u+76u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270254337u;c.pc=c.r[3];return;}
c.pc=270254337u;}
static void b_101bc100(Context& c){
{uint32_t v=add(c,c.r[0],c.r[7],0,false);c.r[0]=v;}
{uint32_t v=add(c,c.r[0],~(11u),1,true);}
{if(cond(c,9)){c.pc=(270254354u|1u);return;}}
c.pc=270254343u;}
static void b_101bc106(Context& c){
{uint32_t a=((270254346u&~3u)+0u+296u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],270254348u,0,false);c.r[3]=v;}
{uint32_t v=add(c,c.r[0],c.r[3],0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+164u);c.r[1]=uint32_t(rd<int8_t>(c,a+0u));}
{c.pc=(270254356u|1u);return;}
c.pc=270254355u;}
static void b_101bc112(Context& c){
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270254367u;c.pc=(270393366u|1u);return;}
c.pc=270254367u;}
static void b_101bc114(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270254367u;c.pc=(270393366u|1u);return;}
c.pc=270254367u;}
static void b_101bc11e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(269975106u|1u);return;}
c.pc=270254379u;}
static void b_101bc12a(Context& c){
{uint32_t a=(c.r[0]+0u+776u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,14)){c.pc=(270254490u|1u);return;}}
c.pc=270254387u;}
static void b_101bc132(Context& c){
{if(c.r[5] == 0){c.pc=(270254460u|1u);return;}}
c.pc=270254389u;}
static void b_101bc134(Context& c){
{uint32_t v=c.r[8];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270254397u;c.pc=(270118736u|1u);return;}
c.pc=270254397u;}
static void b_101bc13c(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270254628u|1u);return;}}
c.pc=270254401u;}
static void b_101bc140(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=140u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.pc=(270254452u|1u);return;}
c.pc=270254409u;}
static void b_101bc148(Context& c){
{if(c.r[5] != 0){c.pc=(270254440u|1u);return;}}
c.pc=270254411u;}
static void b_101bc14a(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=~(344u);c.r[6]=v;}
{uint32_t a=(c.r[3]+0u+76u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270254423u;c.pc=c.r[3];return;}
c.pc=270254423u;}
static void b_101bc156(Context& c){
{uint32_t v=add(c,c.r[0],c.r[6],0,false);c.r[0]=v;}
{uint32_t v=add(c,c.r[0],~(11u),1,true);}
{if(cond(c,9)){c.pc=(270254570u|1u);return;}}
c.pc=270254429u;}
static void b_101bc15c(Context& c){
{uint32_t a=((270254432u&~3u)+0u+212u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],270254434u,0,false);c.r[3]=v;}
{uint32_t v=add(c,c.r[0],c.r[3],0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+176u);c.r[1]=uint32_t(rd<int8_t>(c,a+0u));}
{c.pc=(270254572u|1u);return;}
c.pc=270254441u;}
static void b_101bc168(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270254628u|1u);return;}}
c.pc=270254449u;}
static void b_101bc170(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270391848u|1u);return;}
c.pc=270254461u;}
static void b_101bc174(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270391848u|1u);return;}
c.pc=270254461u;}
static void b_101bc17c(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+76u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270254469u;c.pc=c.r[3];return;}
c.pc=270254469u;}
static void b_101bc184(Context& c){
{uint32_t v=~(344u);c.r[1]=v;}
{uint32_t v=add(c,c.r[0],c.r[1],0,false);c.r[0]=v;}
{uint32_t v=add(c,c.r[0],~(11u),1,true);}
{if(cond(c,9)){c.pc=(270254570u|1u);return;}}
c.pc=270254479u;}
static void b_101bc18e(Context& c){
{uint32_t a=((270254482u&~3u)+0u+168u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],270254484u,0,false);c.r[3]=v;}
{uint32_t v=add(c,c.r[0],c.r[3],0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+188u);c.r[1]=uint32_t(rd<int8_t>(c,a+0u));}
{c.pc=(270254572u|1u);return;}
c.pc=270254491u;}
static void b_101bc19a(Context& c){
{if(c.r[5] != 0){c.pc=(270254522u|1u);return;}}
c.pc=270254493u;}
static void b_101bc19c(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+76u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270254501u;c.pc=c.r[3];return;}
c.pc=270254501u;}
static void b_101bc1a4(Context& c){
{uint32_t v=~(344u);c.r[2]=v;}
{uint32_t v=add(c,c.r[0],c.r[2],0,false);c.r[0]=v;}
{uint32_t v=add(c,c.r[0],~(11u),1,true);}
{if(cond(c,9)){c.pc=(270254570u|1u);return;}}
c.pc=270254511u;}
static void b_101bc1ae(Context& c){
{uint32_t a=((270254514u&~3u)+0u+140u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],270254516u,0,false);c.r[3]=v;}
{uint32_t v=add(c,c.r[0],c.r[3],0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+200u);c.r[1]=uint32_t(rd<int8_t>(c,a+0u));}
{c.pc=(270254572u|1u);return;}
c.pc=270254523u;}
static void b_101bc1ba(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270254628u|1u);return;}}
c.pc=270254529u;}
static void b_101bc1c0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270391404u|1u);return;}
c.pc=270254539u;}
static void b_101bc1ca(Context& c){
{if(c.r[5] != 0){c.pc=(270254586u|1u);return;}}
c.pc=270254541u;}
static void b_101bc1cc(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+76u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270254549u;c.pc=c.r[3];return;}
c.pc=270254549u;}
static void b_101bc1d4(Context& c){
{uint32_t v=~(344u);c.r[3]=v;}
{uint32_t v=add(c,c.r[0],c.r[3],0,false);c.r[0]=v;}
{uint32_t v=add(c,c.r[0],~(11u),1,true);}
{if(cond(c,9)){c.pc=(270254570u|1u);return;}}
c.pc=270254559u;}
static void b_101bc1de(Context& c){
{uint32_t a=((270254562u&~3u)+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],270254564u,0,false);c.r[3]=v;}
{uint32_t v=add(c,c.r[0],c.r[3],0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+212u);c.r[1]=uint32_t(rd<int8_t>(c,a+0u));}
{c.pc=(270254572u|1u);return;}
c.pc=270254571u;}
static void b_101bc1ea(Context& c){
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270393366u|1u);return;}
c.pc=270254587u;}
static void b_101bc1ec(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270393366u|1u);return;}
c.pc=270254587u;}
static void b_101bc1fa(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270254598u|1u);return;}}
c.pc=270254593u;}
static void b_101bc200(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270254599u;c.pc=(270391404u|1u);return;}
c.pc=270254599u;}
static void b_101bc206(Context& c){
{uint32_t v=add(c,c.r[5],~(7u),1,true);}
{if(cond(c,2)){c.pc=(270254628u|1u);return;}}
c.pc=270254603u;}
static void b_101bc20a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{c.r[14]=270254611u;c.pc=(269975106u|1u);return;}
c.pc=270254611u;}
static void b_101bc212(Context& c){
{uint32_t v=4u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{if(c.r[7] != 0){c.pc=(270254628u|1u);return;}}
c.pc=270254617u;}
static void b_101bc218(Context& c){
{uint32_t v=c.r[8];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270253964u|1u);return;}
c.pc=270254629u;}
static void b_101bc224(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270254633u;}
static void b_101bc244(Context& c){
{uint32_t a=(c.r[1]+0u+196u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[0])&(~(8u));c.r[3]=v;}
{uint32_t v=add(c,c.r[3],~(7u),1,true);}
{if(cond(c,1)){c.pc=(270254682u|1u);return;}}
c.pc=270254673u;}
static void b_101bc250(Context& c){
{uint32_t v=add(c,c.r[0],~(19u),1,true);c.r[3]=v;}
{uint32_t v=add(c,0u,~(c.r[3]),1,true);c.r[0]=v;}
{uint32_t v=add(c,c.r[0],c.r[3],c.c,true);c.r[0]=v;}
{c.pc=c.r[14];return;}
c.pc=270254683u;}
static void b_101bc25a(Context& c){
{uint32_t v=1u;nz(c,v);c.r[0]=v;}
{c.pc=c.r[14];return;}
c.pc=270254687u;}
static void b_101bc260(Context& c){
{uint32_t v=add(c,c.r[2],~(70u),1,true);}
{uint32_t a=c.r[13]-36u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[11]);wr<uint32_t>(c,a+32u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-24u;wr<uint64_t>(c,a+0u,c.d[8]);wr<uint64_t>(c,a+8u,c.d[9]);wr<uint64_t>(c,a+16u,c.d[10]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=add(c,c.r[13],~(36u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[3];c.r[6]=v;}
{if(cond(c,1)){c.pc=(270255046u|1u);return;}}
c.pc=270254711u;}
static void b_101bc276(Context& c){
{if(cond(c,13)){c.pc=(270254738u|1u);return;}}
c.pc=270254713u;}
static void b_101bc278(Context& c){
{uint32_t v=add(c,c.r[2],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270254860u|1u);return;}}
c.pc=270254717u;}
static void b_101bc27c(Context& c){
{if(cond(c,13)){c.pc=(270254728u|1u);return;}}
c.pc=270254719u;}
static void b_101bc27e(Context& c){
{uint32_t v=add(c,c.r[2],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270254788u|1u);return;}}
c.pc=270254723u;}
static void b_101bc282(Context& c){
{uint32_t v=add(c,c.r[2],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270254800u|1u);return;}}
c.pc=270254727u;}
static void b_101bc286(Context& c){
{c.pc=(270255786u|1u);return;}
c.pc=270254729u;}
static void b_101bc288(Context& c){
{uint32_t v=add(c,c.r[2],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270254920u|1u);return;}}
c.pc=270254733u;}
static void b_101bc28c(Context& c){
{uint32_t v=add(c,c.r[2],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270254976u|1u);return;}}
c.pc=270254737u;}
static void b_101bc290(Context& c){
{c.pc=(270255786u|1u);return;}
c.pc=270254739u;}
static void b_101bc292(Context& c){
{uint32_t v=add(c,c.r[2],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270255146u|1u);return;}}
c.pc=270254745u;}
static void b_101bc298(Context& c){
{if(cond(c,13)){c.pc=(270254760u|1u);return;}}
c.pc=270254747u;}
static void b_101bc29a(Context& c){
{uint32_t v=add(c,c.r[2],~(80u),1,true);}
{if(cond(c,1)){c.pc=(270255102u|1u);return;}}
c.pc=270254753u;}
static void b_101bc2a0(Context& c){
{uint32_t v=add(c,c.r[2],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270255146u|1u);return;}}
c.pc=270254759u;}
static void b_101bc2a6(Context& c){
{c.pc=(270255786u|1u);return;}
c.pc=270254761u;}
static void b_101bc2a8(Context& c){
{uint32_t v=add(c,c.r[2],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270255146u|1u);return;}}
c.pc=270254767u;}
static void b_101bc2ae(Context& c){
{uint32_t v=add(c,c.r[2],~(140u),1,true);}
{if(cond(c,2)){c.pc=(270255786u|1u);return;}}
c.pc=270254773u;}
static void b_101bc2b4(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.d[10]=rd<uint64_t>(c,a+16u);c.r[13]=a+24u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(270391404u|1u);return;}
c.pc=270254789u;}
static void b_101bc2c4(Context& c){
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270255786u|1u);return;}}
c.pc=270254795u;}
static void b_101bc2ca(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270254932u|1u);return;}
c.pc=270254801u;}
static void b_101bc2d0(Context& c){
{if(c.r[3] != 0){c.pc=(270254834u|1u);return;}}
c.pc=270254803u;}
static void b_101bc2d2(Context& c){
{c.r[14]=270254807u;c.pc=(270254660u|1u);return;}
c.pc=270254807u;}
static void b_101bc2d6(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{if(c.r[2] != 0){c.pc=(270254816u|1u);return;}}
c.pc=270254813u;}
static void b_101bc2dc(Context& c){
{uint32_t v=14u;nz(c,v);c.r[1]=v;}
{c.pc=(270254820u|1u);return;}
c.pc=270254817u;}
static void b_101bc2e0(Context& c){
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270254827u;c.pc=(270393366u|1u);return;}
c.pc=270254827u;}
static void b_101bc2e4(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270254827u;c.pc=(270393366u|1u);return;}
c.pc=270254827u;}
static void b_101bc2ea(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270255786u|1u);return;}
c.pc=270254835u;}
static void b_101bc2f2(Context& c){
{uint32_t a=(c.r[1]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(14u),1,true);}
{if(cond(c,2)){c.pc=(270255710u|1u);return;}}
c.pc=270254845u;}
static void b_101bc2fc(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270255786u|1u);return;}}
c.pc=270254855u;}
static void b_101bc306(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{c.pc=(270254934u|1u);return;}
c.pc=270254861u;}
static void b_101bc30c(Context& c){
{if(c.r[3] != 0){c.pc=(270254882u|1u);return;}}
c.pc=270254863u;}
static void b_101bc30e(Context& c){
{c.r[14]=270254867u;c.pc=(270254660u|1u);return;}
c.pc=270254867u;}
static void b_101bc312(Context& c){
{if(c.r[0] == 0){c.pc=(270254874u|1u);return;}}
c.pc=270254869u;}
static void b_101bc314(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=15u;nz(c,v);c.r[1]=v;}
{c.pc=(270255116u|1u);return;}
c.pc=270254875u;}
static void b_101bc31a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.pc=(270255118u|1u);return;}
c.pc=270254883u;}
static void b_101bc322(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270254900u|1u);return;}}
c.pc=270254889u;}
static void b_101bc328(Context& c){
{uint32_t a=(c.r[1]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(15u),1,true);}
{if(cond(c,1)){c.pc=(270254874u|1u);return;}}
c.pc=270254897u;}
static void b_101bc330(Context& c){
{c.r[14]=270254901u;c.pc=(269980032u|1u);return;}
c.pc=270254901u;}
static void b_101bc334(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.d[10]=rd<uint64_t>(c,a+16u);c.r[13]=a+24u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(269978432u|1u);return;}
c.pc=270254921u;}
static void b_101bc33a(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.d[10]=rd<uint64_t>(c,a+16u);c.r[13]=a+24u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(269978432u|1u);return;}
c.pc=270254921u;}
static void b_101bc348(Context& c){
{if(c.r[3] != 0){c.pc=(270254950u|1u);return;}}
c.pc=270254923u;}
static void b_101bc34a(Context& c){
{c.r[14]=270254927u;c.pc=(270254660u|1u);return;}
c.pc=270254927u;}
static void b_101bc34e(Context& c){
{if(c.r[0] == 0){c.pc=(270254970u|1u);return;}}
c.pc=270254929u;}
static void b_101bc350(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=15u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.d[10]=rd<uint64_t>(c,a+16u);c.r[13]=a+24u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(270393366u|1u);return;}
c.pc=270254951u;}
static void b_101bc354(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.d[10]=rd<uint64_t>(c,a+16u);c.r[13]=a+24u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(270393366u|1u);return;}
c.pc=270254951u;}
static void b_101bc356(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.d[10]=rd<uint64_t>(c,a+16u);c.r[13]=a+24u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(270393366u|1u);return;}
c.pc=270254951u;}
static void b_101bc366(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270255786u|1u);return;}}
c.pc=270254961u;}
static void b_101bc370(Context& c){
{uint32_t a=(c.r[1]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(15u),1,true);}
{if(cond(c,2)){c.pc=(270255772u|1u);return;}}
c.pc=270254971u;}
static void b_101bc37a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{c.pc=(270255768u|1u);return;}
c.pc=270254977u;}
static void b_101bc380(Context& c){
{if(c.r[3] != 0){c.pc=(270255020u|1u);return;}}
c.pc=270254979u;}
static void b_101bc382(Context& c){
{c.r[14]=270254983u;c.pc=(270254660u|1u);return;}
c.pc=270254983u;}
static void b_101bc386(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{if(c.r[2] == 0){c.pc=(270254994u|1u);return;}}
c.pc=270254989u;}
static void b_101bc38c(Context& c){
{uint32_t v=15u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.pc=(270254996u|1u);return;}
c.pc=270254995u;}
static void b_101bc392(Context& c){
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270255003u;c.pc=(270393366u|1u);return;}
c.pc=270255003u;}
static void b_101bc394(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270255003u;c.pc=(270393366u|1u);return;}
c.pc=270255003u;}
static void b_101bc39a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.d[10]=rd<uint64_t>(c,a+16u);c.r[13]=a+24u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(269975948u|1u);return;}
c.pc=270255021u;}
static void b_101bc3ac(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270255718u|1u);return;}}
c.pc=270255031u;}
static void b_101bc3b6(Context& c){
{uint32_t a=(c.r[1]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(15u),1,true);}
{if(cond(c,2)){c.pc=(270255718u|1u);return;}}
c.pc=270255041u;}
static void b_101bc3c0(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270254934u|1u);return;}
c.pc=270255047u;}
static void b_101bc3c6(Context& c){
{uint32_t a=(c.r[1]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(10u),1,true);}
{if(cond(c,2)){c.pc=(270255070u|1u);return;}}
c.pc=270255055u;}
static void b_101bc3ce(Context& c){
{c.r[14]=270255059u;c.pc=(270118736u|1u);return;}
c.pc=270255059u;}
static void b_101bc3d2(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270255786u|1u);return;}}
c.pc=270255065u;}
static void b_101bc3d8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270255768u|1u);return;}
c.pc=270255071u;}
static void b_101bc3de(Context& c){
{uint32_t v=add(c,c.r[6],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270255064u|1u);return;}}
c.pc=270255075u;}
static void b_101bc3e2(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270255786u|1u);return;}}
c.pc=270255085u;}
static void b_101bc3ec(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.d[10]=rd<uint64_t>(c,a+16u);c.r[13]=a+24u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(270391848u|1u);return;}
c.pc=270255103u;}
static void b_101bc3fe(Context& c){
{if(c.r[3] != 0){c.pc=(270255130u|1u);return;}}
c.pc=270255105u;}
static void b_101bc400(Context& c){
{c.r[14]=270255109u;c.pc=(270254660u|1u);return;}
c.pc=270255109u;}
static void b_101bc404(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{if(c.r[2] == 0){c.pc=(270255126u|1u);return;}}
c.pc=270255115u;}
static void b_101bc40a(Context& c){
{uint32_t v=19u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270255125u;c.pc=(270393366u|1u);return;}
c.pc=270255125u;}
static void b_101bc40c(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270255125u;c.pc=(270393366u|1u);return;}
c.pc=270255125u;}
static void b_101bc40e(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270255125u;c.pc=(270393366u|1u);return;}
c.pc=270255125u;}
static void b_101bc414(Context& c){
{c.pc=(270254900u|1u);return;}
c.pc=270255127u;}
static void b_101bc416(Context& c){
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{c.pc=(270255118u|1u);return;}
c.pc=270255131u;}
static void b_101bc41a(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270254900u|1u);return;}}
c.pc=270255139u;}
static void b_101bc422(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270254900u|1u);return;}
c.pc=270255147u;}
static void b_101bc42a(Context& c){
{uint32_t a=(c.r[4]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(10u),1,true);}
{if(cond(c,2)){c.pc=(270255204u|1u);return;}}
c.pc=270255155u;}
static void b_101bc432(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270255163u;c.pc=(270118736u|1u);return;}
c.pc=270255163u;}
static void b_101bc43a(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270255786u|1u);return;}}
c.pc=270255169u;}
static void b_101bc440(Context& c){
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270255181u;c.pc=(270393366u|1u);return;}
c.pc=270255181u;}
static void b_101bc44c(Context& c){
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=65303u;c.r[8]=v;}
{uint32_t v=4294967295u;c.r[9]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[3]);wr<uint32_t>(c,a+4u,c.r[8]);wr<uint32_t>(c,a+8u,c.r[9]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[2];c.r[3]=v;}
{c.pc=(270255704u|1u);return;}
c.pc=270255205u;}
static void b_101bc464(Context& c){
{if(c.r[6] != 0){c.pc=(270255246u|1u);return;}}
c.pc=270255207u;}
static void b_101bc466(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270255219u;c.pc=(270393366u|1u);return;}
c.pc=270255219u;}
static void b_101bc472(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=65303u;c.r[12]=v;}
{uint32_t v=4294967295u;c.r[14]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[3]);wr<uint32_t>(c,a+4u,c.r[12]);wr<uint32_t>(c,a+8u,c.r[14]);}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=c.r[6];c.r[3]=v;}
{c.r[14]=270255245u;c.pc=(270015700u|1u);return;}
c.pc=270255245u;}
static void b_101bc48c(Context& c){
{c.pc=(270255590u|1u);return;}
c.pc=270255247u;}
static void b_101bc48e(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270255590u|1u);return;}}
c.pc=270255257u;}
static void b_101bc498(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=65284u;c.r[6]=v;}
{uint32_t v=4294967295u;c.r[7]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{setfs(c,21,-16.0);}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[3]);wr<uint32_t>(c,a+4u,c.r[6]);wr<uint32_t>(c,a+8u,c.r[7]);}
{uint32_t a=((270255282u&~3u)+0u+516u);setsbits(c,18,rd<uint32_t>(c,a+0u));}
{uint32_t v=c.r[2];c.r[3]=v;}
{uint32_t a=((270255288u&~3u)+0u+512u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{c.r[14]=270255293u;c.pc=(270015700u|1u);return;}
c.pc=270255293u;}
static void b_101bc4bc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270255299u;c.pc=(270392138u|1u);return;}
c.pc=270255299u;}
static void b_101bc4c2(Context& c){
{setfs(c,17,-10.0);}
{setfs(c,20,16.0);}
{setfs(c,19,-8.0);}
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270255319u;c.pc=(270392110u|1u);return;}
c.pc=270255319u;}
static void b_101bc4d6(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=shift(c,c.r[6],1u,3,false);c.r[8]=v;}
{uint32_t v=8u;c.r[12]=v;}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,2)){uint32_t v=4294967295u;c.r[9]=v;}}
{if(cond(c,1)){uint32_t v=1u;c.r[9]=v;}}
{uint32_t v=shift(c,c.r[0],1u,1,false);c.r[11]=v;}
{uint32_t v=shift(c,c.r[0],1u,3,false);c.r[10]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+24u);wr<uint32_t>(c,a+0u,c.r[12]);}
{c.r[14]=270255359u;c.pc=(270082278u|1u);return;}
c.pc=270255359u;}
static void b_101bc4f4(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+24u);wr<uint32_t>(c,a+0u,c.r[12]);}
{c.r[14]=270255359u;c.pc=(270082278u|1u);return;}
c.pc=270255359u;}
static void b_101bc4fe(Context& c){
{uint32_t v=c.r[11];c.r[1]=v;}
{c.r[14]=270255365u;c.pc=(270697604u|1u);return;}
c.pc=270255365u;}
static void b_101bc504(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(c.r[10]),1,false);c.r[7]=v;}
{c.r[14]=270255375u;c.pc=(270082278u|1u);return;}
c.pc=270255375u;}
static void b_101bc50e(Context& c){
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t v=(c.r[9])*(c.r[7]);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[7]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270255389u;c.pc=(270697604u|1u);return;}
c.pc=270255389u;}
static void b_101bc51c(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,21));}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=add(c,c.r[1],~(c.r[8]),1,false);c.r[3]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[1]);wr<uint32_t>(c,a+4u,c.r[7]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270255425u;c.pc=(270091396u|1u);return;}
c.pc=270255425u;}
static void b_101bc540(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270255431u;c.pc=(270082278u|1u);return;}
c.pc=270255431u;}
static void b_101bc546(Context& c){
{uint32_t v=c.r[11];c.r[1]=v;}
{c.r[14]=270255437u;c.pc=(270697604u|1u);return;}
c.pc=270255437u;}
static void b_101bc54c(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(c.r[10]),1,false);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[1]);}
{c.r[14]=270255449u;c.pc=(270082278u|1u);return;}
c.pc=270255449u;}
static void b_101bc558(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[9])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270255463u;c.pc=(270697604u|1u);return;}
c.pc=270255463u;}
static void b_101bc566(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,20));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=add(c,c.r[1],~(c.r[8]),1,false);c.r[3]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[1]);wr<uint32_t>(c,a+4u,c.r[7]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270255499u;c.pc=(270082284u|1u);return;}
c.pc=270255499u;}
static void b_101bc58a(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270255505u;c.pc=(270082278u|1u);return;}
c.pc=270255505u;}
static void b_101bc590(Context& c){
{uint32_t v=c.r[11];c.r[1]=v;}
{c.r[14]=270255511u;c.pc=(270697604u|1u);return;}
c.pc=270255511u;}
static void b_101bc596(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(c.r[10]),1,false);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[1]);}
{c.r[14]=270255523u;c.pc=(270082278u|1u);return;}
c.pc=270255523u;}
static void b_101bc5a2(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[9])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270255537u;c.pc=(270697604u|1u);return;}
c.pc=270255537u;}
static void b_101bc5b0(Context& c){
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,19));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[1],~(c.r[8]),1,false);c.r[3]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[1]);wr<uint32_t>(c,a+4u,c.r[7]);}
{uint32_t v=1090519040u;c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270255575u;c.pc=(270082284u|1u);return;}
c.pc=270255575u;}
static void b_101bc5d6(Context& c){
{uint32_t a=(c.r[13]+0u+24u);c.r[12]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[12],~(1u),1,true);c.r[12]=v;}
{if(cond(c,2)){c.pc=(270255348u|1u);return;}}
c.pc=270255585u;}
static void b_101bc5e0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270255591u;c.pc=(270391404u|1u);return;}
c.pc=270255591u;}
static void b_101bc5e6(Context& c){
{uint32_t a=(c.r[4]+0u+16u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+16u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,13)){c.pc=(270255786u|1u);return;}}
c.pc=270255601u;}
static void b_101bc5f0(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270255607u;c.pc=(270082278u|1u);return;}
c.pc=270255607u;}
static void b_101bc5f6(Context& c){
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.r[14]=270255613u;c.pc=(270697604u|1u);return;}
c.pc=270255613u;}
static void b_101bc5fc(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],3u,0,true);c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+16u);wr<uint32_t>(c,a+0u,c.r[1]);}
{c.r[14]=270255623u;c.pc=(270082278u|1u);return;}
c.pc=270255623u;}
static void b_101bc606(Context& c){
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270255631u;c.pc=(270392110u|1u);return;}
c.pc=270255631u;}
static void b_101bc60e(Context& c){
{uint32_t v=c.r[0];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[0]=v;}
{c.r[14]=270255639u;c.pc=(270697604u|1u);return;}
c.pc=270255639u;}
static void b_101bc616(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[6]=v;}
{c.r[14]=270255647u;c.pc=(270392110u|1u);return;}
c.pc=270255647u;}
static void b_101bc61e(Context& c){
{uint32_t v=add(c,c.r[6],~(shift(c,c.r[0],1,3,false)),1,false);c.r[6]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270255657u;c.pc=(270082278u|1u);return;}
c.pc=270255657u;}
static void b_101bc628(Context& c){
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270255665u;c.pc=(270392138u|1u);return;}
c.pc=270255665u;}
static void b_101bc630(Context& c){
{uint32_t v=c.r[0];c.r[1]=v;}
{uint32_t v=c.r[7];c.r[0]=v;}
{c.r[14]=270255673u;c.pc=(270697604u|1u);return;}
c.pc=270255673u;}
static void b_101bc638(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[7]=v;}
{c.r[14]=270255681u;c.pc=(270392138u|1u);return;}
c.pc=270255681u;}
static void b_101bc640(Context& c){
{uint32_t v=65304u;c.r[1]=v;}
{uint32_t v=4294967295u;c.r[2]=v;}
{uint32_t v=add(c,c.r[7],~(shift(c,c.r[0],1,3,false)),1,false);c.r[3]=v;}
{uint32_t v=0u;nz(c,v);c.r[0]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[0]);wr<uint32_t>(c,a+4u,c.r[1]);wr<uint32_t>(c,a+8u,c.r[2]);}
{uint32_t v=shift(c,c.r[6],1u,1,true);nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270255709u;c.pc=(270015700u|1u);return;}
c.pc=270255709u;}
static void b_101bc658(Context& c){
{c.r[14]=270255709u;c.pc=(270015700u|1u);return;}
c.pc=270255709u;}
static void b_101bc65c(Context& c){
{c.pc=(270255786u|1u);return;}
c.pc=270255711u;}
static void b_101bc65e(Context& c){
{uint32_t v=add(c,c.r[3],~(7u),1,true);}
{if(cond(c,2)){c.pc=(270255786u|1u);return;}}
c.pc=270255715u;}
static void b_101bc662(Context& c){
{uint32_t a=((270255718u&~3u)+0u+88u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270254906u|1u);return;}
c.pc=270255719u;}
static void b_101bc666(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270255727u;c.pc=(270118736u|1u);return;}
c.pc=270255727u;}
static void b_101bc66e(Context& c){
{if(c.r[0] == 0){c.pc=(270255736u|1u);return;}}
c.pc=270255729u;}
static void b_101bc670(Context& c){
{uint32_t a=(c.r[4]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270255764u|1u);return;}}
c.pc=270255737u;}
static void b_101bc678(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[1]=rd<uint8_t>(c,a+0u);}
{if(c.r[1] != 0){c.pc=(270255786u|1u);return;}}
c.pc=270255743u;}
static void b_101bc67e(Context& c){
{uint32_t a=(c.r[4]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(20u),1,true);}
{if(cond(c,2)){c.pc=(270255786u|1u);return;}}
c.pc=270255751u;}
static void b_101bc686(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270255757u;c.pc=(269975948u|1u);return;}
c.pc=270255757u;}
static void b_101bc68c(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=50u;nz(c,v);c.r[2]=v;}
{c.pc=(270255772u|1u);return;}
c.pc=270255765u;}
static void b_101bc694(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=20u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.pc=(270254934u|1u);return;}
c.pc=270255773u;}
static void b_101bc698(Context& c){
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.pc=(270254934u|1u);return;}
c.pc=270255773u;}
static void b_101bc69c(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.d[10]=rd<uint64_t>(c,a+16u);c.r[13]=a+24u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(269980032u|1u);return;}
c.pc=270255787u;}
static void b_101bc6aa(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.d[10]=rd<uint64_t>(c,a+16u);c.r[13]=a+24u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);uint32_t newpc=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;c.pc=newpc;return;}
c.pc=270255797u;}
static void b_101bc6c0(Context& c){
{uint32_t a=c.r[13]-36u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[11]);wr<uint32_t>(c,a+32u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-24u;wr<uint64_t>(c,a+0u,c.d[8]);wr<uint64_t>(c,a+8u,c.d[9]);wr<uint64_t>(c,a+16u,c.d[10]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[4]=v;}
{uint32_t a=((270255822u&~3u)+0u+632u);setsbits(c,18,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[13],~(36u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[5]=v;}
{c.r[14]=270255833u;c.pc=(270392138u|1u);return;}
c.pc=270255833u;}
static void b_101bc6d8(Context& c){
{uint32_t v=1u;c.r[8]=v;}
{uint32_t v=4294967295u;c.r[6]=v;}
{uint32_t v=65303u;c.r[7]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=150u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{setfs(c,21,-16.0);}
{uint32_t v=8u;c.r[11]=v;}
{uint32_t a=((270255870u&~3u)+0u+588u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{setfs(c,17,-10.0);}
{setfs(c,20,16.0);}
{uint32_t v=c.r[0];c.r[9]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270255887u;c.pc=(270015700u|1u);return;}
c.pc=270255887u;}
static void b_101bc70e(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=80u;nz(c,v);c.r[2]=v;}
{uint32_t v=160u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270255907u;c.pc=(270015700u|1u);return;}
c.pc=270255907u;}
static void b_101bc722(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=~(99u);c.r[2]=v;}
{uint32_t v=140u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270255929u;c.pc=(270015700u|1u);return;}
c.pc=270255929u;}
static void b_101bc738(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=160u;nz(c,v);c.r[2]=v;}
{uint32_t v=150u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270255949u;c.pc=(270015700u|1u);return;}
c.pc=270255949u;}
static void b_101bc74c(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=~(199u);c.r[2]=v;}
{uint32_t v=150u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270255971u;c.pc=(270015700u|1u);return;}
c.pc=270255971u;}
static void b_101bc762(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=260u;c.r[2]=v;}
{uint32_t v=160u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270255993u;c.pc=(270015700u|1u);return;}
c.pc=270255993u;}
static void b_101bc778(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t a=((270256002u&~3u)+0u+460u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=140u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270256013u;c.pc=(270015700u|1u);return;}
c.pc=270256013u;}
static void b_101bc78c(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t a=((270256022u&~3u)+0u+444u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=150u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270256033u;c.pc=(270015700u|1u);return;}
c.pc=270256033u;}
static void b_101bc7a0(Context& c){
{setfs(c,19,-8.0);}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=340u;c.r[2]=v;}
{uint32_t v=160u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270256059u;c.pc=(270015700u|1u);return;}
c.pc=270256059u;}
static void b_101bc7ba(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t a=((270256068u&~3u)+0u+400u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=140u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270256079u;c.pc=(270015700u|1u);return;}
c.pc=270256079u;}
static void b_101bc7ce(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=420u;c.r[2]=v;}
{uint32_t v=150u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270256101u;c.pc=(270015700u|1u);return;}
c.pc=270256101u;}
static void b_101bc7e4(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=500u;c.r[2]=v;}
{uint32_t v=150u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270256123u;c.pc=(270015700u|1u);return;}
c.pc=270256123u;}
static void b_101bc7fa(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=580u;c.r[2]=v;}
{uint32_t v=160u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270256145u;c.pc=(270015700u|1u);return;}
c.pc=270256145u;}
static void b_101bc810(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=140u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t a=((270256162u&~3u)+0u+312u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270256165u;c.pc=(270015700u|1u);return;}
c.pc=270256165u;}
static void b_101bc824(Context& c){
{uint32_t a=(c.r[5]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,2)){uint32_t v=c.r[6];c.r[10]=v;}}
{if(cond(c,1)){uint32_t v=c.r[8];c.r[10]=v;}}
{uint32_t v=shift(c,c.r[9],(c.r[8]&255u),3,false);c.r[8]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270256185u;c.pc=(270082278u|1u);return;}
c.pc=270256185u;}
static void b_101bc832(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270256185u;c.pc=(270082278u|1u);return;}
c.pc=270256185u;}
static void b_101bc838(Context& c){
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270256193u;c.pc=(270082278u|1u);return;}
c.pc=270256193u;}
static void b_101bc840(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=c.r[7];c.r[0]=v;}
{c.r[14]=270256203u;c.pc=(270697604u|1u);return;}
c.pc=270256203u;}
static void b_101bc84a(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[7]=v;}
{uint32_t v=1u;nz(c,v);c.r[6]=v;}
{uint32_t v=add(c,c.r[1],~(130u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270256223u;c.pc=(270697604u|1u);return;}
c.pc=270256223u;}
static void b_101bc85e(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,21));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=shift(c,c.r[1],1u,1,true);nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[1],~(c.r[8]),1,false);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[3],70u,0,true);c.r[3]=v;}
{c.r[14]=270256261u;c.pc=(270091396u|1u);return;}
c.pc=270256261u;}
static void b_101bc884(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270256267u;c.pc=(270082278u|1u);return;}
c.pc=270256267u;}
static void b_101bc88a(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270256277u;c.pc=(270082278u|1u);return;}
c.pc=270256277u;}
static void b_101bc894(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270256291u;c.pc=(270697604u|1u);return;}
c.pc=270256291u;}
static void b_101bc8a2(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],30u,0,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270256309u;c.pc=(270697604u|1u);return;}
c.pc=270256309u;}
static void b_101bc8b4(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,20));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=shift(c,c.r[1],(c.r[6]&255u),1,true);nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[1],~(c.r[8]),1,false);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[3],70u,0,true);c.r[3]=v;}
{c.r[14]=270256347u;c.pc=(270082284u|1u);return;}
c.pc=270256347u;}
static void b_101bc8da(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270256353u;c.pc=(270082278u|1u);return;}
c.pc=270256353u;}
static void b_101bc8e0(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270256363u;c.pc=(270082278u|1u);return;}
c.pc=270256363u;}
static void b_101bc8ea(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270256377u;c.pc=(270697604u|1u);return;}
c.pc=270256377u;}
static void b_101bc8f8(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(50u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270256395u;c.pc=(270697604u|1u);return;}
c.pc=270256395u;}
static void b_101bc90a(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,19));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=shift(c,c.r[1],(c.r[6]&255u),1,true);nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[1],~(c.r[8]),1,false);c.r[3]=v;}
{uint32_t v=1090519040u;c.r[1]=v;}
{uint32_t v=add(c,c.r[3],70u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270256435u;c.pc=(270082284u|1u);return;}
c.pc=270256435u;}
static void b_101bc932(Context& c){
{uint32_t v=add(c,c.r[11],~(1u),1,true);c.r[11]=v;}
{if(cond(c,2)){c.pc=(270256178u|1u);return;}}
c.pc=270256443u;}
static void b_101bc93a(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.d[10]=rd<uint64_t>(c,a+16u);c.r[13]=a+24u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);uint32_t newpc=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;c.pc=newpc;return;}
c.pc=270256453u;}
static void b_101bc95c(Context& c){
{uint32_t a=c.r[13]-32u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[8]=v;}
{uint32_t a=(c.r[1]+0u+28u);c.r[9]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[2];c.r[5]=v;}
{uint32_t v=c.r[3];c.r[6]=v;}
{uint32_t v=add(c,c.r[9],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270256648u|1u);return;}}
c.pc=270256499u;}
static void b_101bc972(Context& c){
{uint32_t v=1u;nz(c,v);c.r[7]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t a=(c.r[1]+0u+28u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270256511u;c.pc=(269975422u|1u);return;}
c.pc=270256511u;}
static void b_101bc97e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270256519u;c.pc=(269975414u|1u);return;}
c.pc=270256519u;}
static void b_101bc986(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270256527u;c.pc=(269975768u|1u);return;}
c.pc=270256527u;}
static void b_101bc98e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270256535u;c.pc=(269976968u|1u);return;}
c.pc=270256535u;}
static void b_101bc996(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270256543u;c.pc=(269976986u|1u);return;}
c.pc=270256543u;}
static void b_101bc99e(Context& c){
{uint32_t v=c.r[7];c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270256551u;c.pc=(269975400u|1u);return;}
c.pc=270256551u;}
static void b_101bc9a6(Context& c){
{c.r[14]=270256555u;c.pc=(270408416u|1u);return;}
c.pc=270256555u;}
static void b_101bc9aa(Context& c){
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t v=c.r[0];c.r[10]=v;}
{c.r[14]=270256563u;c.pc=(270408946u|1u);return;}
c.pc=270256563u;}
static void b_101bc9b2(Context& c){
{uint32_t v=c.r[7];c.r[1]=v;}
{uint32_t v=c.r[0];c.r[9]=v;}
{uint32_t v=c.r[10];c.r[0]=v;}
{c.r[14]=270256573u;c.pc=(270408946u|1u);return;}
c.pc=270256573u;}
static void b_101bc9bc(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[2],~(90u),1,true);}
{uint32_t v=70u;c.r[2]=v;}
{uint32_t v=add(c,c.r[0],~(c.r[9]),1,false);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],shift(c,c.r[3],31,2,false),0,false);c.r[3]=v;}
{uint32_t v=shift(c,c.r[3],(c.r[7]&255u),3,false);c.r[3]=v;}
{}
{if(cond(c,2)){uint32_t v=add(c,c.r[0],~(c.r[3]),1,false);c.r[3]=v;}}
{if(cond(c,1)){uint32_t v=add(c,c.r[9],c.r[3],0,false);c.r[9]=v;}}
{uint32_t v=c.r[4];c.r[0]=v;}
{}
{if(cond(c,1)){setsbits(c,14,c.r[9]);}}
{if(cond(c,2)){setsbits(c,14,c.r[3]);}}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.r[14]=270256631u;c.pc=(270393746u|1u);return;}
c.pc=270256631u;}
static void b_101bc9f6(Context& c){
{uint32_t v=add(c,c.r[5],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270256638u|1u);return;}}
c.pc=270256635u;}
static void b_101bc9fa(Context& c){
{uint32_t v=add(c,c.r[5],~(30u),1,true);}
{if(cond(c,2)){c.pc=(270256648u|1u);return;}}
c.pc=270256639u;}
static void b_101bc9fe(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270256649u;}
static void b_101bca08(Context& c){
{uint32_t v=add(c,c.r[5],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270256818u|1u);return;}}
c.pc=270256653u;}
static void b_101bca0c(Context& c){
{if(cond(c,13)){c.pc=(270256680u|1u);return;}}
c.pc=270256655u;}
static void b_101bca0e(Context& c){
{uint32_t v=add(c,c.r[5],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270256710u|1u);return;}}
c.pc=270256659u;}
static void b_101bca12(Context& c){
{if(cond(c,13)){c.pc=(270256668u|1u);return;}}
c.pc=270256661u;}
static void b_101bca14(Context& c){
{uint32_t v=add(c,c.r[5],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270256710u|1u);return;}}
c.pc=270256665u;}
static void b_101bca18(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270256669u;}
static void b_101bca1c(Context& c){
{uint32_t v=add(c,c.r[5],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270256792u|1u);return;}}
c.pc=270256673u;}
static void b_101bca20(Context& c){
{uint32_t v=add(c,c.r[5],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270256800u|1u);return;}}
c.pc=270256677u;}
static void b_101bca24(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270256681u;}
static void b_101bca28(Context& c){
{uint32_t v=add(c,c.r[5],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270256846u|1u);return;}}
c.pc=270256685u;}
static void b_101bca2c(Context& c){
{if(cond(c,13)){c.pc=(270256698u|1u);return;}}
c.pc=270256687u;}
static void b_101bca2e(Context& c){
{uint32_t v=add(c,c.r[5],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270256710u|1u);return;}}
c.pc=270256691u;}
static void b_101bca32(Context& c){
{uint32_t v=add(c,c.r[5],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270256846u|1u);return;}}
c.pc=270256695u;}
static void b_101bca36(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270256699u;}
static void b_101bca3a(Context& c){
{uint32_t v=add(c,c.r[5],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270256846u|1u);return;}}
c.pc=270256703u;}
static void b_101bca3e(Context& c){
{uint32_t v=add(c,c.r[5],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270256886u|1u);return;}}
c.pc=270256707u;}
static void b_101bca42(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270256711u;}
static void b_101bca46(Context& c){
{uint32_t v=add(c,c.r[6],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270256896u|1u);return;}}
c.pc=270256715u;}
static void b_101bca4a(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.r[14]=270256727u;c.pc=(270393366u|1u);return;}
c.pc=270256727u;}
static void b_101bca56(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270256896u|1u);return;}}
c.pc=270256733u;}
static void b_101bca5c(Context& c){
{uint32_t v=c.r[8];c.r[0]=v;}
{c.r[14]=270256739u;c.pc=(270082278u|1u);return;}
c.pc=270256739u;}
static void b_101bca62(Context& c){
{uint32_t v=30u;nz(c,v);c.r[1]=v;}
{c.r[14]=270256745u;c.pc=(270697604u|1u);return;}
c.pc=270256745u;}
static void b_101bca68(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=3u;nz(c,v);c.r[1]=v;}
{c.r[14]=270256753u;c.pc=(270697604u|1u);return;}
c.pc=270256753u;}
static void b_101bca70(Context& c){
{uint32_t v=add(c,c.r[1],~(1u),1,true);}
{uint32_t v=c.r[1];c.r[2]=v;}
{if(cond(c,1)){c.pc=(270256772u|1u);return;}}
c.pc=270256759u;}
static void b_101bca76(Context& c){
{uint32_t v=add(c,c.r[1],~(2u),1,true);}
{if(cond(c,1)){c.pc=(270256784u|1u);return;}}
c.pc=270256763u;}
static void b_101bca7a(Context& c){
{uint32_t v=add(c,c.r[1],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270256896u|1u);return;}}
c.pc=270256767u;}
static void b_101bca7e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=30u;nz(c,v);c.r[1]=v;}
{c.pc=(270256788u|1u);return;}
c.pc=270256773u;}
static void b_101bca84(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=40u;nz(c,v);c.r[1]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(270391848u|1u);return;}
c.pc=270256785u;}
static void b_101bca88(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(270391848u|1u);return;}
c.pc=270256785u;}
static void b_101bca90(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=50u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.pc=(270256776u|1u);return;}
c.pc=270256793u;}
static void b_101bca94(Context& c){
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.pc=(270256776u|1u);return;}
c.pc=270256793u;}
static void b_101bca98(Context& c){
{if(c.r[6] != 0){c.pc=(270256826u|1u);return;}}
c.pc=270256795u;}
static void b_101bca9a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{c.pc=(270256806u|1u);return;}
c.pc=270256801u;}
static void b_101bcaa0(Context& c){
{if(c.r[6] != 0){c.pc=(270256826u|1u);return;}}
c.pc=270256803u;}
static void b_101bcaa2(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(270393366u|1u);return;}
c.pc=270256819u;}
static void b_101bcaa6(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(270393366u|1u);return;}
c.pc=270256819u;}
static void b_101bcab2(Context& c){
{if(c.r[6] != 0){c.pc=(270256826u|1u);return;}}
c.pc=270256821u;}
static void b_101bcab4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270256806u|1u);return;}
c.pc=270256827u;}
static void b_101bcaba(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270256896u|1u);return;}}
c.pc=270256833u;}
static void b_101bcac0(Context& c){
{uint32_t v=c.r[8];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(269980032u|1u);return;}
c.pc=270256847u;}
static void b_101bcace(Context& c){
{if(c.r[6] != 0){c.pc=(270256880u|1u);return;}}
c.pc=270256849u;}
static void b_101bcad0(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270256861u;c.pc=(270393366u|1u);return;}
c.pc=270256861u;}
static void b_101bcadc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=236u;nz(c,v);c.r[1]=v;}
{c.r[14]=270256869u;c.pc=(270393772u|1u);return;}
c.pc=270256869u;}
static void b_101bcae4(Context& c){
{uint32_t v=c.r[8];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(270255808u|1u);return;}
c.pc=270256881u;}
static void b_101bcaf0(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270256896u|1u);return;}}
c.pc=270256887u;}
static void b_101bcaf6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(270391404u|1u);return;}
c.pc=270256897u;}
static void b_101bcb00(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270256901u;}
static void b_101bcb04(Context& c){
{uint32_t a=c.r[13]-24u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-8u;wr<uint64_t>(c,a+0u,c.d[8]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(48u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{c.r[14]=270256917u;c.pc=(270326600u|1u);return;}
c.pc=270256917u;}
static void b_101bcb14(Context& c){
{uint32_t v=add(c,c.r[0],18432u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(9u),1,true);}
{if(cond(c,2)){c.pc=(270257316u|1u);return;}}
c.pc=270256929u;}
static void b_101bcb20(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270257316u|1u);return;}}
c.pc=270256937u;}
static void b_101bcb28(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],48u,0,false);c.r[2]=v;}
{uint32_t v=0u;nz(c,v);c.r[5]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[2]+0u+4294967268u);uint32_t wb=a;wr<uint32_t>(c,a+0u,c.r[5]);c.r[2]=wb;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270256955u;c.pc=c.r[3];return;}
c.pc=270256955u;}
static void b_101bcb3a(Context& c){
{uint32_t a=(c.r[13]+0u+20u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(49u),1,true);}
{if(cond(c,9)){c.pc=(270257316u|1u);return;}}
c.pc=270256963u;}
static void b_101bcb42(Context& c){
{c.r[14]=270256967u;c.pc=(270334540u|1u);return;}
c.pc=270256967u;}
static void b_101bcb46(Context& c){
{uint32_t a=(c.r[13]+0u+20u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[0];c.r[7]=v;}
{c.r[14]=270256975u;c.pc=(270338586u|1u);return;}
c.pc=270256975u;}
static void b_101bcb4e(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270257316u|1u);return;}}
c.pc=270256981u;}
static void b_101bcb54(Context& c){
{uint32_t a=(c.r[0]+0u+80u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[8]=v;}
{uint32_t a=(c.r[0]+0u+16u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,100u,~(c.r[2]),1,false);c.r[2]=v;}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{}
{if(cond(c,12)){uint32_t v=add(c,0u,~(c.r[2]),1,false);c.r[2]=v;}}
{uint32_t a=(c.r[13]+0u+24u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[0]+0u+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+44u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[0]+0u+4u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+32u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[0]+0u+8u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+36u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[0]+0u+12u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+40u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[3]+c.r[8]+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],4u,0,true);c.r[3]=v;}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{}
{if(cond(c,11)){uint32_t v=add(c,c.r[5],c.r[2],0,false);c.r[5]=v;}}
{uint32_t v=add(c,c.r[3],~(24u),1,true);}
{if(cond(c,2)){c.pc=(270257020u|1u);return;}}
c.pc=270257037u;}
static void b_101bcb7c(Context& c){
{uint32_t a=(c.r[3]+c.r[8]+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],4u,0,true);c.r[3]=v;}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{}
{if(cond(c,11)){uint32_t v=add(c,c.r[5],c.r[2],0,false);c.r[5]=v;}}
{uint32_t v=add(c,c.r[3],~(24u),1,true);}
{if(cond(c,2)){c.pc=(270257020u|1u);return;}}
c.pc=270257037u;}
static void b_101bcb8c(Context& c){
{c.r[14]=270257041u;c.pc=(269636796u|0u);return;}
c.pc=270257041u;}
static void b_101bcb90(Context& c){
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270257047u;c.pc=(270697604u|1u);return;}
c.pc=270257047u;}
static void b_101bcb96(Context& c){
{uint32_t v=0u;nz(c,v);c.r[6]=v;}
{uint32_t a=(c.r[8]+shift(c,c.r[6],2,1,false)+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,12)){c.pc=(270257060u|1u);return;}}
c.pc=270257057u;}
static void b_101bcb98(Context& c){
{uint32_t a=(c.r[8]+shift(c,c.r[6],2,1,false)+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,12)){c.pc=(270257060u|1u);return;}}
c.pc=270257057u;}
static void b_101bcba0(Context& c){
{uint32_t v=add(c,c.r[1],~(c.r[3]),1,true);c.r[1]=v;}
{if(cond(c,5)){c.pc=(270257068u|1u);return;}}
c.pc=270257061u;}
static void b_101bcba4(Context& c){
{uint32_t v=add(c,c.r[6],1u,0,true);c.r[6]=v;}
{uint32_t v=add(c,c.r[6],~(6u),1,true);}
{if(cond(c,2)){c.pc=(270257048u|1u);return;}}
c.pc=270257067u;}
static void b_101bcbaa(Context& c){
{c.pc=(270257316u|1u);return;}
c.pc=270257069u;}
static void b_101bcbac(Context& c){
{uint32_t v=add(c,c.r[6],~(0u),1,true);}
{if(cond(c,14)){c.pc=(270257316u|1u);return;}}
c.pc=270257073u;}
static void b_101bcbb0(Context& c){
{uint32_t a=(c.r[4]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(2u),1,true);}
{if(cond(c,1)){c.pc=(270257106u|1u);return;}}
c.pc=270257081u;}
static void b_101bcbb8(Context& c){
{uint32_t v=2u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270257093u;c.pc=(270393366u|1u);return;}
c.pc=270257093u;}
static void b_101bcbc4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=30u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[14]=270257103u;c.pc=(270391848u|1u);return;}
c.pc=270257103u;}
static void b_101bcbce(Context& c){
{uint32_t a=(c.r[4]+0u+16u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.pc=(270257316u|1u);return;}
c.pc=270257107u;}
static void b_101bcbd2(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+56u);c.r[1]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270257115u;c.pc=(270338580u|1u);return;}
c.pc=270257115u;}
static void b_101bcbda(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270257316u|1u);return;}}
c.pc=270257119u;}
static void b_101bcbde(Context& c){
{uint32_t a=(c.r[0]+0u+60u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t v=12u;nz(c,v);c.r[5]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[1]),1,true);}
{uint32_t a=(c.r[0]+0u+56u);c.r[2]=rd<uint32_t>(c,a+0u);}
{if(cond(c,11)){c.pc=(270257144u|1u);return;}}
c.pc=270257131u;}
static void b_101bcbe4(Context& c){
{uint32_t v=add(c,c.r[3],~(c.r[1]),1,true);}
{uint32_t a=(c.r[0]+0u+56u);c.r[2]=rd<uint32_t>(c,a+0u);}
{if(cond(c,11)){c.pc=(270257144u|1u);return;}}
c.pc=270257131u;}
static void b_101bcbea(Context& c){
{uint32_t v=(c.r[5])*(c.r[3])+c.r[2];c.r[7]=v;}
{uint32_t a=(c.r[7]+0u+8u);c.r[7]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[6],~(c.r[7]),1,true);}
{if(cond(c,1)){c.pc=(270257146u|1u);return;}}
c.pc=270257141u;}
static void b_101bcbf4(Context& c){
{uint32_t v=add(c,c.r[3],1u,0,true);c.r[3]=v;}
{c.pc=(270257124u|1u);return;}
c.pc=270257145u;}
static void b_101bcbf8(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{uint32_t v=(c.r[1])*(c.r[3]);c.r[3]=v;nz(c,v);}
{uint32_t v=add(c,c.r[2],c.r[3],0,true);c.r[1]=v;}
{uint32_t a=(c.r[2]+c.r[3]+0u);c.r[8]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+4u);c.r[7]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270257163u;c.pc=(270394904u|1u);return;}
c.pc=270257163u;}
static void b_101bcbfa(Context& c){
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{uint32_t v=(c.r[1])*(c.r[3]);c.r[3]=v;nz(c,v);}
{uint32_t v=add(c,c.r[2],c.r[3],0,true);c.r[1]=v;}
{uint32_t a=(c.r[2]+c.r[3]+0u);c.r[8]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+4u);c.r[7]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270257163u;c.pc=(270394904u|1u);return;}
c.pc=270257163u;}
static void b_101bcc0a(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=327u;c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270257181u;c.pc=(270398276u|1u);return;}
c.pc=270257181u;}
static void b_101bcc1c(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270257316u|1u);return;}}
c.pc=270257187u;}
static void b_101bcc22(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(270u),1,true);}
{if(cond(c,2)){c.pc=(270257218u|1u);return;}}
c.pc=270257201u;}
static void b_101bcc30(Context& c){
{c.r[14]=270257205u;c.pc=(270392110u|1u);return;}
c.pc=270257205u;}
static void b_101bcc34(Context& c){
{setsbits(c,14,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{setfs(c,16,(fs(c,16))-(fs(c,15)));}
{c.pc=(270257234u|1u);return;}
c.pc=270257219u;}
static void b_101bcc42(Context& c){
{c.r[14]=270257223u;c.pc=(270392110u|1u);return;}
c.pc=270257223u;}
static void b_101bcc46(Context& c){
{setsbits(c,14,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{setfs(c,16,(fs(c,15))+(fs(c,16)));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,17,rd<uint32_t>(c,a+0u));}
{c.r[14]=270257245u;c.pc=(270392138u|1u);return;}
c.pc=270257245u;}
static void b_101bcc52(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,17,rd<uint32_t>(c,a+0u));}
{c.r[14]=270257245u;c.pc=(270392138u|1u);return;}
c.pc=270257245u;}
static void b_101bcc5c(Context& c){
{uint32_t a=(c.r[5]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{setsbits(c,16,cvti(fs(c,16),true));}
{setfs(c,13,int32_t(sbits(c,16)));}
{c.r[1]=sbits(c,16);}
{uint32_t a=(c.r[5]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,13));}
{uint32_t a=(c.r[5]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,13));}
{uint32_t v=shift(c,c.r[0],2u,3,true);nz(c,v);c.r[0]=v;}
{setsbits(c,14,c.r[0]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{setfs(c,15,int32_t(sbits(c,14)));}
{setfs(c,15,(fs(c,17))-(fs(c,15)));}
{setsbits(c,15,cvti(fs(c,15),true));}
{setfs(c,14,int32_t(sbits(c,15)));}
{c.r[2]=sbits(c,15);}
{uint32_t a=(c.r[5]+0u+152u);wr<uint32_t>(c,a+0u,sbits(c,14));}
{uint32_t a=(c.r[5]+0u+144u);wr<uint32_t>(c,a+0u,sbits(c,14));}
{uint32_t a=(c.r[3]+0u+144u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270257309u;c.pc=c.r[3];return;}
c.pc=270257309u;}
static void b_101bcc9c(Context& c){
{uint32_t a=(c.r[5]+0u+28u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[5]+0u+52u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[5]+0u+84u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=add(c,c.r[13],48u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.r[13]=a+8u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270257327u;}
static void b_101bcca4(Context& c){
{uint32_t v=add(c,c.r[13],48u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.r[13]=a+8u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270257327u;}
static void b_101bccae(Context& c){
{uint32_t a=c.r[13]-24u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[3];c.r[6]=v;}
{uint32_t a=(c.r[1]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[2];c.r[7]=v;}
{uint32_t a=(c.r[3]+0u+92u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270257347u;c.pc=c.r[3];return;}
c.pc=270257347u;}
static void b_101bccc2(Context& c){
{if(c.r[0] == 0){c.pc=(270257356u|1u);return;}}
c.pc=270257349u;}
static void b_101bccc4(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270257357u;c.pc=(270256900u|1u);return;}
c.pc=270257357u;}
static void b_101bcccc(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[7];c.r[2]=v;}
{uint32_t v=c.r[6];c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(269939764u|1u);return;}
c.pc=270257373u;}
static void b_101bccdc(Context& c){
{uint32_t a=c.r[13]-8u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270257396u|1u);return;}}
c.pc=270257383u;}
static void b_101bcce6(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+60u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=~(99u);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=5u;nz(c,v);c.r[3]=v;}
{c.pc=(270257408u|1u);return;}
c.pc=270257397u;}
static void b_101bccf4(Context& c){
{uint32_t v=add(c,c.r[3],~(40u),1,true);}
{if(cond(c,2)){c.pc=(270257410u|1u);return;}}
c.pc=270257401u;}
static void b_101bccf8(Context& c){
{uint32_t v=100u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=~(4u);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270257416u&~3u)+0u+56u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{c.r[14]=270257459u;c.pc=(270393746u|1u);return;}
c.pc=270257459u;}
static void b_101bcd00(Context& c){
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270257416u&~3u)+0u+56u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{c.r[14]=270257459u;c.pc=(270393746u|1u);return;}
c.pc=270257459u;}
static void b_101bcd02(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270257416u&~3u)+0u+56u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{c.r[14]=270257459u;c.pc=(270393746u|1u);return;}
c.pc=270257459u;}
static void b_101bcd32(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(77u),1,true);}
{}
{if(cond(c,14)){uint32_t v=add(c,c.r[3],1u,0,false);c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270257473u;}
static void b_101bcd44(Context& c){
{uint32_t a=c.r[13]-32u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[14]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(24u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[3];c.r[6]=v;}
{uint32_t v=c.r[0];c.r[9]=v;}
{uint32_t v=c.r[2];c.r[5]=v;}
{c.r[14]=270257495u;c.pc=(270326600u|1u);return;}
c.pc=270257495u;}
static void b_101bcd56(Context& c){
{uint32_t v=add(c,c.r[0],18432u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(5u),1,true);c.r[3]=v;}
{uint32_t v=add(c,0u,~(c.r[3]),1,true);c.r[8]=v;}
{uint32_t v=add(c,c.r[8],c.r[3],c.c,true);c.r[8]=v;}
{uint32_t a=(c.r[4]+0u+56u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270257674u|1u);return;}}
c.pc=270257517u;}
static void b_101bcd6c(Context& c){
{uint32_t v=1u;nz(c,v);c.r[7]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+56u);wr<uint32_t>(c,a+0u,c.r[7]);}
{c.r[14]=270257529u;c.pc=(269975768u|1u);return;}
c.pc=270257529u;}
static void b_101bcd78(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270257537u;c.pc=(269975414u|1u);return;}
c.pc=270257537u;}
static void b_101bcd80(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270257545u;c.pc=(269975422u|1u);return;}
c.pc=270257545u;}
static void b_101bcd88(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270257553u;c.pc=(269975962u|1u);return;}
c.pc=270257553u;}
static void b_101bcd90(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270257566u|1u);return;}}
c.pc=270257559u;}
static void b_101bcd96(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270257567u;c.pc=(269976968u|1u);return;}
c.pc=270257567u;}
static void b_101bcd9e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270257575u;c.pc=(269976986u|1u);return;}
c.pc=270257575u;}
static void b_101bcda6(Context& c){
{uint32_t v=add(c,c.r[5],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270257584u|1u);return;}}
c.pc=270257579u;}
static void b_101bcdaa(Context& c){
{uint32_t v=add(c,c.r[5],~(30u),1,true);}
{if(cond(c,2)){c.pc=(270258396u|1u);return;}}
c.pc=270257585u;}
static void b_101bcdb0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270257597u;c.pc=(270393366u|1u);return;}
c.pc=270257597u;}
static void b_101bcdbc(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270257660u|1u);return;}}
c.pc=270257603u;}
static void b_101bcdc2(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{if(cond(c,2)){c.pc=(270258418u|1u);return;}}
c.pc=270257617u;}
static void b_101bcdc8(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{if(cond(c,2)){c.pc=(270258418u|1u);return;}}
c.pc=270257617u;}
static void b_101bcdd0(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270257631u;c.pc=(270408416u|1u);return;}
c.pc=270257631u;}
static void b_101bcdde(Context& c){
{c.r[14]=270257635u;c.pc=(270408736u|1u);return;}
c.pc=270257635u;}
static void b_101bcde2(Context& c){
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270257643u;c.pc=(270392110u|1u);return;}
c.pc=270257643u;}
static void b_101bcdea(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],shift(c,c.r[0],1,1,false),0,false);c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=((270257654u&~3u)+0u+740u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[2]+0u+0u);uint32_t wb=c.r[2]+52u;c.r[3]=rd<uint32_t>(c,a+0u);c.r[2]=wb;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270257675u;c.pc=c.r[3];return;}
c.pc=270257675u;}
static void b_101bcdf2(Context& c){
{uint32_t a=((270257654u&~3u)+0u+740u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[2]+0u+0u);uint32_t wb=c.r[2]+52u;c.r[3]=rd<uint32_t>(c,a+0u);c.r[2]=wb;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270257675u;c.pc=c.r[3];return;}
c.pc=270257675u;}
static void b_101bcdfc(Context& c){
{uint32_t v=c.r[4];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[2]+0u+0u);uint32_t wb=c.r[2]+52u;c.r[3]=rd<uint32_t>(c,a+0u);c.r[2]=wb;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270257675u;c.pc=c.r[3];return;}
c.pc=270257675u;}
static void b_101bce0a(Context& c){
{uint32_t v=add(c,c.r[5],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270257964u|1u);return;}}
c.pc=270257681u;}
static void b_101bce10(Context& c){
{uint32_t v=add(c,c.r[5],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270258304u|1u);return;}}
c.pc=270257687u;}
static void b_101bce16(Context& c){
{uint32_t v=add(c,c.r[5],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270258304u|1u);return;}}
c.pc=270257693u;}
static void b_101bce1c(Context& c){
{uint32_t v=add(c,c.r[5],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270258304u|1u);return;}}
c.pc=270257699u;}
static void b_101bce22(Context& c){
{uint32_t v=add(c,c.r[5],~(80u),1,true);}
{if(cond(c,1)){c.pc=(270258380u|1u);return;}}
c.pc=270257705u;}
static void b_101bce28(Context& c){
{uint32_t v=add(c,c.r[5],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270258334u|1u);return;}}
c.pc=270257711u;}
static void b_101bce2e(Context& c){
{uint32_t v=add(c,c.r[5],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270258244u|1u);return;}}
c.pc=270257717u;}
static void b_101bce34(Context& c){
{uint32_t v=add(c,c.r[5],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270258220u|1u);return;}}
c.pc=270257723u;}
static void b_101bce3a(Context& c){
{uint32_t v=add(c,c.r[5],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270258220u|1u);return;}}
c.pc=270257729u;}
static void b_101bce40(Context& c){
{c.r[14]=270257733u;c.pc=(270394904u|1u);return;}
c.pc=270257733u;}
static void b_101bce44(Context& c){
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(270u),1,true);}
{c.r[7]=sbits(c,15);}
{uint32_t v=c.r[0];c.r[10]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{if(cond(c,2)){c.pc=(270257766u|1u);return;}}
c.pc=270257757u;}
static void b_101bce5c(Context& c){
{c.r[14]=270257761u;c.pc=(270392110u|1u);return;}
c.pc=270257761u;}
static void b_101bce60(Context& c){
{uint32_t v=add(c,c.r[7],~(shift(c,c.r[0],1,3,false)),1,false);c.r[7]=v;}
{c.pc=(270257774u|1u);return;}
c.pc=270257767u;}
static void b_101bce66(Context& c){
{c.r[14]=270257771u;c.pc=(270392110u|1u);return;}
c.pc=270257771u;}
static void b_101bce6a(Context& c){
{uint32_t v=add(c,c.r[7],shift(c,c.r[0],1,3,false),0,false);c.r[7]=v;}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+116u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[10];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[7];c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[3]=sbits(c,15);}
{c.r[14]=270257809u;c.pc=(270396960u|1u);return;}
c.pc=270257809u;}
static void b_101bce6e(Context& c){
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+116u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[10];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[7];c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[3]=sbits(c,15);}
{c.r[14]=270257809u;c.pc=(270396960u|1u);return;}
c.pc=270257809u;}
static void b_101bce90(Context& c){
{uint32_t v=c.r[0];c.r[10]=v;}
{if(c.r[0] == 0){c.pc=(270257898u|1u);return;}}
c.pc=270257813u;}
static void b_101bce94(Context& c){
{uint32_t v=64u;nz(c,v);c.r[1]=v;}
{c.r[14]=270257819u;c.pc=(270393608u|1u);return;}
c.pc=270257819u;}
static void b_101bce9a(Context& c){
{if(c.r[0] != 0){c.pc=(270257898u|1u);return;}}
c.pc=270257821u;}
static void b_101bce9c(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[10]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(270u),1,true);}
{uint32_t a=(c.r[4]+0u+52u);c.r[3]=rd<uint32_t>(c,a+0u);}
{if(cond(c,2)){c.pc=(270257860u|1u);return;}}
c.pc=270257835u;}
static void b_101bceaa(Context& c){
{uint32_t v=add(c,c.r[7],~(c.r[3]),1,true);c.r[7]=v;}
{setsbits(c,13,c.r[7]);}
{setfs(c,14,int32_t(sbits(c,13)));}
{fcmp(c,fs(c,15),fs(c,14));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,14)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{c.pc=(270257884u|1u);return;}
c.pc=270257861u;}
static void b_101bcec4(Context& c){
{uint32_t v=add(c,c.r[7],c.r[3],0,false);c.r[7]=v;}
{setsbits(c,13,c.r[7]);}
{setfs(c,14,int32_t(sbits(c,13)));}
{fcmp(c,fs(c,15),fs(c,14));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,6)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,5)){uint32_t v=1u;c.r[3]=v;}}
{if(c.r[3] == 0){c.pc=(270257898u|1u);return;}}
c.pc=270257887u;}
static void b_101bcedc(Context& c){
{if(c.r[3] == 0){c.pc=(270257898u|1u);return;}}
c.pc=270257887u;}
static void b_101bcede(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=40u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[14]=270257897u;c.pc=(270391848u|1u);return;}
c.pc=270257897u;}
static void b_101bcee8(Context& c){
{c.pc=(270258472u|1u);return;}
c.pc=270257899u;}
static void b_101bceea(Context& c){
{uint32_t v=add(c,c.r[5],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270258272u|1u);return;}}
c.pc=270257905u;}
static void b_101bcef0(Context& c){
{if(cond(c,13)){c.pc=(270257934u|1u);return;}}
c.pc=270257907u;}
static void b_101bcef2(Context& c){
{uint32_t v=add(c,c.r[5],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270257976u|1u);return;}}
c.pc=270257911u;}
static void b_101bcef6(Context& c){
{if(cond(c,13)){c.pc=(270257920u|1u);return;}}
c.pc=270257913u;}
static void b_101bcef8(Context& c){
{uint32_t v=add(c,c.r[5],~(10u),1,true);}
{if(cond(c,2)){c.pc=(270258380u|1u);return;}}
c.pc=270257919u;}
static void b_101bcefe(Context& c){
{c.pc=(270257964u|1u);return;}
c.pc=270257921u;}
static void b_101bcf00(Context& c){
{uint32_t v=add(c,c.r[5],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270258220u|1u);return;}}
c.pc=270257927u;}
static void b_101bcf06(Context& c){
{uint32_t v=add(c,c.r[5],~(50u),1,true);}
{if(cond(c,2)){c.pc=(270258380u|1u);return;}}
c.pc=270257933u;}
static void b_101bcf0c(Context& c){
{c.pc=(270258244u|1u);return;}
c.pc=270257935u;}
static void b_101bcf0e(Context& c){
{uint32_t v=add(c,c.r[5],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270258304u|1u);return;}}
c.pc=270257941u;}
static void b_101bcf14(Context& c){
{if(cond(c,13)){c.pc=(270257950u|1u);return;}}
c.pc=270257943u;}
static void b_101bcf16(Context& c){
{uint32_t v=add(c,c.r[5],~(100u),1,true);}
{if(cond(c,2)){c.pc=(270258380u|1u);return;}}
c.pc=270257949u;}
static void b_101bcf1c(Context& c){
{c.pc=(270258304u|1u);return;}
c.pc=270257951u;}
static void b_101bcf1e(Context& c){
{uint32_t v=add(c,c.r[5],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270258304u|1u);return;}}
c.pc=270257957u;}
static void b_101bcf24(Context& c){
{uint32_t v=add(c,c.r[5],~(140u),1,true);}
{if(cond(c,2)){c.pc=(270258380u|1u);return;}}
c.pc=270257963u;}
static void b_101bcf2a(Context& c){
{c.pc=(270258334u|1u);return;}
c.pc=270257965u;}
static void b_101bcf2c(Context& c){
{uint32_t v=add(c,c.r[6],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270258380u|1u);return;}}
c.pc=270257971u;}
static void b_101bcf32(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270258278u|1u);return;}
c.pc=270257977u;}
static void b_101bcf38(Context& c){
{if(c.r[6] != 0){c.pc=(270258044u|1u);return;}}
c.pc=270257979u;}
static void b_101bcf3a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270257991u;c.pc=(270393366u|1u);return;}
c.pc=270257991u;}
static void b_101bcf46(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270258380u|1u);return;}}
c.pc=270257999u;}
static void b_101bcf4e(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=5u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270258011u;c.pc=c.r[3];return;}
c.pc=270258011u;}
static void b_101bcf5a(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+20u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{uint32_t v=0u;c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{}
{if(cond(c,2)){setfs(c,15,-(fs(c,15)));}}
{c.r[1]=sbits(c,15);}
{c.r[14]=270258043u;c.pc=(270392848u|1u);return;}
c.pc=270258043u;}
static void b_101bcf7a(Context& c){
{c.pc=(270258052u|1u);return;}
c.pc=270258045u;}
static void b_101bcf7c(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270258380u|1u);return;}}
c.pc=270258053u;}
static void b_101bcf84(Context& c){
{c.r[14]=270258057u;c.pc=(270408416u|1u);return;}
c.pc=270258057u;}
static void b_101bcf88(Context& c){
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[1]=sbits(c,15);}
{uint32_t v=c.r[0];c.r[6]=v;}
{c.r[14]=270258077u;c.pc=(270408818u|1u);return;}
c.pc=270258077u;}
static void b_101bcf9c(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270258085u;c.pc=(269977976u|1u);return;}
c.pc=270258085u;}
static void b_101bcfa4(Context& c){
{if(c.r[0] == 0){c.pc=(270258138u|1u);return;}}
c.pc=270258087u;}
static void b_101bcfa6(Context& c){
{c.r[14]=270258091u;c.pc=(270394904u|1u);return;}
c.pc=270258091u;}
static void b_101bcfaa(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270258099u;c.pc=(270398272u|1u);return;}
c.pc=270258099u;}
static void b_101bcfb2(Context& c){
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[1]=sbits(c,15);}
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[6];c.r[0]=v;}
{c.r[14]=270258121u;c.pc=(270408818u|1u);return;}
c.pc=270258121u;}
static void b_101bcfc8(Context& c){
{uint32_t a=(c.r[5]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[1]=sbits(c,15);}
{c.r[14]=270258137u;c.pc=(269745118u|1u);return;}
c.pc=270258137u;}
static void b_101bcfd8(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=add(c,c.r[5],~(190u),1,true);c.r[5]=v;}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{setsbits(c,14,c.r[5]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{setfs(c,12,(fs(c,15))-(fs(c,13)));}
{setfs(c,14,8.0);}
{setfs(c,12,std::fabs(fs(c,12)));}
{fcmp(c,fs(c,12),fs(c,14));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,14)){c.pc=(270258210u|1u);return;}}
c.pc=270258175u;}
static void b_101bcfda(Context& c){
{uint32_t v=add(c,c.r[5],~(190u),1,true);c.r[5]=v;}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{setsbits(c,14,c.r[5]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{setfs(c,12,(fs(c,15))-(fs(c,13)));}
{setfs(c,14,8.0);}
{setfs(c,12,std::fabs(fs(c,12)));}
{fcmp(c,fs(c,12),fs(c,14));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,14)){c.pc=(270258210u|1u);return;}}
c.pc=270258175u;}
static void b_101bcffe(Context& c){
{fcmp(c,fs(c,15),fs(c,13));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{setfs(c,15,-8.0);}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,14)){c.r[1]=sbits(c,15);}}
{if(cond(c,13)){c.r[1]=sbits(c,14);}}
{c.r[14]=270258209u;c.pc=(270392910u|1u);return;}
c.pc=270258209u;}
static void b_101bd020(Context& c){
{c.pc=(270258380u|1u);return;}
c.pc=270258211u;}
static void b_101bd022(Context& c){
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.pc=(270258380u|1u);return;}
c.pc=270258221u;}
static void b_101bd02c(Context& c){
{if(c.r[6] != 0){c.pc=(270258228u|1u);return;}}
c.pc=270258223u;}
static void b_101bd02e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{c.pc=(270258278u|1u);return;}
c.pc=270258229u;}
static void b_101bd034(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270258364u|1u);return;}}
c.pc=270258237u;}
static void b_101bd03c(Context& c){
{uint32_t v=c.r[9];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.pc=(270258266u|1u);return;}
c.pc=270258245u;}
static void b_101bd044(Context& c){
{if(c.r[6] != 0){c.pc=(270258252u|1u);return;}}
c.pc=270258247u;}
static void b_101bd046(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270258278u|1u);return;}
c.pc=270258253u;}
static void b_101bd04c(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270258380u|1u);return;}}
c.pc=270258261u;}
static void b_101bd054(Context& c){
{uint32_t v=c.r[9];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=50u;nz(c,v);c.r[2]=v;}
{c.r[14]=270258271u;c.pc=(269980032u|1u);return;}
c.pc=270258271u;}
static void b_101bd05a(Context& c){
{c.r[14]=270258271u;c.pc=(269980032u|1u);return;}
c.pc=270258271u;}
static void b_101bd05e(Context& c){
{c.pc=(270258380u|1u);return;}
c.pc=270258273u;}
static void b_101bd060(Context& c){
{if(c.r[6] != 0){c.pc=(270258288u|1u);return;}}
c.pc=270258275u;}
static void b_101bd062(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270258287u;c.pc=(270393366u|1u);return;}
c.pc=270258287u;}
static void b_101bd066(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270258287u;c.pc=(270393366u|1u);return;}
c.pc=270258287u;}
static void b_101bd06e(Context& c){
{c.pc=(270258380u|1u);return;}
c.pc=270258289u;}
static void b_101bd070(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{if(c.r[2] != 0){c.pc=(270258380u|1u);return;}}
c.pc=270258295u;}
static void b_101bd076(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.r[14]=270258303u;c.pc=(270391848u|1u);return;}
c.pc=270258303u;}
static void b_101bd07e(Context& c){
{c.pc=(270258380u|1u);return;}
c.pc=270258305u;}
static void b_101bd080(Context& c){
{if(c.r[6] != 0){c.pc=(270258314u|1u);return;}}
c.pc=270258307u;}
static void b_101bd082(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.pc=(270258464u|1u);return;}
c.pc=270258315u;}
static void b_101bd08a(Context& c){
{uint32_t v=c.r[9];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270258323u;c.pc=(270118736u|1u);return;}
c.pc=270258323u;}
static void b_101bd092(Context& c){
{if(c.r[0] == 0){c.pc=(270258350u|1u);return;}}
c.pc=270258325u;}
static void b_101bd094(Context& c){
{uint32_t a=(c.r[4]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(13u),1,true);}
{if(cond(c,2)){c.pc=(270258350u|1u);return;}}
c.pc=270258333u;}
static void b_101bd09c(Context& c){
{c.pc=(270258458u|1u);return;}
c.pc=270258335u;}
static void b_101bd09e(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270258472u|1u);return;}}
c.pc=270258343u;}
static void b_101bd0a6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270258349u;c.pc=(270391404u|1u);return;}
c.pc=270258349u;}
static void b_101bd0ac(Context& c){
{c.pc=(270258472u|1u);return;}
c.pc=270258351u;}
static void b_101bd0ae(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{if(c.r[2] != 0){c.pc=(270258364u|1u);return;}}
c.pc=270258357u;}
static void b_101bd0b4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.r[14]=270258365u;c.pc=(270391848u|1u);return;}
c.pc=270258365u;}
static void b_101bd0bc(Context& c){
{uint32_t v=add(c,c.r[5],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270258472u|1u);return;}}
c.pc=270258369u;}
static void b_101bd0c0(Context& c){
{uint32_t v=add(c,c.r[5],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270258472u|1u);return;}}
c.pc=270258373u;}
static void b_101bd0c4(Context& c){
{uint32_t v=add(c,c.r[5],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270258472u|1u);return;}}
c.pc=270258377u;}
static void b_101bd0c8(Context& c){
{uint32_t v=add(c,c.r[5],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270258472u|1u);return;}}
c.pc=270258381u;}
static void b_101bd0cc(Context& c){
{uint32_t v=c.r[9];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270258389u;c.pc=(270257372u|1u);return;}
c.pc=270258389u;}
static void b_101bd0d4(Context& c){
{c.pc=(270258472u|1u);return;}
c.pc=270258391u;}
static void b_101bd0dc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270258409u;c.pc=(270393366u|1u);return;}
c.pc=270258409u;}
static void b_101bd0e8(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270257608u|1u);return;}}
c.pc=270258417u;}
static void b_101bd0f0(Context& c){
{c.pc=(270257660u|1u);return;}
c.pc=270258419u;}
static void b_101bd0f2(Context& c){
{c.r[14]=270258423u;c.pc=(270408416u|1u);return;}
c.pc=270258423u;}
static void b_101bd0f6(Context& c){
{c.r[14]=270258427u;c.pc=(270408736u|1u);return;}
c.pc=270258427u;}
static void b_101bd0fa(Context& c){
{setsbits(c,13,c.r[0]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{setfs(c,15,int32_t(sbits(c,13)));}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.r[14]=270258449u;c.pc=(270392110u|1u);return;}
c.pc=270258449u;}
static void b_101bd110(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=shift(c,c.r[0],1u,1,true);nz(c,v);c.r[0]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[0]),1,true);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270257650u|1u);return;}
c.pc=270258459u;}
static void b_101bd11a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=18u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270258471u;c.pc=(270393366u|1u);return;}
c.pc=270258471u;}
static void b_101bd120(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270258471u;c.pc=(270393366u|1u);return;}
c.pc=270258471u;}
static void b_101bd126(Context& c){
{c.pc=(270258364u|1u);return;}
c.pc=270258473u;}
static void b_101bd128(Context& c){
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270258479u;}
static void b_101bd130(Context& c){
{uint32_t a=c.r[13]-36u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[11]);wr<uint32_t>(c,a+32u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-24u;wr<uint64_t>(c,a+0u,c.d[8]);wr<uint64_t>(c,a+8u,c.d[9]);wr<uint64_t>(c,a+16u,c.d[10]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[4]=v;}
{uint32_t a=((270258494u&~3u)+0u+468u);setsbits(c,18,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[13],~(36u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[5]=v;}
{c.r[14]=270258505u;c.pc=(270392110u|1u);return;}
c.pc=270258505u;}
static void b_101bd148(Context& c){
{uint32_t v=0u;nz(c,v);c.r[6]=v;}
{uint32_t v=4294967295u;c.r[7]=v;}
{uint32_t v=65284u;c.r[8]=v;}
{setfs(c,21,-16.0);}
{uint32_t a=((270258522u&~3u)+0u+444u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{setfs(c,17,-10.0);}
{setfs(c,20,16.0);}
{uint32_t v=c.r[0];c.r[10]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270258539u;c.pc=(270392138u|1u);return;}
c.pc=270258539u;}
static void b_101bd16a(Context& c){
{uint32_t v=c.r[10];c.r[2]=v;}
{uint32_t v=c.r[6];c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{setfs(c,19,-8.0);}
{uint32_t v=c.r[0];c.r[11]=v;}
{uint32_t v=shift(c,c.r[0],1u,3,false);c.r[9]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270258567u;c.pc=(270015700u|1u);return;}
c.pc=270258567u;}
static void b_101bd186(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=5u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270258585u;c.pc=(270015700u|1u);return;}
c.pc=270258585u;}
static void b_101bd198(Context& c){
{uint32_t v=add(c,0u,~(c.r[10]),1,false);c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270258605u;c.pc=(270015700u|1u);return;}
c.pc=270258605u;}
static void b_101bd1ac(Context& c){
{uint32_t v=shift(c,c.r[10],1u,3,false);c.r[12]=v;}
{uint32_t v=add(c,0u,~(c.r[9]),1,false);c.r[10]=v;}
{uint32_t v=add(c,c.r[12],10u,0,false);c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[10];c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[12]);}
{c.r[14]=270258637u;c.pc=(270015700u|1u);return;}
c.pc=270258637u;}
static void b_101bd1cc(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[12]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[10];c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=~(9u);c.r[2]=v;}
{uint32_t v=add(c,c.r[2],~(c.r[12]),1,false);c.r[2]=v;}
{uint32_t v=shift(c,c.r[11],2u,3,false);c.r[6]=v;}
{c.r[14]=270258669u;c.pc=(270015700u|1u);return;}
c.pc=270258669u;}
static void b_101bd1ec(Context& c){
{uint32_t a=(c.r[5]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=8u;c.r[11]=v;}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,2)){uint32_t v=c.r[7];c.r[10]=v;}}
{if(cond(c,1)){uint32_t v=1u;c.r[10]=v;}}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270258691u;c.pc=(270082278u|1u);return;}
c.pc=270258691u;}
static void b_101bd1fc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270258691u;c.pc=(270082278u|1u);return;}
c.pc=270258691u;}
static void b_101bd202(Context& c){
{uint32_t v=c.r[0];c.r[8]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270258699u;c.pc=(270082278u|1u);return;}
c.pc=270258699u;}
static void b_101bd20a(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[8];c.r[0]=v;}
{c.r[14]=270258709u;c.pc=(270697604u|1u);return;}
c.pc=270258709u;}
static void b_101bd214(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=0u;c.r[8]=v;}
{uint32_t v=1u;nz(c,v);c.r[7]=v;}
{uint32_t v=add(c,c.r[1],~(130u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270258731u;c.pc=(270697604u|1u);return;}
c.pc=270258731u;}
static void b_101bd22a(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,21));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=shift(c,c.r[1],1u,1,true);nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);c.r[3]=v;}
{c.r[14]=270258767u;c.pc=(270091396u|1u);return;}
c.pc=270258767u;}
static void b_101bd24e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270258773u;c.pc=(270082278u|1u);return;}
c.pc=270258773u;}
static void b_101bd254(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270258783u;c.pc=(270082278u|1u);return;}
c.pc=270258783u;}
static void b_101bd25e(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270258797u;c.pc=(270697604u|1u);return;}
c.pc=270258797u;}
static void b_101bd26c(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],30u,0,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270258815u;c.pc=(270697604u|1u);return;}
c.pc=270258815u;}
static void b_101bd27e(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,20));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=shift(c,c.r[1],(c.r[7]&255u),1,false);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);c.r[3]=v;}
{c.r[14]=270258853u;c.pc=(270082284u|1u);return;}
c.pc=270258853u;}
static void b_101bd2a4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270258859u;c.pc=(270082278u|1u);return;}
c.pc=270258859u;}
static void b_101bd2aa(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270258869u;c.pc=(270082278u|1u);return;}
c.pc=270258869u;}
static void b_101bd2b4(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270258883u;c.pc=(270697604u|1u);return;}
c.pc=270258883u;}
static void b_101bd2c2(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(50u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270258901u;c.pc=(270697604u|1u);return;}
c.pc=270258901u;}
static void b_101bd2d4(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,19));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=shift(c,c.r[1],(c.r[7]&255u),1,false);c.r[3]=v;}
{uint32_t v=1090519040u;c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270258941u;c.pc=(270082284u|1u);return;}
c.pc=270258941u;}
static void b_101bd2fc(Context& c){
{uint32_t v=add(c,c.r[11],~(1u),1,true);c.r[11]=v;}
{if(cond(c,2)){c.pc=(270258684u|1u);return;}}
c.pc=270258949u;}
static void b_101bd304(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.d[10]=rd<uint64_t>(c,a+16u);c.r[13]=a+24u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);uint32_t newpc=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;c.pc=newpc;return;}
c.pc=270258959u;}
static void b_101bd318(Context& c){
{uint32_t a=c.r[13]-28u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[14]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(28u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[3];c.r[5]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[2];c.r[6]=v;}
{c.r[14]=270258987u;c.pc=(270326600u|1u);return;}
c.pc=270258987u;}
static void b_101bd32a(Context& c){
{uint32_t v=add(c,c.r[0],18432u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(5u),1,true);c.r[3]=v;}
{uint32_t v=add(c,0u,~(c.r[3]),1,true);c.r[8]=v;}
{uint32_t v=add(c,c.r[8],c.r[3],c.c,true);c.r[8]=v;}
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270259054u|1u);return;}}
c.pc=270259007u;}
static void b_101bd33e(Context& c){
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[2]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[2]+0u+4294967292u);uint32_t wb=a;wr<uint32_t>(c,a+0u,c.r[3]);c.r[2]=wb;}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270259023u;c.pc=c.r[3];return;}
c.pc=270259023u;}
static void b_101bd34e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270259029u;c.pc=(270392110u|1u);return;}
c.pc=270259029u;}
static void b_101bd354(Context& c){
{uint32_t a=(c.r[13]+0u+20u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],c.r[3],0,true);c.r[0]=v;}
{}
{if(cond(c,2)){uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[0]);}}
{if(cond(c,1)){uint32_t v=1u;c.r[3]=v;}}
{if(cond(c,1)){uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}}
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270259060u|1u);return;}}
c.pc=270259047u;}
static void b_101bd366(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270259055u;c.pc=(269976986u|1u);return;}
c.pc=270259055u;}
static void b_101bd36e(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270259162u|1u);return;}}
c.pc=270259061u;}
static void b_101bd374(Context& c){
{c.r[14]=270259065u;c.pc=(270394904u|1u);return;}
c.pc=270259065u;}
static void b_101bd378(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[3])^(1u);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],14u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[0]+shift(c,c.r[3],2,1,false)+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{if(c.r[3] == 0){c.pc=(270259146u|1u);return;}}
c.pc=270259079u;}
static void b_101bd386(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+28u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[3]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[2],~(90u),1,true);}
{setfs(c,13,int32_t(sbits(c,13)));}
{if(cond(c,2)){c.pc=(270259120u|1u);return;}}
c.pc=270259101u;}
static void b_101bd39c(Context& c){
{setfs(c,14,(fs(c,13))+(fs(c,14)));}
{fcmp(c,fs(c,14),fs(c,15));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,14)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{c.pc=(270259138u|1u);return;}
c.pc=270259121u;}
static void b_101bd3b0(Context& c){
{setfs(c,14,(fs(c,14))-(fs(c,13)));}
{fcmp(c,fs(c,14),fs(c,15));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,6)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,5)){uint32_t v=1u;c.r[3]=v;}}
{if(c.r[3] == 0){c.pc=(270259146u|1u);return;}}
c.pc=270259141u;}
static void b_101bd3c2(Context& c){
{if(c.r[3] == 0){c.pc=(270259146u|1u);return;}}
c.pc=270259141u;}
static void b_101bd3c4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.pc=(270259158u|1u);return;}
c.pc=270259147u;}
static void b_101bd3ca(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270259153u;c.pc=(269976978u|1u);return;}
c.pc=270259153u;}
static void b_101bd3d0(Context& c){
{if(c.r[0] == 0){c.pc=(270259162u|1u);return;}}
c.pc=270259155u;}
static void b_101bd3d2(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{c.r[14]=270259163u;c.pc=(269976968u|1u);return;}
c.pc=270259163u;}
static void b_101bd3d6(Context& c){
{c.r[14]=270259163u;c.pc=(269976968u|1u);return;}
c.pc=270259163u;}
static void b_101bd3da(Context& c){
{uint32_t v=add(c,c.r[6],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270259222u|1u);return;}}
c.pc=270259167u;}
static void b_101bd3de(Context& c){
{if(cond(c,13)){c.pc=(270259194u|1u);return;}}
c.pc=270259169u;}
static void b_101bd3e0(Context& c){
{uint32_t v=add(c,c.r[6],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270259234u|1u);return;}}
c.pc=270259173u;}
static void b_101bd3e4(Context& c){
{if(cond(c,13)){c.pc=(270259184u|1u);return;}}
c.pc=270259175u;}
static void b_101bd3e6(Context& c){
{uint32_t v=add(c,c.r[6],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270259222u|1u);return;}}
c.pc=270259179u;}
static void b_101bd3ea(Context& c){
{uint32_t v=add(c,c.r[6],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270259234u|1u);return;}}
c.pc=270259183u;}
static void b_101bd3ee(Context& c){
{c.pc=(270259546u|1u);return;}
c.pc=270259185u;}
static void b_101bd3f0(Context& c){
{uint32_t v=add(c,c.r[6],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270259270u|1u);return;}}
c.pc=270259189u;}
static void b_101bd3f4(Context& c){
{uint32_t v=add(c,c.r[6],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270259286u|1u);return;}}
c.pc=270259193u;}
static void b_101bd3f8(Context& c){
{c.pc=(270259546u|1u);return;}
c.pc=270259195u;}
static void b_101bd3fa(Context& c){
{uint32_t v=add(c,c.r[6],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270259364u|1u);return;}}
c.pc=270259199u;}
static void b_101bd3fe(Context& c){
{if(cond(c,13)){c.pc=(270259210u|1u);return;}}
c.pc=270259201u;}
static void b_101bd400(Context& c){
{uint32_t v=add(c,c.r[6],~(80u),1,true);}
{if(cond(c,1)){c.pc=(270259314u|1u);return;}}
c.pc=270259205u;}
static void b_101bd404(Context& c){
{uint32_t v=add(c,c.r[6],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270259364u|1u);return;}}
c.pc=270259209u;}
static void b_101bd408(Context& c){
{c.pc=(270259546u|1u);return;}
c.pc=270259211u;}
static void b_101bd40a(Context& c){
{uint32_t v=add(c,c.r[6],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270259364u|1u);return;}}
c.pc=270259215u;}
static void b_101bd40e(Context& c){
{uint32_t v=add(c,c.r[6],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270259534u|1u);return;}}
c.pc=270259221u;}
static void b_101bd414(Context& c){
{c.pc=(270259546u|1u);return;}
c.pc=270259223u;}
static void b_101bd416(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270259546u|1u);return;}}
c.pc=270259229u;}
static void b_101bd41c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270259276u|1u);return;}
c.pc=270259235u;}
static void b_101bd422(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+108u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270259243u;c.pc=c.r[3];return;}
c.pc=270259243u;}
static void b_101bd42a(Context& c){
{if(c.r[5] != 0){c.pc=(270259262u|1u);return;}}
c.pc=270259245u;}
static void b_101bd42c(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270259257u;c.pc=(270393366u|1u);return;}
c.pc=270259257u;}
static void b_101bd438(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270259270u&~3u)+0u+284u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270259358u|1u);return;}
c.pc=270259271u;}
static void b_101bd43e(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270259270u&~3u)+0u+284u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270259358u|1u);return;}
c.pc=270259271u;}
static void b_101bd446(Context& c){
{if(c.r[5] != 0){c.pc=(270259294u|1u);return;}}
c.pc=270259273u;}
static void b_101bd448(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270259285u;c.pc=(270393366u|1u);return;}
c.pc=270259285u;}
static void b_101bd44c(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270259285u;c.pc=(270393366u|1u);return;}
c.pc=270259285u;}
static void b_101bd454(Context& c){
{c.pc=(270259546u|1u);return;}
c.pc=270259287u;}
static void b_101bd456(Context& c){
{if(c.r[5] != 0){c.pc=(270259294u|1u);return;}}
c.pc=270259289u;}
static void b_101bd458(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270259276u|1u);return;}
c.pc=270259295u;}
static void b_101bd45e(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270259546u|1u);return;}}
c.pc=270259303u;}
static void b_101bd466(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.r[14]=270259313u;c.pc=(269980032u|1u);return;}
c.pc=270259313u;}
static void b_101bd470(Context& c){
{c.pc=(270259546u|1u);return;}
c.pc=270259315u;}
static void b_101bd472(Context& c){
{if(c.r[5] != 0){c.pc=(270259334u|1u);return;}}
c.pc=270259317u;}
static void b_101bd474(Context& c){
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270259329u;c.pc=(270393366u|1u);return;}
c.pc=270259329u;}
static void b_101bd480(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.pc=(270259348u|1u);return;}
c.pc=270259335u;}
static void b_101bd486(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[1]=rd<uint8_t>(c,a+0u);}
{if(c.r[1] != 0){c.pc=(270259352u|1u);return;}}
c.pc=270259341u;}
static void b_101bd48c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270259353u;c.pc=(269975768u|1u);return;}
c.pc=270259353u;}
static void b_101bd494(Context& c){
{c.r[14]=270259353u;c.pc=(269975768u|1u);return;}
c.pc=270259353u;}
static void b_101bd498(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270259363u;c.pc=(269978432u|1u);return;}
c.pc=270259363u;}
static void b_101bd49e(Context& c){
{c.r[14]=270259363u;c.pc=(269978432u|1u);return;}
c.pc=270259363u;}
static void b_101bd4a2(Context& c){
{c.pc=(270259546u|1u);return;}
c.pc=270259365u;}
static void b_101bd4a4(Context& c){
{if(c.r[5] != 0){c.pc=(270259380u|1u);return;}}
c.pc=270259367u;}
static void b_101bd4a6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270259379u;c.pc=(270393366u|1u);return;}
c.pc=270259379u;}
static void b_101bd4b2(Context& c){
{c.pc=(270259400u|1u);return;}
c.pc=270259381u;}
static void b_101bd4b4(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270259400u|1u);return;}}
c.pc=270259387u;}
static void b_101bd4ba(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270259395u;c.pc=(270258480u|1u);return;}
c.pc=270259395u;}
static void b_101bd4c2(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270259401u;c.pc=(270391404u|1u);return;}
c.pc=270259401u;}
static void b_101bd4c8(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.r[14]=270259409u;c.pc=(270697604u|1u);return;}
c.pc=270259409u;}
static void b_101bd4d0(Context& c){
{uint32_t v=c.r[1];c.r[6]=v;}
{uint32_t v=add(c,c.r[1],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270259546u|1u);return;}}
c.pc=270259415u;}
static void b_101bd4d6(Context& c){
{c.r[14]=270259419u;c.pc=(269636796u|0u);return;}
c.pc=270259419u;}
static void b_101bd4da(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270259427u;c.pc=(270392110u|1u);return;}
c.pc=270259427u;}
static void b_101bd4e2(Context& c){
{uint32_t v=c.r[0];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270259435u;c.pc=(270697604u|1u);return;}
c.pc=270259435u;}
static void b_101bd4ea(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[9]=v;}
{c.r[14]=270259443u;c.pc=(270392110u|1u);return;}
c.pc=270259443u;}
static void b_101bd4f2(Context& c){
{uint32_t v=add(c,c.r[0],shift(c,c.r[0],31,2,false),0,false);c.r[0]=v;}
{uint32_t v=shift(c,c.r[0],1u,3,false);c.r[8]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270259457u;c.pc=(270392138u|1u);return;}
c.pc=270259457u;}
static void b_101bd500(Context& c){
{uint32_t v=add(c,20u,~(c.r[8]),1,false);c.r[8]=v;}
{uint32_t v=add(c,c.r[8],c.r[9],0,false);c.r[8]=v;}
{uint32_t v=c.r[0];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270259471u;c.pc=(270697604u|1u);return;}
c.pc=270259471u;}
static void b_101bd50e(Context& c){
{uint32_t v=(c.r[5])&(15u);nz(c,v);}
{uint32_t v=65283u;c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],shift(c,c.r[1],31,2,false),0,false);c.r[1]=v;}
{uint32_t v=shift(c,c.r[1],1u,3,false);c.r[3]=v;}
{uint32_t v=65284u;c.r[1]=v;}
{}
{if(cond(c,1)){uint32_t v=c.r[1];c.r[2]=v;}}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(1u);c.r[4]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=(c.r[4])*(c.r[3]);c.r[3]=v;nz(c,v);}
{uint32_t v=4294967295u;c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=shift(c,c.r[8],1u,1,false);c.r[2]=v;}
{c.r[14]=270259523u;c.pc=(270015700u|1u);return;}
c.pc=270259523u;}
static void b_101bd542(Context& c){
{if(c.r[0] == 0){c.pc=(270259546u|1u);return;}}
c.pc=270259525u;}
static void b_101bd544(Context& c){
{uint32_t v=210763776u;c.r[3]=v;}
{uint32_t a=(c.r[0]+0u+240u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270259546u|1u);return;}
c.pc=270259535u;}
static void b_101bd54e(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270259546u|1u);return;}}
c.pc=270259541u;}
static void b_101bd554(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270259547u;c.pc=(270391404u|1u);return;}
c.pc=270259547u;}
static void b_101bd55a(Context& c){
{uint32_t v=add(c,c.r[13],28u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);uint32_t newpc=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;c.pc=newpc;return;}
c.pc=270259553u;}
static void b_101bd564(Context& c){
{uint32_t a=c.r[13]-12u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[14]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(20u),1,false);c.r[13]=v;}
{uint32_t a=(c.r[1]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[5]=v;}
{uint32_t a=(c.r[1]+0u+28u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270259579u;c.pc=c.r[3];return;}
c.pc=270259579u;}
static void b_101bd57a(Context& c){
{uint32_t a=(c.r[4]+0u+277u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=383u;c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[13]+0u+12u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270259601u;c.pc=(270393892u|1u);return;}
c.pc=270259601u;}
static void b_101bd590(Context& c){
{if(c.r[0] == 0){c.pc=(270259610u|1u);return;}}
c.pc=270259603u;}
static void b_101bd592(Context& c){
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[0]+0u+32u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270259619u;c.pc=(269975098u|1u);return;}
c.pc=270259619u;}
static void b_101bd59a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270259619u;c.pc=(269975098u|1u);return;}
c.pc=270259619u;}
static void b_101bd5a2(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270259627u;c.pc=(269975106u|1u);return;}
c.pc=270259627u;}
static void b_101bd5aa(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270259635u;c.pc=(269976968u|1u);return;}
c.pc=270259635u;}
static void b_101bd5b2(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270259643u;c.pc=(269976986u|1u);return;}
c.pc=270259643u;}
static void b_101bd5ba(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270259651u;c.pc=(269975400u|1u);return;}
c.pc=270259651u;}
static void b_101bd5c2(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=2u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270259661u;c.pc=c.r[3];return;}
c.pc=270259661u;}
static void b_101bd5cc(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);uint32_t newpc=rd<uint32_t>(c,a+8u);c.r[13]=a+12u;c.pc=newpc;return;}
c.pc=270259665u;}
static void b_101bd5d0(Context& c){
{uint32_t a=c.r[13]-36u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[11]);wr<uint32_t>(c,a+32u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-24u;wr<uint64_t>(c,a+0u,c.d[8]);wr<uint64_t>(c,a+8u,c.d[9]);wr<uint64_t>(c,a+16u,c.d[10]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[4]=v;}
{uint32_t a=((270259678u&~3u)+0u+468u);setsbits(c,18,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[13],~(36u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[5]=v;}
{c.r[14]=270259689u;c.pc=(270392110u|1u);return;}
c.pc=270259689u;}
static void b_101bd5e8(Context& c){
{uint32_t v=0u;nz(c,v);c.r[6]=v;}
{uint32_t v=4294967295u;c.r[7]=v;}
{uint32_t v=65284u;c.r[8]=v;}
{setfs(c,21,-16.0);}
{uint32_t a=((270259706u&~3u)+0u+444u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{setfs(c,17,-10.0);}
{setfs(c,20,16.0);}
{uint32_t v=c.r[0];c.r[10]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270259723u;c.pc=(270392138u|1u);return;}
c.pc=270259723u;}
static void b_101bd60a(Context& c){
{uint32_t v=c.r[10];c.r[2]=v;}
{uint32_t v=c.r[6];c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{setfs(c,19,-8.0);}
{uint32_t v=c.r[0];c.r[11]=v;}
{uint32_t v=shift(c,c.r[0],1u,3,false);c.r[9]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270259751u;c.pc=(270015700u|1u);return;}
c.pc=270259751u;}
static void b_101bd626(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=5u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270259769u;c.pc=(270015700u|1u);return;}
c.pc=270259769u;}
static void b_101bd638(Context& c){
{uint32_t v=add(c,0u,~(c.r[10]),1,false);c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270259789u;c.pc=(270015700u|1u);return;}
c.pc=270259789u;}
static void b_101bd64c(Context& c){
{uint32_t v=shift(c,c.r[10],1u,3,false);c.r[12]=v;}
{uint32_t v=add(c,0u,~(c.r[9]),1,false);c.r[10]=v;}
{uint32_t v=add(c,c.r[12],10u,0,false);c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[10];c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[12]);}
{c.r[14]=270259821u;c.pc=(270015700u|1u);return;}
c.pc=270259821u;}
static void b_101bd66c(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[12]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[10];c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=~(9u);c.r[2]=v;}
{uint32_t v=add(c,c.r[2],~(c.r[12]),1,false);c.r[2]=v;}
{uint32_t v=shift(c,c.r[11],2u,3,false);c.r[6]=v;}
{c.r[14]=270259853u;c.pc=(270015700u|1u);return;}
c.pc=270259853u;}
static void b_101bd68c(Context& c){
{uint32_t a=(c.r[5]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=8u;c.r[11]=v;}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,2)){uint32_t v=c.r[7];c.r[10]=v;}}
{if(cond(c,1)){uint32_t v=1u;c.r[10]=v;}}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270259875u;c.pc=(270082278u|1u);return;}
c.pc=270259875u;}
static void b_101bd69c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270259875u;c.pc=(270082278u|1u);return;}
c.pc=270259875u;}
static void b_101bd6a2(Context& c){
{uint32_t v=c.r[0];c.r[8]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270259883u;c.pc=(270082278u|1u);return;}
c.pc=270259883u;}
static void b_101bd6aa(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[8];c.r[0]=v;}
{c.r[14]=270259893u;c.pc=(270697604u|1u);return;}
c.pc=270259893u;}
static void b_101bd6b4(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=0u;c.r[8]=v;}
{uint32_t v=1u;nz(c,v);c.r[7]=v;}
{uint32_t v=add(c,c.r[1],~(130u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270259915u;c.pc=(270697604u|1u);return;}
c.pc=270259915u;}
static void b_101bd6ca(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,21));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=shift(c,c.r[1],1u,1,true);nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);c.r[3]=v;}
{c.r[14]=270259951u;c.pc=(270091396u|1u);return;}
c.pc=270259951u;}
static void b_101bd6ee(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270259957u;c.pc=(270082278u|1u);return;}
c.pc=270259957u;}
static void b_101bd6f4(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270259967u;c.pc=(270082278u|1u);return;}
c.pc=270259967u;}
static void b_101bd6fe(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270259981u;c.pc=(270697604u|1u);return;}
c.pc=270259981u;}
static void b_101bd70c(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],30u,0,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270259999u;c.pc=(270697604u|1u);return;}
c.pc=270259999u;}
static void b_101bd71e(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,20));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=shift(c,c.r[1],(c.r[7]&255u),1,false);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);c.r[3]=v;}
{c.r[14]=270260037u;c.pc=(270082284u|1u);return;}
c.pc=270260037u;}
static void b_101bd744(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270260043u;c.pc=(270082278u|1u);return;}
c.pc=270260043u;}
static void b_101bd74a(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270260053u;c.pc=(270082278u|1u);return;}
c.pc=270260053u;}
static void b_101bd754(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270260067u;c.pc=(270697604u|1u);return;}
c.pc=270260067u;}
static void b_101bd762(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(50u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[10])*(c.r[1]);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270260085u;c.pc=(270697604u|1u);return;}
c.pc=270260085u;}
static void b_101bd774(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,19));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=shift(c,c.r[1],(c.r[7]&255u),1,false);c.r[3]=v;}
{uint32_t v=1090519040u;c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[6]),1,true);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270260125u;c.pc=(270082284u|1u);return;}
c.pc=270260125u;}
static void b_101bd79c(Context& c){
{uint32_t v=add(c,c.r[11],~(1u),1,true);c.r[11]=v;}
{if(cond(c,2)){c.pc=(270259868u|1u);return;}}
c.pc=270260133u;}
static void b_101bd7a4(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.d[10]=rd<uint64_t>(c,a+16u);c.r[13]=a+24u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);uint32_t newpc=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;c.pc=newpc;return;}
c.pc=270260143u;}
static void b_101bd7b8(Context& c){
{uint32_t a=c.r[13]-28u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[14]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(28u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[3];c.r[5]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[2];c.r[6]=v;}
{c.r[14]=270260171u;c.pc=(270326600u|1u);return;}
c.pc=270260171u;}
static void b_101bd7ca(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],18432u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+40u);c.r[8]=rd<uint32_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270260206u|1u);return;}}
c.pc=270260183u;}
static void b_101bd7d6(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270260191u;c.pc=(270259556u|1u);return;}
c.pc=270260191u;}
static void b_101bd7de(Context& c){
{uint32_t v=add(c,c.r[8],~(5u),1,true);}
{if(cond(c,2)){c.pc=(270260206u|1u);return;}}
c.pc=270260197u;}
static void b_101bd7e4(Context& c){
{uint32_t v=4u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270260207u;c.pc=(270391404u|1u);return;}
c.pc=270260207u;}
static void b_101bd7ee(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270260364u|1u);return;}}
c.pc=270260213u;}
static void b_101bd7f4(Context& c){
{uint32_t a=(c.r[4]+0u+252u);c.r[5]=rd<uint32_t>(c,a+0u);}
{if(c.r[5] == 0){c.pc=(270260234u|1u);return;}}
c.pc=270260219u;}
static void b_101bd7fa(Context& c){
{uint32_t a=(c.r[5]+0u+100u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270260888u|1u);return;}}
c.pc=270260229u;}
static void b_101bd804(Context& c){
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270260888u|1u);return;}
c.pc=270260235u;}
static void b_101bd80a(Context& c){
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270260245u;c.pc=(269975098u|1u);return;}
c.pc=270260245u;}
static void b_101bd814(Context& c){
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270260253u;c.pc=(269975106u|1u);return;}
c.pc=270260253u;}
static void b_101bd81c(Context& c){
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270260261u;c.pc=(269976968u|1u);return;}
c.pc=270260261u;}
static void b_101bd824(Context& c){
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270260269u;c.pc=(269976986u|1u);return;}
c.pc=270260269u;}
static void b_101bd82c(Context& c){
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270260277u;c.pc=(269975400u|1u);return;}
c.pc=270260277u;}
static void b_101bd834(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[1]);}
{c.r[14]=270260291u;c.pc=(270391848u|1u);return;}
c.pc=270260291u;}
static void b_101bd842(Context& c){
{c.r[14]=270260295u;c.pc=(270408416u|1u);return;}
c.pc=270260295u;}
static void b_101bd846(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270260303u;c.pc=(270392110u|1u);return;}
c.pc=270260303u;}
static void b_101bd84e(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(270u),1,true);}
{uint32_t v=shift(c,c.r[0],1u,3,false);c.r[0]=v;}
{uint32_t v=add(c,0u,~(c.r[0]),1,false);c.r[0]=v;}
{if(cond(c,2)){c.pc=(270260336u|1u);return;}}
c.pc=270260319u;}
static void b_101bd85e(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270260325u;c.pc=(270408736u|1u);return;}
c.pc=270260325u;}
static void b_101bd864(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270260333u;c.pc=(270392110u|1u);return;}
c.pc=270260333u;}
static void b_101bd86c(Context& c){
{uint32_t v=add(c,c.r[5],shift(c,c.r[0],1,3,false),0,false);c.r[0]=v;}
{setsbits(c,14,c.r[0]);}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[3]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270260363u;c.pc=c.r[3];return;}
c.pc=270260363u;}
static void b_101bd870(Context& c){
{setsbits(c,14,c.r[0]);}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[3]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270260363u;c.pc=c.r[3];return;}
c.pc=270260363u;}
static void b_101bd88a(Context& c){
{c.pc=(270260888u|1u);return;}
c.pc=270260365u;}
static void b_101bd88c(Context& c){
{uint32_t a=(c.r[4]+0u+56u);c.r[3]=rd<uint32_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270260402u|1u);return;}}
c.pc=270260369u;}
static void b_101bd890(Context& c){
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[2]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[2]+0u+4294967292u);uint32_t wb=a;wr<uint32_t>(c,a+0u,c.r[3]);c.r[2]=wb;}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270260385u;c.pc=c.r[3];return;}
c.pc=270260385u;}
static void b_101bd8a0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270260391u;c.pc=(270392110u|1u);return;}
c.pc=270260391u;}
static void b_101bd8a6(Context& c){
{uint32_t a=(c.r[13]+0u+20u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],c.r[3],0,true);c.r[0]=v;}
{}
{if(cond(c,2)){uint32_t a=(c.r[4]+0u+56u);wr<uint32_t>(c,a+0u,c.r[0]);}}
{if(cond(c,1)){uint32_t v=1u;c.r[3]=v;}}
{if(cond(c,1)){uint32_t a=(c.r[4]+0u+56u);wr<uint32_t>(c,a+0u,c.r[3]);}}
{c.r[14]=270260407u;c.pc=(270394904u|1u);return;}
c.pc=270260407u;}
static void b_101bd8b2(Context& c){
{c.r[14]=270260407u;c.pc=(270394904u|1u);return;}
c.pc=270260407u;}
static void b_101bd8b6(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[3])^(1u);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],14u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[0]+shift(c,c.r[3],2,1,false)+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{if(c.r[3] == 0){c.pc=(270260488u|1u);return;}}
c.pc=270260421u;}
static void b_101bd8c4(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+56u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[3]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[2],~(90u),1,true);}
{setfs(c,13,int32_t(sbits(c,13)));}
{if(cond(c,2)){c.pc=(270260462u|1u);return;}}
c.pc=270260443u;}
static void b_101bd8da(Context& c){
{setfs(c,14,(fs(c,13))+(fs(c,14)));}
{fcmp(c,fs(c,14),fs(c,15));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,14)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{c.pc=(270260480u|1u);return;}
c.pc=270260463u;}
static void b_101bd8ee(Context& c){
{setfs(c,14,(fs(c,14))-(fs(c,13)));}
{fcmp(c,fs(c,14),fs(c,15));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,6)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,5)){uint32_t v=1u;c.r[3]=v;}}
{if(c.r[3] == 0){c.pc=(270260488u|1u);return;}}
c.pc=270260483u;}
static void b_101bd900(Context& c){
{if(c.r[3] == 0){c.pc=(270260488u|1u);return;}}
c.pc=270260483u;}
static void b_101bd902(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.pc=(270260500u|1u);return;}
c.pc=270260489u;}
static void b_101bd908(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270260495u;c.pc=(269976978u|1u);return;}
c.pc=270260495u;}
static void b_101bd90e(Context& c){
{if(c.r[0] == 0){c.pc=(270260504u|1u);return;}}
c.pc=270260497u;}
static void b_101bd910(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{c.r[14]=270260505u;c.pc=(269976968u|1u);return;}
c.pc=270260505u;}
static void b_101bd914(Context& c){
{c.r[14]=270260505u;c.pc=(269976968u|1u);return;}
c.pc=270260505u;}
static void b_101bd918(Context& c){
{uint32_t v=add(c,c.r[6],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270260564u|1u);return;}}
c.pc=270260509u;}
static void b_101bd91c(Context& c){
{if(cond(c,13)){c.pc=(270260536u|1u);return;}}
c.pc=270260511u;}
static void b_101bd91e(Context& c){
{uint32_t v=add(c,c.r[6],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270260576u|1u);return;}}
c.pc=270260515u;}
static void b_101bd922(Context& c){
{if(cond(c,13)){c.pc=(270260526u|1u);return;}}
c.pc=270260517u;}
static void b_101bd924(Context& c){
{uint32_t v=add(c,c.r[6],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270260564u|1u);return;}}
c.pc=270260521u;}
static void b_101bd928(Context& c){
{uint32_t v=add(c,c.r[6],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270260576u|1u);return;}}
c.pc=270260525u;}
static void b_101bd92c(Context& c){
{c.pc=(270260888u|1u);return;}
c.pc=270260527u;}
static void b_101bd92e(Context& c){
{uint32_t v=add(c,c.r[6],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270260612u|1u);return;}}
c.pc=270260531u;}
static void b_101bd932(Context& c){
{uint32_t v=add(c,c.r[6],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270260628u|1u);return;}}
c.pc=270260535u;}
static void b_101bd936(Context& c){
{c.pc=(270260888u|1u);return;}
c.pc=270260537u;}
static void b_101bd938(Context& c){
{uint32_t v=add(c,c.r[6],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270260706u|1u);return;}}
c.pc=270260541u;}
static void b_101bd93c(Context& c){
{if(cond(c,13)){c.pc=(270260552u|1u);return;}}
c.pc=270260543u;}
static void b_101bd93e(Context& c){
{uint32_t v=add(c,c.r[6],~(80u),1,true);}
{if(cond(c,1)){c.pc=(270260656u|1u);return;}}
c.pc=270260547u;}
static void b_101bd942(Context& c){
{uint32_t v=add(c,c.r[6],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270260706u|1u);return;}}
c.pc=270260551u;}
static void b_101bd946(Context& c){
{c.pc=(270260888u|1u);return;}
c.pc=270260553u;}
static void b_101bd948(Context& c){
{uint32_t v=add(c,c.r[6],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270260706u|1u);return;}}
c.pc=270260557u;}
static void b_101bd94c(Context& c){
{uint32_t v=add(c,c.r[6],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270260876u|1u);return;}}
c.pc=270260563u;}
static void b_101bd952(Context& c){
{c.pc=(270260888u|1u);return;}
c.pc=270260565u;}
static void b_101bd954(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270260888u|1u);return;}}
c.pc=270260571u;}
static void b_101bd95a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270260618u|1u);return;}
c.pc=270260577u;}
static void b_101bd960(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+108u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270260585u;c.pc=c.r[3];return;}
c.pc=270260585u;}
static void b_101bd968(Context& c){
{if(c.r[5] != 0){c.pc=(270260604u|1u);return;}}
c.pc=270260587u;}
static void b_101bd96a(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270260599u;c.pc=(270393366u|1u);return;}
c.pc=270260599u;}
static void b_101bd976(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270260612u&~3u)+0u+284u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270260700u|1u);return;}
c.pc=270260613u;}
static void b_101bd97c(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270260612u&~3u)+0u+284u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270260700u|1u);return;}
c.pc=270260613u;}
static void b_101bd984(Context& c){
{if(c.r[5] != 0){c.pc=(270260636u|1u);return;}}
c.pc=270260615u;}
static void b_101bd986(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270260627u;c.pc=(270393366u|1u);return;}
c.pc=270260627u;}
static void b_101bd98a(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270260627u;c.pc=(270393366u|1u);return;}
c.pc=270260627u;}
static void b_101bd992(Context& c){
{c.pc=(270260888u|1u);return;}
c.pc=270260629u;}
static void b_101bd994(Context& c){
{if(c.r[5] != 0){c.pc=(270260636u|1u);return;}}
c.pc=270260631u;}
static void b_101bd996(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270260618u|1u);return;}
c.pc=270260637u;}
static void b_101bd99c(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270260888u|1u);return;}}
c.pc=270260645u;}
static void b_101bd9a4(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.r[14]=270260655u;c.pc=(269980032u|1u);return;}
c.pc=270260655u;}
static void b_101bd9ae(Context& c){
{c.pc=(270260888u|1u);return;}
c.pc=270260657u;}
static void b_101bd9b0(Context& c){
{if(c.r[5] != 0){c.pc=(270260676u|1u);return;}}
c.pc=270260659u;}
static void b_101bd9b2(Context& c){
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270260671u;c.pc=(270393366u|1u);return;}
c.pc=270260671u;}
static void b_101bd9be(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.pc=(270260690u|1u);return;}
c.pc=270260677u;}
static void b_101bd9c4(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[1]=rd<uint8_t>(c,a+0u);}
{if(c.r[1] != 0){c.pc=(270260694u|1u);return;}}
c.pc=270260683u;}
static void b_101bd9ca(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270260695u;c.pc=(269975768u|1u);return;}
c.pc=270260695u;}
static void b_101bd9d2(Context& c){
{c.r[14]=270260695u;c.pc=(269975768u|1u);return;}
c.pc=270260695u;}
static void b_101bd9d6(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270260705u;c.pc=(269978432u|1u);return;}
c.pc=270260705u;}
static void b_101bd9dc(Context& c){
{c.r[14]=270260705u;c.pc=(269978432u|1u);return;}
c.pc=270260705u;}
static void b_101bd9e0(Context& c){
{c.pc=(270260888u|1u);return;}
c.pc=270260707u;}
static void b_101bd9e2(Context& c){
{if(c.r[5] != 0){c.pc=(270260722u|1u);return;}}
c.pc=270260709u;}
static void b_101bd9e4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270260721u;c.pc=(270393366u|1u);return;}
c.pc=270260721u;}
static void b_101bd9f0(Context& c){
{c.pc=(270260742u|1u);return;}
c.pc=270260723u;}
static void b_101bd9f2(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270260742u|1u);return;}}
c.pc=270260729u;}
static void b_101bd9f8(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270260737u;c.pc=(270259664u|1u);return;}
c.pc=270260737u;}
static void b_101bda00(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270260743u;c.pc=(270391404u|1u);return;}
c.pc=270260743u;}
static void b_101bda06(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.r[14]=270260751u;c.pc=(270697604u|1u);return;}
c.pc=270260751u;}
static void b_101bda0e(Context& c){
{uint32_t v=c.r[1];c.r[6]=v;}
{uint32_t v=add(c,c.r[1],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270260888u|1u);return;}}
c.pc=270260757u;}
static void b_101bda14(Context& c){
{c.r[14]=270260761u;c.pc=(269636796u|0u);return;}
c.pc=270260761u;}
static void b_101bda18(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270260769u;c.pc=(270392110u|1u);return;}
c.pc=270260769u;}
static void b_101bda20(Context& c){
{uint32_t v=c.r[0];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270260777u;c.pc=(270697604u|1u);return;}
c.pc=270260777u;}
static void b_101bda28(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[9]=v;}
{c.r[14]=270260785u;c.pc=(270392110u|1u);return;}
c.pc=270260785u;}
static void b_101bda30(Context& c){
{uint32_t v=add(c,c.r[0],shift(c,c.r[0],31,2,false),0,false);c.r[0]=v;}
{uint32_t v=shift(c,c.r[0],1u,3,false);c.r[8]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270260799u;c.pc=(270392138u|1u);return;}
c.pc=270260799u;}
static void b_101bda3e(Context& c){
{uint32_t v=add(c,20u,~(c.r[8]),1,false);c.r[8]=v;}
{uint32_t v=add(c,c.r[8],c.r[9],0,false);c.r[8]=v;}
{uint32_t v=c.r[0];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270260813u;c.pc=(270697604u|1u);return;}
c.pc=270260813u;}
static void b_101bda4c(Context& c){
{uint32_t v=(c.r[5])&(15u);nz(c,v);}
{uint32_t v=65283u;c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],shift(c,c.r[1],31,2,false),0,false);c.r[1]=v;}
{uint32_t v=shift(c,c.r[1],1u,3,false);c.r[3]=v;}
{uint32_t v=65284u;c.r[1]=v;}
{}
{if(cond(c,1)){uint32_t v=c.r[1];c.r[2]=v;}}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(1u);c.r[4]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=(c.r[4])*(c.r[3]);c.r[3]=v;nz(c,v);}
{uint32_t v=4294967295u;c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=shift(c,c.r[8],1u,1,false);c.r[2]=v;}
{c.r[14]=270260865u;c.pc=(270015700u|1u);return;}
c.pc=270260865u;}
static void b_101bda80(Context& c){
{if(c.r[0] == 0){c.pc=(270260888u|1u);return;}}
c.pc=270260867u;}
static void b_101bda82(Context& c){
{uint32_t v=210763776u;c.r[3]=v;}
{uint32_t a=(c.r[0]+0u+240u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270260888u|1u);return;}
c.pc=270260877u;}
static void b_101bda8c(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270260888u|1u);return;}}
c.pc=270260883u;}
static void b_101bda92(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270260889u;c.pc=(270391404u|1u);return;}
c.pc=270260889u;}
static void b_101bda98(Context& c){
{uint32_t v=add(c,c.r[13],28u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);uint32_t newpc=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;c.pc=newpc;return;}
c.pc=270260895u;}
static void b_101bdaa4(Context& c){
{uint32_t a=c.r[13]-12u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=add(c,c.r[13],~(20u),1,false);c.r[13]=v;}
{c.r[14]=270260911u;c.pc=(270394904u|1u);return;}
c.pc=270260911u;}
static void b_101bdaae(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270260919u;c.pc=(269978260u|1u);return;}
c.pc=270260919u;}
static void b_101bdab6(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{if(c.r[0] != 0){c.pc=(270260966u|1u);return;}}
c.pc=270260923u;}
static void b_101bdaba(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270260935u;c.pc=c.r[3];return;}
c.pc=270260935u;}
static void b_101bdac6(Context& c){
{uint32_t a=(c.r[4]+0u+277u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=395u;c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+12u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270260957u;c.pc=(270393892u|1u);return;}
c.pc=270260957u;}
static void b_101bdadc(Context& c){
{if(c.r[0] == 0){c.pc=(270260966u|1u);return;}}
c.pc=270260959u;}
static void b_101bdade(Context& c){
{uint32_t a=(c.r[4]+0u+240u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[0]+0u+240u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);uint32_t newpc=rd<uint32_t>(c,a+8u);c.r[13]=a+12u;c.pc=newpc;return;}
c.pc=270260971u;}
static void b_101bdae6(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);uint32_t newpc=rd<uint32_t>(c,a+8u);c.r[13]=a+12u;c.pc=newpc;return;}
c.pc=270260971u;}
static void b_101bdaec(Context& c){
{uint32_t a=c.r[13]-28u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+28u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],~(20u),1,false);c.r[13]=v;}
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[2];c.r[7]=v;}
{uint32_t v=c.r[3];c.r[6]=v;}
{if(c.r[1] != 0){c.pc=(270261002u|1u);return;}}
c.pc=270260991u;}
static void b_101bdafe(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=30u;nz(c,v);c.r[2]=v;}
{c.r[14]=270261003u;c.pc=(270393746u|1u);return;}
c.pc=270261003u;}
static void b_101bdb0a(Context& c){
{uint32_t v=add(c,c.r[7],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270261164u|1u);return;}}
c.pc=270261007u;}
static void b_101bdb0e(Context& c){
{if(cond(c,13)){c.pc=(270261034u|1u);return;}}
c.pc=270261009u;}
static void b_101bdb10(Context& c){
{uint32_t v=add(c,c.r[7],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270261102u|1u);return;}}
c.pc=270261013u;}
static void b_101bdb14(Context& c){
{if(cond(c,13)){c.pc=(270261024u|1u);return;}}
c.pc=270261015u;}
static void b_101bdb16(Context& c){
{uint32_t v=add(c,c.r[7],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270261062u|1u);return;}}
c.pc=270261019u;}
static void b_101bdb1a(Context& c){
{uint32_t v=add(c,c.r[7],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270261074u|1u);return;}}
c.pc=270261023u;}
static void b_101bdb1e(Context& c){
{c.pc=(270261826u|1u);return;}
c.pc=270261025u;}
static void b_101bdb20(Context& c){
{uint32_t v=add(c,c.r[7],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270261122u|1u);return;}}
c.pc=270261029u;}
static void b_101bdb24(Context& c){
{uint32_t v=add(c,c.r[7],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270261130u|1u);return;}}
c.pc=270261033u;}
static void b_101bdb28(Context& c){
{c.pc=(270261826u|1u);return;}
c.pc=270261035u;}
static void b_101bdb2a(Context& c){
{uint32_t v=add(c,c.r[7],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270261250u|1u);return;}}
c.pc=270261039u;}
static void b_101bdb2e(Context& c){
{if(cond(c,13)){c.pc=(270261050u|1u);return;}}
c.pc=270261041u;}
static void b_101bdb30(Context& c){
{uint32_t v=add(c,c.r[7],~(80u),1,true);}
{if(cond(c,1)){c.pc=(270261196u|1u);return;}}
c.pc=270261045u;}
static void b_101bdb34(Context& c){
{uint32_t v=add(c,c.r[7],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270261250u|1u);return;}}
c.pc=270261049u;}
static void b_101bdb38(Context& c){
{c.pc=(270261826u|1u);return;}
c.pc=270261051u;}
static void b_101bdb3a(Context& c){
{uint32_t v=add(c,c.r[7],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270261250u|1u);return;}}
c.pc=270261055u;}
static void b_101bdb3e(Context& c){
{uint32_t v=add(c,c.r[7],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270261808u|1u);return;}}
c.pc=270261061u;}
static void b_101bdb44(Context& c){
{c.pc=(270261826u|1u);return;}
c.pc=270261063u;}
static void b_101bdb46(Context& c){
{uint32_t v=add(c,c.r[6],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270261826u|1u);return;}}
c.pc=270261069u;}
static void b_101bdb4c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270261108u|1u);return;}
c.pc=270261075u;}
static void b_101bdb52(Context& c){
{if(c.r[6] != 0){c.pc=(270261094u|1u);return;}}
c.pc=270261077u;}
static void b_101bdb54(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.r[14]=270261089u;c.pc=(270393366u|1u);return;}
c.pc=270261089u;}
static void b_101bdb60(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270261102u&~3u)+0u+732u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270261240u|1u);return;}
c.pc=270261103u;}
static void b_101bdb66(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270261102u&~3u)+0u+732u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270261240u|1u);return;}
c.pc=270261103u;}
static void b_101bdb6e(Context& c){
{if(c.r[6] != 0){c.pc=(270261138u|1u);return;}}
c.pc=270261105u;}
static void b_101bdb70(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[14]=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;}
{c.pc=(270393366u|1u);return;}
c.pc=270261123u;}
static void b_101bdb74(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[14]=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;}
{c.pc=(270393366u|1u);return;}
c.pc=270261123u;}
static void b_101bdb82(Context& c){
{if(c.r[6] != 0){c.pc=(270261138u|1u);return;}}
c.pc=270261125u;}
static void b_101bdb84(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{c.pc=(270261108u|1u);return;}
c.pc=270261131u;}
static void b_101bdb8a(Context& c){
{if(c.r[6] != 0){c.pc=(270261138u|1u);return;}}
c.pc=270261133u;}
static void b_101bdb8c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270261108u|1u);return;}
c.pc=270261139u;}
static void b_101bdb92(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270261826u|1u);return;}}
c.pc=270261149u;}
static void b_101bdb9c(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[7];c.r[2]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[14]=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;}
{c.pc=(269980032u|1u);return;}
c.pc=270261165u;}
static void b_101bdbac(Context& c){
{if(c.r[6] != 0){c.pc=(270261172u|1u);return;}}
c.pc=270261167u;}
static void b_101bdbae(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270261108u|1u);return;}
c.pc=270261173u;}
static void b_101bdbb4(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270261826u|1u);return;}}
c.pc=270261183u;}
static void b_101bdbbe(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[14]=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;}
{c.pc=(270391848u|1u);return;}
c.pc=270261197u;}
static void b_101bdbcc(Context& c){
{if(c.r[6] != 0){c.pc=(270261216u|1u);return;}}
c.pc=270261199u;}
static void b_101bdbce(Context& c){
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270261211u;c.pc=(270393366u|1u);return;}
c.pc=270261211u;}
static void b_101bdbda(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.pc=(270261230u|1u);return;}
c.pc=270261217u;}
static void b_101bdbe0(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[1]=rd<uint8_t>(c,a+0u);}
{if(c.r[1] != 0){c.pc=(270261234u|1u);return;}}
c.pc=270261223u;}
static void b_101bdbe6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270261235u;c.pc=(269975768u|1u);return;}
c.pc=270261235u;}
static void b_101bdbee(Context& c){
{c.r[14]=270261235u;c.pc=(269975768u|1u);return;}
c.pc=270261235u;}
static void b_101bdbf2(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[14]=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;}
{c.pc=(269978432u|1u);return;}
c.pc=270261251u;}
static void b_101bdbf8(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[14]=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;}
{c.pc=(269978432u|1u);return;}
c.pc=270261251u;}
static void b_101bdc02(Context& c){
{uint32_t v=add(c,c.r[6],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270261472u|1u);return;}}
c.pc=270261255u;}
static void b_101bdc06(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270261267u;c.pc=(270393366u|1u);return;}
c.pc=270261267u;}
static void b_101bdc12(Context& c){
{uint32_t v=1u;c.r[9]=v;}
{uint32_t v=65284u;c.r[8]=v;}
{uint32_t v=4294967295u;c.r[7]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=~(39u);c.r[2]=v;}
{uint32_t v=~(179u);c.r[3]=v;}
{c.r[14]=270261305u;c.pc=(270015700u|1u);return;}
c.pc=270261305u;}
static void b_101bdc38(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=40u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=~(159u);c.r[3]=v;}
{c.r[14]=270261329u;c.pc=(270015700u|1u);return;}
c.pc=270261329u;}
static void b_101bdc50(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=~(119u);c.r[3]=v;}
{c.r[14]=270261353u;c.pc=(270015700u|1u);return;}
c.pc=270261353u;}
static void b_101bdc68(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=80u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=~(59u);c.r[3]=v;}
{c.r[14]=270261377u;c.pc=(270015700u|1u);return;}
c.pc=270261377u;}
static void b_101bdc80(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=~(19u);c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=~(39u);c.r[3]=v;}
{c.r[14]=270261403u;c.pc=(270015700u|1u);return;}
c.pc=270261403u;}
static void b_101bdc9a(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=~(79u);c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=50u;nz(c,v);c.r[3]=v;}
{c.r[14]=270261427u;c.pc=(270015700u|1u);return;}
c.pc=270261427u;}
static void b_101bdcb2(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=50u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=30u;nz(c,v);c.r[3]=v;}
{c.r[14]=270261449u;c.pc=(270015700u|1u);return;}
c.pc=270261449u;}
static void b_101bdcc8(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=140u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[6];c.r[3]=v;}
{c.r[14]=270261471u;c.pc=(270015700u|1u);return;}
c.pc=270261471u;}
static void b_101bdcde(Context& c){
{c.pc=(270261706u|1u);return;}
c.pc=270261473u;}
static void b_101bdce0(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[9]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[9],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270261706u|1u);return;}}
c.pc=270261483u;}
static void b_101bdcea(Context& c){
{uint32_t v=1u;c.r[8]=v;}
{uint32_t v=65284u;c.r[7]=v;}
{uint32_t v=4294967295u;c.r[6]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(39u);c.r[2]=v;}
{uint32_t v=~(179u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270261519u;c.pc=(270015700u|1u);return;}
c.pc=270261519u;}
static void b_101bdd0e(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=40u;nz(c,v);c.r[2]=v;}
{uint32_t v=~(159u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270261541u;c.pc=(270015700u|1u);return;}
c.pc=270261541u;}
static void b_101bdd24(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[9];c.r[2]=v;}
{uint32_t v=~(119u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270261563u;c.pc=(270015700u|1u);return;}
c.pc=270261563u;}
static void b_101bdd3a(Context& c){
{uint32_t v=~(119u);c.r[2]=v;}
{uint32_t v=c.r[2];c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270261585u;c.pc=(270015700u|1u);return;}
c.pc=270261585u;}
static void b_101bdd50(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=80u;nz(c,v);c.r[2]=v;}
{uint32_t v=~(59u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270261607u;c.pc=(270015700u|1u);return;}
c.pc=270261607u;}
static void b_101bdd66(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(19u);c.r[2]=v;}
{uint32_t v=~(39u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270261631u;c.pc=(270015700u|1u);return;}
c.pc=270261631u;}
static void b_101bdd7e(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(79u);c.r[2]=v;}
{uint32_t v=50u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270261653u;c.pc=(270015700u|1u);return;}
c.pc=270261653u;}
static void b_101bdd94(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=50u;nz(c,v);c.r[2]=v;}
{uint32_t v=30u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270261673u;c.pc=(270015700u|1u);return;}
c.pc=270261673u;}
static void b_101bdda8(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=140u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270261693u;c.pc=(270015700u|1u);return;}
c.pc=270261693u;}
static void b_101bddbc(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270261701u;c.pc=(270260900u|1u);return;}
c.pc=270261701u;}
static void b_101bddc4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270261707u;c.pc=(270391404u|1u);return;}
c.pc=270261707u;}
static void b_101bddca(Context& c){
{uint32_t a=(c.r[4]+0u+16u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+16u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,13)){c.pc=(270261826u|1u);return;}}
c.pc=270261717u;}
static void b_101bddd4(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270261723u;c.pc=(270082278u|1u);return;}
c.pc=270261723u;}
static void b_101bddda(Context& c){
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.r[14]=270261729u;c.pc=(270697604u|1u);return;}
c.pc=270261729u;}
static void b_101bdde0(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],3u,0,true);c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+16u);wr<uint32_t>(c,a+0u,c.r[1]);}
{c.r[14]=270261739u;c.pc=(270082278u|1u);return;}
c.pc=270261739u;}
static void b_101bddea(Context& c){
{uint32_t v=120u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{c.r[14]=270261747u;c.pc=(270697604u|1u);return;}
c.pc=270261747u;}
static void b_101bddf2(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(60u),1,false);c.r[6]=v;}
{c.r[14]=270261757u;c.pc=(270082278u|1u);return;}
c.pc=270261757u;}
static void b_101bddfc(Context& c){
{uint32_t v=140u;nz(c,v);c.r[1]=v;}
{c.r[14]=270261763u;c.pc=(270697604u|1u);return;}
c.pc=270261763u;}
static void b_101bde02(Context& c){
{uint32_t v=(c.r[7])&(15u);nz(c,v);}
{uint32_t v=65283u;c.r[3]=v;}
{uint32_t v=65284u;c.r[2]=v;}
{}
{if(cond(c,2)){uint32_t v=c.r[3];c.r[2]=v;}}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=shift(c,c.r[1],1u,1,true);nz(c,v);c.r[3]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,40u,~(c.r[3]),1,false);c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[1]);wr<uint32_t>(c,a+4u,c.r[2]);}
{uint32_t v=4294967295u;c.r[2]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=shift(c,c.r[6],1u,1,true);nz(c,v);c.r[2]=v;}
{c.r[14]=270261807u;c.pc=(270015700u|1u);return;}
c.pc=270261807u;}
static void b_101bde2e(Context& c){
{c.pc=(270261826u|1u);return;}
c.pc=270261809u;}
static void b_101bde30(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270261826u|1u);return;}}
c.pc=270261815u;}
static void b_101bde36(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[14]=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;}
{c.pc=(270391404u|1u);return;}
c.pc=270261827u;}
static void b_101bde42(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);uint32_t newpc=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;c.pc=newpc;return;}
c.pc=270261833u;}
static void b_101bde4c(Context& c){
{uint32_t a=(c.r[1]+0u+164u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=1u;nz(c,v);c.r[0]=v;}
{uint32_t v=(c.r[2])|(1u);c.r[2]=v;}
{uint32_t a=(c.r[1]+0u+164u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[3]+0u+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],1u,0,true);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.pc=c.r[14];return;}
c.pc=270261859u;}
static void b_101bde62(Context& c){
{uint32_t a=(c.r[1]+0u+164u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t a=c.r[13]-8u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[14]);c.r[13]=a;}
{uint32_t v=(c.r[0])|(1u);c.r[0]=v;}
{uint32_t a=(c.r[1]+0u+164u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[3]+0u+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],1u,0,true);c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[1]+0u+164u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+shift(c,c.r[0],2,1,false)+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[4])|(c.r[0]);nz(c,v);c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+164u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=(c.r[3]+0u+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],1u,0,true);c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[1]+0u+168u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+shift(c,c.r[0],2,1,false)+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=1u;nz(c,v);c.r[0]=v;}
{uint32_t v=(c.r[4])|(c.r[2]);nz(c,v);c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+168u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=(c.r[3]+0u+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],1u,0,true);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270261923u;}
static void b_101bdea2(Context& c){
{uint32_t v=0u;nz(c,v);c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[1]+0u+164u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[3])|(128u);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+164u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+188u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],1u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+188u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=c.r[14];return;}
c.pc=270261951u;}
static void b_101bdebe(Context& c){
{uint32_t a=(c.r[3]+0u+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],1u,0,true);c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[2]+shift(c,c.r[0],2,1,false)+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{}
{if(cond(c,13)){uint32_t v=add(c,c.r[0],~(c.r[2]),1,false);c.r[0]=v;}}
{if(cond(c,13)){uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[0]);}}
{if(cond(c,14)){uint32_t v=0u;c.r[2]=v;}}
{if(cond(c,14)){uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[2]);}}
{uint32_t a=(c.r[1]+0u+164u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[0]=v;}
{uint32_t v=(c.r[3])|(128u);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+164u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+188u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],1u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+188u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=c.r[14];return;}
c.pc=270262001u;}
static void b_101bdef0(Context& c){
{uint32_t a=(c.r[3]+0u+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t a=c.r[13]-8u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[14]);c.r[13]=a;}
{uint32_t v=add(c,c.r[0],1u,0,true);c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[2]+shift(c,c.r[0],2,1,false)+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+172u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[4])|(c.r[0]);nz(c,v);c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+172u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=(c.r[3]+0u+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],1u,0,true);c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[1]+0u+176u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+shift(c,c.r[0],2,1,false)+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[0]=v;}
{uint32_t v=(c.r[4])|(c.r[2]);nz(c,v);c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+176u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=(c.r[3]+0u+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],2u,0,true);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270262053u;}
static void b_101bdf24(Context& c){
{uint32_t a=(c.r[3]+0u+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t a=c.r[13]-8u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[14]);c.r[13]=a;}
{uint32_t v=add(c,c.r[0],1u,0,true);c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[2]+shift(c,c.r[0],2,1,false)+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+172u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[0])&(~(c.r[4]));c.r[0]=v;}
{uint32_t a=(c.r[1]+0u+172u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[3]+0u+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],1u,0,true);c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[2]+shift(c,c.r[0],2,1,false)+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+176u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[2])&(~(c.r[0]));c.r[2]=v;}
{uint32_t a=(c.r[1]+0u+176u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[3]+0u+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[0]=v;}
{uint32_t v=add(c,c.r[2],2u,0,true);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270262109u;}
static void b_101bdf5c(Context& c){
{uint32_t a=(c.r[3]+0u+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],1u,0,true);c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[2]+shift(c,c.r[0],2,1,false)+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[0]=v;}
{uint32_t a=(c.r[1]+0u+216u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[3]+0u+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],1u,0,true);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.pc=c.r[14];return;}
c.pc=270262133u;}
static void b_101bdf74(Context& c){
{uint32_t a=c.r[13]-12u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[14]);c.r[13]=a;}
{uint32_t a=(c.r[3]+0u+0u);c.r[5]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[5],1u,0,true);c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t v=add(c,c.r[5],2u,0,true);c.r[5]=v;}
{uint32_t a=(c.r[2]+shift(c,c.r[0],2,1,false)+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],shift(c,c.r[0],2,1,false),0,false);c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[0]+0u+4u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=shift(c,c.r[4],12u,1,true);nz(c,v);c.r[0]=v;}
{uint32_t a=(c.r[1]+0u+144u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t v=add(c,c.r[2],~(c.r[4]),1,true);c.r[4]=v;}
{uint32_t v=1u;nz(c,v);c.r[0]=v;}
{uint32_t a=(c.r[1]+0u+220u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t v=4096u;c.r[2]=v;}
{uint32_t a=(c.r[1]+0u+136u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[1]+0u+224u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[3]+0u+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],c.r[0],0,false);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);uint32_t newpc=rd<uint32_t>(c,a+8u);c.r[13]=a+12u;c.pc=newpc;return;}
c.pc=270262189u;}
static void b_101bdfac(Context& c){
{uint32_t a=(c.r[3]+0u+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t a=c.r[13]-16u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[14]);c.r[13]=a;}
{uint32_t v=add(c,c.r[0],1u,0,true);c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[2]+shift(c,c.r[0],2,1,false)+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+112u);c.r[0]=rd<uint32_t>(c,a+0u);}
{if(c.r[0] == 0){c.pc=(270262276u|1u);return;}}
c.pc=270262205u;}
static void b_101bdfbc(Context& c){
{uint32_t a=(c.r[1]+0u+108u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,12)){c.pc=(270262276u|1u);return;}}
c.pc=270262211u;}
static void b_101bdfc2(Context& c){
{uint32_t a=(c.r[0]+0u+176u);c.r[5]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[5]+0u+4u);c.r[6]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(c.r[6]),1,true);}
{if(cond(c,3)){c.pc=(270262276u|1u);return;}}
c.pc=270262221u;}
static void b_101bdfcc(Context& c){
{uint32_t a=(c.r[5]+0u+0u);c.r[5]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[5]+shift(c,c.r[2],2,1,false)+0u);c.r[5]=rd<uint32_t>(c,a+0u);}
{if(c.r[5] == 0){c.pc=(270262276u|1u);return;}}
c.pc=270262229u;}
static void b_101bdfd4(Context& c){
{uint32_t v=shift(c,c.r[4],12u,1,true);nz(c,v);c.r[5]=v;}
{uint32_t a=(c.r[1]+0u+144u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[0]+0u+176u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[0]+0u+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[0]+shift(c,c.r[2],2,1,false)+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+0u+0u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{uint32_t v=add(c,c.r[2],~(c.r[4]),1,true);c.r[4]=v;}
{uint32_t v=4096u;c.r[2]=v;}
{uint32_t a=(c.r[1]+0u+220u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=(c.r[1]+0u+224u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[1]+0u+136u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[3]+0u+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=1u;nz(c,v);c.r[0]=v;}
{uint32_t v=add(c,c.r[2],1u,0,true);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270262287u;}
static void b_101be004(Context& c){
{uint32_t a=(c.r[3]+0u+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=1u;nz(c,v);c.r[0]=v;}
{uint32_t v=add(c,c.r[2],1u,0,true);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270262287u;}
static void b_101be00e(Context& c){
{uint32_t a=c.r[13]-16u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[3];c.r[4]=v;}
{uint32_t a=(c.r[3]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[1];c.r[6]=v;}
{uint32_t v=add(c,c.r[3],1u,0,true);c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+0u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=add(c,c.r[3],2u,0,true);c.r[5]=v;}
{uint32_t v=add(c,c.r[3],3u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[2]+shift(c,c.r[1],2,1,false)+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],shift(c,c.r[1],2,1,false),0,false);c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[1]+0u+4u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+0u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=shift(c,c.r[0],12u,1,true);nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+8u);c.r[5]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(c.r[0]),1,true);c.r[0]=v;}
{uint32_t a=(c.r[6]+0u+144u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{}
{if(cond(c,1)){uint32_t v=4096u;c.r[5]=v;}}
{uint32_t v=shift(c,c.r[0],12u,1,true);nz(c,v);c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270262343u;c.pc=(270697408u|1u);return;}
c.pc=270262343u;}
static void b_101be046(Context& c){
{uint32_t a=(c.r[6]+0u+224u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[6]+0u+220u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t v=1u;nz(c,v);c.r[0]=v;}
{uint32_t a=(c.r[6]+0u+136u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],c.r[0],0,false);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+0u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270262365u;}
static void b_101be05c(Context& c){
{uint32_t a=c.r[13]-24u;wr<uint32_t>(c,a+0u,c.r[3]);wr<uint32_t>(c,a+4u,c.r[4]);wr<uint32_t>(c,a+8u,c.r[5]);wr<uint32_t>(c,a+12u,c.r[6]);wr<uint32_t>(c,a+16u,c.r[7]);wr<uint32_t>(c,a+20u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[3];c.r[5]=v;}
{uint32_t a=(c.r[3]+0u+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=add(c,c.r[0],1u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[5]+0u+0u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[0],2u,0,true);c.r[0]=v;}
{uint32_t a=(c.r[2]+shift(c,c.r[3],2,1,false)+0u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],shift(c,c.r[3],2,1,false),0,false);c.r[3]=v;}
{uint32_t a=(c.r[5]+0u+0u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[3]+0u+4u);c.r[6]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+112u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[6],~(0u),1,true);}
{}
{if(cond(c,1)){uint32_t v=4096u;c.r[6]=v;}}
{if(c.r[2] == 0){c.pc=(270262478u|1u);return;}}
c.pc=270262403u;}
static void b_101be082(Context& c){
{uint32_t a=(c.r[4]+0u+108u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,12)){c.pc=(270262478u|1u);return;}}
c.pc=270262409u;}
static void b_101be088(Context& c){
{uint32_t a=(c.r[2]+0u+176u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[0]+0u+4u);c.r[7]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(c.r[7]),1,true);}
{if(cond(c,3)){c.pc=(270262478u|1u);return;}}
c.pc=270262419u;}
static void b_101be092(Context& c){
{uint32_t a=(c.r[0]+0u+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[0]+shift(c,c.r[3],2,1,false)+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{if(c.r[0] == 0){c.pc=(270262478u|1u);return;}}
c.pc=270262427u;}
static void b_101be09a(Context& c){
{uint32_t v=shift(c,c.r[1],12u,1,true);nz(c,v);c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[2]+0u+176u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+0u+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+shift(c,c.r[3],2,1,false)+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[3]+0u+0u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[3]=sbits(c,15);}
{uint32_t v=add(c,c.r[3],~(c.r[1]),1,true);c.r[0]=v;}
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t v=shift(c,c.r[0],12u,1,true);nz(c,v);c.r[0]=v;}
{c.r[14]=270262465u;c.pc=(270697408u|1u);return;}
c.pc=270262465u;}
static void b_101be0c0(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+224u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[4]+0u+136u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+220u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[5]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=1u;nz(c,v);c.r[0]=v;}
{uint32_t v=add(c,c.r[3],1u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[5]+0u+0u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[3]=rd<uint32_t>(c,a+0u);c.r[4]=rd<uint32_t>(c,a+4u);c.r[5]=rd<uint32_t>(c,a+8u);c.r[6]=rd<uint32_t>(c,a+12u);c.r[7]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270262489u;}
static void b_101be0ce(Context& c){
{uint32_t a=(c.r[5]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=1u;nz(c,v);c.r[0]=v;}
{uint32_t v=add(c,c.r[3],1u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[5]+0u+0u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[3]=rd<uint32_t>(c,a+0u);c.r[4]=rd<uint32_t>(c,a+4u);c.r[5]=rd<uint32_t>(c,a+8u);c.r[6]=rd<uint32_t>(c,a+12u);c.r[7]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270262489u;}
static void b_101be0d8(Context& c){
{uint32_t a=(c.r[3]+0u+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t a=c.r[13]-8u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[14]);c.r[13]=a;}
{uint32_t v=add(c,c.r[0],1u,0,true);c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[2]+shift(c,c.r[0],2,1,false)+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+136u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[3]+0u+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],1u,0,true);c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[2]+shift(c,c.r[0],2,1,false)+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+144u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[3]+0u+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],1u,0,true);c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[1]+0u+164u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+shift(c,c.r[0],2,1,false)+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[4])|(c.r[0]);nz(c,v);c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+164u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=(c.r[3]+0u+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],1u,0,true);c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[1]+0u+168u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+shift(c,c.r[0],2,1,false)+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=1u;nz(c,v);c.r[0]=v;}
{uint32_t v=(c.r[4])|(c.r[2]);nz(c,v);c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+168u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=(c.r[3]+0u+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],1u,0,true);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270262569u;}
static void b_101be128(Context& c){
{uint32_t a=c.r[13]-16u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[14]);c.r[13]=a;}
{uint32_t a=(c.r[3]+0u+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[4],1u,0,true);c.r[5]=v;}
{uint32_t v=add(c,c.r[4],2u,0,true);c.r[6]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=add(c,c.r[4],3u,0,true);c.r[4]=v;}
{uint32_t a=(c.r[2]+shift(c,c.r[5],2,1,false)+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],shift(c,c.r[5],2,1,false),0,false);c.r[5]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[5]+0u+4u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=(c.r[1]+0u+184u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[5]+0u+8u);c.r[2]=rd<uint32_t>(c,a+0u);}
{if(c.r[4] == 0){c.pc=(270262608u|1u);return;}}
c.pc=270262605u;}
static void b_101be14c(Context& c){
{uint32_t v=add(c,0u,~(c.r[0]),1,true);c.r[0]=v;}
{uint32_t v=add(c,0u,~(c.r[2]),1,true);c.r[2]=v;}
{setsbits(c,15,c.r[0]);}
{uint32_t a=((270262616u&~3u)+0u+64u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{setfs(c,13,int32_t(sbits(c,13)));}
{uint32_t v=0u;nz(c,v);c.r[0]=v;}
{setfs(c,12,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[1]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,12))*(fs(c,14))));}
{uint32_t a=(c.r[1]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[1]+0u+64u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[1]+0u+64u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,c.r[2]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[1]+0u+68u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[1]+0u+68u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[3]+0u+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],1u,0,true);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270262679u;}
static void b_101be150(Context& c){
{setsbits(c,15,c.r[0]);}
{uint32_t a=((270262616u&~3u)+0u+64u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{setfs(c,13,int32_t(sbits(c,13)));}
{uint32_t v=0u;nz(c,v);c.r[0]=v;}
{setfs(c,12,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[1]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,12))*(fs(c,14))));}
{uint32_t a=(c.r[1]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[1]+0u+64u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[1]+0u+64u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,c.r[2]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[1]+0u+68u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[1]+0u+68u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[3]+0u+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],1u,0,true);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270262679u;}
static void b_101be19c(Context& c){
{uint32_t a=c.r[13]-16u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[14]);c.r[13]=a;}
{uint32_t a=(c.r[3]+0u+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[4],1u,0,true);c.r[5]=v;}
{uint32_t v=add(c,c.r[4],2u,0,true);c.r[6]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=add(c,c.r[4],3u,0,true);c.r[4]=v;}
{uint32_t a=(c.r[2]+shift(c,c.r[5],2,1,false)+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],shift(c,c.r[5],2,1,false),0,false);c.r[5]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[5]+0u+4u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=(c.r[1]+0u+184u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[5]+0u+8u);c.r[2]=rd<uint32_t>(c,a+0u);}
{if(c.r[4] == 0){c.pc=(270262724u|1u);return;}}
c.pc=270262721u;}
static void b_101be1c0(Context& c){
{uint32_t v=add(c,0u,~(c.r[0]),1,true);c.r[0]=v;}
{uint32_t v=add(c,0u,~(c.r[2]),1,true);c.r[2]=v;}
{setsbits(c,15,c.r[0]);}
{uint32_t v=0u;nz(c,v);c.r[0]=v;}
{setfs(c,14,int32_t(sbits(c,14)));}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=((270262742u&~3u)+0u+44u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,13,(fs(c,13))*(fs(c,15)));}
{setfs(c,14,(fs(c,14))*(fs(c,15)));}
{uint32_t a=(c.r[1]+0u+72u);wr<uint32_t>(c,a+0u,sbits(c,13));}
{setsbits(c,13,c.r[2]);}
{uint32_t a=(c.r[1]+0u+76u);wr<uint32_t>(c,a+0u,sbits(c,14));}
{setfs(c,14,int32_t(sbits(c,13)));}
{setfs(c,15,(fs(c,14))*(fs(c,15)));}
{uint32_t a=(c.r[1]+0u+80u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[3]+0u+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],1u,0,true);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270262783u;}
static void b_101be1c4(Context& c){
{setsbits(c,15,c.r[0]);}
{uint32_t v=0u;nz(c,v);c.r[0]=v;}
{setfs(c,14,int32_t(sbits(c,14)));}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=((270262742u&~3u)+0u+44u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,13,(fs(c,13))*(fs(c,15)));}
{setfs(c,14,(fs(c,14))*(fs(c,15)));}
{uint32_t a=(c.r[1]+0u+72u);wr<uint32_t>(c,a+0u,sbits(c,13));}
{setsbits(c,13,c.r[2]);}
{uint32_t a=(c.r[1]+0u+76u);wr<uint32_t>(c,a+0u,sbits(c,14));}
{setfs(c,14,int32_t(sbits(c,13)));}
{setfs(c,15,(fs(c,14))*(fs(c,15)));}
{uint32_t a=(c.r[1]+0u+80u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[3]+0u+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],1u,0,true);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270262783u;}
static void b_101be204(Context& c){
{uint32_t a=c.r[13]-16u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[14]);c.r[13]=a;}
{uint32_t a=(c.r[3]+0u+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[4],1u,0,true);c.r[5]=v;}
{uint32_t v=add(c,c.r[4],2u,0,true);c.r[6]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=add(c,c.r[4],3u,0,true);c.r[4]=v;}
{uint32_t a=(c.r[2]+shift(c,c.r[5],2,1,false)+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],shift(c,c.r[5],2,1,false),0,false);c.r[5]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[5]+0u+4u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=(c.r[1]+0u+184u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[5]+0u+8u);c.r[2]=rd<uint32_t>(c,a+0u);}
{if(c.r[4] == 0){c.pc=(270262828u|1u);return;}}
c.pc=270262825u;}
static void b_101be228(Context& c){
{uint32_t v=add(c,0u,~(c.r[0]),1,true);c.r[0]=v;}
{uint32_t v=add(c,0u,~(c.r[2]),1,true);c.r[2]=v;}
{setsbits(c,15,c.r[0]);}
{uint32_t a=((270262836u&~3u)+0u+64u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{setfs(c,13,int32_t(sbits(c,13)));}
{uint32_t v=0u;nz(c,v);c.r[0]=v;}
{setfs(c,12,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[1]+0u+84u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,12))*(fs(c,14))));}
{uint32_t a=(c.r[1]+0u+84u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[1]+0u+88u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[1]+0u+88u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,c.r[2]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[1]+0u+92u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[1]+0u+92u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[3]+0u+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],1u,0,true);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270262899u;}
static void b_101be22c(Context& c){
{setsbits(c,15,c.r[0]);}
{uint32_t a=((270262836u&~3u)+0u+64u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{setfs(c,13,int32_t(sbits(c,13)));}
{uint32_t v=0u;nz(c,v);c.r[0]=v;}
{setfs(c,12,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[1]+0u+84u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,12))*(fs(c,14))));}
{uint32_t a=(c.r[1]+0u+84u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[1]+0u+88u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[1]+0u+88u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,c.r[2]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[1]+0u+92u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[1]+0u+92u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[3]+0u+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],1u,0,true);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270262899u;}
static void b_101be278(Context& c){
{uint32_t a=(c.r[3]+0u+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[0]=v;}
{uint32_t v=add(c,c.r[2],2u,0,true);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.pc=c.r[14];return;}
c.pc=270262915u;}
static void b_101be282(Context& c){
{uint32_t a=c.r[13]-8u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[14]);c.r[13]=a;}
{uint32_t a=(c.r[3]+0u+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[4],1u,0,true);c.r[1]=v;}
{uint32_t v=add(c,c.r[4],2u,0,true);c.r[4]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t a=(c.r[2]+shift(c,c.r[1],2,1,false)+0u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[4]);}
{c.r[14]=270262935u;c.pc=(270299588u|1u);return;}
c.pc=270262935u;}
static void b_101be296(Context& c){
{uint32_t v=0u;nz(c,v);c.r[0]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270262939u;}
static void b_101be29a(Context& c){
{uint32_t a=c.r[13]-8u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[3];c.r[4]=v;}
{uint32_t a=(c.r[3]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],1u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+0u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+112u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+shift(c,c.r[3],2,1,false)+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+108u);wr<uint32_t>(c,a+0u,c.r[3]);}
{if(c.r[0] == 0){c.pc=(270262964u|1u);return;}}
c.pc=270262959u;}
static void b_101be2ae(Context& c){
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{c.r[14]=270262965u;c.pc=(269844486u|1u);return;}
c.pc=270262965u;}
static void b_101be2b4(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[0]=v;}
{uint32_t v=add(c,c.r[3],1u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+0u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270262975u;}
static void b_101be2be(Context& c){
{uint32_t a=c.r[13]-8u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[14]);c.r[13]=a;}
{uint32_t a=(c.r[3]+0u+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[4],1u,0,true);c.r[1]=v;}
{uint32_t v=add(c,c.r[4],2u,0,true);c.r[4]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t a=(c.r[2]+shift(c,c.r[1],2,1,false)+0u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[4]);}
{c.r[14]=270262995u;c.pc=(270299592u|1u);return;}
c.pc=270262995u;}
static void b_101be2d2(Context& c){
{uint32_t v=0u;nz(c,v);c.r[0]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270262999u;}
static void b_101be2d8(Context& c){
{uint32_t a=((270263004u&~3u)+0u+192u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],10048u,0,false);c.r[1]=v;}
{uint32_t a=c.r[13]-12u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[14]);c.r[13]=a;}
{uint32_t v=add(c,c.r[2],270263012u,0,false);c.r[2]=v;}
{uint32_t a=((270263014u&~3u)+0u+188u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+12u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+16u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[2]+c.r[4]+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+24u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=((270263026u&~3u)+0u+180u);c.r[5]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+20u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=((270263030u&~3u)+0u+180u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+c.r[4]+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+28u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=((270263038u&~3u)+0u+176u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+c.r[4]+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+40u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+36u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=((270263046u&~3u)+0u+172u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+c.r[4]+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+48u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+44u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=((270263054u&~3u)+0u+168u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+c.r[4]+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+56u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+52u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=((270263062u&~3u)+0u+164u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+c.r[4]+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+60u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t v=add(c,c.r[0],10112u,0,false);c.r[4]=v;}
{uint32_t a=((270263072u&~3u)+0u+156u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+0u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[2]+c.r[1]+0u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+4u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t a=((270263082u&~3u)+0u+152u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+c.r[1]+0u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=add(c,c.r[0],10176u,0,false);c.r[1]=v;}
{uint32_t a=(c.r[1]+0u+0u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[2]+c.r[5]+0u);c.r[5]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+4u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=((270263100u&~3u)+0u+136u);c.r[5]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+c.r[5]+0u);c.r[5]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+16u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+12u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=((270263108u&~3u)+0u+132u);c.r[5]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+c.r[5]+0u);c.r[5]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+52u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=((270263114u&~3u)+0u+132u);c.r[5]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+56u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[2]+c.r[5]+0u);c.r[5]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=((270263124u&~3u)+0u+124u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+c.r[4]+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+60u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t v=add(c,c.r[0],10240u,0,false);c.r[1]=v;}
{uint32_t a=((270263134u&~3u)+0u+120u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],10304u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[1]+0u+0u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[2]+c.r[4]+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+4u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=((270263148u&~3u)+0u+108u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+c.r[4]+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+16u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+12u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=((270263156u&~3u)+0u+104u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+c.r[4]+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+24u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+20u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=((270263164u&~3u)+0u+100u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+c.r[4]+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+28u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=((270263172u&~3u)+0u+96u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+c.r[4]+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+48u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+44u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=((270263180u&~3u)+0u+92u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+c.r[4]+0u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+56u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+52u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t a=((270263188u&~3u)+0u+88u);c.r[4]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[2]+c.r[4]+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+60u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[0]+0u+0u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);uint32_t newpc=rd<uint32_t>(c,a+8u);c.r[13]=a+12u;c.pc=newpc;return;}
c.pc=270263195u;}
static void b_101be3f0(Context& c){
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,12)){c.pc=(270263292u|1u);return;}}
c.pc=270263285u;}
static void b_101be3f4(Context& c){
{uint32_t a=(c.r[1]+0u+124u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+124u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[1]+0u+128u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=c.r[14];return;}
c.pc=270263295u;}
static void b_101be3fc(Context& c){
{c.pc=c.r[14];return;}
c.pc=270263295u;}
static void b_101be3fe(Context& c){
{uint32_t a=c.r[13]-16u;wr<uint32_t>(c,a+0u,c.r[3]);wr<uint32_t>(c,a+4u,c.r[4]);wr<uint32_t>(c,a+8u,c.r[5]);wr<uint32_t>(c,a+12u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[3]+0u+0u);c.r[5]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[5],1u,0,true);c.r[5]=v;}
{uint32_t a=(c.r[3]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t a=(c.r[2]+shift(c,c.r[5],2,1,false)+0u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+128u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270263321u;c.pc=(270263280u|1u);return;}
c.pc=270263321u;}
static void b_101be418(Context& c){
{uint32_t a=(c.r[4]+0u+164u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=2u;nz(c,v);c.r[0]=v;}
{uint32_t v=(c.r[3])|(64u);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+164u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[3]=rd<uint32_t>(c,a+0u);c.r[4]=rd<uint32_t>(c,a+4u);c.r[5]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270263337u;}
static void b_101be428(Context& c){
{uint32_t a=(c.r[1]+0u+64u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+64u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[1]+0u+68u);wr<uint32_t>(c,a+0u,c.r[0]);}
{if(c.r[3] == 0){c.pc=(270263350u|1u);return;}}
c.pc=270263345u;}
static void b_101be430(Context& c){
{uint32_t v=~(1u);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+68u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=c.r[14];return;}
c.pc=270263353u;}
static void b_101be436(Context& c){
{c.pc=c.r[14];return;}
c.pc=270263353u;}
static void b_101be438(Context& c){
{uint32_t a=c.r[13]-16u;wr<uint32_t>(c,a+0u,c.r[3]);wr<uint32_t>(c,a+4u,c.r[4]);wr<uint32_t>(c,a+8u,c.r[5]);wr<uint32_t>(c,a+12u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[2];c.r[5]=v;}
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+16u);c.r[3]=rd<uint8_t>(c,a+0u);}
{c.r[14]=270263369u;c.pc=(270263336u|1u);return;}
c.pc=270263369u;}
static void b_101be448(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=c.r[13];c.r[3]=rd<uint32_t>(c,a+0u);c.r[4]=rd<uint32_t>(c,a+4u);c.r[5]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270265150u|1u);return;}
c.pc=270263381u;}
static void b_101be454(Context& c){
{uint32_t a=(c.r[1]+0u+124u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[1]+0u+128u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+140u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+164u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+220u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[1]+0u+224u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=c.r[14];return;}
c.pc=270263407u;}
static void b_101be470(Context& c){
{uint32_t a=c.r[13]-32u;wr<uint32_t>(c,a+0u,c.r[0]);wr<uint32_t>(c,a+4u,c.r[1]);wr<uint32_t>(c,a+8u,c.r[4]);wr<uint32_t>(c,a+12u,c.r[5]);wr<uint32_t>(c,a+16u,c.r[6]);wr<uint32_t>(c,a+20u,c.r[7]);wr<uint32_t>(c,a+24u,c.r[8]);wr<uint32_t>(c,a+28u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t a=(c.r[1]+0u+124u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[2];c.r[8]=v;}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,12)){c.pc=(270263700u|1u);return;}}
c.pc=270263427u;}
static void b_101be482(Context& c){
{uint32_t a=(c.r[1]+0u+172u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=shift(c,c.r[2],11u,1,true);nz(c,v);c.r[2]=v;}
{if(cond(c,5)){c.pc=(270263700u|1u);return;}}
c.pc=270263437u;}
static void b_101be48c(Context& c){
{uint32_t a=(c.r[1]+0u+128u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(c.r[2]),1,true);}
{if(cond(c,2)){c.pc=(270263484u|1u);return;}}
c.pc=270263445u;}
static void b_101be494(Context& c){
{uint32_t a=(c.r[1]+0u+164u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=shift(c,c.r[3],31u,1,true);nz(c,v);c.r[3]=v;}
{if(cond(c,5)){c.pc=(270263700u|1u);return;}}
c.pc=270263453u;}
static void b_101be49c(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270263468u|1u);return;}}
c.pc=270263459u;}
static void b_101be4a2(Context& c){
{uint32_t a=(c.r[1]+0u+136u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+136u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+136u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,13)){c.pc=(270263700u|1u);return;}}
c.pc=270263477u;}
static void b_101be4ac(Context& c){
{uint32_t a=(c.r[4]+0u+136u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,13)){c.pc=(270263700u|1u);return;}}
c.pc=270263477u;}
static void b_101be4b4(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+164u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270263488u|1u);return;}
c.pc=270263485u;}
void install_29(){register_block(270243439u,b_101b966e);register_block(270243441u,b_101b9670);register_block(270243451u,b_101b967a);register_block(270243455u,b_101b967e);register_block(270243473u,b_101b9690);register_block(270243493u,b_101b96a4);register_block(270243505u,b_101b96b0);register_block(270243525u,b_101b96c4);register_block(270243531u,b_101b96ca);register_block(270243537u,b_101b96d0);register_block(270243541u,b_101b96d4);register_block(270243545u,b_101b96d8);register_block(270243563u,b_101b96ea);register_block(270243567u,b_101b96ee);register_block(270243573u,b_101b96f4);register_block(270243579u,b_101b96fa);register_block(270243585u,b_101b9700);register_block(270243591u,b_101b9706);register_block(270243597u,b_101b970c);register_block(270243603u,b_101b9712);register_block(270243615u,b_101b971e);register_block(270243621u,b_101b9724);register_block(270243627u,b_101b972a);register_block(270243631u,b_101b972e);register_block(270243651u,b_101b9742);register_block(270243657u,b_101b9748);register_block(270243659u,b_101b974a);register_block(270243665u,b_101b9750);register_block(270243667u,b_101b9752);register_block(270243671u,b_101b9756);register_block(270243675u,b_101b975a);register_block(270243677u,b_101b975c);register_block(270243683u,b_101b9762);register_block(270243689u,b_101b9768);register_block(270243691u,b_101b976a);register_block(270243697u,b_101b9770);register_block(270243699u,b_101b9772);register_block(270243705u,b_101b9778);register_block(270243711u,b_101b977e);register_block(270243713u,b_101b9780);register_block(270243719u,b_101b9786);register_block(270243725u,b_101b978c);register_block(270243727u,b_101b978e);register_block(270243731u,b_101b9792);register_block(270243745u,b_101b97a0);register_block(270243763u,b_101b97b2);register_block(270243783u,b_101b97c6);register_block(270243801u,b_101b97d8);register_block(270243803u,b_101b97da);register_block(270243815u,b_101b97e6);register_block(270243825u,b_101b97f0);register_block(270243827u,b_101b97f2);register_block(270243831u,b_101b97f6);register_block(270243833u,b_101b97f8);register_block(270243845u,b_101b9804);register_block(270243847u,b_101b9806);register_block(270243849u,b_101b9808);register_block(270243861u,b_101b9814);register_block(270243873u,b_101b9820);register_block(270243885u,b_101b982c);register_block(270243893u,b_101b9834);register_block(270243905u,b_101b9840);register_block(270243919u,b_101b984e);register_block(270243925u,b_101b9854);register_block(270243933u,b_101b985c);register_block(270243941u,b_101b9864);register_block(270243943u,b_101b9866);register_block(270243949u,b_101b986c);register_block(270243951u,b_101b986e);register_block(270243963u,b_101b987a);register_block(270243981u,b_101b988c);register_block(270243991u,b_101b9896);register_block(270243993u,b_101b9898);register_block(270244013u,b_101b98ac);register_block(270244017u,b_101b98b0);register_block(270244025u,b_101b98b8);register_block(270244039u,b_101b98c6);register_block(270244043u,b_101b98ca);register_block(270244053u,b_101b98d4);register_block(270244055u,b_101b98d6);register_block(270244061u,b_101b98dc);register_block(270244069u,b_101b98e4);register_block(270244079u,b_101b98ee);register_block(270244081u,b_101b98f0);register_block(270244087u,b_101b98f6);register_block(270244089u,b_101b98f8);register_block(270244101u,b_101b9904);register_block(270244103u,b_101b9906);register_block(270244113u,b_101b9910);register_block(270244123u,b_101b991a);register_block(270244125u,b_101b991c);register_block(270244129u,b_101b9920);register_block(270244133u,b_101b9924);register_block(270244147u,b_101b9932);register_block(270244173u,b_101b994c);register_block(270244191u,b_101b995e);register_block(270244193u,b_101b9960);register_block(270244237u,b_101b998c);register_block(270244241u,b_101b9990);register_block(270244245u,b_101b9994);register_block(270244253u,b_101b999c);register_block(270244279u,b_101b99b6);register_block(270244297u,b_101b99c8);register_block(270244311u,b_101b99d6);register_block(270244319u,b_101b99de);register_block(270244327u,b_101b99e6);register_block(270244331u,b_101b99ea);register_block(270244337u,b_101b99f0);register_block(270244359u,b_101b9a06);register_block(270244371u,b_101b9a12);register_block(270244381u,b_101b9a1c);register_block(270244383u,b_101b9a1e);register_block(270244389u,b_101b9a24);register_block(270244401u,b_101b9a30);register_block(270244403u,b_101b9a32);register_block(270244407u,b_101b9a36);register_block(270244413u,b_101b9a3c);register_block(270244423u,b_101b9a46);register_block(270244431u,b_101b9a4e);register_block(270244439u,b_101b9a56);register_block(270244447u,b_101b9a5e);register_block(270244449u,b_101b9a60);register_block(270244451u,b_101b9a62);register_block(270244455u,b_101b9a66);register_block(270244463u,b_101b9a6e);register_block(270244473u,b_101b9a78);register_block(270244483u,b_101b9a82);register_block(270244491u,b_101b9a8a);register_block(270244493u,b_101b9a8c);register_block(270244505u,b_101b9a98);register_block(270244509u,b_101b9a9c);register_block(270244511u,b_101b9a9e);register_block(270244515u,b_101b9aa2);register_block(270244517u,b_101b9aa4);register_block(270244521u,b_101b9aa8);register_block(270244539u,b_101b9aba);register_block(270244545u,b_101b9ac0);register_block(270244551u,b_101b9ac6);register_block(270244567u,b_101b9ad6);register_block(270244575u,b_101b9ade);register_block(270244577u,b_101b9ae0);register_block(270244587u,b_101b9aea);register_block(270244593u,b_101b9af0);register_block(270244619u,b_101b9b0a);register_block(270244645u,b_101b9b24);register_block(270244657u,b_101b9b30);register_block(270244665u,b_101b9b38);register_block(270244671u,b_101b9b3e);register_block(270244679u,b_101b9b46);register_block(270244685u,b_101b9b4c);register_block(270244691u,b_101b9b52);register_block(270244699u,b_101b9b5a);register_block(270244707u,b_101b9b62);register_block(270244717u,b_101b9b6c);register_block(270244735u,b_101b9b7e);register_block(270244757u,b_101b9b94);register_block(270244763u,b_101b9b9a);register_block(270244771u,b_101b9ba2);register_block(270244779u,b_101b9baa);register_block(270244789u,b_101b9bb4);register_block(270244801u,b_101b9bc0);register_block(270244825u,b_101b9bd8);register_block(270244831u,b_101b9bde);register_block(270244839u,b_101b9be6);register_block(270244849u,b_101b9bf0);register_block(270244859u,b_101b9bfa);register_block(270244873u,b_101b9c08);register_block(270244891u,b_101b9c1a);register_block(270244897u,b_101b9c20);register_block(270244905u,b_101b9c28);register_block(270244915u,b_101b9c32);register_block(270244925u,b_101b9c3c);register_block(270244937u,b_101b9c48);register_block(270244955u,b_101b9c5a);register_block(270244961u,b_101b9c60);register_block(270244969u,b_101b9c68);register_block(270244979u,b_101b9c72);register_block(270244989u,b_101b9c7c);register_block(270245003u,b_101b9c8a);register_block(270245021u,b_101b9c9c);register_block(270245027u,b_101b9ca2);register_block(270245035u,b_101b9caa);register_block(270245045u,b_101b9cb4);register_block(270245055u,b_101b9cbe);register_block(270245069u,b_101b9ccc);register_block(270245087u,b_101b9cde);register_block(270245093u,b_101b9ce4);register_block(270245101u,b_101b9cec);register_block(270245109u,b_101b9cf4);register_block(270245119u,b_101b9cfe);register_block(270245131u,b_101b9d0a);register_block(270245149u,b_101b9d1c);register_block(270245157u,b_101b9d24);register_block(270245159u,b_101b9d26);register_block(270245165u,b_101b9d2c);register_block(270245183u,b_101b9d3e);register_block(270245207u,b_101b9d56);register_block(270245227u,b_101b9d6a);register_block(270245245u,b_101b9d7c);register_block(270245251u,b_101b9d82);register_block(270245261u,b_101b9d8c);register_block(270245275u,b_101b9d9a);register_block(270245277u,b_101b9d9c);register_block(270245287u,b_101b9da6);register_block(270245293u,b_101b9dac);register_block(270245305u,b_101b9db8);register_block(270245311u,b_101b9dbe);register_block(270245345u,b_101b9de0);register_block(270245353u,b_101b9de8);register_block(270245377u,b_101b9e00);register_block(270245411u,b_101b9e22);register_block(270245439u,b_101b9e3e);register_block(270245457u,b_101b9e50);register_block(270245477u,b_101b9e64);register_block(270245509u,b_101b9e84);register_block(270245541u,b_101b9ea4);register_block(270245557u,b_101b9eb4);register_block(270245563u,b_101b9eba);register_block(270245571u,b_101b9ec2);register_block(270245581u,b_101b9ecc);register_block(270245603u,b_101b9ee2);register_block(270245639u,b_101b9f06);register_block(270245645u,b_101b9f0c);register_block(270245655u,b_101b9f16);register_block(270245669u,b_101b9f24);register_block(270245687u,b_101b9f36);register_block(270245725u,b_101b9f5c);register_block(270245731u,b_101b9f62);register_block(270245741u,b_101b9f6c);register_block(270245755u,b_101b9f7a);register_block(270245773u,b_101b9f8c);register_block(270245813u,b_101b9fb4);register_block(270245821u,b_101b9fbc);register_block(270245841u,b_101b9fd0);register_block(270245857u,b_101b9fe0);register_block(270245861u,b_101b9fe4);register_block(270245865u,b_101b9fe8);register_block(270245867u,b_101b9fea);register_block(270245871u,b_101b9fee);register_block(270245873u,b_101b9ff0);register_block(270245877u,b_101b9ff4);register_block(270245881u,b_101b9ff8);register_block(270245883u,b_101b9ffa);register_block(270245887u,b_101b9ffe);register_block(270245891u,b_101ba002);register_block(270245897u,b_101ba008);register_block(270245899u,b_101ba00a);register_block(270245905u,b_101ba010);register_block(270245907u,b_101ba012);register_block(270245911u,b_101ba016);register_block(270245915u,b_101ba01a);register_block(270245921u,b_101ba020);register_block(270245923u,b_101ba022);register_block(270245929u,b_101ba028);register_block(270245933u,b_101ba02c);register_block(270245939u,b_101ba032);register_block(270245943u,b_101ba036);register_block(270245949u,b_101ba03c);register_block(270245955u,b_101ba042);register_block(270245957u,b_101ba044);register_block(270245969u,b_101ba050);register_block(270245975u,b_101ba056);register_block(270245983u,b_101ba05e);register_block(270245985u,b_101ba060);register_block(270245989u,b_101ba064);register_block(270246003u,b_101ba072);register_block(270246005u,b_101ba074);register_block(270246011u,b_101ba07a);register_block(270246021u,b_101ba084);register_block(270246023u,b_101ba086);register_block(270246025u,b_101ba088);register_block(270246037u,b_101ba094);register_block(270246051u,b_101ba0a2);register_block(270246061u,b_101ba0ac);register_block(270246067u,b_101ba0b2);register_block(270246083u,b_101ba0c2);register_block(270246085u,b_101ba0c4);register_block(270246097u,b_101ba0d0);register_block(270246099u,b_101ba0d2);register_block(270246105u,b_101ba0d8);register_block(270246111u,b_101ba0de);register_block(270246117u,b_101ba0e4);register_block(270246127u,b_101ba0ee);register_block(270246129u,b_101ba0f0);register_block(270246135u,b_101ba0f6);register_block(270246145u,b_101ba100);register_block(270246151u,b_101ba106);register_block(270246153u,b_101ba108);register_block(270246165u,b_101ba114);register_block(270246173u,b_101ba11c);register_block(270246181u,b_101ba124);register_block(270246187u,b_101ba12a);register_block(270246197u,b_101ba134);register_block(270246207u,b_101ba13e);register_block(270246209u,b_101ba140);register_block(270246211u,b_101ba142);register_block(270246223u,b_101ba14e);register_block(270246249u,b_101ba168);register_block(270246251u,b_101ba16a);register_block(270246255u,b_101ba16e);register_block(270246259u,b_101ba172);register_block(270246267u,b_101ba17a);register_block(270246271u,b_101ba17e);register_block(270246289u,b_101ba190);register_block(270246293u,b_101ba194);register_block(270246305u,b_101ba1a0);register_block(270246311u,b_101ba1a6);register_block(270246325u,b_101ba1b4);register_block(270246331u,b_101ba1ba);register_block(270246335u,b_101ba1be);register_block(270246343u,b_101ba1c6);register_block(270246347u,b_101ba1ca);register_block(270246351u,b_101ba1ce);register_block(270246357u,b_101ba1d4);register_block(270246367u,b_101ba1de);register_block(270246373u,b_101ba1e4);register_block(270246375u,b_101ba1e6);register_block(270246387u,b_101ba1f2);register_block(270246389u,b_101ba1f4);register_block(270246393u,b_101ba1f8);register_block(270246419u,b_101ba212);register_block(270246421u,b_101ba214);register_block(270246425u,b_101ba218);register_block(270246431u,b_101ba21e);register_block(270246437u,b_101ba224);register_block(270246447u,b_101ba22e);register_block(270246451u,b_101ba232);register_block(270246485u,b_101ba254);register_block(270246491u,b_101ba25a);register_block(270246499u,b_101ba262);register_block(270246503u,b_101ba266);register_block(270246509u,b_101ba26c);register_block(270246515u,b_101ba272);register_block(270246523u,b_101ba27a);register_block(270246535u,b_101ba286);register_block(270246553u,b_101ba298);register_block(270246577u,b_101ba2b0);register_block(270246611u,b_101ba2d2);register_block(270246639u,b_101ba2ee);register_block(270246657u,b_101ba300);register_block(270246677u,b_101ba314);register_block(270246709u,b_101ba334);register_block(270246741u,b_101ba354);register_block(270246757u,b_101ba364);register_block(270246763u,b_101ba36a);register_block(270246771u,b_101ba372);register_block(270246781u,b_101ba37c);register_block(270246803u,b_101ba392);register_block(270246839u,b_101ba3b6);register_block(270246845u,b_101ba3bc);register_block(270246855u,b_101ba3c6);register_block(270246869u,b_101ba3d4);register_block(270246887u,b_101ba3e6);register_block(270246925u,b_101ba40c);register_block(270246931u,b_101ba412);register_block(270246941u,b_101ba41c);register_block(270246955u,b_101ba42a);register_block(270246973u,b_101ba43c);register_block(270247013u,b_101ba464);register_block(270247021u,b_101ba46c);register_block(270247041u,b_101ba480);register_block(270247053u,b_101ba48c);register_block(270247055u,b_101ba48e);register_block(270247059u,b_101ba492);register_block(270247061u,b_101ba494);register_block(270247065u,b_101ba498);register_block(270247069u,b_101ba49c);register_block(270247071u,b_101ba49e);register_block(270247075u,b_101ba4a2);register_block(270247079u,b_101ba4a6);register_block(270247081u,b_101ba4a8);register_block(270247085u,b_101ba4ac);register_block(270247087u,b_101ba4ae);register_block(270247091u,b_101ba4b2);register_block(270247095u,b_101ba4b6);register_block(270247097u,b_101ba4b8);register_block(270247101u,b_101ba4bc);register_block(270247105u,b_101ba4c0);register_block(270247107u,b_101ba4c2);register_block(270247111u,b_101ba4c6);register_block(270247117u,b_101ba4cc);register_block(270247119u,b_101ba4ce);register_block(270247131u,b_101ba4da);register_block(270247137u,b_101ba4e0);register_block(270247145u,b_101ba4e8);register_block(270247147u,b_101ba4ea);register_block(270247151u,b_101ba4ee);register_block(270247163u,b_101ba4fa);register_block(270247165u,b_101ba4fc);register_block(270247171u,b_101ba502);register_block(270247179u,b_101ba50a);register_block(270247181u,b_101ba50c);register_block(270247183u,b_101ba50e);register_block(270247195u,b_101ba51a);register_block(270247207u,b_101ba526);register_block(270247215u,b_101ba52e);register_block(270247221u,b_101ba534);register_block(270247227u,b_101ba53a);register_block(270247235u,b_101ba542);register_block(270247237u,b_101ba544);register_block(270247249u,b_101ba550);register_block(270247251u,b_101ba552);register_block(270247257u,b_101ba558);register_block(270247263u,b_101ba55e);register_block(270247269u,b_101ba564);register_block(270247277u,b_101ba56c);register_block(270247279u,b_101ba56e);register_block(270247285u,b_101ba574);register_block(270247291u,b_101ba57a);register_block(270247303u,b_101ba586);register_block(270247305u,b_101ba588);register_block(270247317u,b_101ba594);register_block(270247329u,b_101ba5a0);register_block(270247335u,b_101ba5a6);register_block(270247343u,b_101ba5ae);register_block(270247353u,b_101ba5b8);register_block(270247361u,b_101ba5c0);register_block(270247383u,b_101ba5d6);register_block(270247405u,b_101ba5ec);register_block(270247407u,b_101ba5ee);register_block(270247415u,b_101ba5f6);register_block(270247423u,b_101ba5fe);register_block(270247431u,b_101ba606);register_block(270247439u,b_101ba60e);register_block(270247447u,b_101ba616);register_block(270247455u,b_101ba61e);register_block(270247465u,b_101ba628);register_block(270247469u,b_101ba62c);register_block(270247493u,b_101ba644);register_block(270247527u,b_101ba666);register_block(270247555u,b_101ba682);register_block(270247573u,b_101ba694);register_block(270247593u,b_101ba6a8);register_block(270247625u,b_101ba6c8);register_block(270247657u,b_101ba6e8);register_block(270247673u,b_101ba6f8);register_block(270247679u,b_101ba6fe);register_block(270247687u,b_101ba706);register_block(270247697u,b_101ba710);register_block(270247719u,b_101ba726);register_block(270247755u,b_101ba74a);register_block(270247761u,b_101ba750);register_block(270247771u,b_101ba75a);register_block(270247785u,b_101ba768);register_block(270247803u,b_101ba77a);register_block(270247841u,b_101ba7a0);register_block(270247847u,b_101ba7a6);register_block(270247857u,b_101ba7b0);register_block(270247871u,b_101ba7be);register_block(270247889u,b_101ba7d0);register_block(270247929u,b_101ba7f8);register_block(270247937u,b_101ba800);register_block(270247957u,b_101ba814);register_block(270247971u,b_101ba822);register_block(270247977u,b_101ba828);register_block(270247979u,b_101ba82a);register_block(270247985u,b_101ba830);register_block(270247991u,b_101ba836);register_block(270248001u,b_101ba840);register_block(270248007u,b_101ba846);register_block(270248017u,b_101ba850);register_block(270248025u,b_101ba858);register_block(270248033u,b_101ba860);register_block(270248041u,b_101ba868);register_block(270248049u,b_101ba870);register_block(270248063u,b_101ba87e);register_block(270248067u,b_101ba882);register_block(270248075u,b_101ba88a);register_block(270248091u,b_101ba89a);register_block(270248097u,b_101ba8a0);register_block(270248105u,b_101ba8a8);register_block(270248109u,b_101ba8ac);register_block(270248135u,b_101ba8c6);register_block(270248137u,b_101ba8c8);register_block(270248141u,b_101ba8cc);register_block(270248143u,b_101ba8ce);register_block(270248147u,b_101ba8d2);register_block(270248149u,b_101ba8d4);register_block(270248153u,b_101ba8d8);register_block(270248157u,b_101ba8dc);register_block(270248159u,b_101ba8de);register_block(270248163u,b_101ba8e2);register_block(270248167u,b_101ba8e6);register_block(270248169u,b_101ba8e8);register_block(270248173u,b_101ba8ec);register_block(270248175u,b_101ba8ee);register_block(270248179u,b_101ba8f2);register_block(270248183u,b_101ba8f6);register_block(270248185u,b_101ba8f8);register_block(270248189u,b_101ba8fc);register_block(270248193u,b_101ba900);register_block(270248195u,b_101ba902);register_block(270248199u,b_101ba906);register_block(270248205u,b_101ba90c);register_block(270248207u,b_101ba90e);register_block(270248217u,b_101ba918);register_block(270248223u,b_101ba91e);register_block(270248231u,b_101ba926);register_block(270248233u,b_101ba928);register_block(270248237u,b_101ba92c);register_block(270248249u,b_101ba938);register_block(270248251u,b_101ba93a);register_block(270248257u,b_101ba940);register_block(270248265u,b_101ba948);register_block(270248267u,b_101ba94a);register_block(270248269u,b_101ba94c);register_block(270248279u,b_101ba956);register_block(270248293u,b_101ba964);register_block(270248301u,b_101ba96c);register_block(270248307u,b_101ba972);register_block(270248323u,b_101ba982);register_block(270248325u,b_101ba984);register_block(270248335u,b_101ba98e);register_block(270248337u,b_101ba990);register_block(270248343u,b_101ba996);register_block(270248349u,b_101ba99c);register_block(270248355u,b_101ba9a2);register_block(270248365u,b_101ba9ac);register_block(270248367u,b_101ba9ae);register_block(270248373u,b_101ba9b4);register_block(270248379u,b_101ba9ba);register_block(270248393u,b_101ba9c8);register_block(270248395u,b_101ba9ca);register_block(270248405u,b_101ba9d4);register_block(270248419u,b_101ba9e2);register_block(270248425u,b_101ba9e8);register_block(270248433u,b_101ba9f0);register_block(270248445u,b_101ba9fc);register_block(270248453u,b_101baa04);register_block(270248501u,b_101baa34);register_block(270248525u,b_101baa4c);register_block(270248551u,b_101baa66);register_block(270248575u,b_101baa7e);register_block(270248599u,b_101baa96);register_block(270248619u,b_101baaaa);register_block(270248643u,b_101baac2);register_block(270248663u,b_101baad6);register_block(270248683u,b_101baaea);register_block(270248701u,b_101baafc);register_block(270248713u,b_101bab08);register_block(270248719u,b_101bab0e);register_block(270248727u,b_101bab16);register_block(270248737u,b_101bab20);register_block(270248757u,b_101bab34);register_block(270248791u,b_101bab56);register_block(270248797u,b_101bab5c);register_block(270248807u,b_101bab66);register_block(270248821u,b_101bab74);register_block(270248839u,b_101bab86);register_block(270248873u,b_101baba8);register_block(270248879u,b_101babae);register_block(270248889u,b_101babb8);register_block(270248903u,b_101babc6);register_block(270248921u,b_101babd8);register_block(270248957u,b_101babfc);register_block(270248963u,b_101bac02);register_block(270248985u,b_101bac18);register_block(270249007u,b_101bac2e);register_block(270249019u,b_101bac3a);register_block(270249027u,b_101bac42);register_block(270249035u,b_101bac4a);register_block(270249043u,b_101bac52);register_block(270249051u,b_101bac5a);register_block(270249059u,b_101bac62);register_block(270249067u,b_101bac6a);register_block(270249071u,b_101bac6e);register_block(270249075u,b_101bac72);register_block(270249109u,b_101bac94);register_block(270249113u,b_101bac98);register_block(270249115u,b_101bac9a);register_block(270249119u,b_101bac9e);register_block(270249121u,b_101baca0);register_block(270249125u,b_101baca4);register_block(270249129u,b_101baca8);register_block(270249133u,b_101bacac);register_block(270249137u,b_101bacb0);register_block(270249141u,b_101bacb4);register_block(270249145u,b_101bacb8);register_block(270249147u,b_101bacba);register_block(270249151u,b_101bacbe);register_block(270249155u,b_101bacc2);register_block(270249159u,b_101bacc6);register_block(270249163u,b_101bacca);register_block(270249167u,b_101bacce);register_block(270249171u,b_101bacd2);register_block(270249175u,b_101bacd6);register_block(270249187u,b_101bace2);register_block(270249193u,b_101bace8);register_block(270249199u,b_101bacee);register_block(270249207u,b_101bacf6);register_block(270249211u,b_101bacfa);register_block(270249215u,b_101bacfe);register_block(270249219u,b_101bad02);register_block(270249225u,b_101bad08);register_block(270249227u,b_101bad0a);register_block(270249235u,b_101bad12);register_block(270249241u,b_101bad18);register_block(270249247u,b_101bad1e);register_block(270249249u,b_101bad20);register_block(270249257u,b_101bad28);register_block(270249261u,b_101bad2c);register_block(270249263u,b_101bad2e);register_block(270249271u,b_101bad36);register_block(270249277u,b_101bad3c);register_block(270249279u,b_101bad3e);register_block(270249287u,b_101bad46);register_block(270249293u,b_101bad4c);register_block(270249295u,b_101bad4e);register_block(270249301u,b_101bad54);register_block(270249303u,b_101bad56);register_block(270249307u,b_101bad5a);register_block(270249319u,b_101bad66);register_block(270249321u,b_101bad68);register_block(270249327u,b_101bad6e);register_block(270249333u,b_101bad74);register_block(270249347u,b_101bad82);register_block(270249349u,b_101bad84);register_block(270249355u,b_101bad8a);register_block(270249361u,b_101bad90);register_block(270249367u,b_101bad96);register_block(270249375u,b_101bad9e);register_block(270249387u,b_101badaa);register_block(270249395u,b_101badb2);register_block(270249403u,b_101badba);register_block(270249409u,b_101badc0);register_block(270249419u,b_101badca);register_block(270249423u,b_101badce);register_block(270249475u,b_101bae02);register_block(270249487u,b_101bae0e);register_block(270249499u,b_101bae1a);register_block(270249511u,b_101bae26);register_block(270249523u,b_101bae32);register_block(270249535u,b_101bae3e);register_block(270249547u,b_101bae4a);register_block(270249561u,b_101bae58);register_block(270249573u,b_101bae64);register_block(270249587u,b_101bae72);register_block(270249609u,b_101bae88);register_block(270249637u,b_101baea4);register_block(270249647u,b_101baeae);register_block(270249665u,b_101baec0);register_block(270249683u,b_101baed2);register_block(270249693u,b_101baedc);register_block(270249757u,b_101baf1c);register_block(270249765u,b_101baf24);register_block(270249771u,b_101baf2a);register_block(270249783u,b_101baf36);register_block(270249797u,b_101baf44);register_block(270249803u,b_101baf4a);register_block(270249809u,b_101baf50);register_block(270249819u,b_101baf5a);register_block(270249827u,b_101baf62);register_block(270249835u,b_101baf6a);register_block(270249865u,b_101baf88);register_block(270249877u,b_101baf94);register_block(270249885u,b_101baf9c);register_block(270249895u,b_101bafa6);register_block(270249923u,b_101bafc2);register_block(270249927u,b_101bafc6);register_block(270249937u,b_101bafd0);register_block(270249987u,b_101bb002);register_block(270249989u,b_101bb004);register_block(270249993u,b_101bb008);register_block(270250013u,b_101bb01c);register_block(270250029u,b_101bb02c);register_block(270250053u,b_101bb044);register_block(270250057u,b_101bb048);register_block(270250067u,b_101bb052);register_block(270250077u,b_101bb05c);register_block(270250083u,b_101bb062);register_block(270250093u,b_101bb06c);register_block(270250125u,b_101bb08c);register_block(270250131u,b_101bb092);register_block(270250137u,b_101bb098);register_block(270250139u,b_101bb09a);register_block(270250147u,b_101bb0a2);register_block(270250151u,b_101bb0a6);register_block(270250167u,b_101bb0b6);register_block(270250173u,b_101bb0bc);register_block(270250181u,b_101bb0c4);register_block(270250185u,b_101bb0c8);register_block(270250187u,b_101bb0ca);register_block(270250197u,b_101bb0d4);register_block(270250199u,b_101bb0d6);register_block(270250211u,b_101bb0e2);register_block(270250217u,b_101bb0e8);register_block(270250229u,b_101bb0f4);register_block(270250241u,b_101bb100);register_block(270250253u,b_101bb10c);register_block(270250273u,b_101bb120);register_block(270250275u,b_101bb122);register_block(270250287u,b_101bb12e);register_block(270250293u,b_101bb134);register_block(270250309u,b_101bb144);register_block(270250335u,b_101bb15e);register_block(270250347u,b_101bb16a);register_block(270250355u,b_101bb172);register_block(270250363u,b_101bb17a);register_block(270250371u,b_101bb182);register_block(270250381u,b_101bb18c);register_block(270250387u,b_101bb192);register_block(270250395u,b_101bb19a);register_block(270250401u,b_101bb1a0);register_block(270250405u,b_101bb1a4);register_block(270250409u,b_101bb1a8);register_block(270250411u,b_101bb1aa);register_block(270250415u,b_101bb1ae);register_block(270250417u,b_101bb1b0);register_block(270250421u,b_101bb1b4);register_block(270250425u,b_101bb1b8);register_block(270250429u,b_101bb1bc);register_block(270250433u,b_101bb1c0);register_block(270250437u,b_101bb1c4);register_block(270250439u,b_101bb1c6);register_block(270250443u,b_101bb1ca);register_block(270250447u,b_101bb1ce);register_block(270250451u,b_101bb1d2);register_block(270250453u,b_101bb1d4);register_block(270250455u,b_101bb1d6);register_block(270250457u,b_101bb1d8);register_block(270250463u,b_101bb1de);register_block(270250475u,b_101bb1ea);register_block(270250481u,b_101bb1f0);register_block(270250507u,b_101bb20a);register_block(270250515u,b_101bb212);register_block(270250521u,b_101bb218);register_block(270250525u,b_101bb21c);register_block(270250537u,b_101bb228);register_block(270250547u,b_101bb232);register_block(270250559u,b_101bb23e);register_block(270250563u,b_101bb242);register_block(270250571u,b_101bb24a);register_block(270250573u,b_101bb24c);register_block(270250621u,b_101bb27c);register_block(270250641u,b_101bb290);register_block(270250657u,b_101bb2a0);register_block(270250669u,b_101bb2ac);register_block(270250677u,b_101bb2b4);register_block(270250685u,b_101bb2bc);register_block(270250693u,b_101bb2c4);register_block(270250701u,b_101bb2cc);register_block(270250709u,b_101bb2d4);register_block(270250735u,b_101bb2ee);register_block(270250739u,b_101bb2f2);register_block(270250741u,b_101bb2f4);register_block(270250745u,b_101bb2f8);register_block(270250747u,b_101bb2fa);register_block(270250751u,b_101bb2fe);register_block(270250755u,b_101bb302);register_block(270250757u,b_101bb304);register_block(270250761u,b_101bb308);register_block(270250765u,b_101bb30c);register_block(270250767u,b_101bb30e);register_block(270250771u,b_101bb312);register_block(270250773u,b_101bb314);register_block(270250777u,b_101bb318);register_block(270250781u,b_101bb31c);register_block(270250783u,b_101bb31e);register_block(270250787u,b_101bb322);register_block(270250791u,b_101bb326);register_block(270250793u,b_101bb328);register_block(270250795u,b_101bb32a);register_block(270250801u,b_101bb330);register_block(270250809u,b_101bb338);register_block(270250817u,b_101bb340);register_block(270250825u,b_101bb348);register_block(270250833u,b_101bb350);register_block(270250835u,b_101bb352);register_block(270250847u,b_101bb35e);register_block(270250853u,b_101bb364);register_block(270250867u,b_101bb372);register_block(270250869u,b_101bb374);register_block(270250875u,b_101bb37a);register_block(270250883u,b_101bb382);register_block(270250891u,b_101bb38a);register_block(270250893u,b_101bb38c);register_block(270250897u,b_101bb390);register_block(270250905u,b_101bb398);register_block(270250907u,b_101bb39a);register_block(270250915u,b_101bb3a2);register_block(270250919u,b_101bb3a6);register_block(270250921u,b_101bb3a8);register_block(270250923u,b_101bb3aa);register_block(270250929u,b_101bb3b0);register_block(270250937u,b_101bb3b8);register_block(270250945u,b_101bb3c0);register_block(270250947u,b_101bb3c2);register_block(270250949u,b_101bb3c4);register_block(270250955u,b_101bb3ca);register_block(270250981u,b_101bb3e4);register_block(270250985u,b_101bb3e8);register_block(270250999u,b_101bb3f6);register_block(270251005u,b_101bb3fc);register_block(270251011u,b_101bb402);register_block(270251037u,b_101bb41c);register_block(270251039u,b_101bb41e);register_block(270251045u,b_101bb424);register_block(270251057u,b_101bb430);register_block(270251065u,b_101bb438);register_block(270251079u,b_101bb446);register_block(270251087u,b_101bb44e);register_block(270251091u,b_101bb452);register_block(270251103u,b_101bb45e);register_block(270251125u,b_101bb474);register_block(270251129u,b_101bb478);register_block(270251151u,b_101bb48e);register_block(270251191u,b_101bb4b6);register_block(270251205u,b_101bb4c4);register_block(270251229u,b_101bb4dc);register_block(270251285u,b_101bb514);register_block(270251311u,b_101bb52e);register_block(270251333u,b_101bb544);register_block(270251355u,b_101bb55a);register_block(270251375u,b_101bb56e);register_block(270251395u,b_101bb582);register_block(270251415u,b_101bb596);register_block(270251429u,b_101bb5a4);register_block(270251435u,b_101bb5aa);register_block(270251443u,b_101bb5b2);register_block(270251453u,b_101bb5bc);register_block(270251475u,b_101bb5d2);register_block(270251511u,b_101bb5f6);register_block(270251517u,b_101bb5fc);register_block(270251527u,b_101bb606);register_block(270251541u,b_101bb614);register_block(270251559u,b_101bb626);register_block(270251597u,b_101bb64c);register_block(270251603u,b_101bb652);register_block(270251613u,b_101bb65c);register_block(270251627u,b_101bb66a);register_block(270251645u,b_101bb67c);register_block(270251685u,b_101bb6a4);register_block(270251693u,b_101bb6ac);register_block(270251713u,b_101bb6c0);register_block(270251723u,b_101bb6ca);register_block(270251735u,b_101bb6d6);register_block(270251739u,b_101bb6da);register_block(270251747u,b_101bb6e2);register_block(270251749u,b_101bb6e4);register_block(270251797u,b_101bb714);register_block(270251817u,b_101bb728);register_block(270251823u,b_101bb72e);register_block(270251835u,b_101bb73a);register_block(270251837u,b_101bb73c);register_block(270251853u,b_101bb74c);register_block(270251865u,b_101bb758);register_block(270251873u,b_101bb760);register_block(270251881u,b_101bb768);register_block(270251889u,b_101bb770);register_block(270251897u,b_101bb778);register_block(270251905u,b_101bb780);register_block(270251913u,b_101bb788);register_block(270251935u,b_101bb79e);register_block(270251937u,b_101bb7a0);register_block(270251941u,b_101bb7a4);register_block(270251943u,b_101bb7a6);register_block(270251947u,b_101bb7aa);register_block(270251949u,b_101bb7ac);register_block(270251953u,b_101bb7b0);register_block(270251957u,b_101bb7b4);register_block(270251959u,b_101bb7b6);register_block(270251963u,b_101bb7ba);register_block(270251969u,b_101bb7c0);register_block(270251971u,b_101bb7c2);register_block(270251977u,b_101bb7c8);register_block(270251979u,b_101bb7ca);register_block(270251985u,b_101bb7d0);register_block(270251989u,b_101bb7d4);register_block(270251991u,b_101bb7d6);register_block(270251997u,b_101bb7dc);register_block(270252003u,b_101bb7e2);register_block(270252009u,b_101bb7e8);register_block(270252011u,b_101bb7ea);register_block(270252013u,b_101bb7ec);register_block(270252019u,b_101bb7f2);register_block(270252029u,b_101bb7fc);register_block(270252037u,b_101bb804);register_block(270252045u,b_101bb80c);register_block(270252047u,b_101bb80e);register_block(270252053u,b_101bb814);register_block(270252059u,b_101bb81a);register_block(270252061u,b_101bb81c);register_block(270252073u,b_101bb828);register_block(270252091u,b_101bb83a);register_block(270252099u,b_101bb842);register_block(270252111u,b_101bb84e);register_block(270252125u,b_101bb85c);register_block(270252133u,b_101bb864);register_block(270252135u,b_101bb866);register_block(270252137u,b_101bb868);register_block(270252141u,b_101bb86c);register_block(270252153u,b_101bb878);register_block(270252157u,b_101bb87c);register_block(270252165u,b_101bb884);register_block(270252167u,b_101bb886);register_block(270252173u,b_101bb88c);register_block(270252179u,b_101bb892);register_block(270252187u,b_101bb89a);register_block(270252191u,b_101bb89e);register_block(270252197u,b_101bb8a4);register_block(270252201u,b_101bb8a8);register_block(270252207u,b_101bb8ae);register_block(270252213u,b_101bb8b4);register_block(270252221u,b_101bb8bc);register_block(270252225u,b_101bb8c0);register_block(270252231u,b_101bb8c6);register_block(270252241u,b_101bb8d0);register_block(270252243u,b_101bb8d2);register_block(270252245u,b_101bb8d4);register_block(270252259u,b_101bb8e2);register_block(270252265u,b_101bb8e8);register_block(270252267u,b_101bb8ea);register_block(270252273u,b_101bb8f0);register_block(270252279u,b_101bb8f6);register_block(270252287u,b_101bb8fe);register_block(270252297u,b_101bb908);register_block(270252299u,b_101bb90a);register_block(270252303u,b_101bb90e);register_block(270252307u,b_101bb912);register_block(270252315u,b_101bb91a);register_block(270252323u,b_101bb922);register_block(270252325u,b_101bb924);register_block(270252337u,b_101bb930);register_block(270252339u,b_101bb932);register_block(270252345u,b_101bb938);register_block(270252353u,b_101bb940);register_block(270252381u,b_101bb95c);register_block(270252383u,b_101bb95e);register_block(270252387u,b_101bb962);register_block(270252391u,b_101bb966);register_block(270252397u,b_101bb96c);register_block(270252407u,b_101bb976);register_block(270252413u,b_101bb97c);register_block(270252419u,b_101bb982);register_block(270252429u,b_101bb98c);register_block(270252437u,b_101bb994);register_block(270252445u,b_101bb99c);register_block(270252453u,b_101bb9a4);register_block(270252463u,b_101bb9ae);register_block(270252473u,b_101bb9b8);register_block(270252481u,b_101bb9c0);register_block(270252507u,b_101bb9da);register_block(270252509u,b_101bb9dc);register_block(270252515u,b_101bb9e2);register_block(270252523u,b_101bb9ea);register_block(270252525u,b_101bb9ec);register_block(270252527u,b_101bb9ee);register_block(270252533u,b_101bb9f4);register_block(270252535u,b_101bb9f6);register_block(270252543u,b_101bb9fe);register_block(270252545u,b_101bba00);register_block(270252551u,b_101bba06);register_block(270252557u,b_101bba0c);register_block(270252573u,b_101bba1c);register_block(270252575u,b_101bba1e);register_block(270252579u,b_101bba22);register_block(270252585u,b_101bba28);register_block(270252595u,b_101bba32);register_block(270252597u,b_101bba34);register_block(270252613u,b_101bba44);register_block(270252615u,b_101bba46);register_block(270252625u,b_101bba50);register_block(270252629u,b_101bba54);register_block(270252639u,b_101bba5e);register_block(270252649u,b_101bba68);register_block(270252671u,b_101bba7e);register_block(270252693u,b_101bba94);register_block(270252705u,b_101bbaa0);register_block(270252713u,b_101bbaa8);register_block(270252721u,b_101bbab0);register_block(270252729u,b_101bbab8);register_block(270252737u,b_101bbac0);register_block(270252743u,b_101bbac6);register_block(270252747u,b_101bbaca);register_block(270252753u,b_101bbad0);register_block(270252759u,b_101bbad6);register_block(270252773u,b_101bbae4);register_block(270252777u,b_101bbae8);register_block(270252781u,b_101bbaec);register_block(270252789u,b_101bbaf4);register_block(270252811u,b_101bbb0a);register_block(270252815u,b_101bbb0e);register_block(270252823u,b_101bbb16);register_block(270252829u,b_101bbb1c);register_block(270252831u,b_101bbb1e);register_block(270252835u,b_101bbb22);register_block(270252837u,b_101bbb24);register_block(270252841u,b_101bbb28);register_block(270252843u,b_101bbb2a);register_block(270252849u,b_101bbb30);register_block(270252855u,b_101bbb36);register_block(270252857u,b_101bbb38);register_block(270252863u,b_101bbb3e);register_block(270252865u,b_101bbb40);register_block(270252871u,b_101bbb46);register_block(270252873u,b_101bbb48);register_block(270252879u,b_101bbb4e);register_block(270252885u,b_101bbb54);register_block(270252887u,b_101bbb56);register_block(270252889u,b_101bbb58);register_block(270252901u,b_101bbb64);register_block(270252909u,b_101bbb6c);register_block(270252915u,b_101bbb72);register_block(270252921u,b_101bbb78);register_block(270252925u,b_101bbb7c);register_block(270252939u,b_101bbb8a);register_block(270252947u,b_101bbb92);register_block(270252955u,b_101bbb9a);register_block(270252959u,b_101bbb9e);register_block(270252965u,b_101bbba4);register_block(270252969u,b_101bbba8);register_block(270252977u,b_101bbbb0);register_block(270252979u,b_101bbbb2);register_block(270253033u,b_101bbbe8);register_block(270253057u,b_101bbc00);register_block(270253065u,b_101bbc08);register_block(270253073u,b_101bbc10);register_block(270253109u,b_101bbc34);register_block(270253119u,b_101bbc3e);register_block(270253133u,b_101bbc4c);register_block(270253139u,b_101bbc52);register_block(270253145u,b_101bbc58);register_block(270253151u,b_101bbc5e);register_block(270253155u,b_101bbc62);register_block(270253163u,b_101bbc6a);register_block(270253165u,b_101bbc6c);register_block(270253169u,b_101bbc70);register_block(270253187u,b_101bbc82);register_block(270253195u,b_101bbc8a);register_block(270253259u,b_101bbcca);register_block(270253283u,b_101bbce2);register_block(270253291u,b_101bbcea);register_block(270253299u,b_101bbcf2);register_block(270253335u,b_101bbd16);register_block(270253347u,b_101bbd22);register_block(270253363u,b_101bbd32);register_block(270253365u,b_101bbd34);register_block(270253367u,b_101bbd36);register_block(270253373u,b_101bbd3c);register_block(270253377u,b_101bbd40);register_block(270253383u,b_101bbd46);register_block(270253393u,b_101bbd50);register_block(270253395u,b_101bbd52);register_block(270253403u,b_101bbd5a);register_block(270253413u,b_101bbd64);register_block(270253423u,b_101bbd6e);register_block(270253433u,b_101bbd78);register_block(270253439u,b_101bbd7e);register_block(270253449u,b_101bbd88);register_block(270253451u,b_101bbd8a);register_block(270253453u,b_101bbd8c);register_block(270253465u,b_101bbd98);register_block(270253471u,b_101bbd9e);register_block(270253473u,b_101bbda0);register_block(270253475u,b_101bbda2);register_block(270253483u,b_101bbdaa);register_block(270253489u,b_101bbdb0);register_block(270253495u,b_101bbdb6);register_block(270253521u,b_101bbdd0);register_block(270253527u,b_101bbdd6);register_block(270253529u,b_101bbdd8);register_block(270253535u,b_101bbdde);register_block(270253541u,b_101bbde4);register_block(270253573u,b_101bbe04);register_block(270253585u,b_101bbe10);register_block(270253593u,b_101bbe18);register_block(270253597u,b_101bbe1c);register_block(270253603u,b_101bbe22);register_block(270253607u,b_101bbe26);register_block(270253611u,b_101bbe2a);register_block(270253619u,b_101bbe32);register_block(270253627u,b_101bbe3a);register_block(270253635u,b_101bbe42);register_block(270253637u,b_101bbe44);register_block(270253641u,b_101bbe48);register_block(270253653u,b_101bbe54);register_block(270253655u,b_101bbe56);register_block(270253659u,b_101bbe5a);register_block(270253661u,b_101bbe5c);register_block(270253665u,b_101bbe60);register_block(270253669u,b_101bbe64);register_block(270253671u,b_101bbe66);register_block(270253675u,b_101bbe6a);register_block(270253679u,b_101bbe6e);register_block(270253681u,b_101bbe70);register_block(270253685u,b_101bbe74);register_block(270253687u,b_101bbe76);register_block(270253691u,b_101bbe7a);register_block(270253695u,b_101bbe7e);register_block(270253697u,b_101bbe80);register_block(270253701u,b_101bbe84);register_block(270253705u,b_101bbe88);register_block(270253707u,b_101bbe8a);register_block(270253711u,b_101bbe8e);register_block(270253717u,b_101bbe94);register_block(270253719u,b_101bbe96);register_block(270253731u,b_101bbea2);register_block(270253737u,b_101bbea8);register_block(270253751u,b_101bbeb6);register_block(270253753u,b_101bbeb8);register_block(270253757u,b_101bbebc);register_block(270253759u,b_101bbebe);register_block(270253769u,b_101bbec8);register_block(270253771u,b_101bbeca);register_block(270253777u,b_101bbed0);register_block(270253779u,b_101bbed2);register_block(270253785u,b_101bbed8);register_block(270253793u,b_101bbee0);register_block(270253801u,b_101bbee8);register_block(270253803u,b_101bbeea);register_block(270253815u,b_101bbef6);register_block(270253823u,b_101bbefe);register_block(270253825u,b_101bbf00);register_block(270253833u,b_101bbf08);register_block(270253849u,b_101bbf18);register_block(270253851u,b_101bbf1a);register_block(270253855u,b_101bbf1e);register_block(270253863u,b_101bbf26);register_block(270253875u,b_101bbf32);register_block(270253881u,b_101bbf38);register_block(270253893u,b_101bbf44);register_block(270253895u,b_101bbf46);register_block(270253907u,b_101bbf52);register_block(270253915u,b_101bbf5a);register_block(270253917u,b_101bbf5c);register_block(270253927u,b_101bbf66);register_block(270253943u,b_101bbf76);register_block(270253949u,b_101bbf7c);register_block(270253959u,b_101bbf86);register_block(270253965u,b_101bbf8c);register_block(270253977u,b_101bbf98);register_block(270253989u,b_101bbfa4);register_block(270254001u,b_101bbfb0);register_block(270254021u,b_101bbfc4);register_block(270254023u,b_101bbfc6);register_block(270254035u,b_101bbfd2);register_block(270254041u,b_101bbfd8);register_block(270254057u,b_101bbfe8);register_block(270254073u,b_101bbff8);register_block(270254081u,b_101bc000);register_block(270254087u,b_101bc006);register_block(270254089u,b_101bc008);register_block(270254093u,b_101bc00c);register_block(270254095u,b_101bc00e);register_block(270254099u,b_101bc012);register_block(270254103u,b_101bc016);register_block(270254107u,b_101bc01a);register_block(270254111u,b_101bc01e);register_block(270254115u,b_101bc022);register_block(270254119u,b_101bc026);register_block(270254123u,b_101bc02a);register_block(270254125u,b_101bc02c);register_block(270254129u,b_101bc030);register_block(270254133u,b_101bc034);register_block(270254137u,b_101bc038);register_block(270254143u,b_101bc03e);register_block(270254149u,b_101bc044);register_block(270254155u,b_101bc04a);register_block(270254163u,b_101bc052);register_block(270254173u,b_101bc05c);register_block(270254185u,b_101bc068);register_block(270254187u,b_101bc06a);register_block(270254197u,b_101bc074);register_block(270254233u,b_101bc098);register_block(270254249u,b_101bc0a8);register_block(270254255u,b_101bc0ae);register_block(270254263u,b_101bc0b6);register_block(270254273u,b_101bc0c0);register_block(270254285u,b_101bc0cc);register_block(270254287u,b_101bc0ce);register_block(270254297u,b_101bc0d8);register_block(270254303u,b_101bc0de);register_block(270254323u,b_101bc0f2);register_block(270254325u,b_101bc0f4);register_block(270254337u,b_101bc100);register_block(270254343u,b_101bc106);register_block(270254355u,b_101bc112);register_block(270254357u,b_101bc114);register_block(270254367u,b_101bc11e);register_block(270254379u,b_101bc12a);register_block(270254387u,b_101bc132);register_block(270254389u,b_101bc134);register_block(270254397u,b_101bc13c);register_block(270254401u,b_101bc140);register_block(270254409u,b_101bc148);register_block(270254411u,b_101bc14a);register_block(270254423u,b_101bc156);register_block(270254429u,b_101bc15c);register_block(270254441u,b_101bc168);register_block(270254449u,b_101bc170);register_block(270254453u,b_101bc174);register_block(270254461u,b_101bc17c);register_block(270254469u,b_101bc184);register_block(270254479u,b_101bc18e);register_block(270254491u,b_101bc19a);register_block(270254493u,b_101bc19c);register_block(270254501u,b_101bc1a4);register_block(270254511u,b_101bc1ae);register_block(270254523u,b_101bc1ba);register_block(270254529u,b_101bc1c0);register_block(270254539u,b_101bc1ca);register_block(270254541u,b_101bc1cc);register_block(270254549u,b_101bc1d4);register_block(270254559u,b_101bc1de);register_block(270254571u,b_101bc1ea);register_block(270254573u,b_101bc1ec);register_block(270254587u,b_101bc1fa);register_block(270254593u,b_101bc200);register_block(270254599u,b_101bc206);register_block(270254603u,b_101bc20a);register_block(270254611u,b_101bc212);register_block(270254617u,b_101bc218);register_block(270254629u,b_101bc224);register_block(270254661u,b_101bc244);register_block(270254673u,b_101bc250);register_block(270254683u,b_101bc25a);register_block(270254689u,b_101bc260);register_block(270254711u,b_101bc276);register_block(270254713u,b_101bc278);register_block(270254717u,b_101bc27c);register_block(270254719u,b_101bc27e);register_block(270254723u,b_101bc282);register_block(270254727u,b_101bc286);register_block(270254729u,b_101bc288);register_block(270254733u,b_101bc28c);register_block(270254737u,b_101bc290);register_block(270254739u,b_101bc292);register_block(270254745u,b_101bc298);register_block(270254747u,b_101bc29a);register_block(270254753u,b_101bc2a0);register_block(270254759u,b_101bc2a6);register_block(270254761u,b_101bc2a8);register_block(270254767u,b_101bc2ae);register_block(270254773u,b_101bc2b4);register_block(270254789u,b_101bc2c4);register_block(270254795u,b_101bc2ca);register_block(270254801u,b_101bc2d0);register_block(270254803u,b_101bc2d2);register_block(270254807u,b_101bc2d6);register_block(270254813u,b_101bc2dc);register_block(270254817u,b_101bc2e0);register_block(270254821u,b_101bc2e4);register_block(270254827u,b_101bc2ea);register_block(270254835u,b_101bc2f2);register_block(270254845u,b_101bc2fc);register_block(270254855u,b_101bc306);register_block(270254861u,b_101bc30c);register_block(270254863u,b_101bc30e);register_block(270254867u,b_101bc312);register_block(270254869u,b_101bc314);register_block(270254875u,b_101bc31a);register_block(270254883u,b_101bc322);register_block(270254889u,b_101bc328);register_block(270254897u,b_101bc330);register_block(270254901u,b_101bc334);register_block(270254907u,b_101bc33a);register_block(270254921u,b_101bc348);register_block(270254923u,b_101bc34a);register_block(270254927u,b_101bc34e);register_block(270254929u,b_101bc350);register_block(270254933u,b_101bc354);register_block(270254935u,b_101bc356);register_block(270254951u,b_101bc366);register_block(270254961u,b_101bc370);register_block(270254971u,b_101bc37a);register_block(270254977u,b_101bc380);register_block(270254979u,b_101bc382);register_block(270254983u,b_101bc386);register_block(270254989u,b_101bc38c);register_block(270254995u,b_101bc392);register_block(270254997u,b_101bc394);register_block(270255003u,b_101bc39a);register_block(270255021u,b_101bc3ac);register_block(270255031u,b_101bc3b6);register_block(270255041u,b_101bc3c0);register_block(270255047u,b_101bc3c6);register_block(270255055u,b_101bc3ce);register_block(270255059u,b_101bc3d2);register_block(270255065u,b_101bc3d8);register_block(270255071u,b_101bc3de);register_block(270255075u,b_101bc3e2);register_block(270255085u,b_101bc3ec);register_block(270255103u,b_101bc3fe);register_block(270255105u,b_101bc400);register_block(270255109u,b_101bc404);register_block(270255115u,b_101bc40a);register_block(270255117u,b_101bc40c);register_block(270255119u,b_101bc40e);register_block(270255125u,b_101bc414);register_block(270255127u,b_101bc416);register_block(270255131u,b_101bc41a);register_block(270255139u,b_101bc422);register_block(270255147u,b_101bc42a);register_block(270255155u,b_101bc432);register_block(270255163u,b_101bc43a);register_block(270255169u,b_101bc440);register_block(270255181u,b_101bc44c);register_block(270255205u,b_101bc464);register_block(270255207u,b_101bc466);register_block(270255219u,b_101bc472);register_block(270255245u,b_101bc48c);register_block(270255247u,b_101bc48e);register_block(270255257u,b_101bc498);register_block(270255293u,b_101bc4bc);register_block(270255299u,b_101bc4c2);register_block(270255319u,b_101bc4d6);register_block(270255349u,b_101bc4f4);register_block(270255359u,b_101bc4fe);register_block(270255365u,b_101bc504);register_block(270255375u,b_101bc50e);register_block(270255389u,b_101bc51c);register_block(270255425u,b_101bc540);register_block(270255431u,b_101bc546);register_block(270255437u,b_101bc54c);register_block(270255449u,b_101bc558);register_block(270255463u,b_101bc566);register_block(270255499u,b_101bc58a);register_block(270255505u,b_101bc590);register_block(270255511u,b_101bc596);register_block(270255523u,b_101bc5a2);register_block(270255537u,b_101bc5b0);register_block(270255575u,b_101bc5d6);register_block(270255585u,b_101bc5e0);register_block(270255591u,b_101bc5e6);register_block(270255601u,b_101bc5f0);register_block(270255607u,b_101bc5f6);register_block(270255613u,b_101bc5fc);register_block(270255623u,b_101bc606);register_block(270255631u,b_101bc60e);register_block(270255639u,b_101bc616);register_block(270255647u,b_101bc61e);register_block(270255657u,b_101bc628);register_block(270255665u,b_101bc630);register_block(270255673u,b_101bc638);register_block(270255681u,b_101bc640);register_block(270255705u,b_101bc658);register_block(270255709u,b_101bc65c);register_block(270255711u,b_101bc65e);register_block(270255715u,b_101bc662);register_block(270255719u,b_101bc666);register_block(270255727u,b_101bc66e);register_block(270255729u,b_101bc670);register_block(270255737u,b_101bc678);register_block(270255743u,b_101bc67e);register_block(270255751u,b_101bc686);register_block(270255757u,b_101bc68c);register_block(270255765u,b_101bc694);register_block(270255769u,b_101bc698);register_block(270255773u,b_101bc69c);register_block(270255787u,b_101bc6aa);register_block(270255809u,b_101bc6c0);register_block(270255833u,b_101bc6d8);register_block(270255887u,b_101bc70e);register_block(270255907u,b_101bc722);register_block(270255929u,b_101bc738);register_block(270255949u,b_101bc74c);register_block(270255971u,b_101bc762);register_block(270255993u,b_101bc778);register_block(270256013u,b_101bc78c);register_block(270256033u,b_101bc7a0);register_block(270256059u,b_101bc7ba);register_block(270256079u,b_101bc7ce);register_block(270256101u,b_101bc7e4);register_block(270256123u,b_101bc7fa);register_block(270256145u,b_101bc810);register_block(270256165u,b_101bc824);register_block(270256179u,b_101bc832);register_block(270256185u,b_101bc838);register_block(270256193u,b_101bc840);register_block(270256203u,b_101bc84a);register_block(270256223u,b_101bc85e);register_block(270256261u,b_101bc884);register_block(270256267u,b_101bc88a);register_block(270256277u,b_101bc894);register_block(270256291u,b_101bc8a2);register_block(270256309u,b_101bc8b4);register_block(270256347u,b_101bc8da);register_block(270256353u,b_101bc8e0);register_block(270256363u,b_101bc8ea);register_block(270256377u,b_101bc8f8);register_block(270256395u,b_101bc90a);register_block(270256435u,b_101bc932);register_block(270256443u,b_101bc93a);register_block(270256477u,b_101bc95c);register_block(270256499u,b_101bc972);register_block(270256511u,b_101bc97e);register_block(270256519u,b_101bc986);register_block(270256527u,b_101bc98e);register_block(270256535u,b_101bc996);register_block(270256543u,b_101bc99e);register_block(270256551u,b_101bc9a6);register_block(270256555u,b_101bc9aa);register_block(270256563u,b_101bc9b2);register_block(270256573u,b_101bc9bc);register_block(270256631u,b_101bc9f6);register_block(270256635u,b_101bc9fa);register_block(270256639u,b_101bc9fe);register_block(270256649u,b_101bca08);register_block(270256653u,b_101bca0c);register_block(270256655u,b_101bca0e);register_block(270256659u,b_101bca12);register_block(270256661u,b_101bca14);register_block(270256665u,b_101bca18);register_block(270256669u,b_101bca1c);register_block(270256673u,b_101bca20);register_block(270256677u,b_101bca24);register_block(270256681u,b_101bca28);register_block(270256685u,b_101bca2c);register_block(270256687u,b_101bca2e);register_block(270256691u,b_101bca32);register_block(270256695u,b_101bca36);register_block(270256699u,b_101bca3a);register_block(270256703u,b_101bca3e);register_block(270256707u,b_101bca42);register_block(270256711u,b_101bca46);register_block(270256715u,b_101bca4a);register_block(270256727u,b_101bca56);register_block(270256733u,b_101bca5c);register_block(270256739u,b_101bca62);register_block(270256745u,b_101bca68);register_block(270256753u,b_101bca70);register_block(270256759u,b_101bca76);register_block(270256763u,b_101bca7a);register_block(270256767u,b_101bca7e);register_block(270256773u,b_101bca84);register_block(270256777u,b_101bca88);register_block(270256785u,b_101bca90);register_block(270256789u,b_101bca94);register_block(270256793u,b_101bca98);register_block(270256795u,b_101bca9a);register_block(270256801u,b_101bcaa0);register_block(270256803u,b_101bcaa2);register_block(270256807u,b_101bcaa6);register_block(270256819u,b_101bcab2);register_block(270256821u,b_101bcab4);register_block(270256827u,b_101bcaba);register_block(270256833u,b_101bcac0);register_block(270256847u,b_101bcace);register_block(270256849u,b_101bcad0);register_block(270256861u,b_101bcadc);register_block(270256869u,b_101bcae4);register_block(270256881u,b_101bcaf0);register_block(270256887u,b_101bcaf6);register_block(270256897u,b_101bcb00);register_block(270256901u,b_101bcb04);register_block(270256917u,b_101bcb14);register_block(270256929u,b_101bcb20);register_block(270256937u,b_101bcb28);register_block(270256955u,b_101bcb3a);register_block(270256963u,b_101bcb42);register_block(270256967u,b_101bcb46);register_block(270256975u,b_101bcb4e);register_block(270256981u,b_101bcb54);register_block(270257021u,b_101bcb7c);register_block(270257037u,b_101bcb8c);register_block(270257041u,b_101bcb90);register_block(270257047u,b_101bcb96);register_block(270257049u,b_101bcb98);register_block(270257057u,b_101bcba0);register_block(270257061u,b_101bcba4);register_block(270257067u,b_101bcbaa);register_block(270257069u,b_101bcbac);register_block(270257073u,b_101bcbb0);register_block(270257081u,b_101bcbb8);register_block(270257093u,b_101bcbc4);register_block(270257103u,b_101bcbce);register_block(270257107u,b_101bcbd2);register_block(270257115u,b_101bcbda);register_block(270257119u,b_101bcbde);register_block(270257125u,b_101bcbe4);register_block(270257131u,b_101bcbea);register_block(270257141u,b_101bcbf4);register_block(270257145u,b_101bcbf8);register_block(270257147u,b_101bcbfa);register_block(270257163u,b_101bcc0a);register_block(270257181u,b_101bcc1c);register_block(270257187u,b_101bcc22);register_block(270257201u,b_101bcc30);register_block(270257205u,b_101bcc34);register_block(270257219u,b_101bcc42);register_block(270257223u,b_101bcc46);register_block(270257235u,b_101bcc52);register_block(270257245u,b_101bcc5c);register_block(270257309u,b_101bcc9c);register_block(270257317u,b_101bcca4);register_block(270257327u,b_101bccae);register_block(270257347u,b_101bccc2);register_block(270257349u,b_101bccc4);register_block(270257357u,b_101bcccc);register_block(270257373u,b_101bccdc);register_block(270257383u,b_101bcce6);register_block(270257397u,b_101bccf4);register_block(270257401u,b_101bccf8);register_block(270257409u,b_101bcd00);register_block(270257411u,b_101bcd02);register_block(270257459u,b_101bcd32);register_block(270257477u,b_101bcd44);register_block(270257495u,b_101bcd56);register_block(270257517u,b_101bcd6c);register_block(270257529u,b_101bcd78);register_block(270257537u,b_101bcd80);register_block(270257545u,b_101bcd88);register_block(270257553u,b_101bcd90);register_block(270257559u,b_101bcd96);register_block(270257567u,b_101bcd9e);register_block(270257575u,b_101bcda6);register_block(270257579u,b_101bcdaa);register_block(270257585u,b_101bcdb0);register_block(270257597u,b_101bcdbc);register_block(270257603u,b_101bcdc2);register_block(270257609u,b_101bcdc8);register_block(270257617u,b_101bcdd0);register_block(270257631u,b_101bcdde);register_block(270257635u,b_101bcde2);register_block(270257643u,b_101bcdea);register_block(270257651u,b_101bcdf2);register_block(270257661u,b_101bcdfc);register_block(270257675u,b_101bce0a);register_block(270257681u,b_101bce10);register_block(270257687u,b_101bce16);register_block(270257693u,b_101bce1c);register_block(270257699u,b_101bce22);register_block(270257705u,b_101bce28);register_block(270257711u,b_101bce2e);register_block(270257717u,b_101bce34);register_block(270257723u,b_101bce3a);register_block(270257729u,b_101bce40);register_block(270257733u,b_101bce44);register_block(270257757u,b_101bce5c);register_block(270257761u,b_101bce60);register_block(270257767u,b_101bce66);register_block(270257771u,b_101bce6a);register_block(270257775u,b_101bce6e);register_block(270257809u,b_101bce90);register_block(270257813u,b_101bce94);register_block(270257819u,b_101bce9a);register_block(270257821u,b_101bce9c);register_block(270257835u,b_101bceaa);register_block(270257861u,b_101bcec4);register_block(270257885u,b_101bcedc);register_block(270257887u,b_101bcede);register_block(270257897u,b_101bcee8);register_block(270257899u,b_101bceea);register_block(270257905u,b_101bcef0);register_block(270257907u,b_101bcef2);register_block(270257911u,b_101bcef6);register_block(270257913u,b_101bcef8);register_block(270257919u,b_101bcefe);register_block(270257921u,b_101bcf00);register_block(270257927u,b_101bcf06);register_block(270257933u,b_101bcf0c);register_block(270257935u,b_101bcf0e);register_block(270257941u,b_101bcf14);register_block(270257943u,b_101bcf16);register_block(270257949u,b_101bcf1c);register_block(270257951u,b_101bcf1e);register_block(270257957u,b_101bcf24);register_block(270257963u,b_101bcf2a);register_block(270257965u,b_101bcf2c);register_block(270257971u,b_101bcf32);register_block(270257977u,b_101bcf38);register_block(270257979u,b_101bcf3a);register_block(270257991u,b_101bcf46);register_block(270257999u,b_101bcf4e);register_block(270258011u,b_101bcf5a);register_block(270258043u,b_101bcf7a);register_block(270258045u,b_101bcf7c);register_block(270258053u,b_101bcf84);register_block(270258057u,b_101bcf88);register_block(270258077u,b_101bcf9c);register_block(270258085u,b_101bcfa4);register_block(270258087u,b_101bcfa6);register_block(270258091u,b_101bcfaa);register_block(270258099u,b_101bcfb2);register_block(270258121u,b_101bcfc8);register_block(270258137u,b_101bcfd8);register_block(270258139u,b_101bcfda);register_block(270258175u,b_101bcffe);register_block(270258209u,b_101bd020);register_block(270258211u,b_101bd022);register_block(270258221u,b_101bd02c);register_block(270258223u,b_101bd02e);register_block(270258229u,b_101bd034);register_block(270258237u,b_101bd03c);register_block(270258245u,b_101bd044);register_block(270258247u,b_101bd046);register_block(270258253u,b_101bd04c);register_block(270258261u,b_101bd054);register_block(270258267u,b_101bd05a);register_block(270258271u,b_101bd05e);register_block(270258273u,b_101bd060);register_block(270258275u,b_101bd062);register_block(270258279u,b_101bd066);register_block(270258287u,b_101bd06e);register_block(270258289u,b_101bd070);register_block(270258295u,b_101bd076);register_block(270258303u,b_101bd07e);register_block(270258305u,b_101bd080);register_block(270258307u,b_101bd082);register_block(270258315u,b_101bd08a);register_block(270258323u,b_101bd092);register_block(270258325u,b_101bd094);register_block(270258333u,b_101bd09c);register_block(270258335u,b_101bd09e);register_block(270258343u,b_101bd0a6);register_block(270258349u,b_101bd0ac);register_block(270258351u,b_101bd0ae);register_block(270258357u,b_101bd0b4);register_block(270258365u,b_101bd0bc);register_block(270258369u,b_101bd0c0);register_block(270258373u,b_101bd0c4);register_block(270258377u,b_101bd0c8);register_block(270258381u,b_101bd0cc);register_block(270258389u,b_101bd0d4);register_block(270258397u,b_101bd0dc);register_block(270258409u,b_101bd0e8);register_block(270258417u,b_101bd0f0);register_block(270258419u,b_101bd0f2);register_block(270258423u,b_101bd0f6);register_block(270258427u,b_101bd0fa);register_block(270258449u,b_101bd110);register_block(270258459u,b_101bd11a);register_block(270258465u,b_101bd120);register_block(270258471u,b_101bd126);register_block(270258473u,b_101bd128);register_block(270258481u,b_101bd130);register_block(270258505u,b_101bd148);register_block(270258539u,b_101bd16a);register_block(270258567u,b_101bd186);register_block(270258585u,b_101bd198);register_block(270258605u,b_101bd1ac);register_block(270258637u,b_101bd1cc);register_block(270258669u,b_101bd1ec);register_block(270258685u,b_101bd1fc);register_block(270258691u,b_101bd202);register_block(270258699u,b_101bd20a);register_block(270258709u,b_101bd214);register_block(270258731u,b_101bd22a);register_block(270258767u,b_101bd24e);register_block(270258773u,b_101bd254);register_block(270258783u,b_101bd25e);register_block(270258797u,b_101bd26c);register_block(270258815u,b_101bd27e);register_block(270258853u,b_101bd2a4);register_block(270258859u,b_101bd2aa);register_block(270258869u,b_101bd2b4);register_block(270258883u,b_101bd2c2);register_block(270258901u,b_101bd2d4);register_block(270258941u,b_101bd2fc);register_block(270258949u,b_101bd304);register_block(270258969u,b_101bd318);register_block(270258987u,b_101bd32a);register_block(270259007u,b_101bd33e);register_block(270259023u,b_101bd34e);register_block(270259029u,b_101bd354);register_block(270259047u,b_101bd366);register_block(270259055u,b_101bd36e);register_block(270259061u,b_101bd374);register_block(270259065u,b_101bd378);register_block(270259079u,b_101bd386);register_block(270259101u,b_101bd39c);register_block(270259121u,b_101bd3b0);register_block(270259139u,b_101bd3c2);register_block(270259141u,b_101bd3c4);register_block(270259147u,b_101bd3ca);register_block(270259153u,b_101bd3d0);register_block(270259155u,b_101bd3d2);register_block(270259159u,b_101bd3d6);register_block(270259163u,b_101bd3da);register_block(270259167u,b_101bd3de);register_block(270259169u,b_101bd3e0);register_block(270259173u,b_101bd3e4);register_block(270259175u,b_101bd3e6);register_block(270259179u,b_101bd3ea);register_block(270259183u,b_101bd3ee);register_block(270259185u,b_101bd3f0);register_block(270259189u,b_101bd3f4);register_block(270259193u,b_101bd3f8);register_block(270259195u,b_101bd3fa);register_block(270259199u,b_101bd3fe);register_block(270259201u,b_101bd400);register_block(270259205u,b_101bd404);register_block(270259209u,b_101bd408);register_block(270259211u,b_101bd40a);register_block(270259215u,b_101bd40e);register_block(270259221u,b_101bd414);register_block(270259223u,b_101bd416);register_block(270259229u,b_101bd41c);register_block(270259235u,b_101bd422);register_block(270259243u,b_101bd42a);register_block(270259245u,b_101bd42c);register_block(270259257u,b_101bd438);register_block(270259263u,b_101bd43e);register_block(270259271u,b_101bd446);register_block(270259273u,b_101bd448);register_block(270259277u,b_101bd44c);register_block(270259285u,b_101bd454);register_block(270259287u,b_101bd456);register_block(270259289u,b_101bd458);register_block(270259295u,b_101bd45e);register_block(270259303u,b_101bd466);register_block(270259313u,b_101bd470);register_block(270259315u,b_101bd472);register_block(270259317u,b_101bd474);register_block(270259329u,b_101bd480);register_block(270259335u,b_101bd486);register_block(270259341u,b_101bd48c);register_block(270259349u,b_101bd494);register_block(270259353u,b_101bd498);register_block(270259359u,b_101bd49e);register_block(270259363u,b_101bd4a2);register_block(270259365u,b_101bd4a4);register_block(270259367u,b_101bd4a6);register_block(270259379u,b_101bd4b2);register_block(270259381u,b_101bd4b4);register_block(270259387u,b_101bd4ba);register_block(270259395u,b_101bd4c2);register_block(270259401u,b_101bd4c8);register_block(270259409u,b_101bd4d0);register_block(270259415u,b_101bd4d6);register_block(270259419u,b_101bd4da);register_block(270259427u,b_101bd4e2);register_block(270259435u,b_101bd4ea);register_block(270259443u,b_101bd4f2);register_block(270259457u,b_101bd500);register_block(270259471u,b_101bd50e);register_block(270259523u,b_101bd542);register_block(270259525u,b_101bd544);register_block(270259535u,b_101bd54e);register_block(270259541u,b_101bd554);register_block(270259547u,b_101bd55a);register_block(270259557u,b_101bd564);register_block(270259579u,b_101bd57a);register_block(270259601u,b_101bd590);register_block(270259603u,b_101bd592);register_block(270259611u,b_101bd59a);register_block(270259619u,b_101bd5a2);register_block(270259627u,b_101bd5aa);register_block(270259635u,b_101bd5b2);register_block(270259643u,b_101bd5ba);register_block(270259651u,b_101bd5c2);register_block(270259661u,b_101bd5cc);register_block(270259665u,b_101bd5d0);register_block(270259689u,b_101bd5e8);register_block(270259723u,b_101bd60a);register_block(270259751u,b_101bd626);register_block(270259769u,b_101bd638);register_block(270259789u,b_101bd64c);register_block(270259821u,b_101bd66c);register_block(270259853u,b_101bd68c);register_block(270259869u,b_101bd69c);register_block(270259875u,b_101bd6a2);register_block(270259883u,b_101bd6aa);register_block(270259893u,b_101bd6b4);register_block(270259915u,b_101bd6ca);register_block(270259951u,b_101bd6ee);register_block(270259957u,b_101bd6f4);register_block(270259967u,b_101bd6fe);register_block(270259981u,b_101bd70c);register_block(270259999u,b_101bd71e);register_block(270260037u,b_101bd744);register_block(270260043u,b_101bd74a);register_block(270260053u,b_101bd754);register_block(270260067u,b_101bd762);register_block(270260085u,b_101bd774);register_block(270260125u,b_101bd79c);register_block(270260133u,b_101bd7a4);register_block(270260153u,b_101bd7b8);register_block(270260171u,b_101bd7ca);register_block(270260183u,b_101bd7d6);register_block(270260191u,b_101bd7de);register_block(270260197u,b_101bd7e4);register_block(270260207u,b_101bd7ee);register_block(270260213u,b_101bd7f4);register_block(270260219u,b_101bd7fa);register_block(270260229u,b_101bd804);register_block(270260235u,b_101bd80a);register_block(270260245u,b_101bd814);register_block(270260253u,b_101bd81c);register_block(270260261u,b_101bd824);register_block(270260269u,b_101bd82c);register_block(270260277u,b_101bd834);register_block(270260291u,b_101bd842);register_block(270260295u,b_101bd846);register_block(270260303u,b_101bd84e);register_block(270260319u,b_101bd85e);register_block(270260325u,b_101bd864);register_block(270260333u,b_101bd86c);register_block(270260337u,b_101bd870);register_block(270260363u,b_101bd88a);register_block(270260365u,b_101bd88c);register_block(270260369u,b_101bd890);register_block(270260385u,b_101bd8a0);register_block(270260391u,b_101bd8a6);register_block(270260403u,b_101bd8b2);register_block(270260407u,b_101bd8b6);register_block(270260421u,b_101bd8c4);register_block(270260443u,b_101bd8da);register_block(270260463u,b_101bd8ee);register_block(270260481u,b_101bd900);register_block(270260483u,b_101bd902);register_block(270260489u,b_101bd908);register_block(270260495u,b_101bd90e);register_block(270260497u,b_101bd910);register_block(270260501u,b_101bd914);register_block(270260505u,b_101bd918);register_block(270260509u,b_101bd91c);register_block(270260511u,b_101bd91e);register_block(270260515u,b_101bd922);register_block(270260517u,b_101bd924);register_block(270260521u,b_101bd928);register_block(270260525u,b_101bd92c);register_block(270260527u,b_101bd92e);register_block(270260531u,b_101bd932);register_block(270260535u,b_101bd936);register_block(270260537u,b_101bd938);register_block(270260541u,b_101bd93c);register_block(270260543u,b_101bd93e);register_block(270260547u,b_101bd942);register_block(270260551u,b_101bd946);register_block(270260553u,b_101bd948);register_block(270260557u,b_101bd94c);register_block(270260563u,b_101bd952);register_block(270260565u,b_101bd954);register_block(270260571u,b_101bd95a);register_block(270260577u,b_101bd960);register_block(270260585u,b_101bd968);register_block(270260587u,b_101bd96a);register_block(270260599u,b_101bd976);register_block(270260605u,b_101bd97c);register_block(270260613u,b_101bd984);register_block(270260615u,b_101bd986);register_block(270260619u,b_101bd98a);register_block(270260627u,b_101bd992);register_block(270260629u,b_101bd994);register_block(270260631u,b_101bd996);register_block(270260637u,b_101bd99c);register_block(270260645u,b_101bd9a4);register_block(270260655u,b_101bd9ae);register_block(270260657u,b_101bd9b0);register_block(270260659u,b_101bd9b2);register_block(270260671u,b_101bd9be);register_block(270260677u,b_101bd9c4);register_block(270260683u,b_101bd9ca);register_block(270260691u,b_101bd9d2);register_block(270260695u,b_101bd9d6);register_block(270260701u,b_101bd9dc);register_block(270260705u,b_101bd9e0);register_block(270260707u,b_101bd9e2);register_block(270260709u,b_101bd9e4);register_block(270260721u,b_101bd9f0);register_block(270260723u,b_101bd9f2);register_block(270260729u,b_101bd9f8);register_block(270260737u,b_101bda00);register_block(270260743u,b_101bda06);register_block(270260751u,b_101bda0e);register_block(270260757u,b_101bda14);register_block(270260761u,b_101bda18);register_block(270260769u,b_101bda20);register_block(270260777u,b_101bda28);register_block(270260785u,b_101bda30);register_block(270260799u,b_101bda3e);register_block(270260813u,b_101bda4c);register_block(270260865u,b_101bda80);register_block(270260867u,b_101bda82);register_block(270260877u,b_101bda8c);register_block(270260883u,b_101bda92);register_block(270260889u,b_101bda98);register_block(270260901u,b_101bdaa4);register_block(270260911u,b_101bdaae);register_block(270260919u,b_101bdab6);register_block(270260923u,b_101bdaba);register_block(270260935u,b_101bdac6);register_block(270260957u,b_101bdadc);register_block(270260959u,b_101bdade);register_block(270260967u,b_101bdae6);register_block(270260973u,b_101bdaec);register_block(270260991u,b_101bdafe);register_block(270261003u,b_101bdb0a);register_block(270261007u,b_101bdb0e);register_block(270261009u,b_101bdb10);register_block(270261013u,b_101bdb14);register_block(270261015u,b_101bdb16);register_block(270261019u,b_101bdb1a);register_block(270261023u,b_101bdb1e);register_block(270261025u,b_101bdb20);register_block(270261029u,b_101bdb24);register_block(270261033u,b_101bdb28);register_block(270261035u,b_101bdb2a);register_block(270261039u,b_101bdb2e);register_block(270261041u,b_101bdb30);register_block(270261045u,b_101bdb34);register_block(270261049u,b_101bdb38);register_block(270261051u,b_101bdb3a);register_block(270261055u,b_101bdb3e);register_block(270261061u,b_101bdb44);register_block(270261063u,b_101bdb46);register_block(270261069u,b_101bdb4c);register_block(270261075u,b_101bdb52);register_block(270261077u,b_101bdb54);register_block(270261089u,b_101bdb60);register_block(270261095u,b_101bdb66);register_block(270261103u,b_101bdb6e);register_block(270261105u,b_101bdb70);register_block(270261109u,b_101bdb74);register_block(270261123u,b_101bdb82);register_block(270261125u,b_101bdb84);register_block(270261131u,b_101bdb8a);register_block(270261133u,b_101bdb8c);register_block(270261139u,b_101bdb92);register_block(270261149u,b_101bdb9c);register_block(270261165u,b_101bdbac);register_block(270261167u,b_101bdbae);register_block(270261173u,b_101bdbb4);register_block(270261183u,b_101bdbbe);register_block(270261197u,b_101bdbcc);register_block(270261199u,b_101bdbce);register_block(270261211u,b_101bdbda);register_block(270261217u,b_101bdbe0);register_block(270261223u,b_101bdbe6);register_block(270261231u,b_101bdbee);register_block(270261235u,b_101bdbf2);register_block(270261241u,b_101bdbf8);register_block(270261251u,b_101bdc02);register_block(270261255u,b_101bdc06);register_block(270261267u,b_101bdc12);register_block(270261305u,b_101bdc38);register_block(270261329u,b_101bdc50);register_block(270261353u,b_101bdc68);register_block(270261377u,b_101bdc80);register_block(270261403u,b_101bdc9a);register_block(270261427u,b_101bdcb2);register_block(270261449u,b_101bdcc8);register_block(270261471u,b_101bdcde);register_block(270261473u,b_101bdce0);register_block(270261483u,b_101bdcea);register_block(270261519u,b_101bdd0e);register_block(270261541u,b_101bdd24);register_block(270261563u,b_101bdd3a);register_block(270261585u,b_101bdd50);register_block(270261607u,b_101bdd66);register_block(270261631u,b_101bdd7e);register_block(270261653u,b_101bdd94);register_block(270261673u,b_101bdda8);register_block(270261693u,b_101bddbc);register_block(270261701u,b_101bddc4);register_block(270261707u,b_101bddca);register_block(270261717u,b_101bddd4);register_block(270261723u,b_101bddda);register_block(270261729u,b_101bdde0);register_block(270261739u,b_101bddea);register_block(270261747u,b_101bddf2);register_block(270261757u,b_101bddfc);register_block(270261763u,b_101bde02);register_block(270261807u,b_101bde2e);register_block(270261809u,b_101bde30);register_block(270261815u,b_101bde36);register_block(270261827u,b_101bde42);register_block(270261837u,b_101bde4c);register_block(270261859u,b_101bde62);register_block(270261923u,b_101bdea2);register_block(270261951u,b_101bdebe);register_block(270262001u,b_101bdef0);register_block(270262053u,b_101bdf24);register_block(270262109u,b_101bdf5c);register_block(270262133u,b_101bdf74);register_block(270262189u,b_101bdfac);register_block(270262205u,b_101bdfbc);register_block(270262211u,b_101bdfc2);register_block(270262221u,b_101bdfcc);register_block(270262229u,b_101bdfd4);register_block(270262277u,b_101be004);register_block(270262287u,b_101be00e);register_block(270262343u,b_101be046);register_block(270262365u,b_101be05c);register_block(270262403u,b_101be082);register_block(270262409u,b_101be088);register_block(270262419u,b_101be092);register_block(270262427u,b_101be09a);register_block(270262465u,b_101be0c0);register_block(270262479u,b_101be0ce);register_block(270262489u,b_101be0d8);register_block(270262569u,b_101be128);register_block(270262605u,b_101be14c);register_block(270262609u,b_101be150);register_block(270262685u,b_101be19c);register_block(270262721u,b_101be1c0);register_block(270262725u,b_101be1c4);register_block(270262789u,b_101be204);register_block(270262825u,b_101be228);register_block(270262829u,b_101be22c);register_block(270262905u,b_101be278);register_block(270262915u,b_101be282);register_block(270262935u,b_101be296);register_block(270262939u,b_101be29a);register_block(270262959u,b_101be2ae);register_block(270262965u,b_101be2b4);register_block(270262975u,b_101be2be);register_block(270262995u,b_101be2d2);register_block(270263001u,b_101be2d8);register_block(270263281u,b_101be3f0);register_block(270263285u,b_101be3f4);register_block(270263293u,b_101be3fc);register_block(270263295u,b_101be3fe);register_block(270263321u,b_101be418);register_block(270263337u,b_101be428);register_block(270263345u,b_101be430);register_block(270263351u,b_101be436);register_block(270263353u,b_101be438);register_block(270263369u,b_101be448);register_block(270263381u,b_101be454);register_block(270263409u,b_101be470);register_block(270263427u,b_101be482);register_block(270263437u,b_101be48c);register_block(270263445u,b_101be494);register_block(270263453u,b_101be49c);register_block(270263459u,b_101be4a2);register_block(270263469u,b_101be4ac);register_block(270263477u,b_101be4b4);}