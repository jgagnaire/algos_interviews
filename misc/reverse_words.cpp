#include <iostream>
#include <string>
#include <algorithm>

void    func(std::string &s)
{
  std::reverse(s.begin(), s.end());
  std::size_t    i = 0, j;

  while ((j = s.substr(i).find(" ")) != std::string::npos)
    {
      std::reverse(s.begin() + i, s.begin() + j);
      i += j + 1;
    }
}

int main(int ac, char **av)
{
  if (ac > 1)
    {
      std::string s(av[1]);
      func(s);
      std::cout << s << std::endl;
    }
  return 0;
}
