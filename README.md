# Rosbag2
Rosbag2 is a node.js & browser compatible module for reading Ros2 bag data files. Based on the packages https://github.com/cruise-automation/rosbag.js from Cruise Automation
It tries to keep as close to that API as possible to the extent possible.

## Installation
First make sure to source your ROS2 environment. 
`. install/setup.bash`

Then install rosbag2 using
`npm install rosbag2`

or

`yarn add rosbag2` or `yarn add https://github.com/klintan/rosbag2_nodejs.git`

Then, depending on your environment, you can import {open} from 'rosbag2' or require('rosbag2').

If you're not running your code in node.js or building for the browser using a package manager like webpack, you can import the script directly into the page:

<script src="node_modules/rosbag2/dist/web/index.js"></script>
<script>
  // use rosbag.open() here...
</script>

## Build
First make sure to source your ROS2 environment. 
`. install/setup.bash`

Then run:

`yarn build`


## Quick start
The most common way to interact with a rosbag is to read data records for a specific set of topics. The rosbag format encodes type information for topics, and rosbag reads this type information and parses the data records into JavaScript objects and arrays.

Here is an example of reading messages from a rosbag in node.js:
```
const { open } = require('rosbag');

async function logMessagesFromFooBar() {
 // open a new bag at a given file location:
 const bag = await open('../path/to/ros.bag');

 // read all messages from both the '/foo' and '/bar' topics:
 await bag.readMessages({ topics: ['/foo', '/bar'] }, (result) => {
   // topic is the topic the data record was in
   // in this case it will be either '/foo' or '/bar'
   console.log(result.topic);

   // message is the parsed payload
   // this payload will likely differ based on the topic
   console.log(result.message);
 });
}

logMessagesFromFooBar();
```

## Features
Simple CDR deserializer that can be used in NodeJS (CDR is the default serializer format used for Rosbag2). Deserialize Rosbag2 messages into objects/strings to be used in NodeJS.

Tested on Crystal-Clemmys.

Features:
- Deserialize Ros2 std_msgs::msg::String messages.
- Deserialize Ros2 sensor_msgs::msg::Image messages.
- Deserialize Ros2 sensor_msgs::msg::CompressedImage messages.
- Deserialize Ros2 sensor_msgs::msg::NavSatFix messages.
  - Outputs latitude, longitude and altitude
- Deserialize Ros2 sensor_msgs::msg::Imu messages.
  - Outputs quaternion x, y, z, w (geometry_msgs/Quaternion) part of the message.
- Base64 encodes deserialization results.

Future:
- Generalize message deserialization to easier add other message types
- Full output of message data
- Support arbitrary JSON objects results to be returned (either buffer or base64 encoded)


See the examples folder for usage. Basically what the approach would be is to read a SQLite3 DB from your Rosbag2 recording
and you pass the message type (from the metafile or the DB row) and pass this to the deserializer function. It will deserialize the binary
CDR formatted message payload, and pass pack a base64 encoded string with the message payload (see features for some limitations to some message types)

#### Installation issues
`otool -l rosbag2_nodejs/build/Release/rosbag2_nodejs.node`

`install_name_tool -id @rpath/librosbag2_converter_default_plugins.dylib <ros2-install-folder>/lib/librosbag2_converter_default_plugins.dylib`



#### About separate Rosbag2
If Rosbag2 is not installed as part of your base Ros2 environment, make sure you activate the Rosbag2 workspace as well.
Beware though, this might not work, I had to fight a bit and the `COLCON_PREFIX_PATH` will correctly add `include` and `lib` for Ros2 install folder, 
but not a vanilla rosbag2 what it seems. 

You might need to change some paths in binding.gyp.

## Usage

Make sure that your ROS2 environment is sourced before running the module, since some dependencies are dynamically linked.

See examples folder for an example on how to use the module.

The `sample.db3` is just a rosbag2 file containing:
 - one String message 
 - one Image message
 - one CompressedImage message
 - one NavSatFix message
 - one Imu message
 
 All for testing the deserialization of them and how its done.

`node examples/deserialize.js`

## Other
For some reason the CDR plugin include is in the src instead of include folder, meaning it is not moved on `colcon build`. So I put it in the include folder,
its not ideal, since it will not be updated if not updated manually. If anyone has a good idea I'm all ears.

Please feel free to add a PR for improving the code, it's not ideal at the moment, since I'm a beginner C++ programmer at best. 



