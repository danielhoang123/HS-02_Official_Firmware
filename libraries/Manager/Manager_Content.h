#ifndef Manager_Content_H__
#define Manager_Content_H__
#include "Arduino.h"
#include <LinkedList.h>
#include "dataAdapter.h"

#include "view_LCD_Text.h"
// #include "Sieu_Am.h"
// #include "CB_Dht.h"
// #include "Controller_DHT.h"
// #include "Manager_I2C_Devices.h"

// extern unsigned long Current_Millis;

// extern void Test_SP2();
// extern void Test_Choseen_Menu2();
// extern void initContentManager();
// extern void deInitContentManager();

class Manager_Content : public Data_Adapter
{
public:
    LinkedList<Data_Adapter *> my_Devices_List = LinkedList<Data_Adapter *>();
    int sizeMyDeviceList;
    int Choseen_Menu = 0; // Cài đặt số Menu lựa chọn loại Module

    bool getData();
    bool init();
    bool deInit();
    bool stopBatteryReading();
    void checkIndex();
    void begin();
    // void button_Init(OneButton *btnPrevious_, OneButton *btnNext_, OneButton *btnStart_);
};

extern Manager_Content manager_Content;

#endif