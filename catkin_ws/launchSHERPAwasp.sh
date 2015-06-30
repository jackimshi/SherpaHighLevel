#!/bin/bash

source /opt/ros/indigo/setup.bash
source /home/odroid/catkin_ws/devel/setup.bash
export ROS_WORKSPACE=/home/odroid/catkin_ws
export DISPLAY=:0
xterm -hold -e roslaunch mavros uniboAMSLUSB.launch &
sleep 5
xterm -hold -e roslaunch mavros unibo_GCS.launch &
rosrun usb_cam usb_cam_node
rosrun camera_handler_SHERPA camera_handler_SHERPA
rosrun mms mms
rosrun mavros mavsys rate -all 10
rosrun mavros maparam set sysID_MYGCS 1
#xterm -hold -e mailbox.sh 
