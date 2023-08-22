#include<bits/stdc++.h>
int Mod=1e9+7;
using namespace std;
int mem(string &s,string &t,int sindex,int tindex,vector<vector<int>>&store){
  if(store[sindex][tindex]!=-1)return store[sindex][tindex];
  int take=0;
  if(s[sindex]==t[tindex]){
      if(tindex==t.size()-1)take=1;
        else take=mem(s,t,sindex+1,tindex+1,store);
  }
  int nottake=mem(s,t,sindex+1,tindex,store);
  return store[sindex][tindex]=nottake+take;

}
int dp(string s,string t){
  vector<vector<int>>store(s.size()+1,vector<int>(t.size()+1,0));
  int col=t.size(),row=s.size();
  for(int j=col-1;j>=0;j--){
      for(int  i=row-1;i>=0;i--){
          if(j==col-1){
              if(t[j]==s[i])store[i][j]=1+store[i+1][j];
              else store[i][j]=store[i+1][j];
              continue;
          }
          if(s[i]==t[j])store[i][j]=store[i+1][j+1];
          store[i][j]+=store[i+1][j];
          store[i][j]=store[i][j]%Mod;
      }
  }
  return store[0][0];
}


int numDistinct(string s, string t) {
  return dp(s,t);
  vector<vector<int>>store(s.size()+1,vector<int>(t.size()+1,-1));
  store[s.size()][t.size()]=0;
  for(int i=0;i<=t.size();i++)store[s.size()][i]=0;
  for(int i=0;i<s.size();i++)store[i][t.size()]=0;
  return mem(s,t,0,0,store);
  
}
int main(){
  






return 0;
}