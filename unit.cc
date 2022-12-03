#include "board.h"
#include "unit.h"

Unit::Unit(int x, int y, char blockType, Board *subBoard, bool occ, Block *unitBlock) : x{x}, y{y}, blockType{blockType}, subBoard{subBoard}, occ{occ}, unitBlock{nullptr}{}

Unit::~Unit(){
    delete subBoard;
}

void Unit::placePiece(char c, Block *unitBlock){
    occ = true;
    blockType = c;
    this->unitBlock = unitBlock;
    //notify();
}

void Unit::removePiece(){
    occ = false;
    blockType = ' ';
    this->unitBlock = nullptr;
    //notifyObservers();
}

bool Unit::getOcc() {
    return occ;
}

char Unit::getBlockType() {
    return blockType;
}

int Unit::getX() {
    return x;
}

int Unit::getY() {
    return y;
}

Block *Unit::getUnitBlock(){
    return unitBlock;
}

//void Unit::setUnitBlock(Block *unitBlock){
//    this->unitBlock = unitBlock;
//}

//void Unit::removeUnitBlock(){
//    this->unitBlock = nullptr;
//}
