#include<bits/stdc++.h>
using namespace std;
int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
  // Code here
  vector<vector<vector<int>>>adj(n,vector<vector<int>>());
  for(int i=0;i<flights.size();i++){
      vector<int>temp={flights[i][1],flights[i][2]};
      adj[flights[i][0]].push_back(temp);
  }
  queue<pair<int,pair<int,int>>>pq;
  pq.push({0,{src,0}});
  vector<int>res(n,INT_MAX);
  res[src]=0;
  while(!pq.empty()){
      pair<int,pair<int,int>>p=pq.front();pq.pop();
      int dist=p.second.second,node=p.second.first;
      int stops=p.first;
      if(stops>K)continue;
      for(int i=0;i<adj[node].size();i++){
          int val=dist+adj[node][i][1];
          if(res[adj[node][i][0]]>val){
              res[adj[node][i][0]]=val;
              pq.push({stops+1,{adj[node][i][0],val}});
          }
      }
  }if(res[dst]==INT_MAX)return -1;
  return res[dst];
}
int main(){
  






return 0;
}