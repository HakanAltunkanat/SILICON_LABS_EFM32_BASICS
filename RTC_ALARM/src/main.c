
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



extern uint32_t minutes;
extern uint32_t seconds;

int main(void)
{
  /* Chip errata */
  CHIP_Init();

  lcdSetup(); //lcd settings
  gpioConfig(); //gpio settings
  rtcSetup(); //rtc settings

  while (1) {
   //SegmentLCD_LowerNumber(seconds);
   SegmentLCD_Number(100*minutes+seconds);
  }

  return 0;
}
