#include "block.h"
#include <string>

Block::~Block() {}

Block::Block(int x, int y, int blockNum, int levelGen, char curRotation, bool actionHeavy, bool levelHeavy) : x{x}, y{y}, blockNum{blockNum}, levelGen{levelGen}, curRotation{curRotation}, actionHeavy{actionHeavy}, levelHeavy{levelHeavy}{}

void Block::rotate(){ // to the right
    if(curRotation == 'N'){
        curRotation = 'E';
    }else if(curRotation == 'E'){
        curRotation = 'S';
    }else if(curRotation == 'S'){
        curRotation = 'W';
    }else if(curRotation == 'W'){
        curRotation = 'N';
    }
    y+=3;
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
