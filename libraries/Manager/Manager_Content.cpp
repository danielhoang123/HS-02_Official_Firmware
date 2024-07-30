#include "Manager_Content.h"

// Data_Adapter *listDevice[] = {
//     // &Dht_Device,
//     // &sieuAm_Device,
//     // &Manager_I2C_Device,
// };

// unsigned long contentManager_TimeInterval;

// https://www.geeksforgeeks.org/how-to-find-size-of-array-in-cc-without-using-sizeof-operator/
// int LAST_ID_DEVICE = *(&listDevice + 1) - listDevice;

// int Choseen_Menu = 0; // Cài đặt số Menu lựa chọn loại Module

// unsigned long Current_Millis = millis();
// void AddManagerContent_Device()
// {
//     manager_Content.my_Devices_List.add(&Manager_I2C_Device);
//     manager_Content.my_Devices_List.add(&Dht_Device);
//     manager_Content.my_Devices_List.add(&sieuAm_Device);
// }
extern void AddManagerContent_Device();

bool Manager_Content::getData()
{

    if (millis() - this->Current_Millis > this->timeInterval) // Sau mỗi 0.25s mới cập nhập
    {

        this->checkIndex();
        this->Current_Millis = millis();
        uint8_t tempCurrentIndex = this->Choseen_Menu;

        if (this->sizeMyDeviceList > 0)
        {
            if (this->my_Devices_List.get(tempCurrentIndex)->isRun == true)
            {
                bool tempFlag = this->my_Devices_List.get(tempCurrentIndex)->getData();
            }
        }

        //
        ShowLCD(this->my_Devices_List.get(tempCurrentIndex)->nameDevice, this->my_Devices_List.get(tempCurrentIndex)->valueDevice, this->my_Devices_List.get(tempCurrentIndex)->valueDevice1, "");
        // lcd.clear();         // Xóa màn hình
        // lcd.setCursor(2, 0); // Cột 2 dòng 0
        // lcd.print(this->my_Devices_List.get(tempCurrentIndex)->nameDevice);
        // lcd.setCursor(2, 1); // Cột 2 dòng 0
        // lcd.print(this->my_Devices_List.get(tempCurrentIndex)->valueDevice);
        // lcd.setCursor(2, 2); // Cột 2 dòng 0
        // lcd.print(this->my_Devices_List.get(tempCurrentIndex)->valueDevice1);
        this->timeInterval = this->my_Devices_List.get(tempCurrentIndex)->timeInterval;
    }
    return 1;
}

void Manager_Content::checkIndex() /* Có các mục menu 1 - 2 - 3 - 4*/
{
    if (this->Choseen_Menu >= this->sizeMyDeviceList)
    {
        this->Choseen_Menu = 0;
    }
    if (this->Choseen_Menu < 0)
    {
        this->Choseen_Menu = this->sizeMyDeviceList - 1;
    }
}

bool Manager_Content::init()
{
    this->checkIndex();
    uint8_t tempIndex = this->Choseen_Menu;
    if (this->sizeMyDeviceList > 0)
    {
        this->my_Devices_List.get(tempIndex)->init();
        this->my_Devices_List.get(tempIndex)->stopOtherReading = true;
        this->my_Devices_List.get(tempIndex)->isRun = true;
    }
    // if (listDevice[Choseen_Menu])
    //     listDevice[Choseen_Menu]->init();
    // listDevice[Choseen_Menu]->isRun = true;

    return 1;
}

bool Manager_Content::deInit()
{
    this->checkIndex();

    uint8_t tempIndex = this->Choseen_Menu;
    if (this->sizeMyDeviceList > 0)
    {
        if (this->my_Devices_List.get(tempIndex)->isRun == true)
        {
            bool tempStatus = this->my_Devices_List.get(tempIndex)->deInit();
            this->my_Devices_List.get(tempIndex)->isRun = false;
            this->my_Devices_List.get(tempIndex)->stopOtherReading = false;
        }
    }

    // if (listDevice[Choseen_Menu]->isRun == true)
    //     listDevice[Choseen_Menu]->deInit();
    // listDevice[Choseen_Menu]->isRun = false;

    return 1;
}

void Manager_Content::begin()
{

    // if (this->btnNext)
    // {
    //     LastNextFunction = this->btnNext->_clickFunc;
    // }

    this->my_Devices_List.clear();
    AddManagerContent_Device();
    this->sizeMyDeviceList = this->my_Devices_List.size();
}

// void Manager_Content::button_Init(OneButton *btnPrevious_, OneButton *btnNext_, OneButton *btnStart_)
// {
//     this->btnNext = btnNext_;
//     this->btnPrevious = btnPrevious_;
//     this->btnStart = btnStart_;

//     this->LastNextFunction = this->btnNext->_clickFunc;
//     this->LastPreviousFunction = this->btnPrevious->_clickFunc;
//     this->LastStartFunction_Click = this->btnStart->_clickFunc;
//     this->LastStartFunction_DoubleClick = this->btnStart->_doubleClickFunc;
// }

bool Manager_Content::stopBatteryReading()
{

    this->checkIndex();
    uint8_t tempIndex = this->Choseen_Menu;
    if (this->sizeMyDeviceList > 0)
    {
        // this->my_Devices_List.get(tempIndex)->init();
        // this->my_Devices_List.get(tempIndex)->stopOtherReading = true;
        // this->my_Devices_List.get(tempIndex)->isRun = true;
        return this->my_Devices_List.get(tempIndex)->stopOtherReading;
    }
    // if (listDevice[Choseen_Menu])
    //     listDevice[Choseen_Menu]->init();
    // listDevice[Choseen_Menu]->isRun = true;

    return 1;
}

Manager_Content manager_Content;