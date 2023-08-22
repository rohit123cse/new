#include<bits/stdc++.h>
using namespace std;  //low is inclusive and high is exclusive
int binary_search(int low,int high,vector<int>&nums,int target){
    if(high<=low)return -1;
    if(high-low==1){
        if(nums[low]==target)return low;
        return -1;
    }
    int mid=(high+low)/2;
    if(nums[mid]==target)return mid;
    int a=binary_search(low,mid,nums,target);
    if(a!=-1)return a;
    int b=binary_search(mid,high,nums,target);
    if(b!=-1)return b;
    return -1;
}
int main(){
  vector<int>nums={5,7,7,8,8,10};
  cout<<lower_bound(nums.begin(),nums.end(),8)-nums.begin();
  cout<<upper_bound(nums.begin(),nums.end(),8)-nums.begin();
  
  cout<<binary_search(0,4,nums,5);






return 0;
}