#ifndef _TEXT_H
#define _TEXT_H
#include "observer.h"
class Board;

class Text : public Observer {
  Board* b1;
  Board* b2;
  int width, height;

  public:
    void notify() override;
};

#endif