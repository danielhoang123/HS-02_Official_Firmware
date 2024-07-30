#include "Controller_DHT.h"
#include "MachTest_SP_IO.h"
// #include "debugkxn.h"

Dht_Data::Dht_Data()
{
    this->nameDevice = "DHT";
    this->timeInterval = 4000;
    this->valueDevice = "Ready";
    this->valueDevice1 = "";
}

bool Dht_Data::getData()
{

    if (dht)
    {
        // debug_DHT_ln(F("Start Read DHT"));
        float h, t;
        h = dht->readHumidity();
        t = dht->readTemperature();
        // debug_DHT_ln(F("Done Read DHT"));
        // if (isnan(h) || isnan(t))
        //     return true;

        String tempString = String(t) + "    " + String(h);
        this->valueDevice = String(t) + String(char(223)) + "C";
        this->valueDevice1 = String(h) + "%";
        // debug_DHT_ln(tempString);
    }

    return true;
}

bool Dht_Data::reInit(uint8_t _type)
{
    deInit();
    dht = new (DHT)(8, _type);
    dht->begin();
    return 1;
}

bool Dht_Data::init()
{
    deInit();
    this->timeInterval = 100;
    dht = new (DHT)(8, DHT11);
    this->nameDevice = "DHT11";
    dht->begin();

    delay(200);
    float t = dht->readTemperature();
    if (t < 5)
    {
        delay(200);
        deInit();
        dht = new (DHT)(8, DHT22);
        this->nameDevice = "DHT2x";
    }
    this->isRun = true;
    return true;
}

bool Dht_Data::deInit()
{
    if (dht)
    {
        delete dht;
        dht = 0;
    }
    pinMode(9, INPUT);
    this->valueDevice = "No device";
    this->nameDevice = "DHT";
    this->isRun = false;
    return true;
}

Dht_Data Dht_Device;
