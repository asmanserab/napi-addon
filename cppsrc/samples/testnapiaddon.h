#include <napi.h>
#include <string>

namespace testNapiAddon {
    std::string hello();
    int add(int, int);
    
    Napi::Number AddWrapped(const Napi::CallbackInfo& info);
    Napi::String HelloWrapped(const Napi::CallbackInfo& info);
    Napi::Object Init(Napi::Env env, Napi::Object exports);
}