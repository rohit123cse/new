#include<bits/stdc++.h>
using namespace std;
int lower_bound(vector<int>&arr,int low,int high,int const &target){
  if(low>=high)return -1;
  if(low==high-1){
    if(arr[low]>=target)return low;
    return -1;
  }
  int mid=(high+low)/2;
  if(arr[mid]>=target){
    int index=lower_bound(arr,low,mid,target);
      if(index!=-1)return index;
      return mid;
  }
  else return lower_bound(arr,mid+1,high,target);
}

int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int index= lower_bound(arr, 0, arr.size(), x);
	if(index==-1)return arr.size();
}

int main(){






return 0;
}