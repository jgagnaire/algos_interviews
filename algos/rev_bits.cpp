
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

// with a 16-bit lookup-table
int func_lookup(uint64_t x)
{
  return (tab[x & 0xFFFF] << 16 * 3)
    | (tab[(x >> 16) & 0xFFFF] << 16 * 2)
    | (tab[(x >> 16 * 2) & 0xFFFF] << 16)
    | (tab[(x >> 16 * 3) & 0xFFFF]);
}

int main()
{
  uint64_t x = 42;

  std::cout << "before: " << x << " -- after: " << func_lookup(x) << std::endl;
  return 0;
}
