/**
 * @file SchedulerBlinkTemplateClass.ino
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
 * This Arduino sketch uses the Scheduler library. Rewrite of
 * SchedulerBlink with template class.
 */
 
#include <Scheduler.h>
#include "ArduinoTrace.h"
#include "SoftwareSerial.h"

#include "Blink.h"
#include "Kxn_ReadSerial.h"

// Blink task functions with pin and delay period
Blink<10, 250> blink1;
// Blink<11, 500> blink2;
// Blink<12, 750> blink3;
Blink<9, 1000> blink;
ReadSerial_Class<> ser1;

test tt(8,500);

ReadSerial_Class<0> tttt;

void qq();
//kxnFunction rrr(qq);
void qq()
{
  Serial.println("qq Start!");
  delay(1000);
}

void setup()
{
  Serial.begin(57600);
  Serial.println("Setup Start!");
  blink.setup();
  Scheduler.start(blink1.setup, blink1.loop);
  // Scheduler.start(blink2.setup, blink2.loop);
  // Scheduler.start(blink3.setup, blink3.loop);
  ser1.setup();
  // Scheduler.startLoop(uuu);
  // Scheduler.startLoop(tt.Run);
  Serial.println("Setup done!");
}

void loop()
{
  blink.loop();
  // ser1.loop();
  // yield();
}

void uuu(){
  yield();
}
