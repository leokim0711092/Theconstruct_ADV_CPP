#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "../../test_library/include/test_library/test_library.h"


void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
  
  float linear =msg->twist.twist.linear.x;
  float angular = msg->twist.twist.angular.z;
  Calculation(linear,angular);
  
}

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "odom_listener");


  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("odom", 1000, odomCallback);
  
  ros::spin();

  return 0;
}