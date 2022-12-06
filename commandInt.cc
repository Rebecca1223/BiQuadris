#include "commandInt.h"
#include <string>
#include <iostream>

using namespace std;

CommandInt::CommandInt() {}

string CommandInt::getCommand(std::string input) {
  int index = 0;
  string firstChar = input.substr(0, 1);
  if (firstChar == "l") {
    index = 3;
    string substring = input.substr(0, index);
    if (substring == left.substr(0, index)) {
      return left;
    }
    index = 6;
    substring = input.substr(0, index);
    if (substring == levelup.substr(0, index)) {
      return levelup;
    } else {
      return leveldown;
    }
  } else if (firstChar == "r") {
    index = 2;
    string substring = input.substr(0, index);
    if (substring == right.substr(0, index)) {
      return right;
    } else if (substring == random.substr(0, index)) {
      return random;
    } else {
      return restart;
    }
  } else if (firstChar == "d") {
    index = 2;
    string substring = input.substr(0, index);
    if (substring == down.substr(0, index)) {
      return down;
    } else {
      return drop;
    }
  } else if (firstChar == "c") {
    index = 2;
    string substring = input.substr(0, index);
    if (substring == clockwise.substr(0, index)) {
      return clockwise;
    } else {
      return counterclockwise;
    }
  } else if (firstChar == "n") {
    return norandom;
  } else {
    return sequence;
  }
}

CommandInt::~CommandInt() {}
