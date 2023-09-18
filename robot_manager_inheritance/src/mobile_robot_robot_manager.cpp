#include "ros/node_handle.h"
#include <ros/ros.h>
#include <robot_manager_inheritance/mobile_robot_robot_manager.h>


RobotManagerMoblie::RobotManagerMoblie(ros::NodeHandle *nhb){
    nh = nhb;
    init_config_output_srv();
    init_subscribe();
}

void RobotManagerMoblie::init_subscribe(){
    odom_subscriber= nh->subscribe(odometry_topic, 1000, &RobotManagerMoblie::odom_callback, this);
    ROS_INFO("Odometry subscriber created");
}

void RobotManagerMoblie::odom_callback(const nav_msgs::Odometry::ConstPtr &msg){ 
    if(output_enabled == true ){
        std::cout <<"Hello"<< std::endl;
        current_p_x = msg -> pose.pose.position.x;
        current_p_y = msg -> pose.pose.position.y;
        ROS_INFO("Position (x,y): %lf , %lf", current_p_x,
            current_p_y);
    }

}
void RobotManagerMoblie::displayRobotDetails() {
  ROS_INFO("Robot Name: %s", robot_name.c_str());
  ROS_INFO("Robot Location: %s", robot_location.c_str());
  ROS_INFO("Battery Charge Level: %f", battery_charge_level);
  ROS_INFO("Type of Battery: %s", type_of_battery.c_str());
}