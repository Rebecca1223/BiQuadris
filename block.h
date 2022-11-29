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
    Block(int x, int y, int blockNum, int levelGen, char curRotation, bool actionHeavy, bool levelHeavy);
    void rotate();
    void moveHorz(std::string dir);
    void down();
    void drop();
    virtual ~Block();
};

#endif
