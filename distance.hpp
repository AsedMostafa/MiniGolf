#ifndef DISTANCE_H
#define DISTANCE_H

#include "rsdl.hpp"

class Distance{
public:
    Distance(Point, Point);
    double getXDistance();
    double getYDistance();
    double getDistance();
    bool isXExeeds();
    bool isYExeeds();
    int isPositive(double);

private:
    Point curr;
    Point prev;
    double maxTensionRadius = 100;
};

#endif