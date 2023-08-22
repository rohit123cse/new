#include<bits/stdc++.h>
using namespace std;

// time complexity o(n*n)
void selection_sort(vector<int>&arr){
  int n=arr.size();
  for(int i=0;i<n-1;i++){
    int ele=INT_MAX,index=i;
    for(int j=i;j<n;j++){
      if(ele>arr[j]){
        ele=arr[j];
        index=j;
      }
    }
    swap(arr[index],arr[i]);
  }
}
int main(){
  vector<int>temp={3,1,5,3,68,4};
  selection_sort(temp);
  for(auto it:temp)cout<<it<<" ";






return 0;
}