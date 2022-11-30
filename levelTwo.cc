#include "levelTwo.h"
#include <cstdlib>

LevelTwo::LevelTwo(): level{2} {
  blocksPool = {'I','J','L','O','S','Z','T'};
}

Block* LevelTwo::createBlock() {
  int randIdx = rand() % blocksPool.size();
  if (blocksPool[randIdx] == 'I') return new IBlock{2, false, false};
  else if (blocksPool[randIdx] == 'J') return new JBlock{2, false, false};
  else if (blocksPool[randIdx] == 'L') return new LBlock{2, false, false};
  else if (blocksPool[randIdx] == 'O') return new OBlock{2, false, false};
  else if (blocksPool[randIdx] == 'S') return new SBlock{2, false, false};
  else if (blocksPool[randIdx] == 'Z') return new ZBlock{2, false, false};
  else if (blocksPool[randIdx] == 'T') return new TBlock{2, false, false};
}

void LevelTwo::readFile() {}

int LevelTwo::getLevel() { return level; }

LevelTwo::~LevelTwo() {}
