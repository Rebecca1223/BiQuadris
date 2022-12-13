#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_
#include "observer.h"
#include <vector>
class Board;
class Xwindow;

class Graphics : public Observer {
  int boardHeight, boardWidth, windowHeight, windowWidth;
  Board* b1;
  Board* b2;
  Xwindow* display;
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

  public:
    Graphics(Board* b1, Board* b2, int boardHeight, int boardWidth, int windowHeight, int windowWidth);
    void notify() override;
    void build();
    void blindEffect(int player);
    ~Graphics();
};

#endif
