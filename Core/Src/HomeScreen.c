//
// Created by SMhd3 on 2/7/2023.
//

#include <stdbool.h>
#include "HomeScreen.h"
#include "Utils.h"
#include "LiquidCrystal.h"
#include "Constants.h"

bool showRow1 = true;

char *row1Text = "       Space        ";
char *row2Text = "      Invaders      ";
char *emptyRow = "                    ";

void updateBoard() {
  setCursor(0, 0);
  print(showRow1 ? row1Text : emptyRow);

  setCursor(0, 1);
  print(!showRow1 ? row2Text : emptyRow);

  setCursor(0, 2);
  print(emptyRow);

  setCursor(0, 3);
  print("        ");
  if (showRow1) {
    write(CHAR_USER);
  } else {
    print(" ");
  }

  print(" ");

  if (!showRow1) {
    write(CHAR_ENEMY);
  } else {
    print(" ");
  }
  print("        ");
}

void HomeScreen_OnEverySecond() {
  updateBoard();
  showRow1 = Utils_Toggle(showRow1);
}