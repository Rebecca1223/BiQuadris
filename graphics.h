#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_
#include "observer.h"
class Board;
class Xwindow;

class Graphics : public Observer {
  Board* b1;
  Board* b2;
  Xwindow* display;
  int width, height;

  public:
    void notify() override;
};

#endif