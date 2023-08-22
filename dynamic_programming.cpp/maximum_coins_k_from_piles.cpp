// There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.

// In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.

// Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom, and a positive integer k, return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.
#include<bits/stdc++.h>
using namespace std;
int result(vector<vector<int>>const &piles,int k,int index,vector<vector<int>>&store,int const n){
  if(index==n)return 0;
  if(store[k][index]!=-1)return store[k][index];
  int maxi=result(piles,k,index+1,store,n);
  int temp=0;
  for(int i=0;i<k&&i<piles[index].size();i++){
      temp+=piles[index][i];
      maxi=max(temp+result(piles,k-i-1,index+1,store,n),maxi);
  }
  return store[k][index]=maxi;
}
int maxValueOfCoins(vector<vector<int>>& piles, int k) {
  int col=piles.size();
  vector<vector<int>>store(k+1,vector<int>(col,-1)); 
  for(int i=0;i<col;i++)store[0][i]=0;
  return result(piles,k,0,store,col);
}
int main(){
  






return 0;
}