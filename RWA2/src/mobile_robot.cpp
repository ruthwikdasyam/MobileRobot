#include "mobile_robot.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <random>



// void RWA2::MobileRobot::move(double distance, double angle)
// {
//     std::cout << "moving" << distance << " in angle " << angle <<"\n";
// }

void RWA2::MobileRobot::rotate(double angle){
    orientation_ += angle;
}

void RWA2::MobileRobot::print_status(){
    std::cout<<"Position: "<<position_.first<<","<<position_.second<<"\n";
    std::cout<<"Orientation: "<<orientation_<<"\n";
    std::cout<<"Current Speed: "<<speed_<<"\n";
    std::cout<<"Battery Model: "<<battery_.get_battery_model()<<"\n";
    std::cout<<"Battery Status: "<<battery_.get_current_charge()<<"\n";
}
