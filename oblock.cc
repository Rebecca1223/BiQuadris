#include "oblock.h"
#include "block.h"
#include <string>

OBlock::~OBlock() {}

OBlock::OBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(1, 15, 4, levelGen, 'N', actionHeavy, levelHeavy) {}
