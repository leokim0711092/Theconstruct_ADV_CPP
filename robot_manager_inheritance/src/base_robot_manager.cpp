#include "ros/node_handle.h"
#include <std_srvs/SetBool.h>
#include "robot_manager_inheritance/base_robot_manager.h"

RobotManagerBase::RobotManagerBase(ros::NodeHandle *nnh) {
  nh = nnh;
  init_config_output_srv();
}

void RobotManagerBase::init_config_output_srv() {
  config_output_srv = nh->advertiseService(
      "robot_manager_output", &RobotManagerBase::ConfigOutputCallback, this);
  ROS_INFO("Enable Output Service created");
}

bool RobotManagerBase::ConfigOutputCallback(std_srvs::SetBool::Request &req,
                                            std_srvs::SetBool::Response &res) {
  displayRobotDetails();
  if (req.data == output_enabled) {
    res.success = false;
    res.message = "Output configuration request is the same as the current "
                  "output configuration";
    return true;
  }
  res.success = true;
  output_enabled = req.data;
  if (output_enabled == false) {
    res.message = "Console output disabled.";
    ROS_INFO("Robot Manager console output disabled.");
  } else {
    res.message = "Console output enabled.";
    ROS_INFO("Robot Manager console output enabled.");
  }
  return true;
}
void RobotManagerBase::displayRobotDetails(){
    ROS_INFO("Robot Name: %s", robot_name.c_str());
    ROS_INFO("Robot Location: %s", robot_location.c_str());
}