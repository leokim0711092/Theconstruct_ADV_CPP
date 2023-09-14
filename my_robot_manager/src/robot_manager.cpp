#include "my_robot_manager/robot_manager.h"
#include "ros/node_handle.h"
#include "nav_msgs/Odometry.h"

// initialize static variable
int RobotManager::robot_count = 0;

RobotManager::RobotManager(ros::NodeHandle *nh, std::string topic, std::string name, std::string model){
    odom_topic = topic;
    robot_name = name;
    robot_model =model;
    odom_subscriber = nh->subscribe(odom_topic, 1000, &RobotManager::odom_callback, this);

    // Increase counter every time a new object is created
    robot_count++;
    ROS_INFO("Robot %d created.", robot_count);
}

void RobotManager::odom_callback(const nav_msgs::Odometry::ConstPtr &msg){
    this->current_x_position = msg->pose.pose.position.x;
    this->current_y_position = msg->pose.pose.position.y;
}
void RobotManager::print_specifications() {
  ROS_INFO("Robot Name: %s", robot_name.c_str());
  ROS_INFO("Robot Model: %s", robot_model.c_str());
  ROS_INFO("Battery Capacity (kWh): %.2f", battery_capacity_kwh);
  ROS_INFO("Total Operation Hours: %d", total_operation_hours);
}

bool RobotManager::trigger_srv_callback(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res){
    ROS_INFO("%s position (x,y): %1f, %1f",robot_name.c_str() ,  this->current_x_position, this->current_y_position);
    res.success = true;
    res.message ="Position logged";
    return true;
}