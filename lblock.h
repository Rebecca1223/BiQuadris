#ifndef _LBLOCK_H_
#define _LBLOCK_H_
#include "block.h"
#include <string>

class LBlock : public Block {
  public:
    LBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    ~LBlock();
};

#endif
