#include <stdio.h>
#include "Console.h"
#include "Game_Param.h"

void setWindow(HWND hWnd, HANDLE hStdOut, const short wWidth, const short wHeight)
{
    //Задание типа и размера шрифта в консоли
    CONSOLE_FONT_INFOEX fontInfo;
                fontInfo.cbSize     = sizeof(fontInfo);
                fontInfo.nFont      = 0;
                fontInfo.dwFontSize = {8, 11};
                fontInfo.FontFamily = FF_DONTCARE;
                fontInfo.FontWeight = 700;
        wcscpy( fontInfo.FaceName, L"Lucida Console");
    SetCurrentConsoleFontEx(hStdOut, false, &fontInfo);

    //Размер самого большого возможного заданного консольного окна
    const COORD tempWindowSize = GetLargestConsoleWindowSize(hStdOut);

    //Установка верхнего левого угла окна консоли
    //по координатам (((tempWindowSize.X - wWidth - 1) / 2) * fontInfo.dwFontSize.X), 10
    const COORD initPoint = {static_cast<short>(((tempWindowSize.X - wWidth - 1) / 2) * fontInfo.dwFontSize.X), 10};
    SetWindowPos(hWnd, HWND_TOP, initPoint.X, initPoint.Y, 300, 300, NULL);

    //Размер консольного окна
    const COORD windowSize = {wWidth, wHeight};
    SetConsoleScreenBufferSize(hStdOut, windowSize);

    //Установить размер и текущую позици окна консоли
    SMALL_RECT newConsoleWindow = {0,
                                   0,
                                   static_cast<short>(windowSize.X - 1),
                                   static_cast<short>(windowSize.Y - 1)};

    SetConsoleWindowInfo(hStdOut, true, &newConsoleWindow);
    //printf("maxX = %d, maxY = %d\n", tempWindowSize.X, tempWindowSize.Y);
    //printf("width = %d, height = %d", fontInfo.dwFontSize.X, fontInfo.dwFontSize.Y);

    //hideCursor(hStdOut);
}

void goToXY(HANDLE hStdOut, const int x, const int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(hStdOut, coord);
}

void hideCursor(HANDLE hStdOut)
{
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;

    SetConsoleCursorInfo(hStdOut, &cursorInfo);
}

/*void setColor(HANDLE hStdOut, WORD attribute)
{
    SetConsoleTextAttribute(hStdOut, attribute);
}*/
