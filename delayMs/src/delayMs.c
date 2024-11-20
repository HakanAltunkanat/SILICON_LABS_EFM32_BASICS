/*
 * delayMs.c
 *
 *  Created on: 13 Nov 2024
 *      Author: Step
 */
#include "delayMs.h"
#include <stdbool.h>
#include "em_device.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_timer.h"
#include "bsp.h"

#define delayValueMs 1000 //1 ms base delay time
#define timerPrescaler 16

int delayCounter=0; //variable to check if the desired delay is completed

void initTimer(void)
{
  CMU_ClockEnable(cmuClock_TIMER1, true); //activates timer1 clock

  TIMER_Init_TypeDef init=TIMER_INIT_DEFAULT; //timer 1 struct
  init.enable=false;
  init.prescale=timerPrescale16;
  TIMER_Init(TIMER1, &init);
  TIMER_TopSet(TIMER1, CMU_ClockFreqGet(cmuClock_TIMER1)/(timerPrescaler*delayValueMs));
  NVIC_EnableIRQ(TIMER1_IRQn);
  TIMER_IntEnable(TIMER1, TIMER_IF_OF);

}

void delayMs(int ms)
{
  static bool configuration=false; //timer configuration is done only once
  if(!configuration)
    {
      initTimer();
      configuration=true;
    }
  TIMER_Enable(TIMER1, true); //activates timer
  while(delayCounter<ms); //delay
  TIMER_Enable(TIMER1, false); //deactivates timer
  delayCounter=0;
}

void TIMER1_IRQHandler(void)
{
  uint32_t flags=TIMER_IntGet(TIMER1);
  TIMER_IntClear(TIMER1, flags); //clear flags
  delayCounter++;
}
