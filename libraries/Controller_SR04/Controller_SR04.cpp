#include "Controller_SR04.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

Controller_SR04_Data::Controller_SR04_Data()
{
  this->nameDevice = "Ultrasonic";
  this->timeInterval = 4000;
  this->valueDevice = "Ready";
  // Add your code here
}

bool Controller_SR04_Data::getData()
{
  // Add your code here
  sr04.usonic_transmit();
  this->valueDevice = String(sr04.forLoopFunction(), 1) + "(cm)";
  return true;
}

bool Controller_SR04_Data::init()
{
  deInit();
  // Add your code here
  this->timeInterval = 100;
  pinMode(6, OUTPUT);
  pinMode(7, INPUT);
  
  return 1;
}

bool Controller_SR04_Data::deInit()
{
  // Add your code here
  pinMode(6, INPUT);
  pinMode(7, INPUT);

  return 1;
}

Controller_SR04_Data SR04_Device;