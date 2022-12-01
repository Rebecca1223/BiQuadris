#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "subject.h"
class Block;
class Unit;
class Level;

class Board : public Subject {
    int hiScore, curScore, width, height, curLevel, curBlock, nextBlock;
    bool blind, heavy, force, withEffect;
    Block* curBlock; // Pointer to current block
	Block* nextBlock; // Pointer to next block
	Level* curLevel;
    std::vector<Block> placedBlocks;
    std::vector<std::vector<Unit>> mainBoard;

    public:
        Board(int width, int height, int curLevel);
        ~Board();

        void build();
        void reset();
        void placePiece(int x, int y, char type);
        void placeBlock(Block& block);
        void removePiece(int x, int y);
        void removeRow();

        bool itsValid(int hShift, int vShift, int rotation);
        bool checkFilledRow();
};

#endif
