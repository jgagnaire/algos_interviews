
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>

// O(2^n) bruteforce solution
int func(std::string const &s, int left, int right)
{
  if (left == right)
    return 1;
  if (left == right - 1 && s[left] == s[right])
    return 2;

  if (s[left] == s[right])
    return func(s, left + 1, right - 1) + 2;

  return std::max(func(s, left + 1, right), func(s, left, right - 1));
}

int func_naive(std::string const &s)
{
  return func(s, 0, s.size() - 1);
}

// O(n²) time, O(n²) space, dynamic programming solution
int func_dp(std::string const &s)
{
  int n = s.size();
  int L[n][n];

  for (int i = 0; i < n; ++i)
    L[i][i] = 1;

  for (int k = 2; k <= n; ++k)
    for (int i = 0; i < n - k + 1; ++i)
      {
	int j = i + k - 1;

	if (i == j - 1 && s[i] == s[j])
	  L[i][j] = 2;
	else if (s[i] == s[j])
	  L[i][j] = L[i + 1][j - 1] + 2;
	else
	  L[i][j] = std::max(L[i][j - 1], L[i + 1][j]);
      }
  return L[0][n - 1];
}

int main(int ac, char **av)
{
  if (ac > 1)
    {
      std::string s(av[1]);
      std::cout << func_dp(s) << std::endl;
    }
  return 0;
}
