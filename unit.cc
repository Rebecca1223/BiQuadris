#include "board.h"
#include "unit.h"

unit::unit(int x, int y, char blockType, Board *subBoard, bool occ) : x{x}, y{y}, blockType{blockType}, subBoard{subBoard}, occ{occ} {}

unit::~unit(){
    delete subBoard;
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

bool unit::getOcc() {
    return occ;
}

char unit::getBlockType() {
    return blockType;
}
