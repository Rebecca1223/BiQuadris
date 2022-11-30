#ifndef _OBLOCK_H_
#define _OBLOCK_H_
#include "block.h"
#include <string>
#include <vector>

class OBlock : public Block {
  static const vector<vector<string>> rotationVector;
  public:
    OBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    char getType();
    vector<vector<string>> getVector() override;
    ~OBlock();
};

#endif
