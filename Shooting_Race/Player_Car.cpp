#include <windows.h>
#include "Player_Car.h"
#include "Game_Param.h"

void initPlayerCar(Car* player)
{
    if (player == nullptr)
    {
        return;
    }

    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);

    player->initPosX = (trackWidth - carWidth) / 2;
    player->initPosY = trackHeight - carHeight;
    player->score = 0;
    for(int i = 0; i < carHeight; ++i)
    {
        for(int j = 0; j < carWidth; ++j)
        {
            if(j == 3 || j == 4)
            {
                player->carView[i][j] = '*' | COLOR_PAIR(3);
            }
            else if((j == 1 || j == 6) && (i == 0 || i == 3 || i == 6))
            {
                player->carView[i][j] = ' ' | COLOR_PAIR(2);
            }
            else if((j == 0 || j == 7) && (i != 7))
            {
                player->carView[i][j] = ' ' | COLOR_PAIR(2);
            }
            else
            {
                player->carView[i][j] = '*' | COLOR_PAIR(4);
            }
        }
    }
}

void putPlayerCarOnTrack(const Car* player, chtype** ptrTrack)
{
    if ((player == nullptr) || (ptrTrack == nullptr))
    {
        return;
    }

    for(int i = player->initPosY, k = 0; k < carHeight; ++i, ++k)
    {
        for(int j = player->initPosX, n = 0; n < carWidth; ++j, ++n)
        {
            *(*(ptrTrack + i) + j) = player->carView[k][n];
        }
    }
}

void movePlayerCar(Car* player, Speed speed)
{
    if (player == nullptr)
    {
        return;
    }

    Car tempPlayer = *player;
    if(GetKeyState('D') < 0)
    {
        if((player->initPosX += speed) >= trackWidth - carWidth)
        {
            player->initPosX = tempPlayer.initPosX;
        }
    }
    if(GetKeyState('A') < 0)
    {
        if((player->initPosX -= speed) <= 0)
        {
            player->initPosX = tempPlayer.initPosX;
        }
    }
    if(GetKeyState('W') < 0)
    {
        if((player->initPosY -= speed) < 0)
        {
            player->initPosY = tempPlayer.initPosY;
        }
    }
    if(GetKeyState('S') < 0)
    {
        if((player->initPosY += speed) > trackHeight - carWidth)
        {
            player->initPosY = tempPlayer.initPosY;
        }
    }
}
