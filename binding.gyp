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
            "/Users/andreasklintberg/personal/rosbag2/install/rosbag2/include/",
            "/Users/andreasklintberg/personal/rosbag2/install/rosbag2_storage/include",
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
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
        'conditions': [
        [
          'OS=="mac"',
          {
            'defines': [
              'OS_MACOS'
            ],
            'include_dirs': [
              "<!@(node -e \"console.log(process.env.COLCON_PREFIX_PATH.replace(/:/, '/include/ ') + '/include/')\")",
            ],
            'library_dirs': [
                "<!@(node -e \"console.log(process.env.COLCON_PREFIX_PATH.replace(/:/, '/lib/ ') + '/lib/')\")",
            ],
            'xcode_settings': {
              'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
              'CLANG_CXX_LIBRARY': 'libc++',
              'ALWAYS_SEARCH_USER_PATHS': 'NO'
            }
          }
        ]
        ]
    }]
}
