#include "Controller_DS1307.h"
// #include "debugkxn.h"

Controller_DS1307_Data::Controller_DS1307_Data()
{
  this->nameDevice = "RTC(1307, 3231..)";
  this->timeInterval = 250;
  // this->valueDevice = "No device";
  this->Add_AddressList(0x68);
  // this->Add_HsCode(865);
  // Add your code here
}

Controller_DS1307_Data::~Controller_DS1307_Data()
{
}

bool Controller_DS1307_Data::getData()
{
  // Add your code here
  this->valueDevice = "";
  this->valueDevice1 = "";

  now = this->rtc1->now();

  this->valueDevice += String(now.day()) + "/" + String(now.month()) + "/" + String(now.year());

  this->valueDevice1 += "0" + String(now.hour(), DEC) + ":" + String(now.minute(), DEC) + ":" + String(now.second(), DEC);

  return true;
}

bool Controller_DS1307_Data::init()
{
  deInit();
  // Add your code here
  this->rtc1 = new RTC_DS1307;
  // this->now = new DateTime;
  Wire.begin();
  this->rtc1->begin();

  // this->now = this->rtc1->now();
  now = this->rtc1->now();
  int a = int(now.hour());
  int b = int(now.minute());

  if (a != 7 && b != 5)
  {
    this->rtc1->adjust(DateTime(2023, 4, 23, 7, 5, 0));
  }

  return 1;
}

bool Controller_DS1307_Data::deInit()
{
  // Add your code here
  delete rtc1;
  rtc1 = NULL;
  return 1;
}

Controller_DS1307_Data device_Controller_DS1307;