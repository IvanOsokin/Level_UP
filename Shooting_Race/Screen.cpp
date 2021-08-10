#include "Screen.h"
#include "Game_Param.h"
#include <windows.h>
#include <string.h>

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

void displayScore();
void displayControl();
void displayTitle()
{
    //Open the file and make a check of opening
    const char* titlePath = "D:\\Ivan\\Level_UP\\build-Shooting_Race-Desktop_Qt_6_1_0_MinGW_64_bit-Debug\\debug\\title.txt";
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
