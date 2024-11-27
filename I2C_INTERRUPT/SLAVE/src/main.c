#include <stdio.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_i2c.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "bsp.h"

#define rxBufferLength 10 //rx buffer length
#define txBufferLength 10 //tx buffer length
#define i2cAdress 0xE2 //slave device's adress

uint8_t rxBuffer[rxBufferLength]; //rx buffer
uint8_t txBuffer[txBufferLength]={12,23,34,45,56,67,78,89,90,31}; //txBuffer
uint8_t rxBufferIndex=0,txBufferIndex=0; //rxBuffer and txBuffer indexes
uint8_t firstByte=0; //it holds the addr+(r/w) data from the slave
void i2cConfig(void)
{
  CMU_ClockEnable(cmuClock_I2C0, true);
  I2C_Init_TypeDef i2cInit=I2C_INIT_DEFAULT;
  i2cInit.master=false; //slave mode

  I2C_Init(I2C0, &i2cInit); //applying i2c settings

  //gpio settings
  GPIO_PinModeSet(gpioPortD, 6, gpioModeWiredAndPullUpFilter, 1);
  GPIO_PinModeSet(gpioPortD, 7, gpioModeWiredAndPullUpFilter, 1);

  //PD6 (SDA) and PD7(SCL) are routted to i2c0
  I2C0->ROUTE=I2C_ROUTE_SDAPEN | I2C_ROUTE_SCLPEN;
  I2C0->ROUTE = (I2C0->ROUTE & (~_I2C_ROUTE_LOCATION_MASK)) | I2C_ROUTE_LOCATION_LOC1;

  // Setting up to enable slave mode
  I2C0->SADDR = (i2cAdress); //adress of the slave
  I2C0->CTRL |= I2C_CTRL_SLAVE | I2C_CTRL_AUTOACK | I2C_CTRL_AUTOSN; //slave mode, auto acknowledgement, automatic stop on nack flags are set

  //i2c interrupt settings
  I2C_IntEnable(I2C0, I2C_IEN_ADDR | I2C_IEN_RXDATAV | I2C_IEN_SSTOP | I2C_IEN_TXC);
  NVIC_EnableIRQ(I2C0_IRQn);
  I2C_IntClear(I2C0, I2C_IFC_ADDR | I2C_IFC_SSTOP | I2C_IFC_TXC);
  /*
   *  I2C_IEN_ADDR => address interrupt enable
   *  I2C_IEN_RXDATAV => receive data valid interrupt enable
   *  I2C_IEN_SSTOP => sstop interrupt enable
   */
}

void gpioConfig(void)
{
  //gpio clock enable
  CMU_ClockEnable(cmuClock_GPIO, true);

  //push button 0  gpio setings
  GPIO_PinModeSet(gpioPortC, 8, gpioModeInputPullFilter, 1);
  GPIO_PinModeSet(gpioPortC, 9, gpioModeInputPullFilter, 1);
  //push button interrupt settings
  GPIO_ExtIntConfig(gpioPortC, 8, 8, false,true, true);
  NVIC_EnableIRQ(GPIO_EVEN_IRQn);
  //led0 and led1
  GPIO_PinModeSet(gpioPortC, 10, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortC, 11 , gpioModePushPull, 1);


}

void I2C0_IRQHandler(void)
{
  uint32_t status=I2C0->IF; //interrupt flag register

  if(status & I2C_IF_ADDR) //interrupt happens when the addres sent from the master device is accepted
    {
      firstByte=I2C0->RXDATA;
      if(firstByte & 0x01) //master reads from the slave
        {
          I2C0->TXDATA=txBuffer[txBufferIndex]; //data is sent to the slave
          txBufferIndex++;
        }
      I2C_IntClear(I2C0, I2C_IFC_ADDR);
    }

  else if(status & I2C_IF_RXDATAV) //interrupt happens when the receive buffer has data in it and it is cleared automaticly when the receive buffer is empty
    {
      rxBuffer[rxBufferIndex++]=I2C0->RXDATA; //takes the data from the receive register
    }
  if(status & I2C_IF_SSTOP) //interrupt happens when the stop condition from the master device is received
    {
      rxBufferIndex=0;
      I2C_IntClear(I2C0, I2C_IFC_SSTOP); //clear flag
      if(!(firstByte & 0x01))
        GPIO_PinOutToggle(gpioPortC, 10); //toggle the led to indicate the transfer is completed

    }
  if(status & I2C_IF_TXC) //Set when the transmit shift register becomes empty and there is no more data in the transmit buffer. (transfer completed interrupt flag
    {

      if(txBufferIndex<10)
        {
          I2C0->TXDATA=txBuffer[txBufferIndex++];
          I2C_IntClear(I2C0, I2C_IFC_TXC);

        }
      else{
          I2C_IntClear(I2C0, I2C_IFC_TXC);
          txBufferIndex=0;
          GPIO_PinOutToggle(gpioPortC, 11); //toggle the led1 to indicate transfer is completed

      }
    }
}

int main(void)
{
  // Chip errata
  CHIP_Init();
  gpioConfig();//gpio configuration
  i2cConfig(); //i2c0 configuration

  while (1)
  {

  }
}
