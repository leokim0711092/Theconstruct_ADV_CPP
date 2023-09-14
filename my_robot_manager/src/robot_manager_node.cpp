#include "my_robot_manager/robot_manager.h"
#include "ros/init.h"
#include "ros/node_handle.h"
#include "nav_msgs/Odometry.h"
#include <iostream>
#include <std_srvs/Trigger.h>


int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_manager");
  ros::NodeHandle nh;
  RobotManager rm = RobotManager(&nh, "/robot1/odom", "Turty", "Turtlebot3");
  rm.print_specifications();
  ros::spin();
}