#ifndef Controller_RC522_H__
#define Controller_RC522_H__
#include "dataAdapter.h"

// include your Libraries here
#include <SPI.h>
#include <MFRC522.h>

class Controller_RC522_Data : public Data_Adapter
{
public:
  // Add your declare here
  
  MFRC522 * rfid;
  Controller_RC522_Data();
  virtual ~Controller_RC522_Data(){};
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_RC522_Data RC522_Device;
#endif