#ifndef AREA_H
#define AREA_H
#include <string>
#include "rsdl.hpp"

using namespace std;

class Area{
public:
    virtual void setFriction() = 0;
    virtual void setBackground() = 0;
    virtual void setProp() = 0;
    virtual int getFriction() = 0;
    void draw(){mainWindow->draw_img(backGroundImg, whereIsIt);};
    Rectangle whereIsIt = Rectangle(0,0,0,0);
protected:
    int friction;
    string backGroundImg;
    Window* mainWindow;
};

class normalArea: public Area{
public:
    normalArea(Window* win, int x, int y, int w, int h){
        mainWindow = win;
        whereIsIt = Rectangle(x, y, w, h);
    }
    void setFriction(){friction = 1;};
    void setBackground(){backGroundImg = "./pic/grn.png";};
    void setProp(){
        setFriction();
        setBackground();
    }
    int getFriction(){return friction;}
};

class sandArea: public Area{
public:
    sandArea(Window* win, int x, int y, int w, int h){
        mainWindow = win;
        whereIsIt = Rectangle(x, y, w, h);
    }
    void setFriction(){friction = 2;};
    void setBackground(){backGroundImg = "./pic/sand.png";};
    void setProp(){
        setFriction();
        setBackground();
    }
    int getFriction(){return friction;}
};

class waterArea: public Area{
public:
    waterArea(Window* win, int x, int y, int w, int h){
        whereIsIt = Rectangle(x, y, w, h);
        mainWindow = win;
    }
    void setFriction(){friction = 0;};
    void setBackground(){backGroundImg = "./pic/water.png";};
    void setProp(){
        setFriction();
        setBackground();
    }
    int getFriction(){return friction;}
};

#endif