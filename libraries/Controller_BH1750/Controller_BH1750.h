#ifndef Controller_BH1750_H__
#define Controller_BH1750_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include <BH1750.h>

class Controller_BH1750_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  BH1750 * lightMeter;
  // float lux;
  
  Controller_BH1750_Data();
  ~Controller_BH1750_Data();
  
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_BH1750_Data device_Controller_BH1750;
#endif