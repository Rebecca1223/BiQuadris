// Header files
#include <vector>
#include "board.h"
#include "block.h"
#include "unit.h"
#include "level.h"
#include "levelzero.h"
#include "levelone.h"
#include "leveltwo.h"
#include "levelthree.h"

using namespace std;

// build() initiates board elements
void Board::build() {
    if (mainBoard.size() != 0) mainBoard.clear(); // If there exists a previous board

    // fill up the board
    vector<Unit> row;
    for (int i = 0; i < height; i++) {
        mainBoard.emplace_back(row);
        for (int j = 0; j < width; j++) {
            mainBoard[i].emplace_back(Unit(i, j, ' ', this, false));
        }
    }
}

// Board Constructor
Board::Board(int width, int height, int level) : width{width}, height{height}, hiScore{0}, curScore{0}, level{level}, blind{false}, heavy{false}, force{false}, withEffect{false}, curBlock{nullptr}, nextBlock{nullptr}, curLevel{nullptr} {
	this->build();
}

// Board Destructor
Board::~Board() {
    delete curBlock;
    delete nextBlock;
    delete curLevel;
}

// Places a specific unit piece at coordinates (x, y)
void Board::placePiece(int x, int y, char type) {
    Unit &temp = mainBoard[x][y];
    temp.placePiece(type);
}

// Removes the specific unit at coordinates (x, y)
void Board::removePiece(int x, int y) {
    Unit &temp = mainBoard[x][y];
	temp.placePiece(' ');
}

// Adds Block to the vector of placed blocks
void Board::placeBlock(Block& block) {
    placedBlocks.emplace_back(block);
}

void Board::reset() {
    curScore = 0;

    this->setBlind(false);
    this->setHeavy(false);
    this->setForce(false);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            mainBoard[i][j].removePiece();
        }
    }

    ///////////////////////////////////////////////////////////        ***Reset Level 4 Counter Here***                 ////////////////////////////////////////////////////////

    delete curBlock;
    delete nextBlock;

    placedBlocks.clear();
}

bool Board::checkFilledRow(int index) {
    bool filled = true;

    for (int i = 0; i < width; i++) {
        if (true) { /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// the unit is unoccupied
            filled = false;
            break;
        }
    }

    return filled;
}

void Board::removeRow() {
    int total = 0;

    for (int i = 0; i < 4; i++) {
        if (curBlock->getY() + i < height) {
            bool complete = checkFilledRow(i);
            if (complete) {
                int shift = curBlock->getY() + i - 1;
                total++;

                // Check if entire block is cleared

                // Shift rows down
                for (int i = shift; i > 0; i--) {
                    for (int j = 0; j < width; j++) {
                        if (true) { //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// the mainBoard[i][j] unit is occupied
                            // mainBoard[i+1][j].placePiece(mainBoard[i][j].getInfo().piece)
                        } else {
                            mainBoard[i+1][j].removePiece();
                        }
                    }
                }

                for (int i = 0; i < width; i++) {
                    mainBoard[0][i]. removePiece();
                }
            }
        }
    }

    if (total > 0) {
        curScore = curScore + ((level + total) * (level + total));
        //notify();
        ///////////////////////////////////////////////////////////        ***Reset Level 4 Streak Here***                 ////////////////////////////////////////////////////////

        for (int i = 0; i < placedBlocks.size(); i++) {
            for (int j = 0; j < 4; j++) {
                placedBlocks[i][j].setY(placedBlocks[i][j].getY() + total);
            }
        }
    }

    //////////////////////////////////////////////////////////         ***Increase Streak for Level 4***           /////////////////////////////////////////////////////

    delete curBlock;
    if(total > 1) withEffect = true;
}

int Board::getLevel(){
    return level;
}

bool Board::itsValid(int hShift, int vShift, int rotation) {
    ///////////////////////////////////////////////////////////        ***Level 4 Streak Counter Here***                 ////////////////////////////////////////////////////////

    int reducedRotation = (curBlock->getRotation() + rotation) % 4;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int x = curBlock->getX() + hShift + j;
            int y = curBlock->getY() + vShift + i;
            char here = curBlock->getVector()[reducedRotation][i][j];

            if (here != ',') {
                // Check if block exists
                if (true) { ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// the unit is occupied
                    if (curBlock->getVector()[curBlock->getRotation()][i + y][j + x] == ',') return false;
                    if (y < curBlock->getY() || x < curBlock->getX() || y > 3 + curBlock->getY() || x > 3 + curBlock->getX()) return false;
                }

                // Check if it goes off board
                if (y < 0 || x < 0 || y > height || x > width) return false;
            }
        }
    }

    if (rotation == 0 && hShift == 0 && vShift == 0) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                char here = curBlock->getVector()[curBlock->getRotation()][i][j];
                int x = curBlock->getX() + j;
                int y = curBlock->getY() + i;

                if (here != ',') {
                    if (true) return false; //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// the mainBoard[y][x] unit is unoccupied
                    if (x < 0 || y < 0 || y > height || x > width) return false;
                }
            }
        }
    }

    return true;
}

//moves the block on the board, given horizontal shift, vertical shift, and rotation
void Board::moveBlockInBoard(int hShift, int vShift, int rotation){
    // calculate the rotation
    int finalRotation = (curBlock->getRotation() + rotation) % 4;

    // check every space in block vector
    for(int i=0; i<4; i++){
        for (int j = 0; j < 4; j++) {
            // to get the value at the index so we can put that on the board
            char here = curBlock->getVector()[finalRotation][i][j];
            //if a value exist, we place that on the board
            if(here != ','){
                mainBoard[curBlock->getX()+i+hShift][curBlock->getY()+j+vShift].placePiece(here);
            }
        }
    }
    curBlock->setX(curBlock->getX() + hShift);
	curBlock->setY(curBlock->getY() + vShift);
	curBlock->setRotation(finalRotation);
}

int Board::getHiScore() {return hiScore;}
int Board::getCurLevel() {return level;}
int Board::getCurScore() {return curScore;}
Block *Board::getCurBlock() {return curBlock;}
