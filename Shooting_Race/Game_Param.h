#ifndef GAME_PARAM_H
#define GAME_PARAM_H

constexpr short windowWidth = 131;
constexpr short windowHeight = 41;
constexpr short actualWindowWidth = windowWidth - 2;
constexpr short actualWindowHeight = windowHeight - 1;
constexpr short divisor = 60;
constexpr short trackWidth = actualWindowWidth - divisor;
constexpr short trackHeight = windowHeight;

constexpr short carWidth = 8;
constexpr short carHeight = 8;

constexpr short titleInitPointX = divisor / 2 + 2;
constexpr short titleInitPointY = 2;

//constexpr short bulletsLine = 1;

constexpr short baseDistBtwObstacles = 6;
constexpr int initCounter = 30;
constexpr int numberOfHit = 1;
constexpr int maxAmountOfScores = 10;
constexpr int startPosInTable = 7;

constexpr int controlDescriptionItem = 6;

enum Speed
{
    SLOW_SPD = 1,
    MEDIUM_SPD,
    FAST_SPD
};

enum Difficulty
{
    EASY_DFCT = 1,
    MEDIUM_DFCT,
    HARD_DFCT
};



#endif // GAME_PARAM_H
