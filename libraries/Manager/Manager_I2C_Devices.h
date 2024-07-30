#ifndef _Manager_I2C_Device_H_
#define _Manager_I2C_Device_H_

#include "Wire.h"

#include "dataAdapter.h"
#include "Model_I2C_Device.h"
#include "LinkedList.h"

extern int GetI2C_Address();
extern void Stop_DeviceI2C();
extern void Next_DeviceI2C();
extern void Add_I2C_Device();

typedef struct {
    uint8_t index;
    uint8_t address;
}struct_I2C_DeviceInfo;

class Manager_I2C_Data : public Data_Adapter
{
public:
    LinkedList<Model_I2C_Device *> myI2C_Devices_List = LinkedList<Model_I2C_Device *>();
    LinkedList<struct_I2C_DeviceInfo> indexI2CList = LinkedList<struct_I2C_DeviceInfo>();
    uint8_t currentI2C_DeviceIndex = 0;

    Manager_I2C_Data();
    // Manager_I2C_Data(uint8_t addressNew, Manager_I2C_Data * p_I2C_Device);
    bool getData();
    bool init();
    bool deInit();

    int GetI2C_Address();
    void ScanDeviceI2C_WithAddress(uint8_t address__);
    void RunDeviceI2C_WithIndex(uint8_t index__);
    // void Select_DeviceI2C();
    // void Next_DeviceI2C();
    void ManagerI2C_Device_InitButton();
    // void ShowLCD(String nameDevice__, String valueDevice__);
};

extern Manager_I2C_Data Manager_I2C_Device;
#endif