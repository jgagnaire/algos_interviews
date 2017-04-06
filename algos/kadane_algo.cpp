
int kadane(int *tab, int len)
{
  int max_ending_here = 0;
  int final_max = 0;

  for (int i = 0; i < len; ++i)
    {
      max_ending_here = max_ending_here + tab[i];
      if (max_ending_here < 0)
	max_ending_here = 0;

      if (max_ending_here > final_max)
	final_max = max_ending_here;
    }
  return final_max;
}

#include <iostream>

#define LEN 8

int main()
{
  int tab[LEN] = {-2, -3, 4, -1, -2, 1, 5, -3};
  std::cout << "maximum contiguous subarray sum is " << kadane(tab, LEN) << std::endl;
  return 0;
}
