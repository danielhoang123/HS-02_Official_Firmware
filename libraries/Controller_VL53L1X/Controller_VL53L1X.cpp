#include "Controller_VL53L1X.h"
#include "debugkxn.h"

Controller_VL53L1X_Data::Controller_VL53L1X_Data()
{
    this->nameDevice = "VL53L1X";
    this->timeInterval = 250;
    this->valueDevice = "No device";
    this->Add_AddressList(0x29);
    //   this->Add_HsCode(1518);
    // Add your code here
}

Controller_VL53L1X_Data::~Controller_VL53L1X_Data()
{
}

bool Controller_VL53L1X_Data::getData()
{
    // Add your code here
    this->valueDevice = "";
    this->valueDevice1 = "";

        if (this->vl53->dataReady())
    {
        // new measurement for the taking!
        distance = this->vl53->distance();
        if (distance == -1)
        {
            // something went wrong!
            // Serial.print(F("Couldn't get distance: "));
            // Serial.println(this->vl53->vl_status);
            this->valueDevice += String(this->vl53->vl_status);
            return;
        }
        // Serial.print(F("Distance: "));
        // Serial.print(distance);
        // Serial.println(" mm");
        this->valueDevice += String(distance) + " mm";
        // data is read out, time for another reading!
        this->vl53->clearInterrupt();
    }

    this->valueDevice1 += String(this->vl53->getTimingBudget()) + " ms";

    return true;
}

bool Controller_VL53L1X_Data::init()
{
    deInit();
    // Add your code here
    this->vl53 = new Adafruit_VL53L1X(XSHUT_PIN, IRQ_PIN);
    Wire.begin();

    if (!this->vl53->begin(0x29, &Wire))
    {
        this->valueDevice = "Init Failed!";
        while (1)
            delay(10);
    }

    if (!this->vl53->startRanging())
    {
        this->valueDevice = "Ranging Failed";
        while (1)
            delay(10);
    }

    this->vl53->setTimingBudget(50);

    /*
    vl.VL53L1X_SetDistanceThreshold(100, 300, 3, 1);
    vl.VL53L1X_SetInterruptPolarity(0);
    */
    return 1;
}

bool Controller_VL53L1X_Data::deInit()
{
    // Add your code here
    delete vl53;
    vl53 = nullptr;
    return 1;
}

Controller_VL53L1X_Data device_Controller_VL53L1X;