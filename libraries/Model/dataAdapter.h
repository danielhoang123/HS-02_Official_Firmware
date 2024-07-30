#ifndef _DATA_H_ADAPTER_H_
#define _DATA_H_ADAPTER_H_

#include "Arduino.h"
#include "OneButton.h"
#include "LinkedList.h"

// extern unsigned long Current_Millis;
class Data_Adapter
{
public:
  OneButton *btnNext;
  OneButton *btnPrevious;
  OneButton *btnStart;

  callbackFunction LastNextFunction;
  callbackFunction LastPreviousFunction;
  callbackFunction LastStartFunction_Click;
  callbackFunction LastStartFunction_DoubleClick;

  // LinkedList<uint16_t> hsCode_List = LinkedList<uint16_t>();
  // void Add_HsCode(uint16_t vHscode);

  Data_Adapter(){};
  virtual ~Data_Adapter(){};
  unsigned long Current_Millis = millis();
  unsigned long timeInterval = 100;
  String nameDevice;
  String valueDevice;
  String valueDevice1;
  String valueDevice2;
  
  bool isRun = false;

  bool stopOtherReading = false;
  // uint16_t hsCode;
  uint8_t i2cAddress;

  // void Set_HS_Code(uint16_t hsCode__)
  // {
  //   hsCode = hsCode__;
  // }

  // uint16_t Get_HS_Code()
  // {
  //   return hsCode;
  // }

  virtual bool getData() { return 0; };
  virtual bool init() { return 0; };
  virtual bool deInit() { return 0; };
};

#endif
