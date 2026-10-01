#include "aot_runtime.h"
// Recovered CLZSS::Decode algorithm, verified against the original function.
// Keeping the dictionary loop in C++ avoids a block dispatch for every byte.
static void native_lzss(Context& c){
    uint32_t src=c.r[0],dst=c.r[1],remaining=c.r[2];
    if(!src||!dst||!remaining){c.r[0]=0;c.pc=c.r[14];return;}
    uint8_t dictionary[4096]={};uint32_t write=0xfee,flags=0;
    while(remaining&&!c.error){
        flags>>=1;if(!(flags&0x100))flags=rd<uint8_t>(c,src++)|0xff00;
        uint32_t lo=rd<uint8_t>(c,src++);
        if(flags&1){
            wr<uint8_t>(c,dst++,lo);remaining--;
            dictionary[write]=uint8_t(lo);write=(write+1)&4095;
        }else{
            uint32_t hi=rd<uint8_t>(c,src++),pos=lo|((hi&0xf0)<<4),length=(hi&15)+3;
            for(uint32_t j=0;j<length&&remaining;j++){
                uint8_t b=dictionary[(pos+j)&4095];wr<uint8_t>(c,dst++,b);remaining--;
                dictionary[write]=b;write=(write+1)&4095;
            }
        }
    }
    c.r[0]=c.error?0:1;c.pc=c.r[14];
}
static void native_decrypt(Context& c){
    uint32_t dst=c.r[0],offset=c.r[1]&63,n=c.r[2],last=0;
    uint8_t key[64];for(uint32_t j=0;j<64;j++)key[j]=rd<uint8_t>(c,0x102384b5u+j);
    for(uint32_t j=0;j<n&&!c.error;j++){
        last=rd<uint8_t>(c,dst+j);wr<uint8_t>(c,dst+j,last^key[(offset+j)&63]);
    }
    c.r[0]=last;c.pc=c.r[14];
}
extern "C" __declspec(dllexport) uint32_t msd_run(Context* cp,uint32_t budget){
    Context& c=*cp;
    for(uint32_t i=0;i<budget;i++){
        uint32_t a=c.pc&~1u;
        if(a==0x1fff0000)return 0;
        if(a>=0x1f000000&&a<0x1f010000)return 1;
        if(c.pc==0x1013faa1){native_lzss(c);c.blocks++;if(c.error)return c.error;continue;}
        if(c.pc==0x10146645&&int32_t(c.r[1])>=0&&int32_t(c.r[2])>0){native_decrypt(c);c.blocks++;if(c.error)return c.error;continue;}
        auto f=find_block(c.pc);
        if(!f){missing(c,c.pc);return 2;}
        f(c);c.blocks++;
        if(c.error)return c.error;
    }
    return 4;
}
extern "C" __declspec(dllexport) uint32_t msd_context_size(){return sizeof(Context);}
extern "C" __declspec(dllexport) uint32_t msd_runtime_kind(){return 0x414f5431;}
