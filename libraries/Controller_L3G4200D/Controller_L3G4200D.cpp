#include "Controller_L3G4200D.h"
#include "debugkxn.h"

Controller_L3G4200D_Data::Controller_L3G4200D_Data()
{
  this->nameDevice = "L3G4200D";
  this->timeInterval = 250;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x69);
  // this->Add_HsCode(196);
  // Add your code here

}

Controller_L3G4200D_Data::~Controller_L3G4200D_Data()
{
  
}

bool Controller_L3G4200D_Data::getData()
{
  // Add your code here
  // this->valueDevice = "";
  // this->valueDevice += String(l3g4200d.getGyroValuesX());
  // this->valueDevice += ":";
  // this->valueDevice += String(l3g4200d.getGyroValuesY());
  // this->valueDevice += ":";
  // this->valueDevice += String(l3g4200d.getGyroValuesZ());
  this->valueDevice = "";

  this->l3g4->read();

  this->valueDevice += String((int)this->l3g4->g.x) + ";" + String((int)this->l3g4->g.y) + ";" + String((int)this->l3g4->g.z); 
  // Serial.print("G ");
  // Serial.print("X: ");
  // Serial.print((int)gyro.g.x);
  // Serial.print(" Y: ");
  // Serial.print((int)gyro.g.y);
  // Serial.print(" Z: ");
  // Serial.println((int)gyro.g.z);

  return true;
}

bool Controller_L3G4200D_Data::init()
{
  deInit();
  // Add your code here
  // Wire.begin();
  // l3g4200d.setupL3G4200D(2000);

  this->l3g4 = new L3G;

  Wire.begin();

  if (!this->l3g4->init())
  {
    this->valueDevice = "Connect Failed";
    while (1);
  }

  this->l3g4->enableDefault();

  return 1;
}

bool Controller_L3G4200D_Data::deInit()
{
  // Add your code here
  delete l3g4;
  l3g4 = nullptr;
  return 1;
}

Controller_L3G4200D_Data device_Controller_L3G4200D;