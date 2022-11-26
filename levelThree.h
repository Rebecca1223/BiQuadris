#ifndef _LEVELTHREE_H_
#define _LEVELTHREE_H_
#include "level.h"
#include <vector>

class LevelThree : public Level {
  int level;
  bool randOn;
  std::ifstream &in;
  std::vector<char> blocksPool;

  public:
    Block* createBlock() override;
    void readFile() override;
    ~LevelThree();
};

#endif
