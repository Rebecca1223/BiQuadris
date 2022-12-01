#include "sblock.h"
#include "block.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

SBlock::~SBlock() {}

SBlock::SBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(1, 15, 4, levelGen, 0, actionHeavy, levelHeavy) {}

//vectors for the Sblock
const vector<vector<string>> SBlock::rotationVector = {
    {",,,,", ",,,,", ",SS,", "SS,,"},
    {",,,,", "S,,,", "SS,,", ",S,,"},
};

// returns the type of block
char SBlock::getType() { return 'S'; }

// returns the block vector
vector<vector<string>> SBlock::getVector() {
    return rotationVector;
}
