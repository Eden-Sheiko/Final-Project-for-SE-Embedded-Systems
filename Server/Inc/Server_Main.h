/*
 * SERVER_MAIN
 *
 * Author: Eden Sheiko
 *
 */
#ifndef INC_SERVER_MAIN_H_
#define INC_SERVER_MAIN_H_
#include "main.h"
#include "lwip.h"
#include "udp.h"
#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern UART_HandleTypeDef huart3;
#define UART_DEBUG &huart3

#define SERVER_PORT 7

#define BYTE 1
#define ZERO 0
#define TRUE 1
#define TIMER_ID 1
#define UART_ID 2
#define	SPI_ID 4
#define	I2C_ID 8
#define ADC_ID 16

#define BUFFER_MSG 256

#define BUFFER_NET_SIZE 264


extern struct netif gnetif;	//Generic data structure used for all lwIP network interfaces.

#define END_OF_STRING 0
#define BACKSPACE 8
#define LINE_FEED 10
#define CARRIAGE_RETURN 13

void server_main_program();

#endif /* INC_SERVER_MAIN_H_ */
