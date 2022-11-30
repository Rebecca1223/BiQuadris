#ifndef _LBLOCK_H_
#define _LBLOCK_H_
#include "block.h"
#include <string>
#include <vector>

class LBlock : public Block {
  static const vector<vector<string>> rotationVector;
  public:
    LBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    char getType();
    vector<vector<string>> getVector() override;
    ~LBlock();
};

#endif
