#include<bits/stdc++.h>
using namespace std;

//blind brute force recursive


int recur_min(int n){
  if(n==1)return 0;
  if(n<=3)return 1;
  if(n%3==0)return 1+recur_min(n/3);
  int a=recur_min(n-1);
  int b=INT_MAX;
  if(n%2==0)b=recur_min(n/2);
  return 1+min(a,b);
}
//iter
int iter_min(int n){
  	int res=n;

	int count=0;
	while(res!=1){
		if(res==2||res==3){
			count++;
			break;
		}
		if(res%3==0){
			res/=3;
			count++;
			continue;
		}
		if(res%3==2){
			if(res%2==0){
				res/=2;
				count++;
			}
			else{
				res--;
				count++;
			}
			continue;
		}
		else{
			res--;
			res/=3;
			count+=2;
		}
		
	}
	return count;}

//memoization
  int helper_memoization(int *arr,int n){
    if(arr[n]!=-1)return arr[n];
    if(n%3==0){
      arr[n]=1+helper_memoization(arr,n/3);
      return arr[n];
    }
    int a=helper_memoization(arr,n-1);
    int b=INT_MAX;
    if(n%2==0)b=helper_memoization(arr,n/2);
    arr[n]=1+min(a,b);
    return arr[n];
  }
  int memoization_min(int n){
    if(n==1)return 0;
    if(n<=3)return 1;    
    int *arr=new int[n+1];
    for(int i=0;i<n+1;i++)arr[i]=-1;
    arr[0]=INT_MAX;
    arr[1]=0;
    arr[2]=1;
    arr[3]=1;
    return helper_memoization(arr,n);

  }
  int dp_min(int n){
    if(n==1)return 0;
    if(n<=3)return 1;
    int *arr=new int[n+1];
    arr[0]=0;
    arr[1]=0;
    arr[2]=1;
    arr[3]=1;
    int point=4;
    while(point<n+1){
      if(point%3==0){
        arr[point]=1+arr[point/3];
        point++;
        continue;
      }
      int a=arr[point-1];
      int b=INT_MAX;
      if(point%2==0)b=arr[point/2];
      arr[point]=1+min(a,b);
      point++;
    }
    return arr[n];
  }

int main(){
  cout<<iter_min(12);
  cout<<endl<<memoization_min(12)<<endl;
  cout<<recur_min(12)<<endl;
  cout<<dp_min(12)<<endl;
  






return 0;
}