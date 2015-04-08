#include "rule.h"
using namespace std;

Rule::Rule(){
    m_sizegrid=100;
    m_current.resize(m_sizegrid+2);
    for (int l=0;l<(m_sizegrid+2);l++) m_current[l].resize(m_sizegrid+2);
    
    for (int i=0; i<=m_sizegrid+1;i++){
        m_current[0][i]=m_current[i][0]=0;
        m_current[m_sizegrid+1][i]=m_current[i][m_sizegrid+1]=0;
        
    }
    for (int i=1;i<=m_sizegrid;i++){
        for (int j=1;j<=m_sizegrid;j++){
            m_current[i][j]=rand()%2;
        }
        
    }
    
    
}

Rule::Rule(int size, std::vector< std::vector< int > > init){
    m_sizegrid=size;
    m_current.resize(m_sizegrid+2);
    for (int l=0;l<(m_sizegrid+2);l++) m_current[l].resize(m_sizegrid+2);
    for (int i=0; i<=m_sizegrid+1;i++){
        m_current[0][i]=m_current[i][0]=0;
        m_current[m_sizegrid+1][i]=m_current[i][m_sizegrid+1]=0;
        
    }
    for (int i=1;i<=m_sizegrid;i++){
        for (int j=1;j<=m_sizegrid;j++){
            m_current[i][j]=init[i][j];
        }
        
    }
    
    
}

vector< vector< int> > Rule::getState(){
    vector< vector<int> > board(m_sizegrid, vector<int>(m_sizegrid));
    for (int i=1;i<=m_sizegrid;i++){
        for (int j=1;j<=m_sizegrid;j++){
            board[i-1][j-1]=m_current[i][j];
        }
        
    }

    
    return board;
}


void Rule::NewState(){
     std::vector<std::vector<int > > m_new(m_sizegrid+2,vector<int>(m_sizegrid+2)) ;
    
    for (int i=1;i<=m_sizegrid;i++){
        for (int j=1;j<=m_sizegrid;j++){
            int sum= m_current[i-1][j-1]+m_current[i-1][j]+m_current[i-1][j+1]+m_current[i][j-1]+m_current[i][j+1]+m_current[i+1][j-1]+m_current[i+1][j]+m_current[i+1][j+1]+m_current[i][j];
            if (sum==3) m_new[i][j]=1;
            else if (sum==4) m_new[i][j]=m_current[i][j];
                else m_new[i][j]=0;
        }
        
    }
    for (int i=0; i<=m_sizegrid+1;i++){
        m_new[0][i]=m_new[i][0]=0;
        m_new[m_sizegrid+1][i]=m_new[i][m_sizegrid+1]=0;
        
    }
    m_current.clear();
    m_current=m_new;
    m_new.clear();
}

Rule::~Rule(){
    m_current.clear();
    }
