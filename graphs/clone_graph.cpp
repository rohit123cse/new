#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
Node*create_clone(Node*original,unordered_map<Node*,Node*>&mpp){
  if(original==NULL)return NULL;
  if(mpp.count(original)!=0)return mpp[original];
  Node*newnode=new Node(original->val);
  mpp[original]=newnode;
  for(int i=0;i<original->neighbors.size();i++){
      if(mpp.count(original->neighbors.at(i))==0)newnode->neighbors.push_back(create_clone(original->neighbors.at(i),mpp));
      else{
          newnode->neighbors.push_back(mpp[original->neighbors.at(i)]);
      }
  }
  return newnode;
}


Node* cloneGraph(Node* node) {
  unordered_map<Node*,Node*>mpp;
  return create_clone(node,mpp);
}
int main(){
  






return 0;
}