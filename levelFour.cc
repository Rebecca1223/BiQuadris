#include "levelFour.h"
#include <cstdlib>
#include <fstream>

LevelFour::LevelFour(bool random, string file): level{4}, index{0}, placedBlocks{0}, randOn{random}, sequenceFile{file} {
  blocksPool = {'I','J','L','O','S','S','Z','Z','T'};
}

Block* LevelFour::createBlock() {
  int randIdx;
  if (randOn) {
    randIdx = rand() % blocksPool.size();
  } else {
    blocksPool.clear();
    this->readFile();
    randIdx = index;
  }
  // return new 1x1 block
  //if ((placedBlocks % 5 == 0) && (placedBlocks != 0))
  if (blocksPool[randIdx] == 'I') return new IBlock{4, false, true};
  if (blocksPool[randIdx] == 'J') return new JBlock{4, false, true};
  if (blocksPool[randIdx] == 'L') return new LBlock{4, false, true};
  if (blocksPool[randIdx] == 'O') return new OBlock{4, false, true};
  if (blocksPool[randIdx] == 'S') return new SBlock{4, false, true};
  if (blocksPool[randIdx] == 'Z') return new ZBlock{4, false, true};
  if (blocksPool[randIdx] == 'T') return new TBlock{4, false, true};
  ++index;
}

void LevelFour::readFile() {
  char block;
  ifstream file{sequenceFile};
  while (file >> block) {
    blocksPool.emplace_back(block);
  }
}

int LevelFour::getLevel() { return level; }

void LevelFour::addPlacedBlocks() { ++placedBlocks; }

// call this function (outside) when at least 1 row is cleared.
void LevelFour::resetPlacedBlocks() { placedBlocks = 0; }

LevelFour::~LevelFour() {}
