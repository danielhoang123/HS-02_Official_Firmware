#include "Controller_I2C_Scanner.h"
#include "MachTest_SP_IO.h"

Controller_I2C_Scanner_Data::Controller_I2C_Scanner_Data()
{
    this->nameDevice = "I2C Scanner";
    this->timeInterval = 4000;
    this->valueDevice = "Ready";
    // Add your code here
}

bool Controller_I2C_Scanner_Data::getData()
{
    // Add your code here

    this->valueDevice = "";

    for (byte address = 1; address < 127; ++address)
    {

        Wire.beginTransmission(address);
        byte error = Wire.endTransmission();

        if (error == 0 && address != 39)
        {

            this->valueDevice += "0x" + String(address, HEX) + " ";

            if (address < 16)
            {
                this->valueDevice += "0";
            }
        }
        else if (error == 0 && address == 39)
        {

            this->valueDevice1 = "LCD's I2C: 0x" + String(address, HEX);
        }
    }
    return true;
}

bool Controller_I2C_Scanner_Data::init()
{
    deInit();
    // Add your code here
    this->timeInterval = 100;
    Wire.begin();
    return 1;
}

bool Controller_I2C_Scanner_Data::deInit()
{
    // Add your code here
    
    return 1;
}

Controller_I2C_Scanner_Data I2C_Scanner_Device;