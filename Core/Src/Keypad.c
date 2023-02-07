//
// Created by SMhd3 on 2/7/2023.
//

#include "Keypad.h"
#include "stm32f3xx.h"
#include "Constants.h"
#include "types.h"
#include "HomeScreen.h"
#include "MenuScreen.h"
#include "AboutScreen.h"
#include "InputNameScreen.h"


unsigned long last_debounce_time = 0;
unsigned long current_time = 0;
extern ScreenType currentScreen;

void handleKeyPress(char *key) {
  switch (currentScreen) {
    case SCREEN_HOME:
      HomeScreen_OnKeyPress();
      break;
    case SCREEN_MENU:
       MenuScreen_OnKeyPress(key);
       break;
    case SCREEN_ABOUT:
       AboutScreen_OnKeyPress();
       break;
    case SCREEN_INPUT_NAME:
       InputNameScreen_OnKeyPress();
       break;
    case SCREEN_SET_DIFFICULTY:
      // SetDifficultyScreen_OnKeyPress(key);
      // break;
    case SCREEN_GAME:
      // GameScreen_OnKeyPress(key);
      // break;
    case SCREEN_END_GAME:
      // EndGameScreen_OnKeyPress(key);
      // break;
    default:
      break;
  }
}

void Keypad_Init() {
  HAL_GPIO_WritePin(GPIOB, ROW1, GPIO_PIN_SET);
}

void Keypad_OnInterrupt(uint16_t GPIO_Pin) {
  current_time = HAL_GetTick();
  if (current_time - last_debounce_time < 200) return;
  last_debounce_time = current_time;

  switch(GPIO_Pin) {
    case COLUMN1:
      if(HAL_GPIO_ReadPin(GPIOB, COLUMN1)) handleKeyPress("1");
      break;
    case COLUMN2:
      if(HAL_GPIO_ReadPin(GPIOB, COLUMN2)) handleKeyPress("2");
      break;
    case COLUMN3:
      if(HAL_GPIO_ReadPin(GPIOB, COLUMN3)) handleKeyPress("3");
      break;
    case COLUMN4:
      if(HAL_GPIO_ReadPin(GPIOB, COLUMN4)) handleKeyPress("A");
      break;
    default:
      break;
  }
}
