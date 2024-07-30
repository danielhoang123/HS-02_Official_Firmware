#ifndef Controller_MKL_I2C_Motor_H_
#define Controller_MKL_I2C_Motor_H_

#include "Model_I2C_Device.h"
#include "Makerlabvn_I2C_Motor_Driver.h"

class Controller_MKL_I2C_Motor : public Model_I2C_Device
{
public:
    Makerlabvn_I2C_Motor_Driver myDriver;

    unsigned long timeUpdate = 10; // 10ms
    unsigned long lastTimeUpdate = 0;
    unsigned char speedDCMotor = 0; // 0->255 pwm
    bool dirDCMotor = 0;            // 0 or 1
    unsigned char angleRCValue = 0; // 0->180 degrees

    Controller_MKL_I2C_Motor();
    ~Controller_MKL_I2C_Motor();
    bool getData();

    bool init();

    bool deInit() { return 1; };
};

extern Controller_MKL_I2C_Motor MKL_I2C_Motor_Device;
// extern Controller_MKL_I2C_Motor MKL_I2C_Motor_Device2;
// extern Controller_MKL_I2C_Motor MKL_I2C_Motor_Device3;
#endif