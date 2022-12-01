#include "iblock.h"
#include "block.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

//vectors for the iblock
const vector<vector<string>> IBlock::rotationVector = {
    {",,,,", ",,,,", ",,,,", "IIII"},
    {"I,,,", "I,,,", "I,,,", "I,,,"},
};

IBlock::~IBlock() {}

// create block with x at 1, y at 15, blockNum=4, and direction N
IBlock::IBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(1, 15, 4, levelGen, 0, actionHeavy, levelHeavy) {}

// returns the type of block
char IBlock::getType() { return 'I'; }

// returns the block vector
vector<vector<string>> IBlock::getVector() {
    return rotationVector;
}
