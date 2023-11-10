#pragma once
#include<iostream>
#include <memory>
#include <utility>
#include <vector>
#include "mobile_robot.h"

namespace RWA2{

class AerialRobot : public MobileRobot {

 private:
  // ==================== attributes ====================
  bool has_wings_;
  double altitude_;
  bool is_flying_;
  double take_off_speed_; //newly added
  double land_speed_; //newly added

  // ==================== methods ====================
  void take_off(double altitude);
  void land();
 
 protected:
  // ==================== method ====================
  virtual void rotate(double angle) override;

 public:
  // ==================== constructors ====================
  /**
   * @brief Construct a new Aquatic Robot object
   * 
   */
  AerialRobot(std::string model_name, double x, double y, double orientation, std::string battery_model):
    MobileRobot(model_name, x, y, orientation, battery_model){
    altitude_=0.0;
    is_flying_= false;
    if (model_ == "Erle-Plane"){
      has_wings_ = true;
      take_off_speed_ = 3;
      land_speed_ = 1.5;
    }
    else{
      has_wings_ = false; 
      take_off_speed_ = 4;
      land_speed_ = 2;
    }
  }

  AerialRobot(std::string model_name, std::string battery_model) : AerialRobot(model_name, 0.0, 0.0, 0.0, battery_model){}

  // ======================= attributes ======================  
  virtual void move(double distance, double angle) override;
  virtual void print_status() override;
  

}; 
}