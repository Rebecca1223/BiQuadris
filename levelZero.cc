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
   // cout << block << endl;
  }
}

Block* LevelZero::createBlock() {
  // call readFile outside, only once
  
  if (blockSequence[index] == 'I') {
    ++index;
    return new IBlock{0, false, false};
  }
  if (blockSequence[index] == 'J') {
    ++index;
    return new JBlock{0, false, false};
  }
  if (blockSequence[index] == 'L') {
    ++index;
    return new LBlock{0, false, false};
  }
  if (blockSequence[index] == 'O') {
    ++index;
    return new OBlock{0, false, false};
  }
  if (blockSequence[index] == 'S') {
    ++index;
    return new SBlock{0, false, false};
  }
  if (blockSequence[index] == 'Z') {
    ++index;
    return new ZBlock{0, false, false};
  }
  if (blockSequence[index] == 'T') {
    ++index;
    return new TBlock{0, false, false};
  }
  
}

int LevelZero::getLevel() { return level; }

LevelZero::~LevelZero() {}
