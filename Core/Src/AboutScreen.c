//
// Created by SMhd3 on 2/8/2023.
//

#include "main.h"
#include "AboutScreen.h"
#include "LiquidCrystal.h"
#include "types.h"

char *firstRowText = "     SMhd Asadi     ";
char *secondRowText = "     Mew Samurai    ";
extern ScreenType currentScreen;

void AboutScreen_OnEverySecond() {
  setCursor(0, 0);
  print(firstRowText);

  setCursor(0, 1);
  print(secondRowText);

  setCursor(0, 2);
  print("Date:");

  setCursor(0, 3);
  print("Time:");
}

void AboutScreen_OnKeyPress() {
  currentScreen = SCREEN_MENU;
}