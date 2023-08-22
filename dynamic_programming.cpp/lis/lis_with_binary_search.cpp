#include<bits/stdc++.h>
using namespace std;
int binarysearch(int *arr,int n){
    vector<int>bin;
    bin.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>bin.back())bin.push_back(arr[i]);
        else{
            bin.at(lower_bound(bin.begin(),bin.end(),arr[i])-bin.begin())=arr[i];
        }
    }
    return bin.size();
}
int main(){
  






return 0;
}