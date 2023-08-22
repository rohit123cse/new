#include<bits/stdc++.h>
using namespace std;
int  check(int k,int n,vector<int>&arr){
	vector<vector<int>>store(k+1,vector<int>(n,0));
    // for(int i=0;i<n;i++)store[k][i]=1;
    for(int i=k;i>=0;i--){
        if(i==k){
            if(arr[n-1]==0){
                if(n==1){
                    if(k==0)store[k][n-1]=1;
                    else store[k][n-1]=0;
                }
                else store[k][n-1]=2;
            }
            else store[k][n-1]=0;
            continue;
        }
        int index=i+arr[n-1];
        if(index==k){
            store[i][n-1]=1;
            // break;
        }
        // else if(index<k)store[i][n-1]=store[index][n-1];
    }
    for(int j=n-2;j>=0;j--){
        for(int i=k;i>=0;i--){
            if(i==k){
                if(arr[j]==0){
                    if(store[i][j+1]==0)store[i][j]=1;
                    else store[i][j]=2*store[i][j+1];
                }
                else store[i][j]=store[i][j+1];
                continue;
            }
            int index=i+arr[j];
            if(index>k)store[i][j]=store[i][j+1];
            else{
                if(index==k)store[i][j]=1+store[index][j]+store[i][j+1];
                else{
                    if(arr[j]==0)store[index][j]=2*store[index][j+1];
                    else store[i][j]=store[index][j+1]+store[i][j+1];
                }

            }
        }
    }
    return store[0][0];
}
int main(){
  






return 0;
}