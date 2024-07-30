#include "Controller_DS18B20.h"
#include "MachTest_SP_IO.h"
// #include "debugkxn.h"

Controller_DS18B20_Data::Controller_DS18B20_Data()
{
  this->nameDevice = "DS18B20";
  this->timeInterval = 4000;
  this->valueDevice = "Ready";
  // Add your code here
}

bool Controller_DS18B20_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  this->sensor->requestTemperatures();
  this->valueDevice = String(this->sensor->getTempCByIndex(0)) + " " + String(char(223)) + "C";

  return true;
}

bool Controller_DS18B20_Data::init()
{
  deInit();
  
  // DallasTemperature sensor(&oneWire);
  this->timeInterval = 100;
  oneWire = OneWire(ONE_WIRE_BUS);
  this->sensor = new DallasTemperature(&oneWire);
  return 1;
}

bool Controller_DS18B20_Data::deInit()
{
  // Add your code here
  delete sensor;
  sensor = nullptr;
  return 1;
}

Controller_DS18B20_Data DS18B20_Device;