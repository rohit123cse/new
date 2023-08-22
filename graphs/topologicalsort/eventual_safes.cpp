#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<bool>&isterminal,vector<bool>&visited,int index,vector<int>adj[]){
    if(visited[index])return isterminal[index];
    visited[index]=1;
    if(adj[index].size()==0)return isterminal[index]=true;
    for(int i=0;i<adj[index].size();i++){
        if(!dfs(isterminal,visited,adj[index][i],adj))return isterminal[index]=false;
    }
    return isterminal[index]=true;
}
vector<int> dfs_helper(int V, vector<int> adj[]) {
    // code here
    int n=V;
    vector<bool>isterminal(n,false);
    vector<bool>visited(n,0);
    vector<int>res;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(isterminal,visited,i,adj);
        }
        if(isterminal[i])res.push_back(i);
    }
    return res;
}
int main(){
  






return 0;
}