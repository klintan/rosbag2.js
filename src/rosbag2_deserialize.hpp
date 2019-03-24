#include <string>
#include <iostream>
#include <memory>

#include "rosbag2/converter.hpp"
#include "rosbag2/converter_options.hpp"

#include "rosbag2_storage/ros_helper.hpp"
#include "rosbag2_storage/serialized_bag_message.hpp"
#include "rcutils/strdup.h"

#include "cdr_converter.hpp"

#include "rosbag2/converter_interfaces/serialization_format_converter.hpp"
#include "rosbag2/typesupport_helpers.hpp"
#include "rosbag2/types/introspection_message.hpp"

#include "rosidl_typesupport_cpp/message_type_support.hpp"

#include "rcl/types.h"

#include "rmw/rmw.h"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "sensor_msgs/msg/compressed_image.hpp"
#include "sensor_msgs/msg/nav_sat_fix.hpp"
#include "sensor_msgs/msg/imu.hpp"

#include "base64.h"

class Rosbag2Deserialize {
 public:
  Rosbag2Deserialize();
  std::string deserializeMessage(uint8_t * message, size_t size, std::string message_type, std::string topic);

 private:
 std::string encode_message(std::shared_ptr<rosbag2_introspection_message_t> introspection_message, std::string message_type);
};