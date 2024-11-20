

#ifndef SRC_CONFIG_H_
#define SRC_CONFIG_H_

#include "em_device.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_chip.h"
#include "em_gpio.h"
#include "bsp.h"
#include "em_lcd.h"
#include "segmentlcd.h"

int calculatePerfectNumbers(void);
void gpioInit(void);
void HFRCO_Enable(CMU_HFRCOBand_TypeDef band);
void LFRCO_Enable(void);
void HFXO_Enable(void);
void LFXO_Enable(void);
#endif /* SRC_CONFIG_H_ */
