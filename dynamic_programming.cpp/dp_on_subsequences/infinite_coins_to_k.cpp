#include<bits/stdc++.h>
using namespace std;
/*Given specific denominations of coins and a targert, return the number of ways you can reach the target, you can take the same coins multiple times */
long countWaysToMakeChange(int *denominations, int n, int value)
{
  //Write your code here
  vector<vector<long long>>store(value+1,vector<long long>(n,0));
  for(int i=0;i<n;i++)store[value][i]=1;
  for(int i=value-1;i>=0;i--){
    long long val=denominations[n-1]+i;
    if(val>value)store[i][n-1]=-1;
    else if(val==value)store[i][n-1]=1;
    else{
      long long x=store[val][n-1];
      if(x==-1)store[i][n-1]=-1;
      else store[i][n-1]=x;
    }
  }
  for(int j=n-2;j>=0;j--){
    for(int i=value-1;i>=0;i--){
        long long a=store[i][j+1];
        if(denominations[j]+i>value){
            store[i][j]=a;
        }
        else if(denominations[j]+i==value){
            if(a==-1)store[i][j]=1;
            else store[i][j]=1+a;
        }
        else{
            long long b=store[denominations[j]+i][j];
            if(a==-1){
                if(b==-1)store[i][j]=-1;
                else store[i][j]=b;
            }
            else{
                if(b==-1)store[i][j]=a;
                else store[i][j]=a+b;
            }
        }
    }
  }
  if(store[0][0]==-1)return 0;
  else return store[0][0];
}
int main(){
  






return 0;
}