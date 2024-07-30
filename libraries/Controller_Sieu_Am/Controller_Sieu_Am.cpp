#include "Controller_Sieu_Am.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

UltraSonicDistanceSensor *distanceSensor; // Cài đặt pin Triger(output) là 5, Echo(input) là 6

SieuAm_Data::SieuAm_Data()
{
  this->nameDevice = "Sieu Am";
  this->timeInterval = 250;
  this->valueDevice = "No device";
}

bool SieuAm_Data::getData()
{
  float valuecm;
  if (distanceSensor)
  {
    debug_sieuam(F("doc SIeu am \r\n"));
    if (distanceSensor->available() == true)
    {
      valuecm = distanceSensor->getcm();
      debug_sieuam(valuecm);
    }
    this->valueDevice = (String)valuecm;
  }
  return true;
}

bool SieuAm_Data::init()
{
  deInit();
  distanceSensor = new (UltraSonicDistanceSensor)(TRIG_PIN, ECHO_PIN);
  debug_sieuam(F("Test Sieu am \r\n"));
}

bool SieuAm_Data::deInit()
{
  pinMode(TRIG_PIN, INPUT);
  //  pinMode(ECHO_PIN, INPUT);
  this->valueDevice = "No device";
  if (distanceSensor)
  {
    delete distanceSensor;
    distanceSensor = 0;
  }
  debug_sieuam(F("Xoa Sieu am \r\n"));
}

SieuAm_Data sieuAm_Device;
