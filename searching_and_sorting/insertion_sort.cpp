#include<bits/stdc++.h>
using namespace std;
void insertion_sort(vector<int>&arr){
  int n=arr.size();
  for(int i=1;i<n;i++){
    int j=i;
    while(j>0&&arr[j]<arr[j-1]){
      swap(arr[j],arr[j-1]);
      j--;
    }
  }
}
int main(){
    vector<int>temp={3,1,5,3,68,4};
  insertion_sort(temp);
  for(auto it:temp)cout<<it<<" ";






return 0;
}