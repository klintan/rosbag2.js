#include <napi.h>
#include "rosbag2_deserialize.hpp"

class Rosbag2Wrapper : public Napi::ObjectWrap<Rosbag2Wrapper> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  Rosbag2Wrapper(const Napi::CallbackInfo& info); //Constructor to initialise

 private:
  static Napi::FunctionReference constructor;
  Napi::Value GetValue(const Napi::CallbackInfo& info);
  Napi::Value Add(const Napi::CallbackInfo& info);
  Napi::Value DeserializeMessage(const Napi::CallbackInfo& info);
  Rosbag2Deserialize *rosbag2Deserialize_;
};