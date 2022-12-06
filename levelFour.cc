#include "levelFour.h"
#include "block.h"
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

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
    if (index == blocksPool.size()) {
      index = 0;
    }
    randIdx = index;
  }
  // return new 1x1 block
  //if ((placedBlocks % 5 == 0) && (placedBlocks != 0))
  if (blocksPool[randIdx] == 'I') {
    ++index;
    return new IBlock{4};
  }
  if (blocksPool[randIdx] == 'J') {
    ++index;
    return new JBlock{4};
  }
  if (blocksPool[randIdx] == 'L') {
    ++index;
    return new LBlock{4};
  }
  if (blocksPool[randIdx] == 'O') {
    ++index;
    return new OBlock{4};
  }
  if (blocksPool[randIdx] == 'S') {
    ++index;
    return new SBlock{4};
  }
  if (blocksPool[randIdx] == 'Z') {
    ++index;
    return new ZBlock{4};
  }
  if (blocksPool[randIdx] == 'T') {
    ++index;
    return new TBlock{4};
  }
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
