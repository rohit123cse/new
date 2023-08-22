#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&visited,vector<vector<int>>const &grid,int const &n,int const &m,int i,int j,set<pair<int,int>>&store,int const&refi,int const &refj){
  if(i<0||i==n||j<0||j==m)return;
  if(visited[i][j])return;
  if(grid[i][j]==0)return;
  visited[i][j]=1;
  pair<int,int>temp={i-refi,j-refj};
  store.emplace(temp);
  dfs(visited,grid,n,m,i+1,j,store,refi,refj);
  dfs(visited,grid,n,m,i-1,j,store,refi,refj);
  dfs(visited,grid,n,m,i,j-1,store,refi,refj);
  dfs(visited,grid,n,m,i,j+1,store,refi,refj);
}
int countDistinctIslands(vector<vector<int>>& grid) {
    // code here
    set<set<pair<int,int>>>ans;
    int n=grid.size(),m=grid[0].size();
    vector<vector<int>>visited(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]){
                if(!visited[i][j]){
                    set<pair<int,int>>store;
                    dfs(visited,grid,n,m,i,j,store,i,j);
                    ans.emplace(store);
                }
            }
        }
    }
    return ans.size();
}
int main(){
  






return 0;
}