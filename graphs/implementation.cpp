/*Graph construction using Adjacency Matrix*/
#include<bits/stdc++.h>
using namespace std;
void deletearr(int**arr,int n){
  for(int i=0;i<n;i++)delete arr[i];
  delete arr;
}
void print(int const **edges,int const n){
  for(int i=0;i<n;i++){
    cout<<i<<" : ";
    for(int j=0;j<n;j++){
      if(edges[i][j]==1)cout<<j<<" ";
    }
    cout<<endl;
  }
}
void dfs_helper(int **edges,int n,int sv,vector<int>&visited){
  if(visited[sv])return ;
  visited[sv]=1;
  cout<<sv<<" ";
  for(int i=0;i<n;i++){
    if(edges[sv][i]==1)dfs_helper(edges,n,i,visited);
  }
}
void dfs(int **edges,int n){
  vector<int>visited(n,0);
  for(int i=0;i<n;i++)dfs_helper(edges,n,i,visited);
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
  int n,e;
  cin>>n>>e;
  int**edges=new int*[n];
  for(int i=0;i<n;i++){
    edges[i]=new int[n];
    for(int j=0;j<n;j++)edges[i][j]=0;
  }
  for(int i=0;i<e;i++){
    int x,y;
    cin>>x>>y;
    if(x>=n||y>=n||x<0||y<0)continue;
    if(x==y)continue;
    edges[x][y]=1;  // It is an undirected graph and hence 1->2 then 2->1;
    edges[y][x]=1;    
  }
  unordered_map<int,int>visited;
  print(edges,n);
  deletearr(edges,n);






return 0;
}