#include "sblock.h"
#include "block.h"
#include <string>

SBlock::~SBlock() {}

SBlock::SBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(1, 15, 4, levelGen, 'N', actionHeavy, levelHeavy) {}
