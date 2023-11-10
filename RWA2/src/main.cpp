
#include<iostream>
#include "mobile_robot.h"
#include "aquatic_robot.h"
#include "aerial_robot.h"
#include "wheeled_robot.h"
#include "legged_robot.h"


int main(){

    // std::cout<< "hey";
    // auto robot1 = std::make_unique<RWA2::MobileRobot>();

    // std::cout << (*robot1).get_speed() <<"\n";
    // (*robot1).move(25.00, 32.00);

    // auto sensor1= std::make_unique<RWA2::Sensor>("OSDome");
    // std::cout << "Sensor name : " << sensor1 -> get_model() << "\n";
    // (*sensor1).read_data(5);

    // auto battery1 = std::make_unique<RWA2::Battery>("LiFePO4", 70);
    // (*battery1).get_current_charge();
    // (*battery1).start_charging();

    // auto robot1 = std::make_unique<RWA2::AquaticRobot>("SoFi","Li-ion");
    // auto robot2 = std::make_unique<RWA2::AerialRobot>("Erle-Plane","Li-ion");
    // auto robot1 = std::make_unique<RWA2::WheeledRobot>("Erle-Plane","Li-ion");
    auto robot1 = std::make_unique<RWA2::LeggedRobot>("Atlas","Li-ion");

    (*robot1).print_status();
    (*robot1).move(.5, 30);
    // (*robot1).print_status();
    // (*robot2).print_status();
    // (*robot2).move(20, 30);
    // (*robot2).print_status();





}