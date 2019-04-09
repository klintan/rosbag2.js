install_name_tool -change @rpath/librosidl_typesupport_cpp.dylib $COLCON_PREFIX_PATH/lib/librosidl_typesupport_cpp.dylib ./build/Release/rosbag2_nodejs.node

install_name_tool -change @rpath/librosbag2.dylib $COLCON_PREFIX_PATH/lib/librosbag2.dylib ./build/Release/rosbag2_nodejs.node

install_name_tool -change @rpath/librosbag2_converter_default_plugins.dylib $COLCON_PREFIX_PATH/lib/librosbag2_converter_default_plugins.dylib ./build/Release/rosbag2_nodejs.node

install_name_tool -change @rpath/librosidl_generator_c.dylib $COLCON_PREFIX_PATH/lib/librosidl_generator_c.dylib ./build/Release/rosbag2_nodejs.node

install_name_tool -change @rpath/libament_index_cpp.dylib $COLCON_PREFIX_PATH/lib/libament_index_cpp.dylib ./build/Release/rosbag2_nodejs.node

install_name_tool -change @rpath/libclass_loader.dylib $COLCON_PREFIX_PATH/lib/libclass_loader.dylib ./build/Release/rosbag2_nodejs.node

install_name_tool -change @rpath/librcutils.dylib $COLCON_PREFIX_PATH/lib/librcutils.dylib ./build/Release/rosbag2_nodejs.node

install_name_tool -change @rpath/librosbag2_storage.dylib $COLCON_PREFIX_PATH/lib/librosbag2_storage.dylib ./build/Release/rosbag2_nodejs.node

install_name_tool -change @rpath/librosidl_typesupport_introspection_c.dylib $COLCON_PREFIX_PATH/lib/librosidl_typesupport_introspection_c.dylib ./build/Release/rosbag2_nodejs.node

install_name_tool -change @rpath/librosidl_typesupport_introspection_cpp.dylib $COLCON_PREFIX_PATH/lib/librosidl_typesupport_introspection_cpp.dylib ./build/Release/rosbag2_nodejs.node

install_name_tool -change @rpath/librosidl_typesupport_c.dylib $COLCON_PREFIX_PATH/lib/librosidl_typesupport_c.dylib ./build/Release/rosbag2_nodejs.node

install_name_tool -change @rpath/librmw.dylib $COLCON_PREFIX_PATH/lib/librmw.dylib ./build/Release/rosbag2_nodejs.node
