
#include <vector>
#include <iostream>
#include <algorithm>

#define LEN 10

void func(std::vector<int> &v)
{
  std::sort(std::begin(v), std::end(v));

  for (unsigned long i = 0; i < v.size() - 2; ++i)
    {
      int a = v[i];
      int left = i + 1;
      int right = v.size() - 1;

      while (left < right)
	{
	  int b = v[left];
	  int c = v[right];

	  if (c + b == -a)
	    {
	      std::cout << a << " + " << b << " + " << c << " = 0" << std::endl;
	      ++left;
	      --right;
	    }
	  else if (c + b > -a)
	    --right;
	  else
	    ++left;
	}
    }
}

int	main()
{
  std::vector<int> tab;
  int	a;

  for (a = 0;a < LEN;++a)
    {
      tab.push_back(!(a % 2) ? (rand() % LEN) : -1 * (rand() % LEN));
      std::cout << tab[a] << " ";
    }
  std::cout << std::endl;

  func(tab);
}
