#include <ros/ros.h>
#include <string>

class RobotManager{
    
    public:
        std::string robot_name, robot_model;
        float battery_capacity_kwh = 0.16;
        int total_operation_hours = 2560;
        void print_specifications();
};