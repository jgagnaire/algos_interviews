
#include <limits.h>
#include <iostream>

int max_sub_array_sum(int *tab, int size)
{
  int max_so_far = INT_MIN;
  int max_ending_here = 0;

  for (int i = 0; i < size; ++i)
    {
      max_ending_here += tab[i];
      if (max_so_far < max_ending_here)
	max_so_far = max_ending_here;

      if (max_ending_here < 0)
	max_ending_here = 0;
    }
  return max_so_far;
}

int main()
{
  int tab[] = {-2, -3, 4, -1, -2, 1, 5, -3};

  std::cout << "Max contiguous sum is "
	    << max_sub_array_sum(tab, sizeof(tab) / sizeof(tab[0]))
	    << std::endl;
  return 0;
}
