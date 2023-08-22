#include<bits/stdc++.h>
using namespace std;

int unique_paths(int **arr,int row,int col){
  if(row==1||col==1)return 1;
  int res[row][col];
  res[row-1][col-1]=0;
  for(int i=col-2;i>=0;i--)res[row-1][i]=1;
  for(int i=row-2;i>=0;i--)res[i][col-1]=1;
  for(int i=row-2;i>=0;i--){
    for(int j=col-2;j>=0;j--){
      arr[i][j]=max(arr[i+1][j],arr[i][j+1]);
    }
  }
  return res[0][0];
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    int mod=1e9+7;
    int temp=n;
    n=m;
    m=temp;
    int arr[m][n];
    arr[m-1][n-1]=1;
    for(int i=n-2;i>=0;i--){
        if(mat[m-1][i]==-1)arr[m-1][i]=0;
        else arr[m-1][i]=arr[m-1][i+1];
    }
    for(int i=m-2;i>=0;i--){
        if(mat[i][n-1]==-1)arr[i][n-1]=0;
        else arr[i][n-1]=arr[i+1][n-1];
    }
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            if(mat[i][j]==-1)arr[i][j]=0;
            else{
                arr[i][j]=(arr[i+1][j]+arr[i][j+1])%mod;                
            }
        }
    }
    return arr[0][0];
}


int main(){
  






return 0;
}