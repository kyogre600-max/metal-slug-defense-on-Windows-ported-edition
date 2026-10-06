// LAB 原生钩子（第 1 批）：敌方单位绝招等待条。
// 仅在宿主写入 LAB 共享头（0x1ffeb000，魔数 LAB1）且对应功能位开启时生效；
// 其他模式下全部回落至原生块，行为与原版一致。
//
// 原生结构（BattlePlayerOperator::drawUI，0x1d7ca8 起）：
//   0x1d8d26  BattleObjectManager::getInstance → 0x1d8d2a getTeamUnitList(r7=本方队伍, 0)
//   0x1d8d90… 逐单位循环：0x1d8da0 起按 getSpAttackCooldownRate 绘制绝招等待条（drawConv + fillRect），
//             0x1d8e48 起绘制小地图点；0x1d8ef6 取下一单位；循环结束跳至 0x1d8f0a。
//   0x1d8f0a  第二个循环：getTeamUnitList([sp+56]=敌方队伍, 0)，只绘制敌方小地图点。
// 做法：第一个循环结束到达 0x1d8f0a 时，以敌方队伍再执行一遍第一个循环（状态 1），
//       该遍在 0x1d8e48 直接跳到下一单位，只画等待条、不重复画小地图点；
//       第二次到达 0x1d8f0a 时状态复位，继续原生的敌方小地图循环。
//
// 第 2 批（T1）：点击敌方单位释放其绝招。BattlePlayerOperator::onGameScreenTouchEnded（0x1d74a8）：
//   0x1d7642  getTeamUnitList(r1=r5 本方队伍, r2=r6=0) → 逐单位：isSpAttack、成员 [u+116]==r9、
//             [u+980]==0、|触点世界 x−[u+140]|≤99、|触点 y−[u+144]|<常数，按 [u+240] 与横距择优，结果 r6。
//   0x1d76c8  遍历结束：r6==0 退出；0x1d76cc 成员复核；0x1d76d2 以 [r4+24]（本方控制器）vtable+0x98 发动。
// 做法：本方未命中时置状态 1，r5/r9 换成敌方队伍与成员，r7 恢复触点世界 x（遍历中保存在 s16），
//       模拟调用 BattleObjectManager::getInstance 并返回 0x1d7642 再遍历一遍；命中则在 0x1d76d2 改用
//       敌方控制器（宿主写入 +16）发动。头部字段：+16 敌方控制器，+20 敌方成员，+24 点击补遍状态。
//
// 第 3 批（T2）：底栏左右分栏（功能位 4）。drawUI 作为嵌套调用每帧执行多遍，各遍以裁剪框与仿射变换
// 把底栏片段排成 [我方 AP][我方弹头车]▌我方 3 格▐敌方 3 格▐[敌方弹头车][敌方 AP]；敌方各遍换入敌方
// 控制器、出兵栏状态（头部 +0x70）与出兵格图集（头部 +0x40，宿主以敌方控制器调用 createGrahics 生成）。
// 触点在 onUITouchBegan/Moved/Ended 入口按片段换回原生坐标，敌方片段在处理期间换入敌方状态。
#include "aot_runtime.h"
#include "native_imports.h"
#include <utility>
namespace {
constexpr uint32_t H=0x1ffeb000u,MAGIC=0x4c414231u;   // "LAB1"
constexpr uint32_t FLAGS=H+4u,ENEMY_TEAM=H+8u,GAUGE_PASS=H+12u;
constexpr uint32_t ENEMY_CONTROLLER=H+16u,ENEMY_MEMBER=H+20u,TOUCH_PASS=H+24u;
constexpr uint32_t FLAG_ENEMY_GAUGE=1u,FLAG_ENEMY_TOUCH=2u;
constexpr uint32_t OBJECT_MANAGER_GET_INSTANCE=0x101de618u;
bool enabled(Context& c,uint32_t flag){
    return rd<uint32_t>(c,H)==MAGIC && (rd<uint32_t>(c,FLAGS)&flag);
}
Block old_gauge_loop_exit,old_gauge_minimap;
void gauge_loop_exit(Context& c){
    if(enabled(c,FLAG_ENEMY_GAUGE)){
        if(rd<uint32_t>(c,GAUGE_PASS)==0u){
            wr<uint32_t>(c,GAUGE_PASS,1u);
            c.r[7]=rd<uint32_t>(c,c.r[13]+56u);   // 原生第二循环所用的敌方队伍
            c.pc=0x101d8d27u;                      // 重新进入：getInstance → getTeamUnitList(r7,0)
            return;
        }
        wr<uint32_t>(c,GAUGE_PASS,0u);
    }else if(rd<uint32_t>(c,GAUGE_PASS)){
        wr<uint32_t>(c,GAUGE_PASS,0u);
    }
    old_gauge_loop_exit(c);
}
void gauge_minimap(Context& c){
    if(rd<uint32_t>(c,H)==MAGIC && rd<uint32_t>(c,GAUGE_PASS)==1u){
        c.pc=0x101d8ef7u;                          // 敌方补画遍：跳过小地图点，取下一单位
        return;
    }
    old_gauge_minimap(c);
}
Block old_touch_entry,old_touch_list,old_touch_loop_exit,old_touch_activate;
void touch_entry(Context& c){
    if(rd<uint32_t>(c,TOUCH_PASS))wr<uint32_t>(c,TOUCH_PASS,0u);
    old_touch_entry(c);
}
bool start_enemy_touch_pass(Context& c,uint32_t world_x){
    if(!rd<uint32_t>(c,ENEMY_CONTROLLER))return false;
    wr<uint32_t>(c,TOUCH_PASS,1u);
    c.r[5]=rd<uint32_t>(c,ENEMY_TEAM);
    c.r[6]=0u;
    c.r[9]=rd<uint32_t>(c,ENEMY_MEMBER);
    c.r[7]=world_x;                                // 0x1d764a 由 r7 重新得到 s16
    c.r[14]=0x101d7643u;                           // getInstance 返回后进入 getTeamUnitList(r5,r6=0)
    c.pc=OBJECT_MANAGER_GET_INSTANCE|1u;
    return true;
}
void touch_list(Context& c){
    // 0x1d764a：列表为空时原生直接退出，不经过 0x1d76c8。
    if(c.r[0]==0u && enabled(c,FLAG_ENEMY_TOUCH)){
        uint32_t pass=rd<uint32_t>(c,TOUCH_PASS);
        if(pass==0u && start_enemy_touch_pass(c,c.r[7]))return;
        if(pass)wr<uint32_t>(c,TOUCH_PASS,0u);
    }
    old_touch_list(c);
}
void touch_loop_exit(Context& c){
    if(enabled(c,FLAG_ENEMY_TOUCH)){
        uint32_t pass=rd<uint32_t>(c,TOUCH_PASS);
        if(pass==0u && c.r[6]==0u && start_enemy_touch_pass(c,uint32_t(int32_t(fs(c,16)))))return;
        if(pass==1u)wr<uint32_t>(c,TOUCH_PASS,c.r[6]?2u:0u);
    }else if(rd<uint32_t>(c,TOUCH_PASS)){
        wr<uint32_t>(c,TOUCH_PASS,0u);
    }
    old_touch_loop_exit(c);
}
void touch_activate(Context& c){
    if(rd<uint32_t>(c,TOUCH_PASS)==2u){
        wr<uint32_t>(c,TOUCH_PASS,0u);
        if(enabled(c,FLAG_ENEMY_TOUCH)){
            uint32_t controller=rd<uint32_t>(c,ENEMY_CONTROLLER);
            c.r[0]=controller;
            c.r[1]=rd<uint16_t>(c,c.r[6]+98u);
            c.r[3]=rd<uint32_t>(c,rd<uint32_t>(c,controller)+152u);   // actionUnitSpAttack
            c.r[14]=0x101d76e1u;
            c.pc=c.r[3];
            return;
        }
    }
    old_touch_activate(c);
}
// ---------- 嵌套调用：在钩子内同步执行一段客体函数（与 msd_run 相同的分派，返回哨兵 0x1fff0000） ----------
constexpr uint32_t RETURN_SENTINEL=0x1fff0000u;
bool guest_call(Context& c,uint32_t fn,uint32_t a0,uint32_t a1=0,uint32_t a2=0,uint32_t a3=0,
                const uint32_t* stack=nullptr,uint32_t stack_words=0,uint32_t* result=nullptr){
    uint32_t saved_r[16];std::memcpy(saved_r,c.r,sizeof saved_r);
    uint64_t saved_d[32];std::memcpy(saved_d,c.d,sizeof saved_d);
    uint32_t n=c.n,z=c.z,cf=c.c,v=c.v,fpscr=c.fpscr,pc=c.pc;
    uint32_t sp=(c.r[13]-96u)&~7u;
    for(uint32_t i=0;i<stack_words;++i)wr<uint32_t>(c,sp+i*4u,stack[i]);
    c.r[13]=sp;c.r[0]=a0;c.r[1]=a1;c.r[2]=a2;c.r[3]=a3;c.r[14]=RETURN_SENTINEL;c.pc=fn|1u;
    NativeImports* host=msd_imports(&c);
    bool ok=false;
    for(uint32_t i=0;i<50000000u;++i){
        uint32_t a=c.pc&~1u;
        if(a==RETURN_SENTINEL){ok=true;break;}
        if(a>=0x1f000000u&&a<0x1f010000u){
            if(!msd_native_import(c,a,host))break;        // 需要宿主处理的导入：嵌套调用无法让出，放弃
            c.blocks++;if(c.error)break;continue;
        }
        if(uint32_t thunk=msd_decoder_thunk(host,c.pc)){c.pc=thunk;continue;}
        Block f=find_block(c.pc);
        if(!f){missing(c,c.pc);break;}
        f(c);c.blocks++;
        if(c.error)break;
    }
    if(result)*result=c.r[0];
    std::memcpy(c.r,saved_r,sizeof saved_r);std::memcpy(c.d,saved_d,sizeof saved_d);
    c.n=n;c.z=z;c.c=cf;c.v=v;c.fpscr=fpscr;c.pc=pc;
    return ok;
}
uint32_t fbits(float f){uint32_t x;std::memcpy(&x,&f,4);return x;}
float bitsf(uint32_t x){float f;std::memcpy(&f,&x,4);return f;}

// ---------- 底栏分栏（T2，功能位 4） ----------
// drawUI 的全部底栏绘制最终经由 Graphics::drawImageS(Image*, float m[6]{a,b,tx,c,d,ty}, u,v,w,h,…)、
// Graphics::fillRect 与 Graphics::setClip/clearClip，坐标为原生参考坐标 D（逻辑 1280×720 下 L=(D+88.9)×1.125）。
// LAB 中每帧把 drawUI 作为嵌套调用执行多遍：第 0 遍只画底栏以外（裁剪 y<498）；其余各遍各负责一个底栏片段，
// 以裁剪框限定片段、以仿射变换（统一缩放 s、以底栏上沿为基准）移到新位置；敌方各遍临时换入敌方控制器与敌方滚动状态。
constexpr uint32_t FLAG_SPLIT_BAR=4u;
constexpr uint32_t G_DRAW_S=0x10143cddu,G_DRAW=0x10141b11u,G_FILL=0x1014311du,G_SETCLIP=0x101423ddu,G_CLEARCLIP=0x10142615u;
constexpr uint32_t DRAWUI=0x101d7ca8u,G_DRAWSTACK=0x10143a48u;
constexpr float BAR_TOP=498.0f,BAR_BOTTOM=640.0f,SCREEN_LEFT=-88.89f,SCREEN_RIGHT=1048.89f;
float SCALE=0.88f;                                             // layout() 按片段总宽占满屏幕计算（约 0.863）
// filter：0 全部，1 只画底栏背景。mirror：片段内容绕片段中心水平翻转。
// 两端的边缘块取自底栏背景最左端（源 x −88.89…−70，含 AP 框下方与底栏相接的圆角），右端为其镜像。
struct Segment{float src0,src1;bool enemy;int filter;bool mirror;};
constexpr Segment SEGMENTS[]={
    {-88.89f,-70,false,1,false},
    {18,140,false,0,false},{812,948,false,0,false},{155,177,false,1,false},{184,532,false,0,false},     // 我方：AP 升级、弹头车、左警示条、3 格
    {155,177,true,1,false},{184,532,true,0,false},{776,800,true,1,false},{812,948,true,0,true},{18,140,true,0,false},  // 敌方：中间分隔、3 格、右警示条、弹头车（翻转）、AP 升级
    {-88.89f,-70,true,1,true}};
constexpr int SEGMENT_COUNT=int(sizeof SEGMENTS/sizeof SEGMENTS[0]);
constexpr float ARROW_SHIFT=-246.0f;                           // 滚动箭头（源 x 742）移到 3 格窗口右端
struct Pass{bool active=false;float s=1,offx=0,offy=0;int clip[4]={0,0,0,0};int filter=0;bool cells=false;bool tinted=false;bool rotate=false;bool ap_button=false;bool apbar=false;bool no_apbar=false;bool mirror=false;bool mirror_sprite=false;uint32_t atlas=0;};
Pass pass;
bool enemy_pass=false;
float seg_dest[SEGMENT_COUNT];
bool laid_out_once=false;
void layout(){
    float total=0;for(const Segment& g:SEGMENTS)total+=g.src1-g.src0;
    SCALE=(SCREEN_RIGHT-SCREEN_LEFT)/total;
    float x=SCREEN_LEFT;
    for(int i=0;i<SEGMENT_COUNT;++i){seg_dest[i]=x;x+=SCALE*(SEGMENTS[i].src1-SEGMENTS[i].src0);}
}
bool split_enabled(Context& c){return enabled(c,FLAG_SPLIT_BAR) && rd<uint32_t>(c,ENEMY_CONTROLLER);}
uint32_t graphics_ptr=0;
uint32_t& scratch_matrix_slot(){static uint32_t slot=H+0x800u;return slot;}

bool pass_filter(Context& c,uint32_t u_bits){
    if(pass.filter==1)return u_bits==0u && rd<uint32_t>(c,c.r[13])==fbits(32.0f);   // 底栏背景图块 (0,32,568,71)
    return true;
}
bool is_arrow(Context& c){
    float u=bitsf(c.r[3]),v=bitsf(rd<uint32_t>(c,c.r[13]));
    return v==234.0f && (u==686.0f||u==706.0f);
}
// 裁剪改为软件实现：glScissor/glEnable 由 Python 宿主处理，嵌套调用中无法执行。
// 各遍中原生 setClip/clearClip 只更新 cur_clip（D 坐标），绘制钩子按 cur_clip 裁切每个图块的源矩形与位移。
int cur_clip[4]={0,0,0,0};
bool clip_range(float o,float k,float lo,float hi,float len,float& t0,float& t1){
    if(k==0.0f){t0=0;t1=len;return o>=lo && o<hi;}
    float p=(lo-o)/k,q=(hi-o)/k;if(p>q)std::swap(p,q);
    t0=std::max(0.0f,p);t1=std::min(len,q);return t1>t0;
}
// drawImageS(Image*, float m[6], u, v, w, h, …)：目标 x = tx + a·t（t∈[0,w]），y = ty + d·t（t∈[0,h]）。
bool clip_quad(Context& c,uint32_t m){
    float a=bitsf(rd<uint32_t>(c,m)),b=bitsf(rd<uint32_t>(c,m+4u)),tx=bitsf(rd<uint32_t>(c,m+8u));
    float cc=bitsf(rd<uint32_t>(c,m+12u)),d=bitsf(rd<uint32_t>(c,m+16u)),ty=bitsf(rd<uint32_t>(c,m+20u));
    uint32_t sp=c.r[13];
    float u=bitsf(c.r[3]),v=bitsf(rd<uint32_t>(c,sp)),w=bitsf(rd<uint32_t>(c,sp+4u)),h=bitsf(rd<uint32_t>(c,sp+8u));
    float L=float(cur_clip[0]),T=float(cur_clip[1]),R=L+float(cur_clip[2]),B=T+float(cur_clip[3]);
    if(b!=0.0f || cc!=0.0f){                                    // 旋转图块：只按外接框整体取舍
        float xs[4]={tx,tx+a*w,tx+b*h,tx+a*w+b*h},ys[4]={ty,ty+cc*w,ty+d*h,ty+cc*w+d*h};
        float x0=*std::min_element(xs,xs+4),x1=*std::max_element(xs,xs+4);
        float y0=*std::min_element(ys,ys+4),y1=*std::max_element(ys,ys+4);
        return x1>L && x0<R && y1>T && y0<B;
    }
    float x0,x1,y0,y1;
    if(!clip_range(tx,a,L,R,w,x0,x1) || !clip_range(ty,d,T,B,h,y0,y1))return false;
    if(x0>0.0f || x1<w){c.r[3]=fbits(u+x0);wr<uint32_t>(c,sp+4u,fbits(x1-x0));wr<uint32_t>(c,m+8u,fbits(tx+a*x0));}
    if(y0>0.0f || y1<h){wr<uint32_t>(c,sp,fbits(v+y0));wr<uint32_t>(c,sp+8u,fbits(y1-y0));wr<uint32_t>(c,m+20u,fbits(ty+d*y0));}
    return true;
}
// T5 AP 数值框：drawApBar 从第 0 遍中排除，我方、敌方各单独执行一遍，裁剪到框体真实下沿（D 520），
// 由随后绘制的底栏照原版压住下沿。敌方以敌方控制器执行，框体水平翻转到右下，不加底色（用户 2026-10-06 确认）。
// 框体图块含文字带（源 x 22…100：“AP:”、暗色占位数字与 “/”）：翻转后以无字底纹（源 x 100…122）平铺盖住
// 镜像的文字带，再把文字带不翻转地画到平移后的位置；当前值数字与 “/上限” 由原生平移绘制。
constexpr float AP_BOX_LEFT=-88.0f,AP_BOX_RIGHT=174.0f,AP_BOX_TOP=442.0f,AP_BOX_BOTTOM=520.0f;
constexpr float AP_TEXT0=22.0f,AP_TEXT1=100.0f,AP_PLAIN=100.0f,AP_PLAIN_W=22.0f;
constexpr uint32_t DRAW_AP_BAR=0x101d7ac4u;
constexpr uint32_t G_SETCOLOR=0x101417deu,G_GETCOLOR=0x1014398au;
// AP 升级按钮内的成本数字缩放后偏左约 2 像素（实测）；向右补正使其在数字框内居中（“MAX” 字样原本居中，不补正）。
constexpr float AP_DIGIT_SHIFT=2.0f;
// 缩放后底栏背景的上沿边框（目标 D 498…513，实测）；警示条条纹与骨架区为 513…底栏下沿。
constexpr float BAR_BORDER_SRC=17.0f;
void draw_quad(Context& c,uint32_t matrix,float a,float d,float tx,float ty,float u,float w,const uint32_t* tail){
    wr<uint32_t>(c,matrix,fbits(a));wr<uint32_t>(c,matrix+4u,0u);wr<uint32_t>(c,matrix+8u,fbits(tx));
    wr<uint32_t>(c,matrix+12u,0u);wr<uint32_t>(c,matrix+16u,fbits(d));wr<uint32_t>(c,matrix+20u,fbits(ty));
    uint32_t stack[6]={tail[0],fbits(w),tail[2],tail[3],tail[4],tail[5]};
    guest_call(c,G_DRAW_S-1u,c.r[0],c.r[1],matrix,fbits(u),stack,6);
}
void draw_enemy_ap_frame(Context& c,float a,float d,float tx,float ty){
    uint32_t tail[6];
    for(uint32_t i=0;i<6u;++i)tail[i]=rd<uint32_t>(c,c.r[13]+i*4u);   // v, w, h 及其余参数
    float w=bitsf(tail[1]),mirror_tx=SCREEN_LEFT+SCREEN_RIGHT-tx;
    pass.active=false;
    uint32_t m=H+0x820u;
    draw_quad(c,m,-a,d,mirror_tx,ty,0.0f,w,tail);                                      // 翻转的框体
    for(float x=mirror_tx-a*AP_TEXT1;x<mirror_tx-a*AP_TEXT0;x+=a*AP_PLAIN_W){        // 盖住镜像的文字带
        float tile=std::min(AP_PLAIN_W,(mirror_tx-a*AP_TEXT0-x)/a);
        draw_quad(c,m,a,d,x,ty,AP_PLAIN,tile,tail);
    }
    draw_quad(c,m,a,d,tx+pass.offx+a*AP_TEXT0,ty,AP_TEXT0,AP_TEXT1-AP_TEXT0,tail);     // 不翻转的文字带
    pass.active=true;
}
template<uint32_t ENTRY> struct DrawHook{static Block old;static void run(Context& c);};
template<uint32_t ENTRY> Block DrawHook<ENTRY>::old;
template<uint32_t ENTRY> void DrawHook<ENTRY>::run(Context& c){
    graphics_ptr=c.r[0];
    if(pass.active){
        if(!pass_filter(c,c.r[3])){c.pc=c.r[14];return;}
        float extra=(pass.cells && is_arrow(c))?ARROW_SHIFT*pass.s:0.0f;
        uint32_t m=c.r[2],dst=H+0x800u;
        float a=bitsf(rd<uint32_t>(c,m)),b=bitsf(rd<uint32_t>(c,m+4u)),tx=bitsf(rd<uint32_t>(c,m+8u));
        float cc=bitsf(rd<uint32_t>(c,m+12u)),d=bitsf(rd<uint32_t>(c,m+16u)),ty=bitsf(rd<uint32_t>(c,m+20u));
        float s=pass.s;
        wr<uint32_t>(c,dst,fbits(a*s));wr<uint32_t>(c,dst+4u,fbits(b*s));wr<uint32_t>(c,dst+8u,fbits(tx*s+pass.offx+extra));
        wr<uint32_t>(c,dst+12u,fbits(cc*s));wr<uint32_t>(c,dst+16u,fbits(d*s));wr<uint32_t>(c,dst+20u,fbits(ty*s+pass.offy));
        if(pass.apbar && c.r[3]==0u && rd<uint32_t>(c,c.r[13])==fbits(174.0f)){
            draw_enemy_ap_frame(c,a,d,tx,ty);c.pc=c.r[14];return;
        }
        if(pass.ap_button && ty>=590.0f && ty<625.0f && c.r[3]!=fbits(210.0f))
            wr<uint32_t>(c,dst+8u,fbits(bitsf(rd<uint32_t>(c,dst+8u))+AP_DIGIT_SHIFT));
        // 敌方弹头车片段整体翻转（底部 “MAX” 字样除外）；敌方 AP 升级片段只翻转人物精灵（图集以外的图像）。
        bool flip=(pass.mirror && !(ty>=590.0f && c.r[3]!=0u)) || (pass.mirror_sprite && c.r[1]!=pass.atlas);
        if(flip){
            float cx=float(pass.clip[0])+float(pass.clip[2])*0.5f;
            wr<uint32_t>(c,dst,fbits(-bitsf(rd<uint32_t>(c,dst))));
            wr<uint32_t>(c,dst+4u,fbits(-bitsf(rd<uint32_t>(c,dst+4u))));
            wr<uint32_t>(c,dst+8u,fbits(2.0f*cx-bitsf(rd<uint32_t>(c,dst+8u))));
        }
        if(pass.rotate){                                   // 中间分隔条：绕片段中心旋转 180°
            float px=float(pass.clip[0])+float(pass.clip[2])*0.5f,py=float(pass.clip[1])+float(pass.clip[3])*0.5f;
            for(uint32_t k=0;k<6u;k+=3u){
                wr<uint32_t>(c,dst+k*4u,fbits(-bitsf(rd<uint32_t>(c,dst+k*4u))));
                wr<uint32_t>(c,dst+k*4u+4u,fbits(-bitsf(rd<uint32_t>(c,dst+k*4u+4u))));
            }
            wr<uint32_t>(c,dst+8u,fbits(2.0f*px-bitsf(rd<uint32_t>(c,dst+8u))));
            wr<uint32_t>(c,dst+20u,fbits(2.0f*py-bitsf(rd<uint32_t>(c,dst+20u))));
        }
        c.r[2]=dst;
        if(!clip_quad(c,dst)){c.pc=c.r[14];return;}
    }
    old(c);
}
Block old_fill;
void fill_hook(Context& c){
    if(pass.active){
        if(pass.filter==1){c.pc=c.r[14];return;}
        float s=pass.s;
        int x=int(std::lround(int32_t(c.r[1])*s+pass.offx)),y=int(std::lround(int32_t(c.r[2])*s+pass.offy));
        int w=int(std::lround(int32_t(c.r[3])*s)),h=int(std::lround(int32_t(rd<uint32_t>(c,c.r[13]))*s));
        if(pass.mirror)x=pass.clip[0]*2+pass.clip[2]-(x+w);
        int x0=std::max(x,cur_clip[0]),y0=std::max(y,cur_clip[1]);
        int x1=std::min(x+w,cur_clip[0]+cur_clip[2]),y1=std::min(y+h,cur_clip[1]+cur_clip[3]);
        if(x1<=x0 || y1<=y0){c.pc=c.r[14];return;}
        c.r[1]=uint32_t(x0);c.r[2]=uint32_t(y0);c.r[3]=uint32_t(x1-x0);wr<uint32_t>(c,c.r[13],uint32_t(y1-y0));
    }
    old_fill(c);
}
Block old_setclip,old_clearclip;
// T3 敌我滤镜：出兵格循环的 setClip 之前（GraphicsOpt::setClip 已提交背景批次），在本遍 3 格窗口上叠半透明色块，
// 随后绘制的格子、头像、数字不受影响；警示条属于独立片段，不染色。
constexpr uint32_t TINT_MINE=0x462860ffu,TINT_ENEMY=0x46ff3030u;   // 约 27% 不透明
void draw_tint(Context& c,uint32_t g){
    uint32_t previous=0xffffffffu;
    pass.active=false;
    guest_call(c,G_GETCOLOR,g,0,0,0,nullptr,0,&previous);
    guest_call(c,G_SETCOLOR,g,enemy_pass?TINT_ENEMY:TINT_MINE);
    int top=int(BAR_TOP+BAR_BORDER_SRC*pass.s);                // 避开底栏上沿边框
    uint32_t stack[1]={uint32_t(pass.clip[1]+pass.clip[3]-top)};
    guest_call(c,G_FILL-1u,g,uint32_t(pass.clip[0]),uint32_t(top),uint32_t(pass.clip[2]),stack,1);
    guest_call(c,G_SETCOLOR,g,previous);
    pass.active=true;
}
void setclip_hook(Context& c){
    if(pass.active){
        if(pass.cells && !pass.tinted){pass.tinted=true;draw_tint(c,c.r[0]);}
        float s=pass.s;
        int x=int(std::floor(int32_t(c.r[1])*s+pass.offx)),y=int(std::floor(int32_t(c.r[2])*s+pass.offy));
        int w=int(std::ceil(int32_t(c.r[3])*s)),h=int(std::ceil(int32_t(rd<uint32_t>(c,c.r[13]))*s));
        int x0=std::max(x,pass.clip[0]),y0=std::max(y,pass.clip[1]);
        int x1=std::min(x+w,pass.clip[0]+pass.clip[2]),y1=std::min(y+h,pass.clip[1]+pass.clip[3]);
        cur_clip[0]=x0;cur_clip[1]=y0;cur_clip[2]=std::max(0,x1-x0);cur_clip[3]=std::max(0,y1-y0);
        c.pc=c.r[14];
        return;
    }
    old_setclip(c);
}
void clearclip_hook(Context& c){
    if(pass.active){
        std::memcpy(cur_clip,pass.clip,sizeof cur_clip);
        c.pc=c.r[14];
        return;
    }
    old_clearclip(c);
}

// 出兵栏状态（operator 偏移）：+24 控制器，+32 按下的格，+96 拖动状态，+100 滚动值，+104 最大滚动，+108 格距，+112 拖动中位置，+116 拖动标记。
constexpr uint32_t PANEL_WORDS[]={24,32,96,100,104,112,116};
// 敌方出兵栏状态存放在头部 +0x70 起 7 字（与 PANEL_WORDS 对应），+0x6c 为已初始化标记（宿主开战时清零），
// 宿主可直接改写 +0x7c（滚动值）实现按键自动滚动。
constexpr uint32_t ENEMY_PANEL_READY=H+0x6cu,ENEMY_PANEL=H+0x70u;
void swap_panel(Context& c,uint32_t op){
    for(int i=0;i<7;++i){
        uint32_t a=op+PANEL_WORDS[i],b=ENEMY_PANEL+uint32_t(i)*4u,t=rd<uint32_t>(c,a);
        wr<uint32_t>(c,a,rd<uint32_t>(c,b));wr<uint32_t>(c,b,t);
    }
}
void ensure_enemy_panel(Context& c,uint32_t op){
    if(rd<uint32_t>(c,ENEMY_PANEL_READY)!=1u){
        for(int i=0;i<7;++i)wr<uint32_t>(c,ENEMY_PANEL+uint32_t(i)*4u,rd<uint32_t>(c,op+PANEL_WORDS[i]));
        wr<uint32_t>(c,ENEMY_PANEL+4u,0xffffffffu);wr<uint32_t>(c,ENEMY_PANEL+8u,0u);wr<uint32_t>(c,ENEMY_PANEL+12u,0u);
        wr<uint32_t>(c,ENEMY_PANEL+20u,0u);wr<uint32_t>(c,ENEMY_PANEL+24u,rd<uint32_t>(c,op+116u)&~0xffu);
        wr<uint32_t>(c,ENEMY_PANEL_READY,1u);
    }
    wr<uint32_t>(c,ENEMY_PANEL,rd<uint32_t>(c,ENEMY_CONTROLLER));
}
// 3 格窗口：最大滚动 =（槽位数 − 3）× 格距。
uint32_t max_scroll(Context& c,uint32_t op,uint32_t controller){
    float pitch=bitsf(rd<uint32_t>(c,op+108u));
    int count=int32_t(rd<uint32_t>(c,controller+912u));
    return uint32_t(std::max(0,count-3)*int(pitch+0.5f));
}
// 敌方出兵格图集：宿主在战斗开始后以敌方控制器调用 BattlePlayerOperator::createGrahics（含 OBM 读取，须在顶层执行），
// 把生成的 operator+188…+220 九个字写入头部 +0x40 起，+0x3c 置 1。敌方各遍与 operator 原值互换。
constexpr uint32_t GFX_READY=H+0x3cu,GFX_BASE=H+0x40u,GFX_FIRST=188u,GFX_WORDS=9u;
void swap_gfx(Context& c,uint32_t op){
    if(rd<uint32_t>(c,GFX_READY)!=1u)return;
    for(uint32_t i=0;i<GFX_WORDS;++i){
        uint32_t a=op+GFX_FIRST+i*4u,b=GFX_BASE+i*4u,t=rd<uint32_t>(c,a);
        wr<uint32_t>(c,a,rd<uint32_t>(c,b));wr<uint32_t>(c,b,t);
    }
}
// 与 BattlePlayerOperator::update（0x1d6ae4…0x1d6b34）相同：升级动作（动画 1）播完且据点未满级时回到动画 0，
// 然后推进一帧。敌方图集与出兵栏状态换入期间对 operator+204 执行；每帧一次。
constexpr uint32_t SPRITE_GET_ANIMATION=0x101db8eau,SPRITE_IS_PLAYING=0x101db8f0u,SPRITE_CHANGE=0x101dc3eau,SPRITE_UPDATE=0x101dc4a6u;
constexpr uint32_t KYOTEN_LEVEL_MAX=0x101cbd78u;
void tick_enemy_sprite(Context& c,uint32_t op){
    uint32_t sprite=rd<uint32_t>(c,op+204u),value=0;
    if(!sprite)return;
    guest_call(c,SPRITE_GET_ANIMATION,sprite,0,0,0,nullptr,0,&value);
    if(value==1u){
        guest_call(c,SPRITE_IS_PLAYING,sprite,0,0,0,nullptr,0,&value);
        if(!value){
            guest_call(c,KYOTEN_LEVEL_MAX,rd<uint32_t>(c,op+24u),0,0,0,nullptr,0,&value);
            if(!value)guest_call(c,SPRITE_CHANGE,sprite,0,0);
        }
    }
    guest_call(c,SPRITE_UPDATE,sprite);
}
void run_pass(Context& c,uint32_t op,const Pass& p,uint32_t fn=DRAWUI){
    pass=p;
    std::memcpy(cur_clip,p.clip,sizeof cur_clip);
    guest_call(c,fn,op);
    pass.active=false;
}

Block old_drawui_entry;
bool in_ui=false;
void drawui_entry(Context& c){
    // graphics_ptr 在首次 Graphics 绘制时取得；取得之前按原生流程绘制一帧。
    if(in_ui || !split_enabled(c) || !graphics_ptr){old_drawui_entry(c);return;}
    uint32_t ret=c.r[14],op=c.r[0];
    in_ui=true;
    if(!laid_out_once){layout();laid_out_once=true;}
    ensure_enemy_panel(c,op);
    uint32_t mine=rd<uint32_t>(c,op+24u);
    wr<uint32_t>(c,op+104u,max_scroll(c,op,mine));
    wr<uint32_t>(c,ENEMY_PANEL+16u,max_scroll(c,op,rd<uint32_t>(c,ENEMY_PANEL)));
    // 第 0 遍：底栏以外。
    Pass base;base.active=true;base.s=1.0f;base.no_apbar=true;
    base.clip[0]=int(SCREEN_LEFT)-1;base.clip[1]=0;base.clip[2]=int(SCREEN_RIGHT-SCREEN_LEFT)+2;base.clip[3]=int(BAR_TOP);
    run_pass(c,op,base);
    // AP 数值框（T5）：我方原位，敌方翻转到右下；下沿由随后绘制的底栏压住，与原版一致。
    Pass apm;apm.active=true;apm.s=1.0f;
    apm.clip[0]=int(AP_BOX_LEFT)-2;apm.clip[1]=int(AP_BOX_TOP)-8;
    apm.clip[2]=int(AP_BOX_RIGHT-AP_BOX_LEFT)+4;apm.clip[3]=int(AP_BOX_BOTTOM)+2-apm.clip[1];
    run_pass(c,op,apm,DRAW_AP_BAR);
    Pass apb=apm;apb.apbar=true;
    apb.offx=(SCREEN_LEFT+SCREEN_RIGHT-AP_BOX_RIGHT)-AP_BOX_LEFT;
    apb.clip[0]=int(SCREEN_LEFT+SCREEN_RIGHT-AP_BOX_RIGHT)-2;
    swap_panel(c,op);
    enemy_pass=true;
    run_pass(c,op,apb,DRAW_AP_BAR);
    enemy_pass=false;
    swap_panel(c,op);
    for(int i=0;i<SEGMENT_COUNT;++i){
        const Segment& g=SEGMENTS[i];
        Pass p;p.active=true;p.s=SCALE;p.filter=g.filter;p.cells=(g.src0==184.0f);
        p.ap_button=(g.src0==18.0f);
        p.mirror=g.mirror;
        p.mirror_sprite=g.enemy && g.src0==18.0f;
        p.offx=seg_dest[i]-SCALE*g.src0;
        p.offy=BAR_TOP*(1.0f-SCALE);                       // 以底栏上沿为基准缩放
        p.clip[0]=int(std::floor(seg_dest[i]));p.clip[1]=int(BAR_TOP);
        p.clip[2]=int(std::ceil(SCALE*(g.src1-g.src0)))+1;p.clip[3]=int(std::ceil((BAR_BOTTOM-BAR_TOP)*SCALE));
        if(g.enemy){swap_panel(c,op);swap_gfx(c,op);}
        p.atlas=rd<uint32_t>(c,op+188u);
        enemy_pass=g.enemy;
        if(g.enemy && g.src0==155.0f){
            // 中间分隔条（取自敌方左警示条）：上沿边框不动，条纹段绕自身中心旋转 180°，避免与两侧重复。
            int border=int(BAR_TOP+BAR_BORDER_SRC*SCALE),bottom=p.clip[1]+p.clip[3];
            Pass top=p;top.clip[3]=border-p.clip[1];
            run_pass(c,op,top);
            p.rotate=true;p.clip[1]=border;p.clip[3]=bottom-border;
        }
        run_pass(c,op,p);
        enemy_pass=false;
        if(g.enemy){swap_gfx(c,op);swap_panel(c,op);}
    }
    // 缩放后底栏下方留出的带状区域：以底栏底色填充。
    if(graphics_ptr){
        float bottom=BAR_TOP+(BAR_BOTTOM-BAR_TOP)*SCALE;
        uint32_t stack[1]={uint32_t(int(BAR_BOTTOM-bottom)+2)};
        guest_call(c,0x101417dfu-1u,graphics_ptr,0xff1c1c1cu);                 // Graphics::setColor
        guest_call(c,G_FILL-1u,graphics_ptr,uint32_t(int(SCREEN_LEFT)-1),uint32_t(int(bottom)),uint32_t(int(SCREEN_RIGHT-SCREEN_LEFT)+2),stack,1);
        guest_call(c,0x101417dfu-1u,graphics_ptr,0xffffffffu);
    }
    in_ui=false;
    c.pc=ret;
}
// ---------- 底栏分栏的触点换算 ----------
// onTouchBegan/Moved/Ended 在 y≥512 时尾调用 onUITouchBegan/Moved/Ended(op,x,y,…)。入口处按按下时所在的片段
// 把新布局坐标换回原生坐标（x=(x−offx)/s，y=(y−offy)/s），敌方片段临时换入敌方出兵栏状态，出口块执行后换回。
int touch_segment=-1;bool touch_swapped=false;uint32_t touch_op=0;
int segment_at(float x,float y){
    if(y<BAR_TOP)return -1;
    for(int i=0;i<SEGMENT_COUNT;++i){
        float w=SCALE*(SEGMENTS[i].src1-SEGMENTS[i].src0);
        if(x>=seg_dest[i] && x<seg_dest[i]+w)return i;
    }
    return -1;
}
float to_src_x(int i,float x){return i<0?-10000.0f:(x-(seg_dest[i]-SCALE*SEGMENTS[i].src0))/SCALE;}
float to_src_y(float y){return (y-BAR_TOP*(1.0f-SCALE))/SCALE;}
bool touch_enter(Context& c,bool began,bool has_prev){
    if(!split_enabled(c) || !laid_out_once)return true;
    uint32_t op=c.r[0];
    if(began)touch_segment=segment_at(float(int32_t(c.r[1])),float(int32_t(c.r[2])));
    int i=touch_segment;
    bool enemy=i>=0 && SEGMENTS[i].enemy;
    c.r[1]=uint32_t(int32_t(std::lround(to_src_x(i,float(int32_t(c.r[1]))))));
    c.r[2]=uint32_t(int32_t(std::lround(to_src_y(float(int32_t(c.r[2]))))));
    if(has_prev){                                              // onUITouchMoved(op,x,y,上一 x,上一 y)
        c.r[3]=uint32_t(int32_t(std::lround(to_src_x(i,float(int32_t(c.r[3]))))));
        uint32_t py=rd<uint32_t>(c,c.r[13]);
        wr<uint32_t>(c,c.r[13],uint32_t(int32_t(std::lround(to_src_y(float(int32_t(py)))))));
    }
    if(enemy){swap_panel(c,op);touch_swapped=true;touch_op=op;}
    return true;
}
Block old_ui_began,old_ui_moved,old_ui_ended;
void ui_began(Context& c){if(touch_enter(c,true,false))old_ui_began(c);}
void ui_moved(Context& c){if(touch_enter(c,false,true))old_ui_moved(c);}
void ui_ended(Context& c){if(touch_enter(c,false,false))old_ui_ended(c);}
// 三个处理函数的全部出口块（均以出栈返回结束）：先执行原块，再换回我方状态。
constexpr uint32_t UI_EXITS[]={0x101d725du,0x101d7263u,0x101d72c1u,0x101d72c9u,0x101d72cfu,0x101d7311u,0x101d73d3u,0x101d73d7u,0x101d7411u};
constexpr int UI_EXIT_COUNT=int(sizeof UI_EXITS/sizeof UI_EXITS[0]);
Block old_ui_exit[UI_EXIT_COUNT];
template<int K> void ui_exit(Context& c){
    old_ui_exit[K](c);
    if(touch_swapped){
        touch_swapped=false;
        // 拖动结束时（+96==2）原生 update 只为我方逐帧收敛滚动；敌方直接定位到吸附后的滚动值。
        if(rd<uint32_t>(c,touch_op+96u)==2u){wr<uint32_t>(c,touch_op+96u,0u);wr<uint32_t>(c,touch_op+112u,fbits(float(int32_t(rd<uint32_t>(c,touch_op+100u)))));}
        swap_panel(c,touch_op);
    }
}
template<int... K> void install_ui_exits(std::integer_sequence<int,K...>){
    ((old_ui_exit[K]=find_block(UI_EXITS[K]),register_block(UI_EXITS[K],ui_exit<K>)),...);
}
void install_touch_hooks(){
    old_ui_began=find_block(0x101d7209u);register_block(0x101d7209u,ui_began);
    old_ui_moved=find_block(0x101d7265u);register_block(0x101d7265u,ui_moved);
    old_ui_ended=find_block(0x101d7315u);register_block(0x101d7315u,ui_ended);
    install_ui_exits(std::make_integer_sequence<int,UI_EXIT_COUNT>{});
}
// 我方 AP 获得时的金币动画只属于我方，敌方各遍不绘制。
Block old_coin_draw;
void coin_draw(Context& c){
    if(pass.active && enemy_pass){c.pc=c.r[14];return;}
    old_coin_draw(c);
}
// ---------- 敌方 AP 按钮人物的动画（与我方相同的逻辑） ----------
// 我方：BattlePlayerOperator::update 每帧推进 operator+204；BattleScene 的事件切换动画——
//   onEventBaseLevelup（本方）→ playBaseLevelupAction（动画 1），onEventFeverTimeStart（本方）→ changeRumiAnimationLevelMAX，
//   onEventBaseUnitDead → battleFinish 后本方据点被毁为 Escape，否则（本方未满级时）为 Win。
// 敌方：在上述函数入口以敌方图集与出兵栏状态执行对应动作（敌方据点被毁 → Escape，我方据点被毁 → Win）。
bool enemy_sprite_ready(Context& c){return split_enabled(c) && rd<uint32_t>(c,GFX_READY)==1u && rd<uint32_t>(c,ENEMY_PANEL_READY)==1u;}
template<class F> void with_enemy(Context& c,uint32_t op,F action){
    swap_panel(c,op);swap_gfx(c,op);action();swap_gfx(c,op);swap_panel(c,op);
}
Block old_operator_update;
void operator_update(Context& c){
    uint32_t op=c.r[0];
    if(enemy_sprite_ready(c))with_enemy(c,op,[&]{tick_enemy_sprite(c,op);});
    old_operator_update(c);
}
constexpr uint32_t RUMI_LEVEL_MAX=0x101d7196u,RUMI_ESCAPE=0x101d71b2u,RUMI_WIN=0x101d71ceu;
Block old_fever,old_levelup,old_base_dead;
void scene_fever(Context& c){                                  // onEventFeverTimeStart(scene, team)
    uint32_t scene=c.r[0],op=rd<uint32_t>(c,scene+60u);
    if(enemy_sprite_ready(c) && c.r[1]==rd<uint32_t>(c,ENEMY_TEAM))
        with_enemy(c,op,[&]{guest_call(c,RUMI_LEVEL_MAX,op);});
    old_fever(c);
}
void scene_levelup(Context& c){                                // onEventBaseLevelup(scene, team, level, member, bool)
    uint32_t scene=c.r[0],op=rd<uint32_t>(c,scene+60u);
    if(enemy_sprite_ready(c) && c.r[1]==rd<uint32_t>(c,ENEMY_TEAM))
        with_enemy(c,op,[&]{guest_call(c,SPRITE_CHANGE,rd<uint32_t>(c,op+204u),1u,1u);});   // playBaseLevelupAction 的精灵部分
    old_levelup(c);
}
void scene_base_dead(Context& c){                              // onEventBaseUnitDead(scene, ?, team)
    uint32_t scene=c.r[0],op=rd<uint32_t>(c,scene+60u),team=c.r[2];
    if(enemy_sprite_ready(c)){
        with_enemy(c,op,[&]{
            uint32_t max=0;
            if(team==rd<uint32_t>(c,ENEMY_TEAM))guest_call(c,RUMI_ESCAPE,op);
            else{
                guest_call(c,KYOTEN_LEVEL_MAX,rd<uint32_t>(c,op+24u),0,0,0,nullptr,0,&max);
                if(!max)guest_call(c,RUMI_WIN,op);
            }
        });
    }
    old_base_dead(c);
}
// ---------- T7：AI 自动出兵与自动绝招拆分（功能位 16） ----------
// BattleControllerPlayerBase::noukinAutoPlay（0x1cbfe0，原生 AUTO 每帧一步）：等待计时 → 弹头车（0x1cc018）→
// 逐个本方单位检查绝招（0x1cc04e isSpAttack，就绪则 0x1cc426 发动）→ 0x1cc070 起为出兵等决策。
// 宿主在任一开关开启时对该方 startAutoPlay；头部 +0x30 的禁用位决定跳过哪一部分：
//   位 0/1：我方 自动出兵/自动绝招 关闭；位 2/3：敌方 自动出兵/自动绝招 关闭。“自动出兵”含弹头车与出兵决策。
constexpr uint32_t FLAG_AUTO_SPLIT=16u,AUTO_DISABLE=H+0x30u;
uint32_t auto_disabled(Context& c,uint32_t controller){
    uint32_t bits=rd<uint32_t>(c,AUTO_DISABLE);
    return controller==rd<uint32_t>(c,ENEMY_CONTROLLER)?(bits>>2)&3u:bits&3u;   // 位 0 出兵，位 1 绝招
}
Block old_auto_slug,old_auto_special,old_auto_deploy;
void auto_slug(Context& c){                                    // 0x1cc018：r0=isUseMetasuraHou，r4=控制器
    if(enabled(c,FLAG_AUTO_SPLIT) && (auto_disabled(c,c.r[4])&1u)){c.pc=0x101cc02bu;return;}
    old_auto_slug(c);
}
void auto_special(Context& c){                                 // 0x1cc04e：r5=单位
    if(enabled(c,FLAG_AUTO_SPLIT) && (auto_disabled(c,c.r[4])&2u)){c.pc=0x101cc061u;return;}
    old_auto_special(c);
}
void auto_deploy(Context& c){                                  // 0x1cc070：绝招检查结束，进入出兵决策
    if(enabled(c,FLAG_AUTO_SPLIT) && (auto_disabled(c,c.r[4])&1u)){c.pc=0x101cc52fu;return;}
    old_auto_deploy(c);
}
// ---------- T8 支援：弹头车出击按钮的可选效果（功能位 32） ----------
// BattleControllerPlayerBase::actionMetasuraHou（0x1cc760）：充能（控制器+1036）满时清零并调用
// BattleController::actionMetasuraHou 发射弹头车。按钮、按键与 AI 均经此入口。头部 +0x34：低字节我方、次字节敌方
// 的支援选项；0 为原版弹头车，其余选项在充能满时同样清零充能，执行效果后不发射弹头车。新增选项在 apply_support 中扩展。
//   1：本方除据点外所有存活单位 HP 回满（当前 HP 单位+776 ← 最大 HP 单位+772）。
//   2：本方所有单位绝招立即可再次释放（绝招倒计时 单位+800 大于 0 时置 0；isSpAttack 在其为 0 时成立）。
constexpr uint32_t FLAG_SUPPORT=32u,SUPPORT_OPTIONS=H+0x34u,SUPPORT_LAST=H+0x38u;
constexpr uint32_t IS_USE_SLUG=0x101cbdc0u,GET_TEAM_UNITS=0x101df318u,GET_BASE_UNIT=0x101c9764u;
void apply_support(Context& c,uint32_t controller,uint32_t option){
    uint32_t manager=0,unit=0,base=0;
    guest_call(c,OBJECT_MANAGER_GET_INSTANCE,0,0,0,0,nullptr,0,&manager);
    guest_call(c,GET_BASE_UNIT,controller,0,0,0,nullptr,0,&base);
    guest_call(c,GET_TEAM_UNITS,manager,rd<uint32_t>(c,controller+908u),0,0,nullptr,0,&unit);
    for(int guard=0;unit && guard<4096;++guard){
        if(unit!=base){
            if(option==1u && int32_t(rd<uint32_t>(c,unit+776u))>0)wr<uint32_t>(c,unit+776u,rd<uint32_t>(c,unit+772u));
            if(option==2u && int32_t(rd<uint32_t>(c,unit+800u))>0)wr<uint32_t>(c,unit+800u,0u);
        }
        uint32_t link=rd<uint32_t>(c,unit+0x120u);
        unit=link?link-0x11cu:0u;
    }
}
Block old_slug_action;
void slug_action(Context& c){
    if(enabled(c,FLAG_SUPPORT)){
        uint32_t controller=c.r[0];
        uint32_t options=rd<uint32_t>(c,SUPPORT_OPTIONS);
        uint32_t option=controller==rd<uint32_t>(c,ENEMY_CONTROLLER)?(options>>8)&0xffu:options&0xffu;
        if(option){
            uint32_t ready=0;
            guest_call(c,IS_USE_SLUG,controller,0,0,0,nullptr,0,&ready);
            if(ready){
                wr<uint32_t>(c,controller+1036u,0u);
                apply_support(c,controller,option);
                wr<uint32_t>(c,SUPPORT_LAST,rd<uint32_t>(c,SUPPORT_LAST)+1u);   // 宿主据此给出提示
            }
            c.pc=c.r[14];return;
        }
    }
    old_slug_action(c);
}
Block old_ap_bar;
void ap_bar_entry(Context& c){
    if(pass.active && pass.no_apbar){c.pc=c.r[14];return;}
    old_ap_bar(c);
}
void install_ui_hooks(){
    old_slug_action=find_block(0x101cc761u);register_block(0x101cc761u,slug_action);
    old_auto_slug=find_block(0x101cc019u);register_block(0x101cc019u,auto_slug);
    old_auto_special=find_block(0x101cc04fu);register_block(0x101cc04fu,auto_special);
    old_auto_deploy=find_block(0x101cc071u);register_block(0x101cc071u,auto_deploy);
    old_operator_update=find_block(0x101d6ae5u);register_block(0x101d6ae5u,operator_update);
    old_fever=find_block(0x101d5063u);register_block(0x101d5063u,scene_fever);
    old_levelup=find_block(0x101d5173u);register_block(0x101d5173u,scene_levelup);
    old_base_dead=find_block(0x101d5dfdu);register_block(0x101d5dfdu,scene_base_dead);
    old_ap_bar=find_block(DRAW_AP_BAR|1u);register_block(DRAW_AP_BAR|1u,ap_bar_entry);
    old_coin_draw=find_block(0x101d6881u);register_block(0x101d6881u,coin_draw);
    old_drawui_entry=find_block(0x101d7ca9u);register_block(0x101d7ca9u,drawui_entry);
    DrawHook<G_DRAW_S>::old=find_block(G_DRAW_S);register_block(G_DRAW_S,DrawHook<G_DRAW_S>::run);
    DrawHook<G_DRAW>::old=find_block(G_DRAW);register_block(G_DRAW,DrawHook<G_DRAW>::run);
    old_fill=find_block(G_FILL);register_block(G_FILL,fill_hook);
    old_setclip=find_block(G_SETCLIP);register_block(G_SETCLIP,setclip_hook);
    old_clearclip=find_block(G_CLEARCLIP);register_block(G_CLEARCLIP,clearclip_hook);
    install_touch_hooks();
}
}
extern "C" __declspec(dllexport) uint32_t msd_lab_hooks_version(){return 4u;}
extern "C" __declspec(dllexport) void msd_enable_lab_hooks(){
    static bool installed=false;
    if(installed)return;
    installed=true;
    old_gauge_loop_exit=find_block(0x101d8f0bu);register_block(0x101d8f0bu,gauge_loop_exit);
    old_gauge_minimap=find_block(0x101d8e49u);register_block(0x101d8e49u,gauge_minimap);
    old_touch_entry=find_block(0x101d74a9u);register_block(0x101d74a9u,touch_entry);
    old_touch_list=find_block(0x101d764bu);register_block(0x101d764bu,touch_list);
    old_touch_loop_exit=find_block(0x101d76c9u);register_block(0x101d76c9u,touch_loop_exit);
    old_touch_activate=find_block(0x101d76d3u);register_block(0x101d76d3u,touch_activate);
    install_ui_hooks();
}
