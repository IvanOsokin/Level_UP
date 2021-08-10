#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#include "Surroundings.h"
#include "Player_Car.h"
#include "Game_Param.h"
#include "Console.h"
#include "Screen.h"
#include "Bullet.h"
#include "Obstacles_Vehicles.h"
#include "Game_Over.h"

int main(int argc, char* argv[])
{
    char pathName[500];
    if(argc == 2)
    {
        strcpy(pathName, argv[1]);
        strcpy(pathName + strlen(argv[1]), "\\vehicle.txt");
    }
    else
    {
        strcpy(pathName, "vehicle.txt");
    }

    //Set the console size
    //HWND hWnd = GetConsoleWindow();
    //HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //setWindow(hWnd, hStdOut, windowWidth, windowHeight);

    //CONSOLE_SCREEN_BUFFER_INFO curConsoleInfo;
    //GetConsoleScreenBufferInfo(hStdOut, &curConsoleInfo);
    //printf("curX = %d, curY = %d", curConsoleInfo.dwSize.X, curConsoleInfo.dwSize.Y);

    //PDC library initialization
    initscr();
    resize_term(windowHeight, windowWidth);
    if (!has_colors())
    {
        endwin();
        printf("Colours are not supported!");
        return -1;
    }
    start_color();
    curs_set(0);
    keypad(stdscr, TRUE);
    srand(time(nullptr));

    //Initial data initialization
    Car player;
    initPlayerCar(&player);
    chtype** ptrTrack = createTrack();
    putPlayerCarOnTrack(&player, ptrTrack);
    showTrack(ptrTrack);

    //Show start menu
    displayTitle();
    refresh();
    bool isRaceRun = isRaceLaunched();
    clear();

    int gVelocity = 0;
    Speed spd = FAST_SPD;
    Difficulty dfct = EASY_DFCT;
    int callNxtObj = 0;
    int counter = 0;
    std::vector<Bullet> bullets;
    std::vector<ObstVehic> obstVehic;
    bool isGameOver = false;
    if(isRaceRun)
    {
        do
        {
            moveTrack(ptrTrack, &gVelocity);
            moveObstVehic(obstVehic, ptrTrack, spd, dfct);
            if(counter == callNxtObj)
            {
                createObstacleOrVehicle(pathName, obstVehic, dfct);
                callNxtObj += rand() % 50 + 30;
            }
            if(!bullets.empty())
            {
                moveBullet(bullets, ptrTrack);
            }
            if(isShootButtonDown())
            {
                createBullet(bullets, &player);
            }
            hitCounter(obstVehic, bullets, &player);
            movePlayerCar(&player, spd);
            putPlayerCarOnTrack(&player, ptrTrack);
            showTrack(ptrTrack);
            refresh();
            gVelocity += spd;
            ++counter;
            ++player.score;
            Sleep(90 / spd);
        }while((GetKeyState(VK_ESCAPE) >= 0) && !(isGameOver = isCarCrashed(obstVehic, &player)));
    }

    if(isGameOver)
    {
        gameOver(ptrTrack, &player);
    }

    endwin();

    destroyTrack(ptrTrack);

    return 0;
}
