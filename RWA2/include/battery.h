#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

/**
 * @brief Namespace for RWA2 Project
 * 
 */
namespace RWA2{
/**
 * @brief Class for the Battery
 * 
 */
class Battery{

 private:
  // ==================== attributes ====================
  std::string model_;
  int current_charge_;
  bool is_charging_;
  int charging_rate_;
  // ==================== Methods ====================
  void stop_charging();

 public:
  // ==================== constructor ====================
  // Battery(std::string model_name, int current_charge, int charging_rate) : model_{model_name}, current_charge_{current_charge}, charging_rate_{charging_rate_}
  // {
  //   is_charging_= false;
  // }
  Battery(std::string model_name) : model_{model_name}
  {
    current_charge_ = 100;
    is_charging_= false;
    if (model_ == "LiFePO4"){charging_rate_ =4;}
    if (model_ == "Li-ion"){charging_rate_ =2;}
  }  

  // ==================== accessors ====================
  const int& get_current_charge(){return current_charge_;}
  const std::string& get_battery_model(){return model_;}

  // ==================== Methods ====================
  void start_charging();
  void discharge(double amount);
};

}