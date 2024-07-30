#ifndef Controller_MAX44009_H__
#define Controller_MAX44009_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include <Wire.h>
#define Address 0x4A

class Controller_MAX44009_Data: public Model_I2C_Device{
  public:
  // Add your declare here

  Controller_MAX44009_Data();
  ~Controller_MAX44009_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_MAX44009_Data device_Controller_MAX44009;
#endif