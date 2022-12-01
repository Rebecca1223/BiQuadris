#include "jblock.h"
#include "block.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

JBlock::~JBlock() {}

JBlock::JBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(1, 15, 4, levelGen, 0, actionHeavy, levelHeavy) {}

//vectors for the jblock
const vector<vector<string>> JBlock::rotationVector = {
    {",,,,", ",,,,", "J,,,", "JJJ,"},
    {",,,,", "JJ,,", "J,,,", "J,,,"},
    {",,,,", ",,,,", "JJJ,", ",,J,"},
    {",,,,", ",J,,", ",J,,", "JJ,,"}
};

// returns the type of block
char JBlock::getType() { return 'J'; }

// returns the block vector
vector<vector<string>> JBlock::getVector() {
    return rotationVector;
}
