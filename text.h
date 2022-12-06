#ifndef _TEXT_H
#define _TEXT_H
#include "observer.h"
#include <vector>
#include <iostream>
class Board;

class Text : public Observer {
  Board* b1;
  Board* b2;
  int width, height;
  std::vector<std::vector<char>> p1Screen;
  std::vector<std::vector<char>> p2Screen;
  std::vector<std::vector<char>> blindScreen;
  std::vector<std::vector<char>> p1NextBlock;
  std::vector<std::vector<char>> p2NextBlock;
  std::vector<std::vector<char>> initIBlock;
  std::vector<std::vector<char>> initJBlock;
  std::vector<std::vector<char>> initLBlock;
  std::vector<std::vector<char>> initOBlock;
  std::vector<std::vector<char>> initSBlock;
  std::vector<std::vector<char>> initZBlock;
  std::vector<std::vector<char>> initTBlock;
  std::ostream &out = std::cout;

  public:
    Text(Board* b1, Board* b2, int width, int height);
    void notify() override;
    void blindEffect(int player);
    ~Text();
};

#endif
