#include "my_robot_manager/robot_manager.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_manager");
  RobotManager rm;
  rm.robot_name = "my_robot";
  rm.robot_model = "TurtleBot3";
  rm.print_specifications();
}