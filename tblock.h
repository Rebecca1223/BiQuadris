#ifndef _TBLOCK_H_
#define _TBLOCK_H_
#include "block.h"
#include <string>
#include <vector>

class TBlock : public Block {
  static const vector<vector<string>> rotationVector;
  public:
    TBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    char getType() override;
    vector<vector<string>> getVector() override;
    ~TBlock();
};

#endif
