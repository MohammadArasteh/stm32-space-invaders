//
// Created by Mew on 2/8/2023.
//

#ifndef SPACEINVADERS_GAMESCREEN_H
#define SPACEINVADERS_GAMESCREEN_H

void GameScreen_OnEveryHalfSecond();
void GameScreen_OnEverySecond();
void GameScreen_OnEveryThreeSeconds();
void GameScreen_OnEveryFiveSeconds();
void GameScreen_OnKeyPress(char* key);

void shift_down();
int getPlayerColumn();
void enemy_shot();

// controlling functions
void left();
void right();
void shoot();

#endif //SPACEINVADERS_GAMESCREEN_H
