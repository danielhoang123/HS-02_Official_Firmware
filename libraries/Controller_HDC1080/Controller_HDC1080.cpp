#include "Controller_HDC1080.h"
#include "debugkxn.h"

Controller_HDC1080_Data::Controller_HDC1080_Data()
{
  this->nameDevice = "HDC1080";
  this->timeInterval = 250;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x40);
  // this->Add_HsCode(1310);
  // Add your code here
}

Controller_HDC1080_Data::~Controller_HDC1080_Data()
{
}

bool Controller_HDC1080_Data::getData()
{
  // Add your code here

  this->valueDevice = String(this->hdc1080->readTemperature()) + String(char(223)) + "C";
  this->valueDevice1 = String(this->hdc1080->readHumidity()) + "%";
  return true;
}

bool Controller_HDC1080_Data::init()
{
  deInit();
  // Add your code here
  this->hdc1080 = new ClosedCube_HDC1080;
  this->hdc1080->begin(0x40);
  return 1;
}

bool Controller_HDC1080_Data::deInit()
{
  // Add your code here
  delete hdc1080;
  hdc1080 = nullptr;
  return 1;
}

Controller_HDC1080_Data device_Controller_HDC1080;