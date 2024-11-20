
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

#define RTC_FREQ    32768

/* Initial setup to 12:00:00 */
uint32_t hours   = 12;
uint32_t minutes = 0;
uint32_t seconds=0;

/* This flag enables/disables vboost on the LCD */
bool oldBoost = false;
void RTC_IRQHandler(void)
{
  /* Clear interrupt source */
  RTC_IntClear(RTC_IFC_COMP0);

  /* Increase time by one second */
  seconds++;
  if(seconds>59)
    {
      seconds=0;
      minutes++;
      if (minutes > 59) {
        minutes = 0;
        hours++;
        if (hours > 23) {
          hours = 0;
        }
      }
    }
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

  /* Interrupt every minute */
  RTC_CompareSet(0, ((RTC_FREQ / 32)  - 1));

  /* Enable interrupt */
  NVIC_EnableIRQ(RTC_IRQn);
  RTC_IntEnable(RTC_IEN_COMP0);

  /* Start Counter */
  RTC_Enable(true);
}




void lcdSetUp(void)
{
  LCD_FrameCountInit_TypeDef frameInit;
  LCD_AnimInit_TypeDef animInit;

  /* Write Gecko and display, and light up the colon between hours and minutes. */

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

int main(void)
{
  /* Chip errata */
  CHIP_Init();

  /* Init LCD with no voltage boost */
  SegmentLCD_Init(oldBoost);
  /* Setup RTC to generate an interrupt every second */
  rtcSetup();
  lcdSetUp();

  while (1) {
   SegmentLCD_LowerNumber(seconds);
   SegmentLCD_Number(hours*100+minutes);
  }

  return 0;
}
