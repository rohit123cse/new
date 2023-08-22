#include<bits/stdc++.h>
using namespace std;
vector<int> divisibleSet(vector<int> &arr){
  // Write your code here.
  int n=arr.size();
  sort(arr.begin(),arr.end());
  vector<int>hash(n,0),store(n,1);
  int hashindex=0;
  int maxindex=0;
  for(int i=1;i<n;i++){
      hashindex=i;
      if(arr[i]==0)continue;
      int x=0;
      for(int j=0;j<i;j++){
          if(arr[j]==0)continue;
          if(arr[i]%arr[j]==0){
              if(store[j]>x){
                  x=store[j];
                  hashindex=j;
              }
          }
      }
      hash[i]=hashindex;
      store[i]+=x;
      if(store[i]>store[maxindex])maxindex=i;
  }
  hashindex=maxindex;
  vector<int>div;
  while(hash[hashindex]!=hashindex){
      div.push_back(arr[hashindex]);
      hashindex=hash[hashindex];
  }
  div.push_back(arr[hashindex]);
  return div;
}
int main(){
  






return 0;
}