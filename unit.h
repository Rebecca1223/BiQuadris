#ifndef _UNIT_H_
#define _UNIT_H_
#include "board.h"

class Board;

class unit : public Subject {
    int x, y;
    char blockType;
    Board *subBoard;
    bool occ;
  public:
    unit(int x, int y, char blockType, Board *subBoard, bool occ);
    ~unit();

    void placePiece(char c);
    void removePiece();

    bool getOcc();

    char getBlockType();
};

#endif
