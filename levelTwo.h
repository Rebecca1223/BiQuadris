#ifndef _LEVELTWO_H_
#define _LEVELTWO_H_
#include "level.h"
#include <vector>

class LevelTwo : public Level {
  int level;
//  bool randOn;
//  std::ifstream &in;
  std::vector<char> blocksPool;

  public:
    LevelTwo();
    Block* createBlock() override;
    void readFile() override;
    int getLevel() override;
    ~LevelTwo();
};

#endif
