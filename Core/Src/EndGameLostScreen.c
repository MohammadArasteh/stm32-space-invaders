//
// Created by SMhd3 on 2/9/2023.
//

#include "EndGameLostScreen.h"
#include "main.h"
#include "LiquidCrystal.h"
#include "types.h"
#include "Constants.h"

extern ScreenType currentScreen;

void EndGameLostScreen_OnEverySecond() {
  HAL_GPIO_WritePin(GPIOC, LED, 1);
  setCursor(0, 0);
  print("Oh noo!!!!!         ");

  setCursor(0, 1);
  print("You Lost!!!!        ");

  setCursor(0, 2);
  print("                    ");

  setCursor(0, 3);
  print("press any key...");
}

void EndGameLostScreen_OnKeyPress() {
  HAL_GPIO_WritePin(GPIOC, LED, 0);
  currentScreen = SCREEN_HOME;
}
