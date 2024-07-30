#include "Manager_BatteryNBuzzer.h"

static unsigned int state = 0;

void Manager_BatteryNBuzzer::Battery_LCD()
{
    // if (millis() - startMillis_lcd >= 500)
    // {
    //     startMillis_lcd = millis();

    //     int acquiredValue = analogRead(A1);

    //     float temp_float = acquiredValue * 0.01;

    //     if (temp_float != 0)
    //     {
    //         if (temp_float >= 10.03 && temp_float < 10.15)
    //         {
    //             lcd.setCursor(17, 3);
    //             lcd.print("90%");

    //         }
    //         else if (temp_float >= 9.89 && temp_float < 10.01)
    //         {
    //             lcd.setCursor(17, 3);
    //             lcd.print("80%");
    //         }
    //         else if (temp_float >= 9.75 && temp_float < 9.87)
    //         {
    //             lcd.setCursor(17, 3);
    //             lcd.print("70%");
    //         }
    //         else if (temp_float >= 9.61 && temp_float < 9.73)
    //         {
    //             lcd.setCursor(17, 3);
    //             lcd.print("60%");
    //         }
    //         else if (temp_float >= 9.47 && temp_float < 9.59)
    //         {
    //             lcd.setCursor(17, 3);
    //             lcd.print("50%");
    //         }
    //         else if (temp_float >= 9.33 && temp_float < 9.45)
    //         {
    //             lcd.setCursor(17, 3);
    //             lcd.print("40%");
    //         }
    //         else if (temp_float >= 9.19 && temp_float < 9.31)
    //         {
    //             lcd.setCursor(17, 3);
    //             lcd.print("30%");
    //         }
    //         else if (temp_float >= 9.05 && temp_float < 9.17)
    //         {
    //             lcd.setCursor(17, 3);
    //             lcd.print("20%");
    //         }
    //         else if (temp_float >= 8.91 && temp_float < 9.03)
    //         {
    //             lcd.setCursor(17, 3);
    //             lcd.print("10%");
    //         }
    //         else if (temp_float >= 10.15)
    //         {
    //             lcd.setCursor(16, 3);
    //             lcd.print("100%");
    //         }
    //     }

    // int acquiredValue = analogRead(A1);

    // float temp_float = acquiredValue * 0.01;

    // if (temp_float != 0)
    // {
    //     if (temp_float >= 10.03 && temp_float < 10.15)
    //     {
    //         lcd.setCursor(17, 3);
    //         lcd.print("90%");
    //     }
    //     else if (temp_float >= 9.89 && temp_float < 10.01)
    //     {
    //         lcd.setCursor(17, 3);
    //         lcd.print("80%");
    //     }
    //     else if (temp_float >= 9.75 && temp_float < 9.87)
    //     {
    //         lcd.setCursor(17, 3);
    //         lcd.print("70%");
    //     }
    //     else if (temp_float >= 9.61 && temp_float < 9.73)
    //     {
    //         lcd.setCursor(17, 3);
    //         lcd.print("60%");
    //     }
    //     else if (temp_float >= 9.47 && temp_float < 9.59)
    //     {
    //         lcd.setCursor(17, 3);
    //         lcd.print("50%");
    //     }
    //     else if (temp_float >= 9.33 && temp_float < 9.45)
    //     {
    //         lcd.setCursor(17, 3);
    //         lcd.print("40%");
    //     }
    //     else if (temp_float >= 9.19 && temp_float < 9.31)
    //     {
    //         lcd.setCursor(17, 3);
    //         lcd.print("30%");
    //     }
    //     else if (temp_float >= 9.05 && temp_float < 9.17)
    //     {
    //         lcd.setCursor(17, 3);
    //         lcd.print("20%");
    //     }
    //     else if (temp_float >= 8.91 && temp_float < 9.03)
    //     {
    //         lcd.setCursor(17, 3);
    //         lcd.print("10%");
    //     }
    //     else if (temp_float >= 10.15)
    //     {
    //         lcd.setCursor(16, 3);
    //         lcd.print("100%");
    //     }
    // }

    // Kalman Filter
    int sensorVal_bat = analogRead(sensorPin_bat);
    float voltage_bat = sensorVal_bat * 0.098;

    // kalman process
    Pc_bat = P_bat + varProcess_bat; // predict covariance
    Xp_bat = Xe_bat;                 // predict state

    G_bat = Pc_bat / (Pc_bat + varVolt_bat);

    Zp_bat = Xp_bat;
    Xe_bat = G_bat * (voltage_bat - Zp_bat) + Xp_bat;
    P_bat = (1 - G_bat) * Pc_bat;

    // Serial.print(voltage);
    // Serial.print(",");
    // Serial.print(Xe);

    SUM_bat = SUM_bat - READING_bat[INDEX_bat];

    READING_bat[INDEX_bat] = voltage_bat;
    SUM_bat = SUM_bat + voltage_bat;
    INDEX_bat = (INDEX_bat + 1) % WINDOW_SIZE_bat;

    AVERAGE_bat = SUM_bat / WINDOW_SIZE_bat;

    lcd.setCursor(17, 3);
    lcd.print(AVERAGE_bat);
    lcd.setCursor(19, 3);
    lcd.print("%");
    // Serial.print(",");
    // Serial.println(AVERAGE);
    // delay(20);
}

