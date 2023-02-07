//
// Created by SMhd3 on 2/8/2023.
//

#include <stdbool.h>
#include <string.h>
#include "main.h"
#include "MenuScreen.h"
#include "LiquidCrystal.h"
#include "types.h"
#include "Utils.h"

char *firstRowText = "Press proper key:   ";
char *secondRowText = "1- About us         ";
char *thirdRowText = "2- Start the game   ";
char *emptyRow2 = "                    ";

extern ScreenType currentScreen;

void MenuScreen_OnEverySecond() {
  setCursor(0, 0);
  print(firstRowText);

  setCursor(0, 1);
  print(secondRowText);

  setCursor(0, 2);
  print(thirdRowText);

  setCursor(0, 3);
  print(emptyRow2);
}

void MenuScreen_OnKeyPress(char *key) {
  if (Utils_IsStringOne(key)) {
    currentScreen = SCREEN_ABOUT;
  } else if (Utils_IsStringTwo(key)) {
    currentScreen = SCREEN_INPUT_NAME;
  }
}
