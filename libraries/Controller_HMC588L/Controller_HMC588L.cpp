#include "Controller_HMC588L.h"
#include "debugkxn.h"

Controller_HMC588L_Data::Controller_HMC588L_Data()
{
  this->nameDevice = "HMC5883L";
  this->timeInterval = 250;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x1E);
  // this->Add_HsCode(205);
  // Add your code here
}

Controller_HMC588L_Data::~Controller_HMC588L_Data()
{
}

bool Controller_HMC588L_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  this->valueDevice1 = "";

  int x, y, z; // triple axis data
  int xmin, xmax, ymin, ymax, zmin, zmax;
  xmin = 0;
  xmax = 0;
  ymax = 0;
  ymin = 0;
  zmin = 0;
  zmax = 0;

  // Tell the HMC5883 where to begin reading data
  Wire.beginTransmission(ADDRESS);
  Wire.write(0x03); // select register 3, X MSB register
  Wire.endTransmission();

  // Read data from each axis, 2 registers per axis
  Wire.requestFrom(ADDRESS, 6);
  if (6 <= Wire.available())
  {
    x = Wire.read() << 8; // X msb
    x |= Wire.read();     // X lsb
    z = Wire.read() << 8; // Z msb
    z |= Wire.read();     // Z lsb
    y = Wire.read() << 8; // Y msb
    y |= Wire.read();     // Y lsb
  }
  this->valueDevice  = "RAW Value:";
  this->valueDevice1 = String(x) + " ; " + String(y) + " ; " + String(z);

  return true;
}

bool Controller_HMC588L_Data::init()
{
  deInit();
  // Add your code here
  Wire.begin();
  // Put the HMC5883 IC into the correct operating mode
  Wire.beginTransmission(ADDRESS); // open communication with HMC5883
  Wire.write(0x02);                // select mode register
  Wire.write(0x00);                // continuous measurement mode
  Wire.endTransmission();
  return 1;
}

bool Controller_HMC588L_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_HMC588L_Data device_Controller_HMC588L;