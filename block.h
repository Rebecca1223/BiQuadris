#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <string>
#include <vector>
using namespace std;

class Block {
  protected:
    // set as protected in abstract class to prevent repetitions in each subclass
    int x, y, blockNum, levelGen; //x and y tracks bottom left corner of the block on the board
    char curRotation;
    bool actionHeavy, levelHeavy; 

  public:
    Block(int x, int y, int blockNum, int levelGen, char curRotation, bool actionHeavy, bool levelHeavy);
    void cwrotate();
    void ccwrotate();
    void moveHorz(std::string dir);
    void down();
    void drop();
    int getX();
    int getY();
    int getblockNum();
    char getRotation();
    virtual vector<vector<string>> getVector() = 0;
    void setActionHeavy();
    void setLevelHeavy();
    virtual ~Block();
};

#endif
