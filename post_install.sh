install_name_tool -change @rpath/librosidl_typesupport_cpp.dylib $COLCON_PREFIX_PATH/lib/librosidl_typesupport_cpp.dylib ./node_modules/rosbags2_nodejs/build/Release/rosbags2_nodejs.node

install_name_tool -change @rpath/librosbag2.dylib $COLCON_PREFIX_PATH/lib/librosbag2.dylib ./node_modules/rosbags2_nodejs/build/Release/rosbags2_nodejs.node

install_name_tool -change @rpath/librosbag2_converter_default_plugins.dylib $COLCON_PREFIX_PATH/lib/librosbag2_converter_default_plugins.dylib ./node_modules/rosbags2_nodejs/build/Release/rosbags2_nodejs.node

install_name_tool -change @rpath/librosidl_generator_c.dylib $COLCON_PREFIX_PATH/lib/librosidl_generator_c.dylib ./node_modules/rosbags2_nodejs/build/Release/rosbags2_nodejs.node

install_name_tool -change @rpath/libament_index_cpp.dylib $COLCON_PREFIX_PATH/lib/libament_index_cpp.dylib ./node_modules/rosbags2_nodejs/build/Release/rosbags2_nodejs.node

install_name_tool -change @rpath/libclass_loader.dylib $COLCON_PREFIX_PATH/lib/libclass_loader.dylib ./node_modules/rosbags2_nodejs/build/Release/rosbags2_nodejs.node

install_name_tool -change @rpath/librcutils.dylib $COLCON_PREFIX_PATH/lib/librcutils.dylib ./node_modules/rosbags2_nodejs/build/Release/rosbags2_nodejs.node

install_name_tool -change @rpath/librosbag2_storage.dylib $COLCON_PREFIX_PATH/lib/librosbag2_storage.dylib ./node_modules/rosbags2_nodejs/build/Release/rosbags2_nodejs.node

install_name_tool -change @rpath/librosidl_typesupport_introspection_c.dylib $COLCON_PREFIX_PATH/lib/librosidl_typesupport_introspection_c.dylib ./node_modules/rosbags2_nodejs/build/Release/rosbags2_nodejs.node

install_name_tool -change @rpath/librosidl_typesupport_introspection_cpp.dylib $COLCON_PREFIX_PATH/lib/librosidl_typesupport_introspection_cpp.dylib ./node_modules/rosbags2_nodejs/build/Release/rosbags2_nodejs.node

install_name_tool -change @rpath/librosidl_typesupport_c.dylib $COLCON_PREFIX_PATH/lib/librosidl_typesupport_c.dylib ./node_modules/rosbags2_nodejs/build/Release/rosbags2_nodejs.node

install_name_tool -change @rpath/librmw.dylib $COLCON_PREFIX_PATH/lib/librmw.dylib ./node_modules/rosbags2_nodejs/build/Release/rosbags2_nodejs.node
