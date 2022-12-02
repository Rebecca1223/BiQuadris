#include "block.h"
#include <string>
#include <vector>

Block::~Block() {}

Block::Block(int x, int y, int blockNum, int levelGen, int curRotation, bool actionHeavy, bool levelHeavy): x{x}, y{y}, blockNum{blockNum}, levelGen{levelGen}, curRotation{curRotation}, actionHeavy{actionHeavy}, levelHeavy{levelHeavy} {}

void Block::cwrotate(){ // clockwise
    if(curRotation == 3){
        curRotation = 0;
    }else{
        curRotation+=1;
    }
}

void Block::ccwrotate(){ // counterclockwise
    if(curRotation == 0){
        curRotation = 3;
    }else{
        curRotation-=1;
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

int Block::getX(){
    return x;
}

void Block::setX(int x){
    this->x = x;
}

int Block::getY(){
    return y;
}

void Block::setY(int y){
    this->y = y;
}

int Block::getblockNum(){
    return blockNum;
}

void Block::setBlockNum(int blockNum){
    this->blockNum = blockNum;
}

int Block::getRotation(){
    return curRotation;
}

void Block::setRotation(int rotation){
    this->curRotation = curRotation;
}

bool Block::getActionHeavy(){
    return actionHeavy;
}

//if player does heavy, setActionHeavy for the block. if actionHeavy=true and moveHorz, the
void Block::setActionHeavy(){
    actionHeavy = true;
}

void Block::setLevelHeavy(){
    levelHeavy = true;
}
