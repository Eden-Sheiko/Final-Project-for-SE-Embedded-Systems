#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"
#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// TIM HANDLES:
extern TIM_HandleTypeDef htim3;

// Variables:
#define SEC_TO_MIN 60

// BOOLS:
#define TRUE 1
#define FALSE 0
#define ZERO 0
#define TIME 10

//DEFINE TIMER FUNCTION
#define TIM_3 &htim3

// FUNCTIONS:
uint8_t TIMER_main();

#endif /* INC_TIMER_H_ */
