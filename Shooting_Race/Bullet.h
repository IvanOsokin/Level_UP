#ifndef BULLET_H
#define BULLET_H

#include <vector>
#include <curses.h>
#include "Player_Car.h"
#include "Game_Param.h"

struct Bullet
{
    int x;
    int y;
    chtype bulletView;
};

bool isShootButtonDown();
void createBullet(std::vector<Bullet>& bullets, const Car* playerCar);
void removeBullet(std::vector<Bullet>& bullets, int index);
void moveBullet(std::vector<Bullet>& bullets, chtype** track);

#endif // BULLET_H
