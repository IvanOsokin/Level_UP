#ifndef SURROUNDINGS_H
#define SURROUNDINGS_H
#include <curses.h>

chtype** createTrack();
void     destroyTrack(chtype** ptrTrack);
void     initTrack();
void     showTrack(chtype** ptrTrack);
void     moveTrack(chtype** ptrTrack, const int* vel);

#endif // SURROUNDINGS_H
