#include "Surroundings.h"
#include "Game_Param.h"

void initTrack(chtype** ptrTrack)
{
    if (ptrTrack == nullptr)
    {
        return;
    }

    init_pair(1, COLOR_BLACK | COLOR_WHITE, COLOR_BLACK | COLOR_WHITE);
    init_pair(2, COLOR_BLACK, COLOR_BLACK);

    for(int i = 0; i < trackHeight; ++i)
    {
        for(int j = 0; j < trackWidth; ++j)
        {
            if((j == 0 || j == trackWidth - 1) && (i + 1) % 4 != 0)
            {
                *(*(ptrTrack + i) + j) = '*' | COLOR_PAIR(1);
            }
            else if((j == 0 || j == trackWidth - 1) && (i + 1) % 4 == 0)
            {
                *(*(ptrTrack + i) + j) = '*' | COLOR_PAIR(2);
            }
            else
            {
                *(*(ptrTrack + i) + j) = ' ';
            }
        }
    }
}

chtype** createTrack()
{
    chtype** ptrTrack = new chtype*[trackHeight];
    for(int i = 0; i < trackHeight; ++i)
    {
        *(ptrTrack + i) = new chtype[trackWidth];
    }

    initTrack(ptrTrack);

    return ptrTrack;
}

void showTrack(chtype** ptrTrack)
{
    if (ptrTrack == nullptr)
    {
        return;
    }

    for(int i = 0; i < trackHeight; ++i)
    {
        move(i, divisor / 2);
        for(int j = 0; j < trackWidth; ++j)
        {
            addch(*(*(ptrTrack + i) + j));
        }
    }
}

void destroyTrack(chtype** ptrTrack)
{
    if (ptrTrack == nullptr)
    {
        return;
    }

    for(int i = 0; i < trackHeight; ++i)
    {
        delete[] *(ptrTrack + i);
        *(ptrTrack + i) = nullptr;
    }
    delete[] ptrTrack;
    ptrTrack = nullptr;
}

void moveTrack(chtype** ptrTrack, const int* vel)
{
    if (ptrTrack == nullptr)
    {
        return;
    }

    for(int i = 0; i < trackHeight; ++i)
    {
        for(int j = 0; j < trackWidth; ++j)
        {
            if((j == 0 || j == trackWidth - 1) && (i - *vel) % 5 != 0)
            {
                *(*(ptrTrack + i) + j) = '*' | COLOR_PAIR(1);
            }
            else if((j == 0 || j == trackWidth - 1) && (i - *vel) % 5 == 0)
            {
                *(*(ptrTrack + i) + j) = '*' | COLOR_PAIR(2);
            }
            else
            {
                *(*(ptrTrack + i) + j) = ' ';
            }
        }
    }
}
