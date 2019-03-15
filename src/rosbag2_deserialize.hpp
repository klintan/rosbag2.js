#include <string>
#include "rosbag2/converter.hpp"
#include "rosbag2/converter_options.hpp"
#include "rosbag2/serialization_format_converter_factory.hpp"

class Rosbag2Deserialize {
 public:
  Rosbag2Deserialize(double data);
  rosbag2::SerializationFormatConverterFactory factory;
  std::string deserializeMessage(std::string message);

  double getValue();
  double add(double toAdd);
 private:
  double value_;
};