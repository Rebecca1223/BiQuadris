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
  if (blocksPool[randIdx] == 'I') {
    ++index;
    return new IBlock{3, false, true};
  }
  if (blocksPool[randIdx] == 'J') {
    ++index;
    return new JBlock{3, false, true};
  }
  if (blocksPool[randIdx] == 'L') {
    ++index;
    return new LBlock{3, false, true};
  }
  if (blocksPool[randIdx] == 'O') {
    ++index;
    return new OBlock{3, false, true};
  }
  if (blocksPool[randIdx] == 'S') {
    ++index;
    return new SBlock{3, false, true};
  }
  if (blocksPool[randIdx] == 'Z') {
    ++index;
    return new ZBlock{3, false, true};
  }
  if (blocksPool[randIdx] == 'T') {
    ++index;
    return new TBlock{3, false, true};
  }
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
