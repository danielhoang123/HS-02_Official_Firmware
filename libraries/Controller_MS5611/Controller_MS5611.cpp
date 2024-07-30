#include "Controller_MS5611.h"
#include "debugkxn.h"

Controller_MS5611_Data::Controller_MS5611_Data()
{
  this->nameDevice = "MS5611";
  this->timeInterval = 250;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x77);
  // this->Add_HsCode(1518);
  //  Add your code here
}

Controller_MS5611_Data::~Controller_MS5611_Data()
{
}

bool Controller_MS5611_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  this->valueDevice1 = "";
  int result = this->ms5611->read();

  if (result != MS5611_READ_OK)
  {
    this->valueDevice += "Error: " + String(result);
  }
  else
  {
    // Serial.print("T:\t");
    // Serial.print(this->ms5611->getTemperature(), 2);
    // Serial.print("\tP:\t");
    // Serial.print(this->ms5611->getPressure(), 2);
    // Serial.print("\tt:\t");

    this->valueDevice += "T: " + String(this->ms5611->getTemperature(), 2);
    this->valueDevice1 += "P: " + String(this->ms5611->getPressure(), 2);
  }
  return true;
}

bool Controller_MS5611_Data::init()
{
  deInit();
  // Add your code here

  this->ms5611 = new MS5611(0x77);

  Wire.begin();
  if (!this->ms5611->begin())
  {
    this->valueDevice = "Connect Failed";
  }

  return 1;
}

bool Controller_MS5611_Data::deInit()
{
  // Add your code here
  delete ms5611;
  ms5611 = nullptr;
  // if (this->hbqMS5611 != NULL)
  // {
  //   free(this->hbqMS5611);
  //   this->hbqMS5611 = NULL;
  // }
  return 1;
}

Controller_MS5611_Data device_Controller_MS5611;