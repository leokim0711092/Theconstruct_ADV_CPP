#include "ros/init.h"
#include "ros/node_handle.h"
#include <iostream>
#include <ostream>
#include <ros/ros.h>
#include <robot_commander/robot_commander.h>
#include <unistd.h>
#include <vector>

int main(int argc,char** argv){
    ros::init(argc,argv,"heading_vector");
    ros::NodeHandle nh;
    RobotCommander rb;
    std::vector<float> headings;
    rb.move_in_circles();
    int cap;
    std::cout <<"Enter the number of heading values that you want to capture：";
    std::cin >> cap ;

    for(int i=0; i<cap;i++){
        headings.push_back(rb.get_heading());
        std::cout << "Collecting heading value：" << headings[i] << std::endl;
        usleep(1000000);
    }
    
    std::cout<< std::endl <<"Dispayed saved data" << std::endl;
    for(int i=0;i<cap;i++){
    std::cout << "Heading value" << i << "： "<< headings[i] <<std::endl;
    }
    rb.stop_moving();
    ROS_INFO("Stop the robot");
    return 0;
}