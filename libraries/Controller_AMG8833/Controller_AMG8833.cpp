#include "Controller_AMG8833.h"
#include "debugkxn.h"

Controller_AMG8833_Data::Controller_AMG8833_Data()
{
    this->nameDevice = "AMG8833";
    this->timeInterval = 250;
    // this->valueDevice = "No device";
    this->Add_AddressList(0x69);
    //   this->Add_HsCode(1518);
    // Add your code here
}

Controller_AMG8833_Data::~Controller_AMG8833_Data()
{
}

bool Controller_AMG8833_Data::getData()
{
    // Add your code here
    this->valueDevice = "";
    thermal = this->amg->readThermistor();
    this->valueDevice += String(thermal);
    return true;
}

bool Controller_AMG8833_Data::init()
{
    deInit();
    // Add your code here
    this->amg = new Adafruit_AMG88xx;
    bool status;
    // default settings
    status = this->amg->begin();
    if (!status)
    {
        this->valueDevice = "AMG8833 not Found!";
    }
    return 1;
}

bool Controller_AMG8833_Data::deInit()
{
    // Add your code here
    delete amg;
    amg = nullptr;
    // if(this->amg != NULL){
    //     delete amg;
    // }
    return 1;
}

Controller_AMG8833_Data device_Controller_AMG8833;