
#include "em_device.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_timer.h"
#include "bsp.h"

#define pwmTopValue 500

/*
 * pwmFrequency=(TimerClockFrequency)/(prescaler*topValue)
 * pwmDuty=(topValue*desiredPercent)/100
 */
//gpio settings
void initGpio(void)
{
  // Enable GPIO and clock
  CMU_ClockEnable(cmuClock_GPIO, true);

  // Configure PD6
  GPIO_PinModeSet(gpioPortD, 6, gpioModePushPull, 0);
}

//timer settings
void initTimer(void)
{
  // Enable clock for TIMER1 module
  CMU_ClockEnable(cmuClock_TIMER1, true);

  // Configure TIMER1 Compare/Capture for output compare
  // Use PWM mode, which sets output on overflow and clears on compare events
  TIMER_InitCC_TypeDef timerCCInit = TIMER_INITCC_DEFAULT;
  timerCCInit.mode = timerCCModePWM;
  TIMER_InitCC(TIMER1, 0, &timerCCInit);

  // Route TIMER1 CC0 to location 4 and enable CC0 route pin
  // TIM1_CC0 #4 is GPIO Pin PD6
  TIMER1->ROUTE |= (TIMER_ROUTE_CC0PEN | TIMER_ROUTE_LOCATION_LOC4);

  // Set top value to overflow at the desired PWM_FREQ frequency
  TIMER_TopSet(TIMER1, pwmTopValue);

  // Set compare value for initial duty cycle
  TIMER_CompareSet(TIMER1, 0, (TIMER_TopGet(TIMER1) * 50) / 100);

  // Initialize the timer
  TIMER_Init_TypeDef timerInit = TIMER_INIT_DEFAULT;
  timerInit.prescale = timerPrescale16;
  TIMER_Init(TIMER1, &timerInit);

}

int main(void)
{
  // Chip errata
  CHIP_Init();

  // Initializations
  initGpio();
  initTimer();
  while (1)
  {

  }
}

