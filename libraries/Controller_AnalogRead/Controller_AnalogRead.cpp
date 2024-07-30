#include "Controller_AnalogRead.h"
#include "MachTest_SP_IO.h"
#include "debugkxn.h"

Controller_AnalogRead_Data::Controller_AnalogRead_Data()
{
    this->nameDevice = "Analog";
    this->timeInterval = 4000;
    this->valueDevice = "Ready";
    // Add your code here
}

bool Controller_AnalogRead_Data::getData()
{
    // Add your code here
    float sensorValue = analogRead(A3);
    float estimated_x = this->kalmanFilter_Analog->updateEstimate(sensorValue);

    this->valueDevice = String(estimated_x);
    return true;
}

bool Controller_AnalogRead_Data::init()
{
    deInit();
    // Add your code here
    this->timeInterval = 100;
    this->kalmanFilter_Analog = new SimpleKalmanFilter(3, 3, 0.1);
    return 1;
}

bool Controller_AnalogRead_Data::deInit()
{
    // Add your code here
    delete kalmanFilter_Analog;
    kalmanFilter_Analog = nullptr;
    // if (this->kalmanFilter_Analog != NULL)
    // {
    //     delete kalmanFilter_Analog;
    // }
    return 1;
}

Controller_AnalogRead_Data Analog_Device;