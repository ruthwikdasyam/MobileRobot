#include "mobile_robot.h"
#include "aerial_robot.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <random>

void RWA2::AerialRobot::take_off(double altitude){
    if(is_flying_==false){
        std::cout << "Started flying"<<"\n";
        battery_.discharge(altitude);
        is_flying_=true;
        std::this_thread::sleep_for(std::chrono::duration<double>(altitude/take_off_speed_));
        altitude_ += altitude;
    }
}

void RWA2::AerialRobot::land(){
    if(is_flying_==true){
        std::cout << "Started landing"<<"\n";
        std::this_thread::sleep_for(std::chrono::duration<double>(int(altitude_/take_off_speed_)));
        battery_.discharge(altitude_);
        altitude_=0.0;
        is_flying_=false;
    }
}

void RWA2::AerialRobot::rotate(double angle){
    std::cout << "AerialRobot::"<< model_ << " rotated " << angle << "degrees."<<"\n";
}

void RWA2::AerialRobot::print_status(){
    std::cout<<"Position: "<<position_.first<<","<<position_.second<<"\n";
    std::cout<<"Orientation: "<<orientation_<<"\n";
    std::cout<<"Current Speed: "<<speed_<<"\n";
    std::cout<<"Battery Model: "<<battery_.get_battery_model()<<"\n";
    std::cout<<"Battery Status: "<<battery_.get_current_charge()<<"\n";

    std::cout<<"has wings "<< has_wings_ << "\n";
    std::cout << "Altitude is "<< altitude_ <<"\n";
    std::cout << "is flying ? - "<< is_flying_ << "\n";
}


void RWA2::AerialRobot::move(double distance, double angle){
    if(distance <= 50){
        if(2*distance > battery_.get_current_charge() && distance <= 25){
            battery_.start_charging();
        }
        battery_.discharge(2*distance);
        (*sensors_).read_data(5);
        take_off(distance);
        rotate(angle);
        land();
        std::cout<< model_ <<" Reached an altitude of "<<distance <<"meters and then Landed"<<"\n";
        print_status();
    }    
    else{
        std::cout << "This distance cannot be covered by the robot"<<"\n";
    }
}