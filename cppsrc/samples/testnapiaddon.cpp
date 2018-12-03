#include "testnapiaddon.h"

/**
 * Wrapped Function 
 */
Napi::Object testNapiAddon::Init(Napi::Env env, Napi::Object exports) {
    exports.Set("hello", Napi::Function::New(env, testNapiAddon::HelloWrapped));
    exports.Set("add", Napi::Function::New(env, testNapiAddon::AddWrapped));
    
    return exports;
}

Napi::String testNapiAddon::HelloWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::String returnValue = Napi::String::New(env, testNapiAddon::hello());
    
    return returnValue;
}

Napi::Number testNapiAddon::AddWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    }

    Napi::Number A = info[0].As<Napi::Number>();
    Napi::Number B = info[1].As<Napi::Number>();

    int a = A.Int32Value();
    int b = B.Int32Value();

    int returnValue = testNapiAddon::add(a, b);
    
    return Napi::Number::New(env, returnValue);
}


/**
 * CPP
 */ 

std::string testNapiAddon::hello() {
    return "Hello World";
}

int testNapiAddon::add(int a, int b){
  return a + b;
}
