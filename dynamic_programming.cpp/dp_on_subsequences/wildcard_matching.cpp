#include <bits/stdc++.h>
using namespace std;

bool wildcardMatching(string pattern, string text)
{
  // Write your code here.
  int row = pattern.size(), col = text.size();
  vector<vector<int>> store(row + 1, vector<int>(col + 1, 0));
  store[row][col] = 1;
  if (pattern[row - 1] == '*')
    store[row - 1][col] = 1;
  else
    store[row - 1][col] = 0;
  for (int i = row - 2; i >= 0; i--)
  {
    if (store[i + 1][col] && pattern[i] == '*')
      store[i][col] = 1;
    else
      store[i][col] = 0;
  }
  for (int j = col - 1; j >= 0; j--)
  {
    for (int i = row - 1; i >= 0; i--)
    {
      if (j == col - 1)
      {
        if (pattern[i] == text[j] && store[i + 1][j + 1])
          store[i][j] = 1;
        else if (pattern[i] == '*')
        {
          bool once = store[i + 1][j + 1];
          bool zero = store[i + 1][j];
          if (once || zero)
            store[i][j] = 1;
          else
            store[i][j] = 0;
        }
        else if (pattern[i] == '?')
          store[i][j] = store[i + 1][j + 1];
        else
          store[i][j] = 0;
        continue;
      }
      if (pattern[i] == text[j])
        store[i][j] = store[i + 1][j + 1];
      else if (pattern[i] == '?')
        store[i][j] = store[i + 1][j + 1];
      else if (pattern[i] == '*')
      {
        bool zero = store[i + 1][j];
        bool once = store[i + 1][j + 1];
        bool mul = store[i][j + 1];
        if (once || mul || zero)
          store[i][j] = 1;
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