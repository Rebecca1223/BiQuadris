#ifndef _ZBLOCK_H_
#define _ZBLOCK_H_
#include "block.h"
#include <string>
#include <vector>

class ZBlock : public Block {
  static const vector<vector<string>> rotationVector;
  public:
    ZBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    char getType();
    vector<vector<string>> getVector() override;
    ~ZBlock();
};

#endif
