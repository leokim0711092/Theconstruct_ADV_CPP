#include "ros/init.h"
#include "ros/node_handle.h"
#include <iostream>
#include <ostream>
#include <ros/ros.h>
#include <robot_commander/robot_commander.h>
#include <set>

int main(int argc, char** argv){
    ros::init(argc, argv, "Set");
    ros::NodeHandle nh;
    RobotCommander rb;
    int time;
    std::set <float> sx;
    std::set <float> sy;
    std::cout <<"Move forward time:";
    std::cin >> time;
    std::cout << std::endl;
    rb.move_forward(time);
    sx.insert(rb.get_x_position());
    sy.insert(rb.get_y_position());

    std::cout <<"Move backward time:";
    std::cin >> time;
    std::cout << std::endl;
    rb.move_backwards(time);
    sx.insert(rb.get_x_position());
    sy.insert(rb.get_y_position());
    float v_v;

    std::cout <<"Turn time:";
    std::cin >> time;
    std::cout << std::endl << "Turn velocity:";
    std::cin >> v_v;
    std::cout << std::endl;
    rb.turn(v_v,time);
    sx.insert(rb.get_x_position());
    sy.insert(rb.get_y_position());

    std::set<float, float>::iterator xx;
    std::set<float, float>::iterator yy;    
    std::cout << "The element of Vertex are:" << std::endl;
    
    for(xx = sx.begin(); xx != sx.end();xx++ ){
        std::cout <<"(" << *xx <<" , ";
        yy = sy.begin(); 
        std::cout << *yy << ")" << std::endl;
        yy++;
    }
    return 0;
}