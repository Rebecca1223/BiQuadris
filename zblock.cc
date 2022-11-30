#include "zblock.h"
#include "block.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

ZBlock::~ZBlock() {}

ZBlock::ZBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(1, 15, 4, levelGen, 'N', actionHeavy, levelHeavy) {}

//vectors for the Zblock
const vector<vector<string>> ZBlock::rotationVector = {
    {",,,,", ",,,,", "ZZ,,", ",ZZ,"},
    {",,,,", ",Z,,", "ZZ,,", "Z,,,"},
};

// returns the type of block
char ZBlock::getType() { return 'Z'; }

// returns the block vector
vector<vector<string>> ZBlock::getVector() {
    return rotationVector;
}
