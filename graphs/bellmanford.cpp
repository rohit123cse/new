#include<bits/stdc++.h>

using namespace std;
//works on graphs with negative edges weights with no negative cycle
//O(V*E)
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
  // Code here
  int n=V;
  vector<int>res(n,1e8);
  res[S]=0;
  for(int x=0;x<n-1;x++){
  for(int i=0;i<edges.size();i++){
      int u=edges[i][0];
      int v=edges[i][1];
      int dist=edges[i][2];
      if(res[u]!=1e8&&res[u]+dist<res[v]){
          res[v]=res[u]+dist;
      }
  }
  }
  for(int i=0;i<edges.size();i++){
                  int u=edges[i][0];
      int v=edges[i][1];
      int dist=edges[i][2];
      if(res[u]!=1e8&&res[u]+dist<res[v]){
          vector<int>temp={-1};
          return temp;
      }
  }
  return res;
}
int main(){
  






return 0;
}