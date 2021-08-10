#ifndef CONSOLE_H
#define CONSOLE_H
#include <windows.h>

//constexpr short windowWidth = 131;
//constexpr short windowHeight = 41;
//constexpr short actualWindowWidth = windowWidth - 2;
//constexpr short actualWindowHeight = windowHeight - 1;

enum colors_enum
{
    Black = 0,
    Red = FOREGROUND_RED,
    Green = FOREGROUND_GREEN,
    Blue = FOREGROUND_BLUE,
    Grey = FOREGROUND_INTENSITY,
    LightGrey = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    White = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    Cyan = FOREGROUND_GREEN | FOREGROUND_BLUE,
    Purple = FOREGROUND_RED | FOREGROUND_BLUE,
    LightBlue = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    LightGreen = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    LightCyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    LightRed = FOREGROUND_RED | FOREGROUND_INTENSITY,
    LightPurple = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    Orange = FOREGROUND_RED | FOREGROUND_GREEN,
    Yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
};

void goToXY(HANDLE hStdOut, const int x, const int y);
void hideCursor(HANDLE hStdOut);
void setColor(HANDLE hStdOut, WORD attribute);
void setWindow(HWND hWnd, HANDLE hStdOutd, const short wWidth, const short wHeight);

#endif // CONSOLE_H
