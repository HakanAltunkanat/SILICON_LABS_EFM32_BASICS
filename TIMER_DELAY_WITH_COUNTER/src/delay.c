/*
 * delay.c
 *
 *  Created on: 13 Nov 2024
 *      Author: Step
 */

#include "delay.h"
#include "em_device.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_timer.h"
#include "bsp.h"
#include <stdbool.h>


#define timerTopValue 13.67 //calculated coefficent to create 1ms delay base

void timerInit(void)
{
  CMU_ClockEnable(cmuClock_TIMER1, true); //activates timer1 clcok

  TIMER_Init_TypeDef init= TIMER_INIT_DEFAULT; //timer struct
  init.enable=false; //timer is not enabled at the beginning
  init.prescale=timerPrescale1024;
  TIMER_Init(TIMER1, &init);
}

void delay(int ms)
{
  static bool config=false; //timer configuration is done only once
  if(!config)
    {
      timerInit();
      config=true;
    }
  TIMER_TopSet(TIMER1,((int)(ms*timerTopValue))); //top value is adjusted depending on input
  TIMER_Enable(TIMER1, true);
  while(TIMER_CounterGet(TIMER1)<((int)(ms*timerTopValue))); //mcu will wait till the timer reaches top value
  TIMER_Enable(TIMER1, false);
  TIMER_CounterSet(TIMER1, 0); //counter is reset
}

