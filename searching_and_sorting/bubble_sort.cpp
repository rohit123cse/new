#include<bits/stdc++.h>
using namespace std;
// time complexity o(n*n)
void bubble_sort(vector<int>&arr){
  int n=arr.size();
  for(int i=0;i<n;i++){
    for(int j=0;j<n-1;j++){
      if(arr[j]>arr[j+1])swap(arr[j],arr[j+1]);
    }
  }
}
int main(){
    vector<int>temp={3,1,5,3,68,4};
  bubble_sort(temp);
  for(auto it:temp)cout<<it<<" ";






return 0;
}