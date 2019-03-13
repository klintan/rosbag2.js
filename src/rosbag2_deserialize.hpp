#include <string>
//#include "rosbag2/converter.hpp"

class Rosbag2Deserialize {
 public:
  Rosbag2Deserialize(double data);
  double getValue();
  double add(double toAdd);
 private:
  double value_;
};