#include "lblock.h"
#include "block.h"
#include <string>

LBlock::~LBlock() {}

LBlock::LBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(1, 15, 4, levelGen, 'N', actionHeavy, levelHeavy) {}
