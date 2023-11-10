#include "mobile_robot.h"
#include "aquatic_robot.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <random>

void RWA2::AquaticRobot::dive(double depth){
    if(is_diving_==false){
        std::cout << "Started diving"<<"\n";
        std::this_thread::sleep_for(std::chrono::duration<double>(depth/diving_speed_));
        battery_.discharge(depth);
        is_diving_=true;
        depth_ += depth;
    }
}

void RWA2::AquaticRobot::surface(){
    if(is_diving_ == true){
        std::cout << "Reaching Surface"<<"\n";
        std::this_thread::sleep_for(std::chrono::duration<double>(depth_/surface_speed_));
        battery_.discharge(depth_);
        is_diving_=false;
        depth_ =0.0;
    }
}

void RWA2::AquaticRobot::rotate(double angle){
    std::cout << "AquaticRobot::"<< model_ << " rotated " << angle << "degrees."<<"\n";
}

void RWA2::AquaticRobot::print_status(){
    std::cout<<"Position: "<<position_.first<<","<<position_.second<<"\n";
    std::cout<<"Orientation: "<<orientation_<<"\n";
    std::cout<<"Current Speed: "<<speed_<<"\n";
    std::cout<<"Battery Model: "<<battery_.get_battery_model()<<"\n";
    std::cout<<"Battery Status: "<<battery_.get_current_charge()<<"\n";

    std::cout<<"has fins "<< has_fins_ << "\n";
    std::cout << "depth is "<< depth_ <<"\n";
    std::cout << "is diving ? - "<< is_diving_ << "\n";
}

void RWA2::AquaticRobot::move(double distance, double angle){
    if(distance <= 100){
        if(2*distance > battery_.get_current_charge() && distance <= 50){
            battery_.start_charging();
        }
        (*sensors_).read_data(5);
        rotate(angle);
        dive(distance);
        surface();
        std::cout<< model_ <<" Reached a depth of "<<distance <<"meters and then Surfaced"<<"\n";
        print_status();
    }    
    else{
        std::cout << "This distance cannot be covered by the robot"<<"\n";
    }
}