#include <stdio.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_i2c.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "bsp.h"

#define I2C_SLAVE_ADDRESS  0xE2  // Slave address
#define I2C_TX_BUFFER_SIZE 5     // transmission buffer size
int i=0;
int j=0;


I2C_TransferReturn_TypeDef result; // return code for transmission

void initGPIO(void)
{

  CMU_ClockEnable(cmuClock_GPIO, true);
  // Configure  PB1 as input and int

  GPIO_PinModeSet(BSP_GPIO_PB1_PORT, BSP_GPIO_PB1_PIN, gpioModeInputPull, 1);

  GPIO_ExtIntConfig(BSP_GPIO_PB1_PORT, BSP_GPIO_PB1_PIN, BSP_GPIO_PB1_PIN, false, true, true);

  // Configure LED1 as output

  GPIO_PinModeSet(BSP_GPIO_LED1_PORT, BSP_GPIO_LED1_PIN, gpioModePushPull, 1);

  NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
  NVIC_EnableIRQ(GPIO_EVEN_IRQn);

}


void initI2C_Master(void) {

  CMU_ClockEnable(cmuClock_I2C0, true);
  //i2c STRUCT
   I2C_Init_TypeDef i2cInit = I2C_INIT_DEFAULT;
   I2C_Init(I2C0, &i2cInit); //applying i2c settings
   //


   //PD6 and PD7 is configured for i2c
   GPIO_PinModeSet(gpioPortD, 6, gpioModeWiredAndPullUpFilter, 1);
   GPIO_PinModeSet(gpioPortD, 7, gpioModeWiredAndPullUpFilter, 1);

   // Routing i2c to PD6(sda) and PD7(scl)
   I2C0->ROUTE = I2C_ROUTE_SDAPEN | I2C_ROUTE_SCLPEN;
   I2C0->ROUTE = (I2C0->ROUTE & (~_I2C_ROUTE_LOCATION_MASK)) | I2C_ROUTE_LOCATION_LOC1;

   // i2c is enabled
   I2C_Enable(I2C0, true);
}

void sendDataToSlave(void) {
  //data to be transmitted
   uint8_t txData[I2C_TX_BUFFER_SIZE] = {0xA5, 0x5A, 0x01, 0x02, 0x03};

   // I2C transfer struct
   I2C_TransferSeq_TypeDef seq;

   //slave address
   seq.addr = (I2C_SLAVE_ADDRESS << 1);
   //write mode
   seq.flags = I2C_FLAG_WRITE;
   //buf[0] for transmitted data
   seq.buf[0].data = txData;
   seq.buf[0].len = I2C_TX_BUFFER_SIZE;


    result=I2C_TransferInit(I2C0, &seq); //applying transmission settings

   // wait till the transmission is done
   while (result == i2cTransferInProgress) {
       result = I2C_Transfer(I2C0); //sends data
   }
}


void GPIO_EVEN_IRQHandler(void)
{
	// Clear pending
	  uint32_t flags = GPIO_IntGet();
	  GPIO_IntClear(flags);
	  GPIO_PinOutToggle(BSP_GPIO_LED1_PORT, BSP_GPIO_LED1_PIN); //toggle led to indicate transmission
	  sendDataToSlave(); //sends data from master to slave

}


int main(void)
{
  // Chip errata
   CHIP_Init();
  
  // Initializations
  initGPIO();
  initI2C_Master();

  while (1)
  {

  }
}
