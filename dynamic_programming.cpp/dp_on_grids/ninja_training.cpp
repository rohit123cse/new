#include<bits/stdc++.h>
using namespace std;

int ninja_training(int **merit,int n){
  int **arr=new int*[3];
  for(int i=0;i<3;i++){
    arr[i]=new int[n];
  }
  for(int i=0;i<3;i++)arr[i][n-1]=merit[i][n-1];
  for(int j=n-2;j>=0;j--){
    for(int i=0;i<3;i++){
      int val=merit[i][j];
      int max=0;
      for(int k=0;k<3;k++){
        if(k==i)continue;
        if(arr[k][j+1]>max)max=merit[k][j+1];
      }
      arr[i][j]=val+max;
    }
  }
  int res= max(arr[0][0],max(arr[1][0],arr[2][0]));
  for(int i=0;i<3;i++)delete []arr[i];
  delete []arr; 
  return res;
}


int main(){
  int n;
  cin>>n;
  int **arr=new int*[3];
  for(int i=0;i<3;i++){
    arr[i]=new int[n];
    for(int j=0;j<n;j++)cin>>arr[i][j];
  }
  cout<<ninja_training(arr,n);





return 0;
}