#include "../aot_runtime.h"
static void b_101afbcc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=140u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(270391848u|1u);return;}
c.pc=270203867u;}
static void b_101afbd0(Context& c){
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(270391848u|1u);return;}
c.pc=270203867u;}
static void b_101afbd2(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(270391848u|1u);return;}
c.pc=270203867u;}
static void b_101afbda(Context& c){
{if(c.r[6] != 0){c.pc=(270203874u|1u);return;}}
c.pc=270203869u;}
static void b_101afbdc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270203794u|1u);return;}
c.pc=270203875u;}
static void b_101afbe2(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{if(c.r[2] != 0){c.pc=(270203984u|1u);return;}}
c.pc=270203881u;}
static void b_101afbe8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270203858u|1u);return;}
c.pc=270203887u;}
static void b_101afbee(Context& c){
{if(c.r[6] != 0){c.pc=(270203894u|1u);return;}}
c.pc=270203889u;}
static void b_101afbf0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{c.pc=(270203794u|1u);return;}
c.pc=270203895u;}
static void b_101afbf6(Context& c){
{uint32_t v=c.r[8];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270203903u;c.pc=(270118736u|1u);return;}
c.pc=270203903u;}
static void b_101afbfe(Context& c){
{if(c.r[0] == 0){c.pc=(270203984u|1u);return;}}
c.pc=270203905u;}
static void b_101afc00(Context& c){
{uint32_t v=140u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270203915u;c.pc=(270391848u|1u);return;}
c.pc=270203915u;}
static void b_101afc0a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=17u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.pc=(270203974u|1u);return;}
c.pc=270203923u;}
static void b_101afc12(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270203984u|1u);return;}}
c.pc=270203929u;}
static void b_101afc18(Context& c){
{uint32_t v=add(c,c.r[9],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270203964u|1u);return;}}
c.pc=270203935u;}
static void b_101afc1e(Context& c){
{uint32_t a=((270203938u&~3u)+0u+56u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=((270203948u&~3u)+0u+48u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270203965u;}
static void b_101afc3c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(270391404u|1u);return;}
c.pc=270203975u;}
static void b_101afc46(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[14]=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;}
{c.pc=(270393366u|1u);return;}
c.pc=270203985u;}
static void b_101afc50(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270203989u;}
static void b_101afc60(Context& c){
{uint32_t a=c.r[13]-8u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270204024u|1u);return;}}
c.pc=270204011u;}
static void b_101afc6a(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+60u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=70u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=~(1u);c.r[3]=v;}
{c.pc=(270204036u|1u);return;}
c.pc=270204025u;}
static void b_101afc78(Context& c){
{uint32_t v=add(c,c.r[3],~(12u),1,true);}
{if(cond(c,2)){c.pc=(270204038u|1u);return;}}
c.pc=270204029u;}
static void b_101afc7c(Context& c){
{uint32_t v=~(69u);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=2u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270204044u&~3u)+0u+64u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{setfs(c,14,30.0);}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setfs(c,15,(fs(c,15))-(fs(c,14)));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{c.r[14]=270204095u;c.pc=(270393746u|1u);return;}
c.pc=270204095u;}
static void b_101afc84(Context& c){
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270204044u&~3u)+0u+64u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{setfs(c,14,30.0);}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setfs(c,15,(fs(c,15))-(fs(c,14)));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{c.r[14]=270204095u;c.pc=(270393746u|1u);return;}
c.pc=270204095u;}
static void b_101afc86(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270204044u&~3u)+0u+64u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{setfs(c,14,30.0);}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setfs(c,15,(fs(c,15))-(fs(c,14)));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{c.r[14]=270204095u;c.pc=(270393746u|1u);return;}
c.pc=270204095u;}
static void b_101afcbe(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(23u),1,true);}
{}
{if(cond(c,14)){uint32_t v=add(c,c.r[3],1u,0,false);c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270204109u;}
static void b_101afcd0(Context& c){
{uint32_t a=c.r[13]-16u;wr<uint32_t>(c,a+0u,c.r[3]);wr<uint32_t>(c,a+4u,c.r[4]);wr<uint32_t>(c,a+8u,c.r[5]);wr<uint32_t>(c,a+12u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+98u);c.r[5]=rd<uint16_t>(c,a+0u);}
{c.r[14]=270204125u;c.pc=(270394904u|1u);return;}
c.pc=270204125u;}
static void b_101afcdc(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270204133u;c.pc=(270398260u|1u);return;}
c.pc=270204133u;}
static void b_101afce4(Context& c){
{uint32_t v=c.r[0];c.r[3]=v;}
{if(c.r[0] == 0){c.pc=(270204180u|1u);return;}}
c.pc=270204137u;}
static void b_101afce8(Context& c){
{uint32_t a=(c.r[0]+0u+292u);c.r[0]=rd<uint32_t>(c,a+0u);}
{if(c.r[0] == 0){c.pc=(270204146u|1u);return;}}
c.pc=270204143u;}
static void b_101afcee(Context& c){
{uint32_t v=add(c,c.r[0],~(284u),1,false);c.r[0]=v;}
{uint32_t v=add(c,c.r[0],~(c.r[3]),1,true);}
{if(cond(c,1)){c.pc=(270204180u|1u);return;}}
c.pc=270204151u;}
static void b_101afcf2(Context& c){
{uint32_t v=add(c,c.r[0],~(c.r[3]),1,true);}
{if(cond(c,1)){c.pc=(270204180u|1u);return;}}
c.pc=270204151u;}
static void b_101afcf6(Context& c){
{uint32_t a=(c.r[0]+0u+98u);c.r[2]=rd<uint16_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(c.r[5]),1,true);}
{if(cond(c,2)){c.pc=(270204170u|1u);return;}}
c.pc=270204159u;}
static void b_101afcfe(Context& c){
{uint32_t v=140u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t a=c.r[13];c.r[3]=rd<uint32_t>(c,a+0u);c.r[4]=rd<uint32_t>(c,a+4u);c.r[5]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270391848u|1u);return;}
c.pc=270204171u;}
static void b_101afd0a(Context& c){
{uint32_t a=(c.r[0]+0u+292u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270204142u|1u);return;}}
c.pc=270204179u;}
static void b_101afd12(Context& c){
{c.pc=(270204150u|1u);return;}
c.pc=270204181u;}
static void b_101afd14(Context& c){
{uint32_t a=c.r[13];c.r[3]=rd<uint32_t>(c,a+0u);c.r[4]=rd<uint32_t>(c,a+4u);c.r[5]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270204183u;}
static void b_101afd18(Context& c){
{uint32_t a=c.r[13]-16u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[3];c.r[5]=v;}
{uint32_t a=(c.r[1]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{if(c.r[3] != 0){c.pc=(270204218u|1u);return;}}
c.pc=270204197u;}
static void b_101afd24(Context& c){
{uint32_t v=add(c,c.r[2],~(40u),1,true);}
{uint32_t v=1u;c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+40u);wr<uint32_t>(c,a+0u,c.r[3]);}
{if(cond(c,1)){c.pc=(270204210u|1u);return;}}
c.pc=270204207u;}
static void b_101afd2e(Context& c){
{uint32_t v=add(c,c.r[2],~(30u),1,true);}
{if(cond(c,2)){c.pc=(270204218u|1u);return;}}
c.pc=270204211u;}
static void b_101afd32(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270204219u;}
static void b_101afd3a(Context& c){
{uint32_t v=add(c,c.r[2],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270204386u|1u);return;}}
c.pc=270204223u;}
static void b_101afd3e(Context& c){
{if(cond(c,13)){c.pc=(270204246u|1u);return;}}
c.pc=270204225u;}
static void b_101afd40(Context& c){
{uint32_t v=add(c,c.r[2],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270204322u|1u);return;}}
c.pc=270204229u;}
static void b_101afd44(Context& c){
{if(cond(c,13)){c.pc=(270204236u|1u);return;}}
c.pc=270204231u;}
static void b_101afd46(Context& c){
{uint32_t v=add(c,c.r[2],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270204268u|1u);return;}}
c.pc=270204235u;}
static void b_101afd4a(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270204237u;}
static void b_101afd4c(Context& c){
{uint32_t v=add(c,c.r[2],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270204368u|1u);return;}}
c.pc=270204241u;}
static void b_101afd50(Context& c){
{uint32_t v=add(c,c.r[2],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270204368u|1u);return;}}
c.pc=270204245u;}
static void b_101afd54(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270204247u;}
static void b_101afd56(Context& c){
{uint32_t v=add(c,c.r[2],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270204428u|1u);return;}}
c.pc=270204251u;}
static void b_101afd5a(Context& c){
{if(cond(c,13)){c.pc=(270204258u|1u);return;}}
c.pc=270204253u;}
static void b_101afd5c(Context& c){
{uint32_t v=add(c,c.r[2],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270204288u|1u);return;}}
c.pc=270204257u;}
static void b_101afd60(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270204259u;}
static void b_101afd62(Context& c){
{uint32_t v=add(c,c.r[2],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270204428u|1u);return;}}
c.pc=270204263u;}
static void b_101afd66(Context& c){
{uint32_t v=add(c,c.r[2],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270204428u|1u);return;}}
c.pc=270204267u;}
static void b_101afd6a(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270204269u;}
static void b_101afd6c(Context& c){
{if(c.r[5] != 0){c.pc=(270204282u|1u);return;}}
c.pc=270204271u;}
static void b_101afd6e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270204283u;c.pc=(270393366u|1u);return;}
c.pc=270204283u;}
static void b_101afd7a(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+44u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270204310u|1u);return;}
c.pc=270204289u;}
static void b_101afd80(Context& c){
{if(c.r[5] != 0){c.pc=(270204310u|1u);return;}}
c.pc=270204291u;}
static void b_101afd82(Context& c){
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270204303u;c.pc=(270393366u|1u);return;}
c.pc=270204303u;}
static void b_101afd8e(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270204311u;c.pc=(270204112u|1u);return;}
c.pc=270204311u;}
static void b_101afd96(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270204000u|1u);return;}
c.pc=270204323u;}
static void b_101afda2(Context& c){
{if(c.r[5] != 0){c.pc=(270204342u|1u);return;}}
c.pc=270204325u;}
static void b_101afda4(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270204337u;c.pc=(270393366u|1u);return;}
c.pc=270204337u;}
static void b_101afdb0(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+44u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270204355u;c.pc=(270204000u|1u);return;}
c.pc=270204355u;}
static void b_101afdb6(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+44u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270204355u;c.pc=(270204000u|1u);return;}
c.pc=270204355u;}
static void b_101afdc2(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270204362u&~3u)+0u+108u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(269978432u|1u);return;}
c.pc=270204369u;}
static void b_101afdd0(Context& c){
{if(c.r[5] != 0){c.pc=(270204406u|1u);return;}}
c.pc=270204371u;}
static void b_101afdd2(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270204383u;c.pc=(270393366u|1u);return;}
c.pc=270204383u;}
static void b_101afdde(Context& c){
{uint32_t a=(c.r[4]+0u+16u);wr<uint32_t>(c,a+0u,c.r[5]);}
{c.pc=(270204420u|1u);return;}
c.pc=270204387u;}
static void b_101afde2(Context& c){
{if(c.r[5] != 0){c.pc=(270204406u|1u);return;}}
c.pc=270204389u;}
static void b_101afde4(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270204401u;c.pc=(270393366u|1u);return;}
c.pc=270204401u;}
static void b_101afdf0(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+16u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270204420u|1u);return;}
c.pc=270204407u;}
static void b_101afdf6(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270204420u|1u);return;}}
c.pc=270204413u;}
static void b_101afdfc(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270204421u;c.pc=(269980032u|1u);return;}
c.pc=270204421u;}
static void b_101afe04(Context& c){
{uint32_t a=(c.r[4]+0u+44u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270204310u|1u);return;}}
c.pc=270204427u;}
static void b_101afe0a(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270204429u;}
static void b_101afe0c(Context& c){
{if(c.r[5] != 0){c.pc=(270204444u|1u);return;}}
c.pc=270204431u;}
static void b_101afe0e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270204443u;c.pc=(270393366u|1u);return;}
c.pc=270204443u;}
static void b_101afe1a(Context& c){
{c.pc=(270204456u|1u);return;}
c.pc=270204445u;}
static void b_101afe1c(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270204456u|1u);return;}}
c.pc=270204451u;}
static void b_101afe22(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270204457u;c.pc=(270391404u|1u);return;}
c.pc=270204457u;}
static void b_101afe28(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270204112u|1u);return;}
c.pc=270204469u;}
static void b_101afe38(Context& c){
{uint32_t a=c.r[13]-12u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=add(c,c.r[13],~(20u),1,false);c.r[13]=v;}
{c.r[14]=270204483u;c.pc=(270394904u|1u);return;}
c.pc=270204483u;}
static void b_101afe42(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270204491u;c.pc=(269978260u|1u);return;}
c.pc=270204491u;}
static void b_101afe4a(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{if(c.r[0] != 0){c.pc=(270204564u|1u);return;}}
c.pc=270204495u;}
static void b_101afe4e(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=38u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],8u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270204507u;c.pc=c.r[3];return;}
c.pc=270204507u;}
static void b_101afe5a(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=39u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270204519u;c.pc=c.r[3];return;}
c.pc=270204519u;}
static void b_101afe66(Context& c){
{uint32_t v=~(36u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+277u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+8u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+12u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270204543u;c.pc=(270393892u|1u);return;}
c.pc=270204543u;}
static void b_101afe7e(Context& c){
{if(c.r[0] == 0){c.pc=(270204564u|1u);return;}}
c.pc=270204545u;}
static void b_101afe80(Context& c){
{uint32_t a=(c.r[4]+0u+240u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[0]+0u+240u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t a=(c.r[0]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+98u);c.r[3]=rd<uint16_t>(c,a+0u);}
{uint32_t a=(c.r[0]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);uint32_t newpc=rd<uint32_t>(c,a+8u);c.r[13]=a+12u;c.pc=newpc;return;}
c.pc=270204569u;}
static void b_101afe94(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);uint32_t newpc=rd<uint32_t>(c,a+8u);c.r[13]=a+12u;c.pc=newpc;return;}
c.pc=270204569u;}
static void b_101afe98(Context& c){
{uint32_t v=add(c,c.r[2],~(50u),1,true);}
{uint32_t a=c.r[13]-32u;wr<uint32_t>(c,a+0u,c.r[0]);wr<uint32_t>(c,a+4u,c.r[1]);wr<uint32_t>(c,a+8u,c.r[2]);wr<uint32_t>(c,a+12u,c.r[3]);wr<uint32_t>(c,a+16u,c.r[4]);wr<uint32_t>(c,a+20u,c.r[5]);wr<uint32_t>(c,a+24u,c.r[6]);wr<uint32_t>(c,a+28u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[3];c.r[5]=v;}
{if(cond(c,1)){c.pc=(270204700u|1u);return;}}
c.pc=270204581u;}
static void b_101afea4(Context& c){
{if(cond(c,13)){c.pc=(270204604u|1u);return;}}
c.pc=270204583u;}
static void b_101afea6(Context& c){
{uint32_t v=add(c,c.r[2],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270204648u|1u);return;}}
c.pc=270204587u;}
static void b_101afeaa(Context& c){
{if(cond(c,13)){c.pc=(270204594u|1u);return;}}
c.pc=270204589u;}
static void b_101afeac(Context& c){
{uint32_t v=add(c,c.r[2],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270204626u|1u);return;}}
c.pc=270204593u;}
static void b_101afeb0(Context& c){
{c.pc=(270204874u|1u);return;}
c.pc=270204595u;}
static void b_101afeb2(Context& c){
{uint32_t v=add(c,c.r[2],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270204684u|1u);return;}}
c.pc=270204599u;}
static void b_101afeb6(Context& c){
{uint32_t v=add(c,c.r[2],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270204684u|1u);return;}}
c.pc=270204603u;}
static void b_101afeba(Context& c){
{c.pc=(270204874u|1u);return;}
c.pc=270204605u;}
static void b_101afebc(Context& c){
{uint32_t v=add(c,c.r[2],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270204776u|1u);return;}}
c.pc=270204609u;}
static void b_101afec0(Context& c){
{if(cond(c,13)){c.pc=(270204616u|1u);return;}}
c.pc=270204611u;}
static void b_101afec2(Context& c){
{uint32_t v=add(c,c.r[2],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270204760u|1u);return;}}
c.pc=270204615u;}
static void b_101afec6(Context& c){
{c.pc=(270204874u|1u);return;}
c.pc=270204617u;}
static void b_101afec8(Context& c){
{uint32_t v=add(c,c.r[2],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270204776u|1u);return;}}
c.pc=270204621u;}
static void b_101afecc(Context& c){
{uint32_t v=add(c,c.r[2],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270204776u|1u);return;}}
c.pc=270204625u;}
static void b_101afed0(Context& c){
{c.pc=(270204874u|1u);return;}
c.pc=270204627u;}
static void b_101afed2(Context& c){
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270204874u|1u);return;}}
c.pc=270204631u;}
static void b_101afed6(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270393366u|1u);return;}
c.pc=270204649u;}
static void b_101afee8(Context& c){
{if(c.r[3] != 0){c.pc=(270204668u|1u);return;}}
c.pc=270204651u;}
static void b_101afeea(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270204663u;c.pc=(270393366u|1u);return;}
c.pc=270204663u;}
static void b_101afef6(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270204676u&~3u)+0u+204u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(269978432u|1u);return;}
c.pc=270204685u;}
static void b_101afefc(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270204676u&~3u)+0u+204u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(269978432u|1u);return;}
c.pc=270204685u;}
static void b_101aff0c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=50u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270391848u|1u);return;}
c.pc=270204701u;}
static void b_101aff1c(Context& c){
{if(c.r[3] != 0){c.pc=(270204728u|1u);return;}}
c.pc=270204703u;}
static void b_101aff1e(Context& c){
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.r[14]=270204715u;c.pc=(270393366u|1u);return;}
c.pc=270204715u;}
static void b_101aff2a(Context& c){
{uint32_t v=c.r[4];c.r[2]=v;}
{uint32_t a=(c.r[2]+0u+0u);uint32_t wb=c.r[2]+16u;c.r[3]=rd<uint32_t>(c,a+0u);c.r[2]=wb;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=36u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.pc=(270204756u|1u);return;}
c.pc=270204729u;}
static void b_101aff38(Context& c){
{uint32_t a=(c.r[1]+0u+16u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{uint32_t v=add(c,c.r[3],4294967295u,0,false);c.r[2]=v;}
{uint32_t a=(c.r[1]+0u+16u);wr<uint32_t>(c,a+0u,c.r[2]);}
{if(cond(c,13)){c.pc=(270204874u|1u);return;}}
c.pc=270204741u;}
static void b_101aff44(Context& c){
{c.r[14]=270204745u;c.pc=(270204472u|1u);return;}
c.pc=270204745u;}
static void b_101aff48(Context& c){
{uint32_t v=c.r[4];c.r[2]=v;}
{uint32_t a=(c.r[2]+0u+0u);uint32_t wb=c.r[2]+16u;c.r[3]=rd<uint32_t>(c,a+0u);c.r[2]=wb;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=37u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270204759u;c.pc=c.r[3];return;}
c.pc=270204759u;}
static void b_101aff54(Context& c){
{c.r[14]=270204759u;c.pc=c.r[3];return;}
c.pc=270204759u;}
static void b_101aff56(Context& c){
{c.pc=(270204874u|1u);return;}
c.pc=270204761u;}
static void b_101aff58(Context& c){
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270204874u|1u);return;}}
c.pc=270204765u;}
static void b_101aff5c(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270393272u|1u);return;}
c.pc=270204777u;}
static void b_101aff68(Context& c){
{if(c.r[5] != 0){c.pc=(270204832u|1u);return;}}
c.pc=270204779u;}
static void b_101aff6a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270204791u;c.pc=(270393366u|1u);return;}
c.pc=270204791u;}
static void b_101aff76(Context& c){
{uint32_t a=(c.r[4]+0u+252u);c.r[0]=rd<uint32_t>(c,a+0u);}
{if(c.r[0] == 0){c.pc=(270204804u|1u);return;}}
c.pc=270204797u;}
static void b_101aff7c(Context& c){
{c.r[14]=270204801u;c.pc=(270391404u|1u);return;}
c.pc=270204801u;}
static void b_101aff80(Context& c){
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=65284u;c.r[3]=v;}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[2]);wr<uint32_t>(c,a+4u,c.r[3]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[2];c.r[3]=v;}
{c.r[14]=270204831u;c.pc=(270015700u|1u);return;}
c.pc=270204831u;}
static void b_101aff84(Context& c){
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=65284u;c.r[3]=v;}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[2]);wr<uint32_t>(c,a+4u,c.r[3]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[2];c.r[3]=v;}
{c.r[14]=270204831u;c.pc=(270015700u|1u);return;}
c.pc=270204831u;}
static void b_101aff9e(Context& c){
{c.pc=(270204874u|1u);return;}
c.pc=270204833u;}
static void b_101affa0(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{if(c.r[2] != 0){c.pc=(270204874u|1u);return;}}
c.pc=270204839u;}
static void b_101affa6(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=65284u;c.r[3]=v;}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[2];c.r[3]=v;}
{c.r[14]=270204863u;c.pc=(270015700u|1u);return;}
c.pc=270204863u;}
static void b_101affbe(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270391404u|1u);return;}
c.pc=270204875u;}
static void b_101affca(Context& c){
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270204879u;}
static void b_101affd4(Context& c){
{uint32_t a=c.r[13]-12u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=add(c,c.r[13],~(20u),1,false);c.r[13]=v;}
{c.r[14]=270204895u;c.pc=(270394904u|1u);return;}
c.pc=270204895u;}
static void b_101affde(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+116u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270204903u;c.pc=(269978260u|1u);return;}
c.pc=270204903u;}
static void b_101affe6(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{if(c.r[0] != 0){c.pc=(270204948u|1u);return;}}
c.pc=270204907u;}
static void b_101affea(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270204919u;c.pc=c.r[3];return;}
c.pc=270204919u;}
static void b_101afff6(Context& c){
{uint32_t a=(c.r[4]+0u+277u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=83u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+12u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270204939u;c.pc=(270393892u|1u);return;}
c.pc=270204939u;}
static void b_101b000a(Context& c){
{if(c.r[0] == 0){c.pc=(270204948u|1u);return;}}
c.pc=270204941u;}
static void b_101b000c(Context& c){
{uint32_t a=(c.r[4]+0u+240u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[0]+0u+240u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);uint32_t newpc=rd<uint32_t>(c,a+8u);c.r[13]=a+12u;c.pc=newpc;return;}
c.pc=270204953u;}
static void b_101b0014(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);uint32_t newpc=rd<uint32_t>(c,a+8u);c.r[13]=a+12u;c.pc=newpc;return;}
c.pc=270204953u;}
static void b_101b0018(Context& c){
{uint32_t a=c.r[13]-24u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=add(c,c.r[13],~(24u),1,false);c.r[13]=v;}
{uint32_t v=c.r[2];c.r[6]=v;}
{uint32_t v=c.r[3];c.r[5]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{c.r[14]=270204971u;c.pc=(270394904u|1u);return;}
c.pc=270204971u;}
static void b_101b002a(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270204979u;c.pc=(270398272u|1u);return;}
c.pc=270204979u;}
static void b_101b0032(Context& c){
{uint32_t v=add(c,c.r[6],~(70u),1,true);}
{uint32_t v=c.r[0];c.r[8]=v;}
{if(cond(c,1)){c.pc=(270205244u|1u);return;}}
c.pc=270204987u;}
static void b_101b003a(Context& c){
{if(cond(c,13)){c.pc=(270205014u|1u);return;}}
c.pc=270204989u;}
static void b_101b003c(Context& c){
{uint32_t v=add(c,c.r[6],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270205086u|1u);return;}}
c.pc=270204993u;}
static void b_101b0040(Context& c){
{if(cond(c,13)){c.pc=(270205004u|1u);return;}}
c.pc=270204995u;}
static void b_101b0042(Context& c){
{uint32_t v=add(c,c.r[6],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270205046u|1u);return;}}
c.pc=270204999u;}
static void b_101b0046(Context& c){
{uint32_t v=add(c,c.r[6],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270205058u|1u);return;}}
c.pc=270205003u;}
static void b_101b004a(Context& c){
{c.pc=(270205496u|1u);return;}
c.pc=270205005u;}
static void b_101b004c(Context& c){
{uint32_t v=add(c,c.r[6],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270205096u|1u);return;}}
c.pc=270205009u;}
static void b_101b0050(Context& c){
{uint32_t v=add(c,c.r[6],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270205130u|1u);return;}}
c.pc=270205013u;}
static void b_101b0054(Context& c){
{c.pc=(270205496u|1u);return;}
c.pc=270205015u;}
static void b_101b0056(Context& c){
{uint32_t v=add(c,c.r[6],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270205292u|1u);return;}}
c.pc=270205021u;}
static void b_101b005c(Context& c){
{if(cond(c,13)){c.pc=(270205034u|1u);return;}}
c.pc=270205023u;}
static void b_101b005e(Context& c){
{uint32_t v=add(c,c.r[6],~(80u),1,true);}
{if(cond(c,1)){c.pc=(270205200u|1u);return;}}
c.pc=270205027u;}
static void b_101b0062(Context& c){
{uint32_t v=add(c,c.r[6],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270205292u|1u);return;}}
c.pc=270205033u;}
static void b_101b0068(Context& c){
{c.pc=(270205496u|1u);return;}
c.pc=270205035u;}
static void b_101b006a(Context& c){
{uint32_t v=add(c,c.r[6],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270205292u|1u);return;}}
c.pc=270205039u;}
static void b_101b006e(Context& c){
{uint32_t v=add(c,c.r[6],~(141u),1,true);}
{if(cond(c,1)){c.pc=(270205436u|1u);return;}}
c.pc=270205045u;}
static void b_101b0074(Context& c){
{c.pc=(270205496u|1u);return;}
c.pc=270205047u;}
static void b_101b0076(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270205496u|1u);return;}}
c.pc=270205053u;}
static void b_101b007c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270205092u|1u);return;}
c.pc=270205059u;}
static void b_101b0082(Context& c){
{if(c.r[5] != 0){c.pc=(270205078u|1u);return;}}
c.pc=270205061u;}
static void b_101b0084(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270205073u;c.pc=(270393366u|1u);return;}
c.pc=270205073u;}
static void b_101b0090(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270205086u&~3u)+0u+420u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270205234u|1u);return;}
c.pc=270205087u;}
static void b_101b0096(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270205086u&~3u)+0u+420u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270205234u|1u);return;}
c.pc=270205087u;}
static void b_101b009e(Context& c){
{if(c.r[5] != 0){c.pc=(270205104u|1u);return;}}
c.pc=270205089u;}
static void b_101b00a0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.pc=(270205484u|1u);return;}
c.pc=270205097u;}
static void b_101b00a4(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{c.pc=(270205484u|1u);return;}
c.pc=270205097u;}
static void b_101b00a8(Context& c){
{if(c.r[5] != 0){c.pc=(270205104u|1u);return;}}
c.pc=270205099u;}
static void b_101b00aa(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{c.pc=(270205092u|1u);return;}
c.pc=270205105u;}
static void b_101b00b0(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270205496u|1u);return;}}
c.pc=270205115u;}
static void b_101b00ba(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(269980032u|1u);return;}
c.pc=270205131u;}
static void b_101b00ca(Context& c){
{if(c.r[5] != 0){c.pc=(270205138u|1u);return;}}
c.pc=270205133u;}
static void b_101b00cc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270205092u|1u);return;}
c.pc=270205139u;}
static void b_101b00d2(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270205147u;c.pc=(270118736u|1u);return;}
c.pc=270205147u;}
static void b_101b00da(Context& c){
{if(c.r[0] == 0){c.pc=(270205156u|1u);return;}}
c.pc=270205149u;}
static void b_101b00dc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=33u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.pc=(270205484u|1u);return;}
c.pc=270205157u;}
static void b_101b00e4(Context& c){
{uint32_t a=(c.r[4]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(33u),1,true);}
{if(cond(c,2)){c.pc=(270205496u|1u);return;}}
c.pc=270205167u;}
static void b_101b00ee(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270205496u|1u);return;}}
c.pc=270205177u;}
static void b_101b00f8(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=50u;nz(c,v);c.r[2]=v;}
{c.r[14]=270205187u;c.pc=(269980032u|1u);return;}
c.pc=270205187u;}
static void b_101b0102(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(269975948u|1u);return;}
c.pc=270205201u;}
static void b_101b0110(Context& c){
{if(c.r[5] != 0){c.pc=(270205216u|1u);return;}}
c.pc=270205203u;}
static void b_101b0112(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270205215u;c.pc=(270393366u|1u);return;}
c.pc=270205215u;}
static void b_101b011e(Context& c){
{c.pc=(270205228u|1u);return;}
c.pc=270205217u;}
static void b_101b0120(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270205228u|1u);return;}}
c.pc=270205223u;}
static void b_101b0126(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(269978432u|1u);return;}
c.pc=270205245u;}
static void b_101b012c(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(269978432u|1u);return;}
c.pc=270205245u;}
static void b_101b0132(Context& c){
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(269978432u|1u);return;}
c.pc=270205245u;}
static void b_101b013c(Context& c){
{if(c.r[5] != 0){c.pc=(270205258u|1u);return;}}
c.pc=270205247u;}
static void b_101b013e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270205259u;c.pc=(270393366u|1u);return;}
c.pc=270205259u;}
static void b_101b014a(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270205267u;c.pc=(270118736u|1u);return;}
c.pc=270205267u;}
static void b_101b0152(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270205148u|1u);return;}}
c.pc=270205271u;}
static void b_101b0156(Context& c){
{uint32_t a=(c.r[4]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(33u),1,true);}
{if(cond(c,2)){c.pc=(270205496u|1u);return;}}
c.pc=270205279u;}
static void b_101b015e(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270205496u|1u);return;}}
c.pc=270205287u;}
static void b_101b0166(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270205484u|1u);return;}
c.pc=270205293u;}
static void b_101b016c(Context& c){
{if(c.r[5] != 0){c.pc=(270205326u|1u);return;}}
c.pc=270205295u;}
static void b_101b016e(Context& c){
{uint32_t v=65284u;c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270205321u;c.pc=(270015700u|1u);return;}
c.pc=270205321u;}
static void b_101b0188(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=14u;nz(c,v);c.r[1]=v;}
{c.pc=(270205092u|1u);return;}
c.pc=270205327u;}
static void b_101b018e(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[5]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270205496u|1u);return;}}
c.pc=270205335u;}
static void b_101b0196(Context& c){
{uint32_t v=65284u;c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270205361u;c.pc=(270015700u|1u);return;}
c.pc=270205361u;}
static void b_101b01b0(Context& c){
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t v=12u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[2]);wr<uint32_t>(c,a+4u,c.r[3]);}
{uint32_t a=((270205372u&~3u)+0u+136u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=((270205382u&~3u)+0u+132u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=1082130432u;c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=((270205392u&~3u)+0u+124u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=~(39u);c.r[3]=v;}
{c.r[14]=270205401u;c.pc=(270082284u|1u);return;}
c.pc=270205401u;}
static void b_101b01d8(Context& c){
{uint32_t a=(c.r[8]+0u+776u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,13)){c.pc=(270205420u|1u);return;}}
c.pc=270205409u;}
static void b_101b01e0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270391404u|1u);return;}
c.pc=270205421u;}
static void b_101b01ec(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=141u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270391848u|1u);return;}
c.pc=270205437u;}
static void b_101b01fc(Context& c){
{if(c.r[5] != 0){c.pc=(270205444u|1u);return;}}
c.pc=270205439u;}
static void b_101b01fe(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=35u;nz(c,v);c.r[1]=v;}
{c.pc=(270205092u|1u);return;}
c.pc=270205445u;}
static void b_101b0204(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270205453u;c.pc=(270118736u|1u);return;}
c.pc=270205453u;}
static void b_101b020c(Context& c){
{if(c.r[0] == 0){c.pc=(270205460u|1u);return;}}
c.pc=270205455u;}
static void b_101b020e(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270205496u|1u);return;}
c.pc=270205461u;}
static void b_101b0214(Context& c){
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270205496u|1u);return;}}
c.pc=270205467u;}
static void b_101b021a(Context& c){
{uint32_t a=(c.r[8]+0u+776u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,14)){c.pc=(270205408u|1u);return;}}
c.pc=270205475u;}
static void b_101b0222(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270205483u;c.pc=(270204884u|1u);return;}
c.pc=270205483u;}
static void b_101b022a(Context& c){
{c.pc=(270205408u|1u);return;}
c.pc=270205485u;}
static void b_101b022c(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270393366u|1u);return;}
c.pc=270205497u;}
static void b_101b0238(Context& c){
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270205503u;}
static void b_101b0250(Context& c){
{uint32_t a=c.r[13]-8u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270205544u|1u);return;}}
c.pc=270205531u;}
static void b_101b025a(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+60u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=~(99u);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=5u;nz(c,v);c.r[3]=v;}
{c.pc=(270205556u|1u);return;}
c.pc=270205545u;}
static void b_101b0268(Context& c){
{uint32_t v=add(c,c.r[3],~(40u),1,true);}
{if(cond(c,2)){c.pc=(270205558u|1u);return;}}
c.pc=270205549u;}
static void b_101b026c(Context& c){
{uint32_t v=100u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=~(4u);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270205564u&~3u)+0u+56u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
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
{c.r[14]=270205607u;c.pc=(270393746u|1u);return;}
c.pc=270205607u;}
static void b_101b0274(Context& c){
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270205564u&~3u)+0u+56u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
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
{c.r[14]=270205607u;c.pc=(270393746u|1u);return;}
c.pc=270205607u;}
static void b_101b0276(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270205564u&~3u)+0u+56u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
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
{c.r[14]=270205607u;c.pc=(270393746u|1u);return;}
c.pc=270205607u;}
static void b_101b02a6(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(77u),1,true);}
{}
{if(cond(c,14)){uint32_t v=add(c,c.r[3],1u,0,false);c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270205621u;}
static void b_101b02b8(Context& c){
{uint32_t a=c.r[13]-28u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[14]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(20u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[3];c.r[6]=v;}
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[2];c.r[7]=v;}
{c.r[14]=270205643u;c.pc=(270326600u|1u);return;}
c.pc=270205643u;}
static void b_101b02ca(Context& c){
{uint32_t v=add(c,c.r[0],18432u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(5u),1,true);c.r[3]=v;}
{uint32_t v=add(c,0u,~(c.r[3]),1,true);c.r[8]=v;}
{uint32_t v=add(c,c.r[8],c.r[3],c.c,true);c.r[8]=v;}
{uint32_t a=(c.r[4]+0u+52u);c.r[3]=rd<uint32_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270205756u|1u);return;}}
c.pc=270205663u;}
static void b_101b02de(Context& c){
{uint32_t v=1u;c.r[9]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270205756u|1u);return;}}
c.pc=270205677u;}
static void b_101b02ec(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{c.r[14]=270205685u;c.pc=(269975400u|1u);return;}
c.pc=270205685u;}
static void b_101b02f4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{c.r[14]=270205693u;c.pc=(269975962u|1u);return;}
c.pc=270205693u;}
static void b_101b02fc(Context& c){
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270205701u;c.pc=(269975768u|1u);return;}
c.pc=270205701u;}
static void b_101b0304(Context& c){
{c.r[14]=270205705u;c.pc=(270394904u|1u);return;}
c.pc=270205705u;}
static void b_101b0308(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[8];c.r[2]=v;}
{c.r[14]=270205713u;c.pc=(270398272u|1u);return;}
c.pc=270205713u;}
static void b_101b0310(Context& c){
{uint32_t a=(c.r[0]+0u+140u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270205739u;c.pc=(270408416u|1u);return;}
c.pc=270205739u;}
static void b_101b032a(Context& c){
{uint32_t a=(c.r[0]+0u+8u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(16u),1,true);}
{if(cond(c,2)){c.pc=(270205756u|1u);return;}}
c.pc=270205745u;}
static void b_101b0330(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+156u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270205757u;c.pc=c.r[3];return;}
c.pc=270205757u;}
static void b_101b033c(Context& c){
{uint32_t v=add(c,c.r[7],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270206148u|1u);return;}}
c.pc=270205763u;}
static void b_101b0342(Context& c){
{uint32_t v=add(c,c.r[7],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270206148u|1u);return;}}
c.pc=270205769u;}
static void b_101b0348(Context& c){
{uint32_t v=add(c,c.r[7],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270206148u|1u);return;}}
c.pc=270205775u;}
static void b_101b034e(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270205858u|1u);return;}}
c.pc=270205781u;}
static void b_101b0354(Context& c){
{uint32_t a=(c.r[4]+0u+52u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270205832u|1u);return;}}
c.pc=270205787u;}
static void b_101b035a(Context& c){
{if(c.r[6] != 0){c.pc=(270205798u|1u);return;}}
c.pc=270205789u;}
static void b_101b035c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=81u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.r[14]=270205799u;c.pc=(270393366u|1u);return;}
c.pc=270205799u;}
static void b_101b0366(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270205807u;c.pc=(270118736u|1u);return;}
c.pc=270205807u;}
static void b_101b036e(Context& c){
{if(c.r[0] == 0){c.pc=(270205820u|1u);return;}}
c.pc=270205809u;}
static void b_101b0370(Context& c){
{uint32_t v=2u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=82u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.pc=(270206030u|1u);return;}
c.pc=270205821u;}
static void b_101b037c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=((270205826u&~3u)+0u+640u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.pc=(270206214u|1u);return;}
c.pc=270205833u;}
static void b_101b0388(Context& c){
{uint32_t v=add(c,c.r[3],~(2u),1,true);}
{if(cond(c,2)){c.pc=(270205866u|1u);return;}}
c.pc=270205837u;}
static void b_101b038c(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270206538u|1u);return;}}
c.pc=270205847u;}
static void b_101b0396(Context& c){
{uint32_t a=(c.r[4]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(82u),1,true);}
{if(cond(c,2)){c.pc=(270206538u|1u);return;}}
c.pc=270205857u;}
static void b_101b03a0(Context& c){
{c.pc=(270206472u|1u);return;}
c.pc=270205859u;}
static void b_101b03a2(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{c.r[14]=270205867u;c.pc=(269975400u|1u);return;}
c.pc=270205867u;}
static void b_101b03aa(Context& c){
{uint32_t v=add(c,c.r[7],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270206022u|1u);return;}}
c.pc=270205871u;}
static void b_101b03ae(Context& c){
{if(cond(c,13)){c.pc=(270205894u|1u);return;}}
c.pc=270205873u;}
static void b_101b03b0(Context& c){
{uint32_t v=add(c,c.r[7],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270205950u|1u);return;}}
c.pc=270205877u;}
static void b_101b03b4(Context& c){
{if(cond(c,13)){c.pc=(270205884u|1u);return;}}
c.pc=270205879u;}
static void b_101b03b6(Context& c){
{uint32_t v=add(c,c.r[7],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270205922u|1u);return;}}
c.pc=270205883u;}
static void b_101b03ba(Context& c){
{c.pc=(270206538u|1u);return;}
c.pc=270205885u;}
static void b_101b03bc(Context& c){
{uint32_t v=add(c,c.r[7],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270205986u|1u);return;}}
c.pc=270205889u;}
static void b_101b03c0(Context& c){
{uint32_t v=add(c,c.r[7],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270205994u|1u);return;}}
c.pc=270205893u;}
static void b_101b03c4(Context& c){
{c.pc=(270206538u|1u);return;}
c.pc=270205895u;}
static void b_101b03c6(Context& c){
{uint32_t v=add(c,c.r[7],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270206148u|1u);return;}}
c.pc=270205899u;}
static void b_101b03ca(Context& c){
{if(cond(c,13)){c.pc=(270205910u|1u);return;}}
c.pc=270205901u;}
static void b_101b03cc(Context& c){
{uint32_t v=add(c,c.r[7],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270206068u|1u);return;}}
c.pc=270205905u;}
static void b_101b03d0(Context& c){
{uint32_t v=add(c,c.r[7],~(80u),1,true);}
{if(cond(c,1)){c.pc=(270206094u|1u);return;}}
c.pc=270205909u;}
static void b_101b03d4(Context& c){
{c.pc=(270206538u|1u);return;}
c.pc=270205911u;}
static void b_101b03d6(Context& c){
{uint32_t v=add(c,c.r[7],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270206148u|1u);return;}}
c.pc=270205915u;}
static void b_101b03da(Context& c){
{uint32_t v=add(c,c.r[7],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270206452u|1u);return;}}
c.pc=270205921u;}
static void b_101b03e0(Context& c){
{c.pc=(270206538u|1u);return;}
c.pc=270205923u;}
static void b_101b03e2(Context& c){
{if(c.r[6] != 0){c.pc=(270205936u|1u);return;}}
c.pc=270205925u;}
static void b_101b03e4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270205937u;c.pc=(270393366u|1u);return;}
c.pc=270205937u;}
static void b_101b03e8(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270205937u;c.pc=(270393366u|1u);return;}
c.pc=270205937u;}
static void b_101b03f0(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[14]=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;}
{c.pc=(270205520u|1u);return;}
c.pc=270205951u;}
static void b_101b03fe(Context& c){
{if(c.r[6] != 0){c.pc=(270205970u|1u);return;}}
c.pc=270205953u;}
static void b_101b0400(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.r[14]=270205965u;c.pc=(270393366u|1u);return;}
c.pc=270205965u;}
static void b_101b040c(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270205979u;c.pc=(270205520u|1u);return;}
c.pc=270205979u;}
static void b_101b0412(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270205979u;c.pc=(270205520u|1u);return;}
c.pc=270205979u;}
static void b_101b041a(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270205986u&~3u)+0u+484u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270206138u|1u);return;}
c.pc=270205987u;}
static void b_101b0422(Context& c){
{if(c.r[6] != 0){c.pc=(270206002u|1u);return;}}
c.pc=270205989u;}
static void b_101b0424(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{c.pc=(270205928u|1u);return;}
c.pc=270205995u;}
static void b_101b042a(Context& c){
{if(c.r[6] != 0){c.pc=(270206002u|1u);return;}}
c.pc=270205997u;}
static void b_101b042c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{c.pc=(270205928u|1u);return;}
c.pc=270206003u;}
static void b_101b0432(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270205936u|1u);return;}}
c.pc=270206011u;}
static void b_101b043a(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[7];c.r[2]=v;}
{c.r[14]=270206021u;c.pc=(269980032u|1u);return;}
c.pc=270206021u;}
static void b_101b0444(Context& c){
{c.pc=(270205936u|1u);return;}
c.pc=270206023u;}
static void b_101b0446(Context& c){
{if(c.r[6] != 0){c.pc=(270206042u|1u);return;}}
c.pc=270206025u;}
static void b_101b0448(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[14]=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;}
{c.pc=(270393366u|1u);return;}
c.pc=270206043u;}
static void b_101b044e(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[14]=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;}
{c.pc=(270393366u|1u);return;}
c.pc=270206043u;}
static void b_101b045a(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270206538u|1u);return;}}
c.pc=270206053u;}
static void b_101b0464(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[7];c.r[2]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[14]=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;}
{c.pc=(269980032u|1u);return;}
c.pc=270206069u;}
static void b_101b0474(Context& c){
{if(c.r[6] != 0){c.pc=(270206076u|1u);return;}}
c.pc=270206071u;}
static void b_101b0476(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270205928u|1u);return;}
c.pc=270206077u;}
static void b_101b047c(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270205936u|1u);return;}}
c.pc=270206085u;}
static void b_101b0484(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.r[14]=270206093u;c.pc=(270391848u|1u);return;}
c.pc=270206093u;}
static void b_101b048c(Context& c){
{c.pc=(270205936u|1u);return;}
c.pc=270206095u;}
static void b_101b048e(Context& c){
{if(c.r[6] != 0){c.pc=(270206114u|1u);return;}}
c.pc=270206097u;}
static void b_101b0490(Context& c){
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270206109u;c.pc=(270393366u|1u);return;}
c.pc=270206109u;}
static void b_101b049c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.pc=(270206128u|1u);return;}
c.pc=270206115u;}
static void b_101b04a2(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[1]=rd<uint8_t>(c,a+0u);}
{if(c.r[1] != 0){c.pc=(270206132u|1u);return;}}
c.pc=270206121u;}
static void b_101b04a8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270206133u;c.pc=(269975768u|1u);return;}
c.pc=270206133u;}
static void b_101b04b0(Context& c){
{c.r[14]=270206133u;c.pc=(269975768u|1u);return;}
c.pc=270206133u;}
static void b_101b04b4(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[14]=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;}
{c.pc=(269978432u|1u);return;}
c.pc=270206149u;}
static void b_101b04ba(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[14]=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;}
{c.pc=(269978432u|1u);return;}
c.pc=270206149u;}
static void b_101b04c4(Context& c){
{if(c.r[6] != 0){c.pc=(270206224u|1u);return;}}
c.pc=270206151u;}
static void b_101b04c6(Context& c){
{uint32_t v=1u;c.r[8]=v;}
{uint32_t v=65284u;c.r[3]=v;}
{uint32_t v=4294967295u;c.r[7]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(19u);c.r[2]=v;}
{uint32_t v=~(164u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270206187u;c.pc=(270015700u|1u);return;}
c.pc=270206187u;}
static void b_101b04ea(Context& c){
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=c.r[8];c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270206199u;c.pc=(270393366u|1u);return;}
c.pc=270206199u;}
static void b_101b04f6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270206205u;c.pc=(270393272u|1u);return;}
c.pc=270206205u;}
static void b_101b04fc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1073741824u;c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[7];c.r[3]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[14]=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;}
{c.pc=(270392910u|1u);return;}
c.pc=270206225u;}
static void b_101b0506(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[14]=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;}
{c.pc=(270392910u|1u);return;}
c.pc=270206225u;}
static void b_101b0510(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[9]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[9],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270206538u|1u);return;}}
c.pc=270206237u;}
static void b_101b051c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;c.r[8]=v;}
{uint32_t v=65284u;c.r[7]=v;}
{uint32_t v=4294967295u;c.r[6]=v;}
{c.r[14]=270206255u;c.pc=(270393272u|1u);return;}
c.pc=270206255u;}
static void b_101b052e(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=40u;nz(c,v);c.r[2]=v;}
{uint32_t v=~(159u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270206277u;c.pc=(270015700u|1u);return;}
c.pc=270206277u;}
static void b_101b0544(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[9];c.r[2]=v;}
{uint32_t v=~(119u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270206299u;c.pc=(270015700u|1u);return;}
c.pc=270206299u;}
static void b_101b055a(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(29u);c.r[2]=v;}
{uint32_t v=~(119u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270206323u;c.pc=(270015700u|1u);return;}
c.pc=270206323u;}
static void b_101b0572(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=80u;nz(c,v);c.r[2]=v;}
{uint32_t v=~(59u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270206345u;c.pc=(270015700u|1u);return;}
c.pc=270206345u;}
static void b_101b0588(Context& c){
{uint32_t v=~(119u);c.r[2]=v;}
{uint32_t v=c.r[2];c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270206367u;c.pc=(270015700u|1u);return;}
c.pc=270206367u;}
static void b_101b059e(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(19u);c.r[2]=v;}
{uint32_t v=~(39u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270206391u;c.pc=(270015700u|1u);return;}
c.pc=270206391u;}
static void b_101b05b6(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(79u);c.r[2]=v;}
{uint32_t v=50u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270206413u;c.pc=(270015700u|1u);return;}
c.pc=270206413u;}
static void b_101b05cc(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=50u;nz(c,v);c.r[2]=v;}
{uint32_t v=30u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270206433u;c.pc=(270015700u|1u);return;}
c.pc=270206433u;}
static void b_101b05e0(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=140u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[9];c.r[3]=v;}
{c.r[14]=270206453u;c.pc=(270015700u|1u);return;}
c.pc=270206453u;}
static void b_101b05f4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[14]=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;}
{c.pc=(270391404u|1u);return;}
c.pc=270206465u;}
static void b_101b0608(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270206481u;c.pc=(269975400u|1u);return;}
c.pc=270206481u;}
static void b_101b0610(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270206489u;c.pc=(269975768u|1u);return;}
c.pc=270206489u;}
static void b_101b0618(Context& c){
{c.r[14]=270206493u;c.pc=(270408416u|1u);return;}
c.pc=270206493u;}
static void b_101b061c(Context& c){
{uint32_t a=(c.r[0]+0u+8u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(16u),1,true);}
{if(cond(c,1)){c.pc=(270206506u|1u);return;}}
c.pc=270206499u;}
static void b_101b0622(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270206507u;c.pc=(269975962u|1u);return;}
c.pc=270206507u;}
static void b_101b062a(Context& c){
{uint32_t v=3u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270206523u;c.pc=(270393366u|1u);return;}
c.pc=270206523u;}
static void b_101b063a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[14]=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;}
{c.pc=(270391848u|1u);return;}
c.pc=270206539u;}
static void b_101b064a(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);uint32_t newpc=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;c.pc=newpc;return;}
c.pc=270206545u;}
static void b_101b0650(Context& c){
{uint32_t a=c.r[13]-8u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270206568u|1u);return;}}
c.pc=270206555u;}
static void b_101b065a(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+60u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=40u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+40u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=~(1u);c.r[3]=v;}
{c.pc=(270206580u|1u);return;}
c.pc=270206569u;}
static void b_101b0668(Context& c){
{uint32_t v=add(c,c.r[3],~(12u),1,true);}
{if(cond(c,2)){c.pc=(270206582u|1u);return;}}
c.pc=270206573u;}
static void b_101b066c(Context& c){
{uint32_t v=~(39u);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+40u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=2u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+44u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+40u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270206588u&~3u)+0u+56u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+44u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+40u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{c.r[14]=270206631u;c.pc=(270393746u|1u);return;}
c.pc=270206631u;}
static void b_101b0674(Context& c){
{uint32_t a=(c.r[4]+0u+44u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+40u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270206588u&~3u)+0u+56u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+44u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+40u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{c.r[14]=270206631u;c.pc=(270393746u|1u);return;}
c.pc=270206631u;}
static void b_101b0676(Context& c){
{uint32_t a=(c.r[4]+0u+40u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270206588u&~3u)+0u+56u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+44u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+40u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{c.r[14]=270206631u;c.pc=(270393746u|1u);return;}
c.pc=270206631u;}
static void b_101b06a6(Context& c){
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(23u),1,true);}
{}
{if(cond(c,14)){uint32_t v=add(c,c.r[3],1u,0,false);c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270206645u;}
static void b_101b06b8(Context& c){
{uint32_t a=c.r[13]-36u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[11]);wr<uint32_t>(c,a+32u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-16u;wr<uint64_t>(c,a+0u,c.d[8]);wr<uint64_t>(c,a+8u,c.d[9]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(44u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[3];c.r[5]=v;}
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=c.r[2];c.r[7]=v;}
{c.r[14]=270206671u;c.pc=(270326600u|1u);return;}
c.pc=270206671u;}
static void b_101b06ce(Context& c){
{uint32_t v=add(c,c.r[0],18432u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(5u),1,true);c.r[3]=v;}
{uint32_t v=add(c,0u,~(c.r[3]),1,true);c.r[8]=v;}
{uint32_t v=add(c,c.r[8],c.r[3],c.c,true);c.r[8]=v;}
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270206792u|1u);return;}}
c.pc=270206691u;}
static void b_101b06e2(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270206752u|1u);return;}}
c.pc=270206701u;}
static void b_101b06ec(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{if(cond(c,2)){c.pc=(270206718u|1u);return;}}
c.pc=270206707u;}
static void b_101b06f2(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270206742u|1u);return;}
c.pc=270206719u;}
static void b_101b06fe(Context& c){
{c.r[14]=270206723u;c.pc=(270408416u|1u);return;}
c.pc=270206723u;}
static void b_101b0702(Context& c){
{c.r[14]=270206727u;c.pc=(270408736u|1u);return;}
c.pc=270206727u;}
static void b_101b0706(Context& c){
{setsbits(c,14,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=((270206746u&~3u)+0u+392u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270206761u;c.pc=(269975768u|1u);return;}
c.pc=270206761u;}
static void b_101b0716(Context& c){
{uint32_t a=((270206746u&~3u)+0u+392u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270206761u;c.pc=(269975768u|1u);return;}
c.pc=270206761u;}
static void b_101b0720(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270206761u;c.pc=(269975768u|1u);return;}
c.pc=270206761u;}
static void b_101b0728(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270206769u;c.pc=(269975414u|1u);return;}
c.pc=270206769u;}
static void b_101b0730(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270206777u;c.pc=(269975422u|1u);return;}
c.pc=270206777u;}
static void b_101b0738(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270206785u;c.pc=(269975962u|1u);return;}
c.pc=270206785u;}
static void b_101b0740(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270206793u;c.pc=(269976986u|1u);return;}
c.pc=270206793u;}
static void b_101b0748(Context& c){
{uint32_t v=add(c,c.r[7],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270207078u|1u);return;}}
c.pc=270206799u;}
static void b_101b074e(Context& c){
{if(cond(c,13)){c.pc=(270206822u|1u);return;}}
c.pc=270206801u;}
static void b_101b0750(Context& c){
{uint32_t v=add(c,c.r[7],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270206864u|1u);return;}}
c.pc=270206805u;}
static void b_101b0754(Context& c){
{if(cond(c,13)){c.pc=(270206812u|1u);return;}}
c.pc=270206807u;}
static void b_101b0756(Context& c){
{uint32_t v=add(c,c.r[7],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270206852u|1u);return;}}
c.pc=270206811u;}
static void b_101b075a(Context& c){
{c.pc=(270207474u|1u);return;}
c.pc=270206813u;}
static void b_101b075c(Context& c){
{uint32_t v=add(c,c.r[7],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270206940u|1u);return;}}
c.pc=270206817u;}
static void b_101b0760(Context& c){
{uint32_t v=add(c,c.r[7],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270207010u|1u);return;}}
c.pc=270206821u;}
static void b_101b0764(Context& c){
{c.pc=(270207474u|1u);return;}
c.pc=270206823u;}
static void b_101b0766(Context& c){
{uint32_t v=add(c,c.r[7],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270207140u|1u);return;}}
c.pc=270206829u;}
static void b_101b076c(Context& c){
{if(cond(c,13)){c.pc=(270206838u|1u);return;}}
c.pc=270206831u;}
static void b_101b076e(Context& c){
{uint32_t v=add(c,c.r[7],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270207108u|1u);return;}}
c.pc=270206837u;}
static void b_101b0774(Context& c){
{c.pc=(270207474u|1u);return;}
c.pc=270206839u;}
static void b_101b0776(Context& c){
{uint32_t v=add(c,c.r[7],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270207140u|1u);return;}}
c.pc=270206845u;}
static void b_101b077c(Context& c){
{uint32_t v=add(c,c.r[7],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270207140u|1u);return;}}
c.pc=270206851u;}
static void b_101b0782(Context& c){
{c.pc=(270207474u|1u);return;}
c.pc=270206853u;}
static void b_101b0784(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270207474u|1u);return;}}
c.pc=270206859u;}
static void b_101b078a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270206946u|1u);return;}
c.pc=270206865u;}
static void b_101b0790(Context& c){
{if(c.r[5] != 0){c.pc=(270206930u|1u);return;}}
c.pc=270206867u;}
static void b_101b0792(Context& c){
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270206879u;c.pc=(270393366u|1u);return;}
c.pc=270206879u;}
static void b_101b079e(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=5u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270206897u;c.pc=c.r[3];return;}
c.pc=270206897u;}
static void b_101b07b0(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(270u),1,true);}
{if(cond(c,2)){c.pc=(270206916u|1u);return;}}
c.pc=270206905u;}
static void b_101b07b8(Context& c){
{uint32_t a=(c.r[13]+0u+36u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,-(fs(c,15)));}
{uint32_t a=(c.r[13]+0u+36u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+36u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270206931u;c.pc=(270392848u|1u);return;}
c.pc=270206931u;}
static void b_101b07c4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+36u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270206931u;c.pc=(270392848u|1u);return;}
c.pc=270206931u;}
static void b_101b07d2(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270206939u;c.pc=(270206544u|1u);return;}
c.pc=270206939u;}
static void b_101b07da(Context& c){
{c.pc=(270207474u|1u);return;}
c.pc=270206941u;}
static void b_101b07dc(Context& c){
{if(c.r[5] != 0){c.pc=(270206956u|1u);return;}}
c.pc=270206943u;}
static void b_101b07de(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270206955u;c.pc=(270393366u|1u);return;}
c.pc=270206955u;}
static void b_101b07e2(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270206955u;c.pc=(270393366u|1u);return;}
c.pc=270206955u;}
static void b_101b07ea(Context& c){
{c.pc=(270207474u|1u);return;}
c.pc=270206957u;}
static void b_101b07ec(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[1]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[1],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270207474u|1u);return;}}
c.pc=270206967u;}
static void b_101b07f6(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270207002u|1u);return;}}
c.pc=270206973u;}
static void b_101b07fc(Context& c){
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270206987u;c.pc=(269976968u|1u);return;}
c.pc=270206987u;}
static void b_101b080a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.pc=(270207072u|1u);return;}
c.pc=270206993u;}
static void b_101b0810(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270207474u|1u);return;}}
c.pc=270207003u;}
static void b_101b081a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270207009u;c.pc=(270391404u|1u);return;}
c.pc=270207009u;}
static void b_101b0820(Context& c){
{c.pc=(270207474u|1u);return;}
c.pc=270207011u;}
static void b_101b0822(Context& c){
{if(c.r[5] != 0){c.pc=(270207032u|1u);return;}}
c.pc=270207013u;}
static void b_101b0824(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270207025u;c.pc=(270393366u|1u);return;}
c.pc=270207025u;}
static void b_101b0830(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],1u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270207474u|1u);return;}
c.pc=270207033u;}
static void b_101b0838(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[5]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270207474u|1u);return;}}
c.pc=270207043u;}
static void b_101b0842(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[7];c.r[2]=v;}
{c.r[14]=270207053u;c.pc=(269980032u|1u);return;}
c.pc=270207053u;}
static void b_101b084c(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(2u),1,true);}
{if(cond(c,14)){c.pc=(270207474u|1u);return;}}
c.pc=270207061u;}
static void b_101b0854(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270207069u;c.pc=(269976968u|1u);return;}
c.pc=270207069u;}
static void b_101b085c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270207077u;c.pc=(269976986u|1u);return;}
c.pc=270207077u;}
static void b_101b0860(Context& c){
{c.r[14]=270207077u;c.pc=(269976986u|1u);return;}
c.pc=270207077u;}
static void b_101b0864(Context& c){
{c.pc=(270207474u|1u);return;}
c.pc=270207079u;}
static void b_101b0866(Context& c){
{if(c.r[5] != 0){c.pc=(270207086u|1u);return;}}
c.pc=270207081u;}
static void b_101b0868(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270206946u|1u);return;}
c.pc=270207087u;}
static void b_101b086e(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270207474u|1u);return;}}
c.pc=270207097u;}
static void b_101b0878(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[7];c.r[2]=v;}
{c.r[14]=270207107u;c.pc=(269980032u|1u);return;}
c.pc=270207107u;}
static void b_101b0882(Context& c){
{c.pc=(270207474u|1u);return;}
c.pc=270207109u;}
static void b_101b0884(Context& c){
{if(c.r[5] != 0){c.pc=(270207116u|1u);return;}}
c.pc=270207111u;}
static void b_101b0886(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270206946u|1u);return;}
c.pc=270207117u;}
static void b_101b088c(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270207474u|1u);return;}}
c.pc=270207127u;}
static void b_101b0896(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.r[14]=270207135u;c.pc=(270391848u|1u);return;}
c.pc=270207135u;}
static void b_101b089e(Context& c){
{c.pc=(270207474u|1u);return;}
c.pc=270207137u;}
static void b_101b08a4(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[7]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[7],~(90u),1,true);}
{}
{if(cond(c,2)){uint32_t v=4294967295u;c.r[7]=v;}}
{if(cond(c,1)){uint32_t v=1u;c.r[7]=v;}}
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270206992u|1u);return;}}
c.pc=270207157u;}
static void b_101b08b4(Context& c){
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270207169u;c.pc=(270393366u|1u);return;}
c.pc=270207169u;}
static void b_101b08c0(Context& c){
{uint32_t v=65284u;c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=20u;nz(c,v);c.r[3]=v;}
{c.r[14]=270207195u;c.pc=(270015700u|1u);return;}
c.pc=270207195u;}
static void b_101b08da(Context& c){
{setfs(c,18,-22.0);}
{uint32_t a=((270207202u&~3u)+0u+284u);c.r[10]=rd<uint32_t>(c,a+0u);}
{uint32_t v=3u;c.r[8]=v;}
{uint32_t v=0u;c.r[11]=v;}
{uint32_t v=1107296256u;c.r[9]=v;}
{setfs(c,17,22.0);}
{setfs(c,16,-8.0);}
{uint32_t v=c.r[6];c.r[0]=v;}
{c.r[14]=270207229u;c.pc=(270082278u|1u);return;}
c.pc=270207229u;}
static void b_101b08f6(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{c.r[14]=270207229u;c.pc=(270082278u|1u);return;}
c.pc=270207229u;}
static void b_101b08fc(Context& c){
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270207239u;c.pc=(270082278u|1u);return;}
c.pc=270207239u;}
static void b_101b0906(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[3];c.r[0]=v;}
{c.r[14]=270207251u;c.pc=(270697604u|1u);return;}
c.pc=270207251u;}
static void b_101b0912(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[5]=v;}
{uint32_t v=add(c,c.r[1],~(130u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[7])*(c.r[1]);c.r[2]=v;}
{uint32_t v=60u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270207269u;c.pc=(270697604u|1u);return;}
c.pc=270207269u;}
static void b_101b0924(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t v=add(c,c.r[1],~(130u),1,false);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270207303u;c.pc=(270082284u|1u);return;}
c.pc=270207303u;}
static void b_101b0946(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{c.r[14]=270207309u;c.pc=(270082278u|1u);return;}
c.pc=270207309u;}
static void b_101b094c(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270207319u;c.pc=(270082278u|1u);return;}
c.pc=270207319u;}
static void b_101b0956(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270207333u;c.pc=(270697604u|1u);return;}
c.pc=270207333u;}
static void b_101b0964(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],30u,0,true);c.r[1]=v;}
{uint32_t v=(c.r[7])*(c.r[1]);c.r[2]=v;}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270207351u;c.pc=(270697604u|1u);return;}
c.pc=270207351u;}
static void b_101b0976(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t v=add(c,c.r[1],~(170u),1,false);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270207385u;c.pc=(270082284u|1u);return;}
c.pc=270207385u;}
static void b_101b0998(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{c.r[14]=270207391u;c.pc=(270082278u|1u);return;}
c.pc=270207391u;}
static void b_101b099e(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270207401u;c.pc=(270082278u|1u);return;}
c.pc=270207401u;}
static void b_101b09a8(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270207415u;c.pc=(270697604u|1u);return;}
c.pc=270207415u;}
static void b_101b09b6(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(50u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[7])*(c.r[1]);c.r[2]=v;}
{uint32_t v=60u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270207433u;c.pc=(270697604u|1u);return;}
c.pc=270207433u;}
static void b_101b09c8(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[1],~(130u),1,false);c.r[3]=v;}
{uint32_t v=1090519040u;c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270207469u;c.pc=(270082284u|1u);return;}
c.pc=270207469u;}
static void b_101b09ec(Context& c){
{uint32_t v=add(c,c.r[8],~(1u),1,true);c.r[8]=v;}
{if(cond(c,2)){c.pc=(270207222u|1u);return;}}
c.pc=270207475u;}
static void b_101b09f2(Context& c){
{uint32_t v=add(c,c.r[13],44u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);uint32_t newpc=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;c.pc=newpc;return;}
c.pc=270207485u;}
static void b_101b0a00(Context& c){
{uint32_t a=(c.r[1]+0u+196u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],~(6u),1,true);}
{if(cond(c,1)){c.pc=(270207514u|1u);return;}}
c.pc=270207497u;}
static void b_101b0a08(Context& c){
{uint32_t v=add(c,c.r[0],~(19u),1,true);}
{if(cond(c,1)){c.pc=(270207514u|1u);return;}}
c.pc=270207501u;}
static void b_101b0a0c(Context& c){
{uint32_t v=add(c,c.r[0],~(8u),1,true);}
{if(cond(c,1)){c.pc=(270207514u|1u);return;}}
c.pc=270207505u;}
static void b_101b0a10(Context& c){
{uint32_t v=add(c,c.r[0],~(9u),1,true);c.r[3]=v;}
{uint32_t v=add(c,0u,~(c.r[3]),1,true);c.r[0]=v;}
{uint32_t v=add(c,c.r[0],c.r[3],c.c,true);c.r[0]=v;}
{c.pc=c.r[14];return;}
c.pc=270207515u;}
static void b_101b0a1a(Context& c){
{uint32_t v=1u;nz(c,v);c.r[0]=v;}
{c.pc=c.r[14];return;}
c.pc=270207519u;}
static void b_101b0a20(Context& c){
{uint32_t a=c.r[13]-40u;wr<uint32_t>(c,a+0u,c.r[0]);wr<uint32_t>(c,a+4u,c.r[1]);wr<uint32_t>(c,a+8u,c.r[2]);wr<uint32_t>(c,a+12u,c.r[4]);wr<uint32_t>(c,a+16u,c.r[5]);wr<uint32_t>(c,a+20u,c.r[6]);wr<uint32_t>(c,a+24u,c.r[7]);wr<uint32_t>(c,a+28u,c.r[8]);wr<uint32_t>(c,a+32u,c.r[9]);wr<uint32_t>(c,a+36u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[2];c.r[6]=v;}
{uint32_t v=c.r[3];c.r[5]=v;}
{uint32_t v=c.r[0];c.r[9]=v;}
{c.r[14]=270207537u;c.pc=(270326600u|1u);return;}
c.pc=270207537u;}
static void b_101b0a30(Context& c){
{uint32_t a=(c.r[4]+0u+36u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],18432u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(5u),1,true);c.r[3]=v;}
{uint32_t v=add(c,0u,~(c.r[3]),1,true);c.r[8]=v;}
{uint32_t v=add(c,c.r[8],c.r[3],c.c,true);c.r[8]=v;}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270207724u|1u);return;}}
c.pc=270207559u;}
static void b_101b0a46(Context& c){
{uint32_t v=1u;nz(c,v);c.r[7]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[7];c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270207573u;c.pc=(270393366u|1u);return;}
c.pc=270207573u;}
static void b_101b0a54(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270207581u;c.pc=(269975768u|1u);return;}
c.pc=270207581u;}
static void b_101b0a5c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270207589u;c.pc=(269975414u|1u);return;}
c.pc=270207589u;}
static void b_101b0a64(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270207597u;c.pc=(269975422u|1u);return;}
c.pc=270207597u;}
static void b_101b0a6c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270207605u;c.pc=(269975962u|1u);return;}
c.pc=270207605u;}
static void b_101b0a74(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270207613u;c.pc=(269975400u|1u);return;}
c.pc=270207613u;}
static void b_101b0a7c(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270207716u|1u);return;}}
c.pc=270207619u;}
static void b_101b0a82(Context& c){
{uint32_t a=(c.r[4]+0u+276u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270207704u|1u);return;}}
c.pc=270207625u;}
static void b_101b0a88(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{if(cond(c,2)){c.pc=(270207666u|1u);return;}}
c.pc=270207631u;}
static void b_101b0a8e(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270207645u;c.pc=(270408416u|1u);return;}
c.pc=270207645u;}
static void b_101b0a9c(Context& c){
{c.r[14]=270207649u;c.pc=(270408736u|1u);return;}
c.pc=270207649u;}
static void b_101b0aa0(Context& c){
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270207657u;c.pc=(270392110u|1u);return;}
c.pc=270207657u;}
static void b_101b0aa8(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],shift(c,c.r[0],1,1,false),0,false);c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[0]);}
{c.pc=(270207704u|1u);return;}
c.pc=270207667u;}
static void b_101b0ab2(Context& c){
{c.r[14]=270207671u;c.pc=(270408416u|1u);return;}
c.pc=270207671u;}
static void b_101b0ab6(Context& c){
{c.r[14]=270207675u;c.pc=(270408736u|1u);return;}
c.pc=270207675u;}
static void b_101b0aba(Context& c){
{setsbits(c,14,c.r[0]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.r[14]=270207697u;c.pc=(270392110u|1u);return;}
c.pc=270207697u;}
static void b_101b0ad0(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=shift(c,c.r[0],1u,1,true);nz(c,v);c.r[0]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[0]),1,true);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=((270207708u&~3u)+0u+476u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270207724u|1u);return;}
c.pc=270207717u;}
static void b_101b0ad8(Context& c){
{uint32_t a=((270207708u&~3u)+0u+476u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270207724u|1u);return;}
c.pc=270207717u;}
static void b_101b0ae4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270207725u;c.pc=(269976986u|1u);return;}
c.pc=270207725u;}
static void b_101b0aec(Context& c){
{uint32_t v=add(c,c.r[6],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270207940u|1u);return;}}
c.pc=270207729u;}
static void b_101b0af0(Context& c){
{if(cond(c,13)){c.pc=(270207752u|1u);return;}}
c.pc=270207731u;}
static void b_101b0af2(Context& c){
{uint32_t v=add(c,c.r[6],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270207800u|1u);return;}}
c.pc=270207735u;}
static void b_101b0af6(Context& c){
{if(cond(c,13)){c.pc=(270207742u|1u);return;}}
c.pc=270207737u;}
static void b_101b0af8(Context& c){
{uint32_t v=add(c,c.r[6],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270207788u|1u);return;}}
c.pc=270207741u;}
static void b_101b0afc(Context& c){
{c.pc=(270208176u|1u);return;}
c.pc=270207743u;}
static void b_101b0afe(Context& c){
{uint32_t v=add(c,c.r[6],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270207930u|1u);return;}}
c.pc=270207747u;}
static void b_101b0b02(Context& c){
{uint32_t v=add(c,c.r[6],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270207940u|1u);return;}}
c.pc=270207751u;}
static void b_101b0b06(Context& c){
{c.pc=(270208176u|1u);return;}
c.pc=270207753u;}
static void b_101b0b08(Context& c){
{uint32_t v=add(c,c.r[6],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270208054u|1u);return;}}
c.pc=270207759u;}
static void b_101b0b0e(Context& c){
{if(cond(c,13)){c.pc=(270207774u|1u);return;}}
c.pc=270207761u;}
static void b_101b0b10(Context& c){
{uint32_t v=add(c,c.r[6],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270208032u|1u);return;}}
c.pc=270207767u;}
static void b_101b0b16(Context& c){
{uint32_t v=add(c,c.r[6],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270208054u|1u);return;}}
c.pc=270207773u;}
static void b_101b0b1c(Context& c){
{c.pc=(270208176u|1u);return;}
c.pc=270207775u;}
static void b_101b0b1e(Context& c){
{uint32_t v=add(c,c.r[6],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270208054u|1u);return;}}
c.pc=270207781u;}
static void b_101b0b24(Context& c){
{uint32_t v=add(c,c.r[6],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270208082u|1u);return;}}
c.pc=270207787u;}
static void b_101b0b2a(Context& c){
{c.pc=(270208176u|1u);return;}
c.pc=270207789u;}
static void b_101b0b2c(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270208176u|1u);return;}}
c.pc=270207795u;}
static void b_101b0b32(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270207970u|1u);return;}
c.pc=270207801u;}
static void b_101b0b38(Context& c){
{if(c.r[5] != 0){c.pc=(270207838u|1u);return;}}
c.pc=270207803u;}
static void b_101b0b3a(Context& c){
{uint32_t v=c.r[9];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270207811u;c.pc=(270207488u|1u);return;}
c.pc=270207811u;}
static void b_101b0b42(Context& c){
{if(c.r[0] == 0){c.pc=(270207818u|1u);return;}}
c.pc=270207813u;}
static void b_101b0b44(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=24u;nz(c,v);c.r[1]=v;}
{c.pc=(270207822u|1u);return;}
c.pc=270207819u;}
static void b_101b0b4a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270207831u;c.pc=(270393366u|1u);return;}
c.pc=270207831u;}
static void b_101b0b4e(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270207831u;c.pc=(270393366u|1u);return;}
c.pc=270207831u;}
static void b_101b0b56(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270207884u|1u);return;}
c.pc=270207839u;}
static void b_101b0b5e(Context& c){
{uint32_t v=add(c,c.r[5],~(60u),1,true);}
{if(cond(c,2)){c.pc=(270207860u|1u);return;}}
c.pc=270207843u;}
static void b_101b0b62(Context& c){
{uint32_t a=(c.r[4]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270207884u|1u);return;}}
c.pc=270207849u;}
static void b_101b0b68(Context& c){
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+40u);wr<uint32_t>(c,a+0u,c.r[1]);}
{c.r[14]=270207859u;c.pc=(269976968u|1u);return;}
c.pc=270207859u;}
static void b_101b0b72(Context& c){
{c.pc=(270207884u|1u);return;}
c.pc=270207861u;}
static void b_101b0b74(Context& c){
{uint32_t a=(c.r[4]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(24u),1,true);}
{if(cond(c,2)){c.pc=(270208120u|1u);return;}}
c.pc=270207869u;}
static void b_101b0b7c(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{if(c.r[2] != 0){c.pc=(270207884u|1u);return;}}
c.pc=270207875u;}
static void b_101b0b82(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270207885u;c.pc=(270393366u|1u);return;}
c.pc=270207885u;}
static void b_101b0b8c(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270208176u|1u);return;}}
c.pc=270207893u;}
static void b_101b0b94(Context& c){
{uint32_t a=(c.r[4]+0u+32u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{setfs(c,14,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{fcmp(c,fs(c,15),fs(c,14));}
{if(cond(c,2)){c.pc=(270207922u|1u);return;}}
c.pc=270207915u;}
static void b_101b0baa(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,12)){c.pc=(270208176u|1u);return;}}
c.pc=270207921u;}
static void b_101b0bb0(Context& c){
{c.pc=(270208112u|1u);return;}
c.pc=270207923u;}
static void b_101b0bb2(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,9)){c.pc=(270208176u|1u);return;}}
c.pc=270207929u;}
static void b_101b0bb8(Context& c){
{c.pc=(270208112u|1u);return;}
c.pc=270207931u;}
static void b_101b0bba(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270208176u|1u);return;}}
c.pc=270207935u;}
static void b_101b0bbe(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{c.pc=(270208062u|1u);return;}
c.pc=270207941u;}
static void b_101b0bc4(Context& c){
{if(c.r[5] != 0){c.pc=(270207974u|1u);return;}}
c.pc=270207943u;}
static void b_101b0bc6(Context& c){
{uint32_t v=c.r[9];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270207951u;c.pc=(270207488u|1u);return;}
c.pc=270207951u;}
static void b_101b0bce(Context& c){
{if(c.r[0] == 0){c.pc=(270207966u|1u);return;}}
c.pc=270207953u;}
static void b_101b0bd0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270207965u;c.pc=(270393366u|1u);return;}
c.pc=270207965u;}
static void b_101b0bd6(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270207965u;c.pc=(270393366u|1u);return;}
c.pc=270207965u;}
static void b_101b0bdc(Context& c){
{c.pc=(270208176u|1u);return;}
c.pc=270207967u;}
static void b_101b0bde(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=23u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.pc=(270207958u|1u);return;}
c.pc=270207975u;}
static void b_101b0be2(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{c.pc=(270207958u|1u);return;}
c.pc=270207975u;}
static void b_101b0be6(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[5]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270208176u|1u);return;}}
c.pc=270207983u;}
static void b_101b0bee(Context& c){
{uint32_t a=(c.r[4]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(23u),1,true);}
{if(cond(c,1)){c.pc=(270207952u|1u);return;}}
c.pc=270207991u;}
static void b_101b0bf6(Context& c){
{uint32_t v=c.r[9];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.r[14]=270208001u;c.pc=(269980032u|1u);return;}
c.pc=270208001u;}
static void b_101b0c00(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270208020u|1u);return;}}
c.pc=270208007u;}
static void b_101b0c06(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270208015u;c.pc=(269976986u|1u);return;}
c.pc=270208015u;}
static void b_101b0c0e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.pc=(270208026u|1u);return;}
c.pc=270208021u;}
static void b_101b0c14(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+40u);wr<uint32_t>(c,a+0u,c.r[1]);}
{c.r[14]=270208031u;c.pc=(269976968u|1u);return;}
c.pc=270208031u;}
static void b_101b0c1a(Context& c){
{c.r[14]=270208031u;c.pc=(269976968u|1u);return;}
c.pc=270208031u;}
static void b_101b0c1e(Context& c){
{c.pc=(270208176u|1u);return;}
c.pc=270208033u;}
static void b_101b0c20(Context& c){
{if(c.r[5] != 0){c.pc=(270208040u|1u);return;}}
c.pc=270208035u;}
static void b_101b0c22(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270207970u|1u);return;}
c.pc=270208041u;}
static void b_101b0c28(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270208176u|1u);return;}}
c.pc=270208049u;}
static void b_101b0c30(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270208076u|1u);return;}
c.pc=270208055u;}
static void b_101b0c36(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270208176u|1u);return;}}
c.pc=270208059u;}
static void b_101b0c3a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270208071u;c.pc=(270393366u|1u);return;}
c.pc=270208071u;}
static void b_101b0c3e(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270208071u;c.pc=(270393366u|1u);return;}
c.pc=270208071u;}
static void b_101b0c46(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=140u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270208081u;c.pc=(270391848u|1u);return;}
c.pc=270208081u;}
static void b_101b0c4c(Context& c){
{c.r[14]=270208081u;c.pc=(270391848u|1u);return;}
c.pc=270208081u;}
static void b_101b0c50(Context& c){
{c.pc=(270208176u|1u);return;}
c.pc=270208083u;}
static void b_101b0c52(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[1]=rd<uint8_t>(c,a+0u);}
{if(c.r[1] != 0){c.pc=(270208176u|1u);return;}}
c.pc=270208089u;}
static void b_101b0c58(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270208112u|1u);return;}}
c.pc=270208095u;}
static void b_101b0c5e(Context& c){
{uint32_t v=add(c,c.r[5],~(50u),1,true);}
{if(cond(c,2)){c.pc=(270208176u|1u);return;}}
c.pc=270208099u;}
static void b_101b0c62(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270208105u;c.pc=(269976968u|1u);return;}
c.pc=270208105u;}
static void b_101b0c68(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270208113u;c.pc=(269976986u|1u);return;}
c.pc=270208113u;}
static void b_101b0c70(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270208119u;c.pc=(270391404u|1u);return;}
c.pc=270208119u;}
static void b_101b0c76(Context& c){
{c.pc=(270208176u|1u);return;}
c.pc=270208121u;}
static void b_101b0c78(Context& c){
{uint32_t v=add(c,c.r[3],~(7u),1,true);}
{if(cond(c,2)){c.pc=(270207884u|1u);return;}}
c.pc=270208125u;}
static void b_101b0c7c(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270208176u|1u);return;}}
c.pc=270208131u;}
static void b_101b0c82(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],4u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=5u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270208143u;c.pc=c.r[3];return;}
c.pc=270208143u;}
static void b_101b0c8e(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+4u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{uint32_t v=0u;c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{}
{if(cond(c,2)){setfs(c,15,-(fs(c,15)));}}
{c.r[1]=sbits(c,15);}
{c.r[14]=270208175u;c.pc=(270392848u|1u);return;}
c.pc=270208175u;}
static void b_101b0cae(Context& c){
{c.pc=(270207892u|1u);return;}
c.pc=270208177u;}
static void b_101b0cb0(Context& c){
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);uint32_t newpc=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;c.pc=newpc;return;}
c.pc=270208183u;}
static void b_101b0cbc(Context& c){
{uint32_t a=c.r[13]-12u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+252u);c.r[5]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],~(28u),1,false);c.r[13]=v;}
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270208298u|1u);return;}}
c.pc=270208203u;}
static void b_101b0cca(Context& c){
{uint32_t a=(c.r[1]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],8u,0,false);c.r[2]=v;}
{uint32_t v=38u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270208215u;c.pc=c.r[3];return;}
c.pc=270208215u;}
static void b_101b0cd6(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270208227u;c.pc=c.r[3];return;}
c.pc=270208227u;}
static void b_101b0ce2(Context& c){
{uint32_t a=(c.r[4]+0u+277u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=25u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+12u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270208247u;c.pc=(270393892u|1u);return;}
c.pc=270208247u;}
static void b_101b0cf6(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=2u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270208261u;c.pc=c.r[3];return;}
c.pc=270208261u;}
static void b_101b0d04(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=3u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270208273u;c.pc=c.r[3];return;}
c.pc=270208273u;}
static void b_101b0d10(Context& c){
{uint32_t a=(c.r[5]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+20u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+112u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+16u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[1],~(c.r[3]),1,true);c.r[1]=v;}
{c.r[14]=270208287u;c.pc=c.r[2];return;}
c.pc=270208287u;}
static void b_101b0d1e(Context& c){
{uint32_t a=(c.r[4]+0u+240u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[5]+0u+240u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[13],28u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);uint32_t newpc=rd<uint32_t>(c,a+8u);c.r[13]=a+12u;c.pc=newpc;return;}
c.pc=270208303u;}
static void b_101b0d2a(Context& c){
{uint32_t v=add(c,c.r[13],28u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);uint32_t newpc=rd<uint32_t>(c,a+8u);c.r[13]=a+12u;c.pc=newpc;return;}
c.pc=270208303u;}
static void b_101b0d30(Context& c){
{uint32_t a=c.r[13]-32u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[14]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(32u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[3];c.r[5]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[2];c.r[6]=v;}
{c.r[14]=270208323u;c.pc=(270326600u|1u);return;}
c.pc=270208323u;}
static void b_101b0d42(Context& c){
{uint32_t v=add(c,c.r[0],18432u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(5u),1,true);c.r[3]=v;}
{uint32_t v=add(c,0u,~(c.r[3]),1,true);c.r[8]=v;}
{uint32_t v=add(c,c.r[8],c.r[3],c.c,true);c.r[8]=v;}
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270208608u|1u);return;}}
c.pc=270208347u;}
static void b_101b0d5a(Context& c){
{uint32_t v=1u;c.r[9]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[9]);}
{c.r[14]=270208363u;c.pc=(269975422u|1u);return;}
c.pc=270208363u;}
static void b_101b0d6a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{c.r[14]=270208371u;c.pc=(269975962u|1u);return;}
c.pc=270208371u;}
static void b_101b0d72(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{c.r[14]=270208379u;c.pc=(269975948u|1u);return;}
c.pc=270208379u;}
static void b_101b0d7a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{c.r[14]=270208387u;c.pc=(269976968u|1u);return;}
c.pc=270208387u;}
static void b_101b0d82(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270208608u|1u);return;}}
c.pc=270208393u;}
static void b_101b0d88(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{if(cond(c,2)){c.pc=(270208416u|1u);return;}}
c.pc=270208399u;}
static void b_101b0d8e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270208405u;c.pc=(270392110u|1u);return;}
c.pc=270208405u;}
static void b_101b0d94(Context& c){
{uint32_t v=add(c,0u,~(c.r[0]),1,true);c.r[0]=v;}
{setsbits(c,12,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,12)));}
{c.pc=(270208432u|1u);return;}
c.pc=270208417u;}
static void b_101b0da0(Context& c){
{c.r[14]=270208421u;c.pc=(270408416u|1u);return;}
c.pc=270208421u;}
static void b_101b0da4(Context& c){
{c.r[14]=270208425u;c.pc=(270408736u|1u);return;}
c.pc=270208425u;}
static void b_101b0da8(Context& c){
{setsbits(c,14,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t v=100u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.r[14]=270208449u;c.pc=(270408416u|1u);return;}
c.pc=270208449u;}
static void b_101b0db0(Context& c){
{uint32_t v=100u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.r[14]=270208449u;c.pc=(270408416u|1u);return;}
c.pc=270208449u;}
static void b_101b0dc0(Context& c){
{uint32_t v=c.r[0];c.r[10]=v;}
{c.r[14]=270208455u;c.pc=(270394904u|1u);return;}
c.pc=270208455u;}
static void b_101b0dc6(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270208463u;c.pc=(270398272u|1u);return;}
c.pc=270208463u;}
static void b_101b0dce(Context& c){
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[1]=sbits(c,15);}
{uint32_t v=c.r[0];c.r[9]=v;}
{uint32_t v=c.r[10];c.r[0]=v;}
{c.r[14]=270208485u;c.pc=(270408818u|1u);return;}
c.pc=270208485u;}
static void b_101b0de4(Context& c){
{uint32_t a=(c.r[9]+0u+140u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{setsbits(c,14,cvti(fs(c,14),true));}
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{setfs(c,14,int32_t(sbits(c,14)));}
{fcmp(c,fs(c,15),fs(c,14));}
{if(cond(c,2)){c.pc=(270208522u|1u);return;}}
c.pc=270208511u;}
static void b_101b0dfe(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,6)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,5)){uint32_t v=1u;c.r[3]=v;}}
{c.pc=(270208532u|1u);return;}
c.pc=270208523u;}
static void b_101b0e0a(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,14)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{if(c.r[3] == 0){c.pc=(270208570u|1u);return;}}
c.pc=270208535u;}
static void b_101b0e14(Context& c){
{if(c.r[3] == 0){c.pc=(270208570u|1u);return;}}
c.pc=270208535u;}
static void b_101b0e16(Context& c){
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=c.r[10];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[1]=sbits(c,15);}
{c.r[14]=270208555u;c.pc=(270408818u|1u);return;}
c.pc=270208555u;}
static void b_101b0e2a(Context& c){
{uint32_t a=(c.r[9]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[1]=sbits(c,15);}
{c.r[14]=270208571u;c.pc=(269745118u|1u);return;}
c.pc=270208571u;}
static void b_101b0e3a(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[6],~(40u),1,true);}
{uint32_t v=add(c,c.r[0],~(c.r[3]),1,false);c.r[0]=v;}
{setsbits(c,12,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,12)));}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{if(cond(c,1)){c.pc=(270208600u|1u);return;}}
c.pc=270208597u;}
static void b_101b0e54(Context& c){
{uint32_t v=add(c,c.r[6],~(30u),1,true);}
{if(cond(c,2)){c.pc=(270208608u|1u);return;}}
c.pc=270208601u;}
static void b_101b0e58(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270209558u|1u);return;}
c.pc=270208609u;}
static void b_101b0e60(Context& c){
{uint32_t v=add(c,c.r[6],~(51u),1,true);}
{if(cond(c,1)){c.pc=(270209320u|1u);return;}}
c.pc=270208615u;}
static void b_101b0e66(Context& c){
{if(cond(c,13)){c.pc=(270208648u|1u);return;}}
c.pc=270208617u;}
static void b_101b0e68(Context& c){
{uint32_t v=add(c,c.r[6],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270209190u|1u);return;}}
c.pc=270208623u;}
static void b_101b0e6e(Context& c){
{if(cond(c,13)){c.pc=(270208634u|1u);return;}}
c.pc=270208625u;}
static void b_101b0e70(Context& c){
{uint32_t v=add(c,c.r[6],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270208684u|1u);return;}}
c.pc=270208629u;}
static void b_101b0e74(Context& c){
{uint32_t v=add(c,c.r[6],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270208696u|1u);return;}}
c.pc=270208633u;}
static void b_101b0e78(Context& c){
{c.pc=(270209558u|1u);return;}
c.pc=270208635u;}
static void b_101b0e7a(Context& c){
{uint32_t v=add(c,c.r[6],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270209190u|1u);return;}}
c.pc=270208641u;}
static void b_101b0e80(Context& c){
{uint32_t v=add(c,c.r[6],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270209266u|1u);return;}}
c.pc=270208647u;}
static void b_101b0e86(Context& c){
{c.pc=(270209558u|1u);return;}
c.pc=270208649u;}
static void b_101b0e88(Context& c){
{uint32_t v=add(c,c.r[6],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270209406u|1u);return;}}
c.pc=270208655u;}
static void b_101b0e8e(Context& c){
{if(cond(c,13)){c.pc=(270208670u|1u);return;}}
c.pc=270208657u;}
static void b_101b0e90(Context& c){
{uint32_t v=add(c,c.r[6],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270209352u|1u);return;}}
c.pc=270208663u;}
static void b_101b0e96(Context& c){
{uint32_t v=add(c,c.r[6],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270209406u|1u);return;}}
c.pc=270208669u;}
static void b_101b0e9c(Context& c){
{c.pc=(270209558u|1u);return;}
c.pc=270208671u;}
static void b_101b0e9e(Context& c){
{uint32_t v=add(c,c.r[6],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270209406u|1u);return;}}
c.pc=270208677u;}
static void b_101b0ea4(Context& c){
{uint32_t v=add(c,c.r[6],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270209376u|1u);return;}}
c.pc=270208683u;}
static void b_101b0eaa(Context& c){
{c.pc=(270209558u|1u);return;}
c.pc=270208685u;}
static void b_101b0eac(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270209558u|1u);return;}}
c.pc=270208691u;}
static void b_101b0eb2(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270209272u|1u);return;}
c.pc=270208697u;}
static void b_101b0eb8(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(2u),1,true);}
{if(cond(c,14)){c.pc=(270208812u|1u);return;}}
c.pc=270208703u;}
static void b_101b0ebe(Context& c){
{c.r[14]=270208707u;c.pc=(270394904u|1u);return;}
c.pc=270208707u;}
static void b_101b0ec2(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270208715u;c.pc=(270398272u|1u);return;}
c.pc=270208715u;}
static void b_101b0eca(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{uint32_t a=(c.r[0]+0u+140u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{setsbits(c,14,cvti(fs(c,14),true));}
{setfs(c,14,int32_t(sbits(c,14)));}
{fcmp(c,fs(c,15),fs(c,14));}
{if(cond(c,2)){c.pc=(270208752u|1u);return;}}
c.pc=270208741u;}
static void b_101b0ee4(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,14)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{c.pc=(270208762u|1u);return;}
c.pc=270208753u;}
static void b_101b0ef0(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,6)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,5)){uint32_t v=1u;c.r[3]=v;}}
{if(c.r[3] == 0){c.pc=(270208812u|1u);return;}}
c.pc=270208765u;}
static void b_101b0efa(Context& c){
{if(c.r[3] == 0){c.pc=(270208812u|1u);return;}}
c.pc=270208765u;}
static void b_101b0efc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270208771u;c.pc=(270393220u|1u);return;}
c.pc=270208771u;}
static void b_101b0f02(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1065353216u;c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270208787u;c.pc=(270392910u|1u);return;}
c.pc=270208787u;}
static void b_101b0f12(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270208795u;c.pc=(270118736u|1u);return;}
c.pc=270208795u;}
static void b_101b0f1a(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270209558u|1u);return;}}
c.pc=270208801u;}
static void b_101b0f20(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=51u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270208811u;c.pc=(270391848u|1u);return;}
c.pc=270208811u;}
static void b_101b0f2a(Context& c){
{c.pc=(270209558u|1u);return;}
c.pc=270208813u;}
static void b_101b0f2c(Context& c){
{if(c.r[5] != 0){c.pc=(270208832u|1u);return;}}
c.pc=270208815u;}
static void b_101b0f2e(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270208827u;c.pc=(270393366u|1u);return;}
c.pc=270208827u;}
static void b_101b0f3a(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270209046u|1u);return;}}
c.pc=270208839u;}
static void b_101b0f40(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270209046u|1u);return;}}
c.pc=270208839u;}
static void b_101b0f46(Context& c){
{c.r[14]=270208843u;c.pc=(270408416u|1u);return;}
c.pc=270208843u;}
static void b_101b0f4a(Context& c){
{uint32_t v=c.r[0];c.r[6]=v;}
{c.r[14]=270208849u;c.pc=(270394904u|1u);return;}
c.pc=270208849u;}
static void b_101b0f50(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[8];c.r[2]=v;}
{c.r[14]=270208857u;c.pc=(270398272u|1u);return;}
c.pc=270208857u;}
static void b_101b0f58(Context& c){
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[1]=sbits(c,15);}
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[6];c.r[0]=v;}
{c.r[14]=270208879u;c.pc=(270408818u|1u);return;}
c.pc=270208879u;}
static void b_101b0f6e(Context& c){
{uint32_t a=(c.r[5]+0u+140u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{setsbits(c,14,cvti(fs(c,14),true));}
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{setfs(c,14,int32_t(sbits(c,14)));}
{fcmp(c,fs(c,15),fs(c,14));}
{if(cond(c,2)){c.pc=(270208916u|1u);return;}}
c.pc=270208905u;}
static void b_101b0f88(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,6)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,5)){uint32_t v=1u;c.r[3]=v;}}
{c.pc=(270208926u|1u);return;}
c.pc=270208917u;}
static void b_101b0f94(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,14)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{if(c.r[3] == 0){c.pc=(270208964u|1u);return;}}
c.pc=270208929u;}
static void b_101b0f9e(Context& c){
{if(c.r[3] == 0){c.pc=(270208964u|1u);return;}}
c.pc=270208929u;}
static void b_101b0fa0(Context& c){
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[1]=sbits(c,15);}
{c.r[14]=270208949u;c.pc=(270408818u|1u);return;}
c.pc=270208949u;}
static void b_101b0fb4(Context& c){
{uint32_t a=(c.r[5]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[1]=sbits(c,15);}
{c.r[14]=270208965u;c.pc=(269745118u|1u);return;}
c.pc=270208965u;}
static void b_101b0fc4(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[0],~(c.r[3]),1,true);c.r[0]=v;}
{setsbits(c,14,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{setfs(c,12,(fs(c,15))-(fs(c,13)));}
{setfs(c,14,8.0);}
{setfs(c,12,std::fabs(fs(c,12)));}
{fcmp(c,fs(c,12),fs(c,14));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,14)){c.pc=(270209038u|1u);return;}}
c.pc=270209003u;}
static void b_101b0fea(Context& c){
{fcmp(c,fs(c,15),fs(c,13));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{setfs(c,15,-8.0);}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,14)){c.r[1]=sbits(c,15);}}
{if(cond(c,13)){c.r[1]=sbits(c,14);}}
{c.r[14]=270209037u;c.pc=(270392910u|1u);return;}
c.pc=270209037u;}
static void b_101b100c(Context& c){
{c.pc=(270209046u|1u);return;}
c.pc=270209039u;}
static void b_101b100e(Context& c){
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.r[14]=270209051u;c.pc=(270394904u|1u);return;}
c.pc=270209051u;}
static void b_101b1016(Context& c){
{c.r[14]=270209051u;c.pc=(270394904u|1u);return;}
c.pc=270209051u;}
static void b_101b101a(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],12u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[0]+shift(c,c.r[3],2,1,false)+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270209558u|1u);return;}}
c.pc=270209065u;}
static void b_101b1028(Context& c){
{uint32_t a=(c.r[3]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],32u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=5u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{uint32_t v=0u;c.r[3]=v;}
{uint32_t a=(c.r[2]+0u+4294967292u);uint32_t wb=a;wr<uint32_t>(c,a+0u,c.r[3]);c.r[2]=wb;}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[5]=sbits(c,15);}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{}
{if(cond(c,1)){uint32_t v=add(c,c.r[5],120u,0,false);c.r[5]=v;}}
{if(cond(c,2)){uint32_t v=add(c,c.r[5],~(120u),1,false);c.r[5]=v;}}
{c.r[14]=270209107u;c.pc=c.r[3];return;}
c.pc=270209107u;}
static void b_101b1052(Context& c){
{uint32_t a=(c.r[13]+0u+28u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{fcmp(c,fs(c,15),0);}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,10)){c.pc=(270209558u|1u);return;}}
c.pc=270209123u;}
static void b_101b1062(Context& c){
{setsbits(c,12,c.r[5]);}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{setfs(c,14,int32_t(sbits(c,12)));}
{setfs(c,11,(fs(c,13))-(fs(c,14)));}
{setfs(c,12,(fs(c,15))+(fs(c,15)));}
{setfs(c,11,std::fabs(fs(c,11)));}
{fcmp(c,fs(c,11),fs(c,12));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,10)){c.pc=(270209368u|1u);return;}}
c.pc=270209157u;}
static void b_101b1084(Context& c){
{fcmp(c,fs(c,13),fs(c,14));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,13)){setfs(c,15,-(fs(c,15)));}}
{if(cond(c,13)){uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,sbits(c,15));}}
{uint32_t a=(c.r[13]+0u+28u);c.r[1]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270209189u;c.pc=(270392848u|1u);return;}
c.pc=270209189u;}
static void b_101b10a4(Context& c){
{c.pc=(270209558u|1u);return;}
c.pc=270209191u;}
static void b_101b10a6(Context& c){
{if(c.r[5] != 0){c.pc=(270209210u|1u);return;}}
c.pc=270209193u;}
static void b_101b10a8(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270209205u;c.pc=(270393366u|1u);return;}
c.pc=270209205u;}
static void b_101b10b4(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],1u,0,true);c.r[3]=v;}
{c.pc=(270209316u|1u);return;}
c.pc=270209211u;}
static void b_101b10ba(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[5]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270209558u|1u);return;}}
c.pc=270209221u;}
static void b_101b10c4(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.r[14]=270209231u;c.pc=(269980032u|1u);return;}
c.pc=270209231u;}
static void b_101b10ce(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(2u),1,true);}
{if(cond(c,14)){c.pc=(270209558u|1u);return;}}
c.pc=270209239u;}
static void b_101b10d6(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270209248u|1u);return;}}
c.pc=270209245u;}
static void b_101b10dc(Context& c){
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[5]);}
{c.pc=(270209558u|1u);return;}
c.pc=270209249u;}
static void b_101b10e0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270209257u;c.pc=(269976986u|1u);return;}
c.pc=270209257u;}
static void b_101b10e8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270209265u;c.pc=(269975400u|1u);return;}
c.pc=270209265u;}
static void b_101b10f0(Context& c){
{c.pc=(270209558u|1u);return;}
c.pc=270209267u;}
static void b_101b10f2(Context& c){
{if(c.r[5] != 0){c.pc=(270209282u|1u);return;}}
c.pc=270209269u;}
static void b_101b10f4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270209281u;c.pc=(270393366u|1u);return;}
c.pc=270209281u;}
static void b_101b10f8(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270209281u;c.pc=(270393366u|1u);return;}
c.pc=270209281u;}
static void b_101b1100(Context& c){
{c.pc=(270209558u|1u);return;}
c.pc=270209283u;}
static void b_101b1102(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270209558u|1u);return;}}
c.pc=270209293u;}
static void b_101b110c(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.r[14]=270209303u;c.pc=(269980032u|1u);return;}
c.pc=270209303u;}
static void b_101b1116(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(2u),1,true);}
{if(cond(c,14)){c.pc=(270209558u|1u);return;}}
c.pc=270209309u;}
static void b_101b111c(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270209248u|1u);return;}}
c.pc=270209315u;}
static void b_101b1122(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270209558u|1u);return;}
c.pc=270209321u;}
static void b_101b1124(Context& c){
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270209558u|1u);return;}
c.pc=270209321u;}
static void b_101b1128(Context& c){
{if(c.r[5] != 0){c.pc=(270209328u|1u);return;}}
c.pc=270209323u;}
static void b_101b112a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=41u;nz(c,v);c.r[1]=v;}
{c.pc=(270209272u|1u);return;}
c.pc=270209329u;}
static void b_101b1130(Context& c){
{uint32_t v=add(c,c.r[5],~(33u),1,true);}
{if(cond(c,2)){c.pc=(270209342u|1u);return;}}
c.pc=270209333u;}
static void b_101b1134(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270209341u;c.pc=(270208188u|1u);return;}
c.pc=270209341u;}
static void b_101b113c(Context& c){
{c.pc=(270209558u|1u);return;}
c.pc=270209343u;}
static void b_101b113e(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270209558u|1u);return;}}
c.pc=270209351u;}
static void b_101b1146(Context& c){
{c.pc=(270209552u|1u);return;}
c.pc=270209353u;}
static void b_101b1148(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270209558u|1u);return;}}
c.pc=270209357u;}
static void b_101b114c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270209369u;c.pc=(270393366u|1u);return;}
c.pc=270209369u;}
static void b_101b1158(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270209375u;c.pc=(270393272u|1u);return;}
c.pc=270209375u;}
static void b_101b115e(Context& c){
{c.pc=(270209558u|1u);return;}
c.pc=270209377u;}
static void b_101b1160(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[1]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[1],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270209558u|1u);return;}}
c.pc=270209385u;}
static void b_101b1168(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270209552u|1u);return;}}
c.pc=270209391u;}
static void b_101b116e(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270209405u;c.pc=(269976986u|1u);return;}
c.pc=270209405u;}
static void b_101b117c(Context& c){
{c.pc=(270209558u|1u);return;}
c.pc=270209407u;}
static void b_101b117e(Context& c){
{if(c.r[5] != 0){c.pc=(270209440u|1u);return;}}
c.pc=270209409u;}
static void b_101b1180(Context& c){
{uint32_t v=65284u;c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=20u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270209435u;c.pc=(270015700u|1u);return;}
c.pc=270209435u;}
static void b_101b119a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{c.pc=(270209272u|1u);return;}
c.pc=270209441u;}
static void b_101b11a0(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[5]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270209558u|1u);return;}}
c.pc=270209449u;}
static void b_101b11a8(Context& c){
{uint32_t a=((270209452u&~3u)+0u+116u);c.r[10]=rd<uint32_t>(c,a+0u);}
{uint32_t v=65284u;c.r[3]=v;}
{uint32_t a=((270209460u&~3u)+0u+112u);c.r[9]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270209466u&~3u)+0u+100u);c.r[6]=rd<uint32_t>(c,a+0u);}
{uint32_t v=20u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270209485u;c.pc=(270015700u|1u);return;}
c.pc=270209485u;}
static void b_101b11cc(Context& c){
{uint32_t v=1090519040u;c.r[8]=v;}
{uint32_t v=2u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=20u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[5];c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270209521u;c.pc=(270082284u|1u);return;}
c.pc=270209521u;}
static void b_101b11f0(Context& c){
{uint32_t v=4u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t v=20u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t v=c.r[5];c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270209553u;c.pc=(270091396u|1u);return;}
c.pc=270209553u;}
static void b_101b1210(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270209559u;c.pc=(270391404u|1u);return;}
c.pc=270209559u;}
static void b_101b1216(Context& c){
{uint32_t v=add(c,c.r[13],32u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270209565u;}
static void b_101b1228(Context& c){
{uint32_t a=c.r[13]-28u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-8u;wr<uint64_t>(c,a+0u,c.d[8]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+16u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],~(20u),1,false);c.r[13]=v;}
{uint32_t v=c.r[2];c.r[5]=v;}
{if(c.r[3] != 0){c.pc=(270209600u|1u);return;}}
c.pc=270209595u;}
static void b_101b123a(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+16u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+20u);wr<uint32_t>(c,a+0u,c.r[2]);}
{if(c.r[5] != 0){c.pc=(270209654u|1u);return;}}
c.pc=270209603u;}
static void b_101b1240(Context& c){
{if(c.r[5] != 0){c.pc=(270209654u|1u);return;}}
c.pc=270209603u;}
static void b_101b1242(Context& c){
{c.r[14]=270209607u;c.pc=(270394904u|1u);return;}
c.pc=270209607u;}
static void b_101b1246(Context& c){
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=402u;c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=4u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setfs(c,15,20.0);}
{setfs(c,15,(fs(c,14))+(fs(c,15)));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.pc=(270209968u|1u);return;}
c.pc=270209655u;}
static void b_101b1276(Context& c){
{uint32_t a=(c.r[4]+0u+20u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],2u,0,true);c.r[2]=v;}
{uint32_t v=add(c,c.r[5],~(c.r[2]),1,true);}
{if(cond(c,1)){c.pc=(270209710u|1u);return;}}
c.pc=270209663u;}
static void b_101b127e(Context& c){
{uint32_t v=add(c,c.r[3],4u,0,true);c.r[2]=v;}
{uint32_t v=add(c,c.r[5],~(c.r[2]),1,true);}
{if(cond(c,1)){c.pc=(270209716u|1u);return;}}
c.pc=270209669u;}
static void b_101b1284(Context& c){
{uint32_t v=add(c,c.r[3],6u,0,true);c.r[2]=v;}
{uint32_t v=add(c,c.r[5],~(c.r[2]),1,true);}
{if(cond(c,1)){c.pc=(270209722u|1u);return;}}
c.pc=270209675u;}
static void b_101b128a(Context& c){
{uint32_t v=add(c,c.r[3],8u,0,false);c.r[2]=v;}
{uint32_t v=add(c,c.r[5],~(c.r[2]),1,true);}
{if(cond(c,1)){c.pc=(270209728u|1u);return;}}
c.pc=270209683u;}
static void b_101b1292(Context& c){
{uint32_t v=add(c,c.r[3],10u,0,true);c.r[3]=v;}
{uint32_t v=add(c,c.r[5],~(c.r[3]),1,true);}
{if(cond(c,1)){c.pc=(270209734u|1u);return;}}
c.pc=270209689u;}
static void b_101b1298(Context& c){
{uint32_t a=(c.r[4]+0u+20u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],9u,0,true);c.r[0]=v;}
{uint32_t v=add(c,c.r[0],~(c.r[5]),1,true);}
{}
{if(cond(c,12)){uint32_t v=0u;c.r[0]=v;}}
{if(cond(c,11)){uint32_t v=1u;c.r[0]=v;}}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.r[13]=a+8u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);uint32_t newpc=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;c.pc=newpc;return;}
c.pc=270209711u;}
static void b_101b12ae(Context& c){
{uint32_t v=20u;nz(c,v);c.r[6]=v;}
{uint32_t v=c.r[6];c.r[7]=v;}
{c.pc=(270209738u|1u);return;}
c.pc=270209717u;}
static void b_101b12b4(Context& c){
{uint32_t v=40u;nz(c,v);c.r[6]=v;}
{uint32_t v=36u;nz(c,v);c.r[7]=v;}
{c.pc=(270209738u|1u);return;}
c.pc=270209723u;}
static void b_101b12ba(Context& c){
{uint32_t v=60u;nz(c,v);c.r[6]=v;}
{uint32_t v=46u;nz(c,v);c.r[7]=v;}
{c.pc=(270209738u|1u);return;}
c.pc=270209729u;}
static void b_101b12c0(Context& c){
{uint32_t v=80u;nz(c,v);c.r[6]=v;}
{uint32_t v=66u;nz(c,v);c.r[7]=v;}
{c.pc=(270209738u|1u);return;}
c.pc=270209735u;}
static void b_101b12c6(Context& c){
{uint32_t v=100u;nz(c,v);c.r[6]=v;}
{uint32_t v=82u;nz(c,v);c.r[7]=v;}
{c.r[14]=270209743u;c.pc=(270394904u|1u);return;}
c.pc=270209743u;}
static void b_101b12ca(Context& c){
{c.r[14]=270209743u;c.pc=(270394904u|1u);return;}
c.pc=270209743u;}
static void b_101b12ce(Context& c){
{setsbits(c,15,c.r[7]);}
{uint32_t a=(c.r[4]+0u+120u);c.r[8]=rd<uint32_t>(c,a+0u);}
{uint32_t v=402u;c.r[1]=v;}
{setfs(c,17,int32_t(sbits(c,15)));}
{uint32_t v=2u;nz(c,v);c.r[2]=v;}
{setsbits(c,15,c.r[6]);}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=0u;nz(c,v);c.r[6]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[6]);}
{setfs(c,16,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,(fs(c,15))-(fs(c,17)));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=c.r[0];c.r[9]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,(fs(c,15))-(fs(c,16)));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.r[14]=270209817u;c.pc=(270396032u|1u);return;}
c.pc=270209817u;}
static void b_101b1318(Context& c){
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,(fs(c,17))+(fs(c,15)));}
{uint32_t v=402u;c.r[1]=v;}
{uint32_t v=2u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[9];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[6]);}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,(fs(c,15))-(fs(c,16)));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.r[14]=270209869u;c.pc=(270396032u|1u);return;}
c.pc=270209869u;}
static void b_101b134c(Context& c){
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,(fs(c,15))-(fs(c,17)));}
{uint32_t v=402u;c.r[1]=v;}
{uint32_t v=2u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[6];c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[9];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[6]);}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,(fs(c,16))+(fs(c,15)));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.r[14]=270209921u;c.pc=(270396032u|1u);return;}
c.pc=270209921u;}
static void b_101b1380(Context& c){
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,17,(fs(c,17))+(fs(c,15)));}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=c.r[9];c.r[0]=v;}
{uint32_t v=402u;c.r[1]=v;}
{uint32_t v=2u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[6];c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[6]);}
{setfs(c,16,(fs(c,16))+(fs(c,15)));}
{setsbits(c,17,cvti(fs(c,17),true));}
{setsbits(c,16,cvti(fs(c,16),true));}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{c.r[14]=270209973u;c.pc=(270396032u|1u);return;}
c.pc=270209973u;}
static void b_101b13b0(Context& c){
{c.r[14]=270209973u;c.pc=(270396032u|1u);return;}
c.pc=270209973u;}
static void b_101b13b4(Context& c){
{c.pc=(270209688u|1u);return;}
c.pc=270209975u;}
static void b_101b13b8(Context& c){
{uint32_t v=add(c,c.r[2],~(70u),1,true);}
{uint32_t a=c.r[13]-20u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=add(c,c.r[13],~(20u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[3];c.r[5]=v;}
{if(cond(c,1)){c.pc=(270210164u|1u);return;}}
c.pc=270209991u;}
static void b_101b13c6(Context& c){
{if(cond(c,13)){c.pc=(270210018u|1u);return;}}
c.pc=270209993u;}
static void b_101b13c8(Context& c){
{uint32_t v=add(c,c.r[2],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270210084u|1u);return;}}
c.pc=270209997u;}
static void b_101b13cc(Context& c){
{if(cond(c,13)){c.pc=(270210008u|1u);return;}}
c.pc=270209999u;}
static void b_101b13ce(Context& c){
{uint32_t v=add(c,c.r[2],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270210044u|1u);return;}}
c.pc=270210003u;}
static void b_101b13d2(Context& c){
{uint32_t v=add(c,c.r[2],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270210056u|1u);return;}}
c.pc=270210007u;}
static void b_101b13d6(Context& c){
{c.pc=(270210314u|1u);return;}
c.pc=270210009u;}
static void b_101b13d8(Context& c){
{uint32_t v=add(c,c.r[2],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270210104u|1u);return;}}
c.pc=270210013u;}
static void b_101b13dc(Context& c){
{uint32_t v=add(c,c.r[2],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270210138u|1u);return;}}
c.pc=270210017u;}
static void b_101b13e0(Context& c){
{c.pc=(270210314u|1u);return;}
c.pc=270210019u;}
static void b_101b13e2(Context& c){
{uint32_t v=add(c,c.r[2],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270210230u|1u);return;}}
c.pc=270210023u;}
static void b_101b13e6(Context& c){
{if(cond(c,13)){c.pc=(270210034u|1u);return;}}
c.pc=270210025u;}
static void b_101b13e8(Context& c){
{uint32_t v=add(c,c.r[2],~(80u),1,true);}
{if(cond(c,1)){c.pc=(270210198u|1u);return;}}
c.pc=270210029u;}
static void b_101b13ec(Context& c){
{uint32_t v=add(c,c.r[2],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270210230u|1u);return;}}
c.pc=270210033u;}
static void b_101b13f0(Context& c){
{c.pc=(270210314u|1u);return;}
c.pc=270210035u;}
static void b_101b13f2(Context& c){
{uint32_t v=add(c,c.r[2],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270210230u|1u);return;}}
c.pc=270210039u;}
static void b_101b13f6(Context& c){
{uint32_t v=add(c,c.r[2],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270210288u|1u);return;}}
c.pc=270210043u;}
static void b_101b13fa(Context& c){
{c.pc=(270210314u|1u);return;}
c.pc=270210045u;}
static void b_101b13fc(Context& c){
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270210314u|1u);return;}}
c.pc=270210051u;}
static void b_101b1402(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270210090u|1u);return;}
c.pc=270210057u;}
static void b_101b1408(Context& c){
{if(c.r[3] != 0){c.pc=(270210076u|1u);return;}}
c.pc=270210059u;}
static void b_101b140a(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270210071u;c.pc=(270393366u|1u);return;}
c.pc=270210071u;}
static void b_101b1416(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270210084u&~3u)+0u+236u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270210128u|1u);return;}
c.pc=270210085u;}
static void b_101b141c(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270210084u&~3u)+0u+236u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270210128u|1u);return;}
c.pc=270210085u;}
static void b_101b1424(Context& c){
{if(c.r[3] != 0){c.pc=(270210146u|1u);return;}}
c.pc=270210087u;}
static void b_101b1426(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270393366u|1u);return;}
c.pc=270210105u;}
static void b_101b142a(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270393366u|1u);return;}
c.pc=270210105u;}
static void b_101b1438(Context& c){
{if(c.r[3] != 0){c.pc=(270210112u|1u);return;}}
c.pc=270210107u;}
static void b_101b143a(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{c.pc=(270210204u|1u);return;}
c.pc=270210113u;}
static void b_101b1440(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270210122u|1u);return;}}
c.pc=270210119u;}
static void b_101b1446(Context& c){
{c.r[14]=270210123u;c.pc=(269980032u|1u);return;}
c.pc=270210123u;}
static void b_101b144a(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(269978432u|1u);return;}
c.pc=270210139u;}
static void b_101b1450(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(269978432u|1u);return;}
c.pc=270210139u;}
static void b_101b145a(Context& c){
{if(c.r[3] != 0){c.pc=(270210146u|1u);return;}}
c.pc=270210141u;}
static void b_101b145c(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270210090u|1u);return;}
c.pc=270210147u;}
static void b_101b1462(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270210314u|1u);return;}}
c.pc=270210155u;}
static void b_101b146a(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(269980032u|1u);return;}
c.pc=270210165u;}
static void b_101b1474(Context& c){
{if(c.r[3] != 0){c.pc=(270210172u|1u);return;}}
c.pc=270210167u;}
static void b_101b1476(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270210090u|1u);return;}
c.pc=270210173u;}
static void b_101b147c(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270210314u|1u);return;}}
c.pc=270210181u;}
static void b_101b1484(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.r[14]=270210191u;c.pc=(270393366u|1u);return;}
c.pc=270210191u;}
static void b_101b148e(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270210314u|1u);return;}
c.pc=270210199u;}
static void b_101b1496(Context& c){
{if(c.r[3] != 0){c.pc=(270210214u|1u);return;}}
c.pc=270210201u;}
static void b_101b1498(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270210213u;c.pc=(270393366u|1u);return;}
c.pc=270210213u;}
static void b_101b149c(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270210213u;c.pc=(270393366u|1u);return;}
c.pc=270210213u;}
static void b_101b14a4(Context& c){
{c.pc=(270210122u|1u);return;}
c.pc=270210215u;}
static void b_101b14a6(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270210122u|1u);return;}}
c.pc=270210223u;}
static void b_101b14ae(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270210122u|1u);return;}
c.pc=270210231u;}
static void b_101b14b6(Context& c){
{if(c.r[5] != 0){c.pc=(270210272u|1u);return;}}
c.pc=270210233u;}
static void b_101b14b8(Context& c){
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270210245u;c.pc=(270393366u|1u);return;}
c.pc=270210245u;}
static void b_101b14c4(Context& c){
{uint32_t v=65284u;c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=~(34u);c.r[3]=v;}
{c.r[14]=270210273u;c.pc=(270015700u|1u);return;}
c.pc=270210273u;}
static void b_101b14e0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=140u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270391848u|1u);return;}
c.pc=270210289u;}
static void b_101b14f0(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270210314u|1u);return;}}
c.pc=270210295u;}
static void b_101b14f6(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270210301u;c.pc=(270209576u|1u);return;}
c.pc=270210301u;}
static void b_101b14fc(Context& c){
{if(c.r[0] != 0){c.pc=(270210314u|1u);return;}}
c.pc=270210303u;}
static void b_101b14fe(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270391404u|1u);return;}
c.pc=270210315u;}
static void b_101b150a(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);uint32_t newpc=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;c.pc=newpc;return;}
c.pc=270210319u;}
static void b_101b1514(Context& c){
{uint32_t a=c.r[13]-8u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270210348u|1u);return;}}
c.pc=270210335u;}
static void b_101b151e(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+60u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=70u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=~(1u);c.r[3]=v;}
{c.pc=(270210360u|1u);return;}
c.pc=270210349u;}
static void b_101b152c(Context& c){
{uint32_t v=add(c,c.r[3],~(12u),1,true);}
{if(cond(c,2)){c.pc=(270210362u|1u);return;}}
c.pc=270210353u;}
static void b_101b1530(Context& c){
{uint32_t v=~(69u);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=2u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270210368u&~3u)+0u+56u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
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
{c.r[14]=270210411u;c.pc=(270393746u|1u);return;}
c.pc=270210411u;}
static void b_101b1538(Context& c){
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270210368u&~3u)+0u+56u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
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
{c.r[14]=270210411u;c.pc=(270393746u|1u);return;}
c.pc=270210411u;}
static void b_101b153a(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270210368u&~3u)+0u+56u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
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
{c.r[14]=270210411u;c.pc=(270393746u|1u);return;}
c.pc=270210411u;}
static void b_101b156a(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(23u),1,true);}
{}
{if(cond(c,14)){uint32_t v=add(c,c.r[3],1u,0,false);c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270210425u;}
static void b_101b157c(Context& c){
{uint32_t a=c.r[13]-24u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[14]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(32u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[3];c.r[5]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[2];c.r[6]=v;}
{c.r[14]=270210447u;c.pc=(270326600u|1u);return;}
c.pc=270210447u;}
static void b_101b158e(Context& c){
{uint32_t v=add(c,c.r[0],18432u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(5u),1,true);c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+44u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,0u,~(c.r[1]),1,true);c.r[8]=v;}
{uint32_t v=add(c,c.r[8],c.r[1],c.c,true);c.r[8]=v;}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270210610u|1u);return;}}
c.pc=270210469u;}
static void b_101b15a4(Context& c){
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[4]+0u+48u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+44u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270210570u|1u);return;}}
c.pc=270210481u;}
static void b_101b15b0(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{if(cond(c,2)){c.pc=(270210522u|1u);return;}}
c.pc=270210487u;}
static void b_101b15b6(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270210501u;c.pc=(270408416u|1u);return;}
c.pc=270210501u;}
static void b_101b15c4(Context& c){
{c.r[14]=270210505u;c.pc=(270408736u|1u);return;}
c.pc=270210505u;}
static void b_101b15c8(Context& c){
{uint32_t a=(c.r[4]+0u+40u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270210513u;c.pc=(270392110u|1u);return;}
c.pc=270210513u;}
static void b_101b15d0(Context& c){
{uint32_t a=(c.r[4]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],shift(c,c.r[0],1,1,false),0,false);c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+40u);wr<uint32_t>(c,a+0u,c.r[0]);}
{c.pc=(270210560u|1u);return;}
c.pc=270210523u;}
static void b_101b15da(Context& c){
{c.r[14]=270210527u;c.pc=(270408416u|1u);return;}
c.pc=270210527u;}
static void b_101b15de(Context& c){
{c.r[14]=270210531u;c.pc=(270408736u|1u);return;}
c.pc=270210531u;}
static void b_101b15e2(Context& c){
{setsbits(c,14,c.r[0]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.r[14]=270210553u;c.pc=(270392110u|1u);return;}
c.pc=270210553u;}
static void b_101b15f8(Context& c){
{uint32_t a=(c.r[4]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=shift(c,c.r[0],1u,1,true);nz(c,v);c.r[0]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[0]),1,true);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+40u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=((270210564u&~3u)+0u+520u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270210579u;c.pc=(269975768u|1u);return;}
c.pc=270210579u;}
static void b_101b1600(Context& c){
{uint32_t a=((270210564u&~3u)+0u+520u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270210579u;c.pc=(269975768u|1u);return;}
c.pc=270210579u;}
static void b_101b160a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270210579u;c.pc=(269975768u|1u);return;}
c.pc=270210579u;}
static void b_101b1612(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270210587u;c.pc=(269975414u|1u);return;}
c.pc=270210587u;}
static void b_101b161a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270210595u;c.pc=(269975422u|1u);return;}
c.pc=270210595u;}
static void b_101b1622(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270210603u;c.pc=(269975962u|1u);return;}
c.pc=270210603u;}
static void b_101b162a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270210611u;c.pc=(269976986u|1u);return;}
c.pc=270210611u;}
static void b_101b1632(Context& c){
{uint32_t v=add(c,c.r[6],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270210926u|1u);return;}}
c.pc=270210617u;}
static void b_101b1638(Context& c){
{if(cond(c,13)){c.pc=(270210642u|1u);return;}}
c.pc=270210619u;}
static void b_101b163a(Context& c){
{uint32_t v=add(c,c.r[6],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270210696u|1u);return;}}
c.pc=270210623u;}
static void b_101b163e(Context& c){
{if(cond(c,13)){c.pc=(270210630u|1u);return;}}
c.pc=270210625u;}
static void b_101b1640(Context& c){
{uint32_t v=add(c,c.r[6],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270210672u|1u);return;}}
c.pc=270210629u;}
static void b_101b1644(Context& c){
{c.pc=(270211078u|1u);return;}
c.pc=270210631u;}
static void b_101b1646(Context& c){
{uint32_t v=add(c,c.r[6],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270210820u|1u);return;}}
c.pc=270210635u;}
static void b_101b164a(Context& c){
{uint32_t v=add(c,c.r[6],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270210916u|1u);return;}}
c.pc=270210641u;}
static void b_101b1650(Context& c){
{c.pc=(270211078u|1u);return;}
c.pc=270210643u;}
static void b_101b1652(Context& c){
{uint32_t v=add(c,c.r[6],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270210952u|1u);return;}}
c.pc=270210649u;}
static void b_101b1658(Context& c){
{if(cond(c,13)){c.pc=(270210658u|1u);return;}}
c.pc=270210651u;}
static void b_101b165a(Context& c){
{uint32_t v=add(c,c.r[6],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270210952u|1u);return;}}
c.pc=270210657u;}
static void b_101b1660(Context& c){
{c.pc=(270211078u|1u);return;}
c.pc=270210659u;}
static void b_101b1662(Context& c){
{uint32_t v=add(c,c.r[6],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270210952u|1u);return;}}
c.pc=270210665u;}
static void b_101b1668(Context& c){
{uint32_t v=add(c,c.r[6],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270211042u|1u);return;}}
c.pc=270210671u;}
static void b_101b166e(Context& c){
{c.pc=(270211078u|1u);return;}
c.pc=270210673u;}
static void b_101b1670(Context& c){
{if(c.r[5] != 0){c.pc=(270210686u|1u);return;}}
c.pc=270210675u;}
static void b_101b1672(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270210687u;c.pc=(270393366u|1u);return;}
c.pc=270210687u;}
static void b_101b167e(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270210695u;c.pc=(270210324u|1u);return;}
c.pc=270210695u;}
static void b_101b1686(Context& c){
{c.pc=(270211078u|1u);return;}
c.pc=270210697u;}
static void b_101b1688(Context& c){
{if(c.r[5] != 0){c.pc=(270210762u|1u);return;}}
c.pc=270210699u;}
static void b_101b168a(Context& c){
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270210711u;c.pc=(270393366u|1u);return;}
c.pc=270210711u;}
static void b_101b1696(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=5u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],28u,0,false);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270210729u;c.pc=c.r[3];return;}
c.pc=270210729u;}
static void b_101b16a8(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(270u),1,true);}
{if(cond(c,2)){c.pc=(270210748u|1u);return;}}
c.pc=270210737u;}
static void b_101b16b0(Context& c){
{uint32_t a=(c.r[13]+0u+28u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,-(fs(c,15)));}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270210763u;c.pc=(270392848u|1u);return;}
c.pc=270210763u;}
static void b_101b16bc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270210763u;c.pc=(270392848u|1u);return;}
c.pc=270210763u;}
static void b_101b16ca(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270210771u;c.pc=(270210324u|1u);return;}
c.pc=270210771u;}
static void b_101b16d2(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270211078u|1u);return;}}
c.pc=270210779u;}
static void b_101b16da(Context& c){
{uint32_t a=(c.r[4]+0u+40u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{setfs(c,14,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{fcmp(c,fs(c,15),fs(c,14));}
{if(cond(c,2)){c.pc=(270210810u|1u);return;}}
c.pc=270210801u;}
static void b_101b16f0(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,12)){c.pc=(270211078u|1u);return;}}
c.pc=270210809u;}
static void b_101b16f8(Context& c){
{c.pc=(270211034u|1u);return;}
c.pc=270210811u;}
static void b_101b16fa(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,9)){c.pc=(270211078u|1u);return;}}
c.pc=270210819u;}
static void b_101b1702(Context& c){
{c.pc=(270211034u|1u);return;}
c.pc=270210821u;}
static void b_101b1704(Context& c){
{if(c.r[5] != 0){c.pc=(270210884u|1u);return;}}
c.pc=270210823u;}
static void b_101b1706(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270210864u|1u);return;}}
c.pc=270210829u;}
static void b_101b170c(Context& c){
{uint32_t a=(c.r[4]+0u+40u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{setfs(c,14,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{fcmp(c,fs(c,15),fs(c,14));}
{if(cond(c,2)){c.pc=(270210858u|1u);return;}}
c.pc=270210851u;}
static void b_101b1722(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,12)){c.pc=(270210864u|1u);return;}}
c.pc=270210857u;}
static void b_101b1728(Context& c){
{c.pc=(270211034u|1u);return;}
c.pc=270210859u;}
static void b_101b172a(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,10)){c.pc=(270211034u|1u);return;}}
c.pc=270210865u;}
static void b_101b1730(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270210877u;c.pc=(270393366u|1u);return;}
c.pc=270210877u;}
static void b_101b173c(Context& c){
{uint32_t a=(c.r[4]+0u+48u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],1u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+48u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270211078u|1u);return;}
c.pc=270210885u;}
static void b_101b1744(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270211078u|1u);return;}}
c.pc=270210893u;}
static void b_101b174c(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.r[14]=270210903u;c.pc=(269980032u|1u);return;}
c.pc=270210903u;}
static void b_101b1756(Context& c){
{uint32_t a=(c.r[4]+0u+48u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,14)){c.pc=(270211078u|1u);return;}}
c.pc=270210909u;}
static void b_101b175c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=140u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.pc=(270210946u|1u);return;}
c.pc=270210917u;}
static void b_101b1764(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270210884u|1u);return;}}
c.pc=270210921u;}
static void b_101b1768(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270211048u|1u);return;}
c.pc=270210927u;}
static void b_101b176e(Context& c){
{if(c.r[5] != 0){c.pc=(270210934u|1u);return;}}
c.pc=270210929u;}
static void b_101b1770(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270211048u|1u);return;}
c.pc=270210935u;}
static void b_101b1776(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270211078u|1u);return;}}
c.pc=270210943u;}
static void b_101b177e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.r[14]=270210951u;c.pc=(270391848u|1u);return;}
c.pc=270210951u;}
static void b_101b1782(Context& c){
{c.r[14]=270210951u;c.pc=(270391848u|1u);return;}
c.pc=270210951u;}
static void b_101b1786(Context& c){
{c.pc=(270211078u|1u);return;}
c.pc=270210953u;}
static void b_101b1788(Context& c){
{if(c.r[5] != 0){c.pc=(270210960u|1u);return;}}
c.pc=270210955u;}
static void b_101b178a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{c.pc=(270211048u|1u);return;}
c.pc=270210961u;}
static void b_101b1790(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[5]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270211078u|1u);return;}}
c.pc=270210969u;}
static void b_101b1798(Context& c){
{uint32_t v=65284u;c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270210995u;c.pc=(270015700u|1u);return;}
c.pc=270210995u;}
static void b_101b17b2(Context& c){
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t v=12u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[2]);wr<uint32_t>(c,a+4u,c.r[3]);}
{uint32_t a=((270211006u&~3u)+0u+84u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=((270211016u&~3u)+0u+76u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=1082130432u;c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=((270211026u&~3u)+0u+72u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=~(39u);c.r[3]=v;}
{c.r[14]=270211035u;c.pc=(270082284u|1u);return;}
c.pc=270211035u;}
static void b_101b17da(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270211041u;c.pc=(270391404u|1u);return;}
c.pc=270211041u;}
static void b_101b17e0(Context& c){
{c.pc=(270211078u|1u);return;}
c.pc=270211043u;}
static void b_101b17e2(Context& c){
{if(c.r[5] != 0){c.pc=(270211058u|1u);return;}}
c.pc=270211045u;}
static void b_101b17e4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270211057u;c.pc=(270393366u|1u);return;}
c.pc=270211057u;}
static void b_101b17e8(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270211057u;c.pc=(270393366u|1u);return;}
c.pc=270211057u;}
static void b_101b17f0(Context& c){
{c.pc=(270211078u|1u);return;}
c.pc=270211059u;}
static void b_101b17f2(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270211078u|1u);return;}}
c.pc=270211065u;}
static void b_101b17f8(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270211034u|1u);return;}}
c.pc=270211071u;}
static void b_101b17fe(Context& c){
{uint32_t a=(c.r[4]+0u+48u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[13],32u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270211085u;}
static void b_101b1806(Context& c){
{uint32_t v=add(c,c.r[13],32u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270211085u;}
static void b_101b181c(Context& c){
{uint32_t v=add(c,c.r[2],~(50u),1,true);}
{uint32_t a=c.r[13]-16u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{if(cond(c,1)){c.pc=(270211244u|1u);return;}}
c.pc=270211111u;}
static void b_101b1826(Context& c){
{if(cond(c,13)){c.pc=(270211134u|1u);return;}}
c.pc=270211113u;}
static void b_101b1828(Context& c){
{uint32_t v=add(c,c.r[2],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270211170u|1u);return;}}
c.pc=270211117u;}
static void b_101b182c(Context& c){
{if(cond(c,13)){c.pc=(270211124u|1u);return;}}
c.pc=270211119u;}
static void b_101b182e(Context& c){
{uint32_t v=add(c,c.r[2],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270211160u|1u);return;}}
c.pc=270211123u;}
static void b_101b1832(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270211125u;}
static void b_101b1834(Context& c){
{uint32_t v=add(c,c.r[2],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270211204u|1u);return;}}
c.pc=270211129u;}
static void b_101b1838(Context& c){
{uint32_t v=add(c,c.r[2],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270211222u|1u);return;}}
c.pc=270211133u;}
static void b_101b183c(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270211135u;}
static void b_101b183e(Context& c){
{uint32_t v=add(c,c.r[2],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270211296u|1u);return;}}
c.pc=270211139u;}
static void b_101b1842(Context& c){
{if(cond(c,13)){c.pc=(270211150u|1u);return;}}
c.pc=270211141u;}
static void b_101b1844(Context& c){
{uint32_t v=add(c,c.r[2],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270211276u|1u);return;}}
c.pc=270211145u;}
static void b_101b1848(Context& c){
{uint32_t v=add(c,c.r[2],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270211296u|1u);return;}}
c.pc=270211149u;}
static void b_101b184c(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270211151u;}
static void b_101b184e(Context& c){
{uint32_t v=add(c,c.r[2],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270211322u|1u);return;}}
c.pc=270211155u;}
static void b_101b1852(Context& c){
{uint32_t v=add(c,c.r[2],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270211328u|1u);return;}}
c.pc=270211159u;}
static void b_101b1856(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270211161u;}
static void b_101b1858(Context& c){
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270211344u|1u);return;}}
c.pc=270211165u;}
static void b_101b185c(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270211210u|1u);return;}
c.pc=270211171u;}
static void b_101b1862(Context& c){
{if(c.r[3] != 0){c.pc=(270211190u|1u);return;}}
c.pc=270211173u;}
static void b_101b1864(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270211185u;c.pc=(270393366u|1u);return;}
c.pc=270211185u;}
static void b_101b1870(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270211198u&~3u)+0u+152u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(269978432u|1u);return;}
c.pc=270211205u;}
static void b_101b1876(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270211198u&~3u)+0u+152u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(269978432u|1u);return;}
c.pc=270211205u;}
static void b_101b1884(Context& c){
{if(c.r[3] != 0){c.pc=(270211230u|1u);return;}}
c.pc=270211207u;}
static void b_101b1886(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270393366u|1u);return;}
c.pc=270211223u;}
static void b_101b188a(Context& c){
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270393366u|1u);return;}
c.pc=270211223u;}
static void b_101b1896(Context& c){
{if(c.r[3] != 0){c.pc=(270211230u|1u);return;}}
c.pc=270211225u;}
static void b_101b1898(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{c.pc=(270211210u|1u);return;}
c.pc=270211231u;}
static void b_101b189e(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270211344u|1u);return;}}
c.pc=270211237u;}
static void b_101b18a4(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(269980032u|1u);return;}
c.pc=270211245u;}
static void b_101b18ac(Context& c){
{if(c.r[3] != 0){c.pc=(270211252u|1u);return;}}
c.pc=270211247u;}
static void b_101b18ae(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270211210u|1u);return;}
c.pc=270211253u;}
static void b_101b18b4(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270211344u|1u);return;}}
c.pc=270211259u;}
static void b_101b18ba(Context& c){
{c.r[14]=270211263u;c.pc=(269980032u|1u);return;}
c.pc=270211263u;}
static void b_101b18be(Context& c){
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270405754u|1u);return;}
c.pc=270211277u;}
static void b_101b18cc(Context& c){
{if(c.r[3] != 0){c.pc=(270211284u|1u);return;}}
c.pc=270211279u;}
static void b_101b18ce(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270211210u|1u);return;}
c.pc=270211285u;}
static void b_101b18d4(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{if(c.r[2] != 0){c.pc=(270211344u|1u);return;}}
c.pc=270211291u;}
static void b_101b18da(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270211314u|1u);return;}
c.pc=270211297u;}
static void b_101b18e0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270211309u;c.pc=(270393366u|1u);return;}
c.pc=270211309u;}
static void b_101b18e4(Context& c){
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270211309u;c.pc=(270393366u|1u);return;}
c.pc=270211309u;}
static void b_101b18ec(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=140u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270391848u|1u);return;}
c.pc=270211323u;}
static void b_101b18f2(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270391848u|1u);return;}
c.pc=270211323u;}
static void b_101b18fa(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=15u;nz(c,v);c.r[1]=v;}
{c.pc=(270211300u|1u);return;}
c.pc=270211329u;}
static void b_101b1900(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270211344u|1u);return;}}
c.pc=270211335u;}
static void b_101b1906(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270391404u|1u);return;}
c.pc=270211345u;}
static void b_101b1910(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270211347u;}
static void b_101b1918(Context& c){
{uint32_t v=add(c,c.r[2],~(50u),1,true);}
{uint32_t a=c.r[13]-16u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[2];c.r[5]=v;}
{if(cond(c,1)){c.pc=(270211458u|1u);return;}}
c.pc=270211365u;}
static void b_101b1924(Context& c){
{if(cond(c,13)){c.pc=(270211388u|1u);return;}}
c.pc=270211367u;}
static void b_101b1926(Context& c){
{uint32_t v=add(c,c.r[2],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270211410u|1u);return;}}
c.pc=270211371u;}
static void b_101b192a(Context& c){
{if(cond(c,13)){c.pc=(270211378u|1u);return;}}
c.pc=270211373u;}
static void b_101b192c(Context& c){
{uint32_t v=add(c,c.r[2],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270211410u|1u);return;}}
c.pc=270211377u;}
static void b_101b1930(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270211379u;}
static void b_101b1932(Context& c){
{uint32_t v=add(c,c.r[2],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270211420u|1u);return;}}
c.pc=270211383u;}
static void b_101b1936(Context& c){
{uint32_t v=add(c,c.r[2],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270211420u|1u);return;}}
c.pc=270211387u;}
static void b_101b193a(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270211389u;}
static void b_101b193c(Context& c){
{uint32_t v=add(c,c.r[2],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270211516u|1u);return;}}
c.pc=270211393u;}
static void b_101b1940(Context& c){
{if(cond(c,13)){c.pc=(270211400u|1u);return;}}
c.pc=270211395u;}
static void b_101b1942(Context& c){
{uint32_t v=add(c,c.r[2],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270211490u|1u);return;}}
c.pc=270211399u;}
static void b_101b1946(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270211401u;}
static void b_101b1948(Context& c){
{uint32_t v=add(c,c.r[2],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270211516u|1u);return;}}
c.pc=270211405u;}
static void b_101b194c(Context& c){
{uint32_t v=add(c,c.r[2],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270211516u|1u);return;}}
c.pc=270211409u;}
static void b_101b1950(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270211411u;}
static void b_101b1952(Context& c){
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270211540u|1u);return;}}
c.pc=270211415u;}
static void b_101b1956(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=20u;nz(c,v);c.r[1]=v;}
{c.pc=(270211426u|1u);return;}
c.pc=270211421u;}
static void b_101b195c(Context& c){
{if(c.r[3] != 0){c.pc=(270211438u|1u);return;}}
c.pc=270211423u;}
static void b_101b195e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=21u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270393366u|1u);return;}
c.pc=270211439u;}
static void b_101b1962(Context& c){
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270393366u|1u);return;}
c.pc=270211439u;}
static void b_101b196e(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270211540u|1u);return;}}
c.pc=270211445u;}
static void b_101b1974(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(269980032u|1u);return;}
c.pc=270211459u;}
static void b_101b1982(Context& c){
{if(c.r[3] != 0){c.pc=(270211466u|1u);return;}}
c.pc=270211461u;}
static void b_101b1984(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=22u;nz(c,v);c.r[1]=v;}
{c.pc=(270211426u|1u);return;}
c.pc=270211467u;}
static void b_101b198a(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[5]=rd<uint8_t>(c,a+0u);}
{if(c.r[5] != 0){c.pc=(270211540u|1u);return;}}
c.pc=270211473u;}
static void b_101b1990(Context& c){
{c.r[14]=270211477u;c.pc=(269980032u|1u);return;}
c.pc=270211477u;}
static void b_101b1994(Context& c){
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270405754u|1u);return;}
c.pc=270211491u;}
static void b_101b19a2(Context& c){
{if(c.r[3] != 0){c.pc=(270211498u|1u);return;}}
c.pc=270211493u;}
static void b_101b19a4(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=23u;nz(c,v);c.r[1]=v;}
{c.pc=(270211426u|1u);return;}
c.pc=270211499u;}
static void b_101b19aa(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{if(c.r[2] != 0){c.pc=(270211540u|1u);return;}}
c.pc=270211505u;}
static void b_101b19b0(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270391848u|1u);return;}
c.pc=270211517u;}
static void b_101b19bc(Context& c){
{if(c.r[3] != 0){c.pc=(270211524u|1u);return;}}
c.pc=270211519u;}
static void b_101b19be(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=24u;nz(c,v);c.r[1]=v;}
{c.pc=(270211426u|1u);return;}
c.pc=270211525u;}
static void b_101b19c4(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270211540u|1u);return;}}
c.pc=270211531u;}
static void b_101b19ca(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[14]=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;}
{c.pc=(270391404u|1u);return;}
c.pc=270211541u;}
static void b_101b19d4(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270211543u;}
static void b_101b19d6(Context& c){
{uint32_t a=c.r[13]-24u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[3];c.r[6]=v;}
{uint32_t a=(c.r[1]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[2];c.r[7]=v;}
{uint32_t a=(c.r[3]+0u+76u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270211563u;c.pc=c.r[3];return;}
c.pc=270211563u;}
static void b_101b19ea(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[7];c.r[2]=v;}
{uint32_t v=add(c,c.r[0],~(122u),1,true);}
{uint32_t v=c.r[5];c.r[0]=v;}
{if(cond(c,1)){c.pc=(270211576u|1u);return;}}
c.pc=270211573u;}
static void b_101b19f4(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{if(c.r[3] == 0){c.pc=(270211586u|1u);return;}}
c.pc=270211577u;}
static void b_101b19f8(Context& c){
{uint32_t v=c.r[6];c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270211352u|1u);return;}
c.pc=270211587u;}
static void b_101b1a02(Context& c){
{uint32_t v=c.r[6];c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270211100u|1u);return;}
c.pc=270211597u;}
static void b_101b1a0c(Context& c){
{uint32_t a=c.r[13]-8u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{c.r[14]=270211605u;c.pc=(270394904u|1u);return;}
c.pc=270211605u;}
static void b_101b1a14(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[3])^(1u);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],14u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[0]+shift(c,c.r[3],2,1,false)+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270211744u|1u);return;}}
c.pc=270211621u;}
static void b_101b1a24(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[0]+0u+148u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{fcmp(c,fs(c,14),fs(c,15));}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{if(cond(c,2)){c.pc=(270211650u|1u);return;}}
c.pc=270211639u;}
static void b_101b1a36(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,14)){uint32_t v=0u;c.r[0]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[0]=v;}}
{c.pc=(270211660u|1u);return;}
c.pc=270211651u;}
static void b_101b1a42(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,6)){uint32_t v=0u;c.r[0]=v;}}
{if(cond(c,5)){uint32_t v=1u;c.r[0]=v;}}
{if(c.r[0] == 0){c.pc=(270211744u|1u);return;}}
c.pc=270211663u;}
static void b_101b1a4c(Context& c){
{if(c.r[0] == 0){c.pc=(270211744u|1u);return;}}
c.pc=270211663u;}
static void b_101b1a4e(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270211675u;c.pc=(270393366u|1u);return;}
c.pc=270211675u;}
static void b_101b1a5a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270211681u;c.pc=(270392138u|1u);return;}
c.pc=270211681u;}
static void b_101b1a60(Context& c){
{uint32_t v=25u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[0],shift(c,c.r[0],31,2,false),0,false);c.r[0]=v;}
{uint32_t v=shift(c,c.r[0],1u,3,true);nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,0u,~(c.r[1]),1,true);c.r[1]=v;}
{setsbits(c,15,c.r[1]);}
{setfs(c,15,int32_t(sbits(c,15)));}
{c.r[1]=sbits(c,15);}
{c.r[14]=270211709u;c.pc=(270393090u|1u);return;}
c.pc=270211709u;}
static void b_101b1a7c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270211717u;c.pc=(269976968u|1u);return;}
c.pc=270211717u;}
static void b_101b1a84(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270211725u;c.pc=(269976986u|1u);return;}
c.pc=270211725u;}
static void b_101b1a8c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270211733u;c.pc=(269975400u|1u);return;}
c.pc=270211733u;}
static void b_101b1a94(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=21u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[14]=270211743u;c.pc=(270391848u|1u);return;}
c.pc=270211743u;}
static void b_101b1a9e(Context& c){
{uint32_t v=1u;nz(c,v);c.r[0]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270211747u;}
static void b_101b1aa0(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270211747u;}
static void b_101b1aa2(Context& c){
{uint32_t a=(c.r[1]+0u+124u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270211766u|1u);return;}}
c.pc=270211753u;}
static void b_101b1aa8(Context& c){
{uint32_t v=add(c,c.r[0],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270211766u|1u);return;}}
c.pc=270211757u;}
static void b_101b1aac(Context& c){
{uint32_t v=add(c,c.r[0],~(120u),1,true);c.r[3]=v;}
{uint32_t v=add(c,0u,~(c.r[3]),1,true);c.r[0]=v;}
{uint32_t v=add(c,c.r[0],c.r[3],c.c,true);c.r[0]=v;}
{c.pc=c.r[14];return;}
c.pc=270211767u;}
static void b_101b1ab6(Context& c){
{uint32_t v=1u;nz(c,v);c.r[0]=v;}
{c.pc=c.r[14];return;}
c.pc=270211771u;}
static void b_101b1aba(Context& c){
{uint32_t a=c.r[13]-8u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+36u);c.r[0]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270211781u;c.pc=(269745236u|1u);return;}
c.pc=270211781u;}
static void b_101b1ac4(Context& c){
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],48u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[0]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[14]=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;}
{setfs(c,15,int32_t(sbits(c,15)));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{c.pc=(270393746u|1u);return;}
c.pc=270211815u;}
static void b_101b1ae8(Context& c){
{uint32_t a=c.r[13]-32u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[14]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(24u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[3];c.r[6]=v;}
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[2];c.r[7]=v;}
{c.r[14]=270211835u;c.pc=(270326600u|1u);return;}
c.pc=270211835u;}
static void b_101b1afa(Context& c){
{uint32_t v=add(c,c.r[0],18432u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(5u),1,true);c.r[3]=v;}
{uint32_t v=add(c,0u,~(c.r[3]),1,true);c.r[9]=v;}
{uint32_t v=add(c,c.r[9],c.r[3],c.c,true);c.r[9]=v;}
{uint32_t a=(c.r[4]+0u+52u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270211958u|1u);return;}}
c.pc=270211857u;}
static void b_101b1b10(Context& c){
{uint32_t v=add(c,c.r[9],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270211868u|1u);return;}}
c.pc=270211863u;}
static void b_101b1b16(Context& c){
{uint32_t v=2u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270211946u|1u);return;}
c.pc=270211869u;}
static void b_101b1b1c(Context& c){
{uint32_t v=1u;c.r[8]=v;}
{uint32_t v=100u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[8];c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[8]);}
{c.r[14]=270211889u;c.pc=(269975768u|1u);return;}
c.pc=270211889u;}
static void b_101b1b30(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270211897u;c.pc=(269975414u|1u);return;}
c.pc=270211897u;}
static void b_101b1b38(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270211905u;c.pc=(269975422u|1u);return;}
c.pc=270211905u;}
static void b_101b1b40(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270211913u;c.pc=(269975962u|1u);return;}
c.pc=270211913u;}
static void b_101b1b48(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270211921u;c.pc=(269976968u|1u);return;}
c.pc=270211921u;}
static void b_101b1b50(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270211929u;c.pc=(269976986u|1u);return;}
c.pc=270211929u;}
static void b_101b1b58(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270211937u;c.pc=(269975400u|1u);return;}
c.pc=270211937u;}
static void b_101b1b60(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270211959u;c.pc=(270393366u|1u);return;}
c.pc=270211959u;}
static void b_101b1b6a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270211959u;c.pc=(270393366u|1u);return;}
c.pc=270211959u;}
static void b_101b1b76(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270211967u;c.pc=(270211746u|1u);return;}
c.pc=270211967u;}
static void b_101b1b7e(Context& c){
{if(c.r[0] == 0){c.pc=(270211972u|1u);return;}}
c.pc=270211969u;}
static void b_101b1b80(Context& c){
{uint32_t v=3u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270211981u;c.pc=(270211746u|1u);return;}
c.pc=270211981u;}
static void b_101b1b84(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270211981u;c.pc=(270211746u|1u);return;}
c.pc=270211981u;}
static void b_101b1b8c(Context& c){
{uint32_t v=c.r[0];c.r[10]=v;}
{if(c.r[0] != 0){c.pc=(270211994u|1u);return;}}
c.pc=270211985u;}
static void b_101b1b90(Context& c){
{uint32_t a=(c.r[4]+0u+52u);c.r[8]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[8],~(1u),1,true);}
{if(cond(c,1)){c.pc=(270212016u|1u);return;}}
c.pc=270211995u;}
static void b_101b1b9a(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270212003u;c.pc=(270211746u|1u);return;}
c.pc=270212003u;}
static void b_101b1ba2(Context& c){
{uint32_t v=c.r[0];c.r[8]=v;}
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270212224u|1u);return;}}
c.pc=270212009u;}
static void b_101b1ba8(Context& c){
{uint32_t a=(c.r[4]+0u+52u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(2u),1,true);}
{if(cond(c,2)){c.pc=(270212224u|1u);return;}}
c.pc=270212015u;}
static void b_101b1bae(Context& c){
{c.pc=(270212170u|1u);return;}
c.pc=270212017u;}
static void b_101b1bb0(Context& c){
{c.r[14]=270212021u;c.pc=(270408416u|1u);return;}
c.pc=270212021u;}
static void b_101b1bb4(Context& c){
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=c.r[8];c.r[2]=v;}
{c.r[1]=sbits(c,15);}
{uint32_t v=c.r[0];c.r[6]=v;}
{c.r[14]=270212041u;c.pc=(270408818u|1u);return;}
c.pc=270212041u;}
static void b_101b1bc8(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270212049u;c.pc=(269977976u|1u);return;}
c.pc=270212049u;}
static void b_101b1bd0(Context& c){
{if(c.r[0] == 0){c.pc=(270212102u|1u);return;}}
c.pc=270212051u;}
static void b_101b1bd2(Context& c){
{c.r[14]=270212055u;c.pc=(270394904u|1u);return;}
c.pc=270212055u;}
static void b_101b1bd6(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[10];c.r[2]=v;}
{c.r[14]=270212063u;c.pc=(270398272u|1u);return;}
c.pc=270212063u;}
static void b_101b1bde(Context& c){
{uint32_t v=c.r[8];c.r[2]=v;}
{uint32_t a=(c.r[0]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=c.r[6];c.r[0]=v;}
{c.r[5]=sbits(c,15);}
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[1]=sbits(c,15);}
{c.r[14]=270212095u;c.pc=(270408818u|1u);return;}
c.pc=270212095u;}
static void b_101b1bfe(Context& c){
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270212101u;c.pc=(269745118u|1u);return;}
c.pc=270212101u;}
static void b_101b1c04(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{setsbits(c,13,c.r[5]);}
{uint32_t a=(c.r[4]+0u+152u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,14,int32_t(sbits(c,13)));}
{uint32_t a=(c.r[4]+0u+28u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{setfs(c,14,(fs(c,14))-(fs(c,15)));}
{setfs(c,15,int32_t(sbits(c,13)));}
{fcmp(c,fs(c,14),fs(c,15));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,14)){c.pc=(270212144u|1u);return;}}
c.pc=270212137u;}
static void b_101b1c06(Context& c){
{setsbits(c,13,c.r[5]);}
{uint32_t a=(c.r[4]+0u+152u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,14,int32_t(sbits(c,13)));}
{uint32_t a=(c.r[4]+0u+28u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{setfs(c,14,(fs(c,14))-(fs(c,15)));}
{setfs(c,15,int32_t(sbits(c,13)));}
{fcmp(c,fs(c,14),fs(c,15));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,14)){c.pc=(270212144u|1u);return;}}
c.pc=270212137u;}
static void b_101b1c28(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=((270212142u&~3u)+0u+728u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.pc=(270212160u|1u);return;}
c.pc=270212145u;}
static void b_101b1c30(Context& c){
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[2]=v;}
{uint32_t v=2u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270212169u;c.pc=(270392910u|1u);return;}
c.pc=270212169u;}
static void b_101b1c40(Context& c){
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270212169u;c.pc=(270392910u|1u);return;}
c.pc=270212169u;}
static void b_101b1c48(Context& c){
{c.pc=(270213380u|1u);return;}
c.pc=270212171u;}
static void b_101b1c4a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270212177u;c.pc=(269976978u|1u);return;}
c.pc=270212177u;}
static void b_101b1c50(Context& c){
{if(c.r[0] == 0){c.pc=(270212186u|1u);return;}}
c.pc=270212179u;}
static void b_101b1c52(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270212187u;c.pc=(269976968u|1u);return;}
c.pc=270212187u;}
static void b_101b1c5a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270212193u;c.pc=(269977496u|1u);return;}
c.pc=270212193u;}
static void b_101b1c60(Context& c){
{if(c.r[0] == 0){c.pc=(270212202u|1u);return;}}
c.pc=270212195u;}
static void b_101b1c62(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{c.r[14]=270212203u;c.pc=(269976986u|1u);return;}
c.pc=270212203u;}
static void b_101b1c6a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270212209u;c.pc=(269975408u|1u);return;}
c.pc=270212209u;}
static void b_101b1c70(Context& c){
{if(c.r[0] == 0){c.pc=(270212218u|1u);return;}}
c.pc=270212211u;}
static void b_101b1c72(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{c.r[14]=270212219u;c.pc=(269975400u|1u);return;}
c.pc=270212219u;}
static void b_101b1c7a(Context& c){
{uint32_t v=3u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270213380u|1u);return;}
c.pc=270212225u;}
static void b_101b1c80(Context& c){
{c.r[14]=270212229u;c.pc=(270408416u|1u);return;}
c.pc=270212229u;}
static void b_101b1c84(Context& c){
{uint32_t v=add(c,c.r[7],~(40u),1,true);}
{uint32_t v=c.r[0];c.r[8]=v;}
{if(cond(c,2)){c.pc=(270212242u|1u);return;}}
c.pc=270212235u;}
static void b_101b1c8a(Context& c){
{if(c.r[6] != 0){c.pc=(270212286u|1u);return;}}
c.pc=270212237u;}
static void b_101b1c8c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{c.pc=(270212266u|1u);return;}
c.pc=270212243u;}
static void b_101b1c92(Context& c){
{if(cond(c,14)){c.pc=(270212304u|1u);return;}}
c.pc=270212245u;}
static void b_101b1c94(Context& c){
{uint32_t v=add(c,c.r[7],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270212878u|1u);return;}}
c.pc=270212251u;}
static void b_101b1c9a(Context& c){
{if(cond(c,13)){c.pc=(270212872u|1u);return;}}
c.pc=270212255u;}
static void b_101b1c9e(Context& c){
{uint32_t v=add(c,c.r[7],~(50u),1,true);}
{if(cond(c,2)){c.pc=(270212614u|1u);return;}}
c.pc=270212261u;}
static void b_101b1ca4(Context& c){
{if(c.r[6] != 0){c.pc=(270212276u|1u);return;}}
c.pc=270212263u;}
static void b_101b1ca6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270212275u;c.pc=(270393366u|1u);return;}
c.pc=270212275u;}
static void b_101b1caa(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270212275u;c.pc=(270393366u|1u);return;}
c.pc=270212275u;}
static void b_101b1cb2(Context& c){
{c.pc=(270212320u|1u);return;}
c.pc=270212277u;}
static void b_101b1cb4(Context& c){
{uint32_t v=add(c,c.r[6],~(55u),1,false);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],~(81u),1,true);}
{if(cond(c,10)){c.pc=(270213058u|1u);return;}}
c.pc=270212287u;}
static void b_101b1cbe(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[6]=rd<uint8_t>(c,a+0u);}
{if(c.r[6] != 0){c.pc=(270212318u|1u);return;}}
c.pc=270212293u;}
static void b_101b1cc4(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[7];c.r[2]=v;}
{c.r[14]=270212303u;c.pc=(269980032u|1u);return;}
c.pc=270212303u;}
static void b_101b1cce(Context& c){
{c.pc=(270212320u|1u);return;}
c.pc=270212305u;}
static void b_101b1cd0(Context& c){
{uint32_t v=add(c,c.r[7],~(21u),1,true);}
{if(cond(c,2)){c.pc=(270212506u|1u);return;}}
c.pc=270212309u;}
static void b_101b1cd4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270212315u;c.pc=(269975064u|1u);return;}
c.pc=270212315u;}
static void b_101b1cda(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270212464u|1u);return;}}
c.pc=270212319u;}
static void b_101b1cde(Context& c){
{uint32_t v=0u;nz(c,v);c.r[6]=v;}
{uint32_t v=1u;nz(c,v);c.r[7]=v;}
{uint32_t a=(c.r[4]+0u+252u);c.r[0]=rd<uint32_t>(c,a+0u);}
{if(c.r[0] == 0){c.pc=(270212338u|1u);return;}}
c.pc=270212329u;}
static void b_101b1ce0(Context& c){
{uint32_t v=1u;nz(c,v);c.r[7]=v;}
{uint32_t a=(c.r[4]+0u+252u);c.r[0]=rd<uint32_t>(c,a+0u);}
{if(c.r[0] == 0){c.pc=(270212338u|1u);return;}}
c.pc=270212329u;}
static void b_101b1ce2(Context& c){
{uint32_t a=(c.r[4]+0u+252u);c.r[0]=rd<uint32_t>(c,a+0u);}
{if(c.r[0] == 0){c.pc=(270212338u|1u);return;}}
c.pc=270212329u;}
static void b_101b1ce8(Context& c){
{c.r[14]=270212333u;c.pc=(270391404u|1u);return;}
c.pc=270212333u;}
static void b_101b1cec(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[3]);}
{if(c.r[6] == 0){c.pc=(270212448u|1u);return;}}
c.pc=270212341u;}
static void b_101b1cf2(Context& c){
{if(c.r[6] == 0){c.pc=(270212448u|1u);return;}}
c.pc=270212341u;}
static void b_101b1cf4(Context& c){
{uint32_t v=add(c,c.r[9],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270212448u|1u);return;}}
c.pc=270212347u;}
static void b_101b1cfa(Context& c){
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=c.r[8];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[1]=sbits(c,15);}
{c.r[14]=270212367u;c.pc=(270408818u|1u);return;}
c.pc=270212367u;}
static void b_101b1d0e(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[0],~(c.r[3]),1,true);c.r[0]=v;}
{setsbits(c,14,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{setfs(c,12,(fs(c,15))-(fs(c,13)));}
{setfs(c,14,8.0);}
{setfs(c,12,std::fabs(fs(c,12)));}
{fcmp(c,fs(c,12),fs(c,14));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,14)){c.pc=(270212440u|1u);return;}}
c.pc=270212405u;}
static void b_101b1d34(Context& c){
{fcmp(c,fs(c,15),fs(c,13));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{setfs(c,15,-8.0);}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,14)){c.r[1]=sbits(c,15);}}
{if(cond(c,13)){c.r[1]=sbits(c,14);}}
{c.r[14]=270212439u;c.pc=(270392910u|1u);return;}
c.pc=270212439u;}
static void b_101b1d56(Context& c){
{c.pc=(270212448u|1u);return;}
c.pc=270212441u;}
static void b_101b1d58(Context& c){
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=add(c,c.r[7],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270213380u|1u);return;}}
c.pc=270212455u;}
static void b_101b1d60(Context& c){
{uint32_t v=add(c,c.r[7],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270213380u|1u);return;}}
c.pc=270212455u;}
static void b_101b1d66(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270212463u;c.pc=(270211770u|1u);return;}
c.pc=270212463u;}
static void b_101b1d6e(Context& c){
{c.pc=(270213380u|1u);return;}
c.pc=270212465u;}
static void b_101b1d70(Context& c){
{c.r[14]=270212469u;c.pc=(270394904u|1u);return;}
c.pc=270212469u;}
static void b_101b1d74(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270212477u;c.pc=(270398272u|1u);return;}
c.pc=270212477u;}
static void b_101b1d7c(Context& c){
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270212318u|1u);return;}}
c.pc=270212483u;}
static void b_101b1d82(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+140u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[14]=270212495u;c.pc=(270393014u|1u);return;}
c.pc=270212495u;}
static void b_101b1d8e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=22u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[14]=270212505u;c.pc=(270391848u|1u);return;}
c.pc=270212505u;}
static void b_101b1d98(Context& c){
{c.pc=(270212318u|1u);return;}
c.pc=270212507u;}
static void b_101b1d9a(Context& c){
{if(cond(c,13)){c.pc=(270212626u|1u);return;}}
c.pc=270212509u;}
static void b_101b1d9c(Context& c){
{uint32_t v=add(c,c.r[7],~(10u),1,true);}
{if(cond(c,2)){c.pc=(270212528u|1u);return;}}
c.pc=270212513u;}
static void b_101b1da0(Context& c){
{if(c.r[6] != 0){c.pc=(270212596u|1u);return;}}
c.pc=270212515u;}
static void b_101b1da2(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270212527u;c.pc=(270393366u|1u);return;}
c.pc=270212527u;}
static void b_101b1dae(Context& c){
{c.pc=(270212596u|1u);return;}
c.pc=270212529u;}
static void b_101b1db0(Context& c){
{uint32_t v=add(c,c.r[7],~(20u),1,true);}
{if(cond(c,2)){c.pc=(270212620u|1u);return;}}
c.pc=270212533u;}
static void b_101b1db4(Context& c){
{if(c.r[6] != 0){c.pc=(270212546u|1u);return;}}
c.pc=270212535u;}
static void b_101b1db6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270212547u;c.pc=(270393366u|1u);return;}
c.pc=270212547u;}
static void b_101b1dc2(Context& c){
{uint32_t a=(c.r[4]+0u+52u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,1)){c.pc=(270212596u|1u);return;}}
c.pc=270212553u;}
static void b_101b1dc8(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=5u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270212565u;c.pc=c.r[3];return;}
c.pc=270212565u;}
static void b_101b1dd4(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+20u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{uint32_t v=0u;c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{}
{if(cond(c,2)){setfs(c,15,-(fs(c,15)));}}
{c.r[1]=sbits(c,15);}
{c.r[14]=270212597u;c.pc=(270392848u|1u);return;}
c.pc=270212597u;}
static void b_101b1df4(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270212605u;c.pc=(270211596u|1u);return;}
c.pc=270212605u;}
static void b_101b1dfc(Context& c){
{uint32_t v=1u;nz(c,v);c.r[6]=v;}
{uint32_t v=(c.r[0])^(1u);c.r[0]=v;}
{c.r[7]=uint32_t(uint8_t(c.r[0]));}
{c.pc=(270212322u|1u);return;}
c.pc=270212615u;}
static void b_101b1e06(Context& c){
{uint32_t v=add(c,c.r[7],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270213098u|1u);return;}}
c.pc=270212621u;}
static void b_101b1e0c(Context& c){
{uint32_t v=add(c,c.r[7],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270212454u|1u);return;}}
c.pc=270212625u;}
static void b_101b1e10(Context& c){
{c.pc=(270212318u|1u);return;}
c.pc=270212627u;}
static void b_101b1e12(Context& c){
{uint32_t v=add(c,c.r[7],~(22u),1,true);}
{if(cond(c,2)){c.pc=(270212646u|1u);return;}}
c.pc=270212631u;}
static void b_101b1e16(Context& c){
{uint32_t v=0u;nz(c,v);c.r[6]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[14]=270212645u;c.pc=(270391848u|1u);return;}
c.pc=270212645u;}
static void b_101b1e24(Context& c){
{c.pc=(270212320u|1u);return;}
c.pc=270212647u;}
static void b_101b1e26(Context& c){
{uint32_t v=add(c,c.r[7],~(30u),1,true);}
{if(cond(c,2)){c.pc=(270212318u|1u);return;}}
c.pc=270212653u;}
static void b_101b1e2c(Context& c){
{if(c.r[6] != 0){c.pc=(270212668u|1u);return;}}
c.pc=270212655u;}
static void b_101b1e2e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270212667u;c.pc=(270393366u|1u);return;}
c.pc=270212667u;}
static void b_101b1e3a(Context& c){
{c.pc=(270212858u|1u);return;}
c.pc=270212669u;}
static void b_101b1e3c(Context& c){
{uint32_t v=add(c,c.r[9],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270212754u|1u);return;}}
c.pc=270212675u;}
static void b_101b1e42(Context& c){
{uint32_t v=add(c,c.r[6],~(36u),1,true);}
{if(cond(c,2)){c.pc=(270212754u|1u);return;}}
c.pc=270212679u;}
static void b_101b1e46(Context& c){
{c.r[14]=270212683u;c.pc=(270408416u|1u);return;}
c.pc=270212683u;}
static void b_101b1e4a(Context& c){
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[1]=sbits(c,15);}
{c.r[14]=270212701u;c.pc=(270408818u|1u);return;}
c.pc=270212701u;}
static void b_101b1e5c(Context& c){
{uint32_t v=14u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[9];c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[0]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{setfs(c,14,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,(fs(c,14))-(fs(c,15)));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[3]=sbits(c,15);}
{c.r[14]=270212749u;c.pc=(270015700u|1u);return;}
c.pc=270212749u;}
static void b_101b1e8c(Context& c){
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[0]);}
{c.pc=(270212858u|1u);return;}
c.pc=270212755u;}
static void b_101b1e92(Context& c){
{uint32_t v=add(c,c.r[6],~(115u),1,true);}
{if(cond(c,2)){c.pc=(270212776u|1u);return;}}
c.pc=270212759u;}
static void b_101b1e96(Context& c){
{uint32_t a=(c.r[4]+0u+252u);c.r[0]=rd<uint32_t>(c,a+0u);}
{if(c.r[0] == 0){c.pc=(270212858u|1u);return;}}
c.pc=270212765u;}
static void b_101b1e9c(Context& c){
{c.r[14]=270212769u;c.pc=(270391404u|1u);return;}
c.pc=270212769u;}
static void b_101b1ea0(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270212858u|1u);return;}
c.pc=270212777u;}
static void b_101b1ea8(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270212794u|1u);return;}}
c.pc=270212783u;}
static void b_101b1eae(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=30u;nz(c,v);c.r[2]=v;}
{c.r[14]=270212793u;c.pc=(269980032u|1u);return;}
c.pc=270212793u;}
static void b_101b1eb8(Context& c){
{c.pc=(270212858u|1u);return;}
c.pc=270212795u;}
static void b_101b1eba(Context& c){
{uint32_t a=(c.r[4]+0u+252u);c.r[3]=rd<uint32_t>(c,a+0u);}
{if(c.r[3] == 0){c.pc=(270212858u|1u);return;}}
c.pc=270212801u;}
static void b_101b1ec0(Context& c){
{c.r[14]=270212805u;c.pc=(270408416u|1u);return;}
c.pc=270212805u;}
static void b_101b1ec4(Context& c){
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[1]=sbits(c,15);}
{c.r[14]=270212823u;c.pc=(270408818u|1u);return;}
c.pc=270212823u;}
static void b_101b1ed6(Context& c){
{uint32_t a=(c.r[4]+0u+252u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+148u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[3]+0u+148u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[3]+0u+140u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[4]+0u+252u);c.r[3]=rd<uint32_t>(c,a+0u);}
{setsbits(c,13,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,13)));}
{uint32_t a=(c.r[3]+0u+152u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[3]+0u+144u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+108u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270212867u;c.pc=c.r[3];return;}
c.pc=270212867u;}
static void b_101b1efa(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+108u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270212867u;c.pc=c.r[3];return;}
c.pc=270212867u;}
static void b_101b1f02(Context& c){
{c.pc=(270212454u|1u);return;}
c.pc=270212869u;}
static void b_101b1f08(Context& c){
{uint32_t v=add(c,c.r[7],~(110u),1,true);}
{if(cond(c,2)){c.pc=(270213142u|1u);return;}}
c.pc=270212879u;}
static void b_101b1f0e(Context& c){
{if(c.r[6] != 0){c.pc=(270212894u|1u);return;}}
c.pc=270212881u;}
static void b_101b1f10(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270212893u;c.pc=(270393366u|1u);return;}
c.pc=270212893u;}
static void b_101b1f1c(Context& c){
{c.pc=(270213376u|1u);return;}
c.pc=270212895u;}
static void b_101b1f1e(Context& c){
{uint32_t v=add(c,c.r[6],~(2u),1,true);}
{if(cond(c,2)){c.pc=(270213040u|1u);return;}}
c.pc=270212899u;}
static void b_101b1f22(Context& c){
{uint32_t v=4294967295u;c.r[7]=v;}
{uint32_t v=0u;nz(c,v);c.r[6]=v;}
{uint32_t v=65303u;c.r[10]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[10]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=70u;nz(c,v);c.r[2]=v;}
{uint32_t v=~(149u);c.r[3]=v;}
{c.r[14]=270212929u;c.pc=(270015700u|1u);return;}
c.pc=270212929u;}
static void b_101b1f40(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[10]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=~(69u);c.r[2]=v;}
{uint32_t v=~(149u);c.r[3]=v;}
{c.r[14]=270212951u;c.pc=(270015700u|1u);return;}
c.pc=270212951u;}
static void b_101b1f56(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[10]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=90u;nz(c,v);c.r[2]=v;}
{uint32_t v=~(39u);c.r[3]=v;}
{c.r[14]=270212971u;c.pc=(270015700u|1u);return;}
c.pc=270212971u;}
static void b_101b1f6a(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[10]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=~(119u);c.r[2]=v;}
{uint32_t v=~(59u);c.r[3]=v;}
{uint32_t v=add(c,c.r[10],c.r[7],0,false);c.r[10]=v;}
{c.r[14]=270212995u;c.pc=(270015700u|1u);return;}
c.pc=270212995u;}
static void b_101b1f82(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t v=120u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=~(119u);c.r[3]=v;}
{c.r[14]=270213017u;c.pc=(270015700u|1u);return;}
c.pc=270213017u;}
static void b_101b1f98(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[10]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(69u);c.r[2]=v;}
{uint32_t v=~(59u);c.r[3]=v;}
{c.r[14]=270213039u;c.pc=(270015700u|1u);return;}
c.pc=270213039u;}
static void b_101b1fae(Context& c){
{c.pc=(270213376u|1u);return;}
c.pc=270213041u;}
static void b_101b1fb0(Context& c){
{uint32_t v=add(c,c.r[6],~(89u),1,true);}
{if(cond(c,13)){c.pc=(270213150u|1u);return;}}
c.pc=270213045u;}
static void b_101b1fb4(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270213053u;c.pc=(270118736u|1u);return;}
c.pc=270213053u;}
static void b_101b1fbc(Context& c){
{uint32_t v=c.r[0];c.r[7]=v;}
{if(c.r[0] != 0){c.pc=(270213150u|1u);return;}}
c.pc=270213057u;}
static void b_101b1fc0(Context& c){
{c.pc=(270213298u|1u);return;}
c.pc=270213059u;}
static void b_101b1fc2(Context& c){
{uint32_t v=(c.r[6])&(3u);nz(c,v);c.r[6]=v;}
{if(cond(c,2)){c.pc=(270212318u|1u);return;}}
c.pc=270213067u;}
static void b_101b1fca(Context& c){
{uint32_t v=17u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=((270213074u&~3u)+0u+316u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=add(c,c.r[3],270213082u,0,false);c.r[3]=v;}
{uint32_t a=(c.r[3]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=~(249u);c.r[3]=v;}
{c.r[14]=270213097u;c.pc=(270006056u|1u);return;}
c.pc=270213097u;}
static void b_101b1fe8(Context& c){
{c.pc=(270212320u|1u);return;}
c.pc=270213099u;}
static void b_101b1fea(Context& c){
{if(c.r[6] != 0){c.pc=(270213112u|1u);return;}}
c.pc=270213101u;}
static void b_101b1fec(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270213113u;c.pc=(270393366u|1u);return;}
c.pc=270213113u;}
static void b_101b1ff8(Context& c){
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270213127u;c.pc=(270392848u|1u);return;}
c.pc=270213127u;}
static void b_101b2006(Context& c){
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[1];c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270213141u;c.pc=(270392910u|1u);return;}
c.pc=270213141u;}
static void b_101b2014(Context& c){
{c.pc=(270212318u|1u);return;}
c.pc=270213143u;}
static void b_101b2016(Context& c){
{uint32_t v=add(c,c.r[7],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270212878u|1u);return;}}
c.pc=270213149u;}
static void b_101b201c(Context& c){
{c.pc=(270212620u|1u);return;}
c.pc=270213151u;}
static void b_101b201e(Context& c){
{uint32_t v=4294967295u;c.r[7]=v;}
{uint32_t v=0u;nz(c,v);c.r[6]=v;}
{uint32_t v=65284u;c.r[10]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[10]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=70u;nz(c,v);c.r[2]=v;}
{uint32_t v=~(149u);c.r[3]=v;}
{c.r[14]=270213181u;c.pc=(270015700u|1u);return;}
c.pc=270213181u;}
static void b_101b203c(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[10]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=~(69u);c.r[2]=v;}
{uint32_t v=~(149u);c.r[3]=v;}
{c.r[14]=270213203u;c.pc=(270015700u|1u);return;}
c.pc=270213203u;}
static void b_101b2052(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[10]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=90u;nz(c,v);c.r[2]=v;}
{uint32_t v=~(39u);c.r[3]=v;}
{c.r[14]=270213223u;c.pc=(270015700u|1u);return;}
c.pc=270213223u;}
static void b_101b2066(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[10]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=~(119u);c.r[2]=v;}
{uint32_t v=~(59u);c.r[3]=v;}
{uint32_t v=add(c,c.r[10],c.r[7],0,false);c.r[10]=v;}
{c.r[14]=270213247u;c.pc=(270015700u|1u);return;}
c.pc=270213247u;}
static void b_101b207e(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t v=120u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=~(119u);c.r[3]=v;}
{c.r[14]=270213269u;c.pc=(270015700u|1u);return;}
c.pc=270213269u;}
static void b_101b2094(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[10]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(69u);c.r[2]=v;}
{uint32_t v=~(59u);c.r[3]=v;}
{c.r[14]=270213291u;c.pc=(270015700u|1u);return;}
c.pc=270213291u;}
static void b_101b20aa(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270213297u;c.pc=(270391404u|1u);return;}
c.pc=270213297u;}
static void b_101b20b0(Context& c){
{c.pc=(270213376u|1u);return;}
c.pc=270213299u;}
static void b_101b20b2(Context& c){
{uint32_t v=(c.r[6])&(3u);c.r[6]=v;}
{uint32_t v=add(c,c.r[6],~(3u),1,true);}
{if(cond(c,2)){c.pc=(270213374u|1u);return;}}
c.pc=270213307u;}
static void b_101b20ba(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270213313u;c.pc=(270082278u|1u);return;}
c.pc=270213313u;}
static void b_101b20c0(Context& c){
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270213321u;c.pc=(270082278u|1u);return;}
c.pc=270213321u;}
static void b_101b20c8(Context& c){
{uint32_t v=300u;c.r[1]=v;}
{uint32_t v=c.r[0];c.r[10]=v;}
{uint32_t v=c.r[6];c.r[0]=v;}
{c.r[14]=270213333u;c.pc=(270697604u|1u);return;}
c.pc=270213333u;}
static void b_101b20d4(Context& c){
{uint32_t v=c.r[10];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(150u),1,false);c.r[6]=v;}
{uint32_t v=120u;nz(c,v);c.r[1]=v;}
{c.r[14]=270213345u;c.pc=(270697604u|1u);return;}
c.pc=270213345u;}
static void b_101b20e0(Context& c){
{uint32_t v=65302u;c.r[2]=v;}
{uint32_t v=~(59u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=4294967295u;c.r[2]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[1]),1,true);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270213375u;c.pc=(270015700u|1u);return;}
c.pc=270213375u;}
static void b_101b20fe(Context& c){
{uint32_t v=c.r[7];c.r[6]=v;}
{uint32_t v=c.r[6];c.r[7]=v;}
{c.pc=(270212322u|1u);return;}
c.pc=270213381u;}
static void b_101b2100(Context& c){
{uint32_t v=c.r[6];c.r[7]=v;}
{c.pc=(270212322u|1u);return;}
c.pc=270213381u;}
static void b_101b2104(Context& c){
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270213387u;}
static void b_101b2110(Context& c){
{uint32_t a=c.r[13]-24u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-8u;wr<uint64_t>(c,a+0u,c.d[8]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(8u),1,false);c.r[13]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[2];c.r[8]=v;}
{uint32_t v=c.r[3];c.r[5]=v;}
{c.r[14]=270213415u;c.pc=(270408416u|1u);return;}
c.pc=270213415u;}
static void b_101b2126(Context& c){
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270213452u|1u);return;}}
c.pc=270213423u;}
static void b_101b212e(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,11)){c.pc=(270213452u|1u);return;}}
c.pc=270213429u;}
static void b_101b2134(Context& c){
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270213740u|1u);return;}}
c.pc=270213461u;}
static void b_101b214c(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270213740u|1u);return;}}
c.pc=270213461u;}
static void b_101b2154(Context& c){
{c.r[14]=270213465u;c.pc=(270394904u|1u);return;}
c.pc=270213465u;}
static void b_101b2158(Context& c){
{uint32_t a=(c.r[4]+0u+36u);c.r[2]=rd<uint16_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+116u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270213475u;c.pc=(270397652u|1u);return;}
c.pc=270213475u;}
static void b_101b2162(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{if(c.r[0] != 0){c.pc=(270213488u|1u);return;}}
c.pc=270213479u;}
static void b_101b2166(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=110u;nz(c,v);c.r[1]=v;}
{c.r[14]=270213487u;c.pc=(270391848u|1u);return;}
c.pc=270213487u;}
static void b_101b216e(Context& c){
{c.pc=(270213754u|1u);return;}
c.pc=270213489u;}
static void b_101b2170(Context& c){
{uint32_t v=add(c,c.r[5],~(20u),1,true);}
{if(cond(c,2)){c.pc=(270213754u|1u);return;}}
c.pc=270213495u;}
static void b_101b2176(Context& c){
{uint32_t v=add(c,c.r[13],8u,0,false);c.r[2]=v;}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=5u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[2]+0u+4294967292u);uint32_t wb=a;wr<uint32_t>(c,a+0u,c.r[3]);c.r[2]=wb;}
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270213513u;c.pc=c.r[3];return;}
c.pc=270213513u;}
static void b_101b2188(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(270u),1,true);}
{if(cond(c,2)){c.pc=(270213532u|1u);return;}}
c.pc=270213521u;}
static void b_101b2190(Context& c){
{uint32_t a=(c.r[13]+0u+4u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,-(fs(c,15)));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+28u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{setfs(c,15,int32_t(sbits(c,13)));}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=((270213548u&~3u)+0u+216u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{setfs(c,15,(fs(c,15))-(fs(c,14)));}
{setfs(c,15,std::fabs(fs(c,15)));}
{fcmp(c,fs(c,15),fs(c,13));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,12)){c.pc=(270213576u|1u);return;}}
c.pc=270213567u;}
static void b_101b219c(Context& c){
{uint32_t a=(c.r[4]+0u+28u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{setfs(c,15,int32_t(sbits(c,13)));}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=((270213548u&~3u)+0u+216u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{setfs(c,15,(fs(c,15))-(fs(c,14)));}
{setfs(c,15,std::fabs(fs(c,15)));}
{fcmp(c,fs(c,15),fs(c,13));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,12)){c.pc=(270213576u|1u);return;}}
c.pc=270213567u;}
static void b_101b21be(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=2u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270213724u|1u);return;}
c.pc=270213577u;}
static void b_101b21c8(Context& c){
{uint32_t a=((270213580u&~3u)+0u+188u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{fcmp(c,fs(c,15),fs(c,13));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,12)){c.pc=(270213724u|1u);return;}}
c.pc=270213591u;}
static void b_101b21d6(Context& c){
{uint32_t a=(c.r[13]+0u+4u);setsbits(c,12,rd<uint32_t>(c,a+0u));}
{uint32_t a=((270213598u&~3u)+0u+176u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{setfs(c,13,(fs(c,12))*(fs(c,13)));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,sbits(c,13));}
{uint32_t a=(c.r[4]+0u+32u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{c.r[3]=sbits(c,13);}
{setfs(c,16,int32_t(sbits(c,13)));}
{uint32_t v=add(c,c.r[3],37u,0,true);c.r[3]=v;}
{setsbits(c,13,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,13)));}
{fcmp(c,fs(c,16),fs(c,13));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,1)){c.pc=(270213674u|1u);return;}}
c.pc=270213639u;}
static void b_101b2206(Context& c){
{uint32_t a=((270213642u&~3u)+0u+136u);setsbits(c,12,rd<uint32_t>(c,a+0u));}
{setfs(c,15,(fs(c,15))+(fs(c,12)));}
{uint32_t a=((270213650u&~3u)+0u+132u);setsbits(c,12,rd<uint32_t>(c,a+0u));}
{setfs(c,15,(fs(c,15))*(fs(c,12)));}
{setfs(c,12,1.0);}
{setfs(c,12,(fs(c,12))-(fs(c,15)));}
{setfs(c,15,(fs(c,15))*(fs(c,13)));}
{setfs(c,15,fs(c,15)+float((fs(c,12))*(fs(c,16))));}
{setsbits(c,16,sbits(c,15));}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[6];c.r[0]=v;}
{setsbits(c,14,cvti(fs(c,14),true));}
{c.r[1]=sbits(c,14);}
{c.r[14]=270213691u;c.pc=(270408818u|1u);return;}
c.pc=270213691u;}
static void b_101b222a(Context& c){
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[6];c.r[0]=v;}
{setsbits(c,14,cvti(fs(c,14),true));}
{c.r[1]=sbits(c,14);}
{c.r[14]=270213691u;c.pc=(270408818u|1u);return;}
c.pc=270213691u;}
static void b_101b223a(Context& c){
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{setsbits(c,13,c.r[0]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{setfs(c,15,int32_t(sbits(c,13)));}
{fcmp(c,fs(c,15),fs(c,16));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,9)){c.r[1]=sbits(c,16);}}
{if(cond(c,10)){c.r[1]=sbits(c,15);}}
{c.r[14]=270213725u;c.pc=(270393090u|1u);return;}
c.pc=270213725u;}
static void b_101b225c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270213739u;c.pc=(270392848u|1u);return;}
c.pc=270213739u;}
static void b_101b226a(Context& c){
{c.pc=(270213754u|1u);return;}
c.pc=270213741u;}
static void b_101b226c(Context& c){
{uint32_t v=add(c,c.r[5],~(20u),1,true);}
{if(cond(c,2)){c.pc=(270213754u|1u);return;}}
c.pc=270213745u;}
static void b_101b2270(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270213752u&~3u)+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270213755u;c.pc=(269978432u|1u);return;}
c.pc=270213755u;}
static void b_101b227a(Context& c){
{uint32_t v=add(c,c.r[13],8u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.r[13]=a+8u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270213765u;}
static void b_101b229c(Context& c){
{uint32_t a=c.r[13]-24u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[3];c.r[5]=v;}
{uint32_t a=(c.r[1]+0u+52u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[2];c.r[6]=v;}
{if(c.r[3] != 0){c.pc=(270213858u|1u);return;}}
c.pc=270213805u;}
static void b_101b22ac(Context& c){
{uint32_t a=(c.r[1]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{if(c.r[3] == 0){c.pc=(270213858u|1u);return;}}
c.pc=270213809u;}
static void b_101b22b0(Context& c){
{uint32_t v=1u;c.r[8]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t a=(c.r[1]+0u+52u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270213825u;c.pc=(269976968u|1u);return;}
c.pc=270213825u;}
static void b_101b22c0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270213833u;c.pc=(269976986u|1u);return;}
c.pc=270213833u;}
static void b_101b22c8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270213841u;c.pc=(269975400u|1u);return;}
c.pc=270213841u;}
static void b_101b22d0(Context& c){
{uint32_t v=add(c,c.r[6],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270213848u|1u);return;}}
c.pc=270213845u;}
static void b_101b22d4(Context& c){
{uint32_t v=add(c,c.r[6],~(40u),1,true);}
{if(cond(c,2)){c.pc=(270213858u|1u);return;}}
c.pc=270213849u;}
static void b_101b22d8(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270213859u;}
static void b_101b22e2(Context& c){
{uint32_t a=(c.r[4]+0u+52u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(2u),1,true);}
{if(cond(c,2)){c.pc=(270213892u|1u);return;}}
c.pc=270213865u;}
static void b_101b22e8(Context& c){
{uint32_t v=3u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{c.r[14]=270213877u;c.pc=(269976968u|1u);return;}
c.pc=270213877u;}
static void b_101b22f4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{c.r[14]=270213885u;c.pc=(269976986u|1u);return;}
c.pc=270213885u;}
static void b_101b22fc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{c.r[14]=270213893u;c.pc=(269975400u|1u);return;}
c.pc=270213893u;}
static void b_101b2304(Context& c){
{uint32_t v=add(c,c.r[6],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270214104u|1u);return;}}
c.pc=270213897u;}
static void b_101b2308(Context& c){
{if(cond(c,13)){c.pc=(270213924u|1u);return;}}
c.pc=270213899u;}
static void b_101b230a(Context& c){
{uint32_t v=add(c,c.r[6],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270213984u|1u);return;}}
c.pc=270213903u;}
static void b_101b230e(Context& c){
{if(cond(c,13)){c.pc=(270213912u|1u);return;}}
c.pc=270213905u;}
static void b_101b2310(Context& c){
{uint32_t v=add(c,c.r[6],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270213960u|1u);return;}}
c.pc=270213909u;}
static void b_101b2314(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270213913u;}
static void b_101b2318(Context& c){
{uint32_t v=add(c,c.r[6],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270214020u|1u);return;}}
c.pc=270213917u;}
static void b_101b231c(Context& c){
{uint32_t v=add(c,c.r[6],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270214062u|1u);return;}}
c.pc=270213921u;}
static void b_101b2320(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270213925u;}
static void b_101b2324(Context& c){
{uint32_t v=add(c,c.r[6],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270214214u|1u);return;}}
c.pc=270213931u;}
static void b_101b232a(Context& c){
{if(cond(c,13)){c.pc=(270213944u|1u);return;}}
c.pc=270213933u;}
static void b_101b232c(Context& c){
{uint32_t v=add(c,c.r[6],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270214188u|1u);return;}}
c.pc=270213937u;}
static void b_101b2330(Context& c){
{uint32_t v=add(c,c.r[6],~(80u),1,true);}
{if(cond(c,1)){c.pc=(270214146u|1u);return;}}
c.pc=270213941u;}
static void b_101b2334(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270213945u;}
static void b_101b2338(Context& c){
{uint32_t v=add(c,c.r[6],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270214214u|1u);return;}}
c.pc=270213951u;}
static void b_101b233e(Context& c){
{uint32_t v=add(c,c.r[6],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270214260u|1u);return;}}
c.pc=270213957u;}
static void b_101b2344(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270213961u;}
static void b_101b2348(Context& c){
{if(c.r[5] != 0){c.pc=(270213974u|1u);return;}}
c.pc=270213963u;}
static void b_101b234a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270213975u;c.pc=(270393366u|1u);return;}
c.pc=270213975u;}
static void b_101b2356(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{c.pc=(270214012u|1u);return;}
c.pc=270213985u;}
static void b_101b2360(Context& c){
{if(c.r[5] != 0){c.pc=(270214004u|1u);return;}}
c.pc=270213987u;}
static void b_101b2362(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270213999u;c.pc=(270393366u|1u);return;}
c.pc=270213999u;}
static void b_101b236e(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=20u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270213392u|1u);return;}
c.pc=270214021u;}
static void b_101b2374(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=20u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270213392u|1u);return;}
c.pc=270214021u;}
static void b_101b237c(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270213392u|1u);return;}
c.pc=270214021u;}
static void b_101b2384(Context& c){
{if(c.r[5] != 0){c.pc=(270214036u|1u);return;}}
c.pc=270214023u;}
static void b_101b2386(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270214035u;c.pc=(270393366u|1u);return;}
c.pc=270214035u;}
static void b_101b2392(Context& c){
{c.pc=(270214052u|1u);return;}
c.pc=270214037u;}
static void b_101b2394(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270214052u|1u);return;}}
c.pc=270214043u;}
static void b_101b239a(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.r[14]=270214053u;c.pc=(269980032u|1u);return;}
c.pc=270214053u;}
static void b_101b23a4(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=30u;nz(c,v);c.r[3]=v;}
{c.pc=(270214012u|1u);return;}
c.pc=270214063u;}
static void b_101b23ae(Context& c){
{if(c.r[5] != 0){c.pc=(270214078u|1u);return;}}
c.pc=270214065u;}
static void b_101b23b0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270214077u;c.pc=(270393366u|1u);return;}
c.pc=270214077u;}
static void b_101b23bc(Context& c){
{c.pc=(270214094u|1u);return;}
c.pc=270214079u;}
static void b_101b23be(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270214094u|1u);return;}}
c.pc=270214085u;}
static void b_101b23c4(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.r[14]=270214095u;c.pc=(269980032u|1u);return;}
c.pc=270214095u;}
static void b_101b23ce(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=40u;nz(c,v);c.r[3]=v;}
{c.pc=(270214012u|1u);return;}
c.pc=270214105u;}
static void b_101b23d8(Context& c){
{if(c.r[5] != 0){c.pc=(270214120u|1u);return;}}
c.pc=270214107u;}
static void b_101b23da(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270214119u;c.pc=(270393366u|1u);return;}
c.pc=270214119u;}
static void b_101b23e6(Context& c){
{c.pc=(270214136u|1u);return;}
c.pc=270214121u;}
static void b_101b23e8(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270214136u|1u);return;}}
c.pc=270214127u;}
static void b_101b23ee(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.r[14]=270214137u;c.pc=(269980032u|1u);return;}
c.pc=270214137u;}
static void b_101b23f8(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=50u;nz(c,v);c.r[3]=v;}
{c.pc=(270214012u|1u);return;}
c.pc=270214147u;}
static void b_101b2402(Context& c){
{if(c.r[5] != 0){c.pc=(270214162u|1u);return;}}
c.pc=270214149u;}
static void b_101b2404(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270214161u;c.pc=(270393366u|1u);return;}
c.pc=270214161u;}
static void b_101b2410(Context& c){
{c.pc=(270214174u|1u);return;}
c.pc=270214163u;}
static void b_101b2412(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270214174u|1u);return;}}
c.pc=270214169u;}
static void b_101b2418(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(269978432u|1u);return;}
c.pc=270214189u;}
static void b_101b241e(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(269978432u|1u);return;}
c.pc=270214189u;}
static void b_101b242c(Context& c){
{if(c.r[5] != 0){c.pc=(270214196u|1u);return;}}
c.pc=270214191u;}
static void b_101b242e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270214220u|1u);return;}
c.pc=270214197u;}
static void b_101b2434(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{if(c.r[2] != 0){c.pc=(270214284u|1u);return;}}
c.pc=270214203u;}
static void b_101b243a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270391848u|1u);return;}
c.pc=270214215u;}
static void b_101b2446(Context& c){
{if(c.r[5] != 0){c.pc=(270214232u|1u);return;}}
c.pc=270214217u;}
static void b_101b2448(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270393366u|1u);return;}
c.pc=270214233u;}
static void b_101b244c(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270393366u|1u);return;}
c.pc=270214233u;}
static void b_101b244e(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270393366u|1u);return;}
c.pc=270214233u;}
static void b_101b2458(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270214241u;c.pc=(270118736u|1u);return;}
c.pc=270214241u;}
static void b_101b2460(Context& c){
{if(c.r[0] == 0){c.pc=(270214250u|1u);return;}}
c.pc=270214243u;}
static void b_101b2462(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=14u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.pc=(270214222u|1u);return;}
c.pc=270214251u;}
static void b_101b246a(Context& c){
{uint32_t a=(c.r[4]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(14u),1,true);}
{if(cond(c,2)){c.pc=(270214284u|1u);return;}}
c.pc=270214259u;}
static void b_101b2472(Context& c){
{c.pc=(270214268u|1u);return;}
c.pc=270214261u;}
static void b_101b2474(Context& c){
{if(c.r[5] != 0){c.pc=(270214268u|1u);return;}}
c.pc=270214263u;}
static void b_101b2476(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=17u;nz(c,v);c.r[1]=v;}
{c.pc=(270214220u|1u);return;}
c.pc=270214269u;}
static void b_101b247c(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270214284u|1u);return;}}
c.pc=270214275u;}
static void b_101b2482(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270391404u|1u);return;}
c.pc=270214285u;}
static void b_101b248c(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270214289u;}
static void b_101b2490(Context& c){
{uint32_t a=c.r[13]-36u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[11]);wr<uint32_t>(c,a+32u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-16u;wr<uint64_t>(c,a+0u,c.d[8]);wr<uint64_t>(c,a+8u,c.d[9]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(36u),1,false);c.r[13]=v;}
{uint32_t a=((270214302u&~3u)+0u+448u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{uint32_t v=c.r[1];c.r[5]=v;}
{uint32_t v=1u;nz(c,v);c.r[7]=v;}
{uint32_t v=4294967295u;c.r[6]=v;}
{uint32_t v=c.r[0];c.r[4]=v;}
{uint32_t v=65284u;c.r[8]=v;}
{uint32_t v=~(129u);c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[7]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=170u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{setfs(c,19,-16.0);}
{c.r[14]=270214337u;c.pc=(270015700u|1u);return;}
c.pc=270214337u;}
static void b_101b24c0(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[7]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=~(79u);c.r[2]=v;}
{uint32_t v=190u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=65283u;c.r[9]=v;}
{c.r[14]=270214361u;c.pc=(270015700u|1u);return;}
c.pc=270214361u;}
static void b_101b24d8(Context& c){
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=~(39u);c.r[2]=v;}
{uint32_t v=115u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270214383u;c.pc=(270015700u|1u);return;}
c.pc=270214383u;}
static void b_101b24ee(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[7]);wr<uint32_t>(c,a+4u,c.r[9]);}
{setfs(c,18,16.0);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=~(69u);c.r[2]=v;}
{uint32_t v=150u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270214407u;c.pc=(270015700u|1u);return;}
c.pc=270214407u;}
static void b_101b2506(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[7]);wr<uint32_t>(c,a+4u,c.r[9]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=180u;nz(c,v);c.r[2]=v;}
{uint32_t v=110u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=((270214424u&~3u)+0u+328u);c.r[11]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270214429u;c.pc=(270015700u|1u);return;}
c.pc=270214429u;}
static void b_101b251c(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[7]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=30u;nz(c,v);c.r[2]=v;}
{uint32_t v=145u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{setfs(c,17,-8.0);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270214451u;c.pc=(270015700u|1u);return;}
c.pc=270214451u;}
static void b_101b2532(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[7]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=160u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=130u;nz(c,v);c.r[2]=v;}
{uint32_t v=8u;c.r[9]=v;}
{c.r[14]=270214473u;c.pc=(270015700u|1u);return;}
c.pc=270214473u;}
static void b_101b2548(Context& c){
{uint32_t a=(c.r[5]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=1107296256u;c.r[10]=v;}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,2)){uint32_t v=c.r[6];c.r[8]=v;}}
{if(cond(c,1)){uint32_t v=c.r[7];c.r[8]=v;}}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270214493u;c.pc=(270082278u|1u);return;}
c.pc=270214493u;}
static void b_101b2556(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270214493u;c.pc=(270082278u|1u);return;}
c.pc=270214493u;}
static void b_101b255c(Context& c){
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270214501u;c.pc=(270082278u|1u);return;}
c.pc=270214501u;}
static void b_101b2564(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=c.r[7];c.r[0]=v;}
{c.r[14]=270214511u;c.pc=(270697604u|1u);return;}
c.pc=270214511u;}
static void b_101b256e(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[7]=v;}
{uint32_t v=1u;nz(c,v);c.r[6]=v;}
{uint32_t v=add(c,c.r[1],~(130u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[8])*(c.r[1]);c.r[2]=v;}
{uint32_t v=60u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270214531u;c.pc=(270697604u|1u);return;}
c.pc=270214531u;}
static void b_101b2582(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,19));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t v=add(c,c.r[1],~(130u),1,false);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270214565u;c.pc=(270091396u|1u);return;}
c.pc=270214565u;}
static void b_101b25a4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270214571u;c.pc=(270082278u|1u);return;}
c.pc=270214571u;}
static void b_101b25aa(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270214581u;c.pc=(270082278u|1u);return;}
c.pc=270214581u;}
static void b_101b25b4(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270214595u;c.pc=(270697604u|1u);return;}
c.pc=270214595u;}
static void b_101b25c2(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],30u,0,true);c.r[1]=v;}
{uint32_t v=(c.r[8])*(c.r[1]);c.r[2]=v;}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270214613u;c.pc=(270697604u|1u);return;}
c.pc=270214613u;}
static void b_101b25d4(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t v=add(c,c.r[1],~(170u),1,false);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270214647u;c.pc=(270082284u|1u);return;}
c.pc=270214647u;}
static void b_101b25f6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270214653u;c.pc=(270082278u|1u);return;}
c.pc=270214653u;}
static void b_101b25fc(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270214663u;c.pc=(270082278u|1u);return;}
c.pc=270214663u;}
static void b_101b2606(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270214677u;c.pc=(270697604u|1u);return;}
c.pc=270214677u;}
static void b_101b2614(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(50u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[8])*(c.r[1]);c.r[2]=v;}
{uint32_t v=60u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270214695u;c.pc=(270697604u|1u);return;}
c.pc=270214695u;}
static void b_101b2626(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[1],~(130u),1,false);c.r[3]=v;}
{uint32_t v=1090519040u;c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270214731u;c.pc=(270082284u|1u);return;}
c.pc=270214731u;}
static void b_101b264a(Context& c){
{uint32_t v=add(c,c.r[9],~(1u),1,true);c.r[9]=v;}
{if(cond(c,2)){c.pc=(270214486u|1u);return;}}
c.pc=270214737u;}
static void b_101b2650(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);uint32_t newpc=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;c.pc=newpc;return;}
c.pc=270214747u;}
static void b_101b2668(Context& c){
{uint32_t a=c.r[13]-36u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[11]);wr<uint32_t>(c,a+32u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-16u;wr<uint64_t>(c,a+0u,c.d[8]);wr<uint64_t>(c,a+8u,c.d[9]);c.r[13]=a;}
{uint32_t v=c.r[3];c.r[6]=v;}
{uint32_t a=(c.r[1]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],~(36u),1,false);c.r[13]=v;}
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[2];c.r[7]=v;}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270214914u|1u);return;}}
c.pc=270214785u;}
static void b_101b2680(Context& c){
{uint32_t v=1u;c.r[8]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t a=(c.r[1]+0u+28u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270214801u;c.pc=(269975422u|1u);return;}
c.pc=270214801u;}
static void b_101b2690(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270214809u;c.pc=(269975414u|1u);return;}
c.pc=270214809u;}
static void b_101b2698(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270214817u;c.pc=(269975768u|1u);return;}
c.pc=270214817u;}
static void b_101b26a0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270214825u;c.pc=(269976968u|1u);return;}
c.pc=270214825u;}
static void b_101b26a8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270214833u;c.pc=(269976986u|1u);return;}
c.pc=270214833u;}
static void b_101b26b0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270214841u;c.pc=(269975400u|1u);return;}
c.pc=270214841u;}
static void b_101b26b8(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{if(cond(c,2)){c.pc=(270214864u|1u);return;}}
c.pc=270214847u;}
static void b_101b26be(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270214853u;c.pc=(270392110u|1u);return;}
c.pc=270214853u;}
static void b_101b26c4(Context& c){
{uint32_t v=add(c,0u,~(c.r[0]),1,true);c.r[0]=v;}
{setsbits(c,13,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,13)));}
{c.pc=(270214880u|1u);return;}
c.pc=270214865u;}
static void b_101b26d0(Context& c){
{c.r[14]=270214869u;c.pc=(270408416u|1u);return;}
c.pc=270214869u;}
static void b_101b26d4(Context& c){
{c.r[14]=270214873u;c.pc=(270408736u|1u);return;}
c.pc=270214873u;}
static void b_101b26d8(Context& c){
{setsbits(c,14,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=120u;nz(c,v);c.r[2]=v;}
{c.r[14]=270214899u;c.pc=(270393746u|1u);return;}
c.pc=270214899u;}
static void b_101b26e0(Context& c){
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=120u;nz(c,v);c.r[2]=v;}
{c.r[14]=270214899u;c.pc=(270393746u|1u);return;}
c.pc=270214899u;}
static void b_101b26f2(Context& c){
{uint32_t v=add(c,c.r[7],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270214906u|1u);return;}}
c.pc=270214903u;}
static void b_101b26f6(Context& c){
{uint32_t v=add(c,c.r[7],~(30u),1,true);}
{if(cond(c,2)){c.pc=(270214914u|1u);return;}}
c.pc=270214907u;}
static void b_101b26fa(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270216492u|1u);return;}
c.pc=270214915u;}
static void b_101b2702(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270215152u|1u);return;}}
c.pc=270214921u;}
static void b_101b2708(Context& c){
{c.r[14]=270214925u;c.pc=(270394904u|1u);return;}
c.pc=270214925u;}
static void b_101b270c(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270214933u;c.pc=(270398272u|1u);return;}
c.pc=270214933u;}
static void b_101b2714(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270215080u|1u);return;}}
c.pc=270214937u;}
static void b_101b2718(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[0]+0u+148u);setsbits(c,18,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{uint32_t a=((270214950u&~3u)+0u+828u);setsbits(c,17,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{uint32_t v=c.r[4];c.r[0]=v;}
{if(cond(c,2)){c.pc=(270214982u|1u);return;}}
c.pc=270214957u;}
static void b_101b272c(Context& c){
{c.r[14]=270214961u;c.pc=(270392110u|1u);return;}
c.pc=270214961u;}
static void b_101b2730(Context& c){
{setfs(c,17,(fs(c,18))+(fs(c,17)));}
{setsbits(c,13,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,13)));}
{setfs(c,17,(fs(c,17))+(fs(c,15)));}
{fcmp(c,fs(c,16),fs(c,17));}
{c.pc=(270215116u|1u);return;}
c.pc=270214983u;}
static void b_101b2746(Context& c){
{c.r[14]=270214987u;c.pc=(270392110u|1u);return;}
c.pc=270214987u;}
static void b_101b274a(Context& c){
{setsbits(c,14,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{setfs(c,18,(fs(c,18))-(fs(c,15)));}
{setfs(c,17,(fs(c,18))-(fs(c,17)));}
{fcmp(c,fs(c,16),fs(c,17));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,6)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,5)){uint32_t v=1u;c.r[3]=v;}}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270215152u|1u);return;}}
c.pc=270215021u;}
static void b_101b275e(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,6)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,5)){uint32_t v=1u;c.r[3]=v;}}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270215152u|1u);return;}}
c.pc=270215021u;}
static void b_101b2768(Context& c){
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270215152u|1u);return;}}
c.pc=270215021u;}
static void b_101b276c(Context& c){
{uint32_t v=2u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270215031u;c.pc=(270393272u|1u);return;}
c.pc=270215031u;}
static void b_101b2776(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270215037u;c.pc=(269976978u|1u);return;}
c.pc=270215037u;}
static void b_101b277c(Context& c){
{if(c.r[0] == 0){c.pc=(270215046u|1u);return;}}
c.pc=270215039u;}
static void b_101b277e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{c.r[14]=270215047u;c.pc=(269976968u|1u);return;}
c.pc=270215047u;}
static void b_101b2786(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270215053u;c.pc=(269977496u|1u);return;}
c.pc=270215053u;}
static void b_101b278c(Context& c){
{if(c.r[0] == 0){c.pc=(270215062u|1u);return;}}
c.pc=270215055u;}
static void b_101b278e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{c.r[14]=270215063u;c.pc=(269976986u|1u);return;}
c.pc=270215063u;}
static void b_101b2796(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270215069u;c.pc=(269975408u|1u);return;}
c.pc=270215069u;}
static void b_101b279c(Context& c){
{if(c.r[0] == 0){c.pc=(270215152u|1u);return;}}
c.pc=270215071u;}
static void b_101b279e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{c.r[14]=270215079u;c.pc=(269975400u|1u);return;}
c.pc=270215079u;}
static void b_101b27a6(Context& c){
{c.pc=(270215152u|1u);return;}
c.pc=270215081u;}
static void b_101b27a8(Context& c){
{c.r[14]=270215085u;c.pc=(270408416u|1u);return;}
c.pc=270215085u;}
static void b_101b27ac(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{if(cond(c,2)){c.pc=(270215128u|1u);return;}}
c.pc=270215095u;}
static void b_101b27b6(Context& c){
{c.r[14]=270215099u;c.pc=(270408736u|1u);return;}
c.pc=270215099u;}
static void b_101b27ba(Context& c){
{uint32_t v=add(c,c.r[0],shift(c,c.r[0],31,2,false),0,false);c.r[0]=v;}
{uint32_t v=shift(c,c.r[0],1u,3,true);nz(c,v);c.r[0]=v;}
{setsbits(c,13,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,13)));}
{fcmp(c,fs(c,16),fs(c,15));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,14)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{c.pc=(270215016u|1u);return;}
c.pc=270215129u;}
static void b_101b27cc(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,14)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{c.pc=(270215016u|1u);return;}
c.pc=270215129u;}
static void b_101b27d8(Context& c){
{c.r[14]=270215133u;c.pc=(270408736u|1u);return;}
c.pc=270215133u;}
static void b_101b27dc(Context& c){
{uint32_t v=add(c,c.r[0],shift(c,c.r[0],31,2,false),0,false);c.r[0]=v;}
{uint32_t v=shift(c,c.r[0],1u,3,true);nz(c,v);c.r[0]=v;}
{setsbits(c,14,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{fcmp(c,fs(c,16),fs(c,15));}
{c.pc=(270215006u|1u);return;}
c.pc=270215153u;}
static void b_101b27f0(Context& c){
{uint32_t v=add(c,c.r[7],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270215874u|1u);return;}}
c.pc=270215159u;}
static void b_101b27f6(Context& c){
{if(cond(c,13)){c.pc=(270215188u|1u);return;}}
c.pc=270215161u;}
static void b_101b27f8(Context& c){
{uint32_t v=add(c,c.r[7],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270215300u|1u);return;}}
c.pc=270215165u;}
static void b_101b27fc(Context& c){
{if(cond(c,13)){c.pc=(270215176u|1u);return;}}
c.pc=270215167u;}
static void b_101b27fe(Context& c){
{uint32_t v=add(c,c.r[7],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270215224u|1u);return;}}
c.pc=270215171u;}
static void b_101b2802(Context& c){
{uint32_t v=add(c,c.r[7],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270215236u|1u);return;}}
c.pc=270215175u;}
static void b_101b2806(Context& c){
{c.pc=(270216492u|1u);return;}
c.pc=270215177u;}
static void b_101b2808(Context& c){
{uint32_t v=add(c,c.r[7],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270215300u|1u);return;}}
c.pc=270215181u;}
static void b_101b280c(Context& c){
{uint32_t v=add(c,c.r[7],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270215540u|1u);return;}}
c.pc=270215187u;}
static void b_101b2812(Context& c){
{c.pc=(270216492u|1u);return;}
c.pc=270215189u;}
static void b_101b2814(Context& c){
{uint32_t v=add(c,c.r[7],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270215898u|1u);return;}}
c.pc=270215195u;}
static void b_101b281a(Context& c){
{if(cond(c,13)){c.pc=(270215210u|1u);return;}}
c.pc=270215197u;}
static void b_101b281c(Context& c){
{uint32_t v=add(c,c.r[7],~(80u),1,true);}
{if(cond(c,1)){c.pc=(270215826u|1u);return;}}
c.pc=270215203u;}
static void b_101b2822(Context& c){
{uint32_t v=add(c,c.r[7],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270215898u|1u);return;}}
c.pc=270215209u;}
static void b_101b2828(Context& c){
{c.pc=(270216492u|1u);return;}
c.pc=270215211u;}
static void b_101b282a(Context& c){
{uint32_t v=add(c,c.r[7],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270215898u|1u);return;}}
c.pc=270215217u;}
static void b_101b2830(Context& c){
{uint32_t v=add(c,c.r[7],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270216344u|1u);return;}}
c.pc=270215223u;}
static void b_101b2836(Context& c){
{c.pc=(270216492u|1u);return;}
c.pc=270215225u;}
static void b_101b2838(Context& c){
{uint32_t v=add(c,c.r[6],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270216492u|1u);return;}}
c.pc=270215231u;}
static void b_101b283e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270216350u|1u);return;}
c.pc=270215237u;}
static void b_101b2844(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(2u),1,true);}
{if(cond(c,2)){c.pc=(270215272u|1u);return;}}
c.pc=270215243u;}
static void b_101b284a(Context& c){
{if(c.r[6] != 0){c.pc=(270215256u|1u);return;}}
c.pc=270215245u;}
static void b_101b284c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270215257u;c.pc=(270393366u|1u);return;}
c.pc=270215257u;}
static void b_101b2858(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(270393272u|1u);return;}
c.pc=270215273u;}
static void b_101b2868(Context& c){
{if(c.r[6] != 0){c.pc=(270215292u|1u);return;}}
c.pc=270215275u;}
static void b_101b286a(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.r[14]=270215287u;c.pc=(270393366u|1u);return;}
c.pc=270215287u;}
static void b_101b2876(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270215300u&~3u)+0u+480u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270215860u|1u);return;}
c.pc=270215301u;}
static void b_101b287c(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270215300u&~3u)+0u+480u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270215860u|1u);return;}
c.pc=270215301u;}
static void b_101b2884(Context& c){
{uint32_t v=add(c,c.r[6],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270215796u|1u);return;}}
c.pc=270215307u;}
static void b_101b288a(Context& c){
{c.r[14]=270215311u;c.pc=(270394904u|1u);return;}
c.pc=270215311u;}
static void b_101b288e(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[3])^(1u);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],12u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[0]+shift(c,c.r[3],2,1,false)+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270215518u|1u);return;}}
c.pc=270215327u;}
static void b_101b289e(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[0]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[0]+0u+144u);setsbits(c,17,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,1)){setfs(c,16,(fs(c,15))-(fs(c,16)));}}
{if(cond(c,2)){setfs(c,16,(fs(c,16))-(fs(c,15)));}}
{c.r[14]=270215357u;c.pc=(270392182u|1u);return;}
c.pc=270215357u;}
static void b_101b28bc(Context& c){
{uint32_t v=shift(c,c.r[0],1u,3,true);nz(c,v);c.r[0]=v;}
{setsbits(c,15,c.r[0]);}
{setfs(c,14,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,14,(fs(c,17))-(fs(c,14)));}
{setfs(c,14,(fs(c,14))-(fs(c,15)));}
{setfs(c,15,(fs(c,16))*(fs(c,16)));}
{setfs(c,15,fs(c,15)+float((fs(c,14))*(fs(c,14))));}
{setfs(c,15,std::sqrt(fs(c,15)));}
{setfs(c,15,(fs(c,16))/(fs(c,15)));}
{c.r[0]=sbits(c,15);}
{c.r[14]=270215403u;c.pc=(269636148u|0u);return;}
c.pc=270215403u;}
static void b_101b28ea(Context& c){
{uint32_t a=((270215406u&~3u)+0u+384u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=67u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],270215410u,0,false);c.r[3]=v;}
{uint32_t a=(c.r[3]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{setsbits(c,14,c.r[0]);}
{uint32_t v=20u;nz(c,v);c.r[0]=v;}
{setfd(c,6,fs(c,14));}
{uint32_t a=((270215424u&~3u)+0u+344u);c.d[7]=rd<uint64_t>(c,a+0u);}
{setfd(c,7,(fd(c,6))*(fd(c,7)));}
{uint32_t a=(c.r[3]+0u+0u);setsbits(c,12,rd<uint32_t>(c,a+0u));}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{setfd(c,6,fs(c,12));}
{setfd(c,7,(fd(c,7))/(fd(c,6)));}
{setfs(c,14,fd(c,7));}
{uint32_t a=((270215450u&~3u)+0u+336u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{fcmp(c,fs(c,14),fs(c,15));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,9)){setsbits(c,14,sbits(c,15));}}
{uint32_t v=(c.r[0])*(c.r[3]);c.r[2]=v;}
{setsbits(c,13,c.r[2]);}
{setfs(c,15,int32_t(sbits(c,13)));}
{fcmp(c,fs(c,15),fs(c,14));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,9)){c.pc=(270215510u|1u);return;}}
c.pc=270215487u;}
static void b_101b2928(Context& c){
{uint32_t v=(c.r[0])*(c.r[3]);c.r[2]=v;}
{setsbits(c,13,c.r[2]);}
{setfs(c,15,int32_t(sbits(c,13)));}
{fcmp(c,fs(c,15),fs(c,14));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,9)){c.pc=(270215510u|1u);return;}}
c.pc=270215487u;}
static void b_101b293e(Context& c){
{uint32_t v=add(c,c.r[2],20u,0,true);c.r[2]=v;}
{setsbits(c,13,c.r[2]);}
{setfs(c,15,int32_t(sbits(c,13)));}
{fcmp(c,fs(c,15),fs(c,14));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,11)){uint32_t v=add(c,c.r[3],67u,0,false);c.r[1]=v;}}
{uint32_t v=add(c,c.r[3],1u,0,true);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],~(9u),1,true);}
{if(cond(c,2)){c.pc=(270215464u|1u);return;}}
c.pc=270215517u;}
static void b_101b2956(Context& c){
{uint32_t v=add(c,c.r[3],1u,0,true);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],~(9u),1,true);}
{if(cond(c,2)){c.pc=(270215464u|1u);return;}}
c.pc=270215517u;}
static void b_101b295c(Context& c){
{c.pc=(270215520u|1u);return;}
c.pc=270215519u;}
static void b_101b295e(Context& c){
{uint32_t v=67u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(270393366u|1u);return;}
c.pc=270215541u;}
static void b_101b2960(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(270393366u|1u);return;}
c.pc=270215541u;}
static void b_101b2964(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(270393366u|1u);return;}
c.pc=270215541u;}
static void b_101b2974(Context& c){
{uint32_t v=add(c,c.r[6],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270215796u|1u);return;}}
c.pc=270215545u;}
static void b_101b2978(Context& c){
{c.r[14]=270215549u;c.pc=(270394904u|1u);return;}
c.pc=270215549u;}
static void b_101b297c(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[3])^(1u);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],12u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[0]+shift(c,c.r[3],2,1,false)+0u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270215762u|1u);return;}}
c.pc=270215565u;}
static void b_101b298c(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[0]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[0]+0u+144u);setsbits(c,17,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{uint32_t v=7u;c.r[5]=v;}
{}
{if(cond(c,1)){setfs(c,16,(fs(c,15))-(fs(c,16)));}}
{if(cond(c,2)){setfs(c,16,(fs(c,16))-(fs(c,15)));}}
{c.r[14]=270215599u;c.pc=(270392182u|1u);return;}
c.pc=270215599u;}
static void b_101b29ae(Context& c){
{uint32_t v=shift(c,c.r[0],1u,3,true);nz(c,v);c.r[0]=v;}
{setsbits(c,15,c.r[0]);}
{setfs(c,14,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,14,(fs(c,17))-(fs(c,14)));}
{setfs(c,14,(fs(c,14))-(fs(c,15)));}
{setfs(c,15,(fs(c,16))*(fs(c,16)));}
{setfs(c,15,fs(c,15)+float((fs(c,14))*(fs(c,14))));}
{setfs(c,15,std::sqrt(fs(c,15)));}
{setfs(c,15,(fs(c,16))/(fs(c,15)));}
{c.r[0]=sbits(c,15);}
{c.r[14]=270215645u;c.pc=(269636148u|0u);return;}
c.pc=270215645u;}
static void b_101b29dc(Context& c){
{uint32_t a=((270215648u&~3u)+0u+144u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=94u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],270215652u,0,false);c.r[3]=v;}
{uint32_t a=(c.r[3]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{setsbits(c,14,c.r[0]);}
{uint32_t v=25u;nz(c,v);c.r[0]=v;}
{setfd(c,6,fs(c,14));}
{uint32_t a=((270215666u&~3u)+0u+104u);c.d[7]=rd<uint64_t>(c,a+0u);}
{setfd(c,7,(fd(c,6))*(fd(c,7)));}
{uint32_t a=(c.r[3]+0u+0u);setsbits(c,12,rd<uint32_t>(c,a+0u));}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{setfd(c,6,fs(c,12));}
{setfd(c,7,(fd(c,7))/(fd(c,6)));}
{setfs(c,14,fd(c,7));}
{uint32_t a=((270215692u&~3u)+0u+92u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{fcmp(c,fs(c,14),fs(c,15));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,9)){setsbits(c,14,sbits(c,15));}}
{uint32_t v=(c.r[0])*(c.r[3]);c.r[2]=v;}
{setsbits(c,13,c.r[2]);}
{setfs(c,15,int32_t(sbits(c,13)));}
{fcmp(c,fs(c,15),fs(c,14));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,9)){c.pc=(270215754u|1u);return;}}
c.pc=270215729u;}
static void b_101b2a1a(Context& c){
{uint32_t v=(c.r[0])*(c.r[3]);c.r[2]=v;}
{setsbits(c,13,c.r[2]);}
{setfs(c,15,int32_t(sbits(c,13)));}
{fcmp(c,fs(c,15),fs(c,14));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,9)){c.pc=(270215754u|1u);return;}}
c.pc=270215729u;}
static void b_101b2a30(Context& c){
{uint32_t v=add(c,c.r[2],25u,0,true);c.r[2]=v;}
{setsbits(c,13,c.r[2]);}
{setfs(c,15,int32_t(sbits(c,13)));}
{fcmp(c,fs(c,15),fs(c,14));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,11)){uint32_t v=(c.r[5])*(c.r[3]);c.r[1]=v;}}
{if(cond(c,11)){uint32_t v=add(c,c.r[1],94u,0,false);c.r[1]=v;}}
{uint32_t v=add(c,c.r[3],1u,0,true);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],~(7u),1,true);}
{if(cond(c,2)){c.pc=(270215706u|1u);return;}}
c.pc=270215761u;}
static void b_101b2a4a(Context& c){
{uint32_t v=add(c,c.r[3],1u,0,true);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],~(7u),1,true);}
{if(cond(c,2)){c.pc=(270215706u|1u);return;}}
c.pc=270215761u;}
static void b_101b2a50(Context& c){
{c.pc=(270215520u|1u);return;}
c.pc=270215763u;}
static void b_101b2a52(Context& c){
{uint32_t v=94u;nz(c,v);c.r[1]=v;}
{c.pc=(270215520u|1u);return;}
c.pc=270215767u;}
static void b_101b2a74(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270216492u|1u);return;}}
c.pc=270215807u;}
static void b_101b2a7e(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[7];c.r[2]=v;}
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(269980032u|1u);return;}
c.pc=270215827u;}
static void b_101b2a92(Context& c){
{if(c.r[6] != 0){c.pc=(270215842u|1u);return;}}
c.pc=270215829u;}
static void b_101b2a94(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270215841u;c.pc=(270393366u|1u);return;}
c.pc=270215841u;}
static void b_101b2aa0(Context& c){
{c.pc=(270215854u|1u);return;}
c.pc=270215843u;}
static void b_101b2aa2(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270215854u|1u);return;}}
c.pc=270215849u;}
static void b_101b2aa8(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(269978432u|1u);return;}
c.pc=270215875u;}
static void b_101b2aae(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(269978432u|1u);return;}
c.pc=270215875u;}
static void b_101b2ab4(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(269978432u|1u);return;}
c.pc=270215875u;}
static void b_101b2ac2(Context& c){
{if(c.r[6] != 0){c.pc=(270215882u|1u);return;}}
c.pc=270215877u;}
static void b_101b2ac4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270216350u|1u);return;}
c.pc=270215883u;}
static void b_101b2aca(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270216492u|1u);return;}}
c.pc=270215893u;}
static void b_101b2ad4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270216330u|1u);return;}
c.pc=270215899u;}
static void b_101b2ada(Context& c){
{uint32_t v=add(c,c.r[6],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270216320u|1u);return;}}
c.pc=270215905u;}
static void b_101b2ae0(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270215917u;c.pc=(270393366u|1u);return;}
c.pc=270215917u;}
static void b_101b2aec(Context& c){
{setfs(c,19,-16.0);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=236u;nz(c,v);c.r[1]=v;}
{c.r[14]=270215929u;c.pc=(270393772u|1u);return;}
c.pc=270215929u;}
static void b_101b2af8(Context& c){
{uint32_t v=65303u;c.r[8]=v;}
{uint32_t v=4294967295u;c.r[7]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=120u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270215957u;c.pc=(270015700u|1u);return;}
c.pc=270215957u;}
static void b_101b2b14(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=100u;nz(c,v);c.r[2]=v;}
{uint32_t v=120u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{setfs(c,18,16.0);}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270215979u;c.pc=(270015700u|1u);return;}
c.pc=270215979u;}
static void b_101b2b2a(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(99u);c.r[2]=v;}
{uint32_t v=120u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=((270215998u&~3u)+0u+512u);c.r[11]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270216003u;c.pc=(270015700u|1u);return;}
c.pc=270216003u;}
static void b_101b2b42(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=50u;nz(c,v);c.r[2]=v;}
{uint32_t v=170u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=8u;c.r[9]=v;}
{c.r[14]=270216025u;c.pc=(270015700u|1u);return;}
c.pc=270216025u;}
static void b_101b2b58(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{setfs(c,17,-8.0);}
{uint32_t v=170u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(49u);c.r[2]=v;}
{c.r[14]=270216049u;c.pc=(270015700u|1u);return;}
c.pc=270216049u;}
static void b_101b2b70(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=1107296256u;c.r[10]=v;}
{uint32_t a=((270216058u&~3u)+0u+448u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,2)){uint32_t v=c.r[7];c.r[8]=v;}}
{if(cond(c,1)){uint32_t v=1u;c.r[8]=v;}}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270216075u;c.pc=(270082278u|1u);return;}
c.pc=270216075u;}
static void b_101b2b84(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270216075u;c.pc=(270082278u|1u);return;}
c.pc=270216075u;}
static void b_101b2b8a(Context& c){
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270216083u;c.pc=(270082278u|1u);return;}
c.pc=270216083u;}
static void b_101b2b92(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=c.r[7];c.r[0]=v;}
{c.r[14]=270216093u;c.pc=(270697604u|1u);return;}
c.pc=270216093u;}
static void b_101b2b9c(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[7]=v;}
{uint32_t v=1u;nz(c,v);c.r[6]=v;}
{uint32_t v=add(c,c.r[1],~(130u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[8])*(c.r[1]);c.r[2]=v;}
{uint32_t v=60u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270216113u;c.pc=(270697604u|1u);return;}
c.pc=270216113u;}
static void b_101b2bb0(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,19));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t v=add(c,c.r[1],~(130u),1,false);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270216147u;c.pc=(270091396u|1u);return;}
c.pc=270216147u;}
static void b_101b2bd2(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270216153u;c.pc=(270082278u|1u);return;}
c.pc=270216153u;}
static void b_101b2bd8(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270216163u;c.pc=(270082278u|1u);return;}
c.pc=270216163u;}
static void b_101b2be2(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270216177u;c.pc=(270697604u|1u);return;}
c.pc=270216177u;}
static void b_101b2bf0(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],30u,0,true);c.r[1]=v;}
{uint32_t v=(c.r[8])*(c.r[1]);c.r[2]=v;}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270216195u;c.pc=(270697604u|1u);return;}
c.pc=270216195u;}
static void b_101b2c02(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t v=add(c,c.r[1],~(170u),1,false);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270216229u;c.pc=(270082284u|1u);return;}
c.pc=270216229u;}
static void b_101b2c24(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{c.r[14]=270216235u;c.pc=(270082278u|1u);return;}
c.pc=270216235u;}
static void b_101b2c2a(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270216245u;c.pc=(270082278u|1u);return;}
c.pc=270216245u;}
static void b_101b2c34(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270216259u;c.pc=(270697604u|1u);return;}
c.pc=270216259u;}
static void b_101b2c42(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(50u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[8])*(c.r[1]);c.r[2]=v;}
{uint32_t v=60u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270216277u;c.pc=(270697604u|1u);return;}
c.pc=270216277u;}
static void b_101b2c54(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[1],~(130u),1,false);c.r[3]=v;}
{uint32_t v=1090519040u;c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270216313u;c.pc=(270082284u|1u);return;}
c.pc=270216313u;}
static void b_101b2c78(Context& c){
{uint32_t v=add(c,c.r[9],~(1u),1,true);c.r[9]=v;}
{if(cond(c,2)){c.pc=(270216068u|1u);return;}}
c.pc=270216319u;}
static void b_101b2c7e(Context& c){
{c.pc=(270216492u|1u);return;}
c.pc=270216321u;}
static void b_101b2c80(Context& c){
{uint32_t v=add(c,c.r[6],~(9u),1,true);}
{if(cond(c,14)){c.pc=(270216492u|1u);return;}}
c.pc=270216325u;}
static void b_101b2c84(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=140u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(270391848u|1u);return;}
c.pc=270216345u;}
static void b_101b2c8a(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(270391848u|1u);return;}
c.pc=270216345u;}
static void b_101b2c98(Context& c){
{if(c.r[6] != 0){c.pc=(270216354u|1u);return;}}
c.pc=270216347u;}
static void b_101b2c9a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=138u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.pc=(270215524u|1u);return;}
c.pc=270216355u;}
static void b_101b2c9e(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{c.pc=(270215524u|1u);return;}
c.pc=270216355u;}
static void b_101b2ca2(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] == 0){c.pc=(270216364u|1u);return;}}
c.pc=270216361u;}
static void b_101b2ca8(Context& c){
{uint32_t v=add(c,c.r[6],~(89u),1,true);}
{if(cond(c,14)){c.pc=(270216492u|1u);return;}}
c.pc=270216365u;}
static void b_101b2cac(Context& c){
{uint32_t v=0u;nz(c,v);c.r[6]=v;}
{uint32_t v=65284u;c.r[8]=v;}
{uint32_t v=4294967295u;c.r[7]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=120u;nz(c,v);c.r[3]=v;}
{c.r[14]=270216393u;c.pc=(270015700u|1u);return;}
c.pc=270216393u;}
static void b_101b2cc8(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=100u;nz(c,v);c.r[2]=v;}
{uint32_t v=120u;nz(c,v);c.r[3]=v;}
{c.r[14]=270216411u;c.pc=(270015700u|1u);return;}
c.pc=270216411u;}
static void b_101b2cda(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=~(99u);c.r[2]=v;}
{uint32_t v=120u;nz(c,v);c.r[3]=v;}
{c.r[14]=270216431u;c.pc=(270015700u|1u);return;}
c.pc=270216431u;}
static void b_101b2cee(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=50u;nz(c,v);c.r[2]=v;}
{uint32_t v=170u;nz(c,v);c.r[3]=v;}
{c.r[14]=270216449u;c.pc=(270015700u|1u);return;}
c.pc=270216449u;}
static void b_101b2d00(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(49u);c.r[2]=v;}
{uint32_t v=170u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[6]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[7]);}
{c.r[14]=270216469u;c.pc=(270015700u|1u);return;}
c.pc=270216469u;}
static void b_101b2d14(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270216477u;c.pc=(270214288u|1u);return;}
c.pc=270216477u;}
static void b_101b2d1c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);c.r[14]=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;}
{c.pc=(270391404u|1u);return;}
c.pc=270216493u;}
static void b_101b2d2c(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);uint32_t newpc=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;c.pc=newpc;return;}
c.pc=270216503u;}
static void b_101b2d40(Context& c){
{uint32_t a=c.r[13]-12u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+252u);c.r[5]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],~(20u),1,false);c.r[13]=v;}
{if(c.r[5] != 0){c.pc=(270216582u|1u);return;}}
c.pc=270216525u;}
static void b_101b2d4c(Context& c){
{uint32_t a=(c.r[1]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],8u,0,false);c.r[2]=v;}
{uint32_t v=38u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270216537u;c.pc=c.r[3];return;}
c.pc=270216537u;}
static void b_101b2d58(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270216549u;c.pc=c.r[3];return;}
c.pc=270216549u;}
static void b_101b2d64(Context& c){
{uint32_t a=(c.r[4]+0u+277u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=173u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+12u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270216569u;c.pc=(270393892u|1u);return;}
c.pc=270216569u;}
static void b_101b2d78(Context& c){
{if(c.r[0] == 0){c.pc=(270216582u|1u);return;}}
c.pc=270216571u;}
static void b_101b2d7a(Context& c){
{uint32_t a=(c.r[4]+0u+240u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[0]+0u+240u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);uint32_t newpc=rd<uint32_t>(c,a+8u);c.r[13]=a+12u;c.pc=newpc;return;}
c.pc=270216587u;}
static void b_101b2d86(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);uint32_t newpc=rd<uint32_t>(c,a+8u);c.r[13]=a+12u;c.pc=newpc;return;}
c.pc=270216587u;}
static void b_101b2d8a(Context& c){
{uint32_t a=c.r[13]-24u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[2];c.r[6]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[3];c.r[5]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{c.r[14]=270216603u;c.pc=(270326600u|1u);return;}
c.pc=270216603u;}
static void b_101b2d9a(Context& c){
{uint32_t v=add(c,c.r[0],18432u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(5u),1,true);c.r[3]=v;}
{uint32_t v=add(c,0u,~(c.r[3]),1,true);c.r[8]=v;}
{uint32_t v=add(c,c.r[8],c.r[3],c.c,true);c.r[8]=v;}
{c.r[14]=270216623u;c.pc=(270394904u|1u);return;}
c.pc=270216623u;}
static void b_101b2dae(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270216631u;c.pc=(270398272u|1u);return;}
c.pc=270216631u;}
static void b_101b2db6(Context& c){
{uint32_t v=add(c,c.r[6],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270216806u|1u);return;}}
c.pc=270216635u;}
static void b_101b2dba(Context& c){
{if(cond(c,13)){c.pc=(270216662u|1u);return;}}
c.pc=270216637u;}
static void b_101b2dbc(Context& c){
{uint32_t v=add(c,c.r[6],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270216762u|1u);return;}}
c.pc=270216641u;}
static void b_101b2dc0(Context& c){
{if(cond(c,13)){c.pc=(270216650u|1u);return;}}
c.pc=270216643u;}
static void b_101b2dc2(Context& c){
{uint32_t v=add(c,c.r[6],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270216762u|1u);return;}}
c.pc=270216647u;}
static void b_101b2dc6(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270216651u;}
static void b_101b2dca(Context& c){
{uint32_t v=add(c,c.r[6],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270216806u|1u);return;}}
c.pc=270216655u;}
static void b_101b2dce(Context& c){
{uint32_t v=add(c,c.r[6],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270216806u|1u);return;}}
c.pc=270216659u;}
static void b_101b2dd2(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270216663u;}
static void b_101b2dd6(Context& c){
{uint32_t v=add(c,c.r[6],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270216882u|1u);return;}}
c.pc=270216667u;}
static void b_101b2dda(Context& c){
{if(cond(c,13)){c.pc=(270216680u|1u);return;}}
c.pc=270216669u;}
static void b_101b2ddc(Context& c){
{uint32_t v=add(c,c.r[6],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270216854u|1u);return;}}
c.pc=270216673u;}
static void b_101b2de0(Context& c){
{uint32_t v=add(c,c.r[6],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270216882u|1u);return;}}
c.pc=270216677u;}
static void b_101b2de4(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270216681u;}
static void b_101b2de8(Context& c){
{uint32_t v=add(c,c.r[6],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270216882u|1u);return;}}
c.pc=270216685u;}
static void b_101b2dec(Context& c){
{uint32_t v=add(c,c.r[6],~(141u),1,true);}
{if(cond(c,2)){c.pc=(270217034u|1u);return;}}
c.pc=270216691u;}
static void b_101b2df2(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270217034u|1u);return;}}
c.pc=270216697u;}
static void b_101b2df8(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270216709u;c.pc=(270393366u|1u);return;}
c.pc=270216709u;}
static void b_101b2e04(Context& c){
{setfs(c,15,10.0);}
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,1)){setfs(c,15,(fs(c,14))-(fs(c,15)));}}
{if(cond(c,2)){setfs(c,15,(fs(c,14))+(fs(c,15)));}}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270217034u|1u);return;}}
c.pc=270216747u;}
static void b_101b2e2a(Context& c){
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270216763u;}
static void b_101b2e3a(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270217034u|1u);return;}}
c.pc=270216769u;}
static void b_101b2e40(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270216781u;c.pc=(270393366u|1u);return;}
c.pc=270216781u;}
static void b_101b2e4c(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270217034u|1u);return;}}
c.pc=270216787u;}
static void b_101b2e52(Context& c){
{uint32_t a=(c.r[4]+0u+32u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270216807u;}
static void b_101b2e66(Context& c){
{if(c.r[5] != 0){c.pc=(270216832u|1u);return;}}
c.pc=270216809u;}
static void b_101b2e68(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270216821u;c.pc=(270393366u|1u);return;}
c.pc=270216821u;}
static void b_101b2e74(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(269975106u|1u);return;}
c.pc=270216833u;}
static void b_101b2e80(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270216841u;c.pc=(270118736u|1u);return;}
c.pc=270216841u;}
static void b_101b2e88(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270216960u|1u);return;}}
c.pc=270216845u;}
static void b_101b2e8c(Context& c){
{uint32_t a=(c.r[4]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(10u),1,true);}
{if(cond(c,2)){c.pc=(270216960u|1u);return;}}
c.pc=270216853u;}
static void b_101b2e94(Context& c){
{c.pc=(270216944u|1u);return;}
c.pc=270216855u;}
static void b_101b2e96(Context& c){
{if(c.r[5] != 0){c.pc=(270216862u|1u);return;}}
c.pc=270216857u;}
static void b_101b2e98(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270216896u|1u);return;}
c.pc=270216863u;}
static void b_101b2e9e(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270217034u|1u);return;}}
c.pc=270216871u;}
static void b_101b2ea6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270391848u|1u);return;}
c.pc=270216883u;}
static void b_101b2eb2(Context& c){
{uint32_t a=(c.r[0]+0u+776u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,14)){c.pc=(270216920u|1u);return;}}
c.pc=270216891u;}
static void b_101b2eba(Context& c){
{if(c.r[5] != 0){c.pc=(270216900u|1u);return;}}
c.pc=270216893u;}
static void b_101b2ebc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.pc=(270216950u|1u);return;}
c.pc=270216901u;}
static void b_101b2ec0(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{c.pc=(270216950u|1u);return;}
c.pc=270216901u;}
static void b_101b2ec4(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270216909u;c.pc=(270118736u|1u);return;}
c.pc=270216909u;}
static void b_101b2ecc(Context& c){
{if(c.r[0] == 0){c.pc=(270217000u|1u);return;}}
c.pc=270216911u;}
static void b_101b2ece(Context& c){
{uint32_t a=(c.r[4]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(13u),1,true);}
{if(cond(c,2)){c.pc=(270217000u|1u);return;}}
c.pc=270216919u;}
static void b_101b2ed6(Context& c){
{c.pc=(270216944u|1u);return;}
c.pc=270216921u;}
static void b_101b2ed8(Context& c){
{if(c.r[5] != 0){c.pc=(270216928u|1u);return;}}
c.pc=270216923u;}
static void b_101b2eda(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=17u;nz(c,v);c.r[1]=v;}
{c.pc=(270216896u|1u);return;}
c.pc=270216929u;}
static void b_101b2ee0(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270217034u|1u);return;}}
c.pc=270216935u;}
static void b_101b2ee6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270391404u|1u);return;}
c.pc=270216945u;}
static void b_101b2ef0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=18u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270393366u|1u);return;}
c.pc=270216961u;}
static void b_101b2ef6(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[14]=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;}
{c.pc=(270393366u|1u);return;}
c.pc=270216961u;}
static void b_101b2f00(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[1]=rd<uint8_t>(c,a+0u);}
{if(c.r[1] != 0){c.pc=(270217034u|1u);return;}}
c.pc=270216967u;}
static void b_101b2f06(Context& c){
{uint32_t a=(c.r[4]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(18u),1,true);}
{if(cond(c,2)){c.pc=(270217034u|1u);return;}}
c.pc=270216975u;}
static void b_101b2f0e(Context& c){
{uint32_t v=4u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270216985u;c.pc=(269975106u|1u);return;}
c.pc=270216985u;}
static void b_101b2f18(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270217024u|1u);return;}}
c.pc=270216991u;}
static void b_101b2f1e(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270217001u;}
static void b_101b2f28(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270217034u|1u);return;}}
c.pc=270217007u;}
static void b_101b2f2e(Context& c){
{uint32_t a=(c.r[4]+0u+196u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(18u),1,true);}
{if(cond(c,2)){c.pc=(270217034u|1u);return;}}
c.pc=270217015u;}
static void b_101b2f36(Context& c){
{uint32_t v=4u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270216934u|1u);return;}}
c.pc=270217025u;}
static void b_101b2f40(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270217033u;c.pc=(270216512u|1u);return;}
c.pc=270217033u;}
static void b_101b2f48(Context& c){
{c.pc=(270216934u|1u);return;}
c.pc=270217035u;}
static void b_101b2f4a(Context& c){
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270217039u;}
static void b_101b2f50(Context& c){
{uint32_t a=c.r[13]-36u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[11]);wr<uint32_t>(c,a+32u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-16u;wr<uint64_t>(c,a+0u,c.d[8]);wr<uint64_t>(c,a+8u,c.d[9]);c.r[13]=a;}
{setfs(c,19,-16.0);}
{uint32_t a=((270217056u&~3u)+0u+324u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[13],~(36u),1,false);c.r[13]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t v=65284u;c.r[3]=v;}
{uint32_t v=4294967295u;c.r[6]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[2]);wr<uint32_t>(c,a+4u,c.r[3]);wr<uint32_t>(c,a+8u,c.r[6]);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[1];c.r[5]=v;}
{uint32_t v=c.r[2];c.r[3]=v;}
{uint32_t v=c.r[0];c.r[4]=v;}
{c.r[14]=270217085u;c.pc=(270015700u|1u);return;}
c.pc=270217085u;}
static void b_101b2f7c(Context& c){
{uint32_t a=(c.r[5]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=8u;c.r[9]=v;}
{uint32_t a=((270217094u&~3u)+0u+292u);c.r[11]=rd<uint32_t>(c,a+0u);}
{uint32_t v=1107296256u;c.r[10]=v;}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,2)){uint32_t v=4294967295u;c.r[8]=v;}}
{if(cond(c,1)){uint32_t v=1u;c.r[8]=v;}}
{setfs(c,18,16.0);}
{setfs(c,17,-8.0);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270217125u;c.pc=(270082278u|1u);return;}
c.pc=270217125u;}
static void b_101b2f9e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270217125u;c.pc=(270082278u|1u);return;}
c.pc=270217125u;}
static void b_101b2fa4(Context& c){
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270217133u;c.pc=(270082278u|1u);return;}
c.pc=270217133u;}
static void b_101b2fac(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=c.r[7];c.r[0]=v;}
{c.r[14]=270217143u;c.pc=(270697604u|1u);return;}
c.pc=270217143u;}
static void b_101b2fb6(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[7]=v;}
{uint32_t v=1u;nz(c,v);c.r[6]=v;}
{uint32_t v=add(c,c.r[1],~(130u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[8])*(c.r[1]);c.r[2]=v;}
{uint32_t v=60u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270217163u;c.pc=(270697604u|1u);return;}
c.pc=270217163u;}
static void b_101b2fca(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,19));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t v=add(c,c.r[1],~(130u),1,false);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270217197u;c.pc=(270091396u|1u);return;}
c.pc=270217197u;}
static void b_101b2fec(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270217203u;c.pc=(270082278u|1u);return;}
c.pc=270217203u;}
static void b_101b2ff2(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270217213u;c.pc=(270082278u|1u);return;}
c.pc=270217213u;}
static void b_101b2ffc(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270217227u;c.pc=(270697604u|1u);return;}
c.pc=270217227u;}
static void b_101b300a(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],30u,0,true);c.r[1]=v;}
{uint32_t v=(c.r[8])*(c.r[1]);c.r[2]=v;}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270217245u;c.pc=(270697604u|1u);return;}
c.pc=270217245u;}
static void b_101b301c(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t v=add(c,c.r[1],~(170u),1,false);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270217279u;c.pc=(270082284u|1u);return;}
c.pc=270217279u;}
static void b_101b303e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270217285u;c.pc=(270082278u|1u);return;}
c.pc=270217285u;}
static void b_101b3044(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270217295u;c.pc=(270082278u|1u);return;}
c.pc=270217295u;}
static void b_101b304e(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270217309u;c.pc=(270697604u|1u);return;}
c.pc=270217309u;}
static void b_101b305c(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(50u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[8])*(c.r[1]);c.r[2]=v;}
{uint32_t v=60u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270217327u;c.pc=(270697604u|1u);return;}
c.pc=270217327u;}
static void b_101b306e(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[1],~(130u),1,false);c.r[3]=v;}
{uint32_t v=1090519040u;c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270217363u;c.pc=(270082284u|1u);return;}
c.pc=270217363u;}
static void b_101b3092(Context& c){
{uint32_t v=add(c,c.r[9],~(1u),1,true);c.r[9]=v;}
{if(cond(c,2)){c.pc=(270217118u|1u);return;}}
c.pc=270217369u;}
static void b_101b3098(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);uint32_t newpc=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;c.pc=newpc;return;}
c.pc=270217379u;}
static void b_101b30ac(Context& c){
{uint32_t a=c.r[13]-32u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-8u;wr<uint64_t>(c,a+0u,c.d[8]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t a=(c.r[1]+0u+28u);c.r[8]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],~(24u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[2];c.r[7]=v;}
{uint32_t v=c.r[3];c.r[5]=v;}
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270217496u|1u);return;}}
c.pc=270217417u;}
static void b_101b30c8(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=20u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270217427u;c.pc=(270393746u|1u);return;}
c.pc=270217427u;}
static void b_101b30d2(Context& c){
{uint32_t v=c.r[4];c.r[2]=v;}
{uint32_t a=(c.r[2]+0u+0u);uint32_t wb=c.r[2]+28u;c.r[3]=rd<uint32_t>(c,a+0u);c.r[2]=wb;}
{uint32_t v=3u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270217441u;c.pc=c.r[3];return;}
c.pc=270217441u;}
static void b_101b30e0(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(21u);c.r[2]=v;}
{uint32_t v=add(c,c.r[3],shift(c,c.r[3],31,2,false),0,false);c.r[3]=v;}
{uint32_t v=shift(c,c.r[3],1u,3,true);nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=41u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=((270217470u&~3u)+0u+992u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],270217472u,0,false);c.r[3]=v;}
{uint32_t a=(c.r[3]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=56u;nz(c,v);c.r[3]=v;}
{c.r[14]=270217481u;c.pc=(270077468u|1u);return;}
c.pc=270217481u;}
static void b_101b3108(Context& c){
{if(c.r[0] == 0){c.pc=(270217496u|1u);return;}}
c.pc=270217483u;}
static void b_101b310a(Context& c){
{uint32_t a=(c.r[4]+0u+240u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],2u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[0]+0u+240u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t a=(c.r[4]+0u+32u);c.r[8]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270217546u|1u);return;}}
c.pc=270217507u;}
static void b_101b3118(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[8]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270217546u|1u);return;}}
c.pc=270217507u;}
static void b_101b3122(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=2u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270217519u;c.pc=c.r[3];return;}
c.pc=270217519u;}
static void b_101b312e(Context& c){
{uint32_t a=(c.r[13]+0u+20u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,14)){c.pc=(270217546u|1u);return;}}
c.pc=270217525u;}
static void b_101b3134(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(c.r[2]),1,true);}
{if(cond(c,13)){c.pc=(270217546u|1u);return;}}
c.pc=270217531u;}
static void b_101b313a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=81u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[8];c.r[2]=v;}
{c.r[14]=270217541u;c.pc=(270391848u|1u);return;}
c.pc=270217541u;}
static void b_101b3144(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270218448u|1u);return;}
c.pc=270217547u;}
static void b_101b314a(Context& c){
{uint32_t v=add(c,c.r[7],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270217736u|1u);return;}}
c.pc=270217551u;}
static void b_101b314e(Context& c){
{if(cond(c,13)){c.pc=(270217580u|1u);return;}}
c.pc=270217553u;}
static void b_101b3150(Context& c){
{uint32_t v=add(c,c.r[7],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270217778u|1u);return;}}
c.pc=270217557u;}
static void b_101b3154(Context& c){
{if(cond(c,13)){c.pc=(270217568u|1u);return;}}
c.pc=270217559u;}
static void b_101b3156(Context& c){
{uint32_t v=add(c,c.r[7],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270217702u|1u);return;}}
c.pc=270217563u;}
static void b_101b315a(Context& c){
{uint32_t v=add(c,c.r[7],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270217702u|1u);return;}}
c.pc=270217567u;}
static void b_101b315e(Context& c){
{c.pc=(270218448u|1u);return;}
c.pc=270217569u;}
static void b_101b3160(Context& c){
{uint32_t v=add(c,c.r[7],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270217820u|1u);return;}}
c.pc=270217573u;}
static void b_101b3164(Context& c){
{uint32_t v=add(c,c.r[7],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270217886u|1u);return;}}
c.pc=270217579u;}
static void b_101b316a(Context& c){
{c.pc=(270218448u|1u);return;}
c.pc=270217581u;}
static void b_101b316c(Context& c){
{uint32_t v=add(c,c.r[7],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270218012u|1u);return;}}
c.pc=270217587u;}
static void b_101b3172(Context& c){
{if(cond(c,13)){c.pc=(270217602u|1u);return;}}
c.pc=270217589u;}
static void b_101b3174(Context& c){
{uint32_t v=add(c,c.r[7],~(81u),1,true);}
{if(cond(c,1)){c.pc=(270217978u|1u);return;}}
c.pc=270217595u;}
static void b_101b317a(Context& c){
{uint32_t v=add(c,c.r[7],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270218012u|1u);return;}}
c.pc=270217601u;}
static void b_101b3180(Context& c){
{c.pc=(270218448u|1u);return;}
c.pc=270217603u;}
static void b_101b3182(Context& c){
{uint32_t v=add(c,c.r[7],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270218012u|1u);return;}}
c.pc=270217609u;}
static void b_101b3188(Context& c){
{uint32_t v=add(c,c.r[7],~(141u),1,true);}
{if(cond(c,2)){c.pc=(270218448u|1u);return;}}
c.pc=270217615u;}
static void b_101b318e(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270218448u|1u);return;}}
c.pc=270217621u;}
static void b_101b3194(Context& c){
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270217633u;c.pc=(270393366u|1u);return;}
c.pc=270217633u;}
static void b_101b31a0(Context& c){
{setfs(c,15,10.0);}
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,1)){setfs(c,16,(fs(c,16))-(fs(c,15)));}}
{if(cond(c,2)){setfs(c,16,(fs(c,16))+(fs(c,15)));}}
{setsbits(c,16,cvti(fs(c,16),true));}
{setfs(c,15,int32_t(sbits(c,16)));}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.r[14]=270217675u;c.pc=(270408416u|1u);return;}
c.pc=270217675u;}
static void b_101b31ca(Context& c){
{c.r[1]=sbits(c,16);}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[14]=270217685u;c.pc=(270408818u|1u);return;}
c.pc=270217685u;}
static void b_101b31d4(Context& c){
{setsbits(c,14,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.pc=(270218448u|1u);return;}
c.pc=270217703u;}
static void b_101b31e6(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270218448u|1u);return;}}
c.pc=270217709u;}
static void b_101b31ec(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270217715u;c.pc=(269975956u|1u);return;}
c.pc=270217715u;}
static void b_101b31f2(Context& c){
{if(c.r[0] == 0){c.pc=(270217722u|1u);return;}}
c.pc=270217717u;}
static void b_101b31f4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=53u;nz(c,v);c.r[1]=v;}
{c.pc=(270217726u|1u);return;}
c.pc=270217723u;}
static void b_101b31fa(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270217735u;c.pc=(270393366u|1u);return;}
c.pc=270217735u;}
static void b_101b31fe(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270217735u;c.pc=(270393366u|1u);return;}
c.pc=270217735u;}
static void b_101b3200(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270217735u;c.pc=(270393366u|1u);return;}
c.pc=270217735u;}
static void b_101b3206(Context& c){
{c.pc=(270218448u|1u);return;}
c.pc=270217737u;}
static void b_101b3208(Context& c){
{if(c.r[5] != 0){c.pc=(270217758u|1u);return;}}
c.pc=270217739u;}
static void b_101b320a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270217745u;c.pc=(269975956u|1u);return;}
c.pc=270217745u;}
static void b_101b3210(Context& c){
{if(c.r[0] == 0){c.pc=(270217752u|1u);return;}}
c.pc=270217747u;}
static void b_101b3212(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=57u;nz(c,v);c.r[1]=v;}
{c.pc=(270217726u|1u);return;}
c.pc=270217753u;}
static void b_101b3218(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270217726u|1u);return;}
c.pc=270217759u;}
static void b_101b321e(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270218448u|1u);return;}}
c.pc=270217769u;}
static void b_101b3228(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.r[14]=270217777u;c.pc=(270391848u|1u);return;}
c.pc=270217777u;}
static void b_101b3230(Context& c){
{c.pc=(270218448u|1u);return;}
c.pc=270217779u;}
static void b_101b3232(Context& c){
{if(c.r[5] != 0){c.pc=(270217864u|1u);return;}}
c.pc=270217781u;}
static void b_101b3234(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270217787u;c.pc=(269975956u|1u);return;}
c.pc=270217787u;}
static void b_101b323a(Context& c){
{if(c.r[0] == 0){c.pc=(270217794u|1u);return;}}
c.pc=270217789u;}
static void b_101b323c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=54u;nz(c,v);c.r[1]=v;}
{c.pc=(270217798u|1u);return;}
c.pc=270217795u;}
static void b_101b3242(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270217807u;c.pc=(270393366u|1u);return;}
c.pc=270217807u;}
static void b_101b3246(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270217807u;c.pc=(270393366u|1u);return;}
c.pc=270217807u;}
static void b_101b324e(Context& c){
{uint32_t a=(c.r[4]+0u+252u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270218448u|1u);return;}}
c.pc=270217817u;}
static void b_101b3258(Context& c){
{uint32_t v=41u;nz(c,v);c.r[1]=v;}
{c.pc=(270217860u|1u);return;}
c.pc=270217821u;}
static void b_101b325c(Context& c){
{if(c.r[5] != 0){c.pc=(270217864u|1u);return;}}
c.pc=270217823u;}
static void b_101b325e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270217829u;c.pc=(269975956u|1u);return;}
c.pc=270217829u;}
static void b_101b3264(Context& c){
{if(c.r[0] == 0){c.pc=(270217836u|1u);return;}}
c.pc=270217831u;}
static void b_101b3266(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=55u;nz(c,v);c.r[1]=v;}
{c.pc=(270217840u|1u);return;}
c.pc=270217837u;}
static void b_101b326c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270217849u;c.pc=(270393366u|1u);return;}
c.pc=270217849u;}
static void b_101b3270(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270217849u;c.pc=(270393366u|1u);return;}
c.pc=270217849u;}
static void b_101b3278(Context& c){
{uint32_t a=(c.r[4]+0u+252u);c.r[0]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270218448u|1u);return;}}
c.pc=270217859u;}
static void b_101b3282(Context& c){
{uint32_t v=32u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.pc=(270217728u|1u);return;}
c.pc=270217865u;}
static void b_101b3284(Context& c){
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.pc=(270217728u|1u);return;}
c.pc=270217865u;}
static void b_101b3288(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270218448u|1u);return;}}
c.pc=270217875u;}
static void b_101b3292(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[7];c.r[2]=v;}
{c.r[14]=270217885u;c.pc=(269980032u|1u);return;}
c.pc=270217885u;}
static void b_101b329c(Context& c){
{c.pc=(270218448u|1u);return;}
c.pc=270217887u;}
static void b_101b329e(Context& c){
{if(c.r[5] != 0){c.pc=(270217908u|1u);return;}}
c.pc=270217889u;}
static void b_101b32a0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270217895u;c.pc=(269975956u|1u);return;}
c.pc=270217895u;}
static void b_101b32a6(Context& c){
{if(c.r[0] == 0){c.pc=(270217902u|1u);return;}}
c.pc=270217897u;}
static void b_101b32a8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=56u;nz(c,v);c.r[1]=v;}
{c.pc=(270217726u|1u);return;}
c.pc=270217903u;}
static void b_101b32ae(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270217726u|1u);return;}
c.pc=270217909u;}
static void b_101b32b4(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270217924u|1u);return;}}
c.pc=270217915u;}
static void b_101b32ba(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[7];c.r[2]=v;}
{c.r[14]=270217925u;c.pc=(269980032u|1u);return;}
c.pc=270217925u;}
static void b_101b32c4(Context& c){
{uint32_t v=add(c,c.r[5],~(21u),1,true);}
{if(cond(c,2)){c.pc=(270218448u|1u);return;}}
c.pc=270217931u;}
static void b_101b32ca(Context& c){
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=33u;nz(c,v);c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[2]);wr<uint32_t>(c,a+4u,c.r[3]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t a=((270217944u&~3u)+0u+520u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[2]);}
{uint32_t v=add(c,c.r[3],270217950u,0,false);c.r[3]=v;}
{uint32_t a=(c.r[3]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[2];c.r[3]=v;}
{c.r[14]=270217959u;c.pc=(270006056u|1u);return;}
c.pc=270217959u;}
static void b_101b32e6(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270218448u|1u);return;}}
c.pc=270217965u;}
static void b_101b32ec(Context& c){
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t a=(c.r[0]+0u+32u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.pc=(270218448u|1u);return;}
c.pc=270217979u;}
static void b_101b32fa(Context& c){
{if(c.r[5] != 0){c.pc=(270217994u|1u);return;}}
c.pc=270217981u;}
static void b_101b32fc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=52u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270217993u;c.pc=(270393366u|1u);return;}
c.pc=270217993u;}
static void b_101b3308(Context& c){
{c.pc=(270218072u|1u);return;}
c.pc=270217995u;}
static void b_101b330a(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270218448u|1u);return;}}
c.pc=270218005u;}
static void b_101b3314(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270218448u|1u);return;}
c.pc=270218013u;}
static void b_101b331c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270218019u;c.pc=(269975956u|1u);return;}
c.pc=270218019u;}
static void b_101b3322(Context& c){
{if(c.r[0] != 0){c.pc=(270218082u|1u);return;}}
c.pc=270218021u;}
static void b_101b3324(Context& c){
{if(c.r[5] != 0){c.pc=(270218028u|1u);return;}}
c.pc=270218023u;}
static void b_101b3326(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=52u;nz(c,v);c.r[1]=v;}
{c.pc=(270217726u|1u);return;}
c.pc=270218029u;}
static void b_101b332c(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[5]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270218448u|1u);return;}}
c.pc=270218039u;}
static void b_101b3336(Context& c){
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270218051u;c.pc=(270393366u|1u);return;}
c.pc=270218051u;}
static void b_101b3342(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270218059u;c.pc=(270217040u|1u);return;}
c.pc=270218059u;}
static void b_101b334a(Context& c){
{uint32_t a=(c.r[4]+0u+252u);c.r[0]=rd<uint32_t>(c,a+0u);}
{if(c.r[0] == 0){c.pc=(270218072u|1u);return;}}
c.pc=270218065u;}
static void b_101b3350(Context& c){
{c.r[14]=270218069u;c.pc=(270391404u|1u);return;}
c.pc=270218069u;}
static void b_101b3354(Context& c){
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270218081u;c.pc=(269975948u|1u);return;}
c.pc=270218081u;}
static void b_101b3358(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270218081u;c.pc=(269975948u|1u);return;}
c.pc=270218081u;}
static void b_101b3360(Context& c){
{c.pc=(270218448u|1u);return;}
c.pc=270218083u;}
static void b_101b3362(Context& c){
{if(c.r[5] != 0){c.pc=(270218120u|1u);return;}}
c.pc=270218085u;}
static void b_101b3364(Context& c){
{uint32_t a=(c.r[4]+0u+252u);c.r[0]=rd<uint32_t>(c,a+0u);}
{if(c.r[0] == 0){c.pc=(270218098u|1u);return;}}
c.pc=270218091u;}
static void b_101b336a(Context& c){
{c.r[14]=270218095u;c.pc=(270391404u|1u);return;}
c.pc=270218095u;}
static void b_101b336e(Context& c){
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270218111u;c.pc=(270393366u|1u);return;}
c.pc=270218111u;}
static void b_101b3372(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270218111u;c.pc=(270393366u|1u);return;}
c.pc=270218111u;}
static void b_101b337e(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270218119u;c.pc=(270217040u|1u);return;}
c.pc=270218119u;}
static void b_101b3386(Context& c){
{c.pc=(270218256u|1u);return;}
c.pc=270218121u;}
static void b_101b3388(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[7]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[7],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270218256u|1u);return;}}
c.pc=270218129u;}
static void b_101b3390(Context& c){
{uint32_t v=65284u;c.r[9]=v;}
{uint32_t v=4294967295u;c.r[8]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(89u);c.r[2]=v;}
{uint32_t v=c.r[7];c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[8]);}
{c.r[14]=270218161u;c.pc=(270015700u|1u);return;}
c.pc=270218161u;}
static void b_101b33b0(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=90u;nz(c,v);c.r[2]=v;}
{uint32_t v=~(49u);c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[7]);wr<uint32_t>(c,a+4u,c.r[9]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[8]);}
{c.r[14]=270218183u;c.pc=(270015700u|1u);return;}
c.pc=270218183u;}
static void b_101b33c6(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(19u);c.r[2]=v;}
{uint32_t v=~(119u);c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[7]);wr<uint32_t>(c,a+4u,c.r[9]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[8]);}
{c.r[14]=270218207u;c.pc=(270015700u|1u);return;}
c.pc=270218207u;}
static void b_101b33de(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(44u);c.r[2]=v;}
{uint32_t v=c.r[7];c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[7]);wr<uint32_t>(c,a+4u,c.r[9]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[8]);}
{c.r[14]=270218229u;c.pc=(270015700u|1u);return;}
c.pc=270218229u;}
static void b_101b33f4(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[7]);wr<uint32_t>(c,a+4u,c.r[9]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=60u;nz(c,v);c.r[2]=v;}
{uint32_t v=~(159u);c.r[3]=v;}
{c.r[14]=270218251u;c.pc=(270015700u|1u);return;}
c.pc=270218251u;}
static void b_101b340a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270218257u;c.pc=(270391404u|1u);return;}
c.pc=270218257u;}
static void b_101b3410(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=5u;nz(c,v);c.r[1]=v;}
{c.r[14]=270218265u;c.pc=(270697604u|1u);return;}
c.pc=270218265u;}
static void b_101b3418(Context& c){
{uint32_t v=add(c,c.r[1],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270218448u|1u);return;}}
c.pc=270218269u;}
static void b_101b341c(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=1u;c.r[8]=v;}
{c.r[14]=270218279u;c.pc=(270082278u|1u);return;}
c.pc=270218279u;}
static void b_101b3426(Context& c){
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[6];c.r[0]=v;}
{c.r[14]=270218287u;c.pc=(270082278u|1u);return;}
c.pc=270218287u;}
static void b_101b342e(Context& c){
{uint32_t v=80u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[7];c.r[0]=v;}
{c.r[14]=270218297u;c.pc=(270697604u|1u);return;}
c.pc=270218297u;}
static void b_101b3438(Context& c){
{uint32_t v=c.r[5];c.r[0]=v;}
{uint32_t v=65282u;c.r[7]=v;}
{uint32_t v=4294967295u;c.r[5]=v;}
{uint32_t v=add(c,c.r[1],~(60u),1,false);c.r[9]=v;}
{uint32_t v=180u;nz(c,v);c.r[1]=v;}
{c.r[14]=270218317u;c.pc=(270697604u|1u);return;}
c.pc=270218317u;}
static void b_101b344c(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[9];c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=add(c,0u,~(c.r[1]),1,true);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270218337u;c.pc=(270015700u|1u);return;}
c.pc=270218337u;}
static void b_101b3460(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{c.r[14]=270218343u;c.pc=(270082278u|1u);return;}
c.pc=270218343u;}
static void b_101b3466(Context& c){
{uint32_t v=c.r[0];c.r[9]=v;}
{uint32_t v=c.r[6];c.r[0]=v;}
{c.r[14]=270218351u;c.pc=(270082278u|1u);return;}
c.pc=270218351u;}
static void b_101b346e(Context& c){
{uint32_t v=40u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[10]=v;}
{uint32_t v=c.r[9];c.r[0]=v;}
{c.r[14]=270218361u;c.pc=(270697604u|1u);return;}
c.pc=270218361u;}
static void b_101b3478(Context& c){
{uint32_t v=c.r[10];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(30u),1,false);c.r[9]=v;}
{uint32_t v=220u;nz(c,v);c.r[1]=v;}
{c.r[14]=270218373u;c.pc=(270697604u|1u);return;}
c.pc=270218373u;}
static void b_101b3484(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[9];c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=add(c,0u,~(c.r[1]),1,true);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270218393u;c.pc=(270015700u|1u);return;}
c.pc=270218393u;}
static void b_101b3498(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{c.r[14]=270218399u;c.pc=(270082278u|1u);return;}
c.pc=270218399u;}
static void b_101b349e(Context& c){
{uint32_t v=c.r[0];c.r[9]=v;}
{uint32_t v=c.r[6];c.r[0]=v;}
{c.r[14]=270218407u;c.pc=(270082278u|1u);return;}
c.pc=270218407u;}
static void b_101b34a6(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[10]=v;}
{uint32_t v=c.r[9];c.r[0]=v;}
{c.r[14]=270218417u;c.pc=(270697604u|1u);return;}
c.pc=270218417u;}
static void b_101b34b0(Context& c){
{uint32_t v=c.r[10];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(70u),1,false);c.r[9]=v;}
{uint32_t v=120u;nz(c,v);c.r[1]=v;}
{c.r[14]=270218429u;c.pc=(270697604u|1u);return;}
c.pc=270218429u;}
static void b_101b34bc(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[9];c.r[2]=v;}
{uint32_t v=add(c,0u,~(c.r[1]),1,true);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270218449u;c.pc=(270015700u|1u);return;}
c.pc=270218449u;}
static void b_101b34d0(Context& c){
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.r[13]=a+8u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270218459u;}
static void b_101b34e4(Context& c){
{uint32_t a=c.r[13]-36u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[11]);wr<uint32_t>(c,a+32u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-16u;wr<uint64_t>(c,a+0u,c.d[8]);wr<uint64_t>(c,a+8u,c.d[9]);c.r[13]=a;}
{setfs(c,19,-16.0);}
{uint32_t a=((270218484u&~3u)+0u+368u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[13],~(36u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[5]=v;}
{uint32_t v=1u;c.r[8]=v;}
{uint32_t v=4294967295u;c.r[6]=v;}
{uint32_t v=c.r[0];c.r[4]=v;}
{uint32_t v=65284u;c.r[7]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=~(79u);c.r[2]=v;}
{uint32_t v=~(29u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=8u;c.r[9]=v;}
{c.r[14]=270218527u;c.pc=(270015700u|1u);return;}
c.pc=270218527u;}
static void b_101b351e(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{setfs(c,18,16.0);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=((270218550u&~3u)+0u+308u);c.r[11]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270218555u;c.pc=(270015700u|1u);return;}
c.pc=270218555u;}
static void b_101b353a(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=~(19u);c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=70u;nz(c,v);c.r[2]=v;}
{c.r[14]=270218577u;c.pc=(270015700u|1u);return;}
c.pc=270218577u;}
static void b_101b3550(Context& c){
{uint32_t a=(c.r[5]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=1107296256u;c.r[10]=v;}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,2)){uint32_t v=c.r[6];c.r[8]=v;}}
{setfs(c,17,-8.0);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270218599u;c.pc=(270082278u|1u);return;}
c.pc=270218599u;}
static void b_101b3560(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270218599u;c.pc=(270082278u|1u);return;}
c.pc=270218599u;}
static void b_101b3566(Context& c){
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270218607u;c.pc=(270082278u|1u);return;}
c.pc=270218607u;}
static void b_101b356e(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=c.r[7];c.r[0]=v;}
{c.r[14]=270218617u;c.pc=(270697604u|1u);return;}
c.pc=270218617u;}
static void b_101b3578(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[7]=v;}
{uint32_t v=1u;nz(c,v);c.r[6]=v;}
{uint32_t v=add(c,c.r[1],~(130u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[8])*(c.r[1]);c.r[2]=v;}
{uint32_t v=60u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270218637u;c.pc=(270697604u|1u);return;}
c.pc=270218637u;}
static void b_101b358c(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,19));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t v=add(c,c.r[1],~(130u),1,false);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270218671u;c.pc=(270091396u|1u);return;}
c.pc=270218671u;}
static void b_101b35ae(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270218677u;c.pc=(270082278u|1u);return;}
c.pc=270218677u;}
static void b_101b35b4(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270218687u;c.pc=(270082278u|1u);return;}
c.pc=270218687u;}
static void b_101b35be(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270218701u;c.pc=(270697604u|1u);return;}
c.pc=270218701u;}
static void b_101b35cc(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],30u,0,true);c.r[1]=v;}
{uint32_t v=(c.r[8])*(c.r[1]);c.r[2]=v;}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270218719u;c.pc=(270697604u|1u);return;}
c.pc=270218719u;}
static void b_101b35de(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t v=add(c,c.r[1],~(170u),1,false);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270218753u;c.pc=(270082284u|1u);return;}
c.pc=270218753u;}
static void b_101b3600(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270218759u;c.pc=(270082278u|1u);return;}
c.pc=270218759u;}
static void b_101b3606(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270218769u;c.pc=(270082278u|1u);return;}
c.pc=270218769u;}
static void b_101b3610(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270218783u;c.pc=(270697604u|1u);return;}
c.pc=270218783u;}
static void b_101b361e(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(50u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[8])*(c.r[1]);c.r[2]=v;}
{uint32_t v=60u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270218801u;c.pc=(270697604u|1u);return;}
c.pc=270218801u;}
static void b_101b3630(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[1],~(130u),1,false);c.r[3]=v;}
{uint32_t v=1090519040u;c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270218837u;c.pc=(270082284u|1u);return;}
c.pc=270218837u;}
static void b_101b3654(Context& c){
{uint32_t v=add(c,c.r[9],~(1u),1,true);c.r[9]=v;}
{if(cond(c,2)){c.pc=(270218592u|1u);return;}}
c.pc=270218843u;}
static void b_101b365a(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);uint32_t newpc=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;c.pc=newpc;return;}
c.pc=270218853u;}
static void b_101b366c(Context& c){
{uint32_t a=c.r[13]-28u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-8u;wr<uint64_t>(c,a+0u,c.d[8]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(28u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[3];c.r[5]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[2];c.r[6]=v;}
{c.r[14]=270218883u;c.pc=(270326600u|1u);return;}
c.pc=270218883u;}
static void b_101b3682(Context& c){
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],18432u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+40u);c.r[9]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270219022u|1u);return;}}
c.pc=270218897u;}
static void b_101b3690(Context& c){
{uint32_t v=1u;c.r[8]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[8]);}
{c.r[14]=270218913u;c.pc=(269976968u|1u);return;}
c.pc=270218913u;}
static void b_101b36a0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270218921u;c.pc=(269976986u|1u);return;}
c.pc=270218921u;}
static void b_101b36a8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270218929u;c.pc=(269975400u|1u);return;}
c.pc=270218929u;}
static void b_101b36b0(Context& c){
{uint32_t v=add(c,c.r[6],~(141u),1,true);}
{if(cond(c,2)){c.pc=(270218998u|1u);return;}}
c.pc=270218933u;}
static void b_101b36b4(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{if(cond(c,2)){c.pc=(270218962u|1u);return;}}
c.pc=270218945u;}
static void b_101b36c0(Context& c){
{c.r[14]=270218949u;c.pc=(270392110u|1u);return;}
c.pc=270218949u;}
static void b_101b36c4(Context& c){
{setsbits(c,14,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{setfs(c,16,(fs(c,16))-(fs(c,15)));}
{c.pc=(270218978u|1u);return;}
c.pc=270218963u;}
static void b_101b36d2(Context& c){
{c.r[14]=270218967u;c.pc=(270392110u|1u);return;}
c.pc=270218967u;}
static void b_101b36d6(Context& c){
{setsbits(c,14,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{setfs(c,16,(fs(c,15))+(fs(c,16)));}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=88u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270218999u;c.pc=(270393366u|1u);return;}
c.pc=270218999u;}
static void b_101b36e2(Context& c){
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=88u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270218999u;c.pc=(270393366u|1u);return;}
c.pc=270218999u;}
static void b_101b36f6(Context& c){
{uint32_t v=c.r[4];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[2]+0u+0u);uint32_t wb=c.r[2]+28u;c.r[3]=rd<uint32_t>(c,a+0u);c.r[2]=wb;}
{uint32_t v=3u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270219013u;c.pc=c.r[3];return;}
c.pc=270219013u;}
static void b_101b3704(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],shift(c,c.r[3],31,2,false),0,false);c.r[3]=v;}
{uint32_t v=shift(c,c.r[3],1u,3,true);nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+32u);c.r[8]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270219072u|1u);return;}}
c.pc=270219033u;}
static void b_101b370e(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[8]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270219072u|1u);return;}}
c.pc=270219033u;}
static void b_101b3718(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=2u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[2]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270219045u;c.pc=c.r[3];return;}
c.pc=270219045u;}
static void b_101b3724(Context& c){
{uint32_t a=(c.r[13]+0u+20u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,14)){c.pc=(270219072u|1u);return;}}
c.pc=270219051u;}
static void b_101b372a(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(c.r[2]),1,true);}
{if(cond(c,13)){c.pc=(270219072u|1u);return;}}
c.pc=270219057u;}
static void b_101b3730(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=81u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[8];c.r[2]=v;}
{c.r[14]=270219067u;c.pc=(270391848u|1u);return;}
c.pc=270219067u;}
static void b_101b373a(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270219594u|1u);return;}
c.pc=270219073u;}
static void b_101b3740(Context& c){
{uint32_t v=add(c,c.r[6],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270219242u|1u);return;}}
c.pc=270219077u;}
static void b_101b3744(Context& c){
{if(cond(c,13)){c.pc=(270219100u|1u);return;}}
c.pc=270219079u;}
static void b_101b3746(Context& c){
{uint32_t v=add(c,c.r[6],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270219184u|1u);return;}}
c.pc=270219083u;}
static void b_101b374a(Context& c){
{if(cond(c,13)){c.pc=(270219090u|1u);return;}}
c.pc=270219085u;}
static void b_101b374c(Context& c){
{uint32_t v=add(c,c.r[6],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270219134u|1u);return;}}
c.pc=270219089u;}
static void b_101b3750(Context& c){
{c.pc=(270219594u|1u);return;}
c.pc=270219091u;}
static void b_101b3752(Context& c){
{uint32_t v=add(c,c.r[6],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270219242u|1u);return;}}
c.pc=270219095u;}
static void b_101b3756(Context& c){
{uint32_t v=add(c,c.r[6],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270219242u|1u);return;}}
c.pc=270219099u;}
static void b_101b375a(Context& c){
{c.pc=(270219594u|1u);return;}
c.pc=270219101u;}
static void b_101b375c(Context& c){
{uint32_t v=add(c,c.r[6],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270219424u|1u);return;}}
c.pc=270219107u;}
static void b_101b3762(Context& c){
{if(cond(c,13)){c.pc=(270219120u|1u);return;}}
c.pc=270219109u;}
static void b_101b3764(Context& c){
{uint32_t v=add(c,c.r[6],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270219134u|1u);return;}}
c.pc=270219113u;}
static void b_101b3768(Context& c){
{uint32_t v=add(c,c.r[6],~(81u),1,true);}
{if(cond(c,1)){c.pc=(270219384u|1u);return;}}
c.pc=270219119u;}
static void b_101b376e(Context& c){
{c.pc=(270219594u|1u);return;}
c.pc=270219121u;}
static void b_101b3770(Context& c){
{uint32_t v=add(c,c.r[6],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270219424u|1u);return;}}
c.pc=270219127u;}
static void b_101b3776(Context& c){
{uint32_t v=add(c,c.r[6],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270219424u|1u);return;}}
c.pc=270219133u;}
static void b_101b377c(Context& c){
{c.pc=(270219594u|1u);return;}
c.pc=270219135u;}
static void b_101b377e(Context& c){
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270219150u|1u);return;}}
c.pc=270219141u;}
static void b_101b3784(Context& c){
{if(c.r[5] != 0){c.pc=(270219192u|1u);return;}}
c.pc=270219143u;}
static void b_101b3786(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=14u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.pc=(270219170u|1u);return;}
c.pc=270219151u;}
static void b_101b378e(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270219594u|1u);return;}}
c.pc=270219157u;}
static void b_101b3794(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270219163u;c.pc=(269975956u|1u);return;}
c.pc=270219163u;}
static void b_101b379a(Context& c){
{if(c.r[0] != 0){c.pc=(270219178u|1u);return;}}
c.pc=270219165u;}
static void b_101b379c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270219177u;c.pc=(270393366u|1u);return;}
c.pc=270219177u;}
static void b_101b37a0(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270219177u;c.pc=(270393366u|1u);return;}
c.pc=270219177u;}
static void b_101b37a2(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270219177u;c.pc=(270393366u|1u);return;}
c.pc=270219177u;}
static void b_101b37a8(Context& c){
{c.pc=(270219594u|1u);return;}
c.pc=270219179u;}
static void b_101b37aa(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=31u;nz(c,v);c.r[1]=v;}
{c.pc=(270219168u|1u);return;}
c.pc=270219185u;}
static void b_101b37b0(Context& c){
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270219242u|1u);return;}}
c.pc=270219191u;}
static void b_101b37b6(Context& c){
{c.pc=(270219140u|1u);return;}
c.pc=270219193u;}
static void b_101b37b8(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[5]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270219594u|1u);return;}}
c.pc=270219203u;}
static void b_101b37c2(Context& c){
{uint32_t v=2u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270219213u;c.pc=(269976978u|1u);return;}
c.pc=270219213u;}
static void b_101b37cc(Context& c){
{if(c.r[0] == 0){c.pc=(270219222u|1u);return;}}
c.pc=270219215u;}
static void b_101b37ce(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270219223u;c.pc=(269976968u|1u);return;}
c.pc=270219223u;}
static void b_101b37d6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270219229u;c.pc=(269977496u|1u);return;}
c.pc=270219229u;}
static void b_101b37dc(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270219416u|1u);return;}}
c.pc=270219233u;}
static void b_101b37e0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{c.r[14]=270219241u;c.pc=(269976986u|1u);return;}
c.pc=270219241u;}
static void b_101b37e8(Context& c){
{c.pc=(270219416u|1u);return;}
c.pc=270219243u;}
static void b_101b37ea(Context& c){
{uint32_t v=add(c,c.r[9],~(5u),1,true);}
{if(cond(c,2)){c.pc=(270219274u|1u);return;}}
c.pc=270219249u;}
static void b_101b37f0(Context& c){
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270219274u|1u);return;}}
c.pc=270219255u;}
static void b_101b37f6(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270219142u|1u);return;}}
c.pc=270219259u;}
static void b_101b37fa(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270219594u|1u);return;}}
c.pc=270219269u;}
static void b_101b3804(Context& c){
{uint32_t v=2u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270219594u|1u);return;}
c.pc=270219275u;}
static void b_101b380a(Context& c){
{c.r[14]=270219279u;c.pc=(270394904u|1u);return;}
c.pc=270219279u;}
static void b_101b380e(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270219287u;c.pc=(269978260u|1u);return;}
c.pc=270219287u;}
static void b_101b3816(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270219594u|1u);return;}}
c.pc=270219293u;}
static void b_101b381c(Context& c){
{uint32_t a=(c.r[4]+0u+16u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{uint32_t v=add(c,c.r[3],4294967295u,0,false);c.r[2]=v;}
{uint32_t a=(c.r[4]+0u+16u);wr<uint32_t>(c,a+0u,c.r[2]);}
{if(cond(c,13)){c.pc=(270219594u|1u);return;}}
c.pc=270219307u;}
static void b_101b382a(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[7];c.r[0]=v;}
{c.r[14]=270219315u;c.pc=(270081006u|1u);return;}
c.pc=270219315u;}
static void b_101b3832(Context& c){
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.r[14]=270219321u;c.pc=(270697604u|1u);return;}
c.pc=270219321u;}
static void b_101b3838(Context& c){
{uint32_t v=add(c,c.r[1],~(2u),1,true);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],~(3u),1,true);}
{if(cond(c,9)){c.pc=(270219338u|1u);return;}}
c.pc=270219327u;}
static void b_101b383e(Context& c){
{uint32_t a=((270219330u&~3u)+0u+276u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],270219332u,0,false);c.r[2]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t a=(c.r[3]+0u+130u);c.r[5]=uint32_t(rd<int8_t>(c,a+0u));}
{c.pc=(270219340u|1u);return;}
c.pc=270219339u;}
static void b_101b384a(Context& c){
{uint32_t v=39u;nz(c,v);c.r[5]=v;}
{uint32_t a=(c.r[4]+0u+40u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270219349u;c.pc=(269975956u|1u);return;}
c.pc=270219349u;}
static void b_101b384c(Context& c){
{uint32_t a=(c.r[4]+0u+40u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270219349u;c.pc=(269975956u|1u);return;}
c.pc=270219349u;}
static void b_101b3854(Context& c){
{if(c.r[0] == 0){c.pc=(270219356u|1u);return;}}
c.pc=270219351u;}
static void b_101b3856(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[5],1u,0,true);c.r[1]=v;}
{c.pc=(270219360u|1u);return;}
c.pc=270219357u;}
static void b_101b385c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[2];c.r[3]=v;}
{c.r[14]=270219369u;c.pc=(270393366u|1u);return;}
c.pc=270219369u;}
static void b_101b3860(Context& c){
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[2];c.r[3]=v;}
{c.r[14]=270219369u;c.pc=(270393366u|1u);return;}
c.pc=270219369u;}
static void b_101b3868(Context& c){
{uint32_t v=c.r[4];c.r[2]=v;}
{uint32_t a=(c.r[2]+0u+0u);uint32_t wb=c.r[2]+16u;c.r[3]=rd<uint32_t>(c,a+0u);c.r[2]=wb;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=37u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270219383u;c.pc=c.r[3];return;}
c.pc=270219383u;}
static void b_101b3876(Context& c){
{c.pc=(270219594u|1u);return;}
c.pc=270219385u;}
static void b_101b3878(Context& c){
{if(c.r[5] != 0){c.pc=(270219408u|1u);return;}}
c.pc=270219387u;}
static void b_101b387a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=20u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270219399u;c.pc=(270393366u|1u);return;}
c.pc=270219399u;}
static void b_101b3886(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270219407u;c.pc=(269975948u|1u);return;}
c.pc=270219407u;}
static void b_101b388e(Context& c){
{c.pc=(270219594u|1u);return;}
c.pc=270219409u;}
static void b_101b3890(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270219594u|1u);return;}}
c.pc=270219417u;}
static void b_101b3898(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.pc=(270219594u|1u);return;}
c.pc=270219425u;}
static void b_101b38a0(Context& c){
{if(c.r[5] != 0){c.pc=(270219502u|1u);return;}}
c.pc=270219427u;}
static void b_101b38a2(Context& c){
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270219439u;c.pc=(270393366u|1u);return;}
c.pc=270219439u;}
static void b_101b38ae(Context& c){
{uint32_t v=65284u;c.r[8]=v;}
{uint32_t v=4294967295u;c.r[6]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=60u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[5];c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270219467u;c.pc=(270015700u|1u);return;}
c.pc=270219467u;}
static void b_101b38ca(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=20u;nz(c,v);c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=~(41u);c.r[3]=v;}
{c.r[14]=270219487u;c.pc=(270015700u|1u);return;}
c.pc=270219487u;}
static void b_101b38de(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(79u);c.r[2]=v;}
{c.pc=(270219588u|1u);return;}
c.pc=270219503u;}
static void b_101b38ee(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270219522u|1u);return;}}
c.pc=270219509u;}
static void b_101b38f4(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270219517u;c.pc=(270218468u|1u);return;}
c.pc=270219517u;}
static void b_101b38fc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270219523u;c.pc=(270391404u|1u);return;}
c.pc=270219523u;}
static void b_101b3902(Context& c){
{uint32_t v=add(c,c.r[5],~(15u),1,true);}
{if(cond(c,2)){c.pc=(270219594u|1u);return;}}
c.pc=270219527u;}
static void b_101b3906(Context& c){
{uint32_t v=0u;nz(c,v);c.r[5]=v;}
{uint32_t v=65282u;c.r[8]=v;}
{uint32_t v=4294967295u;c.r[6]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=30u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[5];c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{c.r[14]=270219555u;c.pc=(270015700u|1u);return;}
c.pc=270219555u;}
static void b_101b3922(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=~(41u);c.r[3]=v;}
{c.r[14]=270219575u;c.pc=(270015700u|1u);return;}
c.pc=270219575u;}
static void b_101b3936(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=~(39u);c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270219595u;c.pc=(270015700u|1u);return;}
c.pc=270219595u;}
static void b_101b3944(Context& c){
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270219595u;c.pc=(270015700u|1u);return;}
c.pc=270219595u;}
static void b_101b394a(Context& c){
{uint32_t v=add(c,c.r[13],28u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.r[13]=a+8u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);uint32_t newpc=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;c.pc=newpc;return;}
c.pc=270219605u;}
static void b_101b3958(Context& c){
{uint32_t a=c.r[13]-8u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+36u);c.r[0]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270219619u;c.pc=(269745236u|1u);return;}
c.pc=270219619u;}
static void b_101b3962(Context& c){
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[3],48u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[0]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[14]=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;}
{setfs(c,15,int32_t(sbits(c,15)));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{c.pc=(270393746u|1u);return;}
c.pc=270219653u;}
static void b_101b3984(Context& c){
{uint32_t a=c.r[13]-28u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[14]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(28u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[2];c.r[5]=v;}
{uint32_t v=c.r[3];c.r[6]=v;}
{uint32_t v=c.r[0];c.r[8]=v;}
{c.r[14]=270219671u;c.pc=(270326600u|1u);return;}
c.pc=270219671u;}
static void b_101b3996(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],18432u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(5u),1,true);c.r[3]=v;}
{uint32_t v=add(c,0u,~(c.r[3]),1,true);c.r[9]=v;}
{uint32_t v=add(c,c.r[9],c.r[3],c.c,true);c.r[9]=v;}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270219854u|1u);return;}}
c.pc=270219693u;}
static void b_101b39ac(Context& c){
{uint32_t v=1u;nz(c,v);c.r[7]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[7];c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270219707u;c.pc=(270393366u|1u);return;}
c.pc=270219707u;}
static void b_101b39ba(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270219715u;c.pc=(269975768u|1u);return;}
c.pc=270219715u;}
static void b_101b39c2(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270219723u;c.pc=(269975414u|1u);return;}
c.pc=270219723u;}
static void b_101b39ca(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270219731u;c.pc=(269975422u|1u);return;}
c.pc=270219731u;}
static void b_101b39d2(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[7];c.r[1]=v;}
{c.r[14]=270219739u;c.pc=(269975962u|1u);return;}
c.pc=270219739u;}
static void b_101b39da(Context& c){
{uint32_t v=add(c,c.r[9],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270219854u|1u);return;}}
c.pc=270219745u;}
static void b_101b39e0(Context& c){
{uint32_t a=(c.r[4]+0u+276u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270219830u|1u);return;}}
c.pc=270219751u;}
static void b_101b39e6(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{if(cond(c,2)){c.pc=(270219792u|1u);return;}}
c.pc=270219757u;}
static void b_101b39ec(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270219771u;c.pc=(270408416u|1u);return;}
c.pc=270219771u;}
static void b_101b39fa(Context& c){
{c.r[14]=270219775u;c.pc=(270408736u|1u);return;}
c.pc=270219775u;}
static void b_101b39fe(Context& c){
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270219783u;c.pc=(270392110u|1u);return;}
c.pc=270219783u;}
static void b_101b3a06(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],shift(c,c.r[0],1,1,false),0,false);c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[0]);}
{c.pc=(270219830u|1u);return;}
c.pc=270219793u;}
static void b_101b3a10(Context& c){
{c.r[14]=270219797u;c.pc=(270408416u|1u);return;}
c.pc=270219797u;}
static void b_101b3a14(Context& c){
{c.r[14]=270219801u;c.pc=(270408736u|1u);return;}
c.pc=270219801u;}
static void b_101b3a18(Context& c){
{setsbits(c,14,c.r[0]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.r[14]=270219823u;c.pc=(270392110u|1u);return;}
c.pc=270219823u;}
static void b_101b3a2e(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=shift(c,c.r[0],1u,1,true);nz(c,v);c.r[0]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[0]),1,true);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270219837u;c.pc=(270392138u|1u);return;}
c.pc=270219837u;}
static void b_101b3a36(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270219837u;c.pc=(270392138u|1u);return;}
c.pc=270219837u;}
static void b_101b3a3c(Context& c){
{uint32_t v=add(c,c.r[0],60u,0,true);c.r[0]=v;}
{setsbits(c,14,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=add(c,c.r[5],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270220522u|1u);return;}}
c.pc=270219861u;}
static void b_101b3a4e(Context& c){
{uint32_t v=add(c,c.r[5],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270220522u|1u);return;}}
c.pc=270219861u;}
static void b_101b3a54(Context& c){
{uint32_t v=add(c,c.r[5],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270220522u|1u);return;}}
c.pc=270219867u;}
static void b_101b3a5a(Context& c){
{uint32_t v=add(c,c.r[5],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270220522u|1u);return;}}
c.pc=270219873u;}
static void b_101b3a60(Context& c){
{uint32_t v=add(c,c.r[5],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270220576u|1u);return;}}
c.pc=270219879u;}
static void b_101b3a66(Context& c){
{uint32_t a=(c.r[4]+0u+52u);c.r[7]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[7],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270219984u|1u);return;}}
c.pc=270219885u;}
static void b_101b3a6c(Context& c){
{c.r[14]=270219889u;c.pc=(270408416u|1u);return;}
c.pc=270219889u;}
static void b_101b3a70(Context& c){
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=c.r[7];c.r[2]=v;}
{c.r[1]=sbits(c,15);}
{c.r[14]=270219907u;c.pc=(270408818u|1u);return;}
c.pc=270219907u;}
static void b_101b3a82(Context& c){
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[3]=sbits(c,15);}
{uint32_t v=add(c,c.r[0],~(260u),1,false);c.r[0]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[0]),1,true);}
{if(cond(c,11)){c.pc=(270219942u|1u);return;}}
c.pc=270219927u;}
static void b_101b3a96(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=((270219932u&~3u)+0u+664u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270219941u;c.pc=(270392910u|1u);return;}
c.pc=270219941u;}
static void b_101b3aa4(Context& c){
{c.pc=(270220588u|1u);return;}
c.pc=270219943u;}
static void b_101b3aa6(Context& c){
{uint32_t v=add(c,c.r[5],~(70u),1,true);}
{uint32_t v=2u;c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=10u;c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{if(cond(c,2)){c.pc=(270220588u|1u);return;}}
c.pc=270219963u;}
static void b_101b3aba(Context& c){
{uint32_t v=3u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[7];c.r[2]=v;}
{c.r[14]=270219977u;c.pc=(270391848u|1u);return;}
c.pc=270219977u;}
static void b_101b3ac8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270219983u;c.pc=(270393272u|1u);return;}
c.pc=270219983u;}
static void b_101b3ace(Context& c){
{c.pc=(270220588u|1u);return;}
c.pc=270219985u;}
static void b_101b3ad0(Context& c){
{uint32_t v=add(c,c.r[7],~(2u),1,true);}
{if(cond(c,2)){c.pc=(270220066u|1u);return;}}
c.pc=270219989u;}
static void b_101b3ad4(Context& c){
{uint32_t v=3u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270219999u;c.pc=(269977496u|1u);return;}
c.pc=270219999u;}
static void b_101b3ade(Context& c){
{if(c.r[0] == 0){c.pc=(270220008u|1u);return;}}
c.pc=270220001u;}
static void b_101b3ae0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{c.r[14]=270220009u;c.pc=(269976986u|1u);return;}
c.pc=270220009u;}
static void b_101b3ae8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270220015u;c.pc=(269976978u|1u);return;}
c.pc=270220015u;}
static void b_101b3aee(Context& c){
{if(c.r[0] == 0){c.pc=(270220024u|1u);return;}}
c.pc=270220017u;}
static void b_101b3af0(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{c.r[14]=270220025u;c.pc=(269976968u|1u);return;}
c.pc=270220025u;}
static void b_101b3af8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270220031u;c.pc=(269975408u|1u);return;}
c.pc=270220031u;}
static void b_101b3afe(Context& c){
{if(c.r[0] == 0){c.pc=(270220040u|1u);return;}}
c.pc=270220033u;}
static void b_101b3b00(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[1]=v;}
{c.r[14]=270220041u;c.pc=(269975400u|1u);return;}
c.pc=270220041u;}
static void b_101b3b08(Context& c){
{uint32_t v=add(c,c.r[5],~(20u),1,true);}
{uint32_t v=260u;c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=10u;c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{if(cond(c,2)){c.pc=(270220588u|1u);return;}}
c.pc=270220061u;}
static void b_101b3b1c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.pc=(270220288u|1u);return;}
c.pc=270220067u;}
static void b_101b3b22(Context& c){
{uint32_t v=add(c,c.r[5],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270220444u|1u);return;}}
c.pc=270220073u;}
static void b_101b3b28(Context& c){
{if(cond(c,13)){c.pc=(270220106u|1u);return;}}
c.pc=270220075u;}
static void b_101b3b2a(Context& c){
{uint32_t v=add(c,c.r[5],~(21u),1,true);}
{if(cond(c,1)){c.pc=(270220392u|1u);return;}}
c.pc=270220081u;}
static void b_101b3b30(Context& c){
{if(cond(c,13)){c.pc=(270220092u|1u);return;}}
c.pc=270220083u;}
static void b_101b3b32(Context& c){
{uint32_t v=add(c,c.r[5],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270220142u|1u);return;}}
c.pc=270220087u;}
static void b_101b3b36(Context& c){
{uint32_t v=add(c,c.r[5],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270220318u|1u);return;}}
c.pc=270220091u;}
static void b_101b3b3a(Context& c){
{c.pc=(270220588u|1u);return;}
c.pc=270220093u;}
static void b_101b3b3c(Context& c){
{uint32_t v=add(c,c.r[5],~(22u),1,true);}
{if(cond(c,1)){c.pc=(270220438u|1u);return;}}
c.pc=270220099u;}
static void b_101b3b42(Context& c){
{uint32_t v=add(c,c.r[5],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270220444u|1u);return;}}
c.pc=270220105u;}
static void b_101b3b48(Context& c){
{c.pc=(270220588u|1u);return;}
c.pc=270220107u;}
static void b_101b3b4a(Context& c){
{uint32_t v=add(c,c.r[5],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270220522u|1u);return;}}
c.pc=270220113u;}
static void b_101b3b50(Context& c){
{if(cond(c,13)){c.pc=(270220128u|1u);return;}}
c.pc=270220115u;}
static void b_101b3b52(Context& c){
{uint32_t v=add(c,c.r[5],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270220474u|1u);return;}}
c.pc=270220121u;}
static void b_101b3b58(Context& c){
{uint32_t v=add(c,c.r[5],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270220502u|1u);return;}}
c.pc=270220127u;}
static void b_101b3b5e(Context& c){
{c.pc=(270220588u|1u);return;}
c.pc=270220129u;}
static void b_101b3b60(Context& c){
{uint32_t v=add(c,c.r[5],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270220522u|1u);return;}}
c.pc=270220135u;}
static void b_101b3b66(Context& c){
{uint32_t v=add(c,c.r[5],~(120u),1,true);}
{if(cond(c,2)){c.pc=(270220588u|1u);return;}}
c.pc=270220141u;}
static void b_101b3b6c(Context& c){
{c.pc=(270220522u|1u);return;}
c.pc=270220143u;}
static void b_101b3b6e(Context& c){
{uint32_t v=add(c,c.r[6],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270220308u|1u);return;}}
c.pc=270220147u;}
static void b_101b3b72(Context& c){
{c.r[14]=270220151u;c.pc=(270394904u|1u);return;}
c.pc=270220151u;}
static void b_101b3b76(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=(c.r[3])^(1u);c.r[3]=v;}
{uint32_t v=add(c,c.r[3],14u,0,true);c.r[3]=v;}
{uint32_t a=(c.r[0]+shift(c,c.r[3],2,1,false)+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270220296u|1u);return;}}
c.pc=270220167u;}
static void b_101b3b86(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[3]+0u+148u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{fcmp(c,fs(c,14),fs(c,15));}
{uint32_t v=add(c,c.r[2],~(90u),1,true);}
{if(cond(c,2)){c.pc=(270220196u|1u);return;}}
c.pc=270220185u;}
static void b_101b3b98(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,14)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{c.pc=(270220206u|1u);return;}
c.pc=270220197u;}
static void b_101b3ba4(Context& c){
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,6)){uint32_t v=0u;c.r[3]=v;}}
{if(cond(c,5)){uint32_t v=1u;c.r[3]=v;}}
{if(c.r[3] == 0){c.pc=(270220296u|1u);return;}}
c.pc=270220209u;}
static void b_101b3bae(Context& c){
{if(c.r[3] == 0){c.pc=(270220296u|1u);return;}}
c.pc=270220209u;}
static void b_101b3bb0(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270220221u;c.pc=(270393366u|1u);return;}
c.pc=270220221u;}
static void b_101b3bbc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270220227u;c.pc=(270392138u|1u);return;}
c.pc=270220227u;}
static void b_101b3bc2(Context& c){
{uint32_t v=25u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[0],shift(c,c.r[0],31,2,false),0,false);c.r[0]=v;}
{uint32_t v=shift(c,c.r[0],1u,3,true);nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,0u,~(c.r[1]),1,true);c.r[1]=v;}
{setsbits(c,14,c.r[1]);}
{setfs(c,14,int32_t(sbits(c,14)));}
{c.r[1]=sbits(c,14);}
{c.r[14]=270220255u;c.pc=(270393090u|1u);return;}
c.pc=270220255u;}
static void b_101b3bde(Context& c){
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270220269u;c.pc=(269976968u|1u);return;}
c.pc=270220269u;}
static void b_101b3bec(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270220277u;c.pc=(269976986u|1u);return;}
c.pc=270220277u;}
static void b_101b3bf4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[1]=v;}
{c.r[14]=270220285u;c.pc=(269975400u|1u);return;}
c.pc=270220285u;}
static void b_101b3bfc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=21u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[14]=270220295u;c.pc=(270391848u|1u);return;}
c.pc=270220295u;}
static void b_101b3c00(Context& c){
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[14]=270220295u;c.pc=(270391848u|1u);return;}
c.pc=270220295u;}
static void b_101b3c02(Context& c){
{c.r[14]=270220295u;c.pc=(270391848u|1u);return;}
c.pc=270220295u;}
static void b_101b3c06(Context& c){
{c.pc=(270220588u|1u);return;}
c.pc=270220297u;}
static void b_101b3c08(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270220309u;c.pc=(270393366u|1u);return;}
c.pc=270220309u;}
static void b_101b3c0e(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270220309u;c.pc=(270393366u|1u);return;}
c.pc=270220309u;}
static void b_101b3c14(Context& c){
{uint32_t v=c.r[8];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270220317u;c.pc=(270219608u|1u);return;}
c.pc=270220317u;}
static void b_101b3c1c(Context& c){
{c.pc=(270220588u|1u);return;}
c.pc=270220319u;}
static void b_101b3c1e(Context& c){
{uint32_t v=add(c,c.r[6],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270220308u|1u);return;}}
c.pc=270220323u;}
static void b_101b3c22(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.r[14]=270220335u;c.pc=(270393366u|1u);return;}
c.pc=270220335u;}
static void b_101b3c2e(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[9],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270220588u|1u);return;}}
c.pc=270220347u;}
static void b_101b3c3a(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=5u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270220359u;c.pc=c.r[3];return;}
c.pc=270220359u;}
static void b_101b3c46(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+20u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{uint32_t v=0u;c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{}
{if(cond(c,2)){setfs(c,15,-(fs(c,15)));}}
{c.r[1]=sbits(c,15);}
{c.r[14]=270220391u;c.pc=(270392848u|1u);return;}
c.pc=270220391u;}
static void b_101b3c66(Context& c){
{c.pc=(270220308u|1u);return;}
c.pc=270220393u;}
static void b_101b3c68(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270220399u;c.pc=(269975064u|1u);return;}
c.pc=270220399u;}
static void b_101b3c6e(Context& c){
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270220588u|1u);return;}}
c.pc=270220403u;}
static void b_101b3c72(Context& c){
{c.r[14]=270220407u;c.pc=(270394904u|1u);return;}
c.pc=270220407u;}
static void b_101b3c76(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270220415u;c.pc=(270398272u|1u);return;}
c.pc=270220415u;}
static void b_101b3c7e(Context& c){
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,1)){c.pc=(270220588u|1u);return;}}
c.pc=270220421u;}
static void b_101b3c84(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+140u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[14]=270220433u;c.pc=(270393014u|1u);return;}
c.pc=270220433u;}
static void b_101b3c90(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=22u;nz(c,v);c.r[1]=v;}
{c.pc=(270220288u|1u);return;}
c.pc=270220439u;}
static void b_101b3c96(Context& c){
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.pc=(270220516u|1u);return;}
c.pc=270220445u;}
static void b_101b3c9c(Context& c){
{if(c.r[6] != 0){c.pc=(270220454u|1u);return;}}
c.pc=270220447u;}
static void b_101b3c9e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.pc=(270220302u|1u);return;}
c.pc=270220455u;}
static void b_101b3ca6(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270220308u|1u);return;}}
c.pc=270220463u;}
static void b_101b3cae(Context& c){
{uint32_t v=c.r[8];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270220473u;c.pc=(269980032u|1u);return;}
c.pc=270220473u;}
static void b_101b3cb8(Context& c){
{c.pc=(270220308u|1u);return;}
c.pc=270220475u;}
static void b_101b3cba(Context& c){
{if(c.r[6] != 0){c.pc=(270220482u|1u);return;}}
c.pc=270220477u;}
static void b_101b3cbc(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270220528u|1u);return;}
c.pc=270220483u;}
static void b_101b3cc2(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270220588u|1u);return;}}
c.pc=270220491u;}
static void b_101b3cca(Context& c){
{uint32_t v=c.r[8];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270220501u;c.pc=(269980032u|1u);return;}
c.pc=270220501u;}
static void b_101b3cd4(Context& c){
{c.pc=(270220588u|1u);return;}
c.pc=270220503u;}
static void b_101b3cd6(Context& c){
{if(c.r[6] != 0){c.pc=(270220510u|1u);return;}}
c.pc=270220505u;}
static void b_101b3cd8(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270220528u|1u);return;}
c.pc=270220511u;}
static void b_101b3cde(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{if(c.r[2] != 0){c.pc=(270220588u|1u);return;}}
c.pc=270220517u;}
static void b_101b3ce4(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270220290u|1u);return;}
c.pc=270220523u;}
static void b_101b3cea(Context& c){
{if(c.r[6] != 0){c.pc=(270220538u|1u);return;}}
c.pc=270220525u;}
static void b_101b3cec(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270220537u;c.pc=(270393366u|1u);return;}
c.pc=270220537u;}
static void b_101b3cf0(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270220537u;c.pc=(270393366u|1u);return;}
c.pc=270220537u;}
static void b_101b3cf8(Context& c){
{c.pc=(270220588u|1u);return;}
c.pc=270220539u;}
static void b_101b3cfa(Context& c){
{uint32_t v=c.r[8];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270220547u;c.pc=(270118736u|1u);return;}
c.pc=270220547u;}
static void b_101b3d02(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{if(c.r[0] != 0){c.pc=(270220588u|1u);return;}}
c.pc=270220551u;}
static void b_101b3d06(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t v=65303u;c.r[3]=v;}
{uint32_t v=c.r[8];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[2];c.r[3]=v;}
{c.r[14]=270220575u;c.pc=(270015700u|1u);return;}
c.pc=270220575u;}
static void b_101b3d1e(Context& c){
{c.pc=(270220582u|1u);return;}
c.pc=270220577u;}
static void b_101b3d20(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270220588u|1u);return;}}
c.pc=270220583u;}
static void b_101b3d26(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270220589u;c.pc=(270391404u|1u);return;}
c.pc=270220589u;}
static void b_101b3d2c(Context& c){
{uint32_t v=add(c,c.r[13],28u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);uint32_t newpc=rd<uint32_t>(c,a+24u);c.r[13]=a+28u;c.pc=newpc;return;}
c.pc=270220595u;}
static void b_101b3d38(Context& c){
{uint32_t a=c.r[13]-16u;wr<uint32_t>(c,a+0u,c.r[0]);wr<uint32_t>(c,a+4u,c.r[1]);wr<uint32_t>(c,a+8u,c.r[4]);wr<uint32_t>(c,a+12u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{c.r[14]=270220609u;c.pc=(270394904u|1u);return;}
c.pc=270220609u;}
static void b_101b3d40(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270220617u;c.pc=(269978260u|1u);return;}
c.pc=270220617u;}
static void b_101b3d48(Context& c){
{if(c.r[0] != 0){c.pc=(270220712u|1u);return;}}
c.pc=270220619u;}
static void b_101b3d4a(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=38u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[13];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270220631u;c.pc=c.r[3];return;}
c.pc=270220631u;}
static void b_101b3d56(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=39u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],4u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270220643u;c.pc=c.r[3];return;}
c.pc=270220643u;}
static void b_101b3d62(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=259u;c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+4u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+277u);c.r[3]=rd<uint8_t>(c,a+0u);}
{c.r[14]=270220659u;c.pc=(270393824u|1u);return;}
c.pc=270220659u;}
static void b_101b3d72(Context& c){
{if(c.r[0] == 0){c.pc=(270220712u|1u);return;}}
c.pc=270220661u;}
static void b_101b3d74(Context& c){
{uint32_t a=(c.r[4]+0u+98u);c.r[3]=rd<uint16_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270220712u|1u);return;}}
c.pc=270220673u;}
static void b_101b3d80(Context& c){
{uint32_t a=(c.r[0]+0u+140u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=((270220680u&~3u)+0u+36u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,(fs(c,14))-(fs(c,15)));}
{uint32_t a=(c.r[0]+0u+144u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[0]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[0]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=((270220700u&~3u)+0u+20u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,(fs(c,14))+(fs(c,15)));}
{uint32_t a=(c.r[0]+0u+152u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[0]+0u+144u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=add(c,c.r[13],8u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270220717u;}
static void b_101b3da8(Context& c){
{uint32_t v=add(c,c.r[13],8u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270220717u;}
static void b_101b3db4(Context& c){
{uint32_t a=c.r[13]-32u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[14]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(24u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[2];c.r[5]=v;}
{uint32_t v=c.r[3];c.r[6]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{c.r[14]=270220743u;c.pc=(270326600u|1u);return;}
c.pc=270220743u;}
static void b_101b3dc6(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],18432u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(5u),1,true);c.r[1]=v;}
{uint32_t v=add(c,0u,~(c.r[1]),1,true);c.r[8]=v;}
{uint32_t v=add(c,c.r[8],c.r[1],c.c,true);c.r[8]=v;}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270220994u|1u);return;}}
c.pc=270220765u;}
static void b_101b3ddc(Context& c){
{uint32_t v=1u;c.r[9]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[9]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[9];c.r[3]=v;}
{c.r[14]=270220783u;c.pc=(270393366u|1u);return;}
c.pc=270220783u;}
static void b_101b3dee(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[9];c.r[1]=v;}
{c.r[14]=270220791u;c.pc=(269975962u|1u);return;}
c.pc=270220791u;}
static void b_101b3df6(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270220994u|1u);return;}}
c.pc=270220797u;}
static void b_101b3dfc(Context& c){
{uint32_t a=(c.r[4]+0u+276u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270220882u|1u);return;}}
c.pc=270220803u;}
static void b_101b3e02(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{if(cond(c,2)){c.pc=(270220844u|1u);return;}}
c.pc=270220809u;}
static void b_101b3e08(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270220823u;c.pc=(270408416u|1u);return;}
c.pc=270220823u;}
static void b_101b3e16(Context& c){
{c.r[14]=270220827u;c.pc=(270408736u|1u);return;}
c.pc=270220827u;}
static void b_101b3e1a(Context& c){
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[0]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270220835u;c.pc=(270392110u|1u);return;}
c.pc=270220835u;}
static void b_101b3e22(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],shift(c,c.r[0],1,1,false),0,false);c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[0]);}
{c.pc=(270220882u|1u);return;}
c.pc=270220845u;}
static void b_101b3e2c(Context& c){
{c.r[14]=270220849u;c.pc=(270408416u|1u);return;}
c.pc=270220849u;}
static void b_101b3e30(Context& c){
{c.r[14]=270220853u;c.pc=(270408736u|1u);return;}
c.pc=270220853u;}
static void b_101b3e34(Context& c){
{setsbits(c,14,c.r[0]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.r[14]=270220875u;c.pc=(270392110u|1u);return;}
c.pc=270220875u;}
static void b_101b3e4a(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=shift(c,c.r[0],1u,1,true);nz(c,v);c.r[0]=v;}
{uint32_t v=add(c,c.r[3],~(c.r[0]),1,true);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=90u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270220891u;c.pc=(270408416u|1u);return;}
c.pc=270220891u;}
static void b_101b3e52(Context& c){
{uint32_t v=90u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270220891u;c.pc=(270408416u|1u);return;}
c.pc=270220891u;}
static void b_101b3e5a(Context& c){
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[1]=sbits(c,15);}
{uint32_t v=c.r[0];c.r[10]=v;}
{c.r[14]=270220911u;c.pc=(270408818u|1u);return;}
c.pc=270220911u;}
static void b_101b3e6e(Context& c){
{uint32_t v=c.r[0];c.r[9]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270220919u;c.pc=(269977976u|1u);return;}
c.pc=270220919u;}
static void b_101b3e76(Context& c){
{if(c.r[0] == 0){c.pc=(270220972u|1u);return;}}
c.pc=270220921u;}
static void b_101b3e78(Context& c){
{c.r[14]=270220925u;c.pc=(270394904u|1u);return;}
c.pc=270220925u;}
static void b_101b3e7c(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270220933u;c.pc=(270398272u|1u);return;}
c.pc=270220933u;}
static void b_101b3e84(Context& c){
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[0]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=c.r[10];c.r[0]=v;}
{c.r[9]=sbits(c,15);}
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[1]=sbits(c,15);}
{c.r[14]=270220965u;c.pc=(270408818u|1u);return;}
c.pc=270220965u;}
static void b_101b3ea4(Context& c){
{uint32_t v=c.r[9];c.r[1]=v;}
{c.r[14]=270220971u;c.pc=(269745118u|1u);return;}
c.pc=270220971u;}
static void b_101b3eaa(Context& c){
{uint32_t v=c.r[0];c.r[9]=v;}
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[9],~(c.r[3]),1,false);c.r[3]=v;}
{setsbits(c,14,c.r[3]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=add(c,c.r[5],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270221350u|1u);return;}}
c.pc=270221001u;}
static void b_101b3eac(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[9],~(c.r[3]),1,false);c.r[3]=v;}
{setsbits(c,14,c.r[3]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=add(c,c.r[5],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270221350u|1u);return;}}
c.pc=270221001u;}
static void b_101b3ec2(Context& c){
{uint32_t v=add(c,c.r[5],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270221350u|1u);return;}}
c.pc=270221001u;}
static void b_101b3ec8(Context& c){
{if(cond(c,13)){c.pc=(270221028u|1u);return;}}
c.pc=270221003u;}
static void b_101b3eca(Context& c){
{uint32_t v=add(c,c.r[5],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270221082u|1u);return;}}
c.pc=270221007u;}
static void b_101b3ece(Context& c){
{if(cond(c,13)){c.pc=(270221014u|1u);return;}}
c.pc=270221009u;}
static void b_101b3ed0(Context& c){
{uint32_t v=add(c,c.r[5],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270221070u|1u);return;}}
c.pc=270221013u;}
static void b_101b3ed4(Context& c){
{c.pc=(270221462u|1u);return;}
c.pc=270221015u;}
static void b_101b3ed6(Context& c){
{uint32_t v=add(c,c.r[5],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270221334u|1u);return;}}
c.pc=270221021u;}
static void b_101b3edc(Context& c){
{uint32_t v=add(c,c.r[5],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270221334u|1u);return;}}
c.pc=270221027u;}
static void b_101b3ee2(Context& c){
{c.pc=(270221462u|1u);return;}
c.pc=270221029u;}
static void b_101b3ee4(Context& c){
{uint32_t v=add(c,c.r[5],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270221412u|1u);return;}}
c.pc=270221035u;}
static void b_101b3eea(Context& c){
{if(cond(c,13)){c.pc=(270221050u|1u);return;}}
c.pc=270221037u;}
static void b_101b3eec(Context& c){
{uint32_t v=add(c,c.r[5],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270221392u|1u);return;}}
c.pc=270221043u;}
static void b_101b3ef2(Context& c){
{uint32_t v=add(c,c.r[5],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270221412u|1u);return;}}
c.pc=270221049u;}
static void b_101b3ef8(Context& c){
{c.pc=(270221462u|1u);return;}
c.pc=270221051u;}
static void b_101b3efa(Context& c){
{uint32_t v=add(c,c.r[5],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270221412u|1u);return;}}
c.pc=270221057u;}
static void b_101b3f00(Context& c){
{uint32_t v=add(c,c.r[5],~(140u),1,true);}
{if(cond(c,2)){c.pc=(270221462u|1u);return;}}
c.pc=270221063u;}
static void b_101b3f06(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270221069u;c.pc=(270391404u|1u);return;}
c.pc=270221069u;}
static void b_101b3f0c(Context& c){
{c.pc=(270221462u|1u);return;}
c.pc=270221071u;}
static void b_101b3f0e(Context& c){
{uint32_t v=add(c,c.r[6],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270221462u|1u);return;}}
c.pc=270221077u;}
static void b_101b3f14(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270221340u|1u);return;}
c.pc=270221083u;}
static void b_101b3f1a(Context& c){
{if(c.r[6] != 0){c.pc=(270221156u|1u);return;}}
c.pc=270221085u;}
static void b_101b3f1c(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{c.r[14]=270221097u;c.pc=(270393366u|1u);return;}
c.pc=270221097u;}
static void b_101b3f28(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270221462u|1u);return;}}
c.pc=270221111u;}
static void b_101b3f36(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=5u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[3]+0u+100u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270221123u;c.pc=c.r[3];return;}
c.pc=270221123u;}
static void b_101b3f42(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+20u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{uint32_t v=0u;c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{}
{if(cond(c,2)){setfs(c,15,-(fs(c,15)));}}
{c.r[1]=sbits(c,15);}
{c.r[14]=270221155u;c.pc=(270392848u|1u);return;}
c.pc=270221155u;}
static void b_101b3f62(Context& c){
{c.pc=(270221164u|1u);return;}
c.pc=270221157u;}
static void b_101b3f64(Context& c){
{uint32_t v=add(c,c.r[8],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270221462u|1u);return;}}
c.pc=270221165u;}
static void b_101b3f6c(Context& c){
{c.r[14]=270221169u;c.pc=(270408416u|1u);return;}
c.pc=270221169u;}
static void b_101b3f70(Context& c){
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[1]=sbits(c,15);}
{uint32_t v=c.r[0];c.r[6]=v;}
{c.r[14]=270221189u;c.pc=(270408818u|1u);return;}
c.pc=270221189u;}
static void b_101b3f84(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270221197u;c.pc=(269977976u|1u);return;}
c.pc=270221197u;}
static void b_101b3f8c(Context& c){
{if(c.r[0] == 0){c.pc=(270221250u|1u);return;}}
c.pc=270221199u;}
static void b_101b3f8e(Context& c){
{c.r[14]=270221203u;c.pc=(270394904u|1u);return;}
c.pc=270221203u;}
static void b_101b3f92(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270221211u;c.pc=(270398272u|1u);return;}
c.pc=270221211u;}
static void b_101b3f9a(Context& c){
{uint32_t a=(c.r[4]+0u+148u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[1]=sbits(c,15);}
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=c.r[6];c.r[0]=v;}
{c.r[14]=270221233u;c.pc=(270408818u|1u);return;}
c.pc=270221233u;}
static void b_101b3fb0(Context& c){
{uint32_t a=(c.r[5]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[1]=sbits(c,15);}
{c.r[14]=270221249u;c.pc=(269745118u|1u);return;}
c.pc=270221249u;}
static void b_101b3fc0(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[5],~(c.r[3]),1,true);c.r[5]=v;}
{setsbits(c,14,c.r[5]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{setfs(c,12,(fs(c,15))-(fs(c,13)));}
{setfs(c,14,8.0);}
{setfs(c,12,std::fabs(fs(c,12)));}
{fcmp(c,fs(c,12),fs(c,14));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,14)){c.pc=(270221324u|1u);return;}}
c.pc=270221289u;}
static void b_101b3fc2(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,13,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[5],~(c.r[3]),1,true);c.r[5]=v;}
{setsbits(c,14,c.r[5]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{setfs(c,12,(fs(c,15))-(fs(c,13)));}
{setfs(c,14,8.0);}
{setfs(c,12,std::fabs(fs(c,12)));}
{fcmp(c,fs(c,12),fs(c,14));}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{if(cond(c,14)){c.pc=(270221324u|1u);return;}}
c.pc=270221289u;}
static void b_101b3fe8(Context& c){
{fcmp(c,fs(c,15),fs(c,13));}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{setfs(c,15,-8.0);}
{c.n=c.fpscr>>31;c.z=(c.fpscr>>30)&1;c.c=(c.fpscr>>29)&1;c.v=(c.fpscr>>28)&1;}
{}
{if(cond(c,14)){c.r[1]=sbits(c,15);}}
{if(cond(c,13)){c.r[1]=sbits(c,14);}}
{c.r[14]=270221323u;c.pc=(270392910u|1u);return;}
c.pc=270221323u;}
static void b_101b400a(Context& c){
{c.pc=(270221462u|1u);return;}
c.pc=270221325u;}
static void b_101b400c(Context& c){
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.pc=(270221462u|1u);return;}
c.pc=270221335u;}
static void b_101b4016(Context& c){
{if(c.r[6] != 0){c.pc=(270221374u|1u);return;}}
c.pc=270221337u;}
static void b_101b4018(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270221349u;c.pc=(270393366u|1u);return;}
c.pc=270221349u;}
static void b_101b401c(Context& c){
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270221349u;c.pc=(270393366u|1u);return;}
c.pc=270221349u;}
static void b_101b4024(Context& c){
{c.pc=(270221462u|1u);return;}
c.pc=270221351u;}
static void b_101b4026(Context& c){
{if(c.r[6] != 0){c.pc=(270221374u|1u);return;}}
c.pc=270221353u;}
static void b_101b4028(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270221365u;c.pc=(270393366u|1u);return;}
c.pc=270221365u;}
static void b_101b4034(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270221373u;c.pc=(270220600u|1u);return;}
c.pc=270221373u;}
static void b_101b403c(Context& c){
{c.pc=(270221462u|1u);return;}
c.pc=270221375u;}
static void b_101b403e(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270221462u|1u);return;}}
c.pc=270221381u;}
static void b_101b4044(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270221391u;c.pc=(269980032u|1u);return;}
c.pc=270221391u;}
static void b_101b404e(Context& c){
{c.pc=(270221462u|1u);return;}
c.pc=270221393u;}
static void b_101b4050(Context& c){
{if(c.r[6] != 0){c.pc=(270221400u|1u);return;}}
c.pc=270221395u;}
static void b_101b4052(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270221340u|1u);return;}
c.pc=270221401u;}
static void b_101b4058(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{if(c.r[2] != 0){c.pc=(270221462u|1u);return;}}
c.pc=270221407u;}
static void b_101b405e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270221458u|1u);return;}
c.pc=270221413u;}
static void b_101b4064(Context& c){
{uint32_t v=0u;nz(c,v);c.r[5]=v;}
{uint32_t v=21u;nz(c,v);c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270221427u;c.pc=(270393366u|1u);return;}
c.pc=270221427u;}
static void b_101b4072(Context& c){
{uint32_t v=65284u;c.r[3]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270221453u;c.pc=(270015700u|1u);return;}
c.pc=270221453u;}
static void b_101b408c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=140u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270221463u;c.pc=(270391848u|1u);return;}
c.pc=270221463u;}
static void b_101b4092(Context& c){
{c.r[14]=270221463u;c.pc=(270391848u|1u);return;}
c.pc=270221463u;}
static void b_101b4096(Context& c){
{uint32_t v=add(c,c.r[13],24u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);uint32_t newpc=rd<uint32_t>(c,a+28u);c.r[13]=a+32u;c.pc=newpc;return;}
c.pc=270221469u;}
static void b_101b409c(Context& c){
{uint32_t a=c.r[13]-32u;wr<uint32_t>(c,a+0u,c.r[0]);wr<uint32_t>(c,a+4u,c.r[1]);wr<uint32_t>(c,a+8u,c.r[2]);wr<uint32_t>(c,a+12u,c.r[3]);wr<uint32_t>(c,a+16u,c.r[4]);wr<uint32_t>(c,a+20u,c.r[5]);wr<uint32_t>(c,a+24u,c.r[6]);wr<uint32_t>(c,a+28u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{c.r[14]=270221477u;c.pc=(270394904u|1u);return;}
c.pc=270221477u;}
static void b_101b40a4(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{c.r[14]=270221485u;c.pc=(269978260u|1u);return;}
c.pc=270221485u;}
static void b_101b40ac(Context& c){
{uint32_t v=c.r[0];c.r[5]=v;}
{uint32_t v=add(c,c.r[0],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270221576u|1u);return;}}
c.pc=270221491u;}
static void b_101b40b2(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=38u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],8u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270221503u;c.pc=c.r[3];return;}
c.pc=270221503u;}
static void b_101b40be(Context& c){
{uint32_t a=(c.r[4]+0u+0u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=39u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],12u,0,false);c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[3]+0u+96u);c.r[3]=rd<uint32_t>(c,a+0u);}
{c.r[14]=270221515u;c.pc=c.r[3];return;}
c.pc=270221515u;}
static void b_101b40ca(Context& c){
{uint32_t a=(c.r[4]+0u+277u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=258u;c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+12u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270221537u;c.pc=(270393892u|1u);return;}
c.pc=270221537u;}
static void b_101b40e0(Context& c){
{uint32_t v=c.r[0];c.r[6]=v;}
{if(c.r[0] == 0){c.pc=(270221576u|1u);return;}}
c.pc=270221541u;}
static void b_101b40e4(Context& c){
{uint32_t a=(c.r[4]+0u+252u);wr<uint32_t>(c,a+0u,c.r[0]);}
{c.r[14]=270221549u;c.pc=(270394904u|1u);return;}
c.pc=270221549u;}
static void b_101b40ec(Context& c){
{uint32_t a=(c.r[4]+0u+112u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[5];c.r[2]=v;}
{c.r[14]=270221557u;c.pc=(270398272u|1u);return;}
c.pc=270221557u;}
static void b_101b40f4(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t a=(c.r[0]+0u+776u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{}
{if(cond(c,14)){uint32_t v=100u;c.r[1]=v;}}
{if(cond(c,13)){uint32_t v=81u;c.r[1]=v;}}
{c.r[14]=270221577u;c.pc=(270391848u|1u);return;}
c.pc=270221577u;}
static void b_101b4108(Context& c){
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);uint32_t newpc=rd<uint32_t>(c,a+12u);c.r[13]=a+16u;c.pc=newpc;return;}
c.pc=270221581u;}
static void b_101b410c(Context& c){
{uint32_t v=add(c,c.r[2],~(50u),1,true);}
{uint32_t a=c.r[13]-20u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=add(c,c.r[13],~(20u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[3];c.r[5]=v;}
{if(cond(c,1)){c.pc=(270221710u|1u);return;}}
c.pc=270221595u;}
static void b_101b411a(Context& c){
{if(cond(c,13)){c.pc=(270221618u|1u);return;}}
c.pc=270221597u;}
static void b_101b411c(Context& c){
{uint32_t v=add(c,c.r[2],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270221654u|1u);return;}}
c.pc=270221601u;}
static void b_101b4120(Context& c){
{if(cond(c,13)){c.pc=(270221608u|1u);return;}}
c.pc=270221603u;}
static void b_101b4122(Context& c){
{uint32_t v=add(c,c.r[2],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270221644u|1u);return;}}
c.pc=270221607u;}
static void b_101b4126(Context& c){
{c.pc=(270221876u|1u);return;}
c.pc=270221609u;}
static void b_101b4128(Context& c){
{uint32_t v=add(c,c.r[2],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270221682u|1u);return;}}
c.pc=270221613u;}
static void b_101b412c(Context& c){
{uint32_t v=add(c,c.r[2],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270221702u|1u);return;}}
c.pc=270221617u;}
static void b_101b4130(Context& c){
{c.pc=(270221876u|1u);return;}
c.pc=270221619u;}
static void b_101b4132(Context& c){
{uint32_t v=add(c,c.r[2],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270221808u|1u);return;}}
c.pc=270221623u;}
static void b_101b4136(Context& c){
{if(cond(c,13)){c.pc=(270221634u|1u);return;}}
c.pc=270221625u;}
static void b_101b4138(Context& c){
{uint32_t v=add(c,c.r[2],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270221780u|1u);return;}}
c.pc=270221629u;}
static void b_101b413c(Context& c){
{uint32_t v=add(c,c.r[2],~(80u),1,true);}
{if(cond(c,1)){c.pc=(270221736u|1u);return;}}
c.pc=270221633u;}
static void b_101b4140(Context& c){
{c.pc=(270221876u|1u);return;}
c.pc=270221635u;}
static void b_101b4142(Context& c){
{uint32_t v=add(c,c.r[2],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270221808u|1u);return;}}
c.pc=270221639u;}
static void b_101b4146(Context& c){
{uint32_t v=add(c,c.r[2],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270221808u|1u);return;}}
c.pc=270221643u;}
static void b_101b414a(Context& c){
{c.pc=(270221876u|1u);return;}
c.pc=270221645u;}
static void b_101b414c(Context& c){
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270221876u|1u);return;}}
c.pc=270221649u;}
static void b_101b4150(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270221688u|1u);return;}
c.pc=270221655u;}
static void b_101b4156(Context& c){
{if(c.r[3] != 0){c.pc=(270221674u|1u);return;}}
c.pc=270221657u;}
static void b_101b4158(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=7u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270221669u;c.pc=(270393366u|1u);return;}
c.pc=270221669u;}
static void b_101b4164(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270221682u&~3u)+0u+200u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270221770u|1u);return;}
c.pc=270221683u;}
static void b_101b416a(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=((270221682u&~3u)+0u+200u);c.r[2]=rd<uint32_t>(c,a+0u);}
{c.pc=(270221770u|1u);return;}
c.pc=270221683u;}
static void b_101b4172(Context& c){
{if(c.r[3] != 0){c.pc=(270221718u|1u);return;}}
c.pc=270221685u;}
static void b_101b4174(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=8u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270393366u|1u);return;}
c.pc=270221703u;}
static void b_101b4178(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270393366u|1u);return;}
c.pc=270221703u;}
static void b_101b4186(Context& c){
{if(c.r[3] != 0){c.pc=(270221718u|1u);return;}}
c.pc=270221705u;}
static void b_101b4188(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{c.pc=(270221688u|1u);return;}
c.pc=270221711u;}
static void b_101b418e(Context& c){
{if(c.r[3] != 0){c.pc=(270221718u|1u);return;}}
c.pc=270221713u;}
static void b_101b4190(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270221688u|1u);return;}
c.pc=270221719u;}
static void b_101b4196(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270221876u|1u);return;}}
c.pc=270221727u;}
static void b_101b419e(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(269980032u|1u);return;}
c.pc=270221737u;}
static void b_101b41a8(Context& c){
{if(c.r[3] != 0){c.pc=(270221752u|1u);return;}}
c.pc=270221739u;}
static void b_101b41aa(Context& c){
{uint32_t v=c.r[3];c.r[2]=v;}
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=12u;nz(c,v);c.r[1]=v;}
{c.r[14]=270221751u;c.pc=(270393366u|1u);return;}
c.pc=270221751u;}
static void b_101b41b6(Context& c){
{c.pc=(270221764u|1u);return;}
c.pc=270221753u;}
static void b_101b41b8(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270221764u|1u);return;}}
c.pc=270221759u;}
static void b_101b41be(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(269978432u|1u);return;}
c.pc=270221781u;}
static void b_101b41c4(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(269978432u|1u);return;}
c.pc=270221781u;}
static void b_101b41ca(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(269978432u|1u);return;}
c.pc=270221781u;}
static void b_101b41d4(Context& c){
{if(c.r[3] != 0){c.pc=(270221788u|1u);return;}}
c.pc=270221783u;}
static void b_101b41d6(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{c.pc=(270221688u|1u);return;}
c.pc=270221789u;}
static void b_101b41dc(Context& c){
{uint32_t a=(c.r[1]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{if(c.r[2] != 0){c.pc=(270221876u|1u);return;}}
c.pc=270221795u;}
static void b_101b41e2(Context& c){
{uint32_t v=c.r[1];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270391848u|1u);return;}
c.pc=270221809u;}
static void b_101b41f0(Context& c){
{if(c.r[5] != 0){c.pc=(270221850u|1u);return;}}
c.pc=270221811u;}
static void b_101b41f2(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=27u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270221823u;c.pc=(270393366u|1u);return;}
c.pc=270221823u;}
static void b_101b41fe(Context& c){
{uint32_t v=65281u;c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270221849u;c.pc=(270015700u|1u);return;}
c.pc=270221849u;}
static void b_101b4218(Context& c){
{c.pc=(270221876u|1u);return;}
c.pc=270221851u;}
static void b_101b421a(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270221876u|1u);return;}}
c.pc=270221857u;}
static void b_101b4220(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{c.r[14]=270221865u;c.pc=(270221468u|1u);return;}
c.pc=270221865u;}
static void b_101b4228(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270391404u|1u);return;}
c.pc=270221877u;}
static void b_101b4234(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);uint32_t newpc=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;c.pc=newpc;return;}
c.pc=270221881u;}
static void b_101b423c(Context& c){
{uint32_t a=c.r[13]-36u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[11]);wr<uint32_t>(c,a+32u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-16u;wr<uint64_t>(c,a+0u,c.d[8]);wr<uint64_t>(c,a+8u,c.d[9]);c.r[13]=a;}
{setfs(c,19,-16.0);}
{uint32_t a=((270221900u&~3u)+0u+300u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[1]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],~(36u),1,false);c.r[13]=v;}
{uint32_t a=((270221908u&~3u)+0u+296u);c.r[11]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[0];c.r[4]=v;}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,2)){uint32_t v=4294967295u;c.r[8]=v;}}
{if(cond(c,1)){uint32_t v=1u;c.r[8]=v;}}
{uint32_t v=c.r[1];c.r[5]=v;}
{uint32_t v=8u;c.r[9]=v;}
{uint32_t v=1107296256u;c.r[10]=v;}
{setfs(c,18,16.0);}
{setfs(c,17,-8.0);}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270221947u;c.pc=(270082278u|1u);return;}
c.pc=270221947u;}
static void b_101b4274(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270221947u;c.pc=(270082278u|1u);return;}
c.pc=270221947u;}
static void b_101b427a(Context& c){
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270221955u;c.pc=(270082278u|1u);return;}
c.pc=270221955u;}
static void b_101b4282(Context& c){
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[6]=v;}
{uint32_t v=c.r[7];c.r[0]=v;}
{c.r[14]=270221965u;c.pc=(270697604u|1u);return;}
c.pc=270221965u;}
static void b_101b428c(Context& c){
{uint32_t v=c.r[6];c.r[0]=v;}
{uint32_t v=0u;nz(c,v);c.r[7]=v;}
{uint32_t v=1u;nz(c,v);c.r[6]=v;}
{uint32_t v=add(c,c.r[1],~(130u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[8])*(c.r[1]);c.r[2]=v;}
{uint32_t v=60u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270221985u;c.pc=(270697604u|1u);return;}
c.pc=270221985u;}
static void b_101b42a0(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,19));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t v=add(c,c.r[1],~(130u),1,false);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270222019u;c.pc=(270082284u|1u);return;}
c.pc=270222019u;}
static void b_101b42c2(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270222025u;c.pc=(270082278u|1u);return;}
c.pc=270222025u;}
static void b_101b42c8(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270222035u;c.pc=(270082278u|1u);return;}
c.pc=270222035u;}
static void b_101b42d2(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270222049u;c.pc=(270697604u|1u);return;}
c.pc=270222049u;}
static void b_101b42e0(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],30u,0,true);c.r[1]=v;}
{uint32_t v=(c.r[8])*(c.r[1]);c.r[2]=v;}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270222067u;c.pc=(270697604u|1u);return;}
c.pc=270222067u;}
static void b_101b42f2(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,16));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,sbits(c,18));}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t v=add(c,c.r[1],~(170u),1,false);c.r[3]=v;}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270222101u;c.pc=(270082284u|1u);return;}
c.pc=270222101u;}
static void b_101b4314(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270222107u;c.pc=(270082278u|1u);return;}
c.pc=270222107u;}
static void b_101b431a(Context& c){
{uint32_t v=c.r[0];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270222117u;c.pc=(270082278u|1u);return;}
c.pc=270222117u;}
static void b_101b4324(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=100u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[0];c.r[3]=v;}
{uint32_t v=c.r[2];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{c.r[14]=270222131u;c.pc=(270697604u|1u);return;}
c.pc=270222131u;}
static void b_101b4332(Context& c){
{uint32_t a=(c.r[13]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[3];c.r[0]=v;}
{uint32_t v=add(c,c.r[1],~(50u),1,true);c.r[1]=v;}
{uint32_t v=(c.r[8])*(c.r[1]);c.r[2]=v;}
{uint32_t v=60u;nz(c,v);c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+28u);wr<uint32_t>(c,a+0u,c.r[2]);}
{c.r[14]=270222149u;c.pc=(270697604u|1u);return;}
c.pc=270222149u;}
static void b_101b4344(Context& c){
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[7]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,sbits(c,17));}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[6]);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+16u);wr<uint32_t>(c,a+0u,c.r[11]);}
{uint32_t a=(c.r[13]+0u+20u);wr<uint32_t>(c,a+0u,c.r[10]);}
{uint32_t a=(c.r[13]+0u+28u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[1],~(130u),1,false);c.r[3]=v;}
{uint32_t v=1090519040u;c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+12u);wr<uint32_t>(c,a+0u,c.r[1]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{c.r[14]=270222185u;c.pc=(270082284u|1u);return;}
c.pc=270222185u;}
static void b_101b4368(Context& c){
{uint32_t v=add(c,c.r[9],~(1u),1,true);c.r[9]=v;}
{if(cond(c,2)){c.pc=(270221940u|1u);return;}}
c.pc=270222191u;}
static void b_101b436e(Context& c){
{uint32_t v=add(c,c.r[13],36u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.d[9]=rd<uint64_t>(c,a+8u);c.r[13]=a+16u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);c.r[9]=rd<uint32_t>(c,a+20u);c.r[10]=rd<uint32_t>(c,a+24u);c.r[11]=rd<uint32_t>(c,a+28u);uint32_t newpc=rd<uint32_t>(c,a+32u);c.r[13]=a+36u;c.pc=newpc;return;}
c.pc=270222201u;}
static void b_101b4380(Context& c){
{uint32_t a=c.r[13]-20u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-8u;wr<uint64_t>(c,a+0u,c.d[8]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+28u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[13],~(20u),1,false);c.r[13]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[2];c.r[6]=v;}
{uint32_t v=c.r[3];c.r[5]=v;}
{if(c.r[1] != 0){c.pc=(270222240u|1u);return;}}
c.pc=270222229u;}
static void b_101b4394(Context& c){
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=15u;nz(c,v);c.r[2]=v;}
{c.r[14]=270222241u;c.pc=(270393746u|1u);return;}
c.pc=270222241u;}
static void b_101b43a0(Context& c){
{uint32_t v=add(c,c.r[6],~(50u),1,true);}
{if(cond(c,1)){c.pc=(270222450u|1u);return;}}
c.pc=270222245u;}
static void b_101b43a4(Context& c){
{if(cond(c,13)){c.pc=(270222268u|1u);return;}}
c.pc=270222247u;}
static void b_101b43a6(Context& c){
{uint32_t v=add(c,c.r[6],~(20u),1,true);}
{if(cond(c,1)){c.pc=(270222382u|1u);return;}}
c.pc=270222251u;}
static void b_101b43aa(Context& c){
{if(cond(c,13)){c.pc=(270222258u|1u);return;}}
c.pc=270222253u;}
static void b_101b43ac(Context& c){
{uint32_t v=add(c,c.r[6],~(10u),1,true);}
{if(cond(c,1)){c.pc=(270222382u|1u);return;}}
c.pc=270222257u;}
static void b_101b43b0(Context& c){
{c.pc=(270222566u|1u);return;}
c.pc=270222259u;}
static void b_101b43b2(Context& c){
{uint32_t v=add(c,c.r[6],~(30u),1,true);}
{if(cond(c,1)){c.pc=(270222442u|1u);return;}}
c.pc=270222263u;}
static void b_101b43b6(Context& c){
{uint32_t v=add(c,c.r[6],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270222442u|1u);return;}}
c.pc=270222267u;}
static void b_101b43ba(Context& c){
{c.pc=(270222566u|1u);return;}
c.pc=270222269u;}
static void b_101b43bc(Context& c){
{uint32_t v=add(c,c.r[6],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270222486u|1u);return;}}
c.pc=270222273u;}
static void b_101b43c0(Context& c){
{if(cond(c,13)){c.pc=(270222284u|1u);return;}}
c.pc=270222275u;}
static void b_101b43c2(Context& c){
{uint32_t v=add(c,c.r[6],~(70u),1,true);}
{if(cond(c,1)){c.pc=(270222392u|1u);return;}}
c.pc=270222279u;}
static void b_101b43c6(Context& c){
{uint32_t v=add(c,c.r[6],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270222486u|1u);return;}}
c.pc=270222283u;}
static void b_101b43ca(Context& c){
{c.pc=(270222566u|1u);return;}
c.pc=270222285u;}
static void b_101b43cc(Context& c){
{uint32_t v=add(c,c.r[6],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270222486u|1u);return;}}
c.pc=270222289u;}
static void b_101b43d0(Context& c){
{uint32_t v=add(c,c.r[6],~(141u),1,true);}
{if(cond(c,2)){c.pc=(270222566u|1u);return;}}
c.pc=270222295u;}
static void b_101b43d6(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270222566u|1u);return;}}
c.pc=270222301u;}
static void b_101b43dc(Context& c){
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270222313u;c.pc=(270393366u|1u);return;}
c.pc=270222313u;}
static void b_101b43e8(Context& c){
{setfs(c,15,10.0);}
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,16,rd<uint32_t>(c,a+0u));}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{}
{if(cond(c,1)){setfs(c,16,(fs(c,16))-(fs(c,15)));}}
{if(cond(c,2)){setfs(c,16,(fs(c,16))+(fs(c,15)));}}
{setsbits(c,16,cvti(fs(c,16),true));}
{setfs(c,15,int32_t(sbits(c,16)));}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.r[14]=270222355u;c.pc=(270408416u|1u);return;}
c.pc=270222355u;}
static void b_101b4412(Context& c){
{c.r[1]=sbits(c,16);}
{uint32_t v=1u;nz(c,v);c.r[2]=v;}
{c.r[14]=270222365u;c.pc=(270408818u|1u);return;}
c.pc=270222365u;}
static void b_101b441c(Context& c){
{setsbits(c,14,c.r[0]);}
{setfs(c,15,int32_t(sbits(c,14)));}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{c.pc=(270222566u|1u);return;}
c.pc=270222383u;}
static void b_101b442e(Context& c){
{uint32_t v=add(c,c.r[5],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270222566u|1u);return;}}
c.pc=270222387u;}
static void b_101b4432(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=6u;nz(c,v);c.r[1]=v;}
{c.pc=(270222398u|1u);return;}
c.pc=270222393u;}
static void b_101b4438(Context& c){
{if(c.r[5] != 0){c.pc=(270222416u|1u);return;}}
c.pc=270222395u;}
static void b_101b443a(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=11u;nz(c,v);c.r[1]=v;}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.r[13]=a+8u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270393366u|1u);return;}
c.pc=270222417u;}
static void b_101b443e(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.r[13]=a+8u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270393366u|1u);return;}
c.pc=270222417u;}
static void b_101b4450(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[2]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[2],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270222566u|1u);return;}}
c.pc=270222425u;}
static void b_101b4458(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.r[13]=a+8u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270391848u|1u);return;}
c.pc=270222443u;}
static void b_101b446a(Context& c){
{if(c.r[5] != 0){c.pc=(270222458u|1u);return;}}
c.pc=270222445u;}
static void b_101b446c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=9u;nz(c,v);c.r[1]=v;}
{c.pc=(270222398u|1u);return;}
c.pc=270222451u;}
static void b_101b4472(Context& c){
{if(c.r[5] != 0){c.pc=(270222458u|1u);return;}}
c.pc=270222453u;}
static void b_101b4474(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=10u;nz(c,v);c.r[1]=v;}
{c.pc=(270222398u|1u);return;}
c.pc=270222459u;}
static void b_101b447a(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270222566u|1u);return;}}
c.pc=270222467u;}
static void b_101b4482(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=c.r[6];c.r[2]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.r[13]=a+8u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(269980032u|1u);return;}
c.pc=270222487u;}
static void b_101b4496(Context& c){
{if(c.r[5] != 0){c.pc=(270222544u|1u);return;}}
c.pc=270222489u;}
static void b_101b4498(Context& c){
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=13u;nz(c,v);c.r[1]=v;}
{uint32_t v=1u;nz(c,v);c.r[3]=v;}
{c.r[14]=270222501u;c.pc=(270393366u|1u);return;}
c.pc=270222501u;}
static void b_101b44a4(Context& c){
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=65305u;c.r[3]=v;}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[3]=v;}
{c.r[14]=270222527u;c.pc=(270015700u|1u);return;}
c.pc=270222527u;}
static void b_101b44be(Context& c){
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[4];c.r[1]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.r[13]=a+8u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270221884u|1u);return;}
c.pc=270222545u;}
static void b_101b44d0(Context& c){
{uint32_t a=(c.r[4]+0u+201u);c.r[3]=rd<uint8_t>(c,a+0u);}
{if(c.r[3] != 0){c.pc=(270222566u|1u);return;}}
c.pc=270222551u;}
static void b_101b44d6(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.r[13]=a+8u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[14]=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;}
{c.pc=(270391404u|1u);return;}
c.pc=270222567u;}
static void b_101b44e6(Context& c){
{uint32_t v=add(c,c.r[13],20u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.d[8]=rd<uint64_t>(c,a+0u);c.r[13]=a+8u;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);uint32_t newpc=rd<uint32_t>(c,a+16u);c.r[13]=a+20u;c.pc=newpc;return;}
c.pc=270222575u;}
static void b_101b44f0(Context& c){
{uint32_t a=c.r[13]-8u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[14]);c.r[13]=a;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t a=(c.r[1]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270222600u|1u);return;}}
c.pc=270222587u;}
static void b_101b44fa(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+60u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=~(49u);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=5u;nz(c,v);c.r[3]=v;}
{c.pc=(270222612u|1u);return;}
c.pc=270222601u;}
static void b_101b4508(Context& c){
{uint32_t v=add(c,c.r[3],~(5u),1,true);}
{if(cond(c,2)){c.pc=(270222614u|1u);return;}}
c.pc=270222605u;}
static void b_101b450c(Context& c){
{uint32_t v=50u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[1]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=~(4u);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270222620u&~3u)+0u+56u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[1]=sbits(c,15);}
{c.r[14]=270222663u;c.pc=(270393746u|1u);return;}
c.pc=270222663u;}
static void b_101b4514(Context& c){
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270222620u&~3u)+0u+56u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[1]=sbits(c,15);}
{c.r[14]=270222663u;c.pc=(270393746u|1u);return;}
c.pc=270222663u;}
static void b_101b4516(Context& c){
{uint32_t a=(c.r[4]+0u+32u);c.r[2]=rd<uint32_t>(c,a+0u);}
{uint32_t a=((270222620u&~3u)+0u+56u);setsbits(c,14,rd<uint32_t>(c,a+0u));}
{uint32_t a=(c.r[4]+0u+36u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=add(c,c.r[3],c.r[2],0,false);c.r[3]=v;}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[4]+0u+32u);wr<uint32_t>(c,a+0u,c.r[3]);}
{setsbits(c,15,c.r[3]);}
{setfs(c,13,int32_t(sbits(c,15)));}
{uint32_t a=(c.r[4]+0u+60u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setfs(c,15,fs(c,15)+float((fs(c,13))*(fs(c,14))));}
{uint32_t a=(c.r[4]+0u+60u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[1]=sbits(c,15);}
{c.r[14]=270222663u;c.pc=(270393746u|1u);return;}
c.pc=270222663u;}
static void b_101b4546(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(7u),1,true);}
{}
{if(cond(c,14)){uint32_t v=add(c,c.r[3],1u,0,false);c.r[3]=v;}}
{if(cond(c,13)){uint32_t v=1u;c.r[3]=v;}}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);uint32_t newpc=rd<uint32_t>(c,a+4u);c.r[13]=a+8u;c.pc=newpc;return;}
c.pc=270222677u;}
static void b_101b4558(Context& c){
{uint32_t a=c.r[13]-40u;wr<uint32_t>(c,a+0u,c.r[0]);wr<uint32_t>(c,a+4u,c.r[1]);wr<uint32_t>(c,a+8u,c.r[2]);wr<uint32_t>(c,a+12u,c.r[3]);wr<uint32_t>(c,a+16u,c.r[4]);wr<uint32_t>(c,a+20u,c.r[5]);wr<uint32_t>(c,a+24u,c.r[6]);wr<uint32_t>(c,a+28u,c.r[7]);wr<uint32_t>(c,a+32u,c.r[8]);wr<uint32_t>(c,a+36u,c.r[14]);c.r[13]=a;}
{uint32_t v=4294967295u;c.r[4]=v;}
{uint32_t v=1u;nz(c,v);c.r[5]=v;}
{uint32_t v=65284u;c.r[8]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=~(49u);c.r[3]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[1];c.r[6]=v;}
{c.r[14]=270222715u;c.pc=(270015700u|1u);return;}
c.pc=270222715u;}
static void b_101b457a(Context& c){
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t v=c.r[2];c.r[3]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=add(c,c.r[8],c.r[4],0,false);c.r[8]=v;}
{c.r[14]=270222735u;c.pc=(270015700u|1u);return;}
c.pc=270222735u;}
static void b_101b458e(Context& c){
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t a=(c.r[13]+0u+0u);wr<uint32_t>(c,a+0u,c.r[5]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+4u);wr<uint32_t>(c,a+0u,c.r[8]);}
{uint32_t v=40u;nz(c,v);c.r[2]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{c.r[14]=270222755u;c.pc=(270015700u|1u);return;}
c.pc=270222755u;}
static void b_101b45a2(Context& c){
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t v=100u;nz(c,v);c.r[2]=v;}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{c.r[14]=270222773u;c.pc=(270015700u|1u);return;}
c.pc=270222773u;}
static void b_101b45b4(Context& c){
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t v=170u;nz(c,v);c.r[2]=v;}
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{c.r[14]=270222791u;c.pc=(270015700u|1u);return;}
c.pc=270222791u;}
static void b_101b45c6(Context& c){
{uint32_t v=45u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t v=c.r[2];c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[4]);}
{c.r[14]=270222809u;c.pc=(270015700u|1u);return;}
c.pc=270222809u;}
static void b_101b45d8(Context& c){
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t v=100u;nz(c,v);c.r[2]=v;}
{uint32_t v=90u;nz(c,v);c.r[3]=v;}
{c.r[14]=270222827u;c.pc=(270015700u|1u);return;}
c.pc=270222827u;}
static void b_101b45ea(Context& c){
{uint32_t v=150u;nz(c,v);c.r[2]=v;}
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t v=c.r[2];c.r[3]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[4]);}
{c.r[14]=270222845u;c.pc=(270015700u|1u);return;}
c.pc=270222845u;}
static void b_101b45fc(Context& c){
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t v=45u;nz(c,v);c.r[2]=v;}
{uint32_t v=~(44u);c.r[3]=v;}
{c.r[14]=270222865u;c.pc=(270015700u|1u);return;}
c.pc=270222865u;}
static void b_101b4610(Context& c){
{uint32_t a=c.r[13];wr<uint32_t>(c,a+0u,c.r[5]);wr<uint32_t>(c,a+4u,c.r[8]);}
{uint32_t a=(c.r[13]+0u+8u);wr<uint32_t>(c,a+0u,c.r[4]);}
{uint32_t v=c.r[7];c.r[0]=v;}
{uint32_t v=c.r[6];c.r[1]=v;}
{uint32_t v=100u;nz(c,v);c.r[2]=v;}
{uint32_t v=~(89u);c.r[3]=v;}
{c.r[14]=270222885u;c.pc=(270015700u|1u);return;}
c.pc=270222885u;}
static void b_101b4624(Context& c){
{uint32_t v=add(c,c.r[13],16u,0,false);c.r[13]=v;}
{uint32_t a=c.r[13];c.r[4]=rd<uint32_t>(c,a+0u);c.r[5]=rd<uint32_t>(c,a+4u);c.r[6]=rd<uint32_t>(c,a+8u);c.r[7]=rd<uint32_t>(c,a+12u);c.r[8]=rd<uint32_t>(c,a+16u);uint32_t newpc=rd<uint32_t>(c,a+20u);c.r[13]=a+24u;c.pc=newpc;return;}
c.pc=270222891u;}
static void b_101b462c(Context& c){
{uint32_t a=c.r[13]-36u;wr<uint32_t>(c,a+0u,c.r[4]);wr<uint32_t>(c,a+4u,c.r[5]);wr<uint32_t>(c,a+8u,c.r[6]);wr<uint32_t>(c,a+12u,c.r[7]);wr<uint32_t>(c,a+16u,c.r[8]);wr<uint32_t>(c,a+20u,c.r[9]);wr<uint32_t>(c,a+24u,c.r[10]);wr<uint32_t>(c,a+28u,c.r[11]);wr<uint32_t>(c,a+32u,c.r[14]);c.r[13]=a;}
{uint32_t a=c.r[13]-16u;wr<uint64_t>(c,a+0u,c.d[8]);wr<uint64_t>(c,a+8u,c.d[9]);c.r[13]=a;}
{uint32_t v=add(c,c.r[13],~(44u),1,false);c.r[13]=v;}
{uint32_t v=c.r[1];c.r[4]=v;}
{uint32_t v=c.r[3];c.r[6]=v;}
{uint32_t v=c.r[0];c.r[7]=v;}
{uint32_t v=c.r[2];c.r[5]=v;}
{c.r[14]=270222915u;c.pc=(270326600u|1u);return;}
c.pc=270222915u;}
static void b_101b4642(Context& c){
{uint32_t a=(c.r[4]+0u+28u);c.r[10]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[0],18432u,0,false);c.r[0]=v;}
{uint32_t a=(c.r[0]+0u+40u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(5u),1,true);c.r[0]=v;}
{uint32_t v=add(c,0u,~(c.r[0]),1,true);c.r[9]=v;}
{uint32_t v=add(c,c.r[9],c.r[0],c.c,true);c.r[9]=v;}
{uint32_t v=add(c,c.r[10],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270223042u|1u);return;}}
c.pc=270222941u;}
static void b_101b465c(Context& c){
{uint32_t v=1u;c.r[8]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{uint32_t a=(c.r[4]+0u+28u);wr<uint32_t>(c,a+0u,c.r[8]);}
{c.r[14]=270222957u;c.pc=(269975768u|1u);return;}
c.pc=270222957u;}
static void b_101b466c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270222965u;c.pc=(269975414u|1u);return;}
c.pc=270222965u;}
static void b_101b4674(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270222973u;c.pc=(269975422u|1u);return;}
c.pc=270222973u;}
static void b_101b467c(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t v=c.r[8];c.r[1]=v;}
{c.r[14]=270222981u;c.pc=(269975962u|1u);return;}
c.pc=270222981u;}
static void b_101b4684(Context& c){
{uint32_t v=add(c,c.r[5],~(40u),1,true);}
{if(cond(c,1)){c.pc=(270222990u|1u);return;}}
c.pc=270222985u;}
static void b_101b4688(Context& c){
{uint32_t v=add(c,c.r[5],~(30u),1,true);}
{if(cond(c,2)){c.pc=(270224172u|1u);return;}}
c.pc=270222991u;}
static void b_101b468e(Context& c){
{uint32_t v=add(c,c.r[9],~(0u),1,true);}
{if(cond(c,2)){c.pc=(270223030u|1u);return;}}
c.pc=270222997u;}
static void b_101b4694(Context& c){
{uint32_t v=10u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{if(cond(c,2)){c.pc=(270224194u|1u);return;}}
c.pc=270223011u;}
static void b_101b469a(Context& c){
{uint32_t a=(c.r[4]+0u+120u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[3],~(90u),1,true);}
{if(cond(c,2)){c.pc=(270224194u|1u);return;}}
c.pc=270223011u;}
static void b_101b46a2(Context& c){
{uint32_t v=0u;nz(c,v);c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+148u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+140u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=((270223024u&~3u)+0u+764u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+152u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=add(c,c.r[5],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270223842u|1u);return;}}
c.pc=270223049u;}
static void b_101b46ac(Context& c){
{uint32_t a=((270223024u&~3u)+0u+764u);c.r[3]=rd<uint32_t>(c,a+0u);}
{uint32_t a=(c.r[4]+0u+152u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+144u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t a=(c.r[4]+0u+152u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=add(c,c.r[5],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270223842u|1u);return;}}
c.pc=270223049u;}
static void b_101b46b6(Context& c){
{uint32_t a=(c.r[4]+0u+152u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t a=(c.r[4]+0u+36u);wr<uint32_t>(c,a+0u,sbits(c,15));}
{uint32_t v=add(c,c.r[5],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270223842u|1u);return;}}
c.pc=270223049u;}
static void b_101b46c2(Context& c){
{uint32_t v=add(c,c.r[5],~(100u),1,true);}
{if(cond(c,1)){c.pc=(270223842u|1u);return;}}
c.pc=270223049u;}
static void b_101b46c8(Context& c){
{uint32_t v=add(c,c.r[5],~(120u),1,true);}
{if(cond(c,1)){c.pc=(270223842u|1u);return;}}
c.pc=270223055u;}
static void b_101b46ce(Context& c){
{uint32_t v=add(c,c.r[5],~(110u),1,true);}
{if(cond(c,1)){c.pc=(270223842u|1u);return;}}
c.pc=270223061u;}
static void b_101b46d4(Context& c){
{uint32_t v=add(c,c.r[5],~(140u),1,true);}
{if(cond(c,1)){c.pc=(270224156u|1u);return;}}
c.pc=270223067u;}
static void b_101b46da(Context& c){
{uint32_t a=(c.r[4]+0u+52u);c.r[8]=rd<uint32_t>(c,a+0u);}
{uint32_t v=add(c,c.r[8],~(1u),1,true);}
{if(cond(c,2)){c.pc=(270223176u|1u);return;}}
c.pc=270223077u;}
static void b_101b46e4(Context& c){
{c.r[14]=270223081u;c.pc=(270408416u|1u);return;}
c.pc=270223081u;}
static void b_101b46e8(Context& c){
{uint32_t a=(c.r[4]+0u+140u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{uint32_t v=c.r[8];c.r[2]=v;}
{c.r[1]=sbits(c,15);}
{c.r[14]=270223099u;c.pc=(270408818u|1u);return;}
c.pc=270223099u;}
static void b_101b46fa(Context& c){
{uint32_t a=(c.r[4]+0u+144u);setsbits(c,15,rd<uint32_t>(c,a+0u));}
{setsbits(c,15,cvti(fs(c,15),true));}
{c.r[2]=sbits(c,15);}
{uint32_t v=add(c,c.r[0],~(260u),1,false);c.r[0]=v;}
{uint32_t v=add(c,c.r[2],~(c.r[0]),1,true);}
{if(cond(c,11)){c.pc=(270223134u|1u);return;}}
c.pc=270223119u;}
static void b_101b470e(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=((270223124u&~3u)+0u+668u);c.r[1]=rd<uint32_t>(c,a+0u);}
{uint32_t v=0u;nz(c,v);c.r[2]=v;}
{uint32_t v=4294967295u;c.r[3]=v;}
{c.r[14]=270223133u;c.pc=(270392910u|1u);return;}
c.pc=270223133u;}
static void b_101b471c(Context& c){
{c.pc=(270224276u|1u);return;}
c.pc=270223135u;}
static void b_101b471e(Context& c){
{uint32_t v=add(c,c.r[5],~(70u),1,true);}
{uint32_t v=2u;c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=10u;c.r[3]=v;}
{uint32_t a=(c.r[4]+0u+132u);wr<uint32_t>(c,a+0u,c.r[3]);}
{if(cond(c,2)){c.pc=(270224276u|1u);return;}}
c.pc=270223155u;}
static void b_101b4732(Context& c){
{uint32_t v=3u;nz(c,v);c.r[3]=v;}
{uint32_t v=c.r[4];c.r[0]=v;}
{uint32_t a=(c.r[4]+0u+52u);wr<uint32_t>(c,a+0u,c.r[3]);}
{uint32_t v=c.r[5];c.r[1]=v;}
{uint32_t v=c.r[8];c.r[2]=v;}
{c.r[14]=270223169u;c.pc=(270391848u|1u);return;}
c.pc=270223169u;}
static void b_101b4740(Context& c){
{uint32_t v=c.r[4];c.r[0]=v;}
{c.r[14]=270223175u;c.pc=(270393272u|1u);return;}
c.pc=270223175u;}
static void b_101b4746(Context& c){
{c.pc=(270224276u|1u);return;}
c.pc=270223177u;}
void install_27(){register_block(270203853u,b_101afbcc);register_block(270203857u,b_101afbd0);register_block(270203859u,b_101afbd2);register_block(270203867u,b_101afbda);register_block(270203869u,b_101afbdc);register_block(270203875u,b_101afbe2);register_block(270203881u,b_101afbe8);register_block(270203887u,b_101afbee);register_block(270203889u,b_101afbf0);register_block(270203895u,b_101afbf6);register_block(270203903u,b_101afbfe);register_block(270203905u,b_101afc00);register_block(270203915u,b_101afc0a);register_block(270203923u,b_101afc12);register_block(270203929u,b_101afc18);register_block(270203935u,b_101afc1e);register_block(270203965u,b_101afc3c);register_block(270203975u,b_101afc46);register_block(270203985u,b_101afc50);register_block(270204001u,b_101afc60);register_block(270204011u,b_101afc6a);register_block(270204025u,b_101afc78);register_block(270204029u,b_101afc7c);register_block(270204037u,b_101afc84);register_block(270204039u,b_101afc86);register_block(270204095u,b_101afcbe);register_block(270204113u,b_101afcd0);register_block(270204125u,b_101afcdc);register_block(270204133u,b_101afce4);register_block(270204137u,b_101afce8);register_block(270204143u,b_101afcee);register_block(270204147u,b_101afcf2);register_block(270204151u,b_101afcf6);register_block(270204159u,b_101afcfe);register_block(270204171u,b_101afd0a);register_block(270204179u,b_101afd12);register_block(270204181u,b_101afd14);register_block(270204185u,b_101afd18);register_block(270204197u,b_101afd24);register_block(270204207u,b_101afd2e);register_block(270204211u,b_101afd32);register_block(270204219u,b_101afd3a);register_block(270204223u,b_101afd3e);register_block(270204225u,b_101afd40);register_block(270204229u,b_101afd44);register_block(270204231u,b_101afd46);register_block(270204235u,b_101afd4a);register_block(270204237u,b_101afd4c);register_block(270204241u,b_101afd50);register_block(270204245u,b_101afd54);register_block(270204247u,b_101afd56);register_block(270204251u,b_101afd5a);register_block(270204253u,b_101afd5c);register_block(270204257u,b_101afd60);register_block(270204259u,b_101afd62);register_block(270204263u,b_101afd66);register_block(270204267u,b_101afd6a);register_block(270204269u,b_101afd6c);register_block(270204271u,b_101afd6e);register_block(270204283u,b_101afd7a);register_block(270204289u,b_101afd80);register_block(270204291u,b_101afd82);register_block(270204303u,b_101afd8e);register_block(270204311u,b_101afd96);register_block(270204323u,b_101afda2);register_block(270204325u,b_101afda4);register_block(270204337u,b_101afdb0);register_block(270204343u,b_101afdb6);register_block(270204355u,b_101afdc2);register_block(270204369u,b_101afdd0);register_block(270204371u,b_101afdd2);register_block(270204383u,b_101afdde);register_block(270204387u,b_101afde2);register_block(270204389u,b_101afde4);register_block(270204401u,b_101afdf0);register_block(270204407u,b_101afdf6);register_block(270204413u,b_101afdfc);register_block(270204421u,b_101afe04);register_block(270204427u,b_101afe0a);register_block(270204429u,b_101afe0c);register_block(270204431u,b_101afe0e);register_block(270204443u,b_101afe1a);register_block(270204445u,b_101afe1c);register_block(270204451u,b_101afe22);register_block(270204457u,b_101afe28);register_block(270204473u,b_101afe38);register_block(270204483u,b_101afe42);register_block(270204491u,b_101afe4a);register_block(270204495u,b_101afe4e);register_block(270204507u,b_101afe5a);register_block(270204519u,b_101afe66);register_block(270204543u,b_101afe7e);register_block(270204545u,b_101afe80);register_block(270204565u,b_101afe94);register_block(270204569u,b_101afe98);register_block(270204581u,b_101afea4);register_block(270204583u,b_101afea6);register_block(270204587u,b_101afeaa);register_block(270204589u,b_101afeac);register_block(270204593u,b_101afeb0);register_block(270204595u,b_101afeb2);register_block(270204599u,b_101afeb6);register_block(270204603u,b_101afeba);register_block(270204605u,b_101afebc);register_block(270204609u,b_101afec0);register_block(270204611u,b_101afec2);register_block(270204615u,b_101afec6);register_block(270204617u,b_101afec8);register_block(270204621u,b_101afecc);register_block(270204625u,b_101afed0);register_block(270204627u,b_101afed2);register_block(270204631u,b_101afed6);register_block(270204649u,b_101afee8);register_block(270204651u,b_101afeea);register_block(270204663u,b_101afef6);register_block(270204669u,b_101afefc);register_block(270204685u,b_101aff0c);register_block(270204701u,b_101aff1c);register_block(270204703u,b_101aff1e);register_block(270204715u,b_101aff2a);register_block(270204729u,b_101aff38);register_block(270204741u,b_101aff44);register_block(270204745u,b_101aff48);register_block(270204757u,b_101aff54);register_block(270204759u,b_101aff56);register_block(270204761u,b_101aff58);register_block(270204765u,b_101aff5c);register_block(270204777u,b_101aff68);register_block(270204779u,b_101aff6a);register_block(270204791u,b_101aff76);register_block(270204797u,b_101aff7c);register_block(270204801u,b_101aff80);register_block(270204805u,b_101aff84);register_block(270204831u,b_101aff9e);register_block(270204833u,b_101affa0);register_block(270204839u,b_101affa6);register_block(270204863u,b_101affbe);register_block(270204875u,b_101affca);register_block(270204885u,b_101affd4);register_block(270204895u,b_101affde);register_block(270204903u,b_101affe6);register_block(270204907u,b_101affea);register_block(270204919u,b_101afff6);register_block(270204939u,b_101b000a);register_block(270204941u,b_101b000c);register_block(270204949u,b_101b0014);register_block(270204953u,b_101b0018);register_block(270204971u,b_101b002a);register_block(270204979u,b_101b0032);register_block(270204987u,b_101b003a);register_block(270204989u,b_101b003c);register_block(270204993u,b_101b0040);register_block(270204995u,b_101b0042);register_block(270204999u,b_101b0046);register_block(270205003u,b_101b004a);register_block(270205005u,b_101b004c);register_block(270205009u,b_101b0050);register_block(270205013u,b_101b0054);register_block(270205015u,b_101b0056);register_block(270205021u,b_101b005c);register_block(270205023u,b_101b005e);register_block(270205027u,b_101b0062);register_block(270205033u,b_101b0068);register_block(270205035u,b_101b006a);register_block(270205039u,b_101b006e);register_block(270205045u,b_101b0074);register_block(270205047u,b_101b0076);register_block(270205053u,b_101b007c);register_block(270205059u,b_101b0082);register_block(270205061u,b_101b0084);register_block(270205073u,b_101b0090);register_block(270205079u,b_101b0096);register_block(270205087u,b_101b009e);register_block(270205089u,b_101b00a0);register_block(270205093u,b_101b00a4);register_block(270205097u,b_101b00a8);register_block(270205099u,b_101b00aa);register_block(270205105u,b_101b00b0);register_block(270205115u,b_101b00ba);register_block(270205131u,b_101b00ca);register_block(270205133u,b_101b00cc);register_block(270205139u,b_101b00d2);register_block(270205147u,b_101b00da);register_block(270205149u,b_101b00dc);register_block(270205157u,b_101b00e4);register_block(270205167u,b_101b00ee);register_block(270205177u,b_101b00f8);register_block(270205187u,b_101b0102);register_block(270205201u,b_101b0110);register_block(270205203u,b_101b0112);register_block(270205215u,b_101b011e);register_block(270205217u,b_101b0120);register_block(270205223u,b_101b0126);register_block(270205229u,b_101b012c);register_block(270205235u,b_101b0132);register_block(270205245u,b_101b013c);register_block(270205247u,b_101b013e);register_block(270205259u,b_101b014a);register_block(270205267u,b_101b0152);register_block(270205271u,b_101b0156);register_block(270205279u,b_101b015e);register_block(270205287u,b_101b0166);register_block(270205293u,b_101b016c);register_block(270205295u,b_101b016e);register_block(270205321u,b_101b0188);register_block(270205327u,b_101b018e);register_block(270205335u,b_101b0196);register_block(270205361u,b_101b01b0);register_block(270205401u,b_101b01d8);register_block(270205409u,b_101b01e0);register_block(270205421u,b_101b01ec);register_block(270205437u,b_101b01fc);register_block(270205439u,b_101b01fe);register_block(270205445u,b_101b0204);register_block(270205453u,b_101b020c);register_block(270205455u,b_101b020e);register_block(270205461u,b_101b0214);register_block(270205467u,b_101b021a);register_block(270205475u,b_101b0222);register_block(270205483u,b_101b022a);register_block(270205485u,b_101b022c);register_block(270205497u,b_101b0238);register_block(270205521u,b_101b0250);register_block(270205531u,b_101b025a);register_block(270205545u,b_101b0268);register_block(270205549u,b_101b026c);register_block(270205557u,b_101b0274);register_block(270205559u,b_101b0276);register_block(270205607u,b_101b02a6);register_block(270205625u,b_101b02b8);register_block(270205643u,b_101b02ca);register_block(270205663u,b_101b02de);register_block(270205677u,b_101b02ec);register_block(270205685u,b_101b02f4);register_block(270205693u,b_101b02fc);register_block(270205701u,b_101b0304);register_block(270205705u,b_101b0308);register_block(270205713u,b_101b0310);register_block(270205739u,b_101b032a);register_block(270205745u,b_101b0330);register_block(270205757u,b_101b033c);register_block(270205763u,b_101b0342);register_block(270205769u,b_101b0348);register_block(270205775u,b_101b034e);register_block(270205781u,b_101b0354);register_block(270205787u,b_101b035a);register_block(270205789u,b_101b035c);register_block(270205799u,b_101b0366);register_block(270205807u,b_101b036e);register_block(270205809u,b_101b0370);register_block(270205821u,b_101b037c);register_block(270205833u,b_101b0388);register_block(270205837u,b_101b038c);register_block(270205847u,b_101b0396);register_block(270205857u,b_101b03a0);register_block(270205859u,b_101b03a2);register_block(270205867u,b_101b03aa);register_block(270205871u,b_101b03ae);register_block(270205873u,b_101b03b0);register_block(270205877u,b_101b03b4);register_block(270205879u,b_101b03b6);register_block(270205883u,b_101b03ba);register_block(270205885u,b_101b03bc);register_block(270205889u,b_101b03c0);register_block(270205893u,b_101b03c4);register_block(270205895u,b_101b03c6);register_block(270205899u,b_101b03ca);register_block(270205901u,b_101b03cc);register_block(270205905u,b_101b03d0);register_block(270205909u,b_101b03d4);register_block(270205911u,b_101b03d6);register_block(270205915u,b_101b03da);register_block(270205921u,b_101b03e0);register_block(270205923u,b_101b03e2);register_block(270205925u,b_101b03e4);register_block(270205929u,b_101b03e8);register_block(270205937u,b_101b03f0);register_block(270205951u,b_101b03fe);register_block(270205953u,b_101b0400);register_block(270205965u,b_101b040c);register_block(270205971u,b_101b0412);register_block(270205979u,b_101b041a);register_block(270205987u,b_101b0422);register_block(270205989u,b_101b0424);register_block(270205995u,b_101b042a);register_block(270205997u,b_101b042c);register_block(270206003u,b_101b0432);register_block(270206011u,b_101b043a);register_block(270206021u,b_101b0444);register_block(270206023u,b_101b0446);register_block(270206025u,b_101b0448);register_block(270206031u,b_101b044e);register_block(270206043u,b_101b045a);register_block(270206053u,b_101b0464);register_block(270206069u,b_101b0474);register_block(270206071u,b_101b0476);register_block(270206077u,b_101b047c);register_block(270206085u,b_101b0484);register_block(270206093u,b_101b048c);register_block(270206095u,b_101b048e);register_block(270206097u,b_101b0490);register_block(270206109u,b_101b049c);register_block(270206115u,b_101b04a2);register_block(270206121u,b_101b04a8);register_block(270206129u,b_101b04b0);register_block(270206133u,b_101b04b4);register_block(270206139u,b_101b04ba);register_block(270206149u,b_101b04c4);register_block(270206151u,b_101b04c6);register_block(270206187u,b_101b04ea);register_block(270206199u,b_101b04f6);register_block(270206205u,b_101b04fc);register_block(270206215u,b_101b0506);register_block(270206225u,b_101b0510);register_block(270206237u,b_101b051c);register_block(270206255u,b_101b052e);register_block(270206277u,b_101b0544);register_block(270206299u,b_101b055a);register_block(270206323u,b_101b0572);register_block(270206345u,b_101b0588);register_block(270206367u,b_101b059e);register_block(270206391u,b_101b05b6);register_block(270206413u,b_101b05cc);register_block(270206433u,b_101b05e0);register_block(270206453u,b_101b05f4);register_block(270206473u,b_101b0608);register_block(270206481u,b_101b0610);register_block(270206489u,b_101b0618);register_block(270206493u,b_101b061c);register_block(270206499u,b_101b0622);register_block(270206507u,b_101b062a);register_block(270206523u,b_101b063a);register_block(270206539u,b_101b064a);register_block(270206545u,b_101b0650);register_block(270206555u,b_101b065a);register_block(270206569u,b_101b0668);register_block(270206573u,b_101b066c);register_block(270206581u,b_101b0674);register_block(270206583u,b_101b0676);register_block(270206631u,b_101b06a6);register_block(270206649u,b_101b06b8);register_block(270206671u,b_101b06ce);register_block(270206691u,b_101b06e2);register_block(270206701u,b_101b06ec);register_block(270206707u,b_101b06f2);register_block(270206719u,b_101b06fe);register_block(270206723u,b_101b0702);register_block(270206727u,b_101b0706);register_block(270206743u,b_101b0716);register_block(270206753u,b_101b0720);register_block(270206761u,b_101b0728);register_block(270206769u,b_101b0730);register_block(270206777u,b_101b0738);register_block(270206785u,b_101b0740);register_block(270206793u,b_101b0748);register_block(270206799u,b_101b074e);register_block(270206801u,b_101b0750);register_block(270206805u,b_101b0754);register_block(270206807u,b_101b0756);register_block(270206811u,b_101b075a);register_block(270206813u,b_101b075c);register_block(270206817u,b_101b0760);register_block(270206821u,b_101b0764);register_block(270206823u,b_101b0766);register_block(270206829u,b_101b076c);register_block(270206831u,b_101b076e);register_block(270206837u,b_101b0774);register_block(270206839u,b_101b0776);register_block(270206845u,b_101b077c);register_block(270206851u,b_101b0782);register_block(270206853u,b_101b0784);register_block(270206859u,b_101b078a);register_block(270206865u,b_101b0790);register_block(270206867u,b_101b0792);register_block(270206879u,b_101b079e);register_block(270206897u,b_101b07b0);register_block(270206905u,b_101b07b8);register_block(270206917u,b_101b07c4);register_block(270206931u,b_101b07d2);register_block(270206939u,b_101b07da);register_block(270206941u,b_101b07dc);register_block(270206943u,b_101b07de);register_block(270206947u,b_101b07e2);register_block(270206955u,b_101b07ea);register_block(270206957u,b_101b07ec);register_block(270206967u,b_101b07f6);register_block(270206973u,b_101b07fc);register_block(270206987u,b_101b080a);register_block(270206993u,b_101b0810);register_block(270207003u,b_101b081a);register_block(270207009u,b_101b0820);register_block(270207011u,b_101b0822);register_block(270207013u,b_101b0824);register_block(270207025u,b_101b0830);register_block(270207033u,b_101b0838);register_block(270207043u,b_101b0842);register_block(270207053u,b_101b084c);register_block(270207061u,b_101b0854);register_block(270207069u,b_101b085c);register_block(270207073u,b_101b0860);register_block(270207077u,b_101b0864);register_block(270207079u,b_101b0866);register_block(270207081u,b_101b0868);register_block(270207087u,b_101b086e);register_block(270207097u,b_101b0878);register_block(270207107u,b_101b0882);register_block(270207109u,b_101b0884);register_block(270207111u,b_101b0886);register_block(270207117u,b_101b088c);register_block(270207127u,b_101b0896);register_block(270207135u,b_101b089e);register_block(270207141u,b_101b08a4);register_block(270207157u,b_101b08b4);register_block(270207169u,b_101b08c0);register_block(270207195u,b_101b08da);register_block(270207223u,b_101b08f6);register_block(270207229u,b_101b08fc);register_block(270207239u,b_101b0906);register_block(270207251u,b_101b0912);register_block(270207269u,b_101b0924);register_block(270207303u,b_101b0946);register_block(270207309u,b_101b094c);register_block(270207319u,b_101b0956);register_block(270207333u,b_101b0964);register_block(270207351u,b_101b0976);register_block(270207385u,b_101b0998);register_block(270207391u,b_101b099e);register_block(270207401u,b_101b09a8);register_block(270207415u,b_101b09b6);register_block(270207433u,b_101b09c8);register_block(270207469u,b_101b09ec);register_block(270207475u,b_101b09f2);register_block(270207489u,b_101b0a00);register_block(270207497u,b_101b0a08);register_block(270207501u,b_101b0a0c);register_block(270207505u,b_101b0a10);register_block(270207515u,b_101b0a1a);register_block(270207521u,b_101b0a20);register_block(270207537u,b_101b0a30);register_block(270207559u,b_101b0a46);register_block(270207573u,b_101b0a54);register_block(270207581u,b_101b0a5c);register_block(270207589u,b_101b0a64);register_block(270207597u,b_101b0a6c);register_block(270207605u,b_101b0a74);register_block(270207613u,b_101b0a7c);register_block(270207619u,b_101b0a82);register_block(270207625u,b_101b0a88);register_block(270207631u,b_101b0a8e);register_block(270207645u,b_101b0a9c);register_block(270207649u,b_101b0aa0);register_block(270207657u,b_101b0aa8);register_block(270207667u,b_101b0ab2);register_block(270207671u,b_101b0ab6);register_block(270207675u,b_101b0aba);register_block(270207697u,b_101b0ad0);register_block(270207705u,b_101b0ad8);register_block(270207717u,b_101b0ae4);register_block(270207725u,b_101b0aec);register_block(270207729u,b_101b0af0);register_block(270207731u,b_101b0af2);register_block(270207735u,b_101b0af6);register_block(270207737u,b_101b0af8);register_block(270207741u,b_101b0afc);register_block(270207743u,b_101b0afe);register_block(270207747u,b_101b0b02);register_block(270207751u,b_101b0b06);register_block(270207753u,b_101b0b08);register_block(270207759u,b_101b0b0e);register_block(270207761u,b_101b0b10);register_block(270207767u,b_101b0b16);register_block(270207773u,b_101b0b1c);register_block(270207775u,b_101b0b1e);register_block(270207781u,b_101b0b24);register_block(270207787u,b_101b0b2a);register_block(270207789u,b_101b0b2c);register_block(270207795u,b_101b0b32);register_block(270207801u,b_101b0b38);register_block(270207803u,b_101b0b3a);register_block(270207811u,b_101b0b42);register_block(270207813u,b_101b0b44);register_block(270207819u,b_101b0b4a);register_block(270207823u,b_101b0b4e);register_block(270207831u,b_101b0b56);register_block(270207839u,b_101b0b5e);register_block(270207843u,b_101b0b62);register_block(270207849u,b_101b0b68);register_block(270207859u,b_101b0b72);register_block(270207861u,b_101b0b74);register_block(270207869u,b_101b0b7c);register_block(270207875u,b_101b0b82);register_block(270207885u,b_101b0b8c);register_block(270207893u,b_101b0b94);register_block(270207915u,b_101b0baa);register_block(270207921u,b_101b0bb0);register_block(270207923u,b_101b0bb2);register_block(270207929u,b_101b0bb8);register_block(270207931u,b_101b0bba);register_block(270207935u,b_101b0bbe);register_block(270207941u,b_101b0bc4);register_block(270207943u,b_101b0bc6);register_block(270207951u,b_101b0bce);register_block(270207953u,b_101b0bd0);register_block(270207959u,b_101b0bd6);register_block(270207965u,b_101b0bdc);register_block(270207967u,b_101b0bde);register_block(270207971u,b_101b0be2);register_block(270207975u,b_101b0be6);register_block(270207983u,b_101b0bee);register_block(270207991u,b_101b0bf6);register_block(270208001u,b_101b0c00);register_block(270208007u,b_101b0c06);register_block(270208015u,b_101b0c0e);register_block(270208021u,b_101b0c14);register_block(270208027u,b_101b0c1a);register_block(270208031u,b_101b0c1e);register_block(270208033u,b_101b0c20);register_block(270208035u,b_101b0c22);register_block(270208041u,b_101b0c28);register_block(270208049u,b_101b0c30);register_block(270208055u,b_101b0c36);register_block(270208059u,b_101b0c3a);register_block(270208063u,b_101b0c3e);register_block(270208071u,b_101b0c46);register_block(270208077u,b_101b0c4c);register_block(270208081u,b_101b0c50);register_block(270208083u,b_101b0c52);register_block(270208089u,b_101b0c58);register_block(270208095u,b_101b0c5e);register_block(270208099u,b_101b0c62);register_block(270208105u,b_101b0c68);register_block(270208113u,b_101b0c70);register_block(270208119u,b_101b0c76);register_block(270208121u,b_101b0c78);register_block(270208125u,b_101b0c7c);register_block(270208131u,b_101b0c82);register_block(270208143u,b_101b0c8e);register_block(270208175u,b_101b0cae);register_block(270208177u,b_101b0cb0);register_block(270208189u,b_101b0cbc);register_block(270208203u,b_101b0cca);register_block(270208215u,b_101b0cd6);register_block(270208227u,b_101b0ce2);register_block(270208247u,b_101b0cf6);register_block(270208261u,b_101b0d04);register_block(270208273u,b_101b0d10);register_block(270208287u,b_101b0d1e);register_block(270208299u,b_101b0d2a);register_block(270208305u,b_101b0d30);register_block(270208323u,b_101b0d42);register_block(270208347u,b_101b0d5a);register_block(270208363u,b_101b0d6a);register_block(270208371u,b_101b0d72);register_block(270208379u,b_101b0d7a);register_block(270208387u,b_101b0d82);register_block(270208393u,b_101b0d88);register_block(270208399u,b_101b0d8e);register_block(270208405u,b_101b0d94);register_block(270208417u,b_101b0da0);register_block(270208421u,b_101b0da4);register_block(270208425u,b_101b0da8);register_block(270208433u,b_101b0db0);register_block(270208449u,b_101b0dc0);register_block(270208455u,b_101b0dc6);register_block(270208463u,b_101b0dce);register_block(270208485u,b_101b0de4);register_block(270208511u,b_101b0dfe);register_block(270208523u,b_101b0e0a);register_block(270208533u,b_101b0e14);register_block(270208535u,b_101b0e16);register_block(270208555u,b_101b0e2a);register_block(270208571u,b_101b0e3a);register_block(270208597u,b_101b0e54);register_block(270208601u,b_101b0e58);register_block(270208609u,b_101b0e60);register_block(270208615u,b_101b0e66);register_block(270208617u,b_101b0e68);register_block(270208623u,b_101b0e6e);register_block(270208625u,b_101b0e70);register_block(270208629u,b_101b0e74);register_block(270208633u,b_101b0e78);register_block(270208635u,b_101b0e7a);register_block(270208641u,b_101b0e80);register_block(270208647u,b_101b0e86);register_block(270208649u,b_101b0e88);register_block(270208655u,b_101b0e8e);register_block(270208657u,b_101b0e90);register_block(270208663u,b_101b0e96);register_block(270208669u,b_101b0e9c);register_block(270208671u,b_101b0e9e);register_block(270208677u,b_101b0ea4);register_block(270208683u,b_101b0eaa);register_block(270208685u,b_101b0eac);register_block(270208691u,b_101b0eb2);register_block(270208697u,b_101b0eb8);register_block(270208703u,b_101b0ebe);register_block(270208707u,b_101b0ec2);register_block(270208715u,b_101b0eca);register_block(270208741u,b_101b0ee4);register_block(270208753u,b_101b0ef0);register_block(270208763u,b_101b0efa);register_block(270208765u,b_101b0efc);register_block(270208771u,b_101b0f02);register_block(270208787u,b_101b0f12);register_block(270208795u,b_101b0f1a);register_block(270208801u,b_101b0f20);register_block(270208811u,b_101b0f2a);register_block(270208813u,b_101b0f2c);register_block(270208815u,b_101b0f2e);register_block(270208827u,b_101b0f3a);register_block(270208833u,b_101b0f40);register_block(270208839u,b_101b0f46);register_block(270208843u,b_101b0f4a);register_block(270208849u,b_101b0f50);register_block(270208857u,b_101b0f58);register_block(270208879u,b_101b0f6e);register_block(270208905u,b_101b0f88);register_block(270208917u,b_101b0f94);register_block(270208927u,b_101b0f9e);register_block(270208929u,b_101b0fa0);register_block(270208949u,b_101b0fb4);register_block(270208965u,b_101b0fc4);register_block(270209003u,b_101b0fea);register_block(270209037u,b_101b100c);register_block(270209039u,b_101b100e);register_block(270209047u,b_101b1016);register_block(270209051u,b_101b101a);register_block(270209065u,b_101b1028);register_block(270209107u,b_101b1052);register_block(270209123u,b_101b1062);register_block(270209157u,b_101b1084);register_block(270209189u,b_101b10a4);register_block(270209191u,b_101b10a6);register_block(270209193u,b_101b10a8);register_block(270209205u,b_101b10b4);register_block(270209211u,b_101b10ba);register_block(270209221u,b_101b10c4);register_block(270209231u,b_101b10ce);register_block(270209239u,b_101b10d6);register_block(270209245u,b_101b10dc);register_block(270209249u,b_101b10e0);register_block(270209257u,b_101b10e8);register_block(270209265u,b_101b10f0);register_block(270209267u,b_101b10f2);register_block(270209269u,b_101b10f4);register_block(270209273u,b_101b10f8);register_block(270209281u,b_101b1100);register_block(270209283u,b_101b1102);register_block(270209293u,b_101b110c);register_block(270209303u,b_101b1116);register_block(270209309u,b_101b111c);register_block(270209315u,b_101b1122);register_block(270209317u,b_101b1124);register_block(270209321u,b_101b1128);register_block(270209323u,b_101b112a);register_block(270209329u,b_101b1130);register_block(270209333u,b_101b1134);register_block(270209341u,b_101b113c);register_block(270209343u,b_101b113e);register_block(270209351u,b_101b1146);register_block(270209353u,b_101b1148);register_block(270209357u,b_101b114c);register_block(270209369u,b_101b1158);register_block(270209375u,b_101b115e);register_block(270209377u,b_101b1160);register_block(270209385u,b_101b1168);register_block(270209391u,b_101b116e);register_block(270209405u,b_101b117c);register_block(270209407u,b_101b117e);register_block(270209409u,b_101b1180);register_block(270209435u,b_101b119a);register_block(270209441u,b_101b11a0);register_block(270209449u,b_101b11a8);register_block(270209485u,b_101b11cc);register_block(270209521u,b_101b11f0);register_block(270209553u,b_101b1210);register_block(270209559u,b_101b1216);register_block(270209577u,b_101b1228);register_block(270209595u,b_101b123a);register_block(270209601u,b_101b1240);register_block(270209603u,b_101b1242);register_block(270209607u,b_101b1246);register_block(270209655u,b_101b1276);register_block(270209663u,b_101b127e);register_block(270209669u,b_101b1284);register_block(270209675u,b_101b128a);register_block(270209683u,b_101b1292);register_block(270209689u,b_101b1298);register_block(270209711u,b_101b12ae);register_block(270209717u,b_101b12b4);register_block(270209723u,b_101b12ba);register_block(270209729u,b_101b12c0);register_block(270209735u,b_101b12c6);register_block(270209739u,b_101b12ca);register_block(270209743u,b_101b12ce);register_block(270209817u,b_101b1318);register_block(270209869u,b_101b134c);register_block(270209921u,b_101b1380);register_block(270209969u,b_101b13b0);register_block(270209973u,b_101b13b4);register_block(270209977u,b_101b13b8);register_block(270209991u,b_101b13c6);register_block(270209993u,b_101b13c8);register_block(270209997u,b_101b13cc);register_block(270209999u,b_101b13ce);register_block(270210003u,b_101b13d2);register_block(270210007u,b_101b13d6);register_block(270210009u,b_101b13d8);register_block(270210013u,b_101b13dc);register_block(270210017u,b_101b13e0);register_block(270210019u,b_101b13e2);register_block(270210023u,b_101b13e6);register_block(270210025u,b_101b13e8);register_block(270210029u,b_101b13ec);register_block(270210033u,b_101b13f0);register_block(270210035u,b_101b13f2);register_block(270210039u,b_101b13f6);register_block(270210043u,b_101b13fa);register_block(270210045u,b_101b13fc);register_block(270210051u,b_101b1402);register_block(270210057u,b_101b1408);register_block(270210059u,b_101b140a);register_block(270210071u,b_101b1416);register_block(270210077u,b_101b141c);register_block(270210085u,b_101b1424);register_block(270210087u,b_101b1426);register_block(270210091u,b_101b142a);register_block(270210105u,b_101b1438);register_block(270210107u,b_101b143a);register_block(270210113u,b_101b1440);register_block(270210119u,b_101b1446);register_block(270210123u,b_101b144a);register_block(270210129u,b_101b1450);register_block(270210139u,b_101b145a);register_block(270210141u,b_101b145c);register_block(270210147u,b_101b1462);register_block(270210155u,b_101b146a);register_block(270210165u,b_101b1474);register_block(270210167u,b_101b1476);register_block(270210173u,b_101b147c);register_block(270210181u,b_101b1484);register_block(270210191u,b_101b148e);register_block(270210199u,b_101b1496);register_block(270210201u,b_101b1498);register_block(270210205u,b_101b149c);register_block(270210213u,b_101b14a4);register_block(270210215u,b_101b14a6);register_block(270210223u,b_101b14ae);register_block(270210231u,b_101b14b6);register_block(270210233u,b_101b14b8);register_block(270210245u,b_101b14c4);register_block(270210273u,b_101b14e0);register_block(270210289u,b_101b14f0);register_block(270210295u,b_101b14f6);register_block(270210301u,b_101b14fc);register_block(270210303u,b_101b14fe);register_block(270210315u,b_101b150a);register_block(270210325u,b_101b1514);register_block(270210335u,b_101b151e);register_block(270210349u,b_101b152c);register_block(270210353u,b_101b1530);register_block(270210361u,b_101b1538);register_block(270210363u,b_101b153a);register_block(270210411u,b_101b156a);register_block(270210429u,b_101b157c);register_block(270210447u,b_101b158e);register_block(270210469u,b_101b15a4);register_block(270210481u,b_101b15b0);register_block(270210487u,b_101b15b6);register_block(270210501u,b_101b15c4);register_block(270210505u,b_101b15c8);register_block(270210513u,b_101b15d0);register_block(270210523u,b_101b15da);register_block(270210527u,b_101b15de);register_block(270210531u,b_101b15e2);register_block(270210553u,b_101b15f8);register_block(270210561u,b_101b1600);register_block(270210571u,b_101b160a);register_block(270210579u,b_101b1612);register_block(270210587u,b_101b161a);register_block(270210595u,b_101b1622);register_block(270210603u,b_101b162a);register_block(270210611u,b_101b1632);register_block(270210617u,b_101b1638);register_block(270210619u,b_101b163a);register_block(270210623u,b_101b163e);register_block(270210625u,b_101b1640);register_block(270210629u,b_101b1644);register_block(270210631u,b_101b1646);register_block(270210635u,b_101b164a);register_block(270210641u,b_101b1650);register_block(270210643u,b_101b1652);register_block(270210649u,b_101b1658);register_block(270210651u,b_101b165a);register_block(270210657u,b_101b1660);register_block(270210659u,b_101b1662);register_block(270210665u,b_101b1668);register_block(270210671u,b_101b166e);register_block(270210673u,b_101b1670);register_block(270210675u,b_101b1672);register_block(270210687u,b_101b167e);register_block(270210695u,b_101b1686);register_block(270210697u,b_101b1688);register_block(270210699u,b_101b168a);register_block(270210711u,b_101b1696);register_block(270210729u,b_101b16a8);register_block(270210737u,b_101b16b0);register_block(270210749u,b_101b16bc);register_block(270210763u,b_101b16ca);register_block(270210771u,b_101b16d2);register_block(270210779u,b_101b16da);register_block(270210801u,b_101b16f0);register_block(270210809u,b_101b16f8);register_block(270210811u,b_101b16fa);register_block(270210819u,b_101b1702);register_block(270210821u,b_101b1704);register_block(270210823u,b_101b1706);register_block(270210829u,b_101b170c);register_block(270210851u,b_101b1722);register_block(270210857u,b_101b1728);register_block(270210859u,b_101b172a);register_block(270210865u,b_101b1730);register_block(270210877u,b_101b173c);register_block(270210885u,b_101b1744);register_block(270210893u,b_101b174c);register_block(270210903u,b_101b1756);register_block(270210909u,b_101b175c);register_block(270210917u,b_101b1764);register_block(270210921u,b_101b1768);register_block(270210927u,b_101b176e);register_block(270210929u,b_101b1770);register_block(270210935u,b_101b1776);register_block(270210943u,b_101b177e);register_block(270210947u,b_101b1782);register_block(270210951u,b_101b1786);register_block(270210953u,b_101b1788);register_block(270210955u,b_101b178a);register_block(270210961u,b_101b1790);register_block(270210969u,b_101b1798);register_block(270210995u,b_101b17b2);register_block(270211035u,b_101b17da);register_block(270211041u,b_101b17e0);register_block(270211043u,b_101b17e2);register_block(270211045u,b_101b17e4);register_block(270211049u,b_101b17e8);register_block(270211057u,b_101b17f0);register_block(270211059u,b_101b17f2);register_block(270211065u,b_101b17f8);register_block(270211071u,b_101b17fe);register_block(270211079u,b_101b1806);register_block(270211101u,b_101b181c);register_block(270211111u,b_101b1826);register_block(270211113u,b_101b1828);register_block(270211117u,b_101b182c);register_block(270211119u,b_101b182e);register_block(270211123u,b_101b1832);register_block(270211125u,b_101b1834);register_block(270211129u,b_101b1838);register_block(270211133u,b_101b183c);register_block(270211135u,b_101b183e);register_block(270211139u,b_101b1842);register_block(270211141u,b_101b1844);register_block(270211145u,b_101b1848);register_block(270211149u,b_101b184c);register_block(270211151u,b_101b184e);register_block(270211155u,b_101b1852);register_block(270211159u,b_101b1856);register_block(270211161u,b_101b1858);register_block(270211165u,b_101b185c);register_block(270211171u,b_101b1862);register_block(270211173u,b_101b1864);register_block(270211185u,b_101b1870);register_block(270211191u,b_101b1876);register_block(270211205u,b_101b1884);register_block(270211207u,b_101b1886);register_block(270211211u,b_101b188a);register_block(270211223u,b_101b1896);register_block(270211225u,b_101b1898);register_block(270211231u,b_101b189e);register_block(270211237u,b_101b18a4);register_block(270211245u,b_101b18ac);register_block(270211247u,b_101b18ae);register_block(270211253u,b_101b18b4);register_block(270211259u,b_101b18ba);register_block(270211263u,b_101b18be);register_block(270211277u,b_101b18cc);register_block(270211279u,b_101b18ce);register_block(270211285u,b_101b18d4);register_block(270211291u,b_101b18da);register_block(270211297u,b_101b18e0);register_block(270211301u,b_101b18e4);register_block(270211309u,b_101b18ec);register_block(270211315u,b_101b18f2);register_block(270211323u,b_101b18fa);register_block(270211329u,b_101b1900);register_block(270211335u,b_101b1906);register_block(270211345u,b_101b1910);register_block(270211353u,b_101b1918);register_block(270211365u,b_101b1924);register_block(270211367u,b_101b1926);register_block(270211371u,b_101b192a);register_block(270211373u,b_101b192c);register_block(270211377u,b_101b1930);register_block(270211379u,b_101b1932);register_block(270211383u,b_101b1936);register_block(270211387u,b_101b193a);register_block(270211389u,b_101b193c);register_block(270211393u,b_101b1940);register_block(270211395u,b_101b1942);register_block(270211399u,b_101b1946);register_block(270211401u,b_101b1948);register_block(270211405u,b_101b194c);register_block(270211409u,b_101b1950);register_block(270211411u,b_101b1952);register_block(270211415u,b_101b1956);register_block(270211421u,b_101b195c);register_block(270211423u,b_101b195e);register_block(270211427u,b_101b1962);register_block(270211439u,b_101b196e);register_block(270211445u,b_101b1974);register_block(270211459u,b_101b1982);register_block(270211461u,b_101b1984);register_block(270211467u,b_101b198a);register_block(270211473u,b_101b1990);register_block(270211477u,b_101b1994);register_block(270211491u,b_101b19a2);register_block(270211493u,b_101b19a4);register_block(270211499u,b_101b19aa);register_block(270211505u,b_101b19b0);register_block(270211517u,b_101b19bc);register_block(270211519u,b_101b19be);register_block(270211525u,b_101b19c4);register_block(270211531u,b_101b19ca);register_block(270211541u,b_101b19d4);register_block(270211543u,b_101b19d6);register_block(270211563u,b_101b19ea);register_block(270211573u,b_101b19f4);register_block(270211577u,b_101b19f8);register_block(270211587u,b_101b1a02);register_block(270211597u,b_101b1a0c);register_block(270211605u,b_101b1a14);register_block(270211621u,b_101b1a24);register_block(270211639u,b_101b1a36);register_block(270211651u,b_101b1a42);register_block(270211661u,b_101b1a4c);register_block(270211663u,b_101b1a4e);register_block(270211675u,b_101b1a5a);register_block(270211681u,b_101b1a60);register_block(270211709u,b_101b1a7c);register_block(270211717u,b_101b1a84);register_block(270211725u,b_101b1a8c);register_block(270211733u,b_101b1a94);register_block(270211743u,b_101b1a9e);register_block(270211745u,b_101b1aa0);register_block(270211747u,b_101b1aa2);register_block(270211753u,b_101b1aa8);register_block(270211757u,b_101b1aac);register_block(270211767u,b_101b1ab6);register_block(270211771u,b_101b1aba);register_block(270211781u,b_101b1ac4);register_block(270211817u,b_101b1ae8);register_block(270211835u,b_101b1afa);register_block(270211857u,b_101b1b10);register_block(270211863u,b_101b1b16);register_block(270211869u,b_101b1b1c);register_block(270211889u,b_101b1b30);register_block(270211897u,b_101b1b38);register_block(270211905u,b_101b1b40);register_block(270211913u,b_101b1b48);register_block(270211921u,b_101b1b50);register_block(270211929u,b_101b1b58);register_block(270211937u,b_101b1b60);register_block(270211947u,b_101b1b6a);register_block(270211959u,b_101b1b76);register_block(270211967u,b_101b1b7e);register_block(270211969u,b_101b1b80);register_block(270211973u,b_101b1b84);register_block(270211981u,b_101b1b8c);register_block(270211985u,b_101b1b90);register_block(270211995u,b_101b1b9a);register_block(270212003u,b_101b1ba2);register_block(270212009u,b_101b1ba8);register_block(270212015u,b_101b1bae);register_block(270212017u,b_101b1bb0);register_block(270212021u,b_101b1bb4);register_block(270212041u,b_101b1bc8);register_block(270212049u,b_101b1bd0);register_block(270212051u,b_101b1bd2);register_block(270212055u,b_101b1bd6);register_block(270212063u,b_101b1bde);register_block(270212095u,b_101b1bfe);register_block(270212101u,b_101b1c04);register_block(270212103u,b_101b1c06);register_block(270212137u,b_101b1c28);register_block(270212145u,b_101b1c30);register_block(270212161u,b_101b1c40);register_block(270212169u,b_101b1c48);register_block(270212171u,b_101b1c4a);register_block(270212177u,b_101b1c50);register_block(270212179u,b_101b1c52);register_block(270212187u,b_101b1c5a);register_block(270212193u,b_101b1c60);register_block(270212195u,b_101b1c62);register_block(270212203u,b_101b1c6a);register_block(270212209u,b_101b1c70);register_block(270212211u,b_101b1c72);register_block(270212219u,b_101b1c7a);register_block(270212225u,b_101b1c80);register_block(270212229u,b_101b1c84);register_block(270212235u,b_101b1c8a);register_block(270212237u,b_101b1c8c);register_block(270212243u,b_101b1c92);register_block(270212245u,b_101b1c94);register_block(270212251u,b_101b1c9a);register_block(270212255u,b_101b1c9e);register_block(270212261u,b_101b1ca4);register_block(270212263u,b_101b1ca6);register_block(270212267u,b_101b1caa);register_block(270212275u,b_101b1cb2);register_block(270212277u,b_101b1cb4);register_block(270212287u,b_101b1cbe);register_block(270212293u,b_101b1cc4);register_block(270212303u,b_101b1cce);register_block(270212305u,b_101b1cd0);register_block(270212309u,b_101b1cd4);register_block(270212315u,b_101b1cda);register_block(270212319u,b_101b1cde);register_block(270212321u,b_101b1ce0);register_block(270212323u,b_101b1ce2);register_block(270212329u,b_101b1ce8);register_block(270212333u,b_101b1cec);register_block(270212339u,b_101b1cf2);register_block(270212341u,b_101b1cf4);register_block(270212347u,b_101b1cfa);register_block(270212367u,b_101b1d0e);register_block(270212405u,b_101b1d34);register_block(270212439u,b_101b1d56);register_block(270212441u,b_101b1d58);register_block(270212449u,b_101b1d60);register_block(270212455u,b_101b1d66);register_block(270212463u,b_101b1d6e);register_block(270212465u,b_101b1d70);register_block(270212469u,b_101b1d74);register_block(270212477u,b_101b1d7c);register_block(270212483u,b_101b1d82);register_block(270212495u,b_101b1d8e);register_block(270212505u,b_101b1d98);register_block(270212507u,b_101b1d9a);register_block(270212509u,b_101b1d9c);register_block(270212513u,b_101b1da0);register_block(270212515u,b_101b1da2);register_block(270212527u,b_101b1dae);register_block(270212529u,b_101b1db0);register_block(270212533u,b_101b1db4);register_block(270212535u,b_101b1db6);register_block(270212547u,b_101b1dc2);register_block(270212553u,b_101b1dc8);register_block(270212565u,b_101b1dd4);register_block(270212597u,b_101b1df4);register_block(270212605u,b_101b1dfc);register_block(270212615u,b_101b1e06);register_block(270212621u,b_101b1e0c);register_block(270212625u,b_101b1e10);register_block(270212627u,b_101b1e12);register_block(270212631u,b_101b1e16);register_block(270212645u,b_101b1e24);register_block(270212647u,b_101b1e26);register_block(270212653u,b_101b1e2c);register_block(270212655u,b_101b1e2e);register_block(270212667u,b_101b1e3a);register_block(270212669u,b_101b1e3c);register_block(270212675u,b_101b1e42);register_block(270212679u,b_101b1e46);register_block(270212683u,b_101b1e4a);register_block(270212701u,b_101b1e5c);register_block(270212749u,b_101b1e8c);register_block(270212755u,b_101b1e92);register_block(270212759u,b_101b1e96);register_block(270212765u,b_101b1e9c);register_block(270212769u,b_101b1ea0);register_block(270212777u,b_101b1ea8);register_block(270212783u,b_101b1eae);register_block(270212793u,b_101b1eb8);register_block(270212795u,b_101b1eba);register_block(270212801u,b_101b1ec0);register_block(270212805u,b_101b1ec4);register_block(270212823u,b_101b1ed6);register_block(270212859u,b_101b1efa);register_block(270212867u,b_101b1f02);register_block(270212873u,b_101b1f08);register_block(270212879u,b_101b1f0e);register_block(270212881u,b_101b1f10);register_block(270212893u,b_101b1f1c);register_block(270212895u,b_101b1f1e);register_block(270212899u,b_101b1f22);register_block(270212929u,b_101b1f40);register_block(270212951u,b_101b1f56);register_block(270212971u,b_101b1f6a);register_block(270212995u,b_101b1f82);register_block(270213017u,b_101b1f98);register_block(270213039u,b_101b1fae);register_block(270213041u,b_101b1fb0);register_block(270213045u,b_101b1fb4);register_block(270213053u,b_101b1fbc);register_block(270213057u,b_101b1fc0);register_block(270213059u,b_101b1fc2);register_block(270213067u,b_101b1fca);register_block(270213097u,b_101b1fe8);register_block(270213099u,b_101b1fea);register_block(270213101u,b_101b1fec);register_block(270213113u,b_101b1ff8);register_block(270213127u,b_101b2006);register_block(270213141u,b_101b2014);register_block(270213143u,b_101b2016);register_block(270213149u,b_101b201c);register_block(270213151u,b_101b201e);register_block(270213181u,b_101b203c);register_block(270213203u,b_101b2052);register_block(270213223u,b_101b2066);register_block(270213247u,b_101b207e);register_block(270213269u,b_101b2094);register_block(270213291u,b_101b20aa);register_block(270213297u,b_101b20b0);register_block(270213299u,b_101b20b2);register_block(270213307u,b_101b20ba);register_block(270213313u,b_101b20c0);register_block(270213321u,b_101b20c8);register_block(270213333u,b_101b20d4);register_block(270213345u,b_101b20e0);register_block(270213375u,b_101b20fe);register_block(270213377u,b_101b2100);register_block(270213381u,b_101b2104);register_block(270213393u,b_101b2110);register_block(270213415u,b_101b2126);register_block(270213423u,b_101b212e);register_block(270213429u,b_101b2134);register_block(270213453u,b_101b214c);register_block(270213461u,b_101b2154);register_block(270213465u,b_101b2158);register_block(270213475u,b_101b2162);register_block(270213479u,b_101b2166);register_block(270213487u,b_101b216e);register_block(270213489u,b_101b2170);register_block(270213495u,b_101b2176);register_block(270213513u,b_101b2188);register_block(270213521u,b_101b2190);register_block(270213533u,b_101b219c);register_block(270213567u,b_101b21be);register_block(270213577u,b_101b21c8);register_block(270213591u,b_101b21d6);register_block(270213639u,b_101b2206);register_block(270213675u,b_101b222a);register_block(270213691u,b_101b223a);register_block(270213725u,b_101b225c);register_block(270213739u,b_101b226a);register_block(270213741u,b_101b226c);register_block(270213745u,b_101b2270);register_block(270213755u,b_101b227a);register_block(270213789u,b_101b229c);register_block(270213805u,b_101b22ac);register_block(270213809u,b_101b22b0);register_block(270213825u,b_101b22c0);register_block(270213833u,b_101b22c8);register_block(270213841u,b_101b22d0);register_block(270213845u,b_101b22d4);register_block(270213849u,b_101b22d8);register_block(270213859u,b_101b22e2);register_block(270213865u,b_101b22e8);register_block(270213877u,b_101b22f4);register_block(270213885u,b_101b22fc);register_block(270213893u,b_101b2304);register_block(270213897u,b_101b2308);register_block(270213899u,b_101b230a);register_block(270213903u,b_101b230e);register_block(270213905u,b_101b2310);register_block(270213909u,b_101b2314);register_block(270213913u,b_101b2318);register_block(270213917u,b_101b231c);register_block(270213921u,b_101b2320);register_block(270213925u,b_101b2324);register_block(270213931u,b_101b232a);register_block(270213933u,b_101b232c);register_block(270213937u,b_101b2330);register_block(270213941u,b_101b2334);register_block(270213945u,b_101b2338);register_block(270213951u,b_101b233e);register_block(270213957u,b_101b2344);register_block(270213961u,b_101b2348);register_block(270213963u,b_101b234a);register_block(270213975u,b_101b2356);register_block(270213985u,b_101b2360);register_block(270213987u,b_101b2362);register_block(270213999u,b_101b236e);register_block(270214005u,b_101b2374);register_block(270214013u,b_101b237c);register_block(270214021u,b_101b2384);register_block(270214023u,b_101b2386);register_block(270214035u,b_101b2392);register_block(270214037u,b_101b2394);register_block(270214043u,b_101b239a);register_block(270214053u,b_101b23a4);register_block(270214063u,b_101b23ae);register_block(270214065u,b_101b23b0);register_block(270214077u,b_101b23bc);register_block(270214079u,b_101b23be);register_block(270214085u,b_101b23c4);register_block(270214095u,b_101b23ce);register_block(270214105u,b_101b23d8);register_block(270214107u,b_101b23da);register_block(270214119u,b_101b23e6);register_block(270214121u,b_101b23e8);register_block(270214127u,b_101b23ee);register_block(270214137u,b_101b23f8);register_block(270214147u,b_101b2402);register_block(270214149u,b_101b2404);register_block(270214161u,b_101b2410);register_block(270214163u,b_101b2412);register_block(270214169u,b_101b2418);register_block(270214175u,b_101b241e);register_block(270214189u,b_101b242c);register_block(270214191u,b_101b242e);register_block(270214197u,b_101b2434);register_block(270214203u,b_101b243a);register_block(270214215u,b_101b2446);register_block(270214217u,b_101b2448);register_block(270214221u,b_101b244c);register_block(270214223u,b_101b244e);register_block(270214233u,b_101b2458);register_block(270214241u,b_101b2460);register_block(270214243u,b_101b2462);register_block(270214251u,b_101b246a);register_block(270214259u,b_101b2472);register_block(270214261u,b_101b2474);register_block(270214263u,b_101b2476);register_block(270214269u,b_101b247c);register_block(270214275u,b_101b2482);register_block(270214285u,b_101b248c);register_block(270214289u,b_101b2490);register_block(270214337u,b_101b24c0);register_block(270214361u,b_101b24d8);register_block(270214383u,b_101b24ee);register_block(270214407u,b_101b2506);register_block(270214429u,b_101b251c);register_block(270214451u,b_101b2532);register_block(270214473u,b_101b2548);register_block(270214487u,b_101b2556);register_block(270214493u,b_101b255c);register_block(270214501u,b_101b2564);register_block(270214511u,b_101b256e);register_block(270214531u,b_101b2582);register_block(270214565u,b_101b25a4);register_block(270214571u,b_101b25aa);register_block(270214581u,b_101b25b4);register_block(270214595u,b_101b25c2);register_block(270214613u,b_101b25d4);register_block(270214647u,b_101b25f6);register_block(270214653u,b_101b25fc);register_block(270214663u,b_101b2606);register_block(270214677u,b_101b2614);register_block(270214695u,b_101b2626);register_block(270214731u,b_101b264a);register_block(270214737u,b_101b2650);register_block(270214761u,b_101b2668);register_block(270214785u,b_101b2680);register_block(270214801u,b_101b2690);register_block(270214809u,b_101b2698);register_block(270214817u,b_101b26a0);register_block(270214825u,b_101b26a8);register_block(270214833u,b_101b26b0);register_block(270214841u,b_101b26b8);register_block(270214847u,b_101b26be);register_block(270214853u,b_101b26c4);register_block(270214865u,b_101b26d0);register_block(270214869u,b_101b26d4);register_block(270214873u,b_101b26d8);register_block(270214881u,b_101b26e0);register_block(270214899u,b_101b26f2);register_block(270214903u,b_101b26f6);register_block(270214907u,b_101b26fa);register_block(270214915u,b_101b2702);register_block(270214921u,b_101b2708);register_block(270214925u,b_101b270c);register_block(270214933u,b_101b2714);register_block(270214937u,b_101b2718);register_block(270214957u,b_101b272c);register_block(270214961u,b_101b2730);register_block(270214983u,b_101b2746);register_block(270214987u,b_101b274a);register_block(270215007u,b_101b275e);register_block(270215017u,b_101b2768);register_block(270215021u,b_101b276c);register_block(270215031u,b_101b2776);register_block(270215037u,b_101b277c);register_block(270215039u,b_101b277e);register_block(270215047u,b_101b2786);register_block(270215053u,b_101b278c);register_block(270215055u,b_101b278e);register_block(270215063u,b_101b2796);register_block(270215069u,b_101b279c);register_block(270215071u,b_101b279e);register_block(270215079u,b_101b27a6);register_block(270215081u,b_101b27a8);register_block(270215085u,b_101b27ac);register_block(270215095u,b_101b27b6);register_block(270215099u,b_101b27ba);register_block(270215117u,b_101b27cc);register_block(270215129u,b_101b27d8);register_block(270215133u,b_101b27dc);register_block(270215153u,b_101b27f0);register_block(270215159u,b_101b27f6);register_block(270215161u,b_101b27f8);register_block(270215165u,b_101b27fc);register_block(270215167u,b_101b27fe);register_block(270215171u,b_101b2802);register_block(270215175u,b_101b2806);register_block(270215177u,b_101b2808);register_block(270215181u,b_101b280c);register_block(270215187u,b_101b2812);register_block(270215189u,b_101b2814);register_block(270215195u,b_101b281a);register_block(270215197u,b_101b281c);register_block(270215203u,b_101b2822);register_block(270215209u,b_101b2828);register_block(270215211u,b_101b282a);register_block(270215217u,b_101b2830);register_block(270215223u,b_101b2836);register_block(270215225u,b_101b2838);register_block(270215231u,b_101b283e);register_block(270215237u,b_101b2844);register_block(270215243u,b_101b284a);register_block(270215245u,b_101b284c);register_block(270215257u,b_101b2858);register_block(270215273u,b_101b2868);register_block(270215275u,b_101b286a);register_block(270215287u,b_101b2876);register_block(270215293u,b_101b287c);register_block(270215301u,b_101b2884);register_block(270215307u,b_101b288a);register_block(270215311u,b_101b288e);register_block(270215327u,b_101b289e);register_block(270215357u,b_101b28bc);register_block(270215403u,b_101b28ea);register_block(270215465u,b_101b2928);register_block(270215487u,b_101b293e);register_block(270215511u,b_101b2956);register_block(270215517u,b_101b295c);register_block(270215519u,b_101b295e);register_block(270215521u,b_101b2960);register_block(270215525u,b_101b2964);register_block(270215541u,b_101b2974);register_block(270215545u,b_101b2978);register_block(270215549u,b_101b297c);register_block(270215565u,b_101b298c);register_block(270215599u,b_101b29ae);register_block(270215645u,b_101b29dc);register_block(270215707u,b_101b2a1a);register_block(270215729u,b_101b2a30);register_block(270215755u,b_101b2a4a);register_block(270215761u,b_101b2a50);register_block(270215763u,b_101b2a52);register_block(270215797u,b_101b2a74);register_block(270215807u,b_101b2a7e);register_block(270215827u,b_101b2a92);register_block(270215829u,b_101b2a94);register_block(270215841u,b_101b2aa0);register_block(270215843u,b_101b2aa2);register_block(270215849u,b_101b2aa8);register_block(270215855u,b_101b2aae);register_block(270215861u,b_101b2ab4);register_block(270215875u,b_101b2ac2);register_block(270215877u,b_101b2ac4);register_block(270215883u,b_101b2aca);register_block(270215893u,b_101b2ad4);register_block(270215899u,b_101b2ada);register_block(270215905u,b_101b2ae0);register_block(270215917u,b_101b2aec);register_block(270215929u,b_101b2af8);register_block(270215957u,b_101b2b14);register_block(270215979u,b_101b2b2a);register_block(270216003u,b_101b2b42);register_block(270216025u,b_101b2b58);register_block(270216049u,b_101b2b70);register_block(270216069u,b_101b2b84);register_block(270216075u,b_101b2b8a);register_block(270216083u,b_101b2b92);register_block(270216093u,b_101b2b9c);register_block(270216113u,b_101b2bb0);register_block(270216147u,b_101b2bd2);register_block(270216153u,b_101b2bd8);register_block(270216163u,b_101b2be2);register_block(270216177u,b_101b2bf0);register_block(270216195u,b_101b2c02);register_block(270216229u,b_101b2c24);register_block(270216235u,b_101b2c2a);register_block(270216245u,b_101b2c34);register_block(270216259u,b_101b2c42);register_block(270216277u,b_101b2c54);register_block(270216313u,b_101b2c78);register_block(270216319u,b_101b2c7e);register_block(270216321u,b_101b2c80);register_block(270216325u,b_101b2c84);register_block(270216331u,b_101b2c8a);register_block(270216345u,b_101b2c98);register_block(270216347u,b_101b2c9a);register_block(270216351u,b_101b2c9e);register_block(270216355u,b_101b2ca2);register_block(270216361u,b_101b2ca8);register_block(270216365u,b_101b2cac);register_block(270216393u,b_101b2cc8);register_block(270216411u,b_101b2cda);register_block(270216431u,b_101b2cee);register_block(270216449u,b_101b2d00);register_block(270216469u,b_101b2d14);register_block(270216477u,b_101b2d1c);register_block(270216493u,b_101b2d2c);register_block(270216513u,b_101b2d40);register_block(270216525u,b_101b2d4c);register_block(270216537u,b_101b2d58);register_block(270216549u,b_101b2d64);register_block(270216569u,b_101b2d78);register_block(270216571u,b_101b2d7a);register_block(270216583u,b_101b2d86);register_block(270216587u,b_101b2d8a);register_block(270216603u,b_101b2d9a);register_block(270216623u,b_101b2dae);register_block(270216631u,b_101b2db6);register_block(270216635u,b_101b2dba);register_block(270216637u,b_101b2dbc);register_block(270216641u,b_101b2dc0);register_block(270216643u,b_101b2dc2);register_block(270216647u,b_101b2dc6);register_block(270216651u,b_101b2dca);register_block(270216655u,b_101b2dce);register_block(270216659u,b_101b2dd2);register_block(270216663u,b_101b2dd6);register_block(270216667u,b_101b2dda);register_block(270216669u,b_101b2ddc);register_block(270216673u,b_101b2de0);register_block(270216677u,b_101b2de4);register_block(270216681u,b_101b2de8);register_block(270216685u,b_101b2dec);register_block(270216691u,b_101b2df2);register_block(270216697u,b_101b2df8);register_block(270216709u,b_101b2e04);register_block(270216747u,b_101b2e2a);register_block(270216763u,b_101b2e3a);register_block(270216769u,b_101b2e40);register_block(270216781u,b_101b2e4c);register_block(270216787u,b_101b2e52);register_block(270216807u,b_101b2e66);register_block(270216809u,b_101b2e68);register_block(270216821u,b_101b2e74);register_block(270216833u,b_101b2e80);register_block(270216841u,b_101b2e88);register_block(270216845u,b_101b2e8c);register_block(270216853u,b_101b2e94);register_block(270216855u,b_101b2e96);register_block(270216857u,b_101b2e98);register_block(270216863u,b_101b2e9e);register_block(270216871u,b_101b2ea6);register_block(270216883u,b_101b2eb2);register_block(270216891u,b_101b2eba);register_block(270216893u,b_101b2ebc);register_block(270216897u,b_101b2ec0);register_block(270216901u,b_101b2ec4);register_block(270216909u,b_101b2ecc);register_block(270216911u,b_101b2ece);register_block(270216919u,b_101b2ed6);register_block(270216921u,b_101b2ed8);register_block(270216923u,b_101b2eda);register_block(270216929u,b_101b2ee0);register_block(270216935u,b_101b2ee6);register_block(270216945u,b_101b2ef0);register_block(270216951u,b_101b2ef6);register_block(270216961u,b_101b2f00);register_block(270216967u,b_101b2f06);register_block(270216975u,b_101b2f0e);register_block(270216985u,b_101b2f18);register_block(270216991u,b_101b2f1e);register_block(270217001u,b_101b2f28);register_block(270217007u,b_101b2f2e);register_block(270217015u,b_101b2f36);register_block(270217025u,b_101b2f40);register_block(270217033u,b_101b2f48);register_block(270217035u,b_101b2f4a);register_block(270217041u,b_101b2f50);register_block(270217085u,b_101b2f7c);register_block(270217119u,b_101b2f9e);register_block(270217125u,b_101b2fa4);register_block(270217133u,b_101b2fac);register_block(270217143u,b_101b2fb6);register_block(270217163u,b_101b2fca);register_block(270217197u,b_101b2fec);register_block(270217203u,b_101b2ff2);register_block(270217213u,b_101b2ffc);register_block(270217227u,b_101b300a);register_block(270217245u,b_101b301c);register_block(270217279u,b_101b303e);register_block(270217285u,b_101b3044);register_block(270217295u,b_101b304e);register_block(270217309u,b_101b305c);register_block(270217327u,b_101b306e);register_block(270217363u,b_101b3092);register_block(270217369u,b_101b3098);register_block(270217389u,b_101b30ac);register_block(270217417u,b_101b30c8);register_block(270217427u,b_101b30d2);register_block(270217441u,b_101b30e0);register_block(270217481u,b_101b3108);register_block(270217483u,b_101b310a);register_block(270217497u,b_101b3118);register_block(270217507u,b_101b3122);register_block(270217519u,b_101b312e);register_block(270217525u,b_101b3134);register_block(270217531u,b_101b313a);register_block(270217541u,b_101b3144);register_block(270217547u,b_101b314a);register_block(270217551u,b_101b314e);register_block(270217553u,b_101b3150);register_block(270217557u,b_101b3154);register_block(270217559u,b_101b3156);register_block(270217563u,b_101b315a);register_block(270217567u,b_101b315e);register_block(270217569u,b_101b3160);register_block(270217573u,b_101b3164);register_block(270217579u,b_101b316a);register_block(270217581u,b_101b316c);register_block(270217587u,b_101b3172);register_block(270217589u,b_101b3174);register_block(270217595u,b_101b317a);register_block(270217601u,b_101b3180);register_block(270217603u,b_101b3182);register_block(270217609u,b_101b3188);register_block(270217615u,b_101b318e);register_block(270217621u,b_101b3194);register_block(270217633u,b_101b31a0);register_block(270217675u,b_101b31ca);register_block(270217685u,b_101b31d4);register_block(270217703u,b_101b31e6);register_block(270217709u,b_101b31ec);register_block(270217715u,b_101b31f2);register_block(270217717u,b_101b31f4);register_block(270217723u,b_101b31fa);register_block(270217727u,b_101b31fe);register_block(270217729u,b_101b3200);register_block(270217735u,b_101b3206);register_block(270217737u,b_101b3208);register_block(270217739u,b_101b320a);register_block(270217745u,b_101b3210);register_block(270217747u,b_101b3212);register_block(270217753u,b_101b3218);register_block(270217759u,b_101b321e);register_block(270217769u,b_101b3228);register_block(270217777u,b_101b3230);register_block(270217779u,b_101b3232);register_block(270217781u,b_101b3234);register_block(270217787u,b_101b323a);register_block(270217789u,b_101b323c);register_block(270217795u,b_101b3242);register_block(270217799u,b_101b3246);register_block(270217807u,b_101b324e);register_block(270217817u,b_101b3258);register_block(270217821u,b_101b325c);register_block(270217823u,b_101b325e);register_block(270217829u,b_101b3264);register_block(270217831u,b_101b3266);register_block(270217837u,b_101b326c);register_block(270217841u,b_101b3270);register_block(270217849u,b_101b3278);register_block(270217859u,b_101b3282);register_block(270217861u,b_101b3284);register_block(270217865u,b_101b3288);register_block(270217875u,b_101b3292);register_block(270217885u,b_101b329c);register_block(270217887u,b_101b329e);register_block(270217889u,b_101b32a0);register_block(270217895u,b_101b32a6);register_block(270217897u,b_101b32a8);register_block(270217903u,b_101b32ae);register_block(270217909u,b_101b32b4);register_block(270217915u,b_101b32ba);register_block(270217925u,b_101b32c4);register_block(270217931u,b_101b32ca);register_block(270217959u,b_101b32e6);register_block(270217965u,b_101b32ec);register_block(270217979u,b_101b32fa);register_block(270217981u,b_101b32fc);register_block(270217993u,b_101b3308);register_block(270217995u,b_101b330a);register_block(270218005u,b_101b3314);register_block(270218013u,b_101b331c);register_block(270218019u,b_101b3322);register_block(270218021u,b_101b3324);register_block(270218023u,b_101b3326);register_block(270218029u,b_101b332c);register_block(270218039u,b_101b3336);register_block(270218051u,b_101b3342);register_block(270218059u,b_101b334a);register_block(270218065u,b_101b3350);register_block(270218069u,b_101b3354);register_block(270218073u,b_101b3358);register_block(270218081u,b_101b3360);register_block(270218083u,b_101b3362);register_block(270218085u,b_101b3364);register_block(270218091u,b_101b336a);register_block(270218095u,b_101b336e);register_block(270218099u,b_101b3372);register_block(270218111u,b_101b337e);register_block(270218119u,b_101b3386);register_block(270218121u,b_101b3388);register_block(270218129u,b_101b3390);register_block(270218161u,b_101b33b0);register_block(270218183u,b_101b33c6);register_block(270218207u,b_101b33de);register_block(270218229u,b_101b33f4);register_block(270218251u,b_101b340a);register_block(270218257u,b_101b3410);register_block(270218265u,b_101b3418);register_block(270218269u,b_101b341c);register_block(270218279u,b_101b3426);register_block(270218287u,b_101b342e);register_block(270218297u,b_101b3438);register_block(270218317u,b_101b344c);register_block(270218337u,b_101b3460);register_block(270218343u,b_101b3466);register_block(270218351u,b_101b346e);register_block(270218361u,b_101b3478);register_block(270218373u,b_101b3484);register_block(270218393u,b_101b3498);register_block(270218399u,b_101b349e);register_block(270218407u,b_101b34a6);register_block(270218417u,b_101b34b0);register_block(270218429u,b_101b34bc);register_block(270218449u,b_101b34d0);register_block(270218469u,b_101b34e4);register_block(270218527u,b_101b351e);register_block(270218555u,b_101b353a);register_block(270218577u,b_101b3550);register_block(270218593u,b_101b3560);register_block(270218599u,b_101b3566);register_block(270218607u,b_101b356e);register_block(270218617u,b_101b3578);register_block(270218637u,b_101b358c);register_block(270218671u,b_101b35ae);register_block(270218677u,b_101b35b4);register_block(270218687u,b_101b35be);register_block(270218701u,b_101b35cc);register_block(270218719u,b_101b35de);register_block(270218753u,b_101b3600);register_block(270218759u,b_101b3606);register_block(270218769u,b_101b3610);register_block(270218783u,b_101b361e);register_block(270218801u,b_101b3630);register_block(270218837u,b_101b3654);register_block(270218843u,b_101b365a);register_block(270218861u,b_101b366c);register_block(270218883u,b_101b3682);register_block(270218897u,b_101b3690);register_block(270218913u,b_101b36a0);register_block(270218921u,b_101b36a8);register_block(270218929u,b_101b36b0);register_block(270218933u,b_101b36b4);register_block(270218945u,b_101b36c0);register_block(270218949u,b_101b36c4);register_block(270218963u,b_101b36d2);register_block(270218967u,b_101b36d6);register_block(270218979u,b_101b36e2);register_block(270218999u,b_101b36f6);register_block(270219013u,b_101b3704);register_block(270219023u,b_101b370e);register_block(270219033u,b_101b3718);register_block(270219045u,b_101b3724);register_block(270219051u,b_101b372a);register_block(270219057u,b_101b3730);register_block(270219067u,b_101b373a);register_block(270219073u,b_101b3740);register_block(270219077u,b_101b3744);register_block(270219079u,b_101b3746);register_block(270219083u,b_101b374a);register_block(270219085u,b_101b374c);register_block(270219089u,b_101b3750);register_block(270219091u,b_101b3752);register_block(270219095u,b_101b3756);register_block(270219099u,b_101b375a);register_block(270219101u,b_101b375c);register_block(270219107u,b_101b3762);register_block(270219109u,b_101b3764);register_block(270219113u,b_101b3768);register_block(270219119u,b_101b376e);register_block(270219121u,b_101b3770);register_block(270219127u,b_101b3776);register_block(270219133u,b_101b377c);register_block(270219135u,b_101b377e);register_block(270219141u,b_101b3784);register_block(270219143u,b_101b3786);register_block(270219151u,b_101b378e);register_block(270219157u,b_101b3794);register_block(270219163u,b_101b379a);register_block(270219165u,b_101b379c);register_block(270219169u,b_101b37a0);register_block(270219171u,b_101b37a2);register_block(270219177u,b_101b37a8);register_block(270219179u,b_101b37aa);register_block(270219185u,b_101b37b0);register_block(270219191u,b_101b37b6);register_block(270219193u,b_101b37b8);register_block(270219203u,b_101b37c2);register_block(270219213u,b_101b37cc);register_block(270219215u,b_101b37ce);register_block(270219223u,b_101b37d6);register_block(270219229u,b_101b37dc);register_block(270219233u,b_101b37e0);register_block(270219241u,b_101b37e8);register_block(270219243u,b_101b37ea);register_block(270219249u,b_101b37f0);register_block(270219255u,b_101b37f6);register_block(270219259u,b_101b37fa);register_block(270219269u,b_101b3804);register_block(270219275u,b_101b380a);register_block(270219279u,b_101b380e);register_block(270219287u,b_101b3816);register_block(270219293u,b_101b381c);register_block(270219307u,b_101b382a);register_block(270219315u,b_101b3832);register_block(270219321u,b_101b3838);register_block(270219327u,b_101b383e);register_block(270219339u,b_101b384a);register_block(270219341u,b_101b384c);register_block(270219349u,b_101b3854);register_block(270219351u,b_101b3856);register_block(270219357u,b_101b385c);register_block(270219361u,b_101b3860);register_block(270219369u,b_101b3868);register_block(270219383u,b_101b3876);register_block(270219385u,b_101b3878);register_block(270219387u,b_101b387a);register_block(270219399u,b_101b3886);register_block(270219407u,b_101b388e);register_block(270219409u,b_101b3890);register_block(270219417u,b_101b3898);register_block(270219425u,b_101b38a0);register_block(270219427u,b_101b38a2);register_block(270219439u,b_101b38ae);register_block(270219467u,b_101b38ca);register_block(270219487u,b_101b38de);register_block(270219503u,b_101b38ee);register_block(270219509u,b_101b38f4);register_block(270219517u,b_101b38fc);register_block(270219523u,b_101b3902);register_block(270219527u,b_101b3906);register_block(270219555u,b_101b3922);register_block(270219575u,b_101b3936);register_block(270219589u,b_101b3944);register_block(270219595u,b_101b394a);register_block(270219609u,b_101b3958);register_block(270219619u,b_101b3962);register_block(270219653u,b_101b3984);register_block(270219671u,b_101b3996);register_block(270219693u,b_101b39ac);register_block(270219707u,b_101b39ba);register_block(270219715u,b_101b39c2);register_block(270219723u,b_101b39ca);register_block(270219731u,b_101b39d2);register_block(270219739u,b_101b39da);register_block(270219745u,b_101b39e0);register_block(270219751u,b_101b39e6);register_block(270219757u,b_101b39ec);register_block(270219771u,b_101b39fa);register_block(270219775u,b_101b39fe);register_block(270219783u,b_101b3a06);register_block(270219793u,b_101b3a10);register_block(270219797u,b_101b3a14);register_block(270219801u,b_101b3a18);register_block(270219823u,b_101b3a2e);register_block(270219831u,b_101b3a36);register_block(270219837u,b_101b3a3c);register_block(270219855u,b_101b3a4e);register_block(270219861u,b_101b3a54);register_block(270219867u,b_101b3a5a);register_block(270219873u,b_101b3a60);register_block(270219879u,b_101b3a66);register_block(270219885u,b_101b3a6c);register_block(270219889u,b_101b3a70);register_block(270219907u,b_101b3a82);register_block(270219927u,b_101b3a96);register_block(270219941u,b_101b3aa4);register_block(270219943u,b_101b3aa6);register_block(270219963u,b_101b3aba);register_block(270219977u,b_101b3ac8);register_block(270219983u,b_101b3ace);register_block(270219985u,b_101b3ad0);register_block(270219989u,b_101b3ad4);register_block(270219999u,b_101b3ade);register_block(270220001u,b_101b3ae0);register_block(270220009u,b_101b3ae8);register_block(270220015u,b_101b3aee);register_block(270220017u,b_101b3af0);register_block(270220025u,b_101b3af8);register_block(270220031u,b_101b3afe);register_block(270220033u,b_101b3b00);register_block(270220041u,b_101b3b08);register_block(270220061u,b_101b3b1c);register_block(270220067u,b_101b3b22);register_block(270220073u,b_101b3b28);register_block(270220075u,b_101b3b2a);register_block(270220081u,b_101b3b30);register_block(270220083u,b_101b3b32);register_block(270220087u,b_101b3b36);register_block(270220091u,b_101b3b3a);register_block(270220093u,b_101b3b3c);register_block(270220099u,b_101b3b42);register_block(270220105u,b_101b3b48);register_block(270220107u,b_101b3b4a);register_block(270220113u,b_101b3b50);register_block(270220115u,b_101b3b52);register_block(270220121u,b_101b3b58);register_block(270220127u,b_101b3b5e);register_block(270220129u,b_101b3b60);register_block(270220135u,b_101b3b66);register_block(270220141u,b_101b3b6c);register_block(270220143u,b_101b3b6e);register_block(270220147u,b_101b3b72);register_block(270220151u,b_101b3b76);register_block(270220167u,b_101b3b86);register_block(270220185u,b_101b3b98);register_block(270220197u,b_101b3ba4);register_block(270220207u,b_101b3bae);register_block(270220209u,b_101b3bb0);register_block(270220221u,b_101b3bbc);register_block(270220227u,b_101b3bc2);register_block(270220255u,b_101b3bde);register_block(270220269u,b_101b3bec);register_block(270220277u,b_101b3bf4);register_block(270220285u,b_101b3bfc);register_block(270220289u,b_101b3c00);register_block(270220291u,b_101b3c02);register_block(270220295u,b_101b3c06);register_block(270220297u,b_101b3c08);register_block(270220303u,b_101b3c0e);register_block(270220309u,b_101b3c14);register_block(270220317u,b_101b3c1c);register_block(270220319u,b_101b3c1e);register_block(270220323u,b_101b3c22);register_block(270220335u,b_101b3c2e);register_block(270220347u,b_101b3c3a);register_block(270220359u,b_101b3c46);register_block(270220391u,b_101b3c66);register_block(270220393u,b_101b3c68);register_block(270220399u,b_101b3c6e);register_block(270220403u,b_101b3c72);register_block(270220407u,b_101b3c76);register_block(270220415u,b_101b3c7e);register_block(270220421u,b_101b3c84);register_block(270220433u,b_101b3c90);register_block(270220439u,b_101b3c96);register_block(270220445u,b_101b3c9c);register_block(270220447u,b_101b3c9e);register_block(270220455u,b_101b3ca6);register_block(270220463u,b_101b3cae);register_block(270220473u,b_101b3cb8);register_block(270220475u,b_101b3cba);register_block(270220477u,b_101b3cbc);register_block(270220483u,b_101b3cc2);register_block(270220491u,b_101b3cca);register_block(270220501u,b_101b3cd4);register_block(270220503u,b_101b3cd6);register_block(270220505u,b_101b3cd8);register_block(270220511u,b_101b3cde);register_block(270220517u,b_101b3ce4);register_block(270220523u,b_101b3cea);register_block(270220525u,b_101b3cec);register_block(270220529u,b_101b3cf0);register_block(270220537u,b_101b3cf8);register_block(270220539u,b_101b3cfa);register_block(270220547u,b_101b3d02);register_block(270220551u,b_101b3d06);register_block(270220575u,b_101b3d1e);register_block(270220577u,b_101b3d20);register_block(270220583u,b_101b3d26);register_block(270220589u,b_101b3d2c);register_block(270220601u,b_101b3d38);register_block(270220609u,b_101b3d40);register_block(270220617u,b_101b3d48);register_block(270220619u,b_101b3d4a);register_block(270220631u,b_101b3d56);register_block(270220643u,b_101b3d62);register_block(270220659u,b_101b3d72);register_block(270220661u,b_101b3d74);register_block(270220673u,b_101b3d80);register_block(270220713u,b_101b3da8);register_block(270220725u,b_101b3db4);register_block(270220743u,b_101b3dc6);register_block(270220765u,b_101b3ddc);register_block(270220783u,b_101b3dee);register_block(270220791u,b_101b3df6);register_block(270220797u,b_101b3dfc);register_block(270220803u,b_101b3e02);register_block(270220809u,b_101b3e08);register_block(270220823u,b_101b3e16);register_block(270220827u,b_101b3e1a);register_block(270220835u,b_101b3e22);register_block(270220845u,b_101b3e2c);register_block(270220849u,b_101b3e30);register_block(270220853u,b_101b3e34);register_block(270220875u,b_101b3e4a);register_block(270220883u,b_101b3e52);register_block(270220891u,b_101b3e5a);register_block(270220911u,b_101b3e6e);register_block(270220919u,b_101b3e76);register_block(270220921u,b_101b3e78);register_block(270220925u,b_101b3e7c);register_block(270220933u,b_101b3e84);register_block(270220965u,b_101b3ea4);register_block(270220971u,b_101b3eaa);register_block(270220973u,b_101b3eac);register_block(270220995u,b_101b3ec2);register_block(270221001u,b_101b3ec8);register_block(270221003u,b_101b3eca);register_block(270221007u,b_101b3ece);register_block(270221009u,b_101b3ed0);register_block(270221013u,b_101b3ed4);register_block(270221015u,b_101b3ed6);register_block(270221021u,b_101b3edc);register_block(270221027u,b_101b3ee2);register_block(270221029u,b_101b3ee4);register_block(270221035u,b_101b3eea);register_block(270221037u,b_101b3eec);register_block(270221043u,b_101b3ef2);register_block(270221049u,b_101b3ef8);register_block(270221051u,b_101b3efa);register_block(270221057u,b_101b3f00);register_block(270221063u,b_101b3f06);register_block(270221069u,b_101b3f0c);register_block(270221071u,b_101b3f0e);register_block(270221077u,b_101b3f14);register_block(270221083u,b_101b3f1a);register_block(270221085u,b_101b3f1c);register_block(270221097u,b_101b3f28);register_block(270221111u,b_101b3f36);register_block(270221123u,b_101b3f42);register_block(270221155u,b_101b3f62);register_block(270221157u,b_101b3f64);register_block(270221165u,b_101b3f6c);register_block(270221169u,b_101b3f70);register_block(270221189u,b_101b3f84);register_block(270221197u,b_101b3f8c);register_block(270221199u,b_101b3f8e);register_block(270221203u,b_101b3f92);register_block(270221211u,b_101b3f9a);register_block(270221233u,b_101b3fb0);register_block(270221249u,b_101b3fc0);register_block(270221251u,b_101b3fc2);register_block(270221289u,b_101b3fe8);register_block(270221323u,b_101b400a);register_block(270221325u,b_101b400c);register_block(270221335u,b_101b4016);register_block(270221337u,b_101b4018);register_block(270221341u,b_101b401c);register_block(270221349u,b_101b4024);register_block(270221351u,b_101b4026);register_block(270221353u,b_101b4028);register_block(270221365u,b_101b4034);register_block(270221373u,b_101b403c);register_block(270221375u,b_101b403e);register_block(270221381u,b_101b4044);register_block(270221391u,b_101b404e);register_block(270221393u,b_101b4050);register_block(270221395u,b_101b4052);register_block(270221401u,b_101b4058);register_block(270221407u,b_101b405e);register_block(270221413u,b_101b4064);register_block(270221427u,b_101b4072);register_block(270221453u,b_101b408c);register_block(270221459u,b_101b4092);register_block(270221463u,b_101b4096);register_block(270221469u,b_101b409c);register_block(270221477u,b_101b40a4);register_block(270221485u,b_101b40ac);register_block(270221491u,b_101b40b2);register_block(270221503u,b_101b40be);register_block(270221515u,b_101b40ca);register_block(270221537u,b_101b40e0);register_block(270221541u,b_101b40e4);register_block(270221549u,b_101b40ec);register_block(270221557u,b_101b40f4);register_block(270221577u,b_101b4108);register_block(270221581u,b_101b410c);register_block(270221595u,b_101b411a);register_block(270221597u,b_101b411c);register_block(270221601u,b_101b4120);register_block(270221603u,b_101b4122);register_block(270221607u,b_101b4126);register_block(270221609u,b_101b4128);register_block(270221613u,b_101b412c);register_block(270221617u,b_101b4130);register_block(270221619u,b_101b4132);register_block(270221623u,b_101b4136);register_block(270221625u,b_101b4138);register_block(270221629u,b_101b413c);register_block(270221633u,b_101b4140);register_block(270221635u,b_101b4142);register_block(270221639u,b_101b4146);register_block(270221643u,b_101b414a);register_block(270221645u,b_101b414c);register_block(270221649u,b_101b4150);register_block(270221655u,b_101b4156);register_block(270221657u,b_101b4158);register_block(270221669u,b_101b4164);register_block(270221675u,b_101b416a);register_block(270221683u,b_101b4172);register_block(270221685u,b_101b4174);register_block(270221689u,b_101b4178);register_block(270221703u,b_101b4186);register_block(270221705u,b_101b4188);register_block(270221711u,b_101b418e);register_block(270221713u,b_101b4190);register_block(270221719u,b_101b4196);register_block(270221727u,b_101b419e);register_block(270221737u,b_101b41a8);register_block(270221739u,b_101b41aa);register_block(270221751u,b_101b41b6);register_block(270221753u,b_101b41b8);register_block(270221759u,b_101b41be);register_block(270221765u,b_101b41c4);register_block(270221771u,b_101b41ca);register_block(270221781u,b_101b41d4);register_block(270221783u,b_101b41d6);register_block(270221789u,b_101b41dc);register_block(270221795u,b_101b41e2);register_block(270221809u,b_101b41f0);register_block(270221811u,b_101b41f2);register_block(270221823u,b_101b41fe);register_block(270221849u,b_101b4218);register_block(270221851u,b_101b421a);register_block(270221857u,b_101b4220);register_block(270221865u,b_101b4228);register_block(270221877u,b_101b4234);register_block(270221885u,b_101b423c);register_block(270221941u,b_101b4274);register_block(270221947u,b_101b427a);register_block(270221955u,b_101b4282);register_block(270221965u,b_101b428c);register_block(270221985u,b_101b42a0);register_block(270222019u,b_101b42c2);register_block(270222025u,b_101b42c8);register_block(270222035u,b_101b42d2);register_block(270222049u,b_101b42e0);register_block(270222067u,b_101b42f2);register_block(270222101u,b_101b4314);register_block(270222107u,b_101b431a);register_block(270222117u,b_101b4324);register_block(270222131u,b_101b4332);register_block(270222149u,b_101b4344);register_block(270222185u,b_101b4368);register_block(270222191u,b_101b436e);register_block(270222209u,b_101b4380);register_block(270222229u,b_101b4394);register_block(270222241u,b_101b43a0);register_block(270222245u,b_101b43a4);register_block(270222247u,b_101b43a6);register_block(270222251u,b_101b43aa);register_block(270222253u,b_101b43ac);register_block(270222257u,b_101b43b0);register_block(270222259u,b_101b43b2);register_block(270222263u,b_101b43b6);register_block(270222267u,b_101b43ba);register_block(270222269u,b_101b43bc);register_block(270222273u,b_101b43c0);register_block(270222275u,b_101b43c2);register_block(270222279u,b_101b43c6);register_block(270222283u,b_101b43ca);register_block(270222285u,b_101b43cc);register_block(270222289u,b_101b43d0);register_block(270222295u,b_101b43d6);register_block(270222301u,b_101b43dc);register_block(270222313u,b_101b43e8);register_block(270222355u,b_101b4412);register_block(270222365u,b_101b441c);register_block(270222383u,b_101b442e);register_block(270222387u,b_101b4432);register_block(270222393u,b_101b4438);register_block(270222395u,b_101b443a);register_block(270222399u,b_101b443e);register_block(270222417u,b_101b4450);register_block(270222425u,b_101b4458);register_block(270222443u,b_101b446a);register_block(270222445u,b_101b446c);register_block(270222451u,b_101b4472);register_block(270222453u,b_101b4474);register_block(270222459u,b_101b447a);register_block(270222467u,b_101b4482);register_block(270222487u,b_101b4496);register_block(270222489u,b_101b4498);register_block(270222501u,b_101b44a4);register_block(270222527u,b_101b44be);register_block(270222545u,b_101b44d0);register_block(270222551u,b_101b44d6);register_block(270222567u,b_101b44e6);register_block(270222577u,b_101b44f0);register_block(270222587u,b_101b44fa);register_block(270222601u,b_101b4508);register_block(270222605u,b_101b450c);register_block(270222613u,b_101b4514);register_block(270222615u,b_101b4516);register_block(270222663u,b_101b4546);register_block(270222681u,b_101b4558);register_block(270222715u,b_101b457a);register_block(270222735u,b_101b458e);register_block(270222755u,b_101b45a2);register_block(270222773u,b_101b45b4);register_block(270222791u,b_101b45c6);register_block(270222809u,b_101b45d8);register_block(270222827u,b_101b45ea);register_block(270222845u,b_101b45fc);register_block(270222865u,b_101b4610);register_block(270222885u,b_101b4624);register_block(270222893u,b_101b462c);register_block(270222915u,b_101b4642);register_block(270222941u,b_101b465c);register_block(270222957u,b_101b466c);register_block(270222965u,b_101b4674);register_block(270222973u,b_101b467c);register_block(270222981u,b_101b4684);register_block(270222985u,b_101b4688);register_block(270222991u,b_101b468e);register_block(270222997u,b_101b4694);register_block(270223003u,b_101b469a);register_block(270223011u,b_101b46a2);register_block(270223021u,b_101b46ac);register_block(270223031u,b_101b46b6);register_block(270223043u,b_101b46c2);register_block(270223049u,b_101b46c8);register_block(270223055u,b_101b46ce);register_block(270223061u,b_101b46d4);register_block(270223067u,b_101b46da);register_block(270223077u,b_101b46e4);register_block(270223081u,b_101b46e8);register_block(270223099u,b_101b46fa);register_block(270223119u,b_101b470e);register_block(270223133u,b_101b471c);register_block(270223135u,b_101b471e);register_block(270223155u,b_101b4732);register_block(270223169u,b_101b4740);register_block(270223175u,b_101b4746);}