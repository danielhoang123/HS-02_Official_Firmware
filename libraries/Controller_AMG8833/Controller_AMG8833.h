#ifndef Controller_AMG8833_H__
#define Controller_AMG8833_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include "Adafruit_AMG88xx.h"

class Controller_AMG8833_Data : public Model_I2C_Device
{
public:
    // Add your declare here
    Adafruit_AMG88xx *amg;
    float thermal;
    Controller_AMG8833_Data();
    ~Controller_AMG8833_Data();
    bool getData();
    bool init();
    bool deInit();
};

extern Controller_AMG8833_Data device_Controller_AMG8833;
#endif