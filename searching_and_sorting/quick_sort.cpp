#include<bits/stdc++.h>
using namespace std;

// time complexity o(nlogn) space complexity o(logn)
int pivot(vector<int>&arr,int low,int high){
  if(low>=high-1)return low;
  int val=arr[low];
  int i=low+1,j=high-1;
  while(i<j){
    if(arr[i]>=val&&arr[j]<=val){
      swap(arr[i],arr[j]);
      i++;j--;
    }
    else{
      if(arr[i]<=val)i++;
      if(arr[j]>=val)j--;
    }
  }
  swap(arr[low],arr[j]);
  return j;
}
void quick_sort(vector<int>&arr,int low,int high){
  if(low>=high-1)return;
  if(low==high+2){
    if(arr[low]>arr[high-1])swap(arr[low],arr[high-1]);
    return;
  }
  int index=pivot(arr,low,high);
  quick_sort(arr,low,index);
  quick_sort(arr,index+1,high);
}
int main(){
  vector<int>temp={3,1,5,3,68,4};
  quick_sort(temp,0,temp.size());
  for(auto it:temp)cout<<it<<" ";






return 0;
}