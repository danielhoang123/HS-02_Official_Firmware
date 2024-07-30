#ifndef Controller_SHARP_Ngan_H__
#define Controller_SHARP_Ngan_H__
#include "dataAdapter.h"

// include your Libraries here
#include "SharpIR.h"

class Controller_SHARP_Ngan_Data : public Data_Adapter
{
public:
    // Add your declare here
    int shortType_distance;
    int shortType = 1080;
    SharpIR *shortSharpSensor;
    Controller_SHARP_Ngan_Data();
    virtual ~Controller_SHARP_Ngan_Data(){};
    bool getData();
    bool init();
    bool deInit();
};

extern Controller_SHARP_Ngan_Data SharpNgan_Device;
#endif