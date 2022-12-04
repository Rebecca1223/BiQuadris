#include "levelZero.h"
#include <string>
#include <fstream>
#include <vector>
#include "block.h"

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
  if (blockSequence[index] == 'I') return new IBlock{0, false, false};
  if (blockSequence[index] == 'J') return new JBlock{0, false, false};
  if (blockSequence[index] == 'L') return new LBlock{0, false, false};
  if (blockSequence[index] == 'O') return new OBlock{0, false, false};
  if (blockSequence[index] == 'S') return new SBlock{0, false, false};
  if (blockSequence[index] == 'Z') return new ZBlock{0, false, false};
  if (blockSequence[index] == 'T') return new TBlock{0, false, false};
  ++index;
}

int LevelZero::getLevel() { return level; }

LevelZero::~LevelZero() {}
