#ifndef OBSTACLES_VEHICLES_H
#define OBSTACLES_VEHICLES_H

#include <curses.h>
#include <vector>
#include <stdlib.h>
#include "Game_Param.h"
#include "Bullet.h"
#include "Player_Car.h"

struct ObstVehic
{
    chtype** objectView;
    int      initPosX;
    int      initPosY;
    int      cntHit;     //depends on difficulty
    int      numberOfHit;
    int      objWidth;
    int      objHeight;
    int      freeSpaceL;
    int      freeSpaceT;
    int      freeSpaceR;
    int      freeSpaceB;
};

void      createObstacleOrVehicle(const char* pathName, std::vector<ObstVehic>& obstVehic, const Difficulty dfct);
ObstVehic createObstVehic(const char* pathName, const Difficulty dfct);
void      removeObstVehicObj(std::vector<ObstVehic>& obstVehic, int index);
void      moveObstVehic(std::vector<ObstVehic>& obstVehic, chtype** track, const Speed spd, const Difficulty dfct);
void      setFreeSpace(ObstVehic& obstVehic, Difficulty dfct);
int       offsetDirection(ObstVehic obstVehicCur, ObstVehic obstVehicPrev, int& min, bool& isTrackBorderReached);
void      redefineInitPos(std::vector<ObstVehic>& obstVehic);
void      hitCounter(std::vector<ObstVehic>& obstVehic, std::vector<Bullet>& bullets, Car* player);
bool      isCarCrashed(std::vector<ObstVehic>& obstVehic, Car* player);

#endif // OBSTACLES_VEHICLES_H
