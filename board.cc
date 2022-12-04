// Header files
#include <vector>
#include "board.h"
#include "block.h"
#include "unit.h"
#include "level.h"
#include "levelZero.h"
#include "levelOne.h"
#include "levelTwo.h"
#include "levelThree.h"
#include "levelFour.h"
#include <iostream>

using namespace std;

// build() initiates board elements
void Board::build() {
    if (mainBoard.size() != 0) mainBoard.clear(); // If there exists a previous board
    cout << "b1" << endl;
    // fill up the board
    
    for (int i = 0; i < height; i++) {
        cout << "b2" << endl;
        vector<Unit> row;
        cout << "b2.1" << endl;
        mainBoard.emplace_back(row);
        cout << "b2.2" << endl;
        for (int j = 0; j < width; j++) {
            cout << "b2.3" << endl;
            mainBoard[i].emplace_back(Unit(i, j, ' ', this, false, nullptr)); // problem here
            cout << "b2.4" << endl;
        }
    }
    cout << "b3" << endl;
    notifyObservers();
    cout << "b4" << endl;
}

// Board Constructor
Board::Board(int width, int height, int level) : width{width}, height{height}, hiScore{0}, curScore{0}, level{level}, blind{false}, heavy{false}, force{false}, withEffect{false}, curBlock{nullptr}, nextBlock{nullptr}, curLevel{nullptr} {
    cout << "board ctor" << endl;
	this->build();
    cout << "after board ctor" << endl;

    // potential problem with ctor
}

// Board Destructor
Board::~Board() {
    delete curBlock;
    delete nextBlock;
    delete curLevel;
}

// Places a specific unit piece at coordinates (x, y)
void Board::placePiece(int x, int y, char type, Block* block) {        ///////////////////////////////////////////////////////////// what is this function for and when do we ever need it?
    Unit &temp = mainBoard[x][y];
    temp.placePiece(type, block);
}

// Removes the specific unit at coordinates (x, y)
void Board::removePiece(int x, int y) {                             ///////////////////////////////////////////////////////////// what is this function for and when do we ever need it?
    Unit &temp = mainBoard[x][y];
	temp.placePiece(' ', nullptr);
}

// Adds Block to the vector of placed blocks
//void Board::placeBlock(Block& block) {
//    placedBlocks.emplace_back(block);
    ////
//}

void Board::reset() {
    curScore = 0;

    this->blind = false;
    this->heavy = false;
    this->force = false;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            mainBoard[i][j].removePiece();
        }
    }

    ///////////////////////////////////////////////////////////        ***Reset Level 4 Counter Here***                 ////////////////////////////////////////////////////////

    delete curBlock;
    delete nextBlock;

    placedBlocks.clear();
    notifyObservers();
}

bool Board::checkFilledRow(int index) {
    bool filled = true;

    for (int i = 0; i < width; i++) {
        if (!mainBoard[curBlock->getY() + index][i].getOcc()) {
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

                // subtracting blockNum from all the blocks in that row
                for(int j=0; j<width; j++){
                    int newBlockNum = mainBoard[i][j].getUnitBlock()->getblockNum() - 1;
                    mainBoard[i][j].getUnitBlock()->setBlockNum(newBlockNum);
                    // Check if entire block is cleared and update score
                    if(newBlockNum == 0){
                        curScore += (mainBoard[i][j].getUnitBlock()->getlevelGen()+1) * (mainBoard[i][j].getUnitBlock()->getlevelGen()+1);
                        notifyObservers();
                    }
                }

                // Shift rows down
                for (int i = shift; i > 0; i--) {
                    for (int j = 0; j < width; j++) {
                        if (mainBoard[i][j].getOcc()) { 
                            mainBoard[i+1][j].placePiece(mainBoard[i][j].getBlockType(), mainBoard[i][j].getUnitBlock());
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
        notifyObservers();
        ///////////////////////////////////////////////////////////        ***Reset Level 4 Streak Here***                 ////////////////////////////////////////////////////////

        // for (int i = 0; i < placedBlocks.size(); i++) {
        //     for (int j = 0; j < 4; j++) {
        //         placedBlocks[i][j].setY(placedBlocks[i][j].getY() + total);
        //     }
        // }
    }

    //////////////////////////////////////////////////////////         ***Increase Streak for Level 4***           /////////////////////////////////////////////////////

    delete curBlock;
    if(total > 1) withEffect = true;
    notifyObservers();
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
                if (mainBoard[y][x].getOcc()) { 
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
                    if (mainBoard[y][x].getOcc()) return false; 
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
                mainBoard[curBlock->getX()+i+hShift][curBlock->getY()+j+vShift].placePiece(here, nullptr);
            }
        }
    }
    //remove block pointer to unit
    for(int i=0; i<11; i++){
        for(int j=0; j<15; j++){
            if(mainBoard[i][j].getUnitBlock()==curBlock){
                mainBoard[i][j].removePiece();    
            }
        }
    }

    curBlock->setX(curBlock->getX() + hShift);
	curBlock->setY(curBlock->getY() + vShift);
	curBlock->setRotation(finalRotation);
    // add block pointer to unit
    for(int i=0; i<11; i++){
        for(int j=0; j<15; j++){
            for(int k=0; k<3; k++){
                //if the mainBoard position is equal to the curent block position
                int blockSegPositionX = curBlock->getPositionVector()[finalRotation][k][0]+curBlock->getX()-1;
                int blockSegPositionY = curBlock->getPositionVector()[finalRotation][k][1]+curBlock->getX()-1;
                int unitPositionX = mainBoard[i][j].getX();
                int unitPositionY = mainBoard[i][j].getY();
                if(blockSegPositionX==unitPositionX &&  blockSegPositionY==unitPositionY){ 
                    //set that unit to point to curBlock
                    mainBoard[i][j].placePiece(curBlock->getType(), curBlock);  
                }
            }
        }
    }
    notifyObservers();
}

bool Board::isBlind() {return blind;}

int Board::getHiScore() {return hiScore;}
Level* Board::getCurLevel() {return curLevel;}
int Board::getLevel() { return level; }
int Board::getCurScore() {return curScore;}
Block* Board::getCurBlock() {return curBlock;}
void Board::setCurBlock(Block* curBlock) {this->curBlock = curBlock;}
void Board::setNextBlock(Block* nextBlock) {
        this->nextBlock = nextBlock;
        //notify();
}
vector<vector<Unit>> Board::getBoard() { return mainBoard; }
Block* Board::getNextBlock() { return nextBlock; }

void Board::setCurLevel(int setLevel, bool rand, string sequenceFile) {
    delete curLevel;
    if (setLevel == 0) {
        curLevel = new LevelZero(sequenceFile);
    } else if (setLevel == 1) {
        curLevel = new LevelOne();
    } else if (setLevel == 2) {
        curLevel = new LevelTwo();
    } else if (setLevel == 3) {
        curLevel = new LevelThree(rand, sequenceFile);
    } else if (setLevel == 4) {
        curLevel = new LevelFour(rand, sequenceFile);
    }
    this->level = setLevel;
    notifyObservers();
}
