#include<bits/stdc++.h>
using namespace std;
class disjoint_set{  //O(4alpha)==O(1)
  vector<int>rank,parent;
  public:
  disjoint_set(int n){
    rank.resize(n+1,0);   // assuming 1-based indexing
    parent.resize(n+1,0);
    for(int i=0;i<=n;i++)parent[i]=i;
  }
  int findparent(int x){
    if(x==parent[x])return x;
    return parent[x]=findparent(parent[x]);
  }
  void unionbyrank(int u,int v){
    int upu=findparent(u),upv=findparent(v);
    if(upu==upv)return;
    if(rank[upu]==rank[upv]){
      parent[upv]=upu;
      rank[upu]++;
      return;
    }
    else if(rank[upu]<rank[upv])parent[upu]=upv;
    else parent[upv]=upu;
  }
  bool insameset(int u,int v){
    return findparent(u)==findparent(v);
  }
};
int main(){
  






return 0;
}