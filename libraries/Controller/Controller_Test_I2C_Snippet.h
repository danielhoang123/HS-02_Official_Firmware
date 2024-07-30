#ifndef Controller_Test_I2C_Snippet_H__
#define Controller_Test_I2C_Snippet_H__
#include "Model_I2C_Device.h"

// include your Libraries here


class Controller_Test_I2C_Snippet_Data: public Model_I2C_Device{
  public:
  // Add your declare here

  Controller_Test_I2C_Snippet_Data();
  ~Controller_Test_I2C_Snippet_Data();
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_Test_I2C_Snippet_Data device_Controller_Test_I2C_Snippet;
#endif