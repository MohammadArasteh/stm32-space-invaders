//
// Created by Mew on 2/7/2023.
//
#include <stdbool.h>
#include "Constants.h"

int board[20 + 1][4] = {
        {0, 0, 0, 0},
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        {7, 15, DIFFICULTY_EASY, false} // StatusRow
};


void update_bullets_position() {
    for(int row = 0; row < 20; row++)
        for(int column = 0; column < 4; column++) {
            int cellContent = board[row][column];
            if(cellContent != CHAR_USER_BULLET && cellContent != CHAR_ENEMY_BULLET) continue;
            if(row != 0 && row != 19)
                board[row + cellContent][column] = board[row + cellContent][column] + cellContent;
            // cellContent is 1 or -1
            board[row][column] = BOARD_EMPTY_CELL;
        }
}

void update_board(int generate_enemy, int enemy_shoot) {
    update_bullets_position();
}
void left() {}
void right() {}
void shoot() {}
