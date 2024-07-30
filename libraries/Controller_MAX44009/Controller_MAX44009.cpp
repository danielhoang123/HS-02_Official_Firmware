#include "Controller_MAX44009.h"
#include "debugkxn.h"

Controller_MAX44009_Data::Controller_MAX44009_Data()
{
  this->nameDevice = "MAX44009";
  this->timeInterval = 250;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x4A);
  // this->Add_HsCode(1308);
  // Add your code here

}

Controller_MAX44009_Data::~Controller_MAX44009_Data()
{
  
}

bool Controller_MAX44009_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  unsigned int data[2];
  Wire.beginTransmission(Address); //start wire iic transmission
  Wire.write(0x03); // Select data register
  Wire.endTransmission(); // Stop iic transmission
  Wire.requestFrom(Address, 2); // Request 2 bytes of data
  // Read 2 bytes of data
  // luminance msb, luminance lsb
  if (Wire.available() == 2)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
  }
  // Convert the data to lux
  int exponent = (data[0] & 0xF0) >> 4;
  int mantissa = ((data[0] & 0x0F) << 4) | (data[1] & 0x0F);
  float luminance = pow(2, exponent) * mantissa * 0.045;

  this->valueDevice += "Luminance: " + String(luminance, 1) + "(lux)";
  return true;
}

bool Controller_MAX44009_Data::init()
{
  deInit();
  // Add your code here
  Wire.begin();
  Wire.beginTransmission(Address); 
  Wire.write(0x02); 
  Wire.write(0x40); 
  Wire.endTransmission();
  return 1;
}

bool Controller_MAX44009_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_MAX44009_Data device_Controller_MAX44009;