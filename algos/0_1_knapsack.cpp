#include <iostream>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

/*
// We use dynamic programming with a bottom-up approach + a matrix to improve this 2^n solution

int knapsack(int remaining_available_weight, int *weights, int *values, int n)
{
  if (remaining_available_weight == 0 || n == 0)
    return 0;
  else if (weights[n - 1] > remaining_available_weight)
    return knapsack(remaining_available_weight, weights, values, n - 1);
  else
    return MAX(values[n - 1] + knapsack(remaining_available_weight - weights[n - 1], weights, values, n - 1),
	       knapsack(remaining_available_weight, weights, values, n - 1));
}
*/

int knapsack(int W, int *weights, int *values, int n)
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

  std::cout << knapsack(total_weight, weights, values, 3) << std::endl;
}
