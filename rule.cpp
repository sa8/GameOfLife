#include "rule.h"
using namespace std;

Rule::Rule(){
    m_sizeX=100;
    m_sizeY=100;
    m_current.resize(m_sizeX+2);
    for (int l=0;l<(m_sizeX+2);l++) m_current[l].resize(m_sizeY+2);//increase the size of the "board" to make it easier to calculate states (don't need to differentiate edge or not edge)
    
    for (int i=0; i<=m_sizeX+1;i++){
         m_current[i][0]=m_current[i][m_sizeY+1]=0;}
    for (int i=0; i<=m_sizeY+1;i++){
        m_current[m_sizeX+1][i]=m_current[0][i]=0;
    }
    
    for (int i=1;i<=m_sizeX;i++){
        for (int j=1;j<=m_sizeY;j++){
            m_current[i][j]=rand()%2; //by default create a random initial state
        }
        
    }
    
    
}

Rule::Rule(int sizeX,int sizeY, std::vector< std::vector< int > > init){
    m_sizeX=sizeX;
    m_sizeY=sizeY;
    m_current.resize(m_sizeX+2);
    for (int l=0;l<(m_sizeX+2);l++) m_current[l].resize(m_sizeY+2);
    for (int i=0; i<=m_sizeX+1;i++){
        m_current[i][0]=m_current[i][m_sizeY+1]=0;}
    for (int i=0; i<=m_sizeY+1;i++){
        m_current[m_sizeX+1][i]=m_current[0][i]=0;
    }
    for (int i=1;i<=m_sizeX;i++){
        for (int j=1;j<=m_sizeY;j++){
            m_current[i][j]=init[i][j];
        }
        
    }
    
    
}

vector< vector< int> > Rule::getState(){
    vector< vector<int> > board(m_sizeX, vector<int>(m_sizeY));
    for (int i=1;i<=m_sizeX;i++){
        for (int j=1;j<=m_sizeY;j++){
            board[i-1][j-1]=m_current[i][j];//get the current state without the "edges" that I made to make my code easier
        }
        
    }

    
    return board;
}


void Rule::NewState(){
     std::vector<std::vector<int > > m_new(m_sizeX+2,vector<int>(m_sizeY+2)) ;
    
    for (int i=1;i<=m_sizeX;i++){
        for (int j=1;j<=m_sizeY;j++){
            int sum= m_current[i-1][j-1]+m_current[i-1][j]+m_current[i-1][j+1]+m_current[i][j-1]+m_current[i][j+1]+m_current[i+1][j-1]+m_current[i+1][j]+m_current[i+1][j+1]+m_current[i][j];
            if (sum==3) m_new[i][j]=1;
            else if (sum==4) m_new[i][j]=m_current[i][j];
                else m_new[i][j]=0;
        }
        
    }
    for (int i=0; i<=m_sizeX+1;i++){
        m_new[i][0]=m_new[i][m_sizeY+1]=0;
        
    }
    for (int i=0; i<=m_sizeY+1;i++){
        m_new[0][i]=m_new[m_sizeX+1][i]=0;}
    
    m_current.clear();
    m_current=m_new;
    m_new.clear();
}

Rule::~Rule(){
    m_current.clear();
    }
