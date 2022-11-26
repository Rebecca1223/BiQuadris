#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <string>

class Block {
  protected:
    // set as protected in abstract class to prevent repetitions in each subclass
    int x, y, blockNum, levelGen;
    char curRotation;
    bool actionHeavy, levelHeavy; 

  public:
    virtual void rotate() = 0;
    virtual void moveHorz(std::string dir) = 0;
    virtual void down();
    virtual void drop();
};

#endif
