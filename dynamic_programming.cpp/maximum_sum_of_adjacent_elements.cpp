#include<bits/stdc++.h>
using namespace std;
int maximumNonAdjacentSum_dp(vector<int> nums){
    int n=nums.size();
    if(n==1)return nums[0];
    if(n==2)return max(nums[0],nums[1]);
    int *arr=new int[n];
    arr[n-1]=nums.at(n-1);
    arr[n-2]=max(nums.at(n-1),nums.at(n-2));
    for(int i=n-3;i>=0;i--){
        arr[i]=max(nums.at(i)+arr[i+2],arr[i+1]);
    }
    return arr[0];
}
int mem_helper(vector<int>const &nums,int index,int n,int *arr){
    if(index>=n)return INT_MAX;
    if(arr[index]!=-1)return arr[index];
    arr[index]=max(nums.at(index)+mem_helper(nums, index+2, n, arr),mem_helper(nums,index+1,n,arr));
    return arr[index];
}
int maximumNonAdjacentSum_mem(vector<int>const& nums){
    int n=nums.size();
        if(n==1)return nums[0];
    if(n==2)return max(nums[0],nums[1]);
    int *arr=new int[n];
    for(int i=0;i<n;i++)arr[i]=-1;
    arr[n-1]=nums.at(n-1);
    arr[n-2]=max(nums.at(n-1),nums.at(n-2));
    return mem_helper(nums, 0, n, arr);

}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return maximumNonAdjacentSum_mem(nums);




}
int main(){
  






return 0;
}