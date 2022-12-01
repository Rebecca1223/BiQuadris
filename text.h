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
  std::ostream &out = std::cout;

  public:
    Text(Board* b1, Board* b2, int width, int height);
    void notify() override;
    void blindEffect(int player);
    ~Text();
};

#endif