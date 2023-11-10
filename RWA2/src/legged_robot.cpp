#include "mobile_robot.h"
#include "legged_robot.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <random>


void RWA2::LeggedRobot::kick(){
    std::cout<< model_ << "kick with a strength of" << leg_strength_ <<"\n";
}

void::RWA2::LeggedRobot::jump(double amount){
    // int a{amount*100*leg_strength_};
    std::cout << model_ << "jumps at a height of" << (amount*100*leg_strength_)<<" cm above the ground"<<"\n";
    battery_.discharge(amount*100*leg_strength_);
}

void RWA2::LeggedRobot::rotate(double angle){
    std::cout << "LeggedRobot::"<< model_ << " rotated " << angle << "degrees."<<"\n";
}

void RWA2::LeggedRobot::print_status(){
    std::cout<<"Position: "<<position_.first<<","<<position_.second<<"\n";
    std::cout<<"Orientation: "<<orientation_<<"\n";
    std::cout<<"Current Speed: "<<speed_<<"\n";
    std::cout<<"Battery Model: "<<battery_.get_battery_model()<<"\n";
    std::cout<<"Battery Status: "<<battery_.get_current_charge()<<"\n";

    std::cout<<"has height "<< height_ << "\n";
    std::cout << "Leg Strength is "<< leg_strength_ <<"\n";
    std::cout << "No of legs - "<< number_of_legs_ << "\n";
}

void RWA2::LeggedRobot::move(double distance, double angle){
    if(distance <= 1 ){
        if(distance*100 > battery_.get_current_charge()){
            battery_.start_charging();
        }
        // battery_.discharge(100*distance);
        (*sensors_).read_data(5);
        rotate(angle);
        jump(distance);
        kick();
        // std::cout<< model_ <<" Reached an altitude of "<<distance <<"meters and then Landed"<<"\n";
        print_status();
    }    
    else{
        std::cout << "This distance cannot be covered by the robot"<<"\n";
    }
}