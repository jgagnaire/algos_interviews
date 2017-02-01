
#include <iostream>
#include <vector>

std::vector<int> func(std::vector<int> tab1, std::vector<int> tab2)
{
  std::vector<int> tab;
  size_t a = 0, b = 0;

  while (a < tab1.size() && b < tab2.size())
    {
      if (tab1[a] == tab2[b] && ((tab.size() > 0 && tab.back() != tab1[a]) || !tab.size()))
	{
	  tab.push_back(tab1[a]);
	  ++a;
	  ++b;
	}
      else if (tab1[a] > tab2[b])
	{
	  ++b;
	}
      else
	{
	  ++a;
	}
    }

  for (int c : tab)
    std::cout << c << " ";
  std::cout << std::endl;
  return tab;
}

int main()
{
  func({2, 3, 3, 5, 5, 6, 7, 7, 8, 12}, {5, 5, 6, 8, 8, 9, 10, 10});
}
