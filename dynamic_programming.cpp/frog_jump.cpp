#include<bits/stdc++.h>
using namespace std;
int memoization_frogjump(int index,int n,vector<int>const &heights,int *arr){
    if(index==n)return INT_MAX;
    if(arr[index]!=-1)return arr[index];
    int val=heights[index];
    int a=abs(val-heights[index+1]);
    int b=abs(val-heights[index+2]);
    arr[index]=min(a+memoization_frogjump(index+1,n,heights,arr),b+memoization_frogjump(index+2,n,heights,arr));
    return arr[index];
}
int mem_frogjump(int n,vector<int>const &heights){
    int *arr=new int[n];
    for(int i=0;i<n;i++)arr[i]=-1;
    arr[n-1]=0;
    arr[n-2]=abs(heights[n-2]-heights[n-1]);
    return memoization_frogjump(0,n,heights,arr);
}
int recursive_frogjump(int n,vector<int>const &heights,int index){
    if(index==n-1)return 0;
    if(index==n-2)return abs(heights[n-2]-heights[n-1]);
    int val=heights[index];
    int a=abs(val-heights[index+1]);
    int b=abs(val-heights[index+2]);
    return min(a+recursive_frogjump(n, heights, index+1),b+recursive_frogjump(n, heights, index+2));

}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    return recursive_frogjump(n,heights,0);
    return mem_frogjump(n,heights);
    
    int *arr=new int[n];
    arr[n-1]=0;
    arr[n-2]=abs(heights[n-2]-heights[n-1]);
    for(int i=n-3;i>=0;i--){
        int val=heights[i];
        int a=abs(val-heights[i+1]);
        int b=abs(val-heights[i+2]);
        arr[i]=min((a+arr[i+1]),(b+arr[i+2]));
    }
    return arr[0];

}

//frog jump with k jumps
int frogjump_k(int n,int *cost,int index,int *store,int const k){
    if(index==n-1)return 0;
    if(index>=n)return INT_MAX;
    if(store[index]!=-1)return store[index];
    int min=INT_MAX;
    for(int i=1;i<=k&&i+index<n;i++){
        int temp=abs(cost[index]-cost[index+i]);
        temp+=frogjump_k(n,cost,index+i,store,k);
        if(temp<min)min=temp;
    }
    store[index]=min;
    return store[index];
}



int main(){
    int n,k;
    cin>>n>>k;
    int cost[n];
    int store[n];
    for(int i=0;i<n;i++)store[i]=-1;
    for(int i=0;i<n;i++)cin>>cost[i];
    cout<<frogjump_k(n,cost,0,store,k);
    
    
return 0;
}