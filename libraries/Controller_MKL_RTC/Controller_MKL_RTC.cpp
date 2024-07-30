#include "Controller_MKL_RTC.h"
#include "LinkedList.h"

Controller_MKL_RTC::Controller_MKL_RTC()
{
    this->nameDevice = "RTC";
    this->timeInterval = 1000;
    this->Add_AddressList(0x68);
    // this->Add_HsCode(1522);
}

Controller_MKL_RTC::~Controller_MKL_RTC()
{
}

bool Controller_MKL_RTC::init()
{
    if (!rtc.begin())
    {
        // Serial.println("Couldn't find RTC");
        // Serial.flush();
        // abort();
    }

    if (rtc.lostPower())
    {
        // Serial.println("RTC lost power, let's set the time!");
        // When time needs to be set on a new device, or after a power loss, the
        // following line sets the RTC to the date & time this sketch was compiled
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
        // This line sets the RTC with an explicit date & time, for example to set
        // January 21, 2014 at 3am you would call:
        // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
    }
}

bool Controller_MKL_RTC::getData()
{
    DateTime now = rtc.now();
    String strData = "";

    strData = String(now.hour(), DEC);
    strData += ":";
    strData += String(now.minute(), DEC);
    strData += ":";
    strData += String(now.second(), DEC);
    strData += "    ";

    this->valueDevice = strData;

    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
}

Controller_MKL_RTC RTC_Device;