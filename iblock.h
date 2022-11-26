#ifndef _IBLOCK_H_
#define _IBLOCK_H_
#include "block.h"
#include <string>

class IBlock : public Block {
  public:
    void rotate() override;
    void moveHorz(std::string dir) override;
    void down() override;
    void drop() override;
};

#endif
