#include "block.h"
#include <string>
#include <vector>

Block::~Block() {}

Block::Block(int x, int y, int blockNum, int levelGen, char curRotation, bool actionHeavy, bool levelHeavy) : x{x}, y{y}, blockNum{blockNum}, levelGen{levelGen}, curRotation{curRotation}, actionHeavy{actionHeavy}, levelHeavy{levelHeavy}{}

void Block::cwrotate(){ // clockwise
    if(curRotation == 'N'){
        curRotation = 'E';
    }else if(curRotation == 'E'){
        curRotation = 'S';
    }else if(curRotation == 'S'){
        curRotation = 'W';
    }else if(curRotation == 'W'){
        curRotation = 'N';
    }
}

void Block::ccwrotate(){ // counterclockwise
    if(curRotation == 'N'){
        curRotation = 'W';
    }else if(curRotation == 'E'){
        curRotation = 'N';
    }else if(curRotation == 'S'){
        curRotation = 'E';
    }else if(curRotation == 'W'){
        curRotation = 'S';
    }
}

void Block::moveHorz(std::string dir){
    if(dir == "right"){
        x+=1;
    }else{
        x-=1;
    }
}

void Block::down(){
    y-=1;
}

void Block::drop(){
    // i feel like this should be a while loop in main
    // while the move is valid, move the block down
}

int Block::getX(){
    return x;
}

int Block::getY(){
    return y;
}

int Block::getblockNum(){
    return blockNum;
}
char Block::getRotation(){
    return curRotation;
}

//if player does heavy, setActionHeavy for the block. if actionHeavy=true and moveHorz, the
void Block::setActionHeavy(){
    actionHeavy = true;
}

void Block::setLevelHeavy(){
    levelHeavy = true;
}
