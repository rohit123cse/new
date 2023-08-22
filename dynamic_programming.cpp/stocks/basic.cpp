#include<bits/stdc++.h>
using namespace std;
// Given an array of stock prices on n days, figure the maximum profit that can be obtained by buying and selling the stocks once
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n=prices.size();
    int max=prices[n-1];
    int profit=0;
    for(int i=n-2;i>=0;i--){
        if(max-prices[i]>profit)profit=max-prices[i];
        if(prices[i]>max)max=prices[i];
    }
    return profit;


    // int dp[n];
    // dp[n-1]=prices[n-1];
    // int profit=INT_MIN;
    // int max=dp[n-1];
    // for(int i=n-2;i>=0;i--){

    // }

    // int min=prices[0],maxdiff=0,max=prices[0];
    // for(int i=0;i<prices.size();i++){
    //     if(min>prices[i]){
    //         max=prices[i];
    //         min=prices[i];
    //         continue;
    //     }
    //     if(max<prices[i]){
    //         max=prices[i];
    //         if(max-min>maxdiff)maxdiff=max-min;
    //     }        
    // }
    // return maxdiff;
}
int main(){
  

  




return 0;
}