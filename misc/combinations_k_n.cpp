#include <vector>
#include <iostream>
#include <cstdlib>

void func(std::vector<int> &tab, int j, int k, int n, std::vector<std::vector<int> > *gtab)
{
  if (tab.size() == (unsigned long)k)
    {
      gtab->push_back(tab);
      return ;
    }

  for (int i = j; i <= n; ++i)
    {
      tab.push_back(i);
      func(tab, i + 1, k, n, gtab);
      tab.pop_back();
    }
}

std::vector<std::vector<int> > *wrapper_func(int n, int k)
{
  std::vector<std::vector<int> > *gtab = new std::vector<std::vector<int> >;
  std::vector<int> tab;

  func(tab, 1, k, n, gtab);
  return gtab;
}

int main(int ac, char **av)
{
  if (ac > 2)
    {
      std::vector<std::vector<int> > *tab = wrapper_func(std::atoi(av[1]),
							 std::atoi(av[2]));
      for (auto e1 : *tab)
	{
	  for (auto e2 : e1)
	    std::cout << e2 << " ";
	  std::cout << std::endl;
	}
    }
  return 0;
}
