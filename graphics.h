#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_
#include "observer.h"
#include <vector>
class Board;
class Xwindow;

class Graphics : public Observer {
  Board* b1;
  Board* b2;
  Xwindow* display;
  int boardHeight, boardWidth, windowHeight, windowWidth;
  std::vector<std::vector<char>> p1Screen;
  std::vector<std::vector<char>> p2Screen;

  public:
    Graphics(Board* b1, Board* b2, int boardHeight, int boardWidth, int windowHeight, int windowWidth);
    void notify() override;
    ~Graphics();
};

#endif
