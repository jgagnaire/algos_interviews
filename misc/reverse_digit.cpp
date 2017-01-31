
int    func(int x)
{
  int y = 0;
  bool neg_flag;

  if (x < 0)
    {
      neg_flag = true;
      x = -x;
    }
  while (x > 0)
    {
      y *= 10;
      y += (x % 10);
      x /= 10;
    }
  return neg_flag ? -y : y;
}

#include <iostream>
#include <stdlib.h>

int	main(int ac, char **av)
{
  if (ac == 1)
    return 0;

  std::cout << func(::atoi(av[1])) << std::endl;
  return 0;
}
