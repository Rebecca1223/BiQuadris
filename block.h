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

  public:
    Block(int x, int y, int blockNum, int levelGen, int curRotation);
    void cwrotate();
    void ccwrotate();
    void moveHorz(std::string dir);
    void down();
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    int getblockNum();
    int getlevelGen();
    void setBlockNum(int blockNum);
    int getRotation();
    void setRotation(int rotation);
    virtual vector<vector<string>> getVector() = 0;
    virtual vector<vector<vector<int>>> getPositionVector() = 0;
    virtual char getType() = 0;
    virtual ~Block();
};

class IBlock : public Block {
  static vector<vector<string>> rotationVector;
  static vector<vector<vector<int>>> positionVector;
  public:
    IBlock(int levelGen);
    char getType() override;
    vector<vector<string>> getVector() override;
    vector<vector<vector<int>>> getPositionVector() override;
    ~IBlock();
};

class JBlock : public Block {
  static vector<vector<string>> rotationVector;
  static vector<vector<vector<int>>> positionVector;
  public:
    JBlock(int levelGen);
    char getType() override;
    vector<vector<string>> getVector() override;
    vector<vector<vector<int>>> getPositionVector() override;
    ~JBlock();
};

class LBlock : public Block {
  static vector<vector<string>> rotationVector;
  static vector<vector<vector<int>>> positionVector;
  public:
    LBlock(int levelGen);
    char getType() override;
    vector<vector<string>> getVector() override;
    vector<vector<vector<int>>> getPositionVector() override;
    ~LBlock();
};

class OBlock : public Block {
  static vector<vector<string>> rotationVector;
  static vector<vector<vector<int>>> positionVector;
  public:
    OBlock(int levelGen);
    char getType() override;
    vector<vector<string>> getVector() override;
    vector<vector<vector<int>>> getPositionVector() override;
    ~OBlock();
};

class OneBlock : public Block {
  static vector<vector<string>> rotationVector;
  static vector<vector<vector<int>>> positionVector;
  public:
    OneBlock(int levelGen);
    char getType() override;
    vector<vector<string>> getVector() override;
    vector<vector<vector<int>>> getPositionVector() override;
    ~OneBlock();
};

class SBlock : public Block {
  static vector<vector<string>> rotationVector;
  static vector<vector<vector<int>>> positionVector;
  public:
    SBlock(int levelGen);
    char getType() override;
    vector<vector<string>> getVector() override;
    vector<vector<vector<int>>> getPositionVector() override;
    ~SBlock();
};

class TBlock : public Block {
  static vector<vector<string>> rotationVector;
  static vector<vector<vector<int>>> positionVector;
  public:
    TBlock(int levelGen);
    char getType() override;
    vector<vector<string>> getVector() override;
    vector<vector<vector<int>>> getPositionVector() override;
    ~TBlock();
};

class ZBlock : public Block {
  static vector<vector<string>> rotationVector;
  static vector<vector<vector<int>>> positionVector;
  public:
    ZBlock(int levelGen);
    char getType() override;
    vector<vector<string>> getVector() override;
    vector<vector<vector<int>>> getPositionVector() override;
    ~ZBlock();
};

#endif
