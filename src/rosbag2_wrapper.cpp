#include "rosbag2_wrapper.hpp"

Napi::FunctionReference Rosbag2Wrapper::constructor;

Napi::Object Rosbag2Wrapper::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Rosbag2Wrapper", {
    InstanceMethod("add", &Rosbag2Wrapper::Add),
    InstanceMethod("getValue", &Rosbag2Wrapper::GetValue),
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

  int length = info.Length();
  if (length != 1 || !info[0].IsNumber()) {
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
  }

  Napi::Number value = info[0].As<Napi::Number>();
  this->rosbag2Deserialize_ = new Rosbag2Deserialize(value.DoubleValue());
}

Napi::Value Rosbag2Wrapper::GetValue(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  double num = this->rosbag2Deserialize_->getValue();
  return Napi::Number::New(env, num);
}


Napi::Value Rosbag2Wrapper::Add(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (  info.Length() != 1 || !info[0].IsNumber()) {
    Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
  }

  Napi::Number toAdd = info[0].As<Napi::Number>();
  double answer = this->rosbag2Deserialize_->add(toAdd.DoubleValue());

  return Napi::Number::New(info.Env(), answer);

 }


Napi::Value Rosbag2Wrapper::DeserializeMessage(const Napi::CallbackInfo& info) {
  assert(info[0].IsString());

  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  std::string message = info[0].As<Napi::String>().Utf8Value();

  //Napi::String message = info[0].As<Napi::String>();
  std::string deserialized_message = this->rosbag2Deserialize_->deserializeMessage(message);

  return Napi::String::New(info.Env(), deserialized_message);

 }



Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return Rosbag2Wrapper::Init(env, exports);
}

 NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll);
