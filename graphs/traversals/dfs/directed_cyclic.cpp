#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<int>&visited,vector<int>&currvisit,int index,vector<int>adj[]){
  if(currvisit[index])return true;
  if(visited[index]){
      return false;
  }
  visited[index]=1;currvisit[index]=1;
  for(int i=0;i<adj[index].size();i++){
      if(dfs(visited,currvisit,adj[index][i],adj))return true;
  }
  currvisit[index]=0;
  return false;
}
bool isCyclic(int V, vector<int> adj[]) {
  // code here
  int n=V;
  vector<int>visited(n,0);
  for(int i=0;i<n;i++){
      if(visited[i])continue;
      vector<int>currvisit(n,0);
      if(dfs(visited,currvisit,i,adj))return true;
  }
  return false;
}
int main(){
  






return 0;
}