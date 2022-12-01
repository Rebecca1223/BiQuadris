#include "lblock.h"
#include "block.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

LBlock::~LBlock() {}

LBlock::LBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(1, 15, 4, levelGen, 0, actionHeavy, levelHeavy) {}

//vectors for the Lblock
const vector<vector<string>> LBlock::rotationVector = {
    {",,,,", ",,,,", ",,L,", "LLL,"},
    {",,,,", "L,,,", "L,,,", "LL,,"},
    {",,,,", ",,,,", "LLL,", "L,,,"},
    {",,,,", "LL,,", ",L,,", ",L,,"}
};

// returns the type of block
char LBlock::getType() { return 'L'; }

// returns the block vector
vector<vector<string>> LBlock::getVector() {
    return rotationVector;
}
