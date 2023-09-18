#include "nav_msgs/Odometry.h"
#include "robot_manager_inheritance/base_robot_manager.h"
#include "ros/node_handle.h"
#include "ros/subscriber.h"
#include <ros/ros.h>
#include <string>
#include <nav_msgs/Odometry.h>
class RobotManagerMoblie: public RobotManagerBase{
    public:
        RobotManagerMoblie(ros::NodeHandle *nhb);
        void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);
    private:
        std::string odometry_topic = "/robot1/odom";
        void init_subscribe();
        float current_p_x = 0.0;
        float current_p_y = 0.0;
        ros::Subscriber odom_subscriber;
        void displayRobotDetails();
        float battery_charge_level = 0.55;
        std::string type_of_battery = "Lead acid batteries";
};