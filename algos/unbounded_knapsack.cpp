#include <cstring>
#include <iostream>
#include <algorithm>

// allowed to use unlimited instances of any item
int unbounded_knapsack(int W, int *values, int *weights, int n)
{
  int K[W + 1];
  std::memset(K, 0, sizeof(K));

  for (int i = 0; i <= W; ++i)
    for (int j = 0; j < n; ++j)
      if (weights[j] <= i)
	K[i] = std::max(K[i], values[j] + K[i - weights[j]]);

  return K[W];
}

int main()
{
  int W = 30;
  int values[] = {10, 30, 20};
  int weights[] = {5, 10, 15};

  std::cout << unbounded_knapsack(W, values, weights, 3) << std::endl;
  return 0;
}
