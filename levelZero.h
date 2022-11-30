#ifndef _LEVELZERO_H_
#define _LEVELZERO_H_
#include "level.h"
#include <vector>
#include <string>
#include "block.h"


class LevelZero : public Level {
  int level, index;
  bool randOn;
 // std::ifstream &in;
  string sequenceFile;
  std::vector<char> blockSequence;

  public:
    LevelZero(string file);
    Block* createBlock() override;
    void readFile() override;
    ~LevelZero();
};

#endif
