// Event preview intercepts only finalization and continuation writes.
// Original native blocks remain active outside a selected historical Event.
#include "aot_runtime.h"
static constexpr uint32_t H=0x1ffed000u,MAGIC=0x45565431u;
static Block original_end,original_continue;
static bool active(Context& c){return rd<uint32_t>(c,H)==MAGIC;}
static void event_end(Context& c){
    if(!active(c)||rd<uint32_t>(c,H+116)){original_end(c);return;}
    wr<uint32_t>(c,H+4,1u);c.pc=c.r[14];
}
static void no_event_continuation(Context& c){
    if(active(c))c.r[1]=0u;
    original_continue(c);
}
static bool event_shop(Context& c){
    if(!active(c)||rd<uint32_t>(c,H+8)!=1u||!rd<uint32_t>(c,H+16)||!rd<uint32_t>(c,H+24))return false;
    uint32_t app=rd<uint32_t>(c,H+36);
    return app&&rd<uint32_t>(c,app+0xb890)==6u;
}
static bool hidden_shop(Context& c){
    if(!active(c)||rd<uint32_t>(c,H+16))return false;
    uint32_t app=rd<uint32_t>(c,H+36);
    if(!app)return false;
    uint32_t scene=rd<uint32_t>(c,app+0x22bc);
    return scene==67u||(scene==34u&&rd<uint32_t>(c,H+80));
}
static uint32_t shop_record(Context& c,uint32_t sid){
    if(!event_shop(c))return 0;
    uint32_t base=rd<uint32_t>(c,H+20),count=rd<uint32_t>(c,H+24);
    for(uint32_t i=0;i<count;i++)if(rd<uint32_t>(c,base+i*64)==sid)return base+i*64;
    return 0;
}
static void ret(Context& c,uint32_t value){c.r[0]=value;c.pc=c.r[14];}
#define SHOP_HOOK(NAME,PC,BODY) static Block old_##NAME;static void NAME(Context& c){BODY old_##NAME(c);}
// Clear native overrides before main-menu initialization can invoke another
// scene. The host restores the borrowed mission tables in the same frame.
SHOP_HOOK(main_menu_reset,0x10204051u,{
    uint32_t app=c.r[0];
    if(active(c)||rd<uint32_t>(c,H+80)||rd<uint32_t>(c,H+124)){
        for(uint32_t offset=0;offset<=196;offset+=4)wr<uint32_t>(c,H+offset,0u);
        wr<uint32_t>(c,H+200,1u);
    }
    wr<uint32_t>(c,app+0xb1ec,0u);wr<uint32_t>(c,app+0xb1f0,0u);wr<uint32_t>(c,app+0xb1f4,0u);
    wr<uint32_t>(c,app+0xc030,0u);wr<uint32_t>(c,app+0xc034,0u);
    wr<uint32_t>(c,app+0xc63c,0u);wr<uint32_t>(c,app+0xc06c,0u);wr<uint32_t>(c,app+0xc8c8,0u);
})
SHOP_HOOK(shop_data,0x101655c9u,uint32_t row=shop_record(c,c.r[0]);if(row){ret(c,rd<uint32_t>(c,row+4));return;})
SHOP_HOOK(shop_coin_price,0x10165977u,uint32_t row=shop_record(c,c.r[0]);if(row){ret(c,rd<uint32_t>(c,row+8));return;})
SHOP_HOOK(shop_standard_price,0x101656c5u,uint32_t row=shop_record(c,c.r[0]);if(row){ret(c,rd<uint32_t>(c,row+8));return;})
SHOP_HOOK(shop_discount,0x1016596bu,if(shop_record(c,c.r[0])){ret(c,0u);return;})
SHOP_HOOK(shop_maximum,0x10165709u,uint32_t row=shop_record(c,c.r[0]);if(row){ret(c,rd<uint32_t>(c,row+12));return;})
SHOP_HOOK(shop_stock,0x10165749u,uint32_t row=shop_record(c,c.r[0]);if(row&&rd<uint32_t>(c,row+20)==3){ret(c,rd<uint32_t>(c,row+16));return;})
// Medal packs listed in an Event catalog have an Event-local one-time stock.
// Native sold-out checks read global item stock directly; use the Event-local
// purchase count for these packs so another Event remains independent.
SHOP_HOOK(shop_medal_sold_out,0x10165835u,uint32_t row=shop_record(c,c.r[0]);if(row&&rd<uint32_t>(c,row+20)==3){ret(c,rd<uint32_t>(c,row+16)>=rd<uint32_t>(c,row+12));return;})
SHOP_HOOK(shop_catalog_forward,0x1020bb85u,if(active(c)&&rd<uint32_t>(c,H+8)==1u){c.r[2]=rd<uint32_t>(c,H+12);c.pc=0x1020bba1u;return;})
SHOP_HOOK(shop_catalog_previous,0x1020baedu,if(active(c)&&rd<uint32_t>(c,H+8)==1u){c.r[3]=rd<uint32_t>(c,H+12)+c.r[11]*4+c.r[5];c.pc=0x1020bb05u;return;})
SHOP_HOOK(shop_catalog_count,0x1020c095u,if(active(c)&&rd<uint32_t>(c,H+8)==1u){
    wr<uint32_t>(c,c.r[5]+0x9c,c.r[2]);wr<uint32_t>(c,c.r[5]+0xa0,rd<uint32_t>(c,H+16));
    c.r[2]=0x22;c.r[3]=rd<uint32_t>(c,c.r[6]+0x24);wr<uint32_t>(c,c.r[3]+0x50,c.r[2]);
    c.pc=0x1020c0cdu;return;
})
SHOP_HOOK(shop_buy_request,0x1020b475u,if(event_shop(c)&&!rd<uint32_t>(c,H+44)){
    uint32_t app=rd<uint32_t>(c,H+36);uint32_t index=rd<uint32_t>(c,app+0xb894);
    uint32_t panel=rd<uint32_t>(c,app+0x3380+index*4);
    uint32_t sid=rd<uint32_t>(c,panel+0x224);
    if(shop_record(c,sid))wr<uint32_t>(c,H+28,sid+1);
    ret(c,0);return;
})
SHOP_HOOK(shop_medal_counter,0x10167ac5u,if(active(c)&&rd<uint32_t>(c,H+8)&&rd<uint32_t>(c,H+44)){
    uint32_t row=shop_record(c,rd<uint32_t>(c,H+44)-1);
    if(row&&rd<uint32_t>(c,row+20)==3&&c.r[1]==rd<uint32_t>(c,row+24))
        wr<uint32_t>(c,row+16,rd<uint32_t>(c,row+16)+c.r[2]);
})
// Offline cooperation reuses the Survival controller. Cooperative ex-data
// contains no frozen-POW drop mapping; the original zero-count fallback reads
// dummy float data as an animation ID. A declared empty mapping has no drop.
SHOP_HOOK(empty_frozen_drop_map,0x101bcbf9u,if(active(c)&&!rd<uint32_t>(c,c.r[0]+0x3c)){
    c.pc=0x101bcca5u;return;
})
SHOP_HOOK(empty_enemy_drop_map,0x101d5489u,if(active(c)&&!rd<uint32_t>(c,c.r[0]+0x3c)){
    c.pc=0x101d5503u;return;
})
SHOP_HOOK(trace_drop_creation,0x101df345u,if(active(c)&&c.r[2]==327u){wr<uint32_t>(c,H+68,c.r[14]);})
SHOP_HOOK(trace_drop_animation,0x101de017u,if(active(c)&&rd<uint32_t>(c,c.r[0]+0x78)==327u&&c.r[1]>=32u){
    wr<uint32_t>(c,H+56,c.r[14]);wr<uint32_t>(c,H+60,c.r[0]);wr<uint32_t>(c,H+64,c.r[1]);
})
static bool event_map(Context& c){return active(c)&&rd<uint32_t>(c,H+80);}
SHOP_HOOK(map_campaign_bonus,0x101669fdu,if(event_map(c)&&c.r[14]>=0x10100000u&&c.r[14]<0x10200000u){
    uint32_t base=rd<uint32_t>(c,H+140);uint32_t count=rd<uint32_t>(c,H+144);
    for(uint32_t i=0;i<count;i++){
        uint32_t row=base+i*16;
        if(rd<uint32_t>(c,row)==c.r[0]&&rd<uint32_t>(c,row+4)==c.r[1]&&rd<uint32_t>(c,row+8)==c.r[2]){
            ret(c,rd<uint32_t>(c,row+12));return;
        }
    }
})
static uint32_t map_record(Context& c,uint32_t id){
    if(!event_map(c))return 0;
    uint32_t base=rd<uint32_t>(c,H+92);uint32_t count=rd<uint32_t>(c,H+96);
    for(uint32_t i=0;i<count;i++)if(rd<uint32_t>(c,base+i*64)==id)return base+i*64;
    return 0;
}
static uint32_t map_stage(Context& c,bool method){
    uint32_t w=c.r[method?1:0];uint32_t a=c.r[method?2:1];uint32_t s=c.r[method?3:2];
    return map_record(c,(w+1)*1000+(a+1)*10+s+1);
}
static uint32_t map_world(Context& c,uint32_t w){
    return w<rd<uint32_t>(c,H+148)?rd<uint32_t>(c,H+152)+w*12:0;
}
static bool map_has_area(Context& c,uint32_t w,uint32_t a){uint32_t row=map_world(c,w);return row&&a<rd<uint32_t>(c,row+4);}
SHOP_HOOK(map_area_count,0x10165efdu,if(event_map(c)){uint32_t row=map_world(c,c.r[0]);ret(c,row?rd<uint32_t>(c,row+4):0);return;})
SHOP_HOOK(map_area_data,0x10165f49u,if(event_map(c)&&c.r[2]==0){
    uint32_t row=map_world(c,c.r[0]);ret(c,map_has_area(c,c.r[0],c.r[1])?rd<uint32_t>(c,rd<uint32_t>(c,row)+c.r[1]*4):0);return;
})
SHOP_HOOK(map_area_name,0x10166085u,if(event_map(c)&&c.r[3]==0){
    uint32_t row=map_record(c,(c.r[0]+1)*1000+(c.r[1]+1)*10+1);
    if(row){uint32_t i=(row-rd<uint32_t>(c,H+92))/64;ret(c,rd<uint32_t>(c,rd<uint32_t>(c,H+100)+i*4));return;}
})
SHOP_HOOK(map_mission,0x101d09fdu,uint32_t row=map_record(c,c.r[1]);if(row){ret(c,rd<uint32_t>(c,row+8));return;})
SHOP_HOOK(map_world_enable,0x101664adu,if(event_map(c)){ret(c,map_world(c,c.r[0])!=0);return;})
SHOP_HOOK(map_area_enable,0x10166471u,if(event_map(c)){ret(c,map_has_area(c,c.r[0],c.r[1]));return;})
SHOP_HOOK(map_area_open,0x10166597u,if(event_map(c)){ret(c,map_has_area(c,c.r[0],c.r[1]));return;})
SHOP_HOOK(map_world_init,0x10215009u,if(event_map(c)){
    uint32_t task=rd<uint32_t>(c,c.r[0]+0x3360+c.r[1]*4);
    if(task){bool cats=rd<uint32_t>(c,H+156)!=0;
        wr<uint32_t>(c,task+0x3c,21u);wr<uint32_t>(c,task+0x40,0xffffffffu);
        // The original Event task table also uses world picture 56 above
        // its gray grid. Keep that map layer for every non-Neko Event.
        wr<uint32_t>(c,task+0x50,cats?0xffffffffu:56u);wr<uint32_t>(c,task+0x54,cats?0xffffffffu:56u);
        wr<uint32_t>(c,task+0x5c,27u);
        wr<uint32_t>(c,H+188,0u);
    }
})
// Battle resource initialization can occur after the map UI is suspended.
// Retain the selected Event track throughout that initialization as well.
SHOP_HOOK(map_bgm,0x101663c1u,if(active(c)&&rd<uint32_t>(c,H+164)){ret(c,rd<uint32_t>(c,H+164));return;})
// BattleScene::sceneActivate starts a stage track through FrameworkInstance.
// Victory (104) and defeat (105) effects request their own music during the
// same battle scene. Restrict substitution to the stage activation callsite.
SHOP_HOOK(map_music_request,0x101c677du,if(active(c)&&rd<uint32_t>(c,H+164)&&c.r[14]==0x101d52cbu){
    uint32_t scene=rd<uint32_t>(c,c.r[0]+0x22bc);
    if(scene==99u||scene==100u)c.r[1]=rd<uint32_t>(c,H+164);
})
// Neko has two worlds sharing one atlas. Draw each native world geometry
// through a temporary task, preserving the original geometry for markers.
// Both pages remain visible while the carousel is moving between worlds.
SHOP_HOOK(cat_world_draw,0x10213b35u,if(event_map(c)&&rd<uint32_t>(c,H+156)){
    uint32_t geometry=c.r[0];uint32_t task=rd<uint32_t>(c,H+196);uint32_t slot=rd<uint32_t>(c,geometry+0x1b4);
    if(task&&slot>=29u&&slot<32u){
        task+=(slot-29u)*0x228u;
        for(uint32_t offset=0;offset<0x228u;offset+=4)wr<uint32_t>(c,task+offset,rd<uint32_t>(c,geometry+offset));
        constexpr float overview=0.6529411673545837f;
        float sx=rd<float>(c,geometry+0xa8);float sy=rd<float>(c,geometry+0xac);
        float ox=rd<float>(c,geometry+0x84)+rd<float>(c,geometry+0x9c);
        float oy=rd<float>(c,geometry+0x88)+rd<float>(c,geometry+0xa0);
        wr<float>(c,task+0x84,ox+(-88.0f-(480.0f-720.0f*overview))*sx/overview);
        wr<float>(c,task+0x88,oy+(60.0f-(304.0f-356.0f*overview))*sy/overview);
        wr<float>(c,task+0x9c,0.0f);wr<float>(c,task+0xa0,0.0f);
        wr<float>(c,task+0xa8,2.0f*sx/overview);wr<float>(c,task+0xac,1.5f*sy/overview);
        wr<uint32_t>(c,task+0x3c,57u);wr<uint32_t>(c,task+0x5c,65u);wr<uint32_t>(c,task+0x50,0u);
        c.r[0]=task;
    }
})
SHOP_HOOK(map_background,0x102146cdu,if(event_map(c)){
    // Keep the native task's animated position and scale between draws.
    uint32_t task=c.r[0];
    if(rd<uint32_t>(c,H+156)){ret(c,0u);return;}
    wr<uint32_t>(c,task+0x3c,21u);wr<uint32_t>(c,task+0x5c,27u);
    wr<uint32_t>(c,task+0x50,147u);wr<uint32_t>(c,task+0x54,147u);
    if(rd<uint32_t>(c,H+188)!=task){
        wr<uint32_t>(c,H+188,task);
        wr<uint32_t>(c,task+0x84,0xc2b00000u);wr<uint32_t>(c,task+0x88,0u);
    }
    c.pc=0x101f56f5u;return;
})
// The Neko map numbers only ordinary regions. Boss regions do not consume a
// number; campaign area indices otherwise select unrelated picture frames.
SHOP_HOOK(cat_area_labels,0x10200161u,if(event_map(c)&&rd<uint32_t>(c,H+156)&&c.r[14]==0x10213f13u){
    uint32_t w=rd<uint32_t>(c,c.r[0]+0xb1ec);uint32_t a=rd<uint32_t>(c,c.r[1]+0x224);uint32_t world=map_world(c,w);
    if(world&&a<rd<uint32_t>(c,world+4)){
        uint32_t areas=rd<uint32_t>(c,world);uint32_t area=rd<uint32_t>(c,areas+a*4);
        if(rd<uint16_t>(c,area+14)==0xffffu){
            uint32_t label=0;
            for(uint32_t i=0;i<a;i++)if(rd<uint16_t>(c,rd<uint32_t>(c,areas+i*4)+14)==0xffffu)label++;
            wr<uint32_t>(c,c.r[13],105u+label);
        }
    }
})
SHOP_HOOK(map_stage_enable,0x10166411u,if(event_map(c)){ret(c,map_stage(c,false)!=0);return;})
SHOP_HOOK(map_stage_save_enable,0x10167f0du,if(event_map(c)){ret(c,map_stage(c,true)!=0);return;})
SHOP_HOOK(map_stage_clear,0x101680cdu,if(event_map(c)){uint32_t row=map_stage(c,true);ret(c,row?rd<uint32_t>(c,row+12):0);return;})
SHOP_HOOK(map_stage_time,0x101681afu,if(event_map(c)){uint32_t row=map_stage(c,true);ret(c,row?rd<uint32_t>(c,row+16):0);return;})
SHOP_HOOK(map_stage_prisoner,0x1016830fu,if(event_map(c)){uint32_t row=map_stage(c,true);ret(c,row?rd<uint32_t>(c,row+44):0);return;})
SHOP_HOOK(map_stage_prisoner_max,0x10166165u,if(event_map(c)){uint32_t row=map_stage(c,false);ret(c,row?rd<uint32_t>(c,row+40):0);return;})
static uint32_t prisoner_total(Context& c,uint32_t w,uint32_t a,bool saved){
    uint32_t result=0,base=rd<uint32_t>(c,H+92),count=rd<uint32_t>(c,H+96);bool parts=rd<uint32_t>(c,H+184)!=0;
    for(uint32_t i=0;i<count;i++){
        uint32_t row=base+i*64;
        if(rd<uint32_t>(c,row+32)==w&&rd<uint32_t>(c,row+20)==a){
            uint32_t value=rd<uint32_t>(c,row+(saved?44:40));
            if(parts){if(value>result)result=value;}else result+=value;
        }
    }
    return result;
}
SHOP_HOOK(map_area_prisoner_max,0x101661b5u,if(event_map(c)){ret(c,prisoner_total(c,c.r[0],c.r[1],false));return;})
static Block old_map_prisoner_rate;
static void map_prisoner_rate(Context& c){
    if(event_map(c)&&(c.r[14]<0x10100000u||c.r[14]>=0x10200000u)){
        uint32_t maximum=prisoner_total(c,c.r[0],c.r[1],false),saved=prisoner_total(c,c.r[0],c.r[1],true);
        ret(c,maximum?(saved>=maximum?100u:saved*100u/maximum):0u);return;
    }
    old_map_prisoner_rate(c);
}
static uint32_t prisoner_row(Context& c,uint32_t pid){
    if(!event_map(c))return 0;
    uint32_t base=rd<uint32_t>(c,H+168),count=rd<uint32_t>(c,H+172);
    for(uint32_t i=0;i<count;i++)if(rd<uint32_t>(c,base+i*20)==pid)return base+i*20;
    return 0;
}
SHOP_HOOK(map_prisoner_data,0x101668a9u,uint32_t row=prisoner_row(c,c.r[0]);if(row){ret(c,rd<uint32_t>(c,row+4));return;})
static uint32_t prisoner_text(Context& c,uint32_t field){
    uint32_t row=prisoner_row(c,c.r[0]);
    return row&&c.r[1]<11?rd<uint32_t>(c,rd<uint32_t>(c,row+field)+c.r[1]*4):0;
}
SHOP_HOOK(map_prisoner_name,0x10166911u,uint32_t text=prisoner_text(c,8);if(text){ret(c,text);return;})
SHOP_HOOK(map_prisoner_info1,0x10166925u,uint32_t text=prisoner_text(c,12);if(text){ret(c,text);return;})
SHOP_HOOK(map_prisoner_info2,0x10166939u,uint32_t text=prisoner_text(c,16);if(text){ret(c,text);return;})
SHOP_HOOK(map_prisoner_init,0x102130e1u,if(event_map(c)){
    if(!rd<uint32_t>(c,H+176)){wr<uint32_t>(c,H+180,1u);ret(c,0);return;}
    uint32_t app=c.r[0];
    wr<uint32_t>(c,app+0xc624,rd<uint32_t>(c,app+0xb1ec));
    wr<uint32_t>(c,app+0xc628,rd<uint32_t>(c,app+0xb1f0));wr<uint32_t>(c,app+0xc63c,0u);
})
// The POW cockpit button uses picture 117. Disable its native input callback
// and drawing when the selected Event world has no POW rewards.
// 无商店活动的 SHOP 图标 33 与基地面板 4 同时停用绘制及输入。
SHOP_HOOK(map_prisoner_button_input,0x101ff4e9u,{
    uint32_t task=c.r[0];uint32_t id=rd<uint32_t>(c,task+0x50);
    if(id==33u&&hidden_shop(c)){wr<uint32_t>(c,task+0x7c,rd<uint32_t>(c,task+0x7c)|0xa0u);ret(c,0u);return;}
    if(event_map(c)&&!rd<uint32_t>(c,H+176)&&id==117u){ret(c,0u);return;}
})
SHOP_HOOK(map_prisoner_button_draw,0x102003bdu,{
    uint32_t id=rd<uint32_t>(c,c.r[0]+0x50);
    if((id==33u&&hidden_shop(c))||(event_map(c)&&!rd<uint32_t>(c,H+176)&&id==117u)){ret(c,0u);return;}
})
SHOP_HOOK(base_shop_panel,0x1021d63du,{
    uint32_t task=c.r[0];
    if(hidden_shop(c)&&rd<uint32_t>(c,task+0x50)==4u){
        wr<uint32_t>(c,task+0x7c,rd<uint32_t>(c,task+0x7c)|0xa0u);ret(c,0u);return;
    }
})
SHOP_HOOK(map_stage_new,0x10167ff1u,if(event_map(c)){ret(c,0);return;})
SHOP_HOOK(map_stage_new_delete,0x1016807du,if(event_map(c)){ret(c,0);return;})
SHOP_HOOK(map_area_new,0x10168659u,if(event_map(c)){ret(c,0);return;})
SHOP_HOOK(map_area_new_delete,0x10168705u,if(event_map(c)){ret(c,0);return;})
SHOP_HOOK(map_start_battle,0x101e5b99u,uint32_t row=map_record(c,c.r[1]);if(row){
    wr<uint32_t>(c,H+112,rd<uint32_t>(c,row+28)+1);wr<uint32_t>(c,H+164,rd<uint32_t>(c,row+36));c.r[1]=rd<uint32_t>(c,row+4);
    if(rd<uint32_t>(c,H+108)){c.pc=0x101e5cffu;return;}
})
SHOP_HOOK(selector_mission,0x101d0a0fu,if(rd<uint32_t>(c,H+124)){
    ret(c,c.r[1]<rd<uint32_t>(c,H+132)?rd<uint32_t>(c,H+128)+c.r[1]*112:0);return;
})
SHOP_HOOK(selector_enabled,0x10168b5du,if(rd<uint32_t>(c,H+124)&&c.r[14]>=0x1020d000u&&c.r[14]<0x1020eb00u){ret(c,c.r[1]<rd<uint32_t>(c,H+132));return;})
SHOP_HOOK(selector_cleared,0x10168bc1u,if(rd<uint32_t>(c,H+124)&&c.r[14]>=0x1020d000u&&c.r[14]<0x1020eb00u){ret(c,0);return;})
SHOP_HOOK(selector_chosen,0x1020e805u,if(rd<uint32_t>(c,H+124)){
    wr<uint32_t>(c,H+136,c.r[11]+1);c.pc=0x1020e7f5u;return;
})
// Selecting an Event has no stamina charge. Its stages retain their own costs.
SHOP_HOOK(selector_cost_icon,0x102005ddu,if(rd<uint32_t>(c,H+124)&&c.r[14]==0x1020e9c5u){ret(c,0);return;})
SHOP_HOOK(selector_cost_number,0x101c4935u,if(rd<uint32_t>(c,H+124)&&c.r[14]==0x1020ea05u){ret(c,0);return;})
extern "C" __declspec(dllexport) void msd_enable_historical_event_hooks(){
    static bool done=false;if(done)return;done=true;
    original_end=find_block(0x101ea099u);
    original_continue=find_block(0x10168a03u);
    register_block(0x101ea099u,event_end);
    register_block(0x10168a03u,no_event_continuation);
#define INSTALL(NAME,PC) old_##NAME=find_block(PC);register_block(PC,NAME)
    INSTALL(main_menu_reset,0x10204051u);
    INSTALL(shop_data,0x101655c9u);INSTALL(shop_coin_price,0x10165977u);
    INSTALL(shop_standard_price,0x101656c5u);
    INSTALL(shop_discount,0x1016596bu);
    INSTALL(shop_maximum,0x10165709u);INSTALL(shop_stock,0x10165749u);
    INSTALL(shop_medal_sold_out,0x10165835u);
    INSTALL(shop_catalog_forward,0x1020bb85u);INSTALL(shop_catalog_previous,0x1020baedu);
    INSTALL(shop_catalog_count,0x1020c095u);INSTALL(shop_buy_request,0x1020b475u);
    INSTALL(shop_medal_counter,0x10167ac5u);
    INSTALL(empty_frozen_drop_map,0x101bcbf9u);
    INSTALL(empty_enemy_drop_map,0x101d5489u);
    INSTALL(trace_drop_creation,0x101df345u);INSTALL(trace_drop_animation,0x101de017u);
    INSTALL(map_area_count,0x10165efdu);INSTALL(map_area_data,0x10165f49u);INSTALL(map_area_name,0x10166085u);
    INSTALL(map_campaign_bonus,0x101669fdu);
    old_map_prisoner_rate=find_block(0x101669fdu);register_block(0x101669fdu,map_prisoner_rate);
    INSTALL(map_stage_prisoner_max,0x10166165u);INSTALL(map_area_prisoner_max,0x101661b5u);
    INSTALL(map_prisoner_data,0x101668a9u);INSTALL(map_prisoner_name,0x10166911u);
    INSTALL(map_prisoner_info1,0x10166925u);INSTALL(map_prisoner_info2,0x10166939u);
    INSTALL(map_prisoner_init,0x102130e1u);
    INSTALL(map_prisoner_button_input,0x101ff4e9u);
    INSTALL(map_prisoner_button_draw,0x102003bdu);
    INSTALL(base_shop_panel,0x1021d63du);
    INSTALL(map_world_init,0x10215009u);INSTALL(map_bgm,0x101663c1u);
    INSTALL(map_background,0x102146cdu);
    INSTALL(cat_world_draw,0x10213b35u);
    INSTALL(map_music_request,0x101c677du);
    INSTALL(cat_area_labels,0x10200161u);
    INSTALL(map_mission,0x101d09fdu);INSTALL(map_world_enable,0x101664adu);
    INSTALL(map_area_enable,0x10166471u);INSTALL(map_area_open,0x10166597u);
    INSTALL(map_stage_enable,0x10166411u);INSTALL(map_stage_save_enable,0x10167f0du);
    INSTALL(map_stage_clear,0x101680cdu);INSTALL(map_stage_time,0x101681afu);INSTALL(map_stage_prisoner,0x1016830fu);
    INSTALL(map_stage_new,0x10167ff1u);INSTALL(map_stage_new_delete,0x1016807du);
    INSTALL(map_area_new,0x10168659u);INSTALL(map_area_new_delete,0x10168705u);
    INSTALL(map_start_battle,0x101e5b99u);
    INSTALL(selector_mission,0x101d0a0fu);INSTALL(selector_enabled,0x10168b5du);
    INSTALL(selector_cleared,0x10168bc1u);INSTALL(selector_chosen,0x1020e805u);
    INSTALL(selector_cost_icon,0x102005ddu);INSTALL(selector_cost_number,0x101c4935u);
}
