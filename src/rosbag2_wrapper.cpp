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
  //assert(info[0].IsString());

  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  //std::string message = info[0].As<Napi::String>().Utf8Value();
  Napi::TypedArrayOf<uint8_t> message = info[0].As<Napi::TypedArrayOf<uint8_t>>();

  std::cout << message.ElementLength() << std::endl;

  uint8_t *uint8Message = message.Data();

  /*for (uint8_t i = 0; i < message.ElementLength(); ++i) {
        std::cout << uint8Message[i] << std::endl;
    }*/

  /*for (uint8_t *p = message.Data(); *p; ++p) {
           std::cout << *p << std::endl;
      }*/

  //uint8_t *buffer= new uint8_t[message.ElementLength()];

  //memcpy(buffer, message, message.ElementLength());
  //Object obj = Object::New(env);

  //size_t messageSize = sizeof info[0];
  //Napi::Buffer<rosbag2::SerializedBagMessage> messageBuffer = Napi::Buffer<rosbag2::SerializedBagMessage>(env, info[0]);
  //Napi::Buffer<Napi::String> messageBuffer = info[0].As<Napi::Buffer<Napi::String>>();
  //Napi::String message = info[0].As<Napi::String>();

  std::string deserialized_message = this->rosbag2Deserialize_->deserializeMessage(message.Data(), message.ElementLength());
  //std::string deserialized_message = "test";
  return Napi::String::New(info.Env(), deserialized_message);

 }



Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return Rosbag2Wrapper::Init(env, exports);
}

 NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll);
