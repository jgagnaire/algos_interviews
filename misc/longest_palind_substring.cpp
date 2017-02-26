
#include <cstring>
#include <utility>
#include <string>
#include <queue>
#include <iostream>

// naive solution in O(n³)
std::string bruteforce(std::string const &s)
{
  std::pair<unsigned, unsigned> largest(0, 0);

  for (unsigned i = 0; i < s.size(); ++i)
    for (unsigned j = i; j < s.size(); ++j)
      {
	int k = i, l = j;
	bool is_palind = true;
	while (k < l)
	  {
	    if (s[k] != s[l])
	      {
		is_palind = false;
		break ;
	      }
	    ++k;
	    --l;
	  }
	if (is_palind && largest.second - largest.first + 1 < j - i + 1)
	  {
	    largest.first = i;
	    largest.second = j;
	  }
      }
  return s.substr(largest.first, largest.second - largest.first + 1);
}

// Dynamic programming solution, O(n²) time, O(n²) space
std::string dp_quadratic(std::string const &s)
{
  unsigned n = s.size();
  // tab[i][j] == true if s.substr(i , j - i + 1) is a palindrome
  bool **tab = new bool* [n];
  std::pair<unsigned, unsigned> largest(0, 0);

  for (unsigned i = 0; i < n; ++i)
    {
      tab[i] = new bool[n];
      std::memset(tab[i], false, n);

      // length == 1 => always a palindrome
      tab[i][i] = true;

      // length == 2
      if (i + 1 < n && s[i] == s[i + 1])
	{
	  tab[i][i + 1] = true;
	  largest.first = i;
	  largest.second = i + 1;
	}
    }

  // we process all the sizes in increasing order
  for (unsigned k = 3; k <= n; ++k)
    // and for each size, we try all the index
    for (unsigned i = 0; i + k - 1 < n; ++i)
      {
	unsigned j = i + k - 1;
	if (tab[i + 1][j - 1] && s[j] == s[i])
	  {
	    tab[i][j] = true;
	    if (largest.second - largest.first + 1 < j - i + 1)
	      {
		largest.first = i;
		largest.second = j;
	      }
	  }
      }

  for (unsigned a = 0; a < n; ++a)
    delete[] tab[a];
  delete[] tab;

  return s.substr(largest.first, largest.second - largest.first + 1);
}

// odd & even palindromes refined bruteforce solution, O(n²) time, O(1) space
std::string even_odd_palinds_quadratic(std::string const &s)
{
  std::pair<int, int> largest(0, 0);
  unsigned n = s.size();

  for (unsigned i = 1; i < n; ++i)
    {
      // odd sizes palindromes from i as center
      for (int left = i - 1, right = i + 1; left >= 0 && right < n; --left, ++right)
	{
	  if (s[left] != s[right])
	    break ;
	  if (largest.second - largest.first + 1 < right - left + 1)
	    {
	      largest.first = left;
	      largest.second = right;
	    }
	}

      // even sizes palindromes from i - 1, i as a 'center'
      for (int left = i - 1, right = i; left >= 0 && right < n; --left, ++right)
	{
	  if (s[left] != s[right])
	    break ;
	  if (largest.second - largest.first + 1 < right - left + 1)
	    {
	      largest.first = left;
	      largest.second = right;
	    }
	}
    }
  return s.substr(largest.first, largest.second - largest.first + 1);
}

int main(int ac, char **av)
{
  if (ac > 1)
    {
      std::string s(av[1]);
      std::cout << even_odd_palinds_quadratic(s) << std::endl;
    }
  return 0;
}
