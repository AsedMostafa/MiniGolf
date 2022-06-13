#include "hole.hpp"
#include "rsdl.hpp"

Hole::Hole(Window* w, int x, int y){
    whereIsIt.x = x;
    whereIsIt.y = y;
    win = w;
}

void Hole::draw(){
    win->fill_circle(whereIsIt, radius, BLACK);
}

bool Hole::checkForBall(Ball* b){
    Distance d(b->centerPoint, whereIsIt);
    if(d.getDistance() <= 9){
        return true;
    }
    return false;
}