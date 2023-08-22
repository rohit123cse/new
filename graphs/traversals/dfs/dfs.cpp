#include<bits/stdc++.h>
using namespace std;
/*flood fill using dfs*/
void res(vector<vector<int>>&vec,vector<vector<int>>&images,int i,int j,int const &m,int const &n,int const&same,int const & color){
    if(i<0||i==m||j<0||j==n)return;
    if(vec[i][j]||images[i][j]!=same)return;
    images[i][j]=color;
    vec[i][j]=1;
    res(vec,images,i+1,j,m,n,same,color);
    res(vec,images,i-1,j,m,n,same,color);
    res(vec,images,i,j-1,m,n,same,color);
    res(vec,images,i,j+1,m,n,same,color);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    // Code here 
    int m=image.size(),n=image[0].size();
    vector<vector<int>>vec(m,vector<int>(n,0));
    int same=image[sr][sc];
    res(vec,image,sr,sc,m,n,same,newColor);
    return image;
}




void dfs_helper(int **edges,int n,int sv,vector<int>&visited){
  if(visited[sv])return ;
  visited[sv]=1;
  cout<<sv<<" ";
  for(int i=0;i<n;i++){
    if(edges[sv][i])dfs_helper(edges,n,i,visited);
  }
}
void dfs(int **edges,int n){
  vector<int>visited(n,0);
  for(int i=0;i<n;i++)dfs_helper(edges,n,i,visited);
}
int main(){
  





return 0;
}