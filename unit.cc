#include "board.h"
#include "unit.h"

Unit::Unit(int x, int y, char blockType, Board *subBoard) : x{x}, y{y}, blockType{blockType}, subBoard{subBoard}{}

Unit::~Unit(){
    delete subBoard;
}

unit unit::getUnit() const{
    return unit(x, y, blockType, subBoard, occ);
}

void unit::placePiece(char c){
    occ = true;
    blockType = c;
    //notify();
}

void unit::removePiece(){
    occ = false;
    blockType = ' ';
    //notify();
}
