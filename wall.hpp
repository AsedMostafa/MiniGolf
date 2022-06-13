#ifndef WALL_H
#define WALL_H
#include "rsdl.hpp"
#include "ball.hpp"
#include "utils.hpp"

using namespace std;

class Wall{
public:
    virtual void draw() = 0;
    void setProp(Window*, int, int, int, int);
    virtual void checkForCollision(Ball* b) = 0;
protected:
    bool isColidedFromLeft(Ball* b);
    bool isColidedFromRight(Ball* b);
    bool isColidedFromTop(Ball* b);
    bool isColidedFromBottom(Ball* b);
    int width;
    int height;
    Point corner;
    Rectangle whereIsTheWall = Rectangle(0, 0, 0, 0);
    Window* mainWindow;
};

class normalWall: public Wall{
public:
    normalWall(Window* win, int x, int y, int w, int h){setProp(win, x, y, w, h);};
    void draw();
    void checkForCollision(Ball* b);
    void reflect(Ball* ball);
};

class sharpWall: public Wall{
public:
    sharpWall(Window* win, int x, int y, int w, int h){setProp(win, x, y, w, h);};
    void draw();
    void checkForCollision(Ball* b);
};

#endif