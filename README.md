# Rosbags2 NodeJS wrapper

Simple CDR deserializer that can be used in NodeJS (CDR is the default serializer format used for Rosbags2). Deserialize Rosbag2 messages into objects/strings to be used in NodeJS.

Features:
- Deserialize Ros2 std_msgs::msg::String messages.

Future:
- Deserialize Ros2 sensor_msgs::msg::Image messages.
- Deserialize Ros2 sensor_msgs::msg::NavSatFix messages.
- Generalize message deserialization to easier add other message types
- Base64 encode deserialization results.
- Support arbitrary JSON objects results to be returned (either buffer or base64 encoded)



## Installation
First make sure to source your ROS2 environment. 
`. install/setup.bash`

If Rosbag2 is not installed as part of your base Ros2 environment, make sure you activate the Rosbag2 workspace as well.

Then run:

`yarn build`

You might need to change some paths in binding.gyp, 

## Usage

Make sure that your ROS2 environment is sourced before running the module, since some dependencies are dynamically linked.

See examples folder for an example on how to use the module.

The `sample.db3` is just a rosbag2 file containing one string message and one image message for testing.

## Other

Please feel free to add a PR for improving the code, it's not ideal at the moment, since I'm a beginner C++ programmer at best. 



