#ifndef Controller_MKL_RTC_H__
#define Controller_MKL_RTC_H__

#include "Model_I2C_Device.h"

#include "RTClib.h"

class Controller_MKL_RTC : public Model_I2C_Device
{
public:
    RTC_DS3231 rtc;

    Controller_MKL_RTC();
    ~Controller_MKL_RTC();

    bool getData();

    bool init();

    bool deInit() { return 0; };
};

extern Controller_MKL_RTC RTC_Device;
#endif