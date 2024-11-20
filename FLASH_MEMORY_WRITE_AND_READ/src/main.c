#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_msc.h"
#include "em_gpio.h"


#define USERDATA ((uint32_t*)USERDATA_BASE) //it is address of first memory block (0FE00000)

int buttonCounter=0; //data from user
uint32_t savedValue; //value that is written on flash

//gpio configs
//PB1 increments buttonCounter
//PB0 save the value of buttonCounter to the flash memeory
void gpioConfig(void)
{
  CMU_ClockEnable(cmuClock_GPIO, true);
  GPIO_PinModeSet(gpioPortB, 10, gpioModeInputPullFilter, 1);
  GPIO_PinModeSet(gpioPortB, 9, gpioModeInputPullFilter, 1);
  NVIC_EnableIRQ(GPIO_EVEN_IRQn);
  NVIC_EnableIRQ(GPIO_ODD_IRQn);
  GPIO_ExtIntConfig(gpioPortB, 10, 10, false, true, true);
  GPIO_ExtIntConfig(gpioPortB, 9, 9, false, true, true);

}

void GPIO_EVEN_IRQHandler(void)
{
  uint32_t flags=GPIO_IntGet(); //gets interrupt flag
  GPIO_IntClear(flags); //clear interrupt flag
  buttonCounter++;
}

void GPIO_ODD_IRQHandler(void)
{
  uint32_t flags=GPIO_IntGet();
  GPIO_IntClear(flags);
  MSC_ErasePage(USERDATA); //erase flash memeory content
  MSC_Init(); //initializes the flash memory
  MSC_WriteWord((USERDATA ), &buttonCounter, 4); //writes 32bit(1 word) data to the given address
  MSC_Deinit(); //disables flash write property
}

int main(void) 
{
  // Chip errata
  CHIP_Init();

  gpioConfig();
  MSC_Init();
  savedValue=USERDATA[0]; //previous data that is written on flash memeory

  // Infinite Loop
  while(1);
}
