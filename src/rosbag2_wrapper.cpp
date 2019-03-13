#include "rosbag2_wrapper.hpp"

Napi::FunctionReference Rosbag2Wrapper::constructor;

Napi::Object Rosbag2Wrapper::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Rosbag2Wrapper", {
    InstanceMethod("add", &Rosbag2Wrapper::Add),
    InstanceMethod("getValue", &Rosbag2Wrapper::GetValue),
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