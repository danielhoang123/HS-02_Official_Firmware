#ifndef Controller_VL53L1X_H__
#define Controller_VL53L1X_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include "Adafruit_VL53L1X.h"

#define IRQ_PIN 12
#define XSHUT_PIN 13

class Controller_VL53L1X_Data : public Model_I2C_Device
{
public:
    // Add your declare here
    Adafruit_VL53L1X *vl53;
    int16_t distance;
    // Adafruit_VL53L1X vl53 = Adafruit_VL53L1X(XSHUT_PIN, IRQ_PIN);
    Controller_VL53L1X_Data();
    ~Controller_VL53L1X_Data();
    bool getData();
    bool init();
    bool deInit();
};

extern Controller_VL53L1X_Data device_Controller_VL53L1X;
#endif