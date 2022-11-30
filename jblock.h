#ifndef _JBLOCK_H_
#define _JBLOCK_H_
#include "block.h"
#include <string>
#include <vector>

class JBlock : public Block {
  static const vector<vector<string>> rotationVector;
  public:
    JBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    char getType();
    vector<vector<string>> getVector() override;
    ~JBlock();
};

#endif
