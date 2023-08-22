#include<bits/stdc++.h>
using namespace std;
//you can take the same weight several times
/* TC-> O(exponetial) //we can take the same weight multilple times //worst case : weight^n
SC-> O(weight)// it can contain a one so we have a max stack tree of weight
*/

int mem(int index,vector<vector<int>>&store,vector<int>const &profit,vector<int>const &weight,int w,int const n,int const maxweight){
    if(store[w][index]!=-1)return store[w][index];
    if(index==n-1){
        int nos=(maxweight-w)/weight[index];
        return store[w][index]=nos*profit[index];
    }
    int a=mem(index+1,store,profit,weight,w,n,maxweight);
    int b=INT_MIN;
    if(maxweight-w>=weight[index]){
        b=profit[index]+mem(index,store,profit,weight,w+weight[index],n,maxweight);
    }
    return store[w][index]=max(a,b);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>>store(w+1,vector<int>(n,-1));
    return mem(0,store,profit,weight,0,n,w);
    // vector<vector<int>>store(w+1,vector<int>(n,0));
    for(int i=w;i>=0;i--){
        int nos=(w-i)/weight[n-1];
        store[i][n-1]=nos*profit[n-1];
    }
    for(int j=n-2;j>=0;j--){
        for(int i=w;i>=0;i--){
            int a=store[i][j+1];
            int b=0;
            if(w-i>=weight[j])b=profit[j]+store[i+weight[j]][j];
            store[i][j]=max(a,b);
        }
    }
    return store[0][0];
}

int main(){
  






return 0;
}