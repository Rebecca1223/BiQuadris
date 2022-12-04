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
    int getlevelGen();
    void setBlockNum(int blockNum);
    int getRotation();
    void setRotation(int rotation);
    virtual vector<vector<string>> getVector() = 0;
    virtual vector<vector<vector<int>>> getPositionVector() = 0;
    bool getActionHeavy();
    void setActionHeavy();
    void setLevelHeavy();
    virtual char getType() = 0;
    virtual ~Block();
};

class IBlock : public Block {
  static const vector<vector<string>> rotationVector;
  static const vector<vector<vector<int>>> positionVector;
  public:
    IBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    char getType() override;
    vector<vector<string>> getVector() override;
    vector<vector<vector<int>>> getPositionVector() override;
    ~IBlock();
};

class JBlock : public Block {
  static const vector<vector<string>> rotationVector;
  static const vector<vector<vector<int>>> positionVector;
  public:
    JBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    char getType() override;
    vector<vector<string>> getVector() override;
    vector<vector<vector<int>>> getPositionVector() override;
    ~JBlock();
};

class LBlock : public Block {
  static const vector<vector<string>> rotationVector;
  static const vector<vector<vector<int>>> positionVector;
  public:
    LBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    char getType() override;
    vector<vector<string>> getVector() override;
    vector<vector<vector<int>>> getPositionVector() override;
    ~LBlock();
};

class OBlock : public Block {
  static const vector<vector<string>> rotationVector;
  static const vector<vector<vector<int>>> positionVector;
  public:
    OBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    char getType() override;
    vector<vector<string>> getVector() override;
    vector<vector<vector<int>>> getPositionVector() override;
    ~OBlock();
};

class OneBlock : public Block {
  static const vector<vector<string>> rotationVector;
  static const vector<vector<vector<int>>> positionVector;
  public:
    OneBlock(int levelGen);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    char getType() override;
    vector<vector<string>> getVector() override;
    vector<vector<vector<int>>> getPositionVector() override;
    ~OneBlock();
};

class SBlock : public Block {
  static const vector<vector<string>> rotationVector;
  static const vector<vector<vector<int>>> positionVector;
  public:
    SBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    char getType() override;
    vector<vector<string>> getVector() override;
    vector<vector<vector<int>>> getPositionVector() override;
    ~SBlock();
};

class TBlock : public Block {
  static const vector<vector<string>> rotationVector;
  static const vector<vector<vector<int>>> positionVector;
  public:
    TBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    char getType() override;
    vector<vector<string>> getVector() override;
    vector<vector<vector<int>>> getPositionVector() override;
    ~TBlock();
};

class ZBlock : public Block {
  static const vector<vector<string>> rotationVector;
  static const vector<vector<vector<int>>> positionVector;
  public:
    ZBlock(int levelGen, bool actionHeavy, bool levelHeavy);
    // void rotate() override;
    // void moveHorz(std::string dir) override;
    // void down() override;
    // void drop() override;
    char getType() override;
    vector<vector<string>> getVector() override;
    vector<vector<vector<int>>> getPositionVector() override;
    ~ZBlock();
};

#endif
