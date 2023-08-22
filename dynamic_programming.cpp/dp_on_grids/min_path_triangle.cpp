#include<bits/stdc++.h>
using namespace std;

int minPath_mem(int m,int row,int col,vector<vector<int>>&res,vector<vector<int>>const &triangle){
	if(row==m||col==row+1)return INT_MAX;
	if(row==m-1){
		res[row][col]=triangle[row][col];
		return res[row][col];
	}
	if(res[row][col]!=-1)return res[row][col];
	res[row][col]=triangle[row][col]+min(minPath_mem(m,row+1,col,res,triangle),minPath_mem(m, row+1, col+1, res, triangle));
	return res[row][col];

}
int minPath_mem(vector<vector<int>>&triangle,int n){
	vector<vector<int>>res;
	for(int i=0;i<n;i++){
		vector<int>temp;
		res.push_back(temp);
		for(int j=0;j<=i;j++)res[i].push_back(-1);
	}
	return minPath_mem(n, 0,0, res, triangle);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	return minPath_mem(triangle, n);
	if(n==1)return triangle[0][0];
	int **arr=new int*[n];
	for(int i=0;i<n;i++)arr[i]=new int[i+1];

	for(int i=n-2;i>=0;i--){
		for(int j=i;j>=0;j--){
			if(i==n-2){
				arr[i][j]=triangle[i][j]+min(triangle[i+1][j],triangle[i+1][j+1]);
			}
			else arr[i][j]=triangle[i][j]+min(arr[i+1][j],arr[i+1][j+1]);
		}
	}
	return arr[0][0];
}