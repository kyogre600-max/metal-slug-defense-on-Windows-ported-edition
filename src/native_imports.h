#pragma once
#include "aot_runtime.h"
struct NativeImports;
NativeImports* msd_imports(Context*);
bool msd_native_import(Context&,uint32_t,NativeImports*);
uint32_t msd_decoder_thunk(NativeImports*,uint32_t);
