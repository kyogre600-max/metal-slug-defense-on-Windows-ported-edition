// stb_vorbis is compiled directly for Windows x64; attribution is bundled.
#define STB_VORBIS_NO_STDIO
#include "third_party/stb_vorbis.c"
#include <cstdint>
#include <cstring>
#include <limits>
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
