#include <bits/stdc++.h>
using namespace std;
// You are given a 0-indexed binary string s which represents the types of buildings along a street where:

// s[i] = '0' denotes that the ith building is an office and
// s[i] = '1' denotes that the ith building is a restaurant.
// As a city official, you would like to select 3 buildings for random inspection. However, to ensure variety, no two consecutive buildings out of the selected buildings can be of the same type.

// For example, given s = "001101", we cannot select the 1st, 3rd, and 5th buildings as that would form "011" which is not allowed due to having two consecutive buildings of the same type.
// Return the number of valid ways to select 3 buildings.
long long numberOfWays(string s)
{
  int n = s.size();
  vector<long long> one(3, 0);
  vector<long long> zero(3, 0);

  for (int i = n - 1; i >= 0; i--)
  {
    if (i == n - 1)
    {
      for (int j = 0; j < 3; j++)
      {
        if (j == 2)
        {
          if (s[i] == '1')
            one[j]++;
          else
            zero[j]++;
          continue;
        }
      }
      continue;
    }
    for (int j = 0; j < 3; j++)
    {
      if (j == 2)
      {

        if (s[i] == '1')
          one[j]++;
        else
          zero[j]++;
        continue;
      }
      if (s[i] == '1')
      {
        one[j] += zero[j + 1];
      }
      else
      {
        zero[j] += one[j + 1];
      }
    }
  }
  long long res = 0;
  return (one[0] + zero[0]);
}
int main()
{

  return 0;
}