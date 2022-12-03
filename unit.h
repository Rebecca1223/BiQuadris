#ifndef _UNIT_H_
#define _UNIT_H_
class Board;

class Unit{
    int x, y;
    char blockType;
    Board *subBoard;
    bool occ;
    Block *unitBlock;
  public:
    Unit(int x, int y, char blockType, Board *subBoard, bool occ, Block *unitBlock);
    ~Unit();
    Unit getUnit() const;
    void placePiece(char c, Block *unitBlock);
    void removePiece();

    bool getOcc();
    char getBlockType();

    int getX();
    int getY();
    Block *getUnitBlock();
    //void setUnitBlock(Block *unitBlock);
    //void removeUnitBlock();
};

#endif
