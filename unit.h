#ifndef _UNIT_H_
#define _UNIT_H_
class Board;
class Block;

class Unit{
    int x, y;
    char blockType;
    bool occ;
    Block *unitBlock;
  public:
    Unit(int x, int y, char blockType, bool occ, Block *unitBlock);
    ~Unit();
    Unit getUnit() const;
    void placePiece(char c, Block *unitBlock);
    void removePiece();

    bool getOcc();
    char getBlockType();

    int getX();
    int getY();
    Block *getUnitBlock();
};

#endif
