#ifndef _LEVELFOUR_H_
#define _LEVELFOUR_H_
#include "level.h"
#include <vector>

class LevelFour : public Level {
  int level;
  bool randOn;
  std::ifstream &in;
  std::vector<char> blocksPool;

  public:
    Block* createBlock() override;
    void readFile() override;
    ~LevelFour();
};

#endif
