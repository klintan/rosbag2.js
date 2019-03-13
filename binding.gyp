{
    "targets": [{
        "target_name": "rosbags2_nodejs_wrapper",
        "cflags!": [ "-fno-exceptions" ],
        "cflags": [ "-std=c++11" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "src/rosbag2_deserialize.cpp",
            "src/rosbag2_wrapper.cpp"
        ],
        'include_dirs': [
        "/Users/andreasklintberg/personal/ros2/ros2-osx-crystal-pr2/include/rcl"
        ".",
            "<!@(node -p \"require('node-addon-api').include\")"
        ],
        'libraries': [
                '-Wl,-rpath',
                '-lrcl',
                '-L/Users/andreasklintberg/personal/ros2/ros2-osx-source/install/rcutils/lib',
                '-lrcutils',
                '-L/Users/andreasklintberg/personal/ros2/ros2-osx-source/install/rmw/lib',
                '-lrmw',
                '-L/Users/andreasklintberg/personal/ros2/ros2-osx-source/install/rosidl_generator_c/lib',
                '-lrosidl_generator_c',
                '-L/Users/andreasklintberg/personal/rosbag2/install/rosbag2/lib',
                '-lrosbag2'
              ],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}
