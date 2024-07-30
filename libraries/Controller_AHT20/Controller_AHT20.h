#ifndef Controller_AHT20_H__
#define Controller_AHT20_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include <Adafruit_AHTX0.h>

class Controller_AHT20_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  Adafruit_AHTX0 * a;

  Controller_AHT20_Data();
  ~Controller_AHT20_Data();
  
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_AHT20_Data device_Controller_AHT20;
#endif