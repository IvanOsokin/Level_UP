#include <string.h>
#include <windows.h>
#include <math.h>

#include "Game_Over.h"
#include "Game_Param.h"
#include "Surroundings.h"

void gameOver(chtype** ptrTrack, const Car* player, const char* pathScoreName)
{
    Sleep(2000);
    clear();
    refresh();
    ptrTrack = createTrack();
    showTrack(ptrTrack);
    move(actualWindowHeight / 2, (actualWindowWidth - strlen("GAME OVER")) / 2);
    printw("GAME OVER");
    refresh();
    getchar();
    getch();
    displayTableRank(player, pathScoreName);
}

void displayTableRank(const Car* player, const char* pathScoreName)
{
    FILE* fPtrScore;
    int tableSize = 0;
    Score* scores = getTable(&fPtrScore, &tableSize, pathScoreName);
    if(tableSize == 0)
    {
        ++tableSize;
        scores->score = player->score;
        curs_set(1);
        printTable(scores, &tableSize);
        refresh();
        move(startPosInTable, (divisor / 2) + 15);
        refresh();
        char* tmpUserName = getUserName();
        strcpy(scores->nick, tmpUserName);
        delete[] tmpUserName;
        curs_set(0);
        printTable(scores, &tableSize);
        getch();
    }
    else
    {
        addNewRecord(&scores, &tableSize, player);
        getch();
    }
    closeTheGame(fPtrScore, scores, &tableSize);
}

Score* getTable(FILE** fPtrScore, int* tableSize, const char* pathScoreName)
{
    const char* titlePathToScore = pathScoreName;
    *fPtrScore = fopen(titlePathToScore, "r+");
    Score* _scores = nullptr;
    if(*fPtrScore != nullptr)
    {
        fseek(*fPtrScore, 0, SEEK_SET);
        fscanf(*fPtrScore, "%d", tableSize);
        _scores = new Score[*tableSize];
        for(int i = 0; i < *tableSize; ++i)
        {
            fscanf(*fPtrScore, "%s%d", _scores[i].nick, &_scores[i].score);
        }
    }
    else
    {
        *fPtrScore = fopen(titlePathToScore, "w+");
        _scores = new Score[1];
        strcpy(_scores->nick, "\0");
        _scores->score = 0;
    }
    return _scores;
}

int findPositionInTheTable(Score* scores, int* tableSize, const Car* player)
{
    if(scores == nullptr)
    {
        return -2;
    }
    int tempIndex = -1;
    for(int i = 0; i < *tableSize; ++i)
    {
        if(player->score > scores[i].score)
        {
            return i;
        }
    }
    if(*tableSize <= maxAmountOfScores)
    {
        tempIndex = *tableSize;
    }
    return tempIndex;
}

void printTable(Score* scores, int* tableSize)
{
    clear();
    move(3, (actualWindowWidth - strlen("TOP 10")) / 2);
    printw("TOP 10");
    for(int i = 0; i < *tableSize; ++i)
    {
        move(startPosInTable + i * 2, (divisor / 2) + 15);
        printw("%s", scores[i].nick);
        move(startPosInTable + i * 2, divisor + divisor / 2 - 20);
        printw("%10d", scores[i].score);
    }
    refresh();
}

void addNewRecord(Score** scores, int* tableSize, const Car* player)
{
    int position = findPositionInTheTable(*scores, tableSize, player);
    if(*tableSize != maxAmountOfScores)
    {
        ++(*tableSize);
    }
    if(position >= 0 && position < *tableSize)
    {
        shiftRecords(scores, tableSize, position, player);
        curs_set(1);
        printTable(*scores, tableSize);
        move(startPosInTable + position * 2, (divisor / 2) + 15);
        refresh();
        char* tmpUserName = getUserName();
        strcpy((*scores)[position].nick, tmpUserName);
        delete[] tmpUserName;
        curs_set(0);
        printTable(*scores, tableSize);
    }
}

void shiftRecords(Score** scores, int* tableSize, int index, const Car* player)
{
    Score* _tmpScores = new Score[*tableSize];
    int i = -1;
    for(i = *tableSize - 1; i > index; --i)
    {
        strcpy(_tmpScores[i].nick, (*scores)[i - 1].nick);
        _tmpScores[i].score = (*scores)[i - 1].score;
    }
    strcpy(_tmpScores[i].nick, "\0");
    _tmpScores[i].score = player->score;
    --i;
    for(; i >= 0; --i)
    {
        strcpy(_tmpScores[i].nick, (*scores)[i].nick);
        _tmpScores[i].score = (*scores)[i].score;
    }
    delete[] *scores;
    *scores = _tmpScores;
    _tmpScores = nullptr;
}

char* getUserName()
{
    char tempUserName[255];
    getstr(tempUserName);
    char* tUN = new char[strlen(tempUserName) + 1];
    strcpy(tUN, tempUserName);
    return tUN;
}

void closeTheGame(FILE* fPtrScore, Score* scores, int* tableSize)
{
    if(*tableSize <= 0 || scores == nullptr)
    {
        return;
    }
    fseek(fPtrScore, 0, SEEK_SET);
    fprintf(fPtrScore, "%d\n", *tableSize);
    for(int i = 0; i < *tableSize; ++i)
    {
        fprintf(fPtrScore, "%s %d\n", scores[i].nick, scores[i].score);
    }
    fclose(fPtrScore);
    delete[] scores;
}
