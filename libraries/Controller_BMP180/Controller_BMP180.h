#ifndef Controller_BMP180_H__
#define Controller_BMP180_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include <Adafruit_BMP085.h>
class Controller_BMP180_Data : public Model_I2C_Device
{
public:
  // Add your declare here
  Adafruit_BMP085 * bmp;
  Controller_BMP180_Data();
  ~Controller_BMP180_Data();

  bool getData();
  bool init();
  bool deInit();
};

extern Controller_BMP180_Data device_Controller_BMP180;
#endif