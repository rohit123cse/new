#include<bits/stdc++.h>
using namespace std;
int maxprofit_dp(vector<int>const&prices,int k){
  int n=prices.size();
  // [choice][index][k]
  vector<vector<vector<int>>>store(2,vector<vector<int>>(n,vector<int>(k+1,0)));
  for(int i=0;i<k;i++)store[0][n-1][i]=prices[n-1];
  for(int i=n-2;i>=0;i--){
    for(int j=0;j<=k;j++){   //j is the no of times we can further buy
      if(j==0){  //we can't buy more, we have to just sell what we have
        store[0][i][0]=max(prices[i],store[0][i+1][0]);
        continue;
      }
      store[1][i][j]=max(-prices[i]+store[0][i+1][j-1],store[1][i+1][j]);
      store[0][i][j]=max(prices[i]+store[1][i+1][j],store[0][i+1][j]);
    }
  }
  return store[1][0][k];
}
int maxProfit(int k, vector<int>& prices) {
  return maxprofit_dp(prices,k);
}
int main(){
  






return 0;
}