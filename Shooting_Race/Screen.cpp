#include <windows.h>
#include <string.h>

#include "Screen.h"
#include "Game_Over.h"

bool isRaceLaunched()
{
    do
    {
        if(GetKeyState(VK_RETURN) < 0)
        {
            return true;
        }
        if(GetKeyState(VK_ESCAPE) < 0)
        {
            return false;
        }
    }while(GetKeyState(VK_RETURN) >= 0 || GetKeyState(VK_ESCAPE) >= 0);
}

void displayScore(int y, int x, const Car* player, const char* pathScoreName)
{
    static int tempBestScore = 0;
    if(tempBestScore == 0)
    {
        tempBestScore = getBestScore(pathScoreName);
    }
    Score currentScore = {"Score:", player->score};
    Score bestScore = {"Best score:", tempBestScore};
    mvprintw(y, x, "%s: %d", bestScore.nick, bestScore.score);
    mvprintw(y + 2, x, "%s: %d", currentScore.nick, currentScore.score);
}

int getBestScore(const char* pathScoreName)
{
    const char* titlePathToScore = pathScoreName;
    FILE* fPtrScore = fopen(titlePathToScore, "r");
    int tempScore = 0;
    if(fPtrScore != nullptr)
    {
        fseek(fPtrScore, 0, SEEK_SET);
        while(static_cast<int>(fgetc(fPtrScore)) != '\n');
        while(static_cast<int>(fgetc(fPtrScore)) != ' ');
        fscanf(fPtrScore, "%d", &tempScore);
    }
    fclose(fPtrScore);
    return tempScore;
}

void displayControl()
{
    const char* controlDescription[controlDescriptionItem] = {"W - acelerate",
                                                              "S - slow down",
                                                              "A - to the left",
                                                              "D - to the right",
                                                              "ESC - exit",
                                                              "SPACE - shoot"};
    for(int i = 0; i < controlDescriptionItem; ++i)
    {
        mvprintw(10 + i * 2, 5, "%s", controlDescription[i]);
    }
}

void displayTitle(const char* pathTitleName)
{
    //Open the file and make a check of opening
    const char* titlePath = pathTitleName;
    FILE* fPtrTitle = fopen(titlePath, "r");
    if (fPtrTitle == nullptr)
    {
      printf("Cannot open the file!");
      return;
    }

    //Set attributes of output and get the name of the game
    attron(COLOR_PAIR(3));
    int rows = 0;
    move(titleInitPointY + rows, titleInitPointX);
    chtype tmCh = '\0';
    while(static_cast<int>(tmCh = fgetc(fPtrTitle)) != EOF)
    {
        if(tmCh == '\n')
        {
            ++rows;
            move(titleInitPointY + rows, titleInitPointX);
            continue;
        }
        addch(tmCh);
    }
    fclose(fPtrTitle);

    move(27, divisor / 2 + (trackWidth - strlen("To start press ENTER")) / 2);
    printw("To start press ENTER");
    move(29, divisor / 2 + (trackWidth - strlen("To exit press ESCAPE")) / 2);
    printw("To exit press ESCAPE");
    attroff(COLOR_PAIR(3));
}
