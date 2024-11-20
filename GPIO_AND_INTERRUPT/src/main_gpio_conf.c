
#include "em_device.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "em_chip.h"
#include "bspconfig.h"


void gpioConfig()
{
  CMU_ClockEnable(cmuClock_GPIO, true); //activates gpio clock
  GPIO_PinModeSet(gpioPortE, 2, gpioModePushPull, 0); //gpio settings
  GPIO_PinModeSet(gpioPortE, 3, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortB, 9, gpioModeInputPullFilter, 1);
  GPIO_PinModeSet(gpioPortB, 10, gpioModeInputPullFilter, 1);

  // interrupt settings

  NVIC_EnableIRQ(GPIO_EVEN_IRQn);
  NVIC_EnableIRQ(GPIO_ODD_IRQn);

  GPIO_ExtIntConfig(gpioPortB, 9, 9, false, true, true);
  GPIO_ExtIntConfig(gpioPortB, 10, 10, false, true, true);

}
void GPIO_EVEN_IRQHandler(void)
{
  volatile uint32_t flags = GPIO_IntGet();
  GPIO_IntClear(flags); //clear flags
  GPIO_PinOutToggle(gpioPortE, 2);

}

void GPIO_ODD_IRQHandler(void)
{
  volatile uint32_t flags = GPIO_IntGet();
  GPIO_IntClear(flags); //clear flags
  GPIO_PinOutToggle(gpioPortE, 3);

}
int main(void)
{
  /* Initialize chip */
  CHIP_Init();
  gpioConfig();
  while (1)
  {

  }
}
