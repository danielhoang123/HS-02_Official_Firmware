#ifndef Controller_I2C_Scanner_H__
#define Controller_I2C_Scanner_H__
#include "dataAdapter.h"

// include your Libraries here
#include <Wire.h>

class Controller_I2C_Scanner_Data: public Data_Adapter{
  public:
  // Add your declare here
  
  Controller_I2C_Scanner_Data();
  virtual ~Controller_I2C_Scanner_Data(){};
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_I2C_Scanner_Data I2C_Scanner_Device;
#endif