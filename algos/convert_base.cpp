#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>

std::string    convert_base(std::string const &s, int b1, int b2)
{
  std::string rslt;
  int tmp = 0;

  for (int a = 0; a < s.size(); ++a)
    {
      tmp *= b1;
      tmp += ((s[a] - '0') > 9 ? s[a] - 'A' + 10 : s[a] - '0');
    }
  while (tmp > 0)
    {
      rslt += (char)(((tmp % b2) > 9 ? 'A' + (tmp % b2) - 10 : (tmp % b2) + '0'));
      tmp /= b2;
    }
  std::reverse(std::begin(rslt), std::end(rslt));
  return rslt;
}

int main(int ac, char **av)
{
  if (ac > 3)
    {
      std::string s(av[1]);
      std::cout << convert_base(s, std::atoi(av[2]), std::atoi(av[3])) << std::endl;
    }
  return 0;
}
