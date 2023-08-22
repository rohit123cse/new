#include<bits/stdc++.h>
using namespace std;
//brute force recursive;
int lcs(string a,string b){
  if(a.size()==0||b.size()==0)return 0;
  if(a[0]==b[0])return 1+lcs(a.substr(1),b.substr(1));
  // return max(lcs(a.substr(1),b),max(lcs(a,b.substr(1)),lcs(a.substr(1),b.substr(1))));
  return max(lcs(a.substr(1),b),lcs(a,b.substr(1)));
}
int lcs_mem_helper(int **arr,string a,string b,int m,int n,int row,int col){
  if(m==row||n==col)return 0;
  if(arr[row][col]!=-1)return arr[row][col];
  if(a[row]==b[col]){
    arr[row][col]=1+lcs_mem_helper(arr,a,b,m,n,row+1,col+1);
    return arr[row][col];
  }
  int x=lcs_mem_helper(arr,a,b,m,n,row+1,col);
  int y=lcs_mem_helper(arr,a,b,m,n,row,col+1);
  arr[row][col]=max(x,y);
  return arr[row][col];

}
int lcs_mem(string a,string b){
  if(a.size()==0||b.size()==0)return 0;
  int **arr=new int*[a.size()];
  for(int i=0;i<a.size();i++ ){
    arr[i]=new int[b.size()];
    for(int j=0;j<b.size();j++)arr[i][j]=-1;
  }
  return lcs_mem_helper(arr,a,b,a.size(),b.size(),0,0);
}
int lcs_dp(string a,string b){
  if(a.size()==0||b.size()==0)return 0;
  int m=a.size(),n=b.size();
  int **arr=new int*[m];
  for(int i=0;i<m;i++)arr[i]=new int[n];
  for(int i=m-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
      if(i==m-1&&j==n-1){
        if(a[i]==b[j])arr[i][j]=1;
        else arr[i][j]=0;
        continue;
      }
      if(i==m-1){
        if(a[i]==b[j])arr[i][j]=1;
        else arr[i][j]+=arr[i][j+1];
        continue;
      }
      if(j==n-1){
        if(a[i]==b[j])arr[i][j]=1;
        else arr[i][j]=arr[i+1][j];
        continue;
      }
      int x=arr[i+1][j];
      int y=arr[i][j+1];
      if(a[i]==b[j])arr[i][j]=1+arr[i+1][j+1];
      else arr[i][j]=max(x,y);
    }
  }
  return arr[0][0];
}
void print_lcs_dp(string s,string t,vector<vector<string>>&store){
  int row=s.size();
  int col=t.size();
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      string s;
      store[i][j]=s;
    }
  }
  for(int i=row-1;i>=0;i--){
    if(s[i]==t[col-1])store[i][col-1]=s[i];
  }
  for(int i=col-1;i>=0;i--){
    if(s[col-1]==t[i])store[row-1][i]=t[i];
  }
  for(int i=row-2;i>=0;i--){
    for(int j=col-2;j>=0;j--){
      if(t[j]==s[i]){
        store[i][j]=t[j];
        store[i][j]+=store[i+1][j+1];
      }
      else{
        string a=store[i][j+1];
        string b=store[i+1][j];
        if(a.size()<b.size())store[i][j]=b;
        else store[i][j]=a;
      }
    }
  }
}
void print_lcs(string s,string t,int &max_size,int size,string &max_string,string temp){
  if(s.size()==0||t.size()==0){
    if(max_size<size){
      max_string.erase();
      max_string+=temp;
      max_size=size;
    }
    return;
  }
  if(s[0]==t[0]){
    temp+=s[0];
    print_lcs(s.substr(1),t.substr(1),max_size,size+1,max_string,temp);
    temp=temp.substr(0,temp.size()-1);
    return;
  }
  print_lcs(s.substr(1),t,max_size,size,max_string,temp);
  print_lcs(s.substr(1),t.substr(1),max_size,size,max_string,temp);
  print_lcs(s,t.substr(1),max_size,size,max_string,temp);
}

void print_lcs(string a,string b,string &res){
  string temp;
  int max_size=0;
  print_lcs(a,b,max_size,0,res,temp);
}



int main(){
  // cout<<lcs("abcde","acdeab")<<endl;
  // cout<<lcs_dp("abcde","acdeab")<<endl;
  // cout<<lcs_mem("abcde","acdeab");
  string result;
  string temp;
  int max_size=0;
  print_lcs("abcde","acdeab",max_size,0,result,temp);
  cout<<result<<endl;
  string bin;
  string t="abcde";
  string s="acdeab";
  vector<vector<string>>store(s.size(),vector<string>(t.size()));
  print_lcs_dp(s,t,store);
  cout<<store[0][0]<<endl;







return 0;
}