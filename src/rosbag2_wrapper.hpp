#include <napi.h>
#include "rosbag2_deserialize.hpp"

class Rosbag2Wrapper : public Napi::ObjectWrap<Rosbag2Wrapper> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports); //Init function for setting the export key to JS
  Rosbag2Wrapper(const Napi::CallbackInfo& info); //Constructor to initialise

 private:
  static Napi::FunctionReference constructor; //reference to store the class definition that needs to be exported to JS
  Napi::Value GetValue(const Napi::CallbackInfo& info); //wrapped getValue function
  Napi::Value Add(const Napi::CallbackInfo& info); //wrapped add function
  Rosbag2Deserialize *rosbag2Deserialize_; //internal instance of class used to perform actual operations.
};