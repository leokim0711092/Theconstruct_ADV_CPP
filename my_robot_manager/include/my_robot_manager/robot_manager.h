#include "ros/node_handle.h"
#include "ros/service_server.h"
#include "ros/subscriber.h"
#include <ros/ros.h>
#include <string>
#include "nav_msgs/Odometry.h"
#include <std_srvs/Trigger.h>

class RobotManager{
    
    public:
        void print_specifications();
        RobotManager(ros::NodeHandle *nh, std::string topic, std::string name, std::string model);
        void odom_callback(const nav_msgs::Odometry::ConstPtr &msg); 
        static int robot_count;
        bool trigger_srv_callback(std_srvs::Trigger::Request &req,
                            std_srvs::Trigger::Response &res);
    private:
        std::string robot_name, robot_model;
        float battery_capacity_kwh = 0.16;
        int total_operation_hours = 2560;
        ros::Subscriber odom_subscriber;
        std::string odom_topic;
        float current_x_position = 0, current_y_position = 0;
        ros::ServiceServer trigger_srv;
};