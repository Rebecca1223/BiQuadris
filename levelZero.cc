#include "levelZero.h"
#include <string>
#include <fstream>
#include <vector>
#include "block.h"
#include <iostream>

using namespace std;


LevelZero::LevelZero(string file): level{0}, index{0},
sequenceFile{file} {
  readFile();
}

void LevelZero::readFile() {
  char block;
  ifstream file{sequenceFile};
  while (file >> block) {
    blockSequence.emplace_back(block);
  }
}

Block* LevelZero::createBlock() {
  // call readFile outside, only once
  if (index == blockSequence.size()) {
    index = 0;
  }
  if (blockSequence[index] == 'I') {
    ++index;
    return new IBlock{0};
  }
  if (blockSequence[index] == 'J') {
    ++index;
    return new JBlock{0};
  }
  if (blockSequence[index] == 'L') {
    ++index;
    return new LBlock{0};
  }
  if (blockSequence[index] == 'O') {
    ++index;
    return new OBlock{0};
  }
  if (blockSequence[index] == 'S') {
    ++index;
    return new SBlock{0};
  }
  if (blockSequence[index] == 'Z') {
    ++index;
    return new ZBlock{0};
  }
  if (blockSequence[index] == 'T') {
    ++index;
    return new TBlock{0};
  }
  
}

int LevelZero::getLevel() { return level; }

LevelZero::~LevelZero() {}
