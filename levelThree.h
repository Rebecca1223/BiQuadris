#ifndef _LEVELTHREE_H_
#define _LEVELTHREE_H_
#include "level.h"
#include <vector>
#include <string>

class LevelThree : public Level {
  int level, index;
  bool randOn;
//  std::ifstream &in;
  std::string sequenceFile;
  std::vector<char> blocksPool;

  public:
    LevelThree(bool random, std::string file = "");
    Block* createBlock() override;
    void readFile() override;
    int getLevel() override;
    ~LevelThree();
};

#endif
