#ifndef INC_SPI_H_
#define INC_SPI_H_

#include "main.h"
#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// SPI HANDLES:
extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi4;


// GENERAL DEFINITIONS:
#define TIMEOUT_TIME 100				//Timeout for UART TRANSMIT
#define DELAY_TIME 500					//Delay time for end of loop
#define SHORT_DELAY_TIME 100			//Dealy time for short time
#define BUFFER_SIZE 256

// BOOLS:
#define TRUE 1
#define FALSE 0
#define BYTE 1

//SHARON FUNCTION
#define SPI_MASTER &hspi1
#define SPI_SLAVE &hspi4


// FUNCTIONS:
uint8_t SPI_send(uint8_t data_size,uint8_t *data_sent,uint8_t iteration);


#endif /* INC_SPI_H_ */
