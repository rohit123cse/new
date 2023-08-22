#include<bits/stdc++.h>
using namespace std;

int temp(vector<int>&arr,int low,int high,int const &target){
	if(low>=high)return -1;
	if(low==high-1){
		if(arr[low]>target)return low;
		return -1;
	}
	int mid=(high+low)/2;
	if(arr[mid]>target){
		int index=temp(arr,low,mid,target);
		if(index!=-1)return index;
		return mid;
	}
	else return temp(arr,mid+1,high,target);
}


int upper_bound(vector<int> &arr, int x, int n){
	// Write your code here.	
	int index=temp(arr,0,n,x);
	if(index!=-1)return index;
	return n;
}
int main(){
  






return 0;
}