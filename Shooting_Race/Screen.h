#ifndef SCREEN_H
#define SCREEN_H
#include <curses.h>

#include "Game_Param.h"
#include "Player_Car.h"

bool isRaceLaunched();

void displayScore(int y, int x, const Car* player, const char* pathScoreName);
int  getBestScore(const char* pathScoreName);
void displayControl();
void displayTitle(const char* pathTitleName);

#endif // SCREEN_H
