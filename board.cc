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
#include <string>

using namespace std;

// build() initiates board elements
void Board::build() {
    if (mainBoard.size() != 0) mainBoard.clear(); // If there exists a previous board
    // fill up the board
    
    for (int i = 0; i < height; i++) {
        vector<Unit> row;
        mainBoard.emplace_back(row);
        for (int j = 0; j < width; j++) {
            mainBoard[i].emplace_back(Unit(i, j, ' ', false, nullptr)); // problem here
        }
    }
    notifyObservers();
}

// Board Constructor
Board::Board(int width, int height, int level) : width{width}, height{height}, hiScore{0}, curScore{0}, level{level}, placedBlocks{0}, blind{false}, heavy{false}, force{false}, withEffect{false}, curBlock{nullptr}, nextBlock{nullptr}, curLevel{nullptr} {
	this->build();
}

// Board Destructor
Board::~Board() {
    delete curBlock;
    delete nextBlock;
    delete curLevel;
}

// Places a specific unit piece at coordinates (x, y)
void Board::placePiece(int x, int y, char type, Block* block) {        
    Unit &temp = mainBoard[x][y];
    temp.placePiece(type, block);
}

// Removes the specific unit at coordinates (x, y)
void Board::removePiece(int x, int y) {                             
    Unit &temp = mainBoard[x][y];
	temp.placePiece(' ', nullptr);
}

// Removes a complete Block
void Board::removeBlock(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            int tempRot = curBlock->getRotation();
            char tempVal = curBlock->getVector()[tempRot][i][j];
            
            if (tempVal != ','){
                mainBoard[i+curBlock->getY()][j+curBlock->getX()].removePiece();
            }
        }
    }
}

// Set board state to default
void Board::reset() {
    curScore = 0;

    this->setBlind(false);
    this->setForce(false);
    this->setHeavy(false);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            mainBoard[i][j].removePiece();
        }
    }

    delete curBlock;
    delete nextBlock;
    
}

// Checks whether a row is filled and needs to be cleared. Returns true if it is filled and false otherwise
bool Board::checkFilledRow(int index) {
    bool filled = true;

    for (int i = 0; i < width; i++) {
        if (!mainBoard[index][i].getOcc()) {
            filled = false;
            break;
        }
    }

    return filled;
}

// Clears a horizontal row at row from the board
void Board::removeRow(int row) {
    int total = 0;
    int shift = row - 1;
    total++;

    // subtracting blockNum from all the blocks in that row
    for(int j=0; j<width; j++){
        int newBlockNum = mainBoard[row][j].getUnitBlock()->getblockNum() - 1;
        mainBoard[row][j].getUnitBlock()->setBlockNum(newBlockNum);
        // Check if entire block is cleared and update score
        if(newBlockNum == 0){
            curScore += (mainBoard[row][j].getUnitBlock()->getlevelGen()+1) * (mainBoard[row][j].getUnitBlock()->getlevelGen()+1);
            if (curScore > hiScore){
                hiScore = curScore;
            }
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

    if (total > 0) {
        curScore = curScore + ((level + total) * (level + total));
        if (curScore > hiScore){
            hiScore = curScore;
        }
    }
}

// Checks whether a move with horizontal shift of hShift, vertial shift of vShift, and roation of rotation is a valid move
//      A valid move consists of the block being able to be placed inside the board within the board perimeter constraints
bool Board::itsValid(int hShift, int vShift, int rotation) {
    int reducedRotation = (curBlock->getRotation() + rotation) % 4;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int x = curBlock->getX() + hShift + j;
            int y = curBlock->getY() + vShift + i;
            
            char here = curBlock->getVector()[reducedRotation][i][j];
            if (here != ',') {
                // Check if it goes off board
                if (y < 0 || x < 0 || y >= height || x >= width){
                    return false;
                }
                // Check if block exists
                if (mainBoard[y][x].getOcc()) { 
                    if (y < curBlock->getY() || x < curBlock->getX() || y > 3 + curBlock->getY() || x > 3 + curBlock->getX()) {
                        return false;
                    }

                    if (curBlock->getVector()[curBlock->getRotation()][i + vShift][j + hShift] == ',') {
                        return false;
                    }
                }
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
    this->removeBlock();
    // calculate the rotation
    int finalRotation = (curBlock->getRotation() + rotation) % 4;

    // check every space in block vector
    for(int i=0; i<4; i++){
        for (int j = 0; j < 4; j++) {
            // to get the value at the index so we can put that on the board
            char here = curBlock->getVector()[finalRotation][i][j];
            //if a value exist, we place that on the board
            if(here != ','){
              //  cout << "v: " << curBlock->getY()+i+vShift << "   ";
              //  cout << "h: " << curBlock->getX()+j+hShift << "   ";

                mainBoard[curBlock->getY()+i+vShift][curBlock->getX()+j+hShift].placePiece(here, curBlock);
              //  cout << "bt: " << mainBoard[curBlock->getY()+i+vShift][curBlock->getX()+j+hShift].getBlockType() << endl;
            }
        }
    }

    curBlock->setX(curBlock->getX() + hShift);
	curBlock->setY(curBlock->getY() + vShift);
	curBlock->setRotation(finalRotation);
}

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
bool Board:: getHeavy(){
    return heavy;
}
bool Board::getForce(){
    return force;
}
bool Board::getBlind(){
    return blind;
}
void Board::setHeavy(bool heavy){
    this->heavy = heavy;
}
void Board::setForce(bool force){
    this->force = force;
}
void Board::setBlind(bool blind){
    this->blind = blind;
}

int Board::getPlacedBlocks() {
    return placedBlocks;
}

void Board::addPlacedBlocks() {
    ++placedBlocks;
}

void Board::resetPlacedBlocks() {
    this->placedBlocks = 0;
}

void Board::setCurLevel(int setLevel, bool rand, int state, string sequenceFile) {
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
    if (state != 0) {
        notifyObservers();
    }
}
