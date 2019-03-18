let sqlite3 = require('sqlite3');
let RosbagDeserializer = require('../build/Release/rosbags2_nodejs_wrapper.node');

const deserializer = new RosbagDeserializer.Rosbag2Wrapper();

let dataDir = "/Users/andreasklintberg/personal/rosbag2_nodejs_wrapper/examples/sample.db3";
const frameNumber = 1;


db = new sqlite3.Database(dataDir);


db.serialize(function () {
  db.get("SELECT topic_id, data FROM messages WHERE id=$frameNumber", {
    $frameNumber: frameNumber
  }, function (err, res) {
    const uint8Message = new Uint8Array(res['data']);
    console.log(uint8Message);

    console.log("deserialized message", deserializer.deserializeMessage(uint8Message));
  });
});

