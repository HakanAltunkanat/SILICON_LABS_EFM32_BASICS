#include "em_device.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_timer.h"
#include "bsp.h"
#include "em_lcd.h"
#include "segmentlcd.h"
#include "config.h"



int main(void)
{
  // Chip errata
  CHIP_Init();

  // Initializations

  HFRCO_Enable(0x00000000);
  gpioInit();

  SegmentLCD_Init(false);
  SegmentLCD_LowerNumber(CMU_ClockFreqGet(cmuClock_HF)/1000);
  SegmentLCD_Number(1);

  while (1) {
   calculatePerfectNumbers(); //to keep the cpu busy
  }
}

