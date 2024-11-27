#include <stdio.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_i2c.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "bsp.h"


#define I2C_ADDRESS                     0xE2
#define I2C_RXBUFFER_SIZE                 5


uint8_t i2c_rxBuffer[I2C_RXBUFFER_SIZE];
uint8_t i2c_rxBufferIndex=0;


int i=0,j=0;
/***********************1***************************************************//**
 * @brief  Starting oscillators and enabling clocks
 *****************************************************************************/


/**************************************************************************//**
 * @brief GPIO initialization
 *****************************************************************************/
void initGPIO(void)
{
  CMU_ClockEnable(cmuClock_GPIO, true);
  // Configure  LED1 as output
  GPIO_PinModeSet(BSP_GPIO_LED1_PORT, BSP_GPIO_LED1_PIN, gpioModePushPull, 1);
}



void initI2C(void)
{
  CMU_ClockEnable(cmuClock_I2C0, true);
  // Using default settings
  I2C_Init_TypeDef i2cInit = I2C_INIT_DEFAULT;
  i2cInit.master=false; //slave mode


  // Using PD6 (SDA) and PD7 (SCL)
  GPIO_PinModeSet(gpioPortD, 6, gpioModeWiredAndPullUpFilter, 1);
  GPIO_PinModeSet(gpioPortD, 7, gpioModeWiredAndPullUpFilter, 1);

  // Enable pins at location 1 as specified in datasheet
  I2C0->ROUTE = I2C_ROUTE_SDAPEN | I2C_ROUTE_SCLPEN;
  I2C0->ROUTE = (I2C0->ROUTE & (~_I2C_ROUTE_LOCATION_MASK)) | I2C_ROUTE_LOCATION_LOC1;

  // Initializing the I2C
  I2C_Init(I2C0, &i2cInit);

  i2c_rxBufferIndex = 0;

  // Setting up to enable slave mode
  I2C0->SADDR = (I2C_ADDRESS);
  I2C0->CTRL |= I2C_CTRL_SLAVE | I2C_CTRL_AUTOACK | I2C_CTRL_AUTOSN;

}

volatile bool dummyRead = true; // dummy read for the first byte in rxdata

void i2cReceive(void)
{
    if (I2C0->STATUS & I2C_STATUS_RXDATAV) //I2C_STATUS_RXDATAV flag in I2Cn_STATUS register is set when a new byte is taken
    {
        if (dummyRead)
        {
            // read the first byte
            I2C0->RXDATA;
            dummyRead = false; // dummy read is only for the first byte
        }
        else
        {
            // taking data from RXDATA register
            i2c_rxBuffer[i2c_rxBufferIndex++] = I2C0->RXDATA;

        }
    }
    if (I2C0->IF & I2C_IF_SSTOP) //when master sends a stop  then I2C_IF_SSTOP in I2Cn_IF is set
    {
        I2C0->IFC = I2C_IFC_SSTOP; // clear the interrupt flag
        i2c_rxBufferIndex = 0; //reset buffer index
        dummyRead = true; // dummy read for the new data
        GPIO_PinOutToggle(BSP_GPIO_LED1_PORT, BSP_GPIO_LED1_PIN); //toggle led to indicate data receive

    }
}



int main(void)
{
  // Chip errata
  CHIP_Init();


  // Initializations
  initGPIO();

  // Setting up i2c
  initI2C();

  while (1)
  {
      i2cReceive();

  }
}
