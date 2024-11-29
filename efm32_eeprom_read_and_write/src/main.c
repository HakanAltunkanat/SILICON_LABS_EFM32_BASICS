#include <stdio.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_i2c.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "bsp.h"
#include "eeprom.h"

#define slaveAddress 0xA0 //address of the eeprom
#define txBufferLength 8 //rx and tx buffer lengths
#define rxBufferLength 8

uint8_t txBuffer[txBufferLength]={0x02,0x03,0x05,0x7,0x0B,0x0D,0x11,0x13}; //data that will be transmited to eeprom
uint8_t rxBuffer[rxBufferLength]; //receive buffer
uint8_t byte=0,byte1=0; //variables to test one byte read and write functions of eeprom

void gpioInit(void)
{
  //gpio clcok enable
  CMU_ClockEnable(cmuClock_GPIO, true);
  //push buttons
  GPIO_PinModeSet(gpioPortB, 9, gpioModeInputPullFilter, 1); //push button 0 to write data to the eeprom
  GPIO_PinModeSet(gpioPortB, 10, gpioModeInputPullFilter, 1); //push button 1 to read data from the eeprom

  //push button interrupts
  GPIO_ExtIntConfig(gpioPortB, 9, 9, false, true, true);
  GPIO_ExtIntConfig(gpioPortB, 10, 10, false, true, true);
  NVIC_EnableIRQ(GPIO_EVEN_IRQn);
  NVIC_EnableIRQ(GPIO_ODD_IRQn);

  //LED0 and LED1
  GPIO_PinModeSet(gpioPortE, 2, gpioModePushPull, 1);
  GPIO_PinModeSet(gpioPortE, 3, gpioModePushPull, 1);

}

//push button interrupts
void GPIO_EVEN_IRQHandler(void) //receive data from the eeprom
{
  uint32_t flags=GPIO_IntGet();
  GPIO_IntClear(flags); //clear interrupt flags
  eepromSequentialRead(slaveAddress, 28, rxBuffer); //sequential reading
  GPIO_PinOutToggle(gpioPortE,2); //toggles led to indicate communication
}


void GPIO_ODD_IRQHandler(void) //send data to the eeprom
{
  uint32_t flags=GPIO_IntGet();
  GPIO_IntClear(flags); //clear interrupt flags
  eepromPageWrite(slaveAddress, 28, txBuffer); //page write

  GPIO_PinOutToggle(gpioPortE,3); //toggles led to indicate communication
}


int main(void)
{
  // Chip errata

  CHIP_Init();
  gpioInit(); //gpio settings
  eepromInit(); //i2c settings to communicate with eeprom
  eepromByteWrite(slaveAddress, 0x12, 0x87); //one byte write to the desired adress
  for(int i=0; i<10000;i++); //delay
  eepromByteWrite(slaveAddress, 0x13, 0x45);  //one byte write to the desired adress
  for(int i=0; i<10000;i++); //delay
  byte=eepromRandomAddressRead(slaveAddress, 0x12); //one byte reading from the desired address
  for(int i=0; i<10000;i++); //delay
  byte1=eepromCurrentAddressRead(slaveAddress); //reading from the current address
  while (1)
  {

  }
}


