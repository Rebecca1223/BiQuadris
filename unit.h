#ifndef _UNIT_H_
#define _UNIT_H_
class Board;

class Unit{
    int x, y;
    char blockType;
    Board *subBoard;
    bool occ;
  public:
    Unit(int x, int y, char blockType, Board *subBoard, bool occ);
    ~Unit();
    Unit getUnit() const;
    void placePiece(char c);
    void removePiece();

    bool getOcc();
    char getBlockType();

    int getX();
    int getY();
};

#endif
