#ifndef UTILS_H
#define UTILS_H
#include "rsdl.hpp"

bool isClicked(Event);
bool isMoving(Event);
bool isReleased(Event);
void winingGame(Window*);
void gameOver(Window*);

#endif