//
// Created by Mew on 2/7/2023.
//

#ifndef SPACEINVADERS_GAMEBOARD_H
#define SPACEINVADERS_GAMEBOARD_H

void update_board(int generate_enemy, int enemy_shoot);
void update_bullets_position();
void shift_down();
void generate_enemy();
int getPlayerColumn();

// controlling functions
void left();
void right();
void shoot();

#endif //SPACEINVADERS_GAMEBOARD_H
