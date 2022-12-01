#include "board.h"
#include "unit.h"

unit::unit(int x, int y, char blockType, Board *subBoard, bool occ) : x{x}, y{y}, blockType{blockType}, subBoard{subBoard}, occ{occ} {}

unit::~unit(){
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
