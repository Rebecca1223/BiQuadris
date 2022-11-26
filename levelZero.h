#ifndef _LEVELZERO_H_
#define _LEVELZERO_H_
#include "level.h"
#include <vector>

class LevelZero : public Level {
  int level;
  bool randOn;
  std::ifstream &in;
  std::vector<char> blocksPool;

  public:
    Block* createBlock() override;
    void readFile() override;
};

#endif
