#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <sstream>
#include "board.h"
#include "block.h"

using namespace std;

int main(int argc, char **argv) {
  bool graphicsOn = true;
  int player1 = 1;
  int player2 = 2;
  int startLevel = 0;
  string p1LevelZeroFile = "sequence1.txt";
  string p2LevelZeroFile = "sequence2.txt";
  map<string, string> commands;
  commands = {
    {"left", "left"},
    {"right", "right"},
    {"down", "down"},
    {"clockwise", "clockwise"},
    {"counterclockwise", "counterclockwise"},
    {"drop", "drop"},
    {"levelup", "levelup"},
    {"leveldown", "leveldown"},
    {"norandom", "norandom"},
    {"random", "random"},
    {"sequence", "sequence"},
    {"restart" ,"restart"}
  };
  int board1lvl = 0;
  int board2lvl = 0;
  Board* board1 = new Board(11, 18, board1lvl);
  Board* board2 = new Board(11, 18, board2lvl);
  int turnCount = 0;

  // setting the seed
  srand(7);

  // flags in the beginning, in command line
  for (int i = 0; i < argc; ++i) {
    string flag = argv[i];
    if (flag == "-text") {
      graphicsOn = false;
    } else {
      string field = argv[i+1];
      if (flag == "-seed") {
        srand(stoi(field));
      } else if (flag == "-scriptfile1") {
        p1LevelZeroFile = field;
      } else if (flag == "-scriptfile2") {
        p2LevelZeroFile = field;
      } else if (flag == "-startlevel") {
        startLevel = stoi(field);
      }
    }
  }
  // initialize two boards
  // initialize text, graphics, and set observers

// Command loop
  string command;
  int n;
  int multiplier;
  while (true) {
    cin >> command;
    
    if (command == "rename") {
      string commandName, aliasName;
      cin >> commandName;
      cin >> aliasName;

      commands[commandName] = aliasName;
    }

    // check for multiplier, then save it, and remove it
    istringstream iss{command};
    if (iss >> n) { multiplier = n; }
    int len = command.length();
    for (int i = 0; i < len; ++i) {
      if (isdigit(command[i])) {
        command.erase(i);
      } else {
        break;
      }
    }

    Board *curBoard;
    if (turnCount % 2 == 0) {
      curBoard = board1;
    }else{
      curBoard = board2;
    }

    // number of times controlled by multiplier
    if (command == "left" || commands.at("left") == command) {
      for(int i=0; i<multiplier; i++){
        if (curBoard->itsValid(-1, 0, 0)){
          curBoard->moveBlockInBoard(-1, 0, 0);
        }else{
          break;
        }
      }
    } else if (command == "right" || commands.at("right") == command) {
      for(int i=0; i<multiplier; i++){
        if (curBoard->itsValid(1, 0, 0)){
          curBoard->moveBlockInBoard(1, 0, 0);
        }else{
          break;
        }
      }
    } else if (command == "down" || commands.at("down") == command) {
      for(int i=0; i<multiplier; i++){
        if (curBoard->itsValid(0, 1, 0)){
          curBoard->moveBlockInBoard(0, 1, 0);
        }else{
          break;
        }
      }
    } else if (command == "drop" || commands.at("drop") == command) {
      bool valid = curBoard->itsValid(0, 1, 0);
      while (valid == true){
        curBoard->moveBlockInBoard(0,1,0);
        valid = curBoard->itsValid(0, 1, 0);
      }
      ////////////////////////////////////////////////////////////////////// need to check if line is cleared here
      
      ////////////////////////////////////////////////////////////////////// what if more than 1 drop
      
    } else if (command == "clockwise" || commands.at("clockwise") == command) {
      for(int i=0; i<multiplier; i++){
        if (curBoard->itsValid(0, 0, 1)){
          curBoard->moveBlockInBoard(0, 0, 1);
        }else{
          break;
        }
      }
    } else if (command == "counterclockwise" || commands.at("counterclockwise") == command) {
      for(int i=0; i<multiplier; i++){
        if (curBoard->itsValid(0, 0, -1)){
          curBoard->moveBlockInBoard(0, 0, -1);
        }else{
          break;
        }
      }
    ////////////////////////////////////////////////////////} else if (command == "levelup" || commands.at("levelup") == command) {

    ////////////////////////////////////////////////////////} else if (command == "leveldown" || commands.at("leveldown") == command) {

    ////////////////////////////////////////////////////////} else if (command == "norandom" || commands.at("norandom") == command) {

    ////////////////////////////////////////////////////////} else if (command == "random" || commands.at("random") == command) {

    ////////////////////////////////////////////////////////} else if (command == "sequence" || commands.at("sequence") == command) {

    } else if (command.length() == 1) {
      bool levelHeavy = false;

      Block *curBlock = curBoard->getCurBlock();
      bool actionHeavy = curBlock->getActionHeavy();

      int tempLevel = curBoard->getLevel();

      if(tempLevel == 3 || tempLevel == 4){
        levelHeavy == false;
      }

      // more stuff
      Block *block;
      if (command == "I") {
        // create new block each with respective fields
        block = new IBlock(tempLevel, actionHeavy, levelHeavy);
      } else if (command == "J") {
        block = new JBlock(tempLevel, actionHeavy, levelHeavy);
      } else if (command == "L") {
        block = new LBlock(tempLevel, actionHeavy, levelHeavy);
      } else if (command == "O") {
        block = new OBlock(tempLevel, actionHeavy, levelHeavy);
      } else if (command == "S") {
        block = new SBlock(tempLevel, actionHeavy, levelHeavy);
      } else if (command == "Z") {
        block = new ZBlock(tempLevel, actionHeavy, levelHeavy);
      } else if (command == "T") {
        block = new TBlock(tempLevel, actionHeavy, levelHeavy);
      }
      
    } else if (command == "restart" || commands.at("restart") == command) { // restart game
      // reset boards
      board1->reset();
      board2->reset();

      turnCount = 0;
      startLevel = 0;

      ///////////////////////////////////////////////////////////////////////////// reset blocks

      break;
    }

    // when/where do we want to check lines?
    // when/where do we want to check and apply special actions?
  }  

}
