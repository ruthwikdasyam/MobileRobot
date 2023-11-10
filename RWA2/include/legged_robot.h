#pragma once
#include<iostream>
#include <memory>
#include <utility>
#include <vector>

#include "mobile_robot.h"

/**
 * @brief Namespace RWA2
 * 
 */
namespace RWA2{

class LeggedRobot : public MobileRobot {

 private:
   // ==================== attributes ====================
  double height_;
  int leg_strength_;
  int number_of_legs_;

  // ================ ===== methods ======================
  void kick();
  void jump(double amount);
  
 protected:
   // ==================== method ========================
  virtual void rotate(double angle) override;

 public:
    // ==================== constructors ====================
  /**
   * @brief Construct a new Aquatic Robot object
   * 
   */
  LeggedRobot(std::string model_name, double x, double y, double orientation, std::string battery_model, double height, int leg_strength, int number_of_legs):
    MobileRobot(model_name, x, y, orientation, battery_model){
    if (number_of_legs == 2 || 4 || 6){number_of_legs_=number_of_legs;}
    else {number_of_legs_=2;}
    height_ = height;
    leg_strength_ =leg_strength;
    }

  // WheeledRobot(std::string model_name, std::string battery_model, int number_of_wheels, int desired_speed) : WheeledRobot(model_name, 0.0, 0.0, 0.0, battery_model, number_of_wheels, desired_speed){}
  // WheeledRobot(std::string model_name, std::string battery_model, int number_of_wheels) : WheeledRobot(model_name, 0.0, 0.0, 0.0, battery_model, number_of_wheels, 50 ){}
  // WheeledRobot(std::string model_name, std::string battery_model, int desired_speed) : WheeledRobot(model_name, 0.0, 0.0, 0.0, battery_model, 2, desired_speed ){}
  LeggedRobot(std::string model_name, std::string battery_model) : LeggedRobot(model_name, 0.0, 0.0, 0.0, battery_model, 1, 8, 4){}

  // ====================== attributes =====================
  virtual void move(double distance, double angle) override;
  virtual void print_status() override;

}; 
}