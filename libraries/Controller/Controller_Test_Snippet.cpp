#include "Controller_Test_Snippet.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

Controller_Test_Snippet_Data::Controller_Test_Snippet_Data()
{
  this->nameDevice = "testDevice";
  this->timeInterval = 250;
  this->valueDevice = "No device";
  // Add your code here
}

bool Controller_Test_Snippet_Data::getData()
{
  // Add your code here
  
  return true;
}

bool Controller_Test_Snippet_Data::init()
{
  deInit();
  // Add your code here
  
  return 1;
}

bool Controller_Test_Snippet_Data::deInit()
{
  // Add your code here
  return 1;
}

Controller_Test_Snippet_Data testDevice_Device;