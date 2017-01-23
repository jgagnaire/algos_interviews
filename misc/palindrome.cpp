
#include <iostream>
#include <string>

/*
bool lol(std::string &s)
{
  return s == reverse(s);
}
*/

bool func(std::string s)
{
  int a = 0, b = s.size() -1;

  while (a < b)
    {
      s[a] |= 32;
      s[b] |= 32;
      if (s[a] != s[b])
        return false;
      ++a;
      --b;
    }
  return true;
}

int main(int ac, char **av)
{
  if (ac == 1)
    return 0;
  std::cout << func(std::string(av[1])) << std::endl;
  return 0;
}
