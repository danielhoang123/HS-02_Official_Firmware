#ifndef Controller_LCD3f_H__
#define Controller_LCD3f_H__
#include "Model_I2C_Device.h"

// include your Libraries here
#include <LiquidCrystal_I2C.h>

class Controller_LCD3f_Data : public Model_I2C_Device
{
public:
    // Add your declare here
    LiquidCrystal_I2C *lcd3f; // Cài đặt địa chỉ 0x27, hiển thị 16 cột 2 dòngF
    Controller_LCD3f_Data();
    ~Controller_LCD3f_Data();
    bool getData();
    bool init();
    bool deInit();
};

extern Controller_LCD3f_Data device_Controller_LCD3f;
#endif