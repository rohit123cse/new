#include<bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>>& grid) {
    // Code here
    int m=grid.size(),n=grid[0].size();
    int fresh=0;
    int flag=0;
    queue<pair<int,int>>q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1)fresh++;
            else if(grid[i][j]==2)q.push({i,j});
        }
    }
    int time=0;
    vector<vector<int>>visited(m,vector<int>(n,0));
    while(!q.empty()){
        if(fresh==0)return time;
        int len=q.size();
        flag=1;
        while(len--){
            pair<int,int>p=q.front();
            q.pop();
            int x=p.first,y=p.second;
            visited[x][y]=1;
            if(x>0){
                if(!visited[x-1][y]){
                    if(grid[x-1][y]==1){
                        flag=0;fresh--;
                        grid[x-1][y]=2;
                        q.push({x-1,y});
                    }
                }
            }
            if(x<m-1){
                if(!visited[x+1][y]){
                    if(grid[x+1][y]==1){
                        flag=0;fresh--;
                        grid[x+1][y]=2;
                        q.push({x+1,y});
                    }
                }
            }
            if(y>0){
                if(!visited[x][y-1]){
                    if(grid[x][y-1]==1){
                        flag=0;fresh--;
                        grid[x][y-1]=2;
                        q.push({x,y-1});
                    }
                }
            }
            if(y<n-1){
                if(!visited[x][y+1]){
                    if(grid[x][y+1]==1){
                        flag=0;fresh--;
                        grid[x][y+1]=2;
                        q.push({x,y+1});
                    }
                }
            }
        }
        if(flag)return -1;
        time++;
    }
    return time;
}
int main(){
  






return 0;
}