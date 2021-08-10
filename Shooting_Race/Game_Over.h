#ifndef GAME_OVER_H
#define GAME_OVER_H

#include <curses.h>
#include "Player_Car.h"

struct Score
{
    char nick[255];
    int  score;
};

void        gameOver(chtype** ptrTrack, const Car* player);
void        displayTableRank(const Car* player);
Score*      getTable(FILE** fPtrScore, int* tableSize);
void        closeTheGame(FILE* fPtrScore, Score* scores, int* tableSize);
char*       getUserName();
int         findPositionInTheTable(Score* scores, int* tableSize, const Car* player);
void        shiftRecords(Score** scores, int* tableSize, int index, const Car* player);
void        printTable(Score* scores, int* tableSize);
void        addNewRecord(Score** scores, int* tableSize, const Car* player);
//addNewScore()

#endif // GAME_OVER_H
