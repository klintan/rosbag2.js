#include <napi.h>
#include "rosbag2_deserialize.hpp"
#include "rosbag2/converter_interfaces/serialization_format_converter.hpp"
#include "rosbag2/typesupport_helpers.hpp"
#include "rosbag2/types/introspection_message.hpp"

class Rosbag2Wrapper : public Napi::ObjectWrap<Rosbag2Wrapper> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  Rosbag2Wrapper(const Napi::CallbackInfo& info); //Constructor to initialise

 private:
  static Napi::FunctionReference constructor;
  Napi::Value DeserializeMessage(const Napi::CallbackInfo& info);
  Rosbag2Deserialize *rosbag2Deserialize_;
};