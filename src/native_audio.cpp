// stb_vorbis is compiled directly for Windows x64; attribution is bundled.
#define STB_VORBIS_NO_STDIO
#include "third_party/stb_vorbis.c"
#include <cstdint>
#include <cmath>
#include <cstring>
#include <limits>
#include <numeric>
#include <vector>
extern "C" __declspec(dllexport) int32_t msd_vorbis_decode(const uint8_t* input,int32_t length,
        int32_t* channels,int32_t* rate,int16_t** output){
    *output=nullptr;*channels=0;*rate=0;int error=0;
    auto decoder=stb_vorbis_open_memory(input,length,&error,nullptr);
    if(!decoder)return -1;
    auto info=stb_vorbis_get_info(decoder);uint32_t frames=stb_vorbis_stream_length_in_samples(decoder);
    uint64_t samples=uint64_t(frames)*uint32_t(info.channels);
    if(!frames||info.channels<1||info.channels>2||samples>uint64_t(std::numeric_limits<int32_t>::max())){
        stb_vorbis_close(decoder);return -2;
    }
    auto pcm=static_cast<int16_t*>(std::calloc(size_t(samples),sizeof(int16_t)));
    if(!pcm){stb_vorbis_close(decoder);return -2;}
    auto decoded=stb_vorbis_get_samples_short_interleaved(decoder,info.channels,pcm,int(samples));
    stb_vorbis_close(decoder);
    if(decoded<1){std::free(pcm);return -1;}
    *channels=info.channels;*rate=int32_t(info.sample_rate);*output=pcm;return int32_t(frames);
}
extern "C" __declspec(dllexport) void msd_vorbis_free(void* output){std::free(output);}
// The native mixer only outputs PCM in the format of the 655 original sounds (16 kHz stereo); other rates
// and mono are silent. Converts interleaved PCM to target_rate stereo with a Blackman-windowed sinc
// low-pass (12 zero crossings each side, cutoff 0.46 of the lower rate). Output is freed by msd_vorbis_free.
// The input position of output sample i is t=i*rate/target_rate = n+r/target_rate (n=floor, r=remainder of the
// integer product). r takes target_rate/gcd(rate,target_rate) values (160 for 44.1 kHz to 16 kHz), so the
// filter taps are computed once per value (2026-10-13; computing the window and sinc for every tap of every
// output sample took about 140 ms per second of 44.1 kHz audio). Very large phase counts use the direct form.
extern "C" __declspec(dllexport) int32_t msd_pcm_convert(const int16_t* input,int32_t frames,int32_t channels,
        int32_t rate,int32_t target_rate,int16_t** output){
    *output=nullptr;
    if(!input||frames<1||channels<1||channels>2||rate<1||target_rate<1)return -1;
    int64_t count=(int64_t(frames)*target_rate+rate-1)/rate;
    if(count<1||count*2>int64_t(std::numeric_limits<int32_t>::max()))return -2;
    auto pcm=static_cast<int16_t*>(std::calloc(size_t(count)*2,sizeof(int16_t)));
    if(!pcm)return -2;
    const double pi=3.14159265358979323846;
    double fc=0.46*double(rate<target_rate?rate:target_rate)/rate;   // cycles per input sample
    double half=12.0/(2.0*fc);                                         // half width in input samples
    auto kernel=[&](double d){
        double x=d/half;
        double w=0.42+0.5*std::cos(pi*x)+0.08*std::cos(2*pi*x);
        double s=d==0?1.0:std::sin(2*pi*fc*d)/(2*pi*fc*d);
        return w*s;
    };
    struct Phase{int64_t j0;int64_t taps;size_t at;};
    int64_t step=std::gcd(int64_t(rate),int64_t(target_rate)),phases=target_rate/step;
    std::vector<Phase> phase;std::vector<double> table;
    if(phases<=8192){
        phase.reserve(size_t(phases));
        for(int64_t q=0;q<phases;++q){
            double f=double(q*step)/target_rate;
            int64_t j0=int64_t(std::floor(f-half))+1,j1=int64_t(std::floor(f+half));
            phase.push_back({j0,j1-j0+1,table.size()});
            for(int64_t j=j0;j<=j1;++j)table.push_back(kernel(f-double(j)));
        }
    }
    for(int64_t i=0;i<count;++i){
        double acc[2]={0,0},norm=0;
        if(!phase.empty()){
            int64_t product=i*int64_t(rate),n=product/target_rate;
            const Phase& ph=phase[size_t(product%target_rate/step)];
            const double* h=table.data()+ph.at;
            for(int64_t m=0;m<ph.taps;++m){
                int64_t k=n+ph.j0+m;
                if(k<0||k>=frames)continue;
                norm+=h[m];
                const int16_t* src=input+k*channels;
                acc[0]+=h[m]*src[0];acc[1]+=h[m]*src[channels-1];
            }
        }else{
            double t=double(i)*rate/target_rate;
            int64_t k0=int64_t(std::floor(t-half))+1,k1=int64_t(std::floor(t+half));
            for(int64_t k=k0;k<=k1;++k){
                if(k<0||k>=frames)continue;
                double h=kernel(t-double(k));norm+=h;
                const int16_t* src=input+k*channels;
                acc[0]+=h*src[0];acc[1]+=h*src[channels-1];
            }
        }
        for(int c=0;c<2;++c){
            double v=norm!=0?acc[c]/norm:0;
            pcm[i*2+c]=int16_t(v>32767?32767:v<-32768?-32768:std::lround(v));
        }
    }
    *output=pcm;return int32_t(count);
}
// Content sound "gain" (content_sounds.py): scales int16 PCM in place. Above KNEE of full scale the excess is
// compressed with tanh, so loud peaks round off instead of clipping. Returns the number of samples past the knee.
extern "C" __declspec(dllexport) int32_t msd_pcm_gain(int16_t* pcm,int32_t samples,double gain){
    if(!pcm||samples<1||!(gain>0))return -1;
    const double knee=0.6,full=32767.0;int32_t limited=0;
    for(int32_t i=0;i<samples;++i){
        double v=pcm[i]*gain/full,a=std::fabs(v);
        if(a>knee){a=knee+(1-knee)*std::tanh((a-knee)/(1-knee));++limited;}
        double out=(v<0?-a:a)*full;
        pcm[i]=int16_t(out>32767?32767:out<-32768?-32768:std::lround(out));
    }
    return limited;
}
