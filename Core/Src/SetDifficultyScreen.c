//
// Created by SMhd3 on 2/8/2023.
//

#include "SetDifficultyScreen.h"
#include "LiquidCrystal.h"
#include "Utils.h"
#include "Constants.h"
#include "types.h"

extern int board[20 + 1][4];
extern ScreenType currentScreen;

void SetDifficultyScreen_OnEverySecond() {
  setCursor(0, 0);
  print("Select difficulty:  ");

  setCursor(0, 1);
  print("1       Easy       1");

  setCursor(0, 2);
  print("2      Normal      2");

  setCursor(0, 3);
  print("3       Hard       3");
}

void SetDifficultyScreen_OnKeyPress(char *key) {
  if (Utils_IsStringA(key)) return;

  if (Utils_IsStringOne(key)) {
    board[BOARD_STATUS_ROW][BOARD_DIFFICULTY_COL] = DIFFICULTY_EASY;
  } else if (Utils_IsStringTwo(key)) {
    board[BOARD_STATUS_ROW][BOARD_DIFFICULTY_COL] = DIFFICULTY_NORMAL;
  } else if (Utils_IsStringThree(key)) {
    board[BOARD_STATUS_ROW][BOARD_DIFFICULTY_COL] = DIFFICULTY_HARD;
  }

  currentScreen = SCREEN_GAME;
}
