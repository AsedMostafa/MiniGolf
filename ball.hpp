#ifndef BALL_h
#define BALL_h
#include "rsdl.hpp"
#include "area.hpp"
#include "distance.hpp"

class Ball{
public:
    Ball(Window* win, float _x, float _y);
    void update();
    void draw();
    void kickBall();
    void calculateVelocity(Distance);
    void setVelocity(Distance);
    void setArea(Area*);
    int x,y;
    int xVel, yVel = 0;
    Point centerPoint;
private:
    int maxVel = 20;
    Window* mainWindow;
    Area* area;
};

#endif