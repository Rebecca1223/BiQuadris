#ifndef _LEVELONE_H_
#define _LEVELONE_H_
#include "level.h"
#include <vector>

class LevelOne : public Level {
  int level;
  std::vector<char> blocksPool;

  public:
    LevelOne();
    Block* createBlock() override;
    void readFile() override;
    int getLevel() override;
    ~LevelOne();
};

#endif
