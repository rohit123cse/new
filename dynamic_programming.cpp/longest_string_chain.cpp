#include <bits/stdc++.h>
using namespace std;
bool compareLen(const std::string &a, const std::string &b)
{
  return (a.size() < b.size());
}
struct compare
{
  inline bool operator()(const std::string &first,
                         const std::string &second) const
  {
    return first.size() < second.size();
  }
};
bool isequal(string a, string b)
{
  if (a.size() != b.size())
    return false;
  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] != b[i])
      return false;
  }
  return true;
}
bool onediff(string a, string b)
{
  int pointa = 0, pointb = 0;
  while (pointa < a.size() && pointb < b.size())
  {
    if (a[pointa] == b[pointb])
    {
      pointa++;
      pointb++;
    }
    else
      return isequal(a.substr(pointa), b.substr(pointb + 1)) || isequal(a.substr(pointa + 1), b.substr(pointb));
  }
  return true;
}
int longestStrChain(vector<string> &arr)
{
  // Write your code here.
  int n = arr.size();

  if (n == 0 || n == 1)
    return n;
  compare c;
  std::sort(arr.begin(), arr.end(), c);
  vector<int> store(n, 1);
  int maxi = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i].size() == 1)
      continue;
    int req = arr[i].size() - 1;
    string curr = arr[i];
    int len = 0;

    for (int j = 0; j < i; j++)
    {
      if (arr[j].size() == req)
      {
        if (onediff(arr[j], curr))
          len = max(len, store[j]);
      }
    }
    store[i] += len;
    maxi = max(store[i], maxi);
  }
  return maxi;
}
int main(){
  return 0;
}