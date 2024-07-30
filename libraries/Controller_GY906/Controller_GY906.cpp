#include "Controller_GY906.h"
// #include "debugkxn.h"

Controller_GY906_Data::Controller_GY906_Data()
{
  this->nameDevice = "GY906";
  this->timeInterval = 250;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x5A);
  // this->Add_HsCode(1450);
  // Add your code here
}

Controller_GY906_Data::~Controller_GY906_Data()
{
}

bool Controller_GY906_Data::getData()
{
  // Add your code here
  this->valueDevice = "";

  
  this->valueDevice = "Ambient = " + String(this->mlx->readAmbientTempC()) + String(char(223)) + "C";
  this->valueDevice1 = "Object = " + String(this->mlx->readObjectTempC()) + String(char(223)) + "C";
  return true;
}

bool Controller_GY906_Data::init()
{
  deInit();
  // Add your code here
  //   Adafruit_MLX90614 mlx = Adafruit_MLX90614();
  this->mlx = new Adafruit_MLX90614();
  this->mlx->begin();
  return 1;
}

bool Controller_GY906_Data::deInit()
{
  // Add your code here
  delete mlx;
  mlx = nullptr;
  // if (this->mlx != NULL)
  // {
  //   free(this->mlx);
  //   this->mlx = NULL;
  // }
  return 1;
}

Controller_GY906_Data device_Controller_GY906;