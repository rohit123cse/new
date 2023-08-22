#include<bits/stdc++.h>
using namespace std;

// time complexity o(nlogn) space complexity o(n)
void merge(vector<int>&arr,int const & low,int const &mid,int const & high){
  int point1=low,point2=mid;
  vector<int>temp;
  while(point1<mid&&point2<high){
    if(arr[point1]<=arr[point2])temp.push_back(arr[point1++]);
    else temp.push_back(arr[point2++]);
  }
  while(point1<mid)temp.push_back(arr[point1++]);
  while(point2<high)temp.push_back(arr[point2++]);
  for(int i=low;i<high;i++)arr[i]=temp[i-low];
  return;
}

void merge_sort(vector<int>&arr,int low,int high){    //low is inclusive high is exclusive
  if(low>=high-1)return;
  if(low==high-2){
    if(arr[low]>arr[high-1])swap(arr[low],arr[high-1]);
    return;
  }
  int mid=(high+low)/2;
  merge_sort(arr,low,mid);
  merge_sort(arr,mid,high);
  merge(arr,low,mid,high);
}
int main(){
  vector<int>temp={3,1,5,2,2,1};
  merge_sort(temp,0,temp.size());
  for(auto it:temp)cout<<it<<" ";









return 0;
}