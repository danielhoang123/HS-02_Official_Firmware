#ifndef Controller_SHT30_H__
#define Controller_SHT30_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include "hshop_SHT3x.h"

class Controller_SHT30_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  SHT3x * sht;
  Controller_SHT30_Data();
  ~Controller_SHT30_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_SHT30_Data device_Controller_SHT30;
#endif