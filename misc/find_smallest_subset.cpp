
#include <vector>
#include <map>
#include <iostream>

int func(std::vector<int> const &v)
{
  std::map<int, int> map;
  int largest = 0;
  int tmp = 0;

  for (unsigned int a = 0; a < v.size(); ++a)
    {
      std::map<int, int>::iterator it = map.find(v[a]);
      if (map.size() == 0)
	tmp = a;
      if (it == std::end(map))
        map[v[a]] = a;
      else
	{
	  int size = a - tmp;
	  if (size > largest)
	    largest = size;
	  if (a == v.size() - 1)
	    break ;
	  a = it->second;
	  map.clear();
	}
    }
  return largest;
}

int main()
{
  std::vector<int> v({'F', 'S', 'F', 'E', 'T', 'W', 'E', 'N', 'W', 'E'});
  std::cout << func(v) << std::endl;
}
