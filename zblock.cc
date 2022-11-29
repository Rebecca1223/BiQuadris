#include "zblock.h"
#include "block.h"
#include <string>

ZBlock::~ZBlock() {}

ZBlock::ZBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(1, 15, 4, levelGen, 'N', actionHeavy, levelHeavy) {}
