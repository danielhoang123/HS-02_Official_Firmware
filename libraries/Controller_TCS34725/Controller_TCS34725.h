#ifndef Controller_TCS34725_H__
#define Controller_TCS34725_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include <Wire.h>
#include "Adafruit_TCS34725.h"

class Controller_TCS34725_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  float red, green, blue;
  Adafruit_TCS34725 *tcs;
  Controller_TCS34725_Data();
  ~Controller_TCS34725_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_TCS34725_Data device_Controller_TCS34725;
#endif