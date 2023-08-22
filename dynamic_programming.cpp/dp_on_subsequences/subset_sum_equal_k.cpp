#include<bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.

    //works only on positive values;
    vector<vector<int>>store(k+1,vector<int>(n,0));
    for(int i=0;i<n;i++)store[k][i]=1;
    for(int i=0;i<k;i++){
        int index=i+arr[n-1];
        if(index==k)store[i][n-1]=1;
    }
    for(int j=n-2;j>=0;j--){
        for(int i=k-1;i>=0;i--){
            int index=i+arr[j];
            if(index>k)store[i][j]=store[i][j+1];
            else{
                if(index==k)store[i][j]=1+store[i][j+1];
                else{
                    store[i][j]=store[index][j+1]+store[i][j+1];
                }

            }
        }
    }
    return store[0][0];

    // vector<vector<int>>store(2,vector<int>(n,0));
    // store[0][n-1]=0;
    // store[1][n-1]=arr[n-1];
    // for(int j=n-2;j>=0;j--){
    //     store[0][j]=store[0][j+1]+store[1][j+1];
    //     store[1][j]=arr[j]+store[0][j+1]+store[]
    // }
}