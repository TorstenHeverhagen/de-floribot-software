# @generated

cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

set (CMAKE_VERBOSE_MAKEFILE 1)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

rosbuild_add_library(Floribot_accu_watchdog src/Floribot_accu_watchdog.cpp)
rosbuild_add_executable(floribot_accu_watchdog_node src/floribot_accu_watchdog_node.cpp)
target_link_libraries(floribot_accu_watchdog_node Floribot_accu_watchdog)
rosbuild_add_library(simulink_floribot_accu_watchdog src/simulink/floribot_accu_watchdog_ert_rtw/floribot_accu_watchdog.cpp)
target_link_libraries(floribot_accu_watchdog_node simulink_floribot_accu_watchdog)
rosbuild_add_library(Floribot_base src/Floribot_base.cpp)
rosbuild_add_executable(floribot_base_node src/floribot_base_node.cpp)
target_link_libraries(floribot_base_node Floribot_base)

#Start of user code user defined libraries
	include_directories("/home/floribot/ros_workspace/phidgets/msg_gen/cpp/include")

	rosbuild_add_library(explorer_comms src/explorer_comms.cc)
	target_link_libraries(floribot_base_node explorer_comms)

#End of user code
