#include "block.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

Block::~Block() {}

Block::Block(int x, int y, int blockNum, int levelGen, int curRotation, bool actionHeavy, bool levelHeavy): x{x}, y{y}, blockNum{blockNum}, levelGen{levelGen}, curRotation{curRotation}, actionHeavy{actionHeavy}, levelHeavy{levelHeavy} {}

void Block::cwrotate(){ // clockwise
    if(curRotation == 3){
        curRotation = 0;
    }else{
        curRotation++;
    }
}

void Block::ccwrotate(){ // counterclockwise
    if(curRotation == 0){
        curRotation = 3;
    }else{
        curRotation--;
    }
}

void Block::moveHorz(std::string dir){
    if(dir == "right"){
        x++;
    }else{
        x--;
    }
}

void Block::down(){
    y--;
}

int Block::getX(){
    return x;
}

void Block::setX(int x){
    this->x = x;
}

int Block::getY(){
    return y;
}

void Block::setY(int y){
    this->y = y;
}

int Block::getlevelGen(){
    return levelGen;
}

int Block::getblockNum(){
    return blockNum;
}

void Block::setBlockNum(int blockNum){
    this->blockNum = blockNum;
}

int Block::getRotation(){
    return curRotation;
}

void Block::setRotation(int rotation){
    this->curRotation = curRotation;
}

bool Block::getActionHeavy(){
    return actionHeavy;
}

//if player does heavy, setActionHeavy for the block. if actionHeavy=true and moveHorz, the
void Block::setActionHeavy(){
    actionHeavy = true;
}

void Block::setLevelHeavy(){
    levelHeavy = true;
}

//IBLOCK
//vectors for the iblock
vector<vector<string>> IBlock::rotationVector = {
    {",,,,", ",,,,", ",,,,", "IIII"},
    {"I,,,", "I,,,", "I,,,", "I,,,"},
    {",,,,", ",,,,", ",,,,", "IIII"},
    {"I,,,", "I,,,", "I,,,", "I,,,"}
};
vector<vector<vector<int>>> IBlock::positionVector = {
    {{1, 1}, {2, 1}, {3, 1}, {4, 1}},
    {{1, 4}, {1, 3}, {1, 2}, {1, 1}},
    {{1, 4}, {1, 3}, {1, 2}, {1, 1}},
    {{1, 1}, {2, 1}, {3, 1}, {4, 1}}
};

IBlock::~IBlock() {}

// create block with x at 0, y at 3, blockNum=4, and direction N
IBlock::IBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(0, 0, 4, levelGen, 0, actionHeavy, levelHeavy) {}

// returns the type of block
char IBlock::getType() { return 'I'; }

// returns the block vector
vector<vector<string>> IBlock::getVector() {
    return rotationVector;
}

// returns the position vector
vector<vector<vector<int>>> IBlock::getPositionVector() {
    return positionVector;
}

//JBLOCK
JBlock::~JBlock() {}

JBlock::JBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(0, 3, 4, levelGen, 0, actionHeavy, levelHeavy) {}

//vectors for the jblock
vector<vector<string>> JBlock::rotationVector = {
    {",,,,", ",,,,", "J,,,", "JJJ,"},
    {",,,,", "JJ,,", "J,,,", "J,,,"},
    {",,,,", ",,,,", "JJJ,", ",,J,"},
    {",,,,", ",J,,", ",J,,", "JJ,,"}
};

vector<vector<vector<int>>> JBlock::positionVector = {
    {{1, 2}, {1, 1}, {2, 1},{3, 1}},
    {{1, 3}, {2, 3}, {1, 2},{1, 1}},
    {{1, 2}, {2, 2}, {3, 2},{3, 1}},
    {{2, 3}, {2, 2}, {1, 1},{1, 2}}
};

// returns the type of block
char JBlock::getType() { return 'J'; }

// returns the block vector
vector<vector<string>> JBlock::getVector() {
    return rotationVector;
}

// returns the position vector
vector<vector<vector<int>>> JBlock::getPositionVector() {
    return positionVector;
}

//LBLOCK
LBlock::~LBlock() {}

LBlock::LBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(0, 3, 4, levelGen, 0, actionHeavy, levelHeavy) {}

//vectors for the Lblock
vector<vector<string>> LBlock::rotationVector = {
    {",,,,", ",,,,", ",,L,", "LLL,"},
    {",,,,", "L,,,", "L,,,", "LL,,"},
    {",,,,", ",,,,", "LLL,", "L,,,"},
    {",,,,", "LL,,", ",L,,", ",L,,"}
};

vector<vector<vector<int>>> LBlock::positionVector = {
    {{3, 2}, {1, 1}, {2, 1}, {3, 1}},
    {{1, 3}, {1, 2}, {1, 1}, {2, 1}},
    {{1, 2}, {2, 2}, {3, 2}, {1, 1}},
    {{1, 3}, {2, 3}, {2, 2}, {2, 1}}
};

// returns the type of block
char LBlock::getType() { return 'L'; }

// returns the block vector
vector<vector<string>> LBlock::getVector() {
    return rotationVector;
}

// returns the position vector
vector<vector<vector<int>>> LBlock::getPositionVector() {
    return positionVector;
}

//OBLOCK
OBlock::~OBlock() {}

OBlock::OBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(0, 3, 4, levelGen, 0, actionHeavy, levelHeavy) {}

//vectors for the Oblock
vector<vector<string>> OBlock::rotationVector = {
    {",,,,", ",,,,", "OO,,", "OO,,"},
    {",,,,", ",,,,", "OO,,", "OO,,"},
    {",,,,", ",,,,", "OO,,", "OO,,"},
    {",,,,", ",,,,", "OO,,", "OO,,"}
};

