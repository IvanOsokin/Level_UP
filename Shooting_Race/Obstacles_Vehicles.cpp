#include <string.h>
#include <math.h>
#include "Obstacles_Vehicles.h"

void createObstacleOrVehicle(const char* pathName, std::vector<ObstVehic>& obstVehic, const Difficulty dfct)
{
    obstVehic.emplace_back(createObstVehic(pathName, dfct));
    /*
    //Set a unit to a suitable place onto the track
    int currentIndex = obstVehic.size() - 1;
    bool isTrackBorderReached = false;
    int min = -1;
    if(currentIndex >= 1)
    {
        for(int i = obstVehic.size() - 2; i >= 0; --i)
        {
            int offsetDir = -1;
            do
            {
                offsetDir = offsetDirection(obstVehic[currentIndex],
                                            obstVehic[i],
                                            min,
                                            isTrackBorderReached);                //offDir = 1 - shift left
                if(offsetDir != 0)                                                //offDir = 2 - shift up
                {                                                                 //offDir = 3 - shift right
                    switch (offsetDir)
                    {
                        case 1:
                            obstVehic[currentIndex].initPosX -= min;
                            if(obstVehic[currentIndex].initPosX <= 0)
                            {
                                obstVehic[currentIndex].initPosX = 1;
                                isTrackBorderReached = true;
                            }
                            setFreeSpace(obstVehic[currentIndex], dfct);
                            break;
                        case 2:
                            obstVehic[currentIndex].initPosY -= min;
                            setFreeSpace(obstVehic[currentIndex], dfct);
                            break;
                        case 3:
                            obstVehic[currentIndex].initPosX += min;
                            if(obstVehic[currentIndex].initPosX >= trackWidth - obstVehic[currentIndex].objWidth)
                            {
                                obstVehic[currentIndex].initPosX = trackWidth - obstVehic[currentIndex].objWidth - 1;
                                isTrackBorderReached = true;
                            }
                            setFreeSpace(obstVehic[currentIndex], dfct);
                            break;
                    }
                }
            }while(offsetDir != 0);
        }
    }*/
}

ObstVehic createObstVehic(const char* pathName, const Difficulty dfct)
{
    ObstVehic _tmpVehic;
    _tmpVehic.cntHit = 0;
    _tmpVehic.numberOfHit = dfct * numberOfHit;

    //Define type of a vehicle
    int vehicType = rand() % 4;
    char vehicTypeName[10];
    switch(vehicType)
    {
        case 0: strcpy(vehicTypeName, "car"); break;
        case 1: strcpy(vehicTypeName, "lorry"); break;
        case 2: strcpy(vehicTypeName, "obst1"); break;
        case 3: strcpy(vehicTypeName, "obst2"); break;
    }

    //Open the file and determine objWidth and objHeight
    const char* titlePathToVehicle = pathName;
    FILE* ptrVehicle = fopen(titlePathToVehicle, "r");
    if(ptrVehicle == nullptr)
    {
        printf("Cannot open the file!");
        exit(-1);
    }
    char tempStr[100];
    while(fscanf(ptrVehicle, "%s", tempStr))
    {
        if(!strcmp(tempStr, vehicTypeName))
        {
            break;
        }
    }
    fgetc(ptrVehicle);                              //Skip '\n'

    //Remember needful position in the file
    long long tmp_fpos_t;
    fpos_t* currentFilePosition = &tmp_fpos_t;
    fgetpos(ptrVehicle, currentFilePosition);

    //Determine number of rows and columns
    _tmpVehic.objWidth  = 1;
    _tmpVehic.objHeight = 1;
    char tmpCh = '\0';
    int cntColumns = 0;
    bool israwDone = false;
    while(static_cast<int>(tmpCh = fgetc(ptrVehicle)) != '/')
    {
        if(tmpCh == '\n')
        {
            ++_tmpVehic.objHeight;
            israwDone = true;
        }
        if(israwDone && _tmpVehic.objWidth == 1)
        {
            _tmpVehic.objWidth = cntColumns;
        }
        ++cntColumns;
    }

    //Alloc memory for storing units
    _tmpVehic.objectView = new chtype*[_tmpVehic.objHeight];
    for(int i = 0; i < _tmpVehic.objHeight; ++i)
    {
        *(_tmpVehic.objectView + i) = new chtype[_tmpVehic.objWidth];
    }

    //Fill the matrix
    fsetpos(ptrVehicle, currentFilePosition);
    chtype tmpChtype = '\0';
    for(int i = 0; i < _tmpVehic.objHeight; ++i)
    {
        for(int j = 0; j < _tmpVehic.objWidth; ++j)
        {

            tmpChtype = fgetc(ptrVehicle);
            *(*(_tmpVehic.objectView + i) + j) = tmpChtype | COLOR_PAIR(4);
        }
        fgetc(ptrVehicle);  //Throw new-line terminator away from each line
    }

    fclose(ptrVehicle);

    _tmpVehic.initPosX = (rand() % (trackWidth - _tmpVehic.objWidth - 1)) + 1;
    _tmpVehic.initPosY = -(_tmpVehic.objHeight);

    //setFreeSpace(_tmpVehic, dfct);

    return _tmpVehic;
}

void setFreeSpace(ObstVehic& obstVehic, Difficulty dfct)
{
    int tmpDfct = baseDistBtwObstacles - dfct;
    obstVehic.freeSpaceL = obstVehic.initPosX - carWidth / 2 - tmpDfct;
    obstVehic.freeSpaceT = obstVehic.initPosY - carHeight / 2 - tmpDfct;
    obstVehic.freeSpaceR = obstVehic.initPosX + obstVehic.objWidth + carWidth / 2 + tmpDfct;
    obstVehic.freeSpaceB = obstVehic.initPosY + obstVehic.objHeight + carHeight / 2 + tmpDfct;
}

