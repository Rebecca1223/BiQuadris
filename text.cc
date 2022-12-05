#include "text.h"
#include "board.h"
#include <string>
#include <iostream>

using namespace std;

Text::Text(Board* b1, Board* b2, int width, int height):
b1{b1}, b2{b2}, width{width}, height{height} {
  initIBlock = {
    {' ',' ',' ',' '},
    {'I','I','I','I'},
  };
  initJBlock = {
    {'J',' ',' ',' '},
    {'J','J','J',' '},
  };
  initLBlock = {
    {' ',' ','L',' '},
    {'L','L','L',' '},
  };
  initOBlock = {
    {'O','O',' ',' '},
    {'O','O',' ',' '},
  };
  initSBlock = {
    {' ','S','S',' '},
    {'S','S',' ',' '},
  };
  initZBlock = {
    {'Z','Z',' ',' '},
    {' ','Z','Z',' '},
  };
  initTBlock = {
    {'T','T','T',' '},
    {' ','T',' ',' '},
  };
}

// notify should apply changes to everything, units, board
void Text::notify() {
  string separatingSpace = "       ";
  string colBorder = "-----------";
  p1Screen.clear();
  p2Screen.clear();

  // input each char in both player's screens, need to get each Unit in mainBoard
  for (int i = 0; i < height; ++i) {
    vector<char> p1row;
    vector<char> p2row;
    for (int j = 0; j < width; ++j) {
      // need getBoard for Board
      // need getBlockType for Unit
     // cout << b1->getBoard()[i][j].getBlockType() << endl;
      p1row.emplace_back(b1->getBoard()[i][j].getBlockType());
      p2row.emplace_back(b2->getBoard()[i][j].getBlockType());
    }
    p1Screen.emplace_back(p1row);
    p2Screen.emplace_back(p2row);
  }


  // print level, hiscore, score for both players
  out << "Level:    " << b1->getLevel() << separatingSpace << "Level:    " << b2->getLevel() << endl;
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
      out << endl;
    }
  }
  out << colBorder << separatingSpace << colBorder << endl;

  // print next section for both players
  out << "Next:      " << separatingSpace << "Next:      " << endl;
  char p1blockType = b1->getNextBlock()->getType();
  char p2blockType = b2->getNextBlock()->getType();
  vector<vector<char>> p1Next;
  vector<vector<char>> p2Next;
  string nextSpace = "              ";

  if (p1blockType == 'I') {
    p1Next = initIBlock;
  } else if (p1blockType == 'J') {
    p1Next = initJBlock;
  } else if (p1blockType == 'L') {
    p1Next = initLBlock;
  } else if (p1blockType == 'O') {
    p1Next = initOBlock;
  } else if (p1blockType == 'S') {
    p1Next = initSBlock;
  } else if (p1blockType == 'Z') {
    p1Next = initZBlock;
  } else if (p1blockType == 'T') {
    p1Next = initTBlock;
  }

  if (p2blockType == 'I') {
    p2Next = initIBlock;
  } else if (p2blockType == 'J') {
    p2Next = initJBlock;
  } else if (p2blockType == 'L') {
    p2Next = initLBlock;
  } else if (p2blockType == 'O') {
    p2Next = initOBlock;
  } else if (p2blockType == 'S') {
    p2Next = initSBlock;
  } else if (p2blockType == 'Z') {
    p2Next = initZBlock;
  } else if (p2blockType == 'T') {
    p2Next = initTBlock;
  }
  
  // block is going to encased in 4x2 space
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 4; ++j) {
      out << p1Next[i][j];
    }
    out << nextSpace;
    for (int j = 0; j < 4; ++j) {
      out << p2Next[i][j];
    }
    out << endl;
  }
}


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
    out << endl;
  }

}

Text::~Text() {}
