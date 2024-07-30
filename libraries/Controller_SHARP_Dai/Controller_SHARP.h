#ifndef Controller_SHARP_H__
#define Controller_SHARP_H__
#include "dataAdapter.h"

// include your Libraries here
#include "SharpIR.h"

class Controller_SHARP_Data : public Data_Adapter
{
public:
  // Add your declare here
  int longType_distance;
  int longType_model = 20150;
  SharpIR *longSharpSensor;
  Controller_SHARP_Data();
  virtual ~Controller_SHARP_Data(){};
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_SHARP_Data SHARP_Device;
#endif