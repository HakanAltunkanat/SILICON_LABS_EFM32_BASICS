#include <stdint.h>
#include <stdbool.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_rtc.h"
#include "em_lcd.h"
#include "segmentlcd.h"
#include "bsp_trace.h"
#include "config.h"
#define RTC_FREQ    32768
#define RTC_DIV 32

uint32_t minutes = 0;
uint32_t seconds=0;

void gpioConfig(void)
{
  CMU_ClockEnable(cmuClock_GPIO, true); //activates gpio config

  //PB9-PB10-PC7 are configured as inputs to use buttons
  GPIO_PinModeSet(gpioPortB, 9, gpioModeInputPullFilter, 1);
  GPIO_PinModeSet(gpioPortB, 10, gpioModeInputPullFilter, 1);
  GPIO_PinModeSet(gpioPortC, 7, gpioModeInputPullFilter, 1);

  //PC2 for buzzer to create alarm sound
  GPIO_PinModeSet(gpioPortC, 2, gpioModePushPull, 0);

  //EXTI Configurations

  NVIC_EnableIRQ(GPIO_EVEN_IRQn);
  NVIC_EnableIRQ(GPIO_ODD_IRQn);

  GPIO_ExtIntConfig(gpioPortB, 9, 9, false, true, true);
  GPIO_ExtIntConfig(gpioPortB, 10, 10, false, true, true);
  GPIO_ExtIntConfig(gpioPortC, 7, 7, false, true, true);
}


void lcdSetup(void)
{
  /* Init LCD with no voltage boost */
  SegmentLCD_Init(false);

  LCD_FrameCountInit_TypeDef frameInit;
  LCD_AnimInit_TypeDef animInit;


  SegmentLCD_Symbol(LCD_SYMBOL_COL10, 1);
 // SegmentLCD_Symbol(LCD_SYMBOL_COL5, 1);


  /* Setup frame counter */
  frameInit.enable   = true;           /* Enable framecounter */
  frameInit.top      = 15;             /* Generate event every 15 frames. */
  frameInit.prescale = lcdFCPrescDiv1; /* No prescaling */

  LCD_FrameCountInit(&frameInit);

  /* Animate half ring - by special board design it is possible to achieve */
  /* "slide in/slide out" effect                                           */
  animInit.enable    = true;             /* Enable animation after initialization. */
  animInit.AReg      = 0x00;             /* Initial A register value */
  animInit.BReg      = 0x0F;             /* Initial B register value */
  animInit.AShift    = lcdAnimShiftLeft; /* Shift A register left */
  animInit.BShift    = lcdAnimShiftLeft; /* Shift B register left */
  animInit.animLogic = lcdAnimLogicOr;   /* Enable segment if A or B */
  animInit.startSeg  = 8;                /* Initial animation segment */

  LCD_AnimInit(&animInit);

}

void rtcSetup(void)
{
  RTC_Init_TypeDef rtcInit = RTC_INIT_DEFAULT;


  /* Set a clock divisor of 32 to reduce power conumption. */
  CMU_ClockDivSet(cmuClock_RTC, cmuClkDiv_32);

  /* Enable RTC clock */
  CMU_ClockEnable(cmuClock_RTC, true);

  /* Initialize RTC */
  rtcInit.enable   = false;  /* Do not start RTC after initialization is complete. */
  rtcInit.debugRun = false;  /* Halt RTC when debugging. */
  rtcInit.comp0Top = true;   /* Wrap around on COMP0 match. */
  RTC_Init(&rtcInit);

  /* Interrupt every second */
  RTC_CompareSet(0, ((RTC_FREQ / RTC_DIV)  - 1));

  /* Enable interrupt */
  NVIC_EnableIRQ(RTC_IRQn);
  RTC_IntEnable(RTC_IEN_COMP0);

}


void RTC_IRQHandler(void)
{
  /* Clear interrupt source */
  /* Clear interrupt source */
  RTC_IntClear(RTC_IFC_COMP0);

  /* Increase time by one second */
  if (seconds > 0) {
      seconds--;
  }
  if (seconds == 0 && minutes > 0) {
      seconds = 59;
      minutes--;
  }
  if (seconds == 0 && minutes == 0 ) {
      GPIO_PinOutSet(gpioPortC, 2);

      RTC_Enable(false); //stop rtc

  }
}


void GPIO_EVEN_IRQHandler(void)
{
  volatile uint32_t flags=GPIO_IntGet();
  GPIO_IntClear(flags);
  seconds++;

  if(seconds>59)
    seconds=0;
}

void GPIO_ODD_IRQHandler(void)
{
  volatile uint32_t flags=GPIO_IntGet();

  if(flags==512) //PB9 interrupt flag
    {
      minutes++;
      if(minutes>59)
        minutes=0;
    }
  if(flags==128) //PC7 interrupt flag
    {
      RTC_Enable(true); //start rtc

    }
  GPIO_IntClear(flags); //clear flags
}



