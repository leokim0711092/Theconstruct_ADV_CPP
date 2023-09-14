#include "ros/node_handle.h"
#include "ros/subscriber.h"
#include <ros/ros.h>
#include <string>
#include "nav_msgs/Odometry.h"

class RobotManager{
    
    public:
        void print_specifications();
        RobotManager(ros::NodeHandle *nh, std::string topic, std::string name, std::string model);
        void odom_callback(const nav_msgs::Odometry::ConstPtr &msg); 
        static int robot_count;
    private:
        std::string robot_name, robot_model;
        float battery_capacity_kwh = 0.16;
        int total_operation_hours = 2560;
        ros::Subscriber odom_subscriber;
        std::string odom_topic;
};