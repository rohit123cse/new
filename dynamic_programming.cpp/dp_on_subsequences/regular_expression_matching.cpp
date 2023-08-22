#include <bits/stdc++.h>
using namespace std;
bool isMatch(string s, string p)
{
  int row = p.size(), col = s.size();
  vector<vector<int>> store(row + 1, vector<int>(col + 1, 0));
  store[row][col] = 1;
  for (int i = row - 1; i >= 0; i--)
  {
    if (i == row - 1)
    {
      if (p[i] == '*')
        store[i][col] = 1;
      else
        store[i][col] = 0;
      continue;
    }
    if (p[i] == '*')
    {
      if (store[i + 1][col] == 1)
        store[i][col] = 1;
      else
        store[i][col] = 0;
    }
    else if (p[i + 1] == '*' && store[i + 1][col])
      store[i][col] = 1;
  }
  for (int j = col - 1; j >= 0; j--)
  {
    for (int i = row - 1; i >= 0; i--)
    {
      if (s[j] == p[i] || p[i] == '.')
      {
        if (i < row - 1 && p[i + 1] == '*')
        {
          bool take = store[i + 1][j + 1];
          bool nottake = store[i + 2][j];
          if (take || nottake)
            store[i][j] = 1;
          else
            store[i][j] = 0;
        }
        else
          store[i][j] = store[i + 1][j + 1];
      }
      else if (p[i] == '*')
      {
        if (store[i + 1][j])
          store[i][j] = 1;
        else if (p[i - 1] == s[j] || p[i - 1] == '.')
        {
          bool take = store[i + 1][j + 1];
          bool nottake = store[i][j + 1];
          bool zero = store[i + 1][j];
          if (take || nottake || zero)
            store[i][j] = 1;
          else
            store[i][j] = 0;
        }
        else
          store[i][j] = 0;
      }
      else if (i < row - 1)
      {
        if (p[i + 1] == '*')
          store[i][j] = store[i + 2][j];
        else
          store[i][j] = 0;
      }
      else
        store[i][j] = 0;
    }
  }
  return store[0][0];
}
int main()
{
  return 0;
}