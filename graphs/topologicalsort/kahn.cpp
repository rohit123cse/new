#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    int n = V;
    vector<int> order(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
            order[adj[i][j]]++;
    }
    vector<int> res;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (order[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        res.push_back(val);
        for (int i = 0; i < adj[val].size(); i++)
        {
            order[adj[val][i]]--;
            if (order[adj[val][i]] == 0)
            {
                q.push(adj[val][i]);
            }
        }
    }
    return res;
}


int main()
{
    unordered_map<int,bool>mpp;
    cout<<mpp[1]<<" "<<mpp[1];
    return 0;
}