#include <string>
#include <iostream>
#include <memory>

#include "rosbag2/converter.hpp"
#include "rosbag2/converter_options.hpp"
#include "rosbag2/serialization_format_converter_factory.hpp"

#include "rosbag2_storage/ros_helper.hpp"
#include "rosbag2_storage/serialized_bag_message.hpp"
#include "rcutils/strdup.h"

#include "cdr_converter.hpp"



#include "rosbag2/converter_interfaces/serialization_format_converter.hpp"
#include "rosbag2/typesupport_helpers.hpp"
#include "rosbag2/types/introspection_message.hpp"

//#include "rosidl_generator_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
//#include "rosidl_generator_c/message_type_support_struct.h"

#include "rcl/types.h"

//#include "rclcpp/rclcpp.hpp"

#include "rmw/rmw.h"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/image.hpp"

class Rosbag2Deserialize {
 public:
  Rosbag2Deserialize();
  rosbag2::SerializationFormatConverterFactory factory;
  std::string deserializeMessage(uint8_t * message, size_t size);

 private:
   //std::unique_ptr<rosbag2::converter_interfaces::SerializationFormatConverter> converter_;
   //rcutils_allocator_t allocator_;
   //std::unique_ptr<rosbag2_converter_default_plugins::CdrConverter> converter_;
   //std::unique_ptr<rosbag2::converter_interfaces::SerializationFormatConverter> converter_;
   //std::unique_ptr<rosbag2::Converter> converter_;
   //rosbag2_converter_default_plugins::CdrConverter *converter_;
   //rosbag2::converter_interfaces::SerializationFormatConverter *converter_;


   //rosbag2::ConverterOptions converter_options_;
};