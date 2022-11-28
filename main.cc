#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <sstream>

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


    // number of times controlled by multiplier
    if (command == "left" || commands.at("left") == command) {
      // call function
    } else if (command == "right" || commands.at("right") == command) {

    } else if (command == "down" || commands.at("down") == command) {

    } else if (command == "drop" || commands.at("drop") == command) {

    } else if (command == "clockwise" || commands.at("clockwise") == command) {

    } else if (command == "counterclockwise" || commands.at("counterclockwise") == command) {

    } else if (command == "levelup" || commands.at("levelup") == command) {

    } else if (command == "leveldown" || commands.at("leveldown") == command) {

    } else if (command == "norandom" || commands.at("norandom") == command) {

    } else if (command == "random" || commands.at("random") == command) {

    } else if (command == "sequence" || commands.at("sequence") == command) {

    } else if (command.length() == 1) {
      // more stuff
      if (command == "I") {
        // create new block each, need to know fields
      } else if (command == "J") {

      } else if (command == "L") {

      } else if (command == "O") {

      } else if (command == "S") {

      } else if (command == "Z") {

      } else if (command == "T") {

      }
    } else if (command == "restart" || commands.at("restart") == command) {
      // restart game
    }

    // when/where do we want to check lines?
    // when/where do we want to check and apply special actions?
  }  

}