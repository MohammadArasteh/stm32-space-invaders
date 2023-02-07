//
// Created by SMhd3 on 2/7/2023.
//

#include "Keypad.h"
#include "stm32f3xx_hal_gpio.h"
#include "Constants.h"


unsigned long last_debounce_time = 0;
unsigned long current_time = 0;

void Keypad_Init() {
  HAL_GPIO_WritePin(GPIOB, ROW1, GPIO_PIN_SET);
}

void Keypad_OnInterrupt(uint16_t GPIO_Pin) {
  current_time = HAL_GetTick();
  if (current_time - last_debounce_time < 200) return;
  last_debounce_time = current_time;

  switch(GPIO_Pin) {
    case COLUMN1:
      if(HAL_GPIO_ReadPin(GPIOB, COLUMN1))
        HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_8);
      break;
    case COLUMN2:
      if(HAL_GPIO_ReadPin(GPIOB, COLUMN2))
        HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_8);
      break;
    case COLUMN3:
      if(HAL_GPIO_ReadPin(GPIOB, COLUMN3))
        HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_8);
      break;
    case COLUMN4:
      if(HAL_GPIO_ReadPin(GPIOB, COLUMN4))
        HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_8);
      break;
    default:
      break;
  }
}