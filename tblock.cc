#include "tblock.h"
#include "block.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

TBlock::~TBlock() {}

TBlock::TBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(1, 15, 4, levelGen, 'N', actionHeavy, levelHeavy) {}

//vectors for the Tblock
const vector<vector<string>> TBlock::rotationVector = {
    {",,,,", ",,,,", "TTT,", ",T,,"},
    {",,,,", ",T,,", "TT,,", ",T,,"},
    {",,,,", ",,,,", ",T,,", "TTT,"},
    {",,,,", "T,,,", "TT,,", "T,,,"}
};

// returns the type of block
char TBlock::getType() { return 'T'; }

// returns the block vector
vector<vector<string>> TBlock::getVector() {
    return rotationVector;
}
