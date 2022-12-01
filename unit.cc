#include "board.h"
#include "unit.h"

Unit::Unit(int x, int y, char blockType, Board *subBoard) : x{x}, y{y}, blockType{blockType}, subBoard{subBoard}{}

Unit::~Unit(){
    delete subBoard;
}
