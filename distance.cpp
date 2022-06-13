#include "distance.hpp"
#include "rsdl.hpp"

Distance::Distance(Point _curr, Point _prev){
        curr = _curr;
        prev = _prev;
    }

double Distance::getXDistance(){
    float prevX = prev.x;
    float currX = curr.x;
    return currX - prevX;
}

double Distance::getYDistance(){
    float prevY = prev.y;
    float currY = curr.y;
    return currY - prevY;
}
double Distance::getDistance(){
    double distance = sqrt(pow(getXDistance(),2) + pow(getYDistance(),2));
    return distance;
}

bool Distance::isXExeeds(){
    if(getXDistance() > maxTensionRadius || getXDistance() < -maxTensionRadius){
        return true;
    }
    return false;
}

bool Distance::isYExeeds(){
    if(getYDistance() > maxTensionRadius || getYDistance() < -maxTensionRadius){
        return true;
    }
    return false;
}

int Distance::isPositive(double k){
    if(k >= 0){
        return 1;
    }
    return -1;
}