void Manager_BatteryNBuzzer::Buzzer_Timer()
{
    if (millis() - buzzerTimer_startMillis >= 1000)
    {
        buzzerTimer_startMillis = millis();
        timer++;
        if (timer == 121)
        {
            state = 1;
        }
        // lcd.clear();

        // lcd.print("s");
        // if (120 - timer > 99)
        // {
        //     lcd.setCursor(16, 3);
        // }
        // else if (120 - timer <= 9)
        // {
        //     lcd.setCursor(18, 3);
        // }
        // else if (120 - timer < 0)
        // {
        //     lcd.setCursor(18, 3);
        // }
        // lcd.print(String(120 - timer));
    }

    switch (state)
    {
    case 1:
        if (millis() - buzzerBlinking_startMillis >= 50)
        {
            buzzerBlinking_startMillis = millis();
            temp = !temp;
            count++;

            if (count == 8)
            {
                
                state = 2;
            }
        }
        digitalWrite(A2, temp);
        break;

    case 2:  
        if (millis() - buzzerBlinking_startMillis_state >= 1000)
        {
            buzzerBlinking_startMillis_state = millis();
            state = 1;
            count = 0;
        }
    }

    lcd.setCursor(0, 3);
    lcd.print(120 - timer);
    lcd.print("s");

    // clear "s" at 3,3 when timer variable equal 21
    if (timer == 21)
    {
        lcd.setCursor(3, 3);
        lcd.print(" ");
    }

    // clear "s" at col2, row3 when timer variable equal 111
    if (timer == 111)
    {
        lcd.setCursor(2, 3);
        lcd.print(" ");
    }
}

void Manager_BatteryNBuzzer::Buzzer_Blinking()
{
    // if (timer > 5)
    // {
    //     en_flag1 = 1;
    // }

    // if (en_flag1 == 1 && state_1 == 0)
    // {
    //     if (millis() - buzzerBlinking_startMillis >= 50)
    //     {
    //         buzzerBlinking_startMillis = millis();
    //         temp = !temp;
    //         count++;
    //         Serial.println(count);
    //         if (count == 8)
    //         {
    //             en_flag1 = 0;

    //             state_1 = 1;

    //             Serial.print("Worked");
    //         }
    //     }
    // }
    // else if (en_flag1 == 0 && state_1 == 1)
    // {
    //     if (millis() - buzzerBlinking_startMillis_state >= 1000)
    //     {
    //         buzzerBlinking_startMillis_state = millis();
    //         en_flag1 = 1;
    //         count = 0;
    //         state_1 = 0;
    //         temp = 0;
    //     }
    // }

    // digitalWrite(A2, temp);

    // int temp_timer = timer;
    // if(temp_timer == 5){
    //     state = 1;
    // }

    // switch (state)
    // {
    // case 1:
    //     if (millis() - buzzerBlinking_startMillis >= 50)
    //     {
    //         buzzerBlinking_startMillis = millis();
    //         temp = !temp;
    //         count++;

    //         if (count == 8)
    //         {
    //             Serial.print("Worked");
    //             state = 2;
    //         }
    //     }
    //     break;
    // case 2:
    //     digitalWrite(A2, 0);
    //     if (millis() - buzzerBlinking_startMillis_state >= 1000)
    //     {
    //         buzzerBlinking_startMillis_state = millis();
    //         state = 1;
    //         count = 0;
    //     }
    // }

    // digitalWrite(A2, temp);
}

Manager_BatteryNBuzzer BuzzBat_Content;
