/*
 * config.h
 *
 *  Created on: 14 Nov 2024
 *      Author: Step
 */
#include <stdint.h>
#include <stdbool.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_rtc.h"
#include "em_lcd.h"
#include "segmentlcd.h"
#include "bsp_trace.h"
#ifndef SRC_CONFIG_H_
#define SRC_CONFIG_H_



void gpioConfig(void);

void lcdSetup(void);

void rtcSetup(void);

#endif /* SRC_CONFIG_H_ */
