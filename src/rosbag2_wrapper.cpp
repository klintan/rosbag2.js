#include "rosbag2_wrapper.hpp"

Napi::FunctionReference Rosbag2Wrapper::constructor;

Napi::Object Rosbag2Wrapper::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Rosbag2Wrapper", {
    InstanceMethod("deserializeMessage", &Rosbag2Wrapper::DeserializeMessage),
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("Rosbag2Wrapper", func);
  return exports;
}

Rosbag2Wrapper::Rosbag2Wrapper(const Napi::CallbackInfo& info) : Napi::ObjectWrap<Rosbag2Wrapper>(info)  {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
}


Napi::Value Rosbag2Wrapper::DeserializeMessage(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  Napi::TypedArrayOf<uint8_t> message = info[0].As<Napi::TypedArrayOf<uint8_t>>();
  Napi::String message_type = info[1].As<Napi::String>();
  Napi::String topic = info[2].As<Napi::String>();

  /* there is a bug here in to get the size of the message, deserialization gets out of memory if we don't over-allocate*/
  std::string deserialized_message = this->rosbag2Deserialize_->deserializeMessage(message.Data(), message.ElementLength()+1000, message_type, topic);

  return Napi::String::New(info.Env(), deserialized_message);

}


Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return Rosbag2Wrapper::Init(env, exports);
}

 NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll);
