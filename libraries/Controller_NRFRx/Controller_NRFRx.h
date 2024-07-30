#ifndef Controller_NRFRx_H__
#define Controller_NRFRx_H__
#include "dataAdapter.h"

// include your Libraries here
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

class Controller_NRFRx_Data: public Data_Adapter{
  public:
  // Add your declare here
  RF24 radio_RX;
  Controller_NRFRx_Data();
  virtual ~Controller_NRFRx_Data(){};
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_NRFRx_Data NRFRx_Device;
#endif