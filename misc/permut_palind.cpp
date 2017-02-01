
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

bool    func(std::string s)
{
  std::unordered_map<char, char> hashmap;

  for (size_t a = 0; a < s.size(); ++a)
    ++(hashmap[(s[a] | 32) - 'a']);

  int i = 0;
  return std::none_of(hashmap.begin(), hashmap.end(),
		      [&i](std::pair<char, char> x) {
			if (x.second % 2 != 0)
			  ++i;
			return i > 1;
		      });
}

int main(int ac, char **av)
{
  if (ac > 1)
    std::cout << func(std::string(av[1])) << std::endl;

  return 0;
}
