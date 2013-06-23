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

rosbuild_add_library(Floribot_task2 src/Floribot_task2.cpp)
rosbuild_add_executable(floribot_task2_node src/floribot_task2_node.cpp)
target_link_libraries(floribot_task2_node Floribot_task2)

#Start of user code user defined libraries

rosbuild_add_library(Codepattern src/Codepattern.cpp)
target_link_libraries(floribot_task2_node Codepattern)

rosbuild_add_library(Statediagramm src/Statediagramm.cpp)
target_link_libraries(floribot_task2_node Statediagramm)

#End of user code
