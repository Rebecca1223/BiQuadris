#ifndef _ZBLOCK_H_
#define _ZBLOCK_H_
#include "block.h"
#include <string>

class ZBlock : public Block {
  public:
    ZBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    ~ZBlock();
};

#endif
