#include "Controller_APDS9960.h"
// #include "debugkxn.h"

Controller_APDS9960_Data::Controller_APDS9960_Data()
{
  this->nameDevice = "APDS9960";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->Add_AddressList(0x39);
  // this->Add_HsCode(197);
  // Add your code here

}

Controller_APDS9960_Data::~Controller_APDS9960_Data()
{
  
}

bool Controller_APDS9960_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  
  return true;
}

bool Controller_APDS9960_Data::init()
{
  deInit();
  // Add your code here
  
  return 1;
}

bool Controller_APDS9960_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_APDS9960_Data device_Controller_APDS9960;