#include "robot_manager_composition/system_information.h"
#include <robot_manager_composition/robot_manager_composition.h>
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_manager_using_composition");
  ros::NodeHandle nh;
  ComputerUnit comp; 
  RobotManagerComposition rm = RobotManagerComposition(&nh,comp);

  ros::spin();
}