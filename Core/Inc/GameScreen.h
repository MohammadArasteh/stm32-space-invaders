//
// Created by Mew on 2/8/2023.
//

#ifndef SPACEINVADERS_GAMESCREEN_H
#define SPACEINVADERS_GAMESCREEN_H

void GameScreen_OnEveryHalfSecond();
void GameScreen_OnEverySecond();
void GameScreen_OnKeyPress(char* key);

void shift_down();
void generate_enemy();
int getPlayerColumn();

// controlling functions
void left();
void right();
void shoot();

#endif //SPACEINVADERS_GAMESCREEN_H
