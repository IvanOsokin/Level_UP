#include <string.h>
#include <math.h>
#include "Obstacles_Vehicles.h"

void createObstacleOrVehicle(const char* pathName, std::vector<ObstVehic>& _obstVehic, const Difficulty dfct)
{
    //int currentIndex = _obstVehic.capacity();
    _obstVehic.emplace_back(createObstVehic(pathName, dfct));


    /*
    //Set a unit to a suitable place onto the track
    int currentIndex = _obstVehic.capacity() - 1;
    bool isTrackBorderReached = false;
    int min = -1;
    if(currentIndex >= 1)
    {
        int offsetDir = -1;
        do
        {
            offsetDir = offsetDirection(_obstVehic[currentIndex],
                                        _obstVehic[currentIndex - 1],
                                        min,
                                        isTrackBorderReached);                //offDir = 1 - shift left
            if(offsetDir != 0)                                                //offDir = 2 - shift up
            {                                                                 //offDir = 3 - shift right
                switch (offsetDir)
                {
                    case 1:
                        _obstVehic[currentIndex].initPosX -= min;
                        if(_obstVehic[currentIndex].initPosX <= 0)
                        {
                            _obstVehic[currentIndex].initPosX = 1;
                            isTrackBorderReached = true;
                        }
                        setFreeSpace(_obstVehic[currentIndex], dfct);
                        break;
                    case 2:
                        _obstVehic[currentIndex].initPosY -= min;
                        setFreeSpace(_obstVehic[currentIndex], dfct);
                        break;
                    case 3:
                        _obstVehic[currentIndex].initPosX += min;
                        if(_obstVehic[currentIndex].initPosX >= trackWidth - _obstVehic[currentIndex].objWidth)
                        {
                            _obstVehic[currentIndex].initPosX = trackWidth - _obstVehic[currentIndex].objWidth - 1;
                            isTrackBorderReached = true;
                        }
                        setFreeSpace(_obstVehic[currentIndex], dfct);
                        break;
                }
            }
        }while(offsetDir != 0);
    }
    */
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

void setFreeSpace(ObstVehic& _obstVehic, Difficulty dfct)
{
    int tmpDfct = baseDistBtwObstacles - dfct;
    _obstVehic.freeSpaceL = _obstVehic.initPosX - carWidth / 2 - tmpDfct;
    _obstVehic.freeSpaceT = _obstVehic.initPosY - carHeight / 2 - tmpDfct;
    _obstVehic.freeSpaceR = _obstVehic.initPosX + _obstVehic.objWidth + carWidth / 2 + tmpDfct;
    _obstVehic.freeSpaceB = _obstVehic.initPosY + _obstVehic.objHeight + carHeight / 2 + tmpDfct;
}

void removeObstVehicObj(std::vector<ObstVehic>& _obstVehic, int index)
{
    //Free allocated memory for the object
    if(_obstVehic[index].objectView == nullptr)
    {
        return;
    }
    for(int i = 0; i < _obstVehic[0].objHeight; ++i)
    {
        delete[] *(_obstVehic[0].objectView + i);
    }
    delete[] _obstVehic[0].objectView;

    //Remove the object
    std::vector<ObstVehic>::iterator iter = _obstVehic.begin() + index;
    _obstVehic.erase(iter);
}

void moveObstVehic(std::vector<ObstVehic>& _obstVehic, chtype** track, const Speed spd, const Difficulty dfct)
{
    for(unsigned int k = 0; k < _obstVehic.size(); ++k)
    {
        _obstVehic[k].initPosY += spd;
        setFreeSpace(_obstVehic[k], dfct);
        if(_obstVehic[k].initPosY > trackHeight)
        {
            removeObstVehicObj(_obstVehic, k);
            k = -1;
            continue;
        }
        if(_obstVehic[k].initPosY + _obstVehic[k].objHeight < 0)
        {
            continue;
        }
        for(int i = 0; i < _obstVehic[k].objHeight; ++i)
        {
            if((_obstVehic[k].initPosY + i) >= 0 && (_obstVehic[k].initPosY + i) < trackHeight)
            {
                for(int j = 0; j < _obstVehic[k].objWidth; ++j)
                {
                    track[_obstVehic[k].initPosY + i][_obstVehic[k].initPosX + j] = _obstVehic[k].objectView[i][j];
                }
            }
        }
    }
}

int offsetDirection(ObstVehic _obstVehicCur, ObstVehic _obstVehicPrev, int& min, bool& isTrackBorderReached)
{
    int tempMin_1 = 0;
    int tempMin_2 = 0;
    if(_obstVehicCur.freeSpaceR > _obstVehicPrev.freeSpaceL
    && _obstVehicCur.freeSpaceB > _obstVehicPrev.freeSpaceT)
    {
        if((tempMin_1 = _obstVehicCur.freeSpaceR - _obstVehicPrev.freeSpaceL)
         < (tempMin_2 = _obstVehicCur.freeSpaceB - _obstVehicPrev.freeSpaceT)
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
    if(_obstVehicCur.freeSpaceB > _obstVehicPrev.freeSpaceT
    && _obstVehicCur.freeSpaceL < _obstVehicPrev.freeSpaceR)
    {
        if((tempMin_1 = _obstVehicCur.freeSpaceB - _obstVehicPrev.freeSpaceT)
         > (tempMin_2 = _obstVehicPrev.freeSpaceR - _obstVehicCur.freeSpaceL)
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
    if(_obstVehicCur.freeSpaceL < _obstVehicPrev.freeSpaceR
    && _obstVehicCur.freeSpaceT < _obstVehicPrev.freeSpaceB)
    {
        if((tempMin_1 = _obstVehicPrev.freeSpaceR - _obstVehicCur.freeSpaceL)
         < (tempMin_2 = _obstVehicPrev.freeSpaceB - _obstVehicCur.freeSpaceT)
         && !isTrackBorderReached)
        {
            min = tempMin_1;
            return 3;
        }
    }
    return 0;
}

void hitCounter(std::vector<ObstVehic>& _obstVehic, std::vector<Bullet>& _bullets, Car* _player)
{
    if(!_obstVehic.size() || !_bullets.size())
    {
        return;
    }
    for(unsigned int i = 0; i < _obstVehic.size(); ++i)
    {
        for(int j = _obstVehic[i].objHeight - 1; j >= 0; --j)
        {
            for(int k = 0; k < _obstVehic[i].objWidth; ++k)
            {
                for(unsigned int m = 0; m < _bullets.size(); ++m)
                {
                    if(((_obstVehic[i].initPosY + j) == _bullets[m].y) && ((_obstVehic[i].initPosX + k) == _bullets[m].x))
                    {
                        ++_obstVehic[i].cntHit;
                        removeBullet(_bullets, m);
                        if(_obstVehic[i].cntHit == _obstVehic[i].numberOfHit)
                        {
                            _player->score += 100;
                            removeObstVehicObj(_obstVehic, i);
                        }
                    }
                }
            }
        }
    }
}

bool isCarCrashed(std::vector<ObstVehic>& _obstVehic, Car* _player)
{
    if(!_obstVehic.size() || _player == nullptr)
    {
        return false;
    }
    for(unsigned int i = 0; i < _obstVehic.size(); ++i)
    {
        for(int j = _obstVehic[i].objHeight - 1; j >= 0; --j)
        {
            int jY = _obstVehic[i].initPosY + j;
            for(int k = 0; k < _obstVehic[i].objWidth; ++k)
            {
                int kX = _obstVehic[i].initPosX + k;
                for(int m = 0; m < carHeight; ++m)
                {
                    int mY = _player->initPosY + m;
                    for(int n = 0; n < carWidth; ++n)
                    {
                        int nX = _player->initPosX + n;
                        if((jY == mY) && (kX == nX))
                        {
                            if((_obstVehic[i].objectView[j][k] == ('*' | COLOR_PAIR(4)))
                                    && (_player->carView[m][n] == ('*' | COLOR_PAIR(4))))
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
