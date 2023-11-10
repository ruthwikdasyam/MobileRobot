#include "mobile_robot.h"
#include "wheeled_robot.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <random>


void RWA2::WheeledRobot::accelerate(double amount){
    while(speed_< desired_speed_){
        position_.first +=(speed_*0.5);
        speed_+= amount;
        std::this_thread::sleep_for(std::chrono::duration<double>(0.5));
    }
    battery_.discharge(position_.first);
    std::cout<<model_<<" has reached the desired speed of "<<desired_speed_ <<"m/s"<<"\n";
}

void RWA2::WheeledRobot::decelerate(double amount){
    while(speed_ <= 0){
        position_.first +=(speed_*0.5);
        speed_-= amount;
        std::this_thread::sleep_for(std::chrono::duration<double>(0.5));
    }
    battery_.discharge(position_.first);
    if(speed_!=0){brake();}
    // std::cout<<model_<<" has reached the desired speed of "<<desired_speed <<"m/s"<<"\n";
}

void RWA2::WheeledRobot::brake(){
    speed_=0.0;
}

void RWA2::WheeledRobot::rotate(double angle){
    std::cout << "WheeledRobot::"<< model_ << " rotated " << angle << "degrees."<<"\n";
}

void RWA2::WheeledRobot::print_status(){
    std::cout<<"Position: "<<position_.first<<","<<position_.second<<"\n";
    std::cout<<"Orientation: "<<orientation_<<"\n";
    std::cout<<"Current Speed: "<<speed_<<"\n";
    std::cout<<"Battery Model: "<<battery_.get_battery_model()<<"\n";
    std::cout<<"Battery Status: "<<battery_.get_current_charge()<<"\n";

    std::cout<<"number of wheels "<< number_of_wheels_ << "\n";
    std::cout << "wheel diameter "<< wheel_diameter_ <<"\n";
    std::cout << "desired speed is "<< desired_speed_ << "\n";
}

void RWA2::WheeledRobot::move(double distance, double angle){
    if(distance <= 100){
        if(distance > battery_.get_current_charge()){
            battery_.start_charging();
        }
        (*sensors_).read_data(5);
        accelerate(2);
        decelerate(2);
        brake();
        std::cout<< model_ <<" drove "<< position_.first <<"distance"<<"\n";
        print_status();
    }    
    else{
        std::cout << "This distance cannot be covered by the robot"<<"\n";
    }
}
