#include <iostream>

#define MAX(x, y) ((x) > (y) ? (x) : (y))


// Bruteforce solution, O(2^n)
int knapsack_bruteforce(int W, int *weights, int *values, int n)
{
  if (W == 0 || n == 0)
    return 0;

  if (weights[n - 1] > W)
    return knapsack_bruteforce(W, weights, values, n - 1);
  else
    return MAX(values[n - 1] + knapsack_bruteforce(W - weights[n - 1], weights, values, n - 1),
	       knapsack_bruteforce(W, weights, values, n - 1));
}


// We use dynamic programming with a bottom-up approach + a matrix to improve the solution above
int knapsack_dp(int W, int *weights, int *values, int n)
{
  int K[n + 1][W + 1];

  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= W; ++j)
      {
	if (i == 0 || j == 0)
	  K[i][j] = 0;
	else if (weights[i - 1] > j)
	  K[i][j] = K[i - 1][j];
	else
	  K[i][j] = MAX(values[i - 1] + K[i - 1][j - weights[i - 1]],
			K[i - 1][j]);
      }
  return K[n][W];
}

int main()
{
  int values[] = {60, 100, 120};
  int weights[] = {10, 20, 30};

  int total_weight = 50;

  std::cout << knapsack_dp(total_weight, weights, values, 3) << std::endl;
}
