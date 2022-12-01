#ifndef _UNIT_H_
#define _UNIT_H_
#include "board.h"

class unit{
    int x, y;
    char blockType;
    Board *subBoard;
    bool occ;
  public:
    unit(int x, int y, char blockType, Board *subBoard, bool occ);
    ~unit();
    unit getUnit() const;
    void placePiece(char c);
    void removePiece();
};

#endif
