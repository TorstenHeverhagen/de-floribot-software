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

rosbuild_add_library(Floribot_task3 src/Floribot_task3.cpp)
rosbuild_add_executable(floribot_task3_node src/floribot_task3_node.cpp)
target_link_libraries(floribot_task3_node Floribot_task3)
rosbuild_add_library(simulink_floribot_task3 src/simulink/floribot_task3_ert_rtw/floribot_task3.cpp)
target_link_libraries(floribot_task3_node simulink_floribot_task3)

#Start of user code user defined libraries

rosbuild_add_library(task3_histogramm src/Histogramm.cpp)
target_link_libraries(floribot_task3_node task3_histogramm)

#End of user code
