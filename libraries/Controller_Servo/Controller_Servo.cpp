#include "Controller_Servo.h"
#include "MachTest_SP_IO.h"

Controller_Servo_Data::Controller_Servo_Data()
{
    this->nameDevice = "Servo";
    this->timeInterval = 1500;
    this->valueDevice = "Ready";
    // Add your code here
}

bool Controller_Servo_Data::getData()
{
    // this->valueDevice = "";

    // temp++;
    
    // /*C1*/

    // if (temp == 1)
    // {

    //     this->valueDevice = "0" + String(char(223));
    //     Servo1.write(0);
    // }
    // else if (temp == 2)
    // {

    //     this->valueDevice = "90" + String(char(223));
    //     Servo1.write(90);
    // }
    // else if (temp == 3)
    // {

    //     this->valueDevice = "180" + String(char(223));
    //     Servo1.write(180);
    // }
    // else if (temp > 3)
    // {
    //     temp = 0;
    // }
    // else
    // {
    //     return;
    // }

    this->valueDevice = "";

    position++;

    if (position == 1)
    {
        this->myServo->write(0);

        this->valueDevice += "0" + String(char(223)) + " -> " + String(this->myServo->readMicroseconds()) + " (uS)";

        // this->myServo->writeMicroseconds(540);
    }
    else if (position == 2)
    {

        this->myServo->write(90);

        this->valueDevice += "90" + String(char(223)) + " -> " + String(this->myServo->readMicroseconds()) + " (uS)";

        // this->myServo->writeMicroseconds(2400);
    }
    else if (position == 3)
    {

        this->myServo->write(180);

        this->valueDevice += "180" + String(char(223)) + " -> " + String(this->myServo->readMicroseconds()) + " (uS)";

        // this->myServo->writeMicroseconds(2400);
    }

    else if (position == 4)
    {

        this->myServo->write(90);

        this->valueDevice += "90" + String(char(223)) + " -> " + String(this->myServo->readMicroseconds()) + " (uS)";

        // this->myServo->writeMicroseconds(2400);
    }

    else if (position > 4)
    {

        position = 1;

        // this->valueDevice += "0" + String(char(223));

        // this->myServo->writeMicroseconds(540);

        // this->myServo->write(0);
        this->valueDevice = "";

        this->myServo->write(0);

        this->valueDevice += "0" + String(char(223)) + " -> " + String(this->myServo->readMicroseconds()) + " (uS)";
    }
    else
    {
        return;
    }

    return true;
}

bool Controller_Servo_Data::init()
{
    deInit();
    // Add your code here
    this->myServo = new Servo;
    this->myServo->attach(5);
    return 1;
}

bool Controller_Servo_Data::deInit()
{
    // Add your code here
    delete myServo;
    myServo = nullptr;
    // if (this->myServo != NULL)
    // {
    //     delete myServo;
    // }
    pinMode(5, INPUT);
    return 1;
}

Controller_Servo_Data Servo_Device;