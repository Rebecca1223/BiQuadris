#include "graphics.h"
#include "board.h"
#include <string>
#include "window.h"
#include <vector>
#include "unit.h"
#include "block.h"

using namespace std;

Graphics::Graphics(Board* b1, Board* b2, int bh, int bw, int wh, int ww):
b1{b1}, b2{b2}, boardHeight{bh}, boardWidth{bw}, windowHeight{wh}, windowWidth{ww}, display{new Xwindow{windowWidth * 10, windowHeight * 10}} {
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

  this->build();
}

void Graphics::build() {
  string p1Level = "Level:    " + to_string(b1->getLevel());
  string p2Level = "Level:    " + to_string(b2->getLevel());
  string p1HiScore = "HiScore:  " + to_string(b1->getHiScore());
  string p2HiScore = "HiScore:  " + to_string(b2->getHiScore());
  string p1Score = "Score:    " + to_string(b1->getCurScore());
  string p2Score = "Score:    " + to_string(b2->getCurScore());

  display->drawString(windowWidth, 20, p1Level);
  display->drawString(windowWidth, 40, p1HiScore);
  display->drawString(windowWidth, 60, p1Score);
  display->drawString(windowWidth - 10 + 340, 20, p2Level);
  display->drawString(windowWidth - 10 + 340, 40, p2HiScore);
  display->drawString(windowWidth - 10 + 340, 60, p2Score);

  display->fillRectangle(windowWidth - 10, 80, boardWidth*25, boardHeight*25, 1);
  display->fillRectangle(windowWidth - 10 + 330, 80, boardWidth*25, boardHeight*25, 1);

  display->drawString(windowWidth, boardHeight*25 + 100, "Next: ");
  display->drawString(windowWidth - 10 + 340, boardHeight*25 +100, "Next: ");

}

