#include "rosbag2_deserialize.hpp"


Rosbag2Deserialize::Rosbag2Deserialize(double value){
    this->value_ = value;
}

double Rosbag2Deserialize::getValue()
{
  return this->value_;
}

std::string Rosbag2Deserialize::deserializeMessage(std::string message) {
    auto deserializer = Rosbag2Deserialize::factory.load_deserializer("cdr");
    std::string temp = "test";
    return temp;
}

double Rosbag2Deserialize::add(double toAdd)
{
  this->value_ += toAdd;
  return this->value_;
}
