#include "Controller_HTU21.h"
#include "debugkxn.h"

Controller_HTU21_Data::Controller_HTU21_Data()
{
  this->nameDevice = "HTU21";
  this->timeInterval = 250;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x40);
  // this->Add_HsCode(176);
  // Add your code here

}

Controller_HTU21_Data::~Controller_HTU21_Data()
{
  
}

bool Controller_HTU21_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  float temp = this->htu->readTemperature();
  float rel_hum = this->htu->readHumidity();
  this->valueDevice = String(temp) + String(char(223)) + "C";
  this->valueDevice1 = String(rel_hum) + "%";

  // float temp = htu.readTemperature();
  // float rel_hum = htu.readHumidity();
  // this->valueDevice = String(temp) + String(char(223)) + "C";
  // this->valueDevice1 = String(rel_hum) + "%";

  return true;
}

bool Controller_HTU21_Data::init()
{
  deInit();
  // Add your code here
  this->htu = new Adafruit_HTU21DF();
  this->htu->begin();
  // htu.begin();
  return 1;
}

bool Controller_HTU21_Data::deInit()
{
  // Add your code here
  delete htu;
  htu = nullptr;
  // if(this->htu != NULL){
  //   free(this->htu);
  //   this->htu = NULL;
  // }
  return 1;
}

Controller_HTU21_Data device_Controller_HTU21;