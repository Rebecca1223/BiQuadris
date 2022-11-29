#ifndef _OBLOCK_H_
#define _OBLOCK_H_
#include "block.h"
#include <string>

class OBlock : public Block {
  public:
    OBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    ~OBlock();
};

#endif