vector<vector<vector<int>>> OBlock::positionVector = {
    {{1, 2}, {2, 2}, {1, 1}, {2, 1}},
    {{1, 2}, {2, 2}, {1, 1}, {2, 1}},
    {{1, 2}, {2, 2}, {1, 1}, {2, 1}},
    {{1, 2}, {2, 2}, {1, 1}, {2, 1}}
};

// returns the type of block
char OBlock::getType() { return 'O'; }

// returns the block vector
vector<vector<string>> OBlock::getVector() {
    return rotationVector;
}

// returns the position vector
vector<vector<vector<int>>> OBlock::getPositionVector() {
    return positionVector;
}

//OneBLOCK
OneBlock::~OneBlock() {}

OneBlock::OneBlock(int levelGen) : Block(6, 3, 1, levelGen, 0, false, false) {}

//vectors for the Oneblock
vector<vector<string>> OneBlock::rotationVector = {
    {",,,,", ",,,,", ",,,,", "*,,,"},
    {",,,,", ",,,,", ",,,,", "*,,,"},
    {",,,,", ",,,,", ",,,,", "*,,,"},
    {",,,,", ",,,,", ",,,,", "*,,,"}
};

vector<vector<vector<int>>> OneBlock::positionVector = {
    {{1, 1}, {0, 0}, {0, 0}, {0, 0}},
    {{1, 1}, {0, 0}, {0, 0}, {0, 0}},
    {{1, 1}, {0, 0}, {0, 0}, {0, 0}},
    {{1, 1}, {0, 0}, {0, 0}, {0, 0}}
};

// returns the type of block
char OneBlock::getType() { return '*'; }

// returns the block vector
vector<vector<string>> OneBlock::getVector() {
    return rotationVector;
}

// returns the position vector
vector<vector<vector<int>>> OneBlock::getPositionVector() {
    return positionVector;
}

//SBLOCK
SBlock::~SBlock() {}

SBlock::SBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(0, 3, 4, levelGen, 0, actionHeavy, levelHeavy) {}

//vectors for the Sblock
vector<vector<string>> SBlock::rotationVector = {
    {",,,,", ",,,,", ",SS,", "SS,,"},
    {",,,,", "S,,,", "SS,,", ",S,,"},
    {",,,,", ",,,,", ",SS,", "SS,,"},
    {",,,,", "S,,,", "SS,,", ",S,,"}
};

vector<vector<vector<int>>> SBlock::positionVector = {
    {{2, 2}, {3, 2}, {1, 1}, {2, 1}},
    {{1, 3}, {1, 2}, {2, 2}, {2, 1}},
    {{2, 2}, {3, 2}, {1, 1}, {2, 1}},
    {{1, 3}, {1, 2}, {2, 2}, {2, 1}}
};

// returns the type of block
char SBlock::getType() { return 'S'; }

// returns the block vector
vector<vector<string>> SBlock::getVector() {
    return rotationVector;
}

// returns the position vector
vector<vector<vector<int>>> SBlock::getPositionVector() {
    return positionVector;
}

//TBLOCK
TBlock::~TBlock() {}

TBlock::TBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(0, 3, 4, levelGen, 0, actionHeavy, levelHeavy) {}

//vectors for the Tblock
vector<vector<string>> TBlock::rotationVector = {
    {",,,,", ",,,,", "TTT,", ",T,,"},
    {",,,,", ",T,,", "TT,,", ",T,,"},
    {",,,,", ",,,,", ",T,,", "TTT,"},
    {",,,,", "T,,,", "TT,,", "T,,,"}
};

vector<vector<vector<int>>> TBlock::positionVector = {
    {{1, 2}, {2, 2}, {3, 2}, {2, 1}},
    {{2, 3}, {1, 2}, {2, 2}, {2, 1}},
    {{2, 2}, {1, 1}, {1, 2}, {1, 3}},
    {{1, 3}, {1, 2}, {2, 2}, {1, 1}}
};

// returns the type of block
char TBlock::getType() { return 'T'; }

// returns the block vector
vector<vector<string>> TBlock::getVector() {
    return rotationVector;
}

// returns the position vector
vector<vector<vector<int>>> TBlock::getPositionVector() {
    return positionVector;
}

//ZBLOCK
ZBlock::~ZBlock() {}

ZBlock::ZBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(0, 3, 4, levelGen, 0, actionHeavy, levelHeavy) {}

//vectors for the Zblock
vector<vector<string>> ZBlock::rotationVector = {
    {",,,,", ",,,,", "ZZ,,", ",ZZ,"},
    {",,,,", ",Z,,", "ZZ,,", "Z,,,"},
    {",,,,", ",,,,", "ZZ,,", ",ZZ,"},
    {",,,,", ",Z,,", "ZZ,,", "Z,,,"}
};

vector<vector<vector<int>>> ZBlock::positionVector = {
    {{1, 2}, {2, 2}, {2, 1}, {3, 1}},
    {{2, 3}, {1, 2}, {2, 2}, {1, 1}},
    {{1, 2}, {2, 2}, {2, 1}, {3, 1}},
    {{2, 3}, {1, 2}, {2, 2}, {1, 1}}   
};

// returns the type of block
char ZBlock::getType() { return 'Z'; }

// returns the block vector
vector<vector<string>> ZBlock::getVector() {
    return rotationVector;
}

// returns the position vector
vector<vector<vector<int>>> ZBlock::getPositionVector() {
    return positionVector;
}
