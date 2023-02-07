//
// Created by SMhd3 on 2/7/2023.
//

#include "Utils.h"
#include "Constants.h"
#include <stdbool.h>

bool Utils_Toggle(bool x) {
  return x == true ? false : true;
}

char* Utils_GetCharacter(int value) {
  switch(value) {
    case CHAR_USER_BULLET:
      return "O";
    case CHAR_ENEMY_BULLET:
        return "X";
      case CHAR_USER:
          return "U";
    default:
      return "";
  }
}