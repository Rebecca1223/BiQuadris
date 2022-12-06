#include "levelOne.h"
#include "block.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

LevelOne::LevelOne(): level{1} {
  blocksPool = {'I','I','J','J','L','L','O','O','S','Z','T','T'};
}

Block* LevelOne::createBlock() {
  int randIdx = rand() % blocksPool.size();
  if (blocksPool[randIdx] == 'I') return new IBlock{1};
  else if (blocksPool[randIdx] == 'J') return new JBlock{1};
  else if (blocksPool[randIdx] == 'L') return new LBlock{1};
  else if (blocksPool[randIdx] == 'O') return new OBlock{1};
  else if (blocksPool[randIdx] == 'S') return new SBlock{1};
  else if (blocksPool[randIdx] == 'Z') return new ZBlock{1};
  else if (blocksPool[randIdx] == 'T') return new TBlock{1};
}

void LevelOne::readFile() {}

int LevelOne::getLevel() { return level; }

LevelOne::~LevelOne() {}
