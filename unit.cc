#include "unit.h"

Unit::Unit(int x, int y, char blockType, bool occ, Block *unitBlock) : x{x}, y{y}, blockType{blockType}, occ{occ}, unitBlock{nullptr}{}

Unit::~Unit(){}

void Unit::placePiece(char c, Block *unitBlock){
    occ = true;
    blockType = c;
    this->unitBlock = unitBlock;
}

void Unit::removePiece(){
    occ = false;
    blockType = ' ';
    this->unitBlock = nullptr;
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
