//
// Created by SMhd3 on 2/7/2023.
//

#ifndef SPACEINVADERS_TYPES_H
#define SPACEINVADERS_TYPES_H

typedef enum page {
  INITIAL,
  ABOUT,
  INPUT_NAME,
  SET_LEVEL,
  GAME
} PageType;

typedef enum level {
  EASY,
  NORMAL,
  HARD
} LevelType;

typedef struct gameStatus {
  int playerPosition;
  int life;
  int enemyKilled;
  LevelType level;
} GameStatusStruct;

#endif //SPACEINVADERS_TYPES_H
