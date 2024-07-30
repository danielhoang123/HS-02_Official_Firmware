#ifndef Controller_VL53L0X_H__
#define Controller_VL53L0X_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include <Wire.h>
#include <VL53L0X.h>

class Controller_VL53L0X_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  VL53L0X * sensorVL;
  Controller_VL53L0X_Data();
  ~Controller_VL53L0X_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_VL53L0X_Data device_Controller_VL53L0X;
#endif