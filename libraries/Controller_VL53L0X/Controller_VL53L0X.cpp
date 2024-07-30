#include "Controller_VL53L0X.h"
#include "debugkxn.h"

Controller_VL53L0X_Data::Controller_VL53L0X_Data()
{
  this->nameDevice = "VL53L0X";
  this->timeInterval = 50;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x29);
  //this->Add_HsCode(201);
  // Add your code here

}

Controller_VL53L0X_Data::~Controller_VL53L0X_Data()
{
  
}

bool Controller_VL53L0X_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  this->valueDevice = String(this->sensorVL->readRangeContinuousMillimeters()) + " mm";
  return true;
}

bool Controller_VL53L0X_Data::init()
{
  deInit();
  // Add your code here
  Wire.begin();
  this->sensorVL = new VL53L0X;
  this->sensorVL->init();
  this->sensorVL->startContinuous();
  return 1;
}

bool Controller_VL53L0X_Data::deInit()
{
  // Add your code here
  delete sensorVL;
  sensorVL = nullptr;
  // if(this->sensorVL != NULL){
  //   free(this->sensorVL);
  //   this->sensorVL = NULL;
  // }
  return 1;
}

Controller_VL53L0X_Data device_Controller_VL53L0X;