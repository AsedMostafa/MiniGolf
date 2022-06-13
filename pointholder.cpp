#include "pointholder.hpp"

void pointHolder::setPrev(Point p){prev = p;};
void pointHolder::setCurr(Point p){curr = p;};
void pointHolder::setMovin(Point p){movin = p;};
void pointHolder::setMovin(bool t){isMoving = t;};
void pointHolder::setClicked(bool t){isClicked = t;};