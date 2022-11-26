#ifndef _LBLOCK_H_
#define _LBLOCK_H_
#include "block.h"
#include <string>

class LBlock : public Block {
  public:
    void rotate() override;
    void moveHorz(std::string dir) override;
    void down() override;
    void drop() override;
    ~LBlock();
};

#endif
