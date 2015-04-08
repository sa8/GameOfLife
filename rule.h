#ifndef __GameOfLife__rule__
#define __GameOfLife__rule__

#include <stdio.h>
#include <iostream>
#include <vector>


class Rule{
    
public:
    Rule();
    Rule(int size, std::vector<std::vector<int > > init);
    void NewState();
    std::vector<std::vector<int> > getState();
    ~Rule();
    
    
private:
    int m_sizegrid;
    std::vector<std::vector<int> > m_current;
   
    
  
   
   
   
    
    
    
};

#endif /* defined(__GameOfLife__rule__) */

