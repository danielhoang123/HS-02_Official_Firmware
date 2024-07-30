#include "Controller_PN532.h"
// #include "debugkxn.h"
PN532_I2C pn532_i2c(Wire);
String tagId;
Controller_PN532_Data::Controller_PN532_Data()
{
    this->nameDevice = "PN532";
    this->timeInterval = 250;
    // this->valueDevice = "No device";
    this->Add_AddressList(0x24);
    // this->Add_HsCode(1366);
    //  Add your code here
}

Controller_PN532_Data::~Controller_PN532_Data()
{
}

bool Controller_PN532_Data::getData()
{
    // Add your code here
    this->valueDevice = "";

    if (this->nfc->tagPresent())
    {
        NfcTag tag = this->nfc->read();
        tagId = tag.getUidString();
        this->valueDevice += "UID: " + tagId;
    }

    return true;
}

bool Controller_PN532_Data::init()
{
    deInit();
    // Add your code here
    // this->pn532_i2c = new PN532_I2C(Wire);
    this->nfc = new NfcAdapter(pn532_i2c);
    
    // NfcAdapter nfc = NfcAdapter(pn532_i2c);
    this->nfc->begin();
    return 1;
}

bool Controller_PN532_Data::deInit()
{
    // Add your code here
    delete nfc;
    nfc = nullptr;
    return 1;
}

Controller_PN532_Data device_Controller_PN532;