#ifndef _LEVELFOUR_H_
#define _LEVELFOUR_H_
#include "level.h"
#include <vector>
#include <string>

class LevelFour : public Level {
  int level, index;
  bool randOn;
//  std::ifstream &in;
  std::string sequenceFile;
  std::vector<char> blocksPool;

  public:
    LevelFour(bool random, std::string file = "");
    Block* createBlock() override;
    void readFile() override;
    int getLevel() override;
    ~LevelFour();
};

#endif
