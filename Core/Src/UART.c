//
// Created by SMhd3 on 2/7/2023.
//

#include <string.h>
#include "UART.h"
#include "stm32f3xx_hal_uart.h"

extern UART_HandleTypeDef huart1;

char uart_input[50] = {0};
int uart_input_index = 0;
uint8_t uart_input_char[1] = {0};

void printUART(char *string) {
  HAL_UART_Transmit(&huart1, (uint8_t *)string, strlen(string), 1000);
}

void UART_OnCallback() {
  if (uart_input_char[0] != '\n') {
    uart_input[uart_input_index++] = uart_input_char[0];
  } else {
    uart_input[uart_input_index] = '\0';
    uart_input_index = 0;

    // uart input is stored at uart_input variable. use it
  }
  HAL_UART_Receive_IT(&huart1, uart_input_char, 1);
}