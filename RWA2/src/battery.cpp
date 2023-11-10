
#include "battery.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <random>


void RWA2::Battery::start_charging(){
    if(is_charging_ == false)
    {
        is_charging_ = true;
        std::cout << "Battery " << model_ <<" is charging...."<< '\n';
        std::this_thread::sleep_for(std::chrono::seconds((100 - current_charge_)/charging_rate_));
        current_charge_ = 100;
        // std::cout<<"Charging complete"<<"\n";
        RWA2::Battery::stop_charging();
    }
}

void RWA2::Battery::stop_charging(){
    is_charging_ = false;
    std::cout << "Battery "<< model_ <<" is fully charged"<<"/n";
}

void RWA2::Battery::discharge(double amount){
    current_charge_ -= amount; 
}