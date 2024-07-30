#include "Manager_I2C_Devices.h"
#include "view_LCD_Text.h"
#include "Btn_Process.h"
// #include "debugkxn.h"
#include <LinkedList.h>

Manager_I2C_Data::Manager_I2C_Data()
{
    this->nameDevice = "Manager_I2C";
    this->timeInterval = 250;
    this->valueDevice = "2 click Start";
    this->isRun = false;
}

bool Manager_I2C_Data::getData()
{
    // Step 1: Scan I2C Address list
    // Step 2: Show available I2C Device
    // Step 3: Init 2 Button (Next and Start)
    // Step 4: Select and run I2C Device
    // Step 5: Re Init 2 Button to default
    Manager_I2C_Device.myI2C_Devices_List.clear();
    Add_I2C_Device();
    uint8_t tempGetI2cAddress = GetI2C_Address();
    ManagerI2C_Device_InitButton();
    Next_DeviceI2C();

    while (this->isRun)
    {
        buttonLoop();
        RunDeviceI2C_WithIndex(Manager_I2C_Device.indexI2CList.get(Manager_I2C_Device.currentI2C_DeviceIndex).index);
    }

    buttonInit();

    this->valueDevice = "2 click Start";

    return true;
}

bool Manager_I2C_Data::init()
{
    // deInit();
    lcd.clear();
    return 1;
}

bool Manager_I2C_Data::deInit()
{
    this->nameDevice = "Manager_I2C";
    this->timeInterval = 2000;
    this->valueDevice = "No device";
    this->isRun = false;
    Stop_DeviceI2C();
    return 1;
}

int Manager_I2C_Data::GetI2C_Address()
{
    int nDevices = 0, address_Detect = 1;
    // indexI2CList.clear();
    Manager_I2C_Device.indexI2CList.clear();
    // Serial.println("Scanning...");

    for (int address = 1; address < 127; ++address)
    {
        // The i2c_scanner uses the return value of
        // the Write.endTransmisstion to see if
        // a device did acknowledge to the address.
        Wire.beginTransmission(address);
        byte error = Wire.endTransmission();

        if (error == 0)
        {
            // Serial.print("I2C device found at address 0x");
            if (address < 16)
            {
                // Serial.print("0");
            }
            // Serial.print(address, HEX);
            // Serial.println("  !");

            ++nDevices;
            address_Detect = address;
            ScanDeviceI2C_WithAddress(address_Detect);
        }
        else if (error == 4)
        {
            // Serial.print("Unknown error at address 0x");
            if (address < 16)
            {
                // Serial.print("0");
            }
            // Serial.println(address, HEX);
            address_Detect = address;
            ScanDeviceI2C_WithAddress(address_Detect);
        }
    }
    if (nDevices == 0)
    {
        // Serial.println("No I2C devices found\n");
    }
    else
    {
        // Serial.println("done\n");
    }

    return address_Detect;
}

void Manager_I2C_Data::ScanDeviceI2C_WithAddress(uint8_t address__)
{
    // for (int cf = 0; cf < myI2C_Devices_List.size(); cf++)
    for (int cf = 0; cf < Manager_I2C_Device.myI2C_Devices_List.size(); cf++)
    {
        uint8_t tempSizeAddressList = Manager_I2C_Device.myI2C_Devices_List.get(cf)->myI2C_Address_List.size();
        if (tempSizeAddressList > 0)
        {
            for (int cf2 = 0; cf2 < tempSizeAddressList; cf2++)
            {
                uint8_t tempAddress = Manager_I2C_Device.myI2C_Devices_List.get(cf)->myI2C_Address_List.get(cf2);
                // uint16_t tempHsCode = Manager_I2C_Device.myI2C_Devices_List.get(cf)->Get_HS_Code();

                if (address__ == tempAddress)
                {
                    // debug_manager_I2C_deviceln("tempHsCode: " + String(tempHsCode));
                    // debug_manager_I2C_deviceln("tempAddress: " + String(tempAddress));

                    // myI2C_Devices_List.get(cf)->Set_HS_Code(100);
                    // tempHsCode = myI2C_Devices_List.get(cf)->Get_HS_Code();
                    // debug_manager_I2C_deviceln("Index: " + String(cf));

                    // indexI2CList.add(cf);
                    struct_I2C_DeviceInfo tempI2C_info;
                    tempI2C_info.index = cf;
                    tempI2C_info.address = tempAddress;

                    Manager_I2C_Device.indexI2CList.add(tempI2C_info);
                }
            }
        }
    }
}

