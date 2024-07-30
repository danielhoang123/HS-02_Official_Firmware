#ifndef Controller_DHT_H_
#define Controller_DHT_H_

#include "DHT.h"
#include "dataAdapter.h"
#include "view_LCD_Text.h"

class Dht_Data : public Data_Adapter
{
public:
    DHT *dht;
    Dht_Data();
    bool getData();
    bool reInit(uint8_t _type);
    bool init();
    bool deInit();
};

extern Dht_Data Dht_Device;

#endif

