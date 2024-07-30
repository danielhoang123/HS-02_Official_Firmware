/**
 * @file Blink.h
 * @version 1.0
 *
 * @section License
 * Copyright (C) 2015-2016, Mikael Patel
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * @section Description
 * This Arduino sketch uses the Scheduler library.
 * Blink as a template class.
 */

#ifndef Kxn_ReadSerial_H_
#define Kxn_ReadSerial_H_
#include <Scheduler.h>

// template<unsigned long baud_K>
template<int mSer = 0>
class ReadSerial_Class {
public:
  // volatile uint8_t time;
  // _serial_t & seri;
  // Stream * sSer;
  // Stream & uu;
  ReadSerial_Class(){
    #ifdef SCHEDULER_H
    Scheduler.start(this->setup, this->loop);
    #endif
    // sSer = new SoftwareSerial(2,3);
    // sSer->begin(9600);
    // uu = (ii);
  }
  // static void println(String pp){
  //   seri.println(pp);
  // }
  static void haha(){
    
  }
  
  static void setup()
  {
    pinMode(13, OUTPUT);
    // DUMP(micros());
  }
  static void loop()
  {
    digitalWrite(13, HIGH);
    delay(100);
    digitalWrite(13, LOW);
    delay(100);
    haha();
    // time = 100;
  }

  
};

class test{
  private:
    
  public:
    volatile uint8_t pin;
    volatile unsigned long timeDelay;
    
    test(uint8_t t_pin, unsigned long t_timeDL){
      this->pin = t_pin;
      this->timeDelay = t_timeDL;
    }
    
    void RunTest(){
      // digitalWrite(pin, 1);
      // delay(this->timeDelay);
      // digitalWrite(this->pin, 0);
      // delay(this->timeDelay);
    }
    static void Run(){
      // RunTest();
    }
};

//class kxnFunction{
//  public:
//  kxnFunction(func_t CALLBACK){
//    Scheduler.start(CALLBACK);
//  }
//};

#endif
