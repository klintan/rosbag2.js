#include "rosbag2_deserialize.hpp"

Rosbag2Deserialize::Rosbag2Deserialize(){}

std::string Rosbag2Deserialize::deserializeMessage(uint8_t* message, size_t size) {

  /*for (uint8_t i = 0; i < size; ++i) {
        std::cout << message[i] << std::endl;
    }*/

    //std::cout << *message << std::endl;
    //auto deserializer = Rosbag2Deserialize::factory.load_deserializer("cdr_converter");
    //converter_ = std::make_unique<rosbag2_converter_default_plugins::CdrConverter>();
    auto allocator_ = rcutils_get_default_allocator();

    //auto image_msg = std::make_shared<sensor_msgs::msg::Image>();
    std::string topic_name_ = "test";
    //const rosidl_message_type_support_t * image_ts = rosidl_typesupport_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>();

    //auto image_ts = rosidl_typesupport_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>();
    // can't use dynamic allocation

    //auto type_support = rosbag2::get_typesupport("sensors_msgs/Image", "rosidl_typesupport_cpp");

    std::shared_ptr<rcutils_uint8_array_t> ser_ros_message = rosbag2_storage::make_serialized_message(message, size);
    auto rmw_serialised_message = new rmw_serialized_message_t;
    rmw_serialised_message = ser_ros_message.get();

    sensor_msgs::msg::Image image_msg;
    auto ros_message = std::make_shared<rosbag2_introspection_message_t>();
    ros_message->time_stamp = 0;
    ros_message->message = &image_msg;
    ros_message->allocator = allocator_;


    auto serialized_message = std::make_shared<rosbag2::SerializedBagMessage>();
    serialized_message->serialized_data = ser_ros_message;
    serialized_message->topic_name = topic_name_;
    serialized_message->time_stamp = 1;

    auto type_support = rosbag2::get_typesupport("sensor_msgs/Image", "rosidl_typesupport_cpp");

    //std::cout << *serialized_message << std::endl;

    //std::cout << *ros_message << std::endl;
    converter_ = std::make_unique<rosbag2_converter_default_plugins::CdrConverter>();
    //std::cout << *type_support << std::endl;
    converter_->deserialize(serialized_message, type_support, ros_message);

    //converter_ = std::make_unique<rosbag2::converter_interfaces::SerializationFormatConverter>();

    //converter_->deserialize(serialized_message, type_support, ros_message);

    //allocator_ = rcutils_get_default_allocator();

    /*auto ros_message = std::make_shared<rosbag2_introspection_message_t>();
    ros_message->time_stamp = 0;
    ros_message->message = nullptr;
    ros_message->allocator = allocator_;*/

    //converter_->deserialize(serialized_message, type_support, ros_message);

    //uint8_t uint8_t_message = new uint8_t(message.size());
    //uint8_t *uint8_message;

    /*int i = 0;
    for(char& c : message) {
        uint8_message[i++]=c;
    }*/

    //rcutils_uint8_array_t message_uint = rcutils_uint8_array_t(array)


    auto ret = rmw_deserialize(rmw_serialised_message, type_support,&ros_message );
            if (ret != RMW_RET_OK) {
              fprintf(stderr, "failed to deserialize serialized message\n");
              return "fail";
            }
    std::cout << ret << std::endl;

    std::string temp = "test";
    return temp;
}
