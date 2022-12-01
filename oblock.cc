#include "oblock.h"
#include "block.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

OBlock::~OBlock() {}

OBlock::OBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(1, 15, 4, levelGen, 0, actionHeavy, levelHeavy) {}

//vectors for the Oblock
const vector<vector<string>> OBlock::rotationVector = {
    {",,,,", ",,,,", "OO,,", "OO,,"},
};

// returns the type of block
char OBlock::getType() { return 'O'; }

// returns the block vector
vector<vector<string>> OBlock::getVector() {
    return rotationVector;
}
