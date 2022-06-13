#include "wall.hpp"

using namespace std;

void Wall::setProp(Window* win, int xCor, int yCor, int _w, int _h){
    mainWindow = win;
    width = _w;
    height = _h;
    corner = Point(xCor, yCor);
}

void normalWall::draw(){
    whereIsTheWall = Rectangle(corner, width, height);
    mainWindow->fill_rect(whereIsTheWall, RGB(150, 75, 0));
}

void sharpWall::draw(){
    whereIsTheWall = Rectangle(corner, width, height);
    mainWindow->fill_rect(whereIsTheWall, RED);
}

bool Wall::isColidedFromRight(Ball* b){
    if((b->x > whereIsTheWall.x + whereIsTheWall.w) && (b->x < whereIsTheWall.x + whereIsTheWall.w + 15) && (b->y > (whereIsTheWall.y - 15)) &&
        (b->y < (whereIsTheWall.y + whereIsTheWall.h + 15))){
            return true;
    }
    return false;
}

bool Wall::isColidedFromLeft(Ball* b){
    if((b->x < whereIsTheWall.x) && (b->x > whereIsTheWall.x - 15) && (b->y > (whereIsTheWall.y - 15)) &&
        (b->y < (whereIsTheWall.y + whereIsTheWall.h + 15))){
            return true;
    }
    return false;
}

bool Wall::isColidedFromTop(Ball* b){
    if((b->y > whereIsTheWall.y - 15) && (b->y < whereIsTheWall.y) && 
    (b->x > whereIsTheWall.x - 15) && (b->x < whereIsTheWall.x + whereIsTheWall.w + 15)){
        return true;
    }
    return false;

}

bool Wall::isColidedFromBottom(Ball* b){
    if((b->y > whereIsTheWall.y + whereIsTheWall.h) && (b->y < whereIsTheWall.y + whereIsTheWall.h + 15)
     && (b->x > whereIsTheWall.x - 15) && (b->x < whereIsTheWall.x + whereIsTheWall.w + 15)){
        return true;
    }
    return false;
}

void normalWall::checkForCollision(Ball* b){
    reflect(b);
}


void sharpWall::checkForCollision(Ball* b){
    if(isColidedFromBottom(b) || isColidedFromTop(b) || isColidedFromRight(b) || isColidedFromLeft(b)){
        gameOver(mainWindow);
    }
}

void normalWall::reflect(Ball* b){
    if((isColidedFromRight(b) && b->xVel < 0)|| (isColidedFromLeft(b) && b->xVel > 0)){
        b->xVel = -b->xVel;
    }
    if((isColidedFromTop(b) && b->yVel > 0) || (isColidedFromBottom(b) && b->yVel < 0)){
        b->yVel = -b->yVel;
    }
}