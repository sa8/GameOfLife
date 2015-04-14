

#include <iostream>
#include "rule.h"
#include <fstream>
using namespace std;
int ITERATION(10);

int main(int argc, const char * argv[]) {
    // insert code here...
    ofstream out("./output.txt");
    Rule game;
    for (int l=0; l<ITERATION; l++) {
        game.NewState();
        vector<vector<int> > board =game.getState();
        for (int i=0;i<board.size();i++){
            for (int j=0;j<board.size();j++){
                out<<board[i][j]<<'\t';
            }
            out<<'\n';
        }
        
    }
    
    return 0;
}

