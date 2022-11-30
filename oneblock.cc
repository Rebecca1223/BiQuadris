#include "oneblock.h"
#include "block.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

OneBlock::~OneBlock() {}

OneBlock::OneBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(6, 15, 1, levelGen, 'N', actionHeavy, levelHeavy) {}

//vectors for the Oneblock
const vector<vector<string>> OneBlock::rotationVector = {
    {",,,,", ",,,,", ",,,,", "*,,,"},
};

// returns the type of block
char OneBlock::getType() { return '*'; }

// returns the block vector
vector<vector<string>> OneBlock::getVector() {
    return rotationVector;
}
