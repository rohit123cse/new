#include<bits/stdc++.h>
using namespace std;
/* We reverse the given string and find the LCS between the original and the reversed string*/
int lcs_dp(string a,string b){
  if(a.size()==0||b.size()==0)return 0;
  int m=a.size(),n=b.size();
  vector<vector<int>>arr(m+1,vector<int>(n+1,0));
  arr[m][n]=0;
  for(int i=0;i<n;i++)arr[m][i]=0;
  for(int i=0;i<m;i++)arr[i][n]=0;

  for(int i=m-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
      int x=arr[i+1][j];
      int y=arr[i][j+1];
      if(a[i]==b[j])arr[i][j]=1+arr[i+1][j+1];
      else arr[i][j]=max(x,y);
    }
  }
  return arr[0][0];
}
int longest_palindromic(string s){
  string t;
  int point=s.size()-1;
  while(point>=0){
    if(point==s.size()-1){
      char c=s[point];
      t=c;
      point--;
      continue;
    }
    char c=s[point];
    t+=c;
    point--;
  }
  t+='\0';
  return lcs_dp(s,t);
}

int main(){
  string s="abcda";
  cout<<s.size();
  cout<<"hi"<<endl;
  cout<<longest_palindromic(s);
  cout<<"hi"<<endl;







return 0;
}