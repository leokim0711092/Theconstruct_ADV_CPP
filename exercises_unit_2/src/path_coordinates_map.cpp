#include "ros/init.h"
#include "ros/node_handle.h"
#include <iostream>
#include <ostream>
#include <ros/ros.h>
#include <robot_commander/robot_commander.h>
#include <map>
#include <utility>

struct location{
    float x;
    float y;
};

int main(int argc, char** argv){
    ros::init(argc, argv, "Set");
    ros::NodeHandle nh;
    RobotCommander rb;
    int time;
    location L1, L2, L3, L4;

    std::map <int,location> vtx; 
    std::cout <<"Move forward time:";
    std::cin >> time;
    std::cout << std::endl;
    rb.move_forward(time);
    L1.x = rb.get_x_position();
    L1.y = rb.get_y_position();
    vtx.insert(std::pair<int, location>(1,L1));

    std::cout <<"Move backward time:";
    std::cin >> time;
    std::cout << std::endl;
    rb.move_backwards(time);
    L2.x = rb.get_x_position();
    L2.y = rb.get_y_position();
    vtx.insert(std::pair<int, location>(2,L2));


    float v_v;
    std::cout <<"Turn time:";
    std::cin >> time;
    std::cout << std::endl << "Turn velocity:";
    std::cin >> v_v;
    std::cout << std::endl;
    rb.turn(v_v,time);
    L3.x = rb.get_x_position();
    L3.y = rb.get_y_position();
    vtx.insert(std::pair<int, location>(3,L3));

    std::set<float, float>::iterator xx;
    std::set<float, float>::iterator yy;    
    std::cout << "The element of Vertex are:" << std::endl;
    
    rb.stop_moving();
    L4.x = rb.get_x_position();
    L4.y = rb.get_y_position();
    vtx.insert(std::pair<int, location>(3,L4));

    std::map<int, location>::iterator ptr;
    for(ptr = vtx.begin(); ptr != vtx.end();ptr++ ){
        std::cout <<"(" << ptr -> second.x <<" , ";
        std::cout << ptr->second.y << ") -> " << ptr->first << std::endl;
    }

    return 0;
}