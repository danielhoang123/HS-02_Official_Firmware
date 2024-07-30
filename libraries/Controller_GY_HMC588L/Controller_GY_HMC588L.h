#ifndef Controller_GY_HMC588L_H__
#define Controller_GY_HMC588L_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include <QMC5883LCompass.h>
#include "HMC5883L.h"

class Controller_GY_HMC588L_Data : public Model_I2C_Device
{
public:
    // Add your declare here
    MPU6050 *accelgyro;
    QMC5883LCompass *compass_qmc;
    HMC5883L *compass_hmc;
    int error = 0;
    Controller_GY_HMC588L_Data();
    ~Controller_GY_HMC588L_Data();
    bool getData();
    bool init();
    bool deInit();
};

extern Controller_GY_HMC588L_Data device_Controller_GY_HMC588L;
#endif