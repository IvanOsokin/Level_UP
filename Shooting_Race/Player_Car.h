#ifndef PLAYER_CAR_H
#define PLAYER_CAR_H
#include <curses.h>
#include "Game_Param.h"

struct Car
{
    int initPosX;
    int initPosY;
    int score;
    chtype carView[carHeight][carWidth];
};

void initPlayerCar(Car* player);
void putPlayerCarOnTrack(const Car* player, chtype** ptrTrack);
void movePlayerCar(Car* player, Speed speed);

#endif // PLAYER_CAR_H
