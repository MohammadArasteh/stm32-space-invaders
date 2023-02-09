//
// Created by SMhd3 on 2/9/2023.
//

#include "EndGameWinScreen.h"

#include <string.h>
#include "main.h"
#include "LiquidCrystal.h"
#include "types.h"
#include "Constants.h"

extern ScreenType currentScreen;

void EndGameWinScreen_OnEverySecond() {
  HAL_GPIO_WritePin(GPIOC, LED, 1);
  setCursor(0, 0);
  print("Hooray!!!!!         ");

  setCursor(0, 1);
  print("You Win!!!!         ");

  setCursor(0, 2);
  print("                    ");

  setCursor(0, 3);
  print("press any key...");
}

void EndGameWinScreen_OnKeyPress() {
  HAL_GPIO_WritePin(GPIOC, LED, 0);
  currentScreen = SCREEN_HOME;
}
