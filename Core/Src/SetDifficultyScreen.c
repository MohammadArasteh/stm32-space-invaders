//
// Created by SMhd3 on 2/8/2023.
//

#include "main.h"
#include "SetDifficultyScreen.h"
#include "LiquidCrystal.h"
#include "Utils.h"
#include "Constants.h"
#include "types.h"
#include "UART.h"

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
    board[BOARD_STATUS_ROW][BOARD_USER_HP_COL] = 7;
    board[BOARD_STATUS_ROW][BOARD_USER_HP_COL] = 15;
  } else if (Utils_IsStringTwo(key)) {
    board[BOARD_STATUS_ROW][BOARD_DIFFICULTY_COL] = DIFFICULTY_NORMAL;
    board[BOARD_STATUS_ROW][BOARD_USER_HP_COL] = 5;
    board[BOARD_STATUS_ROW][BOARD_USER_HP_COL] = 25;
  } else if (Utils_IsStringThree(key)) {
    board[BOARD_STATUS_ROW][BOARD_DIFFICULTY_COL] = DIFFICULTY_HARD;
    board[BOARD_STATUS_ROW][BOARD_USER_HP_COL] = 3;
    board[BOARD_STATUS_ROW][BOARD_USER_HP_COL] = 35;
  }
  printUART("--Game Started\n");
  switch(board[BOARD_STATUS_ROW][BOARD_DIFFICULTY_COL]) {
      case DIFFICULTY_EASY:
          printUART("Difficulty: Easy\n");
          printUART("Subject: Destroying 15 of enemies spaceships\n");
          break;
      case DIFFICULTY_NORMAL:
          printUART("Difficulty: Normal\n");
          printUART("Subject: Destroying 25 of enemies spaceships\n");
          break;
      case DIFFICULTY_HARD:
          printUART("Difficulty: Hard\n");
          printUART("Subject: Destroying 35 of enemies spaceships\n");
          break;
  }

  currentScreen = SCREEN_GAME;
}