void removeObstVehicObj(std::vector<ObstVehic>& obstVehic, int index)
{
    //Free allocated memory for the object
    if(obstVehic[index].objectView == nullptr)
    {
        return;
    }
    for(int i = 0; i < obstVehic[0].objHeight; ++i)
    {
        delete[] *(obstVehic[0].objectView + i);
    }
    delete[] obstVehic[0].objectView;

    //Remove the object
    std::vector<ObstVehic>::iterator iter = obstVehic.begin() + index;
    obstVehic.erase(iter);
}

void moveObstVehic(std::vector<ObstVehic>& obstVehic, chtype** track, const Speed spd, const Difficulty dfct)
{
    for(unsigned int k = 0; k < obstVehic.size(); ++k)
    {
        obstVehic[k].initPosY += spd;
        setFreeSpace(obstVehic[k], dfct);
        if(obstVehic[k].initPosY > trackHeight)
        {
            removeObstVehicObj(obstVehic, k);
            k = -1;
            continue;
        }
        if(obstVehic[k].initPosY + obstVehic[k].objHeight < 0)
        {
            continue;
        }
        for(int i = 0; i < obstVehic[k].objHeight; ++i)
        {
            if((obstVehic[k].initPosY + i) >= 0 && (obstVehic[k].initPosY + i) < trackHeight)
            {
                for(int j = 0; j < obstVehic[k].objWidth; ++j)
                {
                    track[obstVehic[k].initPosY + i][obstVehic[k].initPosX + j] = obstVehic[k].objectView[i][j];
                }
            }
        }
    }
}

int offsetDirection(ObstVehic obstVehicCur, ObstVehic obstVehicPrev, int& min, bool& isTrackBorderReached)
{
    int tempMin_1 = 0;
    int tempMin_2 = 0;
    if(obstVehicCur.freeSpaceR > obstVehicPrev.freeSpaceL
    && obstVehicCur.freeSpaceB > obstVehicPrev.freeSpaceT)
    {
        if((tempMin_1 = obstVehicCur.freeSpaceR - obstVehicPrev.freeSpaceL)
         < (tempMin_2 = obstVehicCur.freeSpaceB - obstVehicPrev.freeSpaceT)
         && !isTrackBorderReached)
        {
            min = tempMin_1;
            return 1;
        }
        else
        {
            min = tempMin_2;
            return 2;
        }
    }
    if(obstVehicCur.freeSpaceB > obstVehicPrev.freeSpaceT
    && obstVehicCur.freeSpaceL < obstVehicPrev.freeSpaceR)
    {
        if((tempMin_1 = obstVehicCur.freeSpaceB - obstVehicPrev.freeSpaceT)
         > (tempMin_2 = obstVehicPrev.freeSpaceR - obstVehicCur.freeSpaceL)
         && !isTrackBorderReached)
        {
            min = tempMin_2;
            return 3;
        }
        else
        {
            min = tempMin_1;
            return 2;
        }
    }
    if(obstVehicCur.freeSpaceL < obstVehicPrev.freeSpaceR
    && obstVehicCur.freeSpaceT < obstVehicPrev.freeSpaceB)
    {
        if((tempMin_1 = obstVehicPrev.freeSpaceR - obstVehicCur.freeSpaceL)
         < (tempMin_2 = obstVehicPrev.freeSpaceB - obstVehicCur.freeSpaceT)
         && !isTrackBorderReached)
        {
            min = tempMin_1;
            return 3;
        }
    }
    return 0;
}

void hitCounter(std::vector<ObstVehic>& obstVehic, std::vector<Bullet>& bullets, Car* player)
{
    if(!obstVehic.size() || !bullets.size())
    {
        return;
    }
    for(unsigned int i = 0; i < obstVehic.size(); ++i)
    {
        for(int j = obstVehic[i].objHeight - 1; j >= 0; --j)
        {
            for(int k = 0; k < obstVehic[i].objWidth; ++k)
            {
                for(unsigned int m = 0; m < bullets.size(); ++m)
                {
                    if(((obstVehic[i].initPosY + j) == bullets[m].y) && ((obstVehic[i].initPosX + k) == bullets[m].x))
                    {
                        ++obstVehic[i].cntHit;
                        removeBullet(bullets, m);
                        if(obstVehic[i].cntHit == obstVehic[i].numberOfHit)
                        {
                            player->score += 100;
                            removeObstVehicObj(obstVehic, i);
                        }
                    }
                }
            }
        }
    }
}

bool isCarCrashed(std::vector<ObstVehic>& obstVehic, Car* player)
{
    if(!obstVehic.size() || player == nullptr)
    {
        return false;
    }
    for(unsigned int i = 0; i < obstVehic.size(); ++i)
    {
        for(int j = obstVehic[i].objHeight - 1; j >= 0; --j)
        {
            int jY = obstVehic[i].initPosY + j;
            for(int k = 0; k < obstVehic[i].objWidth; ++k)
            {
                int kX = obstVehic[i].initPosX + k;
                for(int m = 0; m < carHeight; ++m)
                {
                    int mY = player->initPosY + m;
                    for(int n = 0; n < carWidth; ++n)
                    {
                        int nX = player->initPosX + n;
                        if((jY == mY) && (kX == nX))
                        {
                            if((obstVehic[i].objectView[j][k] == ('*' | COLOR_PAIR(4)))
                                    && (player->carView[m][n] == ('*' | COLOR_PAIR(4))))
                            {
                                return true;
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
