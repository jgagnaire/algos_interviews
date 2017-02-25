#include <vector>
#include <iostream>

std::vector<std::vector<int> >        pascal(int n)
{
  std::vector<std::vector<int> >  v;
  int k = 2;

  v.push_back(std::vector<int>());
  v[0].push_back(1);

  for (int i = 1; i < n; ++i)
    {
      v.push_back(std::vector<int>());
      v[i].push_back(1);
      for (int j = 1; j < k; ++j)
	{
	  if (j == v[i - 1].size())
	    v[i].push_back(1);
	  else
	    v[i].push_back(v[i - 1][j - 1] + v[i - 1][j]);
	}
      ++k;
    }
  return v;
}

int main(int ac, char **av)
{
  if (ac > 1)
    {
      std::vector<std::vector<int> > v = pascal(std::atoi(av[1]));
      for (int i = 0; i < v.size(); ++i)
	{
	  for (int j = 0; j < v[i].size(); ++j)
	    std::cout << v[i][j] << " ";
	  std::cout << std::endl;
	}
    }
  return 0;
}
