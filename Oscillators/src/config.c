#include "em_device.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "bsp.h"
#include "em_lcd.h"
#include "segmentlcd.h"
#include "config.h"
#include <stdio.h>



CMU_HFRCOBand_TypeDef HFRC_Band=0x00000000;

int calculatePerfectNumbers(void) //perfect number calculation
{
  volatile int sum=0;
  for(int i=1; i<=10000; i++)
    {
      for(int j=1; j<i; j++)
        {
          if(i%j == 0)
            sum+=j;
        }
      if(sum==i)
        return i;
      sum=0;
    }
  return 0;
}

void gpioInit(void) //gpio settings
{
  CMU_ClockEnable(cmuClock_GPIO, true);
  GPIO_PinModeSet(gpioPortB, 9, gpioModeInputPullFilter, 1); //push button 0
  NVIC_EnableIRQ(GPIO_ODD_IRQn);
  GPIO_ExtIntConfig(gpioPortB, 9, 9, false, true, true);

}
//interrupts

void GPIO_ODD_IRQHandler(void)
{
  int clkFreq=0;
  uint32_t flags=GPIO_IntGet();
  static int count=0;
  GPIO_IntClear(flags);
  count++;
  if(count>8)
    {
      count=0;
    }

  if(count<=5)
    {
      HFRC_Band++;
      if(HFRC_Band>5)
        HFRC_Band=0;
      HFRCO_Enable(HFRC_Band);
      if(count==0)
        CMU_OscillatorEnable(cmuOsc_LFXO, false, true);
      SegmentLCD_Number(1);
    }
  else
    {
      switch (count)
      {
        case 6:
          LFRCO_Enable();
          CMU_OscillatorEnable(cmuOsc_HFRCO, false, true);
          SegmentLCD_Number(2);
        break;
        case 7:
          HFXO_Enable();
          //CMU_OscillatorEnable(cmuOsc_LFRCO, false, true);
          SegmentLCD_Number(3);
        break;
        case 8:
          LFXO_Enable();
          CMU_OscillatorEnable(cmuOsc_HFXO, false, true);

          SegmentLCD_Number(4);

        break;
        default:
        break;
      }
    }
  clkFreq=CMU_ClockFreqGet(cmuClock_HF)/1000;
  SegmentLCD_LowerNumber(clkFreq);

}

void HFRCO_Enable(CMU_HFRCOBand_TypeDef band)
{
  CMU_HFRCOBandSet(band); //adjust frequency for RC Oscillator
  CMU_OscillatorEnable(cmuOsc_HFRCO, true, true); //enables High Frequency RC Oscillator
  CMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFRCO); // Select the reference oscillator used for a HF branch
  CMU_ClockDivSet(cmuClock_HF, cmuClkDiv_1); //HFclk div value
  CMU_ClockDivSet(cmuClock_HFPER, cmuClkDiv_1); //HFPERCLK div value

}
void LFRCO_Enable(void)
{

  CMU_OscillatorEnable(cmuOsc_LFRCO, true, true); //enables Low Frequency RC Oscillator
  CMU_ClockSelectSet(cmuClock_HF, cmuSelect_LFRCO); // Select the reference oscillator used for a HF branch
  CMU_ClockDivSet(cmuClock_HF, cmuClkDiv_1); //HFclk div value
  CMU_ClockDivSet(cmuClock_HFPER, cmuClkDiv_1); //HFPERCLK div value
}
void HFXO_Enable(void)
{

  CMU_OscillatorEnable(cmuOsc_HFXO, true, true);
  CMU_ClockSelectSet(cmuClock_HF,cmuSelect_HFXO);
  CMU_ClockDivSet(cmuClock_HF, cmuClkDiv_1);
  CMU_ClockDivSet(cmuClock_HFPER, cmuClkDiv_1);
}
void LFXO_Enable(void)
{
  CMU_OscillatorEnable(cmuOsc_LFXO, true, true);
  CMU_ClockSelectSet(cmuClock_HF,cmuSelect_LFXO);
  CMU_ClockDivSet(cmuClock_HF, cmuClkDiv_1);
  CMU_ClockDivSet(cmuClock_HFPER, cmuClkDiv_1);
}

