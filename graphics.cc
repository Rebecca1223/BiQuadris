#include "graphics.h"
#include "board.h"
#include <string>

Graphics::Graphics(Board* b1, Board* b2, int bh, int bw, int wh, int ww):
b1{b1}, b2{b2}, boardHeight{bh}, boardWidth{bw}, windowHeight{wh}, windowWidth{ww} {}

void Graphics::notify() {
  // boardWidth = 11, boardHeight = 18
  // separatedSpace = 7
  // windowWidth = (width * 2) + separatedSpace
  
  for (int i = 0; i < boardHeight; ++i) {
    for (int j = 0; j < boardWidth; ++j) {
      p1Screen[i][j] = b1->getBoard()[i][j].getBlockType();
      p2Screen[i][j] = b2->getBoard()[i][j].getBlockType();
    }
  }

  string p1Level = "Level:    " + to_string(b1->getCurLevel());
  string p2Level = "Level:    " + to_string(b2->getCurLevel());
  string p1HiScore = "HiScore:  " + to_string(b1->getHiScore());
  string p2HiScore = "HiScore:  " + to_string(b2->getHiScore());
  string p1Score = "Score:    " + to_string(b1->getCurScore());
  string p2Score = "Score:    " + to_string(b2->getCurScore());
  
}

Graphics::~Graphics() {}
