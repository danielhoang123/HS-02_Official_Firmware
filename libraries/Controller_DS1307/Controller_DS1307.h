#ifndef Controller_DS1307_H__
#define Controller_DS1307_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include "RTClib.h"
#include "Wire.h"
class Controller_DS1307_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  RTC_DS1307 *rtc1;
  DateTime now;
  Controller_DS1307_Data();
  ~Controller_DS1307_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_DS1307_Data device_Controller_DS1307;
#endif