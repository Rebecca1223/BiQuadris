#include "jblock.h"
#include "block.h"
#include <string>

JBlock::~JBlock() {}

JBlock::JBlock(int levelGen, bool actionHeavy, bool levelHeavy) : Block(1, 15, 4, levelGen, 'N', actionHeavy, levelHeavy) {}

void JBlock::rotate(){

}

void JBlock::moveHorz(std::string dir){

}

void JBlock::down(){
    
}

void JBlock::drop(){
    
}
