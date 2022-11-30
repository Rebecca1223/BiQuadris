#ifndef _SBLOCK_H_
#define _SBLOCK_H_
#include "block.h"
#include <string>
#include <vector>

class SBlock : public Block {
  static const vector<vector<string>> rotationVector;
  public:
    SBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    char getType();
    vector<vector<string>> getVector() override;
    ~SBlock();
};

#endif
