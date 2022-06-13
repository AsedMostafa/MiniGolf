#include "mgolf.hpp"

void MiniGolf::eventGeter(Window* win, pointHolder &pH){
    while(win->has_pending_event()){
        Event evn = win->poll_for_event();
        if(evn.get_type() == Event::KEY_PRESS && evn.get_pressed_key() == 'q')
            exit(0);
        eventHandler(evn, pH);
    }
}

void MiniGolf::setMainWindow(Window* win){
    mainGameWindow = win;
}
void MiniGolf::setWall(Wall* w){
    walls.push_back(w);
}

void MiniGolf::setArea(Area* a){
    areas.push_back(a);
}

void MiniGolf::setBall(Ball* b){
    ball = b;
}

void MiniGolf::setHole(Hole* h){
    hole = h;
}


void MiniGolf::drawWalls(){
    for(Wall* w:walls){
        w->draw();
    }
}

void MiniGolf::drawAreas(){
    for(Area* a:areas){
        a->setProp();
        a->draw();
    }
}
void MiniGolf::draw(){
    mainGameWindow->clear();
    drawAreas();
    drawWalls();
    hole->draw();
    ball->draw();
    mainGameWindow->update_screen();
}

bool IsAreaContain(Area* a, Ball* b){
    if((b->x > a->whereIsIt.x) && (b->x < (a->whereIsIt.x + a->whereIsIt.w)) && (b->y > a->whereIsIt.y) && (b->y < (a->whereIsIt.y + a->whereIsIt.h))){
        return true;
    }
    return false;
}

void MiniGolf::whereBallIs(){
    for(Area* a:areas){
        if(IsAreaContain(a, ball)){
            ball->setArea(a);
            if(a->getFriction() == 0){
                gameOver(mainGameWindow);
            }
            break;
        }
    }
}

void MiniGolf::update(){
    eventGeter(mainGameWindow, holderToCalcualate);
    if(released){
        for(Wall* w:walls){
            w->checkForCollision(ball);
        }
        whereBallIs();
        ball->update();
        if(hole->checkForBall(ball)){
            winingGame(mainGameWindow);
        }
    } 
}

void MiniGolf::eventHandler(Event ent, pointHolder &pH){
    if(isClicked(ent)){
        pH.setPrev(ent.get_mouse_position());
        released = false;
    }
    if(isMoving(ent)){
        pH.setMovin(ent.get_mouse_position());
        // this is important due to drawing bar
    }
    if(isReleased(ent)){
        pH.setCurr(ent.get_mouse_position());
        // kick the ball            
        Distance d(holderToCalcualate.prev, holderToCalcualate.curr);
        ball->calculateVelocity(d);
        released = true;

    }
}

void MiniGolf::runTheCommand(int cmd, vector<string> cmdArgs){
    switch (cmd) {
        case 0:{
            Window* win = new Window(stoi(cmdArgs[1]), stoi(cmdArgs[2]));
            setMainWindow(win);
            break;
        }
        case 1:{
            normalArea* Area = new normalArea(mainGameWindow, stoi(cmdArgs[1]),stoi(cmdArgs[2]),
                                        stoi(cmdArgs[3]),stoi(cmdArgs[4]));
            setArea(Area);
            break;
        }
        case 2:{
            sandArea* Area = new sandArea(mainGameWindow, stoi(cmdArgs[1]),stoi(cmdArgs[2]),
                                        stoi(cmdArgs[3]),stoi(cmdArgs[4]));
            setArea(Area);            
            break;
        }
        case 3:{
            waterArea* Area = new waterArea(mainGameWindow, stoi(cmdArgs[1]),stoi(cmdArgs[2]),
                                        stoi(cmdArgs[3]),stoi(cmdArgs[4]));
            setArea(Area);            
            break;
        }
        case 4:{
            Ball* b = new Ball(mainGameWindow, stoi(cmdArgs[1]), stoi(cmdArgs[2]));
            setBall(b);
            break;
        }
        case 5:{
            Hole* h = new Hole(mainGameWindow, stoi(cmdArgs[1]), stoi(cmdArgs[2]));
            setHole(h);
            break;
        }
        case 6:{
            sharpWall* shW = new sharpWall(mainGameWindow, stoi(cmdArgs[1]),stoi(cmdArgs[2]),
                                        stoi(cmdArgs[3]),stoi(cmdArgs[4]));
            setWall(shW);
            break;
        }
        case 7:{
            normalWall* nW  = new normalWall(mainGameWindow, stoi(cmdArgs[1]),stoi(cmdArgs[2]),
                                        stoi(cmdArgs[3]),stoi(cmdArgs[4]));
            setWall(nW);
            break;
        }
        default:
            break;
    }
}