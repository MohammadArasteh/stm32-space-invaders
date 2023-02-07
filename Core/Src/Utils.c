//
// Created by SMhd3 on 2/7/2023.
//

#include "Utils.h"
#include "Constants.h"
#include <stdbool.h>
#include <string.h>

bool Utils_Toggle(bool x) {
  return x == true ? false : true;
}

char* Utils_GetCharacter(int value) {
  switch(value) {
    case CHAR_USER_BULLET:
      return "O";
    case CHAR_ENEMY_BULLET:
        return "X";
    case BOARD_EMPTY_CELL:
          return " ";
    default:
      return " ";
  }
}

bool Utils_IsStringOne(char *key) {
  return strcmp(key, "1") == 0;
}
bool Utils_IsStringTwo(char *key) {
  return strcmp(key, "2") == 0;
}
bool Utils_IsStringThree(char *key) {
  return strcmp(key, "3") == 0;
}
bool Utils_IsStringA(char *key) {
  return strcmp(key, "A") == 0;
}