#include<bits/stdc++.h>
using namespace std;

void makeone(vector<vector<int>>const & grid,vector<vector<int>>&res,int row,int col,int m,int n,int &nos){
    if(row<0||row==m||col<0||col==n)return;
    if(res[row][col]==1)return;
    if(grid[row][col]==1){
        res[row][col]=1;
        nos++;
        makeone(grid,res,row+1,col,m,n,nos);
        makeone(grid,res,row,col+1,m,n,nos);
        makeone(grid,res,row-1,col,m,n,nos);
        makeone(grid,res,row,col-1,m,n,nos);
    }
}
int numEnclaves(vector<vector<int>>& grid) {
    int row=grid.size();
    int col=grid.at(0).size();
    vector<vector<int>>res(row,vector<int>(col,0));
    int nos=0;
    for(int i=0;i<col;i++)makeone(grid,res,0,i,row,col,nos);
    for(int i=0;i<row;i++)makeone(grid,res,i,col-1,row,col,nos);
    for(int i=0;i<col;i++)makeone(grid,res,row-1,i,row,col,nos);
    for(int i=0;i<row;i++)makeone(grid,res,i,0,row,col,nos);
    int nos1=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==1)nos1++;
        }
    }
    return nos1-nos;
}