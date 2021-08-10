#include <windows.h>
#include "Bullet.h"

bool isShootButtonDown()
{
    if(GetAsyncKeyState(VK_SPACE) & 0x01)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createBullet(std::vector<Bullet>& bullets, const Car* playerCar)
{
    static int bulletStep = 0;
    if(bulletStep == 1)
    {
        bullets.emplace_back(Bullet{playerCar->initPosX + 1,
                                    playerCar->initPosY,
                                    '^' | COLOR_PAIR(3)});
        bullets.emplace_back(Bullet{playerCar->initPosX + carWidth - 2,
                                    playerCar->initPosY,
                                    '^' | COLOR_PAIR(3)});
        bulletStep = 0;
        return;
    }
    ++bulletStep;
}

void removeBullet(std::vector<Bullet>& bullets, int index)
{
    std::vector<Bullet>::iterator iter = bullets.begin() + index;
    bullets.erase(iter);
}

void moveBullet(std::vector<Bullet>& bullets, chtype** track)
{
    for(unsigned int i = 0; i < bullets.size(); ++i)
    {
        --bullets[i].y;
        if(bullets[i].y < 0)
        {
            removeBullet(bullets, i);
            i = -1;
            continue;
        }

        //Put the bullets onto he track
        *(*(track + bullets[i].y) + bullets[i].x) = bullets[i].bulletView;
    }
}
