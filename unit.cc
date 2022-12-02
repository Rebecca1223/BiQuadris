#include "board.h"
#include "unit.h"

Unit::Unit(int x, int y, char blockType, Board *subBoard, bool occ) : x{x}, y{y}, blockType{blockType}, subBoard{subBoard}, occ{occ}{}

Unit::~Unit(){
    delete subBoard;
}

void Unit::placePiece(char c){
    occ = true;
    blockType = c;
    //notify();
}

void Unit::removePiece(){
    occ = false;
    blockType = ' ';
    //notify();
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
