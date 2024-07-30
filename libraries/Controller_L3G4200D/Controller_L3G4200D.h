#ifndef Controller_L3G4200D_H__
#define Controller_L3G4200D_H__
#include "Model_I2C_Device.h"

// include your Libraries here
// #include <Wire.h>
// #include <hbq_L3G4200D.h>
#include <Wire.h>
#include <L3G.h>

class Controller_L3G4200D_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  // hbq_L3G4200D l3g4200d;
  L3G *l3g4;
  Controller_L3G4200D_Data();
  ~Controller_L3G4200D_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_L3G4200D_Data device_Controller_L3G4200D;
#endif