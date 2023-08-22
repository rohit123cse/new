#include<bits/stdc++.h>
using namespace std;
vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
  vector<vector<int>>res(n,vector<int>(2,INT_MAX));// i  color (0 is red and 1 is blue)
  res[0][0]=0;res[0][1]=0;
  vector<vector<vector<int>>>adj(n,vector<vector<int>>(2,vector<int>()));//0 is red, 1 is blue
  for(int i=0;i<redEdges.size();i++){
      adj[redEdges[i][0]][0].push_back(redEdges[i][1]);
  }
  for(int i=0;i<blueEdges.size();i++)adj[blueEdges[i][0]][1].push_back(blueEdges[i][1]);
  priority_queue<pair<int,pair<int,int>>>q;  // dist node color
  q.push({0,{0,0}}); //testing for red
  while(!q.empty()){
      pair<int,pair<int,int>>p=q.top();
      int dist=p.first,node=p.second.first,col=p.second.second;
      q.pop();
      if(col==0){   
          for(int i=0;i<adj[node][1].size();i++){
              int val=dist+1;
              int y=adj[node][1][i];
              if(val<res[y][1]){
                  res[y][1]=val;
                  q.push({val,{y,1}});
              }
          }
      }
      else{
          for(int i=0;i<adj[node][0].size();i++){
              int val=dist+1;
              int y=adj[node][0][i];
              if(val<res[y][0]){
                  res[y][0]=val;
                  q.push({val,{y,0}});
              }
          }
      }
  }
  q.push({0,{0,1}});
  while(!q.empty()){
      pair<int,pair<int,int>>p=q.top();
      int dist=p.first,node=p.second.first,col=p.second.second;
      q.pop();
      if(col==0){   
          for(int i=0;i<adj[node][1].size();i++){
              int val=dist+1;
              int y=adj[node][1][i];
              if(val<res[y][1]){
                  res[y][1]=val;
                  q.push({val,{y,1}});
              }
          }
      }
      else{
          for(int i=0;i<adj[node][0].size();i++){
              int val=dist+1;
              int y=adj[node][0][i];
              if(val<res[y][0]){
                  res[y][0]=val;
                  q.push({val,{y,0}});
              }
          }
      }
  }
  vector<int>ans(n,0);
  for(int i=0;i<n;i++){
      int a=res[i][0],b=res[i][1];
      if(a!=INT_MAX&&b!=INT_MAX)ans[i]=min(a,b);
      else if(a!=INT_MAX )ans[i]=a;
      else if(b!=INT_MAX)ans[i]=b;
      else ans[i]=-1;
  }return ans;
}
int main(){
  






return 0;
}