//
// Created by SMhd3 on 2/7/2023.
//

#ifndef SPACEINVADERS_KEYPAD_H
#define SPACEINVADERS_KEYPAD_H

#include <stdint-gcc.h>

void Keypad_Init();
void Keypad_OnInterrupt(uint16_t GPIO_Pin);

#endif //SPACEINVADERS_KEYPAD_H
