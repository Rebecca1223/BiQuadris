#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "subject.h"
#include "unit.h"
#include "level.h"

class Board : public Subject {
    int hiScore, curScore, width, height, level, curBlock, nextBlock;
    bool blind, heavy, force, withEffect;
    Block* curBlock; // Pointer to current block
	Block* nextBlock; // Pointer to next block
	Level* curLevel;
    std::vector<Block> placedBlocks;
    std::vector<std::vector<Unit>> mainBoard;

    public:
        Board(int width, int height, int level);
        ~Board();

        void build();
        void reset();
        void placePiece(int x, int y, char type);
        void placeBlock(Block& block);
        void removePiece(int x, int y);
        void removeRow();
        void moveBlockInBoard(int hShift, int vShift, int rotation);
        void setCurBlock(Block* curBlock);
        void setNextBlock(Block* nextBlock);

        bool itsValid(int hShift, int vShift, int rotation);
        bool checkFilledRow(int index);
        bool isBlind();

        int getLevel();
        int getHiScore();
        int getCurLevel();
        int getCurScore();
        Block *getCurBlock();
        std::vector<std::vector<Unit>> getBoard();
};

#endif
