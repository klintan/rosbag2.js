{
    "targets": [{
        "target_name": "rosbags2_nodejs",
        "cflags!": [ "-fno-exceptions" ],
        "cflags": [ "-std=c++14" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "src/rosbag2_deserialize.cpp",
            "src/rosbag2_wrapper.cpp",
            "src/rosbag2_wrapper.hpp",
            "src/rosbag2_deserialize.hpp",
            "src/base64.h",
            "src/base64.cpp"
        ],
        'include_dirs': [
            "/Users/andreasklintberg/personal/rosbag2/rosbag2_converter_default_plugins/src/rosbag2_converter_default_plugins/cdr",
            "/Users/andreasklintberg/personal/ros2/ros2-osx-crystal-pr2/include/rosidl_generator_cpp",
            "/Users/andreasklintberg/personal/ros2/ros2-osx-crystal-pr2/include/rosidl_typesupport_cpp",
            "/Users/andreasklintberg/personal/ros2/ros2-osx-crystal-pr2/include/rosidl_typesupport_c",
            "/Users/andreasklintberg/personal/rosbag2/install/rosbag2/include/",
            "/Users/andreasklintberg/personal/rosbag2/install/rosbag2_storage/include",
            ".",
            "<!@(node -p \"require('node-addon-api').include\")"
        ],
        'libraries': [
                '-Wl,-rpath',
                '-lrcl',
                '-lrcutils',
                '-lrmw',
                '-lrosidl_generator_c',
                '-lrosidl_typesupport_cpp',
                '-lrosidl_typesupport_c',
                '-L/Users/andreasklintberg/personal/rosbag2/install/rosbag2/lib',
                '-lrosbag2',
                '-L/Users/andreasklintberg/personal/rosbag2/install/rosbag2_converter_default_plugins/lib',
                '-lrosbag2_converter_default_plugins'
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
