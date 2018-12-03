/* cppsrc/main.cpp */
#include "samples/testnapiaddon.h"
#include "samples/classexample.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  testNapiAddon::Init(env, exports);
  return ClassExample::Init(env, exports);
}

NODE_API_MODULE(testNapiAddon, InitAll)
//NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)
