#include <stdio.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_i2c.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "bsp.h"


#define slaveAddress 0xE2 //address of the slave device
#define txBufferLength 10 //rx and tx buffer lengths
#define rxBufferLength 10

uint8_t txBuffer[]={85,96,74,13,21,89,32,96,15,46}; //data that will be transmited to the slave
uint8_t rxBuffer[rxBufferLength]; //receive buffer

void i2cInit(void)
{
  CMU_ClockEnable(cmuClock_I2C0, true); //activates i2c0 clock
  I2C_Init_TypeDef initI2C= I2C_INIT_DEFAULT;
  I2C_Init(I2C0, &initI2C); //applies i2c settings

  //gpio settings
  GPIO_PinModeSet(gpioPortD, 6, gpioModeWiredAndDrivePullUpFilter, 1);
  GPIO_PinModeSet(gpioPortD, 7, gpioModeWiredAndDrivePullUpFilter, 1);

  //PD6 (SDA) and PD7(SCL) are routted to i2c0
  I2C0->ROUTE=I2C_ROUTE_SDAPEN | I2C_ROUTE_SCLPEN;
  I2C0->ROUTE=(I2C0->ROUTE & (~_I2C_ROUTE_LOCATION_MASK)) | I2C_ROUTE_LOCATION_LOC1;


}

void gpioInit(void)
{
  //gpio clcok enable
  CMU_ClockEnable(cmuClock_GPIO, true);
  //push buttons
  GPIO_PinModeSet(gpioPortB, 9, gpioModeInputPullFilter, 1);
  GPIO_PinModeSet(gpioPortB, 10, gpioModeInputPullFilter, 1);

  //push button interrupts
  GPIO_ExtIntConfig(gpioPortB, 9, 9, false, true, true);
  GPIO_ExtIntConfig(gpioPortB, 10, 10, false, true, true);
  NVIC_EnableIRQ(GPIO_EVEN_IRQn);
  NVIC_EnableIRQ(GPIO_ODD_IRQn);

  //LED0 and LED1
  GPIO_PinModeSet(gpioPortE, 2, gpioModePushPull, 1);
  GPIO_PinModeSet(gpioPortE, 3, gpioModePushPull, 1);

}


//sends data to the slave
void i2cSendData(void)
{
  //transfer struct
  I2C_TransferSeq_TypeDef i2cTransfer;
  I2C_TransferReturn_TypeDef result; //transferReturn struct to achieve return code to check whether the tranfer is completed

  i2cTransfer.addr=slaveAddress; //slave address
  i2cTransfer.flags=I2C_FLAG_WRITE; //send data to the slave
  i2cTransfer.buf[0].data=txBuffer; //tx buffer
  i2cTransfer.buf[0].len=txBufferLength;//tx buffer length

  result=I2C_TransferInit(I2C0,&i2cTransfer); //applyng transfer settings

  while(result==i2cTransferInProgress) //wait till the transfer is completed
    {
      result=I2C_Transfer(I2C0); //send data to the slave
    }

}

void i2cReceiveData(void)
{
  I2C_TransferSeq_TypeDef i2cTransfer; //i2c transfer struct
  I2C_TransferReturn_TypeDef result; //transferReturn struct to achieve return code to check whether the tranfer is completed

  i2cTransfer.addr=slaveAddress; //slave address
  i2cTransfer.flags=I2C_FLAG_READ;//read from the slave
  i2cTransfer.buf[0].data=rxBuffer;//receive buffer
  i2cTransfer.buf[0].len=rxBufferLength; //rx buffer length

  result=I2C_TransferInit(I2C0, &i2cTransfer); //applyng transfer settings
  while(result==i2cTransferInProgress) //wait while the adress is sent
    {
      result=I2C_Transfer(I2C0); //sends address to the slave and receives data

    }
}


//push button interrupts
void GPIO_EVEN_IRQHandler(void) //receive data from the slave
{
  uint32_t flags=GPIO_IntGet();
  GPIO_IntClear(flags); //clear interrupt flags
  i2cReceiveData();
  GPIO_PinOutToggle(gpioPortE,2); //toggles led to indicate communication
}

void GPIO_ODD_IRQHandler(void) //send data to the slave
{
  uint32_t flags=GPIO_IntGet();
  GPIO_IntClear(flags); //clear interrupt flags
  i2cSendData();
  GPIO_PinOutToggle(gpioPortE,3); //toggles led to indicate communication
}

//receive data from the slave

int main(void)
{
  // Chip errata

  CHIP_Init();
  gpioInit();
  i2cInit();

  while (1)
  {

  }
}


