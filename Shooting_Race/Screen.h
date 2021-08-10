#ifndef SCREEN_H
#define SCREEN_H
#include <curses.h>

#include "Game_Param.h"
#include "Player_Car.h"

bool isRaceLaunched();

void displayScore(int y, int x, const Car* player);
int  getBestScore();
void displayControl();
void displayTitle();

#endif // SCREEN_H
