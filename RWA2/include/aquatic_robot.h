#pragma once
#include<iostream>
#include <memory>
#include <utility>
#include <vector>

#include "mobile_robot.h"

namespace RWA2{

class AquaticRobot : public MobileRobot {

 private:
  // ==================== attributes ====================
  bool has_fins_;
  double depth_;
  bool is_diving_;
  double diving_speed_; //newly added
  double surface_speed_;  //newly added
  // ==================== methods ====================
  void dive(double depth);
  void surface();

 protected:
  // ==================== method ====================
  virtual void rotate(double angle) override;

 public:
   // ==================== constructors ====================
  /**
   * @brief Construct a new Aquatic Robot object
   * 
   */
  AquaticRobot(std::string model_name, double x, double y, double orientation, std::string battery_model):
    MobileRobot(model_name, x, y, orientation, battery_model){
    depth_=0.0;
    is_diving_= false;
    if (model_ == "SoFI"){
      has_fins_ = true;
      diving_speed_ = 2;
      surface_speed_ = 4;
    }
    else{
      has_fins_ = false; 
      diving_speed_ = 1;
      surface_speed_= 2;
    }
  }

  AquaticRobot(std::string model_name, std::string battery_model) : AquaticRobot(model_name, 0.0, 0.0, 0.0, battery_model){}

  // ======================= attributes ======================
  virtual void move(double distance, double angle) override;
  virtual void print_status() override;
  

}; 
}