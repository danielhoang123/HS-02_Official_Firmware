#include "Controller_LCD3f.h"
#include "debugkxn.h"

Controller_LCD3f_Data::Controller_LCD3f_Data()
{
    this->nameDevice = "LCD";
    this->timeInterval = 250;
    this->valueDevice = "No device";
    this->Add_AddressList(0x3f);
    //   this->Add_HsCode(1518);
    // Add your code here
}

Controller_LCD3f_Data::~Controller_LCD3f_Data()
{
}

bool Controller_LCD3f_Data::getData()
{
    // Add your code here
    this->valueDevice = "device value";

    this->lcd3f->setCursor(0, 0); // Cột 2 dòng 0
    this->lcd3f->print("Test LCD w/ 0x3f");
    this->lcd3f->setCursor(0, 1); // Cột 2 dòng 0
    this->lcd3f->print("This is Row No.2");
    this->lcd3f->setCursor(0, 2); // Cột 2 dòng 0
    this->lcd3f->print("This is Row No.3");
    this->lcd3f->setCursor(0, 3); // Cột 2 dòng 0
    this->lcd3f->print("This is Row No.4");
    return true;
}

bool Controller_LCD3f_Data::init()
{
    deInit();
    // Add your code here
    this->lcd3f = new LiquidCrystal_I2C(0x3f, 20, 4);
    this->lcd3f->init();
    this->lcd3f->backlight();
    this->lcd3f->clear();
    return 1;
}

bool Controller_LCD3f_Data::deInit()
{
    // Add your code here
    delete lcd3f;
    lcd3f = nullptr;
    return 1;
}

Controller_LCD3f_Data device_Controller_LCD3f;