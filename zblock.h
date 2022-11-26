#ifndef _ZBLOCK_H_
#define _ZBLOCK_H_
#include "block.h"
#include <string>

class ZBlock : public Block {
  public:
    void rotate() override;
    void moveHorz(std::string dir) override;
    void down() override;
    void drop() override;
    ~ZBlock();
};

#endif
