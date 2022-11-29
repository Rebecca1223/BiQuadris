#include "iblock.h"
#include "block.h"
#include <string>

IBlock::~IBlock() {}

// create block with x at 1, y at 15, blockNum=4, and direction N
IBlock::IBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(1, 15, 4, levelGen, 'N', actionHeavy, levelHeavy) {}
