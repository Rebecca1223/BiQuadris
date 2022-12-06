#ifndef _COMMANDINT_H
#define _COMMANDINT_H
#include <string>
#include <vector>

class CommandInt {
  std::string command;
  std::string left = "left";
  std::string right = "right";
  std::string down = "down";
  std::string clockwise = "clockwise";
  std::string counterclockwise = "counterclockwise";
  std::string drop = "drop";
  std::string levelup = "levelup";
  std::string leveldown = "leveldown";
  std::string norandom = "norandom";
  std::string random = "random";
  std::string sequence = "sequence";
  std::string restart = "restart";

  public:
    CommandInt();
    std::string getCommand(std::string input);
    ~CommandInt();

};

#endif
