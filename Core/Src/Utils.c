//
// Created by SMhd3 on 2/7/2023.
//

#include "Utils.h"

#include <stdbool.h>

bool Utils_Toggle(bool x) {
  return x == true ? false : true;
}

char* Utils_GetCharacter(int value) {
  switch(value) {
    case 1:
      return "O";
    default:
      return "";
  }
}