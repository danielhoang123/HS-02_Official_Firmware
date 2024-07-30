#include "Controller_SHT30.h"
#include "debugkxn.h"

Controller_SHT30_Data::Controller_SHT30_Data()
{
  this->nameDevice = "SHT3x";
  this->timeInterval = 250;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x44);
  //this->Add_HsCode(1582);
  // Add your code here

}

Controller_SHT30_Data::~Controller_SHT30_Data()
{
  
}

bool Controller_SHT30_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  this->valueDevice1 = "";
  this->sht->UpdateData();
  this->valueDevice += "T: " + String(this->sht->GetTemperature(), 2) + String(char(223)) + "C";
  this->valueDevice1 += "H: " + String(this->sht->GetRelHumidity(), 2) + "%"; 
  return true;
}

bool Controller_SHT30_Data::init()
{
  deInit();
  // Add your code here
  this->sht = new SHT3x();
  this->sht->Begin();

  
  return 1;
}

bool Controller_SHT30_Data::deInit()
{
  // Add your code here
  delete sht;
  sht = nullptr;
  return 1;
}

Controller_SHT30_Data device_Controller_SHT30;