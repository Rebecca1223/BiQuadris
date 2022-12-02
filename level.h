#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "block.h"
class Block;

class Level {
  public:
    virtual Block* createBlock() = 0;
    virtual void readFile() = 0;
    virtual int getLevel() = 0;
    virtual ~Level();
};

#endif
