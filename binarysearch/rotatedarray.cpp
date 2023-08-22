#include<bits/stdc++.h>
using namespace std;
int rotate(vector<int>&arr,int low,int high){
    if(low==high)return low;
    if(low+1==high){
        if(arr[low]<=arr[high])return low;
        return high;
    }
    int mid=(low+high)/2;
    if(arr[mid]<arr[mid-1])return mid;
    if(arr[mid]<arr[high])return rotate(arr, low, mid-1);
    return rotate(arr, mid+1, high);
}
int main(){
  vector<int>A={31,44,56,0,10,13};
  int index=rotate(A,0,5);
      int a=lower_bound(A.begin(),A.begin()+index,56)-A.begin();
      int b=upper_bound(A.begin(),A.begin()+index,56)-A.begin();;
      cout<<a<<" "<<b;





return 0;
}