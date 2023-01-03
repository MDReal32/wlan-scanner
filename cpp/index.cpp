#include <napi.h>
#include <string>

#include "core.h"

Napi::String root_handler(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  std::string data = get_data(false, true);
  return Napi::String::New(env, data);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "getAccessPointList"), Napi::Function::New(env, root_handler));
  return exports;
}

NODE_API_MODULE(root_handler, Init);
