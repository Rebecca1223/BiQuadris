#include "board.h"
#include "unit.h"

unit::unit(int x, int y, char blockType, Board *subBoard) : x{x}, y{y}, blockType{blockType}, subBoard{subBoard}{}

unit::~unit(){
    delete subBoard;
}
