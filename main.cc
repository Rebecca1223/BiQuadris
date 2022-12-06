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
#include "commandInt.h"

using namespace std;

int main(int argc, char **argv) {
  bool graphicsOn = true;
  int player = 1;
  int startLevel = 0;
  string p1LevelZeroFile = "sequence3.txt";
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
  for (int i = 1; i < argc - 1; ++i) {
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


  board1->setCurBlock((board1->getCurLevel())->createBlock());
  board2->setCurBlock((board2->getCurLevel())->createBlock());
  board1->setNextBlock((board1->getCurLevel())->createBlock());
  board2->setNextBlock((board2->getCurLevel())->createBlock());
  board1->moveBlockInBoard(0, 0, 0);
  board2->moveBlockInBoard(0, 0, 0);

// Command loop
  string command;
  int n;
  int multiplier = 1;
  CommandInt cmdInt;
  cout << endl;
  while (true) {
    bool restart = 0;
    int rowsRemoved = 0;
    Board *curBoard;
    if (turnCount % 2 == 0) {
      curBoard = board1;
      player = 1;
    }else{
      curBoard = board2;
      player = 2;
    }
    
    curBoard->notifyObservers();

    while (true) {
      int multiplier = 1;
      cout << "Player " << player <<"'s turn" << endl;
      cout << "Command: ";
      if (sequenceCommands.empty()) {
        cin >> command;
      } else {
        command = sequenceCommands.front();
        cout << command << endl;
        sequenceCommands.erase(sequenceCommands.begin());
      }
      cout << endl;

      if (command == "rename") {
        string commandName, aliasName;
        cout << "Old name: ";
        cin >> commandName;
        cout << "New name: ";
        cin >> aliasName;

        commands[commandName] = aliasName;
        continue;
      }

      // check for multiplier, then save it, and remove it
      istringstream iss{command};
      if (iss >> n) { 
        multiplier = n; 
        int len = command.length();

        for (int i = 0; i < len; ++i) {
          if (isdigit(command[i])) {
            command.erase(i, 1);
            --i;
          } else {
            break;
          }
        }
      }

      if (command.length() != 1) {
        command = cmdInt.getCommand(command);
      }

      // number of times controlled by multiplier
      if (command == "left" || commands.at("left") == command) {
        for(int i=0; i<multiplier; i++){
          if (curBoard->itsValid(-1, 0, 0)){
            curBoard->moveBlockInBoard(-1, 0, 0);
            if(curBoard->getHeavy()){
              curBoard->moveBlockInBoard(0, 1, 0);
              curBoard->moveBlockInBoard(0, 1, 0);
            }
            int level = curBoard->getLevel();
            if (level == 3 || level == 4) {
              curBoard->moveBlockInBoard(0, 1, 0);
            }
          }else{
            break;
          }
        }
        curBoard->notifyObservers();
      }
      if (command == "right" || commands.at("right") == command) {
        for(int i=0; i<multiplier; i++){
          if (curBoard->itsValid(1, 0, 0)){
            curBoard->moveBlockInBoard(1, 0, 0);
            if(curBoard->getHeavy()){
              curBoard->moveBlockInBoard(0, 1, 0);
              curBoard->moveBlockInBoard(0, 1, 0);
            }
            int level = curBoard->getLevel();
            if (level == 3 || level == 4) {
              curBoard->moveBlockInBoard(0, 1, 0);
            }
          }else{
            break;
          }
        }
        curBoard->notifyObservers();
      }
      if (command == "down" || commands.at("down") == command) {
        for(int i=0; i<multiplier; i++){
          if (curBoard->itsValid(0, 1, 0)){
            curBoard->moveBlockInBoard(0, 1, 0);
            int level = curBoard->getLevel();
            if (level == 3 || level == 4) {
              curBoard->moveBlockInBoard(0, 1, 0);
            }
          }else{
            break;
          }
          curBoard->notifyObservers();
        }
      }
      if (command == "drop" || commands.at("drop") == command) {
        int level = curBoard->getLevel();
        if (multiplier != 0) {
          bool valid = curBoard->itsValid(0, 1, 0);
          while (valid == true){
            curBoard->moveBlockInBoard(0,1,0);
            valid = curBoard->itsValid(0, 1, 0);
          }

          int row = curBoard->getCurBlock()->getY();
          
          // check if line is cleared here
          int r = row+3;
          while(r>=row){
            if(curBoard->checkFilledRow(row+3)){
              curBoard->removeRow(row+3);
              curBoard->notifyObservers();
              rowsRemoved++;
            }else{
              r--;
            }
          }

          cout << level << endl;

          if (level == 4) {
            curBoard->addPlacedBlocks();
            cout << curBoard->getPlacedBlocks() << endl;
            if (curBoard->getPlacedBlocks() % 5 == 0 && rowsRemoved == 0) {
              //drop a OneBlock
              Block* temp = curBoard->getCurBlock();
              Block* newOneBlock = new OneBlock(4);
              curBoard->setCurBlock(newOneBlock);
              curBoard->moveBlockInBoard(0,0,0);
              cout << curBoard->getCurBlock()->getType() << endl;

              bool valid = curBoard->itsValid(0, 1, 0);
              while (valid == true){
                curBoard->moveBlockInBoard(0,1,0);
                valid = curBoard->itsValid(0, 1, 0);
              }
              int row = curBoard->getCurBlock()->getY();
              int r = row+3;
              while(r>=row){
                if(curBoard->checkFilledRow(row+3)){
                  curBoard->removeRow(row+3);
                  curBoard->notifyObservers();
                  rowsRemoved++;
                }else{
                  r--;
                }
              }
              curBoard->setCurBlock(temp);
            } else {
              if (rowsRemoved > 0) {
                curBoard->resetPlacedBlocks();
              }
            }

            if (rowsRemoved >= 2) {
              cout << "Special Action!!!" << endl;
              cout << "1. Blind" << endl;
              cout << "2. Heavy" << endl;
              cout << "3. Force" << endl;
              string input;
              cin >> input;
              if(input == "1"){
                if(player == 1){
                  board2->setBlind(true);
                }else{
                  board1->setBlind(true);
                }
              }else if(input == "2"){
                if(player == 1){
                  board2->setHeavy(true);
                }else{
                  board1->setHeavy(true);
                }
              }else if(input == "3"){
                curBoard->setForce(true);
                string type;
                cout << "Enter a block type: ";
                cin >> type;
                sequenceCommands.emplace_back(type);
              }
            }
            if(curBoard->getBlind()){
              curBoard->setBlind(false);
            }if(curBoard->getHeavy()){
              curBoard->setHeavy(false);
            }if(curBoard->getForce()){
              curBoard->setForce(false);
            }
          } 
          break;
        }
      }
      if (command == "clockwise" || commands.at("clockwise") == command) {
          for(int i=0; i<multiplier; i++){
          //curBoard->moveBlockInBoard(0, 0, 1);
          if (curBoard->itsValid(0, 0, 1)){
            curBoard->moveBlockInBoard(0, 0, 1);
            int level = curBoard->getLevel();
            if (level == 3 || level == 4) {
              curBoard->moveBlockInBoard(0, 1, 0);
            }
          }else{
            break;
          }
        }
        curBoard->notifyObservers();
      }
      if (command == "counterclockwise" || commands.at("counterclockwise") == command) {
        for(int i=0; i<multiplier; i++){
          //curBoard->moveBlockInBoard(0, 0, 3);
          if (curBoard->itsValid(0, 0, 3)){
            curBoard->moveBlockInBoard(0, 0, 3);
            int level = curBoard->getLevel();
            if (level == 3 || level == 4) {
              curBoard->moveBlockInBoard(0, 1, 0);
            }
          }else{
            break;
          }
        }
        curBoard->notifyObservers();
      }
      if (command == "levelup" || commands.at("levelup") == command) {
        int level = curBoard->getLevel();
        cout << level << endl;

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
        ifstream file{fileName};

        while (file >> command) {
          sequenceCommands.emplace_back(command);
        }
        continue;

      }
      if (command.length() == 1) {
        bool levelHeavy = false;

        Block *curBlock = curBoard->getCurBlock();

        int tempLevel = curBoard->getLevel();

        if(tempLevel == 3 || tempLevel == 4){
          levelHeavy == false;
        }

        // more stuff
        Block *block;
        if (command == "I") {
          // create new block each with respective fields
          block = new IBlock(tempLevel);
        } else if (command == "J") {
          block = new JBlock(tempLevel);
        } else if (command == "L") {
          block = new LBlock(tempLevel);
        } else if (command == "O") {
          block = new OBlock(tempLevel);
        } else if (command == "S") {
          block = new SBlock(tempLevel);
        } else if (command == "Z") {
          block = new ZBlock(tempLevel);
        } else if (command == "T") {
          block = new TBlock(tempLevel);
        }

        curBoard->removeBlock();
        curBoard->setCurBlock(block);
        curBoard->moveBlockInBoard(0,0,0);
        curBoard->notifyObservers();
        
      }
      if (command == "restart" || commands.at("restart") == command) {
        // restart game
        restart = 1;
        // reset boards
        board1->reset();
        board2->reset();

        turnCount = 0;
        startLevel = 0;

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

        // reset blocks
        board1->setCurBlock((board1->getCurLevel())->createBlock());
        board2->setCurBlock((board2->getCurLevel())->createBlock());
        board1->setNextBlock((board1->getCurLevel())->createBlock());
        board2->setNextBlock((board2->getCurLevel())->createBlock());
        board1->moveBlockInBoard(0, 0, 0);
        board2->moveBlockInBoard(0, 0, 0);
        break;
      }
    }
    if (restart == 0) {
      ++turnCount;
      curBoard->setCurBlock(curBoard->getNextBlock());
      curBoard->setNextBlock(curBoard->getCurLevel()->createBlock());
      if(curBoard->itsValid(0,0,0)){
        curBoard->moveBlockInBoard(0,0,0);
      }else{
        if(player == 1){
          cout << "Player 2 wins!" << endl;
        }else{
          cout << "Player 1 wins!" << endl;
        }
        break;
      }

    }

  }
}
