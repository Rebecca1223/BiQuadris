#ifndef _UNIT_H_
#define _UNIT_H_
class Board;

class Unit {
    int x, y;
    char blockType;
    Board *subBoard;
  public:
    Unit(int x, int y, char blockType, Board *subBoard);
    ~Unit();
};

#endif
