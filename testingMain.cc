#include <string>
#include <vector>
#include <iostream>
#include "block.h"
#include "jblock.h"
using namespace std;

int main(){
    Block *i = new JBlock{1, false, false};
    char rot = i->getRotation(); //'N'

    //rotate cw
    i->cwrotate();
    rot = i->getRotation(); //'E'

    i->cwrotate();
    rot = i->getRotation(); //'S'

    for(int j=0; j<4; j++){
        for(int k=0; k<4; k++){
           cout << i->getVector()[rot][j][k];
        }
        cout << endl;
    }
    return 0;
}
