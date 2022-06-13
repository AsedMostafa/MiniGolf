#ifndef MINIGOLF_H
#define MINIGOLF_H

#include "rsdl.hpp"
#include "ball.hpp"
#include "wall.hpp"
#include "hole.hpp"
#include "utils.hpp"
#include "pointholder.hpp"
#include "area.hpp"
#include <vector>
#include <string>

class MiniGolf{
public:
    void eventGeter(Window*, pointHolder &ph);
    void runTheCommand(int, vector<string>);
    void setMainWindow(Window*);
    void setWall(Wall*);
    void setArea(Area*);
    void setBall(Ball*);
    void setHole(Hole*);
    void drawWalls();
    void drawAreas();
    void draw();
    void update();
    void eventHandler(Event, pointHolder &pH);
    void whereBallIs();
private:
    Window* mainGameWindow;
    Ball* ball;
    Hole* hole;
    vector<Wall*> walls;
    pointHolder holderToCalcualate;
    bool released = false;
    vector<Area*> areas;
};

#endif