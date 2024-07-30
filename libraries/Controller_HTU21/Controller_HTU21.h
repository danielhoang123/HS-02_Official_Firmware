#ifndef Controller_HTU21_H__
#define Controller_HTU21_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include "Adafruit_HTU21DF.h"

class Controller_HTU21_Data: public Model_I2C_Device{
  public:
  // Add your declare here
  //Adafruit_HTU21DF * htu;
  Adafruit_HTU21DF * htu;
  Controller_HTU21_Data();
  ~Controller_HTU21_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_HTU21_Data device_Controller_HTU21;
#endif