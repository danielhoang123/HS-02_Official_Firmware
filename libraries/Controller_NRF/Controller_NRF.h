#ifndef Controller_nRF_H__
#define Controller_nRF_H__
#include "dataAdapter.h"

// include your Libraries here
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

class Controller_nRF_Data : public Data_Adapter
{
public:
  // Add your declare here
  
  RF24 radio;
  
  Controller_nRF_Data();
  virtual ~Controller_nRF_Data(){};
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_nRF_Data NRF_Device;
#endif