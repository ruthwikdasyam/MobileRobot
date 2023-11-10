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
 * @brief Class for the sensor
 * 
 */
class Sensor{

 private:
  // ==================== attributes ====================
  std::string model_;
  std::array<double, 50> data_;

 public:
  // ==================== constructor ====================
  Sensor(std::string model_name) : model_{model_name}{}

  // ==================== accessors ====================
  const std::string& get_model(){return model_;}

//   const std::array<double, 50>& get_data(){return data_;}
  // ==================== methods ====================
  
  void update_data();
  /**
   * @brief start reading sensor data
   * 
   * @param duration duration in seconds
   */
  
  void read_data(unsigned int duration);

};

}