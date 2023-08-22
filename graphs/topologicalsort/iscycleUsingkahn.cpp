#include<bits/stdc++.h>
using namespace std;
/* if a directed graph contains a cycle, then topo sort of such a graph can't exist
in kahn algo any node of the cycle will always have degree>=1 and hence wont give topo sort
*/
bool kahn(int n,vector<int>adj[]){
  vector<int>order(n,0);
  for(int i=0;i<n;i++){
      for(int j=0;j<adj[i].size();j++)order[adj[i][j]]++;
  }
  queue<int>q;
  for(int i=0;i<n;i++){
      if(order[i]==0)q.push(i);
  }
  vector<int>res;
  while(!q.empty()){
      int val=q.front();
      q.pop();
      res.push_back(val);
      for(int i=0;i<adj[val].size();i++){
          order[adj[val][i]]--;
          if(order[adj[val][i]]==0)q.push(adj[val][i]);
      }
  }
  return res.size()!=n;
}
int main(){
  






return 0;
}