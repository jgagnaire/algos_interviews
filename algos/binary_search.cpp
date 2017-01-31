
#include <stdlib.h>
#include <vector>
#include <iostream>

int binary_search(std::vector<int> &tab, int left, int right, int x)
{
  if (left > right)
    return -1;

  int middle = left + (right - left) / 2;

  if (tab[middle] == x)
    return middle;
  else if (tab[middle] < x)
    return binary_search(tab, middle + 1, right, x);
  return binary_search(tab, left, middle - 1, x);
}

#define LEN 10

int main(int ac, char **av)
{
  if (ac == 1)
    return 0;

  srand(time(0));

  std::vector<int> tab;

  for (int a = 0; a < LEN; ++a)
    {
      tab.push_back(rand() % LEN);
      std::cout << tab.back() << " ";
    }
  std::cout << std::endl;

  mergesort(tab, 0, LEN - 1);

  for (int a = 0; a < LEN; ++a)
    std::cout << tab[a] << " ";
  std::cout << std::endl;

  int to_find = atoi(av[1]);
  std::cout << "to find: " << to_find << std::endl;
  std::cout << binary_search(tab, 0, LEN - 1, to_find) << std::endl;
  return 0;
}
