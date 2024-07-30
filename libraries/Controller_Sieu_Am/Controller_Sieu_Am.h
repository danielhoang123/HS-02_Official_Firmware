#ifndef _SIEU_H_AM_H__
#define _SIEU_H_AM_H__

#include "dataAdapter.h"
#include "UltraSonicDistanceSensor.h"

extern UltraSonicDistanceSensor * distanceSensor;

class SieuAm_Data: public Data_Adapter{
  public:
  
  SieuAm_Data();
  virtual ~SieuAm_Data(){};

  bool getData();
  bool init();
  bool deInit();
};

extern SieuAm_Data sieuAm_Device;

#endif
