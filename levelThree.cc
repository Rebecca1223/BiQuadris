#include "levelThree.h"
#include <fstream>
#include <cstdlib>

LevelThree::LevelThree(bool random, string file): level{3}, index{0}, randOn{random}, sequenceFile{file} {
  blocksPool = {'I','J','L','O','S','S','Z','Z','T'};
}

Block* LevelThree::createBlock() {
  int randIdx;
  if (randOn) {
    randIdx = rand() % blocksPool.size();
  } else {
    blocksPool.clear();
    this->readFile();
    randIdx = index;
  }
  if (blocksPool[randIdx] == 'I') return new IBlock{3, false, true};
  if (blocksPool[randIdx] == 'J') return new JBlock{3, false, true};
  if (blocksPool[randIdx] == 'L') return new LBlock{3, false, true};
  if (blocksPool[randIdx] == 'O') return new OBlock{3, false, true};
  if (blocksPool[randIdx] == 'S') return new SBlock{3, false, true};
  if (blocksPool[randIdx] == 'Z') return new ZBlock{3, false, true};
  if (blocksPool[randIdx] == 'T') return new TBlock{3, false, true};
  ++index;
}

void LevelThree::readFile() {
  char block;
  ifstream file{sequenceFile};
  while (file >> block) {
    blocksPool.emplace_back(block);
  }
}

int LevelThree::getLevel() { return level; }

LevelThree::~LevelThree() {}
