#include "rosbag2_deserialize.hpp"

Rosbag2Deserialize::Rosbag2Deserialize(double value){
    this->value_ = value;
}

double Rosbag2Deserialize::getValue()
{
  return this->value_;
}

double Rosbag2Deserialize::add(double toAdd)
{
  this->value_ += toAdd;
  return this->value_;
}


//rosbag2::converter_interfaces::SerializationFormatDeserializer