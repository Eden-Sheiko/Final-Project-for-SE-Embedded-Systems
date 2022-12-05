#ifndef INC_ADC_H_
#define INC_ADC_H_

// includes
#include "main.h"
#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <stdlib.h>

// ADC HANDLES:
extern ADC_HandleTypeDef hadc1;

// GENERAL DEFINITIONS:
#define ADC_1 &hadc1
#define TOP_LIMIT 4100
#define BOTTOM_LIMIT 3900

// BOOLS:
#define TRUE 1
#define FALSE 0
#define FAIL 0xff
#define ZERO 0
// FUNCTIONS:
/*
 * ADC_test
 * ADC - PA_0
 * connected to 3v3 GPIO
 * the signal should be between
 * ~3900 to ~4100
 * if the function successful then it returns 1
 * else ( if it fails in the tests) returns 0xff
 *
 */
uint8_t ADC_test();

#endif /* INC_ADC_H_ */
