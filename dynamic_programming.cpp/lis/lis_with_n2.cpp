#include<bits/stdc++.h>
using namespace std;
int mem(vector<vector<int>>&store,int *arr,int index,int n,int prev){
    if(index==n)return 0;
    if(store[prev][index]!=-1)return store[prev][index];
    int res=mem(store,arr,index+1,n,prev);
    int take=mem(store,arr,index+1,n,index);
    if(prev==n)res=max(res,1+take);
    else if(arr[index]>arr[prev])res=max(res,1+take);
    return store[prev][index]=res;
}

//printing lis

void print_lis(int *arr,int n){
    int hash[n];
    hash[0]=0;
    int max_len=INT_MIN;
    int max_index=0;
    vector<int>store(n,0);
    store[0]=1;
    max_index=0;
    max_len=1;
    for(int i=1;i<n;i++){
        int len=0;
        int index=0;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                if(store[j]>len){
                    len=store[j];
                    index=j;
                }
            }
        }
        if(len==0){
            store[i]=1;
            hash[i]=i;
        }
        else{
            store[i]=1+len;
            hash[i]=index;
        }
        if(store[i]>max_len){
            max_len=store[i];
            max_index=i;
        }
    }
    vector<int>print;
    while(hash[max_index]!=max_index){
        print.push_back(arr[max_index]);
        max_index=hash[max_index];
    }
    print.push_back(arr[max_index]);
    reverse(print.begin(),print.end());
    for(int i=0;i<print.size();i++)cout<<print[i]<<" ";
}





int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    print_lis(arr, n);
    return 0;
    if(n==0||n==1)return n;
    vector<vector<int>>store(n+1,vector<int>(n,-1));
    return mem(store,arr,0,n,n);
    //dp
    int result[n];
    result[n-1]=1;
    int maxi=-10000;
    for(int i=n-2;i>=0;i--){
        int val=arr[i];
        int res=0;
        for(int j=i+1;j<n;j++){
            if(arr[j]>val){
                res=max(res,result[j]);
            }
        }
        result[i]=1+res;
        maxi=max(result[i],maxi);
    }
    return maxi;
}

int main(){
  
vector<int>vin;





return 0;
}