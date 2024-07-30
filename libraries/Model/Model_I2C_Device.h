#ifndef _Model_I2C_Device_H_
#define _Model_I2C_Device_H_

#include "dataAdapter.h"
#include "LinkedList.h"

class Model_I2C_Device : public Data_Adapter
{
public:
    // uint8_t i2cAddress;
    LinkedList<uint8_t> myI2C_Address_List = LinkedList<uint8_t>();

    Model_I2C_Device(){};

    void Add_AddressList(uint8_t addressI2C){
        myI2C_Address_List.add(addressI2C);
    }

    void Clear_AddressList(){
        myI2C_Address_List.clear();
    }

    // bool getData();

    // bool init();
    // bool deInit();
    // uint16_t hsCode;
    // uint8_t i2cAddress;
};

#endif