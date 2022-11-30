#ifndef _ONEBLOCK_H_
#define _ONEBLOCK_H_
#include "block.h"
#include <string>
#include <vector>

class OneBlock : public Block {
  static const vector<vector<string>> rotationVector;
  public:
    OneBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    char getType();
    vector<vector<string>> getVector() override;
    ~OneBlock();
};

#endif
