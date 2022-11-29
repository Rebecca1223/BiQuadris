#ifndef _SBLOCK_H_
#define _SBLOCK_H_
#include "block.h"
#include <string>

class SBlock : public Block {
  public:
    SBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    ~SBlock();
};

#endif
