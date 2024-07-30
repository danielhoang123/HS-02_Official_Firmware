#ifndef Controller_HDC1080_H__
#define Controller_HDC1080_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include <Wire.h>
#include "ClosedCube_HDC1080.h"

class Controller_HDC1080_Data : public Model_I2C_Device
{
public:
  // Add your declare here
  ClosedCube_HDC1080 *hdc1080;
  Controller_HDC1080_Data();
  ~Controller_HDC1080_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_HDC1080_Data device_Controller_HDC1080;
#endif