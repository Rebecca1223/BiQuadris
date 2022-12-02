#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <string>
#include <vector>
using namespace std;

class Block {
  protected:
    // set as protected in abstract class to prevent repetitions in each subclass
    int x, y, blockNum, levelGen; //x and y tracks bottom left corner of the block on the board
    int curRotation;
    bool actionHeavy, levelHeavy; 

  public:
    Block(int x, int y, int blockNum, int levelGen, int curRotation, bool actionHeavy, bool levelHeavy);
    void cwrotate();
    void ccwrotate();
    void moveHorz(std::string dir);
    void down();
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    int getblockNum();
    void setBlockNum(int blockNum);
    int getRotation();
    void setRotation(int rotation);
    virtual vector<vector<string>> getVector() = 0;
    bool getActionHeavy();
    void setActionHeavy();
    void setLevelHeavy();
    virtual ~Block();
};

#endif
