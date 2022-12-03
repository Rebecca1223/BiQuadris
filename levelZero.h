#ifndef _LEVELZERO_H_
#define _LEVELZERO_H_
#include "level.h"
#include <vector>
#include <string>
#include "block.h"


class LevelZero : public Level {
  int level, index;
 // std::ifstream &in;
  string sequenceFile;
  std::vector<char> blockSequence;

  public:
    LevelZero(std::string file);
    Block* createBlock() override;
    void readFile() override;
    int getLevel() override;
    ~LevelZero();
};

#endif
