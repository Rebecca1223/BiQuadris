#include "board.h"
#include "unit.h"

Unit::Unit(int x, int y, char blockType, Board *subBoard, bool occ) : x{x}, y{y}, blockType{blockType}, subBoard{subBoard}, occ{occ}{}

Unit::~Unit(){
    delete subBoard;
}

void unit::placePiece(char c){
    occ = true;
    blockType = c;
    //notify();
}

void Unit::removePiece(){
    occ = false;
    blockType = ' ';
    //notify();
}

bool unit::getOcc() {
    return occ;
}

char unit::getBlockType() {
    return blockType;
}
