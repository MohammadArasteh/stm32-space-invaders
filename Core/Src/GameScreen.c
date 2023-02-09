//
// Created by Mew on 2/8/2023.
//

#include "main.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "HomeScreen.h"
#include "Utils.h"
#include "LiquidCrystal.h"
#include "Constants.h"
#include "types.h"
#include "UART.h"

int getFirstEnemyRow(int col);

extern int board[21][4];
extern int enemy_moves[100][4];
extern ScreenType currentScreen;
int enemy_current_wave = 0;

void updateGameScreen() {
    setCursor(0, 0);
    for(int col = 0; col < 4; col++) {
        setCursor(0, col);
        for(int row = 0; row < 20; row++) {
            if(board[row][col] == CHAR_DEAD_ENEMY) {
                board[row][col] = BOARD_EMPTY_CELL;
                board[BOARD_STATUS_ROW][BOARD_ENEMY_COUNT_COL]--;
                if(board[BOARD_STATUS_ROW][BOARD_ENEMY_COUNT_COL] == 3) {
                    printUART("############\n");
                    printUART("GOOD JOB! Only 3 enemies left...\n");
                    printUART("############\n");
                }
                if(board[BOARD_STATUS_ROW][BOARD_ENEMY_COUNT_COL] == 0) {
                    currentScreen = SCREEN_END_GAME_WIN;
                    printUART("************\n");
                    printUART("You WON!\n");
                    printUART("************\n");
                }
            }
            if(board[row][col] == CHAR_DEAD_USER) {
                if(board[BOARD_STATUS_ROW][BOARD_USER_HP_COL] > 0) {
                    board[BOARD_STATUS_ROW][BOARD_USER_HP_COL]--;
                    board[row][col] = CHAR_USER;
                }
                if(board[BOARD_STATUS_ROW][BOARD_USER_HP_COL] == 1) {
                    printUART("############\n");
                    printUART("WARNING: Only one HP remained!\n");
                    printUART("############\n");
                }
                if(board[BOARD_STATUS_ROW][BOARD_USER_HP_COL] == 0) {
                    currentScreen = SCREEN_END_GAME_LOST;
                    printUART("************\n");
                    printUART("you LOST!\n");
                    printUART("************\n");
                }
            }
            if(board[row][col] == CHAR_USER || board[row][col] == CHAR_DEAD_USER)
                write(2);
            else if(board[row][col] == CHAR_ENEMY)
                write(0);
            else if(board[row][col] == CHAR_ENEMY_BULLET)
                write(3);
            else if(board[row][col] == CHAR_USER_BULLET)
                write(4);
            else if(board[row][col] == BOARD_EMPTY_CELL)
                print(" ");
        }
    }

}

void update_bullets_position() {
    for(int column = 0; column < 4; column++)
        for(int row = 0; row < 20; row++) {
            int cellContent = board[row][column];

            if(cellContent != CHAR_USER_BULLET &&
                cellContent != CHAR_ENEMY_BULLET &&
                cellContent != 2 * CHAR_USER_BULLET)
                continue;

            if(row != 0 && row != 19) {
                if(cellContent == 2 * CHAR_USER_BULLET) {
                    board[row + cellContent][column]  += cellContent / 2;
                    board[row][column] -= 1;
                }
                else {
                    board[row + cellContent][column]  += cellContent;
                    board[row][column] = BOARD_EMPTY_CELL;
                    if(board[row + cellContent][column] != 2 * CHAR_USER_BULLET && cellContent == CHAR_USER_BULLET)
                        row++;
                }
            } else board[row][column] = BOARD_EMPTY_CELL;
        }
}

void shift_down() {
    for(int row = 0; row < 20; row++) {
        for(int col = 0; col < 4; col++) {
            int cellContent = board[row][col];
            if(cellContent == CHAR_ENEMY) {
                if(row != 0 && board[row - 1][col] != CHAR_USER)
                    board[row - 1][col] = cellContent;
                board[row][col] = BOARD_EMPTY_CELL;
            }
        }
    }
    for(int i = 0; i < 4; i++)
        board[19][i] = enemy_moves[enemy_current_wave][i];
    enemy_current_wave++;
    if(enemy_current_wave >= 100) enemy_current_wave = 0;
}
int getPlayerColumn() {
    for(int i = 0; i < 4; i++)
        if(board[0][i] == CHAR_USER) return i;
    return -1;
}
void left() {
    int currentCol = getPlayerColumn();
    if(currentCol == 0) board[0][3] = CHAR_USER;
    else board[0][currentCol - 1] = CHAR_USER;
    board[0][currentCol] = BOARD_EMPTY_CELL;
}
void right() {
    int currentCol = getPlayerColumn();
    if(currentCol == 3) board[0][0] = CHAR_USER;
    else board[0][currentCol + 1] = CHAR_USER;
    board[0][currentCol] = BOARD_EMPTY_CELL;
}
void shoot() {
    int currentCol = getPlayerColumn();
    board[1][currentCol] = CHAR_USER_BULLET;
}
void enemy_shot() {
    int col1 = rand() % (4 + 1 - 0) + 0;
    int col2 = rand() % (4 + 1 - 0) + 0;
    int row1 = getFirstEnemyRow(col1);
    int row2 = getFirstEnemyRow(col2);
    if(col1 == col2 && row1 != -1) board[row1 - 1][col1] = CHAR_ENEMY_BULLET;
    else {
        if(row1 != -1)  board[row1 - 1][col1] = CHAR_ENEMY_BULLET;
        if(row2 != -1)  board[row2 - 1][col2] = CHAR_ENEMY_BULLET;
    }
}
int getFirstEnemyRow(int col) {
    for(int i = 1; i < 20; i++)
        if(board[i][col] == CHAR_ENEMY) return i;
    return -1;
}

void GameScreen_OnKeyPress(char* key) {
    if(strcmp(key, "1") == 0) left();
    else if(strcmp(key, "2") == 0) shoot();
    else if(strcmp(key, "3") == 0) right();
}

void GameScreen_OnEveryHalfSecond() {
    update_bullets_position();
    updateGameScreen();
}
void GameScreen_OnEverySecond() {
    if(board[BOARD_STATUS_ROW][BOARD_DIFFICULTY_COL] == DIFFICULTY_HARD) shift_down();
}
void GameScreen_OnEveryThreeSeconds() {
    if(board[BOARD_STATUS_ROW][BOARD_DIFFICULTY_COL] == DIFFICULTY_NORMAL) shift_down();
}
void GameScreen_OnEveryFiveSeconds() {
    enemy_shot();
    if(board[BOARD_STATUS_ROW][BOARD_DIFFICULTY_COL] == DIFFICULTY_EASY) shift_down();
}