void Manager_I2C_Data::RunDeviceI2C_WithIndex(uint8_t index__)
{
    if (Manager_I2C_Device.myI2C_Devices_List.get(index__)->isRun == false)
        return;

    Manager_I2C_Device.myI2C_Devices_List.get(index__)->init();

    while (Manager_I2C_Device.myI2C_Devices_List.get(index__)->isRun)
    {
        // debug_manager_I2C_deviceln(F("run myI2C_Devices_List.get(cf).getData();"));
        if (millis() - Current_Millis >= Manager_I2C_Device.myI2C_Devices_List.get(Manager_I2C_Device.indexI2CList.get(Manager_I2C_Device.currentI2C_DeviceIndex).index)->timeInterval)
        {
            Current_Millis = millis();
            Manager_I2C_Device.myI2C_Devices_List.get(index__)->getData();
            ShowLCD(Manager_I2C_Device.myI2C_Devices_List.get(index__)->nameDevice, Manager_I2C_Device.myI2C_Devices_List.get(index__)->valueDevice, Manager_I2C_Device.myI2C_Devices_List.get(index__)->valueDevice1, Manager_I2C_Device.myI2C_Devices_List.get(index__)->valueDevice2);
        }
        buttonLoop();
    }

    Manager_I2C_Device.myI2C_Devices_List.get(index__)->isRun = false;
    Manager_I2C_Device.myI2C_Devices_List.get(index__)->deInit();
}

void Start_DeviceI2C()
{
    uint8_t tempSizeIndexI2C_List = Manager_I2C_Device.indexI2CList.size();

    if (tempSizeIndexI2C_List > 0)
    {
        uint8_t temI2cIndex = Manager_I2C_Device.currentI2C_DeviceIndex;
        uint8_t tempI2C_IndexDevice = Manager_I2C_Device.indexI2CList.get(temI2cIndex).index;
        uint8_t tempI2C_AddressDevice = Manager_I2C_Device.indexI2CList.get(temI2cIndex).address;

        Model_I2C_Device *tempI2C_Device = Manager_I2C_Device.myI2C_Devices_List.get(tempI2C_IndexDevice);

        tempI2C_Device->deInit();
        tempI2C_Device->i2cAddress = tempI2C_AddressDevice;
        tempI2C_Device->init();
        tempI2C_Device->isRun = true;

        // debug_manager_I2C_deviceln(F("Start_DeviceI2C"));
    }
    else
    {
        // debug_manager_I2C_deviceln(F("Start No DeviceI2C"));
    }
}

void Stop_DeviceI2C()
{
    uint8_t tempSizeIndexI2C_List = Manager_I2C_Device.indexI2CList.size();

    if (tempSizeIndexI2C_List > 0)
    {
        uint8_t temI2cIndex = Manager_I2C_Device.currentI2C_DeviceIndex;
        uint8_t tempI2C_IndexDevice = Manager_I2C_Device.indexI2CList.get(temI2cIndex).index;

        Model_I2C_Device *tempI2C_Device = Manager_I2C_Device.myI2C_Devices_List.get(tempI2C_IndexDevice);
        if (tempI2C_Device->isRun == true)
        {
            tempI2C_Device->isRun = false;
            tempI2C_Device->deInit();
        }

        // debug_manager_I2C_deviceln(F("Stop_DeviceI2C"));
        // debug_manager_I2C_deviceln(temI2cIndex);
        // Manager_I2C_Device.myI2C_Devices_List.get(tempI2C_IndexDevice)->isRun = false;
        // Manager_I2C_Device.myI2C_Devices_List.get(tempI2C_IndexDevice)->deInit();

        String tempName = Manager_I2C_Device.myI2C_Devices_List.get(tempI2C_IndexDevice)->nameDevice;
        // uint8_t tempValue = Manager_I2C_Device.myI2C_Devices_List.get(tempI2C_IndexDevice)->i2cAddress;
        uint8_t tempValue = Manager_I2C_Device.indexI2CList.get(temI2cIndex).address;
        ShowLCD(tempName, "0x" + String(tempValue, HEX), "", "");
    }
}

void Next_DeviceI2C()
{
    uint8_t tempSizeIndexI2C_List = Manager_I2C_Device.indexI2CList.size();

    if (tempSizeIndexI2C_List > 0)
    {
        uint8_t temI2cIndex = Manager_I2C_Device.currentI2C_DeviceIndex;
        uint8_t tempI2C_IndexDevice = Manager_I2C_Device.indexI2CList.get(temI2cIndex).index;
        Model_I2C_Device *tempI2C_Device = Manager_I2C_Device.myI2C_Devices_List.get(tempI2C_IndexDevice);

        if (tempI2C_Device->isRun)
        {
            tempI2C_Device->deInit();
            tempI2C_Device->isRun = false;
        }

        Manager_I2C_Device.currentI2C_DeviceIndex++;
        
        if (Manager_I2C_Device.currentI2C_DeviceIndex >= Manager_I2C_Device.indexI2CList.size())
            Manager_I2C_Device.currentI2C_DeviceIndex = 0;

        temI2cIndex = Manager_I2C_Device.currentI2C_DeviceIndex;
        tempI2C_IndexDevice = Manager_I2C_Device.indexI2CList.get(temI2cIndex).index;
        tempI2C_Device = Manager_I2C_Device.myI2C_Devices_List.get(tempI2C_IndexDevice);

        String tempName = tempI2C_Device->nameDevice;
        uint8_t tempValue = Manager_I2C_Device.indexI2CList.get(temI2cIndex).address;
        lcd.clear();
        ShowLCD(tempName, "0x" + String(tempValue, HEX), "", "");

        // debug_manager_I2C_deviceln(F("Next I2C Click "));
        // debug_manager_I2C_deviceln(Manager_I2C_Device.currentI2C_DeviceIndex);
        // debug_manager_I2C_deviceln(tempI2C_Device->hsCode);
        // debug_manager_I2C_deviceln(tempValue);
        // debug_manager_I2C_deviceln(tempName);
    }else{
        ShowLCD(Manager_I2C_Device.nameDevice , Manager_I2C_Device.valueDevice, Manager_I2C_Device.valueDevice1, Manager_I2C_Device.valueDevice2);
    }
}

// void Next_DeviceI2C()
// {
//     uint8_t temI2cIndex = Manager_I2C_Device.currentI2C_DeviceIndex;
//     uint8_t tempI2C_IndexDevice = Manager_I2C_Device.indexI2CList.get(temI2cIndex).index;

//     if (Manager_I2C_Device.myI2C_Devices_List.get(tempI2C_IndexDevice)->isRun)
//     {
//         Manager_I2C_Device.myI2C_Devices_List.get(tempI2C_IndexDevice)->deInit();
//         Manager_I2C_Device.myI2C_Devices_List.get(tempI2C_IndexDevice)->isRun = false;
//     }

//     Manager_I2C_Device.currentI2C_DeviceIndex++;
//     if (Manager_I2C_Device.currentI2C_DeviceIndex >= Manager_I2C_Device.indexI2CList.size())
//         Manager_I2C_Device.currentI2C_DeviceIndex = 0;

//     temI2cIndex = Manager_I2C_Device.currentI2C_DeviceIndex;
//     tempI2C_IndexDevice = Manager_I2C_Device.indexI2CList.get(temI2cIndex).index;

//     String tempName = Manager_I2C_Device.myI2C_Devices_List.get(tempI2C_IndexDevice)->nameDevice;
//     // uint8_t tempValue = Manager_I2C_Device.myI2C_Devices_List.get(tempI2C_IndexDevice)->i2cAddress;
//     uint8_t tempValue = Manager_I2C_Device.indexI2CList.get(temI2cIndex).address;
//     ShowLCD(tempName, "0x" + String(tempValue, HEX));

//     debug_manager_I2C_deviceln(F("Next I2C Click "));
//     debug_manager_I2C_deviceln(Manager_I2C_Device.currentI2C_DeviceIndex);
//     debug_manager_I2C_deviceln(Manager_I2C_Device.myI2C_Devices_List.get(tempI2C_IndexDevice)->hsCode);
//     debug_manager_I2C_deviceln(Manager_I2C_Device.myI2C_Devices_List.get(tempI2C_IndexDevice)->i2cAddress);
//     debug_manager_I2C_deviceln(tempName);
// }

void Manager_I2C_Data::ManagerI2C_Device_InitButton()
{
    btn_next.attachClick(&Next_DeviceI2C);
    btn_start.attachClick(&Stop_DeviceI2C);
    btn_start.attachDoubleClick(&Start_DeviceI2C);
}
Manager_I2C_Data Manager_I2C_Device;
