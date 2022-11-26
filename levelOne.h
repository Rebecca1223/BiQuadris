#ifndef _LEVELONE_H_
#define _LEVELONE_H_
#include "level.h"
#include <vector>

class LevelOne : public Level {
  int level;
  bool randOn;
  std::ifstream &in;
  std::vector<char> blocksPool;

  public:
    Block* createBlock() override;
    void readFile() override;
    ~LevelOne();
};

#endif
