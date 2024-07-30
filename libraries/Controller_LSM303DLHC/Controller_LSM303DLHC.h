#ifndef Controller_LSM303DLHC_H__
#define Controller_LSM303DLHC_H__
#include "Model_I2C_Device.h"

// include your Libraries here

#include <Wire.h>
#include <LSM303.h>

class Controller_LSM303DLHC_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  LSM303 * cmps;
  
  Controller_LSM303DLHC_Data();
  ~Controller_LSM303DLHC_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_LSM303DLHC_Data device_Controller_LSM303DLHC;
#endif