#pragma once

#include <utility>
#include <iostream>

#include "battery.h"
#include "sensor.h"

/**
 * @brief Namespace for RWA2
 * 
 */
namespace RWA2 { 
/**
 * @brief Namespace for MobileRbot
 * 
 */
class MobileRobot
{
    
 protected:
  // ==================== attributes ====================
  std::pair<double, double> position_;
  double orientation_;
  double speed_;
  std::string model_;

  RWA2::Battery battery_;
  std::unique_ptr<RWA2::Sensor> sensors_;

  // ==================== methods ====================
  virtual void rotate(double angle);

 public:
  // ==================== constructors ====================
 /**
  * @brief Construct a new Mobile Robot object
  * 
  */
  MobileRobot(std::string robot_model, double x, double y, double orientation, std::string battery_model):
    model_{robot_model},
    position_{std::make_pair(x,y)},
    orientation_{orientation},
    battery_{battery_model},
    speed_{0.0}{
      sensors_ =std::make_unique<RWA2::Sensor>("OSDome");
    }  //constructor

  MobileRobot(std::string robot_model, std::string battery_model): MobileRobot(robot_model, 0.0, 0.0, 0.0, battery_model){}


  // ==================== accessors ====================
  const std::pair<double, double>& get_position(){return position_;}
  const double& get_orientation(){return orientation_;}
  const double& get_speed(){return speed_;}
  const std::string& get_model(){return model_;}

  // ==================== methods ====================
  virtual void move(double distance, double angle)=0; //pure virtual
  virtual void print_status();


}; //class mobilerobot

} //namespace RWA2