
#include <stdio.h>
#include <stdint.h>

uint64_t func(uint64_t x)
{
  int i = 0;
  uint64_t y = 0;

  while (i < 64)
    {
      y = y | (((x >> (63 - i)) & 1) << i);
      ++i;
    }
  return y;
}

int main()
{
  uint64_t x = 42;

  return printf("before: %lu -- after: %lu\n", x, func(x));
}
