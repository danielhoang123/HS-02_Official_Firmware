#ifndef Controller_PAJ7620U2_H__
#define Controller_PAJ7620U2_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include "paj7620.h"

class Controller_PAJ7620U2_Data: public Model_I2C_Device{
  public:
  // Add your declare here

  Controller_PAJ7620U2_Data();
  ~Controller_PAJ7620U2_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_PAJ7620U2_Data device_Controller_PAJ7620U2;
#endif