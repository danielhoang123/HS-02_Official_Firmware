#ifndef Controller_PN532_H__
#define Controller_PN532_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include "Wire.h"
#include <PN532_I2C.h>
#include <NfcAdapter.h>

class Controller_PN532_Data : public Model_I2C_Device
{
public:
  // Add your declare here
  NfcAdapter *nfc;
  Controller_PN532_Data();
  ~Controller_PN532_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_PN532_Data device_Controller_PN532;
#endif