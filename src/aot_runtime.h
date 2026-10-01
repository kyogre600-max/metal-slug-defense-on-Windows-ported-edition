#pragma once
#include <cstdint>
#include <cstring>
#include <cmath>
#include <limits>
#include <algorithm>
#include <atomic>
struct Context {
    uint32_t r[16];
    uint64_t d[32];
    uint32_t n,z,c,v,fpscr,pc,error,error_address;
    uint8_t* memory;
    uint64_t blocks;
};
using Block=void(*)(Context&);
inline void nz(Context& c,uint32_t x){c.n=x>>31;c.z=x==0;}
inline uint32_t add(Context& c,uint32_t a,uint32_t b,uint32_t carry,bool flags){
    uint64_t q=uint64_t(a)+b+carry;uint32_t r=uint32_t(q);
    if(flags){nz(c,r);c.c=q>>32;c.v=((~(a^b)&(a^r))>>31)&1;}return r;
}
inline uint32_t ror(uint32_t x,uint32_t n){n&=31;return n?(x>>n)|(x<<(32-n)):x;}
inline uint32_t shift(Context& c,uint32_t x,uint32_t n,int kind,bool flags){
    uint32_t v=x,carry=c.c;
    if(kind==5){v=(c.c<<31)|(x>>1);carry=x&1;}
    else if(n){
        if(kind==1){carry=n<=32?((x>>(32-n))&1):0;v=n<32?x<<n:0;}
        if(kind==2){carry=n<=32?((x>>(n-1))&1):0;v=n<32?x>>n:0;}
        if(kind==3){carry=n<32?((x>>(n-1))&1):x>>31;v=n<32?uint32_t(int32_t(x)>>n):uint32_t(int32_t(x)>>31);}
        if(kind==4){v=ror(x,n);carry=v>>31;}
    }
    if(flags)c.c=carry;return v;
}
template<class T> inline T rd(Context& c,uint32_t a){
    if(a<0x10000000u || uint64_t(a)+sizeof(T)>0x20000000ull){c.error=3;c.error_address=a;return T{};}
    T x;std::memcpy(&x,c.memory+a-0x10000000u,sizeof x);return x;
}
template<class T> inline void wr(Context& c,uint32_t a,T x){
    if(a<0x10000000u || uint64_t(a)+sizeof(T)>0x20000000ull){c.error=3;c.error_address=a;return;}
    std::memcpy(c.memory+a-0x10000000u,&x,sizeof x);
}
inline uint32_t sbits(Context& c,int n){return uint32_t(c.d[n/2]>>((n%2)*32));}
inline void setsbits(Context& c,int n,uint32_t x){int s=(n%2)*32;c.d[n/2]=(c.d[n/2]&~(uint64_t(0xffffffff)<<s))|(uint64_t(x)<<s);}
inline float fs(Context& c,int n){uint32_t x=sbits(c,n);float f;std::memcpy(&f,&x,4);return f;}
inline double fd(Context& c,int n){double f;std::memcpy(&f,&c.d[n],8);return f;}
inline void setfs(Context& c,int n,float f){uint32_t x;std::memcpy(&x,&f,4);setsbits(c,n,x);}
inline void setfd(Context& c,int n,double f){std::memcpy(&c.d[n],&f,8);}
inline uint32_t cvti(double x,bool sign){
    if(std::isnan(x))return 0;
    if(sign){if(x>=2147483647.0)return 0x7fffffff;if(x<=-2147483648.0)return 0x80000000;return uint32_t(int32_t(x));}
    if(x<=0)return 0;if(x>=4294967295.0)return 0xffffffff;return uint32_t(x);
}
inline void fcmp(Context& c,double a,double b){
    uint32_t f=std::isnan(a)||std::isnan(b)?0x30000000:(a==b?0x60000000:(a<b?0x80000000:0x20000000));
    c.fpscr=(c.fpscr&0x0fffffff)|f;
}
inline bool cond(Context& c,int cc){
    switch(cc){case 1:return c.z;case 2:return !c.z;case 3:return c.c;case 4:return !c.c;
    case 5:return c.n;case 6:return !c.n;case 7:return c.v;case 8:return !c.v;
    case 9:return c.c&&!c.z;case 10:return !c.c||c.z;case 11:return c.n==c.v;
    case 12:return c.n!=c.v;case 13:return !c.z&&c.n==c.v;case 14:return c.z||c.n!=c.v;default:return true;}
}
inline void missing(Context& c,uint32_t a){c.error=2;c.error_address=a;c.pc=a;}
extern Block find_block(uint32_t pc);
extern void register_block(uint32_t pc,Block block);
