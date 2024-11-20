#include "em_device.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_timer.h"
#include "bsp.h"

#define timer3TopValue 874
#define timer2TopValue 50
//gpio settings



/*
 * Frequency Generation
 * desiredFrequency=(timerFrequency)/(2*prescaler*(topValue+1))
 */

/*
 * Timer Interrupt
 * seconds that pass till the timer counts to top value = (timer frequency)/(presclaer*topValue)
 */
void initGpio(void)
{
  // activate gpio clock
  CMU_ClockEnable(cmuClock_GPIO, true);

  // pins are configurated as outputs
  GPIO_PinModeSet(gpioPortE, 2, gpioModePushPull, 1);
  GPIO_PinModeSet(gpioPortE, 3, gpioModePushPull, 1);
}


//timer configuration
void initTimer(void)
{
  // activate timer3 clock
  CMU_ClockEnable(cmuClock_TIMER3, true);

 //timer3 structs
  TIMER_InitCC_TypeDef timerCCInit = TIMER_INITCC_DEFAULT;
  timerCCInit.mode = timerCCModeCompare; //compare mod is selected for frequency generation
  timerCCInit.cmoa=timerOutputActionToggle;
  TIMER_InitCC(TIMER3, 2, &timerCCInit); //timer3 channel 2 is selected

 //timer3  output is directed to pe2 pin via TIMER3->ROUTE register
  //TIMER_ROUTE_CC2PEN : CC Channel 2 Pin Enable
  //TIMER_ROUTE_LOCATION_LOC1 : Shifted mode LOC1 for TIMER_ROUTE
  TIMER3->ROUTE |= (TIMER_ROUTE_CC2PEN | TIMER_ROUTE_LOCATION_LOC1);


  TIMER_TopSet(TIMER3,timer3TopValue);

  TIMER_Init_TypeDef timer3Init = TIMER_INIT_DEFAULT;
  timer3Init.prescale = timerPrescale16;
  TIMER_Init(TIMER3, &timer3Init);

  // activate timer3 clock
  CMU_ClockEnable(cmuClock_TIMER2, true);

  //timer2 structs
  TIMER_Init_TypeDef timer2Init=TIMER_INIT_DEFAULT;
  timer2Init.prescale=timerPrescale16;
  TIMER_TopSet(TIMER2, timer2TopValue);
  TIMER_Init(TIMER2, &timer2Init);
  NVIC_EnableIRQ(TIMER2_IRQn);
  TIMER_IntEnable(TIMER2, TIMER_IF_OF); //tim2 will create an interrupt when it reaches top value

}
void TIMER2_IRQHandler()
{
  uint32_t flags = TIMER_IntGet(TIMER2);
  TIMER_IntClear(TIMER2, flags);//clear interrupt flags
  GPIO_PinOutToggle(gpioPortE, 3);


}
int main(void)
{
  // Chip errata
  CHIP_Init();

  // Initializations
  initGpio();
  initTimer();

  while (1) {
   // EMU_EnterEM1(); // Enter EM1 (won't exit)
  }
}

