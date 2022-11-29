#include "tblock.h"
#include "block.h"
#include <string>

TBlock::~TBlock() {}

TBlock::TBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(1, 15, 4, levelGen, 'N', actionHeavy, levelHeavy) {}
