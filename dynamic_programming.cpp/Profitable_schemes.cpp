#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
{
  int prolen = profit.size();
  vector<vector<vector<int>>> store(prolen, vector<vector<int>>(n + 1, vector<int>(minProfit + 1)));
  for (int i = prolen - 1; i >= 0; i--)
  {
    for (int j = n; j >= 0; j--)
    {
      for (int k = minProfit; k >= 0; k--)
      {
        if (i == prolen - 1)
        {
          if (k == minProfit)
          {
            if (n - j < group[i])
              store[i][j][k] = 1;
            else
              store[i][j][k] = 2;
          }
          else
          {
            if (n - j < group[i])
              store[i][j][k] = 0;
            else
            {
              if (profit[i] + k >= minProfit)
                store[i][j][k] = 1;
              else
                store[i][j][k] = 0;
            }
          }
          continue;
        }
        if (k == minProfit)
        {
          if (n - j < group[i])
            store[i][j][k] = store[i + 1][j][k];
          else
          {
            if (n - j == group[i])
              store[i][j][k] = 1 + store[i + 1][j][k];
            else if (store[i + 1][j + group[i]][k] > 0)
              store[i][j][k] = (store[i + 1][j][k] + store[i + 1][j + group[i]][k]) % mod;
            else
              store[i][j][k] = (1 + store[i + 1][j][k] + store[i + 1][j + group[i]][k]) % mod;
          }
          continue;
        }
        if (n - j < group[i])
          store[i][j][k] = store[i + 1][j][k];
        else
        {
          if (profit[i] >= minProfit - k)
          {
            if (profit[i] == minProfit - k)
            {
              if (store[i + 1][j + group[i]][minProfit] > 0)
                store[i][j][k] = (store[i + 1][j][k] + store[i + 1][j + group[i]][minProfit]) % mod;
              else
                store[i][j][k] = 1 + store[i + 1][j][k];
            }
            else
            {
              if (store[i + 1][j + group[i]][minProfit] > 0)
                store[i][j][k] = ((long long)store[i + 1][j][k] + (long long)store[i + 1][j + group[i]][minProfit]) % mod;
              else
                store[i][j][k] = 1 + store[i + 1][j][k];
            }
          }
          else
          {
            store[i][j][k] = ((long long)store[i + 1][j + group[i]][k + profit[i]] + (long long)store[i + 1][j][k]) % mod;
          }
        }
      }
    }
  }
  // if(minProfit==0)return store[0][0][0]+1;
  return store[0][0][0];
}
int main(){

  return 0;
}