#include "robot_manager_composition/system_information.h"
#include "ros/node_handle.h"
#include "ros/service_server.h"
#include <std_srvs/SetBool.h>
#include <robot_manager_composition/robot_manager_composition.h>

RobotManagerComposition::RobotManagerComposition(ros::NodeHandle *nnh){
    nh = nnh;
    init_config_output_srv();
}

RobotManagerComposition::RobotManagerComposition(ros::NodeHandle *nnh, ComputerUnit comp){
    nh = nnh;
    init_config_output_srv();
    computer = comp;
}

void RobotManagerComposition::init_config_output_srv(){
    config_output_srv = nh->advertiseService("robot_manager_output",&RobotManagerComposition::ConfigOutputCallback, this);
    ROS_INFO("Enable output service created");
}

bool RobotManagerComposition::ConfigOutputCallback(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res){

    if(req.data == output_enabled){
        res.success = false;
        res.message = "Output configuration request is the same as the "
                       "current output configuration.";
        return true;
    }
    res.success = true;
    output_enabled = res.success;
    if (output_enabled == false) {
        res.message = "Console output disabled.";
        ROS_INFO("Robot Manager console output disabled.");
    } else {
        res.message = "Console output enabled.";
        ROS_INFO("Robot Manager console output enabled.");
            // Print CPU and RAM information
        computer.print_info();
    }
    return true;
}