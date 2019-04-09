const RosbagDeserializer = require('./build/Release/rosbag2_nodejs.node');

const deserializer = new RosbagDeserializer.Rosbag2Wrapper();
console.log("test call to deserializer", deserializer.deserializeMessage("test"));

module.exports = RosbagDeserializer;