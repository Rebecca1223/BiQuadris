#include "board.h"
#include "unit.h"

Unit::Unit(int x, int y, char blockType, Board *subBoard, bool occ) : x{x}, y{y}, blockType{blockType}, subBoard{subBoard}, occ{occ}{}

Unit::~Unit(){
    delete subBoard;
}

Unit Unit::getUnit() const{
    return Unit(x, y, blockType, subBoard, occ);
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
