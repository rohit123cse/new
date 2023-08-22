#include<bits/stdc++.h>
using namespace std;
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
  vector<double>res(n,0);
  priority_queue<pair<double,int>>pq;
  pq.push({1,start});
  vector<vector<pair<int,double>>>adj(n,vector<pair<int,double>>());
  for(int i=0;i<edges.size();i++){
      pair<int,double>temp={edges[i][1],succProb[i]};
      adj[edges[i][0]].push_back(temp);
      temp.first=edges[i][0];
      adj[edges[i][1]].push_back(temp);
  }
  while(!pq.empty()){
      pair<double,int>p=pq.top();
      double prob=p.first;int node=p.second;
      pq.pop();
      for(int i=0;i<adj[node].size();i++){
          double tempprob=prob*adj[node][i].second;
          int y=adj[node][i].first;
          if(tempprob>res[y]){
              res[y]=tempprob;
              pq.push({tempprob,y});
          }
      }
  }
  return res[end];
}
int main(){
  






return 0;
}