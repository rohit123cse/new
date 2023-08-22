#include<bits/stdc++.h>
using namespace std;
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.

    int m=matrix.size();
    int n=matrix.at(0).size();
    if(m==1&&n==1)return matrix[0][0];
    if(m==1){
        int max=matrix[0][0];
        for(int i=1;i<n;i++){
            if(matrix[0][i]>max)max=matrix[0][i];
        }
        return max;
    }
    if(n==1){
        int max=matrix[0][0];
        for(int i=1;i<m;i++){
            max+=matrix[i][0];
        }return max;
    }
    int **arr=new int*[m];
    for(int i=0;i<m;i++)arr[i]=new int[n];
    for(int i=0;i<n;i++)arr[m-1][i]=matrix[m-1][i];
    int res=INT_MIN;
    for(int i=m-2;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            
            if(j==n-1){
                arr[i][j]=matrix[i][j]+max(arr[i+1][j],arr[i+1][j-1]);
                continue;
            }
            if(j==0){
                arr[i][j]=matrix[i][j]+max(arr[i+1][j],arr[i+1][j+1]);
                continue;
            }
            arr[i][j]=matrix[i][j]+max(arr[i+1][j],max(arr[i+1][j-1],arr[i+1][j+1]));
        }
    }
    for(int i=0;i<n;i++){
        if(arr[0][i]>res)res=arr[0][i];
    }
    for(int i=0;i<m;i++)delete[]arr[i];
    delete []arr;
    return res;


}
int main(){
  






return 0;
}