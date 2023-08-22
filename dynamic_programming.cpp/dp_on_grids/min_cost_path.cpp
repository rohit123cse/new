#include<bits/stdc++.h>
using namespace std;

int helper(int**input,int m,int n,int row,int col){
	if(row==m||col==n)return INT_MAX;
	if(row==m-1&&col==n-1)return INT_MIN;
	int a=helper(input,m,n,row+1,col);
	int b=helper(input,m,n,row,col+1);
	int c=helper(input,m,n,row+1,col+1);
	int temp=INT_MIN;
	if(a==temp||b==temp||c==temp)return input[row][col];
	return min(a,min(b,c))+input[row][col];

}

int mem_helper(int **input,int**cost,int m,int n,int row,int col){
	if(row==m||col==n)return INT_MAX;
	if(cost[row][col]!=-1)return cost[row][col];
	int a=mem_helper(input,cost,m,n,row+1,col);
	int b=mem_helper(input,cost,m,n,row,col+1);
	int c=mem_helper(input,cost,m,n,row+1,col+1);
	cost[row][col]=input[row][col]+min(a,min(b,c));
	return cost[row][col];
}

int minCost_mem(int **input,int m,int n){
	if(m==1&&n==1)return input[0][0];
	int **cost=new int*[m];
	for(int i=0;i<m;i++){
		cost[i]=new int[n];
		for(int j=0;j<n;j++){
			cost[i][j]=-1;
		}
	}
	cost[m-1][n-1]=0;
	return mem_helper(input,cost,m,n,0,0)+input[m-1][n-1];

}
int mincost_dp(int **input,int m,int n){
	int **cost=new int*[m];
	for(int i=0;i<m;i++){
		cost[i]=new int[n];
		for(int j=0;j<n;j++){
			cost[i][j]=-1;
		}
	}
	int row_point=m-1,col_point=n-1;
	while(row_point>=0){
		while(col_point>=0){
			if(row_point==m-1&&col_point==n-1){
				cost[row_point][col_point]=input[row_point][col_point];
				col_point--;
				continue;
			}
			if(row_point==m-1){
				cost[row_point][col_point]=input[row_point][col_point]+cost[row_point][col_point+1];
				col_point--;
				continue;
			}
			if(col_point==n-1){
				cost[row_point][col_point]=input[row_point][col_point]+cost[row_point+1][col_point];
				col_point--;
				continue;;
			}
			int a=cost[row_point][col_point+1];
			int b=cost[row_point+1][col_point+1];
			int c=cost[row_point+1][col_point];
			cost[row_point][col_point]=input[row_point][col_point]+min(a,min(b,c));
			col_point--;
		}
		col_point=n-1;
		row_point--;
	}

	return cost[0][0];
}

int minCostPath(int **input, int m, int n)
{
	//Write your code here
	// return helper(input,m,n,0,0)+input[m-1][n-1];
	// return minCost_mem(input,m,n);
	return mincost_dp(input, m, n);
}