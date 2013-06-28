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

rosbuild_add_library(Floribot_task5_nav src/Floribot_task5_nav.cpp)
rosbuild_add_executable(floribot_task5_nav_node src/floribot_task5_nav_node.cpp)
target_link_libraries(floribot_task5_nav_node Floribot_task5_nav)
rosbuild_add_library(Florbot_task5_ptu src/Florbot_task5_ptu.cpp)
rosbuild_add_executable(florbot_task5_ptu_node src/florbot_task5_ptu_node.cpp)
target_link_libraries(florbot_task5_ptu_node Florbot_task5_ptu)

#Start of user code user defined libraries

	#uncomment if you have defined messages
	#rosbuild_genmsg()
	#uncomment if you have defined services
	#rosbuild_gensrv()
	
	#common commands for building c++ executables and libraries
	#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
	#target_link_libraries(${PROJECT_NAME} another_library)
	#rosbuild_add_boost_directories()
	#rosbuild_link_boost(${PROJECT_NAME} thread)

#End of user code
