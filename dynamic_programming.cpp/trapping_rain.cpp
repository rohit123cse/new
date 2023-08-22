#include<bits/stdc++.h>
using namespace std;
long long trappingWater(int arr[], int n){
  // code here
  vector<long long>dp(n,0);
  dp[n-1]=0;
  long long res=0;
  int maxindex=n-1;
  for(int i=n-2;i>=0;i--){
      if(arr[i]>=arr[maxindex]){
          long long temp=0;
          for(int j=i+1;j<maxindex;j++){
              temp+=(min(arr[i],arr[maxindex])-arr[j]);
          }
          dp[i]=temp+dp[maxindex];
          maxindex=i;
      }
      else{
          int j=i+1;
          long long temp=0;
          while(j<n){
              if(arr[j]>=arr[i])break;
              temp+=(arr[i]-arr[j++]);
          }
          dp[i]=temp+dp[j];
      }
      res=max(res,dp[i]);
  }
  return res;
}

int main(){






return 0;
}