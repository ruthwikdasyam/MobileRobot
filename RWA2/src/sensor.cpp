
#include "sensor.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <random>



void RWA2::Sensor::read_data(unsigned int duration){

    std::cout << "Starting reading from sensor " << model_ << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(duration));
    //generate random 50 double's between 1 and 30
    for (int i=1; i<50; i++){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(1.0, 30.0);
        data_.at(i)=dis(gen);
    }
    std::cout << "Completed Reading Data from" << model_ << '\n';
    // std::cout << "Sensor" << data_.at(5) <<"\n";
    // stop_reading();
}