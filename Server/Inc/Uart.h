#ifndef INC_UART_H_
#define INC_UART_H_

#include "main.h"
#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// UART HANDLES:
extern UART_HandleTypeDef huart3;	//Change to match your UART number
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart6;  // new

// UARAT AND GPIO DEFINITIONS:
#define UART_DEBUG &huart3			//Debug UART
#define UART_MASTER &huart4			//Transmit UART
#define UART_SLAVE &huart6			//Receive UART

// GENERAL DEFINITIONS:
#define DATA_SIZE 20					//Size of data for transmission
#define TIMEOUT_TIME 100				//Timeout for UART TRANSMIT
#define DELAY_TIME 500					//Delay time for end of loop
#define SHORT_DELAY_TIME 100			//Delay time for short time
#define BUFFER_SIZE 256
// BOOLS:
#define TRUE 1
#define BYTE 1
#define FALSE 0
#define ZERO 0
#define ERROR 0xff

// FUNCTIONS:
uint8_t UART_send(uint8_t data_size, uint8_t *data_sent, uint8_t iteration);
int check_status(HAL_StatusTypeDef *s1,HAL_StatusTypeDef *s2);
int compare_arrays(const uint8_t *arr_1 , const uint8_t *arr_2 ,const uint8_t size);

#endif /* INC_UART_H_ */
