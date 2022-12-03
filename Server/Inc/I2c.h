#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "main.h"
#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// UART HANDLES:
extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;

// GENERAL DEFINITIONS:
#define DATA_SIZE 20					//Size of data for transmission
#define TIMEOUT_TIME 100				//Timeout for UART TRANSMIT
#define DELAY_TIME 500					//Delay time for end of loop
#define SHORT_DELAY_TIME 100			//Dealy time for short time
#define BUFFER_SIZE 256

#define I2C_MASTER &hi2c1
#define I2C_SLAVE &hi2c2
#define SLAVE_ADDRESS 20

// BOOLS:
#define TRUE 1
#define BYTE 1
#define FALSE 0
#define ZERO 0

// FUNCTIONS:
uint8_t I2C_send(uint8_t data_size, uint8_t *data_sent, uint8_t iteration);



#endif /* INC_I2C_H_ */
