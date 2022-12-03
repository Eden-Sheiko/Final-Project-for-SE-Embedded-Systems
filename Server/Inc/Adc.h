#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "main.h"
#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ADC HANDLES:
extern ADC_HandleTypeDef hadc1;

// GENERAL DEFINITIONS:
#define ADC_1 &hadc1
#define TOP_LIMIT 4100
#define BOTTOM_LIMIT 3900

// BOOLS:
#define TRUE 1
#define FALSE 0
#define ZERO 0
// FUNCTIONS:
uint8_t ADC_main();

#endif /* INC_ADC_H_ */
