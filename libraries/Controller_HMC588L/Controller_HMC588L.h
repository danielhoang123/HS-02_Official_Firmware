#ifndef Controller_HMC588L_H__
#define Controller_HMC588L_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include "Wire.h"

#define ADDRESS 0x1E //0011110b, I2C 7bit address of HMC5883

class Controller_HMC588L_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  

  Controller_HMC588L_Data();
  ~Controller_HMC588L_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_HMC588L_Data device_Controller_HMC588L;
#endif