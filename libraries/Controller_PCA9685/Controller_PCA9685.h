#ifndef Controller_PCA9685_H__
#define Controller_PCA9685_H__
#include "Model_I2C_Device.h"

// include your Libraries here
// #include <Wire.h>
#include "PCA9685.h"
class Controller_PCA9685_Data : public Model_I2C_Device
{
public:
  // Add your declare here
  PCA9685 * pwmController; // Library using B010101 (A5-A0) i2c address, and default Wire @400kHz
  Controller_PCA9685_Data();
  ~Controller_PCA9685_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_PCA9685_Data device_Controller_PCA9685;
#endif