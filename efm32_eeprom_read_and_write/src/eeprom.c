#include <stdio.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_i2c.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "bsp.h"
#include "eeprom.h"

void eepromInit(void) //i2c setting to communicate with eeprom
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

void eepromByteWrite(uint8_t eepromAddress, uint8_t dataAddress, uint8_t byteData) //writes one byte to the eeprom
{


  I2C_TransferReturn_TypeDef result; //i2c structs for communication with eeprom
  I2C_TransferSeq_TypeDef i2cTransfer;

  i2cTransfer.addr=eepromAddress;
  i2cTransfer.flags=I2C_FLAG_WRITE_WRITE; //microcontroller transmit data addres then 1 byte data to the eeprom
  i2cTransfer.buf[0].len=1;
  i2cTransfer.buf[0].data=&dataAddress;
  i2cTransfer.buf[1].len=1;
  i2cTransfer.buf[1].data=&byteData;

  result=I2C_TransferInit(I2C0, &i2cTransfer); //applying i2c transfer settings

  while(result==i2cTransferInProgress) //wait till the transfer is completed
    {
      result=I2C_Transfer(I2C0);
    }
}

void eepromPageWrite(uint8_t eepromAddress, uint8_t pageAddress, uint8_t *doubleWordData) //writes double word (8 bytes) to the eeprom
{
  I2C_TransferReturn_TypeDef result; //i2c structs for communication with eeprom
  I2C_TransferSeq_TypeDef i2cTransfer;
  pageAddress=(pageAddress<<3);
  i2cTransfer.addr=eepromAddress;
  i2cTransfer.flags=I2C_FLAG_WRITE_WRITE; //microcontroller transmit data addres then 8 byte data to the eeprom
  i2cTransfer.buf[0].len=1;
  i2cTransfer.buf[0].data=&pageAddress;
  i2cTransfer.buf[1].len=8;
  i2cTransfer.buf[1].data=doubleWordData;

  result=I2C_TransferInit(I2C0, &i2cTransfer); //applying i2c transfer settings

  while(result==i2cTransferInProgress)
    {
      result=I2C_Transfer(I2C0);//wait till the transfer is completed
    }
}

uint8_t eepromCurrentAddressRead(uint8_t eepromAddress)
{
  I2C_TransferReturn_TypeDef result; //i2c structs for communication with eeprom
  I2C_TransferSeq_TypeDef i2cTransfer;

  uint8_t byte[1]={0};

  i2cTransfer.addr=eepromAddress; //reads one byte from the current addres
  i2cTransfer.flags=I2C_FLAG_READ;
  i2cTransfer.buf[0].len=1;
  i2cTransfer.buf[0].data=byte;

  result=I2C_TransferInit(I2C0, &i2cTransfer);

  while(result==i2cTransferInProgress)
    {
      result=I2C_Transfer(I2C0);
    }
  return byte[0];
}

uint8_t eepromRandomAddressRead(uint8_t eepromAddress, uint8_t dataAddress)
{
  I2C_TransferSeq_TypeDef i2cTransfer; //i2c transfer struct
  I2C_TransferReturn_TypeDef result;

  uint8_t byte[1]={0};

  i2cTransfer.addr=eepromAddress; //reads one byte from the desired addres
  i2cTransfer.flags=I2C_FLAG_WRITE;
  i2cTransfer.buf[0].data=&dataAddress;
  i2cTransfer.buf[0].len=1;

  result=I2C_TransferInit(I2C0, &i2cTransfer);
  while(result==i2cTransferInProgress)
    {
      result=I2C_Transfer(I2C0);

    }

  i2cTransfer.addr=eepromAddress;

  i2cTransfer.flags=I2C_FLAG_READ;
  i2cTransfer.buf[0].data=byte;
  i2cTransfer.buf[0].len=1;
  result=I2C_TransferInit(I2C0, &i2cTransfer);
  while(result==i2cTransferInProgress)
    {
      result=I2C_Transfer(I2C0);
    }

  return byte[0];
}

void eepromSequentialRead(uint8_t eepromAddress, uint8_t pageAddress, uint8_t* seqRead)
{
  I2C_TransferSeq_TypeDef i2cTransfer; //i2c transfer struct
  I2C_TransferReturn_TypeDef result;

  pageAddress=(pageAddress<<3); //reads from the eeprom in a sequential order
  i2cTransfer.addr=eepromAddress;
  i2cTransfer.flags=I2C_FLAG_WRITE;
  i2cTransfer.buf[0].data=&pageAddress;
  i2cTransfer.buf[0].len=1;

  result=I2C_TransferInit(I2C0, &i2cTransfer);
  while(result==i2cTransferInProgress)
    {
      result=I2C_Transfer(I2C0);

    }

  i2cTransfer.addr=eepromAddress;

  i2cTransfer.flags=I2C_FLAG_READ;
  i2cTransfer.buf[0].data=seqRead;
  i2cTransfer.buf[0].len=8;
  result=I2C_TransferInit(I2C0, &i2cTransfer);
  while(result==i2cTransferInProgress)
    {
      result=I2C_Transfer(I2C0);
    }


}


