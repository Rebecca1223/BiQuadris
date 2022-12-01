#include "text.h"

Text::Text(Board* b1, Board* b2, int width, int height):
b1{b1}, b2{b2}, width{width}, height{height} {}

void Text::notify() {

}

// blindEffect is called somehwere, in notify?, 

// player is the player that gets blinded
void Text::blindEffect(int player) {
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

  // calculate space between p1Screen and p2Screen
  // print the blindScreen 
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      if (player == 1) {
        out << blindScreen[i][j];
      } else {
        out << p1Screen[i][j];
      }
    }
  }
  // space in between them?
  for (int i = 0; i < height; ++i) {
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
