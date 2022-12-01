#include "text.h"
#include "board.h"
#include <string>

using namespace std;

Text::Text(Board* b1, Board* b2, int width, int height):
b1{b1}, b2{b2}, width{width}, height{height} {}

// notify should apply changes to everything, units, board
void Text::notify() {
  string separatingSpace = "       ";
  string colBorder = "-----------";

  // input each char in both player's screens, need to get each Unit in mainBoard
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      // need getBoard for Board
      // need getBlockType for Unit
      b1->getBoard()[i][j].getBlockType = p1Screen[i][j];
      b2->getBoard()[i][j].getBlockType = p2Screen[i][j];
    }
  }


  // print level, hiscore, score for both players
  out << "Level:    " << b1->getCurLevel() << separatingSpace << "Level:    " << b2->getCurLevel() << endl;
  out << "HiScore:  " << b1->getHiScore() << separatingSpace << "HiScore:  " << b2->getHiScore() << endl;
  out << "Score:    " << b1->getCurScore() << separatingSpace << "Score:    " << b2->getCurScore() << endl;
  out << colBorder << separatingSpace << colBorder << endl;

  // print screen for both players
  if (b1->isBlind()) {
    blindEffect(1);
  } else if (b2->isBlind()) {
    blindEffect(2);
  } else {
    for (int i = 0; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
        out << p1Screen[i][j];
      }
      out << separatingSpace;
      for (int j = 0; j < width; ++j) {
        out << p2Screen[i][j];
      }
    }
  }
  out << colBorder << separatingSpace << colBorder << endl;

  // print next section for both players
  out << "Next:      " << separatingSpace << "Next:      " << endl;
  char blockType;
  // block is going to encased in 4x2 space
  
}

// blindEffect is called somehwere, in notify?, 

// player is the player that gets blinded
void Text::blindEffect(int player) {
  string separatingSpace = "       ";
  if (player == 1) {
    blindScreen = p1Screen;
  } else {
    blindScreen = p2Screen;
  }
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      if ((i >= 2 && i <= 11) && (j >= 2 && j <= 8)) {
        blindScreen[i][j] = '?';
      }
    }
  }

  // print the blindScreen 
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      if (player == 1) {
        out << blindScreen[i][j];
      } else {
        out << p1Screen[i][j];
      }
    }
    out << separatingSpace;

    for (int j = 0; j < width; ++j) {
      if (player == 2) {
        out << blindScreen[i][j];
      } else {
        out << p2Screen[i][j];
      }
    }
  }

}

Text::~Text() {}
