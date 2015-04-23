

#include <iostream>
#include "rule.h"
#include <fstream>
#include <ctime>
#include <time.h>
#include <sys/timeb.h>
using namespace std;
int ITERATION(10);

inline long getCurrentTime() { //function to get the time in millisecond (not relevant otherwise)
    timeb timebstr;
    ftime( &timebstr );
    return (long)(timebstr.time)*1000 + timebstr.millitm;
}
int main(int argc, const char * argv[]) {
    // Obtain an output file that describes the state of the game:
    ofstream out("./output.txt");
    Rule game;
    for (int l=0; l<ITERATION; l++) {
        game.NewState();
        //game.NewStateParallel();
        vector<vector<int> > board =game.getState();
        for (int i=0;i<board.size();i++){
            for (int j=0;j<board.size();j++){
                out<<board[i][j]<<'\t';
            }
            out<<'\n';
        }
        
    }
    
    //Code to obtain a comparison between parallel and serial code :
    ofstream table("./time-comparison.csv");
    table<<"Grid Size"<<","<<"Serial Time (ms)"<<","<<"Parallel Time (ms)"<<","<<"Difference Serial-Parallel (ms)"<<endl;
    for (int i=100; i<=1000; i+=50){
        cout<<"size of grid: "<<i<<'\t';
        Rule game(i,i);
        long start_time1=getCurrentTime();
        for (int j=0; j<ITERATION*10;j++){
            game.NewState();
        }
        long end_time1=getCurrentTime();
        long time_elapsed1=end_time1-start_time1;
    
        cout <<"time in millisecond for serial implementation: "<<time_elapsed1<<'\t';
        long start_time2=getCurrentTime();
        for (int j=0; j<ITERATION*10;j++){
            game.NewStateParallel();
        }
        long end_time2=getCurrentTime();
        long time_elapsed2=end_time2-start_time2;
        table<<i<<","<<time_elapsed1<<","<<time_elapsed2<<","<<time_elapsed1-time_elapsed2<<endl;
        cout <<"for parallel implementation: "<<time_elapsed2<<'\t';
        cout<<"Difference between serial and parallel: "<<time_elapsed1-time_elapsed2<<endl;
    }
    
    return 0;
}

