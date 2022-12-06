#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "subject.h"
#include "unit.h"
#include "level.h"
class Block;
class Unit;
class Level;

class Board : public Subject {
    int hiScore, curScore, width, height, level, placedBlocks;
    bool blind, heavy, force, withEffect;
    Block* curBlock; // Pointer to current block
	Block* nextBlock; // Pointer to next block
	Level* curLevel;
    std::vector<std::vector<Unit>> mainBoard;

    public:
        Board(int width, int height, int level);
        ~Board();

        void build();
        void reset();
        void placePiece(int x, int y, char type, Block* block);
        //void placeBlock(Block& block);
        void removePiece(int x, int y);
        void removeBlock();
        void removeRow(int row);
        void moveBlockInBoard(int hShift, int vShift, int rotation);
        void setCurBlock(Block* curBlock);
        void setNextBlock(Block* nextBlock);

        bool itsValid(int hShift, int vShift, int rotation);
        bool checkFilledRow(int index);

        int getHiScore();
        Level* getCurLevel();
        int getLevel();
        int getCurScore();
        Block* getCurBlock();
        std::vector<std::vector<Unit>> getBoard();
        Block* getNextBlock();
        void setCurLevel(int level, bool rand, int state, string sequenceFile = "");
        bool getHeavy();
        bool getForce();
        bool getBlind();
        void setHeavy(bool heavy);
        void setForce(bool force);
        void setBlind(bool blind);
        int getPlacedBlocks();
        void addPlacedBlocks();
};

#endif
