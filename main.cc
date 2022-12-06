#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <sstream>
#include <fstream>
#include "board.h"
#include "block.h"
#include "text.h"
#include "graphics.h"

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
  vector<string> sequenceCommands;
  int board1lvl = 0;
  int board2lvl = 0;
  Board* board1 = new Board(11, 18, board1lvl);
  Board* board2 = new Board(11, 18, board2lvl);
  int turnCount = 0;
  Text textDisplay{board1, board2, 11, 18};
  //Graphics* graphicDisplay = nullptr;
  board1->attach(&textDisplay);
  board2->attach(&textDisplay);
  // setting the seed
  srand(7);

  // flags in the beginning, in command line
  for (int i = 1; i < argc; ++i) {
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
  //if (graphicsOn) {
  //  graphicDisplay
  //}


  if (startLevel == 0) {
    board1->setCurLevel(startLevel, false, 0, p1LevelZeroFile);
    board2->setCurLevel(startLevel, false, 0, p2LevelZeroFile);
  } else if (startLevel == 1 || startLevel == 2) {
    board1->setCurLevel(startLevel, false, 0);
    board2->setCurLevel(startLevel, false, 0);
  } else {
    board1->setCurLevel(startLevel, true, 0);
    board2->setCurLevel(startLevel, true, 0);
  }

  // get first new blocks???
board1->setCurBlock((board1->getCurLevel())->createBlock());
//cout << board1->getCurBlock()->getType() << endl;
board2->setCurBlock((board2->getCurLevel())->createBlock());
//cout << board2->getCurBlock()->getType() << endl;
board1->setNextBlock((board1->getCurLevel())->createBlock());
//cout << board1->getNextBlock()->getType() << endl;
board2->setNextBlock((board2->getCurLevel())->createBlock());
board1->moveBlockInBoard(0, 0, 0);
board2->moveBlockInBoard(0, 0, 0);

// Command loop
  string command;
  int n;
  int multiplier = 1;
  while (true) {

    Board *curBoard;
    if (turnCount % 2 == 0) {
      curBoard = board1;
    }else{
      curBoard = board2;
    }
    curBoard->notifyObservers();
   // curBoard->moveBlockInBoard(0, 0, 0);

/*
    for(int i=0; i<4; i++){
      for(int j=0; j<4; j++){
        int tempp = curBoard->getCurBlock()->getRotation();
        cout << curBoard->getCurBlock()->getVector()[tempp][i][j];
      } 
      cout << endl;
    } */
    
    while (true) {
      cout << "Command: ";
      if (sequenceCommands.empty()) {
        cin >> command;
      } else {
        command = sequenceCommands.front();
        sequenceCommands.erase(sequenceCommands.begin());
      }

      if (command == "rename") {
        string commandName, aliasName;
        cin >> commandName;
        cin >> aliasName;

        commands[commandName] = aliasName;
      }

      // check for multiplier, then save it, and remove it
      istringstream iss{command};
      if (iss >> n) { 
        multiplier = n; 
        int len = command.length();
        for (int i = 0; i < len; ++i) {
          if (isdigit(command[i])) {
            command.erase(i);
          } else {
            break;
          }
        }
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
        curBoard->notifyObservers();
      }
      if (command == "right" || commands.at("right") == command) {
        cout << "something" << endl;
        for(int i=0; i<multiplier; i++){
          cout << "something1" << endl;
          if (curBoard->itsValid(1, 0, 0)){
            cout << "valid" << endl;
            curBoard->moveBlockInBoard(1, 0, 0);
            cout << "aftermove" << endl;
          }else{
            cout << "else" << endl;
            break;
          }
        }
        curBoard->notifyObservers();
      }
      if (command == "down" || commands.at("down") == command) {
        for(int i=0; i<multiplier; i++){
          if (curBoard->itsValid(0, 1, 0)){
            curBoard->moveBlockInBoard(0, 1, 0);
          }else{
            break;
          }
          curBoard->notifyObservers();
        }
      }
      if (command == "drop" || commands.at("drop") == command) {
        bool valid = curBoard->itsValid(0, 1, 0);
        while (valid == true){
          curBoard->moveBlockInBoard(0,1,0);
          valid = curBoard->itsValid(0, 1, 0);
          
        }
        int row = curBoard->getCurBlock()->getY();
        // check if line is cleared here
        if(curBoard->checkFilledRow(row)){
          curBoard->removeRow();
          curBoard->notifyObservers();
        }
        break;
         

        // what if more than 1 drop
        
      }
      if (command == "clockwise" || commands.at("clockwise") == command) {
        for(int i=0; i<multiplier; i++){
          if (curBoard->itsValid(0, 0, 1)){
            curBoard->moveBlockInBoard(0, 0, 1);
          }else{
            break;
          }
        }
        curBoard->notifyObservers();
      }
      if (command == "counterclockwise" || commands.at("counterclockwise") == command) {
        for(int i=0; i<multiplier; i++){
          if (curBoard->itsValid(0, 0, -1)){
            curBoard->moveBlockInBoard(0, 0, -1);
          }else{
            break;
          }
        }
        curBoard->notifyObservers();
      }
      if (command == "levelup" || commands.at("levelup") == command) {
        int level = curBoard->getLevel();

        for (int i = 0; i < multiplier; ++i) {
          if (level == 4) break;
          ++level;
        }
        curBoard->setCurLevel(level, true, 1); // true for level 3 + 4, set random to false using norandom
        continue;

      }
      if (command == "leveldown" || commands.at("leveldown") == command) {
        int level = curBoard->getLevel();

        for (int i = 0; i < multiplier; ++i) {
          if (level == 0) break;
          --level;
        }
        curBoard->setCurLevel(level, true, 1); // same logic as levelup
        continue;

      }
      if (command == "norandom" || commands.at("norandom") == command) {
        string file;
        cin >> file;
        int level = curBoard->getLevel();

        if (level == 3 || level == 4) curBoard->setCurLevel(level, false, 0, file);
        continue;

      }
      if (command == "random" || commands.at("random") == command) {
        int level = curBoard->getLevel();

        if (level == 3 || level == 4) curBoard->setCurLevel(level, true, 0);
        continue;

      }
      if (command == "sequence" || commands.at("sequence") == command) {
        string fileName;
        string command;
        cin >> fileName;
        ifstream file;

        while (file >> command) {
          sequenceCommands.emplace_back(command);
        }
        continue;

      }
      if (command.length() == 1) {
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

        curBoard->setCurBlock(block);
        
      }
      if (command == "restart" || commands.at("restart") == command) {
        // restart game

        // reset boards
        board1->reset();
        board2->reset();

        turnCount = 0;
        startLevel = 0;

        // reset blocks
        
        break;
      }
    }
    ++turnCount;
    curBoard->setCurBlock(curBoard->getNextBlock());
    curBoard->setNextBlock(curBoard->getCurLevel()->createBlock());

  }

    // when/where do we want to check lines?
    // when/where do we want to check and apply special actions?
  

}
