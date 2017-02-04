
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <unordered_map>

int fibo_topdown_memo_rec_sub(int n, std::unordered_map<int, int> &memo)
{
  int f;

  if (memo.find(n) != memo.end())
    return memo[n];
  if (n <= 2)
    f = 1;
  else
    f = fibo_topdown_memo_rec_sub(n - 1, memo) + fibo_topdown_memo_rec_sub(n - 2, memo);
  
  memo[n] = f;
  return f;
}

int fibo_topdown_memo_rec(int n)
{
  std::unordered_map<int, int> memo;

  return fibo_topdown_memo_rec_sub(n, memo);
}

int fibo_bottomup_it(int n)
{
  std::unordered_map<int, int> memo;
  int k = 0;

  for (k = 0; k < n + 1; ++k)
    {
      int f;

      if (k == 0)
	f = 0;
      else if (k > 0 && k <= 2)
	f = 1;
      else
	f = memo[k - 1] + memo[k - 2];

      memo[k] = f;
    }
  return memo[k - 1];
}

int fibo_topdown_rec(int n)
{
  int f;

  if (n <= 2)
    f = 1;
  else
    f = fibo_topdown_rec(n - 1) + fibo_topdown_rec(n - 2);
  return f;
}

int fibo_lel(int n)
{
  double phi = (1 + sqrt(5)) / 2;
  double phi_prime = -1 / phi;

  return 1 / sqrt(5) * (pow(phi, n) - pow(phi_prime, n));
}

int main(int ac, char **av)
{
  // compute the nth term of fibonacci's sequence

  if (ac > 1)
    {
      int n = std::atoi(av[1]);
      std::cout << fibo_topdown_rec(n) << std::endl;	// O(2^n)
      std::cout << fibo_lel(n) << std::endl;		// O(1)
      std::cout << fibo_topdown_memo_rec(n) << std::endl;		// O(n)
      std::cout << fibo_bottomup_it(n) << std::endl;		// O(n)
    }
  return 0;
}
