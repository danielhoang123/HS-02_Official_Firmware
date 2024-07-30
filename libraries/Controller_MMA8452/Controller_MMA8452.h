#ifndef Controller_MMA8452_H__
#define Controller_MMA8452_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include <Wire.h>                 
#include "SparkFun_MMA8452Q.h"

class Controller_MMA8452_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  MMA8452Q *accel;

  Controller_MMA8452_Data();
  ~Controller_MMA8452_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_MMA8452_Data device_Controller_MMA8452;
#endif