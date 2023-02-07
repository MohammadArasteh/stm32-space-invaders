//
// Created by Mew on 2/7/2023.
//

#ifndef SPACEINVADERS_CONSTANTS_H
#define SPACEINVADERS_CONSTANTS_H

#include "stm32f3xx_hal.h"

// pins
// BEGIN: GPIO-B
#define ROW1 GPIO_PIN_11
#define COLUMN1 GPIO_PIN_12
#define COLUMN2 GPIO_PIN_13
#define COLUMN3 GPIO_PIN_14
#define COLUMN4 GPIO_PIN_15
// END: // GPIO-B

// BEGIN: GPIO-C
#define BUZZER GPIO_PIN_0
#define VOLUME GPIO_PIN_1
#define LED GPIO_PIN_2
// ENG: GPIO-C


// BEGIN: GPIO-D
#define LCD_D1 GPIO_PIN_8
#define LCD_D2 GPIO_PIN_9
#define LCD_D3 GPIO_PIN_10
#define LCD_D4 GPIO_PIN_11
#define LCD_D5 GPIO_PIN_12
#define LCD_D6 GPIO_PIN_13
#define LCD_D7 GPIO_PIN_14
// END: GPIO-D

// characters
#define USER
#define DEAD_USER 2
#define USER_BULLET = 1
#define ENEMY
#define DEAD_ENEMY -2
#define ENEMY_BULLET = -1
#define


#endif //SPACEINVADERS_CONSTANTS_H
