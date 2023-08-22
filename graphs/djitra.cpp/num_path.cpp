#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;

int countPaths(int n, vector<vector<int>>& roads) {
  // code here
  vector<vector<vector<int>>>adj(n,vector<vector<int>>());  // node,dist
  for(int i=0;i<roads.size();i++){
      vector<int>temp={roads[i][1],roads[i][2]};
      adj[roads[i][0]].push_back(temp);
      temp[0]=roads[i][0];
      adj[roads[i][1]].push_back(temp);
  }
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
  vector<unsigned long long>res(n,18446744073709551615);
  vector<int>count(n,0);
  count[0]=1;
  res[0]=0;
  pq.push({0,0});   //dist  source;
  while(!pq.empty()){
      pair<int,int> it=pq.top();
      pq.pop();
      int node=it.second,dist=it.first;
      for(int i=0;i<adj[node].size();i++){
          int val=dist+adj[node][i][1];
          int y=adj[node][i][0];
          if(res[y]>val){
              res[y]=val;
              count[y]=count[node];
              pq.push({val,y});
          }
          else if(res[y]==val){
              int totcount=0;
              for(int j=0;j<adj[y].size();j++){
                  int tempdist=res[adj[y][j][0]]+adj[y][j][1];
                  if(tempdist==val){
                      totcount+=count[adj[y][j][0]];
                      totcount%=mod;
                  }
              }
              count[y]=totcount;
          }
      }
  }
  return count[n-1];
  
}
int main(){
  set<int>s;
  s.insert(1);
  s.insert(3);
  s.insert(5);
  cout<<distance(s.begin(),s.lower_bound(3));






return 0;
}