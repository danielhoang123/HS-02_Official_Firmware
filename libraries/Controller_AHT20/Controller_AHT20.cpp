#include "Controller_AHT20.h"
// #include "debugkxn.h"

Controller_AHT20_Data::Controller_AHT20_Data()
{
  this->nameDevice = "AHT20";
  this->timeInterval = 250;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x38);
  // this->Add_HsCode(1437);
  // Add your code here
}

Controller_AHT20_Data::~Controller_AHT20_Data()
{
}

bool Controller_AHT20_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  this->valueDevice1 = "";

  sensors_event_t humidity, temp;
  this->a->getEvent(&humidity, &temp);

  this->valueDevice += "T: " + String(temp.temperature, 2) + String(char(223)) + "C";
  this->valueDevice1 += "H: " + String(humidity.relative_humidity, 2) + "%";
  return true;
}

bool Controller_AHT20_Data::init()
{
  deInit();
  this->a = new Adafruit_AHTX0;
  // Add your code here
  this->a->begin();

  return 1;
}

bool Controller_AHT20_Data::deInit()
{
  // Add your code here
  delete a;
  a = nullptr;
  return 1;
}

Controller_AHT20_Data device_Controller_AHT20;