#ifndef _JBLOCK_H_
#define _JBLOCK_H_
#include "block.h"
#include <string>

class JBlock : public Block {
  public:
    void rotate() override;
    void moveHorz(std::string dir) override;
    void down() override;
    void drop() override;
    ~JBlock();
};

#endif
