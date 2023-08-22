#include<bits/stdc++.h>
using namespace std;
/* 
Topological Sorting
Works only in Directed Acyclic graph
Linear ordering: if there is an edge between u and v, then u always appears before v
Multiple linear ordering may exits 
*/
bool dfs_helper(vector<int>&visited,vector<int>&currvisit,int index,vector<int>adj[]){
  if(currvisit[index])return true;
  if(visited[index]){
      return false;
  }
  visited[index]=1;currvisit[index]=1;
  for(int i=0;i<adj[index].size();i++){
      if(dfs_helper(visited,currvisit,adj[index][i],adj))return true;
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
      if(dfs_helper(visited,currvisit,i,adj))return true;
  }
  return false;
}
void dfs(vector<int>&visited,int index,vector<int>adj[],stack<int>&s){
  if(visited[index])return;
  visited[index]=1;
  for(int i=0;i<adj[index].size();i++)dfs(visited,adj[index][i],adj,s);
  s.push(index);
}
vector<int> topoSort(int V, vector<int> adj[]) 
{
  // code here
  vector<int>ans;
  if(isCyclic(V,adj))return ans;    
  stack<int>s;
  int n=V;
  vector<int>visited(n,0);
  for(int i=0;i<n;i++){
      if(!visited[i])dfs(visited,i,adj,s);
  }
  while(!s.empty()){
      ans.push_back(s.top());
      s.pop();
  }
  return ans;
}
int main(){
  






return 0;
}