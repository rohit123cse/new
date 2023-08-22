#include<bits/stdc++.h>
using namespace std;
int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
  // Code here
  unordered_map<string,bool>visited;
  queue<string>q;
  if(startWord==targetWord)return 0;
  unordered_map<string,bool>inlist;
  for(int i=0;i<wordList.size();i++)inlist[wordList[i]]=1;
  q.push(startWord);
  int level=-1;
  while(!q.empty()){
      int len=q.size();
      level++;
      while(len--){
          string a=q.front();
          q.pop();
          if(visited[a])continue;
          visited[a]=1;
          if(a==targetWord)return level+1;
          for(int i=0;i<a.size();i++){
              char s=a[i];
              for(int j=0;j<26;j++){
                  char r='a'+j;
                  if(r==s)continue;
                  a[i]=r;
                  if(inlist[a])q.push(a);
              }
              a[i]=s;
          }
      }
  }
  return 0;
}
int main(){






return 0;
}