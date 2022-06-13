#ifndef HOLE_H
#define HOLE_H

#include "rsdl.hpp"
#include "ball.hpp"

class Hole{
public:
    Hole(Window* w, int x, int y);
    void draw();
    bool checkForBall(Ball* b);
private:
    Point whereIsIt;
    Window* win;
    int radius = 12;
};

#endif
