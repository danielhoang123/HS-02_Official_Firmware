#ifndef _BTN_H_PROCESS_H___
#define _BTN_H_PROCESS_H___ 
#include "OneButton.h"

extern OneButton btn_start;
extern OneButton btn_next;
extern OneButton btn_previous;

extern void buttonInit();
extern void buttonLoop();

extern void Start_do_1_Click();
extern void Up_do_0_Click();
extern void Down_do_0_Click();
extern void Start_do_2_Click();

#endif
