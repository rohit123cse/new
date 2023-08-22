#include<bits/stdc++.h>
using namespace std;
bool floydwarshall(vector<vector<int>>&matrix){  //returns if the graph has negative cycle or not
  int n=matrix.size();
  for(int via;via<n;via++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        int a=matrix[i][via],b=matrix[via][j];
        if(a!=1e8&&b!=1e8){
          matrix[i][j]=min(matrix[i][j],a+b);
        }
      }
    }
  }
  for(int i=0;i<n;i++)if(matrix[i][i]!=0)return true;
  return false;
}
int main(){
  






return 0;
}