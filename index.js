const rosbagDeserializer = require('./build/Release/rosbags2_nodejs_wrapper.node');
console.log('addon',rosbagDeserializer);

module.exports = rosbagDeserializer;