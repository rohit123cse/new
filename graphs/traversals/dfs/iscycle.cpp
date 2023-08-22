#include<bits/stdc++.h>
using namespace std;
  bool res(vector<int>&visited,int index,int prev,vector<int>adj[]){
    if(visited[index])return true;
    visited[index]=1;
    for(int i=0;i<adj[index].size();i++){
        int val=adj[index][i];
        if(val==index||val==prev)continue;
        if(res(visited,val,index,adj))return true;
    }
    return false;
  }
  bool isCycle(int V, vector<int> adj[]) {
    // Code here
    int n=V;
    vector<int>visited(n,0);
    for(int i=0;i<n;i++){
        if(visited[i])continue;
        if(res(visited,i,-1,adj))return true;
    }
    return false;
}
int main(){
  






return 0;
}