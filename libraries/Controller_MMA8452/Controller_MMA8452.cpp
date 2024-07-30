#include "Controller_MMA8452.h"
#include "debugkxn.h"

Controller_MMA8452_Data::Controller_MMA8452_Data()
{
  this->nameDevice = "MMA8452";
  this->timeInterval = 250;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x1C);
  // this->Add_HsCode(190);
  //  Add your code here
}

Controller_MMA8452_Data::~Controller_MMA8452_Data()
{
}

bool Controller_MMA8452_Data::getData()
{
  // Add your code here
  this->valueDevice = "";

  if (this->accel->available())
  {

    // Cột 2 dòng 0
    // lcd.print(valueDevice__);

    this->valueDevice = String(this->accel->getCalculatedX(), 2) + ":" + String(this->accel->getCalculatedY(), 2) + ":" + String(this->accel->getCalculatedZ(), 2);
    // this->valueDevice += ":";
    // this->valueDevice += String(this->accel->getCalculatedY(), 2);
    // this->valueDevice += ":";
    // this->valueDevice += String(this->accel->getCalculatedZ(), 2);
  }

  return true;
}

bool Controller_MMA8452_Data::init()
{
  deInit();
  // Add your code here
  Wire.begin();
  this->accel = new MMA8452Q;

  this->accel->begin();
  return 1;
}

bool Controller_MMA8452_Data::deInit()
{
  // Add your code here
  delete accel;
  accel = nullptr;
  return 1;
}

Controller_MMA8452_Data device_Controller_MMA8452;