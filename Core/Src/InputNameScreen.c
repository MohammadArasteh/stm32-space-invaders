//
// Created by SMhd3 on 2/8/2023.
//

#include "main.h"
#include <stdio.h>
#include <stdbool.h>
#include "InputNameScreen.h"
#include "LiquidCrystal.h"
#include "types.h"


bool isNameArrived = false;
extern char* username;
extern ScreenType currentScreen;

void InputNameScreen_OnEverySecond() {
  char message[21];

  if (!isNameArrived) {
    setCursor(0, 0);
    print("Enter your name     ");
    setCursor(0, 1);
    print("                    ");
    setCursor(0, 2);
    print("                    ");
    setCursor(0, 3);
    print("                    ");
  } else {
    setCursor(0, 0);
    print("Your name is:       ");
    setCursor(0, 1);
    sprintf(message, "%20s", username);
    print(message);
    setCursor(0, 2);
    print("                    ");
    setCursor(0, 3);
    print("Press any key...    ");
  }
}

void InputNameScreen_OnUARTMessage(char *message) {
  isNameArrived = true;
  username = message;
}

void InputNameScreen_OnKeyPress() {
  if (!isNameArrived) return;

  isNameArrived = false;
  currentScreen = SCREEN_SET_DIFFICULTY;
}