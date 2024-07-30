#ifndef Manager_BatteryNBuzzer__
#define Manager_BatteryNBuzzer__

#include "Arduino.h"
#include "dataAdapter.h"
#include "view_LCD_Text.h"

class Manager_BatteryNBuzzer : public Data_Adapter
{
public:
    boolean temp = 0, en_flag1 = 0;
    int count = 0;

    unsigned long startMillis_lcd = 0;
    unsigned long buzzerTimer_startMillis = 0;
    unsigned long buzzerBlinking_startMillis = 0;
    unsigned long buzzerBlinking_startMillis_state = 0;

    int timer = 0;

    void Battery_LCD();
    void Buzzer_Timer();
    void Buzzer_Blinking();

private:
    const int sensorPin_bat = A1;
    float varVolt_bat = 1.12184278324081E-05;
    float varProcess_bat = 1e-8;
    float Pc_bat = 0.0;
    float G_bat = 0.0;
    float P_bat = 1.0;
    float Xp_bat = 0.0;
    float Zp_bat = 0.0;
    float Xe_bat = 0.0;

    int WINDOW_SIZE_bat = 50;
    int INDEX_bat = 0;
    float VALUE_bat = 0;
    float SUM_bat = 0;
    float READING_bat[50];
    int AVERAGE_bat = 0;
};

extern Manager_BatteryNBuzzer BuzzBat_Content;

#endif