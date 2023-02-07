//
// Created by SMhd3 on 2/7/2023.
//

#include "main.h"
#include <stdint-gcc.h>
#include "LCD.h"
#include "LiquidCrystal.h"
#include "stm32f303xc.h"
#include "Constants.h"

char spaceship1[] = { // enemy
        0B10000,
        0B11001,
        0B01110,
        0B11101,
        0B11101,
        0B01110,
        0B11001,
        0B10000
};
char spaceship2[] = { // enemy
        0B00011,
        0B01001,
        0B00111,
        0B11101,
        0B11101,
        0B00111,
        0B01001,
        0B00011
};
char spaceship3[] = { // player
        0B11001,
        0B01011,
        0B01110,
        0B11101,
        0B11101,
        0B01110,
        0B01011,
        0B11001
};

void LCD_Init() {
  LiquidCrystal(GPIOD, LCD_D1, LCD_D2, LCD_D3, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

  begin(20, 4);

  createChar(0, spaceship1);
  createChar(1, spaceship2);
  createChar(2, spaceship3);

}
