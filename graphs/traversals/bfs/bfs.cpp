#include<bits/stdc++.h>
using namespace std;
/*flood fill*/
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
  // Code here 
  int m=image.size(),n=image[0].size();
  vector<vector<int>>visited(m,vector<int>(n,0));
  int same=image[sr][sc];
  queue<pair<int,int>>q;
      pair<int,int>p={sr,sc};
      q.push(p);
  while(!q.empty()){
      int len=q.size();
      while(len--)
      {
      pair<int,int>p=q.front();
      q.pop();
      int x=p.first,y=p.second;
      if(visited[x][y]||(image[x][y]!=same))continue;
      image[x][y]=newColor;
      visited[x][y]=1;
      if(x>0)q.push({x-1,y});
      if(x<m-1)q.push({x+1,y});
      if(y>0)q.push({x,y-1});
      if(y<n-1)q.push({x,y+1});
      }
  }
  
  return image;
}



void bfs_helper(int **edges,int n,queue<int>&q,vector<int>&visited){
  int len=q.size();
  while(len--){
    int val=q.front();
    q.pop();
    for(int i=0;i<n;i++){
      if(edges[val][i]==1){
        if(visited[i])continue;
        q.push(i);
        cout<<i<<" ";    //first prints then calls below level
        visited.at(i)=1;
      }
    }
  }
  if(!q.empty())bfs_helper(edges,n,q,visited);
}
void bfs(int **edges,int n){
  vector<int>visited(n,0);
  queue<int>q;
    if(n==0)return;
  for(int i=0;i<n;i++){
    if(visited[i])continue;
    q.push(i);
    visited[i]=1;
    cout<<i<<" ";
    bfs_helper(edges,n,q,visited);
  }
}
int main(){
  






return 0;
}