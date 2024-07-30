#ifndef Controller_Servo_H__
#define Controller_Servo_H__
#include "dataAdapter.h"

// include your Libraries here
// Include the Servo library
#include <Servo.h>
// Declare the Servo pin

// Create a servo object

class Controller_Servo_Data : public Data_Adapter
{
public:
    // Add your declare here
    Servo * myServo;
    uint8_t position = 0;
    Controller_Servo_Data();
    virtual ~Controller_Servo_Data(){};
    bool getData();
    bool init();
    bool deInit();
};

extern Controller_Servo_Data Servo_Device;
#endif