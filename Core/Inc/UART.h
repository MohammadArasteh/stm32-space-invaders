//
// Created by SMhd3 on 2/7/2023.
//

#ifndef SPACEINVADERS_UART_H
#define SPACEINVADERS_UART_H

#include "stm32f3xx_hal_uart.h"

void printUART(char *string);
void UART_OnCallback();
void UART_Init();

#endif //SPACEINVADERS_UART_H
