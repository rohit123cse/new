#include<bits/stdc++.h>
using namespace std;
//doesnt work for negative weight cycle
//O(E*log(V))
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
  // Code here
  int n=V,s=S;
  vector<int>res(n,INT_MAX);
  res[s]=0;
  // priority_queue<pair<int,int>>pq;
  // pq.push({0,s}); 
  // while(!pq.empty()){
  //     pair<int,int>p=pq.top();
  //     pq.pop();
  //     int node=p.second;
  //     int dist=p.first;
  //     for(int i=0;i<adj[node].size();i++){
  //         int val=dist+adj[node][i][1];
  //         if(val<res[adj[node][i][0]]){
  //             res[adj[node][i][0]]=val;
  //             pq.push({val,adj[node][i][0]});
  //         }
  //     }
  // }
  // return res;
  
  //set implementation
  //set gives us the advantage of removing elements in set for which an optimized sol is already found although takes O(logn) time
  set<pair<int,int>>st;
  pair<int,int>temp={0,s};
  st.insert(temp);
  while(!st.empty()){
      pair<int,int>p=*(st.begin());
      st.erase(p);
      int dist=p.first;
      int node=p.second;
      for(int i=0;i<adj[node].size();i++){
          int val=dist+adj[node][i][1];
          if(val<res[adj[node][i][0]]){
              pair<int,int>in={val,adj[node][i][0]};
              if(res[adj[node][i][0]]!=INT_MAX){
              pair<int,int>er={res[adj[node][i][0]],adj[node][i][0]};
              st.erase(er);
              }
              st.insert(in);
              res[adj[node][i][0]]=val;
          }
  }
      }return res; 
}
int main(){
  vector<pair<int,int>>vec(2,{-1,INT_MAX});







return 0;
}