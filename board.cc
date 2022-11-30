// Header files
#include "board.h"

using namespace std;

// build() initiates board elements
void Board::build() {
    if (mainBoard.size() != 0) mainBoard.clear(); // If there exists a previous board

    // fill up the board

}

// Board Constructor
Board::Board(int width, int height, int curLevel) : width{width}, height{height}, hiScore{0}, curScore{0}, curLevel{curLevel}, blind{false}, heavy{false}, force{false}, curBlock{nullptr}, nextBlock{nullptr}, curLevel{nullptr} {
	this->build();
}

// Board Destructor
Board::~Board() {
    delete curBlock;
    delete nextBlock;
    delete curLevel;
}

void Board::reset() {
    ...
}

void Board::placePiece(int x, int y, char type) {
    ...
}

void Board::removeRow() {
    ...
}

bool Board::itsValid(int hShift, int vShift, int rotation) {
    ...
}

bool Board::checkFilledRow() {
    ...
}
