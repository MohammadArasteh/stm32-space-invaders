//
// Created by Mew on 2/8/2023.
//

#include "main.h"
#include <stdbool.h>
#include "HomeScreen.h"
#include "Utils.h"
#include "LiquidCrystal.h"
#include "Constants.h"
#include "types.h"

extern int board[21][4];

void updateBoard() {
    setCursor(0, 0);
    for(int col = 0; col < 4; col++)
        for(int row = 0; row < 20; row++) {
            char* content = Utils_GetCharacter(board[row][col]);
            print(content);
        }
}

void update_bullets_position() {
    for(int column = 0; column < 4; column++)
        for(int row = 0; row < 20; row++) {
            int cellContent = board[row][column];
            if(cellContent != CHAR_USER_BULLET && cellContent != CHAR_ENEMY_BULLET) continue;
            if(row != 0 && row != 19)
                board[row + cellContent][column]  += cellContent;
            // cellContent is 1 or -1
            board[row][column] = BOARD_EMPTY_CELL;
            if(cellContent == CHAR_USER_BULLET) row++;
        }
}

void GameScreen_OnEveryHalfSecond() {
    updateBoard();
}
void GameScreen_OnEverySecond() {
    update_bullets_position();
}

void GameScreen_OnKeyPress(char* key) {

}

int getPlayerColumn() {
    for(int i = 0; i < 4; i++)
        if(board[0][i] == CHAR_USER) return i;
    return -1;
}
void left() {
    int currentCol = getPlayerColumn();
    board[0][currentCol] = BOARD_EMPTY_CELL;
    if(currentCol == 0) board[0][3] = CHAR_USER;
    else board[0][currentCol - 1] = CHAR_USER;
}
void right() {
    int currentCol = getPlayerColumn();
    board[0][currentCol] = BOARD_EMPTY_CELL;
    if(currentCol == 3) board[0][0] = CHAR_USER;
    else board[0][currentCol + 1] = CHAR_USER;
}
void shoot() {}
void shift_down() {}
void generate_enemy() {}