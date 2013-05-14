#! /bin/bash
source /opt/ros/electric/setup.sh

export ROS_MASTER_URI=http://192.168.0.2:11311/
export ROS_IP=192.168.0.2

sleep 5
roslaunch floribot_robot floribot.launch 
