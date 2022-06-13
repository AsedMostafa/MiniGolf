#include "ball.hpp"
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

Ball::Ball(Window* win, float _x, float _y){
    mainWindow = win;
    y = _y;
    x = _x;
    centerPoint = Point(x,y); 
}

void Ball::setArea(Area* a){
    area = a;
}

void Ball::update(){
    x = xVel + x;
    y = yVel + y;
    if(xVel < 2 && xVel > -2){
        xVel = 0;
    }
    if(xVel > 0){
        xVel -= area->getFriction();
    }
    else if(xVel < 0){
        xVel += area->getFriction();
    }
    if(yVel < 2 && yVel > -2){
        yVel = 0;
    }
    if(yVel > 0){
        yVel -= area->getFriction();
    }
    else if(yVel < 0){
        yVel += area->getFriction();
    }
}

void Ball::draw(){
    centerPoint.x = x;
    centerPoint.y = y;
    mainWindow->fill_circle(centerPoint, 7);
}

void Ball::kickBall(){
    std::cout << "selam selam\n";
}


void Ball::setVelocity(Distance d){
    if(d.isXExeeds() && d.isYExeeds()){
        xVel = d.isPositive(d.getXDistance()) * maxVel;
        yVel = d.isPositive(d.getYDistance()) * maxVel;
    }
    if(!d.isXExeeds() && d.isYExeeds()){
        xVel = 0.2*d.getXDistance();
        yVel = d.isPositive(d.getYDistance()) * maxVel;
    }
    if(d.isXExeeds() && !d.isYExeeds()){
        xVel = d.isPositive(d.getXDistance()) * maxVel;
        yVel = 0.2*d.getYDistance();
    }
    if(!d.isXExeeds() && !d.isYExeeds()){
        xVel = 0.2*d.getXDistance();
        yVel = 0.2*d.getYDistance();
    }
}

void Ball::calculateVelocity(Distance d){
    setVelocity(d);
}