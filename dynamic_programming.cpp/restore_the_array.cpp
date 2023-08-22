#include <bits/stdc++.h>
using namespace std;
// A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits s and all we know is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.

// Given the string s and the integer k, return the number of the possible arrays that can be printed as s using the mentioned program
int mod = 1e9 + 7;
int result(string const &s, int low, int const k, vector<int> &store, int const high)
{
  if (store[low] != -1)
    return store[low];
  if (high - low == 1)
  {
    int x = s[low] - 48;
    if (1 <= x && x <= k)
      return store[low] = 1;
    else
      return store[low] = 0;
  }
  if (s[low] - 48 == 0)
  {
    return store[low] = 0;
  }
  int mid = low + 1;
  long long res = 0;
  long long val = 0;
  int mul = 10;
  int isok = 1;
  while (mid < high)
  {
    val *= mul;
    val += s[mid - 1] - 48;

    if (val > k)
    {
      isok = 0;
      break;
    }
    if (1 <= val && val <= k)
    {
      int b = result(s, mid, k, store, high);
      if (b > 0)
      {
        res += b;
        res = res % mod;
      }
    }
    mid++;
  }
  if (isok)
  {
    val *= 10;
    val += s[high - 1] - 48;
    if (1 <= val && val <= k)
      res++;
  }
  return store[low] = res;
}
int numberOfArrays(string s, int k)
{
  int len = s.size();
  vector<int> store(len + 1, -1);
  return result(s, 0, k, store, len);
}
int main()
{

  return 0;
}