#include <string.h>
#include <vector>
#include <iostream>

class Bitset
{
public:
  Bitset(int size)
    : map(new char[size / sizeof(char)])
  {
    ::memset(map, 0, size / sizeof(char));
  }
  ~Bitset() {}

  bool   get(int index)
  {
    return (map[index / 8] >> (index % 8)) & 1;
  }

  void   set(int index, bool value)
  {
    if (value)
      map[index / 8] = map[index / 8] | (1 << (index % 8));
    else
      map[index / 8] = map[index / 8] & ~(1 << index % 8);
  }

private:
  char *map;
};


void    func(std::vector<int> const &list)
{
  Bitset    hashmap(32000);

  for (size_t i = 0; i < list.size(); ++i)
    {
      if (hashmap.get(list[i]))
	std::cout << list[i] << std::endl;
      hashmap.set(list[i], 1);
    }
}


int main(int ac, char **)
{
  if (ac > 1)
    func({32, 12, 8, 3, 71, 134, 8, 31000, 8, 71, 77, 32});
  return 0;
}
