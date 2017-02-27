#include <iostream>
#include <vector>

std::vector<int>    func(std::vector<std::vector<int> > const &v)
{
  int n = v.size();
  std::vector<int> v2;

  for (int i = 0; i < n / 2; ++i)
    {
      for (int j = i; j < n - i - 1; ++j)
	v2.push_back(v[i][j]);
      for (int j = i; j < n - i - 1; ++j)
	v2.push_back(v[j][n - i - 1]);
      for (int j = i; j < n - i - 1; ++j)
	v2.push_back(v[n - i - 1][n - j - 1]);
      for (int j = i; j < n - i - 1; ++j)
	v2.push_back(v[n - j - 1][i]);
    }
  return v2;
}
