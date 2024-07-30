#ifndef Controller_Test_Snippet_H__
#define Controller_Test_Snippet_H__
#include "dataAdapter.h"

// include your Libraries here


class Controller_Test_Snippet_Data: public Data_Adapter{
  public:
  // Add your declare here

  Controller_Test_Snippet_Data();
  virtual ~Controller_Test_Snippet_Data(){};
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_Test_Snippet_Data testDevice_Device;
#endif