void Graphics::notify() {

  p1Screen.clear();
  p2Screen.clear();



  for (int i = 0; i < boardHeight; ++i) {
    vector<char> p1row;
    vector<char> p2row;
    for (int j = 0; j < boardWidth; ++j) {
      p1row.emplace_back(b1->getBoard()[i][j].getBlockType());
      p2row.emplace_back(b2->getBoard()[i][j].getBlockType());
    }
    p1Screen.emplace_back(p1row);
    p2Screen.emplace_back(p2row);
  }

  display->fillRectangle(windowWidth, 10, 80, 15, 0);
  display->fillRectangle(windowWidth, 30, 80, 15, 0);
  display->fillRectangle(windowWidth, 50, 80, 15, 0);
  display->fillRectangle(windowWidth - 10 + 340, 10, 80, 15, 0);
  display->fillRectangle(windowWidth - 10 + 340, 30, 80, 15, 0);
  display->fillRectangle(windowWidth - 10 + 340, 50, 80, 15, 0);

  // level, hiscore, score
  string p1Level = "Level:    " + to_string(b1->getLevel());
  string p2Level = "Level:    " + to_string(b2->getLevel());
  string p1HiScore = "HiScore:  " + to_string(b1->getHiScore());
  string p2HiScore = "HiScore:  " + to_string(b2->getHiScore());
  string p1Score = "Score:    " + to_string(b1->getCurScore());
  string p2Score = "Score:    " + to_string(b2->getCurScore());

  display->drawString(windowWidth, 20, p1Level);
  display->drawString(windowWidth, 40, p1HiScore);
  display->drawString(windowWidth, 60, p1Score);
  display->drawString(windowWidth - 10 + 340, 20, p2Level);
  display->drawString(windowWidth - 10 + 340, 40, p2HiScore);
  display->drawString(windowWidth - 10 + 340, 60, p2Score);

  int topLeft = 80;
  int p1topLeft = windowWidth - 10;
  int p1topRight = boardWidth*25 + p1topLeft;
  int p2topLeft = windowWidth - 10 + 330;
  int p2topRight = boardWidth*25 + p2topLeft;

  int botLeft = boardHeight*25 + topLeft;


    for (int i = topLeft; i < botLeft; i += 25) {
      for (int j = p1topLeft; j < p1topRight; j += 25) {
        int x = (i - 65)/25;
        int y = (j - 60)/25;
        if (p1Screen[x][y] == 'I') display->fillRectangle(j, i, 25, 25, 2);
        else if (p1Screen[x][y] == 'J') display->fillRectangle(j, i, 25, 25, 3);
        else if (p1Screen[x][y] == 'L') display->fillRectangle(j, i, 25, 25, 4);
        else if (p1Screen[x][y] == 'O') display->fillRectangle(j, i, 25, 25, 5);
        else if (p1Screen[x][y] == 'S') display->fillRectangle(j, i, 25, 25, 6);
        else if (p1Screen[x][y] == 'Z') display->fillRectangle(j, i, 25, 25, 7);
        else if (p1Screen[x][y] == 'T') display->fillRectangle(j, i, 25, 25, 8);
        else if (p1Screen[x][y] == '*') display->fillRectangle(j, i, 25, 25, 9);
        else display->fillRectangle(j, i, 25, 25, 1);
      }
      for (int j = p2topLeft; j < p2topRight; j+= 25) {

        int x = (i - 80)/25;
        int y = (j - 395)/25;
        if (p2Screen[x][y] == 'I') display->fillRectangle(j, i, 25, 25, 2);
        else if (p2Screen[x][y] == 'J') display->fillRectangle(j, i, 25, 25, 3);
        else if (p2Screen[x][y] == 'L') display->fillRectangle(i, j, 25, 25, 4);
        else if (p2Screen[x][y] == 'O') display->fillRectangle(j, i, 25, 25, 5);
        else if (p2Screen[x][y] == 'S') display->fillRectangle(j, i, 25, 25, 6);
        else if (p2Screen[x][y] == 'Z') display->fillRectangle(j, i, 25, 25, 7);
        else if (p2Screen[x][y] == 'T') display->fillRectangle(j, i, 25, 25, 8);
        else if (p2Screen[x][y] == '*') display->fillRectangle(j, i, 25, 25, 9);
        else display->fillRectangle(j, i, 25, 25, 1);
      }
    }
  if (b1->getBlind()) {
    for (int i = topLeft + 3*25; i < topLeft + 13*25; i += 25) {
      for (int j = p1topLeft + 3*25; j < p1topLeft + 10*25; j += 25) {
        display->fillRectangle(i, j, 25, 25, 1);
      }
    }
  } else if (b2->getBlind()) {
    for (int i = topLeft + 3*25; i < topLeft + 13*25; i += 25) {
      for (int j = p2topLeft + 3*25; j < p2topLeft + 10*25; j += 25) {
        display->fillRectangle(i, j, 25, 25, 1);
      }
    }
  }


  char p1blockType = b1->getNextBlock()->getType();
  char p2blockType = b2->getNextBlock()->getType();
  vector<vector<char>> p1Next;
  vector<vector<char>> p2Next;
  int p1Colour = 2;
  int p2Colour = 2;
  
  if (p1blockType == 'I') {
    p1Next = initIBlock;
    p1Colour = 2;
  } else if (p1blockType == 'J') {
    p1Next = initJBlock;
    p1Colour = 3;
  } else if (p1blockType == 'L') {
    p1Next = initLBlock;
    p1Colour = 4;
  } else if (p1blockType == 'O') {
    p1Next = initOBlock;
    p1Colour = 5;
  } else if (p1blockType == 'S') {
    p1Next = initSBlock;
    p1Colour = 6;
  } else if (p1blockType == 'Z') {
    p1Next = initZBlock;
    p1Colour = 7;
  } else if (p1blockType == 'T') {
    p1Next = initTBlock;
    p1Colour = 8;
  }

  if (p2blockType == 'I') {
    p2Next = initIBlock;
    p2Colour = 2;
  } else if (p2blockType == 'J') {
    p2Next = initJBlock;
    p2Colour = 3;
  } else if (p2blockType == 'L') {
    p2Next = initLBlock;
    p2Colour = 4;
  } else if (p2blockType == 'O') {
    p2Next = initOBlock;
    p2Colour = 5;
  } else if (p2blockType == 'S') {
    p2Next = initSBlock;
    p2Colour = 6;
  } else if (p2blockType == 'Z') {
    p2Next = initZBlock;
    p2Colour = 7;
  } else if (p2blockType == 'T') {
    p2Next = initTBlock;
    p2Colour = 8;
  }

  // print next block
  for (int i = boardHeight*25 + 100; i < boardHeight*25 + 150; i += 25) {
    for (int j = windowWidth; j < windowWidth+100; j += 25) {
      int x = (i - 550)/25;
      int y = (j - 75)/25;
      if (p1Next[x][y] == ' ') display->fillRectangle(j, i, 25, 25, 0);
      else  {
        display->fillRectangle(j, i, 25, 25, p1Colour);
      }
    }
    for (int j = windowWidth - 10 + 340; j < windowWidth + 430; j += 25) {
      int x = (i - 550)/25;
      int y = (j - 405)/25;
      if (p2Next[x][y] == ' ') display->fillRectangle(j, i, 25, 25, 0);
      else display->fillRectangle(j, i, 25, 25, p2Colour);
    }
  }
}

Graphics::~Graphics() {}

