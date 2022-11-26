#ifndef _TBLOCK_H_
#define _TBLOCK_H_
#include "block.h"
#include <string>

class TBlock : public Block {
  public:
    void rotate() override;
    void moveHorz(std::string dir) override;
    void down() override;
    void drop() override;
};

#endif
