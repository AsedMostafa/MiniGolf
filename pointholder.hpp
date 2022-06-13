#ifndef PH_H
#define PH_H

#include "rsdl.hpp"

class pointHolder{
public:
    Point prev, movin, curr;
    bool isMoving = false;
    bool isClicked = false;
    void setPrev(Point p){prev = p;}
    void setCurr(Point p){curr = p;}
    void setMovin(Point p){movin = p;}
    void setMovin(bool t){isMoving = t;}
    void setClicked(bool t){isClicked = t;}
};

#endif