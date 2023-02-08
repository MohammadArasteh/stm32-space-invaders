//
// Created by Mew on 2/7/2023.
//
#include <stdbool.h>
#include "Constants.h"

int board[20 + 1][4] = {
        {CHAR_USER, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL},
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        {3, 15, DIFFICULTY_EASY, false} // StatusRow
};


int enemy_moves[100][4] = {
        {CHAR_ENEMY, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL},
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY, CHAR_ENEMY },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, CHAR_ENEMY, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        {CHAR_ENEMY, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL},
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY },
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, CHAR_ENEMY, CHAR_ENEMY },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY },
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, CHAR_ENEMY },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        {BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL},
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, CHAR_ENEMY, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY, CHAR_ENEMY },
        { CHAR_ENEMY, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY },
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY },
        {CHAR_ENEMY, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL},
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY, CHAR_ENEMY },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, CHAR_ENEMY, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        {CHAR_ENEMY, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL},
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY },
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, CHAR_ENEMY, CHAR_ENEMY },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY },
        { BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL, CHAR_ENEMY },
        { BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, CHAR_ENEMY, BOARD_EMPTY_CELL },
        { CHAR_ENEMY, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL, BOARD_EMPTY_CELL },
};
