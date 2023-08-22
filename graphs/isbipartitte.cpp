#include<bits/stdc++.h>
using namespace std;
bool bfs(vector<int>adj[],queue<int>&q,vector<int>&color){
  while(!q.empty()){
      int len=q.size();
      while(len--){
          int index=q.front();
          q.pop();
          int val;
          if(color[index]==-1)val=1;
          else val=color[index];
          color[index]=val;
          int col;
          if(val==1)col=2;
          else col=1;
          for(int i=0;i<adj[index].size();i++){
              int x=adj[index][i];
              if(color[x]==-1){
                  q.push(x);
                  color[x]=col;
              }
              else if(color[x]!=col)return false;
          }
      }
  }
  return true;
}
bool isBipartite(int V, vector<int>adj[]){
// Code here
int n=V;
vector<int>color(n,-1);
for(int i=0;i<n;i++){
    if(color[i]!=-1)continue;
queue<int>q;
    q.push(i);
    if(!bfs(adj,q,color))return false;
}
return true;
}
int main(){
  






return 0;
}