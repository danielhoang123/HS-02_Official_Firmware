#ifndef Controller_MS5611_H__
#define Controller_MS5611_H__
#include "Model_I2C_Device.h"

// include your Libraries here
// #include "MS5611.h"
#include "MS5611.h"

class Controller_MS5611_Data : public Model_I2C_Device
{
public:
  // Add your declare here
  // MS5611 * hbqMS5611;
  MS5611 * ms5611;
  Controller_MS5611_Data();
  ~Controller_MS5611_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_MS5611_Data device_Controller_MS5611;
#endif