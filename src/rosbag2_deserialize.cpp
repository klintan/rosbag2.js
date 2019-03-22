#include "rosbag2_deserialize.hpp"

Rosbag2Deserialize::Rosbag2Deserialize(){}

std::string Rosbag2Deserialize::deserializeMessage(uint8_t* message, size_t size, std::string message_type, std::string topic) {
    auto allocator_ = rcutils_get_default_allocator();

    // Create an empty SerializedBagMessage
    auto serialized_message = std::make_shared<rosbag2::SerializedBagMessage>();

    // Fill SerializedBagMessage data with data of type "std::shared_ptr<rcutils_uint8_array_t> serialized_data;"
    std::shared_ptr<rcutils_uint8_array_t> ser_ros_message = rosbag2_storage::make_serialized_message(message, size);
    serialized_message->serialized_data = ser_ros_message;

    // add topic name
    serialized_message->topic_name = topic;

    // add timestamp
    serialized_message->time_stamp = 1;

    // Using the provided typesupport (which has to match the actual type of the SerializedBagMessage).
    auto type_support = rosbag2::get_typesupport(message_type, "rosidl_typesupport_cpp");

   // pre-allocate a empty introspection message of the same type to write to (rosbag2_introspection_message_t)
   auto type_support_introspection = rosbag2::get_typesupport(message_type, "rosidl_typesupport_introspection_cpp");
   auto introspection_message = rosbag2::allocate_introspection_message(type_support_introspection, &allocator_);

   // create CDR convertor for deserialization
   auto converter_ = std::make_shared<rosbag2_converter_default_plugins::CdrConverter>();
   converter_->deserialize(serialized_message, type_support, introspection_message);


   // encode arbitrary message
   auto encoded = Rosbag2Deserialize::encode_message(introspection_message, message_type);

    return encoded;
}


std::string Rosbag2Deserialize::encode_message(std::shared_ptr<rosbag2_introspection_message_t> introspection_message, std::string message_type) {
      if (message_type == "std_msgs/String") {
               auto str_message = static_cast<std_msgs::msg::String *>(introspection_message->message);
               return base64_encode(reinterpret_cast<const unsigned char*>(str_message->data.c_str()), str_message->data.length());
      }
      if (message_type == "sensor_msgs/Image") {
               auto img_message = static_cast<sensor_msgs::msg::Image *>(introspection_message->message);
               //vector<unsigned char, allocator<unsigned char> >
               //reinterpret_cast<char*>(buf.data());
               return base64_encode(reinterpret_cast<const unsigned char*>(img_message->data.data()), img_message->data.size());
      }

      throw std::invalid_argument( "Message type not valid or not implemented" );
}

