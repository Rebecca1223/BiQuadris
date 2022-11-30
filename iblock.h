#ifndef _IBLOCK_H_
#define _IBLOCK_H_
#include "block.h"
#include <string>
#include <vector>

class IBlock : public Block {
  static const vector<vector<string>> rotationVector;
  public:
    IBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    char getType();
    vector<vector<string>> getVector() override;
    ~IBlock();
};

#endif
