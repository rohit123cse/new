#include<bits/stdc++.h>
using namespace std;
int helper(int *arr,int n){  
  if(arr[n]!=-1)return arr[n];
  int a=helper(arr,n-1);int b=helper(arr,n-2);
  if(INT_MAX-a<b)return 0;
  else arr[n]=a+b;
  return arr[n];
}
int return_fibonacci(int n){
  n--;
  if(n<=1)return 1;
  int *arr=new int[n+1];
  for(int i=0;i<n+1;i++)arr[i]=-1;
  arr[0]=1;
  arr[1]=1;
  return helper(arr,n);
}

// in this case, same can be done iteratively
int iter_fibo(int n){
  n--;
  if(n<=1)return n;
  int *arr=new int[n+1];
  arr[0]=1;
  arr[1]=1;
  for(int i=2;i<n+1;i++){
    arr[i]=arr[i-1]+arr[i-2];
  }
  return arr[n];
  

}
int main(){
  cout<<iter_fibo(11);






return 0;
}