#include "rosbag2_deserialize.hpp"

Rosbag2Deserialize::Rosbag2Deserialize(){}

std::string Rosbag2Deserialize::deserializeMessage(uint8_t* message, size_t size) {

    /*for (uint8_t i = 0; i < size; ++i) {
        std::cout << message[i] << std::endl;
    }*/

    auto allocator_ = rcutils_get_default_allocator();

    // Create an empty SerializedBagMessage
    auto serialized_message = std::make_shared<rosbag2::SerializedBagMessage>();

    // Fill SerializedBagMessage data with data of type "std::shared_ptr<rcutils_uint8_array_t> serialized_data;"
    std::shared_ptr<rcutils_uint8_array_t> ser_ros_message = rosbag2_storage::make_serialized_message(message, size);
    serialized_message->serialized_data = ser_ros_message;

    // add topic name
    std::string topic_name_ = "test";
    serialized_message->topic_name = topic_name_;

    // add timestamp
    serialized_message->time_stamp = 1;

    // Using the provided typesupport (which has to match the actual type of the SerializedBagMessage).
    auto type_support = rosbag2::get_typesupport("std_msgs/String", "rosidl_typesupport_cpp");


   // pre-allocate a ROS2 message to fill of the same type as the SerializedBagMessage
   auto string_msg = std::make_shared<std_msgs::msg::String>();

   // pre-allocate a empty introspection message of the same type to write to (rosbag2_introspection_message_t)
   auto type_support_introspection = rosbag2::get_typesupport("std_msgs/String", "rosidl_typesupport_introspection_cpp");
   auto ros_message = rosbag2::allocate_introspection_message(type_support_introspection, &allocator_);

   // create CDR convertor for deserialization
   auto converter_ = std::make_shared<rosbag2_converter_default_plugins::CdrConverter>();
   converter_->deserialize(serialized_message, type_support, ros_message);

   // cast to message type
   auto data = static_cast<std_msgs::msg::String *>(ros_message->message);

    return data->data ;
}
