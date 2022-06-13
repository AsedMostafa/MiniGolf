#include <iostream>
#include "SDL2/SDL.h"
#include "rsdl.hpp"
#include "mgolf.hpp"
#include "ball.hpp"
#include "wall.hpp"
#include "area.hpp"
#include "distance.hpp"
#include "pointholder.hpp"
#include "hole.hpp"
#include "utils.hpp"
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

const vector<string> commands = {"window_size", "normal_area", 
        "sand_area", "water_area", "ball", "hole", "sharp_wall", "wall"};

int whatIsTheCommand(string cmd) {
    int position{0};
    for(string c : commands){
        if(c == cmd){
            break;
        }
        position++;
    }
    return position;
}

vector<string> split(string str){
    stringstream line(str);
    vector<string> result;
    string tempStr;
    while (getline(line, tempStr, ' ')) {
        result.push_back(tempStr);
    }
    return result;
}



void getTheCommand(string map,MiniGolf* mini){
    fstream inputFile(map);
    vector<string> readFile;
    string lineHolder;
    while(getline(inputFile, lineHolder)){
        vector<string> cmdArgs = split(lineHolder);
        int command = whatIsTheCommand(cmdArgs[0]);
        mini->runTheCommand(command, cmdArgs);
    }

}


int main(int argc, char* argv[]){
    string map = argv[1];
    MiniGolf mini;
    getTheCommand(map, &mini);
    while(true){
        mini.update();
        mini.draw();
        delay(50);
    }
}