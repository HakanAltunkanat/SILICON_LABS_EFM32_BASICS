#include "em_device.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "em_timer.h"
#include "bsp.h"
#include "delayMs.h"

void initGpio(void)
{
  // activate gpio clock
  CMU_ClockEnable(cmuClock_GPIO, true);

  // pins are configurated as outputs
  GPIO_PinModeSet(gpioPortC, 7, gpioModePushPull, 1);
}




int main(void)
{
  // Chip errata
  CHIP_Init();

  // Initializations
  initGpio();


  while (1) {
   GPIO_PinOutToggle(gpioPortC, 7);
   delayMs(1000);
  }
}

