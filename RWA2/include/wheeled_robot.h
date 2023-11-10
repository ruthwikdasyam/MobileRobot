#pragma once
#include<iostream>
#include <memory>
#include <utility>
#include <vector>

#include "mobile_robot.h"

namespace RWA2{

class WheeledRobot : public MobileRobot {

 private:
  // ==================== attributes ====================
  int number_of_wheels_;
  double wheel_diameter_;
  double desired_speed_;
  // ==================== methods ====================
  void accelerate(double amount);
  void decelerate(double amount);
  void brake();
  
 protected:
  // ==================== method ====================
  virtual void rotate(double angle) override;

 public:
    // ==================== constructors ====================
  /**
   * @brief Construct a new Aquatic Robot object
   * 
   */
  WheeledRobot(std::string model_name, double x, double y, double orientation, std::string battery_model, int number_of_wheels, int desired_speed):
    MobileRobot(model_name, x, y, orientation, battery_model){
    if (number_of_wheels == 2 || 4 || 6){number_of_wheels_=number_of_wheels;}
    else {number_of_wheels_=2;}
    desired_speed_=desired_speed;
    speed_= 0.0;
    }

  WheeledRobot(std::string model_name, std::string battery_model, int number_of_wheels, int desired_speed) : WheeledRobot(model_name, 0.0, 0.0, 0.0, battery_model, number_of_wheels, desired_speed){}
  WheeledRobot(std::string model_name, std::string battery_model, int number_of_wheels) : WheeledRobot(model_name, 0.0, 0.0, 0.0, battery_model, number_of_wheels, 50 ){}
  // WheeledRobot(std::string model_name, std::string battery_model, int desired_speed) : WheeledRobot(model_name, 0.0, 0.0, 0.0, battery_model, 2, desired_speed ){}
  WheeledRobot(std::string model_name, std::string battery_model) : WheeledRobot(model_name, 0.0, 0.0, 0.0, battery_model, 2, 50 ){}


  // ======================= attributes ======================
  virtual void move(double distance, double angle) override;
  virtual void print_status() override;
  
}; 
}