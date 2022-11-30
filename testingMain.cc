#include <string>
#include <vector>
#include <iostream>
#include "block.h"
#include "iblock.h"
using namespace std;

int main(){
    Block *i = new IBlock{1, false, false};
    char rot = i->getRotation();
    cout << rot << endl;
    i->rotate();
    rot = i->getRotation();
    cout << rot << endl;
    if(rot == 'N'){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                cout << i->getVector()[0][j][k];
            }
            cout << endl;
        }
    }else if(rot == 'E'){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                cout << i->getVector()[1][j][k];
            }
            cout << endl;
        }
    }else if(rot == 'S'){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                cout << i->getVector()[0][j][k];
            }
            cout << endl;
        }
    }else if(rot == 'W'){
        for(int j=0; j<4; j++){
            for(int k=0; k<4; k++){
                cout << i->getVector()[1][j][k];
            }
            cout << endl;
        }
    }
    return 0;
}
