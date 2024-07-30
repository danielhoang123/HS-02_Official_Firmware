#ifndef MACH_TEST_H_SP_IO_H__
#define MACH_TEST_H_SP_IO_H__

    // #define NANO_VTHANH

    #if defined(NANO_VTHANH)
    // Chan Chuan
    #define PIN_1 9
    #define PIN_2 10
    #define PIN_3 12
    #define PIN_4 13

    // sieu am pin out
    #define TRIG_PIN PIN_4
    #define ECHO_PIN PIN_3

    // dht pin out
    #define DHTPIN PIN_1

    // Button pin

    #define BTN_NEXT_PIN        3
    #define BTN_PREVIOUS_PIN    2 // 4
    #define BTN_START_PIN       4    // 2

    


    #else
    // Chan Chuan
    #define PIN_1 9
    #define PIN_2 10
    #define PIN_3 12
    #define PIN_4 13

    // sieu am pin out
    #define TRIG_PIN PIN_4
    #define ECHO_PIN PIN_3

    // dht pin out
    #define DHTPIN PIN_1

    // Button pin

    #define BTN_NEXT_PIN 2
    #define BTN_PREVIOUS_PIN 3 // 4
    #define BTN_START_PIN 4    // 2

    #define BATTERY_LEVEL_PIN A1
    #define BUZZER_PIN A2
    #define LM35_PIN A0
    // #define BTN_NEXT_PIN        A3
    // #define BTN_PREVIOUS_PIN    A2 // 4
    // #define BTN_START_PIN       A1    // 2
    #endif

#endif
