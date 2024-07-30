#include "Controller_Test_I2C_Snippet.h"
// #include "debugkxn.h"

Controller_Test_I2C_Snippet_Data::Controller_Test_I2C_Snippet_Data()
{
  this->nameDevice = "testSnippet I2C";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  this->i2cAddress = 0x68;
  // Set_HS_Code(1518);
  // Add your code here

}

Controller_Test_I2C_Snippet_Data::~Controller_Test_I2C_Snippet_Data()
{
  
}

bool Controller_Test_I2C_Snippet_Data::getData()
{
  // Add your code here
  
  return true;
}

bool Controller_Test_I2C_Snippet_Data::init()
{
  deInit();
  // Add your code here
  
  return 1;
}

bool Controller_Test_I2C_Snippet_Data::deInit()
{
  // Add your code here

  return 1;
}

Controller_Test_I2C_Snippet_Data device_Controller_Test_I2C_Snippet;