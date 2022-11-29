#ifndef _IBLOCK_H_
#define _IBLOCK_H_
#include "block.h"
#include <string>

class IBlock : public Block {
  public:
    IBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    ~IBlock();
};

#endif
