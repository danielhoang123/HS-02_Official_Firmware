#include "Controller_TCS34725.h"
#include "debugkxn.h"

byte gammatable[256];

// Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

Controller_TCS34725_Data::Controller_TCS34725_Data()
{
  this->nameDevice = "TCS34725";
  this->timeInterval = 250;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x29);
  // this->Add_HsCode(1518);
  //  Add your code here
}

Controller_TCS34725_Data::~Controller_TCS34725_Data()
{
}

bool Controller_TCS34725_Data::getData()
{
  // Add your code here
  this->valueDevice = "";

  this->tcs->getRGB(&red, &green, &blue);

  this->valueDevice += "R";
  this->valueDevice += String(int(red));
  this->valueDevice += ";";
  this->valueDevice += "G";
  this->valueDevice += String(int(green));
  this->valueDevice += ";";
  this->valueDevice += "B";
  this->valueDevice += String(int(blue));

  return true;
}

bool Controller_TCS34725_Data::init()
{
  deInit();
  // Add your code here
  this->tcs = new Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

  this->tcs->begin();

  for (int i = 0; i < 256; i++)
  {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;

    if (true)
    {
      gammatable[i] = 255 - x;
    }
    else
    {
      gammatable[i] = x;
    }
  }

  return 1;
}

bool Controller_TCS34725_Data::deInit()
{
  // Add your code here
  delete tcs;
  tcs = nullptr;
  return 1;
}

Controller_TCS34725_Data device_Controller_TCS34725;