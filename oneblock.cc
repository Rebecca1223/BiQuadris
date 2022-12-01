#include "oneblock.h"
#include "block.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

OneBlock::~OneBlock() {}

OneBlock::OneBlock(int levelGen) : Block(6, 15, 1, levelGen, 0, false, false) {}

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
