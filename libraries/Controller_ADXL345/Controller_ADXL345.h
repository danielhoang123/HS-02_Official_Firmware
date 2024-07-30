#ifndef Controller_ADXL345_H__
#define Controller_ADXL345_H__
#include "Model_I2C_Device.h"

// include your Libraries here
// #include "Wire.h"
#include <SparkFun_ADXL345.h>

class Controller_ADXL345_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  // int ADXL345 = 0x53;
  // float X_out, Y_out, Z_out;
  ADXL345 *adxl;

  Controller_ADXL345_Data();
  ~Controller_ADXL345_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_ADXL345_Data device_Controller_ADXL345;
#endif