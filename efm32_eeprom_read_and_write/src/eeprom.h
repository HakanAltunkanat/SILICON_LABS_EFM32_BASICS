#include <stdio.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_i2c.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "bsp.h"
#ifndef SRC_EEPROM_H_
#define SRC_EEPROM_H_

void eepromByteWrite(uint8_t eepromAddress, uint8_t dataAddress, uint8_t byteData);
void eepromPageWrite(uint8_t eepromAddress, uint8_t pageAddress, uint8_t *doubleWordData);
uint8_t eepromCurrentAddressRead(uint8_t eepromAddress);
uint8_t eepromRandomAddressRead(uint8_t eepromAddress, uint8_t dataAddress);
void eepromSequentialRead(uint8_t eepromAddress, uint8_t pageAddress, uint8_t* seqRead);
void eepromInit(void);
#endif
