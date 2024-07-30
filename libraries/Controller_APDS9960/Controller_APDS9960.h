#ifndef Controller_APDS9960_H__
#define Controller_APDS9960_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include <SparkFun_APDS9960.h>

class Controller_APDS9960_Data: public Model_I2C_Device{
  public:
  // Add your declare here

  Controller_APDS9960_Data();
  ~Controller_APDS9960_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_APDS9960_Data device_Controller_APDS9960;
#endif