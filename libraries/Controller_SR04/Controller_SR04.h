#ifndef Controller_SR04_H__
#define Controller_SR04_H__
#include "dataAdapter.h"

// include your Libraries here
#include "Arduino.h"
#include "SR04_Kalman.h"

class Controller_SR04_Data: public Data_Adapter{
  public:
  // Add your declare here
  
  hbq_SR04 sr04;
  // const int echo = 12                                           ;
  // const int trig = 13;

  Controller_SR04_Data();
  virtual ~Controller_SR04_Data(){};
  bool getData();
  bool init();
  bool deInit();
};

extern Controller_SR04_Data SR04_Device;
#endif