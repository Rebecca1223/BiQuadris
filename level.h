#ifndef _LEVEL_H_
#define _LEVEL_H_
class Block;

class Level {
  public:
    virtual Block* createBlock();
    virtual void readFile();
    virtual ~Level();
};

#